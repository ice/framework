
namespace Ice\Log\Driver;

use Ice\Log\Driver;
use Ice\Exception;

/**
 * File driver for the Logger.
 *
 * @package     Ice/Log
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class File extends Driver
{

    protected file;

    /**
     * Logger file constructor.
     *
     * @param string file Filename to log messages to (complete path)
     * @throws Exception When logfile cannot be created or is not writeable
     */
    public function __construct(string file)
    {
        if !file_exists(file) {
            if !touch(file) {
                throw new Exception("Log file " . file . " cannot be created");
            }
        }
        if !is_writable(file) {
            throw new Exception("Log file " . file . " is not writeable");
        }
        
        let this->file = file;
    }

    /**
     * Logs with an arbitrary level.
     *
     * @param mixed level
     * @param string message
     * @param array context
     * @return void
     */
    public function log(var level, string message, array context = []) -> void
    {
        var line;

        let line = "[" . date("Y-m-d H:i:s") . "] " . strtoupper(level) . ": " . this->interpolate(message, context) . PHP_EOL;

        file_put_contents(this->file, line, FILE_APPEND);
    }

    /**
     * Interpolates context values into the message placeholders.
     *
     * @param string message
     * @param array context
     * @return string
     */
    protected function interpolate(string message, array context = []) -> string
    {
        var replace, key, value;

        // Build a replacement array with braces around the context keys
        let replace = [];

        for key, value in context {
            let replace["{" . key . "}"] = value;
        }

        // Interpolate replacement values into the message and return
        return strtr(message, replace);
    }
}
