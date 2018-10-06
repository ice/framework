
namespace Ice\Auth\Driver;

use Ice\Arr;
use Ice\Exception;
use Ice\Auth\Driver;
use Ice\Auth\Driver\DriverInterface;

/**
 * File Auth driver.
 *
 * @package     Ice/Auth
 * @category    Driver
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class File extends Driver implements DriverInterface
{

    protected users { set };

    /**
     * Gets the currently logged in user from the session. Returns NULL if no user is currently logged in.
     *
     * @param mixed defaultValue Default value to return if the user is currently not logged in
     * @return mixed
     */
    public function getUser(var defaultValue = null)
    {
        var username, user;

        if !this->user {
            let username = parent::getUser(defaultValue);

            if username === defaultValue {
                // User isn't currently logged in
                let this->user = defaultValue;
            } else {
                fetch user, this->users[username];
                let user["username"] = username,
                    this->user = user;
            }
        }

        if this->user {
            return new Arr(this->user);
        }
        return this->user;
    }

    /**
     * Check if user has the role.
     *
     * @param array user User data
     * @param string role Role name
     * @return boolean
     */
    public function hasRole(var user, string role = "login") -> boolean
    {
        if typeof user == "array" {
            return in_array(role, user["roles"]);
        } else {
            throw new Exception("User must be an array");
        }
    }

    /**
     * Logs a user in.
     *
     * @param string username Username
     * @param string password Password
     * @param boolean remember Enable autologin (not supported)
     * @param boolean force login without password
     * @return boolean
     */
    public function login(var username, string password, boolean remember = false, boolean force = false) -> boolean | null
    {
        var user;

        if typeof username != "string" {
            throw new Exception("Username must be a string");
        }

        if username && fetch user, this->users[username] {
            if empty password && !force {
                return false;
            }

            if parent::checkHash(password, user["password"]) || force {
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
