
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

	zval *staticRouteMap;

	zephir_fetch_params(0, 1, 0, &staticRouteMap);



	zephir_update_property_this(getThis(), SL("staticRouteMap"), staticRouteMap TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setVariableRouteData) {

	zval *variableRouteData;

	zephir_fetch_params(0, 1, 0, &variableRouteData);



	zephir_update_property_this(getThis(), SL("variableRouteData"), variableRouteData TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, __construct) {

	zval *data_param = NULL, *_0$$3, *_1$$3;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	if (zephir_fast_count_int(data TSRMLS_CC)) {
		zephir_array_fetch_long(&_0$$3, data, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 16 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("staticRouteMap"), _0$$3 TSRMLS_CC);
		zephir_array_fetch_long(&_1$$3, data, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 17 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("variableRouteData"), _1$$3 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, dispatchVariableRoute) {

	HashTable *_1, *_10$$3;
	HashPosition _0, _9$$3;
	zend_long i = 0, j = 0;
	zval *routeData, *uri, *data = NULL, *matches = NULL, *handler = NULL, *varName = NULL, *varNames = NULL, *vars = NULL, **_2, *_14, *_3$$3, *_4$$3 = NULL, *_5$$3, *_6$$3, *_7$$3, *_8$$3, **_11$$3, *_13$$3 = NULL, *_12$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routeData, &uri);



	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	zephir_is_iterable(routeData, &_1, &_0, 0, 0, "ice/mvc/route/dispatcher/groupcount.zep", 48);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(data, _2);
		zephir_array_fetch_string(&_3$$3, data, SL("regex"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 29 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		zephir_preg_match(_4$$3, _3$$3, uri, matches, 0, 0 , 0  TSRMLS_CC);
		if (!(zephir_is_true(_4$$3))) {
			continue;
		}
		j = zephir_fast_count_int(matches TSRMLS_CC);
		zephir_array_fetch_string(&_5$$3, data, SL("routeMap"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34 TSRMLS_CC);
		zephir_array_fetch_long(&_6$$3, _5$$3, j, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34 TSRMLS_CC);
		zephir_array_fetch_long(&handler, _6$$3, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34 TSRMLS_CC);
		zephir_array_fetch_string(&_7$$3, data, SL("routeMap"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 35 TSRMLS_CC);
		zephir_array_fetch_long(&_8$$3, _7$$3, j, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 35 TSRMLS_CC);
		zephir_array_fetch_long(&varNames, _8$$3, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 35 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(vars);
		array_init(vars);
		i = 0;
		zephir_is_iterable(varNames, &_10$$3, &_9$$3, 0, 0, "ice/mvc/route/dispatcher/groupcount.zep", 45);
		for (
		  ; zend_hash_get_current_data_ex(_10$$3, (void**) &_11$$3, &_9$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_10$$3, &_9$$3)
		) {
			ZEPHIR_GET_HVALUE(varName, _11$$3);
			i++;
			zephir_array_fetch_long(&_12$$5, matches, i, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 42 TSRMLS_CC);
			zephir_array_update_zval(&vars, varName, &_12$$5, PH_COPY | PH_SEPARATE);
		}
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_13$$3);
		ZVAL_LONG(_13$$3, 1);
		zephir_array_fast_append(return_value, _13$$3);
		zephir_array_fast_append(return_value, handler);
		zephir_array_fast_append(return_value, vars);
		RETURN_MM();
	}
	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_LONG(_14, 0);
	zephir_array_fast_append(return_value, _14);
	RETURN_MM();

}

