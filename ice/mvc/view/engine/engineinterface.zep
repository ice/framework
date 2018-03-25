
namespace Ice\Mvc\View\Engine;

use Ice\Di;
use Ice\Mvc\View\ViewInterface;

/**
 * Engine interface.
 *
 * @package     Ice/View
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
interface EngineInterface
{

	public function __construct(<ViewInterface> view, <Di> di = null);

	public function render(string! path, array data = []);
}
