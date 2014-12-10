
namespace Ice\Mvc;

use Ice\Exception;
use Ice\Loader;
use Ice\Di\Access;
use Ice\Mvc\Dispatcher;
use Ice\Http\Response\ResponseInterface;

class App extends Access
{

    protected _autoRender = true { get, set };
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
        var router, request, response, dispatcher, controller, view;

        let request = this->_di->{"getRequest"}();
        if method == null {
            let method = request->getMethod();
        }

        if uri == null {
            let uri = request->get("_url");
        }

        let router = this->_di->{"getRouter"}(),
            response = router->handle(method, uri),
            dispatcher = this->_di->{"getDispatcher"}();

        if !(typeof response == "object" && (response instanceof ResponseInterface)) {
            dispatcher->setModules(this->_modules);
            dispatcher->setMethod(method);
            dispatcher->setModule(response["module"]);
            dispatcher->setHandler(response["handler"]);
            dispatcher->setAction(response["action"]);
            dispatcher->setParams(response["params"]);

            let response = dispatcher->dispatch();

            this->_di->applyHook("app.after.dispatch", [response]);

            if !(typeof response == "object" && (response instanceof ResponseInterface)) {

                let controller = response,
                    response = this->_di->{"getResponse"}(),
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

                if this->_autoRender {
                    response->setBody(view->layout(view->getMainView()));
                }
            }
        }

        this->_di->applyHook("app.after.handle", [response]);

        return response->send();
    }
}