
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
	zend_declare_class_constant_long(ice_validation_validator_ce, SL("ALL"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_validation_validator_ce, SL("NUMERIC"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_validation_validator_ce, SL("STRINGS"), 2 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Validator constructor.
 *
 * @param array options
 */
PHP_METHOD(Ice_Validation_Validator, __construct) {

	zval *options_param = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	zephir_update_property_this(getThis(), SL("options"), options TSRMLS_CC);
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

	zval *key, *_0;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, key));

}

/**
 * Retrieve a single option.
 *
 * @param string key The data key
 * @param mixed defaultValue The value to return if data key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Validation_Validator, get) {

	zval *key, *defaultValue = NULL, *value = NULL, *_0;

	zephir_fetch_params(0, 1, 1, &key, &defaultValue);

	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTORW(value);
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

	zval *key, *value;

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

	HashTable *_2;
	HashPosition _1;
	zval *options = NULL;
	zval *keys = NULL, *options_param = NULL, *key = NULL, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keys, &options_param);

	if (!keys) {
		ZEPHIR_INIT_VAR(keys);
		ZVAL_LONG(keys, 0);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/validation/validator.zep", 113);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		do {
			if (ZEPHIR_IS_LONG(keys, 1)) {
				if (Z_TYPE_P(key) == IS_LONG) {
					zephir_array_update_zval(&options, key, &value, PH_COPY | PH_SEPARATE);
				}
				break;
			}
			if (ZEPHIR_IS_LONG(keys, 2)) {
				if (Z_TYPE_P(key) == IS_STRING) {
					zephir_array_update_zval(&options, key, &value, PH_COPY | PH_SEPARATE);
				}
				break;
			}
			zephir_array_update_zval(&options, key, &value, PH_COPY | PH_SEPARATE);
			break;
		} while(0);

	}
	RETURN_CTOR(options);

}

zend_object_value zephir_init_properties_Ice_Validation_Validator(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

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

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("options"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

