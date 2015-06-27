
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"


/**
 * With validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *  
 *  $validation->rules([
 *      'repeatPassword' => [
 *          'with' => [
 *              'fields' => ['password'],
 *          ],
 *      ]
 *  ]);
 *  
 *  $valid = $validation->validate($_POST);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_With) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, With, ice, validation_validator_with, ice_validation_validator_ce, ice_validation_validator_with_method_entry, 0);

	ice_validation_validator_with_ce->create_object = zephir_init_properties;
	return SUCCESS;

}

/**
 * Validate the validator
 * Options: label, fields, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_With, validate) {

	HashTable *_3;
	HashPosition _2;
	zend_bool _0, _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace, *fields = NULL, *with = NULL, *tmp = NULL, *required, *_1 = NULL, **_4, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
	if (!(_0)) {
		_0 = Z_TYPE_P(value) == IS_NULL;
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "getoptions", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(required);
	array_init(required);
	if (ZEPHIR_IS_EMPTY(fields)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "fields", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&fields, this_ptr, "get", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(fields) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Fields must be an array", "ice/validation/validator/with.zep", 64);
		return;
	}
	zephir_is_iterable(fields, &_3, &_2, 0, 0, "ice/validation/validator/with.zep", 75);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(with, _4);
		ZEPHIR_CALL_METHOD(&tmp, validation, "getvalue", NULL, 0, with);
		zephir_check_call_status();
		_5 = ZEPHIR_IS_STRING_IDENTICAL(tmp, "");
		if (!(_5)) {
			_5 = Z_TYPE_P(tmp) == IS_NULL;
		}
		if (_5) {
			zephir_array_append(&required, with, PH_SEPARATE, "ice/validation/validator/with.zep", 71);
		}
	}
	if (zephir_fast_count_int(required TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "has", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "has", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_7)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "with", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_8, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_5 = ZEPHIR_IS_TRUE_IDENTICAL(_8);
		if (_5) {
			ZEPHIR_CALL_METHOD(&_9, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_10, _9, "has", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			_5 = zephir_is_true(_10);
		}
		if (_5) {
			ZEPHIR_CALL_METHOD(&_11, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _11, "get", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_12, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _12);
			ZEPHIR_CALL_METHOD(&_12, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _12);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_1);
		zephir_fast_join_str(_1, SL(", "), required TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":fields"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_11, "strtr", NULL, 76, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("options"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

