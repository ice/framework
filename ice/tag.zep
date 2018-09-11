
namespace Ice;

/**
 * Tag helper is designed to simplify building of HTML tags.
 *
 * @package     Ice/Tag
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        Ice\Mvc\Url
 */
class Tag
{

    const HTML32 = 1;
    const HTML401_STRICT = 2;
    const HTML401_TRANSITIONAL = 3;
    const HTML401_FRAMESET = 4;
    const HTML5 = 5;
    const XHTML10_STRICT = 6;
    const XHTML10_TRANSITIONAL = 7;
    const XHTML10_FRAMESET = 8;
    const XHTML11 = 9;
    const XHTML20 = 10;
    const XHTML5 = 11;

    protected di { get };
    protected values { get };
    protected docType = 5 { set };
    protected title = null { set, get };
    protected titleSeparator = " - " { set, get };
    protected meta = [] { set, get };
    protected escape = true { set };

    /**
     * Tag constructor. Fetch Di and set it as a property.
     */
    public function __construct()
    {
        let this->di = Di::$fetch();
    }

    /**
     * Appends a text to current document title.
     *
     * @param string title
     * @param string separator
     * @return object Tag
     */
    public function appendTitle(string title, string separator = null)
    {
        let this->title = this->title . (separator ? separator : this->titleSeparator) . title;
        
        return this;
    }

    /**
     * Prepends a text to current document title.
     *
     * @param string title
     * @param string separator
     * @return object Tag
     */
    public function prependTitle(string title, string separator = null)
    {
        let this->title = title . (separator ? separator : this->titleSeparator) . this->title;
        
        return this;
    }

    /**
     * Add meta tag to the container.
     *
     * @param array parameters
     * @return object this
     */
    public function addMeta(array parameters) -> object
    {
        let this->meta[] = this->meta(parameters);

        return this;
    }

    /**
     * Builds a HTML INPUT[type="text"] tag.
     *
     * <pre><code>
     *  // Phtml <input type="text" id="some" name="some" value="some_value">
     *  $this->tag->textField(['some', 'some_value']);
     *  
     *  // Sleet <input type="text" id="some1" name="some" value="some_value" class="field" style="width: 100%">
     *  {{ text_field(['some', 'some_value', 'id' => 'some1', 'class' => 'field', 'style' => 'width: 100%']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function textField(array parameters) -> string
    {
        return this->input("text", parameters);
    }

    /**
     * Builds a HTML INPUT[type="password"] tag.
     *
     * <pre><code>
     *  // Phtml <input type="password" id="pass" name="pass" class="form-control">
     *  $this->tag->passwordField(['pass', 'class': 'form-control']);
     *  
     *  // Sleet <input type="password" id="pass" name="pass" placeholder="My secret password">
     *  {{ password_field(['pass', 'placeholder': 'My secret password']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function passwordField(array parameters) -> string
    {
        return this->input("password", parameters);
    }

    /**
     * Builds a HTML INPUT[type="hidden"] tag.
     *
     * <pre><code>
     *  // Phtml <input type="hidden" id="secret" name="secret" value="some value">
     *  $this->tag->hiddenField(['secret', 'some value']);
     *  
     *  // Sleet <input type="hidden" id="my_id" name="secret" value="hidden value">
     *  {{ hidden_field(['secret', 'hidden value', 'id': 'my_id']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function hiddenField(array parameters) -> string
    {
        return this->input("hidden", parameters);
    }

    /**
     * Builds a HTML INPUT[type="file"] tag.
     *
     * <pre><code>
     *  // Sleet <input type="file" id="some" name="some" >
     *  {{ file_field(['some']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function fileField(array parameters) -> string
    {
        return this->input("file", parameters);
    }

    /**
     * Builds a HTML INPUT[type="submit"] tag.
     *
     * <pre><code>
     *  // Phtml <input type="submit" id="some" name="some" value="Submit">
     *  $this->tag->submitButton(['some', 'Submit']);
     *  
     *  // Sleet <input type="submit" id="some1" name="some" value="Submit" class="btn">
     *  {{ submit_button(['some', 'value' => 'Submit', 'id' => 'some1', 'class' => 'btn']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function submitButton(array parameters) -> string
    {
        return this->input("submit", parameters);
    }

    /**
     * Builds a HTML BUTTON tag.
     *
     * <pre><code>
     *  // Phtml <button type="submit" id="some" name="some">content</button>
     *  $this->tag->button(['some', 'content']);
     *  
     *  // Sleet <button type="button" id="some1" name="some"><i class="icon">+</i> Submit</button>
     *  {{ button(['some', '<i class="icon">+</i> ' . 'Submit', 'type' => 'button', 'id' => 'some1']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function button(array parameters) -> string
    {
        var defaultParams;

        let defaultParams = [
            "id": 0,
            "name": 0,
            "content": 1,
            "type": "submit"
        ];

        return this->tagHtml("button", parameters, defaultParams, ["content"], "content", true);
    }

    /**
     * Builds a HTML INPUT[type="checkbox"] tag.
     *
     * <pre><code>
     *  // Phtml <input type="checkbox" id="agree" name="agree" value="yes">
     *  $this->tag->checkField(['agree', 'yes']);
     *  
     *  // Sleet <input type="checkbox" id="remember" name="remember" value="on" checked="checked">
     *  {{ check_field(['remember', 'on', 'checked': 'checked']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function checkField(array parameters) -> string
    {
        return this->input("checkbox", parameters);
    }

    /**
     * Builds a HTML INPUT[type="radio"] tag.
     *
     * <pre><code>
     *  // Phtml <input type="radio" id="sex" name="sex" value="male">
     *  $this->tag->radioField(['sex', 'male']);
     *  
     *  // Sleet <input type="radio" id="sex" name="sex" value="female" checked="checked">
     *  {{ radio_field(['sex', 'female', 'checked': 'checked']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function radioField(array parameters) -> string
    {
        return this->input("radio", parameters);
    }

    /**
     * Builds generic INPUT tags.
     *
     * @param string type
     * @param array parameters
     * @return string
     */
    public function input(string type, array parameters) -> string
    {
        var defaultParams;

        let defaultParams = [
            "id": 0,
            "name": 0,
            "value": 1,
            "type": type
        ];

        return this->tagHtml("input", parameters, defaultParams, [], null, false, false, true);
    }

    /**
     * Builds a HTML FORM tag.
     *
     * <pre><code>
     *  // Phtml <form action="/post/add" method="post">
     *  $this->tag->form(['post/add']);
     *  
     *  // <form action="http://example.com" method="post">
     *  $this->tag->form(['http://example.com', 'local' => false]);
     *  
     *  // Sleet <form method="post">
     *  {{ form([false]) }}
     *  
     *  // <form action="/post/add" class="form-horizontal" method="post" enctype="multipart/form-data">
     *  {{ form(['post/add', 'enctype' => 'multipart/form-data', 'class' => 'form-horizontal']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function form(array parameters) -> string
    {
        var defaultParams, action, local;

        let defaultParams = [
            "action": 0,
            "method": "post"
        ];

        if !fetch local, parameters["local"] {
            let local = true;
        }

        if local {
            if !fetch action, parameters["action"] {
                fetch action, parameters[defaultParams["action"]];
            }

            // Send to current URL if action is false
            if action !== false {
                let parameters["action"] = this->di->get("url")->get(action);
            }
        }

        return this->tagHtml("form", parameters, defaultParams, ["local"]);
    }

    /**
     * Builds a FORM close tag.
     *
     * @return string
     */
    public function endForm() -> string
    {
        return this->endTag("form");
    }

    /**
     * Builds a HTML TEXTAREA tag.
     *
     * <pre><code>
     *  // Phtml <textarea id="description" name="description">content</textarea>
     *  $this->tag->textArea(['description', 'content']);
     *  
     *  // Sleet <textarea id="some" name="some" placeholder="Say something"></textarea>
     *  {{ text_area(['some', 'placeholder' => 'Say something']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function textArea(array parameters) -> string
    {
        var defaultParams;

        let defaultParams = [
            "id": 0,
            "name": 0,
            "content": 1
        ];

        return this->tagHtml("textarea", parameters, defaultParams, ["content", "value"], "content", true);
    }

    /**
     * Alias of the `img` method.
     */
    public function image(array parameters) -> string
    {
        return this->img(parameters);
    }

    /**
     * Builds HTML IMG tags.
     *
     * <pre><code>
     *  // Phtml <img src="/img/logo.png" alt="Logo">
     *  $this->tag->img(['img/logo.png', 'Logo']);
     *  
     *  // Sleet <img src="http://example.com/img/logo.png" alt="Logo">
     *  {{ image(['http://example.com/img/logo.png', 'Logo', 'local' => false]) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function img(array parameters) -> string
    {
        var defaultParams, src, local;

        let defaultParams = [
            "src": 0,
            "alt": 1
        ];

        if !fetch local, parameters["local"] {
            let local = true;
        }

        if local {
            if !fetch src, parameters["src"] {
                fetch src, parameters[defaultParams["src"]];
            }

            let parameters["src"] = this->di->get("url")->getStatic(src);
        }

        return this->tagHtml("img", parameters, defaultParams, ["local"], null, false, false, true);
    }

    /**
     * Alias of the `a` method.
     */
    public function linkTo(array parameters) -> string
    {
        return this->a(parameters);
    }

    /**
     * Builds a HTML A tag using framework conventions.
     *
     * <pre><code>
     *  // Phtml <a href="/post/add" title="Add a post">Add</a>
     *  $this->tag->a(['post/add', 'Add', 'Add a post']);
     *  
     *  // Sleet <a href="http://google.com">Google</a>
     *  {{ link_to(['http://google.com', 'Google', 'local' => false]) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function a(array parameters) -> string
    {
        var defaultParams, href, local, query;

        let defaultParams = [
            "href": 0,
            "text": 1,
            "title": 2
        ];

        if !fetch href, parameters["href"] {
            fetch href, parameters[defaultParams["href"]];
        }

        if !fetch local, parameters["local"] {
            let local = true;
        }

        fetch query, parameters["query"];

        let parameters["href"] = this->di->get("url")->get(href, query, local);

        return this->tagHtml("a", parameters, defaultParams, ["text", "local", "query"], "text", true);
    }

    /**
     * Builds a LINK[rel="stylesheet"] tag.
     *
     * <pre><code>
     *  // Phtml <link rel="stylesheet" type="text/css" href="/css/app.css">
     *  $this->tag->link(['css/app.css']);
     *  
     *  // Sleet <link rel="icon" type="image/x-icon" href="http://example.com/favicon.ico">
     *  {{ link(['http://example.com/favicon.ico', 'type' => 'image/x-icon', 'rel' => 'icon', 'local' => false]) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function link(array parameters) -> string
    {
        var defaultParams, href, local;

        let defaultParams = [
            "href": 0,
            "type": "text/css",
            "rel": "stylesheet"
        ];

        if !fetch local, parameters["local"] {
            let local = true;
        }

        if local {
            if !fetch href, parameters["href"] {
                fetch href, parameters[defaultParams["href"]];
            }

            let parameters["href"] = this->di->get("url")->getStatic(href);
        }

        return this->tagHtml("link", parameters, defaultParams, ["local"], null, false, true, true);
    }

    /**
     * Builds a SCRIPT[type="javascript"] tag.
     *
     * <pre><code>
     *  // Phtml <script type="text/javascript" src="/js/plugins.js"></script>
     *  $this->tag->script(['js/plugins.js']);
     *  
     *  // Sleet <script type="text/javascript">alert("OK");</script>
     *  {{ script(['content' => 'alert("OK");']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function script(array parameters) -> string
    {
        var defaultParams, src, local;

        let defaultParams = [
            "src": 0,
            "type": "text/javascript"
        ];

        if !fetch local, parameters["local"] {
            let local = true;
        }

        if local {
            if !fetch src, parameters["src"] {
                fetch src, parameters[defaultParams["src"]];
            }

            if src {
                let parameters["src"] = this->di->get("url")->getStatic(src);
            }
        }

        return this->tagHtml("script", parameters, defaultParams, ["local", "content"], "content", true) . PHP_EOL;
    }

    /**
     * Builds a STYLE tag.
     *
     * <pre><code>
     *  // Sleet <style type="text/css">body { color: #444 }</style>
     *  {{ style(['body { color: #444 }']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function style(array parameters) -> string
    {
        var defaultParams;

        let defaultParams = [
            "content": 0,
            "type": "text/css"
        ];

        return this->tagHtml("style", parameters, defaultParams, ["content"], "content", true, true);
    }

    /**
     * Builds a META tag.
     *
     * <pre><code>
     *  // Phtml <meta name="keywords" content="ice, framework">
     *  $this->tag->meta(['ice, framework', 'keywords']);
     *  
     *  // Sleet <meta property="og:description" content="Your description">
     *  {{ meta(['Your description', 'property': 'og:description']) }}
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function meta(array parameters) -> string
    {
        var defaultParams;

        let defaultParams = [
            "content": 0,
            "name": 1
        ];

        return this->tagHtml("meta", parameters, defaultParams, [], null, false, true, true);
    }

    /**
     * Builds a SELECT tag.
     *
     * <pre><code>
     *  $countries = [1 => 'England', 2 => 'Poland'];
     *  $this->tag->select('country', $countries);
     * </code></pre>
     *
     * @param array parameters
     * @return string
     */
    public function select(array parameters)
    {
        var defaultParams, name, options, option, selected, tmp, value, text, group, subvalue, subtext, suboptions;

        let defaultParams = [
            "id": 0,
            "name": 0,
            "options": 1
        ];

        if !fetch name, parameters["name"] {
            fetch name, parameters[defaultParams["name"]];
        }

        if !fetch options, parameters["options"] {
            fetch options, parameters[defaultParams["options"]];
        }

        let selected = this->hasValue(name) ? this->getValue(name) : null;

        if typeof selected == "array" {
            // This is a multi-select, god save us!
            let parameters["multiple"] = "multiple";
        }

        if typeof selected != "array" {
            if selected === null {
                // Use an empty array
                let selected = [];
            } else {
                // Convert the selected options to an array
                let tmp = [(string) selected],
                    selected = tmp;
            }
        }

        if empty options {
            // There are no options
            let options = "";
        } else {
            for value, text in options {
                if typeof text == "array" {
                    // Create a new optgroup
                    let group = ["label": value];

                    // Create a new list of options
                    let suboptions = [];

                    for subvalue, subtext in text {
                        // Force value to be string
                        let subvalue = (string) subvalue;

                        // Create a new attribute set for this option
                        let option = ["value": subvalue];

                        if in_array(subvalue, selected) {
                            // This option is selected
                            let option["selected"] = "selected";
                        }

                        // Change the option to the HTML string
                        let option["content"] = subtext,
                            suboptions[] = this->tagHtml("option", option, [], ["content"], "content", true);
                    }

                    // Compile the options into a string
                    let group["content"] = PHP_EOL . implode(PHP_EOL, suboptions) . PHP_EOL,
                        options[value] = this->tagHtml("optgroup", group, [], ["content"], "content", true);
                } else {
                    // Force value to be string
                    let value = (string) value;

                    // Create a new attribute set for this option
                    let option = ["value": value];

                    if in_array(value, selected) {
                        // This option is selected
                        let option["selected"] = "selected";
                    }

                    // Change the option to the HTML string
                    let option["content"] = text,
                        options[value] = this->tagHtml("option", option, [], ["content"], "content", true);
                }
            }

            // Compile the options into a single string
            let parameters["content"] = implode(PHP_EOL, options);
        }

        return this->tagHtml("select", parameters, defaultParams, ["content", "options", "value"], "content", true, true);
    }

    /**
     * Builds a HTML tag.
     *
     * @param string name Name of tag
     * @param array parameters Parameters like id, style
     * @param array defaultParams Default parameters
     * @param array skip Skip parameters
     * @param string content Parameter name to append content
     * @param boolean close Close tag
     * @param boolean eol Add end of line
     * @param boolean single Void element, close a tag by " />" (depending on doctype)
     * @return string
     */
    public function tagHtml(string name, array! parameters = [], array defaultParams = [], array skip = [], string content = null, boolean close = false, boolean eol = false, boolean single = false) -> string
    {
        var params, param, key, value, attributes, code;

        let attributes = [],
            params = parameters;

        for param, key in defaultParams {
            if is_numeric(key) {
                if fetch value, params[key] {
                    let attributes[param] = value;
                }
            } else {
                let attributes[param] = key;
            }
        }

        for key in defaultParams {
            unset params[key];
        }

        let attributes = array_merge(attributes, params),
            code = this->prepareTag(name, attributes, skip, single);

        if eol {
            let code .= PHP_EOL;
        }

        if content {
            // Check if textarea has a value
            if name == "textarea" && isset attributes["name"] && this->hasValue(attributes["name"]) {
                let value = this->getValue(attributes["name"]);
            } else {
                fetch value, attributes[content];
            }

            let code .= value;
        }

        if close {
            let code .= (eol ? PHP_EOL : "") . this->endTag(name, eol);
        }

        return code;
    }

    /**
     * Builds a HTML close tag.
     *
     * <pre><code>
     *  // Sleet </form>
     *  {{ end_tag('form') }}
     * </code></pre>
     *
     * @param string name
     * @param boolean eol
     * @return string
     */
    public function endTag(string name, boolean eol = true) -> string
    {
        return "</" . name . ">" . (eol ? PHP_EOL : "");
    }

    /**
     * Renders parameters keeping order in html attributes.
     *
     * @param string name
     * @param array attributes
     * @param array skip
     * @param boolean single
     * @return string
     */
    public function prepareTag(string! name, array! attributes, array skip = [], boolean single = false) -> string
    {
        var order, keys, attrs, code, type, tmp, value, key;

        let order = ["rel", "type", "for", "src", "href", "action", "id", "name", "value", "class", "style"],
            keys = array_intersect_key(array_flip(order), attributes),
            attrs = array_merge(keys, attributes),
            code = "<" . name;

        if fetch tmp, attrs["name"] {
            if this->hasValue(tmp) {
                // Set the value from values property or _post
                fetch type, attrs["type"];

                switch type {
                    case "radio":
                    case "checkbox":
                        // Don't overwrite values for radio/checkbox
                        if isset attrs["value"] && attrs["value"] == this->getValue(tmp) {
                            let attrs["checked"] = "checked";
                        }
                    break;
                    default:
                        let attrs["value"] = this->getValue(tmp);
                    break;
                }
            }
        }

        for key, value in attrs {
            if typeof key == "string" && value !== null && value !== false && !in_array(key, skip) {
                if this->escape {
                    let value = this->di->get("filter")->sanitize(value, "escape");
                }
                let code .= " " . key . "=\"" . value. "\"";
            }
        }

        if single {
            let code .= this->docType > self::HTML5 ? " />" : ">";
        } else {
            let code .= ">";
        }

        return code;
    }

    /**
     * Check if a helper has a default value set using Ice\Tag::setValues or value from _POST.
     *
     * @param string name
     * @return boolean
     */
    public function hasValue(string name) -> boolean
    {
        // Check if there is a post value for the item
        if isset _POST[name] {
            return true;
        } else {
            // Check if there is a predefined value for it
            if isset this->values[name] {
                return true;
            }
        }

        return false;
    }

    /**
     * Assigns default values to generated tags by helpers.
     *
     * @param string id
     * @param mixed value
     * @return object Tag
     */
    public function setValue(string! id, value)
    {
        if value !== null {
            if typeof value == "array" || typeof value == "object" {
                throw new Exception("Only scalar values can be assigned to UI components");
            }
        }
        let this->values[id] = value;
        
        return this;
    }

    /**
     * Assigns default values to generated tags by helpers.
     *
     * @param array values
     * @param boolean merge
     * @return object Tag
     */
    public function setValues(array values, boolean merge = false)
    {
        var current;

        if typeof values != "array" {
            throw new Exception("An array is required as default values");
        }

        if merge {
            let current = this->values;
            if typeof current == "array" {
                let this->values = array_merge(current, values);
            } else {
                let this->values = values;
            }
        } else {
            let this->values = values;
        }
        
        return this;
    }

    /**
     * Every helper calls this function to check whether a component has a predefined value using Ice\Tag::setValue
     * or value from _POST.
     *
     * @param string name
     * @return mixed
     */
    public function getValue(string name)
    {
        var value;

        // Check if there is a predefined value for it
        if !fetch value, _POST[name] {
            // Check if there is a post value for the item
            if !fetch value, this->values[name] {
                return null;
            }
        }

        return value;
    }

    /**
     * Converts texts into URL-friendly titles.
     *
     * <pre><code>
     *  $title = "Mess'd up --text-- just (to) stress /test/ ?our! `little` \\clean\\ url fun.ction!?-->";
     *  // 'messd-up-text-just-to-stress-test-our-little-clean-url-function'
     *  $friendly = $this->tag->friendlyTitle($title);
     * </code></pre>
     *
     * @param string text
     * @param string separator
     * @param boolean lowercase
     * @param mixed replace
     * @return string
     */
    public function friendlyTitle(string text, string separator = "-", boolean lowercase = true, var replace = null) -> string
    {
        var friendly, locale, search;

        if extension_loaded("iconv") {
            // Save the old locale and set the new locale to UTF-8
            let locale = setlocale(LC_ALL, "en_US.UTF-8"),
                text = iconv("UTF-8", "ASCII//TRANSLIT", text);
        }

        if replace {
            // Replace some additional chars
            if typeof replace != "array" && typeof replace != "string" {
                throw new Exception("Parameter replace must be an array or a string");
            }

            if typeof replace == "array" {
                for search in replace {
                    let text = str_replace(search, " ", text);      
                }
            } else {
                let text = str_replace(replace, " ", text);
            }
        }

        let friendly = preg_replace("/[^a-zA-Z0-9\\/_|+ -]/", "", text);

        if lowercase {
            let friendly = strtolower(friendly);
        }

        let friendly = preg_replace("/[\\/_|+ -]+/", separator, friendly),
            friendly = trim(friendly, separator);

        if extension_loaded("iconv") {
            // Revert back to the old locale
            setlocale(LC_ALL, locale);
        }
        return friendly;
    }

    /**
     * Get the document type declaration of content.
     *
     * @return string
     */
    public function getDocType() -> string
    {
        switch this->docType {
            case self::HTML32:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">" . PHP_EOL;
            case self::HTML401_STRICT:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/html4/strict.dtd\">" . PHP_EOL;
            case self::HTML401_TRANSITIONAL:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/html4/loose.dtd\">" . PHP_EOL;
            case self::HTML401_FRAMESET:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/html4/frameset.dtd\">" . PHP_EOL;
            case self::HTML5:  return "<!DOCTYPE html>" . PHP_EOL;
            case self::XHTML10_STRICT:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" . PHP_EOL;
            case self::XHTML10_TRANSITIONAL:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"" . PHP_EOL."\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">" . PHP_EOL;
            case self::XHTML10_FRAMESET:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">" . PHP_EOL;
            case self::XHTML11:  return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" . PHP_EOL . "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" . PHP_EOL;
            case self::XHTML20: return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"" . PHP_EOL . "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">" . PHP_EOL;
            case self::XHTML5:  return "<!DOCTYPE html>" . PHP_EOL;
        }

        return "";
    }
}
