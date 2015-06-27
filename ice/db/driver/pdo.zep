
namespace Ice\Db\Driver;

use Ice\Arr;
use Ice\Db\DbInterface;

/**
 * Pdo driver.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
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
        var parts;

        let parts = [];

        preg_match("/^.+?(?:dbname|database)=(.+?)(?=;|$)/i", dsn, parts);

        if isset parts[0] && strstr(parts[0], ":", TRUE) == "mysql" {
            let options[\PDO::MYSQL_ATTR_INIT_COMMAND] = "SET NAMES utf8;";
        }

        let this->client = new \Pdo(dsn, user, password, options);
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
    private function where(var filters = [], array values = []) -> array
    {
        var and, data, operator, key, item, value, or, is, index, i, sql;

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
                            let or = [];
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

                                let or [] = "`" . key . "` " . is . " " . index,
                                    values[index] = value;
                            }
                            let and[] = "(" . join(" OR ", or) . ")";
                        break;
                        case "AND":
                        case "and":
                        case "$and":
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

                                let and [] = "`" . key . "` " . is . " " . index,
                                    values[index] = value;
                            }
                        break;
                        default: // short "AND"
                            let key = operator,
                                value = data;

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


                            let and[] = "`" . key . "` " . is . " " . index,
                                values[index] = value;
                        break;
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
