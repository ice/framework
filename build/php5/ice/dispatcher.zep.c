
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
	zend_declare_class_constant_long(ice_dispatcher_ce, SL("DISPATCH_CYCLIC"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_dispatcher_ce, SL("HANDLER_NOT_FOUND"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_dispatcher_ce, SL("ACTION_NOT_FOUND"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(ice_dispatcher_ce, SL("INVALID_PARAMS"), 4 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Dispatcher, getDefaultNamespace) {

	

	RETURN_MEMBER(getThis(), "defaultNamespace");

}

PHP_METHOD(Ice_Dispatcher, setDefaultNamespace) {

	zval *defaultNamespace;

	zephir_fetch_params(0, 1, 0, &defaultNamespace);



	zephir_update_property_this(getThis(), SL("defaultNamespace"), defaultNamespace TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getActiveHandler) {

	

	RETURN_MEMBER(getThis(), "activeHandler");

}

PHP_METHOD(Ice_Dispatcher, getLastHandler) {

	

	RETURN_MEMBER(getThis(), "lastHandler");

}

PHP_METHOD(Ice_Dispatcher, getLoops) {

	

	RETURN_MEMBER(getThis(), "loops");

}

PHP_METHOD(Ice_Dispatcher, setLoops) {

	zval *loops;

	zephir_fetch_params(0, 1, 0, &loops);



	zephir_update_property_this(getThis(), SL("loops"), loops TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getFinished) {

	

	RETURN_MEMBER(getThis(), "finished");

}

PHP_METHOD(Ice_Dispatcher, getForwards) {

	

	RETURN_MEMBER(getThis(), "forwards");

}

PHP_METHOD(Ice_Dispatcher, getForwarded) {

	

	RETURN_MEMBER(getThis(), "forwarded");

}

PHP_METHOD(Ice_Dispatcher, setSilent) {

	zval *silent;

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_this(getThis(), SL("silent"), silent TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getModules) {

	

	RETURN_MEMBER(getThis(), "modules");

}

PHP_METHOD(Ice_Dispatcher, setModules) {

	zval *modules;

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_this(getThis(), SL("modules"), modules TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getModule) {

	

	RETURN_MEMBER(getThis(), "module");

}

PHP_METHOD(Ice_Dispatcher, setModule) {

	zval *module;

	zephir_fetch_params(0, 1, 0, &module);



	zephir_update_property_this(getThis(), SL("module"), module TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getNamespace) {

	

	RETURN_MEMBER(getThis(), "namespace");

}

PHP_METHOD(Ice_Dispatcher, setNamespace) {

	zval *namespace;

	zephir_fetch_params(0, 1, 0, &namespace);



	zephir_update_property_this(getThis(), SL("namespace"), namespace TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getHandler) {

	

	RETURN_MEMBER(getThis(), "handler");

}

PHP_METHOD(Ice_Dispatcher, setHandler) {

	zval *handler;

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_this(getThis(), SL("handler"), handler TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getAction) {

	

	RETURN_MEMBER(getThis(), "action");

}

PHP_METHOD(Ice_Dispatcher, setAction) {

	zval *action;

	zephir_fetch_params(0, 1, 0, &action);



	zephir_update_property_this(getThis(), SL("action"), action TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getParams) {

	

	RETURN_MEMBER(getThis(), "params");

}

PHP_METHOD(Ice_Dispatcher, setParams) {

	zval *params;

	zephir_fetch_params(0, 1, 0, &params);



	zephir_update_property_this(getThis(), SL("params"), params TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getReturnedValue) {

	

	RETURN_MEMBER(getThis(), "returnedValue");

}

PHP_METHOD(Ice_Dispatcher, setReturnedValue) {

	zval *returnedValue;

	zephir_fetch_params(0, 1, 0, &returnedValue);



	zephir_update_property_this(getThis(), SL("returnedValue"), returnedValue TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getHandlerSuffix) {

	

	RETURN_MEMBER(getThis(), "handlerSuffix");

}

PHP_METHOD(Ice_Dispatcher, setHandlerSuffix) {

	zval *handlerSuffix;

	zephir_fetch_params(0, 1, 0, &handlerSuffix);



	zephir_update_property_this(getThis(), SL("handlerSuffix"), handlerSuffix TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dispatcher, getActionSuffix) {

	

	RETURN_MEMBER(getThis(), "actionSuffix");

}

PHP_METHOD(Ice_Dispatcher, setActionSuffix) {

	zval *actionSuffix;

	zephir_fetch_params(0, 1, 0, &actionSuffix);



	zephir_update_property_this(getThis(), SL("actionSuffix"), actionSuffix TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Di constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Dispatcher, __construct) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 1);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("di"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Whether or not an param exists by key.
 *
 * @param string key The param key
 * @return boolean
 */
PHP_METHOD(Ice_Dispatcher, hasParam) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

/**
 * Set a param by its name or numeric index.
 *
 * @param mixed param
 * @param mixed value
 */
PHP_METHOD(Ice_Dispatcher, setParam) {

	zval *param, *value;

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
	zval *key_param = NULL, *filters = NULL, *defaultValue = NULL, *allowEmpty_param = NULL, *params = NULL, *_0, *_1$$4;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &key_param, &filters, &defaultValue, &allowEmpty_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
		zephir_get_strval(key, key_param);
	}
	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!allowEmpty_param) {
		allowEmpty = 0;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	ZEPHIR_INIT_VAR(params);
	object_init_ex(params, ice_arr_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, params, "__construct", NULL, 5, _0);
	zephir_check_call_status();
	if (!(!(!key) && Z_STRLEN_P(key))) {
		RETURN_CCTOR(params);
	} else {
		ZEPHIR_INIT_VAR(_1$$4);
		if (allowEmpty) {
			ZVAL_BOOL(_1$$4, 1);
		} else {
			ZVAL_BOOL(_1$$4, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(params, "getvalue", NULL, 27, key, filters, defaultValue, _1$$4);
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

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("action"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("actionSuffix"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VV(return_value, _0, _1);
	return;

}

/**
 * Dispatches a handle action taking into account the routing parameters.
 *
 * @return object
 */
PHP_METHOD(Ice_Dispatcher, dispatch) {

	zval *_68$$3 = NULL, *_30$$6 = NULL, *_20$$7 = NULL, *_24$$10 = NULL, *_49$$14 = NULL, *_61$$20 = NULL;
	zend_bool fresh = 0, _4$$3;
	zval *handler = NULL, *response = NULL, *handlerName = NULL, *actionName = NULL, *params = NULL, *handlerSuffix = NULL, *handlerClass = NULL, *actionMethod = NULL, *module = NULL, *modules = NULL, *moduleNamespace = NULL, *path = NULL, *moduleClass = NULL, *loader = NULL, *_0, *_1, *_2, *_3$$3, *_5$$3, *_6$$3, *_17$$3, *_39$$3, *_40$$3 = NULL, *_41$$3 = NULL, *_51$$3, *_63$$3, *_67$$3 = NULL, *_7$$4, *_13$$4 = NULL, *_14$$4 = NULL, *_15$$4 = NULL, *_8$$5 = NULL, *_10$$5 = NULL, *_18$$6, *_26$$6 = NULL, *_28$$6 = NULL, *_29$$6 = NULL, *_31$$6 = NULL, *_32$$6, *_33$$6, *_19$$7 = NULL, *_21$$7 = NULL, *_22$$7 = NULL, *_23$$10 = NULL, *_25$$10 = NULL, *_34$$13, *_35$$13 = NULL, *_37$$13 = NULL, *_42$$14, *_48$$14 = NULL, *_50$$14 = NULL, *_43$$15 = NULL, *_45$$15 = NULL, *_53$$16, *_54$$20, *_60$$20 = NULL, *_62$$20 = NULL, *_55$$21 = NULL, *_57$$21 = NULL, *_64$$22 = NULL, *_65$$22 = NULL, *_66$$22 = NULL, *_69$$24;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_12 = NULL, *_16 = NULL, *_27 = NULL, *_36 = NULL, *_38 = NULL, *_44 = NULL, *_46 = NULL, *_47 = NULL, *_52 = NULL, *_56 = NULL, *_58 = NULL, *_59 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "response", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&response, _0, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	fresh = 1;
	ZEPHIR_INIT_VAR(handler);
	ZVAL_NULL(handler);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("handlerSuffix"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(handlerSuffix, _2);
	if (0) {
		zephir_update_property_this(getThis(), SL("finished"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("finished"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("finished"), PH_NOISY_CC);
		if (!(!(zephir_is_true(_2)))) {
			break;
		}
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("forwards") TSRMLS_CC));
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("loops"), PH_NOISY_CC);
		_4$$3 = zephir_is_true(_3$$3);
		if (_4$$3) {
			_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("forwards"), PH_NOISY_CC);
			_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("loops"), PH_NOISY_CC);
			_4$$3 = ZEPHIR_GT(_5$$3, _6$$3);
		}
		if (_4$$3) {
			_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_7$$4)) {
				ZEPHIR_INIT_NVAR(_8$$5);
				ZVAL_LONG(_8$$5, 508);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", &_9, 0, _8$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_8$$5);
				ZVAL_LONG(_8$$5, 508);
				ZEPHIR_CALL_METHOD(&_10$$5, response, "getmessage", &_11, 0, _8$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", &_12, 0, _10$$5);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_13$$4);
			object_init_ex(_13$$4, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_14$$4);
			ZVAL_STRING(_14$$4, "Dispatcher has detected a cyclic routing causing stability problems", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_15$$4);
			ZVAL_LONG(_15$$4, 1);
			ZEPHIR_CALL_METHOD(NULL, _13$$4, "__construct", &_16, 13, _14$$4, _15$$4);
			zephir_check_temp_parameter(_14$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_13$$4, "ice/dispatcher.zep", 153 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (1) {
			zephir_update_property_this(getThis(), SL("finished"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("finished"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		_17$$3 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(modules, _17$$3);
		if (zephir_is_true(modules)) {
			ZEPHIR_OBS_NVAR(module);
			_18$$6 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
			if (!(zephir_array_isset_fetch(&module, modules, _18$$6, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_19$$7);
				object_init_ex(_19$$7, ice_exception_ce);
				ZEPHIR_INIT_NVAR(_20$$7);
				zephir_create_array(_20$$7, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_21$$7);
				ZVAL_STRING(_21$$7, "Module '%s' isn't registered in the application container", 1);
				zephir_array_fast_append(_20$$7, _21$$7);
				ZEPHIR_OBS_NVAR(_22$$7);
				zephir_read_property_this(&_22$$7, this_ptr, SL("module"), PH_NOISY_CC);
				zephir_array_fast_append(_20$$7, _22$$7);
				ZEPHIR_CALL_METHOD(NULL, _19$$7, "__construct", &_16, 13, _20$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_19$$7, "ice/dispatcher.zep", 161 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(module) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Module definition must be an array", "ice/dispatcher.zep", 165);
				return;
			}
			ZEPHIR_OBS_NVAR(path);
			if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
				if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
					ZEPHIR_INIT_NVAR(_23$$10);
					object_init_ex(_23$$10, ice_exception_ce);
					ZEPHIR_INIT_NVAR(_24$$10);
					zephir_create_array(_24$$10, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_25$$10);
					ZVAL_STRING(_25$$10, "Module definition path '%s' doesn't exist", 1);
					zephir_array_fast_append(_24$$10, _25$$10);
					zephir_array_fast_append(_24$$10, path);
					ZEPHIR_CALL_METHOD(NULL, _23$$10, "__construct", &_16, 13, _24$$10);
					zephir_check_call_status();
					zephir_throw_exception_debug(_23$$10, "ice/dispatcher.zep", 170 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(moduleClass);
			if (!(zephir_array_isset_string_fetch(&moduleClass, module, SS("class"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(moduleClass);
				ZVAL_STRING(moduleClass, "Module", 1);
			}
			ZEPHIR_OBS_NVAR(moduleNamespace);
			if (!(zephir_array_isset_string_fetch(&moduleNamespace, module, SS("namespace"), 0 TSRMLS_CC))) {
				ZEPHIR_CPY_WRT(moduleNamespace, moduleClass);
			}
			ZEPHIR_INIT_NVAR(loader);
			object_init_ex(loader, ice_loader_ce);
			if (zephir_has_constructor(loader TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			zephir_update_property_this(getThis(), SL("namespace"), moduleNamespace TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_26$$6, loader, "addnamespace", &_27, 28, moduleNamespace, path);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _26$$6, "register", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_28$$6);
			ZEPHIR_INIT_LNVAR(_29$$6);
			ZEPHIR_CONCAT_VSV(_29$$6, moduleNamespace, "\\", moduleClass);
			ZEPHIR_INIT_NVAR(_30$$6);
			zephir_create_array(_30$$6, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_31$$6);
			zephir_read_property_this(&_31$$6, this_ptr, SL("di"), PH_NOISY_CC);
			zephir_array_fast_append(_30$$6, _31$$6);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_28$$6, _29$$6, _30$$6 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(module, _28$$6);
			_32$$6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, module, "registerautoloaders", NULL, 0, _32$$6);
			zephir_check_call_status();
			_33$$6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, module, "registerservices", NULL, 0, _33$$6);
			zephir_check_call_status();
		}
		_17$$3 = zephir_fetch_nproperty_this(this_ptr, SL("defaultNamespace"), PH_NOISY_CC);
		if (!(zephir_is_true(_17$$3))) {
			_34$$13 = zephir_fetch_nproperty_this(this_ptr, SL("namespace"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_35$$13, this_ptr, "gethandlersuffix", &_36, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_37$$13);
			ZEPHIR_CONCAT_VSV(_37$$13, _34$$13, "\\", _35$$13);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultnamespace", &_38, 0, _37$$13);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(handlerName);
		zephir_read_property_this(&handlerName, this_ptr, SL("handler"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(actionName);
		zephir_read_property_this(&actionName, this_ptr, SL("action"), PH_NOISY_CC);
		_39$$3 = zephir_fetch_nproperty_this(this_ptr, SL("defaultNamespace"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_40$$3);
		ZEPHIR_INIT_NVAR(_41$$3);
		zephir_camelize(_41$$3, handlerName, NULL  );
		zephir_ucfirst(_40$$3, _41$$3);
		ZEPHIR_INIT_NVAR(handlerClass);
		ZEPHIR_CONCAT_VSVV(handlerClass, _39$$3, "\\", _40$$3, handlerSuffix);
		if (!(zephir_class_exists(handlerClass, 1 TSRMLS_CC))) {
			_42$$14 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_42$$14)) {
				ZEPHIR_INIT_NVAR(_43$$15);
				ZVAL_LONG(_43$$15, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", &_44, 0, _43$$15);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_43$$15);
				ZVAL_LONG(_43$$15, 404);
				ZEPHIR_CALL_METHOD(&_45$$15, response, "getmessage", &_46, 0, _43$$15);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", &_47, 0, _45$$15);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_48$$14);
			object_init_ex(_48$$14, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_49$$14);
			zephir_create_array(_49$$14, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_50$$14);
			ZVAL_STRING(_50$$14, "%s handler class cannot be loaded", 1);
			zephir_array_fast_append(_49$$14, _50$$14);
			zephir_array_fast_append(_49$$14, handlerClass);
			ZEPHIR_INIT_NVAR(_50$$14);
			ZVAL_LONG(_50$$14, 2);
			ZEPHIR_CALL_METHOD(NULL, _48$$14, "__construct", &_16, 13, _49$$14, _50$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(_48$$14, "ice/dispatcher.zep", 209 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_this(getThis(), SL("lastHandler"), handler TSRMLS_CC);
		_51$$3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&handler, _51$$3, "build", NULL, 0, handlerClass);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("activeHandler"), handler TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_52, 0);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(handler, SS("before") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, handler, "before", NULL, 0);
			zephir_check_call_status();
			_53$$16 = zephir_fetch_nproperty_this(this_ptr, SL("finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_53$$16)) {
				continue;
			}
		}
		if (fresh == 1) {
			if ((zephir_method_exists_ex(handler, SS("initialize") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(NULL, handler, "initialize", NULL, 0);
				zephir_check_call_status();
			}
		}
		if (!((zephir_method_exists(handler, actionMethod TSRMLS_CC)  == SUCCESS))) {
			_54$$20 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_54$$20)) {
				ZEPHIR_INIT_NVAR(_55$$21);
				ZVAL_LONG(_55$$21, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", &_56, 0, _55$$21);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_55$$21);
				ZVAL_LONG(_55$$21, 404);
				ZEPHIR_CALL_METHOD(&_57$$21, response, "getmessage", &_58, 0, _55$$21);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", &_59, 0, _57$$21);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_60$$20);
			object_init_ex(_60$$20, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_61$$20);
			zephir_create_array(_61$$20, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_62$$20);
			ZVAL_STRING(_62$$20, "Action '%s' was not found on handler '%s'", 1);
			zephir_array_fast_append(_61$$20, _62$$20);
			zephir_array_fast_append(_61$$20, actionName);
			zephir_array_fast_append(_61$$20, handlerName);
			ZEPHIR_INIT_NVAR(_62$$20);
			ZVAL_LONG(_62$$20, 3);
			ZEPHIR_CALL_METHOD(NULL, _60$$20, "__construct", &_16, 13, _61$$20, _62$$20);
			zephir_check_call_status();
			zephir_throw_exception_debug(_60$$20, "ice/dispatcher.zep", 241 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_63$$3 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(params, _63$$3);
		if (Z_TYPE_P(params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_64$$22);
			object_init_ex(_64$$22, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_65$$22);
			ZVAL_STRING(_65$$22, "Action parameters must be an array", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_66$$22);
			ZVAL_LONG(_66$$22, 4);
			ZEPHIR_CALL_METHOD(NULL, _64$$22, "__construct", &_16, 13, _65$$22, _66$$22);
			zephir_check_temp_parameter(_65$$22);
			zephir_check_call_status();
			zephir_throw_exception_debug(_64$$22, "ice/dispatcher.zep", 246 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_67$$3);
		ZEPHIR_INIT_NVAR(_68$$3);
		zephir_create_array(_68$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_68$$3, handler);
		zephir_array_fast_append(_68$$3, actionMethod);
		ZEPHIR_CALL_USER_FUNC_ARRAY(_67$$3, _68$$3, params);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("returnedValue"), _67$$3 TSRMLS_CC);
		_63$$3 = zephir_fetch_nproperty_this(this_ptr, SL("finished"), PH_NOISY_CC);
		if (ZEPHIR_IS_FALSE_IDENTICAL(_63$$3)) {
			continue;
		}
		if ((zephir_method_exists_ex(handler, SS("after") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, handler, "after", NULL, 0);
			zephir_check_call_status();
			_69$$24 = zephir_fetch_nproperty_this(this_ptr, SL("finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_69$$24)) {
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
	zval *forward_param = NULL, *force_param = NULL, *module = NULL, *handler = NULL, *action = NULL, *params = NULL, *_0$$3, *_1$$4, *_2$$5;
	zval *forward = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &forward_param, &force_param);

	forward = forward_param;
	if (!force_param) {
		force = 0;
	} else {
		force = zephir_get_boolval(force_param);
	}


	ZEPHIR_OBS_VAR(module);
	if (zephir_array_isset_string_fetch(&module, forward, SS("module"), 0 TSRMLS_CC)) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("previousModule"), _0$$3 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("module"), module TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(handler);
	if (zephir_array_isset_string_fetch(&handler, forward, SS("handler"), 0 TSRMLS_CC)) {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("previousHandler"), _1$$4 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("handler"), handler TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(action);
	if (zephir_array_isset_string_fetch(&action, forward, SS("action"), 0 TSRMLS_CC)) {
		_2$$5 = zephir_fetch_nproperty_this(this_ptr, SL("action"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("previousAction"), _2$$5 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("action"), action TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(params);
	if (zephir_array_isset_string_fetch(&params, forward, SS("params"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("params"), params TSRMLS_CC);
	}
	if (0) {
		zephir_update_property_this(getThis(), SL("finished"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("finished"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (1) {
		zephir_update_property_this(getThis(), SL("forwarded"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("forwarded"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (force) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Ice_Dispatcher(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

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
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("modules"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

