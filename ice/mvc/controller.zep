
namespace Ice\Mvc;

use Ice\Di\Access;

/**
 * Every mvc controller should extend this class that encapsulates all the controller functionality.
 * The Controller class should at least have a "indexAction" method.
 *
 * @package     Ice/Di/Access
 * @category    Handler
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Controller extends Access
{

    /**
     * Controller constructor. Run onConstruct() if method exist.
     */
    public final function __construct()
    {
        parent::__construct();

        if method_exists(this, "onConstruct") {
            this->{"onConstruct"}();
        }
    }
}
