
namespace Ice\Cli;

use Ice\Loader;
use Ice\Exception;
use Ice\Cli\Dispatcher;
use Ice\Di\Access;
use Ice\Di\DiInterface;

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
        var router, handled, module, modules, $namespace, path, className, loader, dispatcher, task;

        let router = this->_di->getRouter(),
            handled = router->handle(arguments),
            module = handled["module"];

        let modules = this->_modules;
        if !isset modules[module] {
            throw new Exception(sprintf("Module '%s' isn't registered in the console container", module));
        }

        let module = modules[module];
        if typeof module != "array" {
            throw new Exception("Module definition must be an array");
        }

        if fetch path, module["path"] {
            if !file_exists(path) {
                throw new Exception(sprintf("Module definition path '%s' doesn't exist", path));
            }
        }

        if !fetch className, module["className"] {
            let className = "Module";
        }

        if !fetch $namespace, module["namespace"] {
            let $namespace = className;
        }

        let loader = new Loader();
        loader->addNamespace($namespace, path)->register();

        let className = $namespace . "\\" . className,
            module = new {className}(this->_di);

        let dispatcher = this->_di->getDispatcher();
        dispatcher->setDefaultNamespace($namespace . "\\" . dispatcher->getHandlerSuffix());

        module->registerAutoloaders();
        module->registerServices(this->_di);

        dispatcher->setModule(handled["module"]);
        dispatcher->setHandler(handled["handler"]);
        dispatcher->setAction(handled["action"]);
        dispatcher->setParams(handled["params"]);

        let task = dispatcher->dispatch();

        return task;
    }
}