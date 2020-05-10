
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


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Collector) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route, Collector, ice, mvc_route_collector, ice_mvc_route_collector_method_entry, 0);

	zend_declare_property_null(ice_mvc_route_collector_ce, SL("routeParser"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(ice_mvc_route_collector_ce, SL("dataGenerator"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Collector, setRouteParser) {

	zval *routeParser, routeParser_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeParser_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &routeParser);



	zephir_update_property_zval(this_ptr, ZEND_STRL("routeParser"), routeParser);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route_Collector, setDataGenerator) {

	zval *dataGenerator, dataGenerator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataGenerator_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &dataGenerator);



	zephir_update_property_zval(this_ptr, ZEND_STRL("dataGenerator"), dataGenerator);
	RETURN_THISW();

}

/**
 * Constructs a route collector.
 *
 * @param RouteParser   $routeParser
 * @param DataGenerator $dataGenerator
 */
PHP_METHOD(Ice_Mvc_Route_Collector, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routeParser = NULL, routeParser_sub, *dataGenerator = NULL, dataGenerator_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeParser_sub);
	ZVAL_UNDEF(&dataGenerator_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("routeParser"), routeParser);
	zephir_update_property_zval(this_ptr, ZEND_STRL("dataGenerator"), dataGenerator);
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
PHP_METHOD(Ice_Mvc_Route_Collector, addRoute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval route;
	zval *httpMethod = NULL, httpMethod_sub, *route_param = NULL, *handler = NULL, handler_sub, __$null, routeDatas, routeData, method, _0, *_2, _3, _1$$3, *_4$$4, _5$$4, _6$$5, _7$$6, *_8$$7, _9$$7, _10$$8, _11$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethod_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&routeDatas);
	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&route);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &httpMethod, &route_param, &handler);

	ZEPHIR_SEPARATE_PARAM(httpMethod);
	zephir_get_strval(&route, route_param);
	if (!handler) {
		handler = &handler_sub;
		handler = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("routeParser"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&routeDatas, &_0, "parse", NULL, 0, &route);
	zephir_check_call_status();
	if (Z_TYPE_P(httpMethod) == IS_STRING) {
		ZEPHIR_CPY_WRT(&method, httpMethod);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0);
		zephir_array_fast_append(&_1$$3, &method);
		ZEPHIR_CPY_WRT(httpMethod, &_1$$3);
	}
	zephir_is_iterable(httpMethod, 0, "ice/mvc/route/collector.zep", 61);
	if (Z_TYPE_P(httpMethod) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(httpMethod), _2)
		{
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_COPY(&method, _2);
			zephir_is_iterable(&routeDatas, 0, "ice/mvc/route/collector.zep", 59);
			if (Z_TYPE_P(&routeDatas) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routeDatas), _4$$4)
				{
					ZEPHIR_INIT_NVAR(&routeData);
					ZVAL_COPY(&routeData, _4$$4);
					zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("dataGenerator"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_6$$5, "addroute", NULL, 0, &method, &routeData, handler);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &routeDatas, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_5$$4, &routeDatas, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_5$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&routeData, &routeDatas, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property(&_7$$6, this_ptr, ZEND_STRL("dataGenerator"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_7$$6, "addroute", NULL, 0, &method, &routeData, handler);
						zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &routeDatas, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&routeData);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, httpMethod, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, httpMethod, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, httpMethod, "current", NULL, 0);
			zephir_check_call_status();
				zephir_is_iterable(&routeDatas, 0, "ice/mvc/route/collector.zep", 59);
				if (Z_TYPE_P(&routeDatas) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routeDatas), _8$$7)
					{
						ZEPHIR_INIT_NVAR(&routeData);
						ZVAL_COPY(&routeData, _8$$7);
						zephir_read_property(&_10$$8, this_ptr, ZEND_STRL("dataGenerator"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_10$$8, "addroute", NULL, 0, &method, &routeData, handler);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &routeDatas, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_9$$7, &routeDatas, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_9$$7)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&routeData, &routeDatas, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property(&_11$$9, this_ptr, ZEND_STRL("dataGenerator"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_METHOD(NULL, &_11$$9, "addroute", NULL, 0, &method, &routeData, handler);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &routeDatas, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&routeData);
			ZEPHIR_CALL_METHOD(NULL, httpMethod, "next", NULL, 0);
			zephir_check_call_status();
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
PHP_METHOD(Ice_Mvc_Route_Collector, getData) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("dataGenerator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getdata", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

