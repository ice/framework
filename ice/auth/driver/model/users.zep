
namespace Ice\Auth\Driver\Model;

use Ice\Auth\Driver\Model\Roles;
use Ice\Mvc\Model;

/**
 * Model Users.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Users extends Model
{

    /**
     * Initialize user's relations.
     *
     * @return void
     */
    public function initialize()
    {
        this->hasMany(this->getIdKey(), "Ice\\Auth\\Driver\\Model\\Users\\Tokens", "user_id", [
            "alias": "Tokens"
        ]);

        this->hasMany(this->getIdKey(), "Ice\\Auth\\Driver\\Model\\Roles\\Users", "user_id", [
            "alias": "Roles"
        ]);

        this->hasOne(this->getIdKey(), "Ice\\Auth\\Driver\\Model\\Users\\Social", "user_id", [
            "alias": "Social"
        ]);
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

        let role = <Roles> Roles::findOne(["name": name]);

        if !role {
            // Role does not exist
            return null;
        }

        let roles = this->{"getRoles"}(["role_id": role->getId()]);

        // Return the role if user has the role otherwise false
        return roles->count() ? roles->getIterator()->current() : false;
    }
}
