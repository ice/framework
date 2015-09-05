
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
	zend_declare_class_constant_long(ice_dispatcher_ce, SL("DISPATCH_CYCLIC"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_dispatcher_ce, SL("HANDLER_NOT_FOUND"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_dispatcher_ce, SL("ACTION_NOT_FOUND"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(ice_dispatcher_ce, SL("INVALID_PARAMS"), 4 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Dispatcher, getDefaultNamespace) {


	RETURN_MEMBER(this_ptr, "defaultNamespace");

}

PHP_METHOD(Ice_Dispatcher, setDefaultNamespace) {

	zval *defaultNamespace;

	zephir_fetch_params(0, 1, 0, &defaultNamespace);



	zephir_update_property_this(this_ptr, SL("defaultNamespace"), defaultNamespace TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getActiveHandler) {


	RETURN_MEMBER(this_ptr, "activeHandler");

}

PHP_METHOD(Ice_Dispatcher, getLastHandler) {


	RETURN_MEMBER(this_ptr, "lastHandler");

}

PHP_METHOD(Ice_Dispatcher, getLoops) {


	RETURN_MEMBER(this_ptr, "loops");

}

PHP_METHOD(Ice_Dispatcher, getFinished) {


	RETURN_MEMBER(this_ptr, "finished");

}

PHP_METHOD(Ice_Dispatcher, getForwarded) {


	RETURN_MEMBER(this_ptr, "forwarded");

}

PHP_METHOD(Ice_Dispatcher, setSilent) {

	zval *silent;

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_this(this_ptr, SL("silent"), silent TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getModules) {


	RETURN_MEMBER(this_ptr, "modules");

}

PHP_METHOD(Ice_Dispatcher, setModules) {

	zval *modules;

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_this(this_ptr, SL("modules"), modules TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getModule) {


	RETURN_MEMBER(this_ptr, "module");

}

PHP_METHOD(Ice_Dispatcher, setModule) {

	zval *module;

	zephir_fetch_params(0, 1, 0, &module);



	zephir_update_property_this(this_ptr, SL("module"), module TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getNamespace) {


	RETURN_MEMBER(this_ptr, "namespace");

}

PHP_METHOD(Ice_Dispatcher, setNamespace) {

	zval *namespace;

	zephir_fetch_params(0, 1, 0, &namespace);



	zephir_update_property_this(this_ptr, SL("namespace"), namespace TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getHandler) {


	RETURN_MEMBER(this_ptr, "handler");

}

PHP_METHOD(Ice_Dispatcher, setHandler) {

	zval *handler;

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_this(this_ptr, SL("handler"), handler TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getAction) {


	RETURN_MEMBER(this_ptr, "action");

}

PHP_METHOD(Ice_Dispatcher, setAction) {

	zval *action;

	zephir_fetch_params(0, 1, 0, &action);



	zephir_update_property_this(this_ptr, SL("action"), action TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getParams) {


	RETURN_MEMBER(this_ptr, "params");

}

PHP_METHOD(Ice_Dispatcher, setParams) {

	zval *params;

	zephir_fetch_params(0, 1, 0, &params);



	zephir_update_property_this(this_ptr, SL("params"), params TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getReturnedValue) {


	RETURN_MEMBER(this_ptr, "returnedValue");

}

PHP_METHOD(Ice_Dispatcher, setReturnedValue) {

	zval *returnedValue;

	zephir_fetch_params(0, 1, 0, &returnedValue);



	zephir_update_property_this(this_ptr, SL("returnedValue"), returnedValue TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getHandlerSuffix) {


	RETURN_MEMBER(this_ptr, "handlerSuffix");

}

PHP_METHOD(Ice_Dispatcher, setHandlerSuffix) {

	zval *handlerSuffix;

	zephir_fetch_params(0, 1, 0, &handlerSuffix);



	zephir_update_property_this(this_ptr, SL("handlerSuffix"), handlerSuffix TSRMLS_CC);

}

PHP_METHOD(Ice_Dispatcher, getActionSuffix) {


	RETURN_MEMBER(this_ptr, "actionSuffix");

}

PHP_METHOD(Ice_Dispatcher, setActionSuffix) {

	zval *actionSuffix;

	zephir_fetch_params(0, 1, 0, &actionSuffix);



	zephir_update_property_this(this_ptr, SL("actionSuffix"), actionSuffix TSRMLS_CC);

}

/**
 * Di constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Dispatcher, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 8);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _0 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowEmpty, _7, _8;
	zval *key_param = NULL, *filters = NULL, *defaultValue = NULL, *allowEmpty_param = NULL, *params, *value = NULL, *filter = NULL, *_0, *_1 = NULL, *_3, *_4, *_5, *_6 = NULL;
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
	ZEPHIR_CALL_METHOD(NULL, params, "__construct", NULL, 6, _0);
	zephir_check_call_status();
	if (!(key && Z_STRLEN_P(key))) {
		RETURN_CCTOR(params);
	} else {
		ZEPHIR_CALL_METHOD(&value, params, "get", NULL, 27, key, defaultValue);
		zephir_check_call_status();
		if (zephir_is_true(filters)) {
			ZEPHIR_CALL_CE_STATIC(&_1, ice_di_ce, "fetch", &_2, 8);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "filter", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_4);
			ZVAL_NULL(_4);
			ZEPHIR_INIT_VAR(_5);
			ZVAL_BOOL(_5, 1);
			ZEPHIR_CALL_METHOD(&filter, _1, "get", NULL, 27, _3, _4, _5);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6, filter, "sanitize", NULL, 0, value, filters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _6);
		}
		_7 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
		if (!(_7)) {
			_7 = Z_TYPE_P(value) == IS_NULL;
		}
		_8 = _7;
		if (_8) {
			_8 = allowEmpty == 0;
		}
		if (_8) {
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

	zend_class_entry *_25;
	zval *_12 = NULL, *_30 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_8 = NULL, *_11 = NULL, *_14 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL, *_26 = NULL, *_27 = NULL, *_28 = NULL, *_29 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool fresh;
	zval *handler = NULL, *response = NULL, *handlerName = NULL, *actionName = NULL, *params = NULL, *handlerSuffix = NULL, *handlerClass = NULL, *actionMethod = NULL, *module = NULL, *modules = NULL, *moduleNamespace = NULL, *path = NULL, *moduleClass = NULL, *loader = NULL, *_0, *_1 = NULL, *_2, *_3, *_4, *_6 = NULL, *_9 = NULL, *_10 = NULL, *_13 = NULL, *_15 = NULL, *_16, *_17 = NULL, *_23 = NULL, *_24 = NULL;

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
	zephir_update_property_this(this_ptr, SL("finished"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("finished"), PH_NOISY_CC);
		if (!(!(zephir_is_true(_2)))) {
			break;
		}
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("loops") TSRMLS_CC));
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("loops"), PH_NOISY_CC);
		if (ZEPHIR_GT_LONG(_3, 16)) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_4)) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 508);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", &_5, 0, _1);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 508);
				ZEPHIR_CALL_METHOD(&_6, response, "getmessage", &_7, 0, _1);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", &_8, 0, _6);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_1);
			object_init_ex(_1, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_STRING(_9, "Dispatcher has detected a cyclic routing causing stability problems", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_LONG(_10, 1);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_11, 2, _9, _10);
			zephir_check_temp_parameter(_9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "ice/dispatcher.zep", 163 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_this(this_ptr, SL("finished"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(modules, _4);
		if (zephir_is_true(modules)) {
			ZEPHIR_OBS_NVAR(module);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
			if (!(zephir_array_isset_fetch(&module, modules, _4, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, ice_exception_ce);
				ZEPHIR_INIT_NVAR(_12);
				zephir_create_array(_12, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_STRING(_9, "Module '%s' isn't registered in the application container", 1);
				zephir_array_fast_append(_12, _9);
				ZEPHIR_OBS_NVAR(_13);
				zephir_read_property_this(&_13, this_ptr, SL("module"), PH_NOISY_CC);
				zephir_array_fast_append(_12, _13);
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_11, 2, _12);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "ice/dispatcher.zep", 171 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(module) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Module definition must be an array", "ice/dispatcher.zep", 175);
				return;
			}
			ZEPHIR_OBS_NVAR(path);
			if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
				if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
					ZEPHIR_INIT_NVAR(_1);
					object_init_ex(_1, ice_exception_ce);
					ZEPHIR_INIT_NVAR(_12);
					zephir_create_array(_12, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_9);
					ZVAL_STRING(_9, "Module definition path '%s' doesn't exist", 1);
					zephir_array_fast_append(_12, _9);
					zephir_array_fast_append(_12, path);
					ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_11, 2, _12);
					zephir_check_call_status();
					zephir_throw_exception_debug(_1, "ice/dispatcher.zep", 180 TSRMLS_CC);
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
			zephir_update_property_this(this_ptr, SL("namespace"), moduleNamespace TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_6, loader, "addnamespace", &_14, 28, moduleNamespace, path);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _6, "register", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_INIT_LNVAR(_15);
			ZEPHIR_CONCAT_VSV(_15, moduleNamespace, "\\", moduleClass);
			ZEPHIR_INIT_NVAR(_12);
			zephir_create_array(_12, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_13);
			zephir_read_property_this(&_13, this_ptr, SL("di"), PH_NOISY_CC);
			zephir_array_fast_append(_12, _13);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_1, _15, _12 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(module, _1);
			ZEPHIR_CALL_METHOD(NULL, module, "registerautoloaders", NULL, 0);
			zephir_check_call_status();
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, module, "registerservices", NULL, 0, _16);
			zephir_check_call_status();
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("defaultNamespace"), PH_NOISY_CC);
		if (!(zephir_is_true(_4))) {
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("namespace"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_17, this_ptr, "gethandlersuffix", &_18, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_15);
			ZEPHIR_CONCAT_VSV(_15, _16, "\\", _17);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultnamespace", &_19, 0, _15);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(handlerName);
		zephir_read_property_this(&handlerName, this_ptr, SL("handler"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(actionName);
		zephir_read_property_this(&actionName, this_ptr, SL("action"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("defaultNamespace"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_NVAR(_9);
		zephir_camelize(_9, handlerName);
		zephir_ucfirst(_1, _9);
		ZEPHIR_INIT_NVAR(handlerClass);
		ZEPHIR_CONCAT_VSVV(handlerClass, _4, "\\", _1, handlerSuffix);
		if (!(zephir_class_exists(handlerClass, 1 TSRMLS_CC))) {
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_16)) {
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_LONG(_10, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", &_20, 0, _10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_LONG(_10, 404);
				ZEPHIR_CALL_METHOD(&_17, response, "getmessage", &_21, 0, _10);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", &_22, 0, _17);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_10);
			object_init_ex(_10, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_12);
			zephir_create_array(_12, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_23);
			ZVAL_STRING(_23, "%s handler class cannot be loaded", 1);
			zephir_array_fast_append(_12, _23);
			zephir_array_fast_append(_12, handlerClass);
			ZEPHIR_INIT_NVAR(_23);
			ZVAL_LONG(_23, 2);
			ZEPHIR_CALL_METHOD(NULL, _10, "__construct", &_11, 2, _12, _23);
			zephir_check_call_status();
			zephir_throw_exception_debug(_10, "ice/dispatcher.zep", 219 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_this(this_ptr, SL("lastHandler"), handler TSRMLS_CC);
		ZEPHIR_INIT_NVAR(handler);
		zephir_fetch_safe_class(_24, handlerClass);
		_25 = zend_fetch_class(Z_STRVAL_P(_24), Z_STRLEN_P(_24), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(handler, _25);
		if (zephir_has_constructor(handler TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, handler, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("activeHandler"), handler TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&actionMethod, this_ptr, "getactivemethod", &_26, 0);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(handler, SS("before") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, handler, "before", NULL, 0);
			zephir_check_call_status();
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_4)) {
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
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_4)) {
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", &_27, 0, _9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, 404);
				ZEPHIR_CALL_METHOD(&_6, response, "getmessage", &_28, 0, _9);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", &_29, 0, _6);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_9);
			object_init_ex(_9, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_12);
			zephir_create_array(_12, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_STRING(_10, "Action '%s' was not found on handler '%s'", 1);
			zephir_array_fast_append(_12, _10);
			zephir_array_fast_append(_12, actionName);
			zephir_array_fast_append(_12, handlerName);
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_LONG(_10, 3);
			ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_11, 2, _12, _10);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9, "ice/dispatcher.zep", 251 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(params, _4);
		if (Z_TYPE_P(params) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_9);
			object_init_ex(_9, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_STRING(_10, "Action parameters must be an array", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_23);
			ZVAL_LONG(_23, 4);
			ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_11, 2, _10, _23);
			zephir_check_temp_parameter(_10);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9, "ice/dispatcher.zep", 256 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_9);
		ZEPHIR_INIT_NVAR(_30);
		zephir_create_array(_30, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_30, handler);
		zephir_array_fast_append(_30, actionMethod);
		ZEPHIR_CALL_USER_FUNC_ARRAY(_9, _30, params);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("returnedValue"), _9 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("finished"), PH_NOISY_CC);
		if (ZEPHIR_IS_FALSE_IDENTICAL(_4)) {
			continue;
		}
		if ((zephir_method_exists_ex(handler, SS("after") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, handler, "after", NULL, 0);
			zephir_check_call_status();
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("finished"), PH_NOISY_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(_4)) {
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
	zval *forward_param = NULL, *force_param = NULL, *module, *handler, *action, *params, *_0;
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
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("previousModule"), _0 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("module"), module TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(handler);
	if (zephir_array_isset_string_fetch(&handler, forward, SS("handler"), 0 TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("previousHandler"), _0 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("handler"), handler TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(action);
	if (zephir_array_isset_string_fetch(&action, forward, SS("action"), 0 TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("action"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("previousAction"), _0 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("action"), action TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(params);
	if (zephir_array_isset_string_fetch(&params, forward, SS("params"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("params"), params TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("finished"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("forwarded"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	if (force) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

static zend_object_value zephir_init_properties_Ice_Dispatcher(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("params"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("modules"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

