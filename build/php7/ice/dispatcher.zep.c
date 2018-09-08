
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * The base class for Ice\Mvc\Dispatcher and Ice\CLI\Dispatcher.
 * For the response from router and in the specified module, create instance of handler with action and params.
 *
 * @package     Ice/Dispatcher
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Dispatcher) {

	ZEPHIR_REGISTER_CLASS(Ice, Dispatcher, ice, dispatcher, ice_dispatcher_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_dispatcher_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("defaultNamespace"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("activeHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("lastHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_dispatcher_ce, SL("loops"), 16, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("finished"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_dispatcher_ce, SL("forwards"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_dispatcher_ce, SL("forwarded"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_dispatcher_ce, SL("silent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("namespace"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("returnedValue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_dispatcher_ce, SL("handlerSuffix"), "Handler", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_dispatcher_ce, SL("actionSuffix"), "Action", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("previousModule"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("previousHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("previousAction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_dispatcher_ce->create_object = zephir_init_properties_Ice_Dispatcher;
	zephir_declare_class_constant_long(ice_dispatcher_ce, SL("DISPATCH_CYCLIC"), 1);

	zephir_declare_class_constant_long(ice_dispatcher_ce, SL("HANDLER_NOT_FOUND"), 2);

	zephir_declare_class_constant_long(ice_dispatcher_ce, SL("ACTION_NOT_FOUND"), 3);

	zephir_declare_class_constant_long(ice_dispatcher_ce, SL("INVALID_PARAMS"), 4);

	return SUCCESS;

}

PHP_METHOD(Ice_Dispatcher, getDefaultNamespace) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultNamespace");

}

PHP_METHOD(Ice_Dispatcher, setDefaultNamespace) {

	zval *defaultNamespace, defaultNamespace_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultNamespace_sub);

	zephir_fetch_params(0, 1, 0, &defaultNamespace);



	zephir_update_property_zval(this_ptr, SL("defaultNamespace"), defaultNamespace);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getActiveHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeHandler");

}

PHP_METHOD(Ice_Dispatcher, getLastHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "lastHandler");

}

PHP_METHOD(Ice_Dispatcher, getLoops) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "loops");

}

PHP_METHOD(Ice_Dispatcher, setLoops) {

	zval *loops, loops_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&loops_sub);

	zephir_fetch_params(0, 1, 0, &loops);



	zephir_update_property_zval(this_ptr, SL("loops"), loops);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getFinished) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "finished");

}

PHP_METHOD(Ice_Dispatcher, getForwards) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "forwards");

}

PHP_METHOD(Ice_Dispatcher, getForwarded) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "forwarded");

}

PHP_METHOD(Ice_Dispatcher, setSilent) {

	zval *silent, silent_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&silent_sub);

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_zval(this_ptr, SL("silent"), silent);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getModules) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "modules");

}

PHP_METHOD(Ice_Dispatcher, setModules) {

	zval *modules, modules_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modules_sub);

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_zval(this_ptr, SL("modules"), modules);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getModule) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "module");

}

PHP_METHOD(Ice_Dispatcher, setModule) {

	zval *module, module_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module_sub);

	zephir_fetch_params(0, 1, 0, &module);



	zephir_update_property_zval(this_ptr, SL("module"), module);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getNamespace) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "namespace");

}

PHP_METHOD(Ice_Dispatcher, setNamespace) {

	zval *namespace, namespace_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespace_sub);

	zephir_fetch_params(0, 1, 0, &namespace);



	zephir_update_property_zval(this_ptr, SL("namespace"), namespace);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handler");

}

PHP_METHOD(Ice_Dispatcher, setHandler) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_zval(this_ptr, SL("handler"), handler);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getAction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "action");

}

PHP_METHOD(Ice_Dispatcher, setAction) {

	zval *action, action_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action_sub);

	zephir_fetch_params(0, 1, 0, &action);



	zephir_update_property_zval(this_ptr, SL("action"), action);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "params");

}

PHP_METHOD(Ice_Dispatcher, setParams) {

	zval *params, params_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params_sub);

	zephir_fetch_params(0, 1, 0, &params);



	zephir_update_property_zval(this_ptr, SL("params"), params);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getReturnedValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "returnedValue");

}

PHP_METHOD(Ice_Dispatcher, setReturnedValue) {

	zval *returnedValue, returnedValue_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&returnedValue_sub);

	zephir_fetch_params(0, 1, 0, &returnedValue);



	zephir_update_property_zval(this_ptr, SL("returnedValue"), returnedValue);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getHandlerSuffix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handlerSuffix");

}

PHP_METHOD(Ice_Dispatcher, setHandlerSuffix) {

	zval *handlerSuffix, handlerSuffix_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handlerSuffix_sub);

	zephir_fetch_params(0, 1, 0, &handlerSuffix);



	zephir_update_property_zval(this_ptr, SL("handlerSuffix"), handlerSuffix);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getActionSuffix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "actionSuffix");

}

PHP_METHOD(Ice_Dispatcher, setActionSuffix) {

	zval *actionSuffix, actionSuffix_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionSuffix_sub);

	zephir_fetch_params(0, 1, 0, &actionSuffix);



	zephir_update_property_zval(this_ptr, SL("actionSuffix"), actionSuffix);
	RETURN_THISW();

}

/**
 * Di constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Dispatcher, __construct) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("di"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Whether or not an param exists by key.
 *
 * @param string key The param key
 * @return boolean
 */
PHP_METHOD(Ice_Dispatcher, hasParam) {

	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &key));

}

/**
 * Set a param by its name or numeric index.
 *
 * @param mixed param
 * @param mixed value
 */
PHP_METHOD(Ice_Dispatcher, setParam) {

	zval *param, param_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &param, &value);



	zephir_update_property_array(this_ptr, SL("params"), param, value TSRMLS_CC);

}

/**
 * Gets variable from params attribute applying filters if needed.
 * If no parameters are given, return all.
 *
 * <pre><code>
 *  //Returns value from $params["id"] without sanitizing
 *  $id = $this->router->getParam("id");
 *
 *  //Returns value from $params["title"] with sanitizing
 *  $title = $this->router->getParam("title", "escape|repeats");
 *
 *  //Returns value from $params["id"] with a default value
 *  $id = $this->router->getParam("id", null, 150);
 * </code></pre>
 *
 * @param string key Index to get
 * @param string|array filters Filters to apply
 * @param mixed defaultValue Default value if key not exist or value is empty and allowEmpty is false
 * @param boolean allowEmpty
 * @return mixed
 */
PHP_METHOD(Ice_Dispatcher, getParam) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowEmpty;
	zval *key_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *allowEmpty_param = NULL, __$null, params, _0, _1$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &key_param, &filters, &defaultValue, &allowEmpty_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!allowEmpty_param) {
		allowEmpty = 0;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	ZEPHIR_INIT_VAR(&params);
	object_init_ex(&params, ice_arr_ce);
	zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &params, "__construct", NULL, 4, &_0);
	zephir_check_call_status();
	if (!(!(Z_TYPE_P(&key) == IS_UNDEF) && Z_STRLEN_P(&key))) {
		RETURN_CCTOR(params);
	} else {
		if (allowEmpty) {
			ZVAL_BOOL(&_1$$4, 1);
		} else {
			ZVAL_BOOL(&_1$$4, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&params, "getvalue", NULL, 26, &key, filters, defaultValue, &_1$$4);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * Returns the current method to be/executed in the dispatcher.
 *
 * @return string
 */
PHP_METHOD(Ice_Dispatcher, getActiveMethod) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("action"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("actionSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_0, &_1);
	return;

}

/**
 * Dispatches a handle action taking into account the routing parameters.
 *
 * @return object
 */
PHP_METHOD(Ice_Dispatcher, dispatch) {

	zval _70$$3, _30$$6, _20$$7, _24$$10, _49$$14, _62$$20;
	zend_bool fresh = 0, _4$$3;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_12 = NULL, *_16 = NULL, *_27 = NULL, *_36 = NULL, *_38 = NULL, *_44 = NULL, *_46 = NULL, *_47 = NULL, *_53 = NULL, *_57 = NULL, *_59 = NULL, *_60 = NULL;
	zval __$true, __$false, handler, response, handlerName, actionName, params, handlerSuffix, handlerClass, actionMethod, module, modules, moduleNamespace, path, moduleClass, loader, _0, _1, _2, _3$$3, _5$$3, _6$$3, _17$$3, _39$$3, _40$$3, _41$$3, _52$$3, _65$$3, _69$$3, _7$$4, _13$$4, _14$$4, _15$$4, _8$$5, _10$$5, _18$$6, _26$$6, _28$$6, _29$$6, _31$$6, _32$$6, _33$$6, _19$$7, _21$$7, _22$$7, _23$$10, _25$$10, _34$$13, _35$$13, _37$$13, _42$$14, _48$$14, _50$$14, _51$$14, _43$$15, _45$$15, _54$$16, _55$$20, _61$$20, _63$$20, _64$$20, _56$$21, _58$$21, _66$$22, _67$$22, _68$$22, _71$$24;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&handlerName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&handlerSuffix);
	ZVAL_UNDEF(&handlerClass);
	ZVAL_UNDEF(&actionMethod);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&modules);
	ZVAL_UNDEF(&moduleNamespace);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&moduleClass);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_39$$3);
	ZVAL_UNDEF(&_40$$3);
	ZVAL_UNDEF(&_41$$3);
	ZVAL_UNDEF(&_52$$3);
	ZVAL_UNDEF(&_65$$3);
	ZVAL_UNDEF(&_69$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_32$$6);
	ZVAL_UNDEF(&_33$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_42$$14);
	ZVAL_UNDEF(&_48$$14);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_51$$14);
	ZVAL_UNDEF(&_43$$15);
	ZVAL_UNDEF(&_45$$15);
	ZVAL_UNDEF(&_54$$16);
	ZVAL_UNDEF(&_55$$20);
	ZVAL_UNDEF(&_61$$20);
	ZVAL_UNDEF(&_63$$20);
	ZVAL_UNDEF(&_64$$20);
	ZVAL_UNDEF(&_56$$21);
	ZVAL_UNDEF(&_58$$21);
	ZVAL_UNDEF(&_66$$22);
	ZVAL_UNDEF(&_67$$22);
	ZVAL_UNDEF(&_68$$22);
	ZVAL_UNDEF(&_71$$24);
	ZVAL_UNDEF(&_70$$3);
	ZVAL_UNDEF(&_30$$6);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_49$$14);
	ZVAL_UNDEF(&_62$$20);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "response");
	ZEPHIR_CALL_METHOD(&response, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	fresh = 1;
	ZEPHIR_INIT_VAR(&handler);
	ZVAL_NULL(&handler);
	zephir_read_property(&_2, this_ptr, SL("handlerSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handlerSuffix, &_2);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("finished"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("finished"), &__$false);
	}
	while (1) {
		zephir_read_property(&_2, this_ptr, SL("finished"), PH_NOISY_CC | PH_READONLY);
		if (!(!(zephir_is_true(&_2)))) {
			break;
		}
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("forwards") TSRMLS_CC));
		zephir_read_property(&_3$$3, this_ptr, SL("loops"), PH_NOISY_CC | PH_READONLY);
		_4$$3 = zephir_is_true(&_3$$3);
		if (_4$$3) {
			zephir_read_property(&_5$$3, this_ptr, SL("forwards"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_6$$3, this_ptr, SL("loops"), PH_NOISY_CC | PH_READONLY);
			_4$$3 = ZEPHIR_GT(&_5$$3, &_6$$3);
		}
		if (_4$$3) {
			zephir_read_property(&_7$$4, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_7$$4)) {
				ZVAL_LONG(&_8$$5, 508);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", &_9, 0, &_8$$5);
				zephir_check_call_status();
				ZVAL_LONG(&_8$$5, 508);
				ZEPHIR_CALL_METHOD(&_10$$5, &response, "getmessage", &_11, 0, &_8$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", &_12, 0, &_10$$5);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(&_13$$4);
			object_init_ex(&_13$$4, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_14$$4);
			ZVAL_STRING(&_14$$4, "Dispatcher has detected a cyclic routing causing stability problems");
			ZVAL_LONG(&_15$$4, 1);
			ZEPHIR_CALL_METHOD(NULL, &_13$$4, "__construct", &_16, 12, &_14$$4, &_15$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_13$$4, "ice/dispatcher.zep", 153 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (1) {
			zephir_update_property_zval(this_ptr, SL("finished"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("finished"), &__$false);
		}
		zephir_read_property(&_17$$3, this_ptr, SL("modules"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&modules, &_17$$3);
		if (zephir_is_true(&modules)) {
			ZEPHIR_OBS_NVAR(&module);
			zephir_read_property(&_18$$6, this_ptr, SL("module"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset_fetch(&module, &modules, &_18$$6, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&_19$$7);
				object_init_ex(&_19$$7, ice_exception_ce);
				ZEPHIR_INIT_NVAR(&_20$$7);
				zephir_create_array(&_20$$7, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_21$$7);
				ZVAL_STRING(&_21$$7, "Module '%s' isn't registered in the application container");
				zephir_array_fast_append(&_20$$7, &_21$$7);
				ZEPHIR_OBS_NVAR(&_22$$7);
				zephir_read_property(&_22$$7, this_ptr, SL("module"), PH_NOISY_CC);
				zephir_array_fast_append(&_20$$7, &_22$$7);
				ZEPHIR_CALL_METHOD(NULL, &_19$$7, "__construct", &_16, 12, &_20$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_19$$7, "ice/dispatcher.zep", 161 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&module) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Module definition must be an array", "ice/dispatcher.zep", 165);
				return;
			}
			ZEPHIR_OBS_NVAR(&path);
			if (zephir_array_isset_string_fetch(&path, &module, SL("path"), 0)) {
				if (!((zephir_file_exists(&path TSRMLS_CC) == SUCCESS))) {
					ZEPHIR_INIT_NVAR(&_23$$10);
					object_init_ex(&_23$$10, ice_exception_ce);
					ZEPHIR_INIT_NVAR(&_24$$10);
					zephir_create_array(&_24$$10, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_25$$10);
					ZVAL_STRING(&_25$$10, "Module definition path '%s' doesn't exist");
					zephir_array_fast_append(&_24$$10, &_25$$10);
					zephir_array_fast_append(&_24$$10, &path);
					ZEPHIR_CALL_METHOD(NULL, &_23$$10, "__construct", &_16, 12, &_24$$10);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_23$$10, "ice/dispatcher.zep", 170 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&moduleClass);
			if (!(zephir_array_isset_string_fetch(&moduleClass, &module, SL("class"), 0))) {
				ZEPHIR_INIT_NVAR(&moduleClass);
				ZVAL_STRING(&moduleClass, "Module");
			}
			ZEPHIR_OBS_NVAR(&moduleNamespace);
			if (!(zephir_array_isset_string_fetch(&moduleNamespace, &module, SL("namespace"), 0))) {
				ZEPHIR_CPY_WRT(&moduleNamespace, &moduleClass);
			}
			ZEPHIR_INIT_NVAR(&loader);
			object_init_ex(&loader, ice_loader_ce);
			if (zephir_has_constructor(&loader TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &loader, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			zephir_update_property_zval(this_ptr, SL("namespace"), &moduleNamespace);
			ZEPHIR_CALL_METHOD(&_26$$6, &loader, "addnamespace", &_27, 27, &moduleNamespace, &path);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_26$$6, "register", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_28$$6);
			ZEPHIR_INIT_LNVAR(_29$$6);
			ZEPHIR_CONCAT_VSV(&_29$$6, &moduleNamespace, "\\", &moduleClass);
			ZEPHIR_INIT_NVAR(&_30$$6);
			zephir_create_array(&_30$$6, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_31$$6);
			zephir_read_property(&_31$$6, this_ptr, SL("di"), PH_NOISY_CC);
			zephir_array_fast_append(&_30$$6, &_31$$6);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_28$$6, &_29$$6, &_30$$6 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&module, &_28$$6);
			zephir_read_property(&_32$$6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &module, "registerautoloaders", NULL, 0, &_32$$6);
			zephir_check_call_status();
			zephir_read_property(&_33$$6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &module, "registerservices", NULL, 0, &_33$$6);
			zephir_check_call_status();
		}
		zephir_read_property(&_17$$3, this_ptr, SL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_17$$3))) {
			zephir_read_property(&_34$$13, this_ptr, SL("namespace"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_35$$13, this_ptr, "gethandlersuffix", &_36, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_37$$13);
			ZEPHIR_CONCAT_VSV(&_37$$13, &_34$$13, "\\", &_35$$13);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultnamespace", &_38, 0, &_37$$13);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(&handlerName);
		zephir_read_property(&handlerName, this_ptr, SL("handler"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&actionName);
		zephir_read_property(&actionName, this_ptr, SL("action"), PH_NOISY_CC);
		zephir_read_property(&_39$$3, this_ptr, SL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_40$$3);
		ZEPHIR_INIT_NVAR(&_41$$3);
		zephir_camelize(&_41$$3, &handlerName, NULL  );
		zephir_ucfirst(&_40$$3, &_41$$3);
		ZEPHIR_INIT_NVAR(&handlerClass);
		ZEPHIR_CONCAT_VSVV(&handlerClass, &_39$$3, "\\", &_40$$3, &handlerSuffix);
		if (!(zephir_class_exists(&handlerClass, 1 TSRMLS_CC))) {
			zephir_read_property(&_42$$14, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_42$$14)) {
				ZVAL_LONG(&_43$$15, 404);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", &_44, 0, &_43$$15);
				zephir_check_call_status();
				ZVAL_LONG(&_43$$15, 404);
				ZEPHIR_CALL_METHOD(&_45$$15, &response, "getmessage", &_46, 0, &_43$$15);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", &_47, 0, &_45$$15);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(&_48$$14);
			object_init_ex(&_48$$14, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_49$$14);
			zephir_create_array(&_49$$14, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_50$$14);
			ZVAL_STRING(&_50$$14, "%s handler class cannot be loaded");
			zephir_array_fast_append(&_49$$14, &_50$$14);
			zephir_array_fast_append(&_49$$14, &handlerClass);
			ZVAL_LONG(&_51$$14, 2);
			ZEPHIR_CALL_METHOD(NULL, &_48$$14, "__construct", &_16, 12, &_49$$14, &_51$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_48$$14, "ice/dispatcher.zep", 209 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, SL("lastHandler"), &handler);
		zephir_read_property(&_52$$3, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&handler, &_52$$3, "build", NULL, 0, &handlerClass);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("activeHandler"), &handler);
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_53, 0);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(&handler, SL("before") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, &handler, "before", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_54$$16, this_ptr, SL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_54$$16)) {
				continue;
			}
		}
		if (fresh == 1) {
			if ((zephir_method_exists_ex(&handler, SL("initialize") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(NULL, &handler, "initialize", NULL, 0);
				zephir_check_call_status();
			}
		}
		if (!((zephir_method_exists(&handler, &actionMethod TSRMLS_CC)  == SUCCESS))) {
			zephir_read_property(&_55$$20, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_55$$20)) {
				ZVAL_LONG(&_56$$21, 404);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", &_57, 0, &_56$$21);
				zephir_check_call_status();
				ZVAL_LONG(&_56$$21, 404);
				ZEPHIR_CALL_METHOD(&_58$$21, &response, "getmessage", &_59, 0, &_56$$21);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", &_60, 0, &_58$$21);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(&_61$$20);
			object_init_ex(&_61$$20, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_62$$20);
			zephir_create_array(&_62$$20, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_63$$20);
			ZVAL_STRING(&_63$$20, "Action '%s' was not found on handler '%s'");
			zephir_array_fast_append(&_62$$20, &_63$$20);
			zephir_array_fast_append(&_62$$20, &actionName);
			zephir_array_fast_append(&_62$$20, &handlerName);
			ZVAL_LONG(&_64$$20, 3);
			ZEPHIR_CALL_METHOD(NULL, &_61$$20, "__construct", &_16, 12, &_62$$20, &_64$$20);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_61$$20, "ice/dispatcher.zep", 241 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_65$$3, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&params, &_65$$3);
		if (Z_TYPE_P(&params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_66$$22);
			object_init_ex(&_66$$22, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_67$$22);
			ZVAL_STRING(&_67$$22, "Action parameters must be an array");
			ZVAL_LONG(&_68$$22, 4);
			ZEPHIR_CALL_METHOD(NULL, &_66$$22, "__construct", &_16, 12, &_67$$22, &_68$$22);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_66$$22, "ice/dispatcher.zep", 246 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_69$$3);
		ZEPHIR_INIT_NVAR(&_70$$3);
		zephir_create_array(&_70$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_70$$3, &handler);
		zephir_array_fast_append(&_70$$3, &actionMethod);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_69$$3, &_70$$3, &params);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("returnedValue"), &_69$$3);
		zephir_read_property(&_65$$3, this_ptr, SL("finished"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_65$$3)) {
			continue;
		}
		if ((zephir_method_exists_ex(&handler, SL("after") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, &handler, "after", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_71$$24, this_ptr, SL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_71$$24)) {
				continue;
			}
		}
		fresh = 0;
	}
	RETURN_CCTOR(handler);

}

/**
 * Forwards the execution flow to another module/controller/action.
 *
 * @param array forward
 * @param boolean force
 */
PHP_METHOD(Ice_Dispatcher, forward) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool force;
	zval *forward_param = NULL, *force_param = NULL, __$true, __$false, module, handler, action, params, _0$$3, _1$$4, _2$$5;
	zval forward;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&forward);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &forward_param, &force_param);

	ZEPHIR_OBS_COPY_OR_DUP(&forward, forward_param);
	if (!force_param) {
		force = 0;
	} else {
		force = zephir_get_boolval(force_param);
	}


	ZEPHIR_OBS_VAR(&module);
	if (zephir_array_isset_string_fetch(&module, &forward, SL("module"), 0)) {
		zephir_read_property(&_0$$3, this_ptr, SL("module"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("previousModule"), &_0$$3);
		zephir_update_property_zval(this_ptr, SL("module"), &module);
	}
	ZEPHIR_OBS_VAR(&handler);
	if (zephir_array_isset_string_fetch(&handler, &forward, SL("handler"), 0)) {
		zephir_read_property(&_1$$4, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("previousHandler"), &_1$$4);
		zephir_update_property_zval(this_ptr, SL("handler"), &handler);
	}
	ZEPHIR_OBS_VAR(&action);
	if (zephir_array_isset_string_fetch(&action, &forward, SL("action"), 0)) {
		zephir_read_property(&_2$$5, this_ptr, SL("action"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("previousAction"), &_2$$5);
		zephir_update_property_zval(this_ptr, SL("action"), &action);
	}
	ZEPHIR_OBS_VAR(&params);
	if (zephir_array_isset_string_fetch(&params, &forward, SL("params"), 0)) {
		zephir_update_property_zval(this_ptr, SL("params"), &params);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("finished"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("finished"), &__$false);
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("forwarded"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("forwarded"), &__$false);
	}
	if (force) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Ice_Dispatcher(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

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
		zephir_read_property(&_2, this_ptr, SL("modules"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("modules"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

