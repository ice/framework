
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_DispatcherInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Mvc\\Route\\Dispatcher, DispatcherInterface, ice, mvc_route_dispatcher_dispatcherinterface, ice_mvc_route_dispatcher_dispatcherinterface_method_entry);

	return SUCCESS;

}

/**
 * Dispatches against the provided HTTP method verb and URI.
 *
 * Returns array with one of the following formats:
 *
 *  [self::NOT_FOUND]
 *  [self::METHOD_NOT_ALLOWED, ['GET', 'OTHER_ALLOWED_METHODS']]
 *  [self::FOUND, $handler, ['varName' => 'value', ...]]
 *
 * @param string $httpMethod
 * @param string $uri
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Ice_Mvc_Route_Dispatcher_DispatcherInterface, dispatch);

