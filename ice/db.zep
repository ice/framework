
namespace Ice;

use Ice\Db\DbInterface;

class Db
{

    protected _driver { get };

    public function __construct(<DbInterface> db)
    {
        let this->_driver = db;
    }

    public function __call(string method, arguments = null) {
        return call_user_func_array([this->_driver, method], arguments);
    }
}