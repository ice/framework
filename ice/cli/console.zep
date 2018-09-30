
namespace Ice\Cli;

use Ice\Di;
use Ice\Di\Access;

/**
 * This component allows to create CLI applications.
 *
 * @package     Ice/Cli
 * @category    Application
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Console extends Access
{

    protected modules { get, set };

    const NORMAL = 0;
    const BOLD_BRIGHT = 1;
    const UNDERLINE = 4;
    const INVERSE = 7;

    /**
     * Console constructor
     *
     * @param Di $di
     */
    public function __construct(<Di> di = null)
    {
        // Set the dependency injector
        let this->di = di;

        // Register the console itself as a service
        this->di->set("console", this);
    }

    /**
     * Add module with its dir path, initial class name and namespace
     *
     * @param string name
     * @param array options The keys can be [path|class|namespace]
     * @return object Console
     */
    public function addModule(string name, array options)
    {
        // add or replace module
        let this->modules[name] = options;

        return this;
    }

    /**
     * Handle an command-line request.
     *
     * @param array arguments
     * @return mixed
     */
    public function handle(arguments = null)
    {
        var router, response, dispatcher;

        let router = this->di->get("router"),
            response = router->handle(arguments),
            dispatcher = this->di->get("dispatcher");

        dispatcher->setModules(this->modules);
        dispatcher->setModule(response["module"]);
        dispatcher->setHandler(response["handler"]);
        dispatcher->setAction(response["action"]);
        dispatcher->setParams(response["params"]);

        let response = dispatcher->dispatch();

        return response;
    }

    /**
     * Returns the given text with the correct color codes for a foreground and optionally a background color.
     * Colors: black, red, green, yellow, blue, magenta, cyan, lightgray, white*
     *
     * @param string text The text to color
     * @param string color The foreground color
     * @param int decoration Formatting type
     * @param string bgColor The background color
     * @return string Coded string
     */
    public static function color(string text, string color = null, int decoration = 0, string bgColor = null)
    {
        var colors, bgColors, colored, e, foreground, background;

        let colors = [
            "black": "30",
            "red": "31",
            "green": "32",
            "yellow": "33",
            "blue": "34",
            "magenta": "35",
            "cyan": "36",
            "lightgray": "37",
            "white": "97"
        ];

        let bgColors = [
            "black": "40",
            "red": "41",
            "green": "42",
            "yellow": "43",
            "blue": "44",
            "magenta": "45",
            "cyan": "46",
            "lightgray": "47",
            "white": "107"
        ];

        fetch foreground, colors[color];
        fetch background, bgColors[bgColor];

        let e = "\e",
            colored = e . "[" . decoration . (foreground ? ";" . foreground : "") . "m";

        if background {
            let colored .= e . "[" . background . "m";
        }

        return colored . text . e . "[0m";
    }
}
