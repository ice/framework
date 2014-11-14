
namespace Ice\Validation\Validator;

use Ice\Exception;
use Ice\Validation;
use Ice\Validation\Validator;

class Without extends Validator
{

    public function validate(<Validation> validation, string! field)
    {
        var value, label, message, replace, fields, without, tmp, except;

        let value = validation->getValue(field);

        if value === "" || value === null {
            return true;
        }
        
        let fields = this->getOptions(Validator::NUMERIC),
            except = [];

        if empty fields {
            let fields = this->get("fields");
        }

        if typeof fields != "array" {
            throw new Exception("Fields must be an array");
        }

        for without in fields {
            let tmp = validation->getValue(without);

            if tmp !== "" && tmp !== null {
                let except[] = without;
            }
        }

        if count(except) {
            if this->has("label") {
                let label = this->get("label");
            } else {
                let label = validation->getLabel(field);
            }

            if this->has("message") {
                let message = this->get("message");
            } else {
                let message = validation->getDefaultMessage("without");
            }

            let replace = [":field": label, ":fields":  join(", ", except)];

            validation->addMessage(field, strtr(message, replace));
            return false;
        }

        return true;
    }
}