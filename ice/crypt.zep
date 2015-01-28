
namespace Ice;

/**
 * The Crypt library provides two-way encryption of text.
 *
 * @package     Ice/Crypt
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 * @uses        openSSL
 */
class Crypt
{

    protected _key;
    protected _cipher = "aes-256";
    protected _mode = "cbc";
    protected _block = 16;

    /**
     * Create a new encrypter instance.
     *
     * @param string key
     * @return void
     */
    public function __construct(string key)
    {
        let this->_key = key;
    }

    /**
     * Encrypt the given value.
     *
     * @param string text
     * @return string
     */
    public function encrypt(string text) -> string
    {
        var iv, value, mac;

        let iv = this->generateInputVector(),
            value = this->addPadding(serialize(text)),
            value = base64_encode(this->_encrypt(value, iv));

        // Once we have the encrypted value we will go ahead base64_encode the input
        // vector and create the MAC for the encrypted value so we can verify its
        // authenticity. Then, we'll JSON encode the data in a "payload" array.
        let iv = base64_encode(iv),
            mac = this->hash(value);

        return base64_encode(json_encode([
            "iv": iv,
            "value": value,
            "mac": mac
        ]));
    }

    /**
     * Generate an input vector.
     *
     * @return string
     */
    protected function generateInputVector() ->string
    {
        return openssl_random_pseudo_bytes(this->getIvSize());
    }

    /**
     * Actually encrypt the value using the given Iv with the openssl library encrypt function.
     *
     * @param string value
     * @param string iv
     * @return string
     */
    protected function _encrypt(string value, string iv) -> string
    {
        return openssl_encrypt(value, this->_cipher . "-" . this->_mode, this->_key, OPENSSL_RAW_DATA, iv);
    }

    /**
     * Decrypt the given value.
     *
     * @param string text payload
     * @return string
     */
    public function decrypt(string text) -> string
    {
        var value, payload, iv;

        let payload = this->getJsonPayload(text);

        // We'll go ahead and remove the PKCS7 padding from the encrypted value before
        // we decrypt it. Once we have the de-padded value, we will grab the vector
        // and decrypt the data, passing back the unserialized from of the value.
        let value = base64_decode(payload["value"]),
            iv = base64_decode(payload["iv"]);

        return unserialize(this->stripPadding(this->_decrypt(value, iv)));
    }

    /**
     * Actually decrypt the value using the given Iv with the openssl library decrypt function.
     *
     * @param string value
     * @param string iv
     * @return string
     */
    protected function _decrypt(string value, string iv) -> string
    {
        return openssl_decrypt(value, this->_cipher . "-" . this->_mode, this->_key, OPENSSL_RAW_DATA, iv);
    }

    /**
     * Get the JSON array from the given payload.
     *
     * @param string text payload
     * @return array
     */
    protected function getJsonPayload(string text) -> array
    {
        var payload;

        let payload = [],
            payload = json_decode(base64_decode(text), true);

        // If the payload is not valid JSON or does not have the proper keys set we will
        // assume it is invalid and bail out of the routine since we will not be able
        // to decrypt the given value. We'll also check the MAC for this encryption.
        if !payload || this->invalidPayload(payload) {
            throw new Exception("Invalid data passed to encrypter.");
        }

        if payload["mac"] != this->hash(payload["value"]) {
            throw new Exception("MAC for payload is invalid.");
        }

        return payload;
    }

    /**
     * Create a MAC for the given value.
     *
     * @param string value
     * @return string  
     */
    protected function hash(string value) -> string
    {
        return hash_hmac("sha256", value, this->_key);
    }

    /**
     * Add PKCS7 padding to a given value.
     *
     * @param string value
     * @return string
     */
    protected function addPadding(string value) -> string
    {
        var pad, len;

        let len = strlen(value),
            pad = this->_block - (len % this->_block);

        return value . str_repeat(chr(pad), pad);
    }

    /**
     * Remove the padding from the given value.
     *
     * @param string value
     * @return string
     */
    protected function stripPadding(string value) -> string
    {
        var pad, len;

        let len = (int) strlen(value),
            pad = (int) ord(value[len - 1]);

        return this->paddingIsValid(pad, value) ? substr(value, 0, len - pad) : value;
    }

    /**
     * Determine if the given padding for a value is valid.
     *
     * @param int pad
     * @param string value
     * @return bool
     */
    protected function paddingIsValid(int pad, string value) -> boolean
    {
        var beforePad;

        let beforePad = strlen(value) - pad;

        return substr(value, beforePad) == str_repeat(substr(value, -1), pad);
    }

    /**
     * Verify that the encryption payload is valid.
     *
     * @param array data
     * @return bool
     */
    protected function invalidPayload(array data) -> boolean
    {
        return !isset data["iv"] || !isset data["value"] || !isset data["mac"];
    }

    /**
     * Get the IV size for the cipher.
     *
     * @return int
     */
    protected function getIvSize() -> int
    {
        return openssl_cipher_iv_length(this->_cipher . "-" . this->_mode);
    }

    /**
     * Set the encryption key.
     *
     * @param string key
     * @return void
     */
    public function setKey(string key)
    {
        let this->_key = key;
    }

    /**
     * Set the encryption cipher.
     *
     * @param string cipher
     * @return void
     */
    public function setCipher(string cipher)
    {
        let this->_cipher = cipher;
    }

    /**
     * Set the encryption mode.
     *
     * @param string mode
     * @return void
     */
    public function setMode(string mode)
    {
        let this->_mode = mode;
    }
}
