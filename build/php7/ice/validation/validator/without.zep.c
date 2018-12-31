
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Without validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
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
 * Options: fields (0,1,2..), label, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Without, validate) {

	zend_string *_20$$13;
	zend_ulong _19$$13;
	zend_bool _0, _4$$6, _12$$8;
	zephir_fcall_cache_entry *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, label, message, i18n, replace, fields, without, tmp, except, key, translate, _1, *_3, _2$$4, _5$$8, _6$$8, _8$$8, _11$$8, _13$$8, _14$$8, _23$$8, _7$$9, _9$$11, _10$$12, _15$$13, _16$$13, _17$$13, *_18$$13, _21$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&without);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&except);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&translate);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&field);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
	if (!(_0)) {
		_0 = Z_TYPE_P(&value) == IS_NULL;
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "getoptions", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&except);
	array_init(&except);
	if (ZEPHIR_IS_EMPTY(&fields)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "fields");
		ZEPHIR_CALL_METHOD(&fields, this_ptr, "get", NULL, 0, &_2$$4);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&fields) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Fields must be an array", "ice/validation/validator/without.zep", 64);
		return;
	}
	zephir_is_iterable(&fields, 0, "ice/validation/validator/without.zep", 75);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _3)
	{
		ZEPHIR_INIT_NVAR(&without);
		ZVAL_COPY(&without, _3);
		ZEPHIR_CALL_METHOD(&tmp, validation, "getvalue", NULL, 0, &without);
		zephir_check_call_status();
		_4$$6 = !ZEPHIR_IS_STRING_IDENTICAL(&tmp, "");
		if (_4$$6) {
			_4$$6 = Z_TYPE_P(&tmp) != IS_NULL;
		}
		if (_4$$6) {
			zephir_array_append(&except, &without, PH_SEPARATE, "ice/validation/validator/without.zep", 71);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&without);
	if (zephir_fast_count_int(&except TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_6$$8);
		ZVAL_STRING(&_6$$8, "label");
		ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "has", NULL, 0, &_6$$8);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$8)) {
			ZEPHIR_INIT_VAR(&_7$$9);
			ZVAL_STRING(&_7$$9, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_7$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_6$$8);
		ZVAL_STRING(&_6$$8, "message");
		ZEPHIR_CALL_METHOD(&_8$$8, this_ptr, "has", NULL, 0, &_6$$8);
		zephir_check_call_status();
		if (zephir_is_true(&_8$$8)) {
			ZEPHIR_INIT_VAR(&_9$$11);
			ZVAL_STRING(&_9$$11, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_9$$11);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_10$$12);
			ZVAL_STRING(&_10$$12, "without");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_10$$12);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_11$$8, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_12$$8 = ZEPHIR_IS_TRUE_IDENTICAL(&_11$$8);
		if (_12$$8) {
			ZEPHIR_CALL_METHOD(&_13$$8, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_6$$8);
			ZVAL_STRING(&_6$$8, "i18n");
			ZEPHIR_CALL_METHOD(&_14$$8, &_13$$8, "has", NULL, 0, &_6$$8);
			zephir_check_call_status();
			_12$$8 = zephir_is_true(&_14$$8);
		}
		if (_12$$8) {
			ZEPHIR_CALL_METHOD(&_15$$13, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_16$$13);
			ZVAL_STRING(&_16$$13, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_15$$13, "get", NULL, 0, &_16$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_17$$13, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_17$$13);
			ZEPHIR_CALL_METHOD(&_17$$13, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_17$$13);
			zephir_is_iterable(&except, 1, "ice/validation/validator/without.zep", 97);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&except), _19$$13, _20$$13, _18$$13)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_20$$13 != NULL) { 
					ZVAL_STR_COPY(&key, _20$$13);
				} else {
					ZVAL_LONG(&key, _19$$13);
				}
				ZEPHIR_INIT_NVAR(&translate);
				ZVAL_COPY(&translate, _18$$13);
				ZEPHIR_CALL_METHOD(&_21$$14, &i18n, "translate", &_22, 0, &translate);
				zephir_check_call_status();
				zephir_array_update_zval(&except, &key, &_21$$14, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&translate);
			ZEPHIR_INIT_NVAR(&key);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_6$$8);
		zephir_fast_join_str(&_6$$8, SL(", "), &except TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":fields"), &_6$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_23$$8, "strtr", NULL, 103, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_23$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

