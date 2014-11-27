
namespace Ice\Mvc\Route\Dispatcher;

use Ice\Mvc\Route\Dispatcher\Regex;
use Ice\Mvc\Router;

class GroupCount extends Regex
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

    protected function dispatchVariableRoute(routeData, uri)
    {
        var data, matches, handler, varName, varNames, vars;
        int i, j;

        let matches = [];

        for data in routeData {
            if !preg_match(data["regex"], uri, matches) {
                continue;
            }

            let j = count(matches),
                handler = data["routeMap"][j][0],
                varNames = data["routeMap"][j][1];

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