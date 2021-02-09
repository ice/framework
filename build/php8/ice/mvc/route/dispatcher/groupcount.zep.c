
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
#include "kernel/fcall.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_GroupCount) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\Route\\Dispatcher, GroupCount, ice, mvc_route_dispatcher_groupcount, ice_mvc_route_dispatcher_regex_ce, ice_mvc_route_dispatcher_groupcount_method_entry, 0);

	zend_declare_property_null(ice_mvc_route_dispatcher_groupcount_ce, SL("staticRouteMap"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_mvc_route_dispatcher_groupcount_ce, SL("variableRouteData"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setStaticRouteMap) {

	zval *staticRouteMap, staticRouteMap_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticRouteMap_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &staticRouteMap);



	zephir_update_property_zval(this_ptr, ZEND_STRL("staticRouteMap"), staticRouteMap);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setVariableRouteData) {

	zval *variableRouteData, variableRouteData_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variableRouteData_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &variableRouteData);



	zephir_update_property_zval(this_ptr, ZEND_STRL("variableRouteData"), variableRouteData);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL, _0$$3, _1$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	if (zephir_fast_count_int(&data)) {
		zephir_array_fetch_long(&_0$$3, &data, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 15);
		zephir_update_property_zval(this_ptr, ZEND_STRL("staticRouteMap"), &_0$$3);
		zephir_array_fetch_long(&_1$$3, &data, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 16);
		zephir_update_property_zval(this_ptr, ZEND_STRL("variableRouteData"), &_1$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, dispatchVariableRoute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, j = 0;
	zval *routeData, routeData_sub, *uri, uri_sub, data, matches, handler, varName, varNames, vars, *_0, _1, _24, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, *_8$$3, _9$$3, _12$$3, _10$$5, _11$$6, _13$$7, _14$$7, _15$$7, _16$$7, _17$$7, _18$$7, *_19$$7, _20$$7, _23$$7, _21$$9, _22$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeData_sub);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&varName);
	ZVAL_UNDEF(&varNames);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routeData, &uri);



	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	zephir_is_iterable(routeData, 0, "ice/mvc/route/dispatcher/groupcount.zep", 47);
	if (Z_TYPE_P(routeData) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(routeData), _0)
		{
			ZEPHIR_INIT_NVAR(&data);
			ZVAL_COPY(&data, _0);
			zephir_array_fetch_string(&_2$$3, &data, SL("regex"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 28);
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_preg_match(&_3$$3, &_2$$3, uri, &matches, 0, 0 , 0 );
			if (!(zephir_is_true(&_3$$3))) {
				continue;
			}
			j = zephir_fast_count_int(&matches);
			zephir_array_fetch_string(&_4$$3, &data, SL("routeMap"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
			zephir_array_fetch_long(&_5$$3, &_4$$3, j, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
			zephir_array_fetch_long(&handler, &_5$$3, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
			zephir_array_fetch_string(&_6$$3, &data, SL("routeMap"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
			zephir_array_fetch_long(&_7$$3, &_6$$3, j, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
			zephir_array_fetch_long(&varNames, &_7$$3, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
			ZEPHIR_INIT_NVAR(&vars);
			array_init(&vars);
			i = 0;
			zephir_is_iterable(&varNames, 0, "ice/mvc/route/dispatcher/groupcount.zep", 44);
			if (Z_TYPE_P(&varNames) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&varNames), _8$$3)
				{
					ZEPHIR_INIT_NVAR(&varName);
					ZVAL_COPY(&varName, _8$$3);
					i++;
					zephir_array_fetch_long(&_10$$5, &matches, i, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 41);
					zephir_array_update_zval(&vars, &varName, &_10$$5, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &varNames, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_9$$3, &varNames, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_9$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&varName, &varNames, "current", NULL, 0);
					zephir_check_call_status();
						i++;
						zephir_array_fetch_long(&_11$$6, &matches, i, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 41);
						zephir_array_update_zval(&vars, &varName, &_11$$6, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &varNames, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&varName);
			zephir_create_array(return_value, 3, 0);
			ZEPHIR_INIT_NVAR(&_12$$3);
			ZVAL_LONG(&_12$$3, 1);
			zephir_array_fast_append(return_value, &_12$$3);
			zephir_array_fast_append(return_value, &handler);
			zephir_array_fast_append(return_value, &vars);
			RETURN_MM();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, routeData, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, routeData, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&data, routeData, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_13$$7, &data, SL("regex"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 28);
				ZEPHIR_INIT_NVAR(&_14$$7);
				zephir_preg_match(&_14$$7, &_13$$7, uri, &matches, 0, 0 , 0 );
				if (!(zephir_is_true(&_14$$7))) {
					continue;
				}
				j = zephir_fast_count_int(&matches);
				zephir_array_fetch_string(&_15$$7, &data, SL("routeMap"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
				zephir_array_fetch_long(&_16$$7, &_15$$7, j, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &_16$$7, 0, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 33);
				zephir_array_fetch_string(&_17$$7, &data, SL("routeMap"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
				zephir_array_fetch_long(&_18$$7, &_17$$7, j, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
				ZEPHIR_OBS_NVAR(&varNames);
				zephir_array_fetch_long(&varNames, &_18$$7, 1, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 34);
				ZEPHIR_INIT_NVAR(&vars);
				array_init(&vars);
				i = 0;
				zephir_is_iterable(&varNames, 0, "ice/mvc/route/dispatcher/groupcount.zep", 44);
				if (Z_TYPE_P(&varNames) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&varNames), _19$$7)
					{
						ZEPHIR_INIT_NVAR(&varName);
						ZVAL_COPY(&varName, _19$$7);
						i++;
						zephir_array_fetch_long(&_21$$9, &matches, i, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 41);
						zephir_array_update_zval(&vars, &varName, &_21$$9, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &varNames, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_20$$7, &varNames, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_20$$7)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&varName, &varNames, "current", NULL, 0);
						zephir_check_call_status();
							i++;
							zephir_array_fetch_long(&_22$$10, &matches, i, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 41);
							zephir_array_update_zval(&vars, &varName, &_22$$10, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &varNames, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&varName);
				zephir_create_array(return_value, 3, 0);
				ZEPHIR_INIT_NVAR(&_23$$7);
				ZVAL_LONG(&_23$$7, 1);
				zephir_array_fast_append(return_value, &_23$$7);
				zephir_array_fast_append(return_value, &handler);
				zephir_array_fast_append(return_value, &vars);
				RETURN_MM();
			ZEPHIR_CALL_METHOD(NULL, routeData, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&data);
	zephir_create_array(return_value, 1, 0);
	ZEPHIR_INIT_VAR(&_24);
	ZVAL_LONG(&_24, 0);
	zephir_array_fast_append(return_value, &_24);
	RETURN_MM();

}

