
namespace Ice\Auth\Driver\Model\Users;

use Ice\Mvc\Model;

/**
 * Model user's social auth.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Social extends Model
{

    protected from = "user_social";

    /**
     * User class name.
     */
    protected userClass = "Ice\\Auth\\Driver\\Model\\Users";

    /**
     * Initialize relations.
     *
     * @return void
     */
    public function initialize()
    {
        var auth;

        let auth = this->getDi()->get("auth");

        this->hasOne("user_id", auth->getOption("users", this->userClass), this->getIdKey(), [
            "alias": "User"
        ]);
    }

    /**
     * Set PRIMARY key.
     *
     * @return void
     */
    public function onConstruct()
    {
        this->setPrimary(["social_id", "type"]);
    }
}
