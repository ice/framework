
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
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * Router is the standard framework router. Routing is the process of taking a command-line arguments and decomposing it
 * into parameters to determine which module, task, and action of that task should receive the request.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Router) {

	ZEPHIR_REGISTER_CLASS(Ice\\Cli, Router, ice, cli_router, ice_cli_router_method_entry, 0);

	zend_declare_property_string(ice_cli_router_ce, SL("defaultModule"), "shell", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_cli_router_ce, SL("defaultHandler"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_cli_router_ce, SL("defaultAction"), "main", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_cli_router_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_cli_router_ce->create_object = zephir_init_properties_Ice_Cli_Router;
	return SUCCESS;

}

PHP_METHOD(Ice_Cli_Router, getDefaultModule) {

	

	RETURN_MEMBER(getThis(), "defaultModule");

}

PHP_METHOD(Ice_Cli_Router, setDefaultModule) {

	zval *defaultModule;

	zephir_fetch_params(0, 1, 0, &defaultModule);



	zephir_update_property_this(getThis(), SL("defaultModule"), defaultModule TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cli_Router, getDefaultHandler) {

	

	RETURN_MEMBER(getThis(), "defaultHandler");

}

PHP_METHOD(Ice_Cli_Router, setDefaultHandler) {

	zval *defaultHandler;

	zephir_fetch_params(0, 1, 0, &defaultHandler);



	zephir_update_property_this(getThis(), SL("defaultHandler"), defaultHandler TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cli_Router, getDefaultAction) {

	

	RETURN_MEMBER(getThis(), "defaultAction");

}

PHP_METHOD(Ice_Cli_Router, setDefaultAction) {

	zval *defaultAction;

	zephir_fetch_params(0, 1, 0, &defaultAction);



	zephir_update_property_this(getThis(), SL("defaultAction"), defaultAction TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cli_Router, getModule) {

	

	RETURN_MEMBER(getThis(), "module");

}

PHP_METHOD(Ice_Cli_Router, getHandler) {

	

	RETURN_MEMBER(getThis(), "handler");

}

PHP_METHOD(Ice_Cli_Router, getAction) {

	

	RETURN_MEMBER(getThis(), "action");

}

PHP_METHOD(Ice_Cli_Router, getParams) {

	

	RETURN_MEMBER(getThis(), "params");

}

/**
 * Set defaults values
 *
 * @param array defaults
 */
PHP_METHOD(Ice_Cli_Router, setDefaults) {

	zval *defaults_param = NULL, *module = NULL, *handler = NULL, *action = NULL;
	zval *defaults = NULL;

	zephir_fetch_params(0, 1, 0, &defaults_param);

	defaults = defaults_param;


	if (zephir_array_isset_string_fetch(&module, defaults, SS("module"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("defaultModule"), module TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&handler, defaults, SS("handler"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("defaultHandler"), handler TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&action, defaults, SS("action"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("defaultAction"), action TSRMLS_CC);
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

	zend_bool _15, _18, _21;
	HashTable *_4;
	HashPosition _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, *params = NULL, *argument = NULL, *_0, *_1, *_2, **_5, *_16, *_19, *_22, *_24 = NULL, _6$$4 = zval_used_for_init, _7$$4 = zval_used_for_init, *_8$$4 = NULL, _9$$4 = zval_used_for_init, *_10$$4 = NULL, _11$$4 = zval_used_for_init, *_12$$6 = NULL, *_13$$6, *_14$$6 = NULL, *_17$$8, *_20$$9, *_23$$10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Arguments must be an array", "ice/cli/router.zep", 65);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("defaultModule"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("module"), _0 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("defaultHandler"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("handler"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("defaultAction"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("action"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	ZEPHIR_MAKE_REF(arguments);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 3, arguments);
	ZEPHIR_UNREF(arguments);
	zephir_check_call_status();
	zephir_is_iterable(arguments, &_4, &_3, 0, 0, "ice/cli/router.zep", 97);
	for (
	  ; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(argument, _5);
		ZEPHIR_SINIT_NVAR(_6$$4);
		ZVAL_LONG(&_6$$4, 0);
		ZEPHIR_SINIT_NVAR(_7$$4);
		ZVAL_LONG(&_7$$4, 2);
		ZEPHIR_INIT_NVAR(_8$$4);
		zephir_substr(_8$$4, argument, 0 , 2 , 0);
		if (!ZEPHIR_IS_STRING_IDENTICAL(_8$$4, "--")) {
			zephir_array_append(&params, argument, PH_SEPARATE, "ice/cli/router.zep", 81);
			continue;
		}
		ZEPHIR_SINIT_NVAR(_9$$4);
		ZVAL_LONG(&_9$$4, 2);
		ZEPHIR_INIT_NVAR(_10$$4);
		zephir_substr(_10$$4, argument, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CPY_WRT(argument, _10$$4);
		ZEPHIR_SINIT_NVAR(_11$$4);
		ZVAL_STRING(&_11$$4, "=", 0);
		ZEPHIR_INIT_NVAR(_10$$4);
		zephir_fast_strpos(_10$$4, argument, &_11$$4, 0 );
		if (zephir_is_true(_10$$4)) {
			ZEPHIR_INIT_NVAR(_12$$6);
			zephir_fast_explode_str(_12$$6, SL("="), argument, 2  TSRMLS_CC);
			ZEPHIR_CPY_WRT(argument, _12$$6);
			zephir_array_fetch_long(&_13$$6, argument, 1, PH_NOISY | PH_READONLY, "ice/cli/router.zep", 91 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_14$$6);
			zephir_array_fetch_long(&_14$$6, argument, 0, PH_NOISY, "ice/cli/router.zep", 91 TSRMLS_CC);
			zephir_array_update_zval(&params, _14$$6, &_13$$6, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&params, argument, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	_15 = zephir_array_isset_string(params, SS("module"));
	if (_15) {
		zephir_array_fetch_string(&_16, params, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 97 TSRMLS_CC);
		_15 = zephir_is_true(_16);
	}
	if (_15) {
		zephir_array_fetch_string(&_17$$8, params, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 98 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("module"), _17$$8 TSRMLS_CC);
		zephir_array_unset_string(&params, SS("module"), PH_SEPARATE);
	}
	_18 = zephir_array_isset_string(params, SS("handler"));
	if (_18) {
		zephir_array_fetch_string(&_19, params, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 103 TSRMLS_CC);
		_18 = zephir_is_true(_19);
	}
	if (_18) {
		zephir_array_fetch_string(&_20$$9, params, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 104 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("handler"), _20$$9 TSRMLS_CC);
		zephir_array_unset_string(&params, SS("handler"), PH_SEPARATE);
	}
	_21 = zephir_array_isset_string(params, SS("action"));
	if (_21) {
		zephir_array_fetch_string(&_22, params, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 109 TSRMLS_CC);
		_21 = zephir_is_true(_22);
	}
	if (_21) {
		zephir_array_fetch_string(&_23$$10, params, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 110 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("action"), _23$$10 TSRMLS_CC);
		zephir_array_unset_string(&params, SS("action"), PH_SEPARATE);
	}
	if (zephir_fast_count_int(params TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("params"), params TSRMLS_CC);
	}
	zephir_create_array(return_value, 4, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_24);
	zephir_read_property_this(&_24, this_ptr, SL("module"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("module"), &_24, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_24);
	zephir_read_property_this(&_24, this_ptr, SL("handler"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("handler"), &_24, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_24);
	zephir_read_property_this(&_24, this_ptr, SL("action"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("action"), &_24, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_24);
	zephir_read_property_this(&_24, this_ptr, SL("params"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("params"), &_24, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

zend_object_value zephir_init_properties_Ice_Cli_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("params"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

