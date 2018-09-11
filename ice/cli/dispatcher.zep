
namespace Ice\Cli;

use Ice\Cli\Task;

/**
 * Dispatching is the process of taking the command-line arguments, extracting the module name, task name, action name
 * and optional parameters contained in it, and then instantiating a task and calling an action on it.
 *
 * @package     Ice/Dispatcher
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Dispatcher extends \Ice\Dispatcher
{

    protected handlers = "Tasks";
    protected handlerSuffix = "Task";
}