
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


/**
 * Cookie helper.
 *
 * @package     Ice/Cookies
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cookies) {

	ZEPHIR_REGISTER_CLASS(Ice, Cookies, ice, cookies, ice_cookies_method_entry, 0);

	zend_declare_property_null(ice_cookies_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cookies_ce, SL("salt"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_cookies_ce, SL("expiration"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_cookies_ce, SL("path"), "/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cookies_ce, SL("domain"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_cookies_ce, SL("secure"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_cookies_ce, SL("httpOnly"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_cookies_ce, SL("encrypt"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Cookies, getSalt) {


	RETURN_MEMBER(this_ptr, "salt");

}

PHP_METHOD(Ice_Cookies, setSalt) {

	zval *salt;

	zephir_fetch_params(0, 1, 0, &salt);



	zephir_update_property_this(this_ptr, SL("salt"), salt TSRMLS_CC);

}

PHP_METHOD(Ice_Cookies, getExpiration) {


	RETURN_MEMBER(this_ptr, "expiration");

}

PHP_METHOD(Ice_Cookies, setExpiration) {

	zval *expiration;

	zephir_fetch_params(0, 1, 0, &expiration);



	zephir_update_property_this(this_ptr, SL("expiration"), expiration TSRMLS_CC);

}

PHP_METHOD(Ice_Cookies, getPath) {


	RETURN_MEMBER(this_ptr, "path");

}

PHP_METHOD(Ice_Cookies, setPath) {

	zval *path;

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_this(this_ptr, SL("path"), path TSRMLS_CC);

}

PHP_METHOD(Ice_Cookies, getDomain) {


	RETURN_MEMBER(this_ptr, "domain");

}

PHP_METHOD(Ice_Cookies, setDomain) {

	zval *domain;

	zephir_fetch_params(0, 1, 0, &domain);



	zephir_update_property_this(this_ptr, SL("domain"), domain TSRMLS_CC);

}

PHP_METHOD(Ice_Cookies, getSecure) {


	RETURN_MEMBER(this_ptr, "secure");

}

PHP_METHOD(Ice_Cookies, setSecure) {

	zval *secure;

	zephir_fetch_params(0, 1, 0, &secure);



	zephir_update_property_this(this_ptr, SL("secure"), secure TSRMLS_CC);

}

PHP_METHOD(Ice_Cookies, getHttpOnly) {


	RETURN_MEMBER(this_ptr, "httpOnly");

}

PHP_METHOD(Ice_Cookies, setHttpOnly) {

	zval *httpOnly;

	zephir_fetch_params(0, 1, 0, &httpOnly);



	zephir_update_property_this(this_ptr, SL("httpOnly"), httpOnly TSRMLS_CC);

}

PHP_METHOD(Ice_Cookies, getEncrypt) {


	RETURN_MEMBER(this_ptr, "encrypt");

}

PHP_METHOD(Ice_Cookies, setEncrypt) {

	zval *encrypt;

	zephir_fetch_params(0, 1, 0, &encrypt);



	zephir_update_property_this(this_ptr, SL("encrypt"), encrypt TSRMLS_CC);

}

PHP_METHOD(Ice_Cookies, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *salt_param = NULL, *_0 = NULL;
	zval *salt = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &salt_param);

	if (!salt_param) {
		ZEPHIR_INIT_VAR(salt);
		ZVAL_EMPTY_STRING(salt);
	} else {
		zephir_get_strval(salt, salt_param);
	}


	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 8);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("salt"), salt TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Does cookie contain a key
 *
 * @param string key The cookie key
 * @return boolean
 */
PHP_METHOD(Ice_Cookies, has) {

	zval *key_param = NULL, *_COOKIE;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	RETURN_MM_BOOL(zephir_array_isset(_COOKIE, key));

}

/**
 * Gets the value of a signed cookie. 
 * Cookies without signatures will not be returned. If the cookie signature is present, but invalid, the cookie
 * will be deleted.
 *
 * @param string key Cookie name
 * @param mixed defaultValue Default value to return
 */
PHP_METHOD(Ice_Cookies, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, *cookie, *tmp, *hash, *value = NULL, *_COOKIE, _0, *_1, *_2 = NULL, *_3, *_4, *_5 = NULL, *_6, *_7, *_8, *_9 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	zephir_get_strval(key, key_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(cookie);
	if (!(zephir_array_isset_fetch(&cookie, _COOKIE, key, 0 TSRMLS_CC))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "~", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, cookie, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		ZEPHIR_INIT_VAR(tmp);
		zephir_fast_explode_str(tmp, SL("~"), cookie, 2  TSRMLS_CC);
		ZEPHIR_OBS_VAR(hash);
		zephir_array_fetch_long(&hash, tmp, 0, PH_NOISY, "ice/cookies.zep", 65 TSRMLS_CC);
		ZEPHIR_OBS_VAR(value);
		zephir_array_fetch_long(&value, tmp, 1, PH_NOISY, "ice/cookies.zep", 66 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "salt", NULL, 0, key, value);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(_2, hash)) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("encrypt"), PH_NOISY_CC);
			if (zephir_is_true(_3)) {
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_6);
				ZVAL_STRING(_6, "crypt", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_VAR(_7);
				ZVAL_NULL(_7);
				ZEPHIR_INIT_VAR(_8);
				ZVAL_BOOL(_8, 1);
				ZEPHIR_CALL_METHOD(&_5, _4, "get", NULL, 0, _6, _7, _8);
				zephir_check_temp_parameter(_6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_9, _5, "decrypt", NULL, 0, value);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(value, _9);
			}
			RETURN_CCTOR(value);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, key);
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
PHP_METHOD(Ice_Cookies, set) {

	int lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, *lifetime_param = NULL, *_0, *_1, *_2, *_3 = NULL, *_4 = NULL, *_5, *_6, *_7 = NULL, *_8, *_9, *_10, *_11;
	zval *key = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value_param, &lifetime_param);

	zephir_get_strval(key, key_param);
	zephir_get_strval(value, value_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	if (!(lifetime)) {
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("expiration"), PH_NOISY_CC);
		lifetime = zephir_get_intval(_0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encrypt"), PH_NOISY_CC);
	if (zephir_is_true(_1)) {
		if (!(ZEPHIR_IS_EMPTY(value))) {
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "crypt", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_5);
			ZVAL_NULL(_5);
			ZEPHIR_INIT_VAR(_6);
			ZVAL_BOOL(_6, 1);
			ZEPHIR_CALL_METHOD(&_3, _2, "get", NULL, 0, _4, _5, _6);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7, _3, "encrypt", NULL, 0, value);
			zephir_check_call_status();
			zephir_get_strval(value, _7);
		}
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "salt", NULL, 0, key, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VSV(_8, _3, "~", value);
	zephir_get_strval(value, _8);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("domain"), PH_NOISY_CC);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("secure"), PH_NOISY_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("httpOnly"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, lifetime);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setcookie", NULL, 0, key, value, _4, _2, _9, _10, _11);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes a cookie by making the value NULL and expiring it.
 *
 * @param string key cookie name
 * @return boolean
 */
PHP_METHOD(Ice_Cookies, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_COOKIE, *_0, *_1, *_2, *_3, *_4, *_5;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	zephir_array_unset(&_COOKIE, key, PH_SEPARATE);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("domain"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("secure"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("httpOnly"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, -86400);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setcookie", NULL, 0, key, _4, _5, _0, _1, _2, _3);
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
PHP_METHOD(Ice_Cookies, salt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name, *value, *userAgent = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("salt"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "A valid cookie salt is required.", "ice/cookies.zep", 141);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_BOOL(_5, 1);
	ZEPHIR_CALL_METHOD(&_2, _1, "get", NULL, 0, _3, _4, _5);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&userAgent, _2, "getuseragent", NULL, 0);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("salt"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_VVVV(_7, userAgent, name, value, _6);
	ZEPHIR_RETURN_CALL_FUNCTION("sha1", NULL, 36, _7);
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
PHP_METHOD(Ice_Cookies, setcookie) {

	zend_bool secure, httpOnly;
	int expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value_param = NULL, *expire_param = NULL, *path_param = NULL, *domain_param = NULL, *secure_param = NULL, *httpOnly_param = NULL, _0;
	zval *name = NULL, *value = NULL, *path = NULL, *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 7, 0, &name_param, &value_param, &expire_param, &path_param, &domain_param, &secure_param, &httpOnly_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(value, value_param);
	expire = zephir_get_intval(expire_param);
	zephir_get_strval(path, path_param);
	zephir_get_strval(domain, domain_param);
	secure = zephir_get_boolval(secure_param);
	httpOnly = zephir_get_boolval(httpOnly_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, expire);
	ZEPHIR_RETURN_CALL_FUNCTION("setcookie", NULL, 56, name, value, &_0, path, domain, (secure ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), (httpOnly ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

