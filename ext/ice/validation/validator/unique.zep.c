
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


ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Unique) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Unique, ice, validation_validator_unique, ice_validation_validator_ce, ice_validation_validator_unique_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Ice_Validation_Validator_Unique, validate) {

	zval *_6 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_15 = NULL;
	zend_bool _0, _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace, *di = NULL, *db = NULL, *from = NULL, *custom = NULL, *except = NULL, *result = NULL, *id, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL;

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
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&db, di, "getdb", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "has", NULL, _3);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, _3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "from", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 1);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "has", NULL, _3);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 1);
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, _3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "custom", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(custom)) {
		ZEPHIR_CPY_WRT(custom, field);
	}
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 2);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "has", NULL, _3);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 2);
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, _3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "except", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
	}
	if (zephir_is_true(except)) {
		ZEPHIR_INIT_VAR(id);
		array_init_size(id, 2);
		zephir_array_update_string(&id, SL("!="), &except, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_6);
		array_init_size(_6, 3);
		zephir_array_update_zval(&_6, custom, &value, PH_COPY);
		zephir_array_update_string(&_6, SL("id"), &id, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&result, db, "findone", NULL, from, _6);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_6);
		array_init_size(_6, 2);
		zephir_array_update_zval(&_6, custom, &value, PH_COPY);
		ZEPHIR_CALL_METHOD(&result, db, "findone", NULL, from, _6);
		zephir_check_call_status();
	}
	if (zephir_is_true(result)) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "has", NULL, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (zephir_is_true(_7)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "has", NULL, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (zephir_is_true(_8)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "unique", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_9, validation, "gettranslate", NULL);
		zephir_check_call_status();
		_10 = ZEPHIR_IS_TRUE_IDENTICAL(_9);
		if (_10) {
			ZEPHIR_CALL_METHOD(&_11, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_12, _11, "has", NULL, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			_10 = zephir_is_true(_12);
		}
		if (_10) {
			ZEPHIR_CALL_METHOD(&_13, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _13, "get", NULL, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_14, i18n, "translate", NULL, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _14);
			ZEPHIR_CALL_METHOD(&_14, i18n, "translate", NULL, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _14);
		}
		ZEPHIR_INIT_VAR(replace);
		array_init_size(replace, 2);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_13, "strtr", &_15, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _13);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

