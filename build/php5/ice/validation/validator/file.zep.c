
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


/**
 * File validator.
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
 *      'picture' => [
 *          'file' => [
 *              'maxSize' => '6M',
 *              'allowedTypes' => ['image/jpeg', 'image/png'],
 *              'minResolution' => '400x300',
 *              'maxResolution' => '1600x1200',
 *          ]
 *      ]
 *  ]);
 *  
 *  $valid = $validation->validate($_FILES);
 *  
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
ZEPHIR_INIT_CLASS(Ice_Validation_Validator_File) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Validation\\Validator, File, ice, validation_validator_file, ice_validation_validator_ce, ice_validation_validator_file_method_entry, 0);

	return SUCCESS;

}

/**
 * Validate the validator
 * Options: label, messageIniSize, allowEmpty, messageEmpty, messageValid, maxSize, messageSize, allowedTypes, messageType
 * minResolution, maxResolution, messageMinResolution, messageMaxResolution
 *
 * @param Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Ice_Validation_Validator_File, validate) {

	zend_bool _4, _5, _6, _8, _9, _25, _26, _27, _29, _30, _32, _47, _48, _103, _16$$5, _40$$10, _54$$14, _79$$20, _95$$28, _110$$32, _116$$35, _126$$39, _132$$40;
	zephir_fcall_cache_entry *_23 = NULL, *_68 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *_SERVER, *_POST, *_FILES, *value = NULL, *message = NULL, *label = NULL, *i18n = NULL, *replace = NULL, *types = NULL, *byteUnits = NULL, *unit = NULL, *maxSize = NULL, *matches = NULL, *bytes = NULL, *mime = NULL, *tmp = NULL, *width = NULL, *height = NULL, *minResolution = NULL, *maxResolution = NULL, *minWidth = NULL, *maxWidth = NULL, *minHeight = NULL, *maxHeight = NULL, *_0 = NULL, *_1 = NULL, *_3, *_7, *_10, *_24 = NULL, *_28, *_31, *_33, *_34 = NULL, *_61 = NULL, *_86 = NULL, *_102 = NULL, *_104 = NULL, *_2$$3, *_11$$5 = NULL, *_12$$5 = NULL, *_15$$5 = NULL, *_17$$5 = NULL, *_18$$5 = NULL, *_22$$5 = NULL, *_13$$6, *_14$$7, *_19$$8 = NULL, *_20$$8, *_21$$8 = NULL, *_35$$10 = NULL, *_36$$10 = NULL, *_39$$10 = NULL, *_41$$10 = NULL, *_42$$10 = NULL, *_46$$10 = NULL, *_37$$11, *_38$$12, *_43$$13 = NULL, *_44$$13, *_45$$13 = NULL, *_49$$14 = NULL, *_50$$14 = NULL, *_53$$14 = NULL, *_55$$14 = NULL, *_56$$14 = NULL, *_60$$14 = NULL, *_51$$15, *_52$$16, *_57$$17 = NULL, *_58$$17, *_59$$17 = NULL, *_62$$18 = NULL, *_63$$18, *_64$$18, *_65$$18, *_66$$18, *_67$$18 = NULL, *_69$$18, *_70$$18, _71$$18, *_72$$18, *_73$$18 = NULL, *_74$$20 = NULL, *_75$$20 = NULL, *_78$$20 = NULL, *_80$$20 = NULL, *_81$$20 = NULL, *_85$$20 = NULL, *_76$$21, *_77$$22, *_82$$23 = NULL, *_83$$23, *_84$$23 = NULL, *_87$$24, _88$$26, *_89$$26, *_90$$28 = NULL, *_91$$28 = NULL, *_94$$28 = NULL, *_96$$28 = NULL, *_97$$28 = NULL, *_101$$28 = NULL, *_92$$29, *_93$$30, *_98$$31 = NULL, *_99$$31, *_100$$31 = NULL, *_105$$32, *_106$$32 = NULL, *_107$$32 = NULL, *_123$$32 = NULL, *_108$$33 = NULL, *_109$$33, *_111$$35 = NULL, *_112$$35 = NULL, *_115$$35 = NULL, *_117$$35 = NULL, *_118$$35 = NULL, *_122$$35 = NULL, *_113$$36, *_114$$37, *_119$$38 = NULL, *_120$$38, *_121$$38 = NULL, *_124$$39 = NULL, *_125$$39, *_127$$40 = NULL, *_128$$40 = NULL, *_131$$40 = NULL, *_133$$40 = NULL, *_134$$40 = NULL, *_138$$40 = NULL, *_129$$41, *_130$$42, *_135$$43 = NULL, *_136$$43, *_137$$43 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
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
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
		zephir_check_call_status();
	}
	zephir_array_fetch_string(&_3, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 63 TSRMLS_CC);
	_4 = ZEPHIR_IS_STRING(_3, "POST");
	if (_4) {
		_4 = ZEPHIR_IS_EMPTY(_POST);
	}
	_5 = _4;
	if (_5) {
		_5 = ZEPHIR_IS_EMPTY(_FILES);
	}
	_6 = _5;
	if (_6) {
		zephir_array_fetch_string(&_7, _SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 63 TSRMLS_CC);
		_6 = ZEPHIR_GT_LONG(_7, 0);
	}
	_8 = _6;
	if (!(_8)) {
		_9 = zephir_array_isset_string(value, SS("error"));
		if (_9) {
			zephir_array_fetch_string(&_10, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 63 TSRMLS_CC);
			_9 = ZEPHIR_IS_LONG_IDENTICAL(_10, 1);
		}
		_8 = _9;
	}
	if (_8) {
		ZEPHIR_INIT_VAR(_12$$5);
		ZVAL_STRING(_12$$5, "messageIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "has", NULL, 0, _12$$5);
		zephir_check_temp_parameter(_12$$5);
		zephir_check_call_status();
		if (zephir_is_true(_11$$5)) {
			ZEPHIR_INIT_VAR(_13$$6);
			ZVAL_STRING(_13$$6, "messageIniSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _13$$6);
			zephir_check_temp_parameter(_13$$6);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_14$$7);
			ZVAL_STRING(_14$$7, "fileIniSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _14$$7);
			zephir_check_temp_parameter(_14$$7);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_15$$5, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_16$$5 = ZEPHIR_IS_TRUE_IDENTICAL(_15$$5);
		if (_16$$5) {
			ZEPHIR_CALL_METHOD(&_17$$5, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_12$$5);
			ZVAL_STRING(_12$$5, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_18$$5, _17$$5, "has", NULL, 0, _12$$5);
			zephir_check_temp_parameter(_12$$5);
			zephir_check_call_status();
			_16$$5 = zephir_is_true(_18$$5);
		}
		if (_16$$5) {
			ZEPHIR_CALL_METHOD(&_19$$8, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_20$$8);
			ZVAL_STRING(_20$$8, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _19$$8, "get", NULL, 0, _20$$8);
			zephir_check_temp_parameter(_20$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$8, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _21$$8);
			ZEPHIR_CALL_METHOD(&_21$$8, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _21$$8);
		}
		ZEPHIR_INIT_VAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_22$$5, "strtr", &_23, 116, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _22$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_24, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_25 = zephir_is_true(_24);
	if (_25) {
		_26 = ZEPHIR_IS_EMPTY(value);
		if (!(_26)) {
			_27 = zephir_array_isset_string(value, SS("error"));
			if (_27) {
				zephir_array_fetch_string(&_28, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 83 TSRMLS_CC);
				_27 = ZEPHIR_IS_LONG_IDENTICAL(_28, 4);
			}
			_26 = _27;
		}
		_25 = _26;
	}
	if (_25) {
		RETURN_MM_BOOL(1);
	}
	_29 = !(zephir_array_isset_string(value, SS("error")));
	if (!(_29)) {
		_29 = !(zephir_array_isset_string(value, SS("tmp_name")));
	}
	_30 = _29;
	if (!(_30)) {
		zephir_array_fetch_string(&_31, value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 87 TSRMLS_CC);
		_30 = !ZEPHIR_IS_LONG_IDENTICAL(_31, 0);
	}
	_32 = _30;
	if (!(_32)) {
		zephir_array_fetch_string(&_33, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 87 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_34, "is_uploaded_file", NULL, 210, _33);
		zephir_check_call_status();
		_32 = !zephir_is_true(_34);
	}
	if (_32) {
		ZEPHIR_INIT_VAR(_36$$10);
		ZVAL_STRING(_36$$10, "messageEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_35$$10, this_ptr, "has", NULL, 0, _36$$10);
		zephir_check_temp_parameter(_36$$10);
		zephir_check_call_status();
		if (zephir_is_true(_35$$10)) {
			ZEPHIR_INIT_VAR(_37$$11);
			ZVAL_STRING(_37$$11, "messageEmpty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _37$$11);
			zephir_check_temp_parameter(_37$$11);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_38$$12);
			ZVAL_STRING(_38$$12, "fileEmpty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _38$$12);
			zephir_check_temp_parameter(_38$$12);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_39$$10, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_40$$10 = ZEPHIR_IS_TRUE_IDENTICAL(_39$$10);
		if (_40$$10) {
			ZEPHIR_CALL_METHOD(&_41$$10, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_36$$10);
			ZVAL_STRING(_36$$10, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_42$$10, _41$$10, "has", NULL, 0, _36$$10);
			zephir_check_temp_parameter(_36$$10);
			zephir_check_call_status();
			_40$$10 = zephir_is_true(_42$$10);
		}
		if (_40$$10) {
			ZEPHIR_CALL_METHOD(&_43$$13, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_44$$13);
			ZVAL_STRING(_44$$13, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _43$$13, "get", NULL, 0, _44$$13);
			zephir_check_temp_parameter(_44$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_45$$13, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _45$$13);
			ZEPHIR_CALL_METHOD(&_45$$13, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _45$$13);
		}
		ZEPHIR_INIT_NVAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_46$$10, "strtr", &_23, 116, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _46$$10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_47 = !(zephir_array_isset_string(value, SS("name")));
	if (!(_47)) {
		_47 = !(zephir_array_isset_string(value, SS("type")));
	}
	_48 = _47;
	if (!(_48)) {
		_48 = !(zephir_array_isset_string(value, SS("size")));
	}
	if (_48) {
		ZEPHIR_INIT_VAR(_50$$14);
		ZVAL_STRING(_50$$14, "messageValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_49$$14, this_ptr, "has", NULL, 0, _50$$14);
		zephir_check_temp_parameter(_50$$14);
		zephir_check_call_status();
		if (zephir_is_true(_49$$14)) {
			ZEPHIR_INIT_VAR(_51$$15);
			ZVAL_STRING(_51$$15, "messageValid", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _51$$15);
			zephir_check_temp_parameter(_51$$15);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_52$$16);
			ZVAL_STRING(_52$$16, "default", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _52$$16);
			zephir_check_temp_parameter(_52$$16);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_53$$14, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_54$$14 = ZEPHIR_IS_TRUE_IDENTICAL(_53$$14);
		if (_54$$14) {
			ZEPHIR_CALL_METHOD(&_55$$14, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_50$$14);
			ZVAL_STRING(_50$$14, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_56$$14, _55$$14, "has", NULL, 0, _50$$14);
			zephir_check_temp_parameter(_50$$14);
			zephir_check_call_status();
			_54$$14 = zephir_is_true(_56$$14);
		}
		if (_54$$14) {
			ZEPHIR_CALL_METHOD(&_57$$17, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_58$$17);
			ZVAL_STRING(_58$$17, "i18n", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&i18n, _57$$17, "get", NULL, 0, _58$$17);
			zephir_check_temp_parameter(_58$$17);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_59$$17, i18n, "translate", NULL, 0, label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(label, _59$$17);
			ZEPHIR_CALL_METHOD(&_59$$17, i18n, "translate", NULL, 0, message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(message, _59$$17);
		}
		ZEPHIR_INIT_NVAR(replace);
		zephir_create_array(replace, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_60$$14, "strtr", &_23, 116, message, replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _60$$14);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_61, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_61)) {
		ZEPHIR_INIT_VAR(byteUnits);
		zephir_create_array(byteUnits, 9, 0 TSRMLS_CC);
		add_assoc_long_ex(byteUnits, SS("B"), 0);
		add_assoc_long_ex(byteUnits, SS("K"), 10);
		add_assoc_long_ex(byteUnits, SS("M"), 20);
		add_assoc_long_ex(byteUnits, SS("G"), 30);
		add_assoc_long_ex(byteUnits, SS("T"), 40);
		add_assoc_long_ex(byteUnits, SS("KB"), 10);
		add_assoc_long_ex(byteUnits, SS("MB"), 20);
		add_assoc_long_ex(byteUnits, SS("GB"), 30);
		add_assoc_long_ex(byteUnits, SS("TB"), 40);
		ZEPHIR_INIT_VAR(_62$$18);
		ZVAL_STRING(_62$$18, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "get", NULL, 0, _62$$18);
		zephir_check_temp_parameter(_62$$18);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		ZEPHIR_INIT_NVAR(_62$$18);
		ZEPHIR_INIT_VAR(_63$$18);
		zephir_array_keys(_63$$18, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_62$$18, SL("|"), _63$$18 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_64$$18);
		ZEPHIR_CONCAT_SVS(_64$$18, "/^([0-9]+(?:\\.[0-9]+)?)(", _62$$18, ")?$/Di");
		ZEPHIR_INIT_VAR(_65$$18);
		zephir_preg_match(_65$$18, _64$$18, maxSize, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY, "ice/validation/validator/file.zep", 136 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_66$$18, matches, 1, PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 139 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_67$$18, "floatval", &_68, 211, _66$$18);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_69$$18);
		zephir_array_fetch(&_70$$18, byteUnits, unit, PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 139 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_71$$18);
		ZVAL_LONG(&_71$$18, 2);
		zephir_pow_function(_69$$18, &_71$$18, _70$$18);
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _67$$18, _69$$18 TSRMLS_CC);
		zephir_array_fetch_string(&_72$$18, value, SL("size"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 141 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_67$$18, "floatval", &_68, 211, _72$$18);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_73$$18, "floatval", &_68, 211, bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(_67$$18, _73$$18)) {
			ZEPHIR_INIT_VAR(_75$$20);
			ZVAL_STRING(_75$$20, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_74$$20, this_ptr, "has", NULL, 0, _75$$20);
			zephir_check_temp_parameter(_75$$20);
			zephir_check_call_status();
			if (zephir_is_true(_74$$20)) {
				ZEPHIR_INIT_VAR(_76$$21);
				ZVAL_STRING(_76$$21, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _76$$21);
				zephir_check_temp_parameter(_76$$21);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(_77$$22);
				ZVAL_STRING(_77$$22, "fileSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _77$$22);
				zephir_check_temp_parameter(_77$$22);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_78$$20, validation, "gettranslate", NULL, 0);
			zephir_check_call_status();
			_79$$20 = ZEPHIR_IS_TRUE_IDENTICAL(_78$$20);
			if (_79$$20) {
				ZEPHIR_CALL_METHOD(&_80$$20, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_75$$20);
				ZVAL_STRING(_75$$20, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_81$$20, _80$$20, "has", NULL, 0, _75$$20);
				zephir_check_temp_parameter(_75$$20);
				zephir_check_call_status();
				_79$$20 = zephir_is_true(_81$$20);
			}
			if (_79$$20) {
				ZEPHIR_CALL_METHOD(&_82$$23, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_83$$23);
				ZVAL_STRING(_83$$23, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&i18n, _82$$23, "get", NULL, 0, _83$$23);
				zephir_check_temp_parameter(_83$$23);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_84$$23, i18n, "translate", NULL, 0, label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(label, _84$$23);
				ZEPHIR_CALL_METHOD(&_84$$23, i18n, "translate", NULL, 0, message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(message, _84$$23);
			}
			ZEPHIR_INIT_NVAR(replace);
			zephir_create_array(replace, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replace, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_85$$20, "strtr", &_23, 116, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _85$$20);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_86, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_86)) {
		ZEPHIR_INIT_VAR(_87$$24);
		ZVAL_STRING(_87$$24, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&types, this_ptr, "get", NULL, 0, _87$$24);
		zephir_check_temp_parameter(_87$$24);
		zephir_check_call_status();
		if (Z_TYPE_P(types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Option 'allowedTypes' must be an array", "ice/validation/validator/file.zep", 166);
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_VAR(_88$$26);
			ZVAL_LONG(&_88$$26, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 212, &_88$$26);
			zephir_check_call_status();
			zephir_array_fetch_string(&_89$$26, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 171 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 213, tmp, _89$$26);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 214, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY, "ice/validation/validator/file.zep", 175 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_91$$28);
			ZVAL_STRING(_91$$28, "messageType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_90$$28, this_ptr, "has", NULL, 0, _91$$28);
			zephir_check_temp_parameter(_91$$28);
			zephir_check_call_status();
			if (zephir_is_true(_90$$28)) {
				ZEPHIR_INIT_VAR(_92$$29);
				ZVAL_STRING(_92$$29, "messageType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _92$$29);
				zephir_check_temp_parameter(_92$$29);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(_93$$30);
				ZVAL_STRING(_93$$30, "fileType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _93$$30);
				zephir_check_temp_parameter(_93$$30);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_94$$28, validation, "gettranslate", NULL, 0);
			zephir_check_call_status();
			_95$$28 = ZEPHIR_IS_TRUE_IDENTICAL(_94$$28);
			if (_95$$28) {
				ZEPHIR_CALL_METHOD(&_96$$28, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_91$$28);
				ZVAL_STRING(_91$$28, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_97$$28, _96$$28, "has", NULL, 0, _91$$28);
				zephir_check_temp_parameter(_91$$28);
				zephir_check_call_status();
				_95$$28 = zephir_is_true(_97$$28);
			}
			if (_95$$28) {
				ZEPHIR_CALL_METHOD(&_98$$31, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_99$$31);
				ZVAL_STRING(_99$$31, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&i18n, _98$$31, "get", NULL, 0, _99$$31);
				zephir_check_temp_parameter(_99$$31);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_100$$31, i18n, "translate", NULL, 0, label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(label, _100$$31);
				ZEPHIR_CALL_METHOD(&_100$$31, i18n, "translate", NULL, 0, message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(message, _100$$31);
			}
			ZEPHIR_INIT_NVAR(replace);
			zephir_create_array(replace, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_91$$28);
			zephir_fast_join_str(_91$$28, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replace, SL(":types"), &_91$$28, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_101$$28, "strtr", &_23, 116, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _101$$28);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_102, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_103 = zephir_is_true(_102);
	if (!(_103)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_104, this_ptr, "has", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_103 = zephir_is_true(_104);
	}
	if (_103) {
		zephir_array_fetch_string(&_105$$32, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 200 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 215, _105$$32);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY, "ice/validation/validator/file.zep", 201 TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY, "ice/validation/validator/file.zep", 202 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_107$$32);
		ZVAL_STRING(_107$$32, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_106$$32, this_ptr, "has", NULL, 0, _107$$32);
		zephir_check_temp_parameter(_107$$32);
		zephir_check_call_status();
		if (zephir_is_true(_106$$32)) {
			ZEPHIR_INIT_VAR(_109$$33);
			ZVAL_STRING(_109$$33, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_108$$33, this_ptr, "get", NULL, 0, _109$$33);
			zephir_check_temp_parameter(_109$$33);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(minResolution);
			zephir_fast_explode_str(minResolution, SL("x"), _108$$33, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(minWidth);
			zephir_array_fetch_long(&minWidth, minResolution, 0, PH_NOISY, "ice/validation/validator/file.zep", 206 TSRMLS_CC);
			ZEPHIR_OBS_VAR(minHeight);
			zephir_array_fetch_long(&minHeight, minResolution, 1, PH_NOISY, "ice/validation/validator/file.zep", 207 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(minWidth);
			ZVAL_LONG(minWidth, 1);
			ZEPHIR_INIT_NVAR(minHeight);
			ZVAL_LONG(minHeight, 1);
		}
		_110$$32 = ZEPHIR_LT(width, minWidth);
		if (!(_110$$32)) {
			_110$$32 = ZEPHIR_LT(height, minHeight);
		}
		if (_110$$32) {
			ZEPHIR_INIT_VAR(_112$$35);
			ZVAL_STRING(_112$$35, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_111$$35, this_ptr, "has", NULL, 0, _112$$35);
			zephir_check_temp_parameter(_112$$35);
			zephir_check_call_status();
			if (zephir_is_true(_111$$35)) {
				ZEPHIR_INIT_VAR(_113$$36);
				ZVAL_STRING(_113$$36, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _113$$36);
				zephir_check_temp_parameter(_113$$36);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(_114$$37);
				ZVAL_STRING(_114$$37, "fileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _114$$37);
				zephir_check_temp_parameter(_114$$37);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_115$$35, validation, "gettranslate", NULL, 0);
			zephir_check_call_status();
			_116$$35 = ZEPHIR_IS_TRUE_IDENTICAL(_115$$35);
			if (_116$$35) {
				ZEPHIR_CALL_METHOD(&_117$$35, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_112$$35);
				ZVAL_STRING(_112$$35, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_118$$35, _117$$35, "has", NULL, 0, _112$$35);
				zephir_check_temp_parameter(_112$$35);
				zephir_check_call_status();
				_116$$35 = zephir_is_true(_118$$35);
			}
			if (_116$$35) {
				ZEPHIR_CALL_METHOD(&_119$$38, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_120$$38);
				ZVAL_STRING(_120$$38, "i18n", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&i18n, _119$$38, "get", NULL, 0, _120$$38);
				zephir_check_temp_parameter(_120$$38);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_121$$38, i18n, "translate", NULL, 0, label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(label, _121$$38);
				ZEPHIR_CALL_METHOD(&_121$$38, i18n, "translate", NULL, 0, message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(message, _121$$38);
			}
			ZEPHIR_INIT_NVAR(replace);
			zephir_create_array(replace, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_112$$35);
			ZVAL_STRING(_112$$35, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_122$$35, this_ptr, "get", NULL, 0, _112$$35);
			zephir_check_temp_parameter(_112$$35);
			zephir_check_call_status();
			zephir_array_update_string(&replace, SL(":min"), &_122$$35, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_122$$35, "strtr", &_23, 116, message, replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _122$$35);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_107$$32);
		ZVAL_STRING(_107$$32, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_123$$32, this_ptr, "has", NULL, 0, _107$$32);
		zephir_check_temp_parameter(_107$$32);
		zephir_check_call_status();
		if (zephir_is_true(_123$$32)) {
			ZEPHIR_INIT_VAR(_125$$39);
			ZVAL_STRING(_125$$39, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_124$$39, this_ptr, "get", NULL, 0, _125$$39);
			zephir_check_temp_parameter(_125$$39);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(maxResolution);
			zephir_fast_explode_str(maxResolution, SL("x"), _124$$39, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY, "ice/validation/validator/file.zep", 236 TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY, "ice/validation/validator/file.zep", 237 TSRMLS_CC);
			_126$$39 = ZEPHIR_GT(width, maxWidth);
			if (!(_126$$39)) {
				_126$$39 = ZEPHIR_GT(height, maxHeight);
			}
			if (_126$$39) {
				ZEPHIR_INIT_VAR(_128$$40);
				ZVAL_STRING(_128$$40, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_127$$40, this_ptr, "has", NULL, 0, _128$$40);
				zephir_check_temp_parameter(_128$$40);
				zephir_check_call_status();
				if (zephir_is_true(_127$$40)) {
					ZEPHIR_INIT_VAR(_129$$41);
					ZVAL_STRING(_129$$41, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, _129$$41);
					zephir_check_temp_parameter(_129$$41);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_VAR(_130$$42);
					ZVAL_STRING(_130$$42, "fileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _130$$42);
					zephir_check_temp_parameter(_130$$42);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_131$$40, validation, "gettranslate", NULL, 0);
				zephir_check_call_status();
				_132$$40 = ZEPHIR_IS_TRUE_IDENTICAL(_131$$40);
				if (_132$$40) {
					ZEPHIR_CALL_METHOD(&_133$$40, validation, "getdi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_128$$40);
					ZVAL_STRING(_128$$40, "i18n", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_134$$40, _133$$40, "has", NULL, 0, _128$$40);
					zephir_check_temp_parameter(_128$$40);
					zephir_check_call_status();
					_132$$40 = zephir_is_true(_134$$40);
				}
				if (_132$$40) {
					ZEPHIR_CALL_METHOD(&_135$$43, validation, "getdi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(_136$$43);
					ZVAL_STRING(_136$$43, "i18n", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&i18n, _135$$43, "get", NULL, 0, _136$$43);
					zephir_check_temp_parameter(_136$$43);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_137$$43, i18n, "translate", NULL, 0, label);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(label, _137$$43);
					ZEPHIR_CALL_METHOD(&_137$$43, i18n, "translate", NULL, 0, message);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(message, _137$$43);
				}
				ZEPHIR_INIT_NVAR(replace);
				zephir_create_array(replace, 2, 0 TSRMLS_CC);
				zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_128$$40);
				ZVAL_STRING(_128$$40, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_138$$40, this_ptr, "get", NULL, 0, _128$$40);
				zephir_check_temp_parameter(_128$$40);
				zephir_check_call_status();
				zephir_array_update_string(&replace, SL(":max"), &_138$$40, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_138$$40, "strtr", &_23, 116, message, replace);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, field, _138$$40);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

