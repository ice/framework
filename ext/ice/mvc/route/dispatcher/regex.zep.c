
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_Regex) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route\\Dispatcher, Regex, ice, mvc_route_dispatcher_regex, ice_mvc_route_dispatcher_regex_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_route_dispatcher_regex_ce, SL("_staticRouteMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_dispatcher_regex_ce, SL("_variableRouteData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_mvc_route_dispatcher_regex_ce TSRMLS_CC, 1, ice_mvc_route_dispatcher_dispatcherinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setStaticRouteMap) {

	zval *staticRouteMap;

	zephir_fetch_params(0, 1, 0, &staticRouteMap);



	zephir_update_property_this(this_ptr, SL("_staticRouteMap"), staticRouteMap TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setVariableRouteData) {

	zval *variableRouteData;

	zephir_fetch_params(0, 1, 0, &variableRouteData);



	zephir_update_property_this(this_ptr, SL("_variableRouteData"), variableRouteData TSRMLS_CC);

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
	zephir_update_property_this(this_ptr, SL("_staticRouteMap"), _0 TSRMLS_CC);
	zephir_array_fetch_long(&_1, data, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 16 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_variableRouteData"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, dispatchVariableRoute) {

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, dispatch) {

	zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_5;
	HashPosition _4;
	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod, *uri, *varRouteData, *result = NULL, *allowedMethods, *method = NULL, *routeData = NULL, *_0, *_2, *_3, **_6, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpMethod, &uri);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_staticRouteMap"), PH_NOISY_CC);
	if (zephir_array_isset(_0, uri)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dispatchstaticroute", NULL, httpMethod, uri);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(varRouteData);
	zephir_read_property_this(&varRouteData, this_ptr, SL("_variableRouteData"), PH_NOISY_CC);
	_1 = ZEPHIR_IS_STRING_IDENTICAL(httpMethod, "HEAD");
	if (_1) {
		_1 = zephir_array_isset_string(varRouteData, SS("GET"));
	}
	if (zephir_array_isset(varRouteData, httpMethod)) {
		zephir_array_fetch(&_2, varRouteData, httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 32 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", NULL, _2, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_3, result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 34 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(_3, 1)) {
			RETURN_CCTOR(result);
		}
	} else if (_1) {
		zephir_array_fetch_string(&_2, varRouteData, SL("GET"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 38 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", NULL, _2, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_3, result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 40 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(_3, 1)) {
			RETURN_CCTOR(result);
		}
	}
	ZEPHIR_INIT_VAR(allowedMethods);
	array_init(allowedMethods);
	zephir_is_iterable(varRouteData, &_5, &_4, 0, 0, "ice/mvc/route/dispatcher/regex.zep", 61);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(method, _5, _4);
		ZEPHIR_GET_HVALUE(routeData, _6);
		if (ZEPHIR_IS_IDENTICAL(method, httpMethod)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_7, routeData, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_2, result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 56 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(_2, 1)) {
			zephir_array_append(&allowedMethods, method, PH_SEPARATE, "ice/mvc/route/dispatcher/regex.zep", 57);
		}
	}
	if (zephir_is_true(allowedMethods)) {
		array_init_size(return_value, 3);
		ZEPHIR_INIT_VAR(_8);
		ZVAL_LONG(_8, 2);
		zephir_array_fast_append(return_value, _8);
		zephir_array_fast_append(return_value, allowedMethods);
		RETURN_MM();
	} else {
		array_init_size(return_value, 2);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, 0);
		zephir_array_fast_append(return_value, _8);
		RETURN_MM();
	}

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, dispatchStaticRoute) {

	zend_bool _1;
	zval *httpMethod, *uri, *routes, *_0, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpMethod, &uri);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_staticRouteMap"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(routes);
	zephir_array_fetch(&routes, _0, uri, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 72 TSRMLS_CC);
	_1 = ZEPHIR_IS_STRING_IDENTICAL(httpMethod, "HEAD");
	if (_1) {
		_1 = zephir_array_isset_string(routes, SS("GET"));
	}
	if (zephir_array_isset(routes, httpMethod)) {
		array_init_size(return_value, 4);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 1);
		zephir_array_fast_append(return_value, _2);
		ZEPHIR_OBS_VAR(_3);
		zephir_array_fetch(&_3, routes, httpMethod, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 75 TSRMLS_CC);
		zephir_array_fast_append(return_value, _3);
		ZEPHIR_INIT_NVAR(_2);
		array_init(_2);
		zephir_array_fast_append(return_value, _2);
		RETURN_MM();
	} else if (_1) {
		array_init_size(return_value, 4);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 1);
		zephir_array_fast_append(return_value, _2);
		ZEPHIR_OBS_NVAR(_3);
		zephir_array_fetch_string(&_3, routes, SL("GET"), PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 77 TSRMLS_CC);
		zephir_array_fast_append(return_value, _3);
		ZEPHIR_INIT_NVAR(_2);
		array_init(_2);
		zephir_array_fast_append(return_value, _2);
		RETURN_MM();
	} else {
		array_init_size(return_value, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 2);
		zephir_array_fast_append(return_value, _2);
		ZEPHIR_INIT_NVAR(_2);
		zephir_array_keys(_2, routes TSRMLS_CC);
		zephir_array_fast_append(return_value, _2);
		RETURN_MM();
	}

}

