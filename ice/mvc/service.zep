
namespace Ice\Mvc;

use Ice\Di\Access;
use Ice\Exception;

/**
 * Service is intermediary between Model and Controller.
 *
 * @package     Ice/Mvc
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Service extends Access
{

    private model { set, get };

    /**
     * Controller constructor. Run onConstruct() if method exist.
     */
    public final function __construct()
    {
        parent::__construct();

        if method_exists(this, "onConstruct") {
            this->{"onConstruct"}();
        }
    }

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
