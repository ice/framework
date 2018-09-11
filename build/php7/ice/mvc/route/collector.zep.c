
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

	zend_declare_property_null(ice_mvc_route_collector_ce, SL("routeParser"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_collector_ce, SL("dataGenerator"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Collector, setRouteParser) {

	zval *routeParser, routeParser_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeParser_sub);

	zephir_fetch_params(0, 1, 0, &routeParser);



	zephir_update_property_zval(this_ptr, SL("routeParser"), routeParser);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route_Collector, setDataGenerator) {

	zval *dataGenerator, dataGenerator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataGenerator_sub);

	zephir_fetch_params(0, 1, 0, &dataGenerator);



	zephir_update_property_zval(this_ptr, SL("dataGenerator"), dataGenerator);
	RETURN_THISW();

}

/**
 * Constructs a route collector.
 *
 * @param RouteParser   $routeParser
 * @param DataGenerator $dataGenerator
 */
PHP_METHOD(Ice_Mvc_Route_Collector, __construct) {

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
		if (zephir_has_constructor(routeParser TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, routeParser, "__construct", NULL, 0);
			zephir_check_call_status();
		}
	}
	if (!(zephir_is_true(dataGenerator))) {
		ZEPHIR_INIT_NVAR(dataGenerator);
		object_init_ex(dataGenerator, ice_mvc_route_datagenerator_groupcount_ce);
		if (zephir_has_constructor(dataGenerator TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, dataGenerator, "__construct", NULL, 0);
			zephir_check_call_status();
		}
	}
	zephir_update_property_zval(this_ptr, SL("routeParser"), routeParser);
	zephir_update_property_zval(this_ptr, SL("dataGenerator"), dataGenerator);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval route;
	zval *httpMethod = NULL, httpMethod_sub, *route_param = NULL, *handler = NULL, handler_sub, __$null, routeDatas, routeData, method, _0, *_1, *_2$$4, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethod_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&routeDatas);
	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&route);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &httpMethod, &route_param, &handler);

	ZEPHIR_SEPARATE_PARAM(httpMethod);
	zephir_get_strval(&route, route_param);
	if (!handler) {
		handler = &handler_sub;
		handler = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("routeParser"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&routeDatas, &_0, "parse", NULL, 0, &route);
	zephir_check_call_status();
	if (Z_TYPE_P(httpMethod) == IS_STRING) {
		ZEPHIR_CPY_WRT(&method, httpMethod);
		ZEPHIR_INIT_NVAR(httpMethod);
		zephir_create_array(httpMethod, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(httpMethod, &method);
	}
	zephir_is_iterable(httpMethod, 0, "ice/mvc/route/collector.zep", 62);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(httpMethod), _1)
	{
		ZEPHIR_INIT_NVAR(&method);
		ZVAL_COPY(&method, _1);
		zephir_is_iterable(&routeDatas, 0, "ice/mvc/route/collector.zep", 60);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routeDatas), _2$$4)
		{
			ZEPHIR_INIT_NVAR(&routeData);
			ZVAL_COPY(&routeData, _2$$4);
			zephir_read_property(&_3$$5, this_ptr, SL("dataGenerator"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_3$$5, "addroute", NULL, 0, &method, &routeData, handler);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&routeData);
	} ZEND_HASH_FOREACH_END();
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("dataGenerator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getdata", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

