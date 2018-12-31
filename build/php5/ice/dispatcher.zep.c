
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

	zend_declare_property_string(ice_dispatcher_ce, SL("handlers"), "Handlers", ZEND_ACC_PROTECTED TSRMLS_CC);

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

PHP_METHOD(Ice_Dispatcher, getHandlers) {

	

	RETURN_MEMBER(getThis(), "handlers");

}

PHP_METHOD(Ice_Dispatcher, setHandlers) {

	zval *handlers;

	zephir_fetch_params(0, 1, 0, &handlers);



	zephir_update_property_this(getThis(), SL("handlers"), handlers TSRMLS_CC);
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
		ZEPHIR_RETURN_CALL_METHOD(params, "getvalue", NULL, 46, key, filters, defaultValue, _1$$4);
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
 * Add module with its dir path, initial class name and namespace
 *
 * @param string name
 * @param array options The keys can be [path|class|namespace]
 * @return object Dispatcher
 */
PHP_METHOD(Ice_Dispatcher, addModule) {

	zval *options = NULL;
	zval *name_param = NULL, *options_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &options_param);

	zephir_get_strval(name, name_param);
	zephir_get_arrval(options, options_param);


	zephir_update_property_array(this_ptr, SL("modules"), name, options TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Dispatches a handle action taking into account the routing parameters.
 *
 * @return object
 */
PHP_METHOD(Ice_Dispatcher, dispatch) {

	zval *_66$$3 = NULL, *_30$$6 = NULL, *_20$$7 = NULL, *_24$$10 = NULL, *_47$$14 = NULL, *_59$$20 = NULL;
	zend_bool fresh = 0, _4$$3;
	zval *handler = NULL, *response = NULL, *handlerName = NULL, *actionName = NULL, *params = NULL, *handlerSuffix = NULL, *handlerClass = NULL, *actionMethod = NULL, *module = NULL, *modules = NULL, *moduleNamespace = NULL, *path = NULL, *moduleClass = NULL, *loader = NULL, *_0, *_1, *_2, *_3$$3, *_5$$3, *_6$$3, *_17$$3, *_37$$3, *_38$$3 = NULL, *_39$$3 = NULL, *_49$$3, *_61$$3, *_65$$3 = NULL, *_7$$4, *_13$$4 = NULL, *_14$$4 = NULL, *_15$$4 = NULL, *_8$$5 = NULL, *_10$$5 = NULL, *_18$$6, *_26$$6, *_27$$6 = NULL, *_28$$6 = NULL, *_29$$6 = NULL, *_31$$6 = NULL, *_32$$6, *_19$$7 = NULL, *_21$$7 = NULL, *_22$$7 = NULL, *_23$$10 = NULL, *_25$$10 = NULL, *_33$$13, *_34$$13, *_35$$13 = NULL, *_40$$14, *_46$$14 = NULL, *_48$$14 = NULL, *_41$$15 = NULL, *_43$$15 = NULL, *_51$$16, *_52$$20, *_58$$20 = NULL, *_60$$20 = NULL, *_53$$21 = NULL, *_55$$21 = NULL, *_62$$22 = NULL, *_63$$22 = NULL, *_64$$22 = NULL, *_67$$24;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_12 = NULL, *_16 = NULL, *_36 = NULL, *_42 = NULL, *_44 = NULL, *_45 = NULL, *_50 = NULL, *_54 = NULL, *_56 = NULL, *_57 = NULL;
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
			zephir_throw_exception_debug(_13$$4, "ice/dispatcher.zep", 169 TSRMLS_CC);
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
				zephir_throw_exception_debug(_19$$7, "ice/dispatcher.zep", 177 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(module) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Module definition must be an array", "ice/dispatcher.zep", 181);
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
					zephir_throw_exception_debug(_23$$10, "ice/dispatcher.zep", 186 TSRMLS_CC);
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
			_26$$6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_27$$6);
			ZVAL_STRING(_27$$6, "loader", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&loader, _26$$6, "get", NULL, 0, _27$$6);
			zephir_check_temp_parameter(_27$$6);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("namespace"), moduleNamespace TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_28$$6, loader, "addnamespace", NULL, 0, moduleNamespace, path);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _28$$6, "register", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_27$$6);
			ZEPHIR_INIT_LNVAR(_29$$6);
			ZEPHIR_CONCAT_VSV(_29$$6, moduleNamespace, "\\", moduleClass);
			ZEPHIR_INIT_NVAR(_30$$6);
			zephir_create_array(_30$$6, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_31$$6);
			zephir_read_property_this(&_31$$6, this_ptr, SL("di"), PH_NOISY_CC);
			zephir_array_fast_append(_30$$6, _31$$6);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_27$$6, _29$$6, _30$$6 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(module, _27$$6);
			ZEPHIR_CALL_METHOD(NULL, module, "registerautoloaders", NULL, 0, loader);
			zephir_check_call_status();
			_32$$6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, module, "registerservices", NULL, 0, _32$$6);
			zephir_check_call_status();
		}
		_17$$3 = zephir_fetch_nproperty_this(this_ptr, SL("defaultNamespace"), PH_NOISY_CC);
		if (!(zephir_is_true(_17$$3))) {
			_33$$13 = zephir_fetch_nproperty_this(this_ptr, SL("namespace"), PH_NOISY_CC);
			_34$$13 = zephir_fetch_nproperty_this(this_ptr, SL("handlers"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_35$$13);
			ZEPHIR_CONCAT_VSV(_35$$13, _33$$13, "\\", _34$$13);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultnamespace", &_36, 0, _35$$13);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(handlerName);
		zephir_read_property_this(&handlerName, this_ptr, SL("handler"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(actionName);
		zephir_read_property_this(&actionName, this_ptr, SL("action"), PH_NOISY_CC);
		_37$$3 = zephir_fetch_nproperty_this(this_ptr, SL("defaultNamespace"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_38$$3);
		ZEPHIR_INIT_NVAR(_39$$3);
		zephir_camelize(_39$$3, handlerName, NULL  );
		zephir_ucfirst(_38$$3, _39$$3);
		ZEPHIR_INIT_NVAR(handlerClass);
		ZEPHIR_CONCAT_VSVV(handlerClass, _37$$3, "\\", _38$$3, handlerSuffix);
		if (!(zephir_class_exists(handlerClass, 1 TSRMLS_CC))) {
			_40$$14 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_40$$14)) {
				ZEPHIR_INIT_NVAR(_41$$15);
				ZVAL_LONG(_41$$15, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", &_42, 0, _41$$15);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_41$$15);
				ZVAL_LONG(_41$$15, 404);
				ZEPHIR_CALL_METHOD(&_43$$15, response, "getmessage", &_44, 0, _41$$15);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", &_45, 0, _43$$15);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_46$$14);
			object_init_ex(_46$$14, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_47$$14);
			zephir_create_array(_47$$14, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_48$$14);
			ZVAL_STRING(_48$$14, "%s handler class cannot be loaded", 1);
			zephir_array_fast_append(_47$$14, _48$$14);
			zephir_array_fast_append(_47$$14, handlerClass);
			ZEPHIR_INIT_NVAR(_48$$14);
			ZVAL_LONG(_48$$14, 2);
			ZEPHIR_CALL_METHOD(NULL, _46$$14, "__construct", &_16, 13, _47$$14, _48$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(_46$$14, "ice/dispatcher.zep", 225 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_this(getThis(), SL("lastHandler"), handler TSRMLS_CC);
		_49$$3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&handler, _49$$3, "build", NULL, 0, handlerClass);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("activeHandler"), handler TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_50, 0);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(handler, SS("before") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, handler, "before", NULL, 0);
			zephir_check_call_status();
			_51$$16 = zephir_fetch_nproperty_this(this_ptr, SL("finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_51$$16)) {
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
			_52$$20 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_52$$20)) {
				ZEPHIR_INIT_NVAR(_53$$21);
				ZVAL_LONG(_53$$21, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", &_54, 0, _53$$21);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_53$$21);
				ZVAL_LONG(_53$$21, 404);
				ZEPHIR_CALL_METHOD(&_55$$21, response, "getmessage", &_56, 0, _53$$21);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", &_57, 0, _55$$21);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_58$$20);
			object_init_ex(_58$$20, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_59$$20);
			zephir_create_array(_59$$20, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_60$$20);
			ZVAL_STRING(_60$$20, "Action '%s' was not found on handler '%s'", 1);
			zephir_array_fast_append(_59$$20, _60$$20);
			zephir_array_fast_append(_59$$20, actionName);
			zephir_array_fast_append(_59$$20, handlerName);
			ZEPHIR_INIT_NVAR(_60$$20);
			ZVAL_LONG(_60$$20, 3);
			ZEPHIR_CALL_METHOD(NULL, _58$$20, "__construct", &_16, 13, _59$$20, _60$$20);
			zephir_check_call_status();
			zephir_throw_exception_debug(_58$$20, "ice/dispatcher.zep", 257 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_61$$3 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(params, _61$$3);
		if (Z_TYPE_P(params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_62$$22);
			object_init_ex(_62$$22, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_63$$22);
			ZVAL_STRING(_63$$22, "Action parameters must be an array", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_64$$22);
			ZVAL_LONG(_64$$22, 4);
			ZEPHIR_CALL_METHOD(NULL, _62$$22, "__construct", &_16, 13, _63$$22, _64$$22);
			zephir_check_temp_parameter(_63$$22);
			zephir_check_call_status();
			zephir_throw_exception_debug(_62$$22, "ice/dispatcher.zep", 262 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_65$$3);
		ZEPHIR_INIT_NVAR(_66$$3);
		zephir_create_array(_66$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_66$$3, handler);
		zephir_array_fast_append(_66$$3, actionMethod);
		ZEPHIR_CALL_USER_FUNC_ARRAY(_65$$3, _66$$3, params);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("returnedValue"), _65$$3 TSRMLS_CC);
		_61$$3 = zephir_fetch_nproperty_this(this_ptr, SL("finished"), PH_NOISY_CC);
		if (ZEPHIR_IS_FALSE_IDENTICAL(_61$$3)) {
			continue;
		}
		if ((zephir_method_exists_ex(handler, SS("after") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, handler, "after", NULL, 0);
			zephir_check_call_status();
			_67$$24 = zephir_fetch_nproperty_this(this_ptr, SL("finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_67$$24)) {
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
 * @return object Dispatcher
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
	RETURN_THIS();

}

/**
 * Reset module, handler and action to default ones, and empty the params.
 *
 * @return object Dispatcher
 */
PHP_METHOD(Ice_Dispatcher, reset) {

	zval *router = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, _0, SL("router"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(router, _1);
	ZEPHIR_CALL_METHOD(&_3, router, "getdefaultmodule", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "setmodule", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, router, "getdefaulthandler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _2, "sethandler", NULL, 0, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, router, "getdefaultaction", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, _4, "setaction", NULL, 0, _7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	array_init(_8);
	ZEPHIR_CALL_METHOD(NULL, _6, "setparams", NULL, 0, _8);
	zephir_check_call_status();
	RETURN_THIS();

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

