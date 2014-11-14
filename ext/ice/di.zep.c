
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "Zend/zend_closures.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"

ZEPHIR_INIT_CLASS(Ice_Di) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Di, ice, di, ice_arr_ce, ice_di_method_entry, 0);

	zend_declare_property_null(ice_di_ce, SL("_di"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(ice_di_ce, SL("_hooks"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_di_ce TSRMLS_CC, 1, ice_di_diinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Di, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *data_param = NULL, *_0;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_hooks"), _0 TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, ice_di_ce, this_ptr, "__construct", &_1, data);
	zephir_check_call_status();
	zephir_update_static_property_ce(ice_di_ce, SL("_di"), &this_ptr TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the last DI created
 *
 * @return DiInterface
 */
PHP_METHOD(Ice_Di, fetch) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(ice_di_ce, SL("_di") TSRMLS_CC);
	RETURN_CTORW(_0);

}

PHP_METHOD(Ice_Di, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *service = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&service, this_ptr, "resolve", NULL, value);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_data"), key, service TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Di, resolve) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *service = NULL, *params, *_0, *_1 = NULL, *_3, *_4, _5;

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
				ZEPHIR_CALL_FUNCTION(&_1, "call_user_func", &_2, service);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(service, _1);
			}
		} else {
			if (Z_TYPE_P(service) == IS_ARRAY) {
				ZEPHIR_OBS_VAR(params);
				zephir_array_isset_long_fetch(&params, service, 1, 0 TSRMLS_CC);
				if (Z_TYPE_P(params) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(service);
					zephir_array_fetch_long(&_3, service, 0, PH_NOISY | PH_READONLY, "ice/di.zep", 56 TSRMLS_CC);
					ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(service, _3, params TSRMLS_CC);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(service);
					zephir_array_fetch_long(&_3, service, 0, PH_NOISY | PH_READONLY, "ice/di.zep", 58 TSRMLS_CC);
					ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(service, _3 TSRMLS_CC);
					zephir_check_call_status();
				}
			}
		}
	}
	if (Z_TYPE_P(service) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "Service '%s' cannot be resolved", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "sprintf", &_6, &_5, service);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "ice/di.zep", 65 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(service, 1, 0);
	RETURN_MM();

}

/**
 * Assign hook
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_hooks"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, name))) {
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 2);
		ZEPHIR_INIT_VAR(_2);
		array_init(_2);
		zephir_array_fast_append(_1, _2);
		zephir_update_property_array(this_ptr, SL("_hooks"), name, _1 TSRMLS_CC);
	}
	if (zephir_is_callable(callback TSRMLS_CC) == 1) {
		zephir_update_property_array_multi(this_ptr, SL("_hooks"), &callback TSRMLS_CC, SL("zla"), 2, name, priority);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Invoke hook
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_hooks"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, name))) {
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 2);
		ZEPHIR_INIT_VAR(_2);
		array_init(_2);
		zephir_array_fast_append(_1, _2);
		zephir_update_property_array(this_ptr, SL("_hooks"), name, _1 TSRMLS_CC);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_hooks"), PH_NOISY_CC);
	zephir_array_fetch(&_4, _3, name, PH_NOISY | PH_READONLY, "ice/di.zep", 102 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(_4))) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_hooks"), PH_NOISY_CC);
		zephir_array_fetch(&_6, _5, name, PH_NOISY | PH_READONLY, "ice/di.zep", 108 TSRMLS_CC);
		zephir_is_iterable(_6, &_8, &_7, 0, 0, "ice/di.zep", 115);
		for (
		  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HVALUE(priority, _9);
			if (!(ZEPHIR_IS_EMPTY(priority))) {
				zephir_is_iterable(priority, &_11, &_10, 0, 0, "ice/di.zep", 113);
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
 * Get hook listeners
 *
 * Return an array of registered hooks. If `$name` is a valid
 * hook name, only the listeners attached to that hook are returned.
 * Else, all listeners are returned as an associative array whose
 * keys are hook names and whose values are arrays of listeners.
 *
 * @param  string     $name A hook name (Optional)
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
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_hooks"), PH_NOISY_CC);
		if (zephir_array_isset(_1, name)) {
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_hooks"), PH_NOISY_CC);
			zephir_array_fetch(&_0, _2, name, PH_NOISY, "ice/di.zep", 131 TSRMLS_CC);
		} else {
			ZVAL_NULL(_0);
		}
		RETURN_CCTOR(_0);
	} else {
		RETURN_MM_MEMBER(this_ptr, "_hooks");
	}

}

/**
 * Clear hook listeners
 *
 * Clear all listeners for all hooks. If `$name` is
 * a valid hook name, only the listeners attached
 * to that hook will be cleared.
 *
 * @param  string $name A hook name (Optional)
 */
PHP_METHOD(Ice_Di, clearHooks) {

	HashTable *_6;
	HashPosition _5;
	zval *_2 = NULL;
	zend_bool _0;
	zval *name_param = NULL, *key = NULL, *value = NULL, *_1, *_3 = NULL, *_4, **_7;
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
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_hooks"), PH_NOISY_CC);
		_0 = zephir_array_isset(_1, name);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2);
		array_init_size(_2, 2);
		ZEPHIR_INIT_VAR(_3);
		array_init(_3);
		zephir_array_fast_append(_2, _3);
		zephir_update_property_array(this_ptr, SL("_hooks"), name, _2 TSRMLS_CC);
	} else {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_hooks"), PH_NOISY_CC);
		zephir_is_iterable(_4, &_6, &_5, 0, 0, "ice/di.zep", 155);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HMKEY(key, _6, _5);
			ZEPHIR_GET_HVALUE(value, _7);
			ZEPHIR_INIT_NVAR(_2);
			array_init_size(_2, 2);
			ZEPHIR_INIT_NVAR(_3);
			array_init(_3);
			zephir_array_fast_append(_2, _3);
			zephir_update_property_array(this_ptr, SL("_hooks"), key, _2 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic method to get or set services using setters/getters
 *
 * @param string method
 * @param mixed arguments
 * @return mixed
 */
PHP_METHOD(Ice_Di, __call) {

	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_7 = NULL;
	zval *method_param = NULL, *arguments = NULL, *service = NULL, *value = NULL, _0 = zval_used_for_init, *_1 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL;
	zval *method = NULL, *_9;

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
		ZEPHIR_CALL_FUNCTION(&_1, "substr", &_2, method, &_0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&service, "lcfirst", &_3, _1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "has", NULL, service);
		zephir_check_call_status();
		if (zephir_is_true(_4)) {
			ZEPHIR_OBS_VAR(value);
			zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, service, value);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(_5);
			object_init_ex(_5, ice_exception_ce);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "The '%s' service is required", 0);
			ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_7, &_0, service);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_8, _6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "ice/di.zep", 178 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (zephir_start_with_str(method, SL("set"))) {
		ZEPHIR_OBS_NVAR(value);
		zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 3);
		ZEPHIR_CALL_FUNCTION(&_1, "substr", &_2, method, &_0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_4, "lcfirst", &_3, _1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, _4, value);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_LNVAR(_5);
	object_init_ex(_5, ice_exception_ce);
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_SVS(_9, "Call to undefined method or service '", method, "'");
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_8, _9);
	zephir_check_call_status();
	zephir_throw_exception_debug(_5, "ice/di.zep", 190 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

