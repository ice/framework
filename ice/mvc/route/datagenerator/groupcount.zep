
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
        var routeMap, regex, route, regexes, numGroups, numVariables;
        int repeat, i;

        let routeMap = [],
            regexes = [],
            numGroups = 0;

        for regex, route in regexToRoutesMap  {
            let numVariables = count(route->variables),
                numGroups = max(numGroups, numVariables),
                repeat = numGroups - numVariables,
                regexes[] = regex . str_repeat("()", repeat),
                i = numGroups + 1,
                routeMap[i] = [route->handler, route->variables],
                numGroups++;
        }

        let regex = "~^(?|" . implode("|", regexes) . ")$~";
        return ["regex": utf8_encode(regex), "routeMap": routeMap];
    }
}