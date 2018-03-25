
namespace Ice\Validation\Validator;

use Ice\Exception;
use Ice\Validation;
use Ice\Validation\Validator;

/**
 * With validator.
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
 *      'repeatPassword' => [
 *          'with' => [
 *              'fields' => ['password'],
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
class With extends Validator
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
        var value, label, message, i18n, replace, fields, with, tmp, required, key, translate;

        let value = validation->getValue(field);

        if value === "" || value === null {
            return true;
        }
        
        let fields = this->getOptions(Validator::NUMERIC),
            required = [];

        if empty fields {
            let fields = this->get("fields");
        }

        if typeof fields != "array" {
            throw new Exception("Fields must be an array");
        }

        for with in fields {
            let tmp = validation->getValue(with);

            if tmp === "" || tmp === null {
                let required[] = with;
            }
        }

        if count(required) {
            if this->has("label") {
                let label = this->get("label");
            } else {
                let label = validation->getLabel(field);
            }

            if this->has("message") {
                let message = this->get("message");
            } else {
                let message = validation->getDefaultMessage("with");
            }

            // Translate strings
            if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                let i18n = validation->getDi()->get("i18n"),
                    label = i18n->translate(label),
                    message = i18n->translate(message);

                for key, translate in required {
                    let required[key] = i18n->translate(translate);
                }
            }

            let replace = [":field": label, ":fields":  join(", ", required)];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        return true;
    }
}
