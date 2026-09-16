
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
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * The Crypt library provides two-way encryption of text.
 *
 * @package     Ice/Crypt
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 * @uses        openSSL
 */
ZEPHIR_INIT_CLASS(Ice_Crypt)
{
	ZEPHIR_REGISTER_CLASS(Ice, Crypt, ice, crypt, ice_crypt_method_entry, 0);

	zend_declare_property_null(ice_crypt_ce, SL("key"), ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_crypt_ce, SL("cipher"), "aes-256", ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_crypt_ce, SL("mode"), "cbc", ZEND_ACC_PROTECTED);
	zend_declare_property_long(ice_crypt_ce, SL("block"), 16, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Ice_Crypt, setKey)
{
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("key", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &key);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 137, key);
	RETURN_THISW();
}

PHP_METHOD(Ice_Crypt, setCipher)
{
	zval *cipher, cipher_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cipher", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(cipher)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &cipher);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 138, cipher);
	RETURN_THISW();
}

PHP_METHOD(Ice_Crypt, setMode)
{
	zval *mode, mode_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("mode", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &mode);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 139, mode);
	RETURN_THISW();
}

PHP_METHOD(Ice_Crypt, setBlock)
{
	zval *block, block_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&block_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("block", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(block)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &block);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 140, block);
	RETURN_THISW();
}

/**
 * Create a new encrypter instance.
 *
 * @param string key
 * @return void
 */
PHP_METHOD(Ice_Crypt, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval key_zv;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("key", 3, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!key) {
		ZEPHIR_INIT_VAR(&key_zv);
	} else {
		zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 137, &key_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * Encrypt the given value.
 *
 * @param string text
 * @return string
 */
PHP_METHOD(Ice_Crypt, encrypt)
{
	zval _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, iv, value, mac, _0, _1, _3, _4;
	zend_string *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&mac);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZEPHIR_CALL_METHOD(&iv, this_ptr, "generateinputvector", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "serialize", NULL, 14, &text_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&value, this_ptr, "addpadding", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "doencrypt", NULL, 0, &value, &iv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&value, "base64_encode", &_2, 15, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "base64_encode", &_2, 15, &iv);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&iv, &_3);
	ZEPHIR_CALL_METHOD(&mac, this_ptr, "hash", NULL, 0, &value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 3, 0);
	zephir_array_update_string(&_5, SL("iv"), &iv, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("value"), &value, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("mac"), &mac, PH_COPY | PH_SEPARATE);
	zephir_json_encode(&_4, &_5, 0 );
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", &_2, 15, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generate an input vector.
 *
 * @return string
 */
PHP_METHOD(Ice_Crypt, generateInputVector)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getivsize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_random_pseudo_bytes", NULL, 73, &_0);
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
PHP_METHOD(Ice_Crypt, doEncrypt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value_zv, iv_zv, _0, _1, _2, _3, _4;
	zend_string *value = NULL, *iv = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&iv_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cipher", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("mode", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("key", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(value)
		Z_PARAM_STR(iv)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	zephir_memory_observe(&iv_zv);
	ZVAL_STR_COPY(&iv_zv, iv);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 138, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 139, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &_0, "-", &_1);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 137, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_encrypt", NULL, 94, &value_zv, &_2, &_3, &_4, &iv_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Decrypt the given value.
 *
 * @param string text payload
 * @return string
 */
PHP_METHOD(Ice_Crypt, decrypt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, value, payload, iv, _0, _2, _3, _4;
	zend_string *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZEPHIR_CALL_METHOD(&payload, this_ptr, "getjsonpayload", NULL, 0, &text_zv);
	zephir_check_call_status();
	zephir_memory_observe(&_0);
	zephir_array_fetch_string(&_0, &payload, SL("value"), PH_NOISY, "ice/crypt.zep", 96);
	ZEPHIR_CALL_FUNCTION(&value, "base64_decode", &_1, 16, &_0);
	zephir_check_call_status();
	zephir_memory_observe(&_2);
	zephir_array_fetch_string(&_2, &payload, SL("iv"), PH_NOISY, "ice/crypt.zep", 97);
	ZEPHIR_CALL_FUNCTION(&iv, "base64_decode", &_1, 16, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "dodecrypt", NULL, 0, &value, &iv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "strippadding", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 17, &_3);
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
PHP_METHOD(Ice_Crypt, doDecrypt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value_zv, iv_zv, _0, _1, _2, _3, _4;
	zend_string *value = NULL, *iv = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&iv_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cipher", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("mode", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("key", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(value)
		Z_PARAM_STR(iv)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	zephir_memory_observe(&iv_zv);
	ZVAL_STR_COPY(&iv_zv, iv);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 138, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 139, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &_0, "-", &_1);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 137, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_decrypt", NULL, 95, &value_zv, &_2, &_3, &_4, &iv_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get the JSON array from the given payload.
 *
 * @param string text payload
 * @return array
 */
PHP_METHOD(Ice_Crypt, getJsonPayload)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, __$true, payload, _0, _2, _3, _4, _5;
	zend_string *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZEPHIR_INIT_VAR(&payload);
	array_init(&payload);
	ZEPHIR_CALL_FUNCTION(&_0, "base64_decode", NULL, 16, &text_zv);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid data passed to encrypter.", "ice/crypt.zep", 131);
		return;
	}
	zephir_memory_observe(&_3);
	zephir_array_fetch_string(&_3, &payload, SL("mac"), PH_NOISY, "ice/crypt.zep", 134);
	zephir_memory_observe(&_5);
	zephir_array_fetch_string(&_5, &payload, SL("value"), PH_NOISY, "ice/crypt.zep", 134);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "hash", NULL, 0, &_5);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(&_3, &_4)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "MAC for payload is invalid.", "ice/crypt.zep", 135);
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
PHP_METHOD(Ice_Crypt, hash)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value_zv, _0, _1;
	zend_string *value = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("key", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 137, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sha256");
	ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 27, &_1, &value_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Add PKCS7 padding to a given value.
 *
 * @param string value
 * @return string
 */
PHP_METHOD(Ice_Crypt, addPadding)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value_zv, pad, len, _0, _1, _2, _3, _4;
	zend_string *value = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&pad);
	ZVAL_UNDEF(&len);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("block", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	ZEPHIR_INIT_VAR(&len);
	ZVAL_LONG(&len, zephir_fast_strlen_ev(&value_zv));
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 140, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 140, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	mod_function(&_2, &len, &_1);
	ZEPHIR_INIT_VAR(&pad);
	zephir_sub_function(&pad, &_0, &_2);
	ZEPHIR_CALL_FUNCTION(&_3, "chr", NULL, 40, &pad);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "str_repeat", NULL, 96, &_3, &pad);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &value_zv, &_4);
	RETURN_MM();
}

/**
 * Remove the padding from the given value.
 *
 * @param string value
 * @return string
 */
PHP_METHOD(Ice_Crypt, stripPadding)
{
	unsigned char _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pad = 0, len = 0;
	zval value_zv, _1, _2, _3, _4, _5, _6;
	zend_string *value = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	len = zephir_fast_strlen_ev(&value_zv);
	ZEPHIR_INIT_VAR(&_1);
	zephir_string_offset_read(&_1, &value_zv, (len - 1), PH_NOISY);
	ZEPHIR_CALL_FUNCTION(&_2, "ord", NULL, 35, &_1);
	zephir_check_call_status();
	pad = zephir_get_intval(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_5, pad);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "paddingisvalid", NULL, 0, &_5, &value_zv);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZVAL_LONG(&_5, 0);
		ZVAL_LONG(&_6, (len - pad));
		ZEPHIR_INIT_NVAR(&_3);
		zephir_substr(&_3, &value_zv, 0 , zephir_get_intval(&_6), 0);
	} else {
		ZEPHIR_CPY_WRT(&_3, &value_zv);
	}
	RETURN_CCTOR(&_3);
}

/**
 * Determine if the given padding for a value is valid.
 *
 * @param int pad
 * @param string value
 * @return bool
 */
PHP_METHOD(Ice_Crypt, paddingIsValid)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *value = NULL;
	zval *pad_param = NULL, value_zv, beforePad, _0, _1, _2, _3, _4;
	zend_long pad, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&beforePad);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pad)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	pad_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	ZEPHIR_INIT_VAR(&beforePad);
	ZVAL_LONG(&beforePad, (zephir_fast_strlen_ev(&value_zv) - pad));
	ZEPHIR_INIT_VAR(&_0);
	zephir_substr(&_0, &value_zv, zephir_get_intval(&beforePad), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZVAL_LONG(&_1, -1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &value_zv, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZVAL_LONG(&_3, pad);
	ZEPHIR_CALL_FUNCTION(&_4, "str_repeat", NULL, 96, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&_0, &_4));
}

/**
 * Verify that the encryption payload is valid.
 *
 * @param array data
 * @return bool
 */
PHP_METHOD(Ice_Crypt, invalidPayload)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL;
	zval data;

	ZVAL_UNDEF(&data);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	_0 = !(zephir_array_isset_value_string(&data, SL("iv")));
	if (!(_0)) {
		_0 = !(zephir_array_isset_value_string(&data, SL("value")));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = !(zephir_array_isset_value_string(&data, SL("mac")));
	}
	RETURN_MM_BOOL(_1);
}

/**
 * Get the IV size for the cipher.
 *
 * @return int
 */
PHP_METHOD(Ice_Crypt, getIvSize)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cipher", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("mode", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 138, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 139, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &_0, "-", &_1);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_cipher_iv_length", NULL, 97, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

