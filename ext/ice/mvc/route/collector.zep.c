
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Collector) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route, Collector, ice, mvc_route_collector, ice_mvc_route_collector_method_entry, 0);

	zend_declare_property_null(ice_mvc_route_collector_ce, SL("routeParser"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_collector_ce, SL("dataGenerator"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Collector, setRouteParser) {

	zval *routeParser;

	zephir_fetch_params(0, 1, 0, &routeParser);



	zephir_update_property_this(this_ptr, SL("routeParser"), routeParser TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Route_Collector, setDataGenerator) {

	zval *dataGenerator;

	zephir_fetch_params(0, 1, 0, &dataGenerator);



	zephir_update_property_this(this_ptr, SL("dataGenerator"), dataGenerator TSRMLS_CC);

}

/**
 * Constructs a route collector.
 *
 * @param RouteParser   $routeParser
 * @param DataGenerator $dataGenerator
 */
PHP_METHOD(Ice_Mvc_Route_Collector, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _1;
	zval *routeParser = NULL, *dataGenerator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &routeParser, &dataGenerator);

	if (!routeParser) {
		ZEPHIR_CPY_WRT(routeParser, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(routeParser);
	}
	if (!dataGenerator) {
		ZEPHIR_CPY_WRT(dataGenerator, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(dataGenerator);
	}


	_0 = Z_TYPE_P(routeParser) != IS_NULL;
	if (_0) {
		_0 = !(zephir_instance_of_ev(routeParser, ice_mvc_route_parser_parserinterface_ce TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'routeParser' must be an instance of 'Ice\\Mvc\\Route\\Parser\\ParserInterface'", "", 0);
		return;
	}
	_1 = Z_TYPE_P(dataGenerator) != IS_NULL;
	if (_1) {
		_1 = !(zephir_instance_of_ev(dataGenerator, ice_mvc_route_datagenerator_datageneratorinterface_ce TSRMLS_CC));
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dataGenerator' must be an instance of 'Ice\\Mvc\\Route\\DataGenerator\\DataGeneratorInterface'", "", 0);
		return;
	}
	if (!(zephir_is_true(routeParser))) {
		ZEPHIR_INIT_NVAR(routeParser);
		object_init_ex(routeParser, ice_mvc_route_parser_std_ce);
		if (zephir_has_constructor(routeParser TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, routeParser, "__construct", NULL);
			zephir_check_call_status();
		}
	}
	if (!(zephir_is_true(dataGenerator))) {
		ZEPHIR_INIT_NVAR(dataGenerator);
		object_init_ex(dataGenerator, ice_mvc_route_datagenerator_groupcount_ce);
		if (zephir_has_constructor(dataGenerator TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, dataGenerator, "__construct", NULL);
			zephir_check_call_status();
		}
	}
	zephir_update_property_this(this_ptr, SL("routeParser"), routeParser TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("dataGenerator"), dataGenerator TSRMLS_CC);
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
 */
PHP_METHOD(Ice_Mvc_Route_Collector, addRoute) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *route = NULL;
	zval *httpMethod = NULL, *route_param = NULL, *handler = NULL, *routeData = NULL, *method = NULL, *_0, **_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &httpMethod, &route_param, &handler);

	ZEPHIR_SEPARATE_PARAM(httpMethod);
	zephir_get_strval(route, route_param);
	if (!handler) {
		handler = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("routeParser"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&routeData, _0, "parse", NULL, route);
	zephir_check_call_status();
	if (Z_TYPE_P(httpMethod) == IS_STRING) {
		ZEPHIR_CPY_WRT(method, httpMethod);
		ZEPHIR_INIT_NVAR(httpMethod);
		array_init_size(httpMethod, 2);
		zephir_array_fast_append(httpMethod, method);
	}
	zephir_is_iterable(httpMethod, &_2, &_1, 0, 0, "ice/mvc/route/collector.zep", 58);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(method, _3);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("dataGenerator"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _4, "addroute", NULL, method, routeData, handler);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the collected route data, as provided by the data generator.
 *
 * @return array
 */
PHP_METHOD(Ice_Mvc_Route_Collector, getData) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dataGenerator"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getdata", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

