
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
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Cli_Router)
{
	ZEPHIR_REGISTER_CLASS(Ice\\Cli, Router, ice, cli_router, ice_cli_router_method_entry, 0);

	zend_declare_property_string(ice_cli_router_ce, SL("defaultModule"), "shell", ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_cli_router_ce, SL("defaultHandler"), "main", ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_cli_router_ce, SL("defaultAction"), "main", ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_cli_router_ce, SL("module"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_cli_router_ce, SL("handler"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_cli_router_ce, SL("action"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_cli_router_ce, SL("params"), ZEND_ACC_PROTECTED);
	ice_cli_router_ce->create_object = zephir_init_properties_Ice_Cli_Router;

	return SUCCESS;
}

PHP_METHOD(Ice_Cli_Router, getDefaultModule)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultModule");
}

PHP_METHOD(Ice_Cli_Router, setDefaultModule)
{
	zval *defaultModule, defaultModule_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultModule_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultModule)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &defaultModule);


	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), defaultModule);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cli_Router, getDefaultHandler)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultHandler");
}

PHP_METHOD(Ice_Cli_Router, setDefaultHandler)
{
	zval *defaultHandler, defaultHandler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultHandler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultHandler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &defaultHandler);


	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultHandler"), defaultHandler);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cli_Router, getDefaultAction)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultAction");
}

PHP_METHOD(Ice_Cli_Router, setDefaultAction)
{
	zval *defaultAction, defaultAction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultAction_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultAction)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &defaultAction);


	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAction"), defaultAction);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cli_Router, getModule)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "module");
}

PHP_METHOD(Ice_Cli_Router, getHandler)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "handler");
}

PHP_METHOD(Ice_Cli_Router, getAction)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "action");
}

PHP_METHOD(Ice_Cli_Router, getParams)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "params");
}

/**
 * Set defaults values
 *
 * @param array defaults
 */
PHP_METHOD(Ice_Cli_Router, setDefaults)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaults_param = NULL, module, handler, action;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&action);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(defaults)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults_param);
	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);


	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), &module);
	}
	if (zephir_array_isset_string_fetch(&handler, &defaults, SL("handler"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultHandler"), &handler);
	}
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAction"), &action);
	}
	ZEPHIR_MM_RESTORE();
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
PHP_METHOD(Ice_Cli_Router, handle)
{
	zend_bool _23, _26, _29;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, arguments_sub, __$null, params, argument, _0, _1, _2, *_3, _4, _24, _27, _30, _32, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _11$$6, _12$$6, _13$$6, _14$$8, _15$$8, _16$$8, _17$$8, _18$$8, _19$$8, _20$$10, _21$$10, _22$$10, _25$$12, _28$$13, _31$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_31$$14);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Arguments must be an array", "ice/cli/router.zep", 64);
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("module"), &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("defaultHandler"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("defaultAction"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("action"), &_2);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_MAKE_REF(arguments);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 2, arguments);
	ZEPHIR_UNREF(arguments);
	zephir_check_call_status();
	zephir_is_iterable(arguments, 0, "ice/cli/router.zep", 96);
	if (Z_TYPE_P(arguments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(arguments), _3)
		{
			ZEPHIR_INIT_NVAR(&argument);
			ZVAL_COPY(&argument, _3);
			ZVAL_LONG(&_5$$4, 0);
			ZVAL_LONG(&_6$$4, 2);
			ZEPHIR_INIT_NVAR(&_7$$4);
			zephir_substr(&_7$$4, &argument, 0 , 2 , 0);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_7$$4, "--")) {
				zephir_array_append(&params, &argument, PH_SEPARATE, "ice/cli/router.zep", 80);
				continue;
			}
			ZVAL_LONG(&_8$$4, 2);
			ZEPHIR_INIT_NVAR(&_9$$4);
			zephir_substr(&_9$$4, &argument, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CPY_WRT(&argument, &_9$$4);
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "=");
			ZEPHIR_INIT_NVAR(&_10$$4);
			zephir_fast_strpos(&_10$$4, &argument, &_9$$4, 0 );
			if (zephir_is_true(&_10$$4)) {
				ZEPHIR_INIT_NVAR(&_11$$6);
				zephir_fast_explode_str(&_11$$6, SL("="), &argument, 2 );
				ZEPHIR_CPY_WRT(&argument, &_11$$6);
				zephir_array_fetch_long(&_12$$6, &argument, 1, PH_NOISY | PH_READONLY, "ice/cli/router.zep", 90);
				ZEPHIR_OBS_NVAR(&_13$$6);
				zephir_array_fetch_long(&_13$$6, &argument, 0, PH_NOISY, "ice/cli/router.zep", 90);
				zephir_array_update_zval(&params, &_13$$6, &_12$$6, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&params, &argument, &__$null, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, arguments, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, arguments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&argument, arguments, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_14$$8, 0);
				ZVAL_LONG(&_15$$8, 2);
				ZEPHIR_INIT_NVAR(&_16$$8);
				zephir_substr(&_16$$8, &argument, 0 , 2 , 0);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_16$$8, "--")) {
					zephir_array_append(&params, &argument, PH_SEPARATE, "ice/cli/router.zep", 80);
					continue;
				}
				ZVAL_LONG(&_17$$8, 2);
				ZEPHIR_INIT_NVAR(&_18$$8);
				zephir_substr(&_18$$8, &argument, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CPY_WRT(&argument, &_18$$8);
				ZEPHIR_INIT_NVAR(&_18$$8);
				ZVAL_STRING(&_18$$8, "=");
				ZEPHIR_INIT_NVAR(&_19$$8);
				zephir_fast_strpos(&_19$$8, &argument, &_18$$8, 0 );
				if (zephir_is_true(&_19$$8)) {
					ZEPHIR_INIT_NVAR(&_20$$10);
					zephir_fast_explode_str(&_20$$10, SL("="), &argument, 2 );
					ZEPHIR_CPY_WRT(&argument, &_20$$10);
					zephir_array_fetch_long(&_21$$10, &argument, 1, PH_NOISY | PH_READONLY, "ice/cli/router.zep", 90);
					ZEPHIR_OBS_NVAR(&_22$$10);
					zephir_array_fetch_long(&_22$$10, &argument, 0, PH_NOISY, "ice/cli/router.zep", 90);
					zephir_array_update_zval(&params, &_22$$10, &_21$$10, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&params, &argument, &__$null, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, arguments, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&argument);
	_23 = zephir_array_isset_string(&params, SL("module"));
	if (_23) {
		zephir_array_fetch_string(&_24, &params, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 96);
		_23 = zephir_is_true(&_24);
	}
	if (_23) {
		zephir_array_fetch_string(&_25$$12, &params, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 97);
		zephir_update_property_zval(this_ptr, ZEND_STRL("module"), &_25$$12);
		zephir_array_unset_string(&params, SL("module"), PH_SEPARATE);
	}
	_26 = zephir_array_isset_string(&params, SL("handler"));
	if (_26) {
		zephir_array_fetch_string(&_27, &params, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 102);
		_26 = zephir_is_true(&_27);
	}
	if (_26) {
		zephir_array_fetch_string(&_28$$13, &params, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 103);
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &_28$$13);
		zephir_array_unset_string(&params, SL("handler"), PH_SEPARATE);
	}
	_29 = zephir_array_isset_string(&params, SL("action"));
	if (_29) {
		zephir_array_fetch_string(&_30, &params, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 108);
		_29 = zephir_is_true(&_30);
	}
	if (_29) {
		zephir_array_fetch_string(&_31$$14, &params, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 109);
		zephir_update_property_zval(this_ptr, ZEND_STRL("action"), &_31$$14);
		zephir_array_unset_string(&params, SL("action"), PH_SEPARATE);
	}
	if (zephir_fast_count_int(&params)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &params);
	}
	zephir_create_array(return_value, 4, 0);
	ZEPHIR_OBS_VAR(&_32);
	zephir_read_property(&_32, this_ptr, ZEND_STRL("module"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("module"), &_32, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_32);
	zephir_read_property(&_32, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("handler"), &_32, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_32);
	zephir_read_property(&_32, this_ptr, ZEND_STRL("action"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("action"), &_32, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_32);
	zephir_read_property(&_32, this_ptr, ZEND_STRL("params"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("params"), &_32, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

zend_object *zephir_init_properties_Ice_Cli_Router(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

