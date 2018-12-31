
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


/**
 * Auth social adapter.
 *
 * @package     Ice/Auth
 * @category    Adapter
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Social_Adapter) {

	ZEPHIR_REGISTER_CLASS(Ice\\Auth\\Social, Adapter, ice, auth_social_adapter, ice_auth_social_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("accessToken"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("clientId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("clientSecret"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("redirectUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("provider"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("socialFieldsMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_social_adapter_ce, SL("userInfo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_auth_social_adapter_ce, SL("responseType"), "code", ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_auth_social_adapter_ce->create_object = zephir_init_properties_Ice_Auth_Social_Adapter;
	zend_declare_class_constant_long(ice_auth_social_adapter_ce, SL("GET"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_auth_social_adapter_ce, SL("POST"), 1 TSRMLS_CC);

	zend_class_implements(ice_auth_social_adapter_ce TSRMLS_CC, 1, ice_auth_social_socialinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Auth_Social_Adapter, setAccessToken) {

	zval *accessToken;

	zephir_fetch_params(0, 1, 0, &accessToken);



	zephir_update_property_this(getThis(), SL("accessToken"), accessToken TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Auth_Social_Adapter, getAccessToken) {

	

	RETURN_MEMBER(getThis(), "accessToken");

}

PHP_METHOD(Ice_Auth_Social_Adapter, getProvider) {

	

	RETURN_MEMBER(getThis(), "provider");

}

PHP_METHOD(Ice_Auth_Social_Adapter, getResponseType) {

	

	RETURN_MEMBER(getThis(), "responseType");

}

/**
 * Adapter constructor.
 *
 * @param array config
 * @throws Exception
 */
PHP_METHOD(Ice_Auth_Social_Adapter, __construct) {

	zval *_18$$8;
	zend_bool _13, _15, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *config = NULL, *clientId = NULL, *clientSecret = NULL, *redirectUri = NULL, *di = NULL, *auth = NULL, *_12, *_14, *_16, *_1$$3 = NULL, *_2$$3 = NULL, *_4$$3 = NULL, *_5$$3, *_6$$4 = NULL, *_7$$4, *_8$$7 = NULL, *_9$$7 = NULL, *_10$$7 = NULL, *_11$$7 = NULL, *_17$$8, *_19$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		ZEPHIR_SEPARATE_PARAM(config);
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 1);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(config TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "config", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$3, di, "get", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_STRING(_2$$3, "auth", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&auth, _1$$3, "get", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		_3$$3 = zephir_is_true(auth);
		if (_3$$3) {
			_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("provider"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_4$$3, auth, "has", NULL, 0, _5$$3);
			zephir_check_call_status();
			_3$$3 = zephir_is_true(_4$$3);
		}
		if (_3$$3) {
			_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("provider"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_6$$4, auth, "get", NULL, 0, _7$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&config, _6$$4, "toarray", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(clientId);
	if (zephir_array_isset_string_fetch(&clientId, config, SS("client_id"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("clientId"), clientId TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(clientSecret);
	if (zephir_array_isset_string_fetch(&clientSecret, config, SS("client_secret"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("clientSecret"), clientSecret TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(redirectUri);
	if (zephir_array_isset_string_fetch(&redirectUri, config, SS("redirect_uri"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_8$$7);
		ZEPHIR_INIT_VAR(_10$$7);
		ZVAL_STRING(_10$$7, "url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_9$$7, di, "has", NULL, 0, _10$$7);
		zephir_check_temp_parameter(_10$$7);
		zephir_check_call_status();
		if (zephir_is_true(_9$$7)) {
			ZEPHIR_INIT_NVAR(_10$$7);
			ZVAL_STRING(_10$$7, "url", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_11$$7, di, "get", NULL, 0, _10$$7);
			zephir_check_temp_parameter(_10$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$7, _11$$7, "getstatic", NULL, 0, redirectUri);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_8$$7, redirectUri);
		}
		zephir_update_property_this(getThis(), SL("redirectUri"), _8$$7 TSRMLS_CC);
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("clientId"), PH_NOISY_CC);
	_13 = !zephir_is_true(_12);
	if (!(_13)) {
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("clientSecret"), PH_NOISY_CC);
		_13 = !zephir_is_true(_14);
	}
	_15 = _13;
	if (!(_15)) {
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("redirectUri"), PH_NOISY_CC);
		_15 = !zephir_is_true(_16);
	}
	if (_15) {
		ZEPHIR_INIT_VAR(_17$$8);
		object_init_ex(_17$$8, ice_exception_ce);
		ZEPHIR_INIT_VAR(_18$$8);
		zephir_create_array(_18$$8, 4, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_19$$8);
		ZVAL_STRING(_19$$8, "Option `%s`, `%s`, `%s` are required", 1);
		zephir_array_fast_append(_18$$8, _19$$8);
		ZEPHIR_INIT_NVAR(_19$$8);
		ZVAL_STRING(_19$$8, "client_id", 1);
		zephir_array_fast_append(_18$$8, _19$$8);
		ZEPHIR_INIT_NVAR(_19$$8);
		ZVAL_STRING(_19$$8, "client_secret", 1);
		zephir_array_fast_append(_18$$8, _19$$8);
		ZEPHIR_INIT_NVAR(_19$$8);
		ZVAL_STRING(_19$$8, "redirect_uri", 1);
		zephir_array_fast_append(_18$$8, _19$$8);
		ZEPHIR_CALL_METHOD(NULL, _17$$8, "__construct", NULL, 13, _18$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_17$$8, "ice/auth/social/adapter.zep", 63 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(getThis(), SL("options"), config TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *arguments = NULL, *key = NULL, *value = NULL, _0$$3, *_1$$3, *_2$$3 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &arguments);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_start_with_str(name, SL("get"))) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_LONG(&_0$$3, 3);
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_substr(_1$$3, name, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&key, "lcfirst", NULL, 18, _1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "has", NULL, 0, key);
		zephir_check_call_status();
		if (zephir_is_true(_2$$3)) {
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

	zval *key_param = NULL, *_0, *_3, *_1$$3, *_2$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("socialFieldsMap"), PH_NOISY_CC);
	if (zephir_array_isset(_0, key)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("socialFieldsMap"), PH_NOISY_CC);
		zephir_array_fetch(&_2$$3, _1$$3, key, PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 102 TSRMLS_CC);
		zephir_get_strval(key, _2$$3);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("userInfo"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_3, key));

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

	zval *key_param = NULL, *defaultValue = NULL, *value = NULL, *_0, *_3, *_1$$3, *_2$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	zephir_get_strval(key, key_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("socialFieldsMap"), PH_NOISY_CC);
	if (zephir_array_isset(_0, key)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("socialFieldsMap"), PH_NOISY_CC);
		zephir_array_fetch(&_2$$3, _1$$3, key, PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 122 TSRMLS_CC);
		zephir_get_strval(key, _2$$3);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("userInfo"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _3, key, 1 TSRMLS_CC)) {
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

	zval *config = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&config, this_ptr, "prepareauthparams", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, config, SL("auth_url"), PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 143 TSRMLS_CC);
	zephir_array_fetch_string(&_1, config, SL("auth_params"), PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 143 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "http_build_query", NULL, 19, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "urldecode", NULL, 20, _2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, _0, "?", _3);
	RETURN_MM();

}

/**
 * Get option value with key.
 *
 * @param string key The option key
 * @param mixed defaultValue The value to return if option key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Social_Adapter, getOption) {

	zval *key_param = NULL, *defaultValue = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
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
	zval *method_param = NULL, *url_param = NULL, *params_param = NULL, *parse_param = NULL, *curl = NULL, *result = NULL, _11 = zval_used_for_init, *_0$$3 = NULL, *_2$$3 = NULL, *_4$$3, _5$$3, _7$$4 = zval_used_for_init, _8$$4, *_9$$4 = NULL, *_10$$4 = NULL, *_12$$5;
	zend_long method, ZEPHIR_LAST_CALL_STATUS;

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
		ZEPHIR_CALL_FUNCTION(&_0$$3, "http_build_query", &_1, 19, params);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2$$3, "urldecode", &_3, 20, _0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_VSV(_4$$3, url, "?", _2$$3);
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_LONG(&_5$$3, 10002);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_5$$3, _4$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_VAR(_7$$4);
		ZVAL_LONG(&_7$$4, 10002);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_7$$4, url);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_7$$4);
		ZVAL_LONG(&_7$$4, 47);
		ZEPHIR_SINIT_VAR(_8$$4);
		ZVAL_LONG(&_8$$4, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_7$$4, &_8$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_9$$4, "http_build_query", &_1, 19, params);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_10$$4, "urldecode", &_3, 20, _9$$4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_7$$4);
		ZVAL_LONG(&_7$$4, 10015);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_7$$4, _10$$4);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_11, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_11);
	ZVAL_LONG(&_11, 64);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 22, curl, &_11, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 23, curl);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 24, curl);
	zephir_check_call_status();
	if (parse) {
		ZEPHIR_INIT_VAR(_12$$5);
		zephir_json_decode(_12$$5, &(_12$$5), result, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
		ZEPHIR_CPY_WRT(result, _12$$5);
	}
	RETURN_CCTOR(result);

}

zend_object_value zephir_init_properties_Ice_Auth_Social_Adapter(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("socialFieldsMap"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("socialFieldsMap"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

