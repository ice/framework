
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
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *  
 *  $validation->rules([
 *      'password' => [
 *          'without' => [
 *              'fields' => ['newPassword'],
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Without) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Without, ice, validation_validator_without, ice_validation_validator_ce, ice_validation_validator_without_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 * Options: label, fields, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Without, validate) {

	HashTable *_4;
	HashPosition _3;
	zend_bool _0, _6$$6, _14$$8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace = NULL, *fields = NULL, *without = NULL, *tmp = NULL, *except = NULL, *_1, **_5, *_2$$4, *_7$$8 = NULL, *_8$$8 = NULL, *_10$$8 = NULL, *_13$$8 = NULL, *_15$$8 = NULL, *_16$$8 = NULL, *_20$$8 = NULL, *_9$$9, *_11$$11, *_12$$12, *_17$$13 = NULL, *_18$$13, *_19$$13 = NULL;

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
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "getoptions", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(except);
	array_init(except);
	if (ZEPHIR_IS_EMPTY(fields)) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "fields", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&fields, this_ptr, "get", NULL, 0, _2$$4);
		zephir_check_temp_parameter(_2$$4);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(fields) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Fields must be an array", "ice/validation/validator/without.zep", 64);
		return;
	}
	zephir_is_iterable(fields, &_4, &_3, 0, 0, "ice/validation/validator/without.zep", 75);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(without, _5);
		ZEPHIR_CALL_METHOD(&tmp, validation, "getvalue", NULL, 0, without);
		zephir_check_call_status();
		_6$$6 = !ZEPHIR_IS_STRING_IDENTICAL(tmp, "");
		if (_6$$6) {
			_6$$6 = Z_TYPE_P(tmp) != IS_NULL;
		}
		if (_6$$6) {
			zephir_array_append(&except, without, PH_SEPARATE, "ice/validation/validator/without.zep", 71);
		}
	}
	if (zephir_fast_count_int(except TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_8$$8);
		ZVAL_STRING(_8$$8, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_7$$8, this_ptr, "has", NULL, 0, _8$$8);
		zephir_check_temp_parameter(_8$$8);
		zephir_check_call_status();
		if (zephir_is_true(_7$$8)) {
			ZEPHIR_INIT_VAR(_9$$9);
			ZVAL_STRING(_9$$9, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _9$$9);
			zephir_check_temp_parameter(_9$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_8$$8);
		ZVAL_STRING(_8$$8, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10$$8, this_ptr, "has", NULL, 0, _8$$8);
		zephir_check_temp_parameter(_8$$8);
		zephir_check_call_status();
		if (zephir_is_true(_10$$8)) {
			ZEPHIR_INIT_VAR(_11$$11);
			ZVAL_STRING(_11$$11, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _11$$11);
			zephir_check_temp_parameter(_11$$11);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_12$$12);
			ZVAL_STRING(_12$$12, "without", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _12$$12);
			zephir_check_temp_parameter(_12$$12);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_13$$8, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_14$$8 = ZEPHIR_IS_TRUE_IDENTICAL(_13$$8);
		if (_14$$8) {
			ZEPHIR_CALL_METHOD(&_15$$8, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_8$$8);
			ZVAL_STRING(_8$$8, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_16$$8, _15$$8, "has", NULL, 0, _8$$8);
			zephir_check_temp_parameter(_8$$8);
			zephir_check_call_status();
			_14$$8 = zephir_is_true(_16$$8);
		}
		if (_14$$8) {
			ZEPHIR_CALL_METHOD(&_17$$13, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_18$$13);
			ZVAL_STRING(_18$$13, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _17$$13, "get", NULL, 0, _18$$13);
			zephir_check_temp_parameter(_18$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_19$$13, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _19$$13);
			ZEPHIR_CALL_METHOD(&_19$$13, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _19$$13);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_8$$8);
		zephir_fast_join_str(_8$$8, SL(", "), except TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":fields"), &_8$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_20$$8, "strtr", NULL, 82, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _20$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

