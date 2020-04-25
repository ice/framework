
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
#include "kernel/object.h"


/**
 * With validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2020 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *
 *  $validation->rules([
 *      'repeatPassword' => [
 *          'with' => [
 *              'fields' => ['password'],
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_With) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, With, ice, validation_validator_with, ice_validation_validator_ce, ice_validation_validator_with_method_entry, 0);

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
PHP_METHOD(Ice_Validation_Validator_With, validate) {

	zend_string *_23$$15;
	zend_ulong _22$$15;
	zend_bool _0, _5$$6, _6$$8, _14$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_25 = NULL, *_27 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, label, message, i18n, replace, fields, with, tmp, required, key, translate, _1, *_3, _4, _2$$4, _7$$10, _8$$10, _10$$10, _13$$10, _15$$10, _16$$10, _28$$10, _9$$11, _11$$13, _12$$14, _17$$15, _18$$15, _19$$15, *_20$$15, _21$$15, _24$$16, _26$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&with);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&required);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&translate);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&field);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string"));
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
	ZEPHIR_INIT_VAR(&required);
	array_init(&required);
	if (ZEPHIR_IS_EMPTY(&fields)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "fields");
		ZEPHIR_CALL_METHOD(&fields, this_ptr, "get", NULL, 0, &_2$$4);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&fields) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Fields must be an array", "ice/validation/validator/with.zep", 63);
		return;
	}
	zephir_is_iterable(&fields, 0, "ice/validation/validator/with.zep", 74);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _3)
		{
			ZEPHIR_INIT_NVAR(&with);
			ZVAL_COPY(&with, _3);
			ZEPHIR_CALL_METHOD(&tmp, validation, "getvalue", NULL, 0, &with);
			zephir_check_call_status();
			_5$$6 = ZEPHIR_IS_STRING_IDENTICAL(&tmp, "");
			if (!(_5$$6)) {
				_5$$6 = Z_TYPE_P(&tmp) == IS_NULL;
			}
			if (_5$$6) {
				zephir_array_append(&required, &with, PH_SEPARATE, "ice/validation/validator/with.zep", 70);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&with, &fields, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&tmp, validation, "getvalue", NULL, 0, &with);
				zephir_check_call_status();
				_6$$8 = ZEPHIR_IS_STRING_IDENTICAL(&tmp, "");
				if (!(_6$$8)) {
					_6$$8 = Z_TYPE_P(&tmp) == IS_NULL;
				}
				if (_6$$8) {
					zephir_array_append(&required, &with, PH_SEPARATE, "ice/validation/validator/with.zep", 70);
				}
			ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&with);
	if (zephir_fast_count_int(&required)) {
		ZEPHIR_INIT_VAR(&_8$$10);
		ZVAL_STRING(&_8$$10, "label");
		ZEPHIR_CALL_METHOD(&_7$$10, this_ptr, "has", NULL, 0, &_8$$10);
		zephir_check_call_status();
		if (zephir_is_true(&_7$$10)) {
			ZEPHIR_INIT_VAR(&_9$$11);
			ZVAL_STRING(&_9$$11, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_9$$11);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_8$$10);
		ZVAL_STRING(&_8$$10, "message");
		ZEPHIR_CALL_METHOD(&_10$$10, this_ptr, "has", NULL, 0, &_8$$10);
		zephir_check_call_status();
		if (zephir_is_true(&_10$$10)) {
			ZEPHIR_INIT_VAR(&_11$$13);
			ZVAL_STRING(&_11$$13, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_11$$13);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_12$$14);
			ZVAL_STRING(&_12$$14, "with");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_12$$14);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_13$$10, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_14$$10 = ZEPHIR_IS_TRUE_IDENTICAL(&_13$$10);
		if (_14$$10) {
			ZEPHIR_CALL_METHOD(&_15$$10, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$10);
			ZVAL_STRING(&_8$$10, "i18n");
			ZEPHIR_CALL_METHOD(&_16$$10, &_15$$10, "has", NULL, 0, &_8$$10);
			zephir_check_call_status();
			_14$$10 = zephir_is_true(&_16$$10);
		}
		if (_14$$10) {
			ZEPHIR_CALL_METHOD(&_17$$15, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_18$$15);
			ZVAL_STRING(&_18$$15, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_17$$15, "get", NULL, 0, &_18$$15);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_19$$15, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_19$$15);
			ZEPHIR_CALL_METHOD(&_19$$15, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_19$$15);
			zephir_is_iterable(&required, 1, "ice/validation/validator/with.zep", 96);
			if (Z_TYPE_P(&required) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&required), _22$$15, _23$$15, _20$$15)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_23$$15 != NULL) { 
						ZVAL_STR_COPY(&key, _23$$15);
					} else {
						ZVAL_LONG(&key, _22$$15);
					}
					ZEPHIR_INIT_NVAR(&translate);
					ZVAL_COPY(&translate, _20$$15);
					ZEPHIR_CALL_METHOD(&_24$$16, &i18n, "translate", &_25, 0, &translate);
					zephir_check_call_status();
					zephir_array_update_zval(&required, &key, &_24$$16, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &required, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_21$$15, &required, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_21$$15)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, &required, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&translate, &required, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_26$$17, &i18n, "translate", &_27, 0, &translate);
						zephir_check_call_status();
						zephir_array_update_zval(&required, &key, &_26$$17, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &required, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&translate);
			ZEPHIR_INIT_NVAR(&key);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 2, 0);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_8$$10);
		zephir_fast_join_str(&_8$$10, SL(", "), &required);
		zephir_array_update_string(&replace, SL(":fields"), &_8$$10, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_28$$10, "strtr", NULL, 110, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_28$$10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

