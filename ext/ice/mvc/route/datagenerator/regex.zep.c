
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
#include "kernel/hash.h"
#include "kernel/math.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_DataGenerator_Regex) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route\\DataGenerator, Regex, ice, mvc_route_datagenerator_regex, ice_mvc_route_datagenerator_regex_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_route_datagenerator_regex_ce, SL("staticRoutes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_datagenerator_regex_ce, SL("methodToRegexToRoutesMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_mvc_route_datagenerator_regex_ce->create_object = zephir_init_properties_Ice_Mvc_Route_DataGenerator_Regex;

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



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isstaticroute", NULL, 0, routeData);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addstaticroute", NULL, 0, httpMethod, routeData, handler);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addvariableroute", NULL, 0, httpMethod, routeData, handler);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, getData) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("staticRoutes"), PH_NOISY_CC);
		zephir_array_fast_append(return_value, _1);
		ZEPHIR_INIT_VAR(_2);
		array_init(_2);
		zephir_array_fast_append(return_value, _2);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("staticRoutes"), PH_NOISY_CC);
	zephir_array_fast_append(return_value, _1);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "generatevariableroutedata", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, _3);
	RETURN_MM();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, generateVariableRouteData) {

	zval *_7 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *chunkSize = NULL, *chunks = NULL, *data = NULL, *method = NULL, *regexToRoutesMap = NULL, *_0, **_3, *_4 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(data);
	array_init(data);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/mvc/route/datagenerator/regex.zep", 47);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(method, _2, _1);
		ZEPHIR_GET_HVALUE(regexToRoutesMap, _3);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, zephir_fast_count_int(regexToRoutesMap TSRMLS_CC));
		ZEPHIR_CALL_METHOD(&chunkSize, this_ptr, "computechunksize", &_5, 0, _4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&chunks, "array_chunk", &_6, 30, regexToRoutesMap, chunkSize, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7);
		zephir_create_array(_7, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_7, this_ptr);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "processChunk", 1);
		zephir_array_fast_append(_7, _4);
		ZEPHIR_CALL_FUNCTION(&_8, "array_map", &_9, 31, _7, chunks);
		zephir_check_call_status();
		zephir_array_update_zval(&data, method, &_8, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, computeChunkSize) {

	int ZEPHIR_LAST_CALL_STATUS;
	double round = 0, ceil = 0;
	zval *count, *numParts = NULL, *_0 = NULL, *_1, *_2, _3, *_4, *_5, _6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &count);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getapproxchunksize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	div_function(_1, count, _0 TSRMLS_CC);
	round = zephir_get_numberval(_1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_DOUBLE(&_3, round);
	zephir_round(_2, &_3, NULL, NULL TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 1);
	ZEPHIR_CALL_FUNCTION(&numParts, "max", NULL, 32, _4, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	div_function(_5, count, numParts TSRMLS_CC);
	ceil = zephir_get_numberval(_5);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_DOUBLE(&_6, ceil);
	RETURN_MM_DOUBLE(zephir_ceil(&_6 TSRMLS_CC));

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, isStaticRoute) {

	zend_bool _0;
	zval *routeData, *_1;

	zephir_fetch_params(0, 1, 0, &routeData);



	_0 = zephir_fast_count_int(routeData TSRMLS_CC) == 1;
	if (_0) {
		zephir_array_fetch_long(&_1, routeData, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 64 TSRMLS_CC);
		_0 = Z_TYPE_P(_1) == IS_STRING;
	}
	RETURN_BOOL(_0);

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addStaticRoute) {

	HashTable *_13;
	HashPosition _12;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zend_bool _1;
	zval *httpMethod, *routeData, *handler, *routeStr = NULL, *route = NULL, *_0, *_2, *_3, *_4 = NULL, _5 = zval_used_for_init, *_6 = NULL, *_9, *_10, *_11, **_14, *_15 = NULL, *_16 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod, &routeData, &handler);



	ZEPHIR_OBS_VAR(routeStr);
	zephir_array_fetch_long(&routeStr, routeData, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 71 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("staticRoutes"), PH_NOISY_CC);
	_1 = zephir_array_isset(_0, httpMethod);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("staticRoutes"), PH_NOISY_CC);
		zephir_array_fetch(&_3, _2, httpMethod, PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 73 TSRMLS_CC);
		_1 = zephir_array_isset(_3, routeStr);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "Cannot register two routes matching '%s' for method '%s'", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_7, 1, &_5, routeStr, httpMethod);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_8, 2, _6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "ice/mvc/route/datagenerator/regex.zep", 76 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
	if (zephir_array_isset(_9, httpMethod)) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
		zephir_array_fetch(&_11, _10, httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 80 TSRMLS_CC);
		zephir_is_iterable(_11, &_13, &_12, 0, 0, "ice/mvc/route/datagenerator/regex.zep", 88);
		for (
		  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
		  ; zephir_hash_move_forward_ex(_13, &_12)
		) {
			ZEPHIR_GET_HVALUE(route, _14);
			ZEPHIR_CALL_METHOD(&_6, route, "matches", NULL, 0, routeStr);
			zephir_check_call_status();
			if (zephir_is_true(_6)) {
				ZEPHIR_INIT_NVAR(_4);
				object_init_ex(_4, ice_exception_ce);
				ZEPHIR_OBS_NVAR(_15);
				zephir_read_property(&_15, route, SL("regex"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "Static route '%s' is shadowed by previously defined variable route '%s' for method '%s'", 0);
				ZEPHIR_CALL_FUNCTION(&_16, "sprintf", &_7, 1, &_5, routeStr, _15, httpMethod);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_8, 2, _16);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4, "ice/mvc/route/datagenerator/regex.zep", 85 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_update_property_array_multi(this_ptr, SL("staticRoutes"), &handler TSRMLS_CC, SL("zz"), 2, httpMethod, routeStr);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addVariableRoute) {

	zend_bool _4;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod, *routeData, *handler, *regex = NULL, *variables = NULL, *_0 = NULL, *_2 = NULL, *_3, *_5, *_6, *_7 = NULL, _8, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod, &routeData, &handler);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildregexforroute", &_1, 0, routeData);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(regex);
	zephir_array_fetch_long(&regex, _0, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 97 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "buildregexforroute", &_1, 0, routeData);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(variables);
	zephir_array_fetch_long(&variables, _2, 1, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 98 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
	_4 = zephir_array_isset(_3, httpMethod);
	if (_4) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
		zephir_array_fetch(&_6, _5, httpMethod, PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 100 TSRMLS_CC);
		_4 = zephir_array_isset(_6, regex);
	}
	if (_4) {
		ZEPHIR_INIT_VAR(_7);
		object_init_ex(_7, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_STRING(&_8, "Cannot register two routes matching '%s' for method '%s'", 0);
		ZEPHIR_CALL_FUNCTION(&_9, "sprintf", NULL, 1, &_8, regex, httpMethod);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 2, _9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7, "ice/mvc/route/datagenerator/regex.zep", 104 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_7);
	object_init_ex(_7, ice_mvc_route_ce);
	ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 33, httpMethod, handler, regex, variables);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("methodToRegexToRoutesMap"), &_7 TSRMLS_CC, SL("zz"), 2, httpMethod, regex);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, buildRegexForRoute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_8 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *routeData, *regex = NULL, *variables = NULL, *part = NULL, *varName = NULL, *regexPart = NULL, **_2, _3 = zval_used_for_init, *_4 = NULL, *_6 = NULL, *_9 = NULL;

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
			ZEPHIR_CALL_FUNCTION(&_4, "preg_quote", &_5, 34, part, &_3);
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
			ZEPHIR_CALL_FUNCTION(&_4, "sprintf", &_7, 1, &_3, varName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_8, 2, _4);
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
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, regex);
	zephir_array_fast_append(return_value, variables);
	RETURN_MM();

}

static zend_object_value zephir_init_properties_Ice_Mvc_Route_DataGenerator_Regex(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("methodToRegexToRoutesMap"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("staticRoutes"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("staticRoutes"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

