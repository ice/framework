
namespace Ice\Auth\Driver\Model;

use Ice\Mvc\Model;

/**
 * Model Users.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Users extends Model
{
    /**
     * Role class name must extend from Ice\Auth\Driver\Model\Roles
     */
    protected roleClass = "Ice\\Auth\\Driver\\Model\\Roles";

    /**
     * Token class name must extend from Ice\Auth\Driver\Model\Users\Tokens
     */
    protected tokenClass = "Ice\\Auth\\Driver\\Model\\Users\\Tokens";

    /**
     * User class name must extend from Ice\Auth\Driver\Model\Roles\Users
     */
    protected userClass = "Ice\\Auth\\Driver\\Model\\Roles\\Users";

    /**
     * Social class name must extend from Ice\Auth\Driver\Model\Users\Social
     */
    protected socialClass = "Ice\\Auth\\Driver\\Model\\Users\\Social";

    /**
     * Initialize user's relations.
     *
     * @return void
     */
    public function initialize()
    {
        var idKey;
        let idKey = this->getIdKey();

        this->hasMany(idKey, this->tokenClass, "user_id", ["alias": "Tokens"]);

        this->hasMany(idKey, this->userClass, "user_id", ["alias": "Roles"]);

        this->hasOne(idKey, this->socialClass, "user_id", ["alias": "Social"]);
    }

    /**
     * Complete the login for a user by incrementing the logins and saving login timestamp.
     *
     * @return object this
     */
    public function completeLogin()
    {
        // Update the number of logins and last login time
        let this->{"logins"} = this->get("logins") + 1,
            this->{"lastlogin"} = time();

        this->update();

        return this;
    }

    /**
     * Get user's role.
     *
     * @param string name Role name to get
     * @return mixed
     */
    public function getRole(string name = "login")
    {
        var role, roles;

        let roles = this->roleClass,
            role = {roles}::findOne(["name": name]);

        if !role {
            // Role does not exist
            return null;
        }

        let roles = this->{"getRoles"}(["role_id": role->getId()]);

        // Return the role if user has the role otherwise false
        return roles->count() ? roles->getIterator()->current() : false;
    }
}
