
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Email) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Email, ice, validation_validator_email, ice_validation_validator_ce, ice_validation_validator_email_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Ice_Validation_Validator_Email, validate) {

	zephir_nts_static zephir_fcall_cache_entry *_12 = NULL;
	zend_bool _0, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace, _1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL;

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


	if (!(zephir_instance_of_ev(validation, ice_validation_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'validation' must be an instance of 'Ice\\Validation'", "", 0);
		return;
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
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 274);
	ZEPHIR_CALL_FUNCTION(&_2, "filter_var", NULL, value, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "has", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, _4);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "has", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _4);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "email", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _4);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_6, validation, "gettranslate", NULL);
		zephir_check_call_status();
		_7 = ZEPHIR_IS_TRUE_IDENTICAL(_6);
		if (_7) {
			ZEPHIR_CALL_METHOD(&_8, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_9, _8, "has", NULL, _4);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			_7 = zephir_is_true(_9);
		}
		if (_7) {
			ZEPHIR_CALL_METHOD(&_10, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _10, "get", NULL, _4);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_11, i18n, "translate", NULL, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _11);
			ZEPHIR_CALL_METHOD(&_11, i18n, "translate", NULL, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _11);
		}
		ZEPHIR_INIT_VAR(replace);
		array_init_size(replace, 2);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_10, "strtr", &_12, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

