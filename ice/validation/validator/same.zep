
namespace Ice\Validation\Validator;

use Ice\Validation;
use Ice\Validation\Validator;

class Same extends Validator
{

    public function validate(<Validation> validation, string! field)
    {
        var value, allowEmpty, label, message, replace, other, valueOther, labelOther;

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

            let replace = [":field": label, ":other": labelOther];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        return true;
    }
}