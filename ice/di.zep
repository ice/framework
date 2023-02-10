
namespace Ice;

use ReflectionClass;
use ReflectionParameter;

/**
 * Component that implements Dependency Injection and a container for the services.
 *
 * @package     Ice/Di
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2023 Ice Team
 * @license     http://iceframework.org/license
 */
class Di extends Arr
{
    protected static di;
    protected hooks = [];
    protected defaults = [] { set };

    /**
     * Di constructor. Sets root path.
     *
     * @param array data Array of services
     */
    public function __construct(array data = [])
    {
        parent::__construct(data);

        let self::di = this;
    }

    /**
     * Return the last DI created.
     *
     * @return Di
     */
    public static function $fetch() -> <Di>
    {
        return self::di;
    }

    /**
     * Resolves the service based on its configuration.
     *
     * @param string key Service name
     * @param mixed parameters Definition
     */
    public function get(string key, var parameters = null)
    {
        var predefined;

        if this->has(key) {
            return parent::get(key, parameters);
        } else {
            fetch predefined, this->getDefaults()[key];

            return this->set(key, predefined ? predefined : parameters);
        }
    }

    /**
     * Registers a service in the services container.
     *
     * @param string key Service name
     * @param mixed value Definition
     */
    public function set(string key, var value)
    {
        var service;

        let service = this->resolve(value, key),
            this->data[key] = service;

        return service;
    }

    /**
     * Get default services.
     *
     * @return array
     */
    public function getDefaults()
    {
        var defaults = [
            "assets": "Ice\\Assets",
            "config": "Ice\\Config",
            "cookies": "Ice\\Cookies",
            "crypt": "Ice\\Crypt",
            "dispatcher": "Ice\\Mvc\\Dispatcher",
            "dump": "Ice\\Dump",
            "filter": "Ice\\Filter",
            "flash": "Ice\\Flash",
            "loader": "Ice\\Loader",
            "request": "Ice\\Http\\Request",
            "response": "Ice\\Http\\Response",
            "router": "Ice\\Mvc\\Router",
            "session": "Ice\\Session",
            "tag": "Ice\\Tag",
            "text": "Ice\\Text",
            "url": "Ice\\Mvc\\Url",
            "view": "Ice\\Mvc\\View"
        ];

        if PHP_SAPI === "cli" {
            let defaults = array_merge(defaults, [
                "dispatcher": "Ice\\Cli\\Dispatcher",
                "router": "Ice\\Cli\\Router"
            ]);
        }

        return array_merge(defaults, this->defaults);
    }

    /**
     * Resolve service.
     *
     * @param mixed service Definition
     * @return object service
     * @return string key
     */
    public function resolve(var service, string key)
    {
        var params;

        if typeof service == "null" {
            return null;
        } elseif typeof service == "string" {
            if class_exists(service) {
                let service = this->build(service);
            }
        } else {
            if typeof service == "object" {
                if service instanceof \Closure {
                    let service = call_user_func(service);
                }
            } else {
                // Array definitions class name as a key
                if typeof service == "array" {
                    var name;

                    let name = key(service);

                    // Check the defaults
                    if is_numeric(name) {
                        fetch name, this->getDefaults()[key];
                    }

                    let params = current(service),
                        service = this->build(name, [params]);
                }
            }
        }

        if typeof service != "object" {
            throw new Exception(sprintf("Service '%s' cannot be resolved", service));
        }

        return service;
    }

    /**
     * Build an instance of the given class.
     *
     * @param string service
     * @return mixed
     */
    public function build(var service, var parameters = [])
    {
        var reflector, constructor, dependencies;

        if typeof service == "object" {
            if service instanceof \Closure {
                return call_user_func_array(service, parameters);
            }
        }

        let reflector = new ReflectionClass(service);

        if !reflector->isInstantiable() {
            throw new Exception(["Service '%s' is not instantiable", service]);
        }

        let constructor = reflector->getConstructor();

        if is_null(constructor) {
            return create_instance(service);
        }

        let dependencies = constructor->getParameters(),
            parameters = this->getParameters(dependencies, parameters),
            dependencies = this->getDependencies(dependencies, parameters);

        return reflector->newInstanceArgs(dependencies);
    }

    /**
     * If extra parameters are passed by numeric ID, rekey them by argument name.
     *
     * @param array dependencies
     * @param array parameters
     * @return array
     */
    protected function getParameters(array dependencies, array parameters)
    {
        var key, value, dependency;

        for key, value in parameters {
            if is_numeric(key) {
                unset parameters[key];

                let dependency = dependencies[key],
                    parameters[dependency->name] = value;
            }
        }

        return parameters;
    }

    /**
     * Build up a list of dependencies for a given methods parameters.
     *
     * @param array parameters
     * @return array
     */
    public function getDependencies(array parameters, array primitives = [])
    {
        var dependencies, parameter, dependency;

        let dependencies = [];

        for parameter in parameters {
            let dependency = parameter->getType() && !parameter->getType()->isBuiltin() ? new ReflectionClass(parameter->getType()->getName()) : null;

            if array_key_exists(parameter->name, primitives) {
                let dependencies[] = primitives[parameter->name];
            } elseif is_null(dependency) {
                if !parameter->isOptional() {
                    let dependencies[] = this->resolveNonClass(parameter);
                }
            } else {
                let dependencies[] = this->build(dependency->name);
            }
        }

        return dependencies;
    }

    /**
     * Determine what to do with a non-class value.
     *
     * @param ReflectionParameter parameter
     * @return mixed
     *
     * @throws Exception
     */
    public function resolveNonClass(<ReflectionParameter> parameter)
    {
        if parameter->isDefaultValueAvailable() {
            return parameter->getDefaultValue();
        }

        throw new Exception(["Unresolvable dependency resolving '%s' in class '%s'", parameter, parameter->getDeclaringClass()->getName()]);
    }

    /**
     * Set handlers for error, exeception and shutdown.
     * Class should contain method handler, errorHandler and shutdownHandler.
     *
     * @param string className
     * @return object Di
     */
    public function errors(string className = "Ice\\Exception")
    {
        // Enable Ice exception handling, adds stack traces and error source.
        set_exception_handler([className, "handler"]);

        // Enable Ice error handling, converts all PHP errors to exceptions.
        set_error_handler([className, "errorHandler"]);

        // Enable Ice shutdown handler, which catches E_FATAL errors.
        register_shutdown_function([className, "shutdownHandler"]);

        return this;
    }

    /**
     * Assign hook.
     *
     * @param string name The hook name
     * @param mixed callable A callable object
     * @param mixed context The callback bind to the object
     * @param int priority The hook priority; 0 = high, 10 = low
     * @return object Di
     */
    public function hook(string name, var callback, var context = null, int priority = 10)
    {
        if typeof callback == "callable" {
            if context != null && is_object(context) {
                let name .= spl_object_hash(context);
            }
            if !isset this->hooks[name] {
                let this->hooks[name] = [[]];
            }
            let this->hooks[name][priority][] = callback;
        }
        return this;
    }

    /**
     * Invoke hook.
     *
     * @param string name The hook name
     * @param mixed hookArg Argument for hooked functions
     * @param mixed context The callback bind to the object
     * @return object Di
     */
    public function applyHook(string name, array args = null, var context = null)
    {
        var priority, callback;

        if context != null && is_object(context) {
            let name .= spl_object_hash(context);
        }

        if !isset this->hooks[name] {
            let this->hooks[name] = [[]];
        }

        if !empty this->hooks[name] {
            // Sort by priority, low to high, if there's more than one priority
            //if count(this->hooks[name]) > 1 {
            //    ksort(this->hooks[name]);
            //}

            for priority in this->hooks[name] {
                if !empty priority {
                    for callback in priority {
                        call_user_func_array(callback, args);
                    }
                }
            }
        }
        return this;
    }

    /**
     * Get hook listeners.
     * Return an array of registered hooks. If `$name` is a valid hook name, only the listeners attached to that hook
     * are returned. Else, all listeners are returned as an associative array whose keys are hook names and whose values
     * are arrays of listeners.
     *
     * @param string name A hook name (Optional)
     * @param mixed context The callback bind to the object
     * @return array|null
     */
    public function getHooks(string name = null, var context = null) -> array | null
    {
        if name {
            if context != null && is_object(context) {
                let name .= spl_object_hash(context);
            }
            return isset this->hooks[name] ? this->hooks[name] : null;
        } else {
            return this->hooks;
        }
    }

    /**
     * Clear hook listeners.
     * Clear all listeners for all hooks. If `$name` is a valid hook name, only the listeners attached to that hook
     * will be cleared.
     *
     * @param  string $name A hook name (Optional)
     * @param mixed context The callback bind to the object
     * @return object Di
     */
    public function clearHooks(string name = null, var context = null)
    {
        if name {
            if context != null && is_object(context) {
                let name .= spl_object_hash(context);
            }
            unset this->hooks[name];
        } else {
            let this->hooks = [];
        }
        return this;
    }

    /**
     * Magic method to get or set services using setters/getters.
     *
     * @param string method
     * @param mixed arguments
     * @return mixed
     */
    public function __call(string! method, arguments = null)
    {
        var value;

        // If the magic method starts with "get" we try to get a service with that name
        if starts_with(method, "get") {
            fetch value, arguments[0];
            return this->get(lcfirst(substr(method, 3)), value);
        }

        // If the magic method starts with "set" we try to set a service using that name
        if starts_with(method, "set") {
            fetch value, arguments[0];
            return this->set(lcfirst(substr(method, 3)), value);
        }

        // The method doesn't start with set/get throw an exception
        throw new Exception("Call to undefined method or service '" . method . "'");
    }
}
