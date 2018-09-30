
namespace Ice\Cli\Websocket;

use Ice\Cli\Console;

/**
 * A base class used in the server class.
 * It handles all encoding / decoding / masking / socket operations.
 *
 * @package     Ice/Cli
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Websocket
{

    protected static opcodes = [
        "continuation": 0,
        "text": 1,
        "binary": 2,
        "close": 8,
        "ping": 9,
        "pong": 10
    ];

    protected static fragmentSize = 4096;
    protected static magic = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
    protected params;

    /**
     * Send data to a socket in clear form (basically fwrite).
     *
     * @param resource socket The socket to write to
     * @param string data The data to send
     * @return boolean Was the send successful
     */
    public function sendClear(resource socket, string data) -> boolean
    {
        return fwrite(socket, data) > 0;
    }

    /**
     * Send data to a socket.
     *
     * @param resource socket The socket to send to
     * @param string data The data to send
     * @param string opcode One of the opcodes (defaults to "text")
     * @param boolean masked Should the data be masked (per specs the server should not mask, defaults to false)
     * @return boolean Was the send successful
     */
    public function sendData(resource socket, string data, string opcode = "text", boolean masked = false) -> boolean
    {
        var tmp;

        while strlen(data) {
            let tmp = substr(data, 0, self::fragmentSize),
                data = strlen(data) < self::fragmentSize ? "" : substr(data, self::fragmentSize),
                tmp = this->encode(tmp, opcode, masked, strlen(data) === 0);

            if is_resource(socket) && get_resource_type(socket) == "stream" && !feof(socket) {
                if fwrite(socket, tmp) === false || stream_get_meta_data(socket)["timed_out"] {
                    return false;
                }
            } else {
                return false;
            }

            let opcode = "continuation";
        }

        return true;
    }

    /**
     * Read clear data from a socket (basically a fread).
     *
     * @param resource socket The socket to read from
     * @return string The data that was read
     */
    public function receiveClear(resource socket) -> string
    {
        var data, read, buff, meta;

        let data = "",
            read = self::fragmentSize;

        do {
            let buff = fread(socket, read);

            if buff === false {
                return "";
            }

            let data .= buff,
                meta = stream_get_meta_data(socket),
                read = min((int) meta["unread_bytes"], self::fragmentSize);

            usleep(1000);
        } while !feof(socket) && (int) meta["unread_bytes"] > 0;

        if strlen(data) === 1 {
            let data .= this->receiveClear(socket);
        }

        return data;
    }

    /**
     * Read data from a socket (in websocket format).
     *
     * @param resource socket The socket to read from
     * @return string The read data (decoded)
     */
    public function receive(resource socket) -> string | boolean
    {
        var data, fin, opcode, masked, payload, length, tmp, mask, buff;
        int i;

        let data = fread(socket, 2);

        if strlen(data) === 1 {
            let data .= fread(socket, 1);
        }

        if data === false || strlen(data) < 2 {
            return false;
        }

        let fin = (bool) (ord(data[0]) & 1 << 7),
            // rsv1 = (bool) (ord(data[0]) & 1 << 6),
            // rsv2 = (bool) (ord(data[0]) & 1 << 5),
            // rsv3 = (bool) (ord(data[0]) & 1 << 4),
            opcode = ord(data[0]) & 31,
            masked = (bool) (ord(data[1]) >> 7),
            payload = "",
            length = (int) (ord(data[1]) & 127); // Bits 1-7 in byte 1

        if length > 125 {
            let tmp = length === 126 ? fread(socket, 2) : fread(socket, 8);

            if tmp === false {
                return false;
            }

            let length = "",
                i = 0;

            while i < strlen(tmp) {
                let length .= sprintf("%08b", ord(tmp[i])),
                    i++;
            }

            let length = bindec(length);
        }

        let mask = "";

        if masked {
            let mask = fread(socket, 4);

            if mask === false {
                return false;
            }
        }

        if length > 0 {
            let tmp = "";

            do {
                let buff = fread(socket, min(length, self::fragmentSize));

                if buff === false {
                    return false;
                }

                let tmp .= buff;
            } while strlen(tmp) < length;

            if masked {
                let i =0;

                while i < length {
                    let payload .= tmp[i] ^ mask[(int) (i % 4)],
                        i++;
                }
            } else {
                let payload = tmp;
            }
        }

        if opcode === self::opcodes["close"] {
            return false;
        }

        return fin ? payload : payload . this->receive(socket);
    }

    /**
     * Encode the data.
     *
     * @param string data The data to send
     * @param string opcode One of the opcodes (defaults to "text")
     * @param boolean masked Should the data be masked
     * @param boolean fin Add 1 to the head
     * @return string
     */
    protected function encode(string data, string opcode = "text", boolean masked = true, boolean fin = true) -> string
    {
        var length, head, frame, binstr, mask;
        int i;

        let length = strlen(data),
            head = "",
            head .= fin ? "1" : "0",
            head .= "0" . "0" . "0",
            head .= sprintf("%04b", self::opcodes[opcode]),
            head .= masked ? "1" : "0";

        if length > 65535 {
            let head .= decbin(127),
                head .= sprintf("%064b", length);
        } elseif length > 125 {
            let head .= decbin(126),
                head .= sprintf("%016b", length);
        } else {
            let head .= sprintf("%07b", length);
        }

        let frame = "";

        for binstr in str_split(head, 8) {
            let frame .= chr((int) bindec(binstr));
        }

        let mask = "";

        if masked {
            let i = 0;

            while i < 4 {
                let mask .= chr(rand(0, 255)),
                    i++;
            }

            let frame .= mask;
        }

        let i = 0;

        while i < length {
            let frame .= (masked === true) ? data[i] ^ mask[(int) (i % 4)] : data[i],
                i++;
        }

        return frame;
    }

    /**
     * Set server params.
     *
     * @param array params
     * @return self
     */
    public function setParams(array params) -> <self>
    {
        let this->params = params;

        return this;
    }

    /**
     * Get server params.
     *
     * @return array
     */
    public function getParams() -> array
    {
        return this->params;
    }

    /**
     * Retrieve a single param.
     *
     * @param string key The data key
     * @param mixed defaultValue The value to return if data key does not exist
     * @return mixed
     */
    public function getParam(string key, defaultValue = null)
    {
        if isset this->params[key] {
            return this->params[key];
        }

        return defaultValue;
    }

    /**
     * Display text on the console.
     *
     * @param string text Text to display
     * @param string color The foreground color
     * @param int decoration Formatting type
     * @param string bgColor The background color
     * @param boolean exit Die if true
     * @return self
     */
    public function console(string text, string color = null, int decoration = Console::NORMAL, string bgColor = null, boolean exit = false)
    {
        var text;

        let text = date(this->getParam("date_format", "[Y-m-d H:i:s]")) . " " . text . "\r\n";

        if exit {
            die(text);
        }

        if this->getParam("verbose", false) {
            echo Console::color(text, color, decoration, bgColor);
        }

        return this;
    }

    /**
     * Get script uptime.
     *
     * @param boolean human In seconds if false
     * @return float|string
     */
    public function getUptime(boolean human = true)
    {
        var uptime, y, m, d, h, i, s;

        let uptime = microtime(true) - _SERVER["REQUEST_TIME_FLOAT"];

        if !human {
            return uptime;
        }

        let s = uptime % 60,
            i = floor((uptime % 3600) / 60),
            h = floor((uptime % 86400) / 3600),
            d = floor((uptime % 2592000) / 86400),
            m = floor(uptime / 2592000),
            y = floor(uptime / 2592000 * 12);

        return (y ? y . "Y " : "") .
               (m ? m . "M " : "") .
               (d ? d . "d " : "") .
               (h ? h . "h " : "") .
               (i ? i . "m " : "") .
               (s ? s . "s" : "");
    }

    /**
     * Get memory usage.
     *
     * @param boolean human In byetes if false
     * @return int|string
     */
    public function getMemoryUsage(boolean human = true)
    {
        var size, unit, i;

        let size = memory_get_usage();

        if !human {
            return size;
        }

        let unit = ["B", "KB", "MB", "GB", "TB", "PB"],
            i = floor(log(size, 1024));

        return round(size / pow(1024, (i)), 2) . unit[i];
    }
}
