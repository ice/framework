
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_Regex) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route\\Dispatcher, Regex, ice, mvc_route_dispatcher_regex, ice_mvc_route_dispatcher_regex_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_route_dispatcher_regex_ce, SL("staticRouteMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_dispatcher_regex_ce, SL("variableRouteData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_mvc_route_dispatcher_regex_ce TSRMLS_CC, 1, ice_mvc_route_dispatcher_dispatcherinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setStaticRouteMap) {

	zval *staticRouteMap;

	zephir_fetch_params(0, 1, 0, &staticRouteMap);



	zephir_update_property_this(this_ptr, SL("staticRouteMap"), staticRouteMap TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setVariableRouteData) {

	zval *variableRouteData;

	zephir_fetch_params(0, 1, 0, &variableRouteData);



	zephir_update_property_this(this_ptr, SL("variableRouteData"), variableRouteData TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setData) {

	zval *data_param = NULL, *_0, *_1;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
	data = data_param;
	}


	zephir_array_fetch_long(&_0, data, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 15 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("staticRouteMap"), _0 TSRMLS_CC);
	zephir_array_fetch_long(&_1, data, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 16 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("variableRouteData"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, dispatchVariableRoute) {

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, dispatch) {

	HashTable *_14, *_18;
	HashPosition _13, _17;
	zephir_fcall_cache_entry *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1, _4, _10, _16;
	zval *httpMethod, *uri, *handler = NULL, *varRouteData = NULL, *result = NULL, *allowedMethods = NULL, *uriMap = NULL, *method = NULL, *routeData = NULL, *_0, *_2, *_3, *_5, *_6, *_7, *_8, *_9 = NULL, *_12, **_15, **_19;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpMethod, &uri);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
	_1 = zephir_array_isset(_0, httpMethod);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
		zephir_array_fetch(&_3, _2, httpMethod, PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 25 TSRMLS_CC);
		_1 = zephir_array_isset(_3, uri);
	}
	_4 = ZEPHIR_IS_STRING_IDENTICAL(httpMethod, "HEAD");
	if (_4) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
		zephir_array_fetch_string(&_6, _5, SL("GET"), PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 28 TSRMLS_CC);
		_4 = zephir_array_isset(_6, uri);
	}
	if (_1) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
		zephir_array_fetch(&_8, _7, httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 26 TSRMLS_CC);
		ZEPHIR_OBS_VAR(handler);
		zephir_array_fetch(&handler, _8, uri, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 26 TSRMLS_CC);
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9);
		ZVAL_LONG(_9, 1);
		zephir_array_fast_append(return_value, _9);
		zephir_array_fast_append(return_value, handler);
		ZEPHIR_INIT_NVAR(_9);
		array_init(_9);
		zephir_array_fast_append(return_value, _9);
		RETURN_MM();
	} else if (_4) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
		zephir_array_fetch_string(&_8, _7, SL("GET"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 29 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(handler);
		zephir_array_fetch(&handler, _8, uri, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 29 TSRMLS_CC);
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, 1);
		zephir_array_fast_append(return_value, _9);
		zephir_array_fast_append(return_value, handler);
		ZEPHIR_INIT_NVAR(_9);
		array_init(_9);
		zephir_array_fast_append(return_value, _9);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(varRouteData);
	zephir_read_property_this(&varRouteData, this_ptr, SL("variableRouteData"), PH_NOISY_CC);
	_10 = ZEPHIR_IS_STRING_IDENTICAL(httpMethod, "HEAD");
	if (_10) {
		_10 = zephir_array_isset_string(varRouteData, SS("GET"));
	}
	if (zephir_array_isset(varRouteData, httpMethod)) {
		zephir_array_fetch(&_8, varRouteData, httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 36 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_11, 0, _8, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_12, result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 38 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(_12, 1)) {
			RETURN_CCTOR(result);
		}
	} else if (_10) {
		zephir_array_fetch_string(&_8, varRouteData, SL("GET"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 42 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_11, 0, _8, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_12, result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 44 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(_12, 1)) {
			RETURN_CCTOR(result);
		}
	}
	ZEPHIR_INIT_VAR(allowedMethods);
	array_init(allowedMethods);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("staticRouteMap"), PH_NOISY_CC);
	zephir_is_iterable(_7, &_14, &_13, 0, 0, "ice/mvc/route/dispatcher/regex.zep", 58);
	for (
	  ; zephir_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
	  ; zephir_hash_move_forward_ex(_14, &_13)
	) {
		ZEPHIR_GET_HMKEY(method, _14, _13);
		ZEPHIR_GET_HVALUE(uriMap, _15);
		_16 = !ZEPHIR_IS_IDENTICAL(method, httpMethod);
		if (_16) {
			_16 = zephir_array_isset(uriMap, uri);
		}
		if (_16) {
			zephir_array_append(&allowedMethods, method, PH_SEPARATE, "ice/mvc/route/dispatcher/regex.zep", 54);
		}
	}
	zephir_is_iterable(varRouteData, &_18, &_17, 0, 0, "ice/mvc/route/dispatcher/regex.zep", 70);
	for (
	  ; zephir_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS
	  ; zephir_hash_move_forward_ex(_18, &_17)
	) {
		ZEPHIR_GET_HMKEY(method, _18, _17);
		ZEPHIR_GET_HVALUE(routeData, _19);
		if (ZEPHIR_IS_IDENTICAL(method, httpMethod)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_11, 0, routeData, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_8, result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 65 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(_8, 1)) {
			zephir_array_append(&allowedMethods, method, PH_SEPARATE, "ice/mvc/route/dispatcher/regex.zep", 66);
		}
	}
	if (zephir_is_true(allowedMethods)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, 2);
		zephir_array_fast_append(return_value, _9);
		zephir_array_fast_append(return_value, allowedMethods);
		RETURN_MM();
	} else {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, 0);
		zephir_array_fast_append(return_value, _9);
		RETURN_MM();
	}

}

