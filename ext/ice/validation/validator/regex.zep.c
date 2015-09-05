
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
 * @copyright   (c) 2014-2015 Ice Team
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
 * Options: label, pattern, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Regex, validate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool failed, _0, _8;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace, *pattern = NULL, *matches, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL;

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
	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
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
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_CALL_METHOD(&pattern, this_ptr, "get", NULL, 0, _2);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "pattern", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&pattern, this_ptr, "get", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	zephir_preg_match(_2, pattern, value, matches, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_2)) {
		zephir_array_fetch_long(&_3, matches, 0, PH_NOISY | PH_READONLY, "ice/validation/validator/regex.zep", 63 TSRMLS_CC);
		failed = !ZEPHIR_IS_EQUAL(_3, value);
	} else {
		failed = 1;
	}
	if (failed) {
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "has", NULL, 0, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		if (zephir_is_true(_4)) {
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _5);
			zephir_check_temp_parameter(_5);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "has", NULL, 0, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _5);
			zephir_check_temp_parameter(_5);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "regex", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _5);
			zephir_check_temp_parameter(_5);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_7, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_8 = ZEPHIR_IS_TRUE_IDENTICAL(_7);
		if (_8) {
			ZEPHIR_CALL_METHOD(&_9, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_10, _9, "has", NULL, 0, _5);
			zephir_check_temp_parameter(_5);
			zephir_check_call_status();
			_8 = zephir_is_true(_10);
		}
		if (_8) {
			ZEPHIR_CALL_METHOD(&_11, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _11, "get", NULL, 0, _5);
			zephir_check_temp_parameter(_5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_12, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _12);
			ZEPHIR_CALL_METHOD(&_12, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _12);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_11, "strtr", NULL, 85, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

