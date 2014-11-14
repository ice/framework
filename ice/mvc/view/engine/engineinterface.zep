
namespace Ice\Mvc\View\Engine;

use Ice\Di\DiInterface;
use Ice\Mvc\View\ViewInterface;

interface EngineInterface
{

	public function __construct(<ViewInterface> view, <DiInterface> di = null);

	public function render(string! path, array data = []);
}