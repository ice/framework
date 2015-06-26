
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
#include "kernel/array.h"


/**
 * This component allows to create URLs.
 *
 * @package     Ice/Mvc
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
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
 * Generates a URL for a static resource.
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getstaticuri", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, _0, uri);
	RETURN_MM();

}

/**
 * Generates a URL.
 *
 * @param string uri
 * @param array|object args Optional arguments to be appended to the query string
 * @param bool local
 * @return string
 */
PHP_METHOD(Ice_Mvc_Url, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool local, _3;
	zval *uri = NULL, *args = NULL, *local_param = NULL, *baseUri = NULL, *matched, *queryString = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2, *_GET, *_4 = NULL, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
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
		ZEPHIR_CALL_FUNCTION(&_1, "strstr", NULL, 65, uri, &_0);
		zephir_check_call_status();
		if (zephir_is_true(_1)) {
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "/^[^:\\/?#]++:/", 0);
			ZEPHIR_INIT_VAR(matched);
			zephir_preg_match(matched, &_0, uri, _2, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(matched)) {
				local = 0;
			} else {
				local = 1;
			}
		} else {
			local = 1;
		}
	}
	ZEPHIR_CALL_METHOD(&baseUri, this_ptr, "getbaseuri", NULL, 0);
	zephir_check_call_status();
	if (local) {
		_3 = ZEPHIR_IS_FALSE_IDENTICAL(uri);
		if (_3) {
			_3 = zephir_array_isset_string(_GET, SS("_url"));
		}
		if (_3) {
			ZEPHIR_OBS_NVAR(uri);
			zephir_array_fetch_string(&uri, _GET, SL("_url"), PH_NOISY, "ice/mvc/url.zep", 62 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_VV(_4, baseUri, uri);
			ZEPHIR_CPY_WRT(uri, _4);
		}
	}
	if (zephir_is_true(args)) {
		ZEPHIR_CALL_FUNCTION(&queryString, "http_build_query", NULL, 19, args);
		zephir_check_call_status();
		_3 = Z_TYPE_P(queryString) == IS_STRING;
		if (_3) {
			_3 = (zephir_fast_strlen_ev(queryString)) ? 1 : 0;
		}
		if (_3) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "?", 0);
			ZEPHIR_INIT_VAR(_5);
			zephir_fast_strpos(_5, queryString, &_0, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(_5)) {
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "&", queryString);
				zephir_concat_self(&uri, _4 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(_6);
				ZEPHIR_CONCAT_SV(_6, "?", queryString);
				zephir_concat_self(&uri, _6 TSRMLS_CC);
			}
		}
	}
	RETVAL_ZVAL(uri, 1, 0);
	RETURN_MM();

}

