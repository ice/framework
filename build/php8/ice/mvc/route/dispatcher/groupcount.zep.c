
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
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_GroupCount)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\Route\\Dispatcher, GroupCount, ice, mvc_route_dispatcher_groupcount, ice_mvc_route_dispatcher_regex_ce, ice_mvc_route_dispatcher_groupcount_method_entry, 0);

	zend_declare_property_null(ice_mvc_route_dispatcher_groupcount_ce, SL("staticRouteMap"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_route_dispatcher_groupcount_ce, SL("variableRouteData"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setStaticRouteMap)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 227, staticRouteMap);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setVariableRouteData)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 228, variableRouteData);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL, _0$$3, _1$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
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
		zephir_get_arrval(&data, data_param);
	}
	if (zephir_fast_count_int(&data)) {
		zephir_memory_observe(&_0$$3);
		zephir_array_fetch_long(&_0$$3, &data, 0, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 15);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 227, &_0$$3);
		zephir_memory_observe(&_1$$3);
		zephir_array_fetch_long(&_1$$3, &data, 1, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 16);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 228, &_1$$3);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, dispatchVariableRoute)
{
	zend_bool _18, _14$$3, _30$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, j = 0;
	zval *routeData, routeData_sub, *uri, uri_sub, data, matches, handler, varName, varNames, vars, *_0, _1, *_2, _17, _33, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, *_9$$3, _10$$3, *_11$$3, _13$$3, _16$$3, _12$$5, _15$$6, _19$$7, _20$$7, _21$$7, _22$$7, _23$$7, _24$$7, *_25$$7, _26$$7, *_27$$7, _29$$7, _32$$7, _28$$9, _31$$10;

	ZVAL_UNDEF(&routeData_sub);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&varName);
	ZVAL_UNDEF(&varNames);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_31$$10);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(routeData)
		Z_PARAM_ZVAL(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &routeData, &uri);
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	if (Z_TYPE_P(routeData) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, routeData);
		_0 = &_1;
	} else {
		_0 = routeData;
	}
	zephir_is_iterable(_0, 0, "ice/mvc/route/dispatcher/groupcount.zep", 47);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0), _2)
		{
			ZEPHIR_INIT_NVAR(&data);
			ZVAL_COPY(&data, _2);
			ZEPHIR_OBS_NVAR(&_3$$3);
			zephir_array_fetch_string(&_3$$3, &data, SL("regex"), PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 28);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_preg_match(&_4$$3, &_3$$3, uri, &matches, 0, 0 , 0 );
			if (!(zephir_is_true(&_4$$3))) {
				continue;
			}
			j = zephir_fast_count_int(&matches);
			ZEPHIR_OBS_NVAR(&_5$$3);
			zephir_array_fetch_string(&_5$$3, &data, SL("routeMap"), PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
			ZEPHIR_OBS_NVAR(&_6$$3);
			zephir_array_fetch_long(&_6$$3, &_5$$3, j, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_long(&handler, &_6$$3, 0, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
			ZEPHIR_OBS_NVAR(&_7$$3);
			zephir_array_fetch_string(&_7$$3, &data, SL("routeMap"), PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
			ZEPHIR_OBS_NVAR(&_8$$3);
			zephir_array_fetch_long(&_8$$3, &_7$$3, j, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
			ZEPHIR_OBS_NVAR(&varNames);
			zephir_array_fetch_long(&varNames, &_8$$3, 1, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
			ZEPHIR_INIT_NVAR(&vars);
			array_init(&vars);
			i = 0;
			if (Z_TYPE_P(&varNames) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_10$$3);
				zephir_string_to_char_array(&_10$$3, &varNames);
				_9$$3 = &_10$$3;
			} else {
				_9$$3 = &varNames;
			}
			zephir_is_iterable(_9$$3, 0, "ice/mvc/route/dispatcher/groupcount.zep", 44);
			if (Z_TYPE_P(_9$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$3), _11$$3)
				{
					ZEPHIR_INIT_NVAR(&varName);
					ZVAL_COPY(&varName, _11$$3);
					i++;
					ZEPHIR_OBS_NVAR(&_12$$5);
					zephir_array_fetch_long(&_12$$5, &matches, i, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 41);
					zephir_array_update_zval(&vars, &varName, &_12$$5, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _9$$3, "rewind", NULL, 0);
				zephir_check_call_status();
				_14$$3 = 1;
				while (1) {
					if (_14$$3) {
						_14$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _9$$3, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_13$$3, _9$$3, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&varName, _9$$3, "current", NULL, 0);
					zephir_check_call_status();
						i++;
						ZEPHIR_OBS_NVAR(&_15$$6);
						zephir_array_fetch_long(&_15$$6, &matches, i, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 41);
						zephir_array_update_zval(&vars, &varName, &_15$$6, PH_COPY | PH_SEPARATE);
				}
			}
			ZEPHIR_INIT_NVAR(&varName);
			zephir_create_array(return_value, 3, 0);
			ZEPHIR_INIT_NVAR(&_16$$3);
			ZVAL_LONG(&_16$$3, 1);
			zephir_array_fast_append(return_value, &_16$$3);
			zephir_array_fast_append(return_value, &handler);
			zephir_array_fast_append(return_value, &vars);
			RETURN_MM();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _0, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, _0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&data, _0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_19$$7);
				zephir_array_fetch_string(&_19$$7, &data, SL("regex"), PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 28);
				ZEPHIR_INIT_NVAR(&_20$$7);
				zephir_preg_match(&_20$$7, &_19$$7, uri, &matches, 0, 0 , 0 );
				if (!(zephir_is_true(&_20$$7))) {
					continue;
				}
				j = zephir_fast_count_int(&matches);
				ZEPHIR_OBS_NVAR(&_21$$7);
				zephir_array_fetch_string(&_21$$7, &data, SL("routeMap"), PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
				ZEPHIR_OBS_NVAR(&_22$$7);
				zephir_array_fetch_long(&_22$$7, &_21$$7, j, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &_22$$7, 0, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
				ZEPHIR_OBS_NVAR(&_23$$7);
				zephir_array_fetch_string(&_23$$7, &data, SL("routeMap"), PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
				ZEPHIR_OBS_NVAR(&_24$$7);
				zephir_array_fetch_long(&_24$$7, &_23$$7, j, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
				ZEPHIR_OBS_NVAR(&varNames);
				zephir_array_fetch_long(&varNames, &_24$$7, 1, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
				ZEPHIR_INIT_NVAR(&vars);
				array_init(&vars);
				i = 0;
				if (Z_TYPE_P(&varNames) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_26$$7);
					zephir_string_to_char_array(&_26$$7, &varNames);
					_25$$7 = &_26$$7;
				} else {
					_25$$7 = &varNames;
				}
				zephir_is_iterable(_25$$7, 0, "ice/mvc/route/dispatcher/groupcount.zep", 44);
				if (Z_TYPE_P(_25$$7) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_25$$7), _27$$7)
					{
						ZEPHIR_INIT_NVAR(&varName);
						ZVAL_COPY(&varName, _27$$7);
						i++;
						ZEPHIR_OBS_NVAR(&_28$$9);
						zephir_array_fetch_long(&_28$$9, &matches, i, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 41);
						zephir_array_update_zval(&vars, &varName, &_28$$9, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _25$$7, "rewind", NULL, 0);
					zephir_check_call_status();
					_30$$7 = 1;
					while (1) {
						if (_30$$7) {
							_30$$7 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _25$$7, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_29$$7, _25$$7, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_29$$7)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&varName, _25$$7, "current", NULL, 0);
						zephir_check_call_status();
							i++;
							ZEPHIR_OBS_NVAR(&_31$$10);
							zephir_array_fetch_long(&_31$$10, &matches, i, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 41);
							zephir_array_update_zval(&vars, &varName, &_31$$10, PH_COPY | PH_SEPARATE);
					}
				}
				ZEPHIR_INIT_NVAR(&varName);
				zephir_create_array(return_value, 3, 0);
				ZEPHIR_INIT_NVAR(&_32$$7);
				ZVAL_LONG(&_32$$7, 1);
				zephir_array_fast_append(return_value, &_32$$7);
				zephir_array_fast_append(return_value, &handler);
				zephir_array_fast_append(return_value, &vars);
				RETURN_MM();
		}
	}
	ZEPHIR_INIT_NVAR(&data);
	zephir_create_array(return_value, 1, 0);
	ZEPHIR_INIT_VAR(&_33);
	ZVAL_LONG(&_33, 0);
	zephir_array_fast_append(return_value, &_33);
	RETURN_MM();
}

