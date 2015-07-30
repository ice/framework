
namespace Ice;

/**
 * Assets helper is designed to management css/js resources.
 *
 * @package     Ice/Assets
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Assets
{

    protected di;
    protected css = [] { get };
    protected js = [] { get };
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
     * @param mixed minify Local minify option
     * @return object this
     */
    public function add(var parameters, string version = null, var minify = null)
    {
        var content, type;

        if typeof parameters == "string" {
            let content = parameters,
                parameters = [],
                parameters[] = content;
        } elseif !fetch content, parameters["content"] {
            fetch content, parameters[0];
        }

        fetch type, parameters["type"];

        if ends_with(content, ".css") || type == "text/css" {
            this->addCss(parameters, version, minify);
        } elseif ends_with(content, ".js") || type == "text/javascript" {
            this->addJs(parameters, version, minify);
        }

        return this;
    }

    /**
     * Add CSS resource to assets.
     *
     * @param array parameters Parameters of link/style
     * @param string version Version appending to the uri
     * @param mixed minify Local minify option
     * @return object this
     */
    public function addCss(array! parameters, string version = null, var minify = null)
    {

        var content, local, tag;

        let tag = this->di->get("tag", null, true);

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
            let this->css[] = tag->style(["content": minify ? this->minify(content, "css") : content]);
        } else {
            let parameters["href"] = this->prepare(content, "css", minify) . "?v=" . version,
                this->css[] = tag->link(parameters);
        }

        return this;
    }

    /**
     * Add JS resource to assets.
     *
     * @param array parameters Parameters of script
     * @param string version Version appending to the uri
     * @param mixed minify Local minify option
     * @return object this
     */
    public function addJs(array! parameters, string version = null, var minify = null)
    {
        var content, local, tag;

        let tag = this->di->get("tag", null, true);

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
            let this->js[] = tag->script(["content": minify ? this->minify(content, "js") : content]);
        } else {
            let parameters["src"] = this->prepare(content, "js", minify) . "?v=" . version,
                this->js[] = tag->script(parameters);
        }

        return this;
    }

    /**
     * Minify content
     *
     * @param string content Input text to minify
     * @param string type Type of content
     * @return string
     */
    protected function minify(string! content, type)
    {
        return this->di->get("filter", null, true)->sanitize(content, type . "min");
    }

    /**
     * Prepare resource
     *
     * @param string source The uri/url source path
     * @param string type Type of content
     * @param int minify Option of minify
     * @return string New path to the source
     */
    protected function prepare(string! source, string type, var minify)
    {
        var path, target, dir, file, sourceMin, destination, old, minified;

        let path = this->getOption("path"),
            target = this->getOption("target"),
            dir = dirname(source) . DIRECTORY_SEPARATOR,
            file = basename(source, "." . type),
            sourceMin = target . dir . file . ".min." . type,
            destination = path . sourceMin;

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
            break;
        }

        if !minify {
            return source;
        } else {
            let minified = this->minify(file_get_contents(path . source), type);

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

            return sourceMin;
        }
    }
}