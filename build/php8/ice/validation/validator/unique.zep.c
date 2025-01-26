
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
 * Unique validator.
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Unique)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Unique, ice, validation_validator_unique, ice_validation_validator_ce, ice_validation_validator_unique_method_entry, 0);

	return SUCCESS;
}

/**
 * Validate the validator
 * Options: from (0), custom (1), except (2), insensitive (3), label, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Unique, validate)
{
	zval _16$$13, _17$$14;
	zend_bool _0, _25$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, __$true, value, label, message, i18n, replace, di, db, from, custom, except, insensitive, options, result, id, _1, _2, _3, _6, _9, _12, _4$$4, _5$$5, _7$$6, _8$$7, _10$$9, _11$$10, _13$$11, _14$$12, _15$$13, _18$$15, _19$$15, _21$$15, _24$$15, _26$$15, _27$$15, _31$$15, _20$$16, _22$$18, _23$$19, _28$$20, _29$$20, _30$$20;
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
	ZVAL_UNDEF(&except);
	ZVAL_UNDEF(&insensitive);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_23$$19);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$14);
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
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, 0, &_10$$9);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_11$$10);
		ZVAL_STRING(&_11$$10, "except");
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, 0, &_11$$10);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "has", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_12)) {
		ZVAL_LONG(&_13$$11, 3);
		ZEPHIR_CALL_METHOD(&insensitive, this_ptr, "get", NULL, 0, &_13$$11);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_14$$12);
		ZVAL_STRING(&_14$$12, "insensitive");
		ZEPHIR_CALL_METHOD(&insensitive, this_ptr, "get", NULL, 0, &_14$$12);
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
	if (zephir_is_true(&except)) {
		ZEPHIR_INIT_VAR(&id);
		zephir_create_array(&id, 1, 0);
		ZEPHIR_CALL_METHOD(&_15$$13, &db, "getidvalue", NULL, 0, &except);
		zephir_check_call_status();
		zephir_array_update_string(&id, SL("!="), &_15$$13, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_16$$13);
		zephir_create_array(&_16$$13, 2, 0);
		zephir_array_update_zval(&_16$$13, &custom, &value, PH_COPY);
		ZEPHIR_CALL_METHOD(&_15$$13, &db, "getid", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&_16$$13, &_15$$13, &id, PH_COPY);
		ZEPHIR_CALL_METHOD(&result, &db, "findone", NULL, 0, &from, &_16$$13, &options);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_17$$14);
		zephir_create_array(&_17$$14, 1, 0);
		zephir_array_update_zval(&_17$$14, &custom, &value, PH_COPY);
		ZEPHIR_CALL_METHOD(&result, &db, "findone", NULL, 0, &from, &_17$$14, &options);
		zephir_check_call_status();
	}
	if (zephir_is_true(&result)) {
		ZEPHIR_INIT_VAR(&_19$$15);
		ZVAL_STRING(&_19$$15, "label");
		ZEPHIR_CALL_METHOD(&_18$$15, this_ptr, "has", NULL, 0, &_19$$15);
		zephir_check_call_status();
		if (zephir_is_true(&_18$$15)) {
			ZEPHIR_INIT_VAR(&_20$$16);
			ZVAL_STRING(&_20$$16, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_20$$16);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_19$$15);
		ZVAL_STRING(&_19$$15, "message");
		ZEPHIR_CALL_METHOD(&_21$$15, this_ptr, "has", NULL, 0, &_19$$15);
		zephir_check_call_status();
		if (zephir_is_true(&_21$$15)) {
			ZEPHIR_INIT_VAR(&_22$$18);
			ZVAL_STRING(&_22$$18, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_22$$18);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_23$$19);
			ZVAL_STRING(&_23$$19, "unique");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_23$$19);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_24$$15, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_25$$15 = ZEPHIR_IS_TRUE_IDENTICAL(&_24$$15);
		if (_25$$15) {
			ZEPHIR_CALL_METHOD(&_26$$15, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_19$$15);
			ZVAL_STRING(&_19$$15, "i18n");
			ZEPHIR_CALL_METHOD(&_27$$15, &_26$$15, "has", NULL, 0, &_19$$15);
			zephir_check_call_status();
			_25$$15 = zephir_is_true(&_27$$15);
		}
		if (_25$$15) {
			ZEPHIR_CALL_METHOD(&_28$$20, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_29$$20);
			ZVAL_STRING(&_29$$20, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_28$$20, "get", NULL, 0, &_29$$20);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_30$$20, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_30$$20);
			ZEPHIR_CALL_METHOD(&_30$$20, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_30$$20);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 1, 0);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_31$$15, "strtr", NULL, 112, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_31$$15);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

