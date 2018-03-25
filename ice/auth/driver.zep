
namespace Ice\Auth;

use Ice\Di;

/**
 * User authorization library. Handles user login and logout, as well as secure password hashing.
 *
 * @package     Ice/Auth
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Driver
{

    protected session;
    protected cookies;
    protected request;
    protected user;
    protected options = [
        "hash_method": "sha256",
        "hash_key": "",
        "session_key": "auth_user",
        "session_roles": "auth_user_roles",
        "lifetime": 1209600
    ];

    /**
     * Loads services and configuration options.
     *
     * @param array options Config options
     * @return void
     */
    public function __construct(array options = [])
    {
        var di;

        let di = Di::$fetch(),
            this->options = array_merge(this->options, options),
            this->session = di->get("session"),
            this->cookies = di->get("cookies"),
            this->request = di->get("request");
    }

    /**
     * Checks a plain text password and its hash version to check if the password matches.
     *
     * @param string password Password plain text
     * @param string hash Hash version of password
     * @return boolean
     */
    public function checkHash(string password, string hash) -> boolean
    {
        return this->hash(password) == hash;
    }

    /**
     * Complete the login for a user by setting session data and eg. incrementing the logins.
     *
     * @param mixed user Complete the login for this user
     * @param array roles User's roles
     * @return void
     */
    protected function completeLogin(var user, array roles = [])
    {
        var sessionRoles;

        // Regenerate session_id
        this->session->regenerate();

        // Store user in session
        this->session->set(this->getOption("session_key", "auth_user"), user);

        // Check in session can improve performance
        let sessionRoles = this->getOption("session_roles");

        // Store user's roles in session
        if sessionRoles {
            this->session->set(sessionRoles, roles);
        }
    }

    /**
     * Get option value with key.
     *
     * @param string key The option key
     * @param mixed defaultValue The value to return if option key does not exist
     * @return mixed
     */
    public function getOption(string! key, var defaultValue = null)
    {
        var value;

        if fetch value, this->options[key] {
            return value;
        }
        return defaultValue;
    }

    /**
     * Gets the currently logged in user from the session. Returns NULL if no user is currently logged in.
     *
     * @param mixed defaultValue Default value to return if the user is currently not logged in.
     * @return mixed
     */
    public function getUser(var defaultValue = null)
    {
        return this->session->get(this->getOption("session_key"), defaultValue);
    }

    /**
     * Perform a hmac hash, using the configured method.
     *
     * @param string password String to hash
     * @return string
     */
    public function hash(string password)
    {
        return hash_hmac(this->getOption("hash_method"), password, this->getOption("hash_key"));
    }

    /**
     * Check if there is an active session. Optionally allows checking for a specific role.
     *
     * @param string role Role name
     * @return mixed
     */
    public function loggedIn(string role = null)
    {
        var user, sessionRoles, roles;

        // Get the user from the session
        let user = this->getUser();
        if !user {
            // User doesn't exists in the session
            return false;
        } else {
            // If we don't have a role no further checking is needed
            if !role {
                return true;
            }

            // Check if user has the role
            let sessionRoles = this->getOption("session_roles");

            if sessionRoles {
                let roles = this->session->get(sessionRoles);
                return in_array(role, roles);
            } else {
                return this->{"hasRole"}(user, role);
            }
        }
    }

    /**
     * Log out a user by removing the related session variables.
     *
     * @param boolean destroy Completely destroy the session
     * @param boolean logoutAll Remove all tokens for user
     * @return boolean
     */
    public function logout(boolean destroy = false, boolean logoutAll = false) -> boolean
    {
        var sessionRoles;

        if destroy === true {
            // Destroy the session completely
            this->session->destroy();
        } else {
            // Remove the user from the session
            this->session->remove(this->getOption("session_key"));

            let sessionRoles = this->getOption("session_roles");

            if sessionRoles {
                this->session->remove(sessionRoles);
            }

            // Regenerate session_id
            this->session->regenerate();
        }

        // Double check
        return !this->loggedIn();
    }
}
