
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "Zend/zend_closures.h"
#include "kernel/array.h"
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

	ice_di_ce->create_object = zephir_init_properties_Ice_Di;
	return SUCCESS;

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
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	ZEPHIR_CALL_PARENT(NULL, ice_di_ce, this_ptr, "__construct", &_0, 6, data);
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
	zval *service = NULL, *params = NULL, *_0$$4, *_1$$7, *_2$$10, *_3$$11, *_4$$12, _5$$12, *_6$$12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service);

	ZEPHIR_SEPARATE_PARAM(service);


	if (Z_TYPE_P(service) == IS_STRING) {
		if (zephir_class_exists(service, 1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_0$$4);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(_0$$4, service TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(service, _0$$4);
		}
	} else {
		if (Z_TYPE_P(service) == IS_OBJECT) {
			if (zephir_instance_of_ev(service, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_1$$7);
				ZEPHIR_CALL_USER_FUNC(_1$$7, service);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(service, _1$$7);
			}
		} else {
			if (Z_TYPE_P(service) == IS_ARRAY) {
				ZEPHIR_OBS_VAR(params);
				zephir_array_isset_long_fetch(&params, service, 1, 0 TSRMLS_CC);
				if (Z_TYPE_P(params) == IS_ARRAY) {
					zephir_array_fetch_long(&_2$$10, service, 0, PH_NOISY | PH_READONLY, "ice/di.zep", 78 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(service);
					ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(service, _2$$10, params TSRMLS_CC);
					zephir_check_call_status();
				} else {
					zephir_array_fetch_long(&_3$$11, service, 0, PH_NOISY | PH_READONLY, "ice/di.zep", 80 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(service);
					ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(service, _3$$11 TSRMLS_CC);
					zephir_check_call_status();
				}
			}
		}
	}
	if (Z_TYPE_P(service) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_4$$12);
		object_init_ex(_4$$12, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_5$$12);
		ZVAL_STRING(&_5$$12, "Service '%s' cannot be resolved", 0);
		ZEPHIR_CALL_FUNCTION(&_6$$12, "sprintf", NULL, 1, &_5$$12, service);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _4$$12, "__construct", NULL, 2, _6$$12);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$12, "ice/di.zep", 87 TSRMLS_CC);
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

	zval *_0, *_2, *_3;
	int ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 78, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, className);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "errorHandler", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 79, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_3, className);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "shutdownHandler", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 80, _3);
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

	zval *_1$$3;
	int priority;
	zval *name_param = NULL, *callback, *priority_param = NULL, *_0, *_2$$3;
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
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		array_init(_2$$3);
		zephir_array_fast_append(_1$$3, _2$$3);
		zephir_update_property_array(this_ptr, SL("hooks"), name, _1$$3 TSRMLS_CC);
	}
	if (zephir_is_callable(callback TSRMLS_CC) == 1) {
		zephir_update_property_array_multi(this_ptr, SL("hooks"), &callback TSRMLS_CC, SL("zla"), 3, name, priority);
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

	HashTable *_8$$4, *_11$$6;
	HashPosition _7$$4, _10$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL, *_1$$3;
	zval *name_param = NULL, *args_param = NULL, *priority = NULL, *callback = NULL, *_0, *_3, *_4, *_2$$3, *_5$$4, *_6$$4, **_9$$4, **_12$$6, *_13$$7 = NULL;
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
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		array_init(_2$$3);
		zephir_array_fast_append(_1$$3, _2$$3);
		zephir_update_property_array(this_ptr, SL("hooks"), name, _1$$3 TSRMLS_CC);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
	zephir_array_fetch(&_4, _3, name, PH_NOISY | PH_READONLY, "ice/di.zep", 145 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(_4))) {
		_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		zephir_array_fetch(&_6$$4, _5$$4, name, PH_NOISY | PH_READONLY, "ice/di.zep", 151 TSRMLS_CC);
		zephir_is_iterable(_6$$4, &_8$$4, &_7$$4, 0, 0, "ice/di.zep", 158);
		for (
		  ; zephir_hash_get_current_data_ex(_8$$4, (void**) &_9$$4, &_7$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8$$4, &_7$$4)
		) {
			ZEPHIR_GET_HVALUE(priority, _9$$4);
			if (!(ZEPHIR_IS_EMPTY(priority))) {
				zephir_is_iterable(priority, &_11$$6, &_10$$6, 0, 0, "ice/di.zep", 156);
				for (
				  ; zephir_hash_get_current_data_ex(_11$$6, (void**) &_12$$6, &_10$$6) == SUCCESS
				  ; zephir_hash_move_forward_ex(_11$$6, &_10$$6)
				) {
					ZEPHIR_GET_HVALUE(callback, _12$$6);
					ZEPHIR_INIT_NVAR(_13$$7);
					ZEPHIR_CALL_USER_FUNC_ARRAY(_13$$7, callback, args);
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

	zval *name_param = NULL, *_0$$3, *_1$$3, *_2$$3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	if (!(!name) && Z_STRLEN_P(name)) {
		ZEPHIR_INIT_VAR(_0$$3);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		if (zephir_array_isset(_1$$3, name)) {
			_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
			zephir_array_fetch(&_0$$3, _2$$3, name, PH_NOISY, "ice/di.zep", 172 TSRMLS_CC);
		} else {
			ZVAL_NULL(_0$$3);
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

	HashTable *_7$$4;
	HashPosition _6$$4;
	zval *_2$$3, *_9$$5 = NULL;
	zend_bool _0;
	zval *name_param = NULL, *key = NULL, *_1, *_3$$3, *_4$$4, *_5$$4, **_8$$4, *_10$$5 = NULL;
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
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_create_array(_2$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		array_init(_3$$3);
		zephir_array_fast_append(_2$$3, _3$$3);
		zephir_update_property_array(this_ptr, SL("hooks"), name, _2$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_4$$4);
		_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		zephir_array_keys(_4$$4, _5$$4 TSRMLS_CC);
		zephir_is_iterable(_4$$4, &_7$$4, &_6$$4, 0, 0, "ice/di.zep", 194);
		for (
		  ; zephir_hash_get_current_data_ex(_7$$4, (void**) &_8$$4, &_6$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7$$4, &_6$$4)
		) {
			ZEPHIR_GET_HVALUE(key, _8$$4);
			ZEPHIR_INIT_NVAR(_9$$5);
			zephir_create_array(_9$$5, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_10$$5);
			array_init(_10$$5);
			zephir_array_fast_append(_9$$5, _10$$5);
			zephir_update_property_array(this_ptr, SL("hooks"), key, _9$$5 TSRMLS_CC);
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
	zval *method_param = NULL, *arguments = NULL, *service = NULL, *value = NULL, *_11, _0$$3, *_1$$3, *_3$$3 = NULL, *_4$$5, _5$$5, *_6$$5 = NULL, _8$$6, *_9$$6, *_10$$6 = NULL;
	zval *method = NULL, *_12;

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
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_LONG(&_0$$3, 3);
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_substr(_1$$3, method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&service, "lcfirst", &_2, 18, _1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "has", NULL, 0, service);
		zephir_check_call_status();
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_OBS_VAR(value);
			zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, service, value);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(_4$$5);
			object_init_ex(_4$$5, ice_exception_ce);
			ZEPHIR_SINIT_VAR(_5$$5);
			ZVAL_STRING(&_5$$5, "The '%s' service is required", 0);
			ZEPHIR_CALL_FUNCTION(&_6$$5, "sprintf", NULL, 1, &_5$$5, service);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _4$$5, "__construct", &_7, 2, _6$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$5, "ice/di.zep", 217 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (zephir_start_with_str(method, SL("set"))) {
		ZEPHIR_OBS_NVAR(value);
		zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_8$$6);
		ZVAL_LONG(&_8$$6, 3);
		ZEPHIR_INIT_VAR(_9$$6);
		zephir_substr(_9$$6, method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_FUNCTION(&_10$$6, "lcfirst", &_2, 18, _9$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, _10$$6, value);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_11);
	object_init_ex(_11, ice_exception_ce);
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_SVS(_12, "Call to undefined method or service '", method, "'");
	ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_7, 2, _12);
	zephir_check_call_status();
	zephir_throw_exception_debug(_11, "ice/di.zep", 229 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

static zend_object_value zephir_init_properties_Ice_Di(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("data"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("hooks"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("hooks"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

