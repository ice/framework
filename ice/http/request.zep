
namespace Ice\Http;

use Ice\Arr;
use Ice\Di;
use Ice\Http\Request\RequestInterface;

/**
 * Inspect the current HTTP request.
 *
 * @package     Ice/Http
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Request extends Arr implements RequestInterface
{

    protected files;
    protected get;
    protected post;
    protected server;

    /**
     * Request constructor. Fetch data from globals variables: _REQUEST, _SERVER, _POST, _GET and _FILES.
     */
    public function __construct()
    {
        let this->files = new Arr(_FILES),
            this->get = new Arr(_GET),
            this->post = new Arr(_POST),
            this->server = new Arr(_SERVER);

        parent::__construct(_REQUEST);
    }

    /**
     * Check whether _REQUEST has index.
     *
     * @param string name Index name
     * @return boolean
     */
    public function hasRequest(string! name) -> boolean
    {
        return this->has(name);
    }

    /**
     * Check whether _POST has index.
     *
     * @param string name Index name
     * @return boolean
     */
    public function hasPost(string! name) -> boolean
    {
        return this->post->has(name);
    }

    /**
     * Check whether _GET has index.
     *
     * @param string name Index name
     * @return boolean
     */
    public function hasGet(string! name) -> boolean
    {
        return this->get->has(name);
    }

    /**
     * Check whether _SERVER has index.
     *
     * @param string name Index name
     * @return boolean
     */
    public function hasServer(string! name) -> boolean
    {
        return this->server->has(name);
    }

    /**
     * Check whether _FILES has index.
     *
     * @param string name Index name
     * @return boolean
     */
    public function hasFile(string! name) -> boolean
    {
        return this->files->has(name);
    }

    /**
     * Checks whether HTTP method is POST.
     *
     * @return boolean
     */
    public function isPost() -> boolean
    {
        return this->getMethod() == "POST";
    }

    /**
     * Checks whether HTTP method is GET.
     *
     * @return boolean
     */
    public function isGet() -> boolean
    {
        return this->getMethod() == "GET";
    }

    /**
     * Checks whether HTTP method is PUT.
     *
     * @return boolean
     */
    public function isPut() -> boolean
    {
        return this->getMethod() == "PUT";
    }

    /**
     * Checks whether HTTP method is PATCH.
     *
     * @return boolean
     */
    public function isPatch() -> boolean
    {
        return this->getMethod() == "PATCH";
    }

    /**
     * Checks whether HTTP method is HEAD.
     *
     * @return boolean
     */
    public function isHead() -> boolean
    {
        return this->getMethod() == "HEAD";
    }

    /**
     * Checks whether HTTP method is DELETE.
     *
     * @return boolean
     */
    public function isDelete() -> boolean
    {
        return this->getMethod() == "DELETE";
    }

    /**
     * Checks whether HTTP method is OPTIONS.
     *
     * @return boolean
     */
    public function isOptions() -> boolean
    {
        return this->getMethod() == "OPTIONS";
    }

    /**
     * Checks whether request has been made using AJAX.
     *
     * @return boolean
     */
    public function isAjax() -> boolean
    {
        return this->server->get("HTTP_X_REQUESTED_WITH") == "XMLHttpRequest";
    }

    /**
     * Gets HTTP method which request has been made.
     *
     * @return string
     */
    public function getMethod() -> string
    {
        return this->server->get("REQUEST_METHOD", "");
    }

    /**
     * Gets HTTP user agent used to made the request.
     *
     * @return string
     */
    public function getUserAgent() -> string
    {
        return this->server->get("HTTP_USER_AGENT", "");
    }

    /**
     * Gets web page that refers active request.
     *
     * @return string
     */
    public function getHTTPReferer() -> string
    {
        return this->server->get("HTTP_REFERER", "");
    }

    /**
     * Gets most possible client IPv4 Address.
     *
     * @return string
     */
    public function getClientAddress() -> string
    {
        var client, forward, remote, ip;

        let client = this->server->get("HTTP_CLIENT_IP"),
            forward = this->server->get("HTTP_X_FORWARDED_FOR"),
            remote = this->server->get("REMOTE_ADDR");

        if filter_var(client, FILTER_VALIDATE_IP) {
            let ip = client;
        } elseif filter_var(forward, FILTER_VALIDATE_IP) {
            let ip = forward;
        } else {
            let ip = remote;
        }

        return ip;
    }

    /**
     * Gets variable from _GET superglobal applying filters if needed.
     * If no parameters are given, return all.
     *
     * <pre><code>
     *  //Returns value from $_GET["id"] without sanitizing
     *  $id = $this->request->getQuery("id");
     *
     *  //Returns value from $_GET["title"] with sanitizing
     *  $title = $this->request->getQuery("title", "escape|repeats");
     *
     *  //Returns value from $_GET["id"] with a default value
     *  $id = $this->request->getQuery("id", null, 150);
     * </code></pre>
     *
     * @param string key Index to get
     * @param string|array filters Filters to apply
     * @param mixed defaultValue Default value if key not exist or value is empty and allowEmpty is false
     * @param boolean allowEmpty
     * @return mixed
     */
    public function getQuery(string key = null, var filters = null, var defaultValue = null, boolean allowEmpty = true)
    {
        if !key {
            // Remove `_url` from GET
            this->get->set("_url", null);
            this->get->remove("_url");

            return this->get;
        } else {
            return this->get->getValue(key, filters, defaultValue, allowEmpty);
        }
    }

    /**
     * Gets variable from _POST superglobal applying filters if needed.
     * If no parameters are given, return all.
     *
     * <pre><code>
     *  //Returns value from $_POST["id"] without sanitizing
     *  $id = $this->request->getPost("id");
     *
     *  //Returns value from $_POST["title"] with sanitizing
     *  $title = $this->request->getPost("title", "escape|repeats");
     *
     *  //Returns value from $_POST["id"] with a default value
     *  $id = $this->request->getPost("id", null, 150);
     * </code></pre>
     *
     * @param string key Index to get
     * @param string|array filters Filters to apply
     * @param mixed defaultValue Default value if key not exist or value is empty and allowEmpty is false
     * @param boolean allowEmpty
     * @return mixed
     */
    public function getPost(string key = null, var filters = null, var defaultValue = null, boolean allowEmpty = true)
    {
        if !key {
            return this->post;
        } else {
            return this->post->getValue(key, filters, defaultValue, allowEmpty);
        }
    }

    /**
     * Gets variable from _SERVER superglobal.
     *
     * @param string key
     * @param mixed defaultValue
     * @return mixed
     */
    public function getServer(string key = null, var defaultValue = null)
    {
        return key ? this->server->get(key, defaultValue) : this->server;
    }

    /**
     * Gets variable from _FILES superglobal.
     *
     * @param string key
     * @param mixed defaultValue
     * @return mixed
     */
    public function getFiles(string key = null, var defaultValue = null)
    {
        return key ? this->files->get(key, defaultValue) : this->files;
    }
}
