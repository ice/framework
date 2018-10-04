
namespace Ice\Mvc;

use Ice\Di;
use Ice\Exception;
use Ice\Mvc\Route\Collector;
use Ice\Mvc\Route\Dispatcher\DispatcherInterface;

/**
 * Router is the standard framework router. Routing is the process of taking a URI endpoint and decomposing it into
 * parameters to determine which module, controller, and action of that controller should receive the request.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        FastRoute http:/github.com/nikic/FastRoute
 */
class FastRouter
{

    protected defaultModule = "default" { get, set };
    protected defaultHandler = "index" { get, set };
    protected defaultAction = "index" { get, set };

    protected method { get };
    protected module{ get };
    protected handler { get };
    protected action { get };
    protected params = [] { get };

    protected ready = false;
    protected silent = false { set };
    protected options = [] { get };
    protected routes { get, set };
    protected collector { get, set };
    protected dispatcher { get, set };

    const NOT_FOUND = 0;
    const FOUND = 1;
    const METHOD_NOT_ALLOWED = 2;

    /**
     * Set defaults values
     *
     * @param array defaults
     * @return object Router
     */
    public function setDefaults(array! defaults)
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
     * Set options.
     *
     * @param array options
     * @return object Router
     */
    public function setOptions(array! options)
    {
        let this->options = options;

        return this;
    }

    /**
     * Prepare the FastRoute.
     * @return object Router
     */
    public function fastRoute()
    {
        var options, data, route, handler;

        let options = array_merge([
            "routeParser": "Ice\\Mvc\\Route\\Parser\\Std",
            "dataGenerator": "Ice\\Mvc\\Route\\DataGenerator\\GroupCount",
            "dispatcher": "Ice\\Mvc\\Route\\Dispatcher\\GroupCount",
            "cache": false
        ], this->options);

        let this->options = options;

        if typeof this->collector != "object" || typeof this->collector == "object" && !(this->collector instanceof Collector) {
            let this->collector = new Collector(create_instance(options["routeParser"]), create_instance(options["dataGenerator"]));
        }

        if !this->routes {
            // Set default routes
            let this->routes = [
                ["*", "/{controller:[a-z]+}/{action:[a-z]+}[/{param}]"],
                ["*", "/{controller:[a-z]+}"],
                ["*", ""]
            ];
        }

        for route in this->routes {
            fetch handler, route[2];
            this->collector->addRoute(route[0], route[1], handler);
        }

        if typeof this->dispatcher != "object" || typeof this->dispatcher == "object" && !(this->dispatcher instanceof DispatcherInterface) {
            let this->dispatcher = create_instance(options["dispatcher"]);
        }

        if options["cache"] {
            if !isset options["cacheFile"] {
                throw new Exception("Must specify 'cacheFile' option");
            }

            if file_exists(options["cacheFile"]) {
                let data = require options["cacheFile"];
            } else {
                let data = this->collector->getData();

                file_put_contents(options["cacheFile"], "<?php return " . var_export(data, true) . ";");
            }
        } else {
            let data = this->collector->getData();
        }

        this->dispatcher->setData(data);

        let this->ready = true;
        
        return this;
    }

    /**
     * Handles routing information received from the FastRoute engine.
     *
     * @param string uri
     * @return mixed
     */
    public function handle(method = null, uri = null)
    {
        var module, handler, action, params, holders, data, route, response;

        let 
            handler = this->defaultHandler,
            action = this->defaultAction,
            params = [];

        if !this->ready {
            this->fastRoute();
        }

        let route = this->dispatcher->dispatch(method, uri);

        switch route[0] {
            case self::NOT_FOUND:
                if this->silent {
                    // 404 Not Found
                    let response = Di::$fetch()->get("response");
                    response->setStatus(404);
                    response->setBody(response->getMessage(404));

                    return response;
                }
                throw new Exception("The requested route could not be found", self::NOT_FOUND);
            case self::METHOD_NOT_ALLOWED:
                if this->silent {
                    // 405 Method Not Allowed
                    let response = Di::$fetch()->get("response");
                    response->setStatus(405);
                    response->setBody(response->getMessage(405));

                    return response;
                }
                throw new Exception("A request was made of a resource using a request method not supported by that resource", self::METHOD_NOT_ALLOWED);
            case self::FOUND:
                let holders = route[1],
                    data = route[2];

                    if !fetch module, holders["module"] {
                        if fetch module, data["module"] {
                            let module = str_replace("/", "", module);
                            unset data["module"];
                        } else {
                            let module = this->defaultModule;
                        }
                    }

                    if !fetch handler, holders["controller"] {
                        if fetch handler, data["controller"] {
                            let handler = str_replace("/", "", handler);
                            unset data["controller"];
                        } else {
                            let handler = this->defaultHandler;
                        }
                    }

                    if !fetch action, holders["action"] {
                        if fetch action, data["action"] {
                            let action = str_replace("/", "", action);
                            unset data["action"];
                        } else {
                            let action = this->defaultAction;
                        }
                    }

                    let params = data;
            break;
       }

        let this->method = method,
            this->module = module,
            this->handler = handler,
            this->action = action,
            this->params = params;

        return ["module": module, "handler": handler, "action": action, "params": params];
    }
}
