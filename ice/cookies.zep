
namespace Ice;

/**
 * Cookie helper.
 *
 * @package     Ice/Cookies
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Cookies
{

    protected _di;
    protected _salt { get, set };
    protected _expiration = 0 { get, set };
    protected _path = "/" { get, set };
    protected _domain = null { get, set };
    protected _secure = false { get, set };
    protected _httpOnly = false { get, set };
    protected _encrypt = true { get, set };

    public function __construct(string salt = null)
    {
        let this->_di = Di::$fetch();
        let this->_salt = salt;

        //let this->_data = &_COOKIE;
    }

    /**
     * Does cookie contain a key
     *
     * @param string key The cookie key
     * @return boolean
     */
    public function has(string key) -> boolean
    {
        return isset _COOKIE[key];
    }

    /**
     * Gets the value of a signed cookie. 
     * Cookies without signatures will not be returned. If the cookie signature is present, but invalid, the cookie
     * will be deleted.
     *
     * @param string key Cookie name
     * @param mixed defaultValue Default value to return
     */
    public function get(string key, var defaultValue = null)
    {
        var cookie, tmp, hash, value;

        if !fetch cookie, _COOKIE[key] {
            return defaultValue;
        }

        // Find the position of the split between salt and contents
        if strpos(cookie, "~") !== false {
            // Separate the salt and the value
            //list (hash, value) = explode("~", cookie, 2);
            let tmp = explode("~", cookie, 2),
                hash = tmp[0],
                value = tmp[1];

            if this->salt(key, value) == hash {
                // Cookie signature is valid
                if this->_encrypt {
                    let value = this->_di->{"getCrypt"}()->decrypt(value);
                }

                return value;
            }

            // The cookie signature is invalid, delete it
            this->remove(key);
        }

        return defaultValue;
    }

    /**
     * Sets a signed cookie. 
     * Note that all cookie values must be strings and no automatic serialization will be performed!
     *
     * @param string key Name of cookie
     * @param string value Value of cookie
     * @param integer lifetime Expired time in seconds
     * @return boolean
     */
    public function set(string key, string value, int lifetime = 0)
    {
        if !lifetime {
            // Use the default expiration
            let lifetime = (int) this->_expiration;
        }

        if this->_encrypt {
            if !empty value {
                let value = this->_di->{"getCrypt"}()->encrypt(value);
            }
        }

        // Add the salt to the cookie value
        let value = this->salt(key, value) . "~" . value;

        return this->_setcookie(key, value, lifetime, this->_path, this->_domain, this->_secure, this->_httpOnly);
    }

    /**
     * Deletes a cookie by making the value NULL and expiring it.
     *
     * @param string key cookie name
     * @return boolean
     */
    public function remove(string key) -> boolean
    {
        // Remove the cookie
        unset _COOKIE[key];

        // Nullify the cookie and make it expire
        return this->_setcookie(key, null, -86400, this->_path, this->_domain, this->_secure, this->_httpOnly);
    }

    /**
     * Generates a salt string for a cookie based on the name and value.
     *
     * @param string name Name of cookie
     * @param string value Value of cookie
     * @throws Exception if salt is not configured
     * @return string
     */
    public function salt(name, value) -> string
    {
        var userAgent;

        // Require a valid salt
        if !this->_salt {
            throw new Exception("A valid cookie salt is required.");
        }

        // Determine the user agent
        let userAgent = this->_di->{"getRequest"}()->getUserAgent();

        return sha1(userAgent . name . value . this->_salt);
    }

    /**
     * Proxy for the native setcookie function - to allow mocking in unit tests so that they do not fail when headers
     * have been sent.
     *
     * @param string name
     * @param string value
     * @param integer expire
     * @param string path
     * @param string domain
     * @param boolean secure
     * @param boolean httpOnly
     * @return bool
     * @see setcookie
     */
    protected function _setcookie(string name, string value, int expire, string path, string domain, boolean secure, boolean httpOnly)
    {
        return setcookie(name, value, expire, path, domain, secure, httpOnly);
    }
}
