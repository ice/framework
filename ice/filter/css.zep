
namespace Ice\Filter;

/**
 * Minify css string.
 *
 * @package     Ice/Filter
 * @category    Minification
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        cssmin.c www.ryanday.org
 */
class Css
{

    const FREE = 1;
    const ATRULE = 2;
    const SELECTOR = 3;
    const BLOCK = 4;
    const DECLARATION = 5;
    const COMMENT = 6;

    /**
     * Minify the css.
     * Removes comments, removes newlines and line feeds keeping, removes last semicolon from last property
     *
     * @param string css CSS code to minify
     * @return string
     */
    public function sanitize(string css) -> string
    {
        string min = "";
        char c, next;
        int i, tmp, state = 1, inParen = 0;

        for i, c in css {
            let next = css[i + 1];

            //closing comment
            if c == '/' && css[i - 1] == '*' {
                continue;
            }

            if state != self::COMMENT {
                if c == '/' && next == '*' {
                    let tmp = state,
                        state = self::COMMENT;
                }
            }

            switch state {
                case self::FREE:
                    if c == ' ' && c == '\n' {
                        let c = 0;
                    } elseif c == '@' {
                        let state = self::ATRULE;
                        break;
                    } elseif c > 0 {
                        let state = self::SELECTOR;
                    }
                case self::SELECTOR:
                    if c == '{' {
                        let state = self::BLOCK;
                    } elseif c == '\n' {
                        let c = 0;
                    } elseif c == '@' {
                        let state = self::ATRULE;
                    } elseif c == ' ' && next == '{' {
                        let c = 0;
                    }
                    break;
                case self::ATRULE:
                    /* support
                        @import etc.
                        @font-face{
                    */
                    if c == '\n' || c == ';' {
                        let c = ';',
                            state = self::FREE;
                    } elseif c == '{' {
                        let state = self::BLOCK;
                    }
                    break;
                case self::BLOCK:
                    if c == ' ' || c == '\n' {
                        let c = 0;
                        break;
                    } elseif c == '}' {
                        let state = self::FREE;
                        break;
                    } else {
                        let state = self::DECLARATION;
                    }
                case self::DECLARATION:
                    //support in paren because data can uris have ;
                    if c == '(' {
                        let inParen = 1;
                    }

                    if inParen == 0 {
                        if c == ';' {
                            let state = self::BLOCK;
                            //could continue peeking through white space..
                            if next == '}' {
                                let c = 0;
                            }
                        } elseif c == '}' {
                            //handle unterminated declaration
                            let state = self::FREE;
                        } elseif c == '\n' {
                            //skip new lines
                            let c = 0;
                        } elseif c == ' ' {
                            //skip multiple spaces after each other
                            if next == c {
                                let c = 0;
                            }
                        }
                    } elseif c == ')' {
                        let inParen = 0;
                    }
                    break;
                case self::COMMENT:
                    if c == '*' && next == '/' {
                        let state = tmp;
                    }

                    let c = 0;
                    break;
            }

            if c != 0 {
                let min .= c;
            }

        }

        return min;
    }
}
