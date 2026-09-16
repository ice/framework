
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
 * @copyright   (c) Ice Team
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

	RETURN_MEMBER(getThis(), "defaultModule");
}

PHP_METHOD(Ice_Cli_Router, setDefaultModule)
{
	zval *defaultModule, defaultModule_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultModule_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultModule", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultModule)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &defaultModule);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 112, defaultModule);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cli_Router, getDefaultHandler)
{

	RETURN_MEMBER(getThis(), "defaultHandler");
}

PHP_METHOD(Ice_Cli_Router, setDefaultHandler)
{
	zval *defaultHandler, defaultHandler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultHandler_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultHandler", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultHandler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &defaultHandler);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 113, defaultHandler);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cli_Router, getDefaultAction)
{

	RETURN_MEMBER(getThis(), "defaultAction");
}

PHP_METHOD(Ice_Cli_Router, setDefaultAction)
{
	zval *defaultAction, defaultAction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultAction_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultAction", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultAction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &defaultAction);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 114, defaultAction);
	RETURN_THISW();
}

PHP_METHOD(Ice_Cli_Router, getModule)
{

	RETURN_MEMBER(getThis(), "module");
}

PHP_METHOD(Ice_Cli_Router, getHandler)
{

	RETURN_MEMBER(getThis(), "handler");
}

PHP_METHOD(Ice_Cli_Router, getAction)
{

	RETURN_MEMBER(getThis(), "action");
}

PHP_METHOD(Ice_Cli_Router, getParams)
{

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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("defaultHandler", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("defaultAction", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(defaults, defaults_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &defaults_param);
	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);
	zephir_memory_observe(&module);
	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 112, &module);
	}
	zephir_memory_observe(&handler);
	if (zephir_array_isset_string_fetch(&handler, &defaults, SL("handler"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 113, &handler);
	}
	zephir_memory_observe(&action);
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 114, &action);
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
	zend_bool _16, _26, _29, _32;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, arguments_sub, __$null, params, argument, _0, _1, _2, *_3, _4, *_5, _15, _27, _30, _33, _35, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _11$$4, _12$$6, _13$$6, _14$$6, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8, _22$$8, _23$$10, _24$$10, _25$$10, _28$$12, _31$$13, _34$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_34$$14);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("module", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("defaultHandler", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("handler", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("defaultAction", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("action", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("params", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &arguments);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}
	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Arguments must be an array", "ice/cli/router.zep", 64);
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 112, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 115, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_2, 113, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 116, &_1);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_4, 114, PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 117, &_2);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_MAKE_REF(arguments);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 2, arguments);
	ZEPHIR_UNREF(arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(arguments) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, arguments);
		_3 = &_4;
	} else {
		_3 = arguments;
	}
	zephir_is_iterable(_3, 0, "ice/cli/router.zep", 96);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&argument);
			ZVAL_COPY(&argument, _5);
			ZVAL_LONG(&_6$$4, 0);
			ZVAL_LONG(&_7$$4, 2);
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_substr(&_8$$4, &argument, 0 , 2 , 0);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_8$$4, "--")) {
				zephir_array_append(&params, &argument, PH_SEPARATE, "ice/cli/router.zep", 80);
				continue;
			}
			ZVAL_LONG(&_9$$4, 2);
			ZEPHIR_INIT_NVAR(&_10$$4);
			zephir_substr(&_10$$4, &argument, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CPY_WRT(&argument, &_10$$4);
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "=");
			ZEPHIR_INIT_NVAR(&_11$$4);
			zephir_fast_strpos(&_11$$4, &argument, &_10$$4, 0 );
			if (zephir_is_true(&_11$$4)) {
				ZEPHIR_INIT_NVAR(&_12$$6);
				zephir_fast_explode_str(&_12$$6, SL("="), &argument, 2 );
				ZEPHIR_CPY_WRT(&argument, &_12$$6);
				ZEPHIR_OBS_NVAR(&_13$$6);
				zephir_array_fetch_long(&_13$$6, &argument, 1, PH_NOISY, "ice/cli/router.zep", 90);
				ZEPHIR_OBS_NVAR(&_14$$6);
				zephir_array_fetch_long(&_14$$6, &argument, 0, PH_NOISY, "ice/cli/router.zep", 90);
				zephir_array_update_zval(&params, &_14$$6, &_13$$6, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&params, &argument, &__$null, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&argument, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_17$$8, 0);
				ZVAL_LONG(&_18$$8, 2);
				ZEPHIR_INIT_NVAR(&_19$$8);
				zephir_substr(&_19$$8, &argument, 0 , 2 , 0);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_19$$8, "--")) {
					zephir_array_append(&params, &argument, PH_SEPARATE, "ice/cli/router.zep", 80);
					continue;
				}
				ZVAL_LONG(&_20$$8, 2);
				ZEPHIR_INIT_NVAR(&_21$$8);
				zephir_substr(&_21$$8, &argument, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CPY_WRT(&argument, &_21$$8);
				ZEPHIR_INIT_NVAR(&_21$$8);
				ZVAL_STRING(&_21$$8, "=");
				ZEPHIR_INIT_NVAR(&_22$$8);
				zephir_fast_strpos(&_22$$8, &argument, &_21$$8, 0 );
				if (zephir_is_true(&_22$$8)) {
					ZEPHIR_INIT_NVAR(&_23$$10);
					zephir_fast_explode_str(&_23$$10, SL("="), &argument, 2 );
					ZEPHIR_CPY_WRT(&argument, &_23$$10);
					ZEPHIR_OBS_NVAR(&_24$$10);
					zephir_array_fetch_long(&_24$$10, &argument, 1, PH_NOISY, "ice/cli/router.zep", 90);
					ZEPHIR_OBS_NVAR(&_25$$10);
					zephir_array_fetch_long(&_25$$10, &argument, 0, PH_NOISY, "ice/cli/router.zep", 90);
					zephir_array_update_zval(&params, &_25$$10, &_24$$10, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&params, &argument, &__$null, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&argument);
	_26 = zephir_array_isset_value_string(&params, SL("module"));
	if (_26) {
		zephir_memory_observe(&_27);
		zephir_array_fetch_string(&_27, &params, SL("module"), PH_NOISY, "ice/cli/router.zep", 96);
		_26 = zephir_is_true(&_27);
	}
	if (_26) {
		zephir_memory_observe(&_28$$12);
		zephir_array_fetch_string(&_28$$12, &params, SL("module"), PH_NOISY, "ice/cli/router.zep", 97);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 115, &_28$$12);
		zephir_array_unset_string(&params, SL("module"), PH_SEPARATE);
	}
	_29 = zephir_array_isset_value_string(&params, SL("handler"));
	if (_29) {
		zephir_memory_observe(&_30);
		zephir_array_fetch_string(&_30, &params, SL("handler"), PH_NOISY, "ice/cli/router.zep", 102);
		_29 = zephir_is_true(&_30);
	}
	if (_29) {
		zephir_memory_observe(&_31$$13);
		zephir_array_fetch_string(&_31$$13, &params, SL("handler"), PH_NOISY, "ice/cli/router.zep", 103);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 116, &_31$$13);
		zephir_array_unset_string(&params, SL("handler"), PH_SEPARATE);
	}
	_32 = zephir_array_isset_value_string(&params, SL("action"));
	if (_32) {
		zephir_memory_observe(&_33);
		zephir_array_fetch_string(&_33, &params, SL("action"), PH_NOISY, "ice/cli/router.zep", 108);
		_32 = zephir_is_true(&_33);
	}
	if (_32) {
		zephir_memory_observe(&_34$$14);
		zephir_array_fetch_string(&_34$$14, &params, SL("action"), PH_NOISY, "ice/cli/router.zep", 109);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 117, &_34$$14);
		zephir_array_unset_string(&params, SL("action"), PH_SEPARATE);
	}
	if (zephir_fast_count_int(&params)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 118, &params);
	}
	zephir_create_array(return_value, 4, 0);
	zephir_memory_observe(&_35);
	zephir_read_property_cached(&_35, this_ptr, _zephir_prop_1, 115, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("module"), &_35, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_35);
	zephir_read_property_cached(&_35, this_ptr, _zephir_prop_3, 116, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("handler"), &_35, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_35);
	zephir_read_property_cached(&_35, this_ptr, _zephir_prop_5, 117, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("action"), &_35, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_35);
	zephir_read_property_cached(&_35, this_ptr, _zephir_prop_6, 118, PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("params"), &_35, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

zend_object *zephir_init_properties_Ice_Cli_Router(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
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

