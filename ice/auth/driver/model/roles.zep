
namespace Ice\Auth\Driver\Model;

use Ice\Mvc\Model;

/**
 * Model Roles.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Roles extends Model
{
    /**
     * User class name.
     */
    protected userClass = "Ice\\Auth\\Driver\\Model\\Roles\\Users";

    /**
     * Initialize role's relations.
     *
     * @return void
     */
    public function initialize()
    {
        this->hasMany(this->getIdKey(), this->userClass, "role_id", ["alias": "RolesUsers"]);
    }
}
