
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
	zephir_declare_class_constant_long(ice_auth_social_adapter_ce, SL("GET"), 0);

	zephir_declare_class_constant_long(ice_auth_social_adapter_ce, SL("POST"), 1);

	zend_class_implements(ice_auth_social_adapter_ce TSRMLS_CC, 1, ice_auth_social_socialinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Auth_Social_Adapter, setAccessToken) {

	zval *accessToken, accessToken_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&accessToken_sub);

	zephir_fetch_params(0, 1, 0, &accessToken);



	zephir_update_property_zval(this_ptr, SL("accessToken"), accessToken);
	RETURN_THISW();

}

PHP_METHOD(Ice_Auth_Social_Adapter, getAccessToken) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "accessToken");

}

PHP_METHOD(Ice_Auth_Social_Adapter, getProvider) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "provider");

}

PHP_METHOD(Ice_Auth_Social_Adapter, getResponseType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "responseType");

}

/**
 * Adapter constructor.
 *
 * @param array config
 * @throws Exception
 */
PHP_METHOD(Ice_Auth_Social_Adapter, __construct) {

	zval _18$$8;
	zend_bool _13, _15, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *config = NULL, config_sub, clientId, clientSecret, redirectUri, di, auth, _12, _14, _16, _1$$3, _2$$3, _4$$3, _5$$3, _6$$4, _7$$4, _8$$7, _9$$7, _10$$7, _11$$7, _17$$8, _19$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&clientId);
	ZVAL_UNDEF(&clientSecret);
	ZVAL_UNDEF(&redirectUri);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_18$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		config = &config_sub;
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		ZEPHIR_SEPARATE_PARAM(config);
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(config TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "config");
		ZEPHIR_CALL_METHOD(&_1$$3, &di, "get", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "auth");
		ZEPHIR_CALL_METHOD(&auth, &_1$$3, "get", NULL, 0, &_2$$3);
		zephir_check_call_status();
		_3$$3 = zephir_is_true(&auth);
		if (_3$$3) {
			zephir_read_property(&_5$$3, this_ptr, SL("provider"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_4$$3, &auth, "has", NULL, 0, &_5$$3);
			zephir_check_call_status();
			_3$$3 = zephir_is_true(&_4$$3);
		}
		if (_3$$3) {
			zephir_read_property(&_7$$4, this_ptr, SL("provider"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_6$$4, &auth, "get", NULL, 0, &_7$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(config, &_6$$4, "toarray", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(&clientId);
	if (zephir_array_isset_string_fetch(&clientId, config, SL("client_id"), 0)) {
		zephir_update_property_zval(this_ptr, SL("clientId"), &clientId);
	}
	ZEPHIR_OBS_VAR(&clientSecret);
	if (zephir_array_isset_string_fetch(&clientSecret, config, SL("client_secret"), 0)) {
		zephir_update_property_zval(this_ptr, SL("clientSecret"), &clientSecret);
	}
	ZEPHIR_OBS_VAR(&redirectUri);
	if (zephir_array_isset_string_fetch(&redirectUri, config, SL("redirect_uri"), 0)) {
		ZEPHIR_INIT_VAR(&_8$$7);
		ZEPHIR_INIT_VAR(&_10$$7);
		ZVAL_STRING(&_10$$7, "url");
		ZEPHIR_CALL_METHOD(&_9$$7, &di, "has", NULL, 0, &_10$$7);
		zephir_check_call_status();
		if (zephir_is_true(&_9$$7)) {
			ZEPHIR_INIT_NVAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "url");
			ZEPHIR_CALL_METHOD(&_11$$7, &di, "get", NULL, 0, &_10$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$7, &_11$$7, "getstatic", NULL, 0, &redirectUri);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&_8$$7, &redirectUri);
		}
		zephir_update_property_zval(this_ptr, SL("redirectUri"), &_8$$7);
	}
	zephir_read_property(&_12, this_ptr, SL("clientId"), PH_NOISY_CC | PH_READONLY);
	_13 = !zephir_is_true(&_12);
	if (!(_13)) {
		zephir_read_property(&_14, this_ptr, SL("clientSecret"), PH_NOISY_CC | PH_READONLY);
		_13 = !zephir_is_true(&_14);
	}
	_15 = _13;
	if (!(_15)) {
		zephir_read_property(&_16, this_ptr, SL("redirectUri"), PH_NOISY_CC | PH_READONLY);
		_15 = !zephir_is_true(&_16);
	}
	if (_15) {
		ZEPHIR_INIT_VAR(&_17$$8);
		object_init_ex(&_17$$8, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_18$$8);
		zephir_create_array(&_18$$8, 4, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_19$$8);
		ZVAL_STRING(&_19$$8, "Option `%s`, `%s`, `%s` are required");
		zephir_array_fast_append(&_18$$8, &_19$$8);
		ZEPHIR_INIT_NVAR(&_19$$8);
		ZVAL_STRING(&_19$$8, "client_id");
		zephir_array_fast_append(&_18$$8, &_19$$8);
		ZEPHIR_INIT_NVAR(&_19$$8);
		ZVAL_STRING(&_19$$8, "client_secret");
		zephir_array_fast_append(&_18$$8, &_19$$8);
		ZEPHIR_INIT_NVAR(&_19$$8);
		ZVAL_STRING(&_19$$8, "redirect_uri");
		zephir_array_fast_append(&_18$$8, &_19$$8);
		ZEPHIR_CALL_METHOD(NULL, &_17$$8, "__construct", NULL, 12, &_18$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_17$$8, "ice/auth/social/adapter.zep", 63 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("options"), config);
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
	zval *name_param = NULL, *arguments = NULL, arguments_sub, __$null, key, value, _0$$3, _1$$3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &arguments);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	if (zephir_start_with_str(&name, SL("get"))) {
		ZVAL_LONG(&_0$$3, 3);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_substr(&_1$$3, &name, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&key, "lcfirst", NULL, 17, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "has", NULL, 0, &key);
		zephir_check_call_status();
		if (zephir_is_true(&_2$$3)) {
			ZEPHIR_OBS_VAR(&value);
			zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &key, &value);
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

	zval *key_param = NULL, _0, _3, _1$$3, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, SL("socialFieldsMap"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &key)) {
		zephir_read_property(&_1$$3, this_ptr, SL("socialFieldsMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 102 TSRMLS_CC);
		zephir_get_strval(&key, &_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("userInfo"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_3, &key));

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

	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0, _3, _1$$3, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	zephir_get_strval(&key, key_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("socialFieldsMap"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &key)) {
		zephir_read_property(&_1$$3, this_ptr, SL("socialFieldsMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 122 TSRMLS_CC);
		zephir_get_strval(&key, &_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("userInfo"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_3, &key, 1 TSRMLS_CC)) {
		RETURN_CTOR(&value);
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

	zval config, _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&config, this_ptr, "prepareauthparams", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, &config, SL("auth_url"), PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 143 TSRMLS_CC);
	zephir_array_fetch_string(&_1, &config, SL("auth_params"), PH_NOISY | PH_READONLY, "ice/auth/social/adapter.zep", 143 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "http_build_query", NULL, 18, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "urldecode", NULL, 19, &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_0, "?", &_3);
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

	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &key, 1 TSRMLS_CC)) {
		RETURN_CTOR(&value);
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
	zval params;
	zval url;
	zval *method_param = NULL, *url_param = NULL, *params_param = NULL, *parse_param = NULL, __$true, __$false, curl, result, _11, _0$$3, _2$$3, _4$$3, _5$$3, _7$$4, _8$$4, _9$$4, _10$$4, _12$$5;
	zend_long method, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&curl);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &method_param, &url_param, &params_param, &parse_param);

	zephir_get_strval(&url, url_param);
	zephir_get_arrval(&params, params_param);
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


	ZEPHIR_CALL_FUNCTION(&curl, "curl_init", NULL, 20);
	zephir_check_call_status();
	if (method == 0) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "http_build_query", &_1, 18, &params);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2$$3, "urldecode", &_3, 19, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_VSV(&_4$$3, &url, "?", &_2$$3);
		ZVAL_LONG(&_5$$3, 10002);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 21, &curl, &_5$$3, &_4$$3);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_7$$4, 10002);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 21, &curl, &_7$$4, &url);
		zephir_check_call_status();
		ZVAL_LONG(&_7$$4, 47);
		ZVAL_LONG(&_8$$4, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 21, &curl, &_7$$4, &_8$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_9$$4, "http_build_query", &_1, 18, &params);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_10$$4, "urldecode", &_3, 19, &_9$$4);
		zephir_check_call_status();
		ZVAL_LONG(&_7$$4, 10015);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 21, &curl, &_7$$4, &_10$$4);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_11, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 21, &curl, &_11, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_11, 64);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, 21, &curl, &_11, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 22, &curl);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 23, &curl);
	zephir_check_call_status();
	if (parse) {
		ZEPHIR_INIT_VAR(&_12$$5);
		zephir_json_decode(&_12$$5, &result, zephir_get_intval(&__$true) );
		ZEPHIR_CPY_WRT(&result, &_12$$5);
	}
	RETURN_CCTOR(&result);

}

zend_object *zephir_init_properties_Ice_Auth_Social_Adapter(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("socialFieldsMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("socialFieldsMap"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

