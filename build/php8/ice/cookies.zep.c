
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


/**
 * Cookie helper.
 *
 * @package     Ice/Cookies
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cookies)
{
	ZEPHIR_REGISTER_CLASS(Ice, Cookies, ice, cookies, ice_cookies_method_entry, 0);

	zend_declare_property_null(ice_cookies_ce, SL("di"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_cookies_ce, SL("salt"), ZEND_ACC_PROTECTED);
	zend_declare_property_long(ice_cookies_ce, SL("expiration"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_cookies_ce, SL("path"), "/", ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_cookies_ce, SL("domain"), ZEND_ACC_PROTECTED);
	zend_declare_property_bool(ice_cookies_ce, SL("secure"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_bool(ice_cookies_ce, SL("httpOnly"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_bool(ice_cookies_ce, SL("encrypt"), 1, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Ice_Cookies, getSalt)
{

	RETURN_MEMBER(getThis(), "salt");
}

PHP_METHOD(Ice_Cookies, setSalt)
{
	zval *salt, salt_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&salt_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("salt", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(salt)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &salt);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 129, salt);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cookies, getExpiration)
{

	RETURN_MEMBER(getThis(), "expiration");
}

PHP_METHOD(Ice_Cookies, setExpiration)
{
	zval *expiration, expiration_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expiration_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("expiration", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(expiration)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &expiration);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 130, expiration);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cookies, getPath)
{

	RETURN_MEMBER(getThis(), "path");
}

PHP_METHOD(Ice_Cookies, setPath)
{
	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("path", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(path)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &path);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 131, path);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cookies, getDomain)
{

	RETURN_MEMBER(getThis(), "domain");
}

PHP_METHOD(Ice_Cookies, setDomain)
{
	zval *domain, domain_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("domain", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(domain)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &domain);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 132, domain);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cookies, getSecure)
{

	RETURN_MEMBER(getThis(), "secure");
}

PHP_METHOD(Ice_Cookies, setSecure)
{
	zval *secure, secure_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&secure_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("secure", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(secure)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &secure);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 133, secure);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cookies, getHttpOnly)
{

	RETURN_MEMBER(getThis(), "httpOnly");
}

PHP_METHOD(Ice_Cookies, setHttpOnly)
{
	zval *httpOnly, httpOnly_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpOnly_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("httpOnly", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(httpOnly)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &httpOnly);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 134, httpOnly);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cookies, getEncrypt)
{

	RETURN_MEMBER(getThis(), "encrypt");
}

PHP_METHOD(Ice_Cookies, setEncrypt)
{
	zval *encrypt, encrypt_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encrypt_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("encrypt", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(encrypt)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &encrypt);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 135, encrypt);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cookies, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval salt_zv, _0;
	zend_string *salt = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&salt_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("di", 2, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("salt", 4, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(salt)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!salt) {
		ZEPHIR_INIT_VAR(&salt_zv);
	} else {
		zephir_memory_observe(&salt_zv);
	ZVAL_STR_COPY(&salt_zv, salt);
	}
	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 136, &_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 129, &salt_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * Does cookie contain a key
 *
 * @param string key The cookie key
 * @return boolean
 */
PHP_METHOD(Ice_Cookies, has)
{
	zval key_zv, _COOKIE;
	zend_string *key = NULL;

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_COOKIE);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	ZVAL_STR(&key_zv, key);
	RETURN_BOOL(zephir_array_isset_value(&_COOKIE, &key_zv));
}

/**
 * Gets the value of a signed cookie.
 * Cookies without signatures will not be returned. If the cookie signature is present, but invalid, the cookie
 * will be deleted.
 *
 * @param string key Cookie name
 * @param mixed defaultValue Default value to return
 */
PHP_METHOD(Ice_Cookies, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *defaultValue = NULL, defaultValue_sub, _COOKIE, __$null, cookie, tmp, hash, value, _0, _1, _2$$4, _3$$5, _4$$6, _5$$6, _6$$6, _7$$6;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("encrypt", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("di", 2, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_memory_observe(&cookie);
	if (!(zephir_array_isset_fetch(&cookie, &_COOKIE, &key_zv, 0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "~");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &cookie, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&tmp);
		zephir_fast_explode_str(&tmp, SL("~"), &cookie, 2 );
		zephir_memory_observe(&hash);
		zephir_array_fetch_long(&hash, &tmp, 0, PH_NOISY, "ice/cookies.zep", 64);
		zephir_memory_observe(&value);
		zephir_array_fetch_long(&value, &tmp, 1, PH_NOISY, "ice/cookies.zep", 65);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "salt", NULL, 0, &key_zv, &value);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(&_2$$4, &hash)) {
			zephir_read_property_cached(&_3$$5, this_ptr, _zephir_prop_0, 135, PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_3$$5)) {
				zephir_read_property_cached(&_4$$6, this_ptr, _zephir_prop_1, 136, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_6$$6);
				ZVAL_STRING(&_6$$6, "crypt");
				ZEPHIR_CALL_METHOD(&_5$$6, &_4$$6, "get", NULL, 0, &_6$$6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$6, &_5$$6, "decrypt", NULL, 0, &value);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_7$$6);
			}
			RETURN_CCTOR(&value);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, &key_zv);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();
}

/**
 * Sets a signed cookie.
 * Note that all cookie values must be strings and no automatic serialization will be performed!
 *
 * @param string key Name of cookie
 * @param string value Value of cookie
 * @param integer lifetime Expired time in seconds
 * @return boolean
 */
PHP_METHOD(Ice_Cookies, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval value, _10;
	zval key_zv, *value_param = NULL, *lifetime_param = NULL, _0$$3, _1, _6, _7, _8, _9, _11, _12, _13, _2$$5, _3$$5, _4$$5, _5$$5;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_10);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("expiration", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("encrypt", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("di", 2, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("path", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("domain", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("secure", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("httpOnly", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(lifetime)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value_param = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		lifetime_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_get_strval(&value, value_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		}
	if (!(lifetime)) {
		zephir_memory_observe(&_0$$3);
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 130, PH_NOISY_CC);
		lifetime = zephir_get_intval(&_0$$3);
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 135, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		if (!(ZEPHIR_IS_EMPTY(&value))) {
			zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_2, 136, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "crypt");
			ZEPHIR_CALL_METHOD(&_3$$5, &_2$$5, "get", NULL, 0, &_4$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5$$5, &_3$$5, "encrypt", NULL, 0, &value);
			zephir_check_call_status();
			zephir_get_strval(&value, &_5$$5);
		}
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "salt", NULL, 0, &key_zv, &value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_VSV(&_7, &_6, "~", &value);
	zephir_get_strval(&value, &_7);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_3, 131, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_9);
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_4, 132, PH_NOISY_CC);
	zephir_cast_to_string(&_10, &_9);
	zephir_read_property_cached(&_11, this_ptr, _zephir_prop_5, 133, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_12, this_ptr, _zephir_prop_6, 134, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_13, lifetime);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setcookie", NULL, 0, &key_zv, &value, &_13, &_8, &_10, &_11, &_12);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Deletes a cookie by making the value NULL and expiring it.
 *
 * @param string key cookie name
 * @return boolean
 */
PHP_METHOD(Ice_Cookies, remove)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, _COOKIE, _0, _1, _3, _4, _5, _6;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("path", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("domain", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("secure", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("httpOnly", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_array_unset(&_COOKIE, &key_zv, PH_SEPARATE);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 131, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 132, PH_NOISY_CC);
	zephir_cast_to_string(&_2, &_1);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 133, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_3, 134, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "");
	ZVAL_LONG(&_6, -86400);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setcookie", NULL, 0, &key_zv, &_5, &_6, &_0, &_2, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a salt string for a cookie based on the name and value.
 *
 * @param string name Name of cookie
 * @param string value Value of cookie
 * @throws Exception if salt is not configured
 * @return string
 */
PHP_METHOD(Ice_Cookies, salt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, userAgent, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&userAgent);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("salt", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("di", 2, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &name, &value);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 129, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "A valid cookie salt is required.", "ice/cookies.zep", 140);
		return;
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 136, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "request");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&userAgent, &_2, "getuseragent", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 129, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VVVV(&_5, &userAgent, name, value, &_4);
	ZEPHIR_RETURN_CALL_FUNCTION("sha1", NULL, 68, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Proxy for the native setcookie function - to allow mocking in unit tests so that they do not fail when headers
 * have been sent.
 *
 * @param string name
 * @param string value
 * @param integer expire
 * @param string path
 * @param string domain
 * @param boolean secure
 * @param boolean httpOnly
 * @return bool
 * @see setcookie
 */
PHP_METHOD(Ice_Cookies, setcookie)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool secure, httpOnly;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, value_zv, *expire_param = NULL, path_zv, domain_zv, *secure_param = NULL, *httpOnly_param = NULL, _0, _1, _2;
	zend_string *name = NULL, *value = NULL, *path = NULL, *domain = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&domain_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_STR(name)
		Z_PARAM_STR(value)
		Z_PARAM_LONG(expire)
		Z_PARAM_STR(path)
		Z_PARAM_STR(domain)
		Z_PARAM_BOOL(secure)
		Z_PARAM_BOOL(httpOnly)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	expire_param = ZEND_CALL_ARG(execute_data, 3);
	secure_param = ZEND_CALL_ARG(execute_data, 6);
	httpOnly_param = ZEND_CALL_ARG(execute_data, 7);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	zephir_memory_observe(&domain_zv);
	ZVAL_STR_COPY(&domain_zv, domain);
	ZVAL_LONG(&_0, expire);
	ZVAL_BOOL(&_1, (secure ? 1 : 0));
	ZVAL_BOOL(&_2, (httpOnly ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("setcookie", NULL, 93, &name_zv, &value_zv, &_0, &path_zv, &domain_zv, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

