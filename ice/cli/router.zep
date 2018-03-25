
namespace Ice\Cli;

use Ice\Exception;

/**
 * Router is the standard framework router. Routing is the process of taking a command-line arguments and decomposing it
 * into parameters to determine which module, task, and action of that task should receive the request.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Router
{

    protected defaultModule = "shell" { get, set };
    protected defaultHandler = "main" { get, set };
    protected defaultAction = "main" { get, set };

    protected module { get };
    protected handler { get };
    protected action { get };
    protected params = [] { get };

    /**
     * Set defaults values
     *
     * @param array defaults
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
        let this->module = this->defaultModule,
            this->handler = this->defaultHandler,
            this->action = this->defaultAction,
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
            let this->module = params["module"];

            unset params["module"];
        }

        if isset params["handler"] && params["handler"] {
            let this->handler = params["handler"];
            
            unset params["handler"];
        }

        if isset params["action"] && params["action"] {
            let this->action = params["action"];
            
            unset params["action"];
        }

        if count(params) {
            let this->params = params;
        }

        return ["module": this->module, "handler": this->handler, "action": this->action, "params": this->params];
    }
}
