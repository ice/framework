
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * File validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_File) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, File, ice, validation_validator_file, ice_validation_validator_ce, ice_validation_validator_file_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_File, validate) {

	zephir_nts_static zephir_fcall_cache_entry *_17 = NULL, *_25 = NULL, *_31 = NULL, *_33 = NULL, *_36 = NULL, *_41 = NULL;
	zend_bool _3, _4, _5, _7, _8, _12, _18, _19, _21, _23, _26, _28, _43, _44;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *i18n = NULL, *replace = NULL, *types = NULL, *byteUnits, *unit = NULL, *maxSize = NULL, *matches, *bytes, *mime = NULL, *tmp = NULL, *width, *height, *minResolution, *maxResolution, *minWidth = NULL, *maxWidth, *minHeight = NULL, *maxHeight, *_0 = NULL, *_1 = NULL, *_SERVER, *_2, *_POST, *_FILES, *_6, *_9, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_20, *_22, *_24, *_27 = NULL, *_29 = NULL, *_30, *_32, *_34, _35 = zval_used_for_init, *_37, *_38 = NULL, *_39 = NULL, *_40 = NULL, *_42 = NULL, *_45 = NULL, *_46 = NULL, *_47 = NULL;

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
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, field);
		zephir_check_call_status();
	}
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_array_fetch_string(&_2, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 40 TSRMLS_CC);
	_3 = ZEPHIR_IS_STRING(_2, "POST");
	if (_3) {
		zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
		_3 = ZEPHIR_IS_EMPTY(_POST);
	}
	_4 = _3;
	if (_4) {
		zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
		_4 = ZEPHIR_IS_EMPTY(_FILES);
	}
	_5 = _4;
	if (_5) {
		zephir_array_fetch_string(&_6, _SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 40 TSRMLS_CC);
		_5 = ZEPHIR_GT_LONG(_6, 0);
	}
	_7 = _5;
	if (!(_7)) {
		_8 = zephir_array_isset_string(value, SS("error"));
		if (_8) {
			zephir_array_fetch_string(&_9, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 40 TSRMLS_CC);
			_8 = ZEPHIR_IS_LONG_IDENTICAL(_9, 1);
		}
		_7 = _8;
	}
	if (_7) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "messageIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_10)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "messageIniSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "fileIniSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_11, validation, "gettranslate", NULL);
		zephir_check_call_status();
		_12 = ZEPHIR_IS_TRUE_IDENTICAL(_11);
		if (_12) {
			ZEPHIR_CALL_METHOD(&_13, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_14, _13, "has", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			_12 = zephir_is_true(_14);
		}
		if (_12) {
			ZEPHIR_CALL_METHOD(&_15, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _15, "get", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16, i18n, "translate", NULL, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _16);
			ZEPHIR_CALL_METHOD(&_16, i18n, "translate", NULL, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _16);
		}
		ZEPHIR_INIT_VAR(replace);
		array_init_size(replace, 2);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_15, "strtr", &_17, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _15);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_12 = zephir_is_true(_10);
	if (_12) {
		_18 = ZEPHIR_IS_EMPTY(value);
		if (!(_18)) {
			_19 = zephir_array_isset_string(value, SS("error"));
			if (_19) {
				zephir_array_fetch_string(&_20, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 60 TSRMLS_CC);
				_19 = ZEPHIR_IS_LONG_IDENTICAL(_20, 4);
			}
			_18 = _19;
		}
		_12 = _18;
	}
	if (_12) {
		RETURN_MM_BOOL(1);
	}
	_12 = !(zephir_array_isset_string(value, SS("error")));
	if (!(_12)) {
		_12 = !(zephir_array_isset_string(value, SS("tmp_name")));
	}
	_21 = _12;
	if (!(_21)) {
		zephir_array_fetch_string(&_22, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 64 TSRMLS_CC);
		_21 = !ZEPHIR_IS_LONG_IDENTICAL(_22, 0);
	}
	_23 = _21;
	if (!(_23)) {
		zephir_array_fetch_string(&_24, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 64 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "is_uploaded_file", &_25, _24);
		zephir_check_call_status();
		_23 = !zephir_is_true(_10);
	}
	if (_23) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "messageEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "has", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_11)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "messageEmpty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "fileEmpty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_13, validation, "gettranslate", NULL);
		zephir_check_call_status();
		_26 = ZEPHIR_IS_TRUE_IDENTICAL(_13);
		if (_26) {
			ZEPHIR_CALL_METHOD(&_14, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_15, _14, "has", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			_26 = zephir_is_true(_15);
		}
		if (_26) {
			ZEPHIR_CALL_METHOD(&_16, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _16, "get", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_27, i18n, "translate", NULL, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _27);
			ZEPHIR_CALL_METHOD(&_27, i18n, "translate", NULL, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _27);
		}
		ZEPHIR_INIT_NVAR(replace);
		array_init_size(replace, 2);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_15, "strtr", &_17, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _15);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_12 = !(zephir_array_isset_string(value, SS("name")));
	if (!(_12)) {
		_12 = !(zephir_array_isset_string(value, SS("type")));
	}
	_26 = _12;
	if (!(_26)) {
		_26 = !(zephir_array_isset_string(value, SS("size")));
	}
	if (_26) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "messageValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_10)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "messageValid", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "default", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_11, validation, "gettranslate", NULL);
		zephir_check_call_status();
		_28 = ZEPHIR_IS_TRUE_IDENTICAL(_11);
		if (_28) {
			ZEPHIR_CALL_METHOD(&_13, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_14, _13, "has", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			_28 = zephir_is_true(_14);
		}
		if (_28) {
			ZEPHIR_CALL_METHOD(&_15, validation, "getdi", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _15, "get", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16, i18n, "translate", NULL, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _16);
			ZEPHIR_CALL_METHOD(&_16, i18n, "translate", NULL, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _16);
		}
		ZEPHIR_INIT_NVAR(replace);
		array_init_size(replace, 2);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_15, "strtr", &_17, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _15);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_VAR(byteUnits);
		array_init_size(byteUnits, 12);
		add_assoc_long_ex(byteUnits, SS("B"), 0);
		add_assoc_long_ex(byteUnits, SS("K"), 10);
		add_assoc_long_ex(byteUnits, SS("M"), 20);
		add_assoc_long_ex(byteUnits, SS("G"), 30);
		add_assoc_long_ex(byteUnits, SS("T"), 40);
		add_assoc_long_ex(byteUnits, SS("KB"), 10);
		add_assoc_long_ex(byteUnits, SS("MB"), 20);
		add_assoc_long_ex(byteUnits, SS("GB"), 30);
		add_assoc_long_ex(byteUnits, SS("TB"), 40);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "get", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_VAR(_29);
		zephir_array_keys(_29, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_1, SL("|"), _29 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_30);
		ZEPHIR_CONCAT_SVS(_30, "/^([0-9]+(?:\\.[0-9]+)?)(", _1, ")?$/Di");
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(NULL, "preg_match", &_31, _30, maxSize, matches);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY, "ice/validation/validator/file.zep", 113 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_32, matches, 1, PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 116 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "floatval", &_33, _32);
		zephir_check_call_status();
		zephir_array_fetch(&_34, byteUnits, unit, PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 116 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_35);
		ZVAL_LONG(&_35, 2);
		ZEPHIR_CALL_FUNCTION(&_13, "pow", &_36, &_35, _34);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _11, _13 TSRMLS_CC);
		zephir_array_fetch_string(&_37, value, SL("size"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 118 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "floatval", &_33, _37);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_13, "floatval", &_33, bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(_11, _13)) {
			ZEPHIR_INIT_VAR(_38);
			ZVAL_STRING(_38, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_14, this_ptr, "has", NULL, _38);
			zephir_check_temp_parameter(_38);
			zephir_check_call_status();
			if (zephir_is_true(_14)) {
				ZEPHIR_INIT_NVAR(_38);
				ZVAL_STRING(_38, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _38);
				zephir_check_temp_parameter(_38);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(_38);
				ZVAL_STRING(_38, "fileSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _38);
				zephir_check_temp_parameter(_38);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, validation, "gettranslate", NULL);
			zephir_check_call_status();
			_12 = ZEPHIR_IS_TRUE_IDENTICAL(_15);
			if (_12) {
				ZEPHIR_CALL_METHOD(&_16, validation, "getdi", NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_38);
				ZVAL_STRING(_38, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_27, _16, "has", NULL, _38);
				zephir_check_temp_parameter(_38);
				zephir_check_call_status();
				_12 = zephir_is_true(_27);
			}
			if (_12) {
				ZEPHIR_CALL_METHOD(&_39, validation, "getdi", NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_38);
				ZVAL_STRING(_38, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&i18n, _39, "get", NULL, _38);
				zephir_check_temp_parameter(_38);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_40, i18n, "translate", NULL, label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(label, _40);
				ZEPHIR_CALL_METHOD(&_40, i18n, "translate", NULL, message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(message, _40);
			}
			ZEPHIR_INIT_NVAR(replace);
			array_init_size(replace, 3);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replace, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_39, "strtr", &_17, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _39);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_29);
	ZVAL_STRING(_29, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, _29);
	zephir_check_temp_parameter(_29);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_NVAR(_29);
		ZVAL_STRING(_29, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&types, this_ptr, "get", NULL, _29);
		zephir_check_temp_parameter(_29);
		zephir_check_call_status();
		if (Z_TYPE_P(types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Option 'allowedTypes' must be an array", "ice/validation/validator/file.zep", 143);
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_NVAR(_35);
			ZVAL_LONG(&_35, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, &_35);
			zephir_check_call_status();
			zephir_array_fetch_string(&_32, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 148 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, tmp, _32);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY, "ice/validation/validator/file.zep", 152 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_29);
			ZVAL_STRING(_29, "messageType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_11, this_ptr, "has", NULL, _29);
			zephir_check_temp_parameter(_29);
			zephir_check_call_status();
			if (zephir_is_true(_11)) {
				ZEPHIR_INIT_NVAR(_29);
				ZVAL_STRING(_29, "messageType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _29);
				zephir_check_temp_parameter(_29);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(_29);
				ZVAL_STRING(_29, "fileType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _29);
				zephir_check_temp_parameter(_29);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_13, validation, "gettranslate", NULL);
			zephir_check_call_status();
			_12 = ZEPHIR_IS_TRUE_IDENTICAL(_13);
			if (_12) {
				ZEPHIR_CALL_METHOD(&_14, validation, "getdi", NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_29);
				ZVAL_STRING(_29, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_15, _14, "has", NULL, _29);
				zephir_check_temp_parameter(_29);
				zephir_check_call_status();
				_12 = zephir_is_true(_15);
			}
			if (_12) {
				ZEPHIR_CALL_METHOD(&_16, validation, "getdi", NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_29);
				ZVAL_STRING(_29, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&i18n, _16, "get", NULL, _29);
				zephir_check_temp_parameter(_29);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_27, i18n, "translate", NULL, label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(label, _27);
				ZEPHIR_CALL_METHOD(&_27, i18n, "translate", NULL, message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(message, _27);
			}
			ZEPHIR_INIT_NVAR(replace);
			array_init_size(replace, 3);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_29);
			zephir_fast_join_str(_29, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replace, SL(":types"), &_29, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_27, "strtr", &_17, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _27);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_29);
	ZVAL_STRING(_29, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, _29);
	zephir_check_temp_parameter(_29);
	zephir_check_call_status();
	_12 = zephir_is_true(_10);
	if (!(_12)) {
		ZEPHIR_INIT_NVAR(_29);
		ZVAL_STRING(_29, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "has", NULL, _29);
		zephir_check_temp_parameter(_29);
		zephir_check_call_status();
		_12 = zephir_is_true(_11);
	}
	if (_12) {
		zephir_array_fetch_string(&_32, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 177 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", &_41, _32);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY, "ice/validation/validator/file.zep", 178 TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY, "ice/validation/validator/file.zep", 179 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_29);
		ZVAL_STRING(_29, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "has", NULL, _29);
		zephir_check_temp_parameter(_29);
		zephir_check_call_status();
		if (zephir_is_true(_13)) {
			ZEPHIR_INIT_VAR(minResolution);
			ZEPHIR_INIT_NVAR(_29);
			ZVAL_STRING(_29, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_14, this_ptr, "get", NULL, _29);
			zephir_check_temp_parameter(_29);
			zephir_check_call_status();
			zephir_fast_explode_str(minResolution, SL("x"), _14, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(minWidth);
			zephir_array_fetch_long(&minWidth, minResolution, 0, PH_NOISY, "ice/validation/validator/file.zep", 183 TSRMLS_CC);
			ZEPHIR_OBS_VAR(minHeight);
			zephir_array_fetch_long(&minHeight, minResolution, 1, PH_NOISY, "ice/validation/validator/file.zep", 184 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(minWidth);
			ZVAL_LONG(minWidth, 1);
			ZEPHIR_INIT_NVAR(minHeight);
			ZVAL_LONG(minHeight, 1);
		}
		_26 = ZEPHIR_LT(width, minWidth);
		if (!(_26)) {
			_26 = ZEPHIR_LT(height, minHeight);
		}
		if (_26) {
			ZEPHIR_INIT_NVAR(_29);
			ZVAL_STRING(_29, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_15, this_ptr, "has", NULL, _29);
			zephir_check_temp_parameter(_29);
			zephir_check_call_status();
			if (zephir_is_true(_15)) {
				ZEPHIR_INIT_NVAR(_29);
				ZVAL_STRING(_29, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _29);
				zephir_check_temp_parameter(_29);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(_29);
				ZVAL_STRING(_29, "fileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _29);
				zephir_check_temp_parameter(_29);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, validation, "gettranslate", NULL);
			zephir_check_call_status();
			_28 = ZEPHIR_IS_TRUE_IDENTICAL(_16);
			if (_28) {
				ZEPHIR_CALL_METHOD(&_27, validation, "getdi", NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_29);
				ZVAL_STRING(_29, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_39, _27, "has", NULL, _29);
				zephir_check_temp_parameter(_29);
				zephir_check_call_status();
				_28 = zephir_is_true(_39);
			}
			if (_28) {
				ZEPHIR_CALL_METHOD(&_40, validation, "getdi", NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_29);
				ZVAL_STRING(_29, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&i18n, _40, "get", NULL, _29);
				zephir_check_temp_parameter(_29);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_42, i18n, "translate", NULL, label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(label, _42);
				ZEPHIR_CALL_METHOD(&_42, i18n, "translate", NULL, message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(message, _42);
			}
			ZEPHIR_INIT_NVAR(replace);
			array_init_size(replace, 3);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_29);
			ZVAL_STRING(_29, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_39, this_ptr, "get", NULL, _29);
			zephir_check_temp_parameter(_29);
			zephir_check_call_status();
			zephir_array_update_string(&replace, SL(":min"), &_39, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_39, "strtr", &_17, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _39);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_29);
		ZVAL_STRING(_29, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_15, this_ptr, "has", NULL, _29);
		zephir_check_temp_parameter(_29);
		zephir_check_call_status();
		if (zephir_is_true(_15)) {
			ZEPHIR_INIT_VAR(maxResolution);
			ZEPHIR_INIT_NVAR(_29);
			ZVAL_STRING(_29, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "get", NULL, _29);
			zephir_check_temp_parameter(_29);
			zephir_check_call_status();
			zephir_fast_explode_str(maxResolution, SL("x"), _16, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY, "ice/validation/validator/file.zep", 213 TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY, "ice/validation/validator/file.zep", 214 TSRMLS_CC);
			_43 = ZEPHIR_GT(width, maxWidth);
			if (!(_43)) {
				_43 = ZEPHIR_GT(height, maxHeight);
			}
			if (_43) {
				ZEPHIR_INIT_NVAR(_29);
				ZVAL_STRING(_29, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_27, this_ptr, "has", NULL, _29);
				zephir_check_temp_parameter(_29);
				zephir_check_call_status();
				if (zephir_is_true(_27)) {
					ZEPHIR_INIT_NVAR(_29);
					ZVAL_STRING(_29, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _29);
					zephir_check_temp_parameter(_29);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(_29);
					ZVAL_STRING(_29, "fileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _29);
					zephir_check_temp_parameter(_29);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_40, validation, "gettranslate", NULL);
				zephir_check_call_status();
				_44 = ZEPHIR_IS_TRUE_IDENTICAL(_40);
				if (_44) {
					ZEPHIR_CALL_METHOD(&_42, validation, "getdi", NULL);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_29);
					ZVAL_STRING(_29, "i18n", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_45, _42, "has", NULL, _29);
					zephir_check_temp_parameter(_29);
					zephir_check_call_status();
					_44 = zephir_is_true(_45);
				}
				if (_44) {
					ZEPHIR_CALL_METHOD(&_46, validation, "getdi", NULL);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_29);
					ZVAL_STRING(_29, "i18n", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&i18n, _46, "get", NULL, _29);
					zephir_check_temp_parameter(_29);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_47, i18n, "translate", NULL, label);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(label, _47);
					ZEPHIR_CALL_METHOD(&_47, i18n, "translate", NULL, message);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(message, _47);
				}
				ZEPHIR_INIT_NVAR(replace);
				array_init_size(replace, 3);
				zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_29);
				ZVAL_STRING(_29, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_46, this_ptr, "get", NULL, _29);
				zephir_check_temp_parameter(_29);
				zephir_check_call_status();
				zephir_array_update_string(&replace, SL(":max"), &_46, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_46, "strtr", &_17, message, replace);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _46);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

