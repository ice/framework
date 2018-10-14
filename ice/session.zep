
namespace Ice;

/**
 * Session helper.
 *
 * @package     Ice/Session
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Session extends Arr
{

    protected started = false;

    /**
     * Session constructor. Start the session.
     */
    public function __construct()
    {
        this->start();

        //let this->data = &_SESSION;
    }

    /**
     * Start the session.
     *
     * @return boolean
     */
    public function start() -> boolean
    {
        var valid;

        if !headers_sent() {
            let this->started = session_start();

            if this->started {
                let valid = "__valid__";

                // Check if we need to perform the write test.
                if !this->has(valid) {
                    this->set(valid, true);

                    // Attempt to write session to disk
                    session_write_close();

                    // Re-start session
                    let this->started = session_start();

                    if this->started {
                        if !this->has(valid) {
                            // Session was not written to disk
                            let this->started = false;
                        } else {
                            // Unset the variable from memory
                            this->remove(valid);
                        }
                    }
                }
            }
        }

        return this->started;
    }

    /**
     * Check whether the session was started.
     *
     * @param boolean autoStart If session is not started, try to start it
     * @return boolean
     */
    public function isStarted(boolean autoStart = true) -> boolean
    {
        if this->started {
            if session_status() == PHP_SESSION_NONE {
                // the session had been started but dead now, force to restart it
                return this->start();
            }
            return true;
        }
        return autoStart ? this->start() : false;
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
        let this->started = false;
        return session_destroy();
    }

    /**
     * Check whether session has the key.
     * No support for passing variables by reference yet zephir/issues/203
     *
     * @return boolean
     */
    public function has(string key) -> boolean
    {
        return isset _SESSION[key];
    }

    /**
     * Retrieve a single key from the session.
     *
     * @return mixed
     */
    public function get(string key, var defaultValue = null, boolean required = false)
    {
        var value;

        if fetch value, _SESSION[key] {
            return value;
        }

        return defaultValue;
    }

    /**
     * Assigns a value to the specified session key.
     *
     * @return object Session
     */
    public function set(string key, var value) -> <self>
    {
        let _SESSION[key] = value;

        return this;
    }

    /**
     * Remove session key.
     *
     * @return object Session
     */
    public function remove(string key) -> <self>
    {
        unset _SESSION[key];

        return this;
    }

    /**
     * Fetch all data.
     *
     * @return array
     */
    public function getData() -> array
    {
        return _SESSION;
    }
}
