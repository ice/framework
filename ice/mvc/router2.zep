
namespace Ice\Mvc;

use Ice\Di;
use Ice\Exception;

/**
 * Router is the standard framework router. Routing is the process of taking a URI endpoint and decomposing it into
 * parameters to determine which module, controller, and action of that controller should receive the request.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Router2
{
    // list of route objects
    protected routes = [] { get };

    // get the current match route after handle()
    protected route;

    protected method { get };
    protected module { get };
    protected handler { get };
    protected action { get };
    protected params = [] { get };
    protected silent = false { get, set };

    // default module
    protected defaultModule = "default" { get, set };

    // default handler
    protected defaultHandler = "index" { get, set };

    // default action
    protected defaultAction = "index" { get, set };

    /**
     * Stores a named route and returns it.
     *
     * <pre><code>
     *     $router->addRoute("default", "[/{controller}[/{action}[/{id}]]]")
     *         ->defaults(["controller" => "hello"]);
     * </code></pre>
     *
     * @param string route name
     * @param string URI pattern
     * @param array regex patterns for route keys
     * @param mix method Request method limitation, * for no limit or an array of methods
     * @return object self
     */
    public static function addRoute(string name, string uri, array regex = null, var method = "*")
    {
        let this->routes[name] = new Route2(uri, regex, method);

        return this->routes[name];
    }

    /**
     * Retrieves a named route or the current matched route.
     *
     * <pre><code>
     *     $route = $router->getRoute("default");
     * </code></pre>
     *
     * @param   string route name
     * @return  Route|null
     */
    public function getRoute(string name = null)
    {
        if name === null {
            return this->route;
        }

        return isset this->routes[name] ? this->routes[name] : null;
    }

    /**
     * Get the name of a route.
     *
     * @param   object Route instance
     * @return  string
     */
    public function getRouteName(<Route2> route)
    {
        return array_search(route, this->routes);
    }

    /**
     * Saves or loads the route cache.
     *
     * <pre><code>
     *     if (! $router->cache()) {
     *         // set routes
     *         $router->addRoute("default", "[/{controller}[/{action}[/{id}]]]");
     *         // cache routes
     *         $router->cache($filePath);
     *     }
     * </code></pre>
     *
     * @param   string file Cache the current routes to the file
     * @return  self|boolean when saving routes or loading routes
     */
    public function cache(string file = null)
    {
        if file {
            // Cache all defined routes
            file_put_contents(file, "<?php return " . var_export(self::routes, true) . ";");

            return true;
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
     * Set defaults values
     *
     * <pre><code>
     *     $route->defaults(["controller" => "hello", "action" => "world"]);
     * </code></pre>
     *
     * @param array defaults values
     * @return self
     */
    public function defaults(array! defaults)
    {
        var module, handler, action;

        if fetch module, defaults["module"] {
            let this->defaultModule = module;
        }

        if fetch handler, defaults["controller"] {
            let this->defaultHandler = handler;
        }

        if fetch action, defaults["action"] {
            let this->defaultAction = action;
        }

        return this;
    }

    /**
     * Set an array of route rules.
     * httpMethod: *|null - no limit, GET, POST, PUT or PATCH
     * URI pattern: [] wrap for optional, {} wrap for regex placeholder key
     * regex: an associate array placeholder key and regex limitation pattern
     * defaults: default options for the module, handler and action
     *
     * <pre><code>
     *     // the rule format: ['name' => ["httpMethod", "URI pattern", "regex", "defaults"]]
     *     $route->setRoutes([
     *         ["default" => ["POST", "/{controller}[.ext]", ["controller" => "[a-z]+", "ext" => "(?:htm|html)"]]]
     *     ]);
     * </code></pre>
     *
     * @param array routes Route rules
     * @return self
     */
    public function setRoutes(array! routes = null)
    {
        var name, option, route, regex, defaults;

        if empty routes {
            // Set default routes
            let routes = [
                ["*", "[/{controller}[/{action}[/{id}[/{param}]]]]", ["controller":"\w+", "action":"\w+"]]
            ];
        }

        for name, option in routes {
            fetch regex, option[2];
            let route = this->addRoute(name, option[1], regex, option[0]);
            if fetch defaults, option[3] {
                route->defaults(defaults);
            }
        }

        return this;
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
        let uri = uri == "/" ? "/" : rtrim(uri, "/"),
            match = null;

        for name, route in this->routes {
            let params = route->matches(uri, method);
            if !empty params {
                let this->route = name,
                    this->method = method;

                if isset params["module"] {
                    let this->module = params["module"];
                } else {
                    let this->module = this->defaultModule;
                }

                if isset params["controller"] {
                    let this->handler = params["controller"];
                } else {
                    let this->handler = this->defaultHandler;
                }

                if isset params["action"] {
                    let this->action = params["action"];
                } else {
                    let this->action = this->defaultAction;
                }

                // These are accessible as public vars and can be overloaded
                unset params["controller"];
                unset params["action"];
                unset params["module"];

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
