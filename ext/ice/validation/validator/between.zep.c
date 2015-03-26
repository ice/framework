
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
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Between) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Between, ice, validation_validator_between, ice_validation_validator_ce, ice_validation_validator_between_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Between, validate) {

	zephir_nts_static zephir_fcall_cache_entry *_13 = NULL;
	zend_bool _0, _4, _8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace, *min = NULL, *max = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL;

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


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, field);
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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "has", NULL, _2);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_CALL_METHOD(&min, this_ptr, "get", NULL, _2);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "min", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&min, this_ptr, "get", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "has", NULL, _2);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 1);
		ZEPHIR_CALL_METHOD(&max, this_ptr, "get", NULL, _2);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "max", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&max, this_ptr, "get", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	_4 = ZEPHIR_LT(value, min);
	if (!(_4)) {
		_4 = ZEPHIR_GT(value, max);
	}
	if (_4) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "has", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "has", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "between", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_7, validation, "gettranslate", NULL);
		zephir_check_call_status();
		_8 = ZEPHIR_IS_TRUE_IDENTICAL(_7);
		if (_8) {
			ZEPHIR_CALL_METHOD(&_9, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_10, _9, "has", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			_8 = zephir_is_true(_10);
		}
		if (_8) {
			ZEPHIR_CALL_METHOD(&_11, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _11, "get", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_12, i18n, "translate", NULL, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _12);
			ZEPHIR_CALL_METHOD(&_12, i18n, "translate", NULL, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _12);
		}
		ZEPHIR_INIT_VAR(replace);
		array_init_size(replace, 4);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":min"), &min, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":max"), &max, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_11, "strtr", &_13, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

