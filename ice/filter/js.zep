
namespace Ice\Filter;

use Ice\Exception;

/**
 * Minify js string.
 *
 * @package     Ice/Filter
 * @category    Minification
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        jsmin.c www.crockford.com
 */
class Js
{

    const ORD_LF = 10;
    const ORD_SPACE = 32;
    const ACTION_KEEP_A = 1;
    const ACTION_DELETE_A = 2;
    const ACTION_DELETE_A_B = 3;
    protected a = "";
    protected b = "";
    protected input = "";
    protected inputIndex = 0;
    protected inputLength = 0;
    protected lookAhead = null;
    protected output = "" { get };

    /**
     * Minify the js.
     *
     * @param string js JS code to minify
     * @return string
     */
    public function sanitize(string js)
    {
        let this->a = "",
            this->b = "",
            this->input = str_replace("\r\n", "\n", js),
            this->inputLength = strlen(this->input),
            this->inputIndex = 0,
            this->lookAhead = null,
            this->output = "";

        return this->min();
    }

    /**
     * Action -- do something! What to do is determined by the $command argument.
     *
     * action treats a string as a single character. Wow!
     * action recognizes a regular expression if it is preceded by ( or , or =.
     *
     * @throws Exception If parser errors are found:
     *         - Unterminated string literal
     *         - Unterminated regular expression set in regex literal
     *         - Unterminated regular expression literal
     *
     * @param int $command One of class constants:
     *      ACTION_KEEP_A      Output A. Copy B to A. Get the next B.
     *      ACTION_DELETE_A    Copy B to A. Get the next B. (Delete A).
     *      ACTION_DELETE_A_B  Get the next B. (Delete B).
     */
    protected function action(int command)
    {
        //switch command {
            //case self::ACTION_KEEP_A: //1
            if command == self::ACTION_KEEP_A {
                let this->output = this->output . this->a;
            }

            //case self::ACTION_DELETE_A: //1, 2
            if command == self::ACTION_KEEP_A || command == self::ACTION_DELETE_A {
                let this->a = this->b;

                if this->a === "'" || this->a === "\"" {
                    while 1 {
                        let this->output = this->output . this->a,
                            this->a = this->get();

                        if this->a === this->b {
                            break;
                        }

                        if ord(this->a) <= self::ORD_LF {
                            throw new Exception("Unterminated string literal.");
                        }

                        if this->a === "\\" {
                            let this->output = this->output . this->a,
                                this->a = this->get();
                        }
                    }
                }
            }

            //case self::ACTION_DELETE_A_B: //1, 2, 3
            if command == self::ACTION_KEEP_A || command == self::ACTION_DELETE_A || command == self::ACTION_DELETE_A_B {
                let this->b = this->next();

                if this->b === "/" && (
                    this->a === "(" || this->a === "," || this->a === "=" ||
                    this->a === ":" || this->a === "[" || this->a === "!" ||
                    this->a === "&" || this->a === "|" || this->a === "?" ||
                    this->a === "{" || this->a === "}" || this->a === ";" ||
                    this->a === "\n" ) {
                    let this->output = this->output . this->a . this->b;

                    while 1 {
                        let this->a = this->get();
                        if this->a === "[" {
                            /*
                            inside a regex [...] set, which MAY contain a "/" itself. Example: mootools Form.Validator near line 460:
                            return Form.Validator.getValidator("IsEmpty").test(element) || (/^(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]\.?){0,63}[a-z0-9!#$%&'*+/=?^_`{|}~-]@(?:(?:[a-z0-9](?:[a-z0-9-]{0,61}[a-z0-9])?\.)*[a-z0-9](?:[a-z0-9-]{0,61}[a-z0-9])?|\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\])$/i).test(element.get("value"));
                            */
                            while 1 {
                                let this->output = this->output . this->a,
                                    this->a = this->get();

                                if this->a === "]" {
                                    break;
                                } elseif this->a === "\\" {
                                    let this->output = this->output . this->a,
                                        this->a = this->get();
                                } elseif ord(this->a) <= self::ORD_LF {
                                    throw new Exception("Unterminated regular expression set in regex literal.");
                                }
                            }
                        } elseif this->a === "/" {
                            break;
                        } elseif this->a === "\\" {
                            let this->output = this->output . this->a,
                                this->a = this->get();
                        } elseif ord(this->a) <= self::ORD_LF {
                            throw new Exception("Unterminated regular expression literal.");
                        }

                        let this->output = this->output . this->a;
                    }

                    let this->b = this->next();
                }
            }
        //}
    }

    /**
     * Get next char. Convert ctrl char to space.
     *
     * @return string|null
     */
    protected function get()
    {
        var c, i;

        let c = this->lookAhead,
            this->lookAhead = null;

        if c === null {
            if this->inputIndex < this->inputLength {
                let c = substr(this->input, this->inputIndex, 1),
                    i = this->inputIndex,
                    this->inputIndex = i + 1;
            } else {
                let c = null;
            }
        }

        if c === "\r" {
            return "\n";
        }

        if c === null || c === "\n" || ord(c) >= self::ORD_SPACE {
            return c;
        }

        return " ";
    }

    /**
     * Is $c a letter, digit, underscore, dollar sign, or non-ASCII character.
     *
     * @return bool
     */
    protected function isAlphaNum(c)
    {
        return ord(c) > 126 || c === "\\" || preg_match("/^[\\w\\$]$/", c) === 1;
    }

    /**
     * Perform minification, return result
     *
     * @return string
     */
    protected function min()
    {
        if 0 == strncmp(this->peek(), "\xef", 1) {
            this->get();
            this->get();
            this->get();
        }

        let this->a = "\n";
        this->action(self::ACTION_DELETE_A_B);

        while this->a !== null {
            switch this->a {
                case " ":
                    if this->isAlphaNum(this->b) {
                        this->action(self::ACTION_KEEP_A);
                    } else {
                        this->action(self::ACTION_DELETE_A);
                    }
                break;
                case "\n":
                    switch this->b {
                        case "{":
                        case "[":
                        case "(":
                        case "+":
                        case "-":
                        case "!":
                        case "~":
                            this->action(self::ACTION_KEEP_A);
                        break;
                        case " ":
                            this->action(self::ACTION_DELETE_A_B);
                        break;
                        default:
                            if this->isAlphaNum(this->b) {
                                this->action(self::ACTION_KEEP_A);
                            } else {
                                this->action(self::ACTION_DELETE_A);
                            }
                    }
                break;
                default:       
                    switch this->b {
                        case " ":
                            if this->isAlphaNum(this->a) {
                                this->action(self::ACTION_KEEP_A);
                                break;
                            }
                            this->action(self::ACTION_DELETE_A_B);
                        break;
                        case "\n":
                            switch this->a {
                                case "}":
                                case "]":
                                case ")":
                                case "+":
                                case "-":
                                case "\"":
                                case "'":
                                    this->action(self::ACTION_KEEP_A);
                                break;
                                default:
                                    if this->isAlphaNum(this->a) {
                                        this->action(self::ACTION_KEEP_A);
                                    } else {
                                        this->action(self::ACTION_DELETE_A_B);
                                    }
                            }
                        break;
                        default:
                            this->action(self::ACTION_KEEP_A);
                        break;
                    }
            }
        }        
        
        return this->output;
    }

    /**
     * Get the next character, skipping over comments. peek() is used to see
     *  if a "/" is followed by a "/" or "*".
     *
     * @throws Exception On unterminated comment.
     * @return string
     */
    protected function next()
    {
        var c;

        let c = this->get();

        if c === "/" {
            switch this->peek() {
                case "/":
                    while 1 {
                        let c = this->get();
                        if ord(c) <= self::ORD_LF {
                            return c;
                        }
                    }
                case "*":
                    this->get();

                    while 1 {
                        switch this->get() {
                            case "*":
                                if this->peek() === "/" {
                                    this->get();
                                    return " ";
                                }
                            break;
                            case null:
                                throw new Exception("Unterminated comment.");
                        }
                    }
                default:
                    return c;
            }
        }
        return c;
    }

    /**
     * Get next char. If is ctrl character, translate to a space or newline.
     *
     * @return string|null
     */
    protected function peek()
    {
        let this->lookAhead = this->get();
        return this->lookAhead;
    }
}
