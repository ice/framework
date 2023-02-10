
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
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/memory.h"
#include "kernel/require.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Wrapper for configuration arrays.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2023 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Config)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice, Config, ice, config, ice_arr_ce, ice_config_method_entry, 0);

	return SUCCESS;
}

/**
 * Config constructor.
 *
 * @param array data Initial config
 */
PHP_METHOD(Ice_Config, __construct)
{
	zval _3$$5;
	zend_string *_9, *_13$$11, *_19$$21;
	zend_ulong _8, _12$$11, _18$$21;
	zend_bool hasNumericKey = 0, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, __$null, key, value, subkey, subvalue, *_6, _7, _1$$4, _2$$5, _4$$5, *_10$$11, _11$$11, _14$$17, *_16$$21, _17$$21, _20$$27;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&subkey);
	ZVAL_UNDEF(&subvalue);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&_20$$27);
	ZVAL_UNDEF(&_3$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);
	if (!data) {
		data = &data_sub;
		ZEPHIR_CPY_WRT(data, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}


	_0 = Z_TYPE_P(data) == IS_STRING;
	if (_0) {
		_0 = !ZEPHIR_IS_STRING(data, "");
	}
	if (_0) {
		if ((zephir_file_exists(data) == SUCCESS)) {
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_1$$4);
			if (zephir_require_zval_ret(&_1$$4, data) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(data, &_1$$4);
		} else {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, ice_exception_ce);
			ZEPHIR_INIT_VAR(&_3$$5);
			zephir_create_array(&_3$$5, 2, 0);
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "Config file '%s' doesn't exist");
			zephir_array_fast_append(&_3$$5, &_4$$5);
			zephir_array_fast_append(&_3$$5, data);
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", &_5, 12, &_3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "ice/config.zep", 28);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		if (Z_TYPE_P(data) != IS_NULL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The configuration must be an Array", "ice/config.zep", 34);
			return;
		} else {
			RETURN_MM_NULL();
		}
	}
	zephir_is_iterable(data, 0, "ice/config.zep", 63);
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _8, _9, _6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&key, _9);
			} else {
				ZVAL_LONG(&key, _8);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _6);
			if (Z_TYPE_P(&key) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Only string keys are allowed", "ice/config.zep", 42);
				return;
			}
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				hasNumericKey = 0;
				zephir_is_iterable(&value, 0, "ice/config.zep", 54);
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _12$$11, _13$$11, _10$$11)
					{
						ZEPHIR_INIT_NVAR(&subkey);
						if (_13$$11 != NULL) { 
							ZVAL_STR_COPY(&subkey, _13$$11);
						} else {
							ZVAL_LONG(&subkey, _12$$11);
						}
						ZEPHIR_INIT_NVAR(&subvalue);
						ZVAL_COPY(&subvalue, _10$$11);
						if (Z_TYPE_P(&subkey) == IS_LONG) {
							hasNumericKey = 1;
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_11$$11, &value, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_11$$11)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&subkey, &value, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&subvalue, &value, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&subkey) == IS_LONG) {
								hasNumericKey = 1;
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&subvalue);
				ZEPHIR_INIT_NVAR(&subkey);
				if (hasNumericKey) {
					zephir_update_property_array(this_ptr, SL("data"), &key, &value);
				} else {
					ZEPHIR_INIT_NVAR(&_14$$17);
					object_init_ex(&_14$$17, ice_config_ce);
					ZEPHIR_CALL_METHOD(NULL, &_14$$17, "__construct", &_15, 24, &value);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("data"), &key, &_14$$17);
				}
			} else {
				zephir_update_property_array(this_ptr, SL("data"), &key, &value);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Only string keys are allowed", "ice/config.zep", 42);
					return;
				}
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					hasNumericKey = 0;
					zephir_is_iterable(&value, 0, "ice/config.zep", 54);
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _18$$21, _19$$21, _16$$21)
						{
							ZEPHIR_INIT_NVAR(&subkey);
							if (_19$$21 != NULL) { 
								ZVAL_STR_COPY(&subkey, _19$$21);
							} else {
								ZVAL_LONG(&subkey, _18$$21);
							}
							ZEPHIR_INIT_NVAR(&subvalue);
							ZVAL_COPY(&subvalue, _16$$21);
							if (Z_TYPE_P(&subkey) == IS_LONG) {
								hasNumericKey = 1;
								break;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_17$$21, &value, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_17$$21)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&subkey, &value, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&subvalue, &value, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&subkey) == IS_LONG) {
									hasNumericKey = 1;
									break;
								}
							ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&subvalue);
					ZEPHIR_INIT_NVAR(&subkey);
					if (hasNumericKey) {
						zephir_update_property_array(this_ptr, SL("data"), &key, &value);
					} else {
						ZEPHIR_INIT_NVAR(&_20$$27);
						object_init_ex(&_20$$27, ice_config_ce);
						ZEPHIR_CALL_METHOD(NULL, &_20$$27, "__construct", &_15, 24, &value);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("data"), &key, &_20$$27);
					}
				} else {
					zephir_update_property_array(this_ptr, SL("data"), &key, &value);
				}
			ZEPHIR_CALL_METHOD(NULL, data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();
}

