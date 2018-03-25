
namespace Ice\Mvc\View\Engine\Sleet;

use Ice\Exception;

/**
 * Sleet file parser.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Parser
{

    protected functions = [
        "content": "$this->getContent",
        "partial": "$this->partial",
        "load": "$this->load",
        "dump": "$this->dump->vars",
        "version": "Ice\\Version::get"
    ];

    protected filters = [
        "capitalize": "ucfirst"
    ];

    protected env = [];

    const NORMAL = 0;
    const SHORTIF = 1;
    const INARRAY = 2;

    /**
     * Sleet parser constructor. Fetch Ice\Tag methods.
     */
    public function __construct()
    {
        var tag, methods, functions, method;

        let tag = new \ReflectionClass("Ice\\Tag"),
            methods = tag->getMethods(\ReflectionMethod::IS_PUBLIC),
            functions = [];

        for method in methods {
            switch method->name {
                case "__construct":
                    continue;
                default:
                    let functions[method->name] = "$this->tag->" . method->name,
                        functions[uncamelize(method->name)] = "$this->tag->" . method->name;
            }
        }

        let this->functions = array_merge(this->functions, functions),
            this->env[] = Parser::NORMAL;
    }

    /**
     * Parse text.
     *
     * @param string text
     * @return string Parsed text
     */
    public function text(string text) -> string
    {
        var pos, start, parsedText, end, ch;
        int i;

        let pos = 0,
            start = strpos(text, "{"),
            parsedText = "";

        while start !== false {
            let i = start + 1,
                ch = text[i];

            switch ch {
                case '{':
                    // append string before tokens, search close-symbol of the tag
                    let parsedText .= substr(text, pos, (int) (start - pos)),
                        end = strpos(text, "}}", start + 2);

                    if end === false {
                        // If unexpected end of template
                        throw new Exception(sprintf("Unclosed echo on the line %d", substr_count(substr(text, 0, start), PHP_EOL) + 1));
                    }

                    let end = end + 2,
                        parsedText .= this->parse(substr(text, start, (int) (end - start)));
                break;
                case '%':
                    // append string before tokens, search close-symbol of the tag
                    let parsedText .= substr(text, pos, (int) (start - pos)),
                        end = strpos(text, "%}", start + 2);
                   
                    if end === false {
                        // If unexpected end of template
                        throw new Exception(sprintf("Unclosed tag on the line %d", substr_count(substr(text, 0, start), PHP_EOL) + 1));
                    }

                    let end = end + 2,
                        parsedText .= this->parse(substr(text, start, (int) (end - start)));
                break;
                case '#':
                    // append string before comment, search close-symbol of the comment
                    let parsedText .= substr(text, pos, (int) (start - pos)),
                        end = strpos(text, "#}", start + 2);
                   
                    if end === false {
                        // If unexpected end of template
                        throw new Exception(sprintf("Unclosed comment block on the line %d", substr_count(substr(text, 0, start), PHP_EOL) + 1));
                    }

                    let end = end + 2;
                break;
                default:
                    // Ignore the tag
                    let parsedText .= substr(text, pos, (int) (start - pos + 1)),
                        end = start + 1;
                break;
            }
            // next tokens
            let pos = end,
                start = strpos(text, "{", pos);
        }
        // append string after tokens
        let parsedText .= substr(text, pos);

        return parsedText;
    }

    /**
     * Parse one sleet expression.
     *
     * @param string expression
     * @return string
     */
    public function parse(string expression) -> string
    {
        var php, tokenized, tokens, token, first;

        if starts_with(expression, "{{") {
            let php = "<?php echo " . substr(expression, 2, -2);
        } else {
            let php = "<?php " . substr(expression, 2, -2);
        }

        let tokenized = token_get_all(php),
            tokens = [];

        array_shift(tokenized);

        for token in tokenized {
            if typeof token == "array" && token[0] == T_WHITESPACE {
                continue;
            }
            let tokens [] = token;
        }

        let first = array_shift(tokens);

        if typeof first != "array" {
            throw new Exception("Unexpected first tag");
        }

        if typeof tokens != "array" {
            throw new Exception("Unexpected expression");
        }

        switch first[0] {
            case T_ENDIF:
            case T_ENDFOR:
            case T_ENDWHILE:
            case T_ENDSWITCH:
            case T_ENDFOREACH:
                return "<?php " . first[1] . " ?>";
            case T_BREAK:
                return "<?php " . first[1] . "; ?>";
            case T_ELSE:
            case T_DEFAULT:
                return "<?php " . first[1] . ": ?>";
            case T_SWITCH:
            case T_CASE:
            case T_IF:
            case T_ELSEIF:
            case T_DO:
            case T_FOR:
            case T_WHILE:
            case T_FOREACH:
                return this->parseControl(first[1], tokens);
            case T_ECHO:
                return this->parseEcho(tokens);
            case T_VAR:
                return this->parseSet(tokens);
            case T_STRING:
                if first[1] == "set" {
                    return this->parseSet(tokens);
                }
                break;
            case T_USE:
                return this->parseUse(tokens);
        }
        return "";
    }

    /**
     * Parse control expression.
     *
     * @param string control Control structure
     * @param array expression Tokens
     * @return string
     */
    private function parseControl(control, expression) -> string
    {
        return "<?php " . control . "(" . this->doParse(expression) . "): ?>";
    }
    
    /**
     * Parse echo expression.
     *
     * @param array expression Tokens
     * @return string
     */
    private function parseEcho($expression) -> string
    {
        return "<?php echo " . this->doParse(expression) . " ?>";
    }

    /**
     * Parse set expression.
     *
     * @param array expression Tokens
     * @return string
     */
    private function parseSet($expression) -> string
    {
        return "<?php " . this->doParse(expression) . "; ?>";
    }

    /**
     * Parse use expression.
     *
     * @param array expression Tokens
     * @return string
     */
    private function parseUse($expression) -> string
    {
        return "<?php use " . this->doParse(expression) . "; ?>";
    }

    /**
     * Internal tokens parse.
     *
     * @param array tokens
     * @return string
     */
    private function doParse(tokens) -> string
    {
        var i, parsed, prev, next, token, filter, seek, filters;

        let i = new \ArrayIterator(tokens),
            parsed = "",
            prev = "";

        while i->valid() {
            let token = i->current(),
                next = i->offsetExists(i->key() + 1) ? i->offsetGet(i->key() + 1) : null;

            if next == "|" {
                let seek = i->key() + 2,
                    filter = i->offsetGet(seek),
                    filter = isset this->filters[filter[1]] ? this->filters[filter[1]] : filter[1],
                    filters = ["camelize", "uncamelize", "human", "lower", "upper", "alnum", "alpha", "email", "float", "int", "string", "strip_repeats", "e", "escape", "strip_special", "unescape", "unstrip_special"];

                if in_array(filter, filters) {
                    let parsed .=  "$this->filter->sanitize(" . this->token(token, prev, next) . ", '" . filter . "'";
                } else {
                    let parsed .= filter . "(" . this->token(token, prev, next);
                }
                
                let next = i->offsetExists(seek + 1) ? i->offsetGet(seek + 1) : null;

                if next == "(" {
                    let parsed .= ", ",
                        seek++;
                } else {
                    let parsed .= ")";
                }

                i->seek(seek);
                i->next();
                continue;
            }
            
            let parsed .= this->token(token, prev, next),
                prev = token;

            i->next();
        }
        return parsed;
    }

    /**
     * Internal token parse.
     *
     * @param mixed token
     * @param mixed prev
     * @param mixed next
     * @return mixed
     */
    private function token(token, prev = null, next = null)
    {
        string str;

        if typeof token == "array" {
            switch token[0] {
                case T_AS:
                case T_NEW:
                case T_INSTANCEOF:
                case T_IS_EQUAL:
                case T_IS_NOT_EQUAL:
                case T_IS_IDENTICAL:
                case T_IS_NOT_IDENTICAL:
                case T_IS_SMALLER_OR_EQUAL:
                case T_IS_GREATER_OR_EQUAL:
                    return " " . token[1] . " ";
                case T_LOGICAL_OR:
                    return " || ";
                case T_LOGICAL_AND:
                    return " && ";
                case T_STRING:
                    let str = (string) token[1];

                    if next == "(" && (prev != "." || typeof prev == "array" && prev[0] != T_DOUBLE_COLON) {
                        return isset this->functions[str] ? this->functions[str] : str;
                    }
                    switch str {
                        case "in":
                            return " as ";
                        case "is":
                            return next == "!" ? " != " : " == ";
                        case "and":
                            return " && ";
                        case "or":
                            return " || ";
                        case "not":
                            return "!";
                        case "false":
                        case "true":
                        case "null":
                            return str;
                        default:
                            if prev == "." || next == "(" || ctype_upper(str[0]) && next != "|" {
                                return str;
                            }
                            return "$" . str;
                    }
                default:
                    return token[1];
            }
        } else {
            switch token {
                case "-":
                case "+": 
                case "*": 
                case "/": 
                case "%": 
                case "=": 
                case ">": 
                case "<": 
                    return " " . token . " ";
                case "~":
                    return " . ";
                case ",":
                    return ", ";
                case ".":
                    return "->";
                case ":":
                    switch end(this->env) {
                        case Parser::SHORTIF:
                            array_pop(this->env);
                            return " : ";
                        default:
                            return " => ";
                    }
                case "?":
                    let this->env[] = Parser::SHORTIF;
                    return " ? ";
                case "[":
                    let this->env[] = Parser::INARRAY;
                    return token;
                case "]":
                    if end(this->env) == Parser::INARRAY {
                        array_pop(this->env);
                    }
                    return token;
                default:
                    return token;
            }
        }
    }
}
