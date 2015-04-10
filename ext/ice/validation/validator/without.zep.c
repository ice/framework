
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
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Without validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Without) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Without, ice, validation_validator_without, ice_validation_validator_ce, ice_validation_validator_without_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Without, validate) {

	zephir_nts_static zephir_fcall_cache_entry *_14 = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_3;
	HashPosition _2;
	zend_bool _0, _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace, *fields = NULL, *without = NULL, *tmp = NULL, *except, *_1 = NULL, **_4, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL;

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
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "getoptions", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(except);
	array_init(except);
	if (ZEPHIR_IS_EMPTY(fields)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "fields", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&fields, this_ptr, "get", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(fields) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Fields must be an array", "ice/validation/validator/without.zep", 45);
		return;
	}
	zephir_is_iterable(fields, &_3, &_2, 0, 0, "ice/validation/validator/without.zep", 56);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(without, _4);
		ZEPHIR_CALL_METHOD(&tmp, validation, "getvalue", &_5, without);
		zephir_check_call_status();
		_6 = !ZEPHIR_IS_STRING_IDENTICAL(tmp, "");
		if (_6) {
			_6 = Z_TYPE_P(tmp) != IS_NULL;
		}
		if (_6) {
			zephir_array_append(&except, without, PH_SEPARATE, "ice/validation/validator/without.zep", 52);
		}
	}
	if (zephir_fast_count_int(except TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "has", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_7)) {
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
			ZVAL_STRING(_1, "without", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_9, validation, "gettranslate", NULL);
		zephir_check_call_status();
		_6 = ZEPHIR_IS_TRUE_IDENTICAL(_9);
		if (_6) {
			ZEPHIR_CALL_METHOD(&_10, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_11, _10, "has", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			_6 = zephir_is_true(_11);
		}
		if (_6) {
			ZEPHIR_CALL_METHOD(&_12, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _12, "get", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_13, i18n, "translate", NULL, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _13);
			ZEPHIR_CALL_METHOD(&_13, i18n, "translate", NULL, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _13);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_1);
		zephir_fast_join_str(_1, SL(", "), except TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":fields"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_12, "strtr", &_14, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _12);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

