
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
 * @copyright   (c) 2014-2018 Ice Team
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

	zval *_21$$18, *_22$$19;
	zend_bool _0, _30$$20;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace = NULL, *di = NULL, *db = NULL, *from = NULL, *custom = NULL, *except = NULL, *tmp = NULL, *caseInsensitive = NULL, *result = NULL, *id = NULL, *_2 = NULL, *_3 = NULL, *_6 = NULL, *_9 = NULL, *_12 = NULL, *_4$$4, *_5$$5, *_7$$6, *_8$$7, *_10$$9, *_11$$10, *_13$$11, *_14$$12, *_15$$13 = NULL, *_16$$14 = NULL, *_17$$15, *_18$$15, *_19$$16, *_20$$18 = NULL, *_23$$20 = NULL, *_24$$20 = NULL, *_26$$20 = NULL, *_29$$20 = NULL, *_31$$20 = NULL, *_32$$20 = NULL, *_36$$20 = NULL, *_25$$21, *_27$$23, *_28$$24, *_33$$25 = NULL, *_34$$25, *_35$$25 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
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
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_1, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "db", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&db, di, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_LONG(_4$$4, 0);
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, 0, _4$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_5$$5);
		ZVAL_STRING(_5$$5, "from", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&from, this_ptr, "get", NULL, 0, _5$$5);
		zephir_check_temp_parameter(_5$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		ZEPHIR_INIT_VAR(_7$$6);
		ZVAL_LONG(_7$$6, 1);
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, 0, _7$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_8$$7);
		ZVAL_STRING(_8$$7, "custom", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&custom, this_ptr, "get", NULL, 0, _8$$7);
		zephir_check_temp_parameter(_8$$7);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(custom)) {
		ZEPHIR_CPY_WRT(custom, field);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 2);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_9)) {
		ZEPHIR_INIT_VAR(_10$$9);
		ZVAL_LONG(_10$$9, 2);
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, 0, _10$$9);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_11$$10);
		ZVAL_STRING(_11$$10, "except", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&except, this_ptr, "get", NULL, 0, _11$$10);
		zephir_check_temp_parameter(_11$$10);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 3);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_12)) {
		ZEPHIR_INIT_VAR(_13$$11);
		ZVAL_LONG(_13$$11, 3);
		ZEPHIR_CALL_METHOD(&caseInsensitive, this_ptr, "get", NULL, 0, _13$$11);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_14$$12);
		ZVAL_STRING(_14$$12, "caseInsensitive", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&caseInsensitive, this_ptr, "get", NULL, 0, _14$$12);
		zephir_check_temp_parameter(_14$$12);
		zephir_check_call_status();
	}
	if (zephir_is_true(caseInsensitive)) {
		ZEPHIR_CPY_WRT(tmp, value);
		ZEPHIR_CALL_METHOD(&_15$$13, db, "gettype", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(_15$$13, "NOSQL")) {
			ZEPHIR_CALL_METHOD(&_16$$14, db, "getdriver", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(value);
			if (zephir_instance_of_ev(_16$$14, ice_db_driver_mongodb_ce TSRMLS_CC)) {
				object_init_ex(value, zephir_get_internal_ce(SS("mongodb\\bson\\regex") TSRMLS_CC));
				ZEPHIR_INIT_VAR(_17$$15);
				ZEPHIR_CONCAT_SVS(_17$$15, "^", tmp, "$");
				ZEPHIR_INIT_VAR(_18$$15);
				ZVAL_STRING(_18$$15, "i", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, value, "__construct", NULL, 0, _17$$15, _18$$15);
				zephir_check_temp_parameter(_18$$15);
				zephir_check_call_status();
			} else {
				object_init_ex(value, zephir_get_internal_ce(SS("mongoregex") TSRMLS_CC));
				if (zephir_has_constructor(value TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(_19$$16);
					ZEPHIR_CONCAT_SVS(_19$$16, "/^", tmp, "$/i");
					ZEPHIR_CALL_METHOD(NULL, value, "__construct", NULL, 0, _19$$16);
					zephir_check_call_status();
				}
			}
		} else {
			ZEPHIR_INIT_NVAR(value);
			zephir_fast_strtolower(value, tmp);
		}
	}
	if (zephir_is_true(except)) {
		ZEPHIR_INIT_VAR(id);
		zephir_create_array(id, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_20$$18, db, "getidvalue", NULL, 0, except);
		zephir_check_call_status();
		zephir_array_update_string(&id, SL("!="), &_20$$18, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_21$$18);
		zephir_create_array(_21$$18, 2, 0 TSRMLS_CC);
		zephir_array_update_zval(&_21$$18, custom, &value, PH_COPY);
		ZEPHIR_CALL_METHOD(&_20$$18, db, "getid", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&_21$$18, _20$$18, &id, PH_COPY);
		ZEPHIR_CALL_METHOD(&result, db, "findone", NULL, 0, from, _21$$18);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_22$$19);
		zephir_create_array(_22$$19, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(&_22$$19, custom, &value, PH_COPY);
		ZEPHIR_CALL_METHOD(&result, db, "findone", NULL, 0, from, _22$$19);
		zephir_check_call_status();
	}
	if (zephir_is_true(result)) {
		ZEPHIR_INIT_VAR(_24$$20);
		ZVAL_STRING(_24$$20, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_23$$20, this_ptr, "has", NULL, 0, _24$$20);
		zephir_check_temp_parameter(_24$$20);
		zephir_check_call_status();
		if (zephir_is_true(_23$$20)) {
			ZEPHIR_INIT_VAR(_25$$21);
			ZVAL_STRING(_25$$21, "label", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _25$$21);
			zephir_check_temp_parameter(_25$$21);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_24$$20);
		ZVAL_STRING(_24$$20, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_26$$20, this_ptr, "has", NULL, 0, _24$$20);
		zephir_check_temp_parameter(_24$$20);
		zephir_check_call_status();
		if (zephir_is_true(_26$$20)) {
			ZEPHIR_INIT_VAR(_27$$23);
			ZVAL_STRING(_27$$23, "message", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _27$$23);
			zephir_check_temp_parameter(_27$$23);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_28$$24);
			ZVAL_STRING(_28$$24, "unique", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _28$$24);
			zephir_check_temp_parameter(_28$$24);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_29$$20, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_30$$20 = ZEPHIR_IS_TRUE_IDENTICAL(_29$$20);
		if (_30$$20) {
			ZEPHIR_CALL_METHOD(&_31$$20, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_24$$20);
			ZVAL_STRING(_24$$20, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_32$$20, _31$$20, "has", NULL, 0, _24$$20);
			zephir_check_temp_parameter(_24$$20);
			zephir_check_call_status();
			_30$$20 = zephir_is_true(_32$$20);
		}
		if (_30$$20) {
			ZEPHIR_CALL_METHOD(&_33$$25, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_34$$25);
			ZVAL_STRING(_34$$25, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _33$$25, "get", NULL, 0, _34$$25);
			zephir_check_temp_parameter(_34$$25);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_35$$25, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _35$$25);
			ZEPHIR_CALL_METHOD(&_35$$25, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _35$$25);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_36$$20, "strtr", NULL, 116, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _36$$20);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

