
namespace Ice\Auth\Social;

use Ice\Di;
use Ice\Exception;

/**
 * Auth social adapter.
 *
 * @package     Ice/Auth
 * @category    Adapter
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Adapter implements SocialInterface
{

    protected _accessToken { set, get };
    protected _clientId;
    protected _clientSecret;
    protected _redirectUri;
    protected _provider { get };
    protected _socialFieldsMap = [];
    protected _userInfo;
    protected _responseType = "code" { get };

    const GET = 0;
    const POST = 1;

    /**
     * Adapter constructor.
     *
     * @param array config
     * @throws Exception
     */
    public function __construct(config = [])
    {
        var clientId, clientSecret, redirectUri, tmp;

        if !count(config) {
            let tmp = Di::$fetch()->{"getConfig"}()->get("auth");

            if tmp && tmp->has(this->_provider) {
                let config = tmp->get(this->_provider)->toArray();
            }
        }

        if fetch clientId, config["client_id"] {
            let this->_clientId = clientId;
        }
        if fetch clientSecret, config["client_secret"] {
            let this->_clientSecret = clientSecret;
        }
        if fetch redirectUri, config["redirect_uri"] {
            let this->_redirectUri = redirectUri;
        }

        if !this->_clientId || !this->_clientSecret || !this->_redirectUri {
            throw new Exception(["Option `%s`, `%s`, `%s` are required", "client_id", "client_secret", "redirect_uri"]);
        }
    }

    /**
     * Magic method to get user's info.
     *
     * @param string method
     * @param mixed arguments
     * @return mixed
     */
    public function __call(string! name, arguments = null)
    {
        var key, value;

        if starts_with(name, "get") {
            let key = lcfirst(substr(name, 3));

            if this->has(key) {
                fetch value, arguments[0];
                return this->get(key, value);
            } else {
                return null;
            }
        }
    }

    /**
     * Whether or not an data exists by key.
     *
     * @param string key The data key
     * @return boolean
     */
    public function has(string key) -> boolean
    {
        // Unify the key between adapters
        if isset this->_socialFieldsMap[key] {
            let key = this->_socialFieldsMap[key];
        }

        return isset this->_userInfo[key];
    }

    /**
     * Retrieve a single key from an array.
     * If the key does not exist in the array, the default value will be returned.
     *
     * @param string key The data key
     * @param mixed defaultValue The value to return if data key does not exist
     * @return mixed
     */
    public function get(string key, var defaultValue = null)
    {
        var value;

        // Unify the key between adapters
        if isset this->_socialFieldsMap[key] {
            let key = this->_socialFieldsMap[key];
        }

        if fetch value, this->_userInfo[key] {
            return value;
        }

        return defaultValue;
    }

    /**
     * Get authentication url.
     *
     * @return string
     */
    public function getAuthUrl()
    {
        var config;

        let config = this->{"prepareAuthParams"}();

        return config["auth_url"] . "?" . urldecode(http_build_query(config["auth_params"]));
    }

    /**
     * Make curl get/post request and return result.
     *
     * @param int method
     * @param string url
     * @param array params
     * @param boolean parse
     * @return array|string
     */
    protected function call(int method = self::GET, string url, array params, boolean parse = true)
    {
        var curl, result;

        let curl = curl_init();

        if method == self::GET {
            curl_setopt(curl, CURLOPT_URL, url . "?" . urldecode(http_build_query(params)));
        } else {
            curl_setopt(curl, CURLOPT_URL, url);
            curl_setopt(curl, CURLOPT_POST, 1);
            curl_setopt(curl, CURLOPT_POSTFIELDS, urldecode(http_build_query(params)));
        }

        curl_setopt(curl, CURLOPT_RETURNTRANSFER, true);
        curl_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);

        let result = curl_exec(curl);

        curl_close(curl);

        if parse {
            let result = json_decode(result, true);
        }
        return result;
    }
}
