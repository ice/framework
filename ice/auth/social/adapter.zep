
namespace Ice\Auth\Social;

use Ice\Di;
use Ice\Exception;

/**
 * Auth social adapter.
 *
 * @package     Ice/Auth
 * @category    Adapter
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Adapter implements SocialInterface
{

    protected options;
    protected accessToken { set, get };
    protected clientId;
    protected clientSecret;
    protected redirectUri;
    protected provider { get };
    protected socialFieldsMap = [];
    protected userInfo;
    protected responseType = "code" { get };

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
        var clientId, clientSecret, redirectUri, di, auth;

        let di = Di::$fetch();

        if !count(config) {
            let auth = di->get("config")->get("auth");

            if auth && auth->has(this->provider) {
                let config = auth->get(this->provider)->toArray();
            }
        }

        if fetch clientId, config["client_id"] {
            let this->clientId = clientId;
        }
        if fetch clientSecret, config["client_secret"] {
            let this->clientSecret = clientSecret;
        }
        if fetch redirectUri, config["redirect_uri"] {
            let this->redirectUri = di->has("url") ? di->get("url")->getStatic(redirectUri) : redirectUri;
        }

        if !this->clientId || !this->clientSecret || !this->redirectUri {
            throw new Exception(["Option `%s`, `%s`, `%s` are required", "client_id", "client_secret", "redirect_uri"]);
        }

        let this->options = config;
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
        if isset this->socialFieldsMap[key] {
            let key = this->socialFieldsMap[key];
        }

        return isset this->userInfo[key];
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
        if isset this->socialFieldsMap[key] {
            let key = this->socialFieldsMap[key];
        }

        if fetch value, this->userInfo[key] {
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
