
namespace Ice\Config;

use Ice\Config;
use Ice\Exception;

/**
 * Adapter for get config from json files.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Json extends Config
{

    /**
     * Config json constructor.
     *
     * @param string data Path to the json file
     */
    public function __construct(var data = null)
    {
        if typeof data != "string" {
            throw new Exception("The file path must be a string");
        }

        parent::__construct(json_decode(file_get_contents(data), true));
    }
}
