
namespace Ice;

/**
 * Session helper.
 *
 * @package     Ice/Session
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Session extends Arr
{

    protected _started = false;

    /**
     * Session constructor. Start the session.
     */
    public function __construct()
    {
        this->start();

        //let this->_data = &_SESSION;
    }

    /**
     * Start the session.
     *
     * @return boolean
     */
    public function start() -> boolean
    {
        if !headers_sent() {
            session_start();
            let this->_started = true;
            return true;
        }
        return false;
    }

    /**
     * Check whether the session was started.
     *
     * @return boolean
     */
    public function isStarted() -> boolean
    {
        return this->_started;
    }

    /**
     * Get session id.
     *
     * @return string
     */
    public function getId() -> string
    {
        return session_id();
    }

    /**
     * Regenerate session id.
     *
     * @return boolean
     */
    public function regenerate() -> boolean
    {
        return session_regenerate_id();
    }

    /**
     * Destroy the session.
     *
     * @return boolean
     */
    public function destroy() -> boolean
    {
        let this->_started = false;
        return session_destroy();
    }

    /**
     * Check whether session has the key.
     * No support for passing variables by reference yet zephir/issues/203
     */
    public function has(string key) -> boolean
    {
        return isset _SESSION[key];
    }

    /**
     * Retrieve a single key from the session.
     */
    public function get(string key, var defaultValue = null)
    {
        var value;

        if fetch value, _SESSION[key] {
            return value;
        }

        return defaultValue;
    }

    /**
     * Assigns a value to the specified session key.
     */
    public function set(string key, var value)
    {
        let _SESSION[key] = value;
    }

    /**
     * Remove session key.
     */
    public function remove(string key)
    {
        unset _SESSION[key];
    }
}
