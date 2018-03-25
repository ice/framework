
namespace Ice\Validation\Validator;

use Ice\Validation;
use Ice\Validation\Validator;

/**
 * Between validator.
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
 *      'age' => 'between:18,21',
 *      'height' => [
 *          'between' => [
 *              'min' => 180,
 *              'max' => 190,
 *          ]
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
class Between extends Validator
{

    /**
     * Validate the validator
     * Options: min (0), max (1), label, message
     *
     * @param Validation validation
     * @param string field
     * @return boolean
     */
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var value, label, message, i18n, replace, min, max;

        let value = validation->getValue(field);

        if value === "" || value === null {
            return true;
        }

        if this->has(0) {
            let min = this->get(0);
        } else {
            let min = this->get("min");
        }

        if this->has(1) {
            let max = this->get(1);
        } else {
            let max = this->get("max");
        }


        if value < min || value > max {
            if this->has("label") {
                let label = this->get("label");
            } else {
                let label = validation->getLabel(field);
            }

            if this->has("message") {
                let message = this->get("message");
            } else {
                let message = validation->getDefaultMessage("between");
            }

            // Translate strings
            if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                let i18n = validation->getDi()->get("i18n"),
                    label = i18n->translate(label),
                    message = i18n->translate(message);
            }

            let replace = [":field": label, ":min":  min, ":max":  max];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        return true;
    }
}
