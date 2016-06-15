
namespace Ice;

/**
 * Dumps information about a variable(s)
 *
 * @package     Ice/Dump
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
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
    protected skipDi = true { get, set };
    protected methods = [];
    protected styles = [];

    /**
     * Dump constructor
     *
     * @param boolean detailed debug object's private and protected properties
     * @param array styles
     */
    public function __construct(boolean detailed = false, array styles = [])
    {
        if typeof styles != "array" {
            throw new Exception("The styles must be an array");
        }
        this->setStyles(styles);
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
            "str": "color:teal"
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
            let output .= strtr("<b style =':style'>array</b> (<span style =':style'>:count</span>) (\n", [":style": this->getStyle("arr"), ":count": count(variable)]);

            for key, value in variable {
                let output .= str_repeat(space, tab) . strtr("[<span style=':style'>:key</span>] => ", [":style": this->getStyle("arr"), ":key": key]);

                if tab == 1 && name != "" && !is_int(key) && name == key {
                    continue;
                } else {
                    let output .= this->output(value, "", tab + 1) . "\n";
                }
            }
            return output . str_repeat(space, tab - 1) . ")";
        }

        if typeof variable == "object" {
            var className;

            let className = get_class(variable),
                output .= strtr("<b style=':style'>object</b> :class", [":style": this->getStyle("obj"), ":class": className]);

            if get_parent_class(variable) {
                let output .= strtr(" <b style=':style'>extends</b> :parent", [":style": this->getStyle("obj"), ":parent": get_parent_class(variable)]);
            }
            let output .= " (\n";

            if this->skipDi && variable instanceof Di {
                // Skip debuging di
                let output .= str_repeat(space, tab) . "[skipped]\n";
            } elseif !this->detailed {
                // Debug only public properties
                for key, value in get_object_vars(variable) {
                    let output .= str_repeat(space, tab) . strtr("-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", [":style": this->getStyle("obj"), ":key": key, ":type": "public"]);
                    let output .= this->output(value, "", tab + 1) . "\n";
                }
            } else {
                // Debug all properties
                do {
                    let attr = each(variable);

                    if !attr {
                        continue;
                    }
                    let key = attr["key"],
                        value = attr["value"];

                    if !key {
                        continue;
                    }

                    // Explode key by the "\x00" char
                    let key = explode(chr(0), key),
                        type = "public";

                    if isset key[1] {
                        let type = "private";

                        if key[1] == "*" {
                            let type = "protected";
                        }
                    }
                    let output .= str_repeat(space, tab) . strtr("-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", [":style": this->getStyle("obj"), ":key": end(key), ":type": type]),
                        output .= this->output(value, "", tab + 1) . "\n";
                } while attr;
            }

            let attr = get_class_methods(variable),
                output .= str_repeat(space, tab) . strtr(":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", [":style": this->getStyle("obj"), ":class": className, ":count": count(attr)]);

            if in_array(className, this->methods) {
                let output .= str_repeat(space, tab) . "[already listed]\n";
            } else {
                for value in attr {
                    if !in_array(className, this->methods) {
                        let this->methods[] = className;
                    }
                    if value == "__construct" {
                        let output .= str_repeat(space, tab + 1) . strtr("-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", [":style": this->getStyle("obj"), ":method": value]);
                    } else {
                        let output .= str_repeat(space, tab + 1) . strtr("-><span style=':style'>:method</span>();\n", [":style": this->getStyle("obj"), ":method": value]);
                    }
                }
                let output .= str_repeat(space, tab) . ")\n";
            }
            return output . str_repeat(space, tab - 1) . ")";
        }

        if is_int(variable) {
            return output . strtr("<b style=':style'>integer</b> (<span style=':style'>:var</span>)", [":style": this->getStyle("int"), ":var": variable]);
        }

        if is_float(variable) {
            return output . strtr("<b style=':style'>float</b> (<span style=':style'>:var</span>)", [":style": this->getStyle("float"), ":var": variable]);
        }

        if is_numeric(variable) {
            return output . strtr("<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", [":style": this->getStyle("num"), ":length": strlen(variable), ":var": variable]);
        }

        if is_string(variable) {
            return output . strtr("<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", [":style": this->getStyle("str"), ":length": strlen(variable), ":var": nl2br(htmlentities(variable, ENT_IGNORE, "utf-8"))]);
        }

        if is_bool(variable) {
            return output . strtr("<b style=':style'>boolean</b> (<span style=':style'>:var</span>)", [":style": this->getStyle("bool"), ":var": (variable ? "true" : "false")]);
        }

        if is_null(variable) {
            return output . strtr("<b style=':style'>null</b>", [":style": this->getStyle("null")]);
        }
        return output . strtr("(<span style=':style'>:var</span>)", [":style": this->getStyle("other"), ":var": variable]);
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
        return strtr("<pre style=':style'>:output</pre>", [":style": this->getStyle("pre"), ":output": this->output(variable, name)]);
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
}
