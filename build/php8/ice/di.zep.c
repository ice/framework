
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
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Di) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Di, ice, di, ice_arr_ce, ice_di_method_entry, 0);

	zend_declare_property_null(ice_di_ce, SL("di"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	zend_declare_property_null(ice_di_ce, SL("hooks"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_di_ce, SL("defaults"), ZEND_ACC_PROTECTED);

	ice_di_ce->create_object = zephir_init_properties_Ice_Di;
	return SUCCESS;

}

PHP_METHOD(Ice_Di, setDefaults) {

	zval *defaults, defaults_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &defaults);



	zephir_update_property_zval(this_ptr, ZEND_STRL("defaults"), defaults);
	RETURN_THISW();

}

/**
 * Di constructor. Sets root path.
 *
 * @param array data Array of services
 */
PHP_METHOD(Ice_Di, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	ZEPHIR_CALL_PARENT(NULL, ice_di_ce, getThis(), "__construct", &_0, 0, &data);
	zephir_check_call_status();
	zephir_update_static_property_ce(ice_di_ce, ZEND_STRL("di"), this_ptr);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the last DI created.
 *
 * @return Di
 */
PHP_METHOD(Ice_Di, fetch) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, ice_di_ce, SL("di"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

/**
 * Resolves the service based on its configuration.
 *
 * @param string key Service name
 * @param mixed parameters Definition
 */
PHP_METHOD(Ice_Di, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *parameters = NULL, parameters_sub, __$null, predefined, _0, _2$$4, _3$$4;
	zval key;
	zval *this_ptr = getThis();

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
		ZEPHIR_RETURN_CALL_PARENT(ice_di_ce, getThis(), "get", &_1, 0, &key, parameters);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_OBS_VAR(&predefined);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getdefaults", NULL, 0);
		zephir_check_call_status();
		zephir_array_isset_fetch(&predefined, &_2$$4, &key, 0);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, service;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&service);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&service, this_ptr, "resolve", NULL, 0, value, &key);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("data"), &key, &service);
	RETURN_CCTOR(&service);

}

/**
 * Get default services.
 *
 * @return array
 */
PHP_METHOD(Ice_Di, getDefaults) {

	zval _2$$3;
	zval defaults, _0, _3, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&defaults);
	zephir_create_array(&defaults, 17, 0);
	add_assoc_stringl_ex(&defaults, SL("assets"), SL("Ice\\Assets"));
	add_assoc_stringl_ex(&defaults, SL("config"), SL("Ice\\Config"));
	add_assoc_stringl_ex(&defaults, SL("cookies"), SL("Ice\\Cookies"));
	add_assoc_stringl_ex(&defaults, SL("crypt"), SL("Ice\\Crypt"));
	add_assoc_stringl_ex(&defaults, SL("dispatcher"), SL("Ice\\Mvc\\Dispatcher"));
	add_assoc_stringl_ex(&defaults, SL("dump"), SL("Ice\\Dump"));
	add_assoc_stringl_ex(&defaults, SL("filter"), SL("Ice\\Filter"));
	add_assoc_stringl_ex(&defaults, SL("flash"), SL("Ice\\Flash"));
	add_assoc_stringl_ex(&defaults, SL("loader"), SL("Ice\\Loader"));
	add_assoc_stringl_ex(&defaults, SL("request"), SL("Ice\\Http\\Request"));
	add_assoc_stringl_ex(&defaults, SL("response"), SL("Ice\\Http\\Response"));
	add_assoc_stringl_ex(&defaults, SL("router"), SL("Ice\\Mvc\\Router"));
	add_assoc_stringl_ex(&defaults, SL("session"), SL("Ice\\Session"));
	add_assoc_stringl_ex(&defaults, SL("tag"), SL("Ice\\Tag"));
	add_assoc_stringl_ex(&defaults, SL("text"), SL("Ice\\Text"));
	add_assoc_stringl_ex(&defaults, SL("url"), SL("Ice\\Mvc\\Url"));
	add_assoc_stringl_ex(&defaults, SL("view"), SL("Ice\\Mvc\\View"));
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_SAPI");
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "cli")) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 2, 0);
		add_assoc_stringl_ex(&_2$$3, SL("dispatcher"), SL("Ice\\Cli\\Dispatcher"));
		add_assoc_stringl_ex(&_2$$3, SL("router"), SL("Ice\\Cli\\Router"));
		zephir_fast_array_merge(&_1$$3, &defaults, &_2$$3);
		ZEPHIR_CPY_WRT(&defaults, &_1$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("defaults"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(return_value, &defaults, &_3);
	RETURN_MM();

}

/**
 * Resolve service.
 *
 * @param mixed service Definition
 * @return object service
 * @return string key
 */
PHP_METHOD(Ice_Di, resolve) {

	zval _3$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key;
	zval *service = NULL, service_sub, *key_param = NULL, params, _0$$5, _1$$8, name$$10, _2$$11, _4$$12, _5$$12, _6$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$8);
	ZVAL_UNDEF(&name$$10);
	ZVAL_UNDEF(&_2$$11);
	ZVAL_UNDEF(&_4$$12);
	ZVAL_UNDEF(&_5$$12);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_3$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &service, &key_param);

	ZEPHIR_SEPARATE_PARAM(service);
	zephir_get_strval(&key, key_param);


	if (Z_TYPE_P(service) == IS_NULL) {
		RETURN_MM_NULL();
	} else if (Z_TYPE_P(service) == IS_STRING) {
		if (zephir_class_exists(service, 1)) {
			ZEPHIR_CALL_METHOD(&_0$$5, this_ptr, "build", NULL, 0, service);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(service, &_0$$5);
		}
	} else {
		if (Z_TYPE_P(service) == IS_OBJECT) {
			if (zephir_instance_of_ev(service, zend_ce_closure)) {
				ZEPHIR_INIT_VAR(&_1$$8);
				ZEPHIR_CALL_USER_FUNC(&_1$$8, service);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(service, &_1$$8);
			}
		} else {
			if (Z_TYPE_P(service) == IS_ARRAY) {
				ZEPHIR_CALL_FUNCTION(&name$$10, "key", NULL, 100, service);
				zephir_check_call_status();
				if (zephir_is_numeric(&name$$10)) {
					ZEPHIR_OBS_NVAR(&name$$10);
					ZEPHIR_CALL_METHOD(&_2$$11, this_ptr, "getdefaults", NULL, 0);
					zephir_check_call_status();
					zephir_array_isset_fetch(&name$$10, &_2$$11, &key, 0);
				}
				ZEPHIR_CALL_FUNCTION(&params, "current", NULL, 99, service);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_3$$10);
				zephir_create_array(&_3$$10, 1, 0);
				zephir_array_fast_append(&_3$$10, &params);
				ZEPHIR_CALL_METHOD(service, this_ptr, "build", NULL, 0, &name$$10, &_3$$10);
				zephir_check_call_status();
			}
		}
	}
	if (Z_TYPE_P(service) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$12);
		object_init_ex(&_4$$12, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$12);
		ZVAL_STRING(&_5$$12, "Service '%s' cannot be resolved");
		ZEPHIR_CALL_FUNCTION(&_6$$12, "sprintf", NULL, 11, &_5$$12, service);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$12, "__construct", NULL, 12, &_6$$12);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$12, "ice/di.zep", 157);
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

	zval _2$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service, service_sub, *parameters = NULL, parameters_sub, reflector, constructor, dependencies, _0, _4, _1$$5, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&reflector);
	ZVAL_UNDEF(&constructor);
	ZVAL_UNDEF(&dependencies);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$5);
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
		if (zephir_instance_of_ev(service, zend_ce_closure)) {
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, service, parameters);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_VAR(&reflector);
	object_init_ex(&reflector, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflector, "__construct", NULL, 102, service);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &reflector, "isinstantiable", NULL, 103);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$5);
		zephir_create_array(&_2$$5, 2, 0);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "Service '%s' is not instantiable");
		zephir_array_fast_append(&_2$$5, &_3$$5);
		zephir_array_fast_append(&_2$$5, service);
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 12, &_2$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "ice/di.zep", 182);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&constructor, &reflector, "getconstructor", NULL, 104);
	zephir_check_call_status();
	if (Z_TYPE_P(&constructor) == IS_NULL) {
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, service);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&dependencies, &constructor, "getparameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getparameters", NULL, 0, &dependencies, parameters);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(parameters, &_4);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getdependencies", NULL, 0, &dependencies, parameters);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dependencies, &_4);
	ZEPHIR_RETURN_CALL_METHOD(&reflector, "newinstanceargs", NULL, 105, &dependencies);
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

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dependencies_param = NULL, *parameters_param = NULL, key, value, dependency, *_0, _1, _4$$4, _5$$6;
	zval dependencies, parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencies);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&dependency);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &dependencies_param, &parameters_param);

	zephir_get_arrval(&dependencies, dependencies_param);
	zephir_get_arrval(&parameters, parameters_param);


	zephir_is_iterable(&parameters, 1, "ice/di.zep", 218);
	if (Z_TYPE_P(&parameters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parameters), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (zephir_is_numeric(&key)) {
				zephir_array_unset(&parameters, &key, PH_SEPARATE);
				zephir_array_fetch(&dependency, &dependencies, &key, PH_NOISY | PH_READONLY, "ice/di.zep", 213);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_read_property(&_4$$4, &dependency, ZEND_STRL("name"), PH_NOISY_CC);
				zephir_array_update_zval(&parameters, &_4$$4, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parameters, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &parameters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &parameters, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &parameters, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_is_numeric(&key)) {
					zephir_array_unset(&parameters, &key, PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&dependency);
					zephir_array_fetch(&dependency, &dependencies, &key, PH_NOISY, "ice/di.zep", 213);
					ZEPHIR_OBS_NVAR(&_5$$6);
					zephir_read_property(&_5$$6, &dependency, ZEND_STRL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&parameters, &_5$$6, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &parameters, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&parameters);

}

/**
 * Build up a list of dependencies for a given methods parameters.
 *
 * @param array parameters
 * @return array
 */
PHP_METHOD(Ice_Di, getDependencies) {

	zend_bool _3$$3, _19$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_14 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *primitives_param = NULL, dependencies, parameter, dependency, *_0, _1, _2$$3, _4$$3, _5$$3, _6$$3, _7$$3, _9$$3, _10$$4, _11$$4, _12$$5, _13$$6, _15$$7, _16$$7, _18$$8, _20$$8, _21$$8, _22$$8, _23$$8, _24$$8, _25$$9, _26$$9, _27$$10, _28$$11, _29$$12, _30$$12;
	zval parameters, primitives;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&primitives);
	ZVAL_UNDEF(&dependencies);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&dependency);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$12);

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
	zephir_is_iterable(&parameters, 0, "ice/di.zep", 247);
	if (Z_TYPE_P(&parameters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parameters), _0)
		{
			ZEPHIR_INIT_NVAR(&parameter);
			ZVAL_COPY(&parameter, _0);
			ZEPHIR_CALL_METHOD(&_2$$3, &parameter, "gettype", NULL, 0);
			zephir_check_call_status();
			_3$$3 = zephir_is_true(&_2$$3);
			if (_3$$3) {
				ZEPHIR_CALL_METHOD(&_4$$3, &parameter, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$3, &_4$$3, "isbuiltin", NULL, 0);
				zephir_check_call_status();
				_3$$3 = !zephir_is_true(&_5$$3);
			}
			if (_3$$3) {
				ZEPHIR_INIT_NVAR(&dependency);
				object_init_ex(&dependency, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD(&_6$$3, &parameter, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$3, &_6$$3, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &dependency, "__construct", &_8, 102, &_7$$3);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&dependency);
				ZVAL_NULL(&dependency);
			}
			zephir_read_property(&_9$$3, &parameter, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_key_exists(&primitives, &_9$$3)) {
				ZEPHIR_OBS_NVAR(&_11$$4);
				zephir_read_property(&_11$$4, &parameter, ZEND_STRL("name"), PH_NOISY_CC);
				zephir_array_fetch(&_10$$4, &primitives, &_11$$4, PH_NOISY | PH_READONLY, "ice/di.zep", 237);
				zephir_array_append(&dependencies, &_10$$4, PH_SEPARATE, "ice/di.zep", 237);
			} else if (Z_TYPE_P(&dependency) == IS_NULL) {
				ZEPHIR_CALL_METHOD(&_12$$5, &parameter, "isoptional", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_12$$5))) {
					ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "resolvenonclass", &_14, 0, &parameter);
					zephir_check_call_status();
					zephir_array_append(&dependencies, &_13$$6, PH_SEPARATE, "ice/di.zep", 240);
				}
			} else {
				zephir_read_property(&_16$$7, &dependency, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "build", &_17, 0, &_16$$7);
				zephir_check_call_status();
				zephir_array_append(&dependencies, &_15$$7, PH_SEPARATE, "ice/di.zep", 243);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parameters, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &parameters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&parameter, &parameters, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_18$$8, &parameter, "gettype", NULL, 0);
				zephir_check_call_status();
				_19$$8 = zephir_is_true(&_18$$8);
				if (_19$$8) {
					ZEPHIR_CALL_METHOD(&_20$$8, &parameter, "gettype", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_21$$8, &_20$$8, "isbuiltin", NULL, 0);
					zephir_check_call_status();
					_19$$8 = !zephir_is_true(&_21$$8);
				}
				if (_19$$8) {
					ZEPHIR_INIT_NVAR(&dependency);
					object_init_ex(&dependency, zephir_get_internal_ce(SL("reflectionclass")));
					ZEPHIR_CALL_METHOD(&_22$$8, &parameter, "gettype", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_23$$8, &_22$$8, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &dependency, "__construct", &_8, 102, &_23$$8);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&dependency);
					ZVAL_NULL(&dependency);
				}
				zephir_read_property(&_24$$8, &parameter, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_key_exists(&primitives, &_24$$8)) {
					ZEPHIR_OBS_NVAR(&_26$$9);
					zephir_read_property(&_26$$9, &parameter, ZEND_STRL("name"), PH_NOISY_CC);
					zephir_array_fetch(&_25$$9, &primitives, &_26$$9, PH_NOISY | PH_READONLY, "ice/di.zep", 237);
					zephir_array_append(&dependencies, &_25$$9, PH_SEPARATE, "ice/di.zep", 237);
				} else if (Z_TYPE_P(&dependency) == IS_NULL) {
					ZEPHIR_CALL_METHOD(&_27$$10, &parameter, "isoptional", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_27$$10))) {
						ZEPHIR_CALL_METHOD(&_28$$11, this_ptr, "resolvenonclass", &_14, 0, &parameter);
						zephir_check_call_status();
						zephir_array_append(&dependencies, &_28$$11, PH_SEPARATE, "ice/di.zep", 240);
					}
				} else {
					zephir_read_property(&_30$$12, &dependency, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_29$$12, this_ptr, "build", &_17, 0, &_30$$12);
					zephir_check_call_status();
					zephir_array_append(&dependencies, &_29$$12, PH_SEPARATE, "ice/di.zep", 243);
				}
			ZEPHIR_CALL_METHOD(NULL, &parameters, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&parameter);
	RETURN_CCTOR(&dependencies);

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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameter, parameter_sub, _0, _1, _3, _4, _5;
	zval *this_ptr = getThis();

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
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Unresolvable dependency resolving '%s' in class '%s'");
	zephir_array_fast_append(&_2, &_3);
	zephir_array_fast_append(&_2, parameter);
	ZEPHIR_CALL_METHOD(&_4, parameter, "getdeclaringclass", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &_4, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_2, &_5);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 12, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "ice/di.zep", 264);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, _1;
	zval className;
	zval *this_ptr = getThis();

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
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &className);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "handler");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 106, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, &className);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "errorHandler");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 107, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_fast_append(&_3, &className);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "shutdownHandler");
	zephir_array_fast_append(&_3, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 108, &_3);
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

	zval _3$$5;
	zend_bool _0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *callback, callback_sub, *context = NULL, context_sub, *priority_param = NULL, __$null, _2$$3, _1$$4, _4$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &name_param, &callback, &context, &priority_param);

	zephir_get_strval(&name, name_param);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!priority_param) {
		priority = 10;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	if (zephir_is_callable(callback) == 1) {
		_0$$3 = Z_TYPE_P(context) != IS_NULL;
		if (_0$$3) {
			_0$$3 = Z_TYPE_P(context) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_CALL_FUNCTION(&_1$$4, "spl_object_hash", NULL, 109, context);
			zephir_check_call_status();
			zephir_concat_self(&name, &_1$$4);
		}
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("hooks"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset(&_2$$3, &name))) {
			ZEPHIR_INIT_VAR(&_3$$5);
			zephir_create_array(&_3$$5, 1, 0);
			ZEPHIR_INIT_VAR(&_4$$5);
			array_init(&_4$$5);
			zephir_array_fast_append(&_3$$5, &_4$$5);
			zephir_update_property_array(this_ptr, SL("hooks"), &name, &_3$$5);
		}
		zephir_update_property_array_multi(this_ptr, SL("hooks"), callback, SL("zla"), 3, &name, priority);
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

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args, _3$$4;
	zval *name_param = NULL, *args_param = NULL, *context = NULL, context_sub, __$null, priority, callback, _2, _5, _6, _1$$3, _4$$4, _7$$5, _8$$5, *_9$$5, _10$$5, *_11$$7, _12$$7, _13$$8, _14$$9, *_15$$11, _16$$11, _17$$12, _18$$13;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&priority);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &args_param, &context);

	zephir_get_strval(&name, name_param);
	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	_0 = Z_TYPE_P(context) != IS_NULL;
	if (_0) {
		_0 = Z_TYPE_P(context) == IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "spl_object_hash", NULL, 109, context);
		zephir_check_call_status();
		zephir_concat_self(&name, &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("hooks"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_2, &name))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_create_array(&_3$$4, 1, 0);
		ZEPHIR_INIT_VAR(&_4$$4);
		array_init(&_4$$4);
		zephir_array_fast_append(&_3$$4, &_4$$4);
		zephir_update_property_array(this_ptr, SL("hooks"), &name, &_3$$4);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("hooks"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &name, PH_NOISY | PH_READONLY, "ice/di.zep", 331);
	if (!(ZEPHIR_IS_EMPTY(&_6))) {
		zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("hooks"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_8$$5, &_7$$5, &name, PH_NOISY | PH_READONLY, "ice/di.zep", 337);
		zephir_is_iterable(&_8$$5, 0, "ice/di.zep", 344);
		if (Z_TYPE_P(&_8$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_8$$5), _9$$5)
			{
				ZEPHIR_INIT_NVAR(&priority);
				ZVAL_COPY(&priority, _9$$5);
				if (!(ZEPHIR_IS_EMPTY(&priority))) {
					zephir_is_iterable(&priority, 0, "ice/di.zep", 342);
					if (Z_TYPE_P(&priority) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&priority), _11$$7)
						{
							ZEPHIR_INIT_NVAR(&callback);
							ZVAL_COPY(&callback, _11$$7);
							ZEPHIR_INIT_NVAR(&_13$$8);
							ZEPHIR_CALL_USER_FUNC_ARRAY(&_13$$8, &callback, &args);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &priority, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_12$$7, &priority, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_12$$7)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&callback, &priority, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_14$$9);
								ZEPHIR_CALL_USER_FUNC_ARRAY(&_14$$9, &callback, &args);
								zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &priority, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&callback);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_8$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$5, &_8$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&priority, &_8$$5, "current", NULL, 0);
				zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&priority))) {
						zephir_is_iterable(&priority, 0, "ice/di.zep", 342);
						if (Z_TYPE_P(&priority) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&priority), _15$$11)
							{
								ZEPHIR_INIT_NVAR(&callback);
								ZVAL_COPY(&callback, _15$$11);
								ZEPHIR_INIT_NVAR(&_17$$12);
								ZEPHIR_CALL_USER_FUNC_ARRAY(&_17$$12, &callback, &args);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &priority, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_16$$11, &priority, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_16$$11)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&callback, &priority, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_18$$13);
									ZEPHIR_CALL_USER_FUNC_ARRAY(&_18$$13, &callback, &args);
									zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &priority, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&callback);
					}
				ZEPHIR_CALL_METHOD(NULL, &_8$$5, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&priority);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *context = NULL, context_sub, __$null, _2$$3, _3$$3, _4$$3, _1$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &context);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	if (!(Z_TYPE_P(&name) == IS_UNDEF) && Z_STRLEN_P(&name)) {
		_0$$3 = Z_TYPE_P(context) != IS_NULL;
		if (_0$$3) {
			_0$$3 = Z_TYPE_P(context) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_CALL_FUNCTION(&_1$$4, "spl_object_hash", NULL, 109, context);
			zephir_check_call_status();
			zephir_concat_self(&name, &_1$$4);
		}
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("hooks"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_3$$3, &name)) {
			zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("hooks"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_2$$3, &_4$$3, &name, PH_NOISY, "ice/di.zep", 364);
		} else {
			ZVAL_NULL(&_2$$3);
		}
		RETURN_CCTOR(&_2$$3);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *context = NULL, context_sub, __$null, _2$$3, _1$$4, _3$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &context);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	if (!(Z_TYPE_P(&name) == IS_UNDEF) && Z_STRLEN_P(&name)) {
		_0$$3 = Z_TYPE_P(context) != IS_NULL;
		if (_0$$3) {
			_0$$3 = Z_TYPE_P(context) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_CALL_FUNCTION(&_1$$4, "spl_object_hash", NULL, 109, context);
			zephir_check_call_status();
			zephir_concat_self(&name, &_1$$4);
		}
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("hooks"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_2$$3, &name, PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(&_3$$5);
		array_init(&_3$$5);
		zephir_update_property_zval(this_ptr, ZEND_STRL("hooks"), &_3$$5);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *method_param = NULL, *arguments = NULL, arguments_sub, __$null, value, _7, _0$$3, _1$$3, _2$$3, _4$$4, _5$$4, _6$$4;
	zval method, _8;
	zval *this_ptr = getThis();

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

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
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
		zephir_array_isset_long_fetch(&value, arguments, 0, 0);
		ZVAL_LONG(&_0$$3, 3);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_substr(&_1$$3, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "lcfirst", &_3, 17, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_2$$3, &value);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_start_with_str(&method, SL("set"))) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_isset_long_fetch(&value, arguments, 0, 0);
		ZVAL_LONG(&_4$$4, 3);
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_substr(&_5$$4, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&_6$$4, "lcfirst", &_3, 17, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &_6$$4, &value);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, ice_exception_ce);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_SVS(&_8, "Call to undefined method or service '", &method, "'");
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 12, &_8);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_7, "ice/di.zep", 416);
	ZEPHIR_MM_RESTORE();
	return;

}

zend_object *zephir_init_properties_Ice_Di(zend_class_entry *class_type) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("defaults"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("defaults"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("data"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("hooks"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("hooks"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

