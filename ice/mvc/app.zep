
namespace Ice\Mvc;

use Ice\Exception;
use Ice\Loader;
use Ice\Di\Access;
use Ice\Di\DiInterface;
use Ice\Mvc\Dispatcher;
use Ice\Mvc\ModuleInterface;
use Ice\Http\Response\ResponseInterface;

class App extends Access
{

    protected _defaultModule { get, set };
    protected _modules { get, set };

    /**
     * Handles a MVC request
     *
     * @param string method
     * @param string uri
     * @return ResponseInterface
     */
    public function handle(method = null, uri = null) -> <ResponseInterface> | boolean
    {
        var router, request, response, module, modules, $namespace, path, $class, loader, dispatcher, controller, view;

        let request = this->_di->getRequest();
        if method == null {
            let method = request->getMethod();
        }

        if uri == null {
            let uri = request->get("_url");
        }

        let router = this->_di->getRouter(),
            response = router->handle(method, uri);

        if !(typeof response == "object" && (response instanceof ResponseInterface)) {

            let module = response["module"],
                modules = this->_modules;

            if !modules {
                let modules = [
                    "default": [
                        "namespace": "App",
                        "path": "../app/"
                    ]];
            }

            if !isset modules[module] {
                throw new Exception(sprintf("Module '%s' isn't registered in the application container", module));
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

            if !fetch $class, module["class"] {
                let $class = "Module";
            }

            if !fetch $namespace, module["namespace"] {
                let $namespace = $class;
            }

            let loader = new Loader();
            loader->addNamespace($namespace, path)->register();

            let module = <ModuleInterface> create_instance_params($namespace . "\\" . $class, [this->_di]),
                dispatcher = this->_di->getDispatcher();

            dispatcher->setDefaultNamespace($namespace . "\\" . dispatcher->getHandlerSuffix());

            module->registerAutoloaders();
            module->registerServices(this->_di);

            dispatcher->setMethod(method);
            dispatcher->setModule(response["module"]);
            dispatcher->setHandler(response["handler"]);
            dispatcher->setAction(response["action"]);
            dispatcher->setParams(response["params"]);

            let response = dispatcher->dispatch();

            this->_di->applyHook("app.after.dispatch", [response]);

            if !(typeof response == "object" && (response instanceof ResponseInterface)) {

                let controller = response,
                    response = this->_di->getResponse(),
                    view = controller->view;

                if view->getContent() === null {
                    if !view->getFile() {
                        view->setSilent(true);
                        view->setFile(dispatcher->getHandler() . "/" . dispatcher->getAction());
                    }
                    if !view->count() {
                        view->replace(dispatcher->getParams());
                    }

                    view->setContent(view->render());
                }

                response->setBody(view->layout(view->getMainView()));
            }
        }

        this->_di->applyHook("app.after.handle", [response]);

        return response->send();
    }
}