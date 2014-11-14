
namespace Ice\Mvc\View\Engine;

use Ice\Mvc\View\Engine;

class Php extends Engine
{

    public function render(string! path, array data = [])
    {
        extract(data);
        ob_start();
        require path;
        return ob_get_clean();
    }
}