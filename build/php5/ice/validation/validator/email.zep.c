
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
 * Email validator.
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
 *      'e_mail' => 'email'
 *  ]);
 *  
 *  $valid = $validation->validate($_POST);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Email) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Email, ice, validation_validator_email, ice_validation_validator_ce, ice_validation_validator_email_method_entry, 0);

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
PHP_METHOD(Ice_Validation_Validator_Email, validate) {

	zend_bool _0, _10$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace = NULL, _1, *_2 = NULL, *_3$$4 = NULL, *_4$$4 = NULL, *_6$$4 = NULL, *_9$$4 = NULL, *_11$$4 = NULL, *_12$$4 = NULL, *_16$$4 = NULL, *_5$$5, *_7$$7, *_8$$8, *_13$$9 = NULL, *_14$$9, *_15$$9 = NULL;

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
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 274);
	ZEPHIR_CALL_FUNCTION(&_2, "filter_var", NULL, 136, value, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_STRING(_4$$4, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "has", NULL, 0, _4$$4);
		zephir_check_temp_parameter(_4$$4);
		zephir_check_call_status();
		if (zephir_is_true(_3$$4)) {
			ZEPHIR_INIT_VAR(_5$$5);
			ZVAL_STRING(_5$$5, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _5$$5);
			zephir_check_temp_parameter(_5$$5);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_4$$4);
		ZVAL_STRING(_4$$4, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "has", NULL, 0, _4$$4);
		zephir_check_temp_parameter(_4$$4);
		zephir_check_call_status();
		if (zephir_is_true(_6$$4)) {
			ZEPHIR_INIT_VAR(_7$$7);
			ZVAL_STRING(_7$$7, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _7$$7);
			zephir_check_temp_parameter(_7$$7);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_8$$8);
			ZVAL_STRING(_8$$8, "email", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _8$$8);
			zephir_check_temp_parameter(_8$$8);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_9$$4, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_10$$4 = ZEPHIR_IS_TRUE_IDENTICAL(_9$$4);
		if (_10$$4) {
			ZEPHIR_CALL_METHOD(&_11$$4, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_12$$4, _11$$4, "has", NULL, 0, _4$$4);
			zephir_check_temp_parameter(_4$$4);
			zephir_check_call_status();
			_10$$4 = zephir_is_true(_12$$4);
		}
		if (_10$$4) {
			ZEPHIR_CALL_METHOD(&_13$$9, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_14$$9);
			ZVAL_STRING(_14$$9, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _13$$9, "get", NULL, 0, _14$$9);
			zephir_check_temp_parameter(_14$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_15$$9, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _15$$9);
			ZEPHIR_CALL_METHOD(&_15$$9, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _15$$9);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_16$$4, "strtr", NULL, 116, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _16$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

