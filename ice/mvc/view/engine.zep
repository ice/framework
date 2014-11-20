
namespace Ice\Mvc\View;

use Ice\Di\Access;
use Ice\Di\DiInterface;
use Ice\Mvc\View\ViewInterface;
use Ice\Mvc\View\Engine\EngineInterface;

abstract class Engine extends Access implements EngineInterface
{
    
    protected _view;
    protected _options { set };

    public function __construct(<ViewInterface> view, <DiInterface> di = null)
    {
        let this->_view = view;
        parent::__construct(di);
    }

    public function getContent() -> string
    {
        return this->_view->getContent();
    }

    public function load(string! path, array data = []) -> string
    {
        return this->_view->load(path, data);
    }

    public function partial(string! path, array data = []) -> string
    {
        return this->_view->partial(path, data);
    }

    public abstract function render(string! path, array data = []);
}