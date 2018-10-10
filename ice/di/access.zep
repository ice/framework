
namespace Ice\Di;

use Ice\Di;

/**
 * This class allows to access services in the services container by just only accessing a public property with the same
 * name of a registered service.
 *
 * @package     Ice/Di
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Access
{

    protected di;

    /**
     * Magic get to easy retrieve service from the di.
     */
    public function __get(string property)
    {
        var di, service;

        if typeof this->di != "object" || !(this->di instanceof Di) {
            let this->di = Di::$fetch();
        }

        let di = this->di;

        if property == "di" {
            return di;
        }

        let service = di->get(property),
            this->{property} = service;

        return service;
    }

    public function __set(string property, var value)
    {
        if typeof this->di != "object" || !(this->di instanceof Di) {
            let this->di = Di::$fetch();
        }

        return this->di->set(property, value);
    }
}
