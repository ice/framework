
namespace Ice\Validation\Validator;

use Ice\Exception;
use Ice\Validation;
use Ice\Validation\Validator;

/**
 * Without validator.
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
 *      'password' => [
 *          'without' => [
 *              'fields' => ['newPassword'],
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
class Without extends Validator
{

    /**
     * Validate the validator
     * Options: fields (0,1,2..), label, message
     *
     * @param Validation validation
     * @param string field
     * @return boolean
     */
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var value, label, message, i18n, replace, fields, without, tmp, except, key, translate;

        let value = validation->getValue(field);

        if value === "" || value === null {
            return true;
        }
        
        let fields = this->getOptions(Validator::NUMERIC),
            except = [];

        if empty fields {
            let fields = this->get("fields");
        }

        if typeof fields != "array" {
            throw new Exception("Fields must be an array");
        }

        for without in fields {
            let tmp = validation->getValue(without);

            if tmp !== "" && tmp !== null {
                let except[] = without;
            }
        }

        if count(except) {
            if this->has("label") {
                let label = this->get("label");
            } else {
                let label = validation->getLabel(field);
            }

            if this->has("message") {
                let message = this->get("message");
            } else {
                let message = validation->getDefaultMessage("without");
            }

            // Translate strings
            if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                let i18n = validation->getDi()->get("i18n"),
                    label = i18n->translate(label),
                    message = i18n->translate(message);

                for key, translate in except {
                    let except[key] = i18n->translate(translate);
                }
            }

            let replace = [":field": label, ":fields":  join(", ", except)];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        return true;
    }
}
