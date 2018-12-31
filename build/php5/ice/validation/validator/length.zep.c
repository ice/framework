
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Length validator.
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
 *      'title' => 'length:10,100',
 *      'content' => [
 *          'length' => [
 *              'max' => 1000,
 *              'messageMin' => 'Too long!',
 *              'label' => 'Desctiption'
 *          ]
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
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Length) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, Length, ice, validation_validator_length, ice_validation_validator_ce, ice_validation_validator_length_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 * Options: min (0), max (1), label, messageMin, messageMax
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_Length, validate) {

	zend_bool _0, _10, _24, _16$$12, _30$$16;
	zephir_fcall_cache_entry *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *label = NULL, *message = NULL, *i18n = NULL, *replace = NULL, *min = NULL, *max = NULL, *length = NULL, *_1 = NULL, *_2 = NULL, *_5 = NULL, *_8 = NULL, *_3$$4, *_4$$5, *_6$$6, *_7$$7, *_9$$10, *_11$$12 = NULL, *_12$$12 = NULL, *_15$$12 = NULL, *_17$$12 = NULL, *_18$$12 = NULL, *_22$$12 = NULL, *_13$$13, *_14$$14, *_19$$15 = NULL, *_20$$15, *_21$$15 = NULL, *_25$$16 = NULL, *_26$$16 = NULL, *_29$$16 = NULL, *_31$$16 = NULL, *_32$$16 = NULL, *_36$$16 = NULL, *_27$$17, *_28$$18, *_33$$19 = NULL, *_34$$19, *_35$$19 = NULL;

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
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_LONG(_3$$4, 0);
		ZEPHIR_CALL_METHOD(&min, this_ptr, "get", NULL, 0, _3$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_4$$5);
		ZVAL_STRING(_4$$5, "min", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&min, this_ptr, "get", NULL, 0, _4$$5);
		zephir_check_temp_parameter(_4$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "has", NULL, 0, _2);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_INIT_VAR(_6$$6);
		ZVAL_LONG(_6$$6, 1);
		ZEPHIR_CALL_METHOD(&max, this_ptr, "get", NULL, 0, _6$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_7$$7);
		ZVAL_STRING(_7$$7, "max", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&max, this_ptr, "get", NULL, 0, _7$$7);
		zephir_check_temp_parameter(_7$$7);
		zephir_check_call_status();
	}
	if ((zephir_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 216, value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(length);
		ZVAL_LONG(length, zephir_fast_strlen_ev(value));
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "label", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "has", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		ZEPHIR_INIT_VAR(_9$$10);
		ZVAL_STRING(_9$$10, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _9$$10);
		zephir_check_temp_parameter(_9$$10);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
		zephir_check_call_status();
	}
	_10 = zephir_is_true(min);
	if (_10) {
		_10 = ZEPHIR_LT(length, min);
	}
	if (_10) {
		ZEPHIR_INIT_VAR(_12$$12);
		ZVAL_STRING(_12$$12, "messageMin", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11$$12, this_ptr, "has", NULL, 0, _12$$12);
		zephir_check_temp_parameter(_12$$12);
		zephir_check_call_status();
		if (zephir_is_true(_11$$12)) {
			ZEPHIR_INIT_VAR(_13$$13);
			ZVAL_STRING(_13$$13, "messageMin", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _13$$13);
			zephir_check_temp_parameter(_13$$13);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_14$$14);
			ZVAL_STRING(_14$$14, "lengthMin", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _14$$14);
			zephir_check_temp_parameter(_14$$14);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_15$$12, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_16$$12 = ZEPHIR_IS_TRUE_IDENTICAL(_15$$12);
		if (_16$$12) {
			ZEPHIR_CALL_METHOD(&_17$$12, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_12$$12);
			ZVAL_STRING(_12$$12, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_18$$12, _17$$12, "has", NULL, 0, _12$$12);
			zephir_check_temp_parameter(_12$$12);
			zephir_check_call_status();
			_16$$12 = zephir_is_true(_18$$12);
		}
		if (_16$$12) {
			ZEPHIR_CALL_METHOD(&_19$$15, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_20$$15);
			ZVAL_STRING(_20$$15, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _19$$15, "get", NULL, 0, _20$$15);
			zephir_check_temp_parameter(_20$$15);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$15, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _21$$15);
			ZEPHIR_CALL_METHOD(&_21$$15, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _21$$15);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":min"), &min, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_22$$12, "strtr", &_23, 116, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _22$$12);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_24 = zephir_is_true(max);
	if (_24) {
		_24 = ZEPHIR_GT(length, max);
	}
	if (_24) {
		ZEPHIR_INIT_VAR(_26$$16);
		ZVAL_STRING(_26$$16, "messageMax", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_25$$16, this_ptr, "has", NULL, 0, _26$$16);
		zephir_check_temp_parameter(_26$$16);
		zephir_check_call_status();
		if (zephir_is_true(_25$$16)) {
			ZEPHIR_INIT_VAR(_27$$17);
			ZVAL_STRING(_27$$17, "messageMax", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _27$$17);
			zephir_check_temp_parameter(_27$$17);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_28$$18);
			ZVAL_STRING(_28$$18, "lengthMax", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _28$$18);
			zephir_check_temp_parameter(_28$$18);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_29$$16, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_30$$16 = ZEPHIR_IS_TRUE_IDENTICAL(_29$$16);
		if (_30$$16) {
			ZEPHIR_CALL_METHOD(&_31$$16, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_26$$16);
			ZVAL_STRING(_26$$16, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_32$$16, _31$$16, "has", NULL, 0, _26$$16);
			zephir_check_temp_parameter(_26$$16);
			zephir_check_call_status();
			_30$$16 = zephir_is_true(_32$$16);
		}
		if (_30$$16) {
			ZEPHIR_CALL_METHOD(&_33$$19, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_34$$19);
			ZVAL_STRING(_34$$19, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _33$$19, "get", NULL, 0, _34$$19);
			zephir_check_temp_parameter(_34$$19);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_35$$19, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _35$$19);
			ZEPHIR_CALL_METHOD(&_35$$19, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _35$$19);
		}
		ZEPHIR_INIT_NVAR(replace);
		zephir_create_array(replace, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replace, SL(":max"), &max, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_36$$16, "strtr", &_23, 116, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _36$$16);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

