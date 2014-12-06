
namespace Ice\Mvc\View\Engine;

use Ice\Di;
use Ice\Mvc\View\ViewInterface;

interface EngineInterface
{

	public function __construct(<ViewInterface> view, <Di> di = null);

	public function render(string! path, array data = []);
}