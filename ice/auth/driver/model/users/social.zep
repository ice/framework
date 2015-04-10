
namespace Ice\Auth\Driver\Model\Users;

use Ice\Mvc\Model;

/**
 * Model user's social auth.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Social extends Model
{

    protected _from = "user_social";

    /**
     * Initialize relations.
     *
     * @return void
     */
    public function initialize()
    {
        var auth;

        let auth = this->getDi()->{"getAuth"}();

        this->hasOne("user_id", auth->getOption("users", "Ice\\Auth\\Driver\\Model\\Users"), this->getIdKey(), [
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
