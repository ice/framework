
namespace Ice;

class Arr implements \ArrayAccess, \Countable, \IteratorAggregate
{

    protected _data = [] { get };

    public function __construct(array data = [])
    {
        let this->_data = data;
    }

    /**
     * Does this set contain a key?
     * @param  string  $key The data key
     * @return boolean
     */
    public function has(string key) -> boolean
    {
        return isset this->_data[key];
    }

    /**
     * Get data value with key
     * @param string $key The data key
     * @param mixed $defaultValue The value to return if data key does not exist
     * @return mixed
     */
    public function get(string key, var defaultValue = null)
    {
        var value;

        if fetch value, this->_data[key] {
            return value;
        }

        return defaultValue;
    }

    /**
     * Set data key to value
     * @param string $key The data key
     * @param mixed
     */
    public function set(string key, var value)
    {
        let this->_data[key] = value;
    }

    /**
     * Add data to set, replaces the existing data
     * @param array
     */
    public function replace(array! data)
    {
        var key, value;

        for key, value in data {
            this->set(key, value);
        }
    }

    /**
     * Fetch all data
     * @return array
     */
    public function all()
    {
        return this->getData();
    }

    /**
     * Set data, clears and overwrites the current data
     * @param array
     */
    public function setData(array! data = [])
    {
        let this->_data = data;
    }

    /**
     * Fetch set data keys
     * @return array
     */
    public function keys()
    {
        return array_keys(this->_data);
    }

    /**
     * Remove value with key from this set
     * @param  string $key The data key
     */
    public function remove(string key)
    {
        unset this->_data[key];
    }

    /**
     * Clear all values
     */
    public function clear()
    {
        let this->_data = [];
    }

    public function count()
    {
        return count(this->_data);
    }

    public function getIterator()
    {
        return new \ArrayIterator(this->_data);
    }

    public function getPath(var path, var defaultValue = null, string delimiter = ".")
    {
        var parts, value, part;

        if typeof path == "array" {
            let parts = path;
        } else {
            let parts = explode(delimiter, path);
        }

        // use current array as the initial value
        let value = this->toArray();

        // loop through each part and extract its value
        for part in parts {
            if isset value[part] {
                // replace current value with the child
                let value = value[part];
            } else {
                // key doesn't exist, fail
                return defaultValue;
            }
        }

        return value;
    }

    /**
     * Converts recursively the object to an array
     *
     * @return array
     */
    public function toArray()
    {
        var key, value, tmp;

        let tmp = [];
        for key, value in this->_data {
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

    public function __isset(string key) -> boolean
    {
        return this->has(key);
    }

    public function __get(key)
    {
        if isset this->{key} {
            return this->{key};
        }
        return this->get(key);
    }

    public function __set(string key, var value)
    {
        if isset this->{key} {
            let this->{key} = value;
        } else {
            this->set(key, value);
        }
    }

    public function __unset(key)
    {
        return this->remove(key);
    }

    public function offsetExists(string offset) -> boolean
    {
        return this->has(offset);
    }

    public function offsetGet(string offset)
    {
        return this->get(offset);
    }

    public function offsetSet(string offset, var value)
    {
        this->set(offset, value);
    }

    public function offsetUnset(string offset)
    {
        this->remove(offset);
    }
}