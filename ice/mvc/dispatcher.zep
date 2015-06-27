
namespace Ice\Mvc;

use Ice\Exception;
use Ice\Mvc\Route\Collector;

/**
 * Dispatching is the process of taking the request object, extracting the module name, controller name, action name,
 * and optional parameters contained in it, and then instantiating a controller and calling an action on it.
 *
 * @package     Ice/Dispatcher
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Dispatcher extends \Ice\Dispatcher
{

    protected method { get, set };
    protected handlerSuffix = "Controller";

    /**
     * Get active method, first check whether a method with the HTTP method as prefix exist.
     *
     * @return string
     */
    public function getActiveMethod() -> string
    {
        var action;

        let action = strtolower(this->method) . ucfirst(this->action) . this->actionSuffix;
        if method_exists(this->activeHandler, action) {
            return action;
        }

        return parent::getActiveMethod();
    }
}
