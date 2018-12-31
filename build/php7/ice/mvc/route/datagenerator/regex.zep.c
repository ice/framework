
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethod, httpMethod_sub, *routeData, routeData_sub, *handler, handler_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethod_sub);
	ZVAL_UNDEF(&routeData_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);

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

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, getData) {

	zval _0, _3, _4, _1$$3, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("staticRoutes"), PH_NOISY_CC);
		zephir_array_fast_append(return_value, &_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		array_init(&_2$$3);
		zephir_array_fast_append(return_value, &_2$$3);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("staticRoutes"), PH_NOISY_CC);
	zephir_array_fast_append(return_value, &_3);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "generatevariableroutedata", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, &_4);
	RETURN_MM();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, generateVariableRouteData) {

	zval _7$$3;
	zend_string *_3;
	zend_ulong _2;
	zval __$true, chunkSize, chunks, data, method, regexToRoutesMap, _0, *_1, _4$$3, _8$$3, _9$$3;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&chunkSize);
	ZVAL_UNDEF(&chunks);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&regexToRoutesMap);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	zephir_read_property(&_0, this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "ice/mvc/route/datagenerator/regex.zep", 47);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&method);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&method, _3);
		} else {
			ZVAL_LONG(&method, _2);
		}
		ZEPHIR_INIT_NVAR(&regexToRoutesMap);
		ZVAL_COPY(&regexToRoutesMap, _1);
		ZVAL_LONG(&_4$$3, zephir_fast_count_int(&regexToRoutesMap TSRMLS_CC));
		ZEPHIR_CALL_METHOD(&chunkSize, this_ptr, "computechunksize", &_5, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&chunks, "array_chunk", &_6, 47, &regexToRoutesMap, &chunkSize, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_7$$3);
		zephir_create_array(&_7$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_7$$3, this_ptr);
		ZEPHIR_INIT_NVAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "processChunk");
		zephir_array_fast_append(&_7$$3, &_8$$3);
		ZEPHIR_CALL_FUNCTION(&_9$$3, "array_map", &_10, 48, &_7$$3, &chunks);
		zephir_check_call_status();
		zephir_array_update_zval(&data, &method, &_9$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&regexToRoutesMap);
	ZEPHIR_INIT_NVAR(&method);
	RETURN_CCTOR(&data);

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, computeChunkSize) {

	double round = 0, ceil = 0;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &count);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getapproxchunksize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	div_function(&_1, count, &_0 TSRMLS_CC);
	round = zephir_get_numberval(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_DOUBLE(&_3, round);
	zephir_round(&_2, &_3, NULL, NULL TSRMLS_CC);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&numParts, "max", NULL, 49, &_4, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	div_function(&_5, count, &numParts TSRMLS_CC);
	ceil = zephir_get_numberval(&_5);
	ZVAL_DOUBLE(&_4, ceil);
	RETURN_MM_DOUBLE(zephir_ceil(&_4 TSRMLS_CC));

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, isStaticRoute) {

	zend_bool _0;
	zval *routeData, routeData_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeData_sub);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params(0, 1, 0, &routeData);



	_0 = zephir_fast_count_int(routeData TSRMLS_CC) == 1;
	if (_0) {
		zephir_array_fetch_long(&_1, routeData, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 64 TSRMLS_CC);
		_0 = Z_TYPE_P(&_1) == IS_STRING;
	}
	RETURN_BOOL(_0);

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addStaticRoute) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zval *httpMethod, httpMethod_sub, *routeData, routeData_sub, *handler, handler_sub, routeStr, route, _0, _2, _3, _9, _4$$3, _5$$3, _6$$3, _10$$4, _11$$4, *_12$$4, _13$$5, _14$$6, _15$$6, _16$$6, _17$$6;
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
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod, &routeData, &handler);



	ZEPHIR_OBS_VAR(&routeStr);
	zephir_array_fetch_long(&routeStr, routeData, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 71 TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("staticRoutes"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, httpMethod);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("staticRoutes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3, &_2, httpMethod, PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 73 TSRMLS_CC);
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
		zephir_throw_exception_debug(&_4$$3, "ice/mvc/route/datagenerator/regex.zep", 76 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_9, this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_9, httpMethod)) {
		zephir_read_property(&_10$$4, this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_11$$4, &_10$$4, httpMethod, PH_NOISY | PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 80 TSRMLS_CC);
		zephir_is_iterable(&_11$$4, 0, "ice/mvc/route/datagenerator/regex.zep", 88);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_11$$4), _12$$4)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _12$$4);
			ZEPHIR_CALL_METHOD(&_13$$5, &route, "matches", NULL, 0, &routeStr);
			zephir_check_call_status();
			if (zephir_is_true(&_13$$5)) {
				ZEPHIR_INIT_NVAR(&_14$$6);
				object_init_ex(&_14$$6, ice_exception_ce);
				zephir_read_property(&_15$$6, &route, SL("regex"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZVAL_STRING(&_16$$6, "Static route '%s' is shadowed by previously defined variable route '%s' for method '%s'");
				ZEPHIR_CALL_FUNCTION(&_17$$6, "sprintf", &_7, 11, &_16$$6, &routeStr, &_15$$6, httpMethod);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_14$$6, "__construct", &_8, 12, &_17$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$6, "ice/mvc/route/datagenerator/regex.zep", 85 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&route);
	}
	zephir_update_property_array_multi(this_ptr, SL("staticRoutes"), handler TSRMLS_CC, SL("zz"), 2, httpMethod, &routeStr);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addVariableRoute) {

	zend_bool _4;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &httpMethod, &routeData, &handler);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildregexforroute", &_1, 0, routeData);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&regex);
	zephir_array_fetch_long(&regex, &_0, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 97 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "buildregexforroute", &_1, 0, routeData);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&variables);
	zephir_array_fetch_long(&variables, &_2, 1, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 98 TSRMLS_CC);
	zephir_read_property(&_3, this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
	_4 = zephir_array_isset(&_3, httpMethod);
	if (_4) {
		zephir_read_property(&_5, this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_6, &_5, httpMethod, PH_READONLY, "ice/mvc/route/datagenerator/regex.zep", 100 TSRMLS_CC);
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
		zephir_throw_exception_debug(&_7$$3, "ice/mvc/route/datagenerator/regex.zep", 104 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_10);
	object_init_ex(&_10, ice_mvc_fastroute_ce);
	ZEPHIR_CALL_METHOD(NULL, &_10, "__construct", NULL, 50, httpMethod, handler, &regex, &variables);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("methodToRegexToRoutesMap"), &_10 TSRMLS_CC, SL("zz"), 2, httpMethod, &regex);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, buildRegexForRoute) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL, *_8 = NULL;
	zval *routeData, routeData_sub, regex, variables, part, varName, regexPart, *_0, _1$$4, _2$$4, _4$$5, _5$$5, _6$$5, _9$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeData_sub);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&variables);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&varName);
	ZVAL_UNDEF(&regexPart);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &routeData);



	ZEPHIR_INIT_VAR(&regex);
	ZVAL_STRING(&regex, "");
	ZEPHIR_INIT_VAR(&variables);
	array_init(&variables);
	zephir_is_iterable(routeData, 0, "ice/mvc/route/datagenerator/regex.zep", 138);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(routeData), _0)
	{
		ZEPHIR_INIT_NVAR(&part);
		ZVAL_COPY(&part, _0);
		if (Z_TYPE_P(&part) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_1$$4);
			ZVAL_STRING(&_1$$4, "~");
			ZEPHIR_CALL_FUNCTION(&_2$$4, "preg_quote", &_3, 51, &part, &_1$$4);
			zephir_check_call_status();
			zephir_concat_self(&regex, &_2$$4 TSRMLS_CC);
			continue;
		}
		ZEPHIR_OBS_NVAR(&varName);
		zephir_array_fetch_long(&varName, &part, 0, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 125 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&regexPart);
		zephir_array_fetch_long(&regexPart, &part, 1, PH_NOISY, "ice/mvc/route/datagenerator/regex.zep", 126 TSRMLS_CC);
		if (zephir_array_isset(&variables, &varName)) {
			ZEPHIR_INIT_NVAR(&_4$$5);
			object_init_ex(&_4$$5, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "Cannot use the same placeholder '%s' twice");
			ZEPHIR_CALL_FUNCTION(&_6$$5, "sprintf", &_7, 11, &_5$$5, &varName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", &_8, 12, &_6$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$5, "ice/mvc/route/datagenerator/regex.zep", 131 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&variables, &varName, &varName, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_9$$3);
		ZEPHIR_CONCAT_SVS(&_9$$3, "(", &regexPart, ")");
		zephir_concat_self(&regex, &_9$$3 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&part);
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &regex);
	zephir_array_fast_append(return_value, &variables);
	RETURN_MM();

}

zend_object *zephir_init_properties_Ice_Mvc_Route_DataGenerator_Regex(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("methodToRegexToRoutesMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("methodToRegexToRoutesMap"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("staticRoutes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("staticRoutes"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

