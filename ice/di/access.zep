
namespace Ice\Di;

use Ice\Di;

class Access
{

    protected _di;

    public function __construct(<Di> di = null)
    {
        if !di {
            let this->_di = Di::$fetch();
        } else {
            let this->_di = di;
        }
    }

    public function __get(string property)
    {
        var di, service;

        let di = this->_di;

        if property == "di" {
            let this->{"di"} = di;

            return di;
        }

        if di->has(property) {
            let service = di->{"get"}(property),
                this->{property} = service;

            return service;
        }

    }
}