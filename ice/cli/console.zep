
namespace Ice\Cli;

use Ice\Di;
use Ice\Di\Access;

/**
 * This component allows to create CLI applications.
 *
 * @package     Ice/Cli
 * @category    Application
 * @author      Ice Team
 * @copyright   (c) 2014-2020 Ice Team
 * @license     http://iceframework.org/license
 */
class Console extends Access
{

    protected modules { get, set };

    const NORMAL = 0;
    const BOLD_BRIGHT = 1;
    const UNDERLINE = 4;
    const INVERSE = 7;

    const BLACK = 30;
    const RED = 31;
    const GREEN = 32;
    const YELLOW = 33;
    const BLUE = 34;
    const MAGENTA = 35;
    const CYAN = 36;
    const LIGHTGRAY = 37;
    const WHITE = 97;

    const BG_BLACK = 40;
    const BG_RED = 41;
    const BG_GREEN = 42;
    const BG_YELLOW = 43;
    const BG_BLUE = 44;
    const BG_MAGENTA = 45;
    const BG_CYAN = 46;
    const BG_LIGHTGRAY = 47;
    const BG_WHITE = 107;

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
     *
     * @param string text The text to color
     * @param int color The foreground color
     * @param int decoration Formatting type
     * @param int bgColor The background color
     * @return string Coded string
     */
    public function color(string text, int color = null, int decoration = 0, int bgColor = null)
    {
        var colored, e;

        boolean colors = globals_get("cli_colors");

        if colors {
            let e = "\e", // escape (hex 1B) chr(27)
                colored = e . "[" . decoration . (color ? ";" . color : "") . "m";

            if bgColor {
                let colored .= e . "[" . bgColor . "m";
            }

            return colored . text . e . "[0m";
        } else {
            return text;
        }
    }

    /**
     * Returns info text.
     *
     * @param string text
     * @return string
     */
    public function info(string text)
    {
        return this->color(text, self::CYAN);
    }

    /**
     * Returns success text.
     *
     * @param string text
     * @return string
     */
    public function success(string text)
    {
        return this->color(text, self::GREEN);
    }

    /**
     * Returns warning text.
     *
     * @param string text
     * @return string
     */
    public function warning(string text)
    {
        return this->color(text, self::YELLOW);
    }

    /**
     * Returns error text.
     *
     * @param string text
     * @return string
     */
    public function error(string text)
    {
        return this->color(text, self::RED);
    }
}
