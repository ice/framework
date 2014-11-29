
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


ZEPHIR_INIT_CLASS(Ice_Http_Request) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Http, Request, ice, http_request, ice_arr_ce, ice_http_request_method_entry, 0);

	zend_declare_property_null(ice_http_request_ce, SL("_files"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_request_ce, SL("_get"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_request_ce, SL("_post"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_http_request_ce, SL("_server"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Http_Request, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_FILES, *_2, *_GET, *_3, *_POST, *_4, *_SERVER, *_REQUEST;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, ice_arr_ce);
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_1, _FILES);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_files"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, ice_arr_ce);
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_1, _GET);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_get"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, ice_arr_ce);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_1, _POST);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_post"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, ice_arr_ce);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_1, _SERVER);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_server"), _4 TSRMLS_CC);
	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, ice_http_request_ce, this_ptr, "__construct", &_5, _REQUEST);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, name);
	zephir_check_call_status();
	RETURN_MM();

}

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_post"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "has", NULL, name);
	zephir_check_call_status();
	RETURN_MM();

}

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_get"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "has", NULL, name);
	zephir_check_call_status();
	RETURN_MM();

}

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_server"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "has", NULL, name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Http_Request, isPost) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "POST"));

}

PHP_METHOD(Ice_Http_Request, isGet) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "GET"));

}

PHP_METHOD(Ice_Http_Request, isPut) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "PUT"));

}

PHP_METHOD(Ice_Http_Request, isPatch) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "PATCH"));

}

PHP_METHOD(Ice_Http_Request, isHead) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "HEAD"));

}

PHP_METHOD(Ice_Http_Request, isDelete) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "DELETE"));

}

PHP_METHOD(Ice_Http_Request, isOptions) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "OPTIONS"));

}

PHP_METHOD(Ice_Http_Request, isAjax) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_server"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "HTTP_X_REQUESTED_WITH", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_1, "XMLHttpRequest"));

}

PHP_METHOD(Ice_Http_Request, getMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_server"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "REQUEST_METHOD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Http_Request, getUserAgent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_server"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "HTTP_USER_AGENT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Http_Request, getHTTPReferer) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_server"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "HTTP_REFERER", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Http_Request, getClientAddress) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *client = NULL, *forward = NULL, *remote = NULL, *ip = NULL, *_0, *_1 = NULL, *_2, *_3, _4 = zval_used_for_init, *_5 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_server"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "HTTP_CLIENT_IP", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&client, _0, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_server"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "HTTP_X_FORWARDED_FOR", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&forward, _2, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_server"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "REMOTE_ADDR", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&remote, _3, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 275);
	ZEPHIR_CALL_FUNCTION(&_5, "filter_var", NULL, client, &_4);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 275);
	ZEPHIR_CALL_FUNCTION(&_6, "filter_var", NULL, forward, &_4);
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

PHP_METHOD(Ice_Http_Request, getGet) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowEmpty, _4, _5;
	zval *key_param = NULL, *filters = NULL, *defaultValue = NULL, *allowEmpty_param = NULL, *value = NULL, *filter = NULL, *_0, *_1 = NULL, *_3 = NULL;
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


	if (!(key && Z_STRLEN_P(key))) {
		RETURN_MM_MEMBER(this_ptr, "_get");
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_get"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&value, _0, "get", NULL, key, defaultValue);
		zephir_check_call_status();
		if (zephir_is_true(filters)) {
			ZEPHIR_CALL_CE_STATIC(&_1, ice_di_ce, "fetch", &_2);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&filter, _1, "getfilter", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_3, filter, "sanitize", NULL, value, filters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _3);
		}
		_4 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
		if (!(_4)) {
			_4 = Z_TYPE_P(value) == IS_NULL;
		}
		_5 = _4;
		if (_5) {
			_5 = allowEmpty == 0;
		}
		if (_5) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		RETURN_CCTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Http_Request, getPost) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowEmpty, _4, _5;
	zval *key_param = NULL, *filters = NULL, *defaultValue = NULL, *allowEmpty_param = NULL, *value = NULL, *filter = NULL, *_0, *_1 = NULL, *_3 = NULL;
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


	if (!(key && Z_STRLEN_P(key))) {
		RETURN_MM_MEMBER(this_ptr, "_post");
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_post"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&value, _0, "get", NULL, key, defaultValue);
		zephir_check_call_status();
		if (zephir_is_true(filters)) {
			ZEPHIR_CALL_CE_STATIC(&_1, ice_di_ce, "fetch", &_2);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&filter, _1, "getfilter", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_3, filter, "sanitize", NULL, value, filters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _3);
		}
		_4 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
		if (!(_4)) {
			_4 = Z_TYPE_P(value) == IS_NULL;
		}
		_5 = _4;
		if (_5) {
			_5 = allowEmpty == 0;
		}
		if (_5) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		RETURN_CCTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

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
	if (key && Z_STRLEN_P(key)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_server"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, _1, "get", NULL, key, defaultValue);
		zephir_check_call_status();
	} else {
		zephir_read_property_this(&_0, this_ptr, SL("_server"), PH_NOISY_CC);
	}
	RETURN_CCTOR(_0);

}

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
	if (key && Z_STRLEN_P(key)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_files"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, _1, "get", NULL, key, defaultValue);
		zephir_check_call_status();
	} else {
		zephir_read_property_this(&_0, this_ptr, SL("_files"), PH_NOISY_CC);
	}
	RETURN_CCTOR(_0);

}

