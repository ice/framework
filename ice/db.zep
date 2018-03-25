
namespace Ice;

use Ice\Db\Driver\Mongodb;
use Ice\Db\Driver\Pdo;
use Ice\Db\DbInterface;

/**
 * Database component.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
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
     * @param array options
     */
    public function __construct(var driver, string host = null, int port = null, string name = null, string user = null, string password = null, array options = [])
    {
        if typeof driver == "object" && (driver instanceof DbInterface) {
            let this->driver = driver;
        } elseif typeof driver == "string" {
            switch driver {
                case "oci":
                    var tns = "(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=" . host . ")(PORT=" . port . "))(CONNECT_DATA=(SID=orcl)))";
                    let this->driver = new Pdo("oci:dbname=" . tns, user, password, options);
                    break;
                case "mongodb":
                    var dsn = "mongodb://" . user . ":" . password . "@" . host . ":" . port . "/" . name;
                    let this->driver = new Mongodb(dsn, name, options);
                    break;
                default:
                    let this->driver = new Pdo(driver . ":host=" . host . ";port=" . port . ";dbname=" . name, user, password, options);
                    break;
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
