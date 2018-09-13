
namespace Ice\Db\Driver;

use Ice\Arr;
use Ice\Db\DbInterface;

/**
 * Pdo driver.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Pdo implements DbInterface
{

    protected id = "id" { get };
    protected type = "SQL" { get };
    protected error;
    protected client { get };

    /**
     * Instantiate pdo connection.
     *
     * @param string dsn
     * @param string user
     * @param string password
     * @param array options
     */
    public function __construct(string dsn, string user = NULL, string password = NULL, array options = [])
    {
        var parts, pdo;

        let parts = null;

        preg_match("/^.+?(?:dbname|database)=(.+?)(?=;|$)/i", dsn, parts);

        if isset parts[0] && strstr(parts[0], ":", TRUE) == "mysql" {
            let dsn = dsn . ";charset=utf8";
        }

        let pdo = "Pdo",
            this->client = new {pdo}(dsn, user, password, options);
    }

    /**
     * Get the id value.
     *
     * @param string id
     * @return int
     */
    public function getIdValue(id) -> int
    {
        return (int) id;
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

        if typeof value == "integer" {
            let value = "@" . value;
        }

        let date = new \DateTime(value);

        if model {
            return date->format("Y-m-d H:i:s.u");
        }

        return date;
    }
    
    /**
     * Query sql statement. execute the statement and populate into Model object:
     * $m = $this->db->query('select*from t where id=:id', [':id' => 1], new static);
     *
     * @param string sql SQL with kinda of placeholders
     * @param array values Replace placeholders in the sql
     * @param mixed obj The object will be populated from query result
     * @return PDOStatement|object|null
     */
    public function query(string! sql, array values = [], var obj = null)
    {
        var query, result;
        
        let query = this->client->prepare(sql);
   
        query->execute(values);

        let this->error = query->errorInfo();
        
        if empty this->error && obj {
            if typeof obj == "string" {
                let obj = new {obj}();
            }
            if obj instanceof Arr {
                let result = query->$fetch();
                if result {
                    obj->replace(result);
                } else {
                    let obj = null;
                }
                return obj;
            } else {
                throw new Exception(["Only instance of Arr is allowed for populate the result. %s given", get_class(obj)]);
            }
        }

        return query;
    }

    /**
     * Find one row that match criteria.
     *
     * @param string from Table name
     * @param mixed filters Filters to create WHERE conditions
     * @param array options Options to limit/group results
     * @param array fields Fields to retrieve, if not specified get all
     * @return Arr|false
     */
    public function findOne(string! from, var filters = [], array options = [], array fields = [])
    {
        var result;

        let options["limit"] = 1,
            result = this->select(from, filters, options, fields);

        return result->rowCount() ? new Arr(result->$fetch(\Pdo::FETCH_ASSOC)) : false;
    }

    /**
     * Find all records that match criteria.
     *
     * <pre><code>
     *  //SELECT * FROM users WHERE a=1 and b="q"
     *  $db->find("users", array("a" => 1, "b" => "q"));
     * 
     *  //SELECT * FROM users WHERE age>33 
     *  $db->find("users", array("age" => array(">" => 33)));
     * 
     *  //SELECT * FROM users WHERE a=1 or b=2 
     *  $db->find("users", array("OR" => array(array("a" => 1), array("b" => 2))));
     * </code></pre>
     *
     * @param string from Table name
     * @param mixed filters Filters to create WHERE conditions
     * @param array options Options to limit/group results
     * @param array fields Fields to retrieve, if not specified get all
     * @return Arr
     */
    public function find(string! from, var filters = [], array options = [], array fields = [])
    {
        var result;

        let result = this->select(from, filters, options, fields);

        return new Arr(result->fetchAll(\Pdo::FETCH_ASSOC));
    }

    /**
     * Prepare SQL WHERE condition.
     *
     * @params mixed filters
     * @params array values
     */
    protected function where(var filters = [], array values = []) -> array
    {
        var and, data, operator, key, item, value, or, is, index, i, sql, condition;

        let and = [],
            sql = "",
            i = "";

        if is_numeric(filters) {
            let filters = (int) filters;
        }

        switch typeof filters {
            case "array":
                for operator, data in filters {
                    switch operator {
                        case "OR":
                        case "or":
                        case "$or":
                            let or = [],
                                operator = "OR";
                        break;
                        case "AND":
                        case "and":
                        case "$and":
                            let operator = "AND";
                        break;
                        default: // short "AND"
                            var tmp = data;
                            let data = ["AND": [operator: tmp]],
                                operator = "AND";
                        break;
                    }

                    for item in data {
                        let key = key(item),
                            value = current(item);

                        if typeof value == "array" {
                            let is = key(value),
                                value = current(value);
                        } else {
                            let is = "=";
                        }

                        do {
                            let index = ":" . key . i,
                                i = i ? (int) i + 1 : 1;
                        } while isset values[index];

                        switch is {
                            case "IN":
                            case "in":
                            case "$in":
                                if typeof value == "array" {
                                    var j, id, ids = [];
                                    // Bind all values
                                    for j, id in value {
                                        let ids[] = index . j,
                                            values[index . j] = id;
                                    }

                                    let value = "(" . join(", ", ids) . ")";
                                }
                                let condition = "`" . key . "` " . is . " " . value;
                            break;
                            case "IS":
                            case "is":
                            case "IS NOT":
                            case "is not":
                                // Don't bind value
                                let condition = "`" . key . "` " . is . " " . value;
                            break;
                            default:
                                // Bind value
                                let condition = "`" . key . "` " . is . " " . index,
                                    values[index] = value;
                            break;
                        }

                        if operator == "AND" {
                            let and[] = condition;
                        } else {
                            let or[] = condition;
                        }
                    }

                    if operator == "OR" {
                        let and[] = "(" . join(" OR ", or) . ")";
                    }
                }
                let sql .= join(" AND ", and);
            break;
            case "integer":
                let sql .= "`id` = " . filters;
            break;
            case "string":
                let sql .= filters;
            break;
            default:
                let sql .= "TRUE";
            break;
        }

        return [sql, values];
    }

    /**
     * SELECT record(s) that match criteria.
     *
     * @param string from Table name
     * @param mixed filters Filters to create WHERE conditions
     * @param array options Options to limit/group results
     * @param array fields Fields to retrieve, if not specified get all
     */
    public function select(string! from, var filters = [], array options = [], array fields = [])
    {
        var columns, sql, filtered, values, query;

        if count(fields) {
            let columns = join(", ", fields);
        } else {
            let columns = "*";
        }

        let filtered = this->where(filters),
            sql = "SELECT " . columns . " FROM `" . from . "` WHERE " . filtered[0],
            values = filtered[1];

        if isset options["group"] {
            let sql .= " GROUP BY " . join(", ", options["group"]);
        }
        if isset options["order"] {
            let sql .= " ORDER BY " . join(", ", options["order"]);
        }
        if isset options["limit"] {
            let sql .= " LIMIT " . options["limit"];
        }
        if isset options["offset"] {
            let sql .= " OFFSET " . options["offset"];
        }

        let query = this->client->prepare(sql);

        query->execute(values);

        let this->error = query->errorInfo();

        return query;
    }

    /**
     * INSERT record into table.
     *
     * @param string from Table name
     * @param array fields Fields to insert, keys are the column names
     */
    public function insert(string! from, array fields = [])
    {
        var key, value, columns, values, sql, query, status;

        let columns = [],
            values = [];

        for key, value in fields {
            let columns[] = "`" . key . "`",
                values[":" . key] = value;
        }

        let sql = "INSERT INTO `" . from . "` (" . join(", ", columns) . ") VALUES (" . join(", ", array_keys(values)) . ")",
            query = this->client->prepare(sql),
            status = query->execute(values),
            this->error = query->errorInfo();
     
        return status;
    }

    /**
     * UPDATE records in the table.
     *
     * @param string from Table name
     * @param mixed filters Filters to create WHERE conditions
     * @param array fields Fields to update, keys are the column names
     */
    public function update(string! from, var filters = [], array fields = [])
    {
        var key, value, columns, values, filtered, sql, query, status;

        let columns = [],
            values = [];

        for key, value in fields {
            let values[":" . key] = value,
                columns[] = "`" . key . "` = :" . key;
        }

        let filtered = this->where(filters, values),
            sql = "UPDATE `" . from . "` SET " . join(", ", columns) . " WHERE " . filtered[0],
            values = array_merge(values, filtered[1]),
            query = this->client->prepare(sql),
            status = query->execute(values),
            this->error = query->errorInfo();

        return status;
    }

    /**
     * Remove records from the table.
     *
     * @param string from Table name
     * @param mixed filters Filters to create WHERE conditions
     */
    public function remove(string! from, var filters = [])
    {
        var filtered, sql, values, query, status;

        let filtered = this->where(filters),
            sql = "DELETE FROM `" . from . "` WHERE " . filtered[0],
            values = filtered[1],
            query = this->client->prepare(sql),
            status = query->execute(values),
            this->error = query->errorInfo();

        return status;
    }

    /**
     * Get last inserted ID.
     *
     * @return int
     */
    public function getLastInsertId() -> int
    {
        return (int) this->client->lastInsertId();
    }

    /**
     * Get an error message.
     *
     * @return mixed
     */
    public function getError()
    {
        var error;

        fetch error, this->error[0];

        return error;
    }
}
