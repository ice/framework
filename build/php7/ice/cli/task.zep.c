
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
 * Every command-line task should extend this class that encapsulates all the task functionality. A task can be used to
 * run "tasks" such as migrations, cronjobs, unit-tests, or anything that you want. The Task class should at least have
 * a "mainAction" method.
 *
 * @package     Ice/Di/Access
 * @category    Handler
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Task) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Cli, Task, ice, cli_task, ice_di_access_ce, NULL, 0);

	return SUCCESS;

}

