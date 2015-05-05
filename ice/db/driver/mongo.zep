
namespace Ice\Db\Driver;

use Ice\Arr;
use Ice\Db\DbInterface;

/**
 * Mongo driver.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Mongo implements DbInterface
{

    protected _id = "_id" { get };
    protected _type = "NOSQL" { get };
    protected _error;
    protected _client { get };
    protected _lastInsertId { get };

    /**
     * Instantiate mongo connection.
     *
     * @param string dsn
     * @param string dbname
     * @param array options
     */
    public function __construct(string dsn, string dbname = NULL, array options = [])
    {
        let this->_client = new \MongoDB(new \MongoClient(dsn, options), dbname);
    }

    /**
     * Get the id value.
     *
     * @param string id
     * @return object
     */
    public function getIdValue(string id) -> object
    {
        return new \MongoId(id);
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

        return result->count() ? new Arr(result->getNext()) : false;
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

        return new Arr(iterator_to_array(result));
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
        var filtered, collection, result, tmp;

        switch typeof filters {
            case "array":
                // Find by filters
                let filtered = filters;
            break;
            case "integer":
            case "string":
                // Find by id
                let filtered = [this->_id: this->getIdValue(filters)];
            break;
            default:
                // Find all
                let filtered = [];
            break;
        }

        let collection = this->_client->selectcollection(from),
            result = collection->find(filtered, fields);

        if isset options["order"] {
            let tmp = result,
                result = tmp->sort(options["order"]);
        }
        if isset options["limit"] {
            let tmp = result,
                result = tmp->limit(options["limit"]);
        }
        if isset options["offset"] {
            let tmp = result,
                result = tmp->skip(options["offset"]);
        }

        let this->_error = this->_client->lastError();

        return result;
    }

    /**
     * INSERT document into collection.
     *
     * @param string from Collection name
     * @param array fields Fields to insert, keys are the column names
     */
    public function insert(string! from, array fields = [])
    {
        var collection, status;

        let collection = this->_client->selectcollection(from),
            status = collection->insert(fields),
            this->_lastInsertId = fields[this->_id],
            this->_error = status;

        return status["err"] === null ? true : status;
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
        var collection, status;

        let collection = this->_client->selectcollection(from),
            status = collection->update(filters, fields),
            this->_error = status;

        return status["err"] === null ? true : status;
    }

    /**
     * Remove documents from the collection.
     *
     * @param string from Collection name
     * @param mixed filters Criteria
     */
    public function remove(string! from, var filters = [])
    {
        var collection, status;

        let collection = this->_client->selectcollection(from),
            status = collection->remove(filters),
            this->_error = status;

        return status["err"] === null ? true : status;
    }

    /**
     * Get an error message.
     *
     * @return mixed
     */
    public function getError()
    {
        var error;

        fetch error, this->_error["err"];

        return error;
    }
}
