
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

	zval *_20$$16, *_21$$17;
	zend_bool _0, _29$$18;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace = NULL, *di = NULL, *db = NULL, *from = NULL, *custom = NULL, *except = NULL, *tmp = NULL, *caseInsensitive = NULL, *result = NULL, *id = NULL, *_2 = NULL, *_3, *_4, *_5 = NULL, *_8 = NULL, *_11 = NULL, *_14 = NULL, *_6$$4, *_7$$5, *_9$$6, *_10$$7, *_12$$9, *_13$$10, *_15$$11, *_16$$12, *_17$$13 = NULL, *_18$$14, *_19$$16 = NULL, *_22$$18 = NULL, *_23$$18 = NULL, *_25$$18 = NULL, *_28$$18 = NULL, *_30$$18 = NULL, *_31$$18 = NULL, *_35$$18 = NULL, *_24$$19, *_26$$21, *_27$$22, *_32$$23 = NULL, *_33$$23, *_34$$23 = NULL;

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
		ZEPHIR_INIT_VAR(_6$$4);
		ZVAL_LONG(_6$$4, 0);
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, 0, _6$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_7$$5);
		ZVAL_STRING(_7$$5, "from", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, 0, _7$$5);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		ZEPHIR_INIT_VAR(_9$$6);
		ZVAL_LONG(_9$$6, 1);
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, 0, _9$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_10$$7);
		ZVAL_STRING(_10$$7, "custom", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, 0, _10$$7);
		zephir_check_temp_parameter(_10$$7);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(custom)) {
		ZEPHIR_CPY_WRT(custom, field);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 2);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_11)) {
		ZEPHIR_INIT_VAR(_12$$9);
		ZVAL_LONG(_12$$9, 2);
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, 0, _12$$9);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_13$$10);
		ZVAL_STRING(_13$$10, "except", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, 0, _13$$10);
		zephir_check_temp_parameter(_13$$10);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 3);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_14)) {
		ZEPHIR_INIT_VAR(_15$$11);
		ZVAL_LONG(_15$$11, 3);
		ZEPHIR_CALL_METHOD(&caseInsensitive, this_ptr, "get", NULL, 0, _15$$11);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_16$$12);
		ZVAL_STRING(_16$$12, "caseInsensitive", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&caseInsensitive, this_ptr, "get", NULL, 0, _16$$12);
		zephir_check_temp_parameter(_16$$12);
		zephir_check_call_status();
	}
	if (zephir_is_true(caseInsensitive)) {
		ZEPHIR_CPY_WRT(tmp, value);
		ZEPHIR_CALL_METHOD(&_17$$13, db, "gettype", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(_17$$13, "NOSQL")) {
			ZEPHIR_INIT_NVAR(value);
			object_init_ex(value, zephir_get_internal_ce(SS("mongoregex") TSRMLS_CC));
			if (zephir_has_constructor(value TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_18$$14);
				ZEPHIR_CONCAT_SVS(_18$$14, "/^", tmp, "$/i");
				ZEPHIR_CALL_METHOD(NULL, value, "__construct", NULL, 0, _18$$14);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_INIT_NVAR(value);
			zephir_fast_strtolower(value, tmp);
		}
	}
	if (zephir_is_true(except)) {
		ZEPHIR_INIT_VAR(id);
		zephir_create_array(id, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_19$$16, db, "getidvalue", NULL, 0, except);
		zephir_check_call_status();
		zephir_array_update_string(&id, SL("!="), &_19$$16, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_20$$16);
		zephir_create_array(_20$$16, 2, 0 TSRMLS_CC);
		zephir_array_update_zval(&_20$$16, custom, &value, PH_COPY);
		ZEPHIR_CALL_METHOD(&_19$$16, db, "getid", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&_20$$16, _19$$16, &id, PH_COPY);
		ZEPHIR_CALL_METHOD(&result, db, "findone", NULL, 0, from, _20$$16);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_21$$17);
		zephir_create_array(_21$$17, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(&_21$$17, custom, &value, PH_COPY);
		ZEPHIR_CALL_METHOD(&result, db, "findone", NULL, 0, from, _21$$17);
		zephir_check_call_status();
	}
	if (zephir_is_true(result)) {
		ZEPHIR_INIT_VAR(_23$$18);
		ZVAL_STRING(_23$$18, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_22$$18, this_ptr, "has", NULL, 0, _23$$18);
		zephir_check_temp_parameter(_23$$18);
		zephir_check_call_status();
		if (zephir_is_true(_22$$18)) {
			ZEPHIR_INIT_VAR(_24$$19);
			ZVAL_STRING(_24$$19, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _24$$19);
			zephir_check_temp_parameter(_24$$19);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_23$$18);
		ZVAL_STRING(_23$$18, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_25$$18, this_ptr, "has", NULL, 0, _23$$18);
		zephir_check_temp_parameter(_23$$18);
		zephir_check_call_status();
		if (zephir_is_true(_25$$18)) {
			ZEPHIR_INIT_VAR(_26$$21);
			ZVAL_STRING(_26$$21, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _26$$21);
			zephir_check_temp_parameter(_26$$21);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_27$$22);
			ZVAL_STRING(_27$$22, "unique", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _27$$22);
			zephir_check_temp_parameter(_27$$22);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_28$$18, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_29$$18 = ZEPHIR_IS_TRUE_IDENTICAL(_28$$18);
		if (_29$$18) {
			ZEPHIR_CALL_METHOD(&_30$$18, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_23$$18);
			ZVAL_STRING(_23$$18, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_31$$18, _30$$18, "has", NULL, 0, _23$$18);
			zephir_check_temp_parameter(_23$$18);
			zephir_check_call_status();
			_29$$18 = zephir_is_true(_31$$18);
		}
		if (_29$$18) {
			ZEPHIR_CALL_METHOD(&_32$$23, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_33$$23);
			ZVAL_STRING(_33$$23, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _32$$23, "get", NULL, 0, _33$$23);
			zephir_check_temp_parameter(_33$$23);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_34$$23, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _34$$23);
			ZEPHIR_CALL_METHOD(&_34$$23, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _34$$23);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_35$$18, "strtr", NULL, 82, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _35$$18);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

