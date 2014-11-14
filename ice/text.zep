
namespace Ice;

class Text
{

    const ALNUM = 0;
    const ALPHA = 1;
    const HEXDEC = 2;
    const NUMERIC = 3;
    const NOZERO = 4;

    /**
     * Generates a random string based on the given type. Type is one of the constants
     *
     * @param int type
     * @param int length
     * @return string
     */
    static public function random(int type = 0, long length = 8) -> string
    {
        var pool, str = "";
        int end;

        switch type {

            case Text::ALPHA:
                let pool = array_merge(range("a", "z"), range("A", "Z"));
                break;

            case Text::HEXDEC:
                let pool = array_merge(range(0, 9), range("a", "f"));
                break;

            case Text::NUMERIC:
                let pool = range(0, 9);
                break;

            case Text::NOZERO:
                let pool = range(1, 9);
                break;

            default:
                // Text::ALNUM
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