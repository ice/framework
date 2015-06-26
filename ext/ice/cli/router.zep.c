
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
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/operators.h"

ZEPHIR_INIT_CLASS(Ice_Cli_Router) {

	ZEPHIR_REGISTER_CLASS(Ice\\Cli, Router, ice, cli_router, ice_cli_router_method_entry, 0);

	zend_declare_property_string(ice_cli_router_ce, SL("_defaultModule"), "shell", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_cli_router_ce, SL("_defaultHandler"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_cli_router_ce, SL("_defaultAction"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("_handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_cli_router_ce->create_object = zephir_init_properties;
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

/**
 * Set defaults values
 *
 * @param array defaults
 */
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
 * Handles routing information received from command-line arguments.
 *
 * <pre><code>
 *  php index.php --module=shell --handler=main --action=main --id=1 --param="some value"
 * </code></pre>
 *
 * @param array arguments
 * @return array
 */
PHP_METHOD(Ice_Cli_Router, handle) {

	zend_bool _15, _17, _19;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, *params, *argument = NULL, *_0, *_1, *_2, **_5, _6 = zval_used_for_init, _7 = zval_used_for_init, *_8 = NULL, _9 = zval_used_for_init, *_10 = NULL, _11 = zval_used_for_init, *_12 = NULL, *_13, *_14 = NULL, *_16, *_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Arguments must be an array", "ice/cli/router.zep", 65);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultModule"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_module"), _0 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultHandler"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_handler"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAction"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_action"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	Z_SET_ISREF_P(arguments);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 4, arguments);
	Z_UNSET_ISREF_P(arguments);
	zephir_check_call_status();
	zephir_is_iterable(arguments, &_4, &_3, 0, 0, "ice/cli/router.zep", 97);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(argument, _5);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, 0);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, 2);
		ZEPHIR_INIT_NVAR(_8);
		zephir_substr(_8, argument, 0 , 2 , 0);
		if (!ZEPHIR_IS_STRING_IDENTICAL(_8, "--")) {
			zephir_array_append(&params, argument, PH_SEPARATE, "ice/cli/router.zep", 81);
			continue;
		}
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_LONG(&_9, 2);
		ZEPHIR_INIT_NVAR(_10);
		zephir_substr(_10, argument, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CPY_WRT(argument, _10);
		ZEPHIR_SINIT_NVAR(_11);
		ZVAL_STRING(&_11, "=", 0);
		ZEPHIR_INIT_NVAR(_10);
		zephir_fast_strpos(_10, argument, &_11, 0 );
		if (zephir_is_true(_10)) {
			ZEPHIR_INIT_NVAR(_12);
			zephir_fast_explode_str(_12, SL("="), argument, 2  TSRMLS_CC);
			ZEPHIR_CPY_WRT(argument, _12);
			zephir_array_fetch_long(&_13, argument, 1, PH_NOISY | PH_READONLY, "ice/cli/router.zep", 91 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_14);
			zephir_array_fetch_long(&_14, argument, 0, PH_NOISY, "ice/cli/router.zep", 91 TSRMLS_CC);
			zephir_array_update_zval(&params, _14, &_13, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&params, argument, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	_15 = zephir_array_isset_string(params, SS("module"));
	if (_15) {
		zephir_array_fetch_string(&_13, params, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 97 TSRMLS_CC);
		_15 = zephir_is_true(_13);
	}
	if (_15) {
		zephir_array_fetch_string(&_16, params, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 98 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_module"), _16 TSRMLS_CC);
		zephir_array_unset_string(&params, SS("module"), PH_SEPARATE);
	}
	_17 = zephir_array_isset_string(params, SS("handler"));
	if (_17) {
		zephir_array_fetch_string(&_16, params, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 103 TSRMLS_CC);
		_17 = zephir_is_true(_16);
	}
	if (_17) {
		zephir_array_fetch_string(&_18, params, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 104 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_handler"), _18 TSRMLS_CC);
		zephir_array_unset_string(&params, SS("handler"), PH_SEPARATE);
	}
	_19 = zephir_array_isset_string(params, SS("action"));
	if (_19) {
		zephir_array_fetch_string(&_16, params, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 109 TSRMLS_CC);
		_19 = zephir_is_true(_16);
	}
	if (_19) {
		zephir_array_fetch_string(&_18, params, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 110 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_action"), _18 TSRMLS_CC);
		zephir_array_unset_string(&params, SS("action"), PH_SEPARATE);
	}
	if (zephir_fast_count_int(params TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	}
	zephir_create_array(return_value, 4, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_14);
	zephir_read_property_this(&_14, this_ptr, SL("_module"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("module"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_14);
	zephir_read_property_this(&_14, this_ptr, SL("_handler"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("handler"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_14);
	zephir_read_property_this(&_14, this_ptr, SL("_action"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("action"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_14);
	zephir_read_property_this(&_14, this_ptr, SL("_params"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("params"), &_14, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_params"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

