
namespace Ice\Http\Request;

interface RequestInterface
{

    public function hasRequest(string! name) -> boolean;

    public function hasPost(string! name) -> boolean;

    public function hasGet(string! name) -> boolean;

    public final function hasServer(string! name) -> boolean;

    public function isPost() -> boolean;

    public function isGet() -> boolean;

    public function isPut() -> boolean;

    public function isPatch() -> boolean;

    public function isHead() -> boolean;

    public function isDelete() -> boolean;

    public function isOptions() -> boolean;

    public final function getMethod() -> string;

    public function getUserAgent() -> string;

    public function getHTTPReferer() -> string;

    public function get(string key, var defaultValue = null);

    public function request(string key, var defaultValue = null);

    public function post(string key, var defaultValue = null);

    public function server(string key, var defaultValue = null);
}