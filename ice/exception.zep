
namespace Ice;

/**
 * Exception class. Translates exceptions using the [I18n] class.
 */
class Exception extends \Exception
{

    /**
     * Creates a new exception.
     *
     * @param mixed message Error message
     * @param mixed code The exception code
     * @param Exception previous Previous exception
     * @return void
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

}