
namespace Ice\Mvc\View;

interface ViewInterface
{

    public function getEngines();

    public function render(file = null, array data = []);
}