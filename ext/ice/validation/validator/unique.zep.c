
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
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Unique validator.
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
 *      'userName' => [
 *          'unique' => [
 *              'from' => 'users',
 *              'custom' => 'username'
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Unique) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Unique, ice, validation_validator_unique, ice_validation_validator_ce, ice_validation_validator_unique_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 * Options: label, from, custom, except, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Unique, validate) {

	zval *_11 = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_bool _0, _14;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace = NULL, *di = NULL, *db = NULL, *from = NULL, *custom = NULL, *except = NULL, *tmp = NULL, *caseInsensitive = NULL, *result = NULL, *id = NULL, *_2 = NULL, *_3, *_4, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10, *_12 = NULL, *_13 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_18 = NULL;

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
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_1, 8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "db", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_NULL(_3);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, 1);
	ZEPHIR_CALL_METHOD(&db, di, "get", NULL, 0, _2, _3, _4);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, 0, _2);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "from", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 1);
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, 0, _2);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "custom", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(custom)) {
		ZEPHIR_CPY_WRT(custom, field);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 2);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_7)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 2);
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, 0, _2);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "except", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 3);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 3);
		ZEPHIR_CALL_METHOD(&caseInsensitive, this_ptr, "get", NULL, 0, _2);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "caseInsensitive", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&caseInsensitive, this_ptr, "get", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	if (zephir_is_true(caseInsensitive)) {
		ZEPHIR_CPY_WRT(tmp, value);
		ZEPHIR_CALL_METHOD(&_9, db, "gettype", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(_9, "NOSQL")) {
			ZEPHIR_INIT_NVAR(value);
			object_init_ex(value, zephir_get_internal_ce(SS("mongoregex") TSRMLS_CC));
			ZEPHIR_INIT_VAR(_10);
			ZEPHIR_CONCAT_SVS(_10, "/^", tmp, "$/i");
			ZEPHIR_CALL_METHOD(NULL, value, "__construct", NULL, 0, _10);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(value);
			zephir_fast_strtolower(value, tmp);
		}
	}
	if (zephir_is_true(except)) {
		ZEPHIR_INIT_VAR(id);
		zephir_create_array(id, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_9, db, "getidvalue", NULL, 0, except);
		zephir_check_call_status();
		zephir_array_update_string(&id, SL("!="), &_9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_11);
		zephir_create_array(_11, 2, 0 TSRMLS_CC);
		zephir_array_update_zval(&_11, custom, &value, PH_COPY);
		ZEPHIR_CALL_METHOD(&_9, db, "getid", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&_11, _9, &id, PH_COPY);
		ZEPHIR_CALL_METHOD(&result, db, "findone", NULL, 0, from, _11);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_11);
		zephir_create_array(_11, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(&_11, custom, &value, PH_COPY);
		ZEPHIR_CALL_METHOD(&result, db, "findone", NULL, 0, from, _11);
		zephir_check_call_status();
	}
	if (zephir_is_true(result)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_9, this_ptr, "has", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(_9)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "has", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(_12)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "unique", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_13, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_14 = ZEPHIR_IS_TRUE_IDENTICAL(_13);
		if (_14) {
			ZEPHIR_CALL_METHOD(&_15, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_16, _15, "has", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			_14 = zephir_is_true(_16);
		}
		if (_14) {
			ZEPHIR_CALL_METHOD(&_17, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _17, "get", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_18, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _18);
			ZEPHIR_CALL_METHOD(&_18, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _18);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_17, "strtr", NULL, 85, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _17);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

