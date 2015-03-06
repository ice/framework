
namespace Ice;

use Ice\Mvc\ModuleInterface;

/**
 * The base class for Ice\Mvc\Dispatcher and Ice\CLI\Dispatcher.
 * For the response from router and in the specified module, create instance of handler with action and params.
 *
 * @package     Ice/Dispatcher
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Dispatcher 
{

    protected _di;
    protected _defaultNamespace { get, set };
    protected _activeHandler { get };
    protected _lastHandler { get };

    protected _finished { get };
    protected _forwarded = false { get };
    protected _silent = false { set };

    protected _modules = [] { get, set };
    protected _module = null { get, set };
    protected _namespace = null { get, set };
    protected _handler = null { get, set };
    protected _action = null { get, set };

    protected _params = [] { get, set };
    protected _returnedValue = null { get, set };

    protected _handlerSuffix = "Handler" { get, set };
    protected _actionSuffix = "Action" { get, set };

    protected _previousModule = null;
    protected _previousHandler = null;
    protected _previousAction = null;

    const DISPATCH_CYCLIC = 1;
    const HANDLER_NOT_FOUND = 2;
    const ACTION_NOT_FOUND = 3;
    const INVALID_PARAMS = 4;

    /**
     * Di constructor. Fetch Di and set it as a property.
     */
    public function __construct()
    {
        let this->_di = Di::$fetch();
    }

    /**
     * Set a param by its name or numeric index.
     *
     * @param mixed param
     * @param mixed value
     */
    public function setParam(var param, var value)
    {
        let this->_params[param] = value;
    }

    /**
     * Gets a param by its name or numeric index.
     *
     * @param mixed param
     * @param mixed defaultValue
     * @return mixed
     */
    public function getParam(param, defaultValue = null)
    {
        var value;

        if fetch value, this->_params[param] {
            return value;
        }
        return defaultValue;
    }

    /**
     * Returns the current method to be/executed in the dispatcher.
     *
     * @return string
     */
    public function getActiveMethod() -> string
    {
        return this->_action . this->_actionSuffix;
    }

    /**
     * Dispatches a handle action taking into account the routing parameters.
     *
     * @return object
     */
    public function dispatch()
    {
        var handler, response, handlerName, actionName, params, handlerSuffix, actionSuffix, handlerClass, actionMethod;
        var fresh, module, modules, moduleNamespace, path, moduleClass, loader;
        int i = 0;

        let response = this->_di->get("response"),
            fresh = true,
            handler = null,
            handlerSuffix = this->_handlerSuffix,
            actionSuffix = this->_actionSuffix,
            this->_finished = false;

        while !this->_finished {
            let i++;

            // Throw an exception after 16 consecutive forwards
            if i == 16 {
                if this->_silent {
                    // 508 Loop Detected
                    response->setStatus(508);
                    response->setBody(response->getMessage(508));

                    return response;
                }
                throw new Exception("Dispatcher has detected a cyclic routing causing stability problems", self::DISPATCH_CYCLIC);
            }

            let this->_finished = true,
                modules = this->_modules;

            if modules {
                if !fetch module, modules[this->_module] {
                    throw new Exception(["Module '%s' isn't registered in the application container", this->_module]);
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

                let loader = new Loader(),
                    this->_namespace = moduleNamespace;

                loader->addNamespace(moduleNamespace, path)->register();

                let module = <ModuleInterface> create_instance_params(moduleNamespace . "\\" . moduleClass, [this->_di]);

                module->registerAutoloaders();
                module->registerServices(this->_di);
            }

            if !this->_defaultNamespace {
                this->setDefaultNamespace(this->_namespace . "\\" . this->getHandlerSuffix());
            }

            let handlerName = this->_handler,
                actionName = this->_action,
                handlerClass = this->_defaultNamespace . "\\" . ucfirst(camelize(handlerName)) . handlerSuffix;

            if !class_exists(handlerClass) {
                if this->_silent {
                    // 404 Not Found
                    response->setStatus(404);
                    response->setBody(response->getMessage(404));

                    return response;
                }
                throw new Exception(["%s handler class cannot be loaded", handlerClass], self::HANDLER_NOT_FOUND);
            }

            let this->_lastHandler = handler,
                handler = new {handlerClass}(),
                this->_activeHandler = handler,
                actionMethod = this->getActiveMethod();

            if method_exists(handler, "before") {
                handler->before();

                if this->_finished === false {
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
                if this->_silent {
                    // 404 Not Found
                    response->setStatus(404);
                    response->setBody(response->getMessage(404));

                    return response;
                }
                throw new Exception(["Action '%s' was not found on handler '%s'", actionName, handlerName], self::ACTION_NOT_FOUND);
            }

            let params = this->_params;
            if typeof params != "array" {
                throw new Exception("Action parameters must be an array", self::INVALID_PARAMS);
            }

            let this->_returnedValue = call_user_func_array([handler, actionMethod], params);

            if this->_finished === false {
                continue;
            }

            if method_exists(handler, "after") {
                handler->after();

                if this->_finished === false {
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
     */
    public function forward(array! forward)
    {
        var module, handler, action, params;

        // Check if we need to forward to another module
        if fetch module, forward["module"] {
            let this->_previousModule = this->_module,
                this->_module = module;
        }

        // Check if we need to forward to another handler
        if fetch handler, forward["handler"] {
            let this->_previousHandler = this->_handler,
                this->_handler = handler;
        }

        // Check if we need to forward to another action
        if fetch action, forward["action"] {
            let this->_previousAction = this->_action,
                this->_action = action;
        }

        // Check if we need to forward changing the current parameters
        if fetch params, forward["params"] {
            let this->_params = params;
        }

        let this->_finished = false,
            this->_forwarded = true;
    }
}
