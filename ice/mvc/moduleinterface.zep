
namespace Ice\Mvc;

use Ice\Di;
use Ice\Loader;

/**
 * Module interface.
 *
 * @package     Ice/Mvc
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
interface ModuleInterface
{

    public function registerAutoloaders(<Loader> loader = null);

    public function registerServices(<Di> di);
}
