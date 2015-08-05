
namespace Ice\Http;

use Ice\Di;
use Ice\Exception;
use Ice\Http\Response\Headers;
use Ice\Http\Request\RequestInterface;
use Ice\Http\Response\ResponseInterface;

/**
 * This class provides a simple interface around the HTTP response.
 *
 * @package     Ice/Http
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
class Response implements ResponseInterface
{

    protected di;
    protected protocolVersion = "HTTP/1.1" { get, set };
    protected status = 200 { get, set };
    protected headers;
    protected body { get, set };
    protected messages = [
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
     * Response constructor. Fetch Di and set it as a property.
     *
     * @param string body The HTTP response body
     * @param int status The HTTP response status
     */
    public function __construct(string body = "", int status = 200)
    {
        let this->di = Di::$fetch();

        let this->headers = new Headers(),
            this->status = status,
            this->body = body;

        this->headers->set("Content-Type", "text/html");
    }

    /**
     * Get HTTP headers.
     *
     * @return array
     */
    public function getHeaders() -> array
    {
        return this->headers->all();
    }

    /**
     * Check whether request have a given header.
     *
     * @param string name
     * @return boolean
     */
    public function hasHeader(string name) -> boolean
    {
        return this->headers->has(name);
    }

    /**
     * Get header value.
     *
     * @param string name
     * @return string
     */
    public function getHeader(string name) -> string
    {
        return this->headers->get(name);
    }

    /**
     * Set header value.
     *
     * @param string name
     * @param string value
     */
    public function setHeader(string name, string value) -> void
    {
        this->headers->set(name, value);
    }

    /**
     * Set multiple header values.
     *
     * @param array headers
     */
    public function setHeaders(array headers) -> void
    {
        this->headers->replace(headers);
    }

    /**
     * Remove header by index name.
     *
     * @param string name
     */
    public function removeHeader(string name) -> void
    {
        this->headers->remove(name);
    }

    /**
     * Set body content.
     *
     * @param string content
     * @return object Response
     */
    public function setContent(string contet) -> object
    {
        let this->body = contet;

        return this;
    }

    /**
     * Finalize response for delivery to client.
     * Apply final preparations to the resposne object so that it is suitable for delivery to the client.
     *
     * @param RequestInterface request
     * @return Response
     */
    public function finalize(<RequestInterface> request)
    {
        var sendBody;

        let sendBody = true;

        if in_array(this->status, [204, 304]) {
            this->headers->remove("Content-Type");
            this->headers->remove("Content-Length");
            let sendBody = false;
        }

        // Remove body if HEAD request
        if request->isHead() {
            let sendBody = false;
        }

        // Truncate body if it should not be sent with response
        if !sendBody {
            let this->body = "";
        }

        return this;
    }

    /**
     * Send HTTP response headers.
     *
     * @return Response
     */
    public function send()
    {
        if !headers_sent() {
            if strpos(PHP_SAPI, "cgi") === 0 {
                header(sprintf("Status: %d %s", this->status, this->messages[this->status]));
            } else {
                header(sprintf("%s %d %s", this->getProtocolVersion(), this->status, this->messages[this->status]));
            }

            this->headers->send();
        }

        return this;
    }

    /**
     * Redirect to some location.
     * This method prepares the response object to return an HTTP Redirect response to the client.
     *
     * @param string location The redirect destination
     * @param int status The redirect HTTP status code
     * @return object this
     */
    public function redirect(string location = null, int status = 302, boolean external = false)
    {
        var url;

        this->setStatus(status);

        if !external {
            let url = this->di->get("url", null, true),
                location = url->get(location);
        }
        this->headers->set("Location", location);

        return this;
    }

    /**
     * Check whether status is for Empty.
     *
     * @return boolean
     */
    public function isEmpty() -> boolean
    {
        return in_array(this->status, [201, 204, 304]);
    }

    /**
     * Check whether status is for Informational.
     *
     * @return boolean
     */
    public function isInformational() -> boolean
    {
        return this->status >= 100 && this->status < 200;
    }

    /**
     * Check whether status is for OK.
     *
     * @return boolean
     */
    public function isOk() -> boolean
    {
        return this->status === 200;
    }

    /**
     * Check whether status is for Successful.
     *
     * @return boolean
     */
    public function isSuccessful() -> boolean
    {
        return this->status >= 200 && this->status < 300;
    }

    /**
     * Check whether status is for Redirect.
     *
     * @return boolean
     */
    public function isRedirect() -> boolean
    {
        return in_array(this->status, [301, 302, 303, 307]);
    }

    /**
     * Check whether status is for Redirection.
     *
     * @return boolean
     */
    public function isRedirection() -> boolean
    {
        return this->status >= 300 && this->status < 400;
    }

    /**
     * Check whether status is for Forbidden.
     *
     * @return boolean
     */
    public function isForbidden() -> boolean
    {
        return this->status === 403;
    }

    /**
     * Check whether status is for Not Found.
     *
     * @return boolean
     */
    public function isNotFound() -> boolean
    {
        return this->status === 404;
    }

    /**
     * Check whether status is for Client error.
     *
     * @return boolean
     */
    public function isClientError() -> boolean
    {
        return this->status >= 400 && this->status < 500;
    }

    /**
     * Check whether status is for Server Error.
     *
     * @return boolean
     */
    public function isServerError() -> boolean
    {
        return this->status >= 500 && this->status < 600;
    }

    /**
     * Get message for Response codes.
     *
     * @param int code Status code
     * @return string
     */
    public function getMessage(int code = 200) -> string
    {
        var message;

        fetch message, this->messages[code];

        return message ? message : "";
    }

    /**
     * Magic toString, convert response to string.
     *
     * @return string
     */
    public function __toString() -> string
    {
        return this->body;
    }
}
