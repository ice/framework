
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
 * Required validator.
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
 *      'username' => 'required'
 *  ]);
 *  
 *  $valid = $validation->validate($_POST);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Required) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Required, ice, validation_validator_required, ice_validation_validator_ce, ice_validation_validator_required_method_entry, 0);

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
PHP_METHOD(Ice_Validation_Validator_Required, validate) {

	zend_bool _0, _8$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace = NULL, *_1$$3 = NULL, *_2$$3 = NULL, *_4$$3 = NULL, *_7$$3 = NULL, *_9$$3 = NULL, *_10$$3 = NULL, *_14$$3 = NULL, *_3$$4, *_5$$6, *_6$$7, *_11$$8 = NULL, *_12$$8, *_13$$8 = NULL;

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
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "has", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(_1$$3)) {
			ZEPHIR_INIT_VAR(_3$$4);
			ZVAL_STRING(_3$$4, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _3$$4);
			zephir_check_temp_parameter(_3$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_STRING(_2$$3, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "has", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(_4$$3)) {
			ZEPHIR_INIT_VAR(_5$$6);
			ZVAL_STRING(_5$$6, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _5$$6);
			zephir_check_temp_parameter(_5$$6);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_6$$7);
			ZVAL_STRING(_6$$7, "required", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _6$$7);
			zephir_check_temp_parameter(_6$$7);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_7$$3, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_8$$3 = ZEPHIR_IS_TRUE_IDENTICAL(_7$$3);
		if (_8$$3) {
			ZEPHIR_CALL_METHOD(&_9$$3, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_10$$3, _9$$3, "has", NULL, 0, _2$$3);
			zephir_check_temp_parameter(_2$$3);
			zephir_check_call_status();
			_8$$3 = zephir_is_true(_10$$3);
		}
		if (_8$$3) {
			ZEPHIR_CALL_METHOD(&_11$$8, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_12$$8);
			ZVAL_STRING(_12$$8, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _11$$8, "get", NULL, 0, _12$$8);
			zephir_check_temp_parameter(_12$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_13$$8, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _13$$8);
			ZEPHIR_CALL_METHOD(&_13$$8, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _13$$8);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_14$$3, "strtr", NULL, 116, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _14$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

