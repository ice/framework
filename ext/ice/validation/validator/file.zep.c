
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
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/math.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


/**
 * File validator.
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
 *      'picture' => [
 *          'file' => [
 *              'maxSize' => '6M',
 *              'allowedTypes' => ['image/jpeg', 'image/png'],
 *              'minResolution' => '400x300,
 *              'maxResolution' => '1600x1200',
 *          ]
 *      ]
 *  ]);
 *  
 *  $valid = $validation->validate($_FILES);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * <code><pre>
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_File) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, File, ice, validation_validator_file, ice_validation_validator_ce, ice_validation_validator_file_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 * Options: label, messageIniSize, allowEmpty, messageEmpty, messageValid, maxSize, messageSize, allowedTypes, messageType
 * minResolution, maxResolution, messageMinResolution, messageMaxResolution
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_File, validate) {

	zephir_fcall_cache_entry *_17 = NULL, *_32 = NULL;
	zend_bool _3, _4, _5, _7, _8, _12, _18, _19, _21, _23, _25, _27, _40, _41;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *i18n = NULL, *replace = NULL, *types = NULL, *byteUnits, *unit = NULL, *maxSize = NULL, *matches, *bytes, *mime = NULL, *tmp = NULL, *width, *height, *minResolution, *maxResolution, *minWidth = NULL, *maxWidth, *minHeight = NULL, *maxHeight, *_0 = NULL, *_1 = NULL, *_SERVER, *_2, *_POST, *_FILES, *_6, *_9, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_20, *_22, *_24, *_26 = NULL, *_28 = NULL, *_29, *_30, *_31, *_33 = NULL, *_34, _35 = zval_used_for_init, *_36, *_37 = NULL, *_38 = NULL, *_39 = NULL, *_42 = NULL, *_43 = NULL, *_44 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
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
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
		zephir_check_call_status();
	}
	zephir_array_fetch_string(&_2, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 63 TSRMLS_CC);
	_3 = ZEPHIR_IS_STRING(_2, "POST");
	if (_3) {
		_3 = ZEPHIR_IS_EMPTY(_POST);
	}
	_4 = _3;
	if (_4) {
		_4 = ZEPHIR_IS_EMPTY(_FILES);
	}
	_5 = _4;
	if (_5) {
		zephir_array_fetch_string(&_6, _SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 63 TSRMLS_CC);
		_5 = ZEPHIR_GT_LONG(_6, 0);
	}
	_7 = _5;
	if (!(_7)) {
		_8 = zephir_array_isset_string(value, SS("error"));
		if (_8) {
			zephir_array_fetch_string(&_9, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 63 TSRMLS_CC);
			_8 = ZEPHIR_IS_LONG_IDENTICAL(_9, 1);
		}
		_7 = _8;
	}
	if (_7) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "messageIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_10)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "messageIniSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "fileIniSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_11, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_12 = ZEPHIR_IS_TRUE_IDENTICAL(_11);
		if (_12) {
			ZEPHIR_CALL_METHOD(&_13, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_14, _13, "has", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			_12 = zephir_is_true(_14);
		}
		if (_12) {
			ZEPHIR_CALL_METHOD(&_15, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _15, "get", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _16);
			ZEPHIR_CALL_METHOD(&_16, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _16);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_15, "strtr", &_17, 67, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _15);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_12 = zephir_is_true(_10);
	if (_12) {
		_18 = ZEPHIR_IS_EMPTY(value);
		if (!(_18)) {
			_19 = zephir_array_isset_string(value, SS("error"));
			if (_19) {
				zephir_array_fetch_string(&_20, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 83 TSRMLS_CC);
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
		zephir_array_fetch_string(&_22, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 87 TSRMLS_CC);
		_21 = !ZEPHIR_IS_LONG_IDENTICAL(_22, 0);
	}
	_23 = _21;
	if (!(_23)) {
		zephir_array_fetch_string(&_24, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 87 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "is_uploaded_file", NULL, 159, _24);
		zephir_check_call_status();
		_23 = !zephir_is_true(_10);
	}
	if (_23) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "messageEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "has", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_11)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "messageEmpty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "fileEmpty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_13, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_25 = ZEPHIR_IS_TRUE_IDENTICAL(_13);
		if (_25) {
			ZEPHIR_CALL_METHOD(&_14, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_15, _14, "has", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			_25 = zephir_is_true(_15);
		}
		if (_25) {
			ZEPHIR_CALL_METHOD(&_16, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _16, "get", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_26, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _26);
			ZEPHIR_CALL_METHOD(&_26, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _26);
		}
		ZEPHIR_INIT_NVAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_15, "strtr", &_17, 67, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _15);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_12 = !(zephir_array_isset_string(value, SS("name")));
	if (!(_12)) {
		_12 = !(zephir_array_isset_string(value, SS("type")));
	}
	_25 = _12;
	if (!(_25)) {
		_25 = !(zephir_array_isset_string(value, SS("size")));
	}
	if (_25) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "messageValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (zephir_is_true(_10)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "messageValid", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "default", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_11, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_27 = ZEPHIR_IS_TRUE_IDENTICAL(_11);
		if (_27) {
			ZEPHIR_CALL_METHOD(&_13, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_14, _13, "has", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			_27 = zephir_is_true(_14);
		}
		if (_27) {
			ZEPHIR_CALL_METHOD(&_15, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _15, "get", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _16);
			ZEPHIR_CALL_METHOD(&_16, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _16);
		}
		ZEPHIR_INIT_NVAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_15, "strtr", &_17, 67, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _15);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_VAR(byteUnits);
		zephir_create_array(byteUnits, 9, 0 TSRMLS_CC);
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
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "get", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_VAR(_28);
		ZEPHIR_INIT_VAR(_29);
		zephir_array_keys(_29, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_28, SL("|"), _29 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_30);
		ZEPHIR_CONCAT_SVS(_30, "/^([0-9]+(?:\\.[0-9]+)?)(", _28, ")?$/Di");
		zephir_preg_match(_1, _30, maxSize, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY, "ice/validation/validator/file.zep", 136 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_31, matches, 1, PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 139 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "floatval", &_32, 160, _31);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_33);
		zephir_array_fetch(&_34, byteUnits, unit, PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 139 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_35);
		ZVAL_LONG(&_35, 2);
		zephir_pow_function(_33, &_35, _34);
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _11, _33 TSRMLS_CC);
		zephir_array_fetch_string(&_36, value, SL("size"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 141 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "floatval", &_32, 160, _36);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_13, "floatval", &_32, 160, bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(_11, _13)) {
			ZEPHIR_INIT_NVAR(_33);
			ZVAL_STRING(_33, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_14, this_ptr, "has", NULL, 0, _33);
			zephir_check_temp_parameter(_33);
			zephir_check_call_status();
			if (zephir_is_true(_14)) {
				ZEPHIR_INIT_NVAR(_33);
				ZVAL_STRING(_33, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _33);
				zephir_check_temp_parameter(_33);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(_33);
				ZVAL_STRING(_33, "fileSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _33);
				zephir_check_temp_parameter(_33);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, validation, "gettranslate", NULL, 0);
			zephir_check_call_status();
			_12 = ZEPHIR_IS_TRUE_IDENTICAL(_15);
			if (_12) {
				ZEPHIR_CALL_METHOD(&_16, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_33);
				ZVAL_STRING(_33, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_26, _16, "has", NULL, 0, _33);
				zephir_check_temp_parameter(_33);
				zephir_check_call_status();
				_12 = zephir_is_true(_26);
			}
			if (_12) {
				ZEPHIR_CALL_METHOD(&_37, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_33);
				ZVAL_STRING(_33, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&i18n, _37, "get", NULL, 0, _33);
				zephir_check_temp_parameter(_33);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_38, i18n, "translate", NULL, 0, label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(label, _38);
				ZEPHIR_CALL_METHOD(&_38, i18n, "translate", NULL, 0, message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(message, _38);
			}
			ZEPHIR_INIT_NVAR(replace);
			zephir_create_array(replace, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replace, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_37, "strtr", &_17, 67, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _37);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_28);
	ZVAL_STRING(_28, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, 0, _28);
	zephir_check_temp_parameter(_28);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_NVAR(_28);
		ZVAL_STRING(_28, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&types, this_ptr, "get", NULL, 0, _28);
		zephir_check_temp_parameter(_28);
		zephir_check_call_status();
		if (Z_TYPE_P(types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Option 'allowedTypes' must be an array", "ice/validation/validator/file.zep", 166);
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_NVAR(_35);
			ZVAL_LONG(&_35, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 161, &_35);
			zephir_check_call_status();
			zephir_array_fetch_string(&_31, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 171 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 162, tmp, _31);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 163, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY, "ice/validation/validator/file.zep", 175 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_28);
			ZVAL_STRING(_28, "messageType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_11, this_ptr, "has", NULL, 0, _28);
			zephir_check_temp_parameter(_28);
			zephir_check_call_status();
			if (zephir_is_true(_11)) {
				ZEPHIR_INIT_NVAR(_28);
				ZVAL_STRING(_28, "messageType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _28);
				zephir_check_temp_parameter(_28);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(_28);
				ZVAL_STRING(_28, "fileType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _28);
				zephir_check_temp_parameter(_28);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_13, validation, "gettranslate", NULL, 0);
			zephir_check_call_status();
			_12 = ZEPHIR_IS_TRUE_IDENTICAL(_13);
			if (_12) {
				ZEPHIR_CALL_METHOD(&_14, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_28);
				ZVAL_STRING(_28, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_15, _14, "has", NULL, 0, _28);
				zephir_check_temp_parameter(_28);
				zephir_check_call_status();
				_12 = zephir_is_true(_15);
			}
			if (_12) {
				ZEPHIR_CALL_METHOD(&_16, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_28);
				ZVAL_STRING(_28, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&i18n, _16, "get", NULL, 0, _28);
				zephir_check_temp_parameter(_28);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_26, i18n, "translate", NULL, 0, label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(label, _26);
				ZEPHIR_CALL_METHOD(&_26, i18n, "translate", NULL, 0, message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(message, _26);
			}
			ZEPHIR_INIT_NVAR(replace);
			zephir_create_array(replace, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_28);
			zephir_fast_join_str(_28, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replace, SL(":types"), &_28, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_26, "strtr", &_17, 67, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _26);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_28);
	ZVAL_STRING(_28, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, 0, _28);
	zephir_check_temp_parameter(_28);
	zephir_check_call_status();
	_12 = zephir_is_true(_10);
	if (!(_12)) {
		ZEPHIR_INIT_NVAR(_28);
		ZVAL_STRING(_28, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "has", NULL, 0, _28);
		zephir_check_temp_parameter(_28);
		zephir_check_call_status();
		_12 = zephir_is_true(_11);
	}
	if (_12) {
		zephir_array_fetch_string(&_31, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 200 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 164, _31);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY, "ice/validation/validator/file.zep", 201 TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY, "ice/validation/validator/file.zep", 202 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_28);
		ZVAL_STRING(_28, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "has", NULL, 0, _28);
		zephir_check_temp_parameter(_28);
		zephir_check_call_status();
		if (zephir_is_true(_13)) {
			ZEPHIR_INIT_NVAR(_28);
			ZVAL_STRING(_28, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_14, this_ptr, "get", NULL, 0, _28);
			zephir_check_temp_parameter(_28);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(minResolution);
			zephir_fast_explode_str(minResolution, SL("x"), _14, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(minWidth);
			zephir_array_fetch_long(&minWidth, minResolution, 0, PH_NOISY, "ice/validation/validator/file.zep", 206 TSRMLS_CC);
			ZEPHIR_OBS_VAR(minHeight);
			zephir_array_fetch_long(&minHeight, minResolution, 1, PH_NOISY, "ice/validation/validator/file.zep", 207 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(minWidth);
			ZVAL_LONG(minWidth, 1);
			ZEPHIR_INIT_NVAR(minHeight);
			ZVAL_LONG(minHeight, 1);
		}
		_25 = ZEPHIR_LT(width, minWidth);
		if (!(_25)) {
			_25 = ZEPHIR_LT(height, minHeight);
		}
		if (_25) {
			ZEPHIR_INIT_NVAR(_28);
			ZVAL_STRING(_28, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_15, this_ptr, "has", NULL, 0, _28);
			zephir_check_temp_parameter(_28);
			zephir_check_call_status();
			if (zephir_is_true(_15)) {
				ZEPHIR_INIT_NVAR(_28);
				ZVAL_STRING(_28, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _28);
				zephir_check_temp_parameter(_28);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(_28);
				ZVAL_STRING(_28, "fileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _28);
				zephir_check_temp_parameter(_28);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, validation, "gettranslate", NULL, 0);
			zephir_check_call_status();
			_27 = ZEPHIR_IS_TRUE_IDENTICAL(_16);
			if (_27) {
				ZEPHIR_CALL_METHOD(&_26, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_28);
				ZVAL_STRING(_28, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_37, _26, "has", NULL, 0, _28);
				zephir_check_temp_parameter(_28);
				zephir_check_call_status();
				_27 = zephir_is_true(_37);
			}
			if (_27) {
				ZEPHIR_CALL_METHOD(&_38, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_28);
				ZVAL_STRING(_28, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&i18n, _38, "get", NULL, 0, _28);
				zephir_check_temp_parameter(_28);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_39, i18n, "translate", NULL, 0, label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(label, _39);
				ZEPHIR_CALL_METHOD(&_39, i18n, "translate", NULL, 0, message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(message, _39);
			}
			ZEPHIR_INIT_NVAR(replace);
			zephir_create_array(replace, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_28);
			ZVAL_STRING(_28, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", NULL, 0, _28);
			zephir_check_temp_parameter(_28);
			zephir_check_call_status();
			zephir_array_update_string(&replace, SL(":min"), &_37, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_37, "strtr", &_17, 67, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _37);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_28);
		ZVAL_STRING(_28, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_15, this_ptr, "has", NULL, 0, _28);
		zephir_check_temp_parameter(_28);
		zephir_check_call_status();
		if (zephir_is_true(_15)) {
			ZEPHIR_INIT_NVAR(_28);
			ZVAL_STRING(_28, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "get", NULL, 0, _28);
			zephir_check_temp_parameter(_28);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(maxResolution);
			zephir_fast_explode_str(maxResolution, SL("x"), _16, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY, "ice/validation/validator/file.zep", 236 TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY, "ice/validation/validator/file.zep", 237 TSRMLS_CC);
			_40 = ZEPHIR_GT(width, maxWidth);
			if (!(_40)) {
				_40 = ZEPHIR_GT(height, maxHeight);
			}
			if (_40) {
				ZEPHIR_INIT_NVAR(_28);
				ZVAL_STRING(_28, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_26, this_ptr, "has", NULL, 0, _28);
				zephir_check_temp_parameter(_28);
				zephir_check_call_status();
				if (zephir_is_true(_26)) {
					ZEPHIR_INIT_NVAR(_28);
					ZVAL_STRING(_28, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _28);
					zephir_check_temp_parameter(_28);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(_28);
					ZVAL_STRING(_28, "fileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _28);
					zephir_check_temp_parameter(_28);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_38, validation, "gettranslate", NULL, 0);
				zephir_check_call_status();
				_41 = ZEPHIR_IS_TRUE_IDENTICAL(_38);
				if (_41) {
					ZEPHIR_CALL_METHOD(&_39, validation, "getdi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_28);
					ZVAL_STRING(_28, "i18n", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_42, _39, "has", NULL, 0, _28);
					zephir_check_temp_parameter(_28);
					zephir_check_call_status();
					_41 = zephir_is_true(_42);
				}
				if (_41) {
					ZEPHIR_CALL_METHOD(&_43, validation, "getdi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_28);
					ZVAL_STRING(_28, "i18n", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&i18n, _43, "get", NULL, 0, _28);
					zephir_check_temp_parameter(_28);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_44, i18n, "translate", NULL, 0, label);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(label, _44);
					ZEPHIR_CALL_METHOD(&_44, i18n, "translate", NULL, 0, message);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(message, _44);
				}
				ZEPHIR_INIT_NVAR(replace);
				zephir_create_array(replace, 2, 0 TSRMLS_CC);
				zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_28);
				ZVAL_STRING(_28, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_43, this_ptr, "get", NULL, 0, _28);
				zephir_check_temp_parameter(_28);
				zephir_check_call_status();
				zephir_array_update_string(&replace, SL(":max"), &_43, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_43, "strtr", &_17, 67, message, replace);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _43);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

