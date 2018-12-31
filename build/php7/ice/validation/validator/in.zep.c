
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * In validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *  
 *  $validation->rules([
 *      'status' => 'in:1,2,3,4'
 *  ]);
 *  
 *  $valid = $validation->validate($_POST);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_In) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, In, ice, validation_validator_in, ice_validation_validator_ce, ice_validation_validator_in_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 * Options: values (0,1,2..), label, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_In, validate) {

	zend_bool _0, _10$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, label, message, i18n, replace, values, _1, _2$$4, _3$$6, _4$$6, _6$$6, _9$$6, _11$$6, _12$$6, _16$$6, _5$$7, _7$$9, _8$$10, _13$$11, _14$$11, _15$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&field);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
	if (!(_0)) {
		_0 = Z_TYPE_P(&value) == IS_NULL;
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD(&values, this_ptr, "getoptions", NULL, 0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&values)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "values");
		ZEPHIR_CALL_METHOD(&values, this_ptr, "get", NULL, 0, &_2$$4);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&values) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Values must be an array", "ice/validation/validator/in.zep", 59);
		return;
	}
	if (!(zephir_fast_in_array(&value, &values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_4$$6);
		ZVAL_STRING(&_4$$6, "label");
		ZEPHIR_CALL_METHOD(&_3$$6, this_ptr, "has", NULL, 0, &_4$$6);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$6)) {
			ZEPHIR_INIT_VAR(&_5$$7);
			ZVAL_STRING(&_5$$7, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_5$$7);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_4$$6);
		ZVAL_STRING(&_4$$6, "message");
		ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "has", NULL, 0, &_4$$6);
		zephir_check_call_status();
		if (zephir_is_true(&_6$$6)) {
			ZEPHIR_INIT_VAR(&_7$$9);
			ZVAL_STRING(&_7$$9, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_7$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_8$$10);
			ZVAL_STRING(&_8$$10, "in");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_8$$10);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_9$$6, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_10$$6 = ZEPHIR_IS_TRUE_IDENTICAL(&_9$$6);
		if (_10$$6) {
			ZEPHIR_CALL_METHOD(&_11$$6, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$6);
			ZVAL_STRING(&_4$$6, "i18n");
			ZEPHIR_CALL_METHOD(&_12$$6, &_11$$6, "has", NULL, 0, &_4$$6);
			zephir_check_call_status();
			_10$$6 = zephir_is_true(&_12$$6);
		}
		if (_10$$6) {
			ZEPHIR_CALL_METHOD(&_13$$11, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_14$$11);
			ZVAL_STRING(&_14$$11, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_13$$11, "get", NULL, 0, &_14$$11);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_15$$11, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_15$$11);
			ZEPHIR_CALL_METHOD(&_15$$11, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_15$$11);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_4$$6);
		zephir_fast_join_str(&_4$$6, SL(", "), &values TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":values"), &_4$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_16$$6, "strtr", NULL, 103, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_16$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

