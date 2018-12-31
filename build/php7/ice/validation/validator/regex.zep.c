
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Regex validator.
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
 *      'username' => [
 *          'regex' => [
 *              'pattern' => '/[a-zA-Z][a-zA-Z0-9_-]{3,}/'
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Regex) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Regex, ice, validation_validator_regex, ice_validation_validator_ce, ice_validation_validator_regex_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 * Options: pattern (0), label, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Regex, validate) {

	zend_bool failed = 0, _0, _14$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, label, message, i18n, replace, pattern, matches, _1, _2, _5, _3$$4, _4$$5, _6$$6, _7$$8, _8$$8, _10$$8, _13$$8, _15$$8, _16$$8, _20$$8, _9$$9, _11$$11, _12$$12, _17$$13, _18$$13, _19$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
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
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
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
		ZEPHIR_CALL_METHOD(&pattern, this_ptr, "get", NULL, 0, &_3$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "pattern");
		ZEPHIR_CALL_METHOD(&pattern, this_ptr, "get", NULL, 0, &_4$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_preg_match(&_5, &pattern, &value, &matches, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_5)) {
		zephir_array_fetch_long(&_6$$6, &matches, 0, PH_NOISY | PH_READONLY, "ice/validation/validator/regex.zep", 63 TSRMLS_CC);
		failed = !ZEPHIR_IS_EQUAL(&_6$$6, &value);
	} else {
		failed = 1;
	}
	if (failed) {
		ZEPHIR_INIT_VAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "label");
		ZEPHIR_CALL_METHOD(&_7$$8, this_ptr, "has", NULL, 0, &_8$$8);
		zephir_check_call_status();
		if (zephir_is_true(&_7$$8)) {
			ZEPHIR_INIT_VAR(&_9$$9);
			ZVAL_STRING(&_9$$9, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_9$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "message");
		ZEPHIR_CALL_METHOD(&_10$$8, this_ptr, "has", NULL, 0, &_8$$8);
		zephir_check_call_status();
		if (zephir_is_true(&_10$$8)) {
			ZEPHIR_INIT_VAR(&_11$$11);
			ZVAL_STRING(&_11$$11, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_11$$11);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_12$$12);
			ZVAL_STRING(&_12$$12, "regex");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_12$$12);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_13$$8, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_14$$8 = ZEPHIR_IS_TRUE_IDENTICAL(&_13$$8);
		if (_14$$8) {
			ZEPHIR_CALL_METHOD(&_15$$8, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$8);
			ZVAL_STRING(&_8$$8, "i18n");
			ZEPHIR_CALL_METHOD(&_16$$8, &_15$$8, "has", NULL, 0, &_8$$8);
			zephir_check_call_status();
			_14$$8 = zephir_is_true(&_16$$8);
		}
		if (_14$$8) {
			ZEPHIR_CALL_METHOD(&_17$$13, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_18$$13);
			ZVAL_STRING(&_18$$13, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_17$$13, "get", NULL, 0, &_18$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_19$$13, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_19$$13);
			ZEPHIR_CALL_METHOD(&_19$$13, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_19$$13);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_20$$8, "strtr", NULL, 103, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_20$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

