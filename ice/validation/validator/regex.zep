
namespace Ice\Validation\Validator;

use Ice\Validation;
use Ice\Validation\Validator;

class Regex extends Validator
{

    public function validate(<Validation> validation, string! field)
    {
        var value, label, message, i18n, replace, pattern, matches, failed;

        let value = validation->getValue(field),
            matches = [];

        if value === "" || value === null {
            return true;
        }

        if this->has(0) {
            let pattern = this->get(0);
        } else {
            let pattern = this->get("pattern");
        }

        if preg_match(pattern, value, matches) {
            let failed = matches[0] != value;
        } else {
            let failed = true;
        }

        if failed {
            if this->has("label") {
                let label = this->get("label");
            } else {
                let label = validation->getLabel(field);
            }

            if this->has("message") {
                let message = this->get("message");
            } else {
                let message = validation->getDefaultMessage("regex");
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