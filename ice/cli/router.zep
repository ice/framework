
namespace Ice\Cli;

use Ice\Exception;

/**
 * Router is the standard framework router. Routing is the process of taking a command-line arguments and decomposing it
 * into parameters to determine which module, task, and action of that task should receive the request.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Router
{

    protected _defaultModule = "shell" { get, set };
    protected _defaultHandler = "main" { get, set };
    protected _defaultAction = "main" { get, set };

    protected _module { get };
    protected _handler { get };
    protected _action { get };
    protected _params = [] { get };

    /**
     * Set defaults values
     *
     * @param array defaults
     */
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
     * Handles routing information received from command-line arguments.
     *
     * <pre><code>
     *  php index.php --module=shell --handler=main --action=main --id=1 --param="some value"
     * </code></pre>
     *
     * @param array arguments
     * @return array
     */
    public function handle(arguments = null) -> array
    {
        var params, argument;

        if typeof arguments != "array" {
            throw new Exception("Arguments must be an array");
        }

        // Set the defaults
        let this->_module = this->_defaultModule,
            this->_handler = this->_defaultHandler,
            this->_action = this->_defaultAction,
            params = [];

        // Skip the first option, it is always the file executed
        array_shift(arguments);

        for argument in arguments {
            // Get the option
            if substr(argument, 0, 2) !== "--" {
                // This is a positional argument
                let params[] = argument;
                continue;
            }

            // Remove the "--" prefix
            let argument = substr(argument, 2);

            if strpos(argument, "=") {
                // Separate the name and value
                let argument = explode("=", argument, 2),
                    params[argument[0]] = argument[1];
            } else {
                let params[argument] = null;
            }
        }

        if isset params["module"] && params["module"] {
            let this->_module = params["module"];

            unset params["module"];
        }

        if isset params["handler"] && params["handler"] {
            let this->_handler = params["handler"];
            
            unset params["handler"];
        }

        if isset params["action"] && params["action"] {
            let this->_action = params["action"];
            
            unset params["action"];
        }

        if count(params) {
            let this->_params = params;
        }

        return ["module": this->_module, "handler": this->_handler, "action": this->_action, "params": this->_params];
    }
}
