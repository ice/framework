
namespace Ice;

/**
 * Assets helper is designed to management css/js resources.
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

    const NEVER = 0;
    const NOT_EXIST = 1;
    const IF_CHANGE = 2;
    const ALWAYS = 3;

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
        var value;

        if fetch value, this->options[key] {
            return value;
        }

        return defaultValue;
    }

    /**
     * Add resource to assets, autodetect type.
     *
     * @param mixed parameters Parameters of link/script/style
     * @param string version Version appending to the uri
     * @param string Collection Collection name
     * @param mixed minify Local minify option
     * @return object this
     */
    public function add(var parameters, string version = null, string collection = null, var minify = null)
    {
        var content, type, link;

        if typeof parameters == "string" {
            let link = parameters,
                parameters = [],
                parameters[] = link;
        }

        if !fetch content, parameters["content"] {
            fetch content, parameters[0];
        }

        fetch type, parameters["type"];

        if ends_with(content, ".css") || type == "text/css" {
            if !collection {
                let collection = "css";
            }
            this->addCss(parameters, version, collection, minify);
        } elseif ends_with(content, ".js") || type == "text/javascript" {
            if !collection {
                let collection = "js";
            }
            this->addJs(parameters, version, collection, minify);
        }

        return this;
    }

    /**
     * Add CSS resource to assets.
     *
     * @param array parameters Parameters of link/style
     * @param string version Version appending to the uri
     * @param string Collection Collection name
     * @param mixed minify Local minify option
     * @return object this
     */
    public function addCss(array! parameters, string version = null, string collection = "css", var minify = null)
    {

        var content, local, tag;

        let tag = this->di->get("tag");

        if !fetch content, parameters["content"] {
            fetch content, parameters[0];
        }

        if !fetch local, parameters["local"] {
            let local = true;
        }

        // If local minify is not set
        if minify === null {
            // Get global minify option, default is NEVER
            let minify = this->getOption("minify", self::NEVER);
        }

        // Do not minify external or minified resources
        if !local || ends_with(content, ".min.css") {
            let minify = self::NEVER;
        }

        // Check if resource is inline or in file
        if isset parameters["content"] {
            this->addToCollection(collection, tag->style(["content": minify ? this->minify(content, "css") : content]));
        } else {
            let parameters["href"] = this->prepare(content, "css", minify) . (version ? "?v=" . version : "");
            this->addToCollection(collection, tag->link(parameters));
        }

        return this;
    }

    /**
     * Add JS resource to assets.
     *
     * @param array parameters Parameters of script
     * @param string version Version appending to the uri
     * @param string Collection Collection name
     * @param mixed minify Local minify option
     * @return object this
     */
    public function addJs(array! parameters, string version = null, string collection = "js", var minify = null)
    {
        var content, local, tag;

        let tag = this->di->get("tag");

        if !fetch content, parameters["content"] {
            fetch content, parameters[0];
        }

        if !fetch local, parameters["local"] {
            let local = true;
        }

        // If local minify is not set
        if minify === null {
            // Get global minify option, default is NEVER
            let minify = this->getOption("minify", self::NEVER);
        }

        // Do not minify external or minified resources
        if !local || ends_with(content, ".min.js") {
            let minify = self::NEVER;
        }

        // Check if resource is inline or in file
        if isset parameters["content"] {
            this->addToCollection(collection, tag->script(["content": minify ? this->minify(content, "js") : content]));
        } else {
            let parameters["src"] = this->prepare(content, "js", minify) . (version ? "?v=" . version : "");
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
        var collection;

        fetch collection, this->collections[key];

        return collection ? collection : [];
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
     * @param string type Type of content
     * @param int minify Option of minify
     * @return string New path to the source
     */
    protected function prepare(string! uri, string type, var minify)
    {
        var source, target, dir, file, uriMin, destination, exist, old, minified;

        let source = this->getOption("source"),
            target = this->getOption("target"),
            dir = dirname(uri) . DIRECTORY_SEPARATOR,
            file = basename(uri, "." . type),
            uriMin = target . dir . file . ".min." . type,
            destination = source . uriMin,
            exist = false;

        switch minify {
            case self::NOT_EXIST:
                let minify = !file_exists(destination);
            break;
            case self::IF_CHANGE:
                if !file_exists(destination) {
                    let minify = true;
                } else {
                    let minify = md5_file(destination);
                }
            break;
            case self::ALWAYS:
                let minify = true;
            break;
            default: // self::NEVER:
                let minify = false;

                if this->getOption("forceMinified") {
                    let exist = file_exists(destination);
                }
            break;
        }

        if !minify {
            return exist ? uriMin : uri;
        } else {
            let minified = this->minify(file_get_contents(source . uri), type);

            // Check if file was changed
            if typeof minify == "string" {
                if minify != md5(minified) {
                    let minify = true;
                }
            }

            if minify === true {

                if !is_dir(dirname(destination)) {
                    let old = umask(0);

                    mkdir(dirname(destination), 0777, true);
                    umask(old);
                }

                if file_put_contents(destination, minified) === false {
                    throw new Exception("Directory can't be written");
                }
            }

            return uriMin;
        }
    }
}