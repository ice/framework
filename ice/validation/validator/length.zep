
namespace Ice\Validation\Validator;

use Ice\Validation;
use Ice\Validation\Validator;

class Length extends Validator
{

    public function validate(<Validation> validation, string! field)
    {
        var value, label, message, i18n, replace, min, max, length;

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

        if function_exists("mb_strlen") {
            let length = mb_strlen(value);
        } else {
            let length = strlen(value);
        }

        if this->has("label") {
            let label = this->get("label");
        } else {
            let label = validation->getLabel(field);
        }

        if min && length < min {
            if this->has("messageMin") {
                let message = this->get("messageMin");
            } else {
                let message = validation->getDefaultMessage("lengthMin");
            }

            // Translate strings
            if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                let i18n = validation->getDi()->get("i18n"),
                    label = i18n->translate(label),
                    message = i18n->translate(message);
            }

            let replace = [":field": label, ":min":  min];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        if max && length > max {
            if this->has("messageMax") {
                let message = this->get("messageMax");
            } else {
                let message = validation->getDefaultMessage("lengthMax");
            }

            // Translate strings
            if validation->getTranslate() === true && validation->getDi()->has("i18n") {
                let i18n = validation->getDi()->get("i18n"),
                    label = i18n->translate(label),
                    message = i18n->translate(message);
            }

            let replace = [":field": label, ":max":  max];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        return true;
    }
}