
namespace Ice\Mvc;

use Ice\Di\Access;
use Ice\Http\Response\ResponseInterface;

/**
 * This component allows to create MVC applications.
 *
 * @package     Ice/Mvc
 * @category    Application
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class App extends Access
{

    protected _autoRender = true { get, set };
    protected _modules { get, set };

    /**
     * Handles a MVC request.
     *
     * @param string method
     * @param string uri
     * @return ResponseInterface|boolean
     */
    public function handle(method = null, uri = null) -> <ResponseInterface> | boolean
    {
        var argv, router, request, response, dispatcher, controller, view;

        let request = this->_di->get("request", null, true);
        if method == null {
            let method = request->getMethod();
        }

        if uri == null {
            let uri = request->get("_url");
        }

        // Set the default method & uri for the CLI
        if !method && PHP_SAPI === "cli" {
            let method = "GET",
                argv = _SERVER["argv"];

            if !uri && isset argv[1] {
                let uri = argv[1];
            }
        }

        let router = this->_di->get("router", null, true),
            response = router->handle(method, uri),
            dispatcher = this->_di->get("dispatcher", null, true);

        this->_di->applyHook("app.after.router.handle", [response]);

        if !(typeof response == "object" && (response instanceof ResponseInterface)) {
            dispatcher->setModules(this->_modules);
            dispatcher->setMethod(method);
            dispatcher->setModule(response["module"]);
            dispatcher->setHandler(response["handler"]);
            dispatcher->setAction(response["action"]);
            dispatcher->setParams(response["params"]);

            let response = dispatcher->dispatch();

            this->_di->applyHook("app.after.dispatcher.dispatch", [response]);

            if !(typeof response == "object" && (response instanceof ResponseInterface)) {

                let controller = response,
                    response = this->_di->get("response", null, true),
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
