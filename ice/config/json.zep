
namespace Ice\Config;

use Ice\Config;
use Ice\Exception;

/**
 * Adapter for get config from json files.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Json extends Config
{

    /**
     * Config json constructor.
     *
     * @param string data Path to the file or json string
     */
    public function __construct(var data = null)
    {
        if typeof data != "string" {
            throw new Exception("Data must be a json string or path to the file");
        }

        if file_exists(data) {
            let data = file_get_contents(data);
        }

        parent::__construct(json_decode(data, true));
    }
}
