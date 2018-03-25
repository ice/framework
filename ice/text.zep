
namespace Ice;

/**
 * Text helper.
 *
 * @package     Ice/Text
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Text
{

    const ALNUM = 0;
    const ALPHA = 1;
    const HEXDEC = 2;
    const NUMERIC = 3;
    const NOZERO = 4;

    /**
     * Generates a random string based on the given type. Type is one of the constants.
     *
     * @param int type
     * @param int length
     * @return string
     */
    public function random(int type = 0, long length = 8) -> string
    {
        var pool, str = "";
        int end;

        switch type {
            case self::ALPHA:
                let pool = array_merge(range("a", "z"), range("A", "Z"));
                break;

            case self::HEXDEC:
                let pool = array_merge(range(0, 9), range("a", "f"));
                break;

            case self::NUMERIC:
                let pool = range(0, 9);
                break;

            case self::NOZERO:
                let pool = range(1, 9);
                break;

            default:
                // self::ALNUM
                let pool = array_merge(range(0, 9), range("a", "z"), range("A", "Z"));
                break;
        }

        let end = count(pool) - 1;

        while strlen(str) < length {
            let str .= pool[mt_rand(0, end)];
        }

        return str;
    }
}
