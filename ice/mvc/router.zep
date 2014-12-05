
namespace Ice\Mvc;

use Ice\Di;
use Ice\Exception;
use Ice\Mvc\Route\Collector;
use Ice\Mvc\Route\Dispatcher\DispatcherInterface;

/**
 * Router is the standard framework router. Routing is the
 * process of taking a URI endpoint (that part of the URI which comes after the base URL) and
 * decomposing it into parameters to determine which module, controller, and
 * action of that controller should receive the request
 */
class Router
{

    protected _di;
    protected _defaultModule = "default" { get, set };
    protected _defaultHandler = "index" { get, set };
    protected _defaultAction = "index" { get, set };

    protected _method { get };
    protected _module{ get };
    protected _handler { get };
    protected _action { get };
    protected _params = [] { get };

    protected _ready = false;
    protected _silent = false { set };
    protected _options { get, set };
    protected _routes { get, set };
    protected _collector { get, set };
    protected _dispatcher { get, set };

    const NOT_FOUND = 0;
    const FOUND = 1;
    const METHOD_NOT_ALLOWED = 2;

    public function __construct()
    {
        let this->_di = Di::$fetch();
    }

    public function setDefaults(array! defaults)
    {
        var module, handler, action;

        if fetch module, defaults["module"] {
            let this->_defaultModule = module;
        }

        if fetch handler, defaults["handler"] {
            let this->_defaultHandler = handler;
        }

        if fetch action, defaults["action"] {
            let this->_defaultAction = action;
        }
    }

    public function fastRoute(routeDefinitionCallback = null, array options = [])
    {
        var dispatcher, data, collector, parser, generator, route, handler;

        let options = array_merge([
            "routeParser": "Ice\\Mvc\\Route\\Parser\\Std",
            "dataGenerator": "Ice\\Mvc\\Route\\DataGenerator\\GroupCount",
            "dispatcher":"Ice\\Mvc\\Route\\Dispatcher\\GroupCount",
            "cache": false
        ], options);

        let this->_options = options;


        let collector = this->_collector;
        if typeof collector != "object" || typeof collector == "object" && !(collector instanceof Collector) {
            fetch parser, options["routeParser"];
            fetch generator, options["dataGenerator"];

            let this->_collector = new Collector(new {parser}(), new {generator}());
        }

        if typeof routeDefinitionCallback == "callable" {
            {routeDefinitionCallback}(this->_collector);
        }

        if !this->_routes {
            throw new Exception("There are no routes.");
        } else {
            for route in this->_routes {
                fetch handler, route[2];
                this->_collector->addRoute(route[0], route[1], handler);
            }
        }

        let dispatcher = this->_dispatcher;
        if typeof dispatcher != "object" || typeof dispatcher == "object" && !(dispatcher instanceof DispatcherInterface) {
            let dispatcher = options["dispatcher"],
                this->_dispatcher = new {dispatcher}();
        }

        if options["cache"] {
            if !isset options["cacheFile"] {
                throw new Exception("Must specify 'cacheFile' option");
            }

            if file_exists(options["cacheFile"]) {
                let data = require options["cacheFile"];
            } else {
                file_put_contents(options["cacheFile"], "<?php return " . var_export(data, true) . ";");
            }
        } else {
            let data = this->_collector->getData();
        }

        this->_dispatcher->setData(data);

        let this->_ready = true;
    }

    /**
     * Handles routing information received from the rewrite engine
     *
     * @param string uri
     * @return array
     */
    public function handle(method = null, uri = null) -> array
    {
        var module, handler, action, params, holders, data, route, response;

        let 
            handler = this->_defaultHandler,
            action = this->_defaultAction,
            params = [];

        if !this->_ready {
            this->fastRoute();
        }

        let route = this->_dispatcher->dispatch(method, uri);

        switch route[0] {
            case self::NOT_FOUND:
                if this->_silent {
                    // 404 Not Found
                    let response = this->_di->{"getResponse"}();
                    response->setStatus(404);
                    response->setBody(response->getMessage(404));

                    return response;
                }
                throw new Exception("The requested route could not be found", self::NOT_FOUND);
            case self::METHOD_NOT_ALLOWED:
                if this->_silent {
                    // 405 Method Not Allowed
                    let response = this->_di->{"getResponse"}();
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
                            let module = this->_defaultModule;
                        }
                    }

                    if !fetch handler, holders["controller"] {
                        if fetch handler, data["controller"] {
                            let handler = str_replace("/", "", handler);
                            unset data["controller"];
                        } else {
                            let handler = this->_defaultHandler;
                        }
                    }

                    if !fetch action, holders["action"] {
                        if fetch action, data["action"] {
                            let action = str_replace("/", "", action);
                            unset data["action"];
                        } else {
                            let action = this->_defaultAction;
                        }
                    }

                    let params = data;
            break;
       }

        let this->_method = method,
            this->_module = module,
            this->_handler = handler,
            this->_action = action,
            this->_params = params;

        return ["module": module, "handler": handler, "action": action, "params": params];
    }
}