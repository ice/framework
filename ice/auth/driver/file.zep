
namespace Ice\Auth\Driver;

use Ice\Auth\Driver;
use Ice\Auth\Driver\DriverInterface;

/**
 * File Auth driver.
 *
 * @package     Ice/Auth
 * @category    Driver
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class File extends Driver implements DriverInterface
{

    protected _users { set };

    /**
     * Gets the currently logged in user from the session. Returns NULL if no user is currently logged in.
     *
     * @param mixed defaultValue Default value to return if the user is currently not logged in
     * @return mixed
     */
    public function getUser(var defaultValue = null)
    {
        var username, user;

        if !this->_user {
            let username = parent::getUser(defaultValue);

            if username === defaultValue {
                // User isn't currently logged in
                let this->_user = defaultValue;
            } else {
                fetch user, this->_users[username];
                let this->_user = user;
            }
        }

        return this->_user;
    }

    /**
     * Check if user has the role.
     *
     * @param array user User data
     * @param string role Role name
     * @return boolean
     */
    public function hasRole(array user, string role = "login") -> boolean
    {
        return in_array(role, user["roles"]);
    }

    /**
     * Logs a user in.
     *
     * @param string username Username
     * @param string password Password
     * @param boolean remember Enable autologin (not supported)
     * @return boolean
     */
    public function login(string username, string password, boolean remember = false) -> boolean | null
    {
        var user;

        if empty password {
            return false;
        }

        if username && fetch user, this->_users[username] {
            if user["password"] === this->hash(password) {
                // Complete the login
                this->completeLogin(username, user["roles"]);

                return true;
            }

            return false;
        } else {
            // Username not specified or user not found
            return null;
        }
    }
}
