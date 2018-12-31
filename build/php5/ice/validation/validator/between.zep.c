
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


/**
 * Between validator.
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Between) {

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
PHP_METHOD(Ice_Validation_Validator_Between, validate) {

	zend_bool _0, _8, _16$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace = NULL, *min = NULL, *max = NULL, *_1 = NULL, *_2 = NULL, *_5 = NULL, *_3$$4, *_4$$5, *_6$$6, *_7$$7, *_9$$8 = NULL, *_10$$8 = NULL, *_12$$8 = NULL, *_15$$8 = NULL, *_17$$8 = NULL, *_18$$8 = NULL, *_22$$8 = NULL, *_11$$9, *_13$$11, *_14$$12, *_19$$13 = NULL, *_20$$13, *_21$$13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
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
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_LONG(_3$$4, 0);
		ZEPHIR_CALL_METHOD(&min, this_ptr, "get", NULL, 0, _3$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_4$$5);
		ZVAL_STRING(_4$$5, "min", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&min, this_ptr, "get", NULL, 0, _4$$5);
		zephir_check_temp_parameter(_4$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_INIT_VAR(_6$$6);
		ZVAL_LONG(_6$$6, 1);
		ZEPHIR_CALL_METHOD(&max, this_ptr, "get", NULL, 0, _6$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_7$$7);
		ZVAL_STRING(_7$$7, "max", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&max, this_ptr, "get", NULL, 0, _7$$7);
		zephir_check_temp_parameter(_7$$7);
		zephir_check_call_status();
	}
	_8 = ZEPHIR_LT(value, min);
	if (!(_8)) {
		_8 = ZEPHIR_GT(value, max);
	}
	if (_8) {
		ZEPHIR_INIT_VAR(_10$$8);
		ZVAL_STRING(_10$$8, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "has", NULL, 0, _10$$8);
		zephir_check_temp_parameter(_10$$8);
		zephir_check_call_status();
		if (zephir_is_true(_9$$8)) {
			ZEPHIR_INIT_VAR(_11$$9);
			ZVAL_STRING(_11$$9, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _11$$9);
			zephir_check_temp_parameter(_11$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_10$$8);
		ZVAL_STRING(_10$$8, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "has", NULL, 0, _10$$8);
		zephir_check_temp_parameter(_10$$8);
		zephir_check_call_status();
		if (zephir_is_true(_12$$8)) {
			ZEPHIR_INIT_VAR(_13$$11);
			ZVAL_STRING(_13$$11, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _13$$11);
			zephir_check_temp_parameter(_13$$11);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_14$$12);
			ZVAL_STRING(_14$$12, "between", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _14$$12);
			zephir_check_temp_parameter(_14$$12);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_15$$8, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_16$$8 = ZEPHIR_IS_TRUE_IDENTICAL(_15$$8);
		if (_16$$8) {
			ZEPHIR_CALL_METHOD(&_17$$8, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_10$$8);
			ZVAL_STRING(_10$$8, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_18$$8, _17$$8, "has", NULL, 0, _10$$8);
			zephir_check_temp_parameter(_10$$8);
			zephir_check_call_status();
			_16$$8 = zephir_is_true(_18$$8);
		}
		if (_16$$8) {
			ZEPHIR_CALL_METHOD(&_19$$13, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_20$$13);
			ZVAL_STRING(_20$$13, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _19$$13, "get", NULL, 0, _20$$13);
			zephir_check_temp_parameter(_20$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$13, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _21$$13);
			ZEPHIR_CALL_METHOD(&_21$$13, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _21$$13);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":min"), &min, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":max"), &max, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_22$$8, "strtr", NULL, 116, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _22$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

