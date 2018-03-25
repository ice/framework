
namespace Ice\Validation\Validator;

use Ice\Validation;
use Ice\Validation\Validator;

/**
 * Same validator.
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
 *      'email' => 'required|email',
 *      'repeatEmail' => 'same:email'
 *  ]);
 *  
 *  $valid = $validation->validate($_POST);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
class Same extends Validator
{

    /**
     * Validate the validator
     * Options: other (0), allowEmpty (1), label, labelOther, message
     *
     * @param Validation validation
     * @param string field
     * @return boolean
     */
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var value, allowEmpty, label, message, i18n, replace, other, valueOther, labelOther;

        let value = validation->getValue(field);

        if this->has(1) {
            let allowEmpty = this->get(1);
        } else {
            let allowEmpty = this->get("allowEmpty");
        }

        if allowEmpty && (value === "" || value === null) {
            return true;
        }

        if this->has(0) {
            let other = this->get(0);
        } else {
            let other = this->get("other");
        }

        if validation->hasValue(other) {
            let valueOther = validation->getValue(other);
        } else {

            let valueOther = other;
        }

        if value != valueOther {
            if this->has("label") {
                let label = this->get("label");
            } else {
                let label = validation->getLabel(field);
            }

            if this->has("labelOther") {
                let labelOther = this->get("labelOther");
            } else {
                let labelOther = validation->getLabel(other);
            }

            if this->has("message") {
                let message = this->get("message");
            } else {
                let message = validation->getDefaultMessage("same");
            }

            // Translate strings
            if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                let i18n = validation->getDi()->get("i18n"),
                    label = i18n->translate(label),
                    labelOther = i18n->translate(labelOther),
                    message = i18n->translate(message);
            }

            let replace = [":field": label, ":other": labelOther];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        return true;
    }
}
