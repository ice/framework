
namespace Ice\Mvc;

use Ice\Exception;
use Ice\Mvc\Route\Collector;

class Dispatcher extends \Ice\Dispatcher
{

    protected _method { get, set };
    protected _handlerSuffix = "Controller";

    public function getActiveMethod() -> string
    {
        var action;

        let action = strtolower(this->_method) . ucfirst(this->_action) . this->_actionSuffix;
        if method_exists(this->_activeHandler, action) {
            return action;
        }

        return parent::getActiveMethod();
    }
}