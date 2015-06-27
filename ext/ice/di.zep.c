
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "Zend/zend_closures.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"

ZEPHIR_INIT_CLASS(Ice_Di) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Di, ice, di, ice_arr_ce, ice_di_method_entry, 0);

	zend_declare_property_null(ice_di_ce, SL("di"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(ice_di_ce, SL("hooks"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_di_ce->create_object = zephir_init_properties;
	return SUCCESS;

}

/**
 * Di constructor. Sets root path.
 *
 * @param array data Array of services
 */
PHP_METHOD(Ice_Di, __construct) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "__ROOT__", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "defined", NULL, 69, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "../", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "realpath", NULL, 70, &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "__ROOT__", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "define", NULL, 71, &_0, _2, ZEPHIR_GLOBAL(global_false));
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, ice_di_ce, this_ptr, "__construct", &_3, 6, data);
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
 * Registers a service in the services container.
 *
 * @param string key Service name
 * @param mixed value Definition
 */
PHP_METHOD(Ice_Di, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *service = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&service, this_ptr, "resolve", NULL, 0, value);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("data"), key, service TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Resolve service.
 *
 * @param mixed service Definition
 * @return object Service
 */
PHP_METHOD(Ice_Di, resolve) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *service = NULL, *params, *_0 = NULL, *_1, _2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service);

	ZEPHIR_SEPARATE_PARAM(service);


	if (Z_TYPE_P(service) == IS_STRING) {
		if (zephir_class_exists(service, 1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_0);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(_0, service TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(service, _0);
		}
	} else {
		if (Z_TYPE_P(service) == IS_OBJECT) {
			if (zephir_instance_of_ev(service, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(_0);
				ZEPHIR_CALL_USER_FUNC(_0, service);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(service, _0);
			}
		} else {
			if (Z_TYPE_P(service) == IS_ARRAY) {
				ZEPHIR_OBS_VAR(params);
				zephir_array_isset_long_fetch(&params, service, 1, 0 TSRMLS_CC);
				if (Z_TYPE_P(params) == IS_ARRAY) {
					zephir_array_fetch_long(&_1, service, 0, PH_NOISY | PH_READONLY, "ice/di.zep", 83 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(service);
					ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(service, _1, params TSRMLS_CC);
					zephir_check_call_status();
				} else {
					zephir_array_fetch_long(&_1, service, 0, PH_NOISY | PH_READONLY, "ice/di.zep", 85 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(service);
					ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(service, _1 TSRMLS_CC);
					zephir_check_call_status();
				}
			}
		}
	}
	if (Z_TYPE_P(service) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "Service '%s' cannot be resolved", 0);
		ZEPHIR_CALL_FUNCTION(&_3, "sprintf", NULL, 1, &_2, service);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "ice/di.zep", 92 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(service, 1, 0);
	RETURN_MM();

}

/**
 * Set handlers for error, exeception and shutdown.
 * Class should contain method handler, errorHandler and shutdownHandler.
 *
 * @param string className
 * @return object Di
 */
PHP_METHOD(Ice_Di, errors) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_2, *_3;
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
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 72, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, className);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "errorHandler", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 73, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_3, className);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "shutdownHandler", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 74, _3);
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

	zval *_1;
	int priority;
	zval *name_param = NULL, *callback, *priority_param = NULL, *_0, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &callback, &priority_param);

	zephir_get_strval(name, name_param);
	if (!priority_param) {
		priority = 10;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, name))) {
		ZEPHIR_INIT_VAR(_1);
		zephir_create_array(_1, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		array_init(_2);
		zephir_array_fast_append(_1, _2);
		zephir_update_property_array(this_ptr, SL("hooks"), name, _1 TSRMLS_CC);
	}
	if (zephir_is_callable(callback TSRMLS_CC) == 1) {
		zephir_update_property_array_multi(this_ptr, SL("hooks"), &callback TSRMLS_CC, SL("zla"), 2, name, priority);
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
	HashTable *_8, *_11;
	HashPosition _7, _10;
	zval *args = NULL, *_1;
	zval *name_param = NULL, *args_param = NULL, *priority = NULL, *callback = NULL, *_0, *_2 = NULL, *_3, *_4, *_5, *_6, **_9, **_12;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &args_param);

	zephir_get_strval(name, name_param);
	if (!args_param) {
	ZEPHIR_INIT_VAR(args);
	array_init(args);
	} else {
		zephir_get_arrval(args, args_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, name))) {
		ZEPHIR_INIT_VAR(_1);
		zephir_create_array(_1, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		array_init(_2);
		zephir_array_fast_append(_1, _2);
		zephir_update_property_array(this_ptr, SL("hooks"), name, _1 TSRMLS_CC);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
	zephir_array_fetch(&_4, _3, name, PH_NOISY | PH_READONLY, "ice/di.zep", 150 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(_4))) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		zephir_array_fetch(&_6, _5, name, PH_NOISY | PH_READONLY, "ice/di.zep", 156 TSRMLS_CC);
		zephir_is_iterable(_6, &_8, &_7, 0, 0, "ice/di.zep", 163);
		for (
		  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HVALUE(priority, _9);
			if (!(ZEPHIR_IS_EMPTY(priority))) {
				zephir_is_iterable(priority, &_11, &_10, 0, 0, "ice/di.zep", 161);
				for (
				  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
				  ; zephir_hash_move_forward_ex(_11, &_10)
				) {
					ZEPHIR_GET_HVALUE(callback, _12);
					ZEPHIR_INIT_NVAR(_2);
					ZEPHIR_CALL_USER_FUNC_ARRAY(_2, callback, args);
					zephir_check_call_status();
				}
			}
		}
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

	zval *name_param = NULL, *_0, *_1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	if (name && Z_STRLEN_P(name)) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		if (zephir_array_isset(_1, name)) {
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
			zephir_array_fetch(&_0, _2, name, PH_NOISY, "ice/di.zep", 177 TSRMLS_CC);
		} else {
			ZVAL_NULL(_0);
		}
		RETURN_CCTOR(_0);
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

	HashTable *_6;
	HashPosition _5;
	zval *_2 = NULL;
	zend_bool _0;
	zval *name_param = NULL, *key = NULL, *_1, *_3 = NULL, *_4, **_7, *_8 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	_0 = zephir_is_true(name);
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		_0 = zephir_array_isset(_1, name);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2);
		zephir_create_array(_2, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		array_init(_3);
		zephir_array_fast_append(_2, _3);
		zephir_update_property_array(this_ptr, SL("hooks"), name, _2 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_3);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		zephir_array_keys(_3, _4 TSRMLS_CC);
		zephir_is_iterable(_3, &_6, &_5, 0, 0, "ice/di.zep", 199);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HVALUE(key, _7);
			ZEPHIR_INIT_NVAR(_2);
			zephir_create_array(_2, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_8);
			array_init(_8);
			zephir_array_fast_append(_2, _8);
			zephir_update_property_array(this_ptr, SL("hooks"), key, _2 TSRMLS_CC);
		}
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
	zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL;
	zval *method_param = NULL, *arguments = NULL, *service = NULL, *value = NULL, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, *_4, _5, *_6 = NULL;
	zval *method = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_start_with_str(method, SL("get"))) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 3);
		ZEPHIR_INIT_VAR(_1);
		zephir_substr(_1, method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&service, "lcfirst", &_2, 18, _1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "has", NULL, 0, service);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			ZEPHIR_OBS_VAR(value);
			zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, service, value);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(_4);
			object_init_ex(_4, ice_exception_ce);
			ZEPHIR_SINIT_VAR(_5);
			ZVAL_STRING(&_5, "The '%s' service is required", 0);
			ZEPHIR_CALL_FUNCTION(&_6, "sprintf", NULL, 1, &_5, service);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_7, 2, _6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4, "ice/di.zep", 222 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (zephir_start_with_str(method, SL("set"))) {
		ZEPHIR_OBS_NVAR(value);
		zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 3);
		ZEPHIR_INIT_NVAR(_1);
		zephir_substr(_1, method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&_3, "lcfirst", &_2, 18, _1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, _3, value);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_NVAR(_1);
	object_init_ex(_1, ice_exception_ce);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SVS(_8, "Call to undefined method or service '", method, "'");
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_7, 2, _8);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "ice/di.zep", 234 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("data"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("hooks"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

