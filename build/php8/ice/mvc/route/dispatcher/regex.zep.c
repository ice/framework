
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
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_Regex)
{
	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route\\Dispatcher, Regex, ice, mvc_route_dispatcher_regex, ice_mvc_route_dispatcher_regex_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_route_dispatcher_regex_ce, SL("staticRouteMap"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_route_dispatcher_regex_ce, SL("variableRouteData"), ZEND_ACC_PROTECTED);
	zend_class_implements(ice_mvc_route_dispatcher_regex_ce, 1, ice_mvc_route_dispatcher_dispatcherinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setStaticRouteMap)
{
	zval *staticRouteMap, staticRouteMap_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticRouteMap_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("staticRouteMap", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(staticRouteMap)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &staticRouteMap);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 64, staticRouteMap);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setVariableRouteData)
{
	zval *variableRouteData, variableRouteData_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variableRouteData_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("variableRouteData", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(variableRouteData)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &variableRouteData);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 65, variableRouteData);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL, _0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("staticRouteMap", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("variableRouteData", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &data_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	}
	zephir_array_fetch_long(&_0, &data, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 14);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 64, &_0);
	zephir_array_fetch_long(&_1, &data, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/regex.zep", 15);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 65, &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, dispatchVariableRoute)
{
}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, dispatch)
{
	zend_bool _21, _30, _19$$16, _22$$18;
	zend_ulong _17, _26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval httpMethod_zv, uri_zv, handler, varRouteData, result, allowedMethods, uriMap, method, routeData, methodMap, _0, _9, _13, *_14, _15, *_16, _20, *_23, _24, *_25, _29, _1$$4, _2$$5, _4$$5, _5$$7, _6$$9, _7$$10, _8$$10, _10$$13, _11$$14, _12$$14, _28$$20, _31$$23, _32$$26, _33$$27;
	zend_string *httpMethod = NULL, *uri = NULL, *_18, *_27;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethod_zv);
	ZVAL_UNDEF(&uri_zv);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&varRouteData);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&allowedMethods);
	ZVAL_UNDEF(&uriMap);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&methodMap);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_31$$23);
	ZVAL_UNDEF(&_32$$26);
	ZVAL_UNDEF(&_33$$27);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("staticRouteMap", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("variableRouteData", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(httpMethod)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&httpMethod_zv);
	ZVAL_STR_COPY(&httpMethod_zv, httpMethod);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	zephir_memory_observe(&methodMap);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 64, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&methodMap, &_0, &httpMethod_zv, 0)) {
		zephir_memory_observe(&handler);
		if (zephir_array_isset_fetch(&handler, &methodMap, &uri_zv, 0)) {
			zephir_create_array(return_value, 3, 0);
			ZEPHIR_INIT_VAR(&_1$$4);
			ZVAL_LONG(&_1$$4, 1);
			zephir_array_fast_append(return_value, &_1$$4);
			zephir_array_fast_append(return_value, &handler);
			ZEPHIR_INIT_NVAR(&_1$$4);
			array_init(&_1$$4);
			zephir_array_fast_append(return_value, &_1$$4);
			RETURN_MM();
		}
	}
	zephir_memory_observe(&varRouteData);
	zephir_read_property_cached(&varRouteData, this_ptr, _zephir_prop_1, 65, PH_NOISY_CC);
	if (zephir_array_isset_value(&varRouteData, &httpMethod_zv)) {
		zephir_memory_observe(&_2$$5);
		zephir_array_fetch(&_2$$5, &varRouteData, &httpMethod_zv, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 33);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_3, 0, &_2$$5, &uri_zv);
		zephir_check_call_status();
		zephir_memory_observe(&_4$$5);
		zephir_array_fetch_long(&_4$$5, &result, 0, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 35);
		if (ZEPHIR_IS_LONG_IDENTICAL(&_4$$5, 1)) {
			RETURN_CCTOR(&result);
		}
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&httpMethod_zv, "HEAD")) {
		ZEPHIR_OBS_NVAR(&methodMap);
		zephir_read_property_cached(&_5$$7, this_ptr, _zephir_prop_0, 64, PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&methodMap, &_5$$7, SL("GET"), 0)) {
			ZEPHIR_OBS_NVAR(&handler);
			if (zephir_array_isset_fetch(&handler, &methodMap, &uri_zv, 0)) {
				zephir_create_array(return_value, 3, 0);
				ZEPHIR_INIT_VAR(&_6$$9);
				ZVAL_LONG(&_6$$9, 1);
				zephir_array_fast_append(return_value, &_6$$9);
				zephir_array_fast_append(return_value, &handler);
				ZEPHIR_INIT_NVAR(&_6$$9);
				array_init(&_6$$9);
				zephir_array_fast_append(return_value, &_6$$9);
				RETURN_MM();
			}
		}
		if (zephir_array_isset_value_string(&varRouteData, SL("GET"))) {
			zephir_memory_observe(&_7$$10);
			zephir_array_fetch_string(&_7$$10, &varRouteData, SL("GET"), PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 48);
			ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_3, 0, &_7$$10, &uri_zv);
			zephir_check_call_status();
			zephir_memory_observe(&_8$$10);
			zephir_array_fetch_long(&_8$$10, &result, 0, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 50);
			if (ZEPHIR_IS_LONG_IDENTICAL(&_8$$10, 1)) {
				RETURN_CCTOR(&result);
			}
		}
	}
	ZEPHIR_OBS_NVAR(&methodMap);
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_0, 64, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&methodMap, &_9, SL("*"), 0)) {
		ZEPHIR_OBS_NVAR(&handler);
		if (zephir_array_isset_fetch(&handler, &methodMap, &uri_zv, 0)) {
			zephir_create_array(return_value, 3, 0);
			ZEPHIR_INIT_VAR(&_10$$13);
			ZVAL_LONG(&_10$$13, 1);
			zephir_array_fast_append(return_value, &_10$$13);
			zephir_array_fast_append(return_value, &handler);
			ZEPHIR_INIT_NVAR(&_10$$13);
			array_init(&_10$$13);
			zephir_array_fast_append(return_value, &_10$$13);
			RETURN_MM();
		}
	}
	if (zephir_array_isset_value_string(&varRouteData, SL("*"))) {
		zephir_memory_observe(&_11$$14);
		zephir_array_fetch_string(&_11$$14, &varRouteData, SL("*"), PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 63);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_3, 0, &_11$$14, &uri_zv);
		zephir_check_call_status();
		zephir_memory_observe(&_12$$14);
		zephir_array_fetch_long(&_12$$14, &result, 0, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 65);
		if (ZEPHIR_IS_LONG_IDENTICAL(&_12$$14, 1)) {
			RETURN_CCTOR(&result);
		}
	}
	ZEPHIR_INIT_VAR(&allowedMethods);
	array_init(&allowedMethods);
	zephir_read_property_cached(&_13, this_ptr, _zephir_prop_0, 64, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_13) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_15);
		zephir_string_to_char_array(&_15, &_13);
		_14 = &_15;
	} else {
		_14 = &_13;
	}
	zephir_is_iterable(_14, 0, "ice/mvc/route/dispatcher/regex.zep", 79);
	if (Z_TYPE_P(_14) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_14), _17, _18, _16)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_18 != NULL) { 
				ZVAL_STR_COPY(&method, _18);
			} else {
				ZVAL_LONG(&method, _17);
			}
			ZEPHIR_INIT_NVAR(&uriMap);
			ZVAL_COPY(&uriMap, _16);
			_19$$16 = !ZEPHIR_IS_IDENTICAL(&method, &httpMethod_zv);
			if (_19$$16) {
				_19$$16 = zephir_array_key_exists(&uriMap, &uri_zv);
			}
			if (_19$$16) {
				zephir_array_append(&allowedMethods, &method, PH_SEPARATE, "ice/mvc/route/dispatcher/regex.zep", 75);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _14, "rewind", NULL, 0);
		zephir_check_call_status();
		_21 = 1;
		while (1) {
			if (_21) {
				_21 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _14, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_20, _14, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_20)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, _14, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&uriMap, _14, "current", NULL, 0);
			zephir_check_call_status();
				_22$$18 = !ZEPHIR_IS_IDENTICAL(&method, &httpMethod_zv);
				if (_22$$18) {
					_22$$18 = zephir_array_key_exists(&uriMap, &uri_zv);
				}
				if (_22$$18) {
					zephir_array_append(&allowedMethods, &method, PH_SEPARATE, "ice/mvc/route/dispatcher/regex.zep", 75);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&uriMap);
	ZEPHIR_INIT_NVAR(&method);
	if (Z_TYPE_P(&varRouteData) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_24);
		zephir_string_to_char_array(&_24, &varRouteData);
		_23 = &_24;
	} else {
		_23 = &varRouteData;
	}
	zephir_is_iterable(_23, 0, "ice/mvc/route/dispatcher/regex.zep", 91);
	if (Z_TYPE_P(_23) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_23), _26, _27, _25)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_27 != NULL) { 
				ZVAL_STR_COPY(&method, _27);
			} else {
				ZVAL_LONG(&method, _26);
			}
			ZEPHIR_INIT_NVAR(&routeData);
			ZVAL_COPY(&routeData, _25);
			if (ZEPHIR_IS_IDENTICAL(&method, &httpMethod_zv)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_3, 0, &routeData, &uri_zv);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&_28$$20);
			zephir_array_fetch_long(&_28$$20, &result, 0, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 86);
			if (ZEPHIR_IS_LONG_IDENTICAL(&_28$$20, 1)) {
				zephir_array_append(&allowedMethods, &method, PH_SEPARATE, "ice/mvc/route/dispatcher/regex.zep", 87);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _23, "rewind", NULL, 0);
		zephir_check_call_status();
		_30 = 1;
		while (1) {
			if (_30) {
				_30 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _23, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_29, _23, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_29)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, _23, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&routeData, _23, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&method, &httpMethod_zv)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&result, this_ptr, "dispatchvariableroute", &_3, 0, &routeData, &uri_zv);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_31$$23);
				zephir_array_fetch_long(&_31$$23, &result, 0, PH_NOISY, "ice/mvc/route/dispatcher/regex.zep", 86);
				if (ZEPHIR_IS_LONG_IDENTICAL(&_31$$23, 1)) {
					zephir_array_append(&allowedMethods, &method, PH_SEPARATE, "ice/mvc/route/dispatcher/regex.zep", 87);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&routeData);
	ZEPHIR_INIT_NVAR(&method);
	if (zephir_is_true(&allowedMethods)) {
		zephir_create_array(return_value, 2, 0);
		ZEPHIR_INIT_VAR(&_32$$26);
		ZVAL_LONG(&_32$$26, 2);
		zephir_array_fast_append(return_value, &_32$$26);
		zephir_array_fast_append(return_value, &allowedMethods);
		RETURN_MM();
	} else {
		zephir_create_array(return_value, 1, 0);
		ZEPHIR_INIT_VAR(&_33$$27);
		ZVAL_LONG(&_33$$27, 0);
		zephir_array_fast_append(return_value, &_33$$27);
		RETURN_MM();
	}
}

