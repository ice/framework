
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
 * @copyright   (c) 2014-2015 Ice Team
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


	RETURN_MEMBER(this_ptr, "output");

}

/**
 * Minify the js.
 *
 * @param string js JS code to minify
 * @return string
 */
PHP_METHOD(Ice_Filter_Js, sanitize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *js_param = NULL, *_0, *_1, _2, _3, *_4;
	zval *js = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &js_param);

	zephir_get_strval(js, js_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "", 1);
	zephir_update_property_this(this_ptr, SL("a"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "", 1);
	zephir_update_property_this(this_ptr, SL("b"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "\r\n", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "\n", 0);
	zephir_fast_str_replace(&_1, &_2, &_3, js TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("input"), _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("input"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, zephir_fast_strlen_ev(_0));
	zephir_update_property_this(this_ptr, SL("inputLength"), _4 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, 0);
	zephir_update_property_this(this_ptr, SL("inputIndex"), _4 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("lookAhead"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_STRING(_4, "", 1);
	zephir_update_property_this(this_ptr, SL("output"), _4 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_9 = NULL, *_14 = NULL, *_21 = NULL;
	zend_bool _3, _4, _20, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _34, _36;
	zval *command_param = NULL, *_0, *_1, *_2 = NULL, *_5, *_6, *_7, *_8 = NULL, *_10, *_11, *_12, *_13 = NULL, *_15, *_16, *_17, *_18 = NULL, *_19 = NULL, *_33, *_35, *_37, *_38, *_39, *_40, *_41, *_42, *_43, *_44, *_45, *_46, *_47 = NULL, *_48, *_49, *_50, *_51 = NULL, *_52, *_53, *_54 = NULL, *_55 = NULL;
	int command, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &command_param);

	command = zephir_get_intval(command_param);


	if (command == 1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VV(_2, _0, _1);
		zephir_update_property_this(this_ptr, SL("output"), _2 TSRMLS_CC);
	}
	_3 = command == 1;
	if (!(_3)) {
		_3 = command == 2;
	}
	if (_3) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("a"), _0 TSRMLS_CC);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
		_4 = ZEPHIR_IS_STRING_IDENTICAL(_1, "'");
		if (!(_4)) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
			_4 = ZEPHIR_IS_STRING_IDENTICAL(_5, "\"");
		}
		if (_4) {
			while (1) {
				if (!(1)) {
					break;
				}
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_VV(_2, _6, _7);
				zephir_update_property_this(this_ptr, SL("output"), _2 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", &_9, 0);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("a"), _8 TSRMLS_CC);
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
				if (ZEPHIR_IS_IDENTICAL(_10, _11)) {
					break;
				}
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_13, "ord", &_14, 68, _12);
				zephir_check_call_status();
				if (ZEPHIR_LE_LONG(_13, 10)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unterminated string literal.", "ice/filter/js.zep", 89);
					return;
				}
				_15 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				if (ZEPHIR_IS_STRING_IDENTICAL(_15, "\\")) {
					_16 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
					_17 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
					ZEPHIR_INIT_LNVAR(_18);
					ZEPHIR_CONCAT_VV(_18, _16, _17);
					zephir_update_property_this(this_ptr, SL("output"), _18 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_19, this_ptr, "get", &_9, 0);
					zephir_check_call_status();
					zephir_update_property_this(this_ptr, SL("a"), _19 TSRMLS_CC);
				}
			}
		}
	}
	_4 = command == 1;
	if (!(_4)) {
		_4 = command == 2;
	}
	_20 = _4;
	if (!(_20)) {
		_20 = command == 3;
	}
	if (_20) {
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "next", &_21, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("b"), _8 TSRMLS_CC);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
		_22 = ZEPHIR_IS_STRING_IDENTICAL(_0, "/");
		if (_22) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
			_23 = ZEPHIR_IS_STRING_IDENTICAL(_1, "(");
			if (!(_23)) {
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_23 = ZEPHIR_IS_STRING_IDENTICAL(_5, ",");
			}
			_24 = _23;
			if (!(_24)) {
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_24 = ZEPHIR_IS_STRING_IDENTICAL(_6, "=");
			}
			_25 = _24;
			if (!(_25)) {
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_25 = ZEPHIR_IS_STRING_IDENTICAL(_7, ":");
			}
			_26 = _25;
			if (!(_26)) {
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_26 = ZEPHIR_IS_STRING_IDENTICAL(_10, "[");
			}
			_27 = _26;
			if (!(_27)) {
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_27 = ZEPHIR_IS_STRING_IDENTICAL(_11, "!");
			}
			_28 = _27;
			if (!(_28)) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_28 = ZEPHIR_IS_STRING_IDENTICAL(_12, "&");
			}
			_29 = _28;
			if (!(_29)) {
				_15 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_29 = ZEPHIR_IS_STRING_IDENTICAL(_15, "|");
			}
			_30 = _29;
			if (!(_30)) {
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_30 = ZEPHIR_IS_STRING_IDENTICAL(_16, "?");
			}
			_31 = _30;
			if (!(_31)) {
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_31 = ZEPHIR_IS_STRING_IDENTICAL(_17, "{");
			}
			_32 = _31;
			if (!(_32)) {
				_33 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_32 = ZEPHIR_IS_STRING_IDENTICAL(_33, "}");
			}
			_34 = _32;
			if (!(_34)) {
				_35 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_34 = ZEPHIR_IS_STRING_IDENTICAL(_35, ";");
			}
			_36 = _34;
			if (!(_36)) {
				_37 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_36 = ZEPHIR_IS_STRING_IDENTICAL(_37, "\n");
			}
			_22 = _36;
		}
		if (_22) {
			_38 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
			_39 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
			_40 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_VVV(_2, _38, _39, _40);
			zephir_update_property_this(this_ptr, SL("output"), _2 TSRMLS_CC);
			while (1) {
				if (!(1)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", &_9, 0);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("a"), _13 TSRMLS_CC);
				_41 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_42 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_43 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				_44 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_19, "ord", &_14, 68, _44);
				zephir_check_call_status();
				if (ZEPHIR_IS_STRING_IDENTICAL(_41, "[")) {
					while (1) {
						if (!(1)) {
							break;
						}
						_45 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
						_46 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
						ZEPHIR_INIT_LNVAR(_18);
						ZEPHIR_CONCAT_VV(_18, _45, _46);
						zephir_update_property_this(this_ptr, SL("output"), _18 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&_47, this_ptr, "get", &_9, 0);
						zephir_check_call_status();
						zephir_update_property_this(this_ptr, SL("a"), _47 TSRMLS_CC);
						_48 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
						_49 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
						_50 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
						ZEPHIR_CALL_FUNCTION(&_51, "ord", &_14, 68, _50);
						zephir_check_call_status();
						if (ZEPHIR_IS_STRING_IDENTICAL(_48, "]")) {
							break;
						} else if (ZEPHIR_IS_STRING_IDENTICAL(_49, "\\")) {
							_52 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
							_53 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
							ZEPHIR_INIT_LNVAR(_54);
							ZEPHIR_CONCAT_VV(_54, _52, _53);
							zephir_update_property_this(this_ptr, SL("output"), _54 TSRMLS_CC);
							ZEPHIR_CALL_METHOD(&_55, this_ptr, "get", &_9, 0);
							zephir_check_call_status();
							zephir_update_property_this(this_ptr, SL("a"), _55 TSRMLS_CC);
						} else if (ZEPHIR_LE_LONG(_51, 10)) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unterminated regular expression set in regex literal.", "ice/filter/js.zep", 129);
							return;
						}
					}
				} else if (ZEPHIR_IS_STRING_IDENTICAL(_42, "/")) {
					break;
				} else if (ZEPHIR_IS_STRING_IDENTICAL(_43, "\\")) {
					_16 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
					_17 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
					ZEPHIR_INIT_LNVAR(_18);
					ZEPHIR_CONCAT_VV(_18, _16, _17);
					zephir_update_property_this(this_ptr, SL("output"), _18 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_19, this_ptr, "get", &_9, 0);
					zephir_check_call_status();
					zephir_update_property_this(this_ptr, SL("a"), _19 TSRMLS_CC);
				} else if (ZEPHIR_LE_LONG(_19, 10)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unterminated regular expression literal.", "ice/filter/js.zep", 138);
					return;
				}
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("output"), PH_NOISY_CC);
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_18);
				ZEPHIR_CONCAT_VV(_18, _16, _17);
				zephir_update_property_this(this_ptr, SL("output"), _18 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "next", &_21, 0);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("b"), _8 TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _6, _7;
	zval *c = NULL, *i, *_0, *_1, *_2, *_3, _4, *_5, *_8 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(c);
	zephir_read_property_this(&c, this_ptr, SL("lookAhead"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("lookAhead"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	if (Z_TYPE_P(c) == IS_NULL) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("inputIndex"), PH_NOISY_CC);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("inputLength"), PH_NOISY_CC);
		if (ZEPHIR_LT(_0, _1)) {
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("input"), PH_NOISY_CC);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("inputIndex"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_4);
			ZVAL_LONG(&_4, 1);
			ZEPHIR_INIT_NVAR(c);
			zephir_substr(c, _2, zephir_get_intval(_3), 1 , 0);
			ZEPHIR_OBS_VAR(i);
			zephir_read_property_this(&i, this_ptr, SL("inputIndex"), PH_NOISY_CC);
			ZEPHIR_INIT_ZVAL_NREF(_5);
			ZVAL_LONG(_5, (zephir_get_numberval(i) + 1));
			zephir_update_property_this(this_ptr, SL("inputIndex"), _5 TSRMLS_CC);
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
		ZEPHIR_CALL_FUNCTION(&_8, "ord", NULL, 68, c);
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *c, *_0 = NULL, *_3, *_4, _5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &c);



	ZEPHIR_CALL_FUNCTION(&_0, "ord", NULL, 68, c);
	zephir_check_call_status();
	_1 = ZEPHIR_GT_LONG(_0, 126);
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING_IDENTICAL(c, "\\");
	}
	_2 = _1;
	if (!(_2)) {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "/^[\\w\\$]$/", 0);
		zephir_preg_match(_4, &_5, c, _3, 0, 0 , 0  TSRMLS_CC);
		_2 = ZEPHIR_IS_LONG_IDENTICAL(_4, 1);
	}
	RETURN_MM_BOOL(_2);

}

/**
 * Perform minification, return result
 *
 * @return string
 */
PHP_METHOD(Ice_Filter_Js, min) {

	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, _1, _2, *_3 = NULL, *_5, *_6 = NULL, *_8, *_9 = NULL, *_10, *_12, *_13 = NULL, *_14;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "peek", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\xef", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_FUNCTION(&_3, "strncmp", NULL, 106, _0, &_1, &_2);
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
	zephir_update_property_this(this_ptr, SL("a"), _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
	zephir_check_call_status();
	while (1) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
		if (!(Z_TYPE_P(_5) != IS_NULL)) {
			break;
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_STRING(_8, " ")) {
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_9, this_ptr, "isalphanum", &_11, 0, _10);
				zephir_check_call_status();
				if (zephir_is_true(_9)) {
					ZEPHIR_INIT_NVAR(_6);
					ZVAL_LONG(_6, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(_6);
					ZVAL_LONG(_6, 2);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
					zephir_check_call_status();
				}
				break;
			}
			if (ZEPHIR_IS_STRING(_8, "\n")) {
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
				do {
					if (ZEPHIR_IS_STRING(_10, "{") || ZEPHIR_IS_STRING(_10, "[") || ZEPHIR_IS_STRING(_10, "(") || ZEPHIR_IS_STRING(_10, "+") || ZEPHIR_IS_STRING(_10, "-") || ZEPHIR_IS_STRING(_10, "!") || ZEPHIR_IS_STRING(_10, "~")) {
						ZEPHIR_INIT_NVAR(_6);
						ZVAL_LONG(_6, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_STRING(_10, " ")) {
						ZEPHIR_INIT_NVAR(_6);
						ZVAL_LONG(_6, 3);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
						zephir_check_call_status();
						break;
					}
					_12 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(&_9, this_ptr, "isalphanum", &_11, 0, _12);
					zephir_check_call_status();
					if (zephir_is_true(_9)) {
						ZEPHIR_INIT_NVAR(_6);
						ZVAL_LONG(_6, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(_6);
						ZVAL_LONG(_6, 2);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
						zephir_check_call_status();
					}
				} while(0);

				break;
			}
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("b"), PH_NOISY_CC);
			do {
				if (ZEPHIR_IS_STRING(_10, " ")) {
					_12 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(&_9, this_ptr, "isalphanum", &_11, 0, _12);
					zephir_check_call_status();
					if (zephir_is_true(_9)) {
						ZEPHIR_INIT_NVAR(_6);
						ZVAL_LONG(_6, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
						zephir_check_call_status();
						break;
					}
					ZEPHIR_INIT_NVAR(_6);
					ZVAL_LONG(_6, 3);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_STRING(_10, "\n")) {
					_12 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
					do {
						if (ZEPHIR_IS_STRING(_12, "}") || ZEPHIR_IS_STRING(_12, "]") || ZEPHIR_IS_STRING(_12, ")") || ZEPHIR_IS_STRING(_12, "+") || ZEPHIR_IS_STRING(_12, "-") || ZEPHIR_IS_STRING(_12, "\"") || ZEPHIR_IS_STRING(_12, "'")) {
							ZEPHIR_INIT_NVAR(_6);
							ZVAL_LONG(_6, 1);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
							zephir_check_call_status();
							break;
						}
						_14 = zephir_fetch_nproperty_this(this_ptr, SL("a"), PH_NOISY_CC);
						ZEPHIR_CALL_METHOD(&_13, this_ptr, "isalphanum", &_11, 0, _14);
						zephir_check_call_status();
						if (zephir_is_true(_13)) {
							ZEPHIR_INIT_NVAR(_6);
							ZVAL_LONG(_6, 1);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(_6);
							ZVAL_LONG(_6, 3);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
							zephir_check_call_status();
						}
					} while(0);

					break;
				}
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, 1);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "action", &_7, 0, _6);
				zephir_check_call_status();
				break;
			} while(0);

		} while(0);

	}
	RETURN_MM_MEMBER(this_ptr, "output");

}

/**
 * Get the next character, skipping over comments. peek() is used to see
 *  if a "/" is followed by a "/" or "*".
 *
 * @throws Exception On unterminated comment.
 * @return string
 */
PHP_METHOD(Ice_Filter_Js, next) {

	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *c = NULL, *_1 = NULL, *_3 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&c, this_ptr, "get", &_0, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(c, "/")) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "peek", &_2, 0);
		zephir_check_call_status();
		do {
			if (ZEPHIR_IS_STRING(_1, "/")) {
				while (1) {
					if (!(1)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&c, this_ptr, "get", &_0, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_3, "ord", &_4, 68, c);
					zephir_check_call_status();
					if (ZEPHIR_LE_LONG(_3, 10)) {
						RETURN_CCTOR(c);
					}
				}
			}
			if (ZEPHIR_IS_STRING(_1, "*")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_0, 0);
				zephir_check_call_status();
				while (1) {
					if (!(1)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", &_0, 0);
					zephir_check_call_status();
					do {
						if (ZEPHIR_IS_STRING(_3, "*")) {
							ZEPHIR_CALL_METHOD(&_5, this_ptr, "peek", &_2, 0);
							zephir_check_call_status();
							if (ZEPHIR_IS_STRING_IDENTICAL(_5, "/")) {
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "get", &_0, 0);
								zephir_check_call_status();
								RETURN_MM_STRING(" ", 1);
							}
							break;
						}
						if (Z_TYPE_P(_3) == IS_NULL) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("lookAhead"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "lookAhead");

}

