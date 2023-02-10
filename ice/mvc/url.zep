
namespace Ice\Mvc;

use Ice\Di;

/**
 * This component allows to create URLs.
 *
 * @package     Ice/Mvc
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2023 Ice Team
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
    public function href(string uri = null) -> string
    {
        var staticUri;
        let staticUri = rtrim(this->staticUri, "/");
        if uri[0] != '/' {
            let staticUri .= "/";
        }
        return staticUri . uri;
    }

    /**
     * Alias of the `href` method.
     *
     * @deprecated
     * @see self::href()
     */
    public function getStatic(string uri = null) -> string
    {
        return this->href(uri);
    }

    /**
     * Alias of the `get` method.
     *
     * @see self::get()
     */
    public function rel(var uri = null, var args = null, boolean local = true) -> string
    {
        return this->get(uri, args, local);
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
        var queryString;

        if !local && !empty uri {
            let local = empty parse_url(uri, PHP_URL_HOST) && empty parse_url(uri, PHP_URL_SCHEME);
        }

        if local {
            // Get current URL if uri is false
            if uri === false && isset _GET["_url"] {
                let uri = _GET["_url"];
            } else {
                if !starts_with(uri, "#") && !starts_with(uri, "?")  {
                    let uri = this->getBaseUri() . uri;
                }
            }
        }

        if args {
            let queryString = http_build_query(args);
            if queryString {
                if strpos(uri, "?") !== false {
                    let uri .= "&" . queryString;
                } else {
                    let uri .= "?" . queryString;
                }
            }
        }

        return uri;
    }
}
