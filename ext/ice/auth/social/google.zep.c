
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
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Social_Google) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Social, Google, ice, auth_social_google, ice_auth_social_adapter_ce, ice_auth_social_google_method_entry, 0);

	ice_auth_social_google_ce->create_object = zephir_init_properties;
	return SUCCESS;

}

/**
 * Google adapter constructor.
 *
 * @param array config
 */
PHP_METHOD(Ice_Auth_Social_Google, __construct) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
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
	zephir_update_property_this(this_ptr, SL("_provider"), _0 TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, ice_auth_social_google_ce, this_ptr, "__construct", &_1, 45, config);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 6, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_2, SS("socialId"), SL("id"), 1);
	add_assoc_stringl_ex(_2, SS("email"), SL("email"), 1);
	add_assoc_stringl_ex(_2, SS("name"), SL("name"), 1);
	add_assoc_stringl_ex(_2, SS("sex"), SL("gender"), 1);
	add_assoc_stringl_ex(_2, SS("socialPage"), SL("link"), 1);
	add_assoc_stringl_ex(_2, SS("image"), SL("picture"), 1);
	zephir_update_property_this(this_ptr, SL("_socialFieldsMap"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get user birthday or null if it is not set
 *
 * @return string|null
 */
PHP_METHOD(Ice_Auth_Social_Google, getBirthday) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_5, *_6, *_7, *_8, *_9, *_10 = NULL, _11;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "birthday", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "Y", 0);
		ZEPHIR_CALL_FUNCTION(&_3, "date", &_4, 47, &_2);
		zephir_check_call_status();
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_userInfo"), PH_NOISY_CC);
		zephir_array_fetch_string(&_6, _5, SL("birthday"), PH_NOISY | PH_READONLY, "ice/auth/social/google.zep", 45 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, 0000);
		zephir_fast_str_replace(&_1, &_2, _3, _6 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "birthday", 1);
		zephir_update_property_array(this_ptr, SL("_userInfo"), _7, _1 TSRMLS_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_userInfo"), PH_NOISY_CC);
		zephir_array_fetch_string(&_9, _8, SL("birthday"), PH_NOISY | PH_READONLY, "ice/auth/social/google.zep", 47 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "strtotime", NULL, 48, _9);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_11);
		ZVAL_STRING(&_11, "d.m.Y", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("date", &_4, 47, &_11, _10);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params, *tokenInfo = NULL, *userInfo = NULL, *_GET, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5, *_6, *_7;
	zend_bool result;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);

	result = 0;
	if (zephir_array_isset_string(_GET, SS("code"))) {
		ZEPHIR_INIT_VAR(params);
		zephir_create_array(params, 5, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("_clientId"), PH_NOISY_CC);
		zephir_array_update_string(&params, SL("client_id"), &_0, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("_clientSecret"), PH_NOISY_CC);
		zephir_array_update_string(&params, SL("client_secret"), &_0, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("_redirectUri"), PH_NOISY_CC);
		zephir_array_update_string(&params, SL("redirect_uri"), &_0, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(params, SS("grant_type"), SL("authorization_code"), 1);
		ZEPHIR_OBS_NVAR(_0);
		zephir_array_fetch_string(&_0, _GET, SL("code"), PH_NOISY, "ice/auth/social/google.zep", 71 TSRMLS_CC);
		zephir_array_update_string(&params, SL("code"), &_0, PH_COPY | PH_SEPARATE);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_accessToken"), PH_NOISY_CC);
		if (!(zephir_is_true(_1))) {
			ZEPHIR_INIT_VAR(_2);
			ZVAL_LONG(_2, 1);
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "https://accounts.google.com/o/oauth2/token", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&tokenInfo, this_ptr, "call", NULL, 0, _2, _3, params);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			if (zephir_array_isset_string(tokenInfo, SS("access_token"))) {
				zephir_array_fetch_string(&_4, tokenInfo, SL("access_token"), PH_NOISY | PH_READONLY, "ice/auth/social/google.zep", 78 TSRMLS_CC);
				zephir_update_property_this(this_ptr, SL("_accessToken"), _4 TSRMLS_CC);
			}
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_accessToken"), PH_NOISY_CC);
		if (zephir_is_true(_5)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_accessToken"), PH_NOISY_CC);
			zephir_array_update_string(&params, SL("access_token"), &_6, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, 0);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "https://www.googleapis.com/oauth2/v1/userinfo", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&userInfo, this_ptr, "call", NULL, 0, _2, _3, params);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			_7 = zephir_fetch_nproperty_this(this_ptr, SL("_socialFieldsMap"), PH_NOISY_CC);
			zephir_array_fetch_string(&_4, _7, SL("socialId"), PH_READONLY, "ice/auth/social/google.zep", 86 TSRMLS_CC);
			if (zephir_array_isset(userInfo, _4)) {
				zephir_update_property_this(this_ptr, SL("_userInfo"), userInfo TSRMLS_CC);
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

	zval *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SS("auth_url"), SL("https://accounts.google.com/o/oauth2/auth"), 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_redirectUri"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("redirect_uri"), &_1, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_0, SS("response_type"), SL("code"), 1);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_clientId"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("client_id"), &_1, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_0, SS("scope"), SL("https://www.googleapis.com/auth/userinfo.email https://www.googleapis.com/auth/userinfo.profile"), 1);
	zephir_array_update_string(&return_value, SL("auth_params"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_socialFieldsMap"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_socialFieldsMap"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

