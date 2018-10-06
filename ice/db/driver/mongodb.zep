
namespace Ice\Db\Driver;

use Ice\Arr;
use Ice\Exception;
use Ice\Db\DbInterface;

/**
 * MongoDB driver.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Mongodb implements DbInterface
{

    protected id = "_id" { get };
    protected type = "NOSQL" { get };
    protected error;
    protected client { get };
    protected lastInsertId { get };

    /**
     * Instantiate mongo connection.
     *
     * @param string dsn
     * @param string dbname
     * @param array options
     */
    public function __construct(string dsn, string dbname = NULL, array options = [])
    {
        var client;

        if version_compare(phpversion("mongodb"), "1.2.0alpha1", ">=") {
            let client = "MongoDB\\Client",
                this->client = (new {client}(dsn, options))->selectDatabase(dbname);
        } else {
            throw new Exception("Version of `mongodb` extension must be 1.2.0alpha1 or higher");
        }
    }

    /**
     * Get the id value.
     *
     * @param string id
     * @return object
     */
    public function getIdValue(string id) -> object
    {
        return new \MongoDB\BSON\ObjectID(id);
    }

    /**
     * Get a date time object.
     *
     * @param mixed value
     * @param boolean model
     * @return object
     */
    public function getDateTime(value = null, model = false)
    {
        var date;

        if typeof value == "object" && value instanceof \MongoDB\BSON\UTCDateTime {
            let date = value;
        } else {
            long tmp;

            switch typeof value {
                case "NULL":
                    let tmp = time() * 1000,
                        value = tmp;
                    break;
                case "integer":
                    let tmp = value * 1000,
                        value = tmp;
                    break;
                default:
                    let tmp = strtotime(value) * 1000,
                        value = tmp;
                    break;
            }

            let date = new \MongoDB\BSON\UTCDateTime(value);
        }

        if model {
            return date;
        }

        return date->toDateTime();
    }

    /**
     * Find one document that match criteria.
     *
     * @param string from Collection name
     * @param mixed filters Criteria
     * @param array options Options to limit/group results
     * @param array fields Fields to retrieve, if not specified get all
     * @return Arr
     */
    public function findOne(string! from, var filters = [], array options = [], array fields = [])
    {
        var result;

        let options["limit"] = 1,
            result = this->select(from, filters, options, fields);

        return count(result) ? new Arr(current(result)) : false;
    }

    /**
     * Find all documents that match criteria.
     *
     * <pre><code>
     *  $db->find("users", array("a" => 1, "b" => "q"));
     *  $db->find("users", array("age" => array(">" => 33)));
     *  $db->find("users", array("OR" => array(array("a" => 1), array("b" => 2))));
     * </code></pre>
     *
     * @param string from Collection name
     * @param mixed filters Criteria
     * @param array options Options to limit/group results
     * @param array fields Fields to retrieve, if not specified get all
     * @return Arr
     */
    public function find(string! from, var filters = [], array options = [], array fields = [])
    {
        var result;

        let result = this->select(from, filters, options, fields);

        return new Arr(result);
    }

    /**
     * SELECT document(s) that match criteria.
     *
     * @param string from Collection name
     * @param mixed filters Criteria
     * @param array options Options to limit/group results
     * @param array fields Fields to retrieve, if not specified get all
     */
    public function select(string! from, var filters = [], array options = [], array fields = [])
    {
        var filtered, collection, result;

        switch typeof filters {
            case "object":
                // Find by ObjectId
                if filters instanceof \MongoDB\BSON\ObjectID {
                    let filtered = [this->id: filters];
                } else {
                    throw new Exception("Object must be an ObjectID instance");
                }
            break;
            case "array":
                // Find by filters
                let filtered = filters;
            break;
            case "integer":
            case "string":
                // Find by id
                let filtered = [this->id: this->getIdValue(filters)];
            break;
            default:
                // Find all
                let filtered = [];
            break;
        }

        if isset options["order"] {
            let options["sort"] = options["order"];
            unset options["order"];
        }

        if isset options["offset"] {
            let options["skip"] = options["offset"];
            unset options["offset"];
        }

        if count(fields) {
            let options["projection"] = array_fill_keys(array_flip(fields), 1);
        }

        let collection = this->client->selectCollection(from),
            result = collection->find(filtered, options);

        result->setTypeMap(["root": "array", "document": "array", "array": "array"]);

        return iterator_to_array(result);
    }

    /**
     * INSERT document into collection.
     *
     * @param string from Collection name
     * @param array fields Fields to insert, keys are the column names
     */
    public function insert(string! from, array fields = [])
    {
        var collection, result;

        let collection = this->client->selectCollection(from),
            result = collection->insertOne(fields),
            this->lastInsertId = result->getInsertedId();

        return result->getInsertedCount() ? true : false;
    }

    /**
     * UPDATE documents in the collection.
     *
     * @param string from Collection name
     * @param mixed filters Criteria
     * @param array fields Fields to update, keys are the column names
     */
    public function update(string! from, var filters = [], array fields = [])
    {
        var collection, result;

        let collection = this->client->selectCollection(from),
            result = collection->updateMany(filters, ["$set": fields]);

        return result->getMatchedCount() ? true : false;
    }

    /**
     * Remove documents from the collection.
     *
     * @param string from Collection name
     * @param mixed filters Criteria
     */
    public function delete(string! from, var filters = [])
    {
        var collection, result;

        let collection = this->client->selectCollection(from),
            result = collection->deleteMany(filters);

        return result->getDeletedCount() ? true : false;
    }

    /**
     * Get an error message.
     *
     * @return mixed
     */
    public function getError()
    {
        var error;

        fetch error, this->error["err"];

        return error;
    }
}
