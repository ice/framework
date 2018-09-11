
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Dispatching is the process of taking the command-line arguments, extracting the module name, task name, action name
 * and optional parameters contained in it, and then instantiating a task and calling an action on it.
 *
 * @package     Ice/Dispatcher
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Cli, Dispatcher, ice, cli_dispatcher, ice_dispatcher_ce, NULL, 0);

	zend_declare_property_string(ice_cli_dispatcher_ce, SL("handlers"), "Tasks", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_cli_dispatcher_ce, SL("handlerSuffix"), "Task", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

