
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Auth driver interface.
 *
 * @package     Ice/Auth
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_DriverInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Auth\\Driver, DriverInterface, ice, auth_driver_driverinterface, NULL);

	return SUCCESS;

}

