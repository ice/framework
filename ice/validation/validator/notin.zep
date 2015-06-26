
namespace Ice\Validation\Validator;

use Ice\Exception;
use Ice\Validation;
use Ice\Validation\Validator;

/**
 * NotIn validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *  
 *  $validation->rules([
 *      'status' => 'notIn:unactive,removed',
 *      'username' => [
 *          'notIn' => [
 *              'values' => ['about', 'admin', 'user', 'root'],
 *              'message' => 'Field :field is reserved',
 *              'label' => 'Nick'
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
class NotIn extends Validator
{

    /**
     * Validate the validator
     * Options: label, values, message
     *
     * @param Validation validation
     * @param string field
     * @return boolean
     */
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var value, label, message, i18n, replace, values;

        let value = validation->getValue(field);

        if value === "" || value === null {
            return true;
        }

        let values = this->getOptions(Validator::NUMERIC);

        if empty values {
            let values = this->get("values");
        }

        if typeof values != "array" {
            throw new Exception("Values must be an array");
        }

        if in_array(value, values) {
            if this->has("label") {
                let label = this->get("label");
            } else {
                let label = validation->getLabel(field);
            }

            if this->has("message") {
                let message = this->get("message");
            } else {
                let message = validation->getDefaultMessage("notIn");
            }

            // Translate strings
            if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                let i18n = validation->getDi()->get("i18n"),
                    label = i18n->translate(label),
                    message = i18n->translate(message);
            }

            let replace = [":field": label, ":values":  join(", ", values)];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        return true;
    }
}
