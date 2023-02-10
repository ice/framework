
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
 * @copyright   (c) 2014-2023 Ice Team
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
	zval _13;
	zend_bool _0, _21$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, __$true, value, label, message, i18n, replace, di, db, from, custom, insensitive, options, result, _2, _3, _4, _7, _10, _5$$4, _6$$5, _8$$6, _9$$7, _11$$9, _12$$10, _14$$11, _15$$11, _17$$11, _20$$11, _22$$11, _23$$11, _27$$11, _16$$12, _18$$14, _19$$15, _24$$16, _25$$16, _26$$16;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_13);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, ice_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "db");
	ZEPHIR_CALL_METHOD(&db, &di, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "has", NULL, 0, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZVAL_LONG(&_5$$4, 0);
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, 0, &_5$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "from");
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, 0, &_6$$5);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "has", NULL, 0, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZVAL_LONG(&_8$$6, 1);
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, 0, &_8$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_9$$7);
		ZVAL_STRING(&_9$$7, "custom");
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, 0, &_9$$7);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(&custom)) {
		ZEPHIR_CPY_WRT(&custom, &field);
	}
	ZVAL_LONG(&_4, 2);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "has", NULL, 0, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_10)) {
		ZVAL_LONG(&_11$$9, 2);
		ZEPHIR_CALL_METHOD(&insensitive, this_ptr, "get", NULL, 0, &_11$$9);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_12$$10);
		ZVAL_STRING(&_12$$10, "insensitive");
		ZEPHIR_CALL_METHOD(&insensitive, this_ptr, "get", NULL, 0, &_12$$10);
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
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 1, 0);
	zephir_array_update_zval(&_13, &custom, &value, PH_COPY);
	ZEPHIR_CALL_METHOD(&result, &db, "findone", NULL, 0, &from, &_13, &options);
	zephir_check_call_status();
	if (!(zephir_is_true(&result))) {
		ZEPHIR_INIT_VAR(&_15$$11);
		ZVAL_STRING(&_15$$11, "label");
		ZEPHIR_CALL_METHOD(&_14$$11, this_ptr, "has", NULL, 0, &_15$$11);
		zephir_check_call_status();
		if (zephir_is_true(&_14$$11)) {
			ZEPHIR_INIT_VAR(&_16$$12);
			ZVAL_STRING(&_16$$12, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_16$$12);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_15$$11);
		ZVAL_STRING(&_15$$11, "message");
		ZEPHIR_CALL_METHOD(&_17$$11, this_ptr, "has", NULL, 0, &_15$$11);
		zephir_check_call_status();
		if (zephir_is_true(&_17$$11)) {
			ZEPHIR_INIT_VAR(&_18$$14);
			ZVAL_STRING(&_18$$14, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_18$$14);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_19$$15);
			ZVAL_STRING(&_19$$15, "exists");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_19$$15);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_20$$11, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_21$$11 = ZEPHIR_IS_TRUE_IDENTICAL(&_20$$11);
		if (_21$$11) {
			ZEPHIR_CALL_METHOD(&_22$$11, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_15$$11);
			ZVAL_STRING(&_15$$11, "i18n");
			ZEPHIR_CALL_METHOD(&_23$$11, &_22$$11, "has", NULL, 0, &_15$$11);
			zephir_check_call_status();
			_21$$11 = zephir_is_true(&_23$$11);
		}
		if (_21$$11) {
			ZEPHIR_CALL_METHOD(&_24$$16, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_25$$16);
			ZVAL_STRING(&_25$$16, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_24$$16, "get", NULL, 0, &_25$$16);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_26$$16, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_26$$16);
			ZEPHIR_CALL_METHOD(&_26$$16, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_26$$16);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 1, 0);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_27$$11, "strtr", NULL, 111, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_27$$11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

