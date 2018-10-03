
namespace Ice\Mvc;

use Ice\Di;
use Ice\Exception;

/**
 * Routes are used to determine the controller and action for a requested URI.
 * Every route generates a regular expression which is used to match a URI
 * and a route. Routes may also contain keys which can be used to set the
 * controller, action, and parameters.
 *
 * Each {key} will be translated to a regular expression using a default
 * regular expression pattern. You can override the default pattern by providing
 * a pattern for the key:
 *
 * <pre><code>
 *     // This route will only match when {id} is a digit
 *     Route::set("blog", "blog/{action}/{id}", ["id" => "\d+"], ['GET', 'POST']);
 *
 *     // This route will match when {path} is anything
 *     Route::set("file", "{path}", ["path" => ".*"]);
 * </code></pre>
 *
 * It is also possible to create optional segments by using parentheses in
 * the URI definition:
 *
 * <pre><code>
 *     // This is the standard default route, and no keys are required
 *     Route::set('default', '[{controller}[/{action}[/{id}]][.json]]');
 *
 *     // This route only requires the {file} key
 *     Route::set('file', '[{path}/]{file}[.{ext}]', ['path' => '.*', 'ext' => '\w+']);
 * </code></pre>
 *
 * Routes also provide a way to generate URIs (called "reverse routing"), which
 * makes them an extremely powerful and flexible way to generate internal links.
 *
 * <pre><code>
 *     // route: blog/post/10
 *     $uri = $route->uri(["controller" => "blog", "action" => "post", "id" => 10]);
 * </code></pre
 */
class Route2
{
    // list of route objects
    protected static routes = [];

    // Route URI string
    protected routeUri = "";

    // Regular expressions for route keys
    protected routeKeys = [];

    // Compiled regex cache
    protected routeRegex;

    // default module
    protected defaultModule = "default" { get, set };

    // default handler
    protected defaultHandler = "index" { get, set };

    // default action
    protected defaultAction = "index" { get, set };

    // get the current match route after handle()
    protected route { get };
    protected method { get };
    protected module { get };
    protected handler { get };
    protected action { get };
    protected params = [] { get };
    protected silent = false { get, set };
    protected error { get };

    // Defines the pattern of a <placeholder>
    const REGEX_KEYWORD = "\{([a-zA-Z0-9_]++)\}";

    // What can be part of a <placeholder> value
    const REGEX_PLACEHOLDER = "[^/.,;?\n]++";

    // What must be escaped in the route regex
    const REGEX_ESCAPE = "[.\\+*?^$=!|]";

    /**
     * Stores a named route and returns it.
     *
     * <pre><code>
     *     Route::set("default", "[{controller}[/{action}[/{id}]]]")
     *         ->defaults(["controller" => "welcome"]);
     * </code></pre>
     *
     * @param string route name
     * @param string URI pattern
     * @param array regex patterns for route keys
     * @param mix method Request method limitation, * for no limit or an array of methods
     * @return object self
     */
    public static function set(string name, string uri, array regex = null, var method = "*")
    {
        let self::routes[name] = new self(uri, regex, method);

        return self::routes[name];
    }

    /**
     * Retrieves a named route.
     *
     * <pre><code>
     *     $route = Route::get("default");
     * </code></pre>
     *
     * @param   string  route name
     * @return  Route|null
     */
    public static function get(string name)
    {
        return isset self::routes[name] ? self::routes[name] : null;
    }

    /**
     * Retrieves all named routes.
     *
     * @return  array  routes by name
     */
    public static function all()
    {
        return self::routes;
    }

    /**
     * Get the name of a route.
     *
     * @param   object Route instance
     * @return  string
     */
    public static function getName(<Route2> route)
    {
        return array_search(route, self::routes);
    }

    /**
     * Saves or loads the route cache.
     *
     * <pre><code>
     *     if (! Route::cache()) {
     *         // set routes
     *         Route::set("default", "[{controller}[/{action}[/{id}]]]");
     *         // cache routes
     *         Route::cache($filePath);
     *     }
     * </code></pre>
     *
     * @param   string file Cache the current routes to the file
     * @return  self|boolean when saving routes or loading routes
     */
    public static function cache(string file = false)
    {
        if file {
            // Cache all defined routes
            file_put_contents(file, "<?php return " . var_export(self::routes, true) . ";");

            return this;
        }

        if file_exists(file) {
            let self::routes = require file;

            // Routes were cached
            return true;
        }

        // Routes were not cached
        return false;
    }

    /**
     * Sets the URI and regular expressions for keys.
     * Routes should always be created with [Route::set]
     * or they will not be properly stored.
     *
     * <pre><code>
     *     $route = new Route($uri, $regex, ['GET', 'POST']);
     * </code></pre>
     *
     * @param string uri Route URI pattern
     * @param array regex Key patterns
     * @param mix method Request method limitation, * for no limit or an array of methods
     */
    public function __construct(string uri = null, array regex = null, var method = "*")
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
            let this->method = method;
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
     * Provides default values for keys when they are not present. The default
     * action will always be "index" unless it is overloaded here.
     *
     * <pre><code>
     *     $route->defaults(["handler" => "hello", "action" => "world"]);
     * </code></pre>
     *
     * @param   array  key values
     * @return  $this
     */
    public function defaults(array! defaults)
    {
        var module, handler, action;

        if fetch module, defaults["module"] {
            let this->defaultModule = module;
        }

        if fetch handler, defaults["handler"] {
            let this->defaultHandler = handler;
        }

        if fetch action, defaults["action"] {
            let this->defaultAction = action;
        }

        return this;
    }

    /**
     * Tests if the route matches a given URI and method.
     *
     * <pre><code>
     *     // Params: controller = blog, action = edit, id = 10
     *     $params = route->matches("blog/edit/10");
     * </code></pre>
     *
     * @param string URI to match
     * @return array|false|null Routed parameters, method not allowed or no match
     */
    public function matches(string uri, var method = "*")
    {
        var defaults, params, matches, key, value;

        if ! preg_match(this->routeRegex, uri, matches) {
            // NOT FOUND
            return null;
        }

        if this->method !== "*" {
            // For HEAD requests, attempt fallback to GET
            if method === "HEAD" {
                let method = "GET";
            }
            if typeof this->method == "string" && method != this->method
                || typeof this->method === "array" && !in_array(method, this->method) {
                // METHOD NOT ALLOWED
                return false;
            }
        }

        let params = [];

        for key, value in matches {
            if is_int(key) || value === "" {
                continue;
            }
            let params[key] = value;
        }

        let params += [
            "module": this->defaultModule,
            "handle": this->defaultHandler,
            "action": this->defaultAction
        ];

        return params;
    }

    /**
     * Generates a URI for the current route based on the parameters given.
     *
     * <pre><code>
     *     // Using the "default" route: blog/post/10
     *     $uri = $route->uri(["controller" => "blog", "action" => "post", "id" => 10]);
     *     if (!$uri) echo $route->getError();
     * </code></pre>
     *
     * @param array URI parameters
     * @return string|false
     */
    public function uri(array params = null)
    {
        var defaults, uri, match, search, key, replace;

        let defaults = [
            "module": this->defaultModule,
            "controller": this->defaultHandler,
            "action": this->defaultAction
        ];

        if params === null {
            let params = defaults;
        } else {
            let params += defaults;
        }

        let uri = this->routeUri;

        if strpos(uri, "{") === false && strpos(uri, "[") === false {
            // This is a static route, no need to replace anything
            return uri;
        }

        while preg_match("#\[[^[\]]++\]#", uri, match) {
            // Search for the matched value
            let search = match[0];

            // Remove the parenthesis from the match as the replace
            let replace = substr(search, 1, -1);

            while preg_match("#" . self::REGEX_KEYWORD . "#", replace, match) {
                let key = key(match),
                    param = current(match);

                if isset params[param] {
                    // Replace the key with the parameter value
                    let replace = str_replace(key, params[param], replace);
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

            if ! isset params[param] {
                // Ungrouped parameters are required
                let this->error = "Required route parameter not passed: " . param;
                return false;
            }

            let uri = str_replace(key, params[param], uri);
        }

        // Trim all extra slashes from the URI
        return preg_replace("#//+#", "/", rtrim(uri, "/"));
    }

    /**
     * Handles routing information.
     *
     * @param string method
     * @param string uri
     * @return mixed
     */
    public function handle(string method = null, string uri = null)
    {
        var name, route, params, match, response;

        // Remove trailing slashes from the URI
        let uri = trim(uri, '/'),
            match = null;

        for name, route in self::routes {
            let params = route->matches(uri);
            if params {
                let this->route = route;

                if isset params["module"] {
                    let this->module = params["module"];
                } else {
                    let this->module = this->defaultModule;
                }

                if isset params['controller'] {
                    let this->handler = params['controller'];
                } else {
                    let this->handler = this->defaultHandler;
                }

                if isset params['action'] {
                    let this->action = params['action'];
                } else {
                    let this->action = this->defaultAction;
                }

                // These are accessible as public vars and can be overloaded
                unset params['controller'];
                unset params['action'];
                unset params['module'];

                // Params cannot be changed once matched
                let this->params = params;

                return [
                    "module": this->module,
                    "handler": this->handler,
                    "action": this->action,
                    "params": this->params
                ];
            } elseif params === false {
                // method not allowed
                let match = false;
            }
        }

        if this->silent {
            // 404 Not Found, 405 Method Not Allowed
            let response = Di::$fetch()->get("response"),
                match = match === null ? 404 : 405;

            return response->setStatus(match)
                ->setBody(response->getMessage(match));
        }

        throw new Exception([
            match === null
                ? "Unable to find a route to match the URI: %s"
                : "Request method not supported by that resource: %s",
            uri
        ]);
    }
}
