
namespace Ice\Validation;

use Ice\Validation;

/**
 * Validator is a base class for validators.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Validator
{
    
    protected options = [];

    const ALL = 0;
    const NUMERIC = 1;
    const STRINGS = 2;

    /**
     * Validator constructor.
     *
     * @param array options
     */
    public function __construct(array options = [])
    {
        let this->options = options;
    }

    /**
     * Validate the validator
     *
     * @param Validation validation
     * @param string field
     */
    public abstract function validate(<Validation> validation, string! field);

    /**
     * Whether or not an option exists by key.
     *
     * @param string key The option key
     * @return boolean
     */
    public function has(var key) -> boolean
    {
        return isset this->options[key];
    }

    /**
     * Retrieve a single option.
     *
     * @param string key The data key
     * @param mixed defaultValue The value to return if data key does not exist
     * @return mixed
     */
    public function get(var key, var defaultValue = null)
    {
        var value;

        if fetch value, this->options[key] {
            return value;
        }

        return defaultValue;
    }

    /**
     * Assigns a value to the specified option.
     *
     * @param string key The data key
     * @param mixed value
     * @return object Validator
     */
    public function set(var key, var value)
    {
        let this->options[key] = value;
        
        return this;
    }

    /**
     * Get options by type.
     *
     * @param int keys Type of options
     * @param array options
     */
    public function getOptions(keys = self::ALL, array options = [])
    {
        var key, value;

        for key, value in this->options {
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
