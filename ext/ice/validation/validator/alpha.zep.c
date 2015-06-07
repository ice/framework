
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
 * @copyright   (c) 2014-2015 Ice Team
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
 * <code><pre>
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Alpha) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Alpha, ice, validation_validator_alpha, ice_validation_validator_ce, ice_validation_validator_alpha_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Alpha, validate) {

	zend_bool _0, _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL;

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
	_0 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
	if (!(_0)) {
		_0 = Z_TYPE_P(value) == IS_NULL;
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_FUNCTION(&_1, "ctype_alpha", NULL, 158, value);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "has", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "has", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (zephir_is_true(_4)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "alpha", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_5, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_6 = ZEPHIR_IS_TRUE_IDENTICAL(_5);
		if (_6) {
			ZEPHIR_CALL_METHOD(&_7, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_8, _7, "has", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			_6 = zephir_is_true(_8);
		}
		if (_6) {
			ZEPHIR_CALL_METHOD(&_9, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _9, "get", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_10, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _10);
			ZEPHIR_CALL_METHOD(&_10, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _10);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_9, "strtr", NULL, 67, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

