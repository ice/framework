
namespace Ice\Mvc\View;

use Ice\Di;
use Ice\Di\Access;
use Ice\Mvc\View\ViewInterface;
use Ice\Mvc\View\Engine\EngineInterface;

/**
 * View template engine.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Engine extends Access implements EngineInterface
{
    
    protected view;
    protected options { set };

    /**
     * Engine constructor. Set the view and di object.
     */
    public function __construct(<ViewInterface> view, <Di> di = null)
    {
        let this->view = view,
            this->di = di;
    }

    /**
     * Get the view content.
     *
     * @return string
     */
    public function getContent() -> string
    {
        return this->view->getContent();
    }

    /**
     * Load some view.
     *
     * @param string path
     * @param array data
     */
    public function load(string! path, array data = []) -> string
    {
        return this->view->load(path, data);
    }

    /**
     * Load some partial view.
     *
     * @param string path
     * @param array data
     */
    public function partial(string! path, array data = []) -> string
    {
        return this->view->partial(path, data);
    }

    /**
     * Render some view.
     *
     * @param string path
     * @param array data
     */
    public abstract function render(string! path, array data = []);
}
