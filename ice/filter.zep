
namespace Ice;

/**
 * Filter component provides a set of commonly needed data filters.
 *
 * @package     Ice/Filter
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Filter
{

    protected filters;

    /**
     * Adds a user-defined filter.
     *
     * @param string name
     * @param callable body
     * @return object Filter
     */
    public function add(string! name, body)
    {
        if typeof body != "object" {
            throw new Exception("Filter must be an object");
        }

        let this->filters[name] = body;
        
        return this;
    }

    /**
     * Sanitizes a value with a specified single or set of filters.
     *
     * @param mixed value
     * @param mixed filters
     * @return mixed
     */
    public function sanitize(var value, var filters)
    {
        var filter;

        if typeof filters == "string" {
            let filters = explode("|", filters);
        }

        if typeof filters == "array" {
            for filter in filters {
                let value = this->doSanitize(value, filter);
            }
        }
        
        return value;
    }

    /**
     * Internal sanitize.
     *
     * @param mixed value
     * @param string filter
     * @return mixed
     */
    protected function doSanitize(string value, string! filter)
    {
        var custom;

        // Try a user-defined filter first
        if fetch custom, this->filters[filter] {
            // If the filter is a closure we call it in the PHP userland
            if custom instanceof \Closure {
                return call_user_func_array(custom, [value]);
            }

            return custom->sanitize(value);
        }

        switch filter {
            case "cssmin":
                let custom = create_instance("Ice\\Filter\\Css"),
                    this->filters["cssmin"] = custom;
                return custom->sanitize(value);
            case "jsmin":
                let custom = create_instance("Ice\\Filter\\Js"),
                    this->filters["jsmin"] = custom;
                return custom->sanitize(value);

            case "camelize":
                return value->camelize();
            case "uncamelize":
                return value->uncamelize();
            case "human":
                // Replace CamelCase and under_scores to spaces
                return ucfirst(trim(str_replace("_", " ", strtolower(preg_replace("/(?<=\\w)(?=[A-Z])/", " $1", value)))));
            case "lower":
                return function_exists("mb_strtolower") ? mb_strtolower(value) : strtolower(value);
            case "upper":
                return function_exists("mb_strtoupper") ? mb_strtoupper(value) : strtoupper(value);

            case "alnum":
                return preg_replace("/[^a-z0-9]/i", "", value);
            case "alpha":
                return preg_replace("/[^a-z]/i", "", value);
            case "email":
                return filter_var(value, FILTER_SANITIZE_EMAIL);
            case "bool":
            case "boolean":
                return filter_var(value, FILTER_VALIDATE_BOOLEAN);
            case "float":
                return (double) filter_var(value, FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
            case "int":
            case "integer":
                return (int) filter_var(value, FILTER_SANITIZE_NUMBER_INT);
            case "string":
                return filter_var(value, FILTER_SANITIZE_STRING);

            case "repeats":
            case "strip_repeats":
                // Remove repeating, more than 2 spaces to space, more than 3 br to 2 br, more than 3 the same char to 3 chars
                return preg_replace(["/[ ]{2,}/", "/((\\r\\n|\\n\\r|\\n|\\r){3,})/", "~(.?)\\1{3,}~"], [" ", PHP_EOL . PHP_EOL, "$1$1$1"], value);
            case "e":
            case "escape":
            case "strip_special":
                // Convert special characters to HTML entities
                return htmlspecialchars((string) value, ENT_QUOTES | ENT_HTML5);
            case "unescape":
            case "unstrip_special":
                return htmlspecialchars_decode(value, ENT_QUOTES | ENT_HTML5);

            default:
                throw new Exception(sprintf("Filter '%s' is not supported", filter));
        }
    }
}
