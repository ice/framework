
namespace Ice\Validation\Validator;

use Ice\Validation;
use Ice\Validation\Validator;

class Required extends Validator
{

    public function validate(<Validation> validation, string! field)
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