
namespace Ice\Http;

use Ice\Arr;

class Request extends Arr
{

    protected _files;
    protected _get;
    protected _post;
    protected _server;

    public function __construct()
    {
        let this->_files = new Arr(_FILES),
            this->_get = new Arr(_GET),
            this->_post = new Arr(_POST),
            this->_server = new Arr(_SERVER);

        parent::__construct(_REQUEST);
    }

    public function hasRequest(string! name) -> boolean
    {
        return this->has(name);
    }

    public function hasPost(string! name) -> boolean
    {
        return this->_post->has(name);
    }

    public function hasGet(string! name) -> boolean
    {
        return this->_get->has(name);
    }

    public final function hasServer(string! name) -> boolean
    {
        return this->_server->has(name);
    }

    public function isPost() -> boolean
    {
        return this->getMethod() == "POST";
    }

    public function isGet() -> boolean
    {
        return this->getMethod() == "GET";
    }

    public function isPut() -> boolean
    {
        return this->getMethod() == "PUT";
    }

    public function isPatch() -> boolean
    {
        return this->getMethod() == "PATCH";
    }

    public function isHead() -> boolean
    {
        return this->getMethod() == "HEAD";
    }

    public function isDelete() -> boolean
    {
        return this->getMethod() == "DELETE";
    }

    public function isOptions() -> boolean
    {
        return this->getMethod() == "OPTIONS";
    }

    public function isAjax() -> boolean
    {
        return this->_server->get("HTTP_X_REQUESTED_WITH") == "XMLHttpRequest";
    }

    public final function getMethod() -> string
    {
        return this->_server->get("REQUEST_METHOD", "");
    }

    public function getUserAgent() -> string
    {
        return this->_server->get("HTTP_USER_AGENT", "");
    }

    public function getHTTPReferer() -> string
    {
        return this->_server->get("HTTP_REFERER", "");
    }

    public function getGet(string key = null, var defaultValue = null)
    {
        return key ? this->_get->get(key, defaultValue) : this->_get->all();
    }

    public function getPost(string key = null, var defaultValue = null)
    {
        return key ? this->_post->get(key, defaultValue) : this->_post->all();
    }

    public function getServer(string key = null, var defaultValue = null)
    {
        return key ? this->_server->get(key, defaultValue) : this->_server->all();
    }
}