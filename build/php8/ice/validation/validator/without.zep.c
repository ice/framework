
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Without validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) Ice Team
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Without)
{
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
PHP_METHOD(Ice_Validation_Validator_Without, validate)
{
	zend_ulong _25$$15;
	zend_bool _0, _8, _6$$6, _9$$8, _17$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_28 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *field = NULL, *_26$$15;
	zval *validation, validation_sub, field_zv, value, label, message, i18n, replace, fields, without, tmp, except, key, translate, _1, *_3, _4, *_5, _7, _2$$4, _10$$10, _11$$10, _13$$10, _16$$10, _18$$10, _19$$10, _29$$10, _12$$11, _14$$13, _15$$14, _20$$15, _21$$15, _22$$15, *_23$$15, *_24$$15, _27$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_zv);
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_27$$16);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, ice_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	validation = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field_zv);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Fields must be an array", "ice/validation/validator/without.zep", 63);
		return;
	}
	if (Z_TYPE_P(&fields) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &fields);
		_3 = &_4;
	} else {
		_3 = &fields;
	}
	zephir_is_iterable(_3, 0, "ice/validation/validator/without.zep", 74);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&without);
			ZVAL_COPY(&without, _5);
			ZEPHIR_CALL_METHOD(&tmp, validation, "getvalue", NULL, 0, &without);
			zephir_check_call_status();
			_6$$6 = !ZEPHIR_IS_STRING_IDENTICAL(&tmp, "");
			if (_6$$6) {
				_6$$6 = Z_TYPE_P(&tmp) != IS_NULL;
			}
			if (_6$$6) {
				zephir_array_append(&except, &without, PH_SEPARATE, "ice/validation/validator/without.zep", 70);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&without, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&tmp, validation, "getvalue", NULL, 0, &without);
				zephir_check_call_status();
				_9$$8 = !ZEPHIR_IS_STRING_IDENTICAL(&tmp, "");
				if (_9$$8) {
					_9$$8 = Z_TYPE_P(&tmp) != IS_NULL;
				}
				if (_9$$8) {
					zephir_array_append(&except, &without, PH_SEPARATE, "ice/validation/validator/without.zep", 70);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&without);
	if (zephir_fast_count_int(&except)) {
		ZEPHIR_INIT_VAR(&_11$$10);
		ZVAL_STRING(&_11$$10, "label");
		ZEPHIR_CALL_METHOD(&_10$$10, this_ptr, "has", NULL, 0, &_11$$10);
		zephir_check_call_status();
		if (zephir_is_true(&_10$$10)) {
			ZEPHIR_INIT_VAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_12$$11);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field_zv);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_11$$10);
		ZVAL_STRING(&_11$$10, "message");
		ZEPHIR_CALL_METHOD(&_13$$10, this_ptr, "has", NULL, 0, &_11$$10);
		zephir_check_call_status();
		if (zephir_is_true(&_13$$10)) {
			ZEPHIR_INIT_VAR(&_14$$13);
			ZVAL_STRING(&_14$$13, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_14$$13);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_15$$14);
			ZVAL_STRING(&_15$$14, "without");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_15$$14);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_16$$10, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_17$$10 = ZEPHIR_IS_TRUE_IDENTICAL(&_16$$10);
		if (_17$$10) {
			ZEPHIR_CALL_METHOD(&_18$$10, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_11$$10);
			ZVAL_STRING(&_11$$10, "i18n");
			ZEPHIR_CALL_METHOD(&_19$$10, &_18$$10, "has", NULL, 0, &_11$$10);
			zephir_check_call_status();
			_17$$10 = zephir_is_true(&_19$$10);
		}
		if (_17$$10) {
			ZEPHIR_CALL_METHOD(&_20$$15, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_21$$15);
			ZVAL_STRING(&_21$$15, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_20$$15, "get", NULL, 0, &_21$$15);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_22$$15, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_22$$15);
			ZEPHIR_CALL_METHOD(&_22$$15, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_22$$15);
			if (Z_TYPE_P(&except) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_21$$15);
				zephir_string_to_char_array(&_21$$15, &except);
				_23$$15 = &_21$$15;
			} else {
				_23$$15 = &except;
			}
			zephir_is_iterable(_23$$15, 0, "ice/validation/validator/without.zep", 96);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_23$$15), _25$$15, _26$$15, _24$$15)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_26$$15 != NULL) { 
					ZVAL_STR_COPY(&key, _26$$15);
				} else {
					ZVAL_LONG(&key, _25$$15);
				}
				ZEPHIR_INIT_NVAR(&translate);
				ZVAL_COPY(&translate, _24$$15);
				ZEPHIR_CALL_METHOD(&_27$$16, &i18n, "translate", &_28, 0, &translate);
				zephir_check_call_status();
				zephir_array_update_zval(&except, &key, &_27$$16, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&translate);
			ZEPHIR_INIT_NVAR(&key);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 2, 0);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_11$$10);
		zephir_fast_join_str(&_11$$10, SL(", "), &except);
		zephir_array_update_string(&replace, SL(":fields"), &_11$$10, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_29$$10, "strtr", NULL, 113, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field_zv, &_29$$10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

