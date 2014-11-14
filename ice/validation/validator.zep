
namespace Ice\Validation;

use Ice\Validation;

abstract class Validator
{
    
    protected _options = [];

    const ALL = 0;
    const NUMERIC = 1;
    const STRINGS = 2;

    public function __construct(array options = [])
    {
        let this->_options = options;
    }

    public abstract function validate(<Validation> validation, string! field);

    public function has(var key) -> boolean
    {
        return isset this->_options[key];
    }

    public function get(var key, var defaultValue = null)
    {
        var value;

        if fetch value, this->_options[key] {
            return value;
        }

        return defaultValue;
    }

    public function set(var key, var value)
    {
        let this->_options[key] = value;
    }

    public function getOptions(keys = self::ALL, array options = [])
    {
        var key, value;

        for key, value in this->_options {
            switch keys {
                case self::NUMERIC: 
                    if typeof key == "integer" {
                        let options[key] = value;
                    }
                break;
                case self::STRINGS: 
                    if typeof key == "string" {
                        let options[key] = value;
                    }
                break;
                default:
                    let options[key] = value;
                break;
            }
        }

        return options;
    }
}