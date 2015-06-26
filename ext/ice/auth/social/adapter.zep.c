
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
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(Ice_Auth_Social_Adapter) {

	ZEPHIR_REGISTER_CLASS(Ice\\Auth\\Social, Adapter, ice, auth_social_adapter, ice_auth_social_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("_accessToken"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("_clientId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("_clientSecret"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("_redirectUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("_provider"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("_socialFieldsMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("_userInfo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_auth_social_adapter_ce, SL("_responseType"), "code", ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_auth_social_adapter_ce->create_object = zephir_init_properties;
	zend_declare_class_constant_long(ice_auth_social_adapter_ce, SL("GET"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_auth_social_adapter_ce, SL("POST"), 1 TSRMLS_CC);

	zend_class_implements(ice_auth_social_adapter_ce TSRMLS_CC, 1, ice_auth_social_socialinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Auth_Social_Adapter, setAccessToken) {

	zval *accessToken;

	zephir_fetch_params(0, 1, 0, &accessToken);



	zephir_update_property_this(this_ptr, SL("_accessToken"), accessToken TSRMLS_CC);

}

PHP_METHOD(Ice_Auth_Social_Adapter, getAccessToken) {


	RETURN_MEMBER(this_ptr, "_accessToken");

}

PHP_METHOD(Ice_Auth_Social_Adapter, getProvider) {


	RETURN_MEMBER(this_ptr, "_provider");

}

PHP_METHOD(Ice_Auth_Social_Adapter, getResponseType) {


	RETURN_MEMBER(this_ptr, "_responseType");

}

/**
 * Adapter constructor.
 *
 * @param array config
 * @throws Exception
 */
PHP_METHOD(Ice_Auth_Social_Adapter, __construct) {

	zval *_13;
	zend_bool _6, _11;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *config = NULL, *clientId, *clientSecret, *redirectUri, *tmp = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5, *_7 = NULL, *_8, *_9 = NULL, *_10, *_12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		ZEPHIR_SEPARATE_PARAM(config);
	}


	if (!(zephir_fast_count_int(config TSRMLS_CC))) {
		ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "config", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_NULL(_4);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_BOOL(_5, 1);
		ZEPHIR_CALL_METHOD(&_2, _0, "get", NULL, 0, _3, _4, _5);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "auth", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&tmp, _2, "get", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		_6 = zephir_is_true(tmp);
		if (_6) {
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("_provider"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_7, tmp, "has", NULL, 0, _8);
			zephir_check_call_status();
			_6 = zephir_is_true(_7);
		}
		if (_6) {
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_provider"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_9, tmp, "get", NULL, 0, _10);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&config, _9, "toarray", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(clientId);
	if (zephir_array_isset_string_fetch(&clientId, config, SS("client_id"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_clientId"), clientId TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(clientSecret);
	if (zephir_array_isset_string_fetch(&clientSecret, config, SS("client_secret"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_clientSecret"), clientSecret TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(redirectUri);
	if (zephir_array_isset_string_fetch(&redirectUri, config, SS("redirect_uri"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_redirectUri"), redirectUri TSRMLS_CC);
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_clientId"), PH_NOISY_CC);
	_6 = !zephir_is_true(_8);
	if (!(_6)) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_clientSecret"), PH_NOISY_CC);
		_6 = !zephir_is_true(_10);
	}
	_11 = _6;
	if (!(_11)) {
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_redirectUri"), PH_NOISY_CC);
		_11 = !zephir_is_true(_12);
	}
	if (_11) {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, ice_exception_ce);
		ZEPHIR_INIT_VAR(_13);
		zephir_create_array(_13, 4, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "Option `%s`, `%s`, `%s` are required", 1);
		zephir_array_fast_append(_13, _4);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "client_id", 1);
		zephir_array_fast_append(_13, _4);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "client_secret", 1);
		zephir_array_fast_append(_13, _4);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "redirect_uri", 1);
		zephir_array_fast_append(_13, _4);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 2, _13);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "ice/auth/social/adapter.zep", 60 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic method to get user's info.
 *
 * @param string method
 * @param mixed arguments
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Social_Adapter, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *arguments = NULL, *key = NULL, *value, _0, *_1, *_2 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &arguments);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_start_with_str(name, SL("get"))) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 3);
		ZEPHIR_INIT_VAR(_1);
		zephir_substr(_1, name, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&key, "lcfirst", NULL, 18, _1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "has", NULL, 0, key);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			ZEPHIR_OBS_VAR(value);
			zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, key, value);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Whether or not an data exists by key.
 *
 * @param string key The data key
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Social_Adapter, has) {

	zval *key_param = NULL, *_0, *_1, *_2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_socialFieldsMap"), PH_NOISY_CC);
	if (zephir_array_isset(_0, key)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_socialFieldsMap"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, key, PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 97 TSRMLS_CC);
		zephir_get_strval(key, _2);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_userInfo"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_1, key));

}

/**
 * Retrieve a single key from an array.
 * If the key does not exist in the array, the default value will be returned.
 *
 * @param string key The data key
 * @param mixed defaultValue The value to return if data key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Social_Adapter, get) {

	zval *key_param = NULL, *defaultValue = NULL, *value, *_0, *_1, *_2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	zephir_get_strval(key, key_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_socialFieldsMap"), PH_NOISY_CC);
	if (zephir_array_isset(_0, key)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_socialFieldsMap"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, key, PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 117 TSRMLS_CC);
		zephir_get_strval(key, _2);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_userInfo"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _1, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Get authentication url.
 *
 * @return string
 */
PHP_METHOD(Ice_Auth_Social_Adapter, getAuthUrl) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&config, this_ptr, "prepareauthparams", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, config, SL("auth_url"), PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 138 TSRMLS_CC);
	zephir_array_fetch_string(&_1, config, SL("auth_params"), PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 138 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "http_build_query", NULL, 19, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "urldecode", NULL, 20, _2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, _0, "?", _3);
	RETURN_MM();

}

/**
 * Make curl get/post request and return result.
 *
 * @param int method
 * @param string url
 * @param array params
 * @param boolean parse
 * @return array|string
 */
PHP_METHOD(Ice_Auth_Social_Adapter, call) {

	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_6 = NULL;
	zend_bool parse;
	zval *params = NULL;
	zval *url = NULL;
	zval *method_param = NULL, *url_param = NULL, *params_param = NULL, *parse_param = NULL, *curl = NULL, *result = NULL, *_0 = NULL, *_2 = NULL, *_4, _5 = zval_used_for_init, _7, *_8;
	int method, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &method_param, &url_param, &params_param, &parse_param);

	zephir_get_strval(url, url_param);
	zephir_get_arrval(params, params_param);
	if (!method_param) {
		method = 0;
	} else {
		method = zephir_get_intval(method_param);
	}
	if (!parse_param) {
		parse = 1;
	} else {
		parse = zephir_get_boolval(parse_param);
	}


	ZEPHIR_CALL_FUNCTION(&curl, "curl_init", NULL, 21);
	zephir_check_call_status();
	if (method == 0) {
		ZEPHIR_CALL_FUNCTION(&_0, "http_build_query", &_1, 19, params);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2, "urldecode", &_3, 20, _0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VSV(_4, url, "?", _2);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_LONG(&_5, 10002);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_5, _4);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 10002);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_5, url);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 47);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_5, &_7);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_0, "http_build_query", &_1, 19, params);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2, "urldecode", &_3, 20, _0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 10015);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_5, _2);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_5, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 64);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_5, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 23, curl);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 24, curl);
	zephir_check_call_status();
	if (parse) {
		ZEPHIR_INIT_VAR(_8);
		zephir_json_decode(_8, &(_8), result, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
		ZEPHIR_CPY_WRT(result, _8);
	}
	RETURN_CCTOR(result);

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

