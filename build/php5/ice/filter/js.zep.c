
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

	zend_declare_class_constant_long(ice_filter_js_ce, SL("ORD_LF"), 10 TSRMLS_CC);

	zend_declare_class_constant_long(ice_filter_js_ce, SL("ORD_SPACE"), 32 TSRMLS_CC);

	zend_declare_class_constant_long(ice_filter_js_ce, SL("ACTION_KEEP_A"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_filter_js_ce, SL("ACTION_DELETE_A"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_filter_js_ce, SL("ACTION_DELETE_A_B"), 3 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Filter_Js, getOutput) {

	

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
	zval *js_param = NULL, *_0, *_1, _2, _3, *_4;
	zval *js = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &js_param);

	zephir_get_strval(js, js_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "", 1);
	zephir_update_property_this(getThis(), SL("a"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "", 1);
	zephir_update_property_this(getThis(), SL("b"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "\r\n", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "\n", 0);
	zephir_fast_str_replace(&_1, &_2, &_3, js TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("input"), _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("input"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, zephir_fast_strlen_ev(_0));
	zephir_update_property_this(getThis(), SL("inputLength"), _4 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, 0);
	zephir_update_property_this(getThis(), SL("inputIndex"), _4 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("lookAhead"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_STRING(_4, "", 1);
	zephir_update_property_this(getThis(), SL("output"), _4 TSRMLS_CC);
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
	zval *command_param = NULL, *_0$$3, *_1$$3, *_2$$3, *_4$$4, *_5$$4, *_7$$4, *_8$$6, *_9$$6, *_10$$6 = NULL, *_11$$6 = NULL, *_13$$6, *_14$$6, *_15$$6, *_16$$6 = NULL, *_18$$6, *_19$$9, *_20$$9, *_21$$9 = NULL, *_22$$9 = NULL, *_25$$10 = NULL, *_27$$10, *_29$$10, *_31$$10, *_33$$10, *_35$$10, *_37$$10, *_39$$10, *_41$$10, *_43$$10, *_45$$10, *_47$$10, *_49$$10, *_51$$10, *_53$$10, *_54$$11, *_55$$11, *_56$$11, *_57$$11, *_83$$11 = NULL, *_58$$12 = NULL, *_59$$12, *_60$$12, *_61$$12, *_62$$12, *_63$$12 = NULL, *_80$$12, *_81$$12, *_82$$12 = NULL, *_64$$14, *_65$$14, *_66$$14 = NULL, *_67$$14 = NULL, *_68$$14, *_69$$14, *_70$$14, *_71$$14 = NULL, *_72$$16, *_73$$16, *_74$$16 = NULL, *_75$$16 = NULL, *_76$$19, *_77$$19, *_78$$19 = NULL, *_79$$19 = NULL;
	zend_long command, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &command_param);

	command = zephir_get_intval(command_param);


	if (command == 1) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_VV(_2$$3, _0$$3, _1$$3);
		zephir_update_property_this(getThis(), SL("output"), _2$$3 TSRMLS_CC);
	}
	_3 = command == 1;
	if (!(_3)) {
		_3 = command == 2;
	}
	if (_3) {
		_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("a"), _4$$4 TSRMLS_CC);
		_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
		_6$$4 = ZEPHIR_IS_STRING_IDENTICAL(_5$$4, "'");
		if (!(_6$$4)) {
			_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
			_6$$4 = ZEPHIR_IS_STRING_IDENTICAL(_7$$4, "\"");
		}
		if (_6$$4) {
			while (1) {
				if (!(1)) {
					break;
				}
				_8$$6 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
				_9$$6 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_10$$6);
				ZEPHIR_CONCAT_VV(_10$$6, _8$$6, _9$$6);
				zephir_update_property_this(getThis(), SL("output"), _10$$6 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "get", &_12, 0);
				zephir_check_call_status();
				zephir_update_property_this(getThis(), SL("a"), _11$$6 TSRMLS_CC);
				_13$$6 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_14$$6 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
				if (ZEPHIR_IS_IDENTICAL(_13$$6, _14$$6)) {
					break;
				}
				_15$$6 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_16$$6, "ord", &_17, 35, _15$$6);
				zephir_check_call_status();
				if (ZEPHIR_LE_LONG(_16$$6, 10)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unterminated string literal.", "ice/filter/js.zep", 89);
					return;
				}
				_18$$6 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				if (ZEPHIR_IS_STRING_IDENTICAL(_18$$6, "\\")) {
					_19$$9 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
					_20$$9 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
					ZEPHIR_INIT_LNVAR(_21$$9);
					ZEPHIR_CONCAT_VV(_21$$9, _19$$9, _20$$9);
					zephir_update_property_this(getThis(), SL("output"), _21$$9 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_22$$9, this_ptr, "get", &_12, 0);
					zephir_check_call_status();
					zephir_update_property_this(getThis(), SL("a"), _22$$9 TSRMLS_CC);
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
		zephir_update_property_this(getThis(), SL("b"), _25$$10 TSRMLS_CC);
		_27$$10 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
		_28$$10 = ZEPHIR_IS_STRING_IDENTICAL(_27$$10, "/");
		if (_28$$10) {
			_29$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
			_30$$10 = ZEPHIR_IS_STRING_IDENTICAL(_29$$10, "(");
			if (!(_30$$10)) {
				_31$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_30$$10 = ZEPHIR_IS_STRING_IDENTICAL(_31$$10, ",");
			}
			_32$$10 = _30$$10;
			if (!(_32$$10)) {
				_33$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_32$$10 = ZEPHIR_IS_STRING_IDENTICAL(_33$$10, "=");
			}
			_34$$10 = _32$$10;
			if (!(_34$$10)) {
				_35$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_34$$10 = ZEPHIR_IS_STRING_IDENTICAL(_35$$10, ":");
			}
			_36$$10 = _34$$10;
			if (!(_36$$10)) {
				_37$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_36$$10 = ZEPHIR_IS_STRING_IDENTICAL(_37$$10, "[");
			}
			_38$$10 = _36$$10;
			if (!(_38$$10)) {
				_39$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_38$$10 = ZEPHIR_IS_STRING_IDENTICAL(_39$$10, "!");
			}
			_40$$10 = _38$$10;
			if (!(_40$$10)) {
				_41$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_40$$10 = ZEPHIR_IS_STRING_IDENTICAL(_41$$10, "&");
			}
			_42$$10 = _40$$10;
			if (!(_42$$10)) {
				_43$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_42$$10 = ZEPHIR_IS_STRING_IDENTICAL(_43$$10, "|");
			}
			_44$$10 = _42$$10;
			if (!(_44$$10)) {
				_45$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_44$$10 = ZEPHIR_IS_STRING_IDENTICAL(_45$$10, "?");
			}
			_46$$10 = _44$$10;
			if (!(_46$$10)) {
				_47$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_46$$10 = ZEPHIR_IS_STRING_IDENTICAL(_47$$10, "{");
			}
			_48$$10 = _46$$10;
			if (!(_48$$10)) {
				_49$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_48$$10 = ZEPHIR_IS_STRING_IDENTICAL(_49$$10, "}");
			}
			_50$$10 = _48$$10;
			if (!(_50$$10)) {
				_51$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_50$$10 = ZEPHIR_IS_STRING_IDENTICAL(_51$$10, ";");
			}
			_52$$10 = _50$$10;
			if (!(_52$$10)) {
				_53$$10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_52$$10 = ZEPHIR_IS_STRING_IDENTICAL(_53$$10, "\n");
			}
			_28$$10 = _52$$10;
		}
		if (_28$$10) {
			_54$$11 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
			_55$$11 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
			_56$$11 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_57$$11);
			ZEPHIR_CONCAT_VVV(_57$$11, _54$$11, _55$$11, _56$$11);
			zephir_update_property_this(getThis(), SL("output"), _57$$11 TSRMLS_CC);
			while (1) {
				if (!(1)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&_58$$12, this_ptr, "get", &_12, 0);
				zephir_check_call_status();
				zephir_update_property_this(getThis(), SL("a"), _58$$12 TSRMLS_CC);
				_59$$12 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_60$$12 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_61$$12 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_62$$12 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_63$$12, "ord", &_17, 35, _62$$12);
				zephir_check_call_status();
				if (ZEPHIR_IS_STRING_IDENTICAL(_59$$12, "[")) {
					while (1) {
						if (!(1)) {
							break;
						}
						_64$$14 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
						_65$$14 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
						ZEPHIR_INIT_LNVAR(_66$$14);
						ZEPHIR_CONCAT_VV(_66$$14, _64$$14, _65$$14);
						zephir_update_property_this(getThis(), SL("output"), _66$$14 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&_67$$14, this_ptr, "get", &_12, 0);
						zephir_check_call_status();
						zephir_update_property_this(getThis(), SL("a"), _67$$14 TSRMLS_CC);
						_68$$14 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
						_69$$14 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
						_70$$14 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
						ZEPHIR_CALL_FUNCTION(&_71$$14, "ord", &_17, 35, _70$$14);
						zephir_check_call_status();
						if (ZEPHIR_IS_STRING_IDENTICAL(_68$$14, "]")) {
							break;
						} else if (ZEPHIR_IS_STRING_IDENTICAL(_69$$14, "\\")) {
							_72$$16 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
							_73$$16 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
							ZEPHIR_INIT_LNVAR(_74$$16);
							ZEPHIR_CONCAT_VV(_74$$16, _72$$16, _73$$16);
							zephir_update_property_this(getThis(), SL("output"), _74$$16 TSRMLS_CC);
							ZEPHIR_CALL_METHOD(&_75$$16, this_ptr, "get", &_12, 0);
							zephir_check_call_status();
							zephir_update_property_this(getThis(), SL("a"), _75$$16 TSRMLS_CC);
						} else if (ZEPHIR_LE_LONG(_71$$14, 10)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unterminated regular expression set in regex literal.", "ice/filter/js.zep", 129);
							return;
						}
					}
				} else if (ZEPHIR_IS_STRING_IDENTICAL(_60$$12, "/")) {
					break;
				} else if (ZEPHIR_IS_STRING_IDENTICAL(_61$$12, "\\")) {
					_76$$19 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
					_77$$19 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
					ZEPHIR_INIT_LNVAR(_78$$19);
					ZEPHIR_CONCAT_VV(_78$$19, _76$$19, _77$$19);
					zephir_update_property_this(getThis(), SL("output"), _78$$19 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_79$$19, this_ptr, "get", &_12, 0);
					zephir_check_call_status();
					zephir_update_property_this(getThis(), SL("a"), _79$$19 TSRMLS_CC);
				} else if (ZEPHIR_LE_LONG(_63$$12, 10)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unterminated regular expression literal.", "ice/filter/js.zep", 138);
					return;
				}
				_80$$12 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
				_81$$12 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_82$$12);
				ZEPHIR_CONCAT_VV(_82$$12, _80$$12, _81$$12);
				zephir_update_property_this(getThis(), SL("output"), _82$$12 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_83$$11, this_ptr, "next", &_26, 0);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("b"), _83$$11 TSRMLS_CC);
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
	zval *c = NULL, *i = NULL, *_8 = NULL, *_0$$3, *_1$$3, *_2$$4, *_3$$4, _4$$4, *_5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(c);
	zephir_read_property_this(&c, this_ptr, SL("lookAhead"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("lookAhead"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	if (Z_TYPE_P(c) == IS_NULL) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("inputIndex"), PH_NOISY_CC);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("inputLength"), PH_NOISY_CC);
		if (ZEPHIR_LT(_0$$3, _1$$3)) {
			_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("input"), PH_NOISY_CC);
			_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("inputIndex"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_4$$4);
			ZVAL_LONG(&_4$$4, 1);
			ZEPHIR_INIT_NVAR(c);
			zephir_substr(c, _2$$4, zephir_get_intval(_3$$4), 1 , 0);
			ZEPHIR_OBS_VAR(i);
			zephir_read_property_this(&i, this_ptr, SL("inputIndex"), PH_NOISY_CC);
			ZEPHIR_INIT_ZVAL_NREF(_5$$4);
			ZVAL_LONG(_5$$4, (zephir_get_numberval(i) + 1));
			zephir_update_property_this(getThis(), SL("inputIndex"), _5$$4 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(c);
			ZVAL_NULL(c);
		}
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(c, "\r")) {
		RETURN_MM_STRING("\n", 1);
	}
	_6 = Z_TYPE_P(c) == IS_NULL;
	if (!(_6)) {
		_6 = ZEPHIR_IS_STRING_IDENTICAL(c, "\n");
	}
	_7 = _6;
	if (!(_7)) {
		ZEPHIR_CALL_FUNCTION(&_8, "ord", NULL, 35, c);
		zephir_check_call_status();
		_7 = ZEPHIR_GE_LONG(_8, 32);
	}
	if (_7) {
		RETURN_CCTOR(c);
	}
	RETURN_MM_STRING(" ", 1);

}

/**
 * Is $c a letter, digit, underscore, dollar sign, or non-ASCII character.
 *
 * @return bool
 */
PHP_METHOD(Ice_Filter_Js, isAlphaNum) {

	zend_bool _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *c, *_0 = NULL, *_3, _4, *_5, _6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &c);



	ZEPHIR_CALL_FUNCTION(&_0, "ord", NULL, 35, c);
	zephir_check_call_status();
	_1 = ZEPHIR_GT_LONG(_0, 126);
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING_IDENTICAL(c, "\\");
	}
	_2 = _1;
	if (!(_2)) {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "/^[\\w\\$]$/", 0);
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_STRING(&_6, "/^[\\w\\$]$/", 0);
		zephir_preg_match(_5, &_6, c, _3, 0, 0 , 0  TSRMLS_CC);
		_2 = ZEPHIR_IS_LONG_IDENTICAL(_5, 1);
	}
	RETURN_MM_BOOL(_2);

}

/**
 * Perform minification, return result
 *
 * @return string
 */
PHP_METHOD(Ice_Filter_Js, min) {

	zval *_0 = NULL, _1, _2, *_3 = NULL, *_5, *_6, *_8$$4, *_9$$5 = NULL, *_10$$5, *_12$$6 = NULL, *_13$$7 = NULL, *_14$$8, *_15$$9 = NULL, *_16$$10 = NULL, *_17$$11 = NULL, *_18$$11, *_19$$12 = NULL, *_20$$13 = NULL, *_21$$14, *_22$$15 = NULL, *_23$$15, *_25$$15 = NULL, *_24$$16 = NULL, *_26$$17, *_27$$18 = NULL, *_28$$19 = NULL, *_29$$19, *_30$$20 = NULL, *_31$$21 = NULL, *_32$$22 = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "peek", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\xef", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_FUNCTION(&_3, "strncmp", NULL, 84, _0, &_1, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_3, 0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_4, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_4, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_4, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_STRING(_5, "\n", 1);
	zephir_update_property_this(getThis(), SL("a"), _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
	zephir_check_call_status();
	while (1) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
		if (!(Z_TYPE_P(_5) != IS_NULL)) {
			break;
		}
		_8$$4 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_STRING(_8$$4, " ")) {
				_10$$5 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_9$$5, this_ptr, "isalphanum", &_11, 0, _10$$5);
				zephir_check_call_status();
				if (zephir_is_true(_9$$5)) {
					ZEPHIR_INIT_NVAR(_12$$6);
					ZVAL_LONG(_12$$6, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _12$$6);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(_13$$7);
					ZVAL_LONG(_13$$7, 2);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _13$$7);
					zephir_check_call_status();
				}
				break;
			}
			if (ZEPHIR_IS_STRING(_8$$4, "\n")) {
				_14$$8 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
				do {
					if (ZEPHIR_IS_STRING(_14$$8, "{") || ZEPHIR_IS_STRING(_14$$8, "[") || ZEPHIR_IS_STRING(_14$$8, "(") || ZEPHIR_IS_STRING(_14$$8, "+") || ZEPHIR_IS_STRING(_14$$8, "-") || ZEPHIR_IS_STRING(_14$$8, "!") || ZEPHIR_IS_STRING(_14$$8, "~")) {
						ZEPHIR_INIT_NVAR(_15$$9);
						ZVAL_LONG(_15$$9, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _15$$9);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_STRING(_14$$8, " ")) {
						ZEPHIR_INIT_NVAR(_16$$10);
						ZVAL_LONG(_16$$10, 3);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _16$$10);
						zephir_check_call_status();
						break;
					}
					_18$$11 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(&_17$$11, this_ptr, "isalphanum", &_11, 0, _18$$11);
					zephir_check_call_status();
					if (zephir_is_true(_17$$11)) {
						ZEPHIR_INIT_NVAR(_19$$12);
						ZVAL_LONG(_19$$12, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _19$$12);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(_20$$13);
						ZVAL_LONG(_20$$13, 2);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _20$$13);
						zephir_check_call_status();
					}
				} while(0);

				break;
			}
			_21$$14 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
			do {
				if (ZEPHIR_IS_STRING(_21$$14, " ")) {
					_23$$15 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(&_22$$15, this_ptr, "isalphanum", &_11, 0, _23$$15);
					zephir_check_call_status();
					if (zephir_is_true(_22$$15)) {
						ZEPHIR_INIT_NVAR(_24$$16);
						ZVAL_LONG(_24$$16, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _24$$16);
						zephir_check_call_status();
						break;
					}
					ZEPHIR_INIT_NVAR(_25$$15);
					ZVAL_LONG(_25$$15, 3);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _25$$15);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_STRING(_21$$14, "\n")) {
					_26$$17 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
					do {
						if (ZEPHIR_IS_STRING(_26$$17, "}") || ZEPHIR_IS_STRING(_26$$17, "]") || ZEPHIR_IS_STRING(_26$$17, ")") || ZEPHIR_IS_STRING(_26$$17, "+") || ZEPHIR_IS_STRING(_26$$17, "-") || ZEPHIR_IS_STRING(_26$$17, "\"") || ZEPHIR_IS_STRING(_26$$17, "'")) {
							ZEPHIR_INIT_NVAR(_27$$18);
							ZVAL_LONG(_27$$18, 1);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _27$$18);
							zephir_check_call_status();
							break;
						}
						_29$$19 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
						ZEPHIR_CALL_METHOD(&_28$$19, this_ptr, "isalphanum", &_11, 0, _29$$19);
						zephir_check_call_status();
						if (zephir_is_true(_28$$19)) {
							ZEPHIR_INIT_NVAR(_30$$20);
							ZVAL_LONG(_30$$20, 1);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _30$$20);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(_31$$21);
							ZVAL_LONG(_31$$21, 3);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _31$$21);
							zephir_check_call_status();
						}
					} while(0);

					break;
				}
				ZEPHIR_INIT_NVAR(_32$$22);
				ZVAL_LONG(_32$$22, 1);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _32$$22);
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

	zval *c = NULL, *_1$$3 = NULL, *_3$$5 = NULL, *_5$$8 = NULL, *_6$$9 = NULL;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&c, this_ptr, "get", &_0, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(c, "/")) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "peek", &_2, 0);
		zephir_check_call_status();
		do {
			if (ZEPHIR_IS_STRING(_1$$3, "/")) {
				while (1) {
					if (!(1)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&c, this_ptr, "get", &_0, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_3$$5, "ord", &_4, 35, c);
					zephir_check_call_status();
					if (ZEPHIR_LE_LONG(_3$$5, 10)) {
						RETURN_CCTOR(c);
					}
				}
			}
			if (ZEPHIR_IS_STRING(_1$$3, "*")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_0, 0);
				zephir_check_call_status();
				while (1) {
					if (!(1)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "get", &_0, 0);
					zephir_check_call_status();
					do {
						if (ZEPHIR_IS_STRING(_5$$8, "*")) {
							ZEPHIR_CALL_METHOD(&_6$$9, this_ptr, "peek", &_2, 0);
							zephir_check_call_status();
							if (ZEPHIR_IS_STRING_IDENTICAL(_6$$9, "/")) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_0, 0);
								zephir_check_call_status();
								RETURN_MM_STRING(" ", 1);
							}
							break;
						}
						if (Z_TYPE_P(_5$$8) == IS_NULL) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unterminated comment.", "ice/filter/js.zep", 312);
							return;
						}
					} while(0);

				}
			}
			RETURN_CCTOR(c);
		} while(0);

	}
	RETURN_CCTOR(c);

}

/**
 * Get next char. If is ctrl character, translate to a space or newline.
 *
 * @return string|null
 */
PHP_METHOD(Ice_Filter_Js, peek) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("lookAhead"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(getThis(), "lookAhead");

}

