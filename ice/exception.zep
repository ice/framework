
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
     * @param Exception previous Previous exception
     */
    public function __construct(var message = "", code = 0, <\Exception> previous = null)
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
            let message = di->{"get"}("i18n")->translate(str, values);
        } elseif (typeof values == "array") {
            // Check if values is associative or sequential
            if count(array_filter(array_keys(values), "is_string")) {
                let message = strtr(str, values);
            } else {
                let message = call_user_func_array("sprintf", message);
            }
        }

        parent::__construct((string) message, (int) code, <\Exception> previous);
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
     * @param Exception $e
     * @return void
     */
    public static function handler(<\Exception> e)
    {
        // Create new exceptin by this class
        create_instance_params(get_called_class(), [e->getMessage(), e->getCode(), e]);
        exit(1);
    }

    /**
     * Catches errors that are not caught by the error handler, such as E_PARSE.
     *
     * @return  void
     */
    public static function shutdownHandler()
    {
        var e;

        let e = error_get_last();
        if typeof e == "array" && in_array(e["type"], [E_PARSE, E_ERROR, E_USER_ERROR]) {
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
