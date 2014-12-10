
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"

ZEPHIR_INIT_CLASS(Ice_Validation_Validator) {

	ZEPHIR_REGISTER_CLASS(Ice\\Validation, Validator, ice, validation_validator, ice_validation_validator_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_validation_validator_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(ice_validation_validator_ce, SL("ALL"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_validation_validator_ce, SL("NUMERIC"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_validation_validator_ce, SL("STRINGS"), 2 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Validation_Validator, __construct) {

	zval *options_param = NULL, *_0;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_options"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Validation_Validator, validate) {

}

PHP_METHOD(Ice_Validation_Validator, has) {

	zval *key, *_0;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, key));

}

PHP_METHOD(Ice_Validation_Validator, get) {

	zval *key, *defaultValue = NULL, *value, *_0;

	zephir_fetch_params(0, 1, 1, &key, &defaultValue);

	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTORW(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;

}

PHP_METHOD(Ice_Validation_Validator, set) {

	zval *key, *value;

	zephir_fetch_params(0, 2, 0, &key, &value);



	zephir_update_property_array(this_ptr, SL("_options"), key, value TSRMLS_CC);

}

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/validation/validator.zep", 65);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
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

