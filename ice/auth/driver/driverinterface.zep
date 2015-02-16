
namespace Ice\Auth\Driver;

/**
 * Auth driver interface.
 *
 * @package     Ice/Auth
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
interface DriverInterface
{
    
    public function getUser(var defaultValue = null);
    public function hasRole(var user, string role = "login");
    public function login(var username, string password, boolean remember = false);
}
