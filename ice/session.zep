
namespace Ice;

class Session extends Arr
{

    protected _started = false;

    public function __construct()
    {
        this->start();

        //let this->_data = &_SESSION;
    }

    public function start() -> boolean
    {
        if !headers_sent() {
            session_start();
            let this->_started = true;
            return true;
        }
        return false;
    }

    public function isStarted() -> boolean
    {
        return this->_started;
    }

    public function getId() -> string
    {
        return session_id();
    }

    public function regenerate() -> boolean
    {
        return session_regenerate_id();
    }

    public function destroy() -> boolean
    {
        let this->_started = false;
        return session_destroy();
    }

    /**
     * No support for passing variables by reference yet #203
     */
    public function has(string key) -> boolean
    {
        return isset _SESSION[key];
    }

    public function get(string key, var defaultValue = null)
    {
        var value;

        if fetch value, _SESSION[key] {
            return value;
        }

        return defaultValue;
    }

    public function set(string key, var value)
    {
        let _SESSION[key] = value;
    }

    public function remove(string key)
    {
        unset _SESSION[key];
    }
}