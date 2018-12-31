
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
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Length validator.
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
 *      'title' => 'length:10,100',
 *      'content' => [
 *          'length' => [
 *              'max' => 1000,
 *              'messageMin' => 'Too long!',
 *              'label' => 'Desctiption'
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Length) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Length, ice, validation_validator_length, ice_validation_validator_ce, ice_validation_validator_length_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 * Options: min (0), max (1), label, messageMin, messageMax
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Length, validate) {

	zend_bool _0, _11, _25, _17$$12, _31$$16;
	zephir_fcall_cache_entry *_24 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, label, message, i18n, replace, min, max, length, _1, _2, _5, _8, _9, _3$$4, _4$$5, _6$$6, _7$$7, _10$$10, _12$$12, _13$$12, _16$$12, _18$$12, _19$$12, _23$$12, _14$$13, _15$$14, _20$$15, _21$$15, _22$$15, _26$$16, _27$$16, _30$$16, _32$$16, _33$$16, _37$$16, _28$$17, _29$$18, _34$$19, _35$$19, _36$$19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&min);
	ZVAL_UNDEF(&max);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_34$$19);
	ZVAL_UNDEF(&_35$$19);
	ZVAL_UNDEF(&_36$$19);
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
	if ((zephir_function_exists_ex(SL("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 200, &value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&length);
		ZVAL_LONG(&length, zephir_fast_strlen_ev(&value));
	}
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "label");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "has", NULL, 0, &_9);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		ZEPHIR_INIT_VAR(&_10$$10);
		ZVAL_STRING(&_10$$10, "label");
		ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_10$$10);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
		zephir_check_call_status();
	}
	_11 = zephir_is_true(&min);
	if (_11) {
		_11 = ZEPHIR_LT(&length, &min);
	}
	if (_11) {
		ZEPHIR_INIT_VAR(&_13$$12);
		ZVAL_STRING(&_13$$12, "messageMin");
		ZEPHIR_CALL_METHOD(&_12$$12, this_ptr, "has", NULL, 0, &_13$$12);
		zephir_check_call_status();
		if (zephir_is_true(&_12$$12)) {
			ZEPHIR_INIT_VAR(&_14$$13);
			ZVAL_STRING(&_14$$13, "messageMin");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_14$$13);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_15$$14);
			ZVAL_STRING(&_15$$14, "lengthMin");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_15$$14);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_16$$12, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_17$$12 = ZEPHIR_IS_TRUE_IDENTICAL(&_16$$12);
		if (_17$$12) {
			ZEPHIR_CALL_METHOD(&_18$$12, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_13$$12);
			ZVAL_STRING(&_13$$12, "i18n");
			ZEPHIR_CALL_METHOD(&_19$$12, &_18$$12, "has", NULL, 0, &_13$$12);
			zephir_check_call_status();
			_17$$12 = zephir_is_true(&_19$$12);
		}
		if (_17$$12) {
			ZEPHIR_CALL_METHOD(&_20$$15, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_21$$15);
			ZVAL_STRING(&_21$$15, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_20$$15, "get", NULL, 0, &_21$$15);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_22$$15, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_22$$15);
			ZEPHIR_CALL_METHOD(&_22$$15, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_22$$15);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":min"), &min, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_23$$12, "strtr", &_24, 103, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_23$$12);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_25 = zephir_is_true(&max);
	if (_25) {
		_25 = ZEPHIR_GT(&length, &max);
	}
	if (_25) {
		ZEPHIR_INIT_VAR(&_27$$16);
		ZVAL_STRING(&_27$$16, "messageMax");
		ZEPHIR_CALL_METHOD(&_26$$16, this_ptr, "has", NULL, 0, &_27$$16);
		zephir_check_call_status();
		if (zephir_is_true(&_26$$16)) {
			ZEPHIR_INIT_VAR(&_28$$17);
			ZVAL_STRING(&_28$$17, "messageMax");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_28$$17);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_29$$18);
			ZVAL_STRING(&_29$$18, "lengthMax");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_29$$18);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_30$$16, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_31$$16 = ZEPHIR_IS_TRUE_IDENTICAL(&_30$$16);
		if (_31$$16) {
			ZEPHIR_CALL_METHOD(&_32$$16, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_27$$16);
			ZVAL_STRING(&_27$$16, "i18n");
			ZEPHIR_CALL_METHOD(&_33$$16, &_32$$16, "has", NULL, 0, &_27$$16);
			zephir_check_call_status();
			_31$$16 = zephir_is_true(&_33$$16);
		}
		if (_31$$16) {
			ZEPHIR_CALL_METHOD(&_34$$19, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_35$$19);
			ZVAL_STRING(&_35$$19, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_34$$19, "get", NULL, 0, &_35$$19);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_36$$19, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_36$$19);
			ZEPHIR_CALL_METHOD(&_36$$19, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_36$$19);
		}
		ZEPHIR_INIT_NVAR(&replace);
		zephir_create_array(&replace, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":max"), &max, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_37$$16, "strtr", &_24, 103, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_37$$16);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

