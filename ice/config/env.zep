
namespace Ice\Config;

use Ice\Exception;

/**
 * Environment helper.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Env extends Ini
{

    /**
     * Env constructor.
     *
     * @param string data Path to the env file
     */
    public function __construct(var data = null)
    {
        // No support for passing variables by reference yet zephir/issues/203
        //let this->data = &_ENV;
        parent::__construct(data);

        let _ENV = array_merge(_ENV, this->data);
    }

    /**
     * Check whether environment has the key.
     *
     * @return boolean
     */
    public function has(string key) -> boolean
    {
        return isset _ENV[key];
    }

    /**
     * Retrieve a single key from the environment.
     *
     * @return mixed
     */
    public function get(string key, var defaultValue = null, boolean required = false)
    {
        var value;

        if fetch value, _ENV[key] {
            return value;
        }

        return defaultValue;
    }

    /**
     * Assigns a value to the specified environment key.
     *
     * @return object
     */
    public function set(string key, var value) -> <self>
    {
        let _ENV[key] = value;

        return this;
    }

    /**
     * Remove environment key.
     *
     * @return object
     */
    public function remove(string key) -> <self>
    {
        unset _ENV[key];

        return this;
    }

    /**
     * Fetch all data.
     *
     * @return array
     */
    public function getData() -> array
    {
        return _ENV;
    }
}
