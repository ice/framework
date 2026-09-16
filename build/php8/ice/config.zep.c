
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
#include "kernel/string.h"
#include "kernel/object.h"


/**
 * Wrapper for configuration arrays.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) Ice Team
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
	zend_string *_10, *_15$$11, *_26$$21;
	zend_ulong _9, _14$$11, _25$$21;
	zend_bool hasNumericKey = 0, _0, _21, _17$$11, _28$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, __$null, key, value, subkey, subvalue, *_6, _7, *_8, _20, _1$$4, _2$$5, _4$$5, *_11$$11, _12$$11, *_13$$11, _16$$11, _18$$17, *_22$$21, _23$$21, *_24$$21, _27$$21, _29$$27;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&subkey);
	ZVAL_UNDEF(&subvalue);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_29$$27);
	ZVAL_UNDEF(&_3$$5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", &_5, 13, &_3$$5);
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
	if (Z_TYPE_P(data) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_7);
		zephir_string_to_char_array(&_7, data);
		_6 = &_7;
	} else {
		_6 = data;
	}
	zephir_is_iterable(_6, 0, "ice/config.zep", 63);
	if (Z_TYPE_P(_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_6), _9, _10, _8)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_10 != NULL) { 
				ZVAL_STR_COPY(&key, _10);
			} else {
				ZVAL_LONG(&key, _9);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _8);
			if (Z_TYPE_P(&key) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Only string keys are allowed", "ice/config.zep", 42);
				return;
			}
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				hasNumericKey = 0;
				if (Z_TYPE_P(&value) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_12$$11);
					zephir_string_to_char_array(&_12$$11, &value);
					_11$$11 = &_12$$11;
				} else {
					_11$$11 = &value;
				}
				zephir_is_iterable(_11$$11, 0, "ice/config.zep", 54);
				if (Z_TYPE_P(_11$$11) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_11$$11), _14$$11, _15$$11, _13$$11)
					{
						ZEPHIR_INIT_NVAR(&subkey);
						if (_15$$11 != NULL) { 
							ZVAL_STR_COPY(&subkey, _15$$11);
						} else {
							ZVAL_LONG(&subkey, _14$$11);
						}
						ZEPHIR_INIT_NVAR(&subvalue);
						ZVAL_COPY(&subvalue, _13$$11);
						if (Z_TYPE_P(&subkey) == IS_LONG) {
							hasNumericKey = 1;
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _11$$11, "rewind", NULL, 0);
					zephir_check_call_status();
					_17$$11 = 1;
					while (1) {
						if (_17$$11) {
							_17$$11 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _11$$11, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_16$$11, _11$$11, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_16$$11)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&subkey, _11$$11, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&subvalue, _11$$11, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&subkey) == IS_LONG) {
								hasNumericKey = 1;
								break;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&subvalue);
				ZEPHIR_INIT_NVAR(&subkey);
				if (hasNumericKey) {
					zephir_update_property_array(this_ptr, SL("data"), &key, &value);
				} else {
					ZEPHIR_INIT_NVAR(&_18$$17);
					object_init_ex(&_18$$17, ice_config_ce);
					ZEPHIR_CALL_METHOD(NULL, &_18$$17, "__construct", &_19, 25, &value);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("data"), &key, &_18$$17);
				}
			} else {
				zephir_update_property_array(this_ptr, SL("data"), &key, &value);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _6, "rewind", NULL, 0);
		zephir_check_call_status();
		_21 = 1;
		while (1) {
			if (_21) {
				_21 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _6, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_20, _6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_20)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _6, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _6, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Only string keys are allowed", "ice/config.zep", 42);
					return;
				}
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					hasNumericKey = 0;
					if (Z_TYPE_P(&value) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_23$$21);
						zephir_string_to_char_array(&_23$$21, &value);
						_22$$21 = &_23$$21;
					} else {
						_22$$21 = &value;
					}
					zephir_is_iterable(_22$$21, 0, "ice/config.zep", 54);
					if (Z_TYPE_P(_22$$21) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_22$$21), _25$$21, _26$$21, _24$$21)
						{
							ZEPHIR_INIT_NVAR(&subkey);
							if (_26$$21 != NULL) { 
								ZVAL_STR_COPY(&subkey, _26$$21);
							} else {
								ZVAL_LONG(&subkey, _25$$21);
							}
							ZEPHIR_INIT_NVAR(&subvalue);
							ZVAL_COPY(&subvalue, _24$$21);
							if (Z_TYPE_P(&subkey) == IS_LONG) {
								hasNumericKey = 1;
								break;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _22$$21, "rewind", NULL, 0);
						zephir_check_call_status();
						_28$$21 = 1;
						while (1) {
							if (_28$$21) {
								_28$$21 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _22$$21, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_27$$21, _22$$21, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_27$$21)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&subkey, _22$$21, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&subvalue, _22$$21, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&subkey) == IS_LONG) {
									hasNumericKey = 1;
									break;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&subvalue);
					ZEPHIR_INIT_NVAR(&subkey);
					if (hasNumericKey) {
						zephir_update_property_array(this_ptr, SL("data"), &key, &value);
					} else {
						ZEPHIR_INIT_NVAR(&_29$$27);
						object_init_ex(&_29$$27, ice_config_ce);
						ZEPHIR_CALL_METHOD(NULL, &_29$$27, "__construct", &_19, 25, &value);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("data"), &key, &_29$$27);
					}
				} else {
					zephir_update_property_array(this_ptr, SL("data"), &key, &value);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();
}

