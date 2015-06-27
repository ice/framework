
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

    protected autoRender = true { get, set };
    protected modules { get, set };

    /**
     * Handles a MVC request.
     *
     * @param string method
     * @param string uri
     * @return ResponseInterface|boolean
     */
    public function handle(method = null, uri = null) -> <ResponseInterface> | boolean
    {
        var argv, router, request, response, dispatcher, returned, controller, view;

        let request = this->di->get("request", null, true);
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

        let router = this->di->get("router", null, true),
            response = router->handle(method, uri),
            dispatcher = this->di->get("dispatcher", null, true);

        this->di->applyHook("app.after.router.handle", [response]);

        if !(typeof response == "object" && (response instanceof ResponseInterface)) {
            dispatcher->setModules(this->modules);
            dispatcher->setMethod(method);
            dispatcher->setModule(response["module"]);
            dispatcher->setHandler(response["handler"]);
            dispatcher->setAction(response["action"]);
            dispatcher->setParams(response["params"]);

            let response = dispatcher->dispatch(),
                returned = dispatcher->getReturnedValue();

            if typeof returned == "object" && (returned instanceof ResponseInterface) {
                let response = returned;
            }

            this->di->applyHook("app.after.dispatcher.dispatch", [response]);

            if !(typeof response == "object" && (response instanceof ResponseInterface)) {
                let controller = response,
                    response = this->di->get("response", null, true),
                    view = controller->view;

                // Load views and set the response body if auto render
                if this->autoRender {
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
        }

        this->di->applyHook("app.after.handle", [response]);

        return response->send();
    }
}
