
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
#include "kernel/object.h"
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
 * @copyright   (c) 2014-2016 Ice Team
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
 * Options: from (0), custom (1), except (2), caseInsensitive (3), label, message
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Unique, validate) {

	zval _21$$18, _22$$19;
	zephir_nts_static zend_class_entry *_17$$15 = NULL;
	zend_bool _0, _30$$20;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, label, message, i18n, replace, di, db, from, custom, except, tmp, caseInsensitive, result, id, _2, _3, _4, _7, _10, _13, _5$$4, _6$$5, _8$$6, _9$$7, _11$$9, _12$$10, _14$$11, _15$$12, _16$$13, _18$$15, _19$$16, _20$$18, _23$$20, _24$$20, _26$$20, _29$$20, _31$$20, _32$$20, _36$$20, _25$$21, _27$$23, _28$$24, _33$$25, _34$$25, _35$$25;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validation_sub);
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
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&caseInsensitive);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_27$$23);
	ZVAL_UNDEF(&_28$$24);
	ZVAL_UNDEF(&_33$$25);
	ZVAL_UNDEF(&_34$$25);
	ZVAL_UNDEF(&_35$$25);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_22$$19);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
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
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_1, 1);
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
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, 0, &_11$$9);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_12$$10);
		ZVAL_STRING(&_12$$10, "except");
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, 0, &_12$$10);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_4, 3);
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "has", NULL, 0, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_13)) {
		ZVAL_LONG(&_14$$11, 3);
		ZEPHIR_CALL_METHOD(&caseInsensitive, this_ptr, "get", NULL, 0, &_14$$11);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_15$$12);
		ZVAL_STRING(&_15$$12, "caseInsensitive");
		ZEPHIR_CALL_METHOD(&caseInsensitive, this_ptr, "get", NULL, 0, &_15$$12);
		zephir_check_call_status();
	}
	if (zephir_is_true(&caseInsensitive)) {
		ZEPHIR_CPY_WRT(&tmp, &value);
		ZEPHIR_CALL_METHOD(&_16$$13, &db, "gettype", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(&_16$$13, "NOSQL")) {
			ZEPHIR_INIT_NVAR(&value);
			if (zephir_instance_of_ev(&db, ice_db_driver_mongodb_ce TSRMLS_CC)) {
				if (!_17$$15) {
				_17$$15 = zephir_fetch_class_str_ex(SL("MongoDB\\BSON\\Regex"), ZEND_FETCH_CLASS_AUTO);
				}
				object_init_ex(&value, _17$$15);
				if (zephir_has_constructor(&value TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(&_18$$15);
					ZVAL_STRING(&_18$$15, "i");
					ZEPHIR_CALL_METHOD(NULL, &value, "__construct", NULL, 0, &tmp, &_18$$15);
					zephir_check_call_status();
				}
			} else {
				object_init_ex(&value, zephir_get_internal_ce(SL("mongoregex")));
				if (zephir_has_constructor(&value TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(&_19$$16);
					ZEPHIR_CONCAT_SVS(&_19$$16, "/^", &tmp, "$/i");
					ZEPHIR_CALL_METHOD(NULL, &value, "__construct", NULL, 0, &_19$$16);
					zephir_check_call_status();
				}
			}
		} else {
			ZEPHIR_INIT_NVAR(&value);
			zephir_fast_strtolower(&value, &tmp);
		}
	}
	if (zephir_is_true(&except)) {
		ZEPHIR_INIT_VAR(&id);
		zephir_create_array(&id, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_20$$18, &db, "getidvalue", NULL, 0, &except);
		zephir_check_call_status();
		zephir_array_update_string(&id, SL("!="), &_20$$18, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_21$$18);
		zephir_create_array(&_21$$18, 2, 0 TSRMLS_CC);
		zephir_array_update_zval(&_21$$18, &custom, &value, PH_COPY);
		ZEPHIR_CALL_METHOD(&_20$$18, &db, "getid", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&_21$$18, &_20$$18, &id, PH_COPY);
		ZEPHIR_CALL_METHOD(&result, &db, "findone", NULL, 0, &from, &_21$$18);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_22$$19);
		zephir_create_array(&_22$$19, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(&_22$$19, &custom, &value, PH_COPY);
		ZEPHIR_CALL_METHOD(&result, &db, "findone", NULL, 0, &from, &_22$$19);
		zephir_check_call_status();
	}
	if (zephir_is_true(&result)) {
		ZEPHIR_INIT_VAR(&_24$$20);
		ZVAL_STRING(&_24$$20, "label");
		ZEPHIR_CALL_METHOD(&_23$$20, this_ptr, "has", NULL, 0, &_24$$20);
		zephir_check_call_status();
		if (zephir_is_true(&_23$$20)) {
			ZEPHIR_INIT_VAR(&_25$$21);
			ZVAL_STRING(&_25$$21, "label");
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_25$$21);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_24$$20);
		ZVAL_STRING(&_24$$20, "message");
		ZEPHIR_CALL_METHOD(&_26$$20, this_ptr, "has", NULL, 0, &_24$$20);
		zephir_check_call_status();
		if (zephir_is_true(&_26$$20)) {
			ZEPHIR_INIT_VAR(&_27$$23);
			ZVAL_STRING(&_27$$23, "message");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_27$$23);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_28$$24);
			ZVAL_STRING(&_28$$24, "unique");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_28$$24);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_29$$20, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_30$$20 = ZEPHIR_IS_TRUE_IDENTICAL(&_29$$20);
		if (_30$$20) {
			ZEPHIR_CALL_METHOD(&_31$$20, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_24$$20);
			ZVAL_STRING(&_24$$20, "i18n");
			ZEPHIR_CALL_METHOD(&_32$$20, &_31$$20, "has", NULL, 0, &_24$$20);
			zephir_check_call_status();
			_30$$20 = zephir_is_true(&_32$$20);
		}
		if (_30$$20) {
			ZEPHIR_CALL_METHOD(&_33$$25, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_34$$25);
			ZVAL_STRING(&_34$$25, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_33$$25, "get", NULL, 0, &_34$$25);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_35$$25, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_35$$25);
			ZEPHIR_CALL_METHOD(&_35$$25, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_35$$25);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_36$$20, "strtr", NULL, 87, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_36$$20);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

