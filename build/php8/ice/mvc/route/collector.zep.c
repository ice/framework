
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Collector)
{
	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route, Collector, ice, mvc_route_collector, ice_mvc_route_collector_method_entry, 0);

	zend_declare_property_null(ice_mvc_route_collector_ce, SL("routeParser"), ZEND_ACC_PRIVATE);
	zend_declare_property_null(ice_mvc_route_collector_ce, SL("dataGenerator"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

PHP_METHOD(Ice_Mvc_Route_Collector, setRouteParser)
{
	zval *routeParser, routeParser_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeParser_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routeParser", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(routeParser)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &routeParser);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 225, routeParser);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_Route_Collector, setDataGenerator)
{
	zval *dataGenerator, dataGenerator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataGenerator_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dataGenerator", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(dataGenerator)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &dataGenerator);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 226, dataGenerator);
	RETURN_THISW();
}

/**
 * Constructs a route collector.
 *
 * @param RouteParser   $routeParser
 * @param DataGenerator $dataGenerator
 */
PHP_METHOD(Ice_Mvc_Route_Collector, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routeParser = NULL, routeParser_sub, *dataGenerator = NULL, dataGenerator_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeParser_sub);
	ZVAL_UNDEF(&dataGenerator_sub);
	ZVAL_NULL(&__$null);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routeParser", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("dataGenerator", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(routeParser, ice_mvc_route_parser_parserinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(dataGenerator, ice_mvc_route_datagenerator_datageneratorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &routeParser, &dataGenerator);
	if (!routeParser) {
		routeParser = &routeParser_sub;
		ZEPHIR_CPY_WRT(routeParser, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(routeParser);
	}
	if (!dataGenerator) {
		dataGenerator = &dataGenerator_sub;
		ZEPHIR_CPY_WRT(dataGenerator, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(dataGenerator);
	}
	if (!(zephir_is_true(routeParser))) {
		ZEPHIR_INIT_NVAR(routeParser);
		object_init_ex(routeParser, ice_mvc_route_parser_std_ce);
		if (zephir_has_constructor(routeParser)) {
			ZEPHIR_CALL_METHOD(NULL, routeParser, "__construct", NULL, 0);
			zephir_check_call_status();
		}

	}
	if (!(zephir_is_true(dataGenerator))) {
		ZEPHIR_INIT_NVAR(dataGenerator);
		object_init_ex(dataGenerator, ice_mvc_route_datagenerator_groupcount_ce);
		if (zephir_has_constructor(dataGenerator)) {
			ZEPHIR_CALL_METHOD(NULL, dataGenerator, "__construct", NULL, 0);
			zephir_check_call_status();
		}

	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 225, routeParser);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 226, dataGenerator);
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a route to the collection.
 *
 * The syntax used in the $route string depends on the used route parser.
 *
 * @param string|array $httpMethod
 * @param string $route
 * @param mixed  $handler
 * @return object Collector
 */
PHP_METHOD(Ice_Mvc_Route_Collector, addRoute)
{
	zend_bool _13, _10$$4, _19$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *route = NULL;
	zval *httpMethod = NULL, httpMethod_sub, route_zv, *handler = NULL, handler_sub, __$null, routeDatas, routeData, method, _0, *_2, _3, *_4, _12, _1$$3, *_5$$4, _6$$4, *_7$$4, _9$$4, _8$$5, _11$$6, *_14$$7, _15$$7, *_16$$7, _18$$7, _17$$8, _20$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethod_sub);
	ZVAL_UNDEF(&route_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&routeDatas);
	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_20$$9);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routeParser", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("dataGenerator", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(httpMethod)
		Z_PARAM_STR(route)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(handler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	httpMethod = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		handler = ZEND_CALL_ARG(execute_data, 3);
	}
	ZEPHIR_SEPARATE_PARAM(httpMethod);
	zephir_memory_observe(&route_zv);
	ZVAL_STR_COPY(&route_zv, route);
	if (!handler) {
		handler = &handler_sub;
		handler = &__$null;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 225, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&routeDatas, &_0, "parse", NULL, 0, &route_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(httpMethod) == IS_STRING) {
		ZEPHIR_CPY_WRT(&method, httpMethod);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0);
		zephir_array_fast_append(&_1$$3, &method);
		ZEPHIR_CPY_WRT(httpMethod, &_1$$3);
	}
	if (Z_TYPE_P(httpMethod) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, httpMethod);
		_2 = &_3;
	} else {
		_2 = httpMethod;
	}
	zephir_is_iterable(_2, 0, "ice/mvc/route/collector.zep", 61);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
		{
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_COPY(&method, _4);
			if (Z_TYPE_P(&routeDatas) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_string_to_char_array(&_6$$4, &routeDatas);
				_5$$4 = &_6$$4;
			} else {
				_5$$4 = &routeDatas;
			}
			zephir_is_iterable(_5$$4, 0, "ice/mvc/route/collector.zep", 59);
			if (Z_TYPE_P(_5$$4) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_5$$4), _7$$4)
				{
					ZEPHIR_INIT_NVAR(&routeData);
					ZVAL_COPY(&routeData, _7$$4);
					zephir_read_property_cached(&_8$$5, this_ptr, _zephir_prop_1, 226, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_8$$5, "addroute", NULL, 0, &method, &routeData, handler);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _5$$4, "rewind", NULL, 0);
				zephir_check_call_status();
				_10$$4 = 1;
				while (1) {
					if (_10$$4) {
						_10$$4 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _5$$4, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_9$$4, _5$$4, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_9$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&routeData, _5$$4, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property_cached(&_11$$6, this_ptr, _zephir_prop_1, 226, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_11$$6, "addroute", NULL, 0, &method, &routeData, handler);
						zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&routeData);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _2, "rewind", NULL, 0);
		zephir_check_call_status();
		_13 = 1;
		while (1) {
			if (_13) {
				_13 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_12, _2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, _2, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&routeDatas) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_15$$7);
					zephir_string_to_char_array(&_15$$7, &routeDatas);
					_14$$7 = &_15$$7;
				} else {
					_14$$7 = &routeDatas;
				}
				zephir_is_iterable(_14$$7, 0, "ice/mvc/route/collector.zep", 59);
				if (Z_TYPE_P(_14$$7) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_14$$7), _16$$7)
					{
						ZEPHIR_INIT_NVAR(&routeData);
						ZVAL_COPY(&routeData, _16$$7);
						zephir_read_property_cached(&_17$$8, this_ptr, _zephir_prop_1, 226, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_17$$8, "addroute", NULL, 0, &method, &routeData, handler);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _14$$7, "rewind", NULL, 0);
					zephir_check_call_status();
					_19$$7 = 1;
					while (1) {
						if (_19$$7) {
							_19$$7 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _14$$7, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_18$$7, _14$$7, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_18$$7)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&routeData, _14$$7, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property_cached(&_20$$9, this_ptr, _zephir_prop_1, 226, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_METHOD(NULL, &_20$$9, "addroute", NULL, 0, &method, &routeData, handler);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&routeData);
		}
	}
	ZEPHIR_INIT_NVAR(&method);
	RETURN_THIS();
}

/**
 * Returns the collected route data, as provided by the data generator.
 *
 * @return array
 */
PHP_METHOD(Ice_Mvc_Route_Collector, getData)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dataGenerator", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 226, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getdata", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

