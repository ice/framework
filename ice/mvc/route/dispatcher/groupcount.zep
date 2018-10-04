
namespace Ice\Mvc\Route\Dispatcher;

use Ice\Mvc\Route\Dispatcher\Regex;
use Ice\Mvc\FastRouter;

class GroupCount extends Regex
{

    protected staticRouteMap { set };
    protected variableRouteData { set };

    public function __construct(array data = [])
    {
        if count(data) {
            let this->staticRouteMap = data[0],
                this->variableRouteData = data[1];
        }
    }

    protected function dispatchVariableRoute(routeData, uri)
    {
        var data, matches, handler, varName, varNames, vars;
        int i, j;

        let matches = null;

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

            return [FastRouter::FOUND, handler, vars];
        }

        return [FastRouter::NOT_FOUND];
    }
}
