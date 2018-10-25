
namespace Ice;

/**
 * Exception class.
 *
 * @package     Ice/Exception
 * @category    Error
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Exception extends \Exception
{

    /**
     * Creates a new exception.
     * Translate exception's message using the [I18n] class.
     *
     * @param mixed message Error message
     * @param mixed code The exception code
     * @param Exception|Throwable previous Previous exception
     */
    public function __construct(var message = "", code = 0, previous = null)
    {
        var di, values, str;

        let di = Di::$fetch();

        if typeof message == "array" {
            let values = array_slice(message, 1),
                str = message[0];
        } else {
            let values = null,
                str = message;
        }

        // Check if translation module is available.
        if di->has("i18n") {
            let message = di->get("i18n")->translate(str, values);
        } elseif typeof values == "array" {
            // Check if values is associative or sequential
            if count(array_filter(array_keys(values), "is_string")) {
                let message = strtr(str, values);
            } else {
                let message = call_user_func_array("sprintf", message);
            }
        }

        parent::__construct((string) message, (int) code, previous);
    }

    /**
     * Get the full trace as string.
     *
     * @param Exception|Throwable $e
     * @return string
     */
    public function getFullTraceAsString(e)
    {
        var output, frame, args, arg, node;
        int count = 0;

        let output = "";

        for frame in e->getTrace() {
            let args = "";

            if isset frame["args"] {
                let node = [];

                for arg in frame["args"] {
                    switch typeof arg {
                        case "string":
                            let node[] = "'" . arg . "'";
                        break;
                        case "array":
                            let node[] = "Array";
                        break;
                        case "NULL":
                            let node[] = "NULL";
                        break;
                        case "boolean":
                            let node[] = arg ? "true" : "false";
                        break;
                        case "object":
                            let node[] = "Object(" . get_class(arg) . ")";
                        break;
                        case "resource":
                            let node[] = arg;
                        break;
                        default:
                            let node[] = arg;
                        break;
                    }
                }
                let args = join(", ", node);
            }

            let output .= sprintf(
                    "#%s %s: %s(%s)\n",
                    count,
                    (isset frame["file"] ? frame["file"] . "(" . frame["line"] . ")" : "[internal function]"),
                    (isset frame["class"] ? frame["class"] . frame["type"] . frame["function"] : frame["function"]),
                    args
                ),
                count++;
        }
        return output;
    }

    /**
     * PHP error handler, converts all errors into ErrorExceptions. This handler respects error_reporting settings.
     *
     * @throws ErrorException
     * @return true
     */
    public static function errorHandler(int code, string message, string file = null, int line = 0, array context = [])
    {
        if error_reporting() & code {
            // This error is not suppressed by current error reporting settings
            // Convert the error into an ErrorException
            throw new \ErrorException(message, code, 0, file, line);
        }
        // Do not execute the PHP error handler
        return true;
    }

    /**
     * Inline exception handler, displays the error message, source of the exception, and the stack trace of the error.
     *
     * @param Exception|Throwable $e
     * @return void
     */
    public static function handler(e)
    {
        var di, response;

        let di = Di::$fetch(),
            response = di->get("response");

        // Clear the previous response body
        response->setBody("");

        di->applyHook("exception.after.uncaught", [e, di]);

        if response->getBody() {
            echo response->send();
        } else {
            throw e;
        }

        exit(1);
    }

    /**
     * Catches errors that are not caught by the error handler.
     * E_PARSE, E_ERROR, E_CORE_ERROR, E_USER_ERROR
     *
     * @return  void
     */
    public static function shutdownHandler()
    {
        var e;

        let e = error_get_last();
        if typeof e == "array" && in_array(e["type"], [E_PARSE, E_ERROR, E_CORE_ERROR, E_USER_ERROR]) {
            // Clean the output buffer
            ob_get_level();
            ob_clean();
            // Fake an exception for nice debugging
            Exception::handler(new \ErrorException(e["message"], e["type"], 0, e["file"], e["line"]));
            // Shutdown now to avoid a "death loop"
            exit(1);
        }
    }
}
