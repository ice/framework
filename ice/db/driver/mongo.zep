
namespace Ice\Db\Driver;

use Ice\Arr;
use Ice\Db\DbInterface;

class Mongo implements DbInterface
{

    protected _id = "_id" { get };
    protected _type = "NOSQL" { get };
    protected _error { get };
    protected _client { get };

   /**
    * Instantiate class
    *
    * @param string $dsn
    * @param string $dbname
    * @param array $options
    */
    public function __construct(string dsn, string dbname = NULL, array options = [])
    {
        let this->_client = new \MongoDB(new \MongoClient(dsn, options), dbname);
    }

    public function findOne(string! from, var filters = [], array fields = [], array options = [])
    {
        var result;

        let options["limit"] = 1,
            result = this->select(from, filters, fields, options);

        return new Arr(iterator_to_array(result->current()));
    }

    public function find(string! from, var filters = [], array fields = [], array options = [])
    {
        var result;

        let result = this->select(from, filters, fields, options);

        return new Arr(iterator_to_array(result));
    }

    public function select(string! from, var filters = [], array fields = [], array options = [])
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

    public function insert(string! from, array fields = [])
    {
        var collection, status;

        let collection = this->_client->selectcollection(from),
            status = collection->insert(fields);

        return status;
    }

    public function update(string! from, var filters = [], array fields = [])
    {
        var collection, status;

        let collection = this->_client->selectcollection(from),
            status = collection->update(filters, fields);

        return status;
    }
}