
namespace Ice\Auth\Driver\Model\Users;

use Ice\Text;
use Ice\Mvc\Model;

/**
 * Model user's Tokens.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014 Ice Team
 * @license     http://iceframework.org/license
 */
class Tokens extends Model
{

    protected _from = "user_tokens";

    /**
     * Initialize token's relations, remove expired tokens
     *
     * @return void
     */
    public function initialize()
    {
        this->belongsTo("user_id", "Ice\\Auth\\Driver\\Model\\Users", "id", [
            "alias": "User",
            "foreignKey": true
        ]);

        // Do garbage collection
        if mt_rand(1, 100) === 1 {
            this->deleteExpired();
        }

        // This object has expired
        if this->has("expires") && this->get("expires") && this->get("expires") < time() {
            this->remove();
        }
    }

    /**
     * Generate a new unique token and create the token
     *
     * @return mixed
     */
    public function create(var fields = [])
    {
        let this->{"token"} = this->_generate();

        return parent::create(fields);
    }

    /**
     * Deletes all expired tokens
     *
     * @return void
     */
    public function deleteExpired()
    {
        var token, expired;

        let expired = this->load([
            "expires": ["<", time()]
        ]);

        for token in iterator(expired) {
            token->remove();
        }
    }

    /**
     * Generate a new unique token and update the token
     *
     * @return mixed
     */
    public function update(var fields = [])
    {
        let this->{"token"} = this->_generate();

        return parent::update(fields);
    }

    /**
     * Generate a new unique token
     *
     * @return string
     * @uses Text::random()
     */
    protected function _generate() -> string
    {
        var token;

        do {
            let token = sha1(uniqid(Text::random(Text::ALNUM, 32), true));
        } while Tokens::findOne(["token": token]);

        return token;
    }

}