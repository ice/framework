
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
 * Alpha validator.
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
 *      'username' => 'alpha',
 *      'prefix' => [
 *          'alpha' => [
 *              'message' => 'Field :field must be alpha'
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Alpha) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Alpha, ice, validation_validator_alpha, ice_validation_validator_ce, ice_validation_validator_alpha_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 * Options: label, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Alpha, validate) {

	zend_bool _0, _9$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, label, message, i18n, replace, _1, _2$$4, _3$$4, _5$$4, _8$$4, _10$$4, _11$$4, _15$$4, _4$$5, _6$$7, _7$$8, _12$$9, _13$$9, _14$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
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
	ZEPHIR_CALL_FUNCTION(&_1, "ctype_alpha", NULL, 193, &value);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "label");
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "has", NULL, 0, &_3$$4);
		zephir_check_call_status();
		if (zephir_is_true(&_2$$4)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_4$$5);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "message");
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "has", NULL, 0, &_3$$4);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$4)) {
			ZEPHIR_INIT_VAR(&_6$$7);
			ZVAL_STRING(&_6$$7, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_6$$7);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_7$$8);
			ZVAL_STRING(&_7$$8, "alpha");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_7$$8);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_8$$4, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_9$$4 = ZEPHIR_IS_TRUE_IDENTICAL(&_8$$4);
		if (_9$$4) {
			ZEPHIR_CALL_METHOD(&_10$$4, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "i18n");
			ZEPHIR_CALL_METHOD(&_11$$4, &_10$$4, "has", NULL, 0, &_3$$4);
			zephir_check_call_status();
			_9$$4 = zephir_is_true(&_11$$4);
		}
		if (_9$$4) {
			ZEPHIR_CALL_METHOD(&_12$$9, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_13$$9);
			ZVAL_STRING(&_13$$9, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_12$$9, "get", NULL, 0, &_13$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_14$$9, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_14$$9);
			ZEPHIR_CALL_METHOD(&_14$$9, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_14$$9);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_15$$4, "strtr", NULL, 103, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_15$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

