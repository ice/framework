
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * This component allows to create CLI applications
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Console) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Cli, Console, ice, cli_console, ice_di_access_ce, ice_cli_console_method_entry, 0);

	zend_declare_property_null(ice_cli_console_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Cli_Console, getModules) {


	RETURN_MEMBER(this_ptr, "_modules");

}

PHP_METHOD(Ice_Cli_Console, setModules) {

	zval *modules;

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);

}

/**
 * Handle the whole command-line tasks
 *
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Ice_Cli_Console, handle) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, *router = NULL, *response = NULL, *dispatcher = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&router, _0, "getrouter", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, router, "handle", NULL, arguments);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&dispatcher, _1, "getdispatcher", NULL);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodules", NULL, _2);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, response, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 32 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodule", NULL, _3);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, response, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 33 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "sethandler", NULL, _4);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, response, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 34 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setaction", NULL, _5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_6, response, SL("params"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 35 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, _6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, dispatcher, "dispatch", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(response);

}

