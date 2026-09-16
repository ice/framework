
namespace Ice\Mvc\View;

/**
 * View interface.
 *
 * @package     Ice/View
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
interface ViewInterface
{
    public function getEngines();

    public function render(file = null, array data = []);
}
