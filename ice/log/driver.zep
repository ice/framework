
namespace Ice\Log;

use Ice\Log;

/**
 * This is a simple Logger implementation that other Loggers can inherit from.
 * It simply delegates all log-level-specific methods to the `log` method to reduce boilerplate code that a simple
 * Logger that does the same thing with messages regardless of the error level has to implement.
 *
 * @package     Ice/Log
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
abstract class Driver implements LoggerInterface
{
    /**
     * System is unusable.
     *
     * @param string message
     * @param array context
     * @return void
     */
    public function emergency(string message, array context = []) -> void
    {
        this->log(Log::EMERGENCY, message, context);
    }

    /**
     * Action must be taken immediately.
     *
     * Example: Entire website down, database unavailable, etc. This should trigger the SMS alerts and wake you up.
     *
     * @param string message
     * @param array context
     * @return void
     */
    public function alert(string message, array context = []) -> void
    {
        this->log(Log::ALERT, message, context);
    }

    /**
     * Critical conditions.
     *
     * Example: Application component unavailable, unexpected exception.
     *
     * @param string message
     * @param array context
     * @return void
     */
    public function critical(string message, array context = []) -> void
    {
        this->log(Log::CRITICAL, message, context);
    }

    /**
     * Runtime errors that do not require immediate action but should typically be logged and monitored.
     *
     * @param string message
     * @param array context
     * @return void
     */
    public function error(string message, array context = []) -> void
    {
        this->log(Log::ERROR, message, context);
    }

    /**
     * Exceptional occurrences that are not errors.
     *
     * Example: Use of deprecated APIs, poor use of an API, undesirable things that are not necessarily wrong.
     *
     * @param string message
     * @param array context
     * @return void
     */
    public function warning(string message, array context = []) -> void
    {
        this->log(Log::WARNING, message, context);
    }

    /**
     * Normal but significant events.
     *
     * @param string message
     * @param array context
     * @return void
     */
    public function notice(string message, array context = []) -> void
    {
        this->log(Log::NOTICE, message, context);
    }

    /**
     * Interesting events.
     *
     * Example: User logs in, SQL logs.
     *
     * @param string message
     * @param array context
     * @return void
     */
    public function info(string message, array context = []) -> void
    {
        this->log(Log::INFO, message, context);
    }

    /**
     * Detailed debug information.
     *
     * @param string message
     * @param array context
     * @return void
     */
    public function debug(string message, array context = []) -> void
    {
        this->log(Log::DEBUG, message, context);
    }

    /**
     * Logs with an arbitrary level.
     *
     * @param mixed level
     * @param string message
     * @param array context
     * @return void
     */
    public abstract function log(var level, string message, array context = []) -> void;
}
