
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

	zend_declare_property_long(ice_dispatcher_ce, SL("loops"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dispatcher_ce, SL("finished"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "defaultNamespace");

}

PHP_METHOD(Ice_Dispatcher, setDefaultNamespace) {

	zval *defaultNamespace, defaultNamespace_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&defaultNamespace_sub);

	zephir_fetch_params(0, 1, 0, &defaultNamespace);



	zephir_update_property_zval(this_ptr, SL("defaultNamespace"), defaultNamespace);

}

PHP_METHOD(Ice_Dispatcher, getActiveHandler) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "activeHandler");

}

PHP_METHOD(Ice_Dispatcher, getLastHandler) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "lastHandler");

}

PHP_METHOD(Ice_Dispatcher, getLoops) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "loops");

}

PHP_METHOD(Ice_Dispatcher, getFinished) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "finished");

}

PHP_METHOD(Ice_Dispatcher, getForwarded) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "forwarded");

}

PHP_METHOD(Ice_Dispatcher, setSilent) {

	zval *silent, silent_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&silent_sub);

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_zval(this_ptr, SL("silent"), silent);

}

PHP_METHOD(Ice_Dispatcher, getModules) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "modules");

}

PHP_METHOD(Ice_Dispatcher, setModules) {

	zval *modules, modules_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&modules_sub);

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_zval(this_ptr, SL("modules"), modules);

}

PHP_METHOD(Ice_Dispatcher, getModule) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "module");

}

PHP_METHOD(Ice_Dispatcher, setModule) {

	zval *module, module_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&module_sub);

	zephir_fetch_params(0, 1, 0, &module);



	zephir_update_property_zval(this_ptr, SL("module"), module);

}

PHP_METHOD(Ice_Dispatcher, getNamespace) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "namespace");

}

PHP_METHOD(Ice_Dispatcher, setNamespace) {

	zval *namespace, namespace_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&namespace_sub);

	zephir_fetch_params(0, 1, 0, &namespace);



	zephir_update_property_zval(this_ptr, SL("namespace"), namespace);

}

PHP_METHOD(Ice_Dispatcher, getHandler) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "handler");

}

PHP_METHOD(Ice_Dispatcher, setHandler) {

	zval *handler, handler_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_zval(this_ptr, SL("handler"), handler);

}

PHP_METHOD(Ice_Dispatcher, getAction) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "action");

}

PHP_METHOD(Ice_Dispatcher, setAction) {

	zval *action, action_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&action_sub);

	zephir_fetch_params(0, 1, 0, &action);



	zephir_update_property_zval(this_ptr, SL("action"), action);

}

PHP_METHOD(Ice_Dispatcher, getParams) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "params");

}

PHP_METHOD(Ice_Dispatcher, setParams) {

	zval *params, params_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&params_sub);

	zephir_fetch_params(0, 1, 0, &params);



	zephir_update_property_zval(this_ptr, SL("params"), params);

}

PHP_METHOD(Ice_Dispatcher, getReturnedValue) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "returnedValue");

}

PHP_METHOD(Ice_Dispatcher, setReturnedValue) {

	zval *returnedValue, returnedValue_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&returnedValue_sub);

	zephir_fetch_params(0, 1, 0, &returnedValue);



	zephir_update_property_zval(this_ptr, SL("returnedValue"), returnedValue);

}

PHP_METHOD(Ice_Dispatcher, getHandlerSuffix) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "handlerSuffix");

}

PHP_METHOD(Ice_Dispatcher, setHandlerSuffix) {

	zval *handlerSuffix, handlerSuffix_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&handlerSuffix_sub);

	zephir_fetch_params(0, 1, 0, &handlerSuffix);



	zephir_update_property_zval(this_ptr, SL("handlerSuffix"), handlerSuffix);

}

PHP_METHOD(Ice_Dispatcher, getActionSuffix) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "actionSuffix");

}

PHP_METHOD(Ice_Dispatcher, setActionSuffix) {

	zval *actionSuffix, actionSuffix_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
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
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 8);
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
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
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
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
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
	zend_bool allowEmpty, _7$$4, _8$$4;
	zval *key_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *allowEmpty_param = NULL, __$null, params, value, filter, _0, _1$$5, _3$$5, _4$$5, _5$$5, _6$$5;
	zval key;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
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
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);

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
	ZEPHIR_CALL_METHOD(NULL, &params, "__construct", NULL, 6, &_0);
	zephir_check_call_status();
	if (!(!(Z_TYPE_P(&key) == IS_UNDEF) && Z_STRLEN_P(&key))) {
		RETURN_CCTOR(params);
	} else {
		ZEPHIR_CALL_METHOD(&value, &params, "get", NULL, 27, &key, defaultValue);
		zephir_check_call_status();
		if (zephir_is_true(filters)) {
			ZEPHIR_CALL_CE_STATIC(&_1$$5, ice_di_ce, "fetch", &_2, 8);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "filter");
			ZVAL_NULL(&_4$$5);
			ZVAL_BOOL(&_5$$5, 1);
			ZEPHIR_CALL_METHOD(&filter, &_1$$5, "get", NULL, 27, &_3$$5, &_4$$5, &_5$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6$$5, &filter, "sanitize", NULL, 0, &value, filters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_6$$5);
		}
		_7$$4 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
		if (!(_7$$4)) {
			_7$$4 = Z_TYPE_P(&value) == IS_NULL;
		}
		_8$$4 = _7$$4;
		if (_8$$4) {
			_8$$4 = allowEmpty == 0;
		}
		if (_8$$4) {
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
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
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

	zval _67$$3, _27$$6, _17$$7, _21$$10, _45$$14, _59$$20;
	zend_class_entry *_49$$3;
	zend_bool fresh = 0;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_9 = NULL, *_13 = NULL, *_24 = NULL, *_32 = NULL, *_34 = NULL, *_40 = NULL, *_42 = NULL, *_43 = NULL, *_50 = NULL, *_54 = NULL, *_56 = NULL, *_57 = NULL;
	zval __$true, __$false, handler, response, handlerName, actionName, params, handlerSuffix, handlerClass, actionMethod, module, modules, moduleNamespace, path, moduleClass, loader, _0, _1, _2, _3$$3, _14$$3, _35$$3, _36$$3, _37$$3, _48$$3, _62$$3, _66$$3, _4$$4, _10$$4, _11$$4, _12$$4, _5$$5, _7$$5, _15$$6, _23$$6, _25$$6, _26$$6, _28$$6, _29$$6, _16$$7, _18$$7, _19$$7, _20$$10, _22$$10, _30$$13, _31$$13, _33$$13, _38$$14, _44$$14, _46$$14, _47$$14, _39$$15, _41$$15, _51$$16, _52$$20, _58$$20, _60$$20, _61$$20, _53$$21, _55$$21, _63$$22, _64$$22, _65$$22, _68$$24;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
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
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_35$$3);
	ZVAL_UNDEF(&_36$$3);
	ZVAL_UNDEF(&_37$$3);
	ZVAL_UNDEF(&_48$$3);
	ZVAL_UNDEF(&_62$$3);
	ZVAL_UNDEF(&_66$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_44$$14);
	ZVAL_UNDEF(&_46$$14);
	ZVAL_UNDEF(&_47$$14);
	ZVAL_UNDEF(&_39$$15);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_51$$16);
	ZVAL_UNDEF(&_52$$20);
	ZVAL_UNDEF(&_58$$20);
	ZVAL_UNDEF(&_60$$20);
	ZVAL_UNDEF(&_61$$20);
	ZVAL_UNDEF(&_53$$21);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_63$$22);
	ZVAL_UNDEF(&_64$$22);
	ZVAL_UNDEF(&_65$$22);
	ZVAL_UNDEF(&_68$$24);
	ZVAL_UNDEF(&_67$$3);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_45$$14);
	ZVAL_UNDEF(&_59$$20);

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
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("loops") TSRMLS_CC));
		zephir_read_property(&_3$$3, this_ptr, SL("loops"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT_LONG(&_3$$3, 16)) {
			zephir_read_property(&_4$$4, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_4$$4)) {
				ZVAL_LONG(&_5$$5, 508);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", &_6, 0, &_5$$5);
				zephir_check_call_status();
				ZVAL_LONG(&_5$$5, 508);
				ZEPHIR_CALL_METHOD(&_7$$5, &response, "getmessage", &_8, 0, &_5$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", &_9, 0, &_7$$5);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(&_10$$4);
			object_init_ex(&_10$$4, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_11$$4);
			ZVAL_STRING(&_11$$4, "Dispatcher has detected a cyclic routing causing stability problems");
			ZVAL_LONG(&_12$$4, 1);
			ZEPHIR_CALL_METHOD(NULL, &_10$$4, "__construct", &_13, 2, &_11$$4, &_12$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$4, "ice/dispatcher.zep", 163 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (1) {
			zephir_update_property_zval(this_ptr, SL("finished"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("finished"), &__$false);
		}
		zephir_read_property(&_14$$3, this_ptr, SL("modules"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&modules, &_14$$3);
		if (zephir_is_true(&modules)) {
			ZEPHIR_OBS_NVAR(&module);
			zephir_read_property(&_15$$6, this_ptr, SL("module"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset_fetch(&module, &modules, &_15$$6, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&_16$$7);
				object_init_ex(&_16$$7, ice_exception_ce);
				ZEPHIR_INIT_NVAR(&_17$$7);
				zephir_create_array(&_17$$7, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_18$$7);
				ZVAL_STRING(&_18$$7, "Module '%s' isn't registered in the application container");
				zephir_array_fast_append(&_17$$7, &_18$$7);
				ZEPHIR_OBS_NVAR(&_19$$7);
				zephir_read_property(&_19$$7, this_ptr, SL("module"), PH_NOISY_CC);
				zephir_array_fast_append(&_17$$7, &_19$$7);
				ZEPHIR_CALL_METHOD(NULL, &_16$$7, "__construct", &_13, 2, &_17$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_16$$7, "ice/dispatcher.zep", 171 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&module) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Module definition must be an array", "ice/dispatcher.zep", 175);
				return;
			}
			ZEPHIR_OBS_NVAR(&path);
			if (zephir_array_isset_string_fetch(&path, &module, SL("path"), 0)) {
				if (!((zephir_file_exists(&path TSRMLS_CC) == SUCCESS))) {
					ZEPHIR_INIT_NVAR(&_20$$10);
					object_init_ex(&_20$$10, ice_exception_ce);
					ZEPHIR_INIT_NVAR(&_21$$10);
					zephir_create_array(&_21$$10, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_22$$10);
					ZVAL_STRING(&_22$$10, "Module definition path '%s' doesn't exist");
					zephir_array_fast_append(&_21$$10, &_22$$10);
					zephir_array_fast_append(&_21$$10, &path);
					ZEPHIR_CALL_METHOD(NULL, &_20$$10, "__construct", &_13, 2, &_21$$10);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_20$$10, "ice/dispatcher.zep", 180 TSRMLS_CC);
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
			ZEPHIR_CALL_METHOD(&_23$$6, &loader, "addnamespace", &_24, 28, &moduleNamespace, &path);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_23$$6, "register", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_25$$6);
			ZEPHIR_INIT_LNVAR(_26$$6);
			ZEPHIR_CONCAT_VSV(&_26$$6, &moduleNamespace, "\\", &moduleClass);
			ZEPHIR_INIT_NVAR(&_27$$6);
			zephir_create_array(&_27$$6, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_28$$6);
			zephir_read_property(&_28$$6, this_ptr, SL("di"), PH_NOISY_CC);
			zephir_array_fast_append(&_27$$6, &_28$$6);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_25$$6, &_26$$6, &_27$$6 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&module, &_25$$6);
			ZEPHIR_CALL_METHOD(NULL, &module, "registerautoloaders", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_29$$6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &module, "registerservices", NULL, 0, &_29$$6);
			zephir_check_call_status();
		}
		zephir_read_property(&_14$$3, this_ptr, SL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_14$$3))) {
			zephir_read_property(&_30$$13, this_ptr, SL("namespace"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_31$$13, this_ptr, "gethandlersuffix", &_32, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_33$$13);
			ZEPHIR_CONCAT_VSV(&_33$$13, &_30$$13, "\\", &_31$$13);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultnamespace", &_34, 0, &_33$$13);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(&handlerName);
		zephir_read_property(&handlerName, this_ptr, SL("handler"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&actionName);
		zephir_read_property(&actionName, this_ptr, SL("action"), PH_NOISY_CC);
		zephir_read_property(&_35$$3, this_ptr, SL("defaultNamespace"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_36$$3);
		ZEPHIR_INIT_NVAR(&_37$$3);
		zephir_camelize(_37$$3, &handlerName);
		zephir_ucfirst(&_36$$3, &_37$$3);
		ZEPHIR_INIT_NVAR(&handlerClass);
		ZEPHIR_CONCAT_VSVV(&handlerClass, &_35$$3, "\\", &_36$$3, &handlerSuffix);
		if (!(zephir_class_exists(&handlerClass, 1 TSRMLS_CC))) {
			zephir_read_property(&_38$$14, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_38$$14)) {
				ZVAL_LONG(&_39$$15, 404);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", &_40, 0, &_39$$15);
				zephir_check_call_status();
				ZVAL_LONG(&_39$$15, 404);
				ZEPHIR_CALL_METHOD(&_41$$15, &response, "getmessage", &_42, 0, &_39$$15);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", &_43, 0, &_41$$15);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(&_44$$14);
			object_init_ex(&_44$$14, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_45$$14);
			zephir_create_array(&_45$$14, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_46$$14);
			ZVAL_STRING(&_46$$14, "%s handler class cannot be loaded");
			zephir_array_fast_append(&_45$$14, &_46$$14);
			zephir_array_fast_append(&_45$$14, &handlerClass);
			ZVAL_LONG(&_47$$14, 2);
			ZEPHIR_CALL_METHOD(NULL, &_44$$14, "__construct", &_13, 2, &_45$$14, &_47$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_44$$14, "ice/dispatcher.zep", 219 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, SL("lastHandler"), &handler);
		ZEPHIR_INIT_NVAR(&handler);
		zephir_fetch_safe_class(_48$$3, handlerClass);
		_49$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_48$$3), Z_STRLEN_P(&_48$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&handler, _49$$3);
		if (zephir_has_constructor(&handler TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &handler, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("activeHandler"), &handler);
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_50, 0);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(&handler, SS("before") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, &handler, "before", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_51$$16, this_ptr, SL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_51$$16)) {
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
			zephir_read_property(&_52$$20, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_52$$20)) {
				ZVAL_LONG(&_53$$21, 404);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", &_54, 0, &_53$$21);
				zephir_check_call_status();
				ZVAL_LONG(&_53$$21, 404);
				ZEPHIR_CALL_METHOD(&_55$$21, &response, "getmessage", &_56, 0, &_53$$21);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", &_57, 0, &_55$$21);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(&_58$$20);
			object_init_ex(&_58$$20, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_59$$20);
			zephir_create_array(&_59$$20, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_60$$20);
			ZVAL_STRING(&_60$$20, "Action '%s' was not found on handler '%s'");
			zephir_array_fast_append(&_59$$20, &_60$$20);
			zephir_array_fast_append(&_59$$20, &actionName);
			zephir_array_fast_append(&_59$$20, &handlerName);
			ZVAL_LONG(&_61$$20, 3);
			ZEPHIR_CALL_METHOD(NULL, &_58$$20, "__construct", &_13, 2, &_59$$20, &_61$$20);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_58$$20, "ice/dispatcher.zep", 251 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_62$$3, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&params, &_62$$3);
		if (Z_TYPE_P(&params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_63$$22);
			object_init_ex(&_63$$22, ice_exception_ce);
			ZEPHIR_INIT_NVAR(&_64$$22);
			ZVAL_STRING(&_64$$22, "Action parameters must be an array");
			ZVAL_LONG(&_65$$22, 4);
			ZEPHIR_CALL_METHOD(NULL, &_63$$22, "__construct", &_13, 2, &_64$$22, &_65$$22);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_63$$22, "ice/dispatcher.zep", 256 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_66$$3);
		ZEPHIR_INIT_NVAR(&_67$$3);
		zephir_create_array(&_67$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_67$$3, &handler);
		zephir_array_fast_append(&_67$$3, &actionMethod);
		ZEPHIR_CALL_USER_FUNC_ARRAY(_66$$3, &_67$$3, &params);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("returnedValue"), &_66$$3);
		zephir_read_property(&_62$$3, this_ptr, SL("finished"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_62$$3)) {
			continue;
		}
		if ((zephir_method_exists_ex(&handler, SS("after") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, &handler, "after", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_68$$24, this_ptr, SL("finished"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_68$$24)) {
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
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
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

