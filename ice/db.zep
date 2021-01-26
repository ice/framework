
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
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
class Db
{
    protected driver { get, set };

    /**
     * Db constructor.
     *
     * @param mixed dsn
     * @param string host
     * @param int port
     * @param string name
     * @param string user
     * @param string password
     * @param array options
     */
    public function __construct(var dsn, string host = null, int port = null, string name = null, string user = null, string password = null, array options = [])
    {
        if typeof dsn == "object" && (dsn instanceof DbInterface) {
            let this->driver = dsn;
        } elseif typeof dsn == "string" {
            switch dsn {
                case "oci":
                    var tns = "(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=" . host . ")(PORT=" . port . "))(CONNECT_DATA=(SID=orcl)))";
                    let this->driver = new Pdo("oci:dbname=" . tns, user, password, options);
                    break;
                case "mongodb":
                    var dsn = "mongodb://" . user . ":" . password . "@" . host . ":" . port . "/" . name;
                    let this->driver = new Mongodb(dsn, name, options);
                    break;
                default:
                    var settings = [];

                    if host {
                        let settings[] = "host=" . host;
                    }

                    if port {
                        let settings[] = "port=" . port;
                    }

                    if name {
                        let settings[] = "dbname=" . name;
                    }

                    if count(settings) {
                        let dsn .= ":" . join(";", settings);
                    }

                    let this->driver = new Pdo(dsn, user, password, options);
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
