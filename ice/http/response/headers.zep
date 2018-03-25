
namespace Ice\Http\Response;

use Ice\Arr;
use Ice\Http\Response\HeadersInterface;

/**
 * This class is a bag to manage the response headers.
 *
 * @package     Ice/Http
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Headers extends Arr implements HeadersInterface
{

    /**
     * Sends the headers to the client.
     *
     * @return boolean
     */
    public function send() -> boolean
    {
        var header, value;

        if !headers_sent() {
            for header, value in iterator(this) {
                if !empty value {
                    header(header . ": " . value, true);
                } else {
                    header(header, true);
                }
            }
            return true;
        }
        return false;
    }
}
