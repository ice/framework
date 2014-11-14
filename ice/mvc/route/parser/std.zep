
namespace Ice\Mvc\Route\Parser;

use Ice\Mvc\Route\Parser\ParserInterface;

/**
 * Parses routes of the following form:
 *
 * "/user/{name}/{id:[0-9]+}"
 */
class Std implements ParserInterface
{
    const VARIABLE_REGEX = "~\\{ \\s* ([a-zA-Z][a-zA-Z0-9_]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}~x";
    const DEFAULT_DISPATCH_REGEX = "[^/]+";

    public function parse(route)
    {
        var matches, routeData, value;
        int offset = 0;

        let matches = [];

        if !preg_match_all(self::VARIABLE_REGEX, route, matches, PREG_OFFSET_CAPTURE | PREG_SET_ORDER) {
            return [route];
        }

        let routeData = [];
        for value in matches  {
            if value[0][1] > offset {
                let routeData[] = substr(route, offset, value[0][1] - offset);
            }

            let routeData[] = [
                value[1][0],
                isset(value[2]) ? trim(value[2][0]) : self::DEFAULT_DISPATCH_REGEX
            ];

            let offset = value[0][1] + strlen(value[0][0]);
        }

        if (offset != strlen(route)) {
            let routeData[] = substr(route, offset);
        }

        return routeData;
    }
}