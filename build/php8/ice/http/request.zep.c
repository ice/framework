
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * Inspect the current HTTP request.
 *
 * @package     Ice/Http
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Http_Request) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Http, Request, ice, http_request, ice_arr_ce, ice_http_request_method_entry, 0);

	zend_declare_property_null(ice_http_request_ce, SL("files"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_http_request_ce, SL("get"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_http_request_ce, SL("post"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_http_request_ce, SL("server"), ZEND_ACC_PROTECTED);

	zend_class_implements(ice_http_request_ce, 1, ice_http_request_requestinterface_ce);
	return SUCCESS;

}

/**
 * Request constructor. Fetch data from globals variables: _REQUEST, _SERVER, _POST, _GET and _FILES.
 */
PHP_METHOD(Ice_Http_Request, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _FILES, _GET, _POST, _SERVER, _REQUEST, _0, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);


	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_FILES, SL("_FILES"));

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", &_1, 4, &_FILES);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("files"), &_0);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_1, 4, &_GET);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("get"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", &_1, 4, &_POST);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("post"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", &_1, 4, &_SERVER);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("server"), &_4);
	ZEPHIR_CALL_PARENT(NULL, ice_http_request_ce, getThis(), "__construct", &_5, 0, &_REQUEST);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether _REQUEST has index.
 *
 * @param string name Index name
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, hasRequest) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether _POST has index.
 *
 * @param string name Index name
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, hasPost) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("post"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether _GET has index.
 *
 * @param string name Index name
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, hasGet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("get"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether _SERVER has index.
 *
 * @param string name Index name
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, hasServer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether _FILES has index.
 *
 * @param string name Index name
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, hasFile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("files"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks whether HTTP method is POST.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isPost) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "POST"));

}

/**
 * Checks whether HTTP method is GET.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isGet) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "GET"));

}

/**
 * Checks whether HTTP method is PUT.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isPut) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "PUT"));

}

/**
 * Checks whether HTTP method is PATCH.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isPatch) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "PATCH"));

}

/**
 * Checks whether HTTP method is HEAD.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isHead) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "HEAD"));

}

/**
 * Checks whether HTTP method is DELETE.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isDelete) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "DELETE"));

}

/**
 * Checks whether HTTP method is OPTIONS.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isOptions) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "OPTIONS"));

}

/**
 * Checks whether request has been made using AJAX.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isAjax) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "HTTP_X_REQUESTED_WITH");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_1, "XMLHttpRequest"));

}

/**
 * Gets HTTP method which request has been made.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Request, getMethod) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "REQUEST_METHOD");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets HTTP user agent used to made the request.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Request, getUserAgent) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_USER_AGENT");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets web page that refers active request.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Request, getHTTPReferer) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_REFERER");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets most possible client IPv4 Address.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Request, getClientAddress) {

	zval client, forward, remote, ip, _0, _1, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&client);
	ZVAL_UNDEF(&forward);
	ZVAL_UNDEF(&remote);
	ZVAL_UNDEF(&ip);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_CLIENT_IP");
	ZEPHIR_CALL_METHOD(&client, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "HTTP_X_FORWARDED_FOR");
	ZEPHIR_CALL_METHOD(&forward, &_2, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "REMOTE_ADDR");
	ZEPHIR_CALL_METHOD(&remote, &_3, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 275);
	ZEPHIR_CALL_FUNCTION(&_5, "filter_var", NULL, 132, &client, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 275);
	ZEPHIR_CALL_FUNCTION(&_6, "filter_var", NULL, 132, &forward, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CPY_WRT(&ip, &client);
	} else if (zephir_is_true(&_6)) {
		ZEPHIR_CPY_WRT(&ip, &forward);
	} else {
		ZEPHIR_CPY_WRT(&ip, &remote);
	}
	RETURN_CCTOR(&ip);

}

/**
 * Gets variable from _GET superglobal applying filters if needed.
 * If no parameters are given, return all.
 *
 * <pre><code>
 *  //Returns value from $_GET["id"] without sanitizing
 *  $id = $this->request->getQuery("id");
 *
 *  //Returns value from $_GET["title"] with sanitizing
 *  $title = $this->request->getQuery("title", "escape|repeats");
 *
 *  //Returns value from $_GET["id"] with a default value
 *  $id = $this->request->getQuery("id", null, 150);
 * </code></pre>
 *
 * @param string key Index to get
 * @param string|array filters Filters to apply
 * @param mixed defaultValue Default value if key not exist or value is empty and allowEmpty is false
 * @param boolean allowEmpty
 * @return mixed
 */
PHP_METHOD(Ice_Http_Request, getQuery) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowEmpty;
	zval *key_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *allowEmpty_param = NULL, __$null, _0$$3, _1$$3, _2$$3, _3$$4, _4$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
		Z_PARAM_ZVAL(filters)
		Z_PARAM_ZVAL(defaultValue)
		Z_PARAM_BOOL(allowEmpty)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &key_param, &filters, &defaultValue, &allowEmpty_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!allowEmpty_param) {
		allowEmpty = 1;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	if (!(!(Z_TYPE_P(&key) == IS_UNDEF) && Z_STRLEN_P(&key))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("get"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "_url");
		ZVAL_NULL(&_2$$3);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "set", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("get"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "_url");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "remove", NULL, 0, &_1$$3);
		zephir_check_call_status();
		RETURN_MM_MEMBER(getThis(), "get");
	} else {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("get"), PH_NOISY_CC | PH_READONLY);
		if (allowEmpty) {
			ZVAL_BOOL(&_4$$4, 1);
		} else {
			ZVAL_BOOL(&_4$$4, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_3$$4, "getvalue", NULL, 0, &key, filters, defaultValue, &_4$$4);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * Gets variable from _POST superglobal applying filters if needed.
 * If no parameters are given, return all.
 *
 * <pre><code>
 *  //Returns value from $_POST["id"] without sanitizing
 *  $id = $this->request->getPost("id");
 *
 *  //Returns value from $_POST["title"] with sanitizing
 *  $title = $this->request->getPost("title", "escape|repeats");
 *
 *  //Returns value from $_POST["id"] with a default value
 *  $id = $this->request->getPost("id", null, 150);
 * </code></pre>
 *
 * @param string key Index to get
 * @param string|array filters Filters to apply
 * @param mixed defaultValue Default value if key not exist or value is empty and allowEmpty is false
 * @param boolean allowEmpty
 * @return mixed
 */
PHP_METHOD(Ice_Http_Request, getPost) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowEmpty;
	zval *key_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *allowEmpty_param = NULL, __$null, _0$$4, _1$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
		Z_PARAM_ZVAL(filters)
		Z_PARAM_ZVAL(defaultValue)
		Z_PARAM_BOOL(allowEmpty)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &key_param, &filters, &defaultValue, &allowEmpty_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!allowEmpty_param) {
		allowEmpty = 1;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	if (!(!(Z_TYPE_P(&key) == IS_UNDEF) && Z_STRLEN_P(&key))) {
		RETURN_MM_MEMBER(getThis(), "post");
	} else {
		zephir_read_property(&_0$$4, this_ptr, ZEND_STRL("post"), PH_NOISY_CC | PH_READONLY);
		if (allowEmpty) {
			ZVAL_BOOL(&_1$$4, 1);
		} else {
			ZVAL_BOOL(&_1$$4, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_0$$4, "getvalue", NULL, 0, &key, filters, defaultValue, &_1$$4);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * Gets variable from _SERVER superglobal.
 *
 * @param string key
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Ice_Http_Request, getServer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
		Z_PARAM_ZVAL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &defaultValue);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&key) == IS_UNDEF) && Z_STRLEN_P(&key)) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("server"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_0, &_1, "get", NULL, 0, &key, defaultValue);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("server"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Gets variable from _FILES superglobal.
 *
 * @param string key
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Ice_Http_Request, getFiles) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
		Z_PARAM_ZVAL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &defaultValue);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&key) == IS_UNDEF) && Z_STRLEN_P(&key)) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("files"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_0, &_1, "get", NULL, 0, &key, defaultValue);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("files"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);

}

