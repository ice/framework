
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_GroupCount) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route\\Dispatcher, GroupCount, ice, mvc_route_dispatcher_groupcount, ice_mvc_route_dispatcher_groupcount_method_entry, 0);

	zend_declare_property_null(ice_mvc_route_dispatcher_groupcount_ce, SL("_staticRouteMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_dispatcher_groupcount_ce, SL("_variableRouteData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_mvc_route_dispatcher_groupcount_ce TSRMLS_CC, 1, ice_mvc_route_dispatcher_dispatcherinterface_ce);
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

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setData) {

	zval *data_param = NULL, *_0, *_1;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
	if (unlikely(Z_TYPE_P(data_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		data = data_param;

	}


	zephir_array_fetch_long(&_0, data, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 23 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_staticRouteMap"), _0 TSRMLS_CC);
	zephir_array_fetch_long(&_1, data, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 24 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_variableRouteData"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, dispatch) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod, *uri, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpMethod, &uri);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_staticRouteMap"), PH_NOISY_CC);
	if (zephir_array_isset(_0, uri)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dispatchstaticroute", &_1, httpMethod, uri);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dispatchvariableroute", &_2, httpMethod, uri);
		zephir_check_call_status();
		RETURN_MM();
	}

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, dispatchStaticRoute) {

	zend_bool _3;
	zval *httpMethod, *uri, *routes, *_0, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpMethod, &uri);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_staticRouteMap"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(routes);
	zephir_array_fetch(&routes, _0, uri, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 40 TSRMLS_CC);
	if (zephir_array_isset(routes, httpMethod)) {
		array_init_size(return_value, 4);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, 1);
		zephir_array_fast_append(return_value, _1);
		ZEPHIR_OBS_VAR(_2);
		zephir_array_fetch(&_2, routes, httpMethod, PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 43 TSRMLS_CC);
		zephir_array_fast_append(return_value, _2);
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_array_fast_append(return_value, _1);
		RETURN_MM();
	} else {
		_3 = ZEPHIR_IS_STRING_IDENTICAL(httpMethod, "HEAD");
		if (_3) {
			_3 = zephir_array_isset_string(routes, SS("GET"));
		}
		if (_3) {
			array_init_size(return_value, 4);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, 1);
			zephir_array_fast_append(return_value, _1);
			ZEPHIR_OBS_NVAR(_2);
			zephir_array_fetch_string(&_2, routes, SL("GET"), PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 46 TSRMLS_CC);
			zephir_array_fast_append(return_value, _2);
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_array_fast_append(return_value, _1);
			RETURN_MM();
		} else {
			array_init_size(return_value, 3);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, 2);
			zephir_array_fast_append(return_value, _1);
			ZEPHIR_INIT_NVAR(_1);
			zephir_array_keys(_1, routes TSRMLS_CC);
			zephir_array_fast_append(return_value, _1);
			RETURN_MM();
		}
	}

}

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, dispatchVariableRoute) {

	zend_bool _8;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2, *_13;
	HashPosition _1, _12;
	int i, ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod = NULL, *uri, *data = NULL, *matches, *routes = NULL, *handler, *varName = NULL, *varNames, *vars = NULL, *_0, **_3, *_4, *_5 = NULL, *_7, *_9 = NULL, *_10, *_11, **_14, *_15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &httpMethod, &uri);

	ZEPHIR_SEPARATE_PARAM(httpMethod);


	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_variableRouteData"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/mvc/route/dispatcher/groupcount.zep", 89);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(data, _3);
		zephir_array_fetch_string(&_4, data, SL("regex"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 61 TSRMLS_CC);
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(&_5, "preg_match", &_6, _4, uri, matches);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
		if (!(zephir_is_true(_5))) {
			continue;
		}
		zephir_array_fetch_string(&_7, data, SL("routeMap"), PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 65 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(routes);
		zephir_array_fetch_long(&routes, _7, zephir_fast_count_int(matches TSRMLS_CC), PH_NOISY, "ice/mvc/route/dispatcher/groupcount.zep", 65 TSRMLS_CC);
		if (!(zephir_array_isset(routes, httpMethod))) {
			_8 = ZEPHIR_IS_STRING_IDENTICAL(httpMethod, "HEAD");
			if (_8) {
				_8 = zephir_array_isset_string(routes, SS("GET"));
			}
			if (_8) {
				ZEPHIR_INIT_NVAR(httpMethod);
				ZVAL_STRING(httpMethod, "GET", 1);
			} else {
				array_init_size(return_value, 3);
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, 2);
				zephir_array_fast_append(return_value, _9);
				ZEPHIR_INIT_NVAR(_9);
				zephir_array_keys(_9, routes TSRMLS_CC);
				zephir_array_fast_append(return_value, _9);
				RETURN_MM();
			}
		}
		zephir_array_fetch(&_10, routes, httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 75 TSRMLS_CC);
		zephir_array_fetch_long(&handler, _10, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 75 TSRMLS_CC);
		zephir_array_fetch(&_11, routes, httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 76 TSRMLS_CC);
		zephir_array_fetch_long(&varNames, _11, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 76 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(vars);
		array_init(vars);
		i = 0;
		zephir_is_iterable(varNames, &_13, &_12, 0, 0, "ice/mvc/route/dispatcher/groupcount.zep", 86);
		for (
		  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
		  ; zephir_hash_move_forward_ex(_13, &_12)
		) {
			ZEPHIR_GET_HVALUE(varName, _14);
			i++;
			zephir_array_fetch_long(&_15, matches, i, PH_NOISY | PH_READONLY, "ice/mvc/route/dispatcher/groupcount.zep", 83 TSRMLS_CC);
			zephir_array_update_zval(&vars, varName, &_15, PH_COPY | PH_SEPARATE);
		}
		array_init_size(return_value, 4);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, 1);
		zephir_array_fast_append(return_value, _9);
		zephir_array_fast_append(return_value, handler);
		zephir_array_fast_append(return_value, vars);
		RETURN_MM();
	}
	array_init_size(return_value, 2);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_LONG(_9, 0);
	zephir_array_fast_append(return_value, _9);
	RETURN_MM();

}

