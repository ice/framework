
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
 * @copyright   (c) 2014-2018 Ice Team
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "salt");

}

PHP_METHOD(Ice_Cookies, setSalt) {

	zval *salt, salt_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&salt_sub);

	zephir_fetch_params(0, 1, 0, &salt);



	zephir_update_property_zval(this_ptr, SL("salt"), salt);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cookies, getExpiration) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "expiration");

}

PHP_METHOD(Ice_Cookies, setExpiration) {

	zval *expiration, expiration_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expiration_sub);

	zephir_fetch_params(0, 1, 0, &expiration);



	zephir_update_property_zval(this_ptr, SL("expiration"), expiration);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cookies, getPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "path");

}

PHP_METHOD(Ice_Cookies, setPath) {

	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_zval(this_ptr, SL("path"), path);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cookies, getDomain) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "domain");

}

PHP_METHOD(Ice_Cookies, setDomain) {

	zval *domain, domain_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain_sub);

	zephir_fetch_params(0, 1, 0, &domain);



	zephir_update_property_zval(this_ptr, SL("domain"), domain);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cookies, getSecure) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "secure");

}

PHP_METHOD(Ice_Cookies, setSecure) {

	zval *secure, secure_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&secure_sub);

	zephir_fetch_params(0, 1, 0, &secure);



	zephir_update_property_zval(this_ptr, SL("secure"), secure);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cookies, getHttpOnly) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "httpOnly");

}

PHP_METHOD(Ice_Cookies, setHttpOnly) {

	zval *httpOnly, httpOnly_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpOnly_sub);

	zephir_fetch_params(0, 1, 0, &httpOnly);



	zephir_update_property_zval(this_ptr, SL("httpOnly"), httpOnly);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cookies, getEncrypt) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "encrypt");

}

PHP_METHOD(Ice_Cookies, setEncrypt) {

	zval *encrypt, encrypt_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encrypt_sub);

	zephir_fetch_params(0, 1, 0, &encrypt);



	zephir_update_property_zval(this_ptr, SL("encrypt"), encrypt);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cookies, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *salt_param = NULL, _0;
	zval salt;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&salt);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &salt_param);

	if (!salt_param) {
		ZEPHIR_INIT_VAR(&salt);
		ZVAL_STRING(&salt, "");
	} else {
		zephir_get_strval(&salt, salt_param);
	}


	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("di"), &_0);
	zephir_update_property_zval(this_ptr, SL("salt"), &salt);
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
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	RETURN_MM_BOOL(zephir_array_isset(_COOKIE, &key));

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, *_COOKIE, __$null, cookie, tmp, hash, value, _0, _1, _2$$4, _3$$5, _4$$6, _5$$6, _6$$6, _7$$6;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
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

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	zephir_get_strval(&key, key_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_OBS_VAR(&cookie);
	if (!(zephir_array_isset_fetch(&cookie, _COOKIE, &key, 0 TSRMLS_CC))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "~");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &cookie, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&tmp);
		zephir_fast_explode_str(&tmp, SL("~"), &cookie, 2  TSRMLS_CC);
		ZEPHIR_OBS_VAR(&hash);
		zephir_array_fetch_long(&hash, &tmp, 0, PH_NOISY, "ice/cookies.zep", 65 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&value);
		zephir_array_fetch_long(&value, &tmp, 1, PH_NOISY, "ice/cookies.zep", 66 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "salt", NULL, 0, &key, &value);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(&_2$$4, &hash)) {
			zephir_read_property(&_3$$5, this_ptr, SL("encrypt"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_3$$5)) {
				zephir_read_property(&_4$$6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, &key);
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

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, *lifetime_param = NULL, _0$$3, _1, _6, _7, _8, _9, _10, _11, _12, _2$$5, _3$$5, _4$$5, _5$$5;
	zval key, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value_param, &lifetime_param);

	zephir_get_strval(&key, key_param);
	zephir_get_strval(&value, value_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	if (!(lifetime)) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property(&_0$$3, this_ptr, SL("expiration"), PH_NOISY_CC);
		lifetime = zephir_get_intval(&_0$$3);
	}
	zephir_read_property(&_1, this_ptr, SL("encrypt"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		if (!(ZEPHIR_IS_EMPTY(&value))) {
			zephir_read_property(&_2$$5, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "crypt");
			ZEPHIR_CALL_METHOD(&_3$$5, &_2$$5, "get", NULL, 0, &_4$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5$$5, &_3$$5, "encrypt", NULL, 0, &value);
			zephir_check_call_status();
			zephir_get_strval(&value, &_5$$5);
		}
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "salt", NULL, 0, &key, &value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_VSV(&_7, &_6, "~", &value);
	zephir_get_strval(&value, &_7);
	zephir_read_property(&_8, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_9, this_ptr, SL("domain"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_10, this_ptr, SL("secure"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, this_ptr, SL("httpOnly"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_12, lifetime);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setcookie", NULL, 0, &key, &value, &_12, &_8, &_9, &_10, &_11);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_COOKIE, _0, _1, _2, _3, _4, _5;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_array_unset(_COOKIE, &key, PH_SEPARATE);
	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("domain"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("secure"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, SL("httpOnly"), PH_NOISY_CC | PH_READONLY);
	ZVAL_NULL(&_4);
	ZVAL_LONG(&_5, -86400);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setcookie", NULL, 0, &key, &_4, &_5, &_0, &_1, &_2, &_3);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	zephir_read_property(&_0, this_ptr, SL("salt"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "A valid cookie salt is required.", "ice/cookies.zep", 141);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "request");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&userAgent, &_2, "getuseragent", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("salt"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VVVV(&_5, &userAgent, name, value, &_4);
	ZEPHIR_RETURN_CALL_FUNCTION("sha1", NULL, 58, &_5);
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
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value_param = NULL, *expire_param = NULL, *path_param = NULL, *domain_param = NULL, *secure_param = NULL, *httpOnly_param = NULL, _0, _1, _2;
	zval name, value, path, domain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 7, 0, &name_param, &value_param, &expire_param, &path_param, &domain_param, &secure_param, &httpOnly_param);

	zephir_get_strval(&name, name_param);
	zephir_get_strval(&value, value_param);
	expire = zephir_get_intval(expire_param);
	zephir_get_strval(&path, path_param);
	zephir_get_strval(&domain, domain_param);
	secure = zephir_get_boolval(secure_param);
	httpOnly = zephir_get_boolval(httpOnly_param);


	ZVAL_LONG(&_0, expire);
	ZVAL_BOOL(&_1, (secure ? 1 : 0));
	ZVAL_BOOL(&_2, (httpOnly ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("setcookie", NULL, 83, &name, &value, &_0, &path, &domain, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

