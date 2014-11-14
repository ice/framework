
namespace Ice\Mvc;

use Ice\Di\Access;

abstract class Controller extends Access
{

    public final function __construct()
    {
        parent::__construct();

        if method_exists(this, "onConstruct") {
            this->{"onConstruct"}();
        }
    }
}