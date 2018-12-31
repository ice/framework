
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

	zend_bool failed = 0, _0, _13$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace = NULL, *pattern = NULL, *matches = NULL, *_1 = NULL, *_2 = NULL, *_3$$4, *_4$$5, *_5$$6, *_6$$8 = NULL, *_7$$8 = NULL, *_9$$8 = NULL, *_12$$8 = NULL, *_14$$8 = NULL, *_15$$8 = NULL, *_19$$8 = NULL, *_8$$9, *_10$$11, *_11$$12, *_16$$13 = NULL, *_17$$13, *_18$$13 = NULL;

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
	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
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
		ZEPHIR_CALL_METHOD(&pattern, this_ptr, "get", NULL, 0, _3$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_4$$5);
		ZVAL_STRING(_4$$5, "pattern", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&pattern, this_ptr, "get", NULL, 0, _4$$5);
		zephir_check_temp_parameter(_4$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	zephir_preg_match(_2, pattern, value, matches, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_2)) {
		zephir_array_fetch_long(&_5$$6, matches, 0, PH_NOISY | PH_READONLY, "ice/validation/validator/regex.zep", 63 TSRMLS_CC);
		failed = !ZEPHIR_IS_EQUAL(_5$$6, value);
	} else {
		failed = 1;
	}
	if (failed) {
		ZEPHIR_INIT_VAR(_7$$8);
		ZVAL_STRING(_7$$8, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_6$$8, this_ptr, "has", NULL, 0, _7$$8);
		zephir_check_temp_parameter(_7$$8);
		zephir_check_call_status();
		if (zephir_is_true(_6$$8)) {
			ZEPHIR_INIT_VAR(_8$$9);
			ZVAL_STRING(_8$$9, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _8$$9);
			zephir_check_temp_parameter(_8$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_7$$8);
		ZVAL_STRING(_7$$8, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "has", NULL, 0, _7$$8);
		zephir_check_temp_parameter(_7$$8);
		zephir_check_call_status();
		if (zephir_is_true(_9$$8)) {
			ZEPHIR_INIT_VAR(_10$$11);
			ZVAL_STRING(_10$$11, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _10$$11);
			zephir_check_temp_parameter(_10$$11);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_11$$12);
			ZVAL_STRING(_11$$12, "regex", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _11$$12);
			zephir_check_temp_parameter(_11$$12);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_12$$8, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_13$$8 = ZEPHIR_IS_TRUE_IDENTICAL(_12$$8);
		if (_13$$8) {
			ZEPHIR_CALL_METHOD(&_14$$8, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_7$$8);
			ZVAL_STRING(_7$$8, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_15$$8, _14$$8, "has", NULL, 0, _7$$8);
			zephir_check_temp_parameter(_7$$8);
			zephir_check_call_status();
			_13$$8 = zephir_is_true(_15$$8);
		}
		if (_13$$8) {
			ZEPHIR_CALL_METHOD(&_16$$13, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_17$$13);
			ZVAL_STRING(_17$$13, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _16$$13, "get", NULL, 0, _17$$13);
			zephir_check_temp_parameter(_17$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_18$$13, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _18$$13);
			ZEPHIR_CALL_METHOD(&_18$$13, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _18$$13);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_19$$8, "strtr", NULL, 116, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _19$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

