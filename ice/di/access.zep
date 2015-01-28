
namespace Ice\Di;

use Ice\Di;

/**
 * This class allows to access services in the services container by just only accessing a public property with the same
 * name of a registered service.
 *
 * @package     Ice/Di
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Access
{

    protected _di;

    /**
     * Access constructor. Fetch di if not specified.
     *
     * @param Di di
     */
    public function __construct(<Di> di = null)
    {
        if !di {
            let this->_di = Di::$fetch();
        } else {
            let this->_di = di;
        }
    }

    /**
     * Magic get to easy retrieve service from the di.
     */
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
