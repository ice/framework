
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
        var handler, varRouteData, result, allowedMethods, uriMap, method, routeData;

        if isset this->staticRouteMap[httpMethod] && isset this->staticRouteMap[httpMethod][uri] {
            let handler = this->staticRouteMap[httpMethod][uri];
            return [Router::FOUND, handler, []];
        } elseif httpMethod === "HEAD" && isset this->staticRouteMap["GET"][uri] {
            let handler = this->staticRouteMap["GET"][uri];
            return [Router::FOUND, handler, []];
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

        // Find allowed methods for this URI by matching against all other HTTP methods as well
        let allowedMethods = [];

        for method, uriMap in this->staticRouteMap {
            if method !== httpMethod && isset uriMap[uri] {
                let allowedMethods[] = method;
            }
        }

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
}