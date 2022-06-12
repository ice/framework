
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"


/**
 * Between validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *
 *  $validation->rules([
 *      'age' => 'between:18,21',
 *      'height' => [
 *          'between' => [
 *              'min' => 180,
 *              'max' => 190,
 *          ]
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Between)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Between, ice, validation_validator_between, ice_validation_validator_ce, ice_validation_validator_between_method_entry, 0);

	return SUCCESS;
}

/**
 * Validate the validator
 * Options: min (0), max (1), label, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Between, validate)
{
	zend_bool _0, _8, _16$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, label, message, i18n, replace, min, max, _1, _2, _5, _3$$4, _4$$5, _6$$6, _7$$7, _9$$8, _10$$8, _12$$8, _15$$8, _17$$8, _18$$8, _22$$8, _11$$9, _13$$11, _14$$12, _19$$13, _20$$13, _21$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&min);
	ZVAL_UNDEF(&max);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&field);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, ice_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);
	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
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
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZVAL_LONG(&_3$$4, 0);
		ZEPHIR_CALL_METHOD(&min, this_ptr, "get", NULL, 0, &_3$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "min");
		ZEPHIR_CALL_METHOD(&min, this_ptr, "get", NULL, 0, &_4$$5);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZVAL_LONG(&_6$$6, 1);
		ZEPHIR_CALL_METHOD(&max, this_ptr, "get", NULL, 0, &_6$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_7$$7);
		ZVAL_STRING(&_7$$7, "max");
		ZEPHIR_CALL_METHOD(&max, this_ptr, "get", NULL, 0, &_7$$7);
		zephir_check_call_status();
	}
	_8 = ZEPHIR_LT(&value, &min);
	if (!(_8)) {
		_8 = ZEPHIR_GT(&value, &max);
	}
	if (_8) {
		ZEPHIR_INIT_VAR(&_10$$8);
		ZVAL_STRING(&_10$$8, "label");
		ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "has", NULL, 0, &_10$$8);
		zephir_check_call_status();
		if (zephir_is_true(&_9$$8)) {
			ZEPHIR_INIT_VAR(&_11$$9);
			ZVAL_STRING(&_11$$9, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_11$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_10$$8);
		ZVAL_STRING(&_10$$8, "message");
		ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "has", NULL, 0, &_10$$8);
		zephir_check_call_status();
		if (zephir_is_true(&_12$$8)) {
			ZEPHIR_INIT_VAR(&_13$$11);
			ZVAL_STRING(&_13$$11, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_13$$11);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_14$$12);
			ZVAL_STRING(&_14$$12, "between");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_14$$12);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_15$$8, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_16$$8 = ZEPHIR_IS_TRUE_IDENTICAL(&_15$$8);
		if (_16$$8) {
			ZEPHIR_CALL_METHOD(&_17$$8, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$8);
			ZVAL_STRING(&_10$$8, "i18n");
			ZEPHIR_CALL_METHOD(&_18$$8, &_17$$8, "has", NULL, 0, &_10$$8);
			zephir_check_call_status();
			_16$$8 = zephir_is_true(&_18$$8);
		}
		if (_16$$8) {
			ZEPHIR_CALL_METHOD(&_19$$13, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_20$$13);
			ZVAL_STRING(&_20$$13, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_19$$13, "get", NULL, 0, &_20$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$13, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_21$$13);
			ZEPHIR_CALL_METHOD(&_21$$13, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_21$$13);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 3, 0);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":min"), &min, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":max"), &max, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_22$$8, "strtr", NULL, 110, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_22$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

