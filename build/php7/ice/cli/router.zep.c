
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultModule");

}

PHP_METHOD(Ice_Cli_Router, setDefaultModule) {

	zval *defaultModule, defaultModule_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultModule_sub);

	zephir_fetch_params(0, 1, 0, &defaultModule);



	zephir_update_property_zval(this_ptr, SL("defaultModule"), defaultModule);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cli_Router, getDefaultHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultHandler");

}

PHP_METHOD(Ice_Cli_Router, setDefaultHandler) {

	zval *defaultHandler, defaultHandler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultHandler_sub);

	zephir_fetch_params(0, 1, 0, &defaultHandler);



	zephir_update_property_zval(this_ptr, SL("defaultHandler"), defaultHandler);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cli_Router, getDefaultAction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultAction");

}

PHP_METHOD(Ice_Cli_Router, setDefaultAction) {

	zval *defaultAction, defaultAction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultAction_sub);

	zephir_fetch_params(0, 1, 0, &defaultAction);



	zephir_update_property_zval(this_ptr, SL("defaultAction"), defaultAction);
	RETURN_THISW();

}

PHP_METHOD(Ice_Cli_Router, getModule) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "module");

}

PHP_METHOD(Ice_Cli_Router, getHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handler");

}

PHP_METHOD(Ice_Cli_Router, getAction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "action");

}

PHP_METHOD(Ice_Cli_Router, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "params");

}

/**
 * Set defaults values
 *
 * @param array defaults
 */
PHP_METHOD(Ice_Cli_Router, setDefaults) {

	zval *defaults_param = NULL, module, handler, action;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&action);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults_param);

	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);


	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultModule"), &module);
	}
	if (zephir_array_isset_string_fetch(&handler, &defaults, SL("handler"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultHandler"), &handler);
	}
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultAction"), &action);
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
PHP_METHOD(Ice_Cli_Router, handle) {

	zend_bool _13, _16, _19;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, arguments_sub, __$null, params, argument, _0, _1, _2, *_3, _14, _17, _20, _22, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$6, _11$$6, _12$$6, _15$$8, _18$$9, _21$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_21$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Arguments must be an array", "ice/cli/router.zep", 65);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("defaultModule"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("module"), &_0);
	zephir_read_property(&_1, this_ptr, SL("defaultHandler"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("handler"), &_1);
	zephir_read_property(&_2, this_ptr, SL("defaultAction"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("action"), &_2);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_MAKE_REF(arguments);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 2, arguments);
	ZEPHIR_UNREF(arguments);
	zephir_check_call_status();
	zephir_is_iterable(arguments, 0, "ice/cli/router.zep", 97);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(arguments), _3)
	{
		ZEPHIR_INIT_NVAR(&argument);
		ZVAL_COPY(&argument, _3);
		ZVAL_LONG(&_4$$4, 0);
		ZVAL_LONG(&_5$$4, 2);
		ZEPHIR_INIT_NVAR(&_6$$4);
		zephir_substr(&_6$$4, &argument, 0 , 2 , 0);
		if (!ZEPHIR_IS_STRING_IDENTICAL(&_6$$4, "--")) {
			zephir_array_append(&params, &argument, PH_SEPARATE, "ice/cli/router.zep", 81);
			continue;
		}
		ZVAL_LONG(&_7$$4, 2);
		ZEPHIR_INIT_NVAR(&_8$$4);
		zephir_substr(&_8$$4, &argument, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CPY_WRT(&argument, &_8$$4);
		ZEPHIR_INIT_NVAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "=");
		ZEPHIR_INIT_NVAR(&_9$$4);
		zephir_fast_strpos(&_9$$4, &argument, &_8$$4, 0 );
		if (zephir_is_true(&_9$$4)) {
			ZEPHIR_INIT_NVAR(&_10$$6);
			zephir_fast_explode_str(&_10$$6, SL("="), &argument, 2  TSRMLS_CC);
			ZEPHIR_CPY_WRT(&argument, &_10$$6);
			zephir_array_fetch_long(&_11$$6, &argument, 1, PH_NOISY | PH_READONLY, "ice/cli/router.zep", 91 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_12$$6);
			zephir_array_fetch_long(&_12$$6, &argument, 0, PH_NOISY, "ice/cli/router.zep", 91 TSRMLS_CC);
			zephir_array_update_zval(&params, &_12$$6, &_11$$6, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&params, &argument, &__$null, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&argument);
	_13 = zephir_array_isset_string(&params, SL("module"));
	if (_13) {
		zephir_array_fetch_string(&_14, &params, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 97 TSRMLS_CC);
		_13 = zephir_is_true(&_14);
	}
	if (_13) {
		zephir_array_fetch_string(&_15$$8, &params, SL("module"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 98 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("module"), &_15$$8);
		zephir_array_unset_string(&params, SL("module"), PH_SEPARATE);
	}
	_16 = zephir_array_isset_string(&params, SL("handler"));
	if (_16) {
		zephir_array_fetch_string(&_17, &params, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 103 TSRMLS_CC);
		_16 = zephir_is_true(&_17);
	}
	if (_16) {
		zephir_array_fetch_string(&_18$$9, &params, SL("handler"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 104 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("handler"), &_18$$9);
		zephir_array_unset_string(&params, SL("handler"), PH_SEPARATE);
	}
	_19 = zephir_array_isset_string(&params, SL("action"));
	if (_19) {
		zephir_array_fetch_string(&_20, &params, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 109 TSRMLS_CC);
		_19 = zephir_is_true(&_20);
	}
	if (_19) {
		zephir_array_fetch_string(&_21$$10, &params, SL("action"), PH_NOISY | PH_READONLY, "ice/cli/router.zep", 110 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("action"), &_21$$10);
		zephir_array_unset_string(&params, SL("action"), PH_SEPARATE);
	}
	if (zephir_fast_count_int(&params TSRMLS_CC)) {
		zephir_update_property_zval(this_ptr, SL("params"), &params);
	}
	zephir_create_array(return_value, 4, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_22);
	zephir_read_property(&_22, this_ptr, SL("module"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("module"), &_22, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_22);
	zephir_read_property(&_22, this_ptr, SL("handler"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("handler"), &_22, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_22);
	zephir_read_property(&_22, this_ptr, SL("action"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("action"), &_22, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_22);
	zephir_read_property(&_22, this_ptr, SL("params"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("params"), &_22, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

zend_object *zephir_init_properties_Ice_Cli_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("params"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

