
namespace Ice\Cli\Websocket;

use Ice\Exception;

/**
 * Websocket server.
 *
 * @package     Ice/Cli
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Server extends Websocket
{

    protected verbose = false { set };
    protected address;
    protected server { get };
    protected sockets = [];
    protected clients = [] { get };
    protected callbacks = [];

    /**
     * Create an instance.
     *
     * @param string address Where to create the server, defaults to "ws://127.0.0.1:8080"
     * @param array options Stream context options
     */
    public function __construct(string address = "ws://127.0.0.1:8080", array options = [])
    {
        var addr, context, key, value;

        let addr = parse_url(address);

        if addr === false || !isset addr["scheme"] || !isset addr["host"] || !isset addr["port"] {
            throw new Exception("Invalid address");
        }

        let context = stream_context_create();

        if count(options) {
            for key, value in options {
                stream_context_set_option(context, "ssl", key, value);
            }
        }

        let this->address = address;

        let this->server = stream_socket_server(
            (in_array(addr["scheme"], ["wss", "tls"]) ? "tls" : "tcp") . "://" . addr["host"] . ":" . addr["port"],
            null,
            null,
            STREAM_SERVER_BIND | STREAM_SERVER_LISTEN,
            context
        );

        if this->server === false {
            throw new Exception("Could not create server");
        }
    }

    /**
     * Start processing requests. This method runs in an infinite loop.
     *
     * @return void
     */
    public function run() -> void
    {
        var changed, write, except, stream, messages, message, socket, tmp;

        let this->sockets[] = this->server;

        if isset this->callbacks["boot"] {
            call_user_func(this->callbacks["boot"], this);
        }

        while 1 {
            if isset this->callbacks["tick"] {
                if call_user_func(this->callbacks["tick"], this) === false {
                    break;
                }
            }

            let changed = this->sockets,
                write = [],
                except = [],
                stream = stream_select(changed, write, except, (isset this->callbacks["tick"] ? 0 : null));

            if stream > 0 {
                let messages = [];

                for socket in changed {
                    if socket === this->server {
                        let tmp = stream_socket_accept(this->server);

                        if tmp !== false {
                            if this->connect(tmp) {
                                if isset this->callbacks["connect"] {
                                    call_user_func(this->callbacks["connect"], this->clients[(int) tmp], this);
                                }
                            }
                        }
                    } else {
                        let message = this->receive(socket);

                        if message === false || in_array(message, ["quit", "exit", "close"]) {
                            if isset this->callbacks["disconnect"] {
                                call_user_func(this->callbacks["disconnect"], this->clients[(int) socket], this);
                            }

                            this->disconnect(socket);
                        } else {
                            let messages[] = [
                                "client": this->clients[(int) socket],
                                "message": message
                            ];
                        }
                    }
                }

                for message in messages {
                    if isset this->callbacks["message"] {
                        call_user_func(this->callbacks["message"], message["client"], message["message"], this);
                    }
                }
            }

            usleep(this->getParam("sleep", 5000));
        }
    }

    /**
     * Connect a socket to the server.
     *
     * @param resource socket The resource
     * @return boolean
     */
    protected function connect(resource socket) -> boolean
    {
        var headers, header, request, tmp, cookies, value, client, response;

        let headers = this->receiveClear(socket);

        if !headers {
            return false;
        }

        let headers = str_replace(["\r\n", "\n"], ["\n", "\r\n"], headers),
            headers = array_filter(explode("\r\n", preg_replace("(\r\n\s+)", " ", headers))),
            request = explode(" ", array_shift(headers));

        if strtoupper(request[0]) !== "GET" {
            this->sendClear(socket, "HTTP/1.1 405 Method Not Allowed\r\n\r\n");

            return false;
        }

        let tmp = [];

        for header in headers {
            let header = explode(":", header, 2),
                tmp[trim(strtolower(header[0]))] = trim(header[1]);
        }

        let headers = tmp;

        if !isset headers["sec-websocket-key"] || !isset headers["upgrade"] || !isset headers["connection"] ||
            strtolower(headers["upgrade"]) != "websocket" || strpos(strtolower(headers["connection"]), "upgrade") === false {
            this->sendClear(socket, "HTTP/1.1 400 Bad Request\r\n\r\n");

            return false;
        }

        let cookies = [];

        if isset headers["cookie"] {
            let tmp = explode(";", headers["cookie"]);

            for value in tmp {
                if trim(value) !== "" && strpos(value, "=") !== false {
                    let value = explode("=", value, 2),
                        cookies[trim(value[0])] = value[1];
                }
            }
        }

        let client = [
            "socket": socket,
            "headers": headers,
            "resource": request[1],
            "cookies": cookies
        ];

        if isset this->callbacks["validate"] && !call_user_func(this->callbacks["validate"], client, this) {
            this->sendClear(socket, "HTTP/1.1 400 Bad Request\r\n\r\n");

            return false;
        }

        let response = [
            "HTTP/1.1 101 WebSocket Protocol Handshake",
            "Upgrade: WebSocket",
            "Connection: Upgrade",
            "Sec-WebSocket-Version: 13",
            "Sec-WebSocket-Location: " . this->address,
            "Sec-WebSocket-Accept: " . base64_encode(sha1(headers["sec-websocket-key"] . self::magic, true))
        ];

        if isset headers["origin"] {
            let response[] = "Sec-WebSocket-Origin: " . headers["origin"];
        }

        let this->sockets[(int) socket] = socket,
            this->clients[(int) socket] = client;

        return this->sendClear(socket, implode("\r\n", response) . "\r\n\r\n");
    }

    /**
     * Disconnect a socket from the server.
     *
     * @param resource socket The resource
     * @return void
     */
    public function disconnect(resource socket) -> void
    {
        unset this->clients[(int) socket];
        unset this->sockets[(int) socket];
    }

    /**
     * Set a callback to be executed when a client connects, returning `false` will prevent the client from connecting.
     * The callable will receive:
     *  - an associative array with client data
     *  - the current server instance
     * The callable should return `true` if the client should be allowed to connect or `false` otherwise.
     *
     * @param callable callback The callback
     * @return self
     */
    public function onValidate(callable callback) -> <self>
    {
        return this->callback("validate", callback);
    }

    /**
     * Set a callback to be executed when a client is connected.
     * The callable will receive:
     *  - an associative array with client data
     *  - the current server instance
     *
     * @param callable callback The callback
     * @return self
     */
    public function onConnect(callable callback) -> <self>
    {
        return this->callback("connect", callback);
    }

    /**
     * Set a callback to execute when a client disconnects.
     * The callable will receive:
     *  - an associative array with client data
     *  - the current server instance
     *
     * @param callable callback The callback
     * @return self
     */
    public function onDisconnect(callable callback) -> <self>
    {
        return this->callback("disconnect", callback);
    }

    /**
     * Set a callback to execute when a client sends a message.
     * The callable will receive:
     *  - an associative array with client data
     *  - the message string
     *  - the current server instance
     *
     * @param callable callback The callback
     * @return self
     */
    public function onMessage(callable callback) -> <self>
    {
        return this->callback("message", callback);
    }

    /**
     * Set a callback to execute every few milliseconds.
     * The callable will receive the server instance. If it returns boolean `false` the server will stop listening.
     *
     * @param callable callback The callback
     * @return self
     */
    public function onTick(callable callback) -> <self>
    {
        return this->callback("tick", callback);
    }

    /**
     * Set a callback to execute on boot the server.
     * The callable will receive the server instance.
     *
     * @param callable callback The callback
     * @return self
     */
    public function onBoot(callable callback) -> <self>
    {
        return this->callback("boot", callback);
    }

    /**
     * Register a callback to execute.
     *
     * @param string key A callback key
     * @param callable callback The callback
     * @return self
     */
    public function callback(string key, callable callback) -> <self>
    {
        let this->callbacks[key] = callback;

        return this;
    }
}
