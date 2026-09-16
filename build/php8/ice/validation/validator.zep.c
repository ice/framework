
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/fcall.h"


/**
 * Validator is a base class for validators.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator)
{
	ZEPHIR_REGISTER_CLASS(Ice\\Validation, Validator, ice, validation_validator, ice_validation_validator_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_validation_validator_ce, SL("options"), ZEND_ACC_PROTECTED);
	ice_validation_validator_ce->create_object = zephir_init_properties_Ice_Validation_Validator;
	zephir_declare_class_constant_long(ice_validation_validator_ce, SL("ALL"), 0);

	zephir_declare_class_constant_long(ice_validation_validator_ce, SL("NUMERIC"), 1);

	zephir_declare_class_constant_long(ice_validation_validator_ce, SL("STRINGS"), 2);

	return SUCCESS;
}

/**
 * Validator constructor.
 *
 * @param array options
 */
PHP_METHOD(Ice_Validation_Validator, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1, &options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Validate the validator
 *
 * @param Validation validation
 * @param string field
 */
PHP_METHOD(Ice_Validation_Validator, validate)
{
}

/**
 * Whether or not an option exists by key.
 *
 * @param string key The option key
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator, has)
{
	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &key);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, key));
}

/**
 * Retrieve a single option.
 *
 * @param string key The data key
 * @param mixed defaultValue The value to return if data key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Validation_Validator, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key, key_sub, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &key, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_memory_observe(&value);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, key, 0)) {
		RETURN_CCTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();
}

/**
 * Assigns a value to the specified option.
 *
 * @param string key The data key
 * @param mixed value
 * @return object Validator
 */
PHP_METHOD(Ice_Validation_Validator, set)
{
	zval *key, key_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &key, &value);
	zephir_update_property_array(this_ptr, SL("options"), key, value);
	RETURN_THISW();
}

/**
 * Get options by type.
 *
 * @param int keys Type of options
 * @param array options
 */
PHP_METHOD(Ice_Validation_Validator, getOptions)
{
	zend_bool _7;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *keys = NULL, keys_sub, *options_param = NULL, key, value, _0, *_1, _2, *_3, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(keys)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &keys, &options_param);
	if (!keys) {
		keys = &keys_sub;
		ZEPHIR_INIT_VAR(keys);
		ZVAL_LONG(keys, 0);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "ice/validation/validator.zep", 112);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			if (ZEPHIR_IS_LONG(keys, 1)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(keys, 2)) { goto zephir_switch_0_clause_1; }
			goto zephir_switch_0_clause_2;
			zephir_switch_0_clause_0: ;
				if (Z_TYPE_P(&key) == IS_LONG) {
					zephir_array_update_zval(&options, &key, &value, PH_COPY | PH_SEPARATE);
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_1: ;
				if (Z_TYPE_P(&key) == IS_STRING) {
					zephir_array_update_zval(&options, &key, &value, PH_COPY | PH_SEPARATE);
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
				zephir_array_update_zval(&options, &key, &value, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_end: ;

		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _1, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_LONG(keys, 1)) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_LONG(keys, 2)) { goto zephir_switch_1_clause_1; }
				goto zephir_switch_1_clause_2;
				zephir_switch_1_clause_0: ;
					if (Z_TYPE_P(&key) == IS_LONG) {
						zephir_array_update_zval(&options, &key, &value, PH_COPY | PH_SEPARATE);
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_1: ;
					if (Z_TYPE_P(&key) == IS_STRING) {
						zephir_array_update_zval(&options, &key, &value, PH_COPY | PH_SEPARATE);
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_2: ;
					zephir_array_update_zval(&options, &key, &value, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&options);
}

zend_object *zephir_init_properties_Ice_Validation_Validator(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

