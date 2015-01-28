
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
#include "kernel/operators.h"
#include "kernel/memory.h"
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
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 * @uses        openSSL
 */
ZEPHIR_INIT_CLASS(Ice_Crypt) {

	ZEPHIR_REGISTER_CLASS(Ice, Crypt, ice, crypt, ice_crypt_method_entry, 0);

	zend_declare_property_null(ice_crypt_ce, SL("_key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_crypt_ce, SL("_cipher"), "aes-256", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_crypt_ce, SL("_mode"), "cbc", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_crypt_ce, SL("_block"), 16, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Create a new encrypter instance.
 *
 * @param string key
 * @return void
 */
PHP_METHOD(Ice_Crypt, __construct) {

	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	zephir_update_property_this(this_ptr, SL("_key"), key TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Encrypt the given value.
 *
 * @param string text
 * @return string
 */
PHP_METHOD(Ice_Crypt, encrypt) {

	zval *_6;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *iv = NULL, *value = NULL, *mac = NULL, *_0 = NULL, *_2 = NULL, *_4 = NULL, *_5;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(text, text_param);


	ZEPHIR_CALL_METHOD(&iv, this_ptr, "generateinputvector", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "serialize", &_1, text);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&value, this_ptr, "addpadding", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_encrypt", NULL, value, iv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&value, "base64_encode", &_3, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "base64_encode", &_3, iv);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(iv, _4);
	ZEPHIR_CALL_METHOD(&mac, this_ptr, "hash", NULL, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_INIT_VAR(_6);
	array_init_size(_6, 4);
	zephir_array_update_string(&_6, SL("iv"), &iv, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("value"), &value, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("mac"), &mac, PH_COPY | PH_SEPARATE);
	zephir_json_encode(_5, &(_5), _6, 0  TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", &_3, _5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate an input vector.
 *
 * @return string
 */
PHP_METHOD(Ice_Crypt, generateInputVector) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getivsize", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_random_pseudo_bytes", NULL, _0);
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
PHP_METHOD(Ice_Crypt, _encrypt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *iv_param = NULL, *_0, *_1, *_2, *_3, _4;
	zval *value = NULL, *iv = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value_param, &iv_param);

	zephir_get_strval(value, value_param);
	zephir_get_strval(iv, iv_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cipher"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_mode"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, _0, "-", _1);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_encrypt", NULL, value, _2, _3, &_4, iv);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *value = NULL, *payload = NULL, *iv = NULL, *_0, *_2, *_3 = NULL, *_4 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(text, text_param);


	ZEPHIR_CALL_METHOD(&payload, this_ptr, "getjsonpayload", NULL, text);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, payload, SL("value"), PH_NOISY | PH_READONLY, "ice/crypt.zep", 97 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&value, "base64_decode", &_1, _0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, payload, SL("iv"), PH_NOISY | PH_READONLY, "ice/crypt.zep", 98 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&iv, "base64_decode", &_1, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "_decrypt", NULL, value, iv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "strippadding", NULL, _4);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", &_5, _3);
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
PHP_METHOD(Ice_Crypt, _decrypt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *iv_param = NULL, *_0, *_1, *_2, *_3, _4;
	zval *value = NULL, *iv = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value_param, &iv_param);

	zephir_get_strval(value, value_param);
	zephir_get_strval(iv, iv_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cipher"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_mode"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, _0, "-", _1);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_decrypt", NULL, value, _2, _3, &_4, iv);
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

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *text_param = NULL, *payload = NULL, *_0 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(text, text_param);


	ZEPHIR_INIT_VAR(payload);
	array_init(payload);
	ZEPHIR_INIT_NVAR(payload);
	ZEPHIR_CALL_FUNCTION(&_0, "base64_decode", &_1, text);
	zephir_check_call_status();
	zephir_json_decode(payload, &(payload), _0, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	_2 = !zephir_is_true(payload);
	if (!(_2)) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "invalidpayload", NULL, payload);
		zephir_check_call_status();
		_2 = zephir_is_true(_3);
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid data passed to encrypter.", "ice/crypt.zep", 132);
		return;
	}
	zephir_array_fetch_string(&_4, payload, SL("mac"), PH_NOISY | PH_READONLY, "ice/crypt.zep", 135 TSRMLS_CC);
	zephir_array_fetch_string(&_6, payload, SL("value"), PH_NOISY | PH_READONLY, "ice/crypt.zep", 135 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "hash", NULL, _6);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_4, _5)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "MAC for payload is invalid.", "ice/crypt.zep", 136);
		return;
	}
	RETURN_CCTOR(payload);

}

/**
 * Create a MAC for the given value.
 *
 * @param string value
 * @return string  
 */
PHP_METHOD(Ice_Crypt, hash) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *_0, _1;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "sha256", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, &_1, value, _0);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zval *value_param = NULL, *pad, *len, *_0, *_1, *_2, *_3 = NULL, *_5 = NULL;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(value, value_param);


	ZEPHIR_INIT_VAR(len);
	ZVAL_LONG(len, zephir_fast_strlen_ev(value));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_block"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_block"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	mod_function(_2, len, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(pad);
	sub_function(pad, _0, _2 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "chr", &_4, pad);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "str_repeat", &_6, _3, pad);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, value, _5);
	RETURN_MM();

}

/**
 * Remove the padding from the given value.
 *
 * @param string value
 * @return string
 */
PHP_METHOD(Ice_Crypt, stripPadding) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL;
	unsigned char _0;
	int pad, len, ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_6, _7;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(value, value_param);


	len = zephir_fast_strlen_ev(value);
	_0 = ZEPHIR_STRING_OFFSET(value, (len - 1));
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, _0);
	ZEPHIR_CALL_FUNCTION(&_2, "ord", &_3, &_1);
	zephir_check_call_status();
	pad = zephir_get_intval(_2);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, pad);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "paddingisvalid", NULL, _6, value);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, (len - pad));
		ZEPHIR_CALL_FUNCTION(&_4, "substr", &_8, value, &_1, &_7);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(_4, value);
	}
	RETURN_CCTOR(_4);

}

/**
 * Determine if the given padding for a value is valid.
 *
 * @param int pad
 * @param string value
 * @return bool
 */
PHP_METHOD(Ice_Crypt, paddingIsValid) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	zval *value = NULL;
	zval *pad_param = NULL, *value_param = NULL, *beforePad, *_0 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_4 = NULL;
	int pad, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &pad_param, &value_param);

	pad = zephir_get_intval(pad_param);
	zephir_get_strval(value, value_param);


	ZEPHIR_INIT_VAR(beforePad);
	ZVAL_LONG(beforePad, (zephir_fast_strlen_ev(value) - pad));
	ZEPHIR_CALL_FUNCTION(&_0, "substr", &_1, value, beforePad);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, -1);
	ZEPHIR_CALL_FUNCTION(&_3, "substr", &_1, value, &_2);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, pad);
	ZEPHIR_CALL_FUNCTION(&_4, "str_repeat", &_5, _3, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(_0, _4));

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
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);


	_0 = !zephir_array_isset_string(data, SS("iv"));
	if (!(_0)) {
		_0 = !zephir_array_isset_string(data, SS("value"));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = !zephir_array_isset_string(data, SS("mac"));
	}
	RETURN_MM_BOOL(_1);

}

/**
 * Get the IV size for the cipher.
 *
 * @return int
 */
PHP_METHOD(Ice_Crypt, getIvSize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cipher"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_mode"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, _0, "-", _1);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_cipher_iv_length", NULL, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set the encryption key.
 *
 * @param string key
 * @return void
 */
PHP_METHOD(Ice_Crypt, setKey) {

	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	zephir_update_property_this(this_ptr, SL("_key"), key TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the encryption cipher.
 *
 * @param string cipher
 * @return void
 */
PHP_METHOD(Ice_Crypt, setCipher) {

	zval *cipher_param = NULL;
	zval *cipher = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipher_param);

	zephir_get_strval(cipher, cipher_param);


	zephir_update_property_this(this_ptr, SL("_cipher"), cipher TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the encryption mode.
 *
 * @param string mode
 * @return void
 */
PHP_METHOD(Ice_Crypt, setMode) {

	zval *mode_param = NULL;
	zval *mode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mode_param);

	zephir_get_strval(mode, mode_param);


	zephir_update_property_this(this_ptr, SL("_mode"), mode TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

