
namespace Ice\Http;

use Ice\Di;
use Ice\Exception;
use Ice\Http\Response\Headers;
use Ice\Http\Request\RequestInterface;
use Ice\Http\Response\ResponseInterface;

/**
 * Response
 *
 * This class provides a simple interface around the HTTP response
 */
class Response implements ResponseInterface
{

    protected _di;
    protected _protocolVersion = "HTTP/1.1" { get, set };
    protected _status = 200 { get, set };
    protected _headers;
    protected _body { get, set };
    protected _messages = [
        //Informational 1xx
        100: "Continue",
        101: "Switching Protocols",
        102: "Processing",
        //Successful 2xx
        200: "OK",
        201: "Created",
        202: "Accepted",
        203: "Non-Authoritative Information",
        204: "No Content",
        205: "Reset Content",
        206: "Partial Content",
        207: "Multi-Status",
        208: "Already Reported",
        226: "IM Used",
        //Redirection 3xx
        300: "Multiple Choices",
        301: "Moved Permanently",
        302: "Found",
        303: "See Other",
        304: "Not Modified",
        305: "Use Proxy",
        306: "(Unused)",
        307: "Temporary Redirect",
        308: "Permanent Redirect",
        310: "Too Many Redirects",
        //Client Error 4xx
        400: "Bad Request",
        401: "Unauthorized",
        402: "Payment Required",
        403: "Forbidden",
        404: "Not Found",
        405: "Method Not Allowed",
        406: "Not Acceptable",
        407: "Proxy Authentication Required",
        408: "Request Timeout",
        409: "Conflict",
        410: "Gone",
        411: "Length Required",
        412: "Precondition Failed",
        413: "Request Entity Too Large",
        414: "Request-URI Too Long",
        415: "Unsupported Media Type",
        416: "Requested Range Not Satisfiable",
        417: "Expectation Failed",
        418: "I\"m a teapot",
        422: "Unprocessable Entity",
        423: "Locked",
        424: "Failed Dependency",
        426: "Upgrade Required",
        428: "Precondition Required",
        429: "Too Many Requests",
        431: "Request Header Fields Too Large",
        //Server Error 5xx
        500: "Internal Server Error",
        501: "Not Implemented",
        502: "Bad Gateway",
        503: "Service Unavailable",
        504: "Gateway Timeout",
        505: "HTTP Version Not Supported",
        506: "Variant Also Negotiates",
        507: "Insufficient Storage",
        508: "Loop Detected",
        510: "Not Extended",
        511: "Network Authentication Required"
    ] { get };

    /**
     * Constructor
     *
     * @param string $body The HTTP response body
     * @param int $status The HTTP response status
     */
    public function __construct(string body = "", int status = 200)
    {
        let this->_di = Di::$fetch();

        let this->_headers = new Headers(),
            this->_status = status,
            this->_body = body;

        this->_headers->set("Content-Type", "text/html");
    }

    /**
     * Get HTTP headers
     *
     * @return array
     */
    public function getHeaders()
    {
        return this->_headers->all();
    }

    /**
     * Does this request have a given header?
     *
     * @param  string $name
     * @return bool
     */
    public function hasHeader(string name)
    {
        return this->_headers->has(name);
    }

    /**
     * Get header value
     *
     * @param  string $name
     * @return string
     */
    public function getHeader(string name)
    {
        return this->_headers->get(name);
    }

    /**
     * Set header value
     *
     * @param string $name
     * @param string $value
     */
    public function setHeader(string name, string value)
    {
        this->_headers->set(name, value);
    }

    /**
     * Set multiple header values
     *
     * @param array $headers
     */
    public function setHeaders(array headers)
    {
        this->_headers->replace(headers);
    }

    /**
     * Remove header
     *
     * @param string $name
     */
    public function removeHeader(string name)
    {
        this->_headers->remove(name);
    }

    /**
     * Finalize response for delivery to client
     *
     * Apply final preparations to the resposne object
     * so that it is suitable for delivery to the client.
     *
     * @param RequestInterface $request
     * @return Response Self
     */
    public function finalize(<RequestInterface> request)
    {
        var sendBody;

        let sendBody = true;

        if in_array(this->_status, [204, 304]) {
            this->_headers->remove("Content-Type");
            this->_headers->remove("Content-Length");
            let sendBody = false;
        }

        // Remove body if HEAD request
        if request->isHead() {
            let sendBody = false;
        }

        // Truncate body if it should not be sent with response
        if !sendBody {
            let this->_body = "";
        }

        return this;
    }

    /**
     * Send HTTP response headers
     *
     * @return Response Self
     */
    public function send()
    {
        if !headers_sent() {
            if strpos(PHP_SAPI, "cgi") === 0 {
                header(sprintf("Status: %d %s", this->_status, this->_messages[this->_status]));
            } else {
                header(sprintf("%s %d %s", this->getProtocolVersion(), this->_status, this->_messages[this->_status]));
            }

            this->_headers->send();
        }

        return this;
    }

    /**
     * Redirect
     *
     * This method prepares the response object to return an HTTP Redirect response
     * to the client.
     *
     * @param string $location The redirect destination
     * @param int    $status The redirect HTTP status code
     */
    public function redirect(string location = null, int status = 302, boolean external = false)
    {
        var url;

        this->setStatus(status);

        if !external {
            let url = this->_di->getUrl(),
                location = url->get(location);
        }
        this->_headers->set("Location", location);
    }

    /**
     * Helpers: Empty?
     *
     * @return bool
     */
    public function isEmpty()
    {
        return in_array(this->_status, [201, 204, 304]);
    }

    /**
     * Helpers: Informational?
     *
     * @return bool
     */
    public function isInformational()
    {
        return this->_status >= 100 && this->_status < 200;
    }

    /**
     * Helpers: OK?
     *
     * @return bool
     */
    public function isOk()
    {
        return this->_status === 200;
    }

    /**
     * Helpers: Successful?
     *
     * @return bool
     */
    public function isSuccessful()
    {
        return this->_status >= 200 && this->_status < 300;
    }

    /**
     * Helpers: Redirect?
     *
     * @return bool
     */
    public function isRedirect()
    {
        return in_array(this->_status, [301, 302, 303, 307]);
    }

    /**
     * Helpers: Redirection?
     *
     * @return bool
     */
    public function isRedirection()
    {
        return this->_status >= 300 && this->_status < 400;
    }

    /**
     * Helpers: Forbidden?
     *
     * @return bool
     */
    public function isForbidden()
    {
        return this->_status === 403;
    }

    /**
     * Helpers: Not Found?
     *
     * @return bool
     */
    public function isNotFound()
    {
        return this->_status === 404;
    }

    /**
     * Helpers: Client error?
     *
     * @return bool
     */
    public function isClientError()
    {
        return this->_status >= 400 && this->_status < 500;
    }

    /**
     * Helpers: Server Error?
     *
     * @return bool
     */
    public function isServerError()
    {
        return this->_status >= 500 && this->_status < 600;
    }

    /**
     * Response codes and associated messages
     *
     * @param int code Status code
     * @return string
     */
    public function getMessage(int code = 200) -> string
    {
        var message;

        fetch message, this->_messages[code];

        return (string) message;
    }

    /**
     * Convert response to string
     *
     * @return string
     */
    public function __toString()
    {
        return this->_body;
    }
}