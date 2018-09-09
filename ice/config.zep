
namespace Ice;

/**
 * Wrapper for configuration arrays.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Config extends Arr
{

    /**
     * Config constructor.
     *
     * @param array data Initial config
     */
    public function __construct(var data = null)
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
                    let this->data[key] = value;
                } else {
                    let this->data[key] = new Config(value);
                }
            } else {
                let this->data[key] = value;
            }
        }
    }
    
    /**
     * Load config from php file, which must return an array.
     *
     * @param string file The path of the config
     * @return object Config
     */
    public static function load(string file)
    {
        var config;

        if file_exists(file) {
            let config = require file;
            return new Config(config);
        }
        
        throw new Exception(["Config file '%s' doesn't exist", file]);
    }
    
}
