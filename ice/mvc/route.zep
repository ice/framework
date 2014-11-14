
namespace Ice\Mvc;

class Route
{

    public httpMethod;
    public regex;
    public variables;
    public handler;

    /**
     * Constructs a route (value object).
     *
     * @param string $httpMethod
     * @param mixed  $handler
     * @param string $regex
     * @param array  $variables
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
     * @param string $str
     *
     * @return bool
     */
    public function matches(string str) -> boolean
    {
        var regex;

        let regex = "~^" . this->regex . "$~";
        return (boolean) preg_match(regex, str);
    }
}
