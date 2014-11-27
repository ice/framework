
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
#include "kernel/hash.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_GroupCount) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\Route\\Dispatcher, GroupCount, ice, mvc_route_dispatcher_groupcount, ice_mvc_route_dispatcher_regex_ce, ice_mvc_route_dispatcher_groupcount_method_entry, 0);

	zend_declare_property_null(ice_mvc_route_dispatcher_groupcount_ce, SL("_staticRouteMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_dispatcher_groupcount_ce, SL("_variableRouteData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setStaticRouteMap) {

	zval *staticRouteMap;

	zephir_fetch_params(0, 1, 0, &staticRouteMap);



	zephir_update_property_this(this_ptr, SL("_staticRouteMap"), staticRouteMap TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setVariableRouteData) {

	zval *variableRouteData;

	zephir_fetch_params(0, 1, 0, &variableRouteData);



	zephir_update_property_this(this_ptr, SL("_variableRouteData"), variableRouteData TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, __construct) {

	zval *data_param = NULL, *_0, *_1;
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
		zephir_array_fetch_long(&_0, data, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 16 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_staticRouteMap"), _0 TSRMLS_CC);
		zephir_array_fetch_long(&_1, data, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 17 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_variableRouteData"), _1 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, dispatchVariableRoute) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_1, *_11;
	HashPosition _0, _10;
	int i, j, ZEPHIR_LAST_CALL_STATUS;
	zval *routeData, *uri, *data = NULL, *matches, *handler, *varName = NULL, *varNames, *vars = NULL, **_2, *_3, *_4 = NULL, *_6, *_7, *_8, *_9, **_12, *_13, *_14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routeData, &uri);



	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	zephir_is_iterable(routeData, &_1, &_0, 0, 0, "ice/mvc/route/dispatcher/groupcount.zep", 48);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(data, _2);
		zephir_array_fetch_string(&_3, data, SL("regex"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 29 TSRMLS_CC);
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(&_4, "preg_match", &_5, _3, uri, matches);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
		if (!(zephir_is_true(_4))) {
			continue;
		}
		j = zephir_fast_count_int(matches TSRMLS_CC);
		zephir_array_fetch_string(&_6, data, SL("routeMap"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34 TSRMLS_CC);
		zephir_array_fetch_long(&_7, _6, j, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34 TSRMLS_CC);
		zephir_array_fetch_long(&handler, _7, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 34 TSRMLS_CC);
		zephir_array_fetch_string(&_8, data, SL("routeMap"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 35 TSRMLS_CC);
		zephir_array_fetch_long(&_9, _8, j, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 35 TSRMLS_CC);
		zephir_array_fetch_long(&varNames, _9, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 35 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(vars);
		array_init(vars);
		i = 0;
		zephir_is_iterable(varNames, &_11, &_10, 0, 0, "ice/mvc/route/dispatcher/groupcount.zep", 45);
		for (
		  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HVALUE(varName, _12);
			i++;
			zephir_array_fetch_long(&_13, matches, i, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 42 TSRMLS_CC);
			zephir_array_update_zval(&vars, varName, &_13, PH_COPY | PH_SEPARATE);
		}
		array_init_size(return_value, 4);
		ZEPHIR_INIT_NVAR(_14);
		ZVAL_LONG(_14, 1);
		zephir_array_fast_append(return_value, _14);
		zephir_array_fast_append(return_value, handler);
		zephir_array_fast_append(return_value, vars);
		RETURN_MM();
	}
	array_init_size(return_value, 2);
	ZEPHIR_INIT_NVAR(_14);
	ZVAL_LONG(_14, 0);
	zephir_array_fast_append(return_value, _14);
	RETURN_MM();

}

