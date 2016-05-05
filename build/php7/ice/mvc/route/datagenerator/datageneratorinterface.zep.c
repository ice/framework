
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_DataGenerator_DataGeneratorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Mvc\\Route\\DataGenerator, DataGeneratorInterface, ice, mvc_route_datagenerator_datageneratorinterface, ice_mvc_route_datagenerator_datageneratorinterface_method_entry);

	return SUCCESS;

}

/**
 * Adds a route to the data generator. The route data uses the
 * same format that is returned by RouterParser::parser().
 *
 * The handler doesn't necessarily need to be a callable, it
 * can be arbitrary data that will be returned when the route
 * matches.
 *
 * @param string $httpMethod
 * @param array $routeData
 * @param mixed $handler
 */
ZEPHIR_DOC_METHOD(Ice_Mvc_Route_DataGenerator_DataGeneratorInterface, addRoute);

/**
 * Returns dispatcher data in some unspecified format, which
 * depends on the used method of dispatch.
 */
ZEPHIR_DOC_METHOD(Ice_Mvc_Route_DataGenerator_DataGeneratorInterface, getData);

