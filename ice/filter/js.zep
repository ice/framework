
namespace Ice\Filter;

/**
 * Minify js string.
 *
 * @package     Ice/Filter
 * @category    Minification
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 * @uses        jsmin.c www.crockford.com
 */
class Js
{

    /**
     * Minify the js.
     *
     * @param string js JS code to minify
     * @return string
     */
    public function sanitize(string js)
    {
        string min = "";
        char c;
        int i;
        char next;

        for i, c in js {
            let next = js[i],
                min .= c;
        }
        
        return min;
    }
}
