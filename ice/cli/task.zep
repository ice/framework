
namespace Ice\Cli;

use Ice\Di\Access;

/**
 * Every command-line task should extend this class that encapsulates all the task functionality. A task can be used to
 * run "tasks" such as migrations, cronjobs, unit-tests, or anything that you want. The Task class should at least have
 * a "mainAction" method.
 *
 * @package     Ice/Di/Access
 * @category    Handler
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Task extends Access
{

}
