
namespace Ice\Mvc;

use Ice\Di\DiInterface;

interface ModuleInterface
{

    public function registerAutoloaders();
    
    public function registerServices(<DiInterface> di);
}