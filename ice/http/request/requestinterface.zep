
namespace Ice\Http\Request;

/**
 * Request interface.
 *
 * @package     Ice/Http
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
interface RequestInterface
{

    public function hasRequest(string! name) -> boolean;

    public function hasPost(string! name) -> boolean;

    public function hasGet(string! name) -> boolean;

    public function hasServer(string! name) -> boolean;

    public function isPost() -> boolean;

    public function isGet() -> boolean;

    public function isPut() -> boolean;

    public function isPatch() -> boolean;

    public function isHead() -> boolean;

    public function isDelete() -> boolean;

    public function isOptions() -> boolean;

    public function getMethod() -> string;

    public function getUserAgent() -> string;

    public function getHTTPReferer() -> string;

    public function getQuery(string key = null, var filters = null, var defaultValue = null, boolean allowEmpty = false);

    public function getFiles(string key = null, var defaultValue = null);

    public function getPost(string key = null, var filters = null, var defaultValue = null, boolean allowEmpty = false);

    public function getServer(string key = null, var defaultValue = null);
}
