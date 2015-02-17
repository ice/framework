
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
    protected _error { get };
    protected _client { get };

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
            result = this->select(from, filters, fields, options);

        return new Arr(iterator_to_array(result->current()));
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

        let result = this->select(from, filters, fields, options);

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
        var collection, result;

        let collection = this->_client->selectcollection(from),
            result = collection->find(filters, fields);

        if isset options["order"] {
            let result = result->sort(options["order"]);
        }
        if isset options["limit"] {
            let result = result->limit(options["limit"]);
        }
        if isset options["offset"] {
            let result = result->skip(options["offset"]);
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
            status = collection->insert(fields);

        return status;
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
            status = collection->update(filters, fields);

        return status;
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
            status = collection->remove(filters);

        return status;
    }
}
