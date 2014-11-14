
namespace Ice\Mvc\Route\Dispatcher;

use Ice\Mvc\Router;
use Ice\Mvc\Route\Dispatcher\DispatcherInterface;

class GroupCount implements DispatcherInterface
{

    protected _staticRouteMap { set };
    protected _variableRouteData { set };

    public function __construct(array data = [])
    {
        if count(data) {
            let this->_staticRouteMap = data[0],
                this->_variableRouteData = data[1];
        }
    }

    public function setData(array! data = [])
    {
        let this->_staticRouteMap = data[0],
            this->_variableRouteData = data[1];
    }

    public function dispatch(httpMethod, uri)
    {
        if isset this->_staticRouteMap[uri] {
            return this->dispatchStaticRoute(httpMethod, uri);
        } else {
            return this->dispatchVariableRoute(httpMethod, uri);
        }
    }

    private function dispatchStaticRoute(httpMethod, uri)
    {
        var routes;

        let routes = this->_staticRouteMap[uri];

        if isset routes[httpMethod] {
            return [Router::FOUND, routes[httpMethod], []];
        } else {
            if httpMethod === "HEAD" && isset routes["GET"] {
                return [Router::FOUND, routes["GET"], []];
            } else {
                return [Router::METHOD_NOT_ALLOWED, array_keys(routes)];
            }
        }
    }

    private function dispatchVariableRoute(httpMethod, uri)
    {
        var data, matches, routes, handler, varName, varNames, vars;
        int i;

        let matches = [];

        for data in this->_variableRouteData {
            if !preg_match(data["regex"], uri, matches) {
                continue;
            }

            let routes = data["routeMap"][count(matches)];

            if !isset routes[httpMethod] {
                if httpMethod === "HEAD" && isset routes["GET"] {
                    let httpMethod = "GET";
                } else {
                    return [Router::METHOD_NOT_ALLOWED, array_keys(routes)];
                }
            }

            let handler = routes[httpMethod][0],
                varNames = routes[httpMethod][1];

            let vars = [],
                i = 0;

            for varName in varNames {
                let i++,
                    vars[varName] = matches[i];
            }

            return [Router::FOUND, handler, vars];
        }

        return [Router::NOT_FOUND];
    }
}