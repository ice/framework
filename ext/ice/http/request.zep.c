
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
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Http_Request) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Http, Request, ice, http_request, ice_arr_ce, ice_http_request_method_entry, 0);

	zend_declare_property_null(ice_http_request_ce, SL("files"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_request_ce, SL("get"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_request_ce, SL("post"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_request_ce, SL("server"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Request constructor. Fetch data from globals variables: _REQUEST, _SERVER, _POST, _GET and _FILES.
 */
PHP_METHOD(Ice_Http_Request, __construct) {

	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_FILES, *_2, *_GET, *_3, *_POST, *_4, *_SERVER, *_REQUEST;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_1, 6, _FILES);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("files"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_1, 6, _GET);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("get"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_1, 6, _POST);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("post"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_1, 6, _SERVER);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("server"), _4 TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, ice_http_request_ce, this_ptr, "__construct", &_5, 6, _REQUEST);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, name);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("post"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "has", NULL, 0, name);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("get"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "has", NULL, 0, name);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "has", NULL, 0, name);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("files"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "has", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks whether HTTP method is POST.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isPost) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "POST"));

}

/**
 * Checks whether HTTP method is GET.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "GET"));

}

/**
 * Checks whether HTTP method is PUT.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isPut) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "PUT"));

}

/**
 * Checks whether HTTP method is PATCH.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isPatch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "PATCH"));

}

/**
 * Checks whether HTTP method is HEAD.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isHead) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "HEAD"));

}

/**
 * Checks whether HTTP method is DELETE.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "DELETE"));

}

/**
 * Checks whether HTTP method is OPTIONS.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "OPTIONS"));

}

/**
 * Checks whether request has been made using AJAX.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Http_Request, isAjax) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "HTTP_X_REQUESTED_WITH", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_1, "XMLHttpRequest"));

}

/**
 * Gets HTTP method which request has been made.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Request, getMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "REQUEST_METHOD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets HTTP user agent used to made the request.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Request, getUserAgent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "HTTP_USER_AGENT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets web page that refers active request.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Request, getHTTPReferer) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "HTTP_REFERER", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets most possible client IPv4 Address.
 *
 * @return string
 */
PHP_METHOD(Ice_Http_Request, getClientAddress) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *client = NULL, *forward = NULL, *remote = NULL, *ip = NULL, *_0, *_1 = NULL, *_2, *_3, _4 = zval_used_for_init, *_5 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "HTTP_CLIENT_IP", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&client, _0, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "HTTP_X_FORWARDED_FOR", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&forward, _2, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "REMOTE_ADDR", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&remote, _3, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 275);
	ZEPHIR_CALL_FUNCTION(&_5, "filter_var", NULL, 104, client, &_4);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 275);
	ZEPHIR_CALL_FUNCTION(&_6, "filter_var", NULL, 104, forward, &_4);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_CPY_WRT(ip, client);
	} else if (zephir_is_true(_6)) {
		ZEPHIR_CPY_WRT(ip, forward);
	} else {
		ZEPHIR_CPY_WRT(ip, remote);
	}
	RETURN_CCTOR(ip);

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

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowEmpty, _8, _9;
	zval *key_param = NULL, *filters = NULL, *defaultValue = NULL, *allowEmpty_param = NULL, *value = NULL, *filter = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_6, *_7 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &key_param, &filters, &defaultValue, &allowEmpty_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
		zephir_get_strval(key, key_param);
	}
	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!allowEmpty_param) {
		allowEmpty = 0;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	if (!(!(!key) && Z_STRLEN_P(key))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("get"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "_url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_NULL(_2);
		ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, _1, _2);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("get"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "_url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3, "remove", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		RETURN_MM_MEMBER(this_ptr, "get");
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("get"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&value, _0, "get", NULL, 0, key, defaultValue);
		zephir_check_call_status();
		if (zephir_is_true(filters)) {
			ZEPHIR_CALL_CE_STATIC(&_4, ice_di_ce, "fetch", &_5, 8);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "filter", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_NULL(_2);
			ZEPHIR_INIT_VAR(_6);
			ZVAL_BOOL(_6, 1);
			ZEPHIR_CALL_METHOD(&filter, _4, "get", NULL, 0, _1, _2, _6);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7, filter, "sanitize", NULL, 0, value, filters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _7);
		}
		_8 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
		if (!(_8)) {
			_8 = Z_TYPE_P(value) == IS_NULL;
		}
		_9 = _8;
		if (_9) {
			_9 = allowEmpty == 0;
		}
		if (_9) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		RETURN_CCTOR(value);
	}
	ZEPHIR_MM_RESTORE();

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

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowEmpty, _7, _8;
	zval *key_param = NULL, *filters = NULL, *defaultValue = NULL, *allowEmpty_param = NULL, *value = NULL, *filter = NULL, *_0, *_1 = NULL, *_3, *_4, *_5, *_6 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &key_param, &filters, &defaultValue, &allowEmpty_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
		zephir_get_strval(key, key_param);
	}
	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!allowEmpty_param) {
		allowEmpty = 0;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	if (!(!(!key) && Z_STRLEN_P(key))) {
		RETURN_MM_MEMBER(this_ptr, "post");
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("post"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&value, _0, "get", NULL, 0, key, defaultValue);
		zephir_check_call_status();
		if (zephir_is_true(filters)) {
			ZEPHIR_CALL_CE_STATIC(&_1, ice_di_ce, "fetch", &_2, 8);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "filter", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_4);
			ZVAL_NULL(_4);
			ZEPHIR_INIT_VAR(_5);
			ZVAL_BOOL(_5, 1);
			ZEPHIR_CALL_METHOD(&filter, _1, "get", NULL, 0, _3, _4, _5);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6, filter, "sanitize", NULL, 0, value, filters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _6);
		}
		_7 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
		if (!(_7)) {
			_7 = Z_TYPE_P(value) == IS_NULL;
		}
		_8 = _7;
		if (_8) {
			_8 = allowEmpty == 0;
		}
		if (_8) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		RETURN_CCTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets variable from _SERVER superglobal.
 *
 * @param string key
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Ice_Http_Request, getServer) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, *_0 = NULL, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &defaultValue);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
		zephir_get_strval(key, key_param);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	if (!(!key) && Z_STRLEN_P(key)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("server"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, _1, "get", NULL, 0, key, defaultValue);
		zephir_check_call_status();
	} else {
		zephir_read_property_this(&_0, this_ptr, SL("server"), PH_NOISY_CC);
	}
	RETURN_CCTOR(_0);

}

/**
 * Gets variable from _FILES superglobal.
 *
 * @param string key
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Ice_Http_Request, getFiles) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, *_0 = NULL, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &defaultValue);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
		zephir_get_strval(key, key_param);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	if (!(!key) && Z_STRLEN_P(key)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("files"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, _1, "get", NULL, 0, key, defaultValue);
		zephir_check_call_status();
	} else {
		zephir_read_property_this(&_0, this_ptr, SL("files"), PH_NOISY_CC);
	}
	RETURN_CCTOR(_0);

}

