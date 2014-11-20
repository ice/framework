
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
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/concat.h"


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

	zend_class_entry *_9;
	zephir_fcall_cache_entry *_5 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, *router = NULL, *handled = NULL, *module = NULL, *modules, *namespace = NULL, *path, *className = NULL, *loader, *dispatcher = NULL, *task = NULL, *_0, *_1 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_6, *_7 = NULL, *_8 = NULL, *_10, *_11, *_12 = NULL, *_13, *_14, *_15, *_16;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&router, _0, "getrouter", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&handled, router, "handle", NULL, arguments);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(module);
	zephir_array_fetch_string(&module, handled, SL("module"), PH_NOISY, "ice/cli/console.zep", 30 TSRMLS_CC);
	ZEPHIR_OBS_VAR(modules);
	zephir_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY_CC);
	if (!(zephir_array_isset(modules, module))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "Module '%s' isn't registered in the console container", 0);
		ZEPHIR_CALL_FUNCTION(&_3, "sprintf", &_4, &_2, module);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_5, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "ice/cli/console.zep", 34 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch(&_6, modules, module, PH_NOISY | PH_READONLY, "ice/cli/console.zep", 37 TSRMLS_CC);
	ZEPHIR_CPY_WRT(module, _6);
	if (Z_TYPE_P(module) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Module definition must be an array", "ice/cli/console.zep", 39);
		return;
	}
	ZEPHIR_OBS_VAR(path);
	if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
		if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_INIT_NVAR(_1);
			object_init_ex(_1, ice_exception_ce);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_STRING(&_2, "Module definition path '%s' doesn't exist", 0);
			ZEPHIR_CALL_FUNCTION(&_3, "sprintf", &_4, &_2, path);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_5, _3);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "ice/cli/console.zep", 44 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_OBS_VAR(className);
	if (!(zephir_array_isset_string_fetch(&className, module, SS("className"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(className);
		ZVAL_STRING(className, "Module", 1);
	}
	ZEPHIR_OBS_VAR(namespace);
	if (!(zephir_array_isset_string_fetch(&namespace, module, SS("namespace"), 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(namespace, className);
	}
	ZEPHIR_INIT_VAR(loader);
	object_init_ex(loader, ice_loader_ce);
	if (zephir_has_constructor(loader TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_3, loader, "addnamespace", NULL, namespace, path);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _3, "register", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_VSV(_7, namespace, "\\", className);
	ZEPHIR_CPY_WRT(className, _7);
	ZEPHIR_INIT_NVAR(module);
	zephir_fetch_safe_class(_8, className);
	_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(module, _9);
	if (zephir_has_constructor(module TSRMLS_CC)) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, module, "__construct", NULL, _10);
		zephir_check_call_status();
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&dispatcher, _11, "getdispatcher", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, dispatcher, "gethandlersuffix", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_7);
	ZEPHIR_CONCAT_VSV(_7, namespace, "\\", _12);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setdefaultnamespace", NULL, _7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, module, "registerautoloaders", NULL);
	zephir_check_call_status();
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, module, "registerservices", NULL, _13);
	zephir_check_call_status();
	zephir_array_fetch_string(&_6, handled, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 68 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodule", NULL, _6);
	zephir_check_call_status();
	zephir_array_fetch_string(&_14, handled, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 69 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "sethandler", NULL, _14);
	zephir_check_call_status();
	zephir_array_fetch_string(&_15, handled, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 70 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setaction", NULL, _15);
	zephir_check_call_status();
	zephir_array_fetch_string(&_16, handled, SL("params"), PH_NOISY | PH_READONLY, "ice/cli/console.zep", 71 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, _16);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&task, dispatcher, "dispatch", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(task);

}

