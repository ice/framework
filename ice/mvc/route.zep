
namespace Ice\Mvc;

/**
 * This class represents every route added to the router.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 * @uses        FastRoute http:/github.com/nikic/FastRoute/commit/02b8aabe519672f250e261e24282dc1937f2637b
 */
class Route
{

    public httpMethod;
    public regex;
    public variables;
    public handler;

    /**
     * Constructs a route (value object).
     *
     * @param string httpMethod
     * @param mixed handler
     * @param string regex
     * @param array variables
     */
    public function __construct(string httpMethod, handler, string regex, array variables)
    {
        let this->httpMethod = httpMethod,
            this->handler = handler,
            this->regex = regex,
            this->variables = variables;
    }

    /**
     * Tests whether this route matches the given string.
     *
     * @param string str
     * @return bool
     */
    public function matches(string str) -> boolean
    {
        var regex;

        let regex = "~^" . this->regex . "$~";
        return (boolean) preg_match(regex, str);
    }
}
