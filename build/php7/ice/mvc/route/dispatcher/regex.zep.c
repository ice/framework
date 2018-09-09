
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


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_Regex) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route\\Dispatcher, Regex, ice, mvc_route_dispatcher_regex, ice_mvc_route_dispatcher_regex_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_route_dispatcher_regex_ce, SL("staticRouteMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_dispatcher_regex_ce, SL("variableRouteData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_mvc_route_dispatcher_regex_ce TSRMLS_CC, 1, ice_mvc_route_dispatcher_dispatcherinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setStaticRouteMap) {

	zval *staticRouteMap, staticRouteMap_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticRouteMap_sub);

	zephir_fetch_params(0, 1, 0, &staticRouteMap);



	zephir_update_property_zval(this_ptr, SL("staticRouteMap"), staticRouteMap);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setVariableRouteData) {

	zval *variableRouteData, variableRouteData_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variableRouteData_sub);

	zephir_fetch_params(0, 1, 0, &variableRouteData);



	zephir_update_property_zval(this_ptr, SL("variableRouteData"), variableRouteData);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setData) {

	zval *data_param = NULL, _0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
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

	zend_string *_27, *_31;
	zend_ulong _26, _30;
	zend_bool _1, _28$$13;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod_param = NULL, *uri_param = NULL, handler, varRouteData, result, allowedMethods, uriMap, method, routeData, _0, _2, _3, _17, _18, _24, *_25, *_29, _4$$3, _5$$3, _6$$3, _7$$4, _9$$4, _10$$6, _11$$6, _12$$7, _13$$7, _14$$7, _15$$8, _16$$8, _19$$10, _20$$10, _21$$10, _22$$11, _23$$11, _32$$15, _33$$18, _34$$19;
	zval httpMethod, uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethod);
	ZVAL_UNDEF(&uri);
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
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_33$$18);
	ZVAL_UNDEF(&_34$$19);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpMethod_param, &uri_param);

	zephir_get_strval(&httpMethod, httpMethod_param);
	zephir_get_strval(&uri, uri_param);


	zephir_read_property(&_0, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, &httpMethod);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3, &_2, &httpMethod, PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 25 TSRMLS_CC);
		_1 = zephir_array_isset(&_3, &uri);
	}
	if (_1) {
		zephir_read_property(&_4$$3, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_5$$3, &_4$$3, &httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 26 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&handler);
		zephir_array_fetch(&handler, &_5$$3, &uri, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 26 TSRMLS_CC);
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_LONG(&_6$$3, 1);
		zephir_array_fast_append(return_value, &_6$$3);
		zephir_array_fast_append(return_value, &handler);
		ZEPHIR_INIT_NVAR(&_6$$3);
		array_init(&_6$$3);
		zephir_array_fast_append(return_value, &_6$$3);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&varRouteData);
	zephir_read_property(&varRouteData, this_ptr, SL("variableRouteData"), PH_NOISY_CC);
	if (zephir_array_isset(&varRouteData, &httpMethod)) {
		zephir_array_fetch(&_7$$4, &varRouteData, &httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 33 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_8, 0, &_7$$4, &uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_9$$4, &result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 35 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(&_9$$4, 1)) {
			RETURN_CCTOR(&result);
		}
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&httpMethod, "HEAD")) {
		zephir_read_property(&_10$$6, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_11$$6, &_10$$6, SL("GET"), PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 42 TSRMLS_CC);
		if (zephir_array_isset(&_11$$6, &uri)) {
			zephir_read_property(&_12$$7, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_13$$7, &_12$$7, SL("GET"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 43 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch(&handler, &_13$$7, &uri, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 43 TSRMLS_CC);
			zephir_create_array(return_value, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_14$$7);
			ZVAL_LONG(&_14$$7, 1);
			zephir_array_fast_append(return_value, &_14$$7);
			zephir_array_fast_append(return_value, &handler);
			ZEPHIR_INIT_NVAR(&_14$$7);
			array_init(&_14$$7);
			zephir_array_fast_append(return_value, &_14$$7);
			RETURN_MM();
		}
		if (zephir_array_isset_string(&varRouteData, SL("GET"))) {
			zephir_array_fetch_string(&_15$$8, &varRouteData, SL("GET"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 48 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_8, 0, &_15$$8, &uri);
			zephir_check_call_status();
			zephir_array_fetch_long(&_16$$8, &result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 50 TSRMLS_CC);
			if (ZEPHIR_IS_LONG_IDENTICAL(&_16$$8, 1)) {
				RETURN_CCTOR(&result);
			}
		}
	}
	zephir_read_property(&_17, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_18, &_17, SL("*"), PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 57 TSRMLS_CC);
	if (zephir_array_isset(&_18, &uri)) {
		zephir_read_property(&_19$$10, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_20$$10, &_19$$10, SL("*"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 58 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&handler);
		zephir_array_fetch(&handler, &_20$$10, &uri, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 58 TSRMLS_CC);
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_21$$10);
		ZVAL_LONG(&_21$$10, 1);
		zephir_array_fast_append(return_value, &_21$$10);
		zephir_array_fast_append(return_value, &handler);
		ZEPHIR_INIT_NVAR(&_21$$10);
		array_init(&_21$$10);
		zephir_array_fast_append(return_value, &_21$$10);
		RETURN_MM();
	}
	if (zephir_array_isset_string(&varRouteData, SL("*"))) {
		zephir_array_fetch_string(&_22$$11, &varRouteData, SL("*"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 63 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_8, 0, &_22$$11, &uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_23$$11, &result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 65 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(&_23$$11, 1)) {
			RETURN_CCTOR(&result);
		}
	}
	ZEPHIR_INIT_VAR(&allowedMethods);
	array_init(&allowedMethods);
	zephir_read_property(&_24, this_ptr, SL("staticRouteMap"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_24, 0, "ice/mvc/route/dispatcher/regex.zep", 79);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_24), _26, _27, _25)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_27 != NULL) { 
			ZVAL_STR_COPY(&method, _27);
		} else {
			ZVAL_LONG(&method, _26);
		}
		ZEPHIR_INIT_NVAR(&uriMap);
		ZVAL_COPY(&uriMap, _25);
		_28$$13 = !ZEPHIR_IS_IDENTICAL(&method, &httpMethod);
		if (_28$$13) {
			_28$$13 = zephir_array_isset(&uriMap, &uri);
		}
		if (_28$$13) {
			zephir_array_append(&allowedMethods, &method, PH_SEPARATE, "ice/mvc/route/dispatcher/regex.zep", 75);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&uriMap);
	ZEPHIR_INIT_NVAR(&method);
	zephir_is_iterable(&varRouteData, 0, "ice/mvc/route/dispatcher/regex.zep", 91);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&varRouteData), _30, _31, _29)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_31 != NULL) { 
			ZVAL_STR_COPY(&method, _31);
		} else {
			ZVAL_LONG(&method, _30);
		}
		ZEPHIR_INIT_NVAR(&routeData);
		ZVAL_COPY(&routeData, _29);
		if (ZEPHIR_IS_IDENTICAL(&method, &httpMethod)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_8, 0, &routeData, &uri);
		zephir_check_call_status();
		zephir_array_fetch_long(&_32$$15, &result, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 86 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(&_32$$15, 1)) {
			zephir_array_append(&allowedMethods, &method, PH_SEPARATE, "ice/mvc/route/dispatcher/regex.zep", 87);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&routeData);
	ZEPHIR_INIT_NVAR(&method);
	if (zephir_is_true(&allowedMethods)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_33$$18);
		ZVAL_LONG(&_33$$18, 2);
		zephir_array_fast_append(return_value, &_33$$18);
		zephir_array_fast_append(return_value, &allowedMethods);
		RETURN_MM();
	} else {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_34$$19);
		ZVAL_LONG(&_34$$19, 0);
		zephir_array_fast_append(return_value, &_34$$19);
		RETURN_MM();
	}

}

