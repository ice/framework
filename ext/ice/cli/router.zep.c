
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
#include "kernel/operators.h"
#include "kernel/string.h"

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
 *<code>
 *  php index.php --module=shell --handler=main --action=main --id=1 --param="some value"
 *</code>
 *
 * @param array arguments
 * @return array
 */
PHP_METHOD(Ice_Cli_Router, handle) {

	zend_bool _16, _18, _20;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_10 = NULL;
	zval *arguments = NULL, *params, *argument = NULL, *_0, *_1, *_2, **_6, _7 = zval_used_for_init, _8 = zval_used_for_init, *_9 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14, *_15 = NULL, *_17, *_19;

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
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_3, arguments);
	Z_UNSET_ISREF_P(arguments);
	zephir_check_call_status();
	zephir_is_iterable(arguments, &_5, &_4, 0, 0, "ice/cli/router.zep", 97);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(argument, _6);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, 0);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_LONG(&_8, 2);
		ZEPHIR_CALL_FUNCTION(&_9, "substr", &_10, argument, &_7, &_8);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING_IDENTICAL(_9, "--")) {
			zephir_array_append(&params, argument, PH_SEPARATE, "ice/cli/router.zep", 81);
			continue;
		}
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, 2);
		ZEPHIR_CALL_FUNCTION(&_11, "substr", &_10, argument, &_7);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(argument, _11);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_STRING(&_7, "=", 0);
		ZEPHIR_INIT_NVAR(_12);
		zephir_fast_strpos(_12, argument, &_7, 0 );
		if (zephir_is_true(_12)) {
			ZEPHIR_INIT_NVAR(_13);
			zephir_fast_explode_str(_13, SL("="), argument, 2  TSRMLS_CC);
			ZEPHIR_CPY_WRT(argument, _13);
			zephir_array_fetch_long(&_14, argument, 1, PH_NOISY | PH_READONLY, "ice/cli/router.zep", 91 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_15);
			zephir_array_fetch_long(&_15, argument, 0, PH_NOISY, "ice/cli/router.zep", 91 TSRMLS_CC);
			zephir_array_update_zval(&params, _15, &_14, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&params, argument, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	_16 = zephir_array_isset_string(params, SS("module"));
	if (_16) {
		zephir_array_fetch_string(&_14, params, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 97 TSRMLS_CC);
		_16 = zephir_is_true(_14);
	}
	if (_16) {
		zephir_array_fetch_string(&_17, params, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 98 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_module"), _17 TSRMLS_CC);
		zephir_array_unset_string(&params, SS("module"), PH_SEPARATE);
	}
	_18 = zephir_array_isset_string(params, SS("handler"));
	if (_18) {
		zephir_array_fetch_string(&_17, params, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 103 TSRMLS_CC);
		_18 = zephir_is_true(_17);
	}
	if (_18) {
		zephir_array_fetch_string(&_19, params, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 104 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_handler"), _19 TSRMLS_CC);
		zephir_array_unset_string(&params, SS("handler"), PH_SEPARATE);
	}
	_20 = zephir_array_isset_string(params, SS("action"));
	if (_20) {
		zephir_array_fetch_string(&_17, params, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 109 TSRMLS_CC);
		_20 = zephir_is_true(_17);
	}
	if (_20) {
		zephir_array_fetch_string(&_19, params, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 110 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_action"), _19 TSRMLS_CC);
		zephir_array_unset_string(&params, SS("action"), PH_SEPARATE);
	}
	if (zephir_fast_count_int(params TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	}
	array_init_size(return_value, 6);
	ZEPHIR_OBS_NVAR(_15);
	zephir_read_property_this(&_15, this_ptr, SL("_module"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("module"), &_15, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_15);
	zephir_read_property_this(&_15, this_ptr, SL("_handler"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("handler"), &_15, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_15);
	zephir_read_property_this(&_15, this_ptr, SL("_action"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("action"), &_15, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_15);
	zephir_read_property_this(&_15, this_ptr, SL("_params"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("params"), &_15, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(Ice_Cli_Router, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_params"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

