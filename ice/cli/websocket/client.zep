
namespace Ice\Cli\Websocket;

use Ice\Exception;

/**
 * Websocket client.
 *
 * @package     Ice/Cli
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Client extends Websocket
{

    protected socket = null;
    protected message = null;
    protected tick = null;

    /**
     * Connect to server.
     *
     * @param string address Address to bind to, defaults to `ws://127.0.0.1:8080`
     * @param array headers Optional array of headers to pass when connecting
     * @return self
     */
    public function connect(string address = "ws://127.0.0.1:8080", var headers = []) -> <self>
    {
        var addr, key, name, value, res, data, matches;

        let addr = parse_url(address);

        if addr === false || !isset addr["host"] || !isset addr["port"] {
            throw new Exception("Invalid address");
        }

        let this->socket = fsockopen(
            (isset addr["scheme"] && in_array(addr["scheme"], ["ssl", "tls", "wss"]) ? "tls://" : "") . addr["host"],
            addr["port"]
        );

        if this->socket === false {
            throw new Exception("Could not connect");
        }

        let key = this->generateKey(),
            headers = array_merge(
                this->normalizeHeaders([
                    "Host": addr["host"] . ":" . addr["port"],
                    "Connection": "Upgrade",
                    "Upgrade": "websocket",
                    "Sec-Websocket-Key": key,
                    "Sec-Websocket-Version": "13"
                ]),
                this->normalizeHeaders(headers)
            );

        let key = headers["Sec-Websocket-Key"];

        for name, value in headers {
            let headers[name] = name . ": " . value;
        }

        if !empty addr["path"] {
            let res = addr["path"] . (empty addr["query"] ? "" : "?" . addr["query"]);
        } else {
            let res = "/";
        }

        array_unshift(headers, "GET " . res . " HTTP/1.1");
        this->sendClear(this->socket, implode("\r\n", headers)."\r\n");

        let data = this->receiveClear(this->socket);

        if !preg_match("(Sec-Websocket-Accept:\s*(.*)$)mUi", data, matches) {
            throw new Exception("Bad response");
        }

        if trim(matches[1]) !== base64_encode(pack("H*", sha1(key . self::magic))) {
            throw new Exception(sprintf("Bad key `%s` `%s`", trim(matches[1]), base64_encode(pack("H*", sha1(key . self::magic)))));
        }

        return this;
    }

    /**
     * Generate key.
     *
     * @return string
     */
    protected function generateKey() -> string
    {
        var chars, key, length;
        int i = 0;

        let chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"$&/()=[]{}0123456789",
            key = "",
            length = strlen(chars) - 1;

        while i < 16 {
            let key .= chars[mt_rand(0, length)],
                i++;
        }

        return base64_encode(key);
    }

    /**
     * Normalize header.
     *
     * @param array headers headers to normalize
     * @return array
     */
    protected function normalizeHeaders(array headers) -> array
    {
        var cleaned, name, value;

        let cleaned = [];

        for name, value in headers {
            if strncmp(name, "HTTP_", 5) === 0 {
                let name = substr(name, 5);
            }

            if name !== false {
                let name = ucwords(str_replace(
                     ["_", "-", " "],
                     [" ", " ", "-"],
                     strtolower(name)
                 ),  "-"),
                    cleaned[name] = value;
            }
        }

        return cleaned;
    }

    /**
     * Send a message to the server.
     *
     * @param string data The data to send
     * @param string opcode The data opcode, defaults to `text`
     * @return boolean Was the send successful
     */
    public function send(string data, string opcode = "text") -> boolean
    {
        return parent::sendData(this->socket, data, opcode, true);
    }

    /**
     * Start listening.
     *
     * @return void
     */
    public function run() -> void
    {
        var changed, write, except, socket, message;

        while 1 {
            if isset this->tick {
                if call_user_func(this->tick, this) === false {
                    break;
                }
            }

            let changed = [this->socket],
                write = [],
                except = [];

            if stream_select(changed, null, null, (isset this->tick ? 0 : null)) > 0 {
                for socket in changed {
                    let message = this->receive(socket);

                    if message !== false && isset this->message {
                        call_user_func(this->message, message, this);
                    }
                }
            }
            usleep(this->getParam("sleep", 5000));
        }
    }

    /**
     * Set a callback to execute when a message arrives.
     * The callable will receive the message string and the server instance.
     *
     * @param callable callback The callback
     * @return self
     */
    public function onMessage(callable callback) -> <self>
    {
        let this->message = callback;

        return this;
    }

    /**
     * Set a callback to execute every few milliseconds.
     * The callable will receive the server instance. If it returns boolean `false` the client will stop listening.
     *
     * @param callable callback The callback
     * @return self
     */
    public function onTick(callable callback) -> <self>
    {
        let this->tick = callback;

        return this;
    }
}
