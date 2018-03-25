
namespace Ice\Log;

/**
 * Describes a logger instance
 *
 * The message MUST be a string or object implementing __toString().
 *
 * The message MAY contain placeholders in the form: {foo} where foo
 * will be replaced by the context data in key "foo".
 *
 * The context array can contain arbitrary data, the only assumption that
 * can be made by implementors is that if an Exception instance is given
 * to produce a stack trace, it MUST be in a key named "exception".
 *
 * See https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-3-logger-interface.md
 * for the full interface specification.
 *
 * @package     Ice/Log
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
interface LoggerInterface
{

    public function emergency(string message, array context = []);

    public function alert(string message, array context = []);

    public function critical(string message, array context = []);

    public function error(string message, array context = []);

    public function warning(string message, array context = []);

    public function notice(string message, array context = []);

    public function info(string message, array context = []);

    public function debug(string message, array context = []);

    public function log(var level, string message, array context = []);
}
