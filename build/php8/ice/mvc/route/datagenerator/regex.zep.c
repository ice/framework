
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
#include "kernel/math.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_DataGenerator_Regex)
{
	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route\\DataGenerator, Regex, ice, mvc_route_datagenerator_regex, ice_mvc_route_datagenerator_regex_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_route_datagenerator_regex_ce, SL("staticRoutes"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_route_datagenerator_regex_ce, SL("methodToRegexToRoutesMap"), ZEND_ACC_PROTECTED);
	ice_mvc_route_datagenerator_regex_ce->create_object = zephir_init_properties_Ice_Mvc_Route_DataGenerator_Regex;

	zend_class_implements(ice_mvc_route_datagenerator_regex_ce, 1, ice_mvc_route_datagenerator_datageneratorinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, getApproxChunkSize)
{
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, processChunk)
{
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addRoute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod, httpMethod_sub, *routeData, routeData_sub, *handler, handler_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethod_sub);
	ZVAL_UNDEF(&routeData_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(httpMethod)
		Z_PARAM_ZVAL(routeData)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod, &routeData, &handler);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isstaticroute", NULL, 0, routeData);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addstaticroute", NULL, 0, httpMethod, routeData, handler);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addvariableroute", NULL, 0, httpMethod, routeData, handler);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, getData)
{
	zval _0, _3, _4, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		zephir_create_array(return_value, 2, 0);
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("staticRoutes"), PH_NOISY_CC);
		zephir_array_fast_append(return_value, &_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		array_init(&_2$$3);
		zephir_array_fast_append(return_value, &_2$$3);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("staticRoutes"), PH_NOISY_CC);
	zephir_array_fast_append(return_value, &_3);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "generatevariableroutedata", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, &_4);
	RETURN_MM();
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, generateVariableRouteData)
{
	zval _8$$3, _13$$4;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, chunkSize, chunks, data, method, regexToRoutesMap, _0, *_1, _2, _5$$3, _9$$3, _10$$3, _12$$4, _14$$4, _15$$4;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&chunkSize);
	ZVAL_UNDEF(&chunks);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&regexToRoutesMap);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_13$$4);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "ice/mvc/route/datagenerator/regex.zep", 46);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&method, _4);
			} else {
				ZVAL_LONG(&method, _3);
			}
			ZEPHIR_INIT_NVAR(&regexToRoutesMap);
			ZVAL_COPY(&regexToRoutesMap, _1);
			ZVAL_LONG(&_5$$3, zephir_fast_count_int(&regexToRoutesMap));
			ZEPHIR_CALL_METHOD(&chunkSize, this_ptr, "computechunksize", &_6, 0, &_5$$3);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&chunks, "array_chunk", &_7, 58, &regexToRoutesMap, &chunkSize, &__$true);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$3);
			zephir_create_array(&_8$$3, 2, 0);
			zephir_array_fast_append(&_8$$3, this_ptr);
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "processChunk");
			zephir_array_fast_append(&_8$$3, &_9$$3);
			ZEPHIR_CALL_FUNCTION(&_10$$3, "array_map", &_11, 52, &_8$$3, &chunks);
			zephir_check_call_status();
			zephir_array_update_zval(&data, &method, &_10$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&regexToRoutesMap, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_12$$4, zephir_fast_count_int(&regexToRoutesMap));
				ZEPHIR_CALL_METHOD(&chunkSize, this_ptr, "computechunksize", &_6, 0, &_12$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&chunks, "array_chunk", &_7, 58, &regexToRoutesMap, &chunkSize, &__$true);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$4);
				zephir_create_array(&_13$$4, 2, 0);
				zephir_array_fast_append(&_13$$4, this_ptr);
				ZEPHIR_INIT_NVAR(&_14$$4);
				ZVAL_STRING(&_14$$4, "processChunk");
				zephir_array_fast_append(&_13$$4, &_14$$4);
				ZEPHIR_CALL_FUNCTION(&_15$$4, "array_map", &_11, 52, &_13$$4, &chunks);
				zephir_check_call_status();
				zephir_array_update_zval(&data, &method, &_15$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&regexToRoutesMap);
	ZEPHIR_INIT_NVAR(&method);
	RETURN_CCTOR(&data);
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, computeChunkSize)
{
	double round = 0, ceil = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *count, count_sub, numParts, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&count_sub);
	ZVAL_UNDEF(&numParts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(count)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &count);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getapproxchunksize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	div_function(&_1, count, &_0);
	round = zephir_get_numberval(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_DOUBLE(&_3, round);
	zephir_round(&_2, &_3, NULL, NULL);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&numParts, "max", NULL, 50, &_4, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	div_function(&_5, count, &numParts);
	ceil = zephir_get_numberval(&_5);
	ZVAL_DOUBLE(&_4, ceil);
	RETURN_MM_DOUBLE(zephir_ceil(&_4));
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, isStaticRoute)
{
	zend_bool _0;
	zval *routeData, routeData_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeData_sub);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(routeData)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &routeData);


	_0 = zephir_fast_count_int(routeData) == 1;
	if (_0) {
		zephir_array_fetch_long(&_1, routeData, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 63);
		_0 = Z_TYPE_P(&_1) == IS_STRING;
	}
	RETURN_BOOL(_0);
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addStaticRoute)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zval *httpMethod, httpMethod_sub, *routeData, routeData_sub, *handler, handler_sub, routeStr, route, _0, _2, _3, _9, _4$$3, _5$$3, _6$$3, _10$$4, _11$$4, *_12$$4, _13$$4, _14$$5, _15$$6, _16$$6, _17$$6, _18$$6, _19$$7, _20$$8, _21$$8, _22$$8, _23$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethod_sub);
	ZVAL_UNDEF(&routeData_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&routeStr);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(httpMethod)
		Z_PARAM_ZVAL(routeData)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod, &routeData, &handler);


	ZEPHIR_OBS_VAR(&routeStr);
	zephir_array_fetch_long(&routeStr, routeData, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 70);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("staticRoutes"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, httpMethod);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("staticRoutes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3, &_2, httpMethod, PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 72);
		_1 = zephir_array_isset(&_3, &routeStr);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Cannot register two routes matching '%s' for method '%s'");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", &_7, 11, &_5$$3, &routeStr, httpMethod);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", &_8, 12, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "ice/mvc/route/datagenerator/regex.zep", 75);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_9, this_ptr, ZEND_STRL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_9, httpMethod)) {
		zephir_read_property(&_10$$4, this_ptr, ZEND_STRL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_11$$4, &_10$$4, httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 79);
		zephir_is_iterable(&_11$$4, 0, "ice/mvc/route/datagenerator/regex.zep", 87);
		if (Z_TYPE_P(&_11$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_11$$4), _12$$4)
			{
				ZEPHIR_INIT_NVAR(&route);
				ZVAL_COPY(&route, _12$$4);
				ZEPHIR_CALL_METHOD(&_14$$5, &route, "matches", NULL, 0, &routeStr);
				zephir_check_call_status();
				if (zephir_is_true(&_14$$5)) {
					ZEPHIR_INIT_NVAR(&_15$$6);
					object_init_ex(&_15$$6, ice_exception_ce);
					zephir_read_property(&_16$$6, &route, ZEND_STRL("regex"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_17$$6);
					ZVAL_STRING(&_17$$6, "Static route '%s' is shadowed by previously defined variable route '%s' for method '%s'");
					ZEPHIR_CALL_FUNCTION(&_18$$6, "sprintf", &_7, 11, &_17$$6, &routeStr, &_16$$6, httpMethod);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_15$$6, "__construct", &_8, 12, &_18$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_15$$6, "ice/mvc/route/datagenerator/regex.zep", 84);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_11$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_13$$4, &_11$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_13$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&route, &_11$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_19$$7, &route, "matches", NULL, 0, &routeStr);
					zephir_check_call_status();
					if (zephir_is_true(&_19$$7)) {
						ZEPHIR_INIT_NVAR(&_20$$8);
						object_init_ex(&_20$$8, ice_exception_ce);
						zephir_read_property(&_21$$8, &route, ZEND_STRL("regex"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_22$$8);
						ZVAL_STRING(&_22$$8, "Static route '%s' is shadowed by previously defined variable route '%s' for method '%s'");
						ZEPHIR_CALL_FUNCTION(&_23$$8, "sprintf", &_7, 11, &_22$$8, &routeStr, &_21$$8, httpMethod);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &_20$$8, "__construct", &_8, 12, &_23$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_20$$8, "ice/mvc/route/datagenerator/regex.zep", 84);
						ZEPHIR_MM_RESTORE();
						return;
					}
				ZEPHIR_CALL_METHOD(NULL, &_11$$4, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&route);
	}
	zephir_update_property_array_multi(this_ptr, SL("staticRoutes"), handler, SL("zz"), 2, httpMethod, &routeStr);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addVariableRoute)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod, httpMethod_sub, *routeData, routeData_sub, *handler, handler_sub, regex, variables, _0, _2, _3, _5, _6, _10, _7$$3, _8$$3, _9$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethod_sub);
	ZVAL_UNDEF(&routeData_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&variables);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(httpMethod)
		Z_PARAM_ZVAL(routeData)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod, &routeData, &handler);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildregexforroute", &_1, 0, routeData);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&regex);
	zephir_array_fetch_long(&regex, &_0, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 96);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "buildregexforroute", &_1, 0, routeData);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&variables);
	zephir_array_fetch_long(&variables, &_2, 1, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 97);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
	_4 = zephir_array_isset(&_3, httpMethod);
	if (_4) {
		zephir_read_property(&_5, this_ptr, ZEND_STRL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_6, &_5, httpMethod, PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 99);
		_4 = zephir_array_isset(&_6, &regex);
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&_7$$3);
		object_init_ex(&_7$$3, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "Cannot register two routes matching '%s' for method '%s'");
		ZEPHIR_CALL_FUNCTION(&_9$$3, "sprintf", NULL, 11, &_8$$3, &regex, httpMethod);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$3, "__construct", NULL, 12, &_9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$3, "ice/mvc/route/datagenerator/regex.zep", 103);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_10);
	object_init_ex(&_10, ice_mvc_fastroute_ce);
	ZEPHIR_CALL_METHOD(NULL, &_10, "__construct", NULL, 59, httpMethod, handler, &regex, &variables);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("methodToRegexToRoutesMap"), &_10, SL("zz"), 2, httpMethod, &regex);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, buildRegexForRoute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routeData, routeData_sub, regex, variables, part, varName, regexPart, *_0, _1, _2$$4, _3$$4, _5$$5, _6$$5, _7$$5, _10$$3, _11$$7, _12$$7, _13$$8, _14$$8, _15$$8, _16$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeData_sub);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&variables);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&varName);
	ZVAL_UNDEF(&regexPart);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(routeData)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &routeData);


	ZEPHIR_INIT_VAR(&regex);
	ZVAL_STRING(&regex, "");
	ZEPHIR_INIT_VAR(&variables);
	array_init(&variables);
	zephir_is_iterable(routeData, 0, "ice/mvc/route/datagenerator/regex.zep", 137);
	if (Z_TYPE_P(routeData) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(routeData), _0)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _0);
			if (Z_TYPE_P(&part) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_2$$4);
				ZVAL_STRING(&_2$$4, "~");
				ZEPHIR_CALL_FUNCTION(&_3$$4, "preg_quote", &_4, 60, &part, &_2$$4);
				zephir_check_call_status();
				zephir_concat_self(&regex, &_3$$4);
				continue;
			}
			ZEPHIR_OBS_NVAR(&varName);
			zephir_array_fetch_long(&varName, &part, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 124);
			ZEPHIR_OBS_NVAR(&regexPart);
			zephir_array_fetch_long(&regexPart, &part, 1, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 125);
			if (zephir_array_isset(&variables, &varName)) {
				ZEPHIR_INIT_NVAR(&_5$$5);
				object_init_ex(&_5$$5, ice_exception_ce);
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZVAL_STRING(&_6$$5, "Cannot use the same placeholder '%s' twice");
				ZEPHIR_CALL_FUNCTION(&_7$$5, "sprintf", &_8, 11, &_6$$5, &varName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", &_9, 12, &_7$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$5, "ice/mvc/route/datagenerator/regex.zep", 130);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&variables, &varName, &varName, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_10$$3);
			ZEPHIR_CONCAT_SVS(&_10$$3, "(", &regexPart, ")");
			zephir_concat_self(&regex, &_10$$3);
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
			ZEPHIR_CALL_METHOD(&part, routeData, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&part) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_11$$7);
					ZVAL_STRING(&_11$$7, "~");
					ZEPHIR_CALL_FUNCTION(&_12$$7, "preg_quote", &_4, 60, &part, &_11$$7);
					zephir_check_call_status();
					zephir_concat_self(&regex, &_12$$7);
					continue;
				}
				ZEPHIR_OBS_NVAR(&varName);
				zephir_array_fetch_long(&varName, &part, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 124);
				ZEPHIR_OBS_NVAR(&regexPart);
				zephir_array_fetch_long(&regexPart, &part, 1, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 125);
				if (zephir_array_isset(&variables, &varName)) {
					ZEPHIR_INIT_NVAR(&_13$$8);
					object_init_ex(&_13$$8, ice_exception_ce);
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZVAL_STRING(&_14$$8, "Cannot use the same placeholder '%s' twice");
					ZEPHIR_CALL_FUNCTION(&_15$$8, "sprintf", &_8, 11, &_14$$8, &varName);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_13$$8, "__construct", &_9, 12, &_15$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_13$$8, "ice/mvc/route/datagenerator/regex.zep", 130);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&variables, &varName, &varName, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZEPHIR_CONCAT_SVS(&_16$$6, "(", &regexPart, ")");
				zephir_concat_self(&regex, &_16$$6);
			ZEPHIR_CALL_METHOD(NULL, routeData, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	zephir_create_array(return_value, 2, 0);
	zephir_array_fast_append(return_value, &regex);
	zephir_array_fast_append(return_value, &variables);
	RETURN_MM();
}

zend_object *zephir_init_properties_Ice_Mvc_Route_DataGenerator_Regex(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("methodToRegexToRoutesMap"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("staticRoutes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("staticRoutes"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

