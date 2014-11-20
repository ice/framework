
namespace Ice;

use Ice\Arr;
use Ice\Exception;
use Ice\Di\DiInterface;

class Di extends Arr implements DiInterface
{

    protected static _di;
    protected _hooks = [];

    public function __construct(array data = [])
    {
        parent::__construct(data);

        let self::_di = this;
    }

    /**
     * Return the last DI created
     *
     * @return DiInterface
     */
    public static function $fetch() -> <DiInterface>
    {
        return self::_di;
    }

    public function set(string key, var value)
    {
        var service;
        let service = this->resolve(value),
            this->_data[key] = service;
    }

    public function resolve(service)
    {
        var params;

        if typeof service == "string" {
            if class_exists(service) {
                let service = create_instance(service);
            }
        } else {
            if typeof service == "object" {
                if service instanceof \Closure {
                    let service = call_user_func(service);
                }
            } else {
                // Array definitions store class name at firest parameter
                if typeof service == "array" {
                    fetch params, service[1];
                    if typeof params == "array" {
                        let service = create_instance_params(service[0], params);
                    } else {
                        let service = create_instance(service[0]);
                    }
                }
            }
        }

        if typeof service != "object" {
            throw new Exception(sprintf("Service '%s' cannot be resolved", service));
        }

        return service;
    }

    /**
     * Assign hook
     *
     * @param string name The hook name
     * @param mixed callable A callable object
     * @param int priority The hook priority; 0 = high, 10 = low
     */
    public function hook(string name, var callback, int priority = 10)
    {
        if !isset this->_hooks[name] {
            let this->_hooks[name] = [[]];
        }

        if typeof callback == "callable" {
            let this->_hooks[name][priority][] = callback;
        }
    }
    /**
     * Invoke hook
     *
     * @param string name The hook name
     * @param mixed hookArg Argument for hooked functions
     */
    public function applyHook(string name, array args = null)
    {
        var priority, callback;

        if !isset this->_hooks[name] {
            let this->_hooks[name] = [[]];
        }

        if !empty this->_hooks[name] {
            // Sort by priority, low to high, if there's more than one priority
            //if count(this->_hooks[name]) > 1 {
            //    ksort(this->_hooks[name]);
            //}

            for priority in this->_hooks[name] {
                if !empty priority {
                    for callback in priority {
                        call_user_func_array(callback, args);
                    }
                }
            }
        }
    }
    /**
     * Get hook listeners
     *
     * Return an array of registered hooks. If `$name` is a valid
     * hook name, only the listeners attached to that hook are returned.
     * Else, all listeners are returned as an associative array whose
     * keys are hook names and whose values are arrays of listeners.
     *
     * @param  string     $name A hook name (Optional)
     * @return array|null
     */
    public function getHooks(string name = null) -> array | null
    {
        if name {
            return isset this->_hooks[name] ? this->_hooks[name] : null;
        } else {
            return this->_hooks;
        }
    }
    /**
     * Clear hook listeners
     *
     * Clear all listeners for all hooks. If `$name` is
     * a valid hook name, only the listeners attached
     * to that hook will be cleared.
     *
     * @param  string $name A hook name (Optional)
     */
    public function clearHooks(string name = null)
    {
        var key;

        if name && isset this->_hooks[name] {
            let this->_hooks[name] = [[]];
        } else {
            for key in array_keys(this->_hooks) {
                let this->_hooks[key] = [[]];
            }
        }
    }

    /**
     * Magic method to get or set services using setters/getters
     *
     * @param string method
     * @param mixed arguments
     * @return mixed
     */
    public function __call(string! method, arguments = null)
    {
        var service, value;

        // If the magic method starts with "get" we try to get a service with that name
        if starts_with(method, "get") {
        //if strpos(method, "get") !== false {
            let service = lcfirst(substr(method, 3));

            if this->has(service) {
                fetch value, arguments[0];
                return this->get(service, value);
            } else {
                throw new Exception(sprintf("The '%s' service is required", service));
            }
        }

        // If the magic method starts with "set" we try to set a service using that name
        if starts_with(method, "set") {
            fetch value, arguments[0];
            this->set(lcfirst(substr(method, 3)), value);
            return null;
        }

        // The method doesn't start with set/get throw an exception
        throw new Exception("Call to undefined method or service '" . method . "'");
    }
}