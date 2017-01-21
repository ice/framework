
namespace Ice\Mvc\Route\Parser;

use Ice\Exception;
use Ice\Mvc\Route\Parser\ParserInterface;

/**
 * Parses route strings of the following form:
 *
 * "/user/{name}[/{id:[0-9]+}]"
 */
class Std implements ParserInterface
{
    const VARIABLE_REGEX = "\\{ \\s* ([a-zA-Z_][a-zA-Z0-9_-]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}";
    const DEFAULT_DISPATCH_REGEX = "[^/]+";

    public function parse(route)
    {
        var routeWithoutClosingOptionals, numOptionals, segments, currentRoute, routeDatas, n, segment;

        let routeWithoutClosingOptionals = rtrim(route, "]"),
            numOptionals = strlen(route) - strlen(routeWithoutClosingOptionals);
        
        // Split on [ while skipping placeholders
        let segments = preg_split("~" . self::VARIABLE_REGEX . "(*SKIP)(*F) | \\[~x", routeWithoutClosingOptionals);

        if numOptionals !== count(segments) - 1 {
            // If there are any ] in the middle of the route, throw a more specific error message
            if preg_match("~" . self::VARIABLE_REGEX . "(*SKIP)(*F) | \\]~x", routeWithoutClosingOptionals) {
                throw new Exception("Optional segments can only occur at the end of a route");
            }

            throw new Exception("Number of opening '[' and closing ']' does not match");
        }

        let currentRoute = "",
            routeDatas = [];

        for n, segment in segments {
            if segment === "" && n !== 0 {
                throw new Exception("Empty optional part");
            }

            let currentRoute .= segment,
                routeDatas[] = this->parsePlaceholders(currentRoute);
        }

        return routeDatas;
    }

    /**
     * Parses a route string that does not contain optional segments.
     */
    private function parsePlaceholders(route)
    {
        var matches, routeData, value, offset;

        let matches = null;

        if !preg_match_all("~" . self::VARIABLE_REGEX . "~x", route, matches, PREG_OFFSET_CAPTURE | PREG_SET_ORDER) {
            return [route];
        }

        let offset = 0,
            routeData = [];

        for value in matches {
            if value[0][1] > offset {
                let routeData[] = substr(route, offset, value[0][1] - offset);
            }

            let routeData[] = [
                value[1][0],
                isset(value[2]) ? trim(value[2][0]) : self::DEFAULT_DISPATCH_REGEX
            ];
            let offset = value[0][1] + strlen(value[0][0]);
        }

        if offset != strlen(route) {
            let routeData[] = substr(route, offset);
        }

        return routeData;
    }
}