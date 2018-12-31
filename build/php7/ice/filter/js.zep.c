
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


/**
 * Minify js string.
 *
 * @package     Ice/Filter
 * @category    Minification
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        jsmin.c www.crockford.com
 */
ZEPHIR_INIT_CLASS(Ice_Filter_Js) {

	ZEPHIR_REGISTER_CLASS(Ice\\Filter, Js, ice, filter_js, ice_filter_js_method_entry, 0);

	zend_declare_property_string(ice_filter_js_ce, SL("a"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_filter_js_ce, SL("b"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_filter_js_ce, SL("input"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_filter_js_ce, SL("inputIndex"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(ice_filter_js_ce, SL("inputLength"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_filter_js_ce, SL("lookAhead"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_filter_js_ce, SL("output"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_long(ice_filter_js_ce, SL("ORD_LF"), 10);

	zephir_declare_class_constant_long(ice_filter_js_ce, SL("ORD_SPACE"), 32);

	zephir_declare_class_constant_long(ice_filter_js_ce, SL("ACTION_KEEP_A"), 1);

	zephir_declare_class_constant_long(ice_filter_js_ce, SL("ACTION_DELETE_A"), 2);

	zephir_declare_class_constant_long(ice_filter_js_ce, SL("ACTION_DELETE_A_B"), 3);

	return SUCCESS;

}

PHP_METHOD(Ice_Filter_Js, getOutput) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "output");

}

/**
 * Minify the js.
 *
 * @param string js JS code to minify
 * @return string
 */
PHP_METHOD(Ice_Filter_Js, sanitize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *js_param = NULL, __$null, _0, _1, _2, _3, _4, _5;
	zval js;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&js);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &js_param);

	zephir_get_strval(&js, js_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("a"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("b"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\r\n");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\n");
	zephir_fast_str_replace(&_0, &_1, &_2, &js TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("input"), &_0);
	zephir_read_property(&_3, this_ptr, SL("input"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(&_4, zephir_fast_strlen_ev(&_3));
	zephir_update_property_zval(this_ptr, SL("inputLength"), &_4);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(&_4, 0);
	zephir_update_property_zval(this_ptr, SL("inputIndex"), &_4);
	zephir_update_property_zval(this_ptr, SL("lookAhead"), &__$null);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "");
	zephir_update_property_zval(this_ptr, SL("output"), &_5);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "min", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Action -- do something! What to do is determined by the $command argument.
 *
 * action treats a string as a single character. Wow!
 * action recognizes a regular expression if it is preceded by ( or , or =.
 *
 * @throws Exception If parser errors are found:
 *         - Unterminated string literal
 *         - Unterminated regular expression set in regex literal
 *         - Unterminated regular expression literal
 *
 * @param int $command One of class constants:
 *      ACTION_KEEP_A      Output A. Copy B to A. Get the next B.
 *      ACTION_DELETE_A    Copy B to A. Get the next B. (Delete A).
 *      ACTION_DELETE_A_B  Get the next B. (Delete B).
 */
PHP_METHOD(Ice_Filter_Js, action) {

	zend_bool _3, _23, _24, _6$$4, _28$$10, _30$$10, _32$$10, _34$$10, _36$$10, _38$$10, _40$$10, _42$$10, _44$$10, _46$$10, _48$$10, _50$$10, _52$$10;
	zephir_fcall_cache_entry *_12 = NULL, *_17 = NULL, *_26 = NULL;
	zval *command_param = NULL, _0$$3, _1$$3, _2$$3, _4$$4, _5$$4, _7$$4, _8$$6, _9$$6, _10$$6, _11$$6, _13$$6, _14$$6, _15$$6, _16$$6, _18$$6, _19$$9, _20$$9, _21$$9, _22$$9, _25$$10, _27$$10, _29$$10, _31$$10, _33$$10, _35$$10, _37$$10, _39$$10, _41$$10, _43$$10, _45$$10, _47$$10, _49$$10, _51$$10, _53$$10, _54$$11, _55$$11, _56$$11, _57$$11, _83$$11, _58$$12, _59$$12, _60$$12, _61$$12, _62$$12, _63$$12, _80$$12, _81$$12, _82$$12, _64$$14, _65$$14, _66$$14, _67$$14, _68$$14, _69$$14, _70$$14, _71$$14, _72$$16, _73$$16, _74$$16, _75$$16, _76$$19, _77$$19, _78$$19, _79$$19;
	zend_long command, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_31$$10);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_47$$10);
	ZVAL_UNDEF(&_49$$10);
	ZVAL_UNDEF(&_51$$10);
	ZVAL_UNDEF(&_53$$10);
	ZVAL_UNDEF(&_54$$11);
	ZVAL_UNDEF(&_55$$11);
	ZVAL_UNDEF(&_56$$11);
	ZVAL_UNDEF(&_57$$11);
	ZVAL_UNDEF(&_83$$11);
	ZVAL_UNDEF(&_58$$12);
	ZVAL_UNDEF(&_59$$12);
	ZVAL_UNDEF(&_60$$12);
	ZVAL_UNDEF(&_61$$12);
	ZVAL_UNDEF(&_62$$12);
	ZVAL_UNDEF(&_63$$12);
	ZVAL_UNDEF(&_80$$12);
	ZVAL_UNDEF(&_81$$12);
	ZVAL_UNDEF(&_82$$12);
	ZVAL_UNDEF(&_64$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_66$$14);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_68$$14);
	ZVAL_UNDEF(&_69$$14);
	ZVAL_UNDEF(&_70$$14);
	ZVAL_UNDEF(&_71$$14);
	ZVAL_UNDEF(&_72$$16);
	ZVAL_UNDEF(&_73$$16);
	ZVAL_UNDEF(&_74$$16);
	ZVAL_UNDEF(&_75$$16);
	ZVAL_UNDEF(&_76$$19);
	ZVAL_UNDEF(&_77$$19);
	ZVAL_UNDEF(&_78$$19);
	ZVAL_UNDEF(&_79$$19);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &command_param);

	command = zephir_get_intval(command_param);


	if (command == 1) {
		zephir_read_property(&_0$$3, this_ptr, SL("output"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_1$$3, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VV(&_2$$3, &_0$$3, &_1$$3);
		zephir_update_property_zval(this_ptr, SL("output"), &_2$$3);
	}
	_3 = command == 1;
	if (!(_3)) {
		_3 = command == 2;
	}
	if (_3) {
		zephir_read_property(&_4$$4, this_ptr, SL("b"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("a"), &_4$$4);
		zephir_read_property(&_5$$4, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
		_6$$4 = ZEPHIR_IS_STRING_IDENTICAL(&_5$$4, "'");
		if (!(_6$$4)) {
			zephir_read_property(&_7$$4, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
			_6$$4 = ZEPHIR_IS_STRING_IDENTICAL(&_7$$4, "\"");
		}
		if (_6$$4) {
			while (1) {
				if (!(1)) {
					break;
				}
				zephir_read_property(&_8$$6, this_ptr, SL("output"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_9$$6, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_LNVAR(_10$$6);
				ZEPHIR_CONCAT_VV(&_10$$6, &_8$$6, &_9$$6);
				zephir_update_property_zval(this_ptr, SL("output"), &_10$$6);
				ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "get", &_12, 0);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("a"), &_11$$6);
				zephir_read_property(&_13$$6, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_14$$6, this_ptr, SL("b"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_IDENTICAL(&_13$$6, &_14$$6)) {
					break;
				}
				zephir_read_property(&_15$$6, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_16$$6, "ord", &_17, 34, &_15$$6);
				zephir_check_call_status();
				if (ZEPHIR_LE_LONG(&_16$$6, 10)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unterminated string literal.", "ice/filter/js.zep", 89);
					return;
				}
				zephir_read_property(&_18$$6, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_STRING_IDENTICAL(&_18$$6, "\\")) {
					zephir_read_property(&_19$$9, this_ptr, SL("output"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_20$$9, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_LNVAR(_21$$9);
					ZEPHIR_CONCAT_VV(&_21$$9, &_19$$9, &_20$$9);
					zephir_update_property_zval(this_ptr, SL("output"), &_21$$9);
					ZEPHIR_CALL_METHOD(&_22$$9, this_ptr, "get", &_12, 0);
					zephir_check_call_status();
					zephir_update_property_zval(this_ptr, SL("a"), &_22$$9);
				}
			}
		}
	}
	_23 = command == 1;
	if (!(_23)) {
		_23 = command == 2;
	}
	_24 = _23;
	if (!(_24)) {
		_24 = command == 3;
	}
	if (_24) {
		ZEPHIR_CALL_METHOD(&_25$$10, this_ptr, "next", &_26, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("b"), &_25$$10);
		zephir_read_property(&_27$$10, this_ptr, SL("b"), PH_NOISY_CC | PH_READONLY);
		_28$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_27$$10, "/");
		if (_28$$10) {
			zephir_read_property(&_29$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
			_30$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_29$$10, "(");
			if (!(_30$$10)) {
				zephir_read_property(&_31$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_30$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_31$$10, ",");
			}
			_32$$10 = _30$$10;
			if (!(_32$$10)) {
				zephir_read_property(&_33$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_32$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_33$$10, "=");
			}
			_34$$10 = _32$$10;
			if (!(_34$$10)) {
				zephir_read_property(&_35$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_34$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_35$$10, ":");
			}
			_36$$10 = _34$$10;
			if (!(_36$$10)) {
				zephir_read_property(&_37$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_36$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_37$$10, "[");
			}
			_38$$10 = _36$$10;
			if (!(_38$$10)) {
				zephir_read_property(&_39$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_38$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_39$$10, "!");
			}
			_40$$10 = _38$$10;
			if (!(_40$$10)) {
				zephir_read_property(&_41$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_40$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_41$$10, "&");
			}
			_42$$10 = _40$$10;
			if (!(_42$$10)) {
				zephir_read_property(&_43$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_42$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_43$$10, "|");
			}
			_44$$10 = _42$$10;
			if (!(_44$$10)) {
				zephir_read_property(&_45$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_44$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_45$$10, "?");
			}
			_46$$10 = _44$$10;
			if (!(_46$$10)) {
				zephir_read_property(&_47$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_46$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_47$$10, "{");
			}
			_48$$10 = _46$$10;
			if (!(_48$$10)) {
				zephir_read_property(&_49$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_48$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_49$$10, "}");
			}
			_50$$10 = _48$$10;
			if (!(_50$$10)) {
				zephir_read_property(&_51$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_50$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_51$$10, ";");
			}
			_52$$10 = _50$$10;
			if (!(_52$$10)) {
				zephir_read_property(&_53$$10, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				_52$$10 = ZEPHIR_IS_STRING_IDENTICAL(&_53$$10, "\n");
			}
			_28$$10 = _52$$10;
		}
		if (_28$$10) {
			zephir_read_property(&_54$$11, this_ptr, SL("output"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_55$$11, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_56$$11, this_ptr, SL("b"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_57$$11);
			ZEPHIR_CONCAT_VVV(&_57$$11, &_54$$11, &_55$$11, &_56$$11);
			zephir_update_property_zval(this_ptr, SL("output"), &_57$$11);
			while (1) {
				if (!(1)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&_58$$12, this_ptr, "get", &_12, 0);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("a"), &_58$$12);
				zephir_read_property(&_59$$12, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_60$$12, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_61$$12, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_62$$12, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_63$$12, "ord", &_17, 34, &_62$$12);
				zephir_check_call_status();
				if (ZEPHIR_IS_STRING_IDENTICAL(&_59$$12, "[")) {
					while (1) {
						if (!(1)) {
							break;
						}
						zephir_read_property(&_64$$14, this_ptr, SL("output"), PH_NOISY_CC | PH_READONLY);
						zephir_read_property(&_65$$14, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_LNVAR(_66$$14);
						ZEPHIR_CONCAT_VV(&_66$$14, &_64$$14, &_65$$14);
						zephir_update_property_zval(this_ptr, SL("output"), &_66$$14);
						ZEPHIR_CALL_METHOD(&_67$$14, this_ptr, "get", &_12, 0);
						zephir_check_call_status();
						zephir_update_property_zval(this_ptr, SL("a"), &_67$$14);
						zephir_read_property(&_68$$14, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
						zephir_read_property(&_69$$14, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
						zephir_read_property(&_70$$14, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_FUNCTION(&_71$$14, "ord", &_17, 34, &_70$$14);
						zephir_check_call_status();
						if (ZEPHIR_IS_STRING_IDENTICAL(&_68$$14, "]")) {
							break;
						} else if (ZEPHIR_IS_STRING_IDENTICAL(&_69$$14, "\\")) {
							zephir_read_property(&_72$$16, this_ptr, SL("output"), PH_NOISY_CC | PH_READONLY);
							zephir_read_property(&_73$$16, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_LNVAR(_74$$16);
							ZEPHIR_CONCAT_VV(&_74$$16, &_72$$16, &_73$$16);
							zephir_update_property_zval(this_ptr, SL("output"), &_74$$16);
							ZEPHIR_CALL_METHOD(&_75$$16, this_ptr, "get", &_12, 0);
							zephir_check_call_status();
							zephir_update_property_zval(this_ptr, SL("a"), &_75$$16);
						} else if (ZEPHIR_LE_LONG(&_71$$14, 10)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unterminated regular expression set in regex literal.", "ice/filter/js.zep", 129);
							return;
						}
					}
				} else if (ZEPHIR_IS_STRING_IDENTICAL(&_60$$12, "/")) {
					break;
				} else if (ZEPHIR_IS_STRING_IDENTICAL(&_61$$12, "\\")) {
					zephir_read_property(&_76$$19, this_ptr, SL("output"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_77$$19, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_LNVAR(_78$$19);
					ZEPHIR_CONCAT_VV(&_78$$19, &_76$$19, &_77$$19);
					zephir_update_property_zval(this_ptr, SL("output"), &_78$$19);
					ZEPHIR_CALL_METHOD(&_79$$19, this_ptr, "get", &_12, 0);
					zephir_check_call_status();
					zephir_update_property_zval(this_ptr, SL("a"), &_79$$19);
				} else if (ZEPHIR_LE_LONG(&_63$$12, 10)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unterminated regular expression literal.", "ice/filter/js.zep", 138);
					return;
				}
				zephir_read_property(&_80$$12, this_ptr, SL("output"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_81$$12, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_LNVAR(_82$$12);
				ZEPHIR_CONCAT_VV(&_82$$12, &_80$$12, &_81$$12);
				zephir_update_property_zval(this_ptr, SL("output"), &_82$$12);
			}
			ZEPHIR_CALL_METHOD(&_83$$11, this_ptr, "next", &_26, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("b"), &_83$$11);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get next char. Convert ctrl char to space.
 *
 * @return string|null
 */
PHP_METHOD(Ice_Filter_Js, get) {

	zend_bool _6, _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$null, c, i, _8, _0$$3, _1$$3, _2$$4, _3$$4, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&c);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&c);
	zephir_read_property(&c, this_ptr, SL("lookAhead"), PH_NOISY_CC);
	zephir_update_property_zval(this_ptr, SL("lookAhead"), &__$null);
	if (Z_TYPE_P(&c) == IS_NULL) {
		zephir_read_property(&_0$$3, this_ptr, SL("inputIndex"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_1$$3, this_ptr, SL("inputLength"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_LT(&_0$$3, &_1$$3)) {
			zephir_read_property(&_2$$4, this_ptr, SL("input"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_3$$4, this_ptr, SL("inputIndex"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_4$$4, 1);
			ZEPHIR_INIT_NVAR(&c);
			zephir_substr(&c, &_2$$4, zephir_get_intval(&_3$$4), 1 , 0);
			ZEPHIR_OBS_VAR(&i);
			zephir_read_property(&i, this_ptr, SL("inputIndex"), PH_NOISY_CC);
			ZEPHIR_INIT_ZVAL_NREF(_5$$4);
			ZVAL_LONG(&_5$$4, (zephir_get_numberval(&i) + 1));
			zephir_update_property_zval(this_ptr, SL("inputIndex"), &_5$$4);
		} else {
			ZEPHIR_INIT_NVAR(&c);
			ZVAL_NULL(&c);
		}
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&c, "\r")) {
		RETURN_MM_STRING("\n");
	}
	_6 = Z_TYPE_P(&c) == IS_NULL;
	if (!(_6)) {
		_6 = ZEPHIR_IS_STRING_IDENTICAL(&c, "\n");
	}
	_7 = _6;
	if (!(_7)) {
		ZEPHIR_CALL_FUNCTION(&_8, "ord", NULL, 34, &c);
		zephir_check_call_status();
		_7 = ZEPHIR_GE_LONG(&_8, 32);
	}
	if (_7) {
		RETURN_CCTOR(&c);
	}
	RETURN_MM_STRING(" ");

}

/**
 * Is $c a letter, digit, underscore, dollar sign, or non-ASCII character.
 *
 * @return bool
 */
PHP_METHOD(Ice_Filter_Js, isAlphaNum) {

	zend_bool _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *c, c_sub, _0, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&c_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &c);



	ZEPHIR_CALL_FUNCTION(&_0, "ord", NULL, 34, c);
	zephir_check_call_status();
	_1 = ZEPHIR_GT_LONG(&_0, 126);
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING_IDENTICAL(c, "\\");
	}
	_2 = _1;
	if (!(_2)) {
		ZEPHIR_INIT_VAR(&_3);
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "/^[\\w\\$]$/");
		ZEPHIR_INIT_VAR(&_5);
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_STRING(&_6, "/^[\\w\\$]$/");
		zephir_preg_match(&_5, &_6, c, &_3, 0, 0 , 0  TSRMLS_CC);
		_2 = ZEPHIR_IS_LONG_IDENTICAL(&_5, 1);
	}
	RETURN_MM_BOOL(_2);

}

/**
 * Perform minification, return result
 *
 * @return string
 */
PHP_METHOD(Ice_Filter_Js, min) {

	zval _0, _1, _2, _3, _6$$4, _7$$5, _8$$5, _10$$6, _11$$7, _12$$8, _13$$9, _14$$10, _15$$11, _16$$11, _17$$12, _18$$13, _19$$14, _20$$15, _21$$15, _23$$15, _22$$16, _24$$17, _25$$18, _26$$19, _27$$19, _28$$20, _29$$21, _30$$22;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$22);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "peek", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\xef");
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_FUNCTION(&_3, "strncmp", NULL, 74, &_0, &_1, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_3, 0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_4, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_4, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_4, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\n");
	zephir_update_property_zval(this_ptr, SL("a"), &_1);
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_2);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_2, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
		if (!(Z_TYPE_P(&_2) != IS_NULL)) {
			break;
		}
		zephir_read_property(&_6$$4, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
		do {
			if (ZEPHIR_IS_STRING(&_6$$4, " ")) {
				zephir_read_property(&_8$$5, this_ptr, SL("b"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_7$$5, this_ptr, "isalphanum", &_9, 0, &_8$$5);
				zephir_check_call_status();
				if (zephir_is_true(&_7$$5)) {
					ZVAL_LONG(&_10$$6, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_10$$6);
					zephir_check_call_status();
				} else {
					ZVAL_LONG(&_11$$7, 2);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_11$$7);
					zephir_check_call_status();
				}
				break;
			}
			if (ZEPHIR_IS_STRING(&_6$$4, "\n")) {
				zephir_read_property(&_12$$8, this_ptr, SL("b"), PH_NOISY_CC | PH_READONLY);
				do {
					if (ZEPHIR_IS_STRING(&_12$$8, "{") || ZEPHIR_IS_STRING(&_12$$8, "[") || ZEPHIR_IS_STRING(&_12$$8, "(") || ZEPHIR_IS_STRING(&_12$$8, "+") || ZEPHIR_IS_STRING(&_12$$8, "-") || ZEPHIR_IS_STRING(&_12$$8, "!") || ZEPHIR_IS_STRING(&_12$$8, "~")) {
						ZVAL_LONG(&_13$$9, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_13$$9);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_STRING(&_12$$8, " ")) {
						ZVAL_LONG(&_14$$10, 3);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_14$$10);
						zephir_check_call_status();
						break;
					}
					zephir_read_property(&_16$$11, this_ptr, SL("b"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_15$$11, this_ptr, "isalphanum", &_9, 0, &_16$$11);
					zephir_check_call_status();
					if (zephir_is_true(&_15$$11)) {
						ZVAL_LONG(&_17$$12, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_17$$12);
						zephir_check_call_status();
					} else {
						ZVAL_LONG(&_18$$13, 2);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_18$$13);
						zephir_check_call_status();
					}
				} while(0);

				break;
			}
			zephir_read_property(&_19$$14, this_ptr, SL("b"), PH_NOISY_CC | PH_READONLY);
			do {
				if (ZEPHIR_IS_STRING(&_19$$14, " ")) {
					zephir_read_property(&_21$$15, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_20$$15, this_ptr, "isalphanum", &_9, 0, &_21$$15);
					zephir_check_call_status();
					if (zephir_is_true(&_20$$15)) {
						ZVAL_LONG(&_22$$16, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_22$$16);
						zephir_check_call_status();
						break;
					}
					ZVAL_LONG(&_23$$15, 3);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_23$$15);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_STRING(&_19$$14, "\n")) {
					zephir_read_property(&_24$$17, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
					do {
						if (ZEPHIR_IS_STRING(&_24$$17, "}") || ZEPHIR_IS_STRING(&_24$$17, "]") || ZEPHIR_IS_STRING(&_24$$17, ")") || ZEPHIR_IS_STRING(&_24$$17, "+") || ZEPHIR_IS_STRING(&_24$$17, "-") || ZEPHIR_IS_STRING(&_24$$17, "\"") || ZEPHIR_IS_STRING(&_24$$17, "'")) {
							ZVAL_LONG(&_25$$18, 1);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_25$$18);
							zephir_check_call_status();
							break;
						}
						zephir_read_property(&_27$$19, this_ptr, SL("a"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(&_26$$19, this_ptr, "isalphanum", &_9, 0, &_27$$19);
						zephir_check_call_status();
						if (zephir_is_true(&_26$$19)) {
							ZVAL_LONG(&_28$$20, 1);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_28$$20);
							zephir_check_call_status();
						} else {
							ZVAL_LONG(&_29$$21, 3);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_29$$21);
							zephir_check_call_status();
						}
					} while(0);

					break;
				}
				ZVAL_LONG(&_30$$22, 1);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_5, 0, &_30$$22);
				zephir_check_call_status();
				break;
			} while(0);

		} while(0);

	}
	RETURN_MM_MEMBER(getThis(), "output");

}

/**
 * Get the next character, skipping over comments. peek() is used to see
 *  if a "/" is followed by a "/" or "*".
 *
 * @throws Exception On unterminated comment.
 * @return string
 */
PHP_METHOD(Ice_Filter_Js, next) {

	zval c, _1$$3, _3$$5, _5$$8, _6$$9;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&c);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&c, this_ptr, "get", &_0, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(&c, "/")) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "peek", &_2, 0);
		zephir_check_call_status();
		do {
			if (ZEPHIR_IS_STRING(&_1$$3, "/")) {
				while (1) {
					if (!(1)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&c, this_ptr, "get", &_0, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_3$$5, "ord", &_4, 34, &c);
					zephir_check_call_status();
					if (ZEPHIR_LE_LONG(&_3$$5, 10)) {
						RETURN_CCTOR(&c);
					}
				}
			}
			if (ZEPHIR_IS_STRING(&_1$$3, "*")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_0, 0);
				zephir_check_call_status();
				while (1) {
					if (!(1)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "get", &_0, 0);
					zephir_check_call_status();
					do {
						if (ZEPHIR_IS_STRING(&_5$$8, "*")) {
							ZEPHIR_CALL_METHOD(&_6$$9, this_ptr, "peek", &_2, 0);
							zephir_check_call_status();
							if (ZEPHIR_IS_STRING_IDENTICAL(&_6$$9, "/")) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_0, 0);
								zephir_check_call_status();
								RETURN_MM_STRING(" ");
							}
							break;
						}
						if (Z_TYPE_P(&_5$$8) == IS_NULL) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unterminated comment.", "ice/filter/js.zep", 312);
							return;
						}
					} while(0);

				}
			}
			RETURN_CCTOR(&c);
		} while(0);

	}
	RETURN_CCTOR(&c);

}

/**
 * Get next char. If is ctrl character, translate to a space or newline.
 *
 * @return string|null
 */
PHP_METHOD(Ice_Filter_Js, peek) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("lookAhead"), &_0);
	RETURN_MM_MEMBER(getThis(), "lookAhead");

}

