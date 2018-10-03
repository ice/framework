
namespace Ice\Mvc;

use Ice\Di;
use Ice\Exception;

/**
 * Routes are used to determine the controller and action for a requested URI.
 * Every route generates a regular expression which is used to match a URI
 * and a route. Routes may also contain keys which can be used to set the
 * controller, action, and parameters.
 */
class Route2
{
    // Route URI string
    protected routeUri = "";

    // Regular expressions for route keys
    protected routeKeys = [];

    // Compiled regex cache
    protected routeRegex;

    // Regular expressions for route keys
    protected defaults = ["action": "index"] { get, set };

    protected method { get };
    protected error { get };

    // Defines the pattern of a {placeholder}
    const REGEX_KEYWORD = "\{([a-zA-Z0-9_]++)\}";

    // What can be part of a {placeholder} value
    const REGEX_PLACEHOLDER = "[^/.,;?\n]++";

    // What must be escaped in the route regex
    const REGEX_ESCAPE = "[.\\+*?^$=!|]";

    /**
     * Each {key} will be translated to a regular expression using a default
     * regular expression pattern. You can override the default pattern by providing
     * a pattern for the key:
     *
     * <pre><code>
     *     // This route will only match when {id} is a digit
     *     new Route("/blog/{action}/{id}", ["id" => "\d+"], ['GET', 'POST']);
     *
     *     // This route will match when {path} is anything
     *     new Route("/{path}", ["path" => ".*"]);
     * </code></pre>
     *
     * It is also possible to create optional segments by using parentheses in
     * the URI definition:
     *
     * <pre><code>
     *     // This is the standard default route, and no keys are required
     *     new Route('/{module}[/{controller}[/{action}[/{id}[/params]]]]');
     *
     *     // This route only requires the {file} key
     *     new Route('[/{path}/]{file}[.{ext}]', ['path' => '.*', 'ext' => '\w+']);
     * </code></pre>
     *
     * <pre><code>
     *     $route = new Route($uri, $regex, ['GET', 'POST']);
     * </code></pre>
     *
     * @param string uri Route URI pattern
     * @param array regex Key patterns
     * @param mix method Request method limitation, * for no limit or an array of methods
     */
    public function __construct(string! uri = null, array regex = null, var method = "*")
    {
        var regex, search, replace, key, value;

        if uri === null {
            // Assume the route is from cache
            return;
        }

        // Store the URI that this route will match
        let this->routeUri = uri;

        if !empty regex {
            let this->routeKeys = regex;
        }

        if empty method {
            let this->method = "*";
        } else {
            if typeof method == "array" {
                let this->method = array_map("strtoupper", method);
            } else {
                let this->method = strtoupper(method);
            }
        }

        // The URI should be considered literal except for keys and optional parts
        // Escape everything preg_quote would escape except for : [ ] { }
        let regex = preg_replace("#" . self::REGEX_ESCAPE . "#", "\\\\$0", this->routeUri);

        if strpos(regex, "[") !== false {
            // Make optional parts of the URI non-capturing and optional
            let regex = str_replace(["[", "]"], ["(?:", ")?"], regex);
        }

        // Insert default regex for keys
        let regex = str_replace(["{", "}"], ["(?P<", ">" . self::REGEX_PLACEHOLDER . ")"], regex);

        if !empty this->routeKeys {
            let search = [], replace = [];
            for key, value in this->routeKeys {
                let search[]  = "<" . key . ">" . self::REGEX_PLACEHOLDER,
                    replace[] = "<" . key . ">" . value;
            }
            // Replace the default regex with the user-specified regex
            let regex = str_replace(search, replace, regex);
        }

        // Store the compiled regex locally
        let this->routeRegex = "#^" . regex . "$#uD";
    }

    /**
     * Tests if the route matches a given URI and method.
     *
     * <pre><code>
     *     // Params: controller = blog, action = edit, id = 10
     *     $params = route->matches("/blog/edit/10");
     * </code></pre>
     *
     * @param string URI to match
     * @return array|false|null Routed parameters, method not allowed or no match
     */
    public function matches(string uri, string method = "*")
    {
        var params, matches, key, value;

		echo $this->_route_regex."====".$uri;
        if !preg_match(this->routeRegex, uri, matches) {
            // NOT FOUND
            return null;
        }
		print_r($matches);

        if this->method != "*" && method != "*" {        
            if !empty method {
                let method = strtoupper(method);
            }
            // For HEAD requests, attempt fallback to GET
            if method === "HEAD" {
                let method = "GET";
            }
            if typeof this->method == "string" && method != this->method
                || typeof this->method == "array" && !in_array(method, this->method) {
                // METHOD NOT ALLOWED
                return false;
            }
        }

        let params = this->defaults;

        for key, value in matches {
            if is_int(key) || value === "" {
                continue;
            }
            let params[key] = value;
        }

        return params;
    }

    /**
     * Generates a URI for the current route based on the parameters given. (AKA. reverse route)
     *
     * <pre><code>
     *     // Using the "default" route: /blog/post/10
     *     $uri = $route->uri(["controller" => "blog", "action" => "post", "id" => 10]);
     *     if (!$uri) echo $route->getError();
     * </code></pre>
     *
     * @param array URI parameters
     * @param array defaults Options for module, controller and action
     * @return string|false
     */
    public function uri(array! params = null)
    {
        var defaults, uri, match, param, search, key, replace;

        let uri = this->routeUri,
            defaults = this->defaults;

        if strpos(uri, "{") === false && strpos(uri, "[") === false {
            // This is a static route, no need to replace anything
            return uri;
        }

        if !empty params {
            for key, replace in params {
                if is_int(key) || replace === "" {
                    continue;
                }
                let defaults[key] = replace;
            }
        }

        while preg_match("#\[[^[\]]++\]#", uri, match) {
            // Search for the matched value
            let search = match[0];

            // Remove the parenthesis from the match as the replace
            let replace = substr(search, 1, -1);

            while preg_match("#" . self::REGEX_KEYWORD . "#", replace, match) {
                let key = key(match),
                    param = current(match);

                if isset defaults[param] {
                    // Replace the key with the parameter value
                    let replace = str_replace(key, defaults[param], replace);
                } else {
                    // This group has missing parameters
                    let replace = "";
                    break;
                }
            }
            // Replace the group in the URI
            let uri = str_replace(search, replace, uri);
        }

        while preg_match("#" . self::REGEX_KEYWORD . "#", uri, match) {
            let key = key(match),
                param = current(match);

            if !isset defaults[param] {
                // Ungrouped parameters are required
                let this->error = "Required route parameter not passed: " . param;
                return false;
            }

            let uri = str_replace(key, defaults[param], uri);
        }

        // Trim all extra slashes from the URI
        return preg_replace("#//+#", "/", rtrim(uri, "/"));
    }
}
