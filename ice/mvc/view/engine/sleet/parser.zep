
namespace Ice\Mvc\View\Engine\Sleet;

use Ice\Exception;

class Parser
{

    protected _functions = [
        "content": "$this->getContent",
        "partial": "$this->partial",
        "load": "$this->load",
        "dump": "$this->dump->vars",
        "version": "Ice\\Version::get"
    ];

    protected _filters = [
        "capitalize": "ucfirst"
    ];

    protected _env;

    const NORMAL = 0;
    const SHORTIF = 1;

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

        let this->_functions = array_merge(this->_functions, functions),
            this->_env = Parser::NORMAL;
    }

    public function text(string text)
    {
        var parsed, key, line;

        let parsed = "";

        for key, line in explode(PHP_EOL, text) {
            let parsed .= (key ? PHP_EOL : "") . this->line(line, key + 1);
        }
        return parsed;
    }

    public function line(string line, int no = 1)
    {
        var pos, start, parsedLine, end, ch;
        int i;

        let pos = 0,
            start = strpos(line, "{"),
            parsedLine = "";

        while start !== false {
            //let split = str_split(line),
            //let line = (string) line,
            let i = start + 1,
                ch = line[i];

            switch ch {
                case '{':
                    // appand string before tokens, search close-symbol of the tag
                    let parsedLine .= substr(line, pos, (int) (start - pos)),
                        end = strpos(line, "}}", start + 2);

                    if end === false {
                        // If unexpected end of template
                        throw new Exception(sprintf("Unclosed tag on the line %d", no + 1));
                    }

                    let end = end + 2,
                        parsedLine .= this->parse(substr(line, start, (int) (end - start)));
                break;
                case '%':
                    // appand string before tokens, search close-symbol of the tag
                    let parsedLine .= substr(line, pos, (int) (start - pos)),
                        end = strpos(line, "%}", start + 2);
                   
                    if end === false {
                        // If unexpected end of template
                        throw new Exception(sprintf("Unclosed tag on the line %d", no + 1));
                    }

                    let end = end + 2,
                        parsedLine .= this->parse(substr(line, start, (int) (end - start)));
                break;
            }
            // next tokens
            let pos = end,
                start = strpos(line, "{", pos);
        }
        // appand string after tokens
        let parsedLine .= substr(line, pos);

        return parsedLine;
    }

    public function parse(expresion)
    {
        var php, tokenized, tokens, token, first;

        if starts_with(expresion, "{{") {
            let php = "<?php echo " . substr(expresion, 2, -2);
        } else {
            let php = "<?php " . substr(expresion, 2, -2);
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

    public function parseControl(control, expression)
    {
        return "<?php " . control . "(" . this->_parse(expression) . "): ?>";
    }
    
    public function parseEcho($expression)
    {
        return "<?php echo " . this->_parse(expression) . " ?>";
    }

    public function parseSet($expression)
    {
        return "<?php " . this->_parse(expression) . "; ?>";
    }

    public function parseUse($expression)
    {
        return "<?php use " . this->_parse(expression) . "; ?>";
    }

    private function _parse(tokens)
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
                    filter = isset this->_filters[filter[1]] ? this->_filters[filter[1]] : filter[1],
                    filters = ["camelize", "uncamelize", "human", "lower", "upper", "alnum", "alpha", "email", "float", "int", "string", "strip_repeats", "e", "escape", "strip_special", "unescape", "unstrip_special"];

                if in_array(filter, filters) {
                    let parsed .=  "$this->filter->sanitize(" . this->_token(token, prev, next) . ", '" . filter . "'";
                } else {
                    let parsed .= filter . "(" . this->_token(token, prev, next);
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
            
            let parsed .= this->_token(token, prev, next),
                prev = token;

            i->next();
        }
        return parsed;
    }

    private function _token(token, prev = null, next = null)
    {
        string str;

        if typeof token == "array" {
            switch token[0] {
                case T_AS:
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

                    if next == "(" && prev != "." && prev != ":" {
                        return isset this->_functions[str] ? this->_functions[str] : str;
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
                    switch this->_env {
                        case Parser::SHORTIF:
                            let this->_env = Parser::NORMAL;
                            return " : ";
                        default:
                            return " => ";
                    }
                case "?":
                    let this->_env = Parser::SHORTIF;
                    return " ? ";
                default:
                    return token;
            }
        }
    }

}