
namespace Ice\Validation\Validator;

use Ice\Validation;
use Ice\Validation\Validator;

/**
 * Required validator.
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
 *      'username' => 'required'
 *  ]);
 *  
 *  $valid = $validation->validate($_POST);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
class Required extends Validator
{

    /**
     * Validate the validator
     * Options: label, message
     *
     * @param Validation validation
     * @param string field
     * @return boolean
     */
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var value, label, message, i18n, replace;

        let value = validation->getValue(field);

        if value === "" || value === null {
            if this->has("label") {
                let label = this->get("label");
            } else {
                let label = validation->getLabel(field);
            }

            if this->has("message") {
                let message = this->get("message");
            } else {
                let message = validation->getDefaultMessage("required");
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
