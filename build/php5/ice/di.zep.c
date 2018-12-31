
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Component that implements Dependency Injection and a container for the services.
 *
 * @package     Ice/Di
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Di) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Di, ice, di, ice_arr_ce, ice_di_method_entry, 0);

	zend_declare_property_null(ice_di_ce, SL("di"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(ice_di_ce, SL("hooks"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_di_ce, SL("defaults"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_di_ce->create_object = zephir_init_properties_Ice_Di;
	return SUCCESS;

}

PHP_METHOD(Ice_Di, setDefaults) {

	zval *defaults;

	zephir_fetch_params(0, 1, 0, &defaults);



	zephir_update_property_this(getThis(), SL("defaults"), defaults TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Di constructor. Sets root path.
 *
 * @param array data Array of services
 */
PHP_METHOD(Ice_Di, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	ZEPHIR_CALL_PARENT(NULL, ice_di_ce, getThis(), "__construct", &_0, 5, data);
	zephir_check_call_status();
	zephir_update_static_property_ce(ice_di_ce, SL("di"), &this_ptr TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the last DI created.
 *
 * @return Di
 */
PHP_METHOD(Ice_Di, fetch) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(ice_di_ce, SL("di") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Resolves the service based on its configuration.
 *
 * @param string key Service name
 * @param mixed parameters Definition
 */
PHP_METHOD(Ice_Di, get) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *parameters = NULL, *predefined = NULL, *_0 = NULL, *_2$$4 = NULL, *_3$$4 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &parameters);

	zephir_get_strval(key, key_param);
	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_RETURN_CALL_PARENT(ice_di_ce, getThis(), "get", &_1, 107, key, parameters);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_OBS_VAR(predefined);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getdefaults", NULL, 0);
		zephir_check_call_status();
		zephir_array_isset_fetch(&predefined, _2$$4, key, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$4);
		if (zephir_is_true(predefined)) {
			ZEPHIR_CPY_WRT(_3$$4, predefined);
		} else {
			ZEPHIR_CPY_WRT(_3$$4, parameters);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, key, _3$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers a service in the services container.
 *
 * @param string key Service name
 * @param mixed value Definition
 */
PHP_METHOD(Ice_Di, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *service = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&service, this_ptr, "resolve", NULL, 0, value);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("data"), key, service TSRMLS_CC);
	RETURN_CCTOR(service);

}

/**
 * Get default services.
 *
 * @return array
 */
PHP_METHOD(Ice_Di, getDefaults) {

	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 16, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("assets"), SL("Ice\\Assets"), 1);
	add_assoc_stringl_ex(_0, SS("cookies"), SL("Ice\\Cookies"), 1);
	add_assoc_stringl_ex(_0, SS("crypt"), SL("Ice\\Crypt"), 1);
	add_assoc_stringl_ex(_0, SS("dispatcher"), SL("Ice\\Mvc\\Dispatcher"), 1);
	add_assoc_stringl_ex(_0, SS("dump"), SL("Ice\\Dump"), 1);
	add_assoc_stringl_ex(_0, SS("filter"), SL("Ice\\Filter"), 1);
	add_assoc_stringl_ex(_0, SS("flash"), SL("Ice\\Flash"), 1);
	add_assoc_stringl_ex(_0, SS("loader"), SL("Ice\\Loader"), 1);
	add_assoc_stringl_ex(_0, SS("request"), SL("Ice\\Http\\Request"), 1);
	add_assoc_stringl_ex(_0, SS("response"), SL("Ice\\Http\\Response"), 1);
	add_assoc_stringl_ex(_0, SS("router"), SL("Ice\\Mvc\\Router"), 1);
	add_assoc_stringl_ex(_0, SS("session"), SL("Ice\\Session"), 1);
	add_assoc_stringl_ex(_0, SS("tag"), SL("Ice\\Tag"), 1);
	add_assoc_stringl_ex(_0, SS("text"), SL("Ice\\Text"), 1);
	add_assoc_stringl_ex(_0, SS("url"), SL("Ice\\Mvc\\Url"), 1);
	add_assoc_stringl_ex(_0, SS("view"), SL("Ice\\Mvc\\View"), 1);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("defaults"), PH_NOISY_CC);
	zephir_fast_array_merge(return_value, &(_0), &(_1) TSRMLS_CC);
	RETURN_MM();

}

/**
 * Resolve service.
 *
 * @param mixed service Definition
 * @return object Service
 */
PHP_METHOD(Ice_Di, resolve) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service = NULL, *params = NULL, *_0$$5 = NULL, *_1$$8, *_2$$10 = NULL, *_3$$10 = NULL, *_4$$11, _5$$11, *_6$$11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service);

	ZEPHIR_SEPARATE_PARAM(service);


	if (Z_TYPE_P(service) == IS_NULL) {
		RETURN_MM_NULL();
	} else if (Z_TYPE_P(service) == IS_STRING) {
		if (zephir_class_exists(service, 1 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_0$$5, this_ptr, "build", NULL, 0, service);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(service, _0$$5);
		}
	} else {
		if (Z_TYPE_P(service) == IS_OBJECT) {
			if (zephir_instance_of_ev(service, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_1$$8);
				ZEPHIR_CALL_USER_FUNC(_1$$8, service);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(service, _1$$8);
			}
		} else {
			if (Z_TYPE_P(service) == IS_ARRAY) {
				ZEPHIR_MAKE_REF(service);
				ZEPHIR_CALL_FUNCTION(&params, "current", NULL, 104, service);
				ZEPHIR_UNREF(service);
				zephir_check_call_status();
				ZEPHIR_MAKE_REF(service);
				ZEPHIR_CALL_FUNCTION(&_2$$10, "key", NULL, 106, service);
				ZEPHIR_UNREF(service);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_3$$10);
				if (Z_TYPE_P(params) == IS_ARRAY) {
					ZEPHIR_CPY_WRT(_3$$10, params);
				} else {
					ZEPHIR_INIT_NVAR(_3$$10);
					zephir_create_array(_3$$10, 1, 0 TSRMLS_CC);
					zephir_array_fast_append(_3$$10, params);
				}
				ZEPHIR_CALL_METHOD(&service, this_ptr, "build", NULL, 0, _2$$10, _3$$10);
				zephir_check_call_status();
			}
		}
	}
	if (Z_TYPE_P(service) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_4$$11);
		object_init_ex(_4$$11, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_5$$11);
		ZVAL_STRING(&_5$$11, "Service '%s' cannot be resolved", 0);
		ZEPHIR_CALL_FUNCTION(&_6$$11, "sprintf", NULL, 12, &_5$$11, service);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _4$$11, "__construct", NULL, 13, _6$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$11, "ice/di.zep", 138 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(service, 1, 0);
	RETURN_MM();

}

/**
 * Build an instance of the given class.
 * 
 * @param string service
 * @return mixed
 */
PHP_METHOD(Ice_Di, build) {

	zval *_2$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service, *parameters = NULL, *reflector = NULL, *constructor = NULL, *dependencies = NULL, *_0 = NULL, *_4 = NULL, *_1$$5, *_3$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &service, &parameters);

	if (!parameters) {
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	} else {
		ZEPHIR_SEPARATE_PARAM(parameters);
	}


	if (Z_TYPE_P(service) == IS_OBJECT) {
		if (zephir_instance_of_ev(service, zend_ce_closure TSRMLS_CC)) {
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, service, parameters);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_VAR(reflector);
	object_init_ex(reflector, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, reflector, "__construct", NULL, 108, service);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, reflector, "isinstantiable", NULL, 109);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$5);
		object_init_ex(_1$$5, ice_exception_ce);
		ZEPHIR_INIT_VAR(_2$$5);
		zephir_create_array(_2$$5, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$5);
		ZVAL_STRING(_3$$5, "Service '%s' is not instantiable", 1);
		zephir_array_fast_append(_2$$5, _3$$5);
		zephir_array_fast_append(_2$$5, service);
		ZEPHIR_CALL_METHOD(NULL, _1$$5, "__construct", NULL, 13, _2$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$5, "ice/di.zep", 163 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&constructor, reflector, "getconstructor", NULL, 110);
	zephir_check_call_status();
	if (Z_TYPE_P(constructor) == IS_NULL) {
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, service TSRMLS_CC);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&dependencies, constructor, "getparameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getparameters", NULL, 0, dependencies, parameters);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(parameters, _4);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getdependencies", NULL, 0, dependencies, parameters);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dependencies, _4);
	ZEPHIR_RETURN_CALL_METHOD(reflector, "newinstanceargs", NULL, 111, dependencies);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * If extra parameters are passed by numeric ID, rekey them by argument name.
 *
 * @param array dependencies
 * @param array parameters
 * @return array
 */
PHP_METHOD(Ice_Di, getParameters) {

	HashTable *_1;
	HashPosition _0;
	zval *dependencies_param = NULL, *parameters_param = NULL, *key = NULL, *value = NULL, *dependency = NULL, **_2, *_3$$4 = NULL;
	zval *dependencies = NULL, *parameters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &dependencies_param, &parameters_param);

	zephir_get_arrval(dependencies, dependencies_param);
	zephir_get_arrval(parameters, parameters_param);


	zephir_is_iterable(parameters, &_1, &_0, 1, 0, "ice/di.zep", 199);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (zephir_is_numeric(key)) {
			zephir_array_unset(&parameters, key, PH_SEPARATE);
			zephir_array_fetch(&dependency, dependencies, key, PH_NOISY | PH_READONLY, "ice/di.zep", 194 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_3$$4);
			zephir_read_property(&_3$$4, dependency, SL("name"), PH_NOISY_CC);
			zephir_array_update_zval(&parameters, _3$$4, &value, PH_COPY | PH_SEPARATE);
		}
	}
	zend_hash_destroy(_1);
	FREE_HASHTABLE(_1);
	RETURN_CTOR(parameters);

}

/**
 * Build up a list of dependencies for a given methods parameters.
 *
 * @param array parameters
 * @return array
 */
PHP_METHOD(Ice_Di, getDependencies) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *primitives_param = NULL, *dependencies = NULL, *parameter = NULL, *dependency = NULL, **_2, *_3$$3 = NULL, *_4$$4, *_5$$4 = NULL, *_6$$5 = NULL, *_7$$6 = NULL, *_9$$7 = NULL, *_10$$7 = NULL;
	zval *parameters = NULL, *primitives = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters_param, &primitives_param);

	zephir_get_arrval(parameters, parameters_param);
	if (!primitives_param) {
		ZEPHIR_INIT_VAR(primitives);
		array_init(primitives);
	} else {
		zephir_get_arrval(primitives, primitives_param);
	}


	ZEPHIR_INIT_VAR(dependencies);
	array_init(dependencies);
	zephir_is_iterable(parameters, &_1, &_0, 0, 0, "ice/di.zep", 228);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(parameter, _2);
		ZEPHIR_CALL_METHOD(&dependency, parameter, "getclass", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(_3$$3);
		zephir_read_property(&_3$$3, parameter, SL("name"), PH_NOISY_CC);
		if (zephir_array_key_exists(primitives, _3$$3 TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(_5$$4);
			zephir_read_property(&_5$$4, parameter, SL("name"), PH_NOISY_CC);
			zephir_array_fetch(&_4$$4, primitives, _5$$4, PH_NOISY | PH_READONLY, "ice/di.zep", 218 TSRMLS_CC);
			zephir_array_append(&dependencies, _4$$4, PH_SEPARATE, "ice/di.zep", 218);
		} else if (Z_TYPE_P(dependency) == IS_NULL) {
			ZEPHIR_CALL_METHOD(&_6$$5, parameter, "isoptional", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_6$$5))) {
				ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "resolvenonclass", &_8, 0, parameter);
				zephir_check_call_status();
				zephir_array_append(&dependencies, _7$$6, PH_SEPARATE, "ice/di.zep", 221);
			}
		} else {
			ZEPHIR_OBS_NVAR(_10$$7);
			zephir_read_property(&_10$$7, dependency, SL("name"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_9$$7, this_ptr, "build", &_11, 0, _10$$7);
			zephir_check_call_status();
			zephir_array_append(&dependencies, _9$$7, PH_SEPARATE, "ice/di.zep", 224);
		}
	}
	RETURN_CCTOR(dependencies);

}

/**
 * Determine what to do with a non-class value.
 *
 * @param ReflectionParameter parameter
 * @return mixed
 *
 * @throws Exception
 */
PHP_METHOD(Ice_Di, resolveNonClass) {

	zval *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameter, *_0 = NULL, *_1, *_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameter);



	ZEPHIR_CALL_METHOD(&_0, parameter, "isdefaultvalueavailable", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_RETURN_CALL_METHOD(parameter, "getdefaultvalue", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, ice_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Unresolvable dependency resolving '%s' in class '%s'", 1);
	zephir_array_fast_append(_2, _3);
	zephir_array_fast_append(_2, parameter);
	ZEPHIR_CALL_METHOD(&_4, parameter, "getdeclaringclass", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, _4, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(_2, _5);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 13, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "ice/di.zep", 245 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Set handlers for error, exeception and shutdown.
 * Class should contain method handler, errorHandler and shutdownHandler.
 *
 * @param string className
 * @return object Di
 */
PHP_METHOD(Ice_Di, errors) {

	zval *_0, *_2, *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *_1 = NULL;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &className_param);

	if (!className_param) {
		ZEPHIR_INIT_VAR(className);
		ZVAL_STRING(className, "Ice\\Exception", 1);
	} else {
		zephir_get_strval(className, className_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, className);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "handler", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 112, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, className);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "errorHandler", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 113, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_3, className);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "shutdownHandler", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 114, _3);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Assign hook.
 *
 * @param string name The hook name
 * @param mixed callable A callable object
 * @param mixed context The callback bind to the object
 * @param int priority The hook priority; 0 = high, 10 = low
 * @return object Di
 */
PHP_METHOD(Ice_Di, hook) {

	zval *_3$$5;
	zend_bool _0$$3;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *callback, *context = NULL, *priority_param = NULL, *_2$$3, *_1$$4 = NULL, *_4$$5;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &name_param, &callback, &context, &priority_param);

	zephir_get_strval(name, name_param);
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}
	if (!priority_param) {
		priority = 10;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	if (zephir_is_callable(callback TSRMLS_CC) == 1) {
		_0$$3 = Z_TYPE_P(context) != IS_NULL;
		if (_0$$3) {
			_0$$3 = Z_TYPE_P(context) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_CALL_FUNCTION(&_1$$4, "spl_object_hash", NULL, 115, context);
			zephir_check_call_status();
			zephir_concat_self(&name, _1$$4 TSRMLS_CC);
		}
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		if (!(zephir_array_isset(_2$$3, name))) {
			ZEPHIR_INIT_VAR(_3$$5);
			zephir_create_array(_3$$5, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4$$5);
			array_init(_4$$5);
			zephir_array_fast_append(_3$$5, _4$$5);
			zephir_update_property_array(this_ptr, SL("hooks"), name, _3$$5 TSRMLS_CC);
		}
		zephir_update_property_array_multi(this_ptr, SL("hooks"), &callback TSRMLS_CC, SL("zla"), 3, name, priority);
	}
	RETURN_THIS();

}

/**
 * Invoke hook.
 *
 * @param string name The hook name
 * @param mixed hookArg Argument for hooked functions
 * @param mixed context The callback bind to the object
 * @return object Di
 */
PHP_METHOD(Ice_Di, applyHook) {

	HashTable *_10$$5, *_13$$7;
	HashPosition _9$$5, _12$$7;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL, *_3$$4;
	zval *name_param = NULL, *args_param = NULL, *context = NULL, *priority = NULL, *callback = NULL, *_2, *_5, *_6, *_1$$3 = NULL, *_4$$4, *_7$$5, *_8$$5, **_11$$5, **_14$$7, *_15$$8 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &args_param, &context);

	zephir_get_strval(name, name_param);
	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
		zephir_get_arrval(args, args_param);
	}
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(context) != IS_NULL;
	if (_0) {
		_0 = Z_TYPE_P(context) == IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "spl_object_hash", NULL, 115, context);
		zephir_check_call_status();
		zephir_concat_self(&name, _1$$3 TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
	if (!(zephir_array_isset(_2, name))) {
		ZEPHIR_INIT_VAR(_3$$4);
		zephir_create_array(_3$$4, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4$$4);
		array_init(_4$$4);
		zephir_array_fast_append(_3$$4, _4$$4);
		zephir_update_property_array(this_ptr, SL("hooks"), name, _3$$4 TSRMLS_CC);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
	zephir_array_fetch(&_6, _5, name, PH_NOISY | PH_READONLY, "ice/di.zep", 312 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(_6))) {
		_7$$5 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		zephir_array_fetch(&_8$$5, _7$$5, name, PH_NOISY | PH_READONLY, "ice/di.zep", 318 TSRMLS_CC);
		zephir_is_iterable(_8$$5, &_10$$5, &_9$$5, 0, 0, "ice/di.zep", 325);
		for (
		  ; zend_hash_get_current_data_ex(_10$$5, (void**) &_11$$5, &_9$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_10$$5, &_9$$5)
		) {
			ZEPHIR_GET_HVALUE(priority, _11$$5);
			if (!(ZEPHIR_IS_EMPTY(priority))) {
				zephir_is_iterable(priority, &_13$$7, &_12$$7, 0, 0, "ice/di.zep", 323);
				for (
				  ; zend_hash_get_current_data_ex(_13$$7, (void**) &_14$$7, &_12$$7) == SUCCESS
				  ; zend_hash_move_forward_ex(_13$$7, &_12$$7)
				) {
					ZEPHIR_GET_HVALUE(callback, _14$$7);
					ZEPHIR_INIT_NVAR(_15$$8);
					ZEPHIR_CALL_USER_FUNC_ARRAY(_15$$8, callback, args);
					zephir_check_call_status();
				}
			}
		}
	}
	RETURN_THIS();

}

/**
 * Get hook listeners.
 * Return an array of registered hooks. If `$name` is a valid hook name, only the listeners attached to that hook
 * are returned. Else, all listeners are returned as an associative array whose keys are hook names and whose values
 * are arrays of listeners.
 *
 * @param string name A hook name (Optional)
 * @param mixed context The callback bind to the object
 * @return array|null
 */
PHP_METHOD(Ice_Di, getHooks) {

	zend_bool _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *context = NULL, *_2$$3, *_3$$3, *_4$$3, *_1$$4 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &context);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}


	if (!(!name) && Z_STRLEN_P(name)) {
		_0$$3 = Z_TYPE_P(context) != IS_NULL;
		if (_0$$3) {
			_0$$3 = Z_TYPE_P(context) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_CALL_FUNCTION(&_1$$4, "spl_object_hash", NULL, 115, context);
			zephir_check_call_status();
			zephir_concat_self(&name, _1$$4 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(_2$$3);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		if (zephir_array_isset(_3$$3, name)) {
			_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
			zephir_array_fetch(&_2$$3, _4$$3, name, PH_NOISY, "ice/di.zep", 345 TSRMLS_CC);
		} else {
			ZVAL_NULL(_2$$3);
		}
		RETURN_CCTOR(_2$$3);
	} else {
		RETURN_MM_MEMBER(getThis(), "hooks");
	}

}

/**
 * Clear hook listeners.
 * Clear all listeners for all hooks. If `$name` is a valid hook name, only the listeners attached to that hook
 * will be cleared.
 *
 * @param  string $name A hook name (Optional)
 * @param mixed context The callback bind to the object
 * @return object Di
 */
PHP_METHOD(Ice_Di, clearHooks) {

	zend_bool _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *context = NULL, *_2$$3, *_1$$4 = NULL, *_3$$5;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &context);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}


	if (!(!name) && Z_STRLEN_P(name)) {
		_0$$3 = Z_TYPE_P(context) != IS_NULL;
		if (_0$$3) {
			_0$$3 = Z_TYPE_P(context) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_CALL_FUNCTION(&_1$$4, "spl_object_hash", NULL, 115, context);
			zephir_check_call_status();
			zephir_concat_self(&name, _1$$4 TSRMLS_CC);
		}
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		zephir_array_unset(&_2$$3, name, PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(_3$$5);
		array_init(_3$$5);
		zephir_update_property_this(getThis(), SL("hooks"), _3$$5 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Magic method to get or set services using setters/getters.
 *
 * @param string method
 * @param mixed arguments
 * @return mixed
 */
PHP_METHOD(Ice_Di, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *method_param = NULL, *arguments = NULL, *value = NULL, *_7, _0$$3, *_1$$3, *_2$$3 = NULL, _4$$4, *_5$$4, *_6$$4 = NULL;
	zval *method = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_start_with_str(method, SL("get"))) {
		ZEPHIR_OBS_VAR(value);
		zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_LONG(&_0$$3, 3);
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_substr(_1$$3, method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "lcfirst", &_3, 18, _1$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, _2$$3, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_start_with_str(method, SL("set"))) {
		ZEPHIR_OBS_NVAR(value);
		zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_4$$4);
		ZVAL_LONG(&_4$$4, 3);
		ZEPHIR_INIT_VAR(_5$$4);
		zephir_substr(_5$$4, method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&_6$$4, "lcfirst", &_3, 18, _5$$4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, _6$$4, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_7);
	object_init_ex(_7, ice_exception_ce);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SVS(_8, "Call to undefined method or service '", method, "'");
	ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 13, _8);
	zephir_check_call_status();
	zephir_throw_exception_debug(_7, "ice/di.zep", 397 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

zend_object_value zephir_init_properties_Ice_Di(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_1$$3, *_3$$4, *_5$$5;

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

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("defaults"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("defaults"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("data"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(getThis(), SL("hooks"), _5$$5 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

