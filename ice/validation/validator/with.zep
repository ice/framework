
namespace Ice\Validation\Validator;

use Ice\Exception;
use Ice\Validation;
use Ice\Validation\Validator;

class With extends Validator
{

    public function validate(<Validation> validation, string! field)
    {
        var value, label, message, replace, fields, with, tmp, required;

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

            let replace = [":field": label, ":fields":  join(", ", required)];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        return true;
    }
}