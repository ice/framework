
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
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Same) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Same, ice, validation_validator_same, ice_validation_validator_ce, ice_validation_validator_same_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Same, validate) {

	zephir_nts_static zephir_fcall_cache_entry *_15 = NULL;
	zend_bool _2, _3, _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *allowEmpty = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace, *other = NULL, *valueOther = NULL, *labelOther = NULL, *_0 = NULL, *_1 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL;

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
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, _1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 1);
		ZEPHIR_CALL_METHOD(&allowEmpty, this_ptr, "get", NULL, _1);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&allowEmpty, this_ptr, "get", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	_2 = zephir_is_true(allowEmpty);
	if (_2) {
		_3 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
		if (!(_3)) {
			_3 = Z_TYPE_P(value) == IS_NULL;
		}
		_2 = _3;
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "has", NULL, _1);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
		ZEPHIR_CALL_METHOD(&other, this_ptr, "get", NULL, _1);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "other", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&other, this_ptr, "get", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_5, validation, "hasvalue", NULL, other);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_CALL_METHOD(&valueOther, validation, "getvalue", NULL, other);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(valueOther, other);
	}
	if (!ZEPHIR_IS_EQUAL(value, valueOther)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "has", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "labelOther", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "has", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_7)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "labelOther", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&labelOther, this_ptr, "get", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&labelOther, validation, "getlabel", NULL, other);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "has", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_8)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "same", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_9, validation, "gettranslate", NULL);
		zephir_check_call_status();
		_10 = ZEPHIR_IS_TRUE_IDENTICAL(_9);
		if (_10) {
			ZEPHIR_CALL_METHOD(&_11, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_12, _11, "has", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			_10 = zephir_is_true(_12);
		}
		if (_10) {
			ZEPHIR_CALL_METHOD(&_13, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _13, "get", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_14, i18n, "translate", NULL, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _14);
			ZEPHIR_CALL_METHOD(&_14, i18n, "translate", NULL, labelOther);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(labelOther, _14);
			ZEPHIR_CALL_METHOD(&_14, i18n, "translate", NULL, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _14);
		}
		ZEPHIR_INIT_VAR(replace);
		array_init_size(replace, 3);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":other"), &labelOther, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_13, "strtr", &_15, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _13);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

