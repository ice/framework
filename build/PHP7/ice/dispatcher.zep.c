
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
 * @copyright   (c) 2014-2015 Ice Team
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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "defaultNamespace");

}

PHP_METHOD(Ice_Dispatcher, setDefaultNamespace) {

	zval *defaultNamespace, defaultNamespace_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&defaultNamespace_sub);

	zephir_fetch_params(0, 1, 0, &defaultNamespace);



	zephir_update_property_zval(this_ptr, SL("defaultNamespace"), defaultNamespace);

}

PHP_METHOD(Ice_Dispatcher, getActiveHandler) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "activeHandler");

}

PHP_METHOD(Ice_Dispatcher, getLastHandler) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "lastHandler");

}

PHP_METHOD(Ice_Dispatcher, getLoops) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "loops");

}

PHP_METHOD(Ice_Dispatcher, setLoops) {

	zval *loops, loops_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&loops_sub);

	zephir_fetch_params(0, 1, 0, &loops);



	zephir_update_property_zval(this_ptr, SL("loops"), loops);

}

PHP_METHOD(Ice_Dispatcher, getFinished) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "finished");

}

PHP_METHOD(Ice_Dispatcher, getForwards) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "forwards");

}

PHP_METHOD(Ice_Dispatcher, getForwarded) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "forwarded");

}

PHP_METHOD(Ice_Dispatcher, setSilent) {

	zval *silent, silent_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&silent_sub);

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_zval(this_ptr, SL("silent"), silent);

}

PHP_METHOD(Ice_Dispatcher, getModules) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "modules");

}

PHP_METHOD(Ice_Dispatcher, setModules) {

	zval *modules, modules_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modules_sub);

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_zval(this_ptr, SL("modules"), modules);

}

PHP_METHOD(Ice_Dispatcher, getModule) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "module");

}

PHP_METHOD(Ice_Dispatcher, setModule) {

	zval *module, module_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&module_sub);

	zephir_fetch_params(0, 1, 0, &module);



	zephir_update_property_zval(this_ptr, SL("module"), module);

}

PHP_METHOD(Ice_Dispatcher, getNamespace) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "namespace");

}

PHP_METHOD(Ice_Dispatcher, setNamespace) {

	zval *namespace, namespace_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&namespace_sub);

	zephir_fetch_params(0, 1, 0, &namespace);



	zephir_update_property_zval(this_ptr, SL("namespace"), namespace);

}

PHP_METHOD(Ice_Dispatcher, getHandler) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "handler");

}

PHP_METHOD(Ice_Dispatcher, setHandler) {

	zval *handler, handler_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_zval(this_ptr, SL("handler"), handler);

}

PHP_METHOD(Ice_Dispatcher, getAction) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "action");

}

PHP_METHOD(Ice_Dispatcher, setAction) {

	zval *action, action_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&action_sub);

	zephir_fetch_params(0, 1, 0, &action);



	zephir_update_property_zval(this_ptr, SL("action"), action);

}

PHP_METHOD(Ice_Dispatcher, getParams) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "params");

}

PHP_METHOD(Ice_Dispatcher, setParams) {

	zval *params, params_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&params_sub);

	zephir_fetch_params(0, 1, 0, &params);



	zephir_update_property_zval(this_ptr, SL("params"), params);

}

PHP_METHOD(Ice_Dispatcher, getReturnedValue) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "returnedValue");

}

PHP_METHOD(Ice_Dispatcher, setReturnedValue) {

	zval *returnedValue, returnedValue_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&returnedValue_sub);

	zephir_fetch_params(0, 1, 0, &returnedValue);



	zephir_update_property_zval(this_ptr, SL("returnedValue"), returnedValue);

}

PHP_METHOD(Ice_Dispatcher, getHandlerSuffix) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "handlerSuffix");

}

PHP_METHOD(Ice_Dispatcher, setHandlerSuffix) {

	zval *handlerSuffix, handlerSuffix_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&handlerSuffix_sub);

	zephir_fetch_params(0, 1, 0, &handlerSuffix);



	zephir_update_property_zval(this_ptr, SL("handlerSuffix"), handlerSuffix);

}

PHP_METHOD(Ice_Dispatcher, getActionSuffix) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "actionSuffix");

}

PHP_METHOD(Ice_Dispatcher, setActionSuffix) {

	zval *actionSuffix, actionSuffix_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&actionSuffix_sub);

	zephir_fetch_params(0, 1, 0, &actionSuffix);



	zephir_update_property_zval(this_ptr, SL("actionSuffix"), actionSuffix);

}

/**
 * Di constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Dispatcher, __construct) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 6);
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
	ZEPHIR_INIT_THIS();

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
	ZEPHIR_INIT_THIS();

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

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowEmpty, _5$$4, _6$$4;
	zval *key_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *allowEmpty_param = NULL, __$null, params, value, filter, _0, _1$$5, _3$$5, _4$$5;
	zval key;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);

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
		ZEPHIR_CALL_METHOD(&value, &params, "get", NULL, 27, &key, defaultValue);
		zephir_check_call_status();
		if (zephir_is_true(filters)) {
			ZEPHIR_CALL_CE_STATIC(&_1$$5, ice_di_ce, "fetch", &_2, 6);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "filter");
			ZEPHIR_CALL_METHOD(&filter, &_1$$5, "get", NULL, 0, &_3$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$5, &filter, "sanitize", NULL, 0, &value, filters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_4$$5);
		}
		_5$$4 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
		if (!(_5$$4)) {
			_5$$4 = Z_TYPE_P(&value) == IS_NULL;
		}
		_6$$4 = _5$$4;
		if (_6$$4) {
			_6$$4 = allowEmpty == 0;
		}
		if (_6$$4) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		RETURN_CCTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the current method to be/executed in the dispatcher.
 *
 * @return string
 */
PHP_METHOD(Ice_Dispatcher, getActiveMethod) {

	zval _0, _1;
	ZEPHIR_INIT_THIS();

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

	zval _69$$3, _30$$6, _20$$7, _24$$10, _48$$14, _61$$20;
	zend_bool fresh = 0, _4$$3;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_12 = NULL, *_16 = NULL, *_27 = NULL, *_35 = NULL, *_37 = NULL, *_43 = NULL, *_45 = NULL, *_46 = NULL, *_52 = NULL, *_56 = NULL, *_58 = NULL, *_59 = NULL;
	zval __$true, __$false, handler, response, handlerName, actionName, params, handlerSuffix, handlerClass, actionMethod, module, modules, moduleNamespace, path, moduleClass, loader, _0, _1, _2, _3$$3, _5$$3, _6$$3, _17$$3, _38$$3, _39$$3, _40$$3, _51$$3, _64$$3, _68$$3, _7$$4, _13$$4, _14$$4, _15$$4, _8$$5, _10$$5, _18$$6, _26$$6, _28$$6, _29$$6, _31$$6, _32$$6, _19$$7, _21$$7, _22$$7, _23$$10, _25$$10, _33$$13, _34$$13, _36$$13, _41$$14, _47$$14, _49$$14, _50$$14, _42$$15, _44$$15, _53$$16, _54$$20, _60$$20, _62$$20, _63$$20, _55$$21, _57$$21, _65$$22, _66$$22, _67$$22, _70$$24;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

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
	ZVAL_UNDEF(&_38$$3);
	ZVAL_UNDEF(&_39$$3);
	ZVAL_UNDEF(&_40$$3);
	ZVAL_UNDEF(&_51$$3);
	ZVAL_UNDEF(&_64$$3);
	ZVAL_UNDEF(&_68$$3);
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
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_41$$14);
	ZVAL_UNDEF(&_47$$14);
	ZVAL_UNDEF(&_49$$14);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_42$$15);
	ZVAL_UNDEF(&_44$$15);
	ZVAL_UNDEF(&_53$$16);
	ZVAL_UNDEF(&_54$$20);
	ZVAL_UNDEF(&_60$$20);
	ZVAL_UNDEF(&_62$$20);
	ZVAL_UNDEF(&_63$$20);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_57$$21);
	ZVAL_UNDEF(&_65$$22);
	ZVAL_UNDEF(&_66$$22);
	ZVAL_UNDEF(&_67$$22);
	ZVAL_UNDEF(&_70$$24);
	ZVAL_UNDEF(&_69$$3);
	ZVAL_UNDEF(&_30$$6);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_48$$14);
	ZVAL_UNDEF(&_61$$20);

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
			ZEPHIR_CALL_METHOD(NULL, &_13$$4, "__construct", &_16, 13, &_14$$4, &_15$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_13$$4, "ice/dispatcher.zep", 164 TSRMLS_CC);
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
				ZEPHIR_CALL_METHOD(NULL, &_19$$7, "__construct", &_16, 13, &_20$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_19$$7, "ice/dispatcher.zep", 172 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&module) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Module definition must be an array", "ice/dispatcher.zep", 176);
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
					ZEPHIR_CALL_METHOD(NULL, &_23$$10, "__construct", &_16, 13, &_24$$10);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_23$$10, "ice/dispatcher.zep", 181 TSRMLS_CC);
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
			ZEPHIR_CALL_METHOD(&_26$$6, &loader, "addnamespace", &_27, 28, &moduleNamespace, &path);
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
			ZEPHIR_CALL_METHOD(NULL, &module, "registerautoloaders", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_32$$6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &module, "registerservices", NULL, 0, &_32$$6);
			zephir_check_call_status();
		}
		zephir_read_property(&_17$$3, this_ptr, SL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_17$$3))) {
			zephir_read_property(&_33$$13, this_ptr, SL("namespace"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_34$$13, this_ptr, "gethandlersuffix", &_35, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_36$$13);
			ZEPHIR_CONCAT_VSV(&_36$$13, &_33$$13, "\\", &_34$$13);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultnamespace", &_37, 0, &_36$$13);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(&handlerName);
		zephir_read_property(&handlerName, this_ptr, SL("handler"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&actionName);
		zephir_read_property(&actionName, this_ptr, SL("action"), PH_NOISY_CC);
		zephir_read_property(&_38$$3, this_ptr, SL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_39$$3);
		ZEPHIR_INIT_NVAR(&_40$$3);
		zephir_camelize(&_40$$3, &handlerName);
		zephir_ucfirst(&_39$$3, &_40$$3);
		ZEPHIR_INIT_NVAR(&handlerClass);
		ZEPHIR_CONCAT_VSVV(&handlerClass, &_38$$3, "\\", &_39$$3, &handlerSuffix);
		if (!(zephir_class_exists(&handlerClass, 1 TSRMLS_CC))) {
			zephir_read_property(&_41$$14, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_41$$14)) {
				ZVAL_LONG(&_42$$15, 404);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", &_43, 0, &_42$$15);
				zephir_check_call_status();
				ZVAL_LONG(&_42$$15, 404);
				ZEPHIR_CALL_METHOD(&_44$$15, &response, "getmessage", &_45, 0, &_42$$15);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", &_46, 0, &_44$$15);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(&_47$$14);
			object_init_ex(&_47$$14, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_48$$14);
			zephir_create_array(&_48$$14, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_49$$14);
			ZVAL_STRING(&_49$$14, "%s handler class cannot be loaded");
			zephir_array_fast_append(&_48$$14, &_49$$14);
			zephir_array_fast_append(&_48$$14, &handlerClass);
			ZVAL_LONG(&_50$$14, 2);
			ZEPHIR_CALL_METHOD(NULL, &_47$$14, "__construct", &_16, 13, &_48$$14, &_50$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_47$$14, "ice/dispatcher.zep", 220 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, SL("lastHandler"), &handler);
		zephir_read_property(&_51$$3, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&handler, &_51$$3, "build", NULL, 0, &handlerClass);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("activeHandler"), &handler);
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_52, 0);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(&handler, SS("before") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, &handler, "before", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_53$$16, this_ptr, SL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_53$$16)) {
				continue;
			}
		}
		if (fresh == 1) {
			if ((zephir_method_exists_ex(&handler, SS("initialize") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(NULL, &handler, "initialize", NULL, 0);
				zephir_check_call_status();
			}
		}
		if (!((zephir_method_exists(&handler, &actionMethod TSRMLS_CC)  == SUCCESS))) {
			zephir_read_property(&_54$$20, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_54$$20)) {
				ZVAL_LONG(&_55$$21, 404);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", &_56, 0, &_55$$21);
				zephir_check_call_status();
				ZVAL_LONG(&_55$$21, 404);
				ZEPHIR_CALL_METHOD(&_57$$21, &response, "getmessage", &_58, 0, &_55$$21);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", &_59, 0, &_57$$21);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(&_60$$20);
			object_init_ex(&_60$$20, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_61$$20);
			zephir_create_array(&_61$$20, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_62$$20);
			ZVAL_STRING(&_62$$20, "Action '%s' was not found on handler '%s'");
			zephir_array_fast_append(&_61$$20, &_62$$20);
			zephir_array_fast_append(&_61$$20, &actionName);
			zephir_array_fast_append(&_61$$20, &handlerName);
			ZVAL_LONG(&_63$$20, 3);
			ZEPHIR_CALL_METHOD(NULL, &_60$$20, "__construct", &_16, 13, &_61$$20, &_63$$20);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_60$$20, "ice/dispatcher.zep", 252 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_64$$3, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&params, &_64$$3);
		if (Z_TYPE_P(&params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_65$$22);
			object_init_ex(&_65$$22, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_66$$22);
			ZVAL_STRING(&_66$$22, "Action parameters must be an array");
			ZVAL_LONG(&_67$$22, 4);
			ZEPHIR_CALL_METHOD(NULL, &_65$$22, "__construct", &_16, 13, &_66$$22, &_67$$22);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_65$$22, "ice/dispatcher.zep", 257 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_68$$3);
		ZEPHIR_INIT_NVAR(&_69$$3);
		zephir_create_array(&_69$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_69$$3, &handler);
		zephir_array_fast_append(&_69$$3, &actionMethod);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_68$$3, &_69$$3, &params);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("returnedValue"), &_68$$3);
		zephir_read_property(&_64$$3, this_ptr, SL("finished"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_64$$3)) {
			continue;
		}
		if ((zephir_method_exists_ex(&handler, SS("after") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, &handler, "after", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_70$$24, this_ptr, SL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_70$$24)) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool force;
	zval *forward_param = NULL, *force_param = NULL, __$true, __$false, module, handler, action, params, _0$$3, _1$$4, _2$$5;
	zval forward;
	ZEPHIR_INIT_THIS();

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

	ZVAL_COPY_VALUE(&forward, forward_param);
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

static zend_object *zephir_init_properties_Ice_Dispatcher(zend_class_entry *class_type TSRMLS_DC) {

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

