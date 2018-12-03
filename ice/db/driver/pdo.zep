
namespace Ice\Db\Driver;

use Ice\Arr;
use Ice\Exception;
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
    protected driverName { get };

    protected identifier = "\"%s\"";

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
        let this->driverName = explode(":", dsn, 2)[0];

        switch this->driverName {
            case "mysql":
                let this->identifier = "`%s`";
                let dsn = dsn . ";charset=utf8";
            break;
            case "sqlsrv":
                let this->identifier = "[%s]";
            break;
            case "sqlite":
                let this->identifier = "[%s]";
            break;
            case "oci":
                let this->identifier = "\"%s\"";
            break;
            case "pgsql":
                let this->identifier = "\"%s\"";
            break;
        }

        let this->client = new \PDO(dsn, user, password, options);
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
     * Find one row that match criteria.
     *
     * <pre><code>
     *  //SELECT x, y FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc Limit 1
     *  $db->findOne("users", ["OR" => [["a" => 1], ["b" => 2]]], ["order" => ["a desc", "b asc"]], ["x","y"]);
     * </code></pre>
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
     *  $db->find("users", ["a" => 1, "b" => "q"]);
     *
     *  //SELECT * FROM users WHERE age>33
     *  $db->find("users", ["age" => [">" => 33]]);
     *
     *  //SELECT x, y FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc
     *  $db->find("users", ["OR" => [["a" => 1], ["b" => 2]]], ["order" => ["a desc", "b asc"]], ["x","y"]);
     * </code></pre>
     *
     * @param string from Table name
     * @param mixed filters Filters to create WHERE conditions
     * @param array options Options to limit[top]/group results
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

                                    let value = "(" . implode(", ", ids) . ")";
                                }
                                let condition = sprintf(this->identifier, key) . is . " " . value;
                            break;
                            case "IS":
                            case "is":
                            case "IS NOT":
                            case "is not":
                                // Don't bind value
                                let condition = sprintf(this->identifier, key) . is . " " . value;
                            break;
                            default:
                                // Bind value
                                let condition = sprintf(this->identifier, key) . is . " " . index,
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
                        let and[] = "(" . implode(" OR ", or) . ")";
                    }
                }
                let sql .= implode(" AND ", and);
            break;
            case "integer":
                let sql .= sprintf(this->identifier, this->id) . "=" . filters;
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
     * <pre><code>
     *  // MySQL: SELECT * FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc LIMIT 10
     *  // MSSQL: SELECT TOP 10 * FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc
     *  $db->select("users", ["OR" => [["a" => 1], ["b" => 2]]], ["order" => ["a desc", "b asc"], "limit" => 10]);
     *
     *  // MySQL: SELECT x, y FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc LIMIT 10 offset 50
     *  // MSSQL: SELECT x, y FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc offset 50 ROWS FETCH NEXT 10 ROWS ONLY
     *  $db->select("users", ["OR" => [["a" => 1], ["b" => 2]]], ["order" => ["a desc", "b asc"], "limit" => 10, "offset" => 50], ["x","y"]);
     * </code></pre>
     *
     * @param string from Table name
     * @param mixed filters Filters to create WHERE conditions
     * @param array options Options to limit/offset/group results
     * @param array fields Fields to retrieve, if not specified get all
     */
    public function select(string! from, var filters = [], array options = [], array fields = [])
    {
        var columns, filtered, values, query, sql = "SELECT ";

        if count(fields) {
            let columns = implode(", ", fields);
        } else {
            let columns = "*";
        }

        if isset options["limit"] {
            // ms sql server only
            if this->driverName == "sqlsrv" {
                if isset options["offset"] {
                    // SQL Server 2012+ ONLY
                    let options["offset"] .= " ROWS FETCH NEXT ". options["limit"] . " ROWS ONLY";
                } else {
                    let sql .= "TOP " . options["limit"] . " ";
                }
                unset options["limit"];
            } elseif this->driverName == "oci" {
                if isset options["offset"] {
                    let options["offset"] .= " ROWS FETCH NEXT ". options["limit"] . " ROWS ONLY";
                } else {
                    if empty filters {
                        let filters = "rownum = " . options["limit"];
                    } else {
                        let filters = ["AND": [filters, ["rownum", options["limit"]]]];
                    }
                }
                unset options["limit"];
            }
        }

        let filtered = this->where(filters),
            sql .= columns . " FROM " . sprintf(this->identifier, from),
            values = filtered[1];

        if !empty filtered[0] {
            let sql .= " WHERE " . filtered[0];
        }

        if isset options["group"] {
            if typeof options["group"] == "array" {
                let sql .= " GROUP BY " . implode(", ", options["group"]);
            } else {
                let sql .= " GROUP BY " . options["group"];
            }
        }
        if isset options["order"] {
            if typeof options["order"] == "array" {
                let sql .= " ORDER BY " . implode(", ", options["order"]);
            } else {
                let sql .= " ORDER BY " . options["order"];
            }
        }
        if isset options["limit"] {
            let sql .= " LIMIT " . options["limit"];
        }
        if isset options["offset"] {
            let sql .= " OFFSET " . options["offset"];
        }

        let query = this->client->prepare(sql);

        let this->error = query->execute(values) ? null : query->errorInfo();

        return query;
    }

    /**
     * INSERT record into table.
     *
     * <pre><code>
     *  //INSERT INTO users (a,b) VALUES (1, 2)
     *  $db->insert("users", [["a" => 1], ["b" => 2]]);
     * </code></pre>
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
            let columns[] = sprintf(this->identifier, key),
                values[":" . key] = value;
        }

        let sql = "INSERT INTO " . sprintf(this->identifier, from) . " (" . implode(", ", columns) . ") VALUES (" . implode(", ", array_keys(values)) . ")",
            query = this->client->prepare(sql),
            status = query->execute(values),
            this->error = status ? null : query->errorInfo();

        return status;
    }

    /**
     * UPDATE records in the table.
     *
     * <pre><code>
     *  //UPDATE users SET a=1, b=2 WHERE id=10 OR foo="bar"
     *  $db->update("users", ["OR" => ["id" => 10, "foo" => "bar"]], [["a" => 1], ["b" => 2]]);
     * </code></pre>
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
                columns[] = sprintf(this->identifier, key) . " = :" . key;
        }

        let filtered = this->where(filters, values),
            sql = "UPDATE " . sprintf(this->identifier, from) . " SET " . implode(", ", columns) . " WHERE " . filtered[0],
            values = array_merge(values, filtered[1]),
            query = this->client->prepare(sql),
            status = query->execute(values),
            this->error = status ? null : query->errorInfo();

        return status;
    }

    /**
     * Remove records from the table.
     *
     * <pre><code>
     *  //DELETE FROM users WHERE id=10 OR foo="bar"
     *  $db->delete("users", ["OR" => ["id" => 10, "foo" => "bar"]]);
     * </code></pre>
     *
     * @param string from Table name
     * @param mixed filters Filters to create WHERE conditions
     */
    public function delete(string! from, var filters = [])
    {
        var filtered, sql, values, query, status;

        let filtered = this->where(filters),
            sql = "DELETE FROM " . sprintf(this->identifier, from) . " WHERE " . filtered[0],
            values = filtered[1],
            query = this->client->prepare(sql),
            status = query->execute(values),
            this->error = status ? null : query->errorInfo();

        return status;
    }

    /**
     * Query sql statement. execute the statement and populate into Model object:
     *
     * <pre><code>
     *  //select * from t where id=1
     *  $m = $this->db->query('select * from t where id=:id', [':id' => 1], new stdClass);
     *
     *  //select * from t where id=1 OR foo='bar'
     *  $m = $this->db->query('select * from t where id=? OR foo=?', [1, "bar"], '\Ice\Arr');
     * </code></pre>
     *
     * @param string sql SQL with kinda of placeholders
     * @param array values Replace placeholders in the sql
     * @param mixed obj The classname or arr object will be populated from query result
     * @return PDOStatement|object|null If fail return null
     */
    public function query(string! sql, array values = [], var obj = null)
    {
        var query, result, status;

        let query = this->client->prepare(sql),
            status = query->execute(values),
            this->error = status ? null : query->errorInfo();

        if status && obj {
            if typeof obj == "string" {
                return query->fetchObject(obj);
            }
            let result = query->$fetch(\Pdo::FETCH_ASSOC);
            if result {
                if obj instanceof Arr {
                    obj->replace(result);
                } else {
                    let obj = new Arr(result);
                }
                return obj;
            } else {
                return false;
            }
        }

        return status ? query : null;
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
