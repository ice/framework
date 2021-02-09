
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
 * @copyright   (c) 2014-2021 Ice Team
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

	zend_bool _4, _5, _6, _8, _9, _25, _26, _27, _29, _30, _32, _48, _49, _107, _16$$5, _40$$10, _55$$14, _81$$20, _98$$28, _114$$32, _120$$35, _131$$39, _137$$40;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_23 = NULL, *_70 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, _SERVER, _POST, _FILES, value, message, label, i18n, replace, types, byteUnits, unit, maxSize, matches, bytes, mime, tmp, width, height, minResolution, maxResolution, minWidth, maxWidth, minHeight, maxHeight, _0, _1, _3, _7, _10, _24, _28, _31, _33, _34, _63, _89, _106, _108, _2$$3, _11$$5, _12$$5, _15$$5, _17$$5, _18$$5, _22$$5, _13$$6, _14$$7, _19$$8, _20$$8, _21$$8, _35$$10, _36$$10, _39$$10, _41$$10, _42$$10, _46$$10, _47$$10, _37$$11, _38$$12, _43$$13, _44$$13, _45$$13, _50$$14, _51$$14, _54$$14, _56$$14, _57$$14, _61$$14, _62$$14, _52$$15, _53$$16, _58$$17, _59$$17, _60$$17, _64$$18, _65$$18, _66$$18, _67$$18, _68$$18, _69$$18, _71$$18, _72$$18, _73$$18, _74$$18, _75$$18, _76$$20, _77$$20, _80$$20, _82$$20, _83$$20, _87$$20, _88$$20, _78$$21, _79$$22, _84$$23, _85$$23, _86$$23, _90$$24, _91$$26, _92$$26, _93$$28, _94$$28, _97$$28, _99$$28, _100$$28, _104$$28, _105$$28, _95$$29, _96$$30, _101$$31, _102$$31, _103$$31, _109$$32, _110$$32, _111$$32, _128$$32, _112$$33, _113$$33, _115$$35, _116$$35, _119$$35, _121$$35, _122$$35, _126$$35, _127$$35, _117$$36, _118$$37, _123$$38, _124$$38, _125$$38, _129$$39, _130$$39, _132$$40, _133$$40, _136$$40, _138$$40, _139$$40, _143$$40, _144$$40, _134$$41, _135$$42, _140$$43, _141$$43, _142$$43;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&byteUnits);
	ZVAL_UNDEF(&unit);
	ZVAL_UNDEF(&maxSize);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&mime);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&minResolution);
	ZVAL_UNDEF(&maxResolution);
	ZVAL_UNDEF(&minWidth);
	ZVAL_UNDEF(&maxWidth);
	ZVAL_UNDEF(&minHeight);
	ZVAL_UNDEF(&maxHeight);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_63);
	ZVAL_UNDEF(&_89);
	ZVAL_UNDEF(&_106);
	ZVAL_UNDEF(&_108);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_47$$10);
	ZVAL_UNDEF(&_37$$11);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&_43$$13);
	ZVAL_UNDEF(&_44$$13);
	ZVAL_UNDEF(&_45$$13);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_51$$14);
	ZVAL_UNDEF(&_54$$14);
	ZVAL_UNDEF(&_56$$14);
	ZVAL_UNDEF(&_57$$14);
	ZVAL_UNDEF(&_61$$14);
	ZVAL_UNDEF(&_62$$14);
	ZVAL_UNDEF(&_52$$15);
	ZVAL_UNDEF(&_53$$16);
	ZVAL_UNDEF(&_58$$17);
	ZVAL_UNDEF(&_59$$17);
	ZVAL_UNDEF(&_60$$17);
	ZVAL_UNDEF(&_64$$18);
	ZVAL_UNDEF(&_65$$18);
	ZVAL_UNDEF(&_66$$18);
	ZVAL_UNDEF(&_67$$18);
	ZVAL_UNDEF(&_68$$18);
	ZVAL_UNDEF(&_69$$18);
	ZVAL_UNDEF(&_71$$18);
	ZVAL_UNDEF(&_72$$18);
	ZVAL_UNDEF(&_73$$18);
	ZVAL_UNDEF(&_74$$18);
	ZVAL_UNDEF(&_75$$18);
	ZVAL_UNDEF(&_76$$20);
	ZVAL_UNDEF(&_77$$20);
	ZVAL_UNDEF(&_80$$20);
	ZVAL_UNDEF(&_82$$20);
	ZVAL_UNDEF(&_83$$20);
	ZVAL_UNDEF(&_87$$20);
	ZVAL_UNDEF(&_88$$20);
	ZVAL_UNDEF(&_78$$21);
	ZVAL_UNDEF(&_79$$22);
	ZVAL_UNDEF(&_84$$23);
	ZVAL_UNDEF(&_85$$23);
	ZVAL_UNDEF(&_86$$23);
	ZVAL_UNDEF(&_90$$24);
	ZVAL_UNDEF(&_91$$26);
	ZVAL_UNDEF(&_92$$26);
	ZVAL_UNDEF(&_93$$28);
	ZVAL_UNDEF(&_94$$28);
	ZVAL_UNDEF(&_97$$28);
	ZVAL_UNDEF(&_99$$28);
	ZVAL_UNDEF(&_100$$28);
	ZVAL_UNDEF(&_104$$28);
	ZVAL_UNDEF(&_105$$28);
	ZVAL_UNDEF(&_95$$29);
	ZVAL_UNDEF(&_96$$30);
	ZVAL_UNDEF(&_101$$31);
	ZVAL_UNDEF(&_102$$31);
	ZVAL_UNDEF(&_103$$31);
	ZVAL_UNDEF(&_109$$32);
	ZVAL_UNDEF(&_110$$32);
	ZVAL_UNDEF(&_111$$32);
	ZVAL_UNDEF(&_128$$32);
	ZVAL_UNDEF(&_112$$33);
	ZVAL_UNDEF(&_113$$33);
	ZVAL_UNDEF(&_115$$35);
	ZVAL_UNDEF(&_116$$35);
	ZVAL_UNDEF(&_119$$35);
	ZVAL_UNDEF(&_121$$35);
	ZVAL_UNDEF(&_122$$35);
	ZVAL_UNDEF(&_126$$35);
	ZVAL_UNDEF(&_127$$35);
	ZVAL_UNDEF(&_117$$36);
	ZVAL_UNDEF(&_118$$37);
	ZVAL_UNDEF(&_123$$38);
	ZVAL_UNDEF(&_124$$38);
	ZVAL_UNDEF(&_125$$38);
	ZVAL_UNDEF(&_129$$39);
	ZVAL_UNDEF(&_130$$39);
	ZVAL_UNDEF(&_132$$40);
	ZVAL_UNDEF(&_133$$40);
	ZVAL_UNDEF(&_136$$40);
	ZVAL_UNDEF(&_138$$40);
	ZVAL_UNDEF(&_139$$40);
	ZVAL_UNDEF(&_143$$40);
	ZVAL_UNDEF(&_144$$40);
	ZVAL_UNDEF(&_134$$41);
	ZVAL_UNDEF(&_135$$42);
	ZVAL_UNDEF(&_140$$43);
	ZVAL_UNDEF(&_141$$43);
	ZVAL_UNDEF(&_142$$43);
	ZVAL_UNDEF(&field);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
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
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "label");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "label");
		ZEPHIR_CALL_METHOD(&label, this_ptr, "get", NULL, 0, &_2$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
		zephir_check_call_status();
	}
	zephir_array_fetch_string(&_3, &_SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 62);
	_4 = ZEPHIR_IS_STRING(&_3, "POST");
	if (_4) {
		_4 = ZEPHIR_IS_EMPTY(&_POST);
	}
	_5 = _4;
	if (_5) {
		_5 = ZEPHIR_IS_EMPTY(&_FILES);
	}
	_6 = _5;
	if (_6) {
		zephir_array_fetch_string(&_7, &_SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 62);
		_6 = ZEPHIR_GT_LONG(&_7, 0);
	}
	_8 = _6;
	if (!(_8)) {
		_9 = zephir_array_isset_string(&value, SL("error"));
		if (_9) {
			zephir_array_fetch_string(&_10, &value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 62);
			_9 = ZEPHIR_IS_LONG_IDENTICAL(&_10, 1);
		}
		_8 = _9;
	}
	if (_8) {
		ZEPHIR_INIT_VAR(&_12$$5);
		ZVAL_STRING(&_12$$5, "messageIniSize");
		ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "has", NULL, 0, &_12$$5);
		zephir_check_call_status();
		if (zephir_is_true(&_11$$5)) {
			ZEPHIR_INIT_VAR(&_13$$6);
			ZVAL_STRING(&_13$$6, "messageIniSize");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_13$$6);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_14$$7);
			ZVAL_STRING(&_14$$7, "fileIniSize");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_14$$7);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_15$$5, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_16$$5 = ZEPHIR_IS_TRUE_IDENTICAL(&_15$$5);
		if (_16$$5) {
			ZEPHIR_CALL_METHOD(&_17$$5, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$5);
			ZVAL_STRING(&_12$$5, "i18n");
			ZEPHIR_CALL_METHOD(&_18$$5, &_17$$5, "has", NULL, 0, &_12$$5);
			zephir_check_call_status();
			_16$$5 = zephir_is_true(&_18$$5);
		}
		if (_16$$5) {
			ZEPHIR_CALL_METHOD(&_19$$8, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_20$$8);
			ZVAL_STRING(&_20$$8, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_19$$8, "get", NULL, 0, &_20$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$8, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_21$$8);
			ZEPHIR_CALL_METHOD(&_21$$8, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_21$$8);
		}
		ZEPHIR_INIT_VAR(&replace);
		zephir_create_array(&replace, 1, 0);
		zephir_array_update_string(&replace, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_22$$5, "strtr", &_23, 110, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_22$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "allowEmpty");
	ZEPHIR_CALL_METHOD(&_24, this_ptr, "has", NULL, 0, &_1);
	zephir_check_call_status();
	_25 = zephir_is_true(&_24);
	if (_25) {
		_26 = ZEPHIR_IS_EMPTY(&value);
		if (!(_26)) {
			_27 = zephir_array_isset_string(&value, SL("error"));
			if (_27) {
				zephir_array_fetch_string(&_28, &value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 82);
				_27 = ZEPHIR_IS_LONG_IDENTICAL(&_28, 4);
			}
			_26 = _27;
		}
		_25 = _26;
	}
	if (_25) {
		RETURN_MM_BOOL(1);
	}
	_29 = !(zephir_array_isset_string(&value, SL("error")));
	if (!(_29)) {
		_29 = !(zephir_array_isset_string(&value, SL("tmp_name")));
	}
	_30 = _29;
	if (!(_30)) {
		zephir_array_fetch_string(&_31, &value, SL("error"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 86);
		_30 = !ZEPHIR_IS_LONG_IDENTICAL(&_31, 0);
	}
	_32 = _30;
	if (!(_32)) {
		zephir_array_fetch_string(&_33, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 86);
		ZEPHIR_CALL_FUNCTION(&_34, "is_uploaded_file", NULL, 218, &_33);
		zephir_check_call_status();
		_32 = !zephir_is_true(&_34);
	}
	if (_32) {
		ZEPHIR_INIT_VAR(&_36$$10);
		ZVAL_STRING(&_36$$10, "messageEmpty");
		ZEPHIR_CALL_METHOD(&_35$$10, this_ptr, "has", NULL, 0, &_36$$10);
		zephir_check_call_status();
		if (zephir_is_true(&_35$$10)) {
			ZEPHIR_INIT_VAR(&_37$$11);
			ZVAL_STRING(&_37$$11, "messageEmpty");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_37$$11);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_38$$12);
			ZVAL_STRING(&_38$$12, "fileEmpty");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_38$$12);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_39$$10, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_40$$10 = ZEPHIR_IS_TRUE_IDENTICAL(&_39$$10);
		if (_40$$10) {
			ZEPHIR_CALL_METHOD(&_41$$10, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_36$$10);
			ZVAL_STRING(&_36$$10, "i18n");
			ZEPHIR_CALL_METHOD(&_42$$10, &_41$$10, "has", NULL, 0, &_36$$10);
			zephir_check_call_status();
			_40$$10 = zephir_is_true(&_42$$10);
		}
		if (_40$$10) {
			ZEPHIR_CALL_METHOD(&_43$$13, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_44$$13);
			ZVAL_STRING(&_44$$13, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_43$$13, "get", NULL, 0, &_44$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_45$$13, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_45$$13);
			ZEPHIR_CALL_METHOD(&_45$$13, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_45$$13);
		}
		ZEPHIR_INIT_VAR(&_46$$10);
		zephir_create_array(&_46$$10, 1, 0);
		zephir_array_update_string(&_46$$10, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&replace, &_46$$10);
		ZEPHIR_CALL_FUNCTION(&_47$$10, "strtr", &_23, 110, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_47$$10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_48 = !(zephir_array_isset_string(&value, SL("name")));
	if (!(_48)) {
		_48 = !(zephir_array_isset_string(&value, SL("type")));
	}
	_49 = _48;
	if (!(_49)) {
		_49 = !(zephir_array_isset_string(&value, SL("size")));
	}
	if (_49) {
		ZEPHIR_INIT_VAR(&_51$$14);
		ZVAL_STRING(&_51$$14, "messageValid");
		ZEPHIR_CALL_METHOD(&_50$$14, this_ptr, "has", NULL, 0, &_51$$14);
		zephir_check_call_status();
		if (zephir_is_true(&_50$$14)) {
			ZEPHIR_INIT_VAR(&_52$$15);
			ZVAL_STRING(&_52$$15, "messageValid");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_52$$15);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_53$$16);
			ZVAL_STRING(&_53$$16, "default");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_53$$16);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_54$$14, validation, "gettranslate", NULL, 0);
		zephir_check_call_status();
		_55$$14 = ZEPHIR_IS_TRUE_IDENTICAL(&_54$$14);
		if (_55$$14) {
			ZEPHIR_CALL_METHOD(&_56$$14, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_51$$14);
			ZVAL_STRING(&_51$$14, "i18n");
			ZEPHIR_CALL_METHOD(&_57$$14, &_56$$14, "has", NULL, 0, &_51$$14);
			zephir_check_call_status();
			_55$$14 = zephir_is_true(&_57$$14);
		}
		if (_55$$14) {
			ZEPHIR_CALL_METHOD(&_58$$17, validation, "getdi", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_59$$17);
			ZVAL_STRING(&_59$$17, "i18n");
			ZEPHIR_CALL_METHOD(&i18n, &_58$$17, "get", NULL, 0, &_59$$17);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_60$$17, &i18n, "translate", NULL, 0, &label);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&label, &_60$$17);
			ZEPHIR_CALL_METHOD(&_60$$17, &i18n, "translate", NULL, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&message, &_60$$17);
		}
		ZEPHIR_INIT_VAR(&_61$$14);
		zephir_create_array(&_61$$14, 1, 0);
		zephir_array_update_string(&_61$$14, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&replace, &_61$$14);
		ZEPHIR_CALL_FUNCTION(&_62$$14, "strtr", &_23, 110, &message, &replace);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_62$$14);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "maxSize");
	ZEPHIR_CALL_METHOD(&_63, this_ptr, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_63)) {
		ZEPHIR_INIT_VAR(&byteUnits);
		zephir_create_array(&byteUnits, 9, 0);
		add_assoc_long_ex(&byteUnits, SL("B"), 0);
		add_assoc_long_ex(&byteUnits, SL("K"), 10);
		add_assoc_long_ex(&byteUnits, SL("M"), 20);
		add_assoc_long_ex(&byteUnits, SL("G"), 30);
		add_assoc_long_ex(&byteUnits, SL("T"), 40);
		add_assoc_long_ex(&byteUnits, SL("KB"), 10);
		add_assoc_long_ex(&byteUnits, SL("MB"), 20);
		add_assoc_long_ex(&byteUnits, SL("GB"), 30);
		add_assoc_long_ex(&byteUnits, SL("TB"), 40);
		ZEPHIR_INIT_VAR(&_64$$18);
		ZVAL_STRING(&_64$$18, "maxSize");
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "get", NULL, 0, &_64$$18);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&matches);
		ZVAL_NULL(&matches);
		ZEPHIR_INIT_VAR(&unit);
		ZVAL_STRING(&unit, "B");
		ZEPHIR_INIT_NVAR(&_64$$18);
		ZEPHIR_INIT_VAR(&_65$$18);
		zephir_array_keys(&_65$$18, &byteUnits);
		zephir_fast_join_str(&_64$$18, SL("|"), &_65$$18);
		ZEPHIR_INIT_VAR(&_66$$18);
		ZEPHIR_CONCAT_SVS(&_66$$18, "/^([0-9]+(?:\\.[0-9]+)?)(", &_64$$18, ")?$/Di");
		ZEPHIR_INIT_VAR(&_67$$18);
		zephir_preg_match(&_67$$18, &_66$$18, &maxSize, &matches, 0, 0 , 0 );
		if (zephir_array_isset_long(&matches, 2)) {
			ZEPHIR_OBS_NVAR(&unit);
			zephir_array_fetch_long(&unit, &matches, 2, PH_NOISY, "ice/validation/validator/file.zep", 135);
		}
		zephir_array_fetch_long(&_68$$18, &matches, 1, PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 138);
		ZEPHIR_CALL_FUNCTION(&_69$$18, "floatval", &_70, 219, &_68$$18);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_71$$18);
		zephir_array_fetch(&_72$$18, &byteUnits, &unit, PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 138);
		ZVAL_LONG(&_73$$18, 2);
		zephir_pow_function(&_71$$18, &_73$$18, &_72$$18);
		ZEPHIR_INIT_VAR(&bytes);
		mul_function(&bytes, &_69$$18, &_71$$18);
		zephir_array_fetch_string(&_74$$18, &value, SL("size"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 140);
		ZEPHIR_CALL_FUNCTION(&_69$$18, "floatval", &_70, 219, &_74$$18);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_75$$18, "floatval", &_70, 219, &bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(&_69$$18, &_75$$18)) {
			ZEPHIR_INIT_VAR(&_77$$20);
			ZVAL_STRING(&_77$$20, "messageSize");
			ZEPHIR_CALL_METHOD(&_76$$20, this_ptr, "has", NULL, 0, &_77$$20);
			zephir_check_call_status();
			if (zephir_is_true(&_76$$20)) {
				ZEPHIR_INIT_VAR(&_78$$21);
				ZVAL_STRING(&_78$$21, "messageSize");
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_78$$21);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_79$$22);
				ZVAL_STRING(&_79$$22, "fileSize");
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_79$$22);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_80$$20, validation, "gettranslate", NULL, 0);
			zephir_check_call_status();
			_81$$20 = ZEPHIR_IS_TRUE_IDENTICAL(&_80$$20);
			if (_81$$20) {
				ZEPHIR_CALL_METHOD(&_82$$20, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_77$$20);
				ZVAL_STRING(&_77$$20, "i18n");
				ZEPHIR_CALL_METHOD(&_83$$20, &_82$$20, "has", NULL, 0, &_77$$20);
				zephir_check_call_status();
				_81$$20 = zephir_is_true(&_83$$20);
			}
			if (_81$$20) {
				ZEPHIR_CALL_METHOD(&_84$$23, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_85$$23);
				ZVAL_STRING(&_85$$23, "i18n");
				ZEPHIR_CALL_METHOD(&i18n, &_84$$23, "get", NULL, 0, &_85$$23);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_86$$23, &i18n, "translate", NULL, 0, &label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&label, &_86$$23);
				ZEPHIR_CALL_METHOD(&_86$$23, &i18n, "translate", NULL, 0, &message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&message, &_86$$23);
			}
			ZEPHIR_INIT_VAR(&_87$$20);
			zephir_create_array(&_87$$20, 2, 0);
			zephir_array_update_string(&_87$$20, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_87$$20, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&replace, &_87$$20);
			ZEPHIR_CALL_FUNCTION(&_88$$20, "strtr", &_23, 110, &message, &replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_88$$20);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "allowedTypes");
	ZEPHIR_CALL_METHOD(&_89, this_ptr, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_89)) {
		ZEPHIR_INIT_VAR(&_90$$24);
		ZVAL_STRING(&_90$$24, "allowedTypes");
		ZEPHIR_CALL_METHOD(&types, this_ptr, "get", NULL, 0, &_90$$24);
		zephir_check_call_status();
		if (Z_TYPE_P(&types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Option 'allowedTypes' must be an array", "ice/validation/validator/file.zep", 165);
			return;
		}
		if ((zephir_function_exists_ex(ZEND_STRL("finfo_open")) == SUCCESS)) {
			ZVAL_LONG(&_91$$26, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 220, &_91$$26);
			zephir_check_call_status();
			zephir_array_fetch_string(&_92$$26, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 170);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 221, &tmp, &_92$$26);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 222, &tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&mime);
			zephir_array_fetch_string(&mime, &value, SL("type"), PH_NOISY, "ice/validation/validator/file.zep", 174);
		}
		if (!(zephir_fast_in_array(&mime, &types))) {
			ZEPHIR_INIT_VAR(&_94$$28);
			ZVAL_STRING(&_94$$28, "messageType");
			ZEPHIR_CALL_METHOD(&_93$$28, this_ptr, "has", NULL, 0, &_94$$28);
			zephir_check_call_status();
			if (zephir_is_true(&_93$$28)) {
				ZEPHIR_INIT_VAR(&_95$$29);
				ZVAL_STRING(&_95$$29, "messageType");
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_95$$29);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_96$$30);
				ZVAL_STRING(&_96$$30, "fileType");
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_96$$30);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_97$$28, validation, "gettranslate", NULL, 0);
			zephir_check_call_status();
			_98$$28 = ZEPHIR_IS_TRUE_IDENTICAL(&_97$$28);
			if (_98$$28) {
				ZEPHIR_CALL_METHOD(&_99$$28, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_94$$28);
				ZVAL_STRING(&_94$$28, "i18n");
				ZEPHIR_CALL_METHOD(&_100$$28, &_99$$28, "has", NULL, 0, &_94$$28);
				zephir_check_call_status();
				_98$$28 = zephir_is_true(&_100$$28);
			}
			if (_98$$28) {
				ZEPHIR_CALL_METHOD(&_101$$31, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_102$$31);
				ZVAL_STRING(&_102$$31, "i18n");
				ZEPHIR_CALL_METHOD(&i18n, &_101$$31, "get", NULL, 0, &_102$$31);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_103$$31, &i18n, "translate", NULL, 0, &label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&label, &_103$$31);
				ZEPHIR_CALL_METHOD(&_103$$31, &i18n, "translate", NULL, 0, &message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&message, &_103$$31);
			}
			ZEPHIR_INIT_VAR(&_104$$28);
			zephir_create_array(&_104$$28, 2, 0);
			zephir_array_update_string(&_104$$28, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_94$$28);
			zephir_fast_join_str(&_94$$28, SL(", "), &types);
			zephir_array_update_string(&_104$$28, SL(":types"), &_94$$28, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&replace, &_104$$28);
			ZEPHIR_CALL_FUNCTION(&_105$$28, "strtr", &_23, 110, &message, &replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_105$$28);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "minResolution");
	ZEPHIR_CALL_METHOD(&_106, this_ptr, "has", NULL, 0, &_1);
	zephir_check_call_status();
	_107 = zephir_is_true(&_106);
	if (!(_107)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "maxResolution");
		ZEPHIR_CALL_METHOD(&_108, this_ptr, "has", NULL, 0, &_1);
		zephir_check_call_status();
		_107 = zephir_is_true(&_108);
	}
	if (_107) {
		zephir_array_fetch_string(&_109$$32, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "ice/validation/validator/file.zep", 199);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 48, &_109$$32);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&width);
		zephir_array_fetch_long(&width, &tmp, 0, PH_NOISY, "ice/validation/validator/file.zep", 200);
		ZEPHIR_OBS_VAR(&height);
		zephir_array_fetch_long(&height, &tmp, 1, PH_NOISY, "ice/validation/validator/file.zep", 201);
		ZEPHIR_INIT_VAR(&_111$$32);
		ZVAL_STRING(&_111$$32, "minResolution");
		ZEPHIR_CALL_METHOD(&_110$$32, this_ptr, "has", NULL, 0, &_111$$32);
		zephir_check_call_status();
		if (zephir_is_true(&_110$$32)) {
			ZEPHIR_INIT_VAR(&_113$$33);
			ZVAL_STRING(&_113$$33, "minResolution");
			ZEPHIR_CALL_METHOD(&_112$$33, this_ptr, "get", NULL, 0, &_113$$33);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&minResolution);
			zephir_fast_explode_str(&minResolution, SL("x"), &_112$$33, LONG_MAX);
			ZEPHIR_OBS_VAR(&minWidth);
			zephir_array_fetch_long(&minWidth, &minResolution, 0, PH_NOISY, "ice/validation/validator/file.zep", 205);
			ZEPHIR_OBS_VAR(&minHeight);
			zephir_array_fetch_long(&minHeight, &minResolution, 1, PH_NOISY, "ice/validation/validator/file.zep", 206);
		} else {
			ZEPHIR_INIT_NVAR(&minWidth);
			ZVAL_LONG(&minWidth, 1);
			ZEPHIR_INIT_NVAR(&minHeight);
			ZVAL_LONG(&minHeight, 1);
		}
		_114$$32 = ZEPHIR_LT(&width, &minWidth);
		if (!(_114$$32)) {
			_114$$32 = ZEPHIR_LT(&height, &minHeight);
		}
		if (_114$$32) {
			ZEPHIR_INIT_VAR(&_116$$35);
			ZVAL_STRING(&_116$$35, "messageMinResolution");
			ZEPHIR_CALL_METHOD(&_115$$35, this_ptr, "has", NULL, 0, &_116$$35);
			zephir_check_call_status();
			if (zephir_is_true(&_115$$35)) {
				ZEPHIR_INIT_VAR(&_117$$36);
				ZVAL_STRING(&_117$$36, "messageMinResolution");
				ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_117$$36);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_118$$37);
				ZVAL_STRING(&_118$$37, "fileMinResolution");
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_118$$37);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_119$$35, validation, "gettranslate", NULL, 0);
			zephir_check_call_status();
			_120$$35 = ZEPHIR_IS_TRUE_IDENTICAL(&_119$$35);
			if (_120$$35) {
				ZEPHIR_CALL_METHOD(&_121$$35, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_116$$35);
				ZVAL_STRING(&_116$$35, "i18n");
				ZEPHIR_CALL_METHOD(&_122$$35, &_121$$35, "has", NULL, 0, &_116$$35);
				zephir_check_call_status();
				_120$$35 = zephir_is_true(&_122$$35);
			}
			if (_120$$35) {
				ZEPHIR_CALL_METHOD(&_123$$38, validation, "getdi", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_124$$38);
				ZVAL_STRING(&_124$$38, "i18n");
				ZEPHIR_CALL_METHOD(&i18n, &_123$$38, "get", NULL, 0, &_124$$38);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_125$$38, &i18n, "translate", NULL, 0, &label);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&label, &_125$$38);
				ZEPHIR_CALL_METHOD(&_125$$38, &i18n, "translate", NULL, 0, &message);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&message, &_125$$38);
			}
			ZEPHIR_INIT_VAR(&_126$$35);
			zephir_create_array(&_126$$35, 2, 0);
			zephir_array_update_string(&_126$$35, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_116$$35);
			ZVAL_STRING(&_116$$35, "minResolution");
			ZEPHIR_CALL_METHOD(&_127$$35, this_ptr, "get", NULL, 0, &_116$$35);
			zephir_check_call_status();
			zephir_array_update_string(&_126$$35, SL(":min"), &_127$$35, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&replace, &_126$$35);
			ZEPHIR_CALL_FUNCTION(&_127$$35, "strtr", &_23, 110, &message, &replace);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_127$$35);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_111$$32);
		ZVAL_STRING(&_111$$32, "maxResolution");
		ZEPHIR_CALL_METHOD(&_128$$32, this_ptr, "has", NULL, 0, &_111$$32);
		zephir_check_call_status();
		if (zephir_is_true(&_128$$32)) {
			ZEPHIR_INIT_VAR(&_130$$39);
			ZVAL_STRING(&_130$$39, "maxResolution");
			ZEPHIR_CALL_METHOD(&_129$$39, this_ptr, "get", NULL, 0, &_130$$39);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&maxResolution);
			zephir_fast_explode_str(&maxResolution, SL("x"), &_129$$39, LONG_MAX);
			ZEPHIR_OBS_VAR(&maxWidth);
			zephir_array_fetch_long(&maxWidth, &maxResolution, 0, PH_NOISY, "ice/validation/validator/file.zep", 235);
			ZEPHIR_OBS_VAR(&maxHeight);
			zephir_array_fetch_long(&maxHeight, &maxResolution, 1, PH_NOISY, "ice/validation/validator/file.zep", 236);
			_131$$39 = ZEPHIR_GT(&width, &maxWidth);
			if (!(_131$$39)) {
				_131$$39 = ZEPHIR_GT(&height, &maxHeight);
			}
			if (_131$$39) {
				ZEPHIR_INIT_VAR(&_133$$40);
				ZVAL_STRING(&_133$$40, "messageMaxResolution");
				ZEPHIR_CALL_METHOD(&_132$$40, this_ptr, "has", NULL, 0, &_133$$40);
				zephir_check_call_status();
				if (zephir_is_true(&_132$$40)) {
					ZEPHIR_INIT_VAR(&_134$$41);
					ZVAL_STRING(&_134$$41, "messageMaxResolution");
					ZEPHIR_CALL_METHOD(&message, this_ptr, "get", NULL, 0, &_134$$41);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_VAR(&_135$$42);
					ZVAL_STRING(&_135$$42, "fileMaxResolution");
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_135$$42);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_136$$40, validation, "gettranslate", NULL, 0);
				zephir_check_call_status();
				_137$$40 = ZEPHIR_IS_TRUE_IDENTICAL(&_136$$40);
				if (_137$$40) {
					ZEPHIR_CALL_METHOD(&_138$$40, validation, "getdi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_133$$40);
					ZVAL_STRING(&_133$$40, "i18n");
					ZEPHIR_CALL_METHOD(&_139$$40, &_138$$40, "has", NULL, 0, &_133$$40);
					zephir_check_call_status();
					_137$$40 = zephir_is_true(&_139$$40);
				}
				if (_137$$40) {
					ZEPHIR_CALL_METHOD(&_140$$43, validation, "getdi", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&_141$$43);
					ZVAL_STRING(&_141$$43, "i18n");
					ZEPHIR_CALL_METHOD(&i18n, &_140$$43, "get", NULL, 0, &_141$$43);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_142$$43, &i18n, "translate", NULL, 0, &label);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&label, &_142$$43);
					ZEPHIR_CALL_METHOD(&_142$$43, &i18n, "translate", NULL, 0, &message);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&message, &_142$$43);
				}
				ZEPHIR_INIT_VAR(&_143$$40);
				zephir_create_array(&_143$$40, 2, 0);
				zephir_array_update_string(&_143$$40, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_133$$40);
				ZVAL_STRING(&_133$$40, "maxResolution");
				ZEPHIR_CALL_METHOD(&_144$$40, this_ptr, "get", NULL, 0, &_133$$40);
				zephir_check_call_status();
				zephir_array_update_string(&_143$$40, SL(":max"), &_144$$40, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&replace, &_143$$40);
				ZEPHIR_CALL_FUNCTION(&_144$$40, "strtr", &_23, 110, &message, &replace);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "addmessage", NULL, 0, &field, &_144$$40);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

