
namespace Ice\Mvc;

use Ice\Di;

/**
 * This component allows to create URLs.
 *
 * @package     Ice/Mvc
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 */
class Url
{

    protected baseUri = "/" { get, set };
    protected staticUri = "/" { get, set };

    /**
     * Generates a URL for a static resource.
     *
     * @param string uri
     * @return string
     */
    public function getStatic(string uri = null) -> string
    {
        return this->getStaticUri() . uri;
    }

    /**
     * Generates a URL.
     *
     * @param string uri
     * @param array|object args Optional arguments to be appended to the query string
     * @param bool local
     * @return string
     */
    public function get(var uri = null, var args = null, boolean local = true) -> string
    {
        var baseUri, matched, queryString;

        if !local && !starts_with(uri, "mailto:") {
            if strstr(uri, "://") {
                let matched = preg_match("/^[^:\\/?#]++:/", uri);
                if matched {
                    let local = false;
                } else {
                    let local = true;
                }
            } else {
                let local = true;
            }
        }

        let baseUri = this->getBaseUri();

        if local {
            // Get current URL if uri is false
            if uri === false && isset _GET["_url"] {
                let uri = _GET["_url"];
            } else {
                let uri = baseUri . uri;
            }
        }

        if args {
            let queryString = http_build_query(args);
            if typeof queryString == "string" && strlen(queryString) {
                if strpos(queryString, "?") !== false {
                    let uri .= "&" . queryString;
                } else {
                    let uri .= "?" . queryString;
                }
            }
        }

        return uri;
    }
}
