
namespace Ice\Mvc;

use Ice\Di\Access;
use Ice\Exception;

/**
 * Service is intermediary between Model and Controller.
 *
 * @package     Ice/Mvc
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Service extends Access
{

    protected model { set, get };

    /**
     * Magic method to call model's method.
     *
     * @param string method
     * @param mixed arguments
     * @return mixed
     */
    public function __call(string! method, arguments = null)
    {
        if typeof this->model == "object" && (this->model instanceof Model) {
            return call_user_func_array([this->model, method], arguments);
        } else {
            throw new Exception("The `model` property must be instance of Model");
        }
    }
}
