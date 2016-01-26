
namespace Ice;

use ArrayIterator;

/**
 * Access class as array and the same time as object.
 *
 * @package     Ice/Arr
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Arr implements \ArrayAccess, \Countable, \IteratorAggregate
{

    protected data = [] { get };

    /**
     * Arr constructor.
     *
     * @param array data Initial array
     */
    public function __construct(array data = [])
    {
        let this->data = data;
    }

    /**
     * Whether or not an data exists by key.
     *
     * @param string key The data key
     * @return boolean
     */
    public function has(string key) -> boolean
    {
        return isset this->data[key];
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

        if fetch value, this->data[key] {
            return value;
        }

        return defaultValue;
    }

    /**
     * Assigns a value to the specified data.
     *
     * @param string key The data key
     * @param mixed value
     * @return void
     */
    public function set(string key, var value) -> void
    {
        let this->data[key] = value;
    }

    /**
     * Add data to set, replaces the existing data.
     *
     * @param array data
     * @return void
     */
    public function replace(array! data) -> void
    {
        var key, value;

        for key, value in data {
            this->set(key, value);
        }
    }

    /**
     * Fetch all data.
     *
     * @return array
     */
    public function all() -> array
    {
        return this->getData();
    }

    /**
     * Set data, clears and overwrites the current data.
     *
     * @param array data
     * @return void
     */
    public function setData(array! data = []) -> void
    {
        let this->data = data;
    }

    /**
     * Fetch set data keys.
     *
     * @return array
     */
    public function keys() -> array
    {
        return array_keys(this->data);
    }

    /**
     * Remove an data by key.
     *
     * @param string key The data key
     * @return void
     */
    public function remove(string key) -> void
    {
        unset this->data[key];
    }

    /**
     * Clear all values.
     *
     * @return void
     */
    public function clear() -> void
    {
        let this->data = [];
    }

    /**
     * Count all elements in a data.
     *
     * @return int
     */
    public function count() -> int
    {
        return count(this->data);
    }

    /**
     * Get a data iterator.
     *
     * return ArrayIterator
     */
    public function getIterator() -> <ArrayIterator>
    {
        return new ArrayIterator(this->data);
    }

    /**
     * Gets a value from an array using a dot separated path.
     *
     * <pre><code>
     *  // Get the value of $array['foo']['bar']
     *  $value = (new Arr($array))->getPath('foo.bar');
     * </code></pre>
     *
     * <pre><code>
     *  // Get the values of "color" in theme
     *  $colors = (new Arr($array))->getPath('theme.*.color');
     * </code></pre>
     *
     * @param mixed path Key path string (delimiter separated) or array of keys
     * @param mixed defaultValue Default value if the path is not set
     * @param string delimiter Key path delimiter
     * @return mixed
     */
    public function getPath(var path, var defaultValue = null, string delimiter = ".")
    {
        var data, keys, key;

        let data = this->data;

        if typeof path == "array" {
            // The path has already been separated into keys
            let keys = path;
        } else {
            if array_key_exists(path, data) {
                // No need to do extra processing
                return data[path];
            }

            // Remove starting delimiters and spaces
            let path = ltrim(path, "{" . delimiter . "} "),
                // Remove ending delimiters, spaces, and wildcards
                path = rtrim(path, "{" . delimiter . "} *"),
                // Split the keys by delimiter
                keys = explode(delimiter, path);
        }

        do {
            let key = array_shift(keys);

            if ctype_digit(key) {
                // Make the key an integer
                let key = (int) key;
            }

            if isset data[key] {
                if keys {
                    if typeof data[key] == "array" {
                        // Dig down into the next part of the path
                        let data = data[key];
                    } else {
                        // Unable to dig deeper
                        break;
                    }
                } else {
                    // Found the path requested
                    return data[key];
                }
            } elseif key === "*" {
                var values, value, arr;

                // Handle wildcards
                let values = [];

                for arr in data {
                    if typeof arr == "array" {
                        let value = (new Arr(arr))->getPath(keys);

                        if value {
                            let values[] = value;
                        }
                    }
                }
                if values {
                    // Found the values requested
                    return values;
                } else {
                    // Unable to dig deeper
                    break;
                }
            } else {
                // Unable to dig deeper
                break;
            }
        } while keys;

        // Unable to find the value requested
        return defaultValue;
    }

    /**
     * Converts recursively the object to an array.
     *
     * @return array
     */
    public function toArray() -> array
    {
        var key, value, tmp;

        let tmp = [];
        for key, value in this->data {
            if typeof value == "object" {
                if method_exists(value, "toArray") {
                    let tmp[key] = value->toArray();
                } else {
                    let tmp[key] = value;
                }
            } else {
                let tmp[key] = value;
            }
        }
        return tmp;
    }

    /**
     * Whether or not an offset exists.
     *
     * @param string An offset to check for
     * @return boolean
     * @abstracting ArrayAccess
     */
    public function offsetExists(string offset) -> boolean
    {
        return this->has(offset);
    }

    /**
     * Returns the value at specified offset.
     *
     * @param string The offset to retrieve
     * @return mixed
     * @abstracting ArrayAccess
     */
    public function offsetGet(string offset)
    {
        return this->get(offset);
    }

    /**
     * Assigns a value to the specified offset.
     *
     * @param string The offset to assign the value to
     * @param mixed  The value to set
     * @return void
     * @abstracting ArrayAccess
     */
    public function offsetSet(string offset, var value) -> void
    {
        this->set(offset, value);
    }

    /**
     * Unsets an offset.
     *
     * @param string The offset to unset
     * @return void
     * @abstracting ArrayAccess
     */
    public function offsetUnset(string offset) -> void
    {
        this->remove(offset);
    }

    /**
     * Magic isset, whether or not a key exists.
     */
    public function __isset(string key) -> boolean
    {
        return this->has(key);
    }

    /**
     * Magic get, returns the value at specified key.
     * First check if property exist.
     */
    public function __get(key)
    {
        if isset this->{key} {
            return this->{key};
        }
        return this->get(key);
    }

    /**
     * Magic set, assigns a value to the specified key.
     * First check if property exist.
     */
    public function __set(string key, var value) -> void
    {
        if isset this->{key} {
            let this->{key} = value;
        } else {
            this->set(key, value);
        }
    }

    /**
     * Magic unset, unsets a key.
     */
    public function __unset(key) -> void
    {
        unset this->data[key];
    }
}
