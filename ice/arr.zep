
namespace Ice;

use ArrayIterator;

/**
 * Access class as array and the same time as object.
 *
 * @package     Ice/Arr
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
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
     * Whether or not a data exists by key.
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
     * @return object Arr
     */
    public function set(string key, var value)
    {
        let this->data[key] = value;

        return this;
    }

    /**
     * Add data to set, replaces the existing data.
     *
     * @param array data
     * @return Arr
     */
    public function replace(array! data)
    {
        var key, value;

        for key, value in data {
            this->set(key, value);
        }

        return this;
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
     * Fetch some data.
     *
     * @param array keys Keys to fetch
     * @param boolean strict Fetch key only if exist
     * @return array
     */
    public function only(array! keys, boolean strict = true) -> array
    {
        var key, only = [];

        for key in keys {
            if !strict || strict && this->has(key) {
                let only[key] = this->get(key);
            }
        }
        return only;
    }

    /**
     * Gets value from data applying filters if needed.
     *
     * <pre><code>
     *  //Returns value from $arr["id"] without sanitizing
     *  $id = $arr->getValue("id");
     *
     *  //Returns value from $arr["title"] with sanitizing
     *  $title = $arr->getValue("title", "escape|repeats");
     *
     *  //Returns value from $arr["id"] with a default value
     *  $id = $arr->getValue("id", null, 150);
     * </code></pre>
     *
     * @param string key Index to get
     * @param string|array filters Filters to apply
     * @param mixed defaultValue Default value if key not exist or value is empty and allowEmpty is false
     * @param boolean allowEmpty
     * @return mixed
     */
    public function getValue(string key, var filters = null, var defaultValue = null, boolean allowEmpty = false)
    {
        var value, filter;

        let value = this->get(key, defaultValue);

        if filters {
            let filter = Di::$fetch()->get("filter"),
                value = filter->sanitize(value, filters);
        }

        if (value === "" || value === null) && allowEmpty === false {
            return defaultValue;
        }

        return value;
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
        return array_keys(this->getData());
    }

    /**
     * Remove a data by key.
     *
     * @param string key The data key
     * @return object Arr
     */
    public function remove(string key)
    {
        unset this->data[key];

        return this;
    }

    /**
     * Clear all values.
     *
     * @return object Arr
     */
    public function clear()
    {
        let this->data = [];

        return this;
    }

    /**
     * Count all elements in a data.
     *
     * @return int
     */
    public function count() -> int
    {
        return count(this->getData());
    }

    /**
     * Get a data iterator.
     *
     * return ArrayIterator
     */
    public function getIterator() -> <ArrayIterator>
    {
        return new ArrayIterator(this->getData());
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

        let data = this->getData();

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
        for key, value in this->getData() {
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
    public function offsetExists(offset) -> boolean
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
    public function offsetGet(offset)
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
    public function offsetSet(offset, var value) -> void
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
    public function offsetUnset(offset) -> void
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
        this->remove(key);
    }
}
