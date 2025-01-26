
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"


/**
 * Exists validator.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2025 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *
 *  $validation->rules([
 *      'userName' => [
 *          'exists' => [
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Exists)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Exists, ice, validation_validator_exists, ice_validation_validator_ce, ice_validation_validator_exists_method_entry, 0);

	return SUCCESS;
}

/**
 * Validate the validator
 * Options: from (0), custom (1), insensitive (2), label, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Exists, validate)
{
	zval _12;
	zend_bool _0, _20$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, __$true, value, label, message, i18n, replace, di, db, from, custom, insensitive, options, result, _1, _2, _3, _6, _9, _4$$4, _5$$5, _7$$6, _8$$7, _10$$9, _11$$10, _13$$11, _14$$11, _16$$11, _19$$11, _21$$11, _22$$11, _26$$11, _15$$12, _17$$14, _18$$15, _23$$16, _24$$16, _25$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&db);
	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&custom);
	ZVAL_UNDEF(&insensitive);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_12);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, ice_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field_param);
	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
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
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "db");
	ZEPHIR_CALL_METHOD(&db, &di, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "has", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZVAL_LONG(&_4$$4, 0);
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, 0, &_4$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "from");
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, 0, &_5$$5);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "has", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		ZVAL_LONG(&_7$$6, 1);
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, 0, &_7$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_8$$7);
		ZVAL_STRING(&_8$$7, "custom");
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, 0, &_8$$7);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(&custom)) {
		ZEPHIR_CPY_WRT(&custom, &field);
	}
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "has", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_9)) {
		ZVAL_LONG(&_10$$9, 2);
		ZEPHIR_CALL_METHOD(&insensitive, this_ptr, "get", NULL, 0, &_10$$9);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_11$$10);
		ZVAL_STRING(&_11$$10, "insensitive");
		ZEPHIR_CALL_METHOD(&insensitive, this_ptr, "get", NULL, 0, &_11$$10);
		zephir_check_call_status();
	}
	if (zephir_is_true(&insensitive)) {
		ZEPHIR_INIT_VAR(&options);
		zephir_create_array(&options, 1, 0);
		zephir_array_update_string(&options, SL("insensitive"), &__$true, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(&options);
		array_init(&options);
	}
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 1, 0);
	zephir_array_update_zval(&_12, &custom, &value, PH_COPY);
	ZEPHIR_CALL_METHOD(&result, &db, "findone", NULL, 0, &from, &_12, &options);
	zephir_check_call_status();
	if (!(zephir_is_true(&result))) {
		ZEPHIR_INIT_VAR(&_14$$11);
		ZVAL_STRING(&_14$$11, "label");
		ZEPHIR_CALL_METHOD(&_13$$11, this_ptr, "has", NULL, 0, &_14$$11);
		zephir_check_call_status();
		if (zephir_is_true(&_13$$11)) {
			ZEPHIR_INIT_VAR(&_15$$12);
			ZVAL_STRING(&_15$$12, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_15$$12);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_14$$11);
		ZVAL_STRING(&_14$$11, "message");
		ZEPHIR_CALL_METHOD(&_16$$11, this_ptr, "has", NULL, 0, &_14$$11);
		zephir_check_call_status();
		if (zephir_is_true(&_16$$11)) {
			ZEPHIR_INIT_VAR(&_17$$14);
			ZVAL_STRING(&_17$$14, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_17$$14);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_18$$15);
			ZVAL_STRING(&_18$$15, "exists");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_18$$15);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_19$$11, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_20$$11 = ZEPHIR_IS_TRUE_IDENTICAL(&_19$$11);
		if (_20$$11) {
			ZEPHIR_CALL_METHOD(&_21$$11, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_14$$11);
			ZVAL_STRING(&_14$$11, "i18n");
			ZEPHIR_CALL_METHOD(&_22$$11, &_21$$11, "has", NULL, 0, &_14$$11);
			zephir_check_call_status();
			_20$$11 = zephir_is_true(&_22$$11);
		}
		if (_20$$11) {
			ZEPHIR_CALL_METHOD(&_23$$16, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_24$$16);
			ZVAL_STRING(&_24$$16, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_23$$16, "get", NULL, 0, &_24$$16);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_25$$16, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_25$$16);
			ZEPHIR_CALL_METHOD(&_25$$16, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_25$$16);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 1, 0);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_26$$11, "strtr", NULL, 112, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_26$$11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

