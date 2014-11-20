
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(Ice_Mvc_Route_DataGenerator_Regex) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route\\DataGenerator, Regex, ice, mvc_route_datagenerator_regex, ice_mvc_route_datagenerator_regex_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_route_datagenerator_regex_ce, SL("staticRoutes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_datagenerator_regex_ce, SL("regexToRoutesMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_mvc_route_datagenerator_regex_ce TSRMLS_CC, 1, ice_mvc_route_datagenerator_datageneratorinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, getApproxChunkSize) {

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, processChunk) {

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addRoute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod, *routeData, *handler, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod, &routeData, &handler);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isstaticroute", NULL, routeData);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addstaticroute", NULL, httpMethod, routeData, handler);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addvariableroute", NULL, httpMethod, routeData, handler);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, getData) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("regexToRoutesMap"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		array_init_size(return_value, 3);
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("staticRoutes"), PH_NOISY_CC);
		zephir_array_fast_append(return_value, _1);
		ZEPHIR_INIT_VAR(_2);
		array_init(_2);
		zephir_array_fast_append(return_value, _2);
		RETURN_MM();
	}
	array_init_size(return_value, 3);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("staticRoutes"), PH_NOISY_CC);
	zephir_array_fast_append(return_value, _1);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "generatevariableroutedata", NULL);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, _3);
	RETURN_MM();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, generateVariableRouteData) {

	zval *_4;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *chunkSize = NULL, *chunks = NULL, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("regexToRoutesMap"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, zephir_fast_count_int(_0 TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&chunkSize, this_ptr, "computechunksize", NULL, _1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("regexToRoutesMap"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&chunks, "array_chunk", &_3, _2, chunkSize, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	array_init_size(_4, 3);
	zephir_array_fast_append(_4, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "processChunk", 1);
	zephir_array_fast_append(_4, _1);
	ZEPHIR_RETURN_CALL_FUNCTION("array_map", &_5, _4, chunks);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, computeChunkSize) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	double round, ceil;
	zval *count, *numParts = NULL, *_0 = NULL, *_1, _2 = zval_used_for_init, *_4, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &count);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getapproxchunksize", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	div_function(_1, count, _0 TSRMLS_CC);
	round = zephir_get_numberval(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_DOUBLE(&_2, round);
	ZEPHIR_CALL_FUNCTION(&_0, "round", &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 1);
	ZEPHIR_CALL_FUNCTION(&numParts, "max", &_5, _4, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	div_function(_6, count, numParts TSRMLS_CC);
	ceil = zephir_get_numberval(_6);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_DOUBLE(&_2, ceil);
	ZEPHIR_RETURN_CALL_FUNCTION("ceil", &_7, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, isStaticRoute) {

	zend_bool _0;
	zval *routeData, *_1;

	zephir_fetch_params(0, 1, 0, &routeData);



	_0 = zephir_fast_count_int(routeData TSRMLS_CC) == 1;
	if (_0) {
		zephir_array_fetch_long(&_1, routeData, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 59 TSRMLS_CC);
		_0 = Z_TYPE_P(_1) == IS_STRING;
	}
	RETURN_BOOL(_0);

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addStaticRoute) {

	HashTable *_12;
	HashPosition _11;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	zend_bool _1;
	zval *httpMethod, *routeData, *handler, *routeStr, *route = NULL, *routes = NULL, *_0, *_2, *_3, *_4 = NULL, _5 = zval_used_for_init, *_6 = NULL, *_9, *_10, **_13, *_14 = NULL, *_15 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod, &routeData, &handler);



	ZEPHIR_OBS_VAR(routeStr);
	zephir_array_fetch_long(&routeStr, routeData, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 65 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("staticRoutes"), PH_NOISY_CC);
	_1 = zephir_array_isset(_0, routeStr);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("staticRoutes"), PH_NOISY_CC);
		zephir_array_fetch(&_3, _2, routeStr, PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 67 TSRMLS_CC);
		_1 = zephir_array_isset(_3, httpMethod);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "Cannot register two routes matching '%s' for method '%s'", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_7, &_5, routeStr, httpMethod);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_8, _6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "ice/mvc/route/datagenerator/regex.zep", 70 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("regexToRoutesMap"), PH_NOISY_CC);
	if (zephir_fast_count_int(_9 TSRMLS_CC)) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("regexToRoutesMap"), PH_NOISY_CC);
		zephir_is_iterable(_10, &_12, &_11, 0, 0, "ice/mvc/route/datagenerator/regex.zep", 88);
		for (
		  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HVALUE(routes, _13);
			if (!(zephir_array_isset(routes, httpMethod))) {
				continue;
			}
			ZEPHIR_OBS_NVAR(route);
			zephir_array_fetch(&route, routes, httpMethod, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 79 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_6, route, "matches", NULL, routeStr);
			zephir_check_call_status();
			if (zephir_is_true(_6)) {
				ZEPHIR_INIT_NVAR(_4);
				object_init_ex(_4, ice_exception_ce);
				ZEPHIR_OBS_NVAR(_14);
				zephir_read_property(&_14, route, SL("regex"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "Static route '%s' is shadowed by previously defined variable route '%s' for method '%s'", 0);
				ZEPHIR_CALL_FUNCTION(&_15, "sprintf", &_7, &_5, routeStr, _14, httpMethod);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_8, _15);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4, "ice/mvc/route/datagenerator/regex.zep", 85 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_update_property_array_multi(this_ptr, SL("staticRoutes"), &handler TSRMLS_CC, SL("zz"), 2, routeStr, httpMethod);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addVariableRoute) {

	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL;
	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod, *routeData, *handler, *regex, *variables, *_0 = NULL, *_1 = NULL, *_2, *_4, *_5, *_6 = NULL, _7, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod, &routeData, &handler);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildregexforroute", NULL, routeData);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(regex);
	zephir_array_fetch_long(&regex, _0, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 97 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildregexforroute", NULL, routeData);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(variables);
	zephir_array_fetch_long(&variables, _1, 1, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 98 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("regexToRoutesMap"), PH_NOISY_CC);
	_3 = zephir_array_isset(_2, regex);
	if (_3) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("regexToRoutesMap"), PH_NOISY_CC);
		zephir_array_fetch(&_5, _4, regex, PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 100 TSRMLS_CC);
		_3 = zephir_array_isset(_5, httpMethod);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(_6);
		object_init_ex(_6, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_STRING(&_7, "Cannot register two routes matching '%s' for method '%s'", 0);
		ZEPHIR_CALL_FUNCTION(&_8, "sprintf", &_9, &_7, regex, httpMethod);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, _8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6, "ice/mvc/route/datagenerator/regex.zep", 104 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_6);
	object_init_ex(_6, ice_mvc_route_ce);
	ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, httpMethod, handler, regex, variables);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("regexToRoutesMap"), &_6 TSRMLS_CC, SL("zz"), 2, regex, httpMethod);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, buildRegexForRoute) {

	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *routeData, *regex, *variables, *part = NULL, *varName = NULL, *regexPart = NULL, **_2, _3 = zval_used_for_init, *_4 = NULL, *_6 = NULL, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &routeData);



	ZEPHIR_INIT_VAR(regex);
	ZVAL_STRING(regex, "", 1);
	ZEPHIR_INIT_VAR(variables);
	array_init(variables);
	zephir_is_iterable(routeData, &_1, &_0, 0, 0, "ice/mvc/route/datagenerator/regex.zep", 138);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(part, _2);
		if (Z_TYPE_P(part) == IS_STRING) {
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "~", 0);
			ZEPHIR_CALL_FUNCTION(&_4, "preg_quote", &_5, part, &_3);
			zephir_check_call_status();
			zephir_concat_self(&regex, _4 TSRMLS_CC);
			continue;
		}
		ZEPHIR_OBS_NVAR(varName);
		zephir_array_fetch_long(&varName, part, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 125 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(regexPart);
		zephir_array_fetch_long(&regexPart, part, 1, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 126 TSRMLS_CC);
		if (zephir_array_isset(variables, varName)) {
			ZEPHIR_INIT_NVAR(_6);
			object_init_ex(_6, ice_exception_ce);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "Cannot use the same placeholder '%s' twice", 0);
			ZEPHIR_CALL_FUNCTION(&_4, "sprintf", &_7, &_3, varName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_8, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6, "ice/mvc/route/datagenerator/regex.zep", 131 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&variables, varName, &varName, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_SVS(_9, "(", regexPart, ")");
		zephir_concat_self(&regex, _9 TSRMLS_CC);
	}
	array_init_size(return_value, 3);
	zephir_array_fast_append(return_value, regex);
	zephir_array_fast_append(return_value, variables);
	RETURN_MM();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, __construct) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("regexToRoutesMap"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("staticRoutes"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

