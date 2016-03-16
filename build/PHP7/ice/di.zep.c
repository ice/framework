
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
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Component that implements Dependency Injection and a container for the services.
 *
 * @package     Ice/Di
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
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

	zval *defaults, defaults_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&defaults_sub);

	zephir_fetch_params(0, 1, 0, &defaults);



	zephir_update_property_zval(this_ptr, SL("defaults"), defaults);

}

/**
 * Di constructor. Sets root path.
 *
 * @param array data Array of services
 */
PHP_METHOD(Ice_Di, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL;
	zval data;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	ZEPHIR_CALL_PARENT(NULL, ice_di_ce, this_ptr, "__construct", &_0, 4, &data);
	zephir_check_call_status();
	zephir_update_static_property_ce(ice_di_ce, SL("di"), this_ptr);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the last DI created.
 *
 * @return Di
 */
PHP_METHOD(Ice_Di, fetch) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, ice_di_ce, SL("di"), PH_NOISY_CC | PH_READONLY);
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *parameters = NULL, parameters_sub, __$null, predefined, _0, _2$$4, _3$$4;
	zval key;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&predefined);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &parameters);

	zephir_get_strval(&key, key_param);
	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &key);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_PARENT(ice_di_ce, this_ptr, "get", &_1, 27, &key, parameters);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_OBS_VAR(&predefined);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getdefaults", NULL, 0);
		zephir_check_call_status();
		zephir_array_isset_fetch(&predefined, &_2$$4, &key, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$4);
		if (zephir_is_true(&predefined)) {
			ZEPHIR_CPY_WRT(&_3$$4, &predefined);
		} else {
			ZEPHIR_CPY_WRT(&_3$$4, parameters);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &key, &_3$$4);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, service;
	zval key;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&service);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&service, this_ptr, "resolve", NULL, 0, value);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("data"), &key, &service TSRMLS_CC);
	RETURN_CCTOR(service);

}

/**
 * Get default services.
 *
 * @return array
 */
PHP_METHOD(Ice_Di, getDefaults) {

	zval _1;
	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 16, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_0, SL("assets"), SL("Ice\\Assets"));
	add_assoc_stringl_ex(&_0, SL("cookies"), SL("Ice\\Cookies"));
	add_assoc_stringl_ex(&_0, SL("crypt"), SL("Ice\\Crypt"));
	add_assoc_stringl_ex(&_0, SL("dispatcher"), SL("Ice\\Mvc\\Dispatcher"));
	add_assoc_stringl_ex(&_0, SL("dump"), SL("Ice\\Dump"));
	add_assoc_stringl_ex(&_0, SL("filter"), SL("Ice\\Filter"));
	add_assoc_stringl_ex(&_0, SL("flash"), SL("Ice\\Flash"));
	add_assoc_stringl_ex(&_0, SL("loader"), SL("Ice\\Loader"));
	add_assoc_stringl_ex(&_0, SL("request"), SL("Ice\\Http\\Request"));
	add_assoc_stringl_ex(&_0, SL("response"), SL("Ice\\Http\\Response"));
	add_assoc_stringl_ex(&_0, SL("router"), SL("Ice\\Mvc\\Router"));
	add_assoc_stringl_ex(&_0, SL("session"), SL("Ice\\Session"));
	add_assoc_stringl_ex(&_0, SL("tag"), SL("Ice\\Tag"));
	add_assoc_stringl_ex(&_0, SL("text"), SL("Ice\\Text"));
	add_assoc_stringl_ex(&_0, SL("url"), SL("Ice\\Url"));
	add_assoc_stringl_ex(&_0, SL("view"), SL("Ice\\Mvc\\View"));
	zephir_read_property(&_1, this_ptr, SL("defaults"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(return_value, &_0, &_1 TSRMLS_CC);
	RETURN_MM();

}

/**
 * Resolve service.
 *
 * @param mixed service Definition
 * @return object Service
 */
PHP_METHOD(Ice_Di, resolve) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *service = NULL, service_sub, params, _0$$5, _1$$8, _2$$10, _3$$10, _4$$11, _5$$11, _6$$11;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&service_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$8);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service);

	ZEPHIR_SEPARATE_PARAM(service);


	if (Z_TYPE_P(service) == IS_NULL) {
		RETURN_MM_NULL();
	} else if (Z_TYPE_P(service) == IS_STRING) {
		if (zephir_class_exists(service, 1 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_0$$5, this_ptr, "build", NULL, 0, service);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(service, &_0$$5);
		}
	} else {
		if (Z_TYPE_P(service) == IS_OBJECT) {
			if (zephir_instance_of_ev(service, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(&_1$$8);
				ZEPHIR_CALL_USER_FUNC(&_1$$8, service);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(service, &_1$$8);
			}
		} else {
			if (Z_TYPE_P(service) == IS_ARRAY) {
				ZEPHIR_CALL_FUNCTION(&params, "current", NULL, 75, service);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_2$$10, "key", NULL, 74, service);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_3$$10);
				if (ZEPHIR_IS_STRING(&params, "array")) {
					ZEPHIR_CPY_WRT(&_3$$10, &params);
				} else {
					ZEPHIR_INIT_NVAR(&_3$$10);
					zephir_create_array(&_3$$10, 1, 0 TSRMLS_CC);
					zephir_array_fast_append(&_3$$10, &params);
				}
				ZEPHIR_CALL_METHOD(service, this_ptr, "build", NULL, 0, &_2$$10, &_3$$10);
				zephir_check_call_status();
			}
		}
	}
	if (Z_TYPE_P(service) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$11);
		object_init_ex(&_4$$11, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$11);
		ZVAL_STRING(&_5$$11, "Service '%s' cannot be resolved");
		ZEPHIR_CALL_FUNCTION(&_6$$11, "sprintf", NULL, 12, &_5$$11, service);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$11, "__construct", NULL, 13, &_6$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$11, "ice/di.zep", 138 TSRMLS_CC);
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

	zend_class_entry *_5$$6;
	zval _2$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *service, service_sub, *parameters = NULL, parameters_sub, reflector, constructor, dependencies, _0, _6, _1$$5, _3$$5, _4$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&service_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&reflector);
	ZVAL_UNDEF(&constructor);
	ZVAL_UNDEF(&dependencies);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &service, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
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
	ZEPHIR_INIT_VAR(&reflector);
	object_init_ex(&reflector, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflector, "__construct", NULL, 77, service);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &reflector, "isinstantiable", NULL, 78);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$5);
		zephir_create_array(&_2$$5, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "Service '%s' is not instantiable");
		zephir_array_fast_append(&_2$$5, &_3$$5);
		zephir_array_fast_append(&_2$$5, service);
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 13, &_2$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "ice/di.zep", 163 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&constructor, &reflector, "getconstructor", NULL, 79);
	zephir_check_call_status();
	if (Z_TYPE_P(&constructor) == IS_NULL) {
		zephir_fetch_safe_class(&_4$$6, service);
		_5$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_4$$6), Z_STRLEN_P(&_4$$6), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(return_value, _5$$6);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&dependencies, &constructor, "getparameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getparameters", NULL, 0, &dependencies, parameters);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(parameters, &_6);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getdependencies", NULL, 0, &dependencies, parameters);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dependencies, &_6);
	ZEPHIR_RETURN_CALL_METHOD(&reflector, "newinstanceargs", NULL, 80, &dependencies);
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

	zend_string *_2;
	zend_ulong _1;
	zval *dependencies_param = NULL, *parameters_param = NULL, key, value, dependency, *_0, _3$$4;
	zval dependencies, parameters;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dependencies);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&dependency);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &dependencies_param, &parameters_param);

	zephir_get_arrval(&dependencies, dependencies_param);
	zephir_get_arrval(&parameters, parameters_param);


	zephir_is_iterable(&parameters, 1, "ice/di.zep", 199);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parameters), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (zephir_is_numeric(&key)) {
			zephir_array_unset(&parameters, &key, PH_SEPARATE);
			zephir_array_fetch(&dependency, &dependencies, &key, PH_NOISY | PH_READONLY, "ice/di.zep", 194 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_3$$4);
			zephir_read_property(&_3$$4, &dependency, SL("name"), PH_NOISY_CC);
			zephir_array_update_zval(&parameters, &_3$$4, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(parameters);

}

/**
 * Build up a list of dependencies for a given methods parameters.
 *
 * @param array parameters
 * @return array
 */
PHP_METHOD(Ice_Di, getDependencies) {

	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *primitives_param = NULL, dependencies, parameter, dependency, *_0, _1$$3, _2$$4, _3$$4, _4$$5, _5$$6, _7$$7, _8$$7;
	zval parameters, primitives;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&primitives);
	ZVAL_UNDEF(&dependencies);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&dependency);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parameters_param, &primitives_param);

	zephir_get_arrval(&parameters, parameters_param);
	if (!primitives_param) {
		ZEPHIR_INIT_VAR(&primitives);
		array_init(&primitives);
	} else {
		zephir_get_arrval(&primitives, primitives_param);
	}


	ZEPHIR_INIT_VAR(&dependencies);
	array_init(&dependencies);
	zephir_is_iterable(&parameters, 0, "ice/di.zep", 228);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parameters), _0)
	{
		ZEPHIR_INIT_NVAR(&parameter);
		ZVAL_COPY(&parameter, _0);
		ZEPHIR_CALL_METHOD(&dependency, &parameter, "getclass", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, &parameter, SL("name"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_key_exists(&primitives, &_1$$3 TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(&_3$$4);
			zephir_read_property(&_3$$4, &parameter, SL("name"), PH_NOISY_CC);
			zephir_array_fetch(&_2$$4, &primitives, &_3$$4, PH_NOISY | PH_READONLY, "ice/di.zep", 218 TSRMLS_CC);
			zephir_array_append(&dependencies, &_2$$4, PH_SEPARATE, "ice/di.zep", 218);
		} else if (Z_TYPE_P(&dependency) == IS_NULL) {
			ZEPHIR_CALL_METHOD(&_4$$5, &parameter, "isoptional", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_4$$5))) {
				ZEPHIR_CALL_METHOD(&_5$$6, this_ptr, "resolvenonclass", &_6, 0, &parameter);
				zephir_check_call_status();
				zephir_array_append(&dependencies, &_5$$6, PH_SEPARATE, "ice/di.zep", 221);
			}
		} else {
			zephir_read_property(&_8$$7, &dependency, SL("name"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "build", &_9, 0, &_8$$7);
			zephir_check_call_status();
			zephir_array_append(&dependencies, &_7$$7, PH_SEPARATE, "ice/di.zep", 224);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&parameter);
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

	zval _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameter, parameter_sub, _0, _1, _3, _4, _5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parameter_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameter);



	ZEPHIR_CALL_METHOD(&_0, parameter, "isdefaultvalueavailable", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(parameter, "getdefaultvalue", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, ice_exception_ce);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Unresolvable dependency resolving '%s' in class '%s'");
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&_2, parameter);
	ZEPHIR_CALL_METHOD(&_4, parameter, "getdeclaringclass", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &_4, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_2, &_5);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 13, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "ice/di.zep", 245 TSRMLS_CC);
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

	zval _0, _2, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, _1;
	zval className;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &className_param);

	if (!className_param) {
		ZEPHIR_INIT_VAR(&className);
		ZVAL_STRING(&className, "Ice\\Exception");
	} else {
		zephir_get_strval(&className, className_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, &className);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "handler");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 81, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, &className);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "errorHandler");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 82, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, &className);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "shutdownHandler");
	zephir_array_fast_append(&_3, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 83, &_3);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Assign hook.
 *
 * @param string name The hook name
 * @param mixed callable A callable object
 * @param int priority The hook priority; 0 = high, 10 = low
 */
PHP_METHOD(Ice_Di, hook) {

	zval _1$$3;
	int priority;
	zval *name_param = NULL, *callback, callback_sub, *priority_param = NULL, _0, _2$$3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &callback, &priority_param);

	zephir_get_strval(&name, name_param);
	if (!priority_param) {
		priority = 10;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	zephir_read_property(&_0, this_ptr, SL("hooks"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		array_init(&_2$$3);
		zephir_array_fast_append(&_1$$3, &_2$$3);
		zephir_update_property_array(this_ptr, SL("hooks"), &name, &_1$$3 TSRMLS_CC);
	}
	if (zephir_is_callable(callback TSRMLS_CC) == 1) {
		zephir_update_property_array_multi(this_ptr, SL("hooks"), callback TSRMLS_CC, SL("zla"), 3, &name, priority);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Invoke hook.
 *
 * @param string name The hook name
 * @param mixed hookArg Argument for hooked functions
 */
PHP_METHOD(Ice_Di, applyHook) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval args, _1$$3;
	zval *name_param = NULL, *args_param = NULL, priority, callback, _0, _3, _4, _2$$3, _5$$4, _6$$4, *_7$$4, *_8$$6, _9$$7;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&priority);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &args_param);

	zephir_get_strval(&name, name_param);
	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	zephir_read_property(&_0, this_ptr, SL("hooks"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		array_init(&_2$$3);
		zephir_array_fast_append(&_1$$3, &_2$$3);
		zephir_update_property_array(this_ptr, SL("hooks"), &name, &_1$$3 TSRMLS_CC);
	}
	zephir_read_property(&_3, this_ptr, SL("hooks"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "ice/di.zep", 301 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(&_4))) {
		zephir_read_property(&_5$$4, this_ptr, SL("hooks"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_6$$4, &_5$$4, &name, PH_NOISY | PH_READONLY, "ice/di.zep", 307 TSRMLS_CC);
		zephir_is_iterable(&_6$$4, 0, "ice/di.zep", 314);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_6$$4), _7$$4)
		{
			ZEPHIR_INIT_NVAR(&priority);
			ZVAL_COPY(&priority, _7$$4);
			if (!(ZEPHIR_IS_EMPTY(&priority))) {
				zephir_is_iterable(&priority, 0, "ice/di.zep", 312);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&priority), _8$$6)
				{
					ZEPHIR_INIT_NVAR(&callback);
					ZVAL_COPY(&callback, _8$$6);
					ZEPHIR_INIT_NVAR(&_9$$7);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&_9$$7, &callback, &args);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&callback);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&priority);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get hook listeners.
 * Return an array of registered hooks. If `$name` is a valid hook name, only the listeners attached to that hook
 * are returned. Else, all listeners are returned as an associative array whose keys are hook names and whose values
 * are arrays of listeners.
 *
 * @param string name A hook name (Optional)
 * @return array|null
 */
PHP_METHOD(Ice_Di, getHooks) {

	zval *name_param = NULL, _0$$3, _1$$3, _2$$3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	if (!(Z_TYPE_P(&name) == IS_UNDEF) && Z_STRLEN_P(&name)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("hooks"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_1$$3, &name)) {
			zephir_read_property(&_2$$3, this_ptr, SL("hooks"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_0$$3, &_2$$3, &name, PH_NOISY, "ice/di.zep", 329 TSRMLS_CC);
		} else {
			ZVAL_NULL(&_0$$3);
		}
		RETURN_CCTOR(_0$$3);
	} else {
		RETURN_MM_MEMBER(this_ptr, "hooks");
	}

}

/**
 * Clear hook listeners.
 * Clear all listeners for all hooks. If `$name` is a valid hook name, only the listeners attached to that hook
 * will be cleared.
 *
 * @param  string $name A hook name (Optional)
 */
PHP_METHOD(Ice_Di, clearHooks) {

	zval _2$$3, _7$$5;
	zend_bool _0;
	zval *name_param = NULL, key, _1, _3$$3, _4$$4, _5$$4, *_6$$4, _8$$5;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	_0 = zephir_is_true(&name);
	if (_0) {
		zephir_read_property(&_1, this_ptr, SL("hooks"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_array_isset(&_1, &name);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$3);
		array_init(&_3$$3);
		zephir_array_fast_append(&_2$$3, &_3$$3);
		zephir_update_property_array(this_ptr, SL("hooks"), &name, &_2$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_read_property(&_5$$4, this_ptr, SL("hooks"), PH_NOISY_CC | PH_READONLY);
		zephir_array_keys(&_4$$4, &_5$$4 TSRMLS_CC);
		zephir_is_iterable(&_4$$4, 0, "ice/di.zep", 352);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4$$4), _6$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _6$$4);
			ZEPHIR_INIT_NVAR(&_7$$5);
			zephir_create_array(&_7$$5, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_8$$5);
			array_init(&_8$$5);
			zephir_array_fast_append(&_7$$5, &_8$$5);
			zephir_update_property_array(this_ptr, SL("hooks"), &key, &_7$$5 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&key);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic method to get or set services using setters/getters.
 *
 * @param string method
 * @param mixed arguments
 * @return mixed
 */
PHP_METHOD(Ice_Di, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *method_param = NULL, *arguments = NULL, arguments_sub, __$null, value, _7, _0$$3, _1$$3, _2$$3, _4$$4, _5$$4, _6$$4;
	zval method, _8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	if (zephir_start_with_str(&method, SL("get"))) {
		ZEPHIR_OBS_VAR(&value);
		zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
		ZVAL_LONG(&_0$$3, 3);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_substr(&_1$$3, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "lcfirst", &_3, 18, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_2$$3, &value);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_start_with_str(&method, SL("set"))) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
		ZVAL_LONG(&_4$$4, 3);
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_substr(&_5$$4, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&_6$$4, "lcfirst", &_3, 18, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &_6$$4, &value);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, ice_exception_ce);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_SVS(&_8, "Call to undefined method or service '", &method, "'");
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 13, &_8);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_7, "ice/di.zep", 379 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

static zend_object *zephir_init_properties_Ice_Di(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("defaults"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("defaults"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("data"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("hooks"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("hooks"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

