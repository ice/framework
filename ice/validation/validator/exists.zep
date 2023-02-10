
namespace Ice\Validation\Validator;

use Ice\Di;
use Ice\Validation;
use Ice\Validation\Validator;
use Ice\Db\Driver\Mongodb;

/**
 * Exists validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2023 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *
 *  $validation->rules([
 *      'userName' => [
 *          'exists' => [
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
class Exists extends Validator
{
    /**
     * Validate the validator
     * Options: from (0), custom (1), insensitive (2), label, message
     *
     * @param Validation validation
     * @param string field
     * @return boolean
     */
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var value, label, message, i18n, replace, di, db, from, custom, insensitive, options, result;

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

        // Case insensitive
        if this->has(2) {
            let insensitive = this->get(2);
        } else {
            let insensitive = this->get("insensitive");
        }

        let options = insensitive ? ["insensitive": true] : [],
            result = db->findOne(from, [custom: value], options);

        if !result {
            if this->has("label") {
                let label = this->get("label");
            } else {
                let label = validation->getLabel(field);
            }

            if this->has("message") {
                let message = this->get("message");
            } else {
                let message = validation->getDefaultMessage("exists");
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
