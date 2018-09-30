
namespace Ice\Auth\Driver\Model\Roles;

use Ice\Di;
use Ice\Mvc\Model;

/**
 * Model user's Roles.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Users extends Model
{

    protected from = "roles_users";

    /**
     * User class name.
     */
    protected userClass = "Ice\\Auth\\Driver\\Model\\Users";

    /**
     * Role class name.
     */
    protected roleClass = "Ice\\Auth\\Driver\\Model\\Roles";

    /**
     * Initialize roles-users relations.
     *
     * @return void
     */
    public function initialize()
    {
        var auth;

        let auth = this->getDi()->get("auth");

        this->belongsTo("user_id", auth->getOption("users", this->userClass), this->getIdKey(), [
            "alias": "User"
        ]);

        this->belongsTo("role_id", this->roleClass, this->getIdKey(), [
            "alias": "Role"
        ]);
    }
}
