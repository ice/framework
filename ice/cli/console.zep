
namespace Ice\Cli;

use Ice\Loader;
use Ice\Exception;
use Ice\Cli\Dispatcher;
use Ice\Di\Access;

/**
 * This component allows to create CLI applications
 */
class Console extends Access
{

    protected _modules { get, set };

    /**
     * Handle the whole command-line tasks
     *
     * @param array arguments
     * @return mixed
     */
    public function handle(arguments = null)
    {
        var router, response, dispatcher;

        let router = this->_di->{"getRouter"}(),
            response = router->handle(arguments),
            dispatcher = this->_di->{"getDispatcher"}();

        dispatcher->setModules(this->_modules);
        dispatcher->setModule(response["module"]);
        dispatcher->setHandler(response["handler"]);
        dispatcher->setAction(response["action"]);
        dispatcher->setParams(response["params"]);

        let response = dispatcher->dispatch();

        return response;
    }
}