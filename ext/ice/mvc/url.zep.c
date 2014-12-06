
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Url) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc, Url, ice, mvc_url, ice_mvc_url_method_entry, 0);

	zend_declare_property_string(ice_mvc_url_ce, SL("_baseUri"), "/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_url_ce, SL("_staticUri"), "/", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Url, getBaseUri) {


	RETURN_MEMBER(this_ptr, "_baseUri");

}

PHP_METHOD(Ice_Mvc_Url, setBaseUri) {

	zval *baseUri;

	zephir_fetch_params(0, 1, 0, &baseUri);



	zephir_update_property_this(this_ptr, SL("_baseUri"), baseUri TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Url, getStaticUri) {


	RETURN_MEMBER(this_ptr, "_staticUri");

}

PHP_METHOD(Ice_Mvc_Url, setStaticUri) {

	zval *staticUri;

	zephir_fetch_params(0, 1, 0, &staticUri);



	zephir_update_property_this(this_ptr, SL("_staticUri"), staticUri TSRMLS_CC);

}

/**
 * Generates a URL for a static resource
 *
 * @param string uri
 * @return string
 */
PHP_METHOD(Ice_Mvc_Url, getStatic) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *_0 = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	} else {
		zephir_get_strval(uri, uri_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getstaticuri", NULL);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, _0, uri);
	RETURN_MM();

}

/**
 * Generates a URL
 *
 * @param string uri
 * @param array|object args Optional arguments to be appended to the query string
 * @param bool local
 * @return string
 */
PHP_METHOD(Ice_Mvc_Url, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_5 = NULL, *_8 = NULL;
	zend_bool local, _9;
	zval *uri = NULL, *args = NULL, *local_param = NULL, *baseUri = NULL, *matched = NULL, *queryString = NULL, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, *_6 = NULL, *_7 = NULL, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &uri, &args, &local_param);

	if (!uri) {
		ZEPHIR_CPY_WRT(uri, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}
	if (!args) {
		args = ZEPHIR_GLOBAL(global_null);
	}
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}


	if (!(local)) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "://", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strstr", &_2, uri, &_0);
		zephir_check_call_status();
		if (zephir_is_true(_1)) {
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "/^[^:\\/?#]++:/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&matched, "preg_match", &_4, _3, uri);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			if (zephir_is_true(matched)) {
				local = 0;
			} else {
				local = 1;
			}
		} else {
			local = 1;
		}
	}
	ZEPHIR_CALL_METHOD(&baseUri, this_ptr, "getbaseuri", NULL);
	zephir_check_call_status();
	if (local) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(uri)) {
			ZEPHIR_CALL_CE_STATIC(&_1, ice_di_ce, "fetch", &_5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6, _1, "getrequest", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "_url", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&uri, _6, "get", NULL, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_7);
			ZEPHIR_CONCAT_VV(_7, baseUri, uri);
			ZEPHIR_CPY_WRT(uri, _7);
		}
	}
	if (zephir_is_true(args)) {
		ZEPHIR_CALL_FUNCTION(&queryString, "http_build_query", &_8, args);
		zephir_check_call_status();
		_9 = Z_TYPE_P(queryString) == IS_STRING;
		if (_9) {
			_9 = (zephir_fast_strlen_ev(queryString)) ? 1 : 0;
		}
		if (_9) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "?", 0);
			ZEPHIR_INIT_NVAR(_3);
			zephir_fast_strpos(_3, queryString, &_0, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SV(_7, "&", queryString);
				zephir_concat_self(&uri, _7 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(_10);
				ZEPHIR_CONCAT_SV(_10, "?", queryString);
				zephir_concat_self(&uri, _10 TSRMLS_CC);
			}
		}
	}
	RETVAL_ZVAL(uri, 1, 0);
	RETURN_MM();

}

