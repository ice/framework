
namespace Ice\Db;

/**
 * Database driver interface.
 *
 * @package     Ice/Db
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
interface DbInterface
{

    public function findOne(string! from, var filters = [], array fields = [], array options = []);

    public function find(string! from, var filters = [], array fields = [], array options = []);

    public function select(string! from, var filters = [], array fields = [], array options = []);

    public function insert(string! from, array fields = []);

    public function update(string! from, var filters = [], array fields = []);

    public function delete(string! from, var filters = []);
}
