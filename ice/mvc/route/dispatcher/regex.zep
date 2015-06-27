
namespace Ice\Mvc\Route\Dispatcher;

use Ice\Mvc\Route\Dispatcher\DispatcherInterface;
use Ice\Mvc\Router;

abstract class Regex implements DispatcherInterface
{

    protected staticRouteMap { set };
    protected variableRouteData { set };

    public function setData(array! data = [])
    {
        let this->staticRouteMap = data[0],
            this->variableRouteData = data[1];
    }

    protected abstract function dispatchVariableRoute(routeData, uri);

    public function dispatch(httpMethod, uri)
    {
        var varRouteData, result, allowedMethods, method, routeData;

        if isset this->staticRouteMap[uri] {
            return this->dispatchStaticRoute(httpMethod, uri);
        }

        let varRouteData = this->variableRouteData;

        if isset varRouteData[httpMethod] {
            let result = this->dispatchVariableRoute(varRouteData[httpMethod], uri);

            if result[0] === Router::FOUND {
                return result;
            }
        } elseif httpMethod === "HEAD" && isset varRouteData["GET"] {
            let result = this->dispatchVariableRoute(varRouteData["GET"], uri);

            if result[0] === Router::FOUND {
                return result;
            }
        }

        // Find allowed methods for this URI by matching against all other
        // HTTP methods as well
        let allowedMethods = [];

        for method, routeData in varRouteData {
            if method === httpMethod {
                continue;
            }

            let result = this->dispatchVariableRoute(routeData, uri);

            if result[0] === Router::FOUND {
                let allowedMethods[] = method;
            }
        }
        // If there are no allowed methods the route simply does not exist
        if allowedMethods {
            return [Router::METHOD_NOT_ALLOWED, allowedMethods];
        } else {
            return [Router::NOT_FOUND];
        }
    }

    protected function dispatchStaticRoute(httpMethod, uri)
    {
        var routes;

        let routes = this->staticRouteMap[uri];

        if isset routes[httpMethod] {
            return [Router::FOUND, routes[httpMethod], []];
        } elseif httpMethod === "HEAD" && isset routes["GET"] {
            return [Router::FOUND, routes["GET"], []];
        } else {
            return [Router::METHOD_NOT_ALLOWED, array_keys(routes)];
        }
    }
}