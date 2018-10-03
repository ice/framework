
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
        // algorithms are currently supported: PASSWORD_DEFAULT, PASSWORD_BCRYPT and PASSWORD_ARGON2I
        "hash_method": PASSWORD_BCRYPT,
        "hash_option": [],
        // DEPRECATED in 2.0
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
        if typeof this->options["hash_method"] == "string" {
            return hash_equals(this->hash(password), hash);
        } else {
            return password_verify(password, hash);
        }
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
     * Assigns a value to the specified options.
     *
     * @param string key The option key
     * @param mixed value
     * @return object self
     */
    public function setOption(string key, var value)
    {
        let this->options[key] = value;

        return this;
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
        if typeof this->options["hash_method"] == "string" {
            return hash_hmac(this->options["hash_method"], password, this->options["hash_key"]);
        } else {
            return password_hash(password, this->options["hash_method"], this->options["hash_option"]);
        }
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
