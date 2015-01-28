
namespace Ice;

use Ice\Db\DbInterface;

/**
 * Database component.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Db
{

    protected _driver { get };

    /**
     * Db constructor.
     *
     * @param DbInterface driver Database driver
     */
    public function __construct(<DbInterface> driver)
    {
        let this->_driver = driver;
    }

    /**
     * Magic call, call driver's method.
     */
    public function __call(string method, arguments = null) {
        return call_user_func_array([this->_driver, method], arguments);
    }
}
