
namespace Ice\Mvc;

use Ice\Di;

interface ModuleInterface
{

    public function registerAutoloaders();
    
    public function registerServices(<Di> di);
}