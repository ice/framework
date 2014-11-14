
namespace Ice\Cli;

use Ice\Cli\Task;

/**
 * Dispatching is the process of taking the command-line arguments, extracting the module name,
 * task name, action name, and optional parameters contained in it, and then
 * instantiating a task and calling an action on it.
 */
class Dispatcher extends \Ice\Dispatcher
{

    protected _handlerSuffix = "Task";
}