
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Response implements ResponseInterface
{

    protected protocolVersion = "HTTP/1.1" { get, set };
    protected status = 200 { get, set };
    protected headers;
    protected loops = 16 { get, set };
    protected redirects = 0 { get };
    protected body { get, set };

    /**
     * Response constructor. Fetch Di and set it as a property.
     *
     * @param string|null body The HTTP response body
     * @param int status The HTTP response status
     */
    public function __construct(var body = null, int status = 200)
    {
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
     * @return object Response
     */
    public function setHeader(string name, string value)
    {
        this->headers->set(name, value);
        
        return this;
    }

    /**
     * Set multiple header values.
     *
     * @param array headers
     * @return object Response
     */
    public function setHeaders(array headers)
    {
        this->headers->replace(headers);
        
        return this;
    }

    /**
     * Remove header by index name.
     *
     * @param string name
     * @return object Response     
     */
    public function removeHeader(string name)
    {
        this->headers->remove(name);
        
        return this;
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
     * @return object Response
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
     * @return object Response
     */
    public function send()
    {
        if !headers_sent() {
            if strpos(PHP_SAPI, "cgi") === 0 {
                header(sprintf("Status: %d %s", this->status, this->getMessage(this->status)));
            } else {
                header(sprintf("%s %d %s", this->getProtocolVersion(), this->status, this->getMessage(this->status)));
            }

            var di = Di::$fetch();

            if di->has("session") && !this->isRedirect() {
                di->get("session")->remove("_redirects");
            }

            this->headers->send();
        }

        return this;
    }

    /**
     * Send file download as the response. All execution will be halted when
     * this method is called! The third parameter allows the following
     * options to be set:
     *
     * Type      | Option    | Description                        | Default Value
     * ----------|-----------|------------------------------------|--------------
     * string    | file      | file that already exists           | null
     * boolean   | inline    | Display inline instead of download | FALSE
     * boolean   | resumable | Allow to resumable download        | FALSE
     * boolean   | delete    | Delete the file after sending      | FALSE
     * int       | timeout   | Execute time for the script        | 0
     * int       | speed     | Download speed in millisecond      | 0
     *
     * Download a file that already exists:
     *
     *     $request->sendFile('ice.zip', 'application/zip', ['file' => '/download/latest.zip']);
     *
     * Download generated content as a file:
     *
     *     $response->setContent($content);
     *     $response->sendFile($filename, $mineType);
     *
     * Attention: No further processing can be done after this method is called!
     *
     * @param string filename The file name of the attachment
     * @param string mime Manual mime type
     * @param array options The keys can be [file|inline|resumable|delete|timeout|speed]
     * @return  void
     */
    public function sendFile(string filename, string mime, array options = [])
    {
        var file, filepath, data, size, isDelete, disposition, block, pos, speed, range, start, end;

        if empty options["file"] {
            // Force the data to be rendered if
            let data = (string) this->body;

            // Get the content size
            let size = strlen(data);

            // Create a temporary file to hold the current response
            let file = tmpfile();

            // Write the current response into the file
            fwrite(file, data);

            let isDelete = false;
        } else {
            // Get the complete file path
            let filepath = realpath(options["file"]);

            // Get the file size
            let size = filesize(filepath);

            // Open the file for reading
            let file = fopen(filepath, "rb");

            fetch isDelete, options["delete"];
        }

        if !is_resource(file) {
            throw new Exception(["Could not read file to send: %s",  filename]);
        }

        if empty options["inline"] {
            let disposition = "attachment";
        } else {
            let disposition = "inline";
        }

        if empty options["resumable"] {
            this->headers->set("Content-Length", size);
        } else {
            // Calculate byte range to download.
            let range = this->getByteRange(size),
                start = range[0],
                end = range[1];

            // HTTP/1.1 416 Requested Range Not Satisfiable
            if this->status == 416 {                
                header(sprintf("%s %d %s", this->getProtocolVersion(), this->status, this->getMessage(this->status)));
                exit();
            }

            // Partial Content
            if start > 0 || end < size - 1 {
                let this->status = 206;
            }

            // Range of bytes being sent
            this->headers->set("Accept-Ranges", "bytes");
            this->headers->set("Content-Range", "bytes ".start."-".end."/".size);
            this->headers->set("Content-Length", end - start + 1);
        }

        // Set the headers for a download
        this->headers->set("Content-Disposition", disposition."; filename=\"".filename."\"");
        this->headers->set("Content-Type", mime);

        // Send all headers now
        this->headers->send();

        while ob_get_level() {
            // Flush all output buffers
            ob_end_flush();
        }

        // Manually stop execution
        ignore_user_abort(true);

        if empty options["timeout"] {
            // Keep the script running forever
            set_time_limit(0);
        } else {
            set_time_limit((int)options["timeout"]);
        }

        // Send data in 16kb blocks
        let block = 1024 * 16;

        if !empty options["sleep"] {
            let speed = ((int)options["sleep"]) * 1000;
        } else {
            let speed = 0;
        }

        fseek(file, start);

        while !feof(file)  {
            let pos = ftell(file);

            if pos > end || connection_aborted() {
                break;
            }

            if pos + block > end {
                // Don't read past the buffer.
                let block = end - pos + 1;
            }

            // Output a block of the file
            echo fread(file, block);

            // Send the data now
            flush();

            if speed > 0 {
                usleep(speed);
            }
        }

        // Close the file
        fclose(file);

        if isDelete {
            try {
                // Attempt to remove the file
                unlink(filepath);
            } catch \Exception {
                // TODO: Write log for this exception
                // Do NOT display the exception, it will corrupt the output!
            }
        }

        // Stop execution
        exit();
    }

    /**
     * Redirect to some location.
     * This method prepares the response object to return an HTTP Redirect response to the client.
     *
     * @param string location The redirect destination
     * @param int status The redirect HTTP status code
     * @return object Response
     */
    public function redirect(string location = null, int status = 302, boolean external = false)
    {
        var url, di = Di::$fetch();;
        int redirects;

        this->setStatus(status);

        if !external {
            let url = di->get("url"),
                location = url->get(location);
        }

        if di->has("session") && this->loops {
            var session = di->get("session");

            let redirects = (int) session->get("_redirects", 0) + 1,
                this->redirects = redirects;

            session->set("_redirects", redirects);

            if this->redirects > this->loops {
                return this;
            }
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

        fetch message, this->getMessages()[code];

        return message ? message : "";
    }

    /**
     * Get all messages.
     *
     * @return array
     */
    public function getMessages() -> array
    {
        return [
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
            418: "I'm a teapot",
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
        ];
    }

    /**
     * Response data to JSON string.
     *
     * @param mixed data Can be any type excepta resource
     * @param int option The options for json_encode
     * @return object Response
     */
    public function toJson(var data, var option = null)
    {
        this->headers->set("Content-Type", "application/json;charset=utf-8");

        let this->body = json_encode(data, option);

        return this;
    }

    /**
     * Response data to XML string.
     *
     * <pre><code>
     *     $response->toXml(
     *         [['title' => 'hello world', 'desc' => 'dont panic']],
     *         ['root' => 'blogs', 'namespace' => 'http://example.com/xml/blog']
     *     );
     *
     *     // This will output the xml
     *     <?xml version="1.0"?><blogs xmlns="http://example.com/xml/blog">
     *     <blog><title>hello world</title><desc>dont panic</desc></blog></blogs>
     * </code></pre>
     *
     * @param mixed data Can be any type excepta resource
     * @param array options The options can be [root|charset|namespace]
     * @return object Response
     */
    public function toXml(var data, var options = null)
    {
        var doc, ns, rootName, charset;

        let rootName = isset options["root"] ? options["root"] : "result",
            charset = isset options["charset"] ? options["charset"] : "utf-8",
            doc = this->xmlEncode(data, rootName),
            doc->preserveWhiteSpace = false,
            doc->formatOutput = true,
            doc->encoding = charset;

        if fetch ns, options["namespace"] {
            doc->createAttributeNS(ns, "xmlns");
        }

        this->headers->set("Content-Type", "application/xml;charset=" . charset);

        let this->body = doc->saveXML();

        return this;
    }

    /**
     * Convert data to XML string.
     *
     * @param mixed data Can be any type excepta resource
     * @param string root The root tag name
     * @param DOMElement domNode null, ONLY FOR INTERNAL USE
     * @return DOMDocument domDoc object
     */
    public function xmlEncode(var data, string root = "root", <\DOMElement> domNode = null)
    {
        var domDoc, type, key, val, node;

        if domNode === null {
            let domDoc = new \DOMDocument,
                domNode = domDoc->createElement(root);

            domDoc->appendChild(domNode);
            this->xmlEncode(data, null, domNode);

            return domDoc;
        }

        let domDoc = domNode->ownerDocument,
            type = typeof data;

        if type == "array" {
            for key, val in data {
                if typeof key == "integer" {
                    let node = domDoc->createElement(rtrim(domNode->tagName, "s"));
                    node->setAttribute("i", key);
                } else {
                    let node = domDoc->createElement(key);
                }
                domNode->appendChild(node);

                this->xmlEncode(val, null, node);
            }
        } elseif type == "object" {
            // set internal attr __is__ eq object
            domNode->setAttribute("__is__", "obj");

            for key, val in get_object_vars(data) {
                if typeof val == "array" || typeof val == "object" {
                    let node = domDoc->createElement(key);
                    domNode->appendChild(node);
                    this->xmlEncode(val, null, node);
                } else {
                    domNode->setAttribute(key, val);
                }
            }
        } else {
            if type == "boolean" {
                let data = data ? "true" : "false";
            }
            domNode->appendChild(domDoc->createTextNode(data));
        }
    }

    /**
     * Magic toString, convert response to string.
     *
     * @return string
     */
    public function __toString() -> string
    {
        return (string) this->body;
    }

    /**
     *
     * At the moment we only support single ranges.
     * Multiple ranges requires some more work to ensure it works correctly
     * and comply with the spesifications:
     *    http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.2
     *
     * Multirange support annouces itself with:
     * header('Accept-Ranges: bytes');
     *
     * Multirange content must be sent with multipart/byteranges mediatype,
     * as well as a boundry header to indicate the various chunks of data.
     *
     * @return array The bytes range start and end, error message if there is
     */
    protected function getByteRange(int size) -> array
    {
        var start, end, range;

        let start = 0,
            end = size - 1;

        // Defaults to start with when the HTTP_RANGE header doesn't exist.
        if isset _SERVER["HTTP_RANGE"] {
            let range = explode("=", _SERVER["HTTP_RANGE"], 2);

            if range[0] != "bytes" {
                let this->status = 416;
            } else {
                // multiple ranges could be specified at the same time,
                // but for simplicity only serve the first range ATM
                let range = explode(",", range[1], 2), range = range[0];

                // A negative value means we start from the end
                if range[0] == "-" {
                    let start = abs(size - abs((int)range));
                } else {
                    let range = explode("-", range), start = abs((int)range[0]);

                    if range[1] && is_numeric(range[1]) {
                        let end = (int)range[1];
                    }
                }

                if end > size {
                    let end = size - 1;
                }

                if start > end || start > size - 1 || end >= size {
                    let this->status = 416;
                }
            }
        }
        return [start, end];
    }
}
