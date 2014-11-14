
namespace Ice\Db;

interface DbInterface
{

    public function findOne(string! from, var filters = [], array fields = [], array options = []);

    public function find(string! from, var filters = [], array fields = [], array options = []);

    public function select(string! from, var filters = [], array fields = [], array options = []);

    public function insert(string! from, array fields = []);

    public function update(string! from, var filters = [], array fields = []);
}