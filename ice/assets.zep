
namespace Ice;

use Ice\Exception;

/**
 * Assets helper is designed to management css/js resources.
 * Tips for performance improvement if needed, export the assets files cache
 * and save to disk or memcache and load it before init the assets.
 *
 * <pre><code>
 *     // cache should be set before addCss or addJs. getMemCache is pseudo code!
 *     if ($cache = getMemCache('assets')) {
 *         $di->assets->setCache($cache);
 *     }
 *     $assets = $di->assets->addCss(['/css/style.css'])->addJs(['/js/script.js']);
 *     // cache should get after addCss or addJs. setMemCache is pseudo code!
 *     if ($cache = $assets->getCache())
 *         setMemCache($cache);
 *     }
 * </code></pre>
 *
 * Head ups! cache content will not be updated to the lastest version automatically.
 * A cache clear mechanism is required.
 *
 * @package     Ice/Assets
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Assets
{

    protected di;
    protected collections = [] { set, get };
    protected options = [] { set };
    protected cache = [] { get, set };

    /**
     * Assets constructor. Fetch Di and set it as a property.
     */
    public function __construct()
    {
        let this->di = Di::$fetch();
    }

    /**
     * Retrieve a single option.
     *
     * @param string key The data key
     * @param mixed defaultValue The value to return if data key does not exist
     * @return mixed
     */
    public function getOption(var key, var defaultValue = null)
    {
        return isset this->options[key] ? this->options[key] : defaultValue;
    }

    /**
     * Add resource to assets, autodetect type.
     *
     * @param mixed parameters Parameters of link/script/style
     * @param string Collection Collection name
     * @param mixed minify Local minify option
     * @return object this
     */
    public function add(var parameters, string collection = null, var minify = null)
    {
        var content, type, link;

        if typeof parameters == "string" {
            let link = parameters,
                parameters = [link];
        }

        if !fetch content, parameters["content"] {
            fetch content, parameters[0];
        }

        fetch type, parameters["type"];

        if ends_with(content, ".css") || type == "text/css" {
            if !collection {
                let collection = "css";
            }
            this->addCss(parameters, collection, minify);
        } elseif ends_with(content, ".js") || type == "text/javascript" {
            if !collection {
                let collection = "js";
            }
            this->addJs(parameters, collection, minify);
        }

        return this;
    }

    /**
     * Add CSS resource to assets.
     *
     * @param array parameters Parameters of link/style
     * @param string Collection Collection name
     * @param mixed minify Local minify option
     * @return object this
     */
    public function addCss(array! parameters, string collection = "css", var minify = null)
    {
        var content, tag, local = true;

        let tag = this->di->get("tag");

        if !fetch content, parameters["content"] {
            if fetch content, parameters[0] {
                // do not support the host of url is the same as _SERVER["HTTP_HOST"] ATM
                // the url contains any host will not minify the resource
                let local = empty parse_url(content, PHP_URL_HOST);
            } else {
                throw new Exception("There is no css content or uri in the parameters");
            }
        }

        // If local minify is not set
        if minify === null {
            // Get global minify option, default is NEVER
            let minify = this->getOption("minify", false);
        }

        // Do not minify external or minified resources
        if !local || ends_with(content, ".min.css") {
            let minify = false;
        }

        // Check if resource is inline or in file
        if isset parameters["content"] {
            this->addToCollection(collection, tag->style(["content": minify ? this->minify(content, "css") : content]));
        } else {
            if isset this->cache[content] {
                let parameters["href"] = this->cache[content];
            } else {
                let parameters["href"] = this->prepare(content, minify),
                    this->cache[content] = parameters["href"];
            }
            this->addToCollection(collection, tag->link(parameters));
        }

        return this;
    }

    /**
     * Add JS resource to assets.
     *
     * @param array parameters Parameters of script
     * @param string Collection Collection name
     * @param mixed minify Local minify option
     * @return object this
     */
    public function addJs(array! parameters, string collection = "js", var minify = null)
    {
        var content, tag, local = true;

        let tag = this->di->get("tag");

        if !fetch content, parameters["content"] {
             if fetch content, parameters[0] {
                // do not support the host of url is the same as _SERVER["HTTP_HOST"] ATM
                // the url contains any host will not minify the resource
                let local = empty parse_url(content, PHP_URL_HOST);
            } else {
                throw new Exception("There is no js content or uri in the parameters");
            }
        }

        // If local minify is not set
        if minify === null {
            // Get global minify option, default is NEVER
            let minify = this->getOption("minify", false);
        }

        // Do not minify external or minified resources
        if !local || ends_with(content, ".min.js") {
            let minify = false;
        }

        // Check if resource is inline or in file
        if isset parameters["content"] {
            this->addToCollection(collection, tag->script(["content": minify ? this->minify(content, "js") : content]));
        } else {
            if isset this->cache[content] {
                let parameters["src"] = this->cache[content];
            } else {
                let parameters["src"] = this->prepare(content, minify),
                    this->cache[content] = parameters["src"];
            }
            this->addToCollection(collection, tag->script(parameters));
        }

        return this;
    }

    /**
     * Add an asset to the collection.
     *
     * @param string key Collection name
     * @param string value Asset HTML code
     */
    public function addToCollection(key, value)
    {
        if !isset this->collections[key] {
            let this->collections[key] = [];
        }

        let this->collections[key][] = value;
    }

    /**
     * Get the CSS default collection.
     *
     * @return array
     */
    public function getCss()
    {
        return this->get("css");
    }

    /**
     * Get the JS default collection.
     *
     * @return array
     */
    public function getJs()
    {
        return this->get("js");
    }

    /**
     * Get some collection.
     *
     * @param string key Collection name
     * @return array
     */
    public function get(string key)
    {
        return isset this->collections[key] ? this->collections[key] : [];
    }

    /**
     * Minify content.
     *
     * @param string content Input text to minify
     * @param string type Type of content
     * @return string
     */
    protected function minify(string! content, type)
    {
        return this->di->get("filter")->sanitize(content, type . "min");
    }

    /**
     * Prepare resource.
     *
     * @param string uri The uri/url source path
     * @param int minify Option of minify
     * @return string New path to the source
     */
    protected function prepare(string! uri, var minify)
    {
        var source, target, file, uriMin, destination, md5Old, md5New, old, minified;

        let source = this->getOption("source"),
            target = this->getOption("target"),
            file = pathinfo(uri, PATHINFO_FILENAME | PATHINFO_EXTENSION),
            type = file["extension"],
            file = file["filename"];

        // uri is start from absolute path, try to load from document root
        if uri[0] == '/' || empty source {
            let source = _SERVER["DOCUMENT_ROOT"];
        }

        if (source[-1] != '/') {
            let source .= "/";
        }

        let uri = ltrim(uri, "/"),
            source .= uri;

        if !file_exists(source) {
            throw new Exception(["The request assets do not exist: %s", source]);
        }

        let uriMin = "/" . trim(target, "/") . "/" . dirname(uri) . "/";

        // cache min files place to document root always
        let destination = _SERVER["DOCUMENT_ROOT"] . uriMin,
            md5file = glob(destination . file . ".????????????????????????????????." . type),
            md5New = null;

        if !empty md5file {
            let md5file = md5file[0],
                md5Old = substr(md5file, strlen(md5file) - strlen(type) - 33, 32),
                md5New = md5_file(source);

            if md5Old != md5New {
                // new version found
                let md5file = null;
                // delete the old version
                unlink(md5file);
            } else {
                let uriMin .= file . "." . md5New . "." . type;
            }
        }
        if empty md5file {
            if !md5New {
                let md5New = md5_file(source);
            }

            if !is_dir(destination) {
                let old = umask(0);

                mkdir(destination, 0777, true);
                umask(old);
            }

            let uriMin .= file . "." . md5New . "." . type,
                destination = _SERVER["DOCUMENT_ROOT"] . uriMin;

            if minify {
                let minified = this->minify(file_get_contents(source), type);
                if file_put_contents(destination, minified) === false {
                    throw new Exception(["Directory can't be written: %s", destination]);
                }
            } elseif copy(source, destination) === false {
                    throw new Exception(["Directory can't be written: %s", destination]);
                }
            }
        }
        return uriMin;
    }
}
