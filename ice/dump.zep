
namespace Ice;

/**
 * Dumps information about a variable(s)
 *
 * @package     Ice/Dump
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $foo = 123;
 *  echo (new \Ice\Dump())->variable($foo, "foo");
 * </code></pre>
 *
 * <pre><code>
 *  $foo = "string";
 *  $bar = ["key" => "value"];
 *  $baz = new stdClass();
 *  echo (new \Ice\Dump())->vars($foo, $bar, $baz);
 * </code></pre>
 *
 * Sleet usage:
 * <pre><code>
 *  {{ dump('str', 1, 2.5, true, null, ['key': 'value']) }}
 * </code></pre>
 */
class Dump
{

    protected detailed = false { get, set };
    protected plain = false { get, set };
    protected skip = ["Ice\\Di"] { get, set };
    protected methods = [];
    protected styles = [];

    /**
     * Dump constructor
     *
     * @param boolean detailed debug object's private and protected properties
     * @param mixed styles
     */
    public function __construct(boolean detailed = false, var styles = [])
    {
        if typeof styles == "array" {
            this->setStyles(styles);
        } elseif typeof styles == "boolean" {
            let this->plain = styles;
        }
        let this->detailed = detailed;
    }


    /**
     * Alias of vars() method
     *
     * <pre><code>
     *  echo (new \Ice\Dump())->all($foo, $bar, $baz);
     * </code></pre>
     *
     * @param mixed variable
     * @param ...
     * @return string
     */
    public function all() -> string
    {
        return call_user_func_array([this, "vars"], func_get_args());
    }

    /**
     * Get style for type
     *
     * @param string type
     * @return string
     */
    protected function getStyle(string! type) -> string
    {
        var style;

        if fetch style, this->styles[type] {
            return style;
        } else {
            return "color:gray";
        }
    }

    /**
     * Set styles for vars type
     * Styles: pre, arr, bool, float, int, null, num, obj, other, res, str
     *
     * @param array styles
     * @return array
     */
    public function setStyles(array styles = []) -> array
    {
        var defaultStyles;

        if typeof styles != "array" {
            throw new Exception("The styles must be an array");
        }

        let defaultStyles = [
            "pre": "background-color:#f9f9f9; font-size:11px; padding:10px; border:1px solid #ccc; text-align:left; color:#333",
            "arr": "color:red",
            "bool": "color:green",
            "float": "color:fuchsia",
            "int": "color:blue",
            "null": "color:black",
            "num": "color:navy",
            "obj": "color:purple",
            "other": "color:maroon",
            "res": "color:lime",
            "str": "color:teal",
            "line": "highlight-block",
            "lines": ""
        ];

        let this->styles = array_merge(defaultStyles, styles);
        return this->styles;
    }

    /**
     * Alias of variable() method
     *
     * <pre><code>
     *  echo (new \Ice\Dump())->one($foo, "foo");
     * </code></pre>
     *
     * @param mixed variable
     * @param string name
     * @return string
     */
    public function one(variable, string name = null) -> string
    {
        return this->variable(variable, name);
    }

    /**
     * Prepare an HTML string of information about a single variable.
     *
     * @param mixed variable
     * @param string name
     * @param integer tab
     * @return  string
     */
    protected function output(variable, name = null, tab = 1) -> string
    {
        var key, value, output, space, type, attr;

        let space = "  ",
            output = "";

        if name {
            let output = name . " ";
        }

        if typeof variable == "array" {
            let output .= strtr((this->plain ? "array (:count) (" . PHP_EOL : "<b style =':style'>array</b> (<span style =':style'>:count</span>) (" . PHP_EOL), [":style": this->getStyle("arr"), ":count": count(variable)]);

            for key, value in variable {
                let output .= str_repeat(space, tab) . strtr((this->plain ? "[:key] => " : "[<span style=':style'>:key</span>] => "), [":style": this->getStyle("arr"), ":key": key]);

                if tab == 1 && name != "" && !is_int(key) && name == key {
                    continue;
                } else {
                    let output .= this->output(value, "", tab + 1) . PHP_EOL;
                }
            }
            return output . str_repeat(space, tab - 1) . ")";
        }

        if typeof variable == "object" {
            var className;

            let className = get_class(variable),
                output .= strtr((this->plain ? "object :class" : "<b style=':style'>object</b> :class"), [":style": this->getStyle("obj"), ":class": className]);

            if get_parent_class(variable) {
                let output .= strtr((this->plain ? " extends :parent" : " <b style=':style'>extends</b> :parent"), [":style": this->getStyle("obj"), ":parent": get_parent_class(variable)]);
            }
            let output .= " (" . PHP_EOL;

            if in_array(className, this->skip) {
                // Skip debuging
                let output .= str_repeat(space, tab) . "[skipped]" . PHP_EOL;
            } elseif !this->detailed {
                // Debug only public properties
                for key, value in get_object_vars(variable) {
                    let output .= str_repeat(space, tab) . strtr((this->plain ? "->:key (:type) = " :  "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = "), [":style": this->getStyle("obj"), ":key": key, ":type": "public"]);
                    let output .= this->output(value, "", tab + 1) . PHP_EOL;
                }
            } else {
                // Debug all properties
                var reflect = "ReflectionClass";

                for attr in (new {reflect}(variable))->getProperties() {
                    let key = attr->getName(),
                        type = "public";

                    if attr->isProtected() {
                        attr->setAccessible(true);
                        let type = "protected";
                    }

                    if attr->isPrivate() {
                        attr->setAccessible(true);
                        let type = "private";
                    }

                    let value = attr->getValue(variable);

                    let output .= str_repeat(space, tab) . strtr((this->plain ? "->:key (:type) = " : "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = "), [":style": this->getStyle("obj"), ":key": key, ":type": type]),
                        output .= this->output(value, "", tab + 1) . PHP_EOL;
                }
            }

            let attr = get_class_methods(variable),
                output .= str_repeat(space, tab) . strtr((this->plain ? ":class methods: (:count) (" . PHP_EOL : ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (" . PHP_EOL), [":style": this->getStyle("obj"), ":class": className, ":count": count(attr)]);

            if in_array(className, this->methods) {
                let output .= str_repeat(space, tab) . "[already listed]" . PHP_EOL;
            } else {
                for value in attr {
                    if !in_array(className, this->methods) {
                        let this->methods[] = className;
                    }
                    if value == "__construct" {
                        let output .= str_repeat(space, tab + 1) . strtr((this->plain ? "->:method(); [constructor]" . PHP_EOL : "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]" . PHP_EOL), [":style": this->getStyle("obj"), ":method": value]);
                    } else {
                        let output .= str_repeat(space, tab + 1) . strtr((this->plain ? "->:method();" . PHP_EOL : "-><span style=':style'>:method</span>();" . PHP_EOL), [":style": this->getStyle("obj"), ":method": value]);
                    }
                }
                let output .= str_repeat(space, tab) . ")" . PHP_EOL;
            }
            return output . str_repeat(space, tab - 1) . ")";
        }

        if is_int(variable) {
            return output . strtr((this->plain ? "integer (:var)" : "<b style=':style'>integer</b> (<span style=':style'>:var</span>)"), [":style": this->getStyle("int"), ":var": variable]);
        }

        if is_float(variable) {
            return output . strtr((this->plain ? "float (:var)" : "<b style=':style'>float</b> (<span style=':style'>:var</span>)"), [":style": this->getStyle("float"), ":var": variable]);
        }

        if is_numeric(variable) {
            return output . strtr((this->plain ? "numeric string (:length) \":var\"" : "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\""), [":style": this->getStyle("num"), ":length": strlen(variable), ":var": variable]);
        }

        if is_string(variable) {
            return output . strtr((this->plain ? "string (:length) \":var\"" : "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\""), [":style": this->getStyle("str"), ":length": strlen(variable), ":var": nl2br(htmlentities(variable, ENT_IGNORE, "utf-8"))]);
        }

        if is_bool(variable) {
            return output . strtr((this->plain ? "boolean (:var)" : "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)"), [":style": this->getStyle("bool"), ":var": (variable ? "true" : "false")]);
        }

        if is_null(variable) {
            return output . strtr((this->plain ? "null" : "<b style=':style'>null</b>"), [":style": this->getStyle("null")]);
        }
        return output . strtr((this->plain ? "(:var)" : "(<span style=':style'>:var</span>)"), [":style": this->getStyle("other"), ":var": variable]);
    }

     /**
     * Returns an HTML string of information about a single variable.
     *
     * <pre><code>
     *  $foo = 123;
     *  echo (new \Ice\Dump())->variable($foo, "foo");
     * </code></pre>
     *
     * @param mixed variable
     * @param string name
     * @return string
     */
    public function variable(variable, string name = null) -> string
    {
        return strtr((this->plain ? ":output" : "<pre style=':style'>:output</pre>"), [":style": this->getStyle("pre"), ":output": this->output(variable, name)]);
    }

    /**
     * Returns an HTML string of debugging information about any number of
     * variables, each wrapped in a "pre" tag.
     *
     * <pre><code>
     *  $foo = "string";
     *  $bar = ["key" => "value"];
     *  $baz = new stdClass();
     *  echo (new \Ice\Dump())->vars($foo, $bar, $baz);
     * </code></pre>
     *
     * @param mixed variable
     * @param ...
     * @return string
     */
    public function vars() -> string
    {
        var key, value, output;

        let output = "";

        for key, value in func_get_args() {
            let output .= this->one(value, "var " . key);
        }

        return output;
    }

    /**
     * Returns an HTML string, highlighting a specific line of a file, with some number of lines padded above and below.
     *
     * @param string file File to open
     * @param integer line Line number to highlight
     * @param integer padding Number of padding lines
     * @return array Source of file, false if file is unreadable
     */
    public function source(string filename, int line, int padding = 5) -> array|boolean
    {
        var file, range, format, lines, row;
        int i = 0;

        if empty filename || !is_readable(filename) {
            // Continuing will cause errors
            return false;
        }

        // Open the file and set the line position
        let file = fopen(filename, "r");

        // Set the reading range
        let range = [
            "start": line - padding,
            "end": line + padding
        ];

        // Set the zero-padding amount for line numbers
        let format = "% " . strlen(range["end"]) . "d",
            lines = [],
            row = fgets(file);

        while !feof(file) {
            if row === false {
                break;
            }

            // Increment the line number
            let i++;

            if i > range["end"] {
                break;
            }

            if i >= range["start"] {
                // Make the row safe for output
                let row = htmlspecialchars(row, ENT_NOQUOTES, "utf-8");

                if i === line {
                    // Apply highlighting to this row
                    let lines[sprintf(format, i)] .= strtr((this->plain ? ":var" : "<div class=':class'>:var</div>"), [":class": this->getStyle("line"), ":var": row]);
                } else {
                    let lines[sprintf(format, i)] .= strtr((this->plain ? ":var" : "<div class=':class'>:var</div>"), [":class": this->getStyle("lines"), ":var": row]);
                }
            }

            let row = fgets(file);
        }

        // Close the file
        fclose(file);

        return lines;
    }
}
