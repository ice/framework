
namespace Ice\Mvc\Route\DataGenerator;

use Ice\Mvc\Route\DataGenerator\DataGeneratorInterface;
use Ice\Exception;
use Ice\Mvc\FastRoute;

abstract class Regex implements DataGeneratorInterface
{

    protected staticRoutes = [];
    protected methodToRegexToRoutesMap = [];

    protected abstract function getApproxChunkSize();
    protected abstract function processChunk(regexToRoutesMap);

    public function addRoute(httpMethod, routeData, handler)
    {
        if this->isStaticRoute(routeData) {
            this->addStaticRoute(httpMethod, routeData, handler);
        } else {
            this->addVariableRoute(httpMethod, routeData, handler);
        }
    }

    public function getData()
    {
        if empty this->methodToRegexToRoutesMap {
            return [this->staticRoutes, []];
        }

        return [this->staticRoutes, this->generateVariableRouteData()];
    }

    protected function generateVariableRouteData()
    {
        var chunkSize, chunks, data, method, regexToRoutesMap;

        let data = [];

        for method, regexToRoutesMap in this->methodToRegexToRoutesMap {
            let chunkSize = this->computeChunkSize(count(regexToRoutesMap)),
                chunks = array_chunk(regexToRoutesMap, chunkSize, true),
                data[method] = array_map([this, "processChunk"], chunks);
        }

        return data;
    }

    protected function computeChunkSize(count)
    {
        var numParts;
        float round, ceil;

        let round = count / this->getApproxChunkSize(),
            numParts = max(1, round(round)),
            ceil = count / numParts;

        return ceil(ceil);
    }

    protected function isStaticRoute(routeData)
    {
        return count(routeData) == 1 && is_string(routeData[0]);
    }

    protected function addStaticRoute(httpMethod, routeData, handler)
    {
        var routeStr, route;

        let routeStr = routeData[0];

        if isset this->staticRoutes[httpMethod] && isset this->staticRoutes[httpMethod][routeStr] {
            throw new Exception(sprintf("Cannot register two routes matching '%s' for method '%s'",
                routeStr, httpMethod
            ));
        }

        if isset this->methodToRegexToRoutesMap[httpMethod] {
            for route in this->methodToRegexToRoutesMap[httpMethod] {
                if route->matches(routeStr) {
                    throw new Exception(sprintf(
                        "Static route '%s' is shadowed by previously defined variable route '%s' for method '%s'",
                        routeStr, route->regex, httpMethod
                    ));
                }
            }
        }

        let this->staticRoutes[httpMethod][routeStr] = handler;
    }

    protected function addVariableRoute(httpMethod, routeData, handler)
    {
        var regex, variables;

        let regex = this->buildRegexForRoute(routeData)[0],
            variables = this->buildRegexForRoute(routeData)[1];

        if isset this->methodToRegexToRoutesMap[httpMethod] && isset this->methodToRegexToRoutesMap[httpMethod][regex] {
            throw new Exception(sprintf(
                "Cannot register two routes matching '%s' for method '%s'",
                regex, httpMethod
            ));
        }

        let this->methodToRegexToRoutesMap[httpMethod][regex] = new FastRoute(
            httpMethod, handler, regex, variables
        );
    }

    protected function buildRegexForRoute(routeData)
    {
        var regex, variables, part, varName, regexPart;

        let regex = "",
            variables = [];

        for part in routeData {
            if typeof part == "string" {
                let regex .= preg_quote(part, "~");
                continue;
            }

            let varName = part[0],
                regexPart = part[1];

            if isset variables[varName] {
                throw new Exception(sprintf(
                    "Cannot use the same placeholder '%s' twice", varName
                ));
            }

            let variables[varName] = varName,
                regex .= "(" . regexPart . ")";
        }

        return [regex, variables];
    }
}
