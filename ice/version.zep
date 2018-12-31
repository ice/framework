
namespace Ice;

/**
 * Get version of the framework.
 *
 * @package     Ice/Version
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @see         http://semver.org (Semantic Versioning 2.0.0)
 */
class Version
{

    const DEV = 0;
    const ALPHA = 1;
    const BETA = 2;
    const RC = 3;
    const STABLE = 4;
    // Don't forget to update config.json and run zephir fullclean
    const MAJOR = 1;
    const MINOR = 4;
    const PATCH = 1;
    const STAGE = self::STABLE;
    const BUILD = 0;

    /**
     * Get version array.
     *
     * @return array
     */
    public static function current() -> array
    {
        return [
            "major": self::MAJOR,
            "minor": self::MINOR,
            "patch": self::PATCH,
            "stage": self::STAGE,
            "build": self::BUILD
        ];
    }

    /**
     * Get version string.
     *
     * 1.0.0-dev
     * 1.0.0-alpha.3
     * 1.0.0-beta.2
     * 1.0.0-rc.5
     * 1.0.0
     *
     * @return string
     */
    public static function get() -> string
    {
        var suffix;

        switch self::STAGE {
            case self::DEV:
                let suffix = "-dev";
            break;
            case self::ALPHA:
                let suffix = "-alpha." . self::BUILD;
            break;
            case self::BETA:
                let suffix = "-beta." . self::BUILD;
            break;
            case self::RC:
                let suffix = "-rc." . self::BUILD;
            break;
            case self::STABLE:
                let suffix = "";
            break;
        }

        return self::MAJOR . "." . self::MINOR . "." . self::PATCH . suffix;
    }

    /**
     * Get version id.
     *
     * [major][minor(2 digits)][patch (2 digits)][stage][build]
     * eg. id for 1.4.12-rc.5 is 1041235
     *
     * @return int
     */
    public static function id() -> int
    {
        var id;

        let id =
            self::MAJOR .
            sprintf("%02s", self::MINOR) .
            sprintf("%02s", self::PATCH) .
            self::STAGE .
            self::BUILD;

        return (int) id;
    }
}
