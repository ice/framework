
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * Every command-line task should extend this class that encapsulates all the task functionality. A task can be used to
 * run "tasks" such as migrations, cronjobs, unit-tests, or anything that you want. The Task class should at least have
 * a "mainAction" method.
 *
 * @package     Ice/Di/Access
 * @category    Handler
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Task) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Cli, Task, ice, cli_task, ice_di_access_ce, ice_cli_task_method_entry, 0);

	return SUCCESS;

}

/**
 * Task constructor. Run onConstruct() if method exist.
 */
PHP_METHOD(Ice_Cli_Task, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, ice_cli_task_ce, this_ptr, "__construct", &_0, 29);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

