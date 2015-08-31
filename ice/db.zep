
namespace Ice;

use Ice\Db\Driver\Mongo;
use Ice\Db\Driver\Pdo;
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

    protected driver { get, set };

    /**
     * Db constructor.
     *
     * @param mixed driver
     * @param string host 
     * @param int port
     * @param string name
     * @param string user
     * @param string password
     */
    public function __construct(var driver, string host = null, int port = null, string name = null, string user = null, string password = null)
    {
        if typeof driver == "object" && (driver instanceof DbInterface) {
            let this->driver = driver;
        } elseif typeof driver == "string" {
            if driver == "mongodb" {
                let this->driver = new Mongo(
                    driver . "://" .
                    user . ":" .
                    password . "@" .
                    host . ":" .
                    port . "/" .
                    name,
                    name
                );
            } else {
                let this->driver = new Pdo(
                    driver . ":host=" .
                    host . ";port=" .
                    port . ";dbname=" .
                    name,
                    user, password
                );
            }
        }
    }

    /**
     * Magic call, call driver's method.
     */
    public function __call(string method, arguments = null) {
        return call_user_func_array([this->driver, method], arguments);
    }
}
