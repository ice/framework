
namespace Ice\Config;

use Ice\Config;

class Ini extends Config
{

    /**
     * Config Ini adapter constructor
     *
     * @param string $file
     */
    public function __construct(string file = null)
    {
        var ini;

        let ini = parse_ini_file(file, true),
            ini = this->arrayMapRecursive([this, "cast"], ini);

        parent::__construct(ini);
    }

    /**
     * Return real type from string
     * eg "true" => true
     *
     * @param string $value
     * @return mixed
     */
    public function cast(value)
    {
        if typeof value == "string" {
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

    private function arrayMapRecursive(callback, data)
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