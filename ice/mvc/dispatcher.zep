
namespace Ice\Mvc;

use Ice\Exception;
use Ice\Mvc\Route\Collector;

/**
 * Dispatching is the process of taking the request object, extracting the module name, controller name, action name,
 * and optional parameters contained in it, and then instantiating a controller and calling an action on it.
 *
 * @package     Ice/Dispatcher
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Dispatcher extends \Ice\Dispatcher
{

    protected method { get, set };
    protected handlers = "Controllers";
    protected handlerSuffix = "Controller";

    const REDIRECT_CYCLIC = 5;

    /**
     * Get active method, first check whether a method with the HTTP method as prefix exist.
     *
     * @return string
     */
    public function getActiveMethod() -> string
    {
        var action;

        let action = strtolower(this->method) . ucfirst(this->action) . this->actionSuffix;
        if method_exists(this->activeHandler, action) {
            return action;
        }

        return parent::getActiveMethod();
    }

    public function dispatch()
    {
        var parent, response;

        let parent = parent::dispatch(),
            response = this->di->get("response");

        // Throw an exception after 16 consecutive redirects
        if response->getRedirects() > response->getLoops() {
            if this->silent {
                // 310 Too Many Redirects
                response->setStatus(310);
                response->setBody(response->getMessage(310));

                return response;
            }
            throw new Exception("This Webpage has a redirect loop", self::REDIRECT_CYCLIC);
        }

        return parent;
    }
}
