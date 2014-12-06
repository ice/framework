
namespace Ice;

class Config extends Arr
{

    public function __construct(data = null)
    {
        var key, value,hasNumericKey, subkey, subvalue;

        if typeof data != "array" {
            if data !== null {
                throw new Exception("The configuration must be an Array");
            } else {
                return;
            }
        }

        for key, value in data {
            if typeof key != "string" {
                throw new Exception("Only string keys are allowed");
            }

            if typeof value == "array" {
                let hasNumericKey = false;

                for subkey, subvalue in value {
                    if typeof subkey == "integer" {
                        let hasNumericKey = true;
                        break;
                    }
                }
                if hasNumericKey {
                    let this->_data[key] = value;
                } else {
                    let this->_data[key] = new Config(value);
                }
            } else {
                let this->_data[key] = value;
            }
        }
    }

}