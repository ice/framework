
namespace Ice\Validation\Validator;

use Ice\Di;
use Ice\Validation;
use Ice\Validation\Validator;
use Ice\Db\Driver\Mongodb;

/**
 * Unique validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *  
 *  $validation->rules([
 *      'userName' => [
 *          'unique' => [
 *              'from' => 'users',
 *              'custom' => 'username'
 *          ],
 *      ]
 *  ]);
 *  
 *  $valid = $validation->validate($_POST);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
class Unique extends Validator
{

    /**
     * Validate the validator
     * Options: from (0), custom (1), except (2), caseInsensitive (3), label, message
     *
     * @param Validation validation
     * @param string field
     * @return boolean
     */
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var value, label, message, i18n, replace, di, db, from, custom, except, tmp, caseInsensitive, result, id;

        let value = validation->getValue(field);

        if value === "" || value === null {
            return true;
        }

        let di = Di::$fetch(),
            db = di->get("db");

        if this->has(0) {
            let from = this->get(0);
        } else {
            let from = this->get("from");
        }

        // Specifying a custom column name
        if this->has(1) {
            let custom = this->get(1);
        } else {
            let custom = this->get("custom");
        }
        if empty custom {
            let custom = field;
        }

        // Forcing a unique rule to ignore a given value
        if this->has(2) {
            let except = this->get(2);
        } else {
            let except = this->get("except");
        }

        // Case insensitive
        if this->has(3) {
            let caseInsensitive = this->get(3);
        } else {
            let caseInsensitive = this->get("caseInsensitive");
        }

        if caseInsensitive {
            let tmp = value;

            if db->getType() == "NOSQL" {
                if db->getDriver() instanceof Mongodb {
                    let value = new \MongoDB\BSON\Regex("^" . tmp . "$", "i");
                } else {
                    let value = new \MongoRegex("/^" . tmp . "$/i");
                }
            } else {
                // TODO: LOWER column name
                let value = strtolower(tmp);
            }
        }

        if except {
            let id = ["!=": db->getIdValue(except)],
                result = db->findOne(from, [custom: value, db->getId(): id]);
        } else {
            let result = db->findOne(from, [custom: value]);
        }

        if result {
            if this->has("label") {
                let label = this->get("label");
            } else {
                let label = validation->getLabel(field);
            }

            if this->has("message") {
                let message = this->get("message");
            } else {
                let message = validation->getDefaultMessage("unique");
            }

            // Translate strings
            if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                let i18n = validation->getDi()->get("i18n"),
                    label = i18n->translate(label),
                    message = i18n->translate(message);
            }

            let replace = [":field": label];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        return true;
    }
}
