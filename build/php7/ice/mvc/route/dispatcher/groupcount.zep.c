
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


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_GroupCount) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\Route\\Dispatcher, GroupCount, ice, mvc_route_dispatcher_groupcount, ice_mvc_route_dispatcher_regex_ce, ice_mvc_route_dispatcher_groupcount_method_entry, 0);

	zend_declare_property_null(ice_mvc_route_dispatcher_groupcount_ce, SL("staticRouteMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_dispatcher_groupcount_ce, SL("variableRouteData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setStaticRouteMap) {

	zval *staticRouteMap, staticRouteMap_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticRouteMap_sub);

	zephir_fetch_params(0, 1, 0, &staticRouteMap);



	zephir_update_property_zval(this_ptr, SL("staticRouteMap"), staticRouteMap);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setVariableRouteData) {

	zval *variableRouteData, variableRouteData_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variableRouteData_sub);

	zephir_fetch_params(0, 1, 0, &variableRouteData);



	zephir_update_property_zval(this_ptr, SL("variableRouteData"), variableRouteData);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, __construct) {

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


	if (zephir_fast_count_int(&data TSRMLS_CC)) {
		zephir_array_fetch_long(&_0$$3, &data, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 16 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("staticRouteMap"), &_0$$3);
		zephir_array_fetch_long(&_1$$3, &data, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 17 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("variableRouteData"), &_1$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, dispatchVariableRoute) {

	zend_long i = 0, j = 0;
	zval *routeData, routeData_sub, *uri, uri_sub, data, matches, handler, varName, varNames, vars, *_0, _10, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, *_7$$3, _9$$3, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeData_sub);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&varName);
	ZVAL_UNDEF(&varNames);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routeData, &uri);



	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	zephir_is_iterable(routeData, 0, "ice/mvc/route/dispatcher/groupcount.zep", 48);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(routeData), _0)
	{
		ZEPHIR_INIT_NVAR(&data);
		ZVAL_COPY(&data, _0);
		zephir_array_fetch_string(&_1$$3, &data, SL("regex"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 29 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_preg_match(&_2$$3, &_1$$3, uri, &matches, 0, 0 , 0  TSRMLS_CC);
		if (!(zephir_is_true(&_2$$3))) {
			continue;
		}
		j = zephir_fast_count_int(&matches TSRMLS_CC);
		zephir_array_fetch_string(&_3$$3, &data, SL("routeMap"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34 TSRMLS_CC);
		zephir_array_fetch_long(&_4$$3, &_3$$3, j, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34 TSRMLS_CC);
		zephir_array_fetch_long(&handler, &_4$$3, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34 TSRMLS_CC);
		zephir_array_fetch_string(&_5$$3, &data, SL("routeMap"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 35 TSRMLS_CC);
		zephir_array_fetch_long(&_6$$3, &_5$$3, j, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 35 TSRMLS_CC);
		zephir_array_fetch_long(&varNames, &_6$$3, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 35 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&vars);
		array_init(&vars);
		i = 0;
		zephir_is_iterable(&varNames, 0, "ice/mvc/route/dispatcher/groupcount.zep", 45);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&varNames), _7$$3)
		{
			ZEPHIR_INIT_NVAR(&varName);
			ZVAL_COPY(&varName, _7$$3);
			i++;
			zephir_array_fetch_long(&_8$$5, &matches, i, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 42 TSRMLS_CC);
			zephir_array_update_zval(&vars, &varName, &_8$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&varName);
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_9$$3);
		ZVAL_LONG(&_9$$3, 1);
		zephir_array_fast_append(return_value, &_9$$3);
		zephir_array_fast_append(return_value, &handler);
		zephir_array_fast_append(return_value, &vars);
		RETURN_MM();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&data);
	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_LONG(&_10, 0);
	zephir_array_fast_append(return_value, &_10);
	RETURN_MM();

}

