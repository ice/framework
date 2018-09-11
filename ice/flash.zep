
namespace Ice;

/**
 * Shows HTML notifications related to different circumstances.
 *
 * @package     Ice/Flash
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Flash
{

    protected session;
    protected tag;
    protected options = [
        "session_key": "_flash",
        "success": ["class": "alert alert-success"],
        "info": ["class": "alert alert-info"],
        "warning": ["class": "alert alert-warning"],
        "danger": ["class": "alert alert-danger"],
        "html": true
    ] { set };

    /**
     * Flash constructor. Fetch session and tag service from the di.
     *
     * @param array options
     */
    public function __construct(array options = [])
    {
        var di;

        let di = Di::$fetch(),
            this->session = di->get("session"),
            this->tag = di->get("tag");

        if count(options) {
            let this->options = options;
        }
    }

    /**
     * Get option value with key.
     *
     * @param string key The option key
     * @param mixed defaultValue The value to return if option key does not exist
     * @return mixed
     */
    public function getOption(string! key, var defaultValue = null)
    {
        var value;

        if fetch value, this->options[key] {
            return value;
        }
        return defaultValue;
    }

    /**
     * Display the messages.
     *
     * @param boolean remove
     * @return string
     */
    public function getMessages(boolean remove = true) -> string
    {
        var key, type, message, messages, body;

        let key = this->getOption("session_key"),
            messages = this->session->get(key),
            body = "";

        if typeof messages == "array" {
            for type, message in messages {
                let body .= this->getMessage(type, message);
            }
        }

        if remove {
            this->session->remove(key);
        }

        return body;
    }

    /**
     * Get a message formatting it with HTML.
     *
     * @param string type
     * @param mixed message
     * @return string
     */
    public function getMessage(string type, var messages) -> string
    {
        var params, body, close, message;

        let params = this->getOption(type, []),
            close = this->tag->a(["#", "×", "class": "close"]),
            body = "";

        if typeof messages != "array" {
            let messages = [messages];
        }

        for message in messages {
            if this->getOption("html") {
                let body .= this->tag->tagHtml("div", params, ["content": close . message],  ["content"], "content", true, true);
            } else {
                let body .= message . PHP_EOL;
            }
        }

        return body;
    }

    /**
     * Adds a message to the flash.
     *
     * @param string type
     * @param string message
     * @return object Flash
     */
    public function message(string type, string message)
    {
        var key, messages;

        let key = this->getOption("session_key"),
            messages = this->session->get(key, []);

        if !isset messages[type] {
            let messages[type] = [];
        }

        let messages[type][] = message;

        this->session->set(key, messages);
        
        return this;
    }

    /**
     * Add success message.
     *
     * @param string message
     * @return object Flash
     */
    public function success(string message)
    {
        this->message("success", message);
        
        return this;
    }

    /**
     * Alias of success message.
     * @return object Flash
     */
    public function ok(string message)
    {
        return this->message("success", message);
    }

    /**
     * Add info message.
     *
     * @param string message
     * @return object Flash
     */
    public function info(string message)
    {
        return this->message("info", message);
    }

    /**
     * Alias of info message.
     * @return object Flash
     */
    public function notice(string message)
    {
        return this->message("info", message);
    }

    /**
     * Add warning message.
     *
     * @param string message
     * @return object Flash
     */
    public function warning(string message)
    {
        return this->message("warning", message);
    }

    /**
     * Alias of warning message.
     * @return object Flash
     */
    public function alert(string message)
    {
        return this->message("warning", message);
    }

    /**
     * Add danger message.
     *
     * @param string message
     * @return object Flash
     */
    public function danger(string message)
    {
        return this->message("danger", message);
    }

    /**
     * Alias of danger message.
     * @return object Flash
     */
    public function error(string message)
    {
        return this->message("danger", message);
    }
}
