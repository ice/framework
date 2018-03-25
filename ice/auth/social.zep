
namespace Ice\Auth;

use Ice\Auth\Social\SocialInterface;

/**
 * Simple implementation of authentication through popular social networks.
 *
 * @package     Ice/Auth
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Social
{

    protected adapter { get };

    /**
     * Constructor.
     *
     * @param SocialInterface adapter
     */
    public function __construct(<SocialInterface> adapter)
    {
        let this->adapter = adapter;
    }

    /**
     * Call method authenticate() of adater class.
     *
     * @return boolean
     */
    public function authenticate()
    {
        return this->adapter->authenticate();
    }

    /**
     * Retrieve a single key from an adapter.
     *
     * @param string key The data key
     * @param mixed defaultValue The value to return if data key does not exist
     * @return mixed
     */
    public function get(string key, var defaultValue = null)
    {
        return this->adapter->get(key, defaultValue);
    }

    /**
     * Call method of this class or methods of adapter class.
     *
     * @param string method
     * @param mixed arguments
     * @return mixed
     */
    public function __call(string method, arguments = null) {
        return call_user_func_array([this->adapter, method], arguments);
    }
}
