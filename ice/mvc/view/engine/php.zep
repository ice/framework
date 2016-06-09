
namespace Ice\Mvc\View\Engine;

use Ice\Mvc\View\Engine;

/**
 * PHP template engine.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 */
class Php extends Engine
{

    /**
     * Render the PHP file.
     *
     * @param string path
     * @param array data
     * @return string
     */
    public function render(string! path, array data = [])
    {
        extract(data);
        ob_start();
        require path;
        return ob_get_clean();
    }
}
