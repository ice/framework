
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"


/**
 * Google Auth social adapter.
 *
 * @package     Ice/Auth
 * @category    Adapter
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Social_Google) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Social, Google, ice, auth_social_google, ice_auth_social_adapter_ce, ice_auth_social_google_method_entry, 0);

	return SUCCESS;

}

/**
 * Google adapter constructor.
 *
 * @param array config
 */
PHP_METHOD(Ice_Auth_Social_Google, __construct) {

	zval *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *config = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "google", 1);
	zephir_update_property_this(getThis(), SL("provider"), _0 TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, ice_auth_social_google_ce, getThis(), "__construct", &_1, 73, config);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 6, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_2, SS("socialId"), SL("id"), 1);
	add_assoc_stringl_ex(_2, SS("email"), SL("email"), 1);
	add_assoc_stringl_ex(_2, SS("name"), SL("name"), 1);
	add_assoc_stringl_ex(_2, SS("sex"), SL("gender"), 1);
	add_assoc_stringl_ex(_2, SS("socialPage"), SL("link"), 1);
	add_assoc_stringl_ex(_2, SS("image"), SL("picture"), 1);
	zephir_update_property_this(getThis(), SL("socialFieldsMap"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get user birthday or null if it is not set
 *
 * @return string|null
 */
PHP_METHOD(Ice_Auth_Social_Google, getBirthday) {

	zval *_0 = NULL, *_1, *_2$$3, _3$$3 = zval_used_for_init, *_4$$3 = NULL, *_6$$3, *_7$$3, *_8$$3, *_9$$3, *_10$$3, *_11$$3 = NULL, _12$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "birthday", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "Y", 0);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "date", &_5, 42, &_3$$3);
		zephir_check_call_status();
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("userInfo"), PH_NOISY_CC);
		zephir_array_fetch_string(&_7$$3, _6$$3, SL("birthday"), PH_NOISY | PH_READONLY, "ice/auth/social/google.zep", 45 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_STRING(&_3$$3, "0000", 0);
		zephir_fast_str_replace(&_2$$3, &_3$$3, _4$$3, _7$$3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8$$3);
		ZVAL_STRING(_8$$3, "birthday", 1);
		zephir_update_property_array(this_ptr, SL("userInfo"), _8$$3, _2$$3 TSRMLS_CC);
		_9$$3 = zephir_fetch_nproperty_this(this_ptr, SL("userInfo"), PH_NOISY_CC);
		zephir_array_fetch_string(&_10$$3, _9$$3, SL("birthday"), PH_NOISY | PH_READONLY, "ice/auth/social/google.zep", 47 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11$$3, "strtotime", NULL, 74, _10$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_12$$3);
		ZVAL_STRING(&_12$$3, "d.m.Y", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("date", &_5, 42, &_12$$3, _11$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Authenticate and return bool result of authentication
 *
 * @return bool
 */
PHP_METHOD(Ice_Auth_Social_Google, authenticate) {

	zend_bool result = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_GET, *params = NULL, *tokenInfo = NULL, *userInfo = NULL, *_0$$3 = NULL, *_1$$3, *_5$$3, *_2$$4, *_3$$4, *_4$$5, *_6$$6, *_7$$6, *_8$$6, *_9$$6, *_10$$6;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);

	result = 0;
	if (zephir_array_isset_string(_GET, SS("code"))) {
		ZEPHIR_INIT_VAR(params);
		zephir_create_array(params, 5, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_this(&_0$$3, this_ptr, SL("clientId"), PH_NOISY_CC);
		zephir_array_update_string(&params, SL("client_id"), &_0$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_0$$3);
		zephir_read_property_this(&_0$$3, this_ptr, SL("clientSecret"), PH_NOISY_CC);
		zephir_array_update_string(&params, SL("client_secret"), &_0$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_0$$3);
		zephir_read_property_this(&_0$$3, this_ptr, SL("redirectUri"), PH_NOISY_CC);
		zephir_array_update_string(&params, SL("redirect_uri"), &_0$$3, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(params, SS("grant_type"), SL("authorization_code"), 1);
		ZEPHIR_OBS_NVAR(_0$$3);
		zephir_array_fetch_string(&_0$$3, _GET, SL("code"), PH_NOISY, "ice/auth/social/google.zep", 71 TSRMLS_CC);
		zephir_array_update_string(&params, SL("code"), &_0$$3, PH_COPY | PH_SEPARATE);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("accessToken"), PH_NOISY_CC);
		if (!(zephir_is_true(_1$$3))) {
			ZEPHIR_INIT_VAR(_2$$4);
			ZVAL_LONG(_2$$4, 1);
			ZEPHIR_INIT_VAR(_3$$4);
			ZVAL_STRING(_3$$4, "https://accounts.google.com/o/oauth2/token", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&tokenInfo, this_ptr, "call", NULL, 0, _2$$4, _3$$4, params);
			zephir_check_temp_parameter(_3$$4);
			zephir_check_call_status();
			if (zephir_array_isset_string(tokenInfo, SS("access_token"))) {
				zephir_array_fetch_string(&_4$$5, tokenInfo, SL("access_token"), PH_NOISY | PH_READONLY, "ice/auth/social/google.zep", 78 TSRMLS_CC);
				zephir_update_property_this(getThis(), SL("accessToken"), _4$$5 TSRMLS_CC);
			}
		}
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("accessToken"), PH_NOISY_CC);
		if (zephir_is_true(_5$$3)) {
			_6$$6 = zephir_fetch_nproperty_this(this_ptr, SL("accessToken"), PH_NOISY_CC);
			zephir_array_update_string(&params, SL("access_token"), &_6$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(_7$$6);
			ZVAL_LONG(_7$$6, 0);
			ZEPHIR_INIT_VAR(_8$$6);
			ZVAL_STRING(_8$$6, "https://www.googleapis.com/oauth2/v1/userinfo", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&userInfo, this_ptr, "call", NULL, 0, _7$$6, _8$$6, params);
			zephir_check_temp_parameter(_8$$6);
			zephir_check_call_status();
			_9$$6 = zephir_fetch_nproperty_this(this_ptr, SL("socialFieldsMap"), PH_NOISY_CC);
			zephir_array_fetch_string(&_10$$6, _9$$6, SL("socialId"), PH_READONLY, "ice/auth/social/google.zep", 86 TSRMLS_CC);
			if (zephir_array_isset(userInfo, _10$$6)) {
				zephir_update_property_this(getThis(), SL("userInfo"), userInfo TSRMLS_CC);
				result = 1;
			}
		}
	}
	RETURN_MM_BOOL(result);

}

/**
 * Prepare params for authentication url
 *
 * @return array
 */
PHP_METHOD(Ice_Auth_Social_Google, prepareAuthParams) {

	zval *_1 = NULL, *_2 = NULL, *_3, *_4;
	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SS("auth_url"), SL("https://accounts.google.com/o/oauth2/auth"), 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("redirectUri"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("redirect_uri"), &_1, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_0, SS("response_type"), SL("code"), 1);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("clientId"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("client_id"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "scope", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "https://www.googleapis.com/auth/userinfo.email https://www.googleapis.com/auth/userinfo.profile", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getoption", NULL, 0, _3, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("scope"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("auth_params"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

