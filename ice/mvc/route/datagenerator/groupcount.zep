
namespace Ice\Mvc\Route\DataGenerator;

use Ice\Mvc\Route\DataGenerator\Regex;

class GroupCount extends Regex
{

    protected function getApproxChunkSize()
    {
        return 10;
    }

    public function processChunk(regexToRoutesMap)
    {
        var routeMap, regex, regexes, route, routes, numGroups, numVariables;
        int repeat, i;

        let routeMap = [],
            regexes = [];

        let numGroups = 0;
        for regex, routes in regexToRoutesMap  {
            let numVariables = count(reset(routes)->variables),
                numGroups = max(numGroups, numVariables);


            let repeat = numGroups - numVariables,
                regexes[] = regex . str_repeat("()", repeat);

            for route in routes {
                let i = numGroups + 1;
                let routeMap[i][route->httpMethod] = [route->handler, route->variables];
            }

            let numGroups++;
        }

        let regex = "~^(?|" . implode("|", regexes) . ")$~";
        return ["regex": utf8_encode(regex), "routeMap": routeMap];
    }
}