
namespace Ice;

/**
 * Get version of the framework
 *
 * @package     Ice/Version
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014 Ice Team
 * @license     http://iceframework.org/license
 */
class Version
{

    const DEV = 0;
    const ALPHA = 1;
    const BETA = 2;
    const RC = 3;
    const $FINAL = 4;

    /**
     * Get array version of the framework
     *
     * @return array
     */
    public static function current() -> array
    {
        // Don't forget to update config.json and run zephir fullclean
        return [
            "major": 1,
            "minor": 0,
            "patch": 0,
            "stage": Version::ALPHA,
            "build": 1
        ];
    }

    /**
     * Get version of the framework
     * 
     * 1.0.0-dev
     * 1.0.0-alpha3
     * 1.0.0-beta2
     * 1.0.0-rc5
     * 1.0.0
     *
     * @return string
     */
    public static function get() -> string
    {
        var current, suffix;

        let current = self::current();

        switch current["stage"] {
            case Version::DEV:
                let suffix = "-dev";
            break;
            case Version::ALPHA:
                let suffix = "-alpha" . current["build"];
            break;
            case Version::BETA:
                let suffix = "-beta" . current["build"];
            break;
            case Version::RC:
                let suffix = "-RC" . current["build"];
            break;
            case Version::$FINAL:
                let suffix = "";
            break;
        }

        return current["major"] . "." . current["minor"] . "." . current["patch"] . suffix;
    }

    /**
     * Get version id of the framework
     * [major][minor(2 digits)][patch (2 digits)][stage][build], eg. id for 1.4.2-rc5 is 1040235
     *
     * @return string
     */
    public static function id() -> string
    {
        var current;

        let current = self::current();

        return current["major"] . sprintf("%02s", current["minor"]) . sprintf("%02s", current["patch"]) . current["stage"] . current["build"];
    }

}
