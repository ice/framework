
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

	zval *staticRouteMap, staticRouteMap_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&staticRouteMap_sub);

	zephir_fetch_params(0, 1, 0, &staticRouteMap);



	zephir_update_property_zval(this_ptr, SL("staticRouteMap"), staticRouteMap);

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setVariableRouteData) {

	zval *variableRouteData, variableRouteData_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&variableRouteData_sub);

	zephir_fetch_params(0, 1, 0, &variableRouteData);



	zephir_update_property_zval(this_ptr, SL("variableRouteData"), variableRouteData);

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setData) {

	zval *data_param = NULL, _0, _1;
	zval data;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
	ZEPHIR_OBS_VAR_ONCE(&data);
	ZVAL_COPY(&data, data_param);
	}


	zephir_array_fetch_long(&_0, &data, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 15 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("staticRouteMap"), &_0);
	zephir_array_fetch_long(&_1, &data, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 16 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("variableRouteData"), &_1);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, dispatchVariableRoute) {

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, dispatch) {

	zend_string *_22, *_26;
	zend_ulong _21, _25;
	zend_bool _1, _4, _13, _23$$9;
	zephir_fcall_cache_entry *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod, httpMethod_sub, *uri, uri_sub, handler, varRouteData, result, allowedMethods, uriMap, method, routeData, _0, _2, _3, _5, _6, _19, *_20, *_24, _7$$3, _8$$3, _9$$3, _10$$4, _11$$4, _12$$4, _14$$5, _16$$5, _17$$7, _18$$7, _27$$11, _28$$14, _29$$15;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&httpMethod_sub);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&varRouteData);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&allowedMethods);
	ZVAL_UNDEF(&uriMap);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_29$$15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpMethod, &uri);



	zephir_read_property(&_0, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, httpMethod);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3, &_2, httpMethod, PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 25 TSRMLS_CC);
		_1 = zephir_array_isset(&_3, uri);
	}
	_4 = ZEPHIR_IS_STRING_IDENTICAL(httpMethod, "HEAD");
	if (_4) {
		zephir_read_property(&_5, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_6, &_5, SL("GET"), PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 28 TSRMLS_CC);
		_4 = zephir_array_isset(&_6, uri);
	}
	if (_1) {
		zephir_read_property(&_7$$3, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_8$$3, &_7$$3, httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 26 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&handler);
		zephir_array_fetch(&handler, &_8$$3, uri, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 26 TSRMLS_CC);
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_LONG(&_9$$3, 1);
		zephir_array_fast_append(return_value, &_9$$3);
		zephir_array_fast_append(return_value, &handler);
		ZEPHIR_INIT_NVAR(&_9$$3);
		array_init(&_9$$3);
		zephir_array_fast_append(return_value, &_9$$3);
		RETURN_MM();
	} else if (_4) {
		zephir_read_property(&_10$$4, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_11$$4, &_10$$4, SL("GET"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 29 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&handler);
		zephir_array_fetch(&handler, &_11$$4, uri, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 29 TSRMLS_CC);
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_12$$4);
		ZVAL_LONG(&_12$$4, 1);
		zephir_array_fast_append(return_value, &_12$$4);
		zephir_array_fast_append(return_value, &handler);
		ZEPHIR_INIT_NVAR(&_12$$4);
		array_init(&_12$$4);
		zephir_array_fast_append(return_value, &_12$$4);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&varRouteData);
	zephir_read_property(&varRouteData, this_ptr, SL("variableRouteData"), PH_NOISY_CC);
	_13 = ZEPHIR_IS_STRING_IDENTICAL(httpMethod, "HEAD");
	if (_13) {
		_13 = zephir_array_isset_string(&varRouteData, SL("GET"));
	}
	if (zephir_array_isset(&varRouteData, httpMethod)) {
		zephir_array_fetch(&_14$$5, &varRouteData, httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 36 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_15, 0, &_14$$5, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_16$$5, &result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 38 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(&_16$$5, 1)) {
			RETURN_CCTOR(result);
		}
	} else if (_13) {
		zephir_array_fetch_string(&_17$$7, &varRouteData, SL("GET"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 42 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_15, 0, &_17$$7, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_18$$7, &result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 44 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(&_18$$7, 1)) {
			RETURN_CCTOR(result);
		}
	}
	ZEPHIR_INIT_VAR(&allowedMethods);
	array_init(&allowedMethods);
	zephir_read_property(&_19, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_19, 0, "ice/mvc/route/dispatcher/regex.zep", 58);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_19), _21, _22, _20)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_22 != NULL) { 
			ZVAL_STR_COPY(&method, _22);
		} else {
			ZVAL_LONG(&method, _21);
		}
		ZEPHIR_INIT_NVAR(&uriMap);
		ZVAL_COPY(&uriMap, _20);
		_23$$9 = !ZEPHIR_IS_IDENTICAL(&method, httpMethod);
		if (_23$$9) {
			_23$$9 = zephir_array_isset(&uriMap, uri);
		}
		if (_23$$9) {
			zephir_array_append(&allowedMethods, &method, PH_SEPARATE, "ice/mvc/route/dispatcher/regex.zep", 54);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&uriMap);
	ZEPHIR_INIT_NVAR(&method);
	zephir_is_iterable(&varRouteData, 0, "ice/mvc/route/dispatcher/regex.zep", 70);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&varRouteData), _25, _26, _24)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_26 != NULL) { 
			ZVAL_STR_COPY(&method, _26);
		} else {
			ZVAL_LONG(&method, _25);
		}
		ZEPHIR_INIT_NVAR(&routeData);
		ZVAL_COPY(&routeData, _24);
		if (ZEPHIR_IS_IDENTICAL(&method, httpMethod)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_15, 0, &routeData, uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_27$$11, &result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 65 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(&_27$$11, 1)) {
			zephir_array_append(&allowedMethods, &method, PH_SEPARATE, "ice/mvc/route/dispatcher/regex.zep", 66);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&routeData);
	ZEPHIR_INIT_NVAR(&method);
	if (zephir_is_true(&allowedMethods)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_28$$14);
		ZVAL_LONG(&_28$$14, 2);
		zephir_array_fast_append(return_value, &_28$$14);
		zephir_array_fast_append(return_value, &allowedMethods);
		RETURN_MM();
	} else {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_29$$15);
		ZVAL_LONG(&_29$$15, 0);
		zephir_array_fast_append(return_value, &_29$$15);
		RETURN_MM();
	}

}

