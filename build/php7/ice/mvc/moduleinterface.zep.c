
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Module interface.
 *
 * @package     Ice/Mvc
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_ModuleInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Mvc, ModuleInterface, ice, mvc_moduleinterface, ice_mvc_moduleinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Ice_Mvc_ModuleInterface, registerAutoloaders);

ZEPHIR_DOC_METHOD(Ice_Mvc_ModuleInterface, registerServices);

