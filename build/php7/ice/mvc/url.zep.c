
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * This component allows to create URLs.
 *
 * @package     Ice/Mvc
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2020 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Url) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc, Url, ice, mvc_url, ice_mvc_url_method_entry, 0);

	zend_declare_property_string(ice_mvc_url_ce, SL("baseUri"), "/", ZEND_ACC_PROTECTED);

	zend_declare_property_string(ice_mvc_url_ce, SL("staticUri"), "/", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Url, getBaseUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "baseUri");

}

PHP_METHOD(Ice_Mvc_Url, setBaseUri) {

	zval *baseUri, baseUri_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&baseUri_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &baseUri);



	zephir_update_property_zval(this_ptr, ZEND_STRL("baseUri"), baseUri);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Url, getStaticUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "staticUri");

}

PHP_METHOD(Ice_Mvc_Url, setStaticUri) {

	zval *staticUri, staticUri_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticUri_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &staticUri);



	zephir_update_property_zval(this_ptr, ZEND_STRL("staticUri"), staticUri);
	RETURN_THISW();

}

/**
 * Generates a URL for a static resource.
 *
 * @param string uri
 * @return string
 */
PHP_METHOD(Ice_Mvc_Url, href) {

	unsigned char _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *uri_param = NULL, staticUri, _0, _1;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&staticUri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
		zephir_get_strval(&uri, uri_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("staticUri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_INIT_VAR(&staticUri);
	zephir_fast_trim(&staticUri, &_0, &_1, ZEPHIR_TRIM_RIGHT);
	_2 = ZEPHIR_STRING_OFFSET(&uri, 0);
	if (_2 != '/') {
		zephir_concat_self_str(&staticUri, SL("/"));
	}
	ZEPHIR_CONCAT_VV(return_value, &staticUri, &uri);
	RETURN_MM();

}

/**
 * Alias of the `href` method.
 *
 * @deprecated
 * @see self::href()
 */
PHP_METHOD(Ice_Mvc_Url, getStatic) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
		zephir_get_strval(&uri, uri_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "href", NULL, 0, &uri);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of the `get` method.
 *
 * @see self::get()
 */
PHP_METHOD(Ice_Mvc_Url, rel) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool local;
	zval *uri = NULL, uri_sub, *args = NULL, args_sub, *local_param = NULL, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&args_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &uri, &args, &local_param);

	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}
	if (!args) {
		args = &args_sub;
		args = &__$null;
	}
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}


	if (local) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, uri, args, &_0);
	zephir_check_call_status();
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_bool local, _0, _4$$3, _6$$4, _7$$6;
	zval *uri = NULL, uri_sub, *args = NULL, args_sub, *local_param = NULL, _GET, __$null, queryString, _1$$3, _2$$3, _5$$3, _8$$7, _9$$7, _10$$9, _11$$9, _12$$10, _13$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&args_sub);
	ZVAL_UNDEF(&_GET);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&queryString);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$11);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 0, 3, &uri, &args, &local_param);

	if (!uri) {
		uri = &uri_sub;
		ZEPHIR_CPY_WRT(uri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}
	if (!args) {
		args = &args_sub;
		args = &__$null;
	}
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}


	_0 = !local;
	if (_0) {
		_0 = !(ZEPHIR_IS_EMPTY(uri));
	}
	if (_0) {
		ZVAL_LONG(&_1$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "parse_url", &_3, 78, uri, &_1$$3);
		zephir_check_call_status();
		_4$$3 = ZEPHIR_IS_EMPTY(&_2$$3);
		if (_4$$3) {
			ZVAL_LONG(&_1$$3, 0);
			ZEPHIR_CALL_FUNCTION(&_5$$3, "parse_url", &_3, 78, uri, &_1$$3);
			zephir_check_call_status();
			_4$$3 = ZEPHIR_IS_EMPTY(&_5$$3);
		}
		local = _4$$3;
	}
	if (local) {
		_6$$4 = ZEPHIR_IS_FALSE_IDENTICAL(uri);
		if (_6$$4) {
			_6$$4 = zephir_array_isset_string(&_GET, SL("_url"));
		}
		if (_6$$4) {
			ZEPHIR_OBS_NVAR(uri);
			zephir_array_fetch_string(uri, &_GET, SL("_url"), PH_NOISY, "ice/mvc/url.zep", 76);
		} else {
			_7$$6 = !(zephir_start_with_str(uri, SL("#")));
			if (_7$$6) {
				_7$$6 = !(zephir_start_with_str(uri, SL("?")));
			}
			if (_7$$6) {
				ZEPHIR_CALL_METHOD(&_8$$7, this_ptr, "getbaseuri", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_9$$7);
				ZEPHIR_CONCAT_VV(&_9$$7, &_8$$7, uri);
				ZEPHIR_CPY_WRT(uri, &_9$$7);
			}
		}
	}
	if (zephir_is_true(args)) {
		ZEPHIR_CALL_FUNCTION(&queryString, "http_build_query", NULL, 18, args);
		zephir_check_call_status();
		if (zephir_is_true(&queryString)) {
			ZEPHIR_INIT_VAR(&_10$$9);
			ZVAL_STRING(&_10$$9, "?");
			ZEPHIR_INIT_VAR(&_11$$9);
			zephir_fast_strpos(&_11$$9, uri, &_10$$9, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_11$$9)) {
				ZEPHIR_INIT_VAR(&_12$$10);
				ZEPHIR_CONCAT_SV(&_12$$10, "&", &queryString);
				zephir_concat_self(uri, &_12$$10);
			} else {
				ZEPHIR_INIT_VAR(&_13$$11);
				ZEPHIR_CONCAT_SV(&_13$$11, "?", &queryString);
				zephir_concat_self(uri, &_13$$11);
			}
		}
	}
	RETVAL_ZVAL(uri, 1, 0);
	RETURN_MM();

}

