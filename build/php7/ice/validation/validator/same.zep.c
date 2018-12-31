
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Same validator.
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
 *      'email' => 'required|email',
 *      'repeatEmail' => 'same:email'
 *  ]);
 *  
 *  $valid = $validation->validate($_POST);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Same) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Same, ice, validation_validator_same, ice_validation_validator_ce, ice_validation_validator_same_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 * Options: other (0), allowEmpty (1), label, labelOther, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Same, validate) {

	zend_bool _4, _5, _19$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, allowEmpty, label, message, i18n, replace, other, valueOther, labelOther, _0, _1, _6, _9, _2$$3, _3$$4, _7$$6, _8$$7, _10$$10, _11$$10, _13$$10, _15$$10, _18$$10, _20$$10, _21$$10, _25$$10, _12$$11, _14$$13, _16$$15, _17$$16, _22$$17, _23$$17, _24$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&allowEmpty);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&other);
	ZVAL_UNDEF(&valueOther);
	ZVAL_UNDEF(&labelOther);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$17);
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
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZVAL_LONG(&_2$$3, 1);
		ZEPHIR_CALL_METHOD(&allowEmpty, this_ptr, "get", NULL, 0, &_2$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "allowEmpty");
		ZEPHIR_CALL_METHOD(&allowEmpty, this_ptr, "get", NULL, 0, &_3$$4);
		zephir_check_call_status();
	}
	_4 = zephir_is_true(&allowEmpty);
	if (_4) {
		_5 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
		if (!(_5)) {
			_5 = Z_TYPE_P(&value) == IS_NULL;
		}
		_4 = _5;
	}
	if (_4) {
		RETURN_MM_BOOL(1);
	}
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		ZVAL_LONG(&_7$$6, 0);
		ZEPHIR_CALL_METHOD(&other, this_ptr, "get", NULL, 0, &_7$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_8$$7);
		ZVAL_STRING(&_8$$7, "other");
		ZEPHIR_CALL_METHOD(&other, this_ptr, "get", NULL, 0, &_8$$7);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_9, validation, "hasvalue", NULL, 0, &other);
	zephir_check_call_status();
	if (zephir_is_true(&_9)) {
		ZEPHIR_CALL_METHOD(&valueOther, validation, "getvalue", NULL, 0, &other);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&valueOther, &other);
	}
	if (!ZEPHIR_IS_EQUAL(&value, &valueOther)) {
		ZEPHIR_INIT_VAR(&_11$$10);
		ZVAL_STRING(&_11$$10, "label");
		ZEPHIR_CALL_METHOD(&_10$$10, this_ptr, "has", NULL, 0, &_11$$10);
		zephir_check_call_status();
		if (zephir_is_true(&_10$$10)) {
			ZEPHIR_INIT_VAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_12$$11);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_11$$10);
		ZVAL_STRING(&_11$$10, "labelOther");
		ZEPHIR_CALL_METHOD(&_13$$10, this_ptr, "has", NULL, 0, &_11$$10);
		zephir_check_call_status();
		if (zephir_is_true(&_13$$10)) {
			ZEPHIR_INIT_VAR(&_14$$13);
			ZVAL_STRING(&_14$$13, "labelOther");
			ZEPHIR_CALL_METHOD(&labelOther, this_ptr, "get", NULL, 0, &_14$$13);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&labelOther, validation, "getlabel", NULL, 0, &other);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_11$$10);
		ZVAL_STRING(&_11$$10, "message");
		ZEPHIR_CALL_METHOD(&_15$$10, this_ptr, "has", NULL, 0, &_11$$10);
		zephir_check_call_status();
		if (zephir_is_true(&_15$$10)) {
			ZEPHIR_INIT_VAR(&_16$$15);
			ZVAL_STRING(&_16$$15, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_16$$15);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_17$$16);
			ZVAL_STRING(&_17$$16, "same");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_17$$16);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_18$$10, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_19$$10 = ZEPHIR_IS_TRUE_IDENTICAL(&_18$$10);
		if (_19$$10) {
			ZEPHIR_CALL_METHOD(&_20$$10, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_11$$10);
			ZVAL_STRING(&_11$$10, "i18n");
			ZEPHIR_CALL_METHOD(&_21$$10, &_20$$10, "has", NULL, 0, &_11$$10);
			zephir_check_call_status();
			_19$$10 = zephir_is_true(&_21$$10);
		}
		if (_19$$10) {
			ZEPHIR_CALL_METHOD(&_22$$17, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_23$$17);
			ZVAL_STRING(&_23$$17, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_22$$17, "get", NULL, 0, &_23$$17);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_24$$17, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_24$$17);
			ZEPHIR_CALL_METHOD(&_24$$17, &i18n, "translate", NULL, 0, &labelOther);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&labelOther, &_24$$17);
			ZEPHIR_CALL_METHOD(&_24$$17, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_24$$17);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":other"), &labelOther, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_25$$10, "strtr", NULL, 103, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_25$$10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

