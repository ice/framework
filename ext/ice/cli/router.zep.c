
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


/**
 * Router is the standard framework router. Routing is the
 * process of taking a command-line arguments and
 * decomposing it into parameters to determine which module, task, and
 * action of that task should receive the request
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Router) {

	ZEPHIR_REGISTER_CLASS(Ice\\Cli, Router, ice, cli_router, ice_cli_router_method_entry, 0);

	zend_declare_property_string(ice_cli_router_ce, SL("_defaultModule"), "shell", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_cli_router_ce, SL("_defaultHandler"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_cli_router_ce, SL("_defaultAction"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("_handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Cli_Router, getDefaultModule) {


	RETURN_MEMBER(this_ptr, "_defaultModule");

}

PHP_METHOD(Ice_Cli_Router, setDefaultModule) {

	zval *defaultModule;

	zephir_fetch_params(0, 1, 0, &defaultModule);



	zephir_update_property_this(this_ptr, SL("_defaultModule"), defaultModule TSRMLS_CC);

}

PHP_METHOD(Ice_Cli_Router, getDefaultHandler) {


	RETURN_MEMBER(this_ptr, "_defaultHandler");

}

PHP_METHOD(Ice_Cli_Router, setDefaultHandler) {

	zval *defaultHandler;

	zephir_fetch_params(0, 1, 0, &defaultHandler);



	zephir_update_property_this(this_ptr, SL("_defaultHandler"), defaultHandler TSRMLS_CC);

}

PHP_METHOD(Ice_Cli_Router, getDefaultAction) {


	RETURN_MEMBER(this_ptr, "_defaultAction");

}

PHP_METHOD(Ice_Cli_Router, setDefaultAction) {

	zval *defaultAction;

	zephir_fetch_params(0, 1, 0, &defaultAction);



	zephir_update_property_this(this_ptr, SL("_defaultAction"), defaultAction TSRMLS_CC);

}

PHP_METHOD(Ice_Cli_Router, getModule) {


	RETURN_MEMBER(this_ptr, "_module");

}

PHP_METHOD(Ice_Cli_Router, getHandler) {


	RETURN_MEMBER(this_ptr, "_handler");

}

PHP_METHOD(Ice_Cli_Router, getAction) {


	RETURN_MEMBER(this_ptr, "_action");

}

PHP_METHOD(Ice_Cli_Router, getParams) {


	RETURN_MEMBER(this_ptr, "_params");

}

PHP_METHOD(Ice_Cli_Router, setDefaults) {

	zval *defaults_param = NULL, *module, *handler, *action;
	zval *defaults = NULL;

	zephir_fetch_params(0, 1, 0, &defaults_param);

	defaults = defaults_param;



	if (zephir_array_isset_string_fetch(&module, defaults, SS("module"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultModule"), module TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&handler, defaults, SS("handler"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultHandler"), handler TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&action, defaults, SS("action"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultAction"), action TSRMLS_CC);
	}

}

/**
 * Handles routing information received from command-line arguments
 * php index.php module handler action param1 param2
 *
 * @param array arguments
 * @return array
 */
PHP_METHOD(Ice_Cli_Router, handle) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int _0, ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, *module = NULL, *handler = NULL, *action = NULL, *params = NULL, _1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Arguments must be an array", "ice/cli/router.zep", 53);
		return;
	}
	ZEPHIR_OBS_VAR(module);
	zephir_read_property_this(&module, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(handler);
	zephir_read_property_this(&handler, this_ptr, SL("_defaultHandler"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(action);
	zephir_read_property_this(&action, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	do {
		_0 = zephir_fast_count_int(arguments TSRMLS_CC);
		if (_0 == 1) {
			break;
		}
		if (_0 == 2) {
			ZEPHIR_OBS_NVAR(module);
			zephir_array_fetch_long(&module, arguments, 1, PH_NOISY, "ice/cli/router.zep", 66 TSRMLS_CC);
			break;
		}
		if (_0 == 3) {
			ZEPHIR_OBS_NVAR(module);
			zephir_array_fetch_long(&module, arguments, 1, PH_NOISY, "ice/cli/router.zep", 69 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(handler);
			zephir_array_fetch_long(&handler, arguments, 2, PH_NOISY, "ice/cli/router.zep", 70 TSRMLS_CC);
			break;
		}
		if (_0 == 4) {
			ZEPHIR_OBS_NVAR(module);
			zephir_array_fetch_long(&module, arguments, 1, PH_NOISY, "ice/cli/router.zep", 73 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(handler);
			zephir_array_fetch_long(&handler, arguments, 2, PH_NOISY, "ice/cli/router.zep", 74 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(action);
			zephir_array_fetch_long(&action, arguments, 3, PH_NOISY, "ice/cli/router.zep", 75 TSRMLS_CC);
			break;
		}
		ZEPHIR_OBS_NVAR(module);
		zephir_array_fetch_long(&module, arguments, 1, PH_NOISY, "ice/cli/router.zep", 78 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(handler);
		zephir_array_fetch_long(&handler, arguments, 2, PH_NOISY, "ice/cli/router.zep", 79 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(action);
		zephir_array_fetch_long(&action, arguments, 3, PH_NOISY, "ice/cli/router.zep", 80 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 4);
		ZEPHIR_CALL_FUNCTION(&params, "array_slice", &_2, arguments, &_1);
		zephir_check_call_status();
		break;
	} while(0);

	zephir_update_property_this(this_ptr, SL("_module"), module TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	array_init_size(return_value, 6);
	zephir_array_update_string(&return_value, SL("module"), &module, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("action"), &action, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("params"), &params, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

