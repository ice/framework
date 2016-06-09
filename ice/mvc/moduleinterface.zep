
namespace Ice\Mvc;

use Ice\Di;

/**
 * Module interface.
 *
 * @package     Ice/Mvc
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 */
interface ModuleInterface
{

    public function registerAutoloaders();
    
    public function registerServices(<Di> di);
}
