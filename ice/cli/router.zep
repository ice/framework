
namespace Ice\Cli;

use Ice\Exception;

/**
 * Router is the standard framework router. Routing is the
 * process of taking a command-line arguments and
 * decomposing it into parameters to determine which module, task, and
 * action of that task should receive the request
 */
class Router
{

    protected _defaultModule = "shell" { get, set };
    protected _defaultHandler = "main" { get, set };
    protected _defaultAction = "main" { get, set };

    protected _module = null { get };
    protected _handler = null { get };
    protected _action = null { get };
    protected _params = null { get };

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

    /**
     * Handles routing information received from command-line arguments
     * php index.php module handler action param1 param2
     *
     * @param array arguments
     * @return array
     */
    public function handle(arguments = null) -> array
    {
        var module, handler, action, params;

        if typeof arguments != "array" {
            throw new Exception("Arguments must be an array");
        }

        let module = this->_defaultModule,
            handler = this->_defaultHandler,
            action = this->_defaultAction,
            params = [];

        switch count(arguments) {
            case 1:
                // Handle defaults
            break;
            case 2:
                let module = arguments[1];
            break;
            case 3:
                let module = arguments[1],
                    handler = arguments[2];
            break;
            case 4:
                let module = arguments[1],
                    handler = arguments[2],
                    action = arguments[3];
            break;
            default:
                let module = arguments[1],
                    handler = arguments[2],
                    action = arguments[3],
                    params = array_slice(arguments, 4);
            break;
        }

        let this->_module = module,
            this->_handler = handler,
            this->_action = action,
            this->_params = params;

        return ["module": module, "handler": handler, "action": action, "params": params];
    }
}