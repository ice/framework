
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


/**
 * Validator is a base class for validators.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator) {

	ZEPHIR_REGISTER_CLASS(Ice\\Validation, Validator, ice, validation_validator, ice_validation_validator_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_validation_validator_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
PHP_METHOD(Ice_Validation_Validator, __construct) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Validate the validator
 *
 * @param Validation validation
 * @param string field
 */
PHP_METHOD(Ice_Validation_Validator, validate) {

}

/**
 * Whether or not an option exists by key.
 *
 * @param string key The option key
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator, has) {

	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &key);



	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, key));

}

/**
 * Retrieve a single option.
 *
 * @param string key The data key
 * @param mixed defaultValue The value to return if data key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Validation_Validator, get) {

	zval *key, key_sub, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 1, &key, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, key, 1 TSRMLS_CC)) {
		RETURN_CTORW(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;

}

/**
 * Assigns a value to the specified option.
 *
 * @param string key The data key
 * @param mixed value
 * @return object Validator
 */
PHP_METHOD(Ice_Validation_Validator, set) {

	zval *key, key_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &key, &value);



	zephir_update_property_array(this_ptr, SL("options"), key, value TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get options by type.
 *
 * @param int keys Type of options
 * @param array options
 */
PHP_METHOD(Ice_Validation_Validator, getOptions) {

	zend_string *_3;
	zend_ulong _2;
	zval options;
	zval *keys = NULL, keys_sub, *options_param = NULL, key, value, _0, *_1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
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


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "ice/validation/validator.zep", 113);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		do {
			if (ZEPHIR_IS_LONG(keys, 1)) {
				if (Z_TYPE_P(&key) == IS_LONG) {
					zephir_array_update_zval(&options, &key, &value, PH_COPY | PH_SEPARATE);
				}
				break;
			}
			if (ZEPHIR_IS_LONG(keys, 2)) {
				if (Z_TYPE_P(&key) == IS_STRING) {
					zephir_array_update_zval(&options, &key, &value, PH_COPY | PH_SEPARATE);
				}
				break;
			}
			zephir_array_update_zval(&options, &key, &value, PH_COPY | PH_SEPARATE);
			break;
		} while(0);

	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&options);

}

zend_object *zephir_init_properties_Ice_Validation_Validator(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

