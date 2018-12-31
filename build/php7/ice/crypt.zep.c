
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


/**
 * The Crypt library provides two-way encryption of text.
 *
 * @package     Ice/Crypt
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        openSSL
 */
ZEPHIR_INIT_CLASS(Ice_Crypt) {

	ZEPHIR_REGISTER_CLASS(Ice, Crypt, ice, crypt, ice_crypt_method_entry, 0);

	zend_declare_property_null(ice_crypt_ce, SL("key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_crypt_ce, SL("cipher"), "aes-256", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_crypt_ce, SL("mode"), "cbc", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_crypt_ce, SL("block"), 16, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Crypt, setKey) {

	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);

	zephir_fetch_params(0, 1, 0, &key);



	zephir_update_property_zval(this_ptr, SL("key"), key);
	RETURN_THISW();

}

PHP_METHOD(Ice_Crypt, setCipher) {

	zval *cipher, cipher_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher_sub);

	zephir_fetch_params(0, 1, 0, &cipher);



	zephir_update_property_zval(this_ptr, SL("cipher"), cipher);
	RETURN_THISW();

}

PHP_METHOD(Ice_Crypt, setMode) {

	zval *mode, mode_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode_sub);

	zephir_fetch_params(0, 1, 0, &mode);



	zephir_update_property_zval(this_ptr, SL("mode"), mode);
	RETURN_THISW();

}

PHP_METHOD(Ice_Crypt, setBlock) {

	zval *block, block_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&block_sub);

	zephir_fetch_params(0, 1, 0, &block);



	zephir_update_property_zval(this_ptr, SL("block"), block);
	RETURN_THISW();

}

/**
 * Create a new encrypter instance.
 *
 * @param string key
 * @return void
 */
PHP_METHOD(Ice_Crypt, __construct) {

	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}


	zephir_update_property_zval(this_ptr, SL("key"), &key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Encrypt the given value.
 *
 * @param string text
 * @return string
 */
PHP_METHOD(Ice_Crypt, encrypt) {

	zval _5;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, iv, value, mac, _0, _1, _3, _4;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&mac);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(&text, text_param);


	ZEPHIR_CALL_METHOD(&iv, this_ptr, "generateinputvector", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "serialize", NULL, 13, &text);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&value, this_ptr, "addpadding", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "doencrypt", NULL, 0, &value, &iv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&value, "base64_encode", &_2, 14, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "base64_encode", &_2, 14, &iv);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&iv, &_3);
	ZEPHIR_CALL_METHOD(&mac, this_ptr, "hash", NULL, 0, &value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_5, SL("iv"), &iv, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("value"), &value, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("mac"), &mac, PH_COPY | PH_SEPARATE);
	zephir_json_encode(&_4, &_5, 0 );
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", &_2, 14, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate an input vector.
 *
 * @return string
 */
PHP_METHOD(Ice_Crypt, generateInputVector) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getivsize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_random_pseudo_bytes", NULL, 62, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Actually encrypt the value using the given Iv with the openssl library encrypt function.
 *
 * @param string value
 * @param string iv
 * @return string
 */
PHP_METHOD(Ice_Crypt, doEncrypt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *iv_param = NULL, _0, _1, _2, _3, _4;
	zval value, iv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value_param, &iv_param);

	zephir_get_strval(&value, value_param);
	zephir_get_strval(&iv, iv_param);


	zephir_read_property(&_0, this_ptr, SL("cipher"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("mode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &_0, "-", &_1);
	zephir_read_property(&_3, this_ptr, SL("key"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_encrypt", NULL, 84, &value, &_2, &_3, &_4, &iv);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrypt the given value.
 *
 * @param string text payload
 * @return string
 */
PHP_METHOD(Ice_Crypt, decrypt) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, value, payload, iv, _0, _2, _3, _4;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(&text, text_param);


	ZEPHIR_CALL_METHOD(&payload, this_ptr, "getjsonpayload", NULL, 0, &text);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, &payload, SL("value"), PH_NOISY | PH_READONLY, "ice/crypt.zep", 97 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&value, "base64_decode", &_1, 15, &_0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &payload, SL("iv"), PH_NOISY | PH_READONLY, "ice/crypt.zep", 98 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&iv, "base64_decode", &_1, 15, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "dodecrypt", NULL, 0, &value, &iv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "strippadding", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 16, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Actually decrypt the value using the given Iv with the openssl library decrypt function.
 *
 * @param string value
 * @param string iv
 * @return string
 */
PHP_METHOD(Ice_Crypt, doDecrypt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *iv_param = NULL, _0, _1, _2, _3, _4;
	zval value, iv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value_param, &iv_param);

	zephir_get_strval(&value, value_param);
	zephir_get_strval(&iv, iv_param);


	zephir_read_property(&_0, this_ptr, SL("cipher"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("mode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &_0, "-", &_1);
	zephir_read_property(&_3, this_ptr, SL("key"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_decrypt", NULL, 85, &value, &_2, &_3, &_4, &iv);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the JSON array from the given payload.
 *
 * @param string text payload
 * @return array
 */
PHP_METHOD(Ice_Crypt, getJsonPayload) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, __$true, payload, _0, _2, _3, _4, _5;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(&text, text_param);


	ZEPHIR_INIT_VAR(&payload);
	array_init(&payload);
	ZEPHIR_CALL_FUNCTION(&_0, "base64_decode", NULL, 15, &text);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&payload);
	zephir_json_decode(&payload, &_0, zephir_get_intval(&__$true) );
	_1 = !zephir_is_true(&payload);
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "invalidpayload", NULL, 0, &payload);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid data passed to encrypter.", "ice/crypt.zep", 132);
		return;
	}
	zephir_array_fetch_string(&_3, &payload, SL("mac"), PH_NOISY | PH_READONLY, "ice/crypt.zep", 135 TSRMLS_CC);
	zephir_array_fetch_string(&_5, &payload, SL("value"), PH_NOISY | PH_READONLY, "ice/crypt.zep", 135 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "hash", NULL, 0, &_5);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(&_3, &_4)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "MAC for payload is invalid.", "ice/crypt.zep", 136);
		return;
	}
	RETURN_CCTOR(&payload);

}

/**
 * Create a MAC for the given value.
 *
 * @param string value
 * @return string  
 */
PHP_METHOD(Ice_Crypt, hash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, _0, _1;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	zephir_read_property(&_0, this_ptr, SL("key"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sha256");
	ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 26, &_1, &value, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add PKCS7 padding to a given value.
 *
 * @param string value
 * @return string
 */
PHP_METHOD(Ice_Crypt, addPadding) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, pad, len, _0, _1, _2, _3, _4;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&pad);
	ZVAL_UNDEF(&len);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	ZEPHIR_INIT_VAR(&len);
	ZVAL_LONG(&len, zephir_fast_strlen_ev(&value));
	zephir_read_property(&_0, this_ptr, SL("block"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("block"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	mod_function(&_2, &len, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&pad);
	zephir_sub_function(&pad, &_0, &_2);
	ZEPHIR_CALL_FUNCTION(&_3, "chr", NULL, 39, &pad);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "str_repeat", NULL, 86, &_3, &pad);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &value, &_4);
	RETURN_MM();

}

/**
 * Remove the padding from the given value.
 *
 * @param string value
 * @return string
 */
PHP_METHOD(Ice_Crypt, stripPadding) {

	unsigned char _0;
	zend_long ZEPHIR_LAST_CALL_STATUS, pad = 0, len = 0;
	zval *value_param = NULL, _1, _2, _3, _4, _5;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	len = zephir_fast_strlen_ev(&value);
	_0 = ZEPHIR_STRING_OFFSET(&value, (len - 1));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRINGL(&_1, &_0, 1);
	ZEPHIR_CALL_FUNCTION(&_2, "ord", NULL, 34, &_1);
	zephir_check_call_status();
	pad = zephir_get_intval(&_2);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_4, pad);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "paddingisvalid", NULL, 0, &_4, &value);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZVAL_LONG(&_4, 0);
		ZVAL_LONG(&_5, (len - pad));
		zephir_substr(&_1, &value, 0 , zephir_get_intval(&_5), 0);
	} else {
		ZEPHIR_CPY_WRT(&_1, &value);
	}
	RETURN_CCTOR(&_1);

}

/**
 * Determine if the given padding for a value is valid.
 *
 * @param int pad
 * @param string value
 * @return bool
 */
PHP_METHOD(Ice_Crypt, paddingIsValid) {

	zval value;
	zval *pad_param = NULL, *value_param = NULL, beforePad, _0, _1, _2, _3, _4;
	zend_long pad, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&beforePad);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &pad_param, &value_param);

	pad = zephir_get_intval(pad_param);
	zephir_get_strval(&value, value_param);


	ZEPHIR_INIT_VAR(&beforePad);
	ZVAL_LONG(&beforePad, (zephir_fast_strlen_ev(&value) - pad));
	ZEPHIR_INIT_VAR(&_0);
	zephir_substr(&_0, &value, zephir_get_intval(&beforePad), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZVAL_LONG(&_1, -1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &value, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZVAL_LONG(&_3, pad);
	ZEPHIR_CALL_FUNCTION(&_4, "str_repeat", NULL, 86, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&_0, &_4));

}

/**
 * Verify that the encryption payload is valid.
 *
 * @param array data
 * @return bool
 */
PHP_METHOD(Ice_Crypt, invalidPayload) {

	zend_bool _0, _1;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	_0 = !(zephir_array_isset_string(&data, SL("iv")));
	if (!(_0)) {
		_0 = !(zephir_array_isset_string(&data, SL("value")));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = !(zephir_array_isset_string(&data, SL("mac")));
	}
	RETURN_MM_BOOL(_1);

}

/**
 * Get the IV size for the cipher.
 *
 * @return int
 */
PHP_METHOD(Ice_Crypt, getIvSize) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("cipher"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("mode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &_0, "-", &_1);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_cipher_iv_length", NULL, 87, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

