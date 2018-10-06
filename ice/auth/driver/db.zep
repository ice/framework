
namespace Ice\Auth\Driver;

use Ice\Exception;
use Ice\Auth\Social;
use Ice\Auth\Driver;
use Ice\Auth\Driver\DriverInterface;
use Ice\Auth\Driver\Model\Roles;
use Ice\Auth\Driver\Model\Users;
use Ice\Auth\Driver\Model\Users\Tokens;
use Ice\Auth\Driver\Model\Users\Social as UserSocial;

/**
 * Auth database driver.
 *
 * @package     Ice/Auth
 * @category    Driver
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Db extends Driver implements DriverInterface
{

    /**
     * Logs a user in, based on the autologin cookie.
     *
     * @return mixed
     */
    public function autoLogin()
    {
        var token, user, userRoles, roles, role;

        let token = this->cookies->get("auth_autologin");

        if token {
            // Find the token
            let token = Tokens::findOne(["token": token]);

            if token {
                // Get user for the token
                let user = token->{"getUser"}();

                if user && token->{"useragent"} === sha1(this->request->getUserAgent()) {
                    // Get user's roles
                    let userRoles = user->{"getRoles"}(),
                        roles = [];

                    for role in iterator(userRoles) {
                        let role = <Roles> role->{"getRole"}(),
                            roles[] = role->get("name");
                    }

                    if in_array("login", roles) {
                        // Update the token to create a new unique token
                        token->update();

                        // Set the new token
                        this->cookies->set("auth_autologin", token->{"token"}, token->{"expires"});

                        // Complete the login with the found data
                        this->completeLogin(user, roles);

                        // Automatic login was successful
                        return user;
                    }
                }

                // Token is invalid
                token->delete();
            }
        }

        return false;
    }
    /**
     * Complete the login for a user by setting session data and eg. incrementing the logins.
     *
     * @param object user User Model object
     * @param array roles User's roles
     * @return void
     */
    protected function completeLogin(var user, array roles = [])
    {
        if user instanceof Users {
            user->completeLogin();

            parent::completeLogin(serialize(user), roles);
        }
    }

    /**
     * Gets the currently logged in user from the session. Returns NULL if no user is currently logged in.
     *
     * @param mixed defaultValue Default value to return if the user is currently not logged in
     * @return mixed
     */
    public function getUser(var defaultValue = null)
    {
        var data;

        if !this->user {
            let data = parent::getUser(defaultValue);

            if data === defaultValue {
                // User isn't currently logged in
                let this->user = defaultValue;
            } elseif typeof data == "string" {
                var user;

                let user = unserialize(data);

                if user instanceof Users {
                    let this->user = user;
                }
            }
        }

        if !this->user {
            let this->user = this->autoLogin();
        }

        return this->user;
    }

    /**
     * Check if user has the role.
     *
     * @param object user User Model object
     * @param string role Role name
     * @return boolean
     */
    public function hasRole(var user, string role = "login") -> boolean
    {
        if typeof user == "object" && (user instanceof Users) {
            return user->getRole(role) ? true : false;
        } else {
            throw new Exception("User must be an object");
        }
    }

    /**
     * Logs a user in.
     *
     * @param mixed username
     * @param string password
     * @param boolean remember enable autologin
     * @param boolean force login without password
     * @return boolean
     */
    public function login(var username, string password, boolean remember = false, boolean force = false) -> boolean | null
    {
        var user, users, roles, userRoles, role, token, lifetime;

        let user = null;

        if username {
            if typeof username == "object" {
                let user = username;
            } else {
                let users = this->getOption("users", "Ice\\Auth\\Driver\\Model\\Users"),
                    user = {users}::findOne(["username": username]);
            }
        } else {
            // Username not specified
            return null;
        }

        if typeof user == "object" && (user instanceof Users) {
            if empty password && !force {
                return false;
            }

            // Check if password match
            if parent::checkHash(password, user->get("password")) || force {
                let userRoles = user->{"getRoles"}(),
                    roles = [];

                for role in iterator(userRoles) {
                    let role = <Roles> role->{"getRole"}(),
                        roles[] = role->get("name");
                }

                // Check if user has `login` role
                if in_array("login", roles) {
                    if remember {
                        // Create a new autologin token
                        let lifetime = this->getOption("lifetime"),
                            token = new Tokens(),
                            token->{"user_id"} = user->getId(),
                            token->{"useragent"} = sha1(this->request->getUserAgent()),
                            token->{"created"} = time(),
                            token->{"expires"} = time() + lifetime;

                        if token->create() === true {
                            // Set the autologin cookie
                            this->cookies->set("auth_autologin", token->get("token"), token->get("expires"));
                        }
                    }

                    this->completeLogin(user, roles);

                    return true;
                }
            }

            return false;
        } else {
            // User not found
            return null;
        }
    }

    /**
     * Logs a user in through social network.
     *
     * @param mixed social
     * @param boolean remember enable autologin
     * @return boolean
     */
    public function loginBy(<Social> social, boolean remember = false)
    {
        var user, userSocial, roles, userRoles, role, token, lifetime;

        // Try to find record for this social response
        let userSocial = UserSocial::findOne(["social_id": social->get("socialId"), "type": social->getAdapter()->getProvider()]);

        // Check if record exist
        if typeof userSocial == "object" && (userSocial instanceof UserSocial) {
            let user = userSocial->{"getUser"}();

            // Check if user is valid
            if typeof user == "object" && (user instanceof Users) {
                let userRoles = user->{"getRoles"}(),
                    roles = [];

                for role in iterator(userRoles) {
                    let role = <Roles> role->{"getRole"}(),
                        roles[] = role->get("name");
                }

                // Check if user has `login` role
                if in_array("login", roles) {
                    if remember {
                        // Create a new autologin token
                        let lifetime = this->getOption("lifetime"),
                            token = new Tokens(),
                            token->{"user_id"} = user->getId(),
                            token->{"useragent"} = sha1(this->request->getUserAgent()),
                            token->{"created"} = time(),
                            token->{"expires"} = time() + lifetime;

                        if token->create() === true {
                            // Set the autologin cookie
                            this->cookies->set("auth_autologin", token->get("token"), token->get("expires"));
                        }
                    }

                    this->completeLogin(user, roles);

                    return true;
                }

                return false;
            }
        }

        // Social or user not found
        return null;
    }

    /**
     * Log a user out and remove any autologin cookies.
     *
     * @param boolean destroy Completely destroy the session
     * @param boolean logoutAll Remove all tokens for user
     * @return boolean
     */
    public function logout(boolean destroy = false, boolean logoutAll = false) -> boolean
    {
        var token, tokens, user;

        let token = this->cookies->get("auth_autologin");

        if token {
            // Delete the autologin cookie to prevent re-login
            this->cookies->remove("auth_autologin");

            // Clear the autologin token from the database
            let token = Tokens::findOne(["token": token]);

            if token {
                token->delete();
            }
        }

        if logoutAll {
            // Delete all user tokens
            let tokens = new Tokens(),
                user = this->getUser();

            if user {
                tokens->delete(["user_id": user->getId()]);
            }
        }

        return parent::logout(destroy);
    }

    /**
     * Refresh user data stored in the session.
     * Returns null if no user is currently logged in.
     *
     * @return mixed
     */
    public function refreshUser()
    {
        var user, refreshed, userRoles, userRole, roles, role;

        let user = this->getUser();

        if !user {
            return null;
        } else {
            if typeof user == "object" && (user instanceof Users) && this->getOption("session_roles") {
                // Get user's data from db
                let refreshed = user->loadOne(user->get(user->getPrimary())),
                    user = refreshed,
                    userRoles = user->{"getRoles"}(),
                    roles = [];

                for userRole in iterator(userRoles) {
                    let role = <Roles> userRole->{"getRole"}(),
                        roles[] = role->get("name");
                }

                parent::completeLogin(serialize(user), roles);

                let this->user = user;
            }
        }

        return user;
    }
}
