
namespace Ice\Config;

use Ice\Config;

/**
 * Adapter for get config from ini files.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Ini extends Config
{

    /**
     * Config ini constructor.
     *
     * @param string file Path to the ini file
     */
    public function __construct(string file = null)
    {
        var ini;

        let ini = parse_ini_file(file, true),
            ini = this->arrayMapRecursive([this, "cast"], ini);

        parent::__construct(ini);
    }

    /**
     * Return real type from a string, eg. "true" => true.
     *
     * @param string value
     * @return mixed
     */
    public function cast(value)
    {
        if typeof value == "string" {
            // Try to convert to float/int
            if !preg_match("/[^0-9.]+/", value) {
                if preg_match("/[.]+/", value) {
                    return (double) value;
                } else {
                    return (int) value;
                }
            }
            switch value {
                case "false":
                case "FALSE":
                    return false;
                case "true":
                case "TRUE":
                    return true;
                case "null":
                case "NULL":
                    return null;
                default:
                    return value;
            }
        }
        return value;
    }

    /**
     * Map the array recursively.
     *
     * @param object callback Callback to apply
     * @param array data Data to convert
     * @return array
     */
    private function arrayMapRecursive(callback, data) -> array
    {
        var key, value;

        for key, value in data {
            if typeof value == "array" {
                let data[key] = this->arrayMapRecursive(callback, data[key]);
            }
            else {
                let data[key] = call_user_func(callback, data[key]);
            }
        }
        return data;
    }
}
