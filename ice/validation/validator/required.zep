
namespace Ice\Validation\Validator;

use Ice\Validation;
use Ice\Validation\Validator;

class Required extends Validator
{

    public function validate(<Validation> validation, string! field)
    {
        var value, label, message, replace;

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

            let replace = [":field": label];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        return true;
    }
}