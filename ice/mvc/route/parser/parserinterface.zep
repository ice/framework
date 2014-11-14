
namespace Ice\Mvc\Route\Parser;

interface ParserInterface
{

    /**
     * Returns an array of the following form:
     *
     *[
     *  "/fixedRoutePart/",
     *  ["varName", "[^/]+"],
     *  "/moreFixed/",
     *  ["varName2", [0-9]+"],
     *]
     *
     * @param string $route Route to parse
     * 
     * @return array Parsed route data
     */
    public function parse(route);
}