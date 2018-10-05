
namespace Ice\Config;

use Ice\Config;
use Ice\Exception;

/**
 * Adapter for get config from ini files.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Ini extends Config
{

    /**
     * Config ini constructor.
     *
     * @param string file Path to the ini file
     */
    public function __construct(var data = null)
    {
        var ini, raw;

        if typeof data != "string" {
            throw new Exception("The file path must be a string");
        }

        let ini = parse_ini_file(data, true),
            raw = parse_ini_file(data, true, INI_SCANNER_RAW),
            data = this->map(ini, raw);

        parent::__construct(data);
    }

    /**
     * We have to cast values manually because parse_ini_file() has a poor implementation.
     *
     * @param mixed ini The array casted by `parse_ini_file`
     * @param mixed raw The same array but with raw strings
     * @return mixed
     */
    protected function cast(ini, raw)
    {
        if typeof ini == "string" {
            // Decode true
            if ini == "1" && (raw === "true" || raw === "yes" || raw === "on") {
                return true;
            }

            // Decode false
            if ini === "" && (raw === "false" || raw === "no" || raw === "off") {
                return false;
            }

            // Decode null
            if ini === "" && raw === "null" {
                return null;
            }

            // Decode float/int
            if is_numeric(ini) {
                if preg_match("/[.]+/", ini) {
                    return (double) ini;
                } else {
                    return (int) ini;
                }
            }
        }
        return ini;
    }

    /**
     * Map the array recursively.
     *
     * @param array ini
     * @param array raw
     * @return array
     */
    protected function map(ini, raw)
    {
        var key, value, data = [];

        for key, value in ini {
            if typeof value == "array" {
                let data[key] = this->map(value, raw[key]);
            } else {
                let data[key] = this->cast(value, raw[key]);
            }
        }
        return data;
    }
}
