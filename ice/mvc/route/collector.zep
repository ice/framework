
namespace Ice\Mvc\Route;

use Ice\Mvc\Route\Parser\ParserInterface;
use Ice\Mvc\Route\DataGenerator\DataGeneratorInterface;
use Ice\Mvc\Route\Parser\Std;
use Ice\Mvc\Route\DataGenerator\GroupCount as Generator;

class Collector
{

    private routeParser { set };
    private dataGenerator { set };

    /**
     * Constructs a route collector.
     *
     * @param RouteParser   $routeParser
     * @param DataGenerator $dataGenerator
     */
    public function __construct(<ParserInterface> routeParser = null, <DataGeneratorInterface> dataGenerator = null)
    {
        if !routeParser {
            let routeParser = new Std();
        }

        if !dataGenerator {
            let dataGenerator = new Generator();
        }
            
        let this->routeParser = routeParser,
            this->dataGenerator = dataGenerator;
    }

    /**
     * Adds a route to the collection.
     *
     * The syntax used in the $route string depends on the used route parser.
     *
     * @param string|array $httpMethod
     * @param string $route
     * @param mixed  $handler
     */
    public function addRoute(var httpMethod, string route, handler = null)
    {
        var routeData, method;

        let routeData = this->routeParser->parse(route);

        if typeof httpMethod == "string" {
            let method = httpMethod,
                httpMethod = [method];
        }

        for method in httpMethod {
            this->dataGenerator->addRoute(method, routeData, handler);
        }
    }

    /**
     * Returns the collected route data, as provided by the data generator.
     *
     * @return array
     */
    public function getData()
    {
        return this->dataGenerator->getData();
    }
}