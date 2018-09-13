
namespace Ice;

use Ice\Mvc\ModuleInterface;

/**
 * The base class for Ice\Mvc\Dispatcher and Ice\CLI\Dispatcher.
 * For the response from router and in the specified module, create instance of handler with action and params.
 *
 * @package     Ice/Dispatcher
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Dispatcher
{

    protected di;
    protected defaultNamespace { get, set };
    protected activeHandler { get };
    protected lastHandler { get };

    protected loops = 16 { get, set };
    protected finished { get };
    protected forwards = 0 { get };
    protected forwarded = false { get };
    protected silent = false { set };

    protected modules = [] { get, set };
    protected module = null { get, set };
    protected $namespace = null { get, set };
    protected handler = null { get, set };
    protected action = null { get, set };

    protected params = [] { get, set };
    protected returnedValue = null { get, set };

    protected handlers = "Handlers" { get, set };
    protected handlerSuffix = "Handler" { get, set };
    protected actionSuffix = "Action" { get, set };

    protected previousModule = null;
    protected previousHandler = null;
    protected previousAction = null;

    const DISPATCH_CYCLIC = 1;
    const HANDLER_NOT_FOUND = 2;
    const ACTION_NOT_FOUND = 3;
    const INVALID_PARAMS = 4;

    /**
     * Di constructor. Fetch Di and set it as a property.
     */
    public function __construct()
    {
        let this->di = Di::$fetch();
    }

    /**
     * Whether or not an param exists by key.
     *
     * @param string key The param key
     * @return boolean
     */
    public function hasParam(string key) -> boolean
    {
        return isset this->params[key];
    }

    /**
     * Set a param by its name or numeric index.
     *
     * @param mixed param
     * @param mixed value
     */
    public function setParam(var param, var value)
    {
        let this->params[param] = value;
    }

    /**
     * Gets variable from params attribute applying filters if needed.
     * If no parameters are given, return all.
     *
     * <pre><code>
     *  //Returns value from $params["id"] without sanitizing
     *  $id = $this->router->getParam("id");
     *
     *  //Returns value from $params["title"] with sanitizing
     *  $title = $this->router->getParam("title", "escape|repeats");
     *
     *  //Returns value from $params["id"] with a default value
     *  $id = $this->router->getParam("id", null, 150);
     * </code></pre>
     *
     * @param string key Index to get
     * @param string|array filters Filters to apply
     * @param mixed defaultValue Default value if key not exist or value is empty and allowEmpty is false
     * @param boolean allowEmpty
     * @return mixed
     */
    public function getParam(string key = null, var filters = null, var defaultValue = null, boolean allowEmpty = false)
    {
        var params;

        let params = new Arr(this->params);

        if !key {
            return params;
        } else {
            return params->getValue(key, filters, defaultValue, allowEmpty);
        }
    }

    /**
     * Returns the current method to be/executed in the dispatcher.
     *
     * @return string
     */
    public function getActiveMethod() -> string
    {
        return this->action . this->actionSuffix;
    }

    /**
     * Add module with its dir path, initial class name and namespace
     *
     * @param string name
     * @param array options The keys can be [path|class|namespace]
     * @return object Dispatcher
     */
    public function addModule(string name, array options)
    {
        // add or replace module
        let this->modules[name] = options;

        return this;
    }

    /**
     * Dispatches a handle action taking into account the routing parameters.
     *
     * @return object
     */
    public function dispatch()
    {
        var handler, response, handlerName, actionName, params, handlerSuffix, handlerClass, actionMethod;
        var fresh, module, modules, moduleNamespace, path, moduleClass, loader;

        let response = this->di->get("response"),
            fresh = true,
            handler = null,
            handlerSuffix = this->handlerSuffix,
            this->finished = false;

        while !this->finished {
            let this->forwards++;

            // Throw an exception after 16 consecutive forwards
            if this->loops && this->forwards > this->loops {
                if this->silent {
                    // 508 Loop Detected
                    response->setStatus(508);
                    response->setBody(response->getMessage(508));

                    return response;
                }
                throw new Exception("Dispatcher has detected a cyclic routing causing stability problems", self::DISPATCH_CYCLIC);
            }

            let this->finished = true,
                modules = this->modules;

            if modules {
                if !fetch module, modules[this->module] {
                    throw new Exception(["Module '%s' isn't registered in the application container", this->module]);
                }

                if typeof module != "array" {
                    throw new Exception("Module definition must be an array");
                }

                if fetch path, module["path"] {
                    if !file_exists(path) {
                        throw new Exception(["Module definition path '%s' doesn't exist", path]);
                    }
                }

                if !fetch moduleClass, module["class"] {
                    let moduleClass = "Module";
                }

                if !fetch moduleNamespace, module["namespace"] {
                    let moduleNamespace = moduleClass;
                }

                let loader = this->di->get("loader"),
                    this->$namespace = moduleNamespace;

                loader->addNamespace(moduleNamespace, path)->register();

                let module = <ModuleInterface> create_instance_params(moduleNamespace . "\\" . moduleClass, [this->di]);

                module->registerAutoloaders(loader);
                module->registerServices(this->di);
            }

            if !this->defaultNamespace {
                this->setDefaultNamespace(this->$namespace . "\\" . this->handlers);
            }

            let handlerName = this->handler,
                actionName = this->action,
                handlerClass = this->defaultNamespace . "\\" . ucfirst(camelize(handlerName)) . handlerSuffix;

            if !class_exists(handlerClass) {
                if this->silent {
                    // 404 Not Found
                    response->setStatus(404);
                    response->setBody(response->getMessage(404));

                    return response;
                }
                throw new Exception(["%s handler class cannot be loaded", handlerClass], self::HANDLER_NOT_FOUND);
            }

            let this->lastHandler = handler,
                handler = this->di->build(handlerClass),
                this->activeHandler = handler,
                actionMethod = this->getActiveMethod();

            if method_exists(handler, "before") {
                handler->before();

                if this->finished === false {
                    continue;
                }
            }

            // Call the 'initialize' method just once per request
            if fresh === true {
                if method_exists(handler, "initialize") {
                    handler->initialize();
                }
            }

            // Check if the method exists in the handler
            if !method_exists(handler, actionMethod) {
                if this->silent {
                    // 404 Not Found
                    response->setStatus(404);
                    response->setBody(response->getMessage(404));

                    return response;
                }
                throw new Exception(["Action '%s' was not found on handler '%s'", actionName, handlerName], self::ACTION_NOT_FOUND);
            }

            let params = this->params;
            if typeof params != "array" {
                throw new Exception("Action parameters must be an array", self::INVALID_PARAMS);
            }

            let this->returnedValue = call_user_func_array([handler, actionMethod], params);

            if this->finished === false {
                continue;
            }

            if method_exists(handler, "after") {
                handler->after();

                if this->finished === false {
                    continue;
                }
            }
            let fresh = false;
        }

        return handler;
    }

    /**
     * Forwards the execution flow to another module/controller/action.
     *
     * @param array forward
     * @param boolean force
     * @return object Dispatcher
     */
    public function forward(array! forward, boolean force = false)
    {
        var module, handler, action, params;

        // Check if we need to forward to another module
        if fetch module, forward["module"] {
            let this->previousModule = this->module,
                this->module = module;
        }

        // Check if we need to forward to another handler
        if fetch handler, forward["handler"] {
            let this->previousHandler = this->handler,
                this->handler = handler;
        }

        // Check if we need to forward to another action
        if fetch action, forward["action"] {
            let this->previousAction = this->action,
                this->action = action;
        }

        // Check if we need to forward changing the current parameters
        if fetch params, forward["params"] {
            let this->params = params;
        }

        let this->finished = false,
            this->forwarded = true;

        if force {
            this->dispatch();
        }

        return this;
    }
    /**
     * Reset module, handler and action to default ones, and empty the params.
     *
     * @return object Dispatcher
     */
    public function reset()
    {
        var router;

        let router = this->di->router;

        this->setModule(router->getDefaultModule())
            ->setHandler(router->getDefaultHandler())
            ->setAction(router->getDefaultAction())
            ->setParams([]);

        return this;
    }
}
