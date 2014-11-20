
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


ZEPHIR_INIT_CLASS(Ice_Validation_Validator_File) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, File, ice, validation_validator_file, ice_validation_validator_ce, ice_validation_validator_file_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 *
 * @param object validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_File, validate) {

	zephir_nts_static zephir_fcall_cache_entry *_12 = NULL, *_22 = NULL, *_28 = NULL, *_30 = NULL, *_33 = NULL, *_39 = NULL;
	zend_bool _3, _4, _5, _7, _8, _13, _14, _15, _17, _18, _20, _24, _25, _38, _40, _41;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *replace = NULL, *types = NULL, *byteUnits, *unit = NULL, *maxSize = NULL, *matches, *bytes, *mime = NULL, *tmp = NULL, *width, *height, *minResolution, *maxResolution, *minWidth = NULL, *maxWidth, *minHeight = NULL, *maxHeight, *_0 = NULL, *_1 = NULL, *_SERVER, *_2, *_POST, *_FILES, *_6, *_9, *_10 = NULL, *_11 = NULL, *_16, *_19, *_21, *_23 = NULL, *_26 = NULL, *_27, *_29, *_31, _32 = zval_used_for_init, *_34, *_35 = NULL, *_36 = NULL, *_37 = NULL, *_42 = NULL, *_43 = NULL;

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
	zephir_array_fetch_string(&_2, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 31 TSRMLS_CC);
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
		zephir_array_fetch_string(&_6, _SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 31 TSRMLS_CC);
		_5 = ZEPHIR_GT_LONG(_6, 0);
	}
	_7 = _5;
	if (!(_7)) {
		_8 = zephir_array_isset_string(value, SS("error"));
		if (_8) {
			zephir_array_fetch_string(&_9, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 31 TSRMLS_CC);
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
		ZEPHIR_INIT_VAR(replace);
		array_init_size(replace, 2);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_11, "strtr", &_12, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_13 = zephir_is_true(_10);
	if (_13) {
		_14 = ZEPHIR_IS_EMPTY(value);
		if (!(_14)) {
			_15 = zephir_array_isset_string(value, SS("error"));
			if (_15) {
				zephir_array_fetch_string(&_16, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 44 TSRMLS_CC);
				_15 = ZEPHIR_IS_LONG_IDENTICAL(_16, 4);
			}
			_14 = _15;
		}
		_13 = _14;
	}
	if (_13) {
		RETURN_MM_BOOL(1);
	}
	_17 = !zephir_array_isset_string(value, SS("error"));
	if (!(_17)) {
		_17 = !zephir_array_isset_string(value, SS("tmp_name"));
	}
	_18 = _17;
	if (!(_18)) {
		zephir_array_fetch_string(&_19, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 48 TSRMLS_CC);
		_18 = !ZEPHIR_IS_LONG_IDENTICAL(_19, 0);
	}
	_20 = _18;
	if (!(_20)) {
		zephir_array_fetch_string(&_21, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 48 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "is_uploaded_file", &_22, _21);
		zephir_check_call_status();
		_20 = !zephir_is_true(_10);
	}
	if (_20) {
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
		ZEPHIR_INIT_NVAR(replace);
		array_init_size(replace, 2);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_23, "strtr", &_12, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _23);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_24 = !zephir_array_isset_string(value, SS("name"));
	if (!(_24)) {
		_24 = !zephir_array_isset_string(value, SS("type"));
	}
	_25 = _24;
	if (!(_25)) {
		_25 = !zephir_array_isset_string(value, SS("size"));
	}
	if (_25) {
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
			ZVAL_STRING(_1, "fileValid", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(replace);
		array_init_size(replace, 2);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_11, "strtr", &_12, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _11);
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
		ZEPHIR_INIT_VAR(_26);
		zephir_array_keys(_26, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_1, SL("|"), _26 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_27);
		ZEPHIR_CONCAT_SVS(_27, "/^([0-9]+(?:\\.[0-9]+)?)(", _1, ")?$/Di");
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(NULL, "preg_match", &_28, _27, maxSize, matches);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY, "ice/validation/validator/file.zep", 83 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_29, matches, 1, PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 86 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "floatval", &_30, _29);
		zephir_check_call_status();
		zephir_array_fetch(&_31, byteUnits, unit, PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 86 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_32);
		ZVAL_LONG(&_32, 2);
		ZEPHIR_CALL_FUNCTION(&_23, "pow", &_33, &_32, _31);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _11, _23 TSRMLS_CC);
		zephir_array_fetch_string(&_34, value, SL("size"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 88 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "floatval", &_30, _34);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_23, "floatval", &_30, bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(_11, _23)) {
			ZEPHIR_INIT_VAR(_36);
			ZVAL_STRING(_36, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_35, this_ptr, "has", NULL, _36);
			zephir_check_temp_parameter(_36);
			zephir_check_call_status();
			if (zephir_is_true(_35)) {
				ZEPHIR_INIT_NVAR(_36);
				ZVAL_STRING(_36, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _36);
				zephir_check_temp_parameter(_36);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(_36);
				ZVAL_STRING(_36, "fileSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _36);
				zephir_check_temp_parameter(_36);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(replace);
			array_init_size(replace, 3);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replace, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_37, "strtr", &_12, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _37);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_26);
	ZVAL_STRING(_26, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, _26);
	zephir_check_temp_parameter(_26);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_NVAR(_26);
		ZVAL_STRING(_26, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&types, this_ptr, "get", NULL, _26);
		zephir_check_temp_parameter(_26);
		zephir_check_call_status();
		if (Z_TYPE_P(types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Option 'allowedTypes' must be an array", "ice/validation/validator/file.zep", 106);
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_NVAR(_32);
			ZVAL_LONG(&_32, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, &_32);
			zephir_check_call_status();
			zephir_array_fetch_string(&_29, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 111 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, tmp, _29);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY, "ice/validation/validator/file.zep", 115 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "messageType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_11, this_ptr, "has", NULL, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			if (zephir_is_true(_11)) {
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "messageType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "fileType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(replace);
			array_init_size(replace, 3);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_26);
			zephir_fast_join_str(_26, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replace, SL(":types"), &_26, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_23, "strtr", &_12, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _23);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_26);
	ZVAL_STRING(_26, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, _26);
	zephir_check_temp_parameter(_26);
	zephir_check_call_status();
	_38 = zephir_is_true(_10);
	if (!(_38)) {
		ZEPHIR_INIT_NVAR(_26);
		ZVAL_STRING(_26, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "has", NULL, _26);
		zephir_check_temp_parameter(_26);
		zephir_check_call_status();
		_38 = zephir_is_true(_11);
	}
	if (_38) {
		zephir_array_fetch_string(&_29, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 133 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", &_39, _29);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY, "ice/validation/validator/file.zep", 134 TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY, "ice/validation/validator/file.zep", 135 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_26);
		ZVAL_STRING(_26, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_23, this_ptr, "has", NULL, _26);
		zephir_check_temp_parameter(_26);
		zephir_check_call_status();
		if (zephir_is_true(_23)) {
			ZEPHIR_INIT_VAR(minResolution);
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", NULL, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			zephir_fast_explode_str(minResolution, SL("x"), _35, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(minWidth);
			zephir_array_fetch_long(&minWidth, minResolution, 0, PH_NOISY, "ice/validation/validator/file.zep", 139 TSRMLS_CC);
			ZEPHIR_OBS_VAR(minHeight);
			zephir_array_fetch_long(&minHeight, minResolution, 1, PH_NOISY, "ice/validation/validator/file.zep", 140 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(minWidth);
			ZVAL_LONG(minWidth, 1);
			ZEPHIR_INIT_NVAR(minHeight);
			ZVAL_LONG(minHeight, 1);
		}
		_40 = ZEPHIR_LT(width, minWidth);
		if (!(_40)) {
			_40 = ZEPHIR_LT(height, minHeight);
		}
		if (_40) {
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_35, this_ptr, "has", NULL, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			if (zephir_is_true(_35)) {
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "fileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(replace);
			array_init_size(replace, 3);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", NULL, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			zephir_array_update_string(&replace, SL(":min"), &_37, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_37, "strtr", &_12, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _37);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_26);
		ZVAL_STRING(_26, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_35, this_ptr, "has", NULL, _26);
		zephir_check_temp_parameter(_26);
		zephir_check_call_status();
		if (zephir_is_true(_35)) {
			ZEPHIR_INIT_VAR(maxResolution);
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", NULL, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			zephir_fast_explode_str(maxResolution, SL("x"), _37, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY, "ice/validation/validator/file.zep", 162 TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY, "ice/validation/validator/file.zep", 163 TSRMLS_CC);
			_41 = ZEPHIR_GT(width, maxWidth);
			if (!(_41)) {
				_41 = ZEPHIR_GT(height, maxHeight);
			}
			if (_41) {
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_42, this_ptr, "has", NULL, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
				if (zephir_is_true(_42)) {
					ZEPHIR_INIT_NVAR(_26);
					ZVAL_STRING(_26, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, _26);
					zephir_check_temp_parameter(_26);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(_26);
					ZVAL_STRING(_26, "fileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _26);
					zephir_check_temp_parameter(_26);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(replace);
				array_init_size(replace, 3);
				zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_43, this_ptr, "get", NULL, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
				zephir_array_update_string(&replace, SL(":max"), &_43, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_43, "strtr", &_12, message, replace);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, field, _43);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

