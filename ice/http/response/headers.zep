
namespace Ice\Http\Response;

use Ice\Arr;
use Ice\Http\Response\HeadersInterface;

/**
 * This class is a bag to manage the response headers
 */
class Headers extends Arr implements HeadersInterface
{

    /**
     * Sends the headers to the client
     *
     * @return boolean
     */
    public function send()
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