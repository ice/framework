
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 * Sleet file parser.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_Sleet_Parser) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\View\\Engine\\Sleet, Parser, ice, mvc_view_engine_sleet_parser, ice_mvc_view_engine_sleet_parser_method_entry, 0);

	zend_declare_property_null(ice_mvc_view_engine_sleet_parser_ce, SL("functions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_engine_sleet_parser_ce, SL("filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_engine_sleet_parser_ce, SL("env"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_mvc_view_engine_sleet_parser_ce->create_object = zephir_init_properties_Ice_Mvc_View_Engine_Sleet_Parser;
	zend_declare_class_constant_long(ice_mvc_view_engine_sleet_parser_ce, SL("NORMAL"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_view_engine_sleet_parser_ce, SL("SHORTIF"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_view_engine_sleet_parser_ce, SL("INARRAY"), 2 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sleet parser constructor. Fetch Ice\Tag methods.
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, __construct) {

	HashTable *_2;
	HashPosition _1;
	zval *tag = NULL, *methods = NULL, *functions = NULL, *method = NULL, *_0 = NULL, **_3, *_12, *_13, *_4$$3 = NULL, *_5$$5 = NULL, *_6$$5 = NULL, *_7$$5 = NULL, *_8$$5 = NULL, *_9$$5 = NULL, *_10$$5 = NULL, *_11$$5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(tag);
	object_init_ex(tag, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Ice\\Tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, tag, "__construct", NULL, 108, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 256);
	ZEPHIR_CALL_METHOD(&methods, tag, "getmethods", NULL, 177, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(functions);
	array_init(functions);
	zephir_is_iterable(methods, &_2, &_1, 0, 0, "ice/mvc/view/engine/sleet/parser.zep", 57);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(method, _3);
		ZEPHIR_OBS_NVAR(_4$$3);
		zephir_read_property(&_4$$3, method, SL("name"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_STRING(_4$$3, "__construct")) {
				continue;
			}
			ZEPHIR_OBS_NVAR(_5$$5);
			zephir_read_property(&_5$$5, method, SL("name"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_6$$5);
			ZEPHIR_CONCAT_SV(_6$$5, "$this->tag->", _5$$5);
			ZEPHIR_OBS_NVAR(_7$$5);
			zephir_read_property(&_7$$5, method, SL("name"), PH_NOISY_CC);
			zephir_array_update_zval(&functions, _7$$5, &_6$$5, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_8$$5);
			zephir_read_property(&_8$$5, method, SL("name"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_9$$5);
			ZEPHIR_CONCAT_SV(_9$$5, "$this->tag->", _8$$5);
			ZEPHIR_INIT_NVAR(_10$$5);
			ZEPHIR_OBS_NVAR(_11$$5);
			zephir_read_property(&_11$$5, method, SL("name"), PH_NOISY_CC);
			zephir_uncamelize(_10$$5, _11$$5, NULL  );
			zephir_array_update_zval(&functions, _10$$5, &_9$$5, PH_COPY | PH_SEPARATE);
		} while(0);

	}
	ZEPHIR_INIT_NVAR(_0);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("functions"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_12), &(functions) TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("functions"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_13);
	ZVAL_LONG(_13, 0);
	zephir_update_property_array_append(this_ptr, SL("env"), _13 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Parse text.
 *
 * @param string text
 * @return string Parsed text
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, text) {

	unsigned char _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, _18$$4, _37$$6, _55$$8;
	zephir_fcall_cache_entry *_12 = NULL, *_16 = NULL, *_17 = NULL, *_23 = NULL;
	zval *text_param = NULL, *pos = NULL, *start = NULL, *parsedText = NULL, *end = NULL, *ch = NULL, _0, *_60, _59$$3 = zval_used_for_init, *_2$$4 = NULL, _3$$4 = zval_used_for_init, *_4$$4 = NULL, _5$$4 = zval_used_for_init, _6$$4 = zval_used_for_init, *_19$$4 = NULL, *_20$$4 = NULL, _21$$4 = zval_used_for_init, *_22$$4 = NULL, *_7$$5 = NULL, _8$$5 = zval_used_for_init, *_9$$5 = NULL, *_10$$5 = NULL, *_11$$5 = NULL, _13$$5 = zval_used_for_init, _14$$5 = zval_used_for_init, *_15$$5 = NULL, *_24$$6 = NULL, _25$$6 = zval_used_for_init, *_26$$6 = NULL, _27$$6 = zval_used_for_init, _28$$6 = zval_used_for_init, *_38$$6 = NULL, *_39$$6 = NULL, _40$$6 = zval_used_for_init, *_41$$6 = NULL, *_29$$7 = NULL, _30$$7 = zval_used_for_init, *_31$$7 = NULL, *_32$$7 = NULL, *_33$$7 = NULL, _34$$7 = zval_used_for_init, _35$$7 = zval_used_for_init, *_36$$7 = NULL, *_42$$8 = NULL, _43$$8 = zval_used_for_init, *_44$$8 = NULL, _45$$8 = zval_used_for_init, _46$$8 = zval_used_for_init, *_47$$9 = NULL, _48$$9 = zval_used_for_init, *_49$$9 = NULL, *_50$$9 = NULL, *_51$$9 = NULL, _52$$9 = zval_used_for_init, _53$$9 = zval_used_for_init, *_54$$9 = NULL, _56$$10 = zval_used_for_init, _57$$10 = zval_used_for_init, *_58$$10 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(text, text_param);


	ZEPHIR_INIT_VAR(pos);
	ZVAL_LONG(pos, 0);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "{", 0);
	ZEPHIR_INIT_VAR(start);
	zephir_fast_strpos(start, text, &_0, 0 );
	ZEPHIR_INIT_VAR(parsedText);
	ZVAL_STRING(parsedText, "", 1);
	while (1) {
		if (!(!ZEPHIR_IS_FALSE_IDENTICAL(start))) {
			break;
		}
		i = (zephir_get_numberval(start) + 1);
		_1$$3 = ZEPHIR_STRING_OFFSET(text, i);
		ZEPHIR_INIT_NVAR(ch);
		ZVAL_LONG(ch, _1$$3);
		do {
			if (ZEPHIR_IS_LONG(ch, '{')) {
				ZEPHIR_INIT_LNVAR(_2$$4);
				zephir_sub_function(_2$$4, start, pos);
				ZEPHIR_SINIT_NVAR(_3$$4);
				ZVAL_LONG(&_3$$4, zephir_get_intval(_2$$4));
				ZEPHIR_INIT_NVAR(_4$$4);
				zephir_substr(_4$$4, text, zephir_get_intval(pos), zephir_get_intval(&_3$$4), 0);
				zephir_concat_self(&parsedText, _4$$4 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_5$$4);
				ZVAL_STRING(&_5$$4, "}}", 0);
				ZEPHIR_SINIT_NVAR(_6$$4);
				ZVAL_LONG(&_6$$4, (zephir_get_numberval(start) + 2));
				ZEPHIR_INIT_NVAR(end);
				zephir_fast_strpos(end, text, &_5$$4, zephir_get_intval(&_6$$4) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(end)) {
					ZEPHIR_INIT_NVAR(_7$$5);
					object_init_ex(_7$$5, ice_exception_ce);
					ZEPHIR_SINIT_NVAR(_8$$5);
					ZVAL_LONG(&_8$$5, 0);
					ZEPHIR_INIT_NVAR(_9$$5);
					zephir_substr(_9$$5, text, 0 , zephir_get_intval(start), 0);
					ZEPHIR_INIT_NVAR(_10$$5);
					ZEPHIR_GET_CONSTANT(_10$$5, "PHP_EOL");
					ZEPHIR_CALL_FUNCTION(&_11$$5, "substr_count", &_12, 178, _9$$5, _10$$5);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_13$$5);
					ZVAL_STRING(&_13$$5, "Unclosed echo on the line %d", 0);
					ZEPHIR_SINIT_NVAR(_14$$5);
					ZVAL_LONG(&_14$$5, (zephir_get_numberval(_11$$5) + 1));
					ZEPHIR_CALL_FUNCTION(&_15$$5, "sprintf", &_16, 12, &_13$$5, &_14$$5);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", &_17, 13, _15$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(_7$$5, "ice/mvc/view/engine/sleet/parser.zep", 88 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_18$$4 = (zephir_get_numberval(end) + 2);
				ZEPHIR_INIT_NVAR(end);
				ZVAL_LONG(end, _18$$4);
				ZEPHIR_INIT_LNVAR(_20$$4);
				zephir_sub_function(_20$$4, end, start);
				ZEPHIR_SINIT_NVAR(_21$$4);
				ZVAL_LONG(&_21$$4, zephir_get_intval(_20$$4));
				ZEPHIR_INIT_NVAR(_22$$4);
				zephir_substr(_22$$4, text, zephir_get_intval(start), zephir_get_intval(&_21$$4), 0);
				ZEPHIR_CALL_METHOD(&_19$$4, this_ptr, "parse", &_23, 0, _22$$4);
				zephir_check_call_status();
				zephir_concat_self(&parsedText, _19$$4 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(ch, '%')) {
				ZEPHIR_INIT_LNVAR(_24$$6);
				zephir_sub_function(_24$$6, start, pos);
				ZEPHIR_SINIT_NVAR(_25$$6);
				ZVAL_LONG(&_25$$6, zephir_get_intval(_24$$6));
				ZEPHIR_INIT_NVAR(_26$$6);
				zephir_substr(_26$$6, text, zephir_get_intval(pos), zephir_get_intval(&_25$$6), 0);
				zephir_concat_self(&parsedText, _26$$6 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_27$$6);
				ZVAL_STRING(&_27$$6, "%}", 0);
				ZEPHIR_SINIT_NVAR(_28$$6);
				ZVAL_LONG(&_28$$6, (zephir_get_numberval(start) + 2));
				ZEPHIR_INIT_NVAR(end);
				zephir_fast_strpos(end, text, &_27$$6, zephir_get_intval(&_28$$6) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(end)) {
					ZEPHIR_INIT_NVAR(_29$$7);
					object_init_ex(_29$$7, ice_exception_ce);
					ZEPHIR_SINIT_NVAR(_30$$7);
					ZVAL_LONG(&_30$$7, 0);
					ZEPHIR_INIT_NVAR(_31$$7);
					zephir_substr(_31$$7, text, 0 , zephir_get_intval(start), 0);
					ZEPHIR_INIT_NVAR(_32$$7);
					ZEPHIR_GET_CONSTANT(_32$$7, "PHP_EOL");
					ZEPHIR_CALL_FUNCTION(&_33$$7, "substr_count", &_12, 178, _31$$7, _32$$7);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_34$$7);
					ZVAL_STRING(&_34$$7, "Unclosed tag on the line %d", 0);
					ZEPHIR_SINIT_NVAR(_35$$7);
					ZVAL_LONG(&_35$$7, (zephir_get_numberval(_33$$7) + 1));
					ZEPHIR_CALL_FUNCTION(&_36$$7, "sprintf", &_16, 12, &_34$$7, &_35$$7);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, _29$$7, "__construct", &_17, 13, _36$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(_29$$7, "ice/mvc/view/engine/sleet/parser.zep", 101 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_37$$6 = (zephir_get_numberval(end) + 2);
				ZEPHIR_INIT_NVAR(end);
				ZVAL_LONG(end, _37$$6);
				ZEPHIR_INIT_LNVAR(_39$$6);
				zephir_sub_function(_39$$6, end, start);
				ZEPHIR_SINIT_NVAR(_40$$6);
				ZVAL_LONG(&_40$$6, zephir_get_intval(_39$$6));
				ZEPHIR_INIT_NVAR(_41$$6);
				zephir_substr(_41$$6, text, zephir_get_intval(start), zephir_get_intval(&_40$$6), 0);
				ZEPHIR_CALL_METHOD(&_38$$6, this_ptr, "parse", &_23, 0, _41$$6);
				zephir_check_call_status();
				zephir_concat_self(&parsedText, _38$$6 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(ch, '#')) {
				ZEPHIR_INIT_LNVAR(_42$$8);
				zephir_sub_function(_42$$8, start, pos);
				ZEPHIR_SINIT_NVAR(_43$$8);
				ZVAL_LONG(&_43$$8, zephir_get_intval(_42$$8));
				ZEPHIR_INIT_NVAR(_44$$8);
				zephir_substr(_44$$8, text, zephir_get_intval(pos), zephir_get_intval(&_43$$8), 0);
				zephir_concat_self(&parsedText, _44$$8 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_45$$8);
				ZVAL_STRING(&_45$$8, "#}", 0);
				ZEPHIR_SINIT_NVAR(_46$$8);
				ZVAL_LONG(&_46$$8, (zephir_get_numberval(start) + 2));
				ZEPHIR_INIT_NVAR(end);
				zephir_fast_strpos(end, text, &_45$$8, zephir_get_intval(&_46$$8) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(end)) {
					ZEPHIR_INIT_NVAR(_47$$9);
					object_init_ex(_47$$9, ice_exception_ce);
					ZEPHIR_SINIT_NVAR(_48$$9);
					ZVAL_LONG(&_48$$9, 0);
					ZEPHIR_INIT_NVAR(_49$$9);
					zephir_substr(_49$$9, text, 0 , zephir_get_intval(start), 0);
					ZEPHIR_INIT_NVAR(_50$$9);
					ZEPHIR_GET_CONSTANT(_50$$9, "PHP_EOL");
					ZEPHIR_CALL_FUNCTION(&_51$$9, "substr_count", &_12, 178, _49$$9, _50$$9);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_52$$9);
					ZVAL_STRING(&_52$$9, "Unclosed comment block on the line %d", 0);
					ZEPHIR_SINIT_NVAR(_53$$9);
					ZVAL_LONG(&_53$$9, (zephir_get_numberval(_51$$9) + 1));
					ZEPHIR_CALL_FUNCTION(&_54$$9, "sprintf", &_16, 12, &_52$$9, &_53$$9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, _47$$9, "__construct", &_17, 13, _54$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(_47$$9, "ice/mvc/view/engine/sleet/parser.zep", 114 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_55$$8 = (zephir_get_numberval(end) + 2);
				ZEPHIR_INIT_NVAR(end);
				ZVAL_LONG(end, _55$$8);
				break;
			}
			ZEPHIR_SINIT_NVAR(_56$$10);
			zephir_sub_function(&_56$$10, start, pos);
			ZEPHIR_SINIT_NVAR(_57$$10);
			ZVAL_LONG(&_57$$10, (zephir_get_numberval(&_56$$10) + 1));
			ZEPHIR_INIT_NVAR(_58$$10);
			zephir_substr(_58$$10, text, zephir_get_intval(pos), zephir_get_intval(&_57$$10), 0);
			zephir_concat_self(&parsedText, _58$$10 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(end);
			ZVAL_LONG(end, (zephir_get_numberval(start) + 1));
			break;
		} while(0);

		ZEPHIR_CPY_WRT(pos, end);
		ZEPHIR_SINIT_NVAR(_59$$3);
		ZVAL_STRING(&_59$$3, "{", 0);
		ZEPHIR_INIT_NVAR(start);
		zephir_fast_strpos(start, text, &_59$$3, zephir_get_intval(pos) );
	}
	ZEPHIR_INIT_VAR(_60);
	zephir_substr(_60, text, zephir_get_intval(pos), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_concat_self(&parsedText, _60 TSRMLS_CC);
	RETURN_CCTOR(parsedText);

}

/**
 * Parse one sleet expression.
 *
 * @param string expression
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parse) {

	zend_bool _10$$5;
	HashTable *_8;
	HashPosition _7;
	zephir_fcall_cache_entry *_6 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expression_param = NULL, *php = NULL, *tokenized = NULL, *tokens = NULL, *token = NULL, *first = NULL, **_9, *_12, _0$$3, _1$$3, *_2$$3, _3$$4, _4$$4, *_5$$4, *_11$$5, *_13$$9, *_14$$10, *_15$$11, *_16$$12, *_18$$15;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression_param);

	zephir_get_strval(expression, expression_param);


	ZEPHIR_INIT_VAR(php);
	if (zephir_start_with_str(expression, SL("{{"))) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_LONG(&_0$$3, 2);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, -2);
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_substr(_2$$3, expression, 2 , -2 , 0);
		ZEPHIR_CONCAT_SV(php, "<?php echo ", _2$$3);
	} else {
		ZEPHIR_SINIT_VAR(_3$$4);
		ZVAL_LONG(&_3$$4, 2);
		ZEPHIR_SINIT_VAR(_4$$4);
		ZVAL_LONG(&_4$$4, -2);
		ZEPHIR_INIT_VAR(_5$$4);
		zephir_substr(_5$$4, expression, 2 , -2 , 0);
		ZEPHIR_CONCAT_SV(php, "<?php ", _5$$4);
	}
	ZEPHIR_CALL_FUNCTION(&tokenized, "token_get_all", NULL, 179, php);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(tokens);
	array_init(tokens);
	ZEPHIR_MAKE_REF(tokenized);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_6, 3, tokenized);
	ZEPHIR_UNREF(tokenized);
	zephir_check_call_status();
	zephir_is_iterable(tokenized, &_8, &_7, 0, 0, "ice/mvc/view/engine/sleet/parser.zep", 163);
	for (
	  ; zend_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zend_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HVALUE(token, _9);
		_10$$5 = Z_TYPE_P(token) == IS_ARRAY;
		if (_10$$5) {
			zephir_array_fetch_long(&_11$$5, token, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 157 TSRMLS_CC);
			_10$$5 = ZEPHIR_IS_LONG(_11$$5, 379);
		}
		if (_10$$5) {
			continue;
		}
		zephir_array_append(&tokens, token, PH_SEPARATE, "ice/mvc/view/engine/sleet/parser.zep", 160);
	}
	ZEPHIR_MAKE_REF(tokens);
	ZEPHIR_CALL_FUNCTION(&first, "array_shift", &_6, 3, tokens);
	ZEPHIR_UNREF(tokens);
	zephir_check_call_status();
	if (Z_TYPE_P(first) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unexpected first tag", "ice/mvc/view/engine/sleet/parser.zep", 166);
		return;
	}
	if (Z_TYPE_P(tokens) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unexpected expression", "ice/mvc/view/engine/sleet/parser.zep", 170);
		return;
	}
	zephir_array_fetch_long(&_12, first, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 173 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_12, 307) || ZEPHIR_IS_LONG(_12, 324) || ZEPHIR_IS_LONG(_12, 322) || ZEPHIR_IS_LONG(_12, 331) || ZEPHIR_IS_LONG(_12, 326)) {
			zephir_array_fetch_long(&_13$$9, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 179 TSRMLS_CC);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", _13$$9, " ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 334)) {
			zephir_array_fetch_long(&_14$$10, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 181 TSRMLS_CC);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", _14$$10, "; ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 306) || ZEPHIR_IS_LONG(_12, 333)) {
			zephir_array_fetch_long(&_15$$11, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 184 TSRMLS_CC);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", _15$$11, ": ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 330) || ZEPHIR_IS_LONG(_12, 332) || ZEPHIR_IS_LONG(_12, 304) || ZEPHIR_IS_LONG(_12, 305) || ZEPHIR_IS_LONG(_12, 320) || ZEPHIR_IS_LONG(_12, 323) || ZEPHIR_IS_LONG(_12, 321) || ZEPHIR_IS_LONG(_12, 325)) {
			zephir_array_fetch_long(&_16$$12, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 193 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parsecontrol", NULL, 180, _16$$12, tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 319)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseecho", NULL, 181, tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 353)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseset", &_17, 182, tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 310)) {
			zephir_array_fetch_long(&_18$$15, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 199 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(_18$$15, "set")) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseset", &_17, 182, tokens);
				zephir_check_call_status();
				RETURN_MM();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(_12, 344)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseuse", NULL, 183, tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

	RETURN_MM_STRING("", 1);

}

/**
 * Parse control expression.
 *
 * @param string control Control structure
 * @param array expression Tokens
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseControl) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *control, *expression, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &control, &expression);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 184, expression);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<?php ", control, "(", _0, "): ?>");
	RETURN_MM();

}

/**
 * Parse echo expression.
 *
 * @param array expression Tokens
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseEcho) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expression, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 184, expression);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php echo ", _0, " ?>");
	RETURN_MM();

}

/**
 * Parse set expression.
 *
 * @param array expression Tokens
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expression, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 184, expression);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php ", _0, "; ?>");
	RETURN_MM();

}

/**
 * Parse use expression.
 *
 * @param array expression Tokens
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseUse) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expression, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 184, expression);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php use ", _0, "; ?>");
	RETURN_MM();

}

/**
 * Internal tokens parse.
 *
 * @param array tokens
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, doParse) {

	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_18 = NULL, *_23 = NULL, *_24 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tokens, *i = NULL, *parsed = NULL, *prev = NULL, *next = NULL, *token = NULL, *filter = NULL, *seek = NULL, *filters = NULL, *_0 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, *_6$$3 = NULL, *_8$$3 = NULL, *_25$$3 = NULL, *_10$$4 = NULL, *_11$$4 = NULL, *_12$$4, *_13$$4, *_14$$4, *_15$$4 = NULL, *_16$$4 = NULL, *_22$$4 = NULL, *_17$$5 = NULL, *_19$$5 = NULL, *_20$$6 = NULL, *_21$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tokens);



	ZEPHIR_INIT_VAR(i);
	object_init_ex(i, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, i, "__construct", NULL, 2, tokens);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(parsed);
	ZVAL_STRING(parsed, "", 1);
	ZEPHIR_INIT_VAR(prev);
	ZVAL_STRING(prev, "", 1);
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, i, "valid", &_1, 185);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&token, i, "current", &_2, 186);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, i, "key", &_5, 187);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_LONG(_6$$3, (zephir_get_numberval(_4$$3) + 1));
		ZEPHIR_CALL_METHOD(&_3$$3, i, "offsetexists", &_7, 188, _6$$3);
		zephir_check_call_status();
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_CALL_METHOD(&_8$$3, i, "key", &_5, 187);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_6$$3);
			ZVAL_LONG(_6$$3, (zephir_get_numberval(_8$$3) + 1));
			ZEPHIR_CALL_METHOD(&next, i, "offsetget", &_9, 189, _6$$3);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(next);
			ZVAL_NULL(next);
		}
		if (ZEPHIR_IS_STRING(next, "|")) {
			ZEPHIR_CALL_METHOD(&_10$$4, i, "key", &_5, 187);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(seek);
			ZVAL_LONG(seek, (zephir_get_numberval(_10$$4) + 2));
			ZEPHIR_CALL_METHOD(&filter, i, "offsetget", &_9, 189, seek);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_11$$4);
			_12$$4 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
			zephir_array_fetch_long(&_13$$4, filter, 1, PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 275 TSRMLS_CC);
			if (zephir_array_isset(_12$$4, _13$$4)) {
				_14$$4 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
				ZEPHIR_OBS_NVAR(_11$$4);
				ZEPHIR_OBS_NVAR(_15$$4);
				zephir_array_fetch_long(&_15$$4, filter, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 275 TSRMLS_CC);
				zephir_array_fetch(&_11$$4, _14$$4, _15$$4, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 275 TSRMLS_CC);
			} else {
				ZEPHIR_OBS_NVAR(_11$$4);
				zephir_array_fetch_long(&_11$$4, filter, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 275 TSRMLS_CC);
			}
			ZEPHIR_CPY_WRT(filter, _11$$4);
			ZEPHIR_INIT_NVAR(filters);
			zephir_create_array(filters, 17, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "camelize", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "uncamelize", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "human", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "lower", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "upper", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "alnum", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "alpha", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "email", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "float", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "int", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "string", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "strip_repeats", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "e", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "escape", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "strip_special", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "unescape", 1);
			zephir_array_fast_append(filters, _16$$4);
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_STRING(_16$$4, "unstrip_special", 1);
			zephir_array_fast_append(filters, _16$$4);
			if (zephir_fast_in_array(filter, filters TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&_17$$5, this_ptr, "token", &_18, 190, token, prev, next);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_19$$5);
				ZEPHIR_CONCAT_SVSVS(_19$$5, "$this->filter->sanitize(", _17$$5, ", '", filter, "'");
				zephir_concat_self(&parsed, _19$$5 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_METHOD(&_20$$6, this_ptr, "token", &_18, 190, token, prev, next);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_21$$6);
				ZEPHIR_CONCAT_VSV(_21$$6, filter, "(", _20$$6);
				zephir_concat_self(&parsed, _21$$6 TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_LONG(_16$$4, (zephir_get_numberval(seek) + 1));
			ZEPHIR_CALL_METHOD(&_22$$4, i, "offsetexists", &_7, 188, _16$$4);
			zephir_check_call_status();
			if (zephir_is_true(_22$$4)) {
				ZEPHIR_INIT_NVAR(_16$$4);
				ZVAL_LONG(_16$$4, (zephir_get_numberval(seek) + 1));
				ZEPHIR_CALL_METHOD(&next, i, "offsetget", &_9, 189, _16$$4);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(next);
				ZVAL_NULL(next);
			}
			if (ZEPHIR_IS_STRING(next, "(")) {
				zephir_concat_self_str(&parsed, SL(", ") TSRMLS_CC);
				ZEPHIR_SEPARATE(seek);
				zephir_increment(seek);
			} else {
				zephir_concat_self_str(&parsed, SL(")") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(NULL, i, "seek", &_23, 191, seek);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, i, "next", &_24, 192);
			zephir_check_call_status();
			continue;
		}
		ZEPHIR_CALL_METHOD(&_25$$3, this_ptr, "token", &_18, 190, token, prev, next);
		zephir_check_call_status();
		zephir_concat_self(&parsed, _25$$3 TSRMLS_CC);
		ZEPHIR_CPY_WRT(prev, token);
		ZEPHIR_CALL_METHOD(NULL, i, "next", &_24, 192);
		zephir_check_call_status();
	}
	RETURN_CCTOR(parsed);

}

/**
 * Internal token parse.
 *
 * @param mixed token
 * @param mixed prev
 * @param mixed next
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, token) {

	unsigned char _14$$15;
	zend_bool _4$$7, _5$$7, _6$$7, _12$$15, _13$$15, _17$$15;
	zval *str = NULL, *_3$$7 = NULL;
	zephir_fcall_cache_entry *_21 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *token, *prev = NULL, *next = NULL, *_0$$3, *_1$$4, *_2$$7, *_7$$7, *_8$$8 = NULL, *_9$$8, *_10$$8, *_11$$10, _15$$15, *_16$$15 = NULL, *_18$$17, *_19$$23, *_20$$23 = NULL, *_22$$24, *_24$$26, *_25$$27, *_26$$28, *_27$$28 = NULL, *_28$$29;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &token, &prev, &next);

	if (!prev) {
		prev = ZEPHIR_GLOBAL(global_null);
	}
	if (!next) {
		next = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(token) == IS_ARRAY) {
		zephir_array_fetch_long(&_0$$3, token, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 319 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_0$$3, 329) || ZEPHIR_IS_LONG(_0$$3, 302) || ZEPHIR_IS_LONG(_0$$3, 290) || ZEPHIR_IS_LONG(_0$$3, 285) || ZEPHIR_IS_LONG(_0$$3, 284) || ZEPHIR_IS_LONG(_0$$3, 283) || ZEPHIR_IS_LONG(_0$$3, 282) || ZEPHIR_IS_LONG(_0$$3, 287) || ZEPHIR_IS_LONG(_0$$3, 286)) {
				zephir_array_fetch_long(&_1$$4, token, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 329 TSRMLS_CC);
				ZEPHIR_CONCAT_SVS(return_value, " ", _1$$4, " ");
				RETURN_MM();
			}
			if (ZEPHIR_IS_LONG(_0$$3, 263)) {
				RETURN_MM_STRING(" || ", 1);
			}
			if (ZEPHIR_IS_LONG(_0$$3, 265)) {
				RETURN_MM_STRING(" && ", 1);
			}
			if (ZEPHIR_IS_LONG(_0$$3, 310)) {
				ZEPHIR_OBS_VAR(_2$$7);
				zephir_array_fetch_long(&_2$$7, token, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 335 TSRMLS_CC);
				zephir_get_strval(_3$$7, _2$$7);
				ZEPHIR_CPY_WRT(str, _3$$7);
				_4$$7 = ZEPHIR_IS_STRING(next, "(");
				if (_4$$7) {
					_5$$7 = !ZEPHIR_IS_STRING(prev, ".");
					if (!(_5$$7)) {
						_6$$7 = Z_TYPE_P(prev) == IS_ARRAY;
						if (_6$$7) {
							zephir_array_fetch_long(&_7$$7, prev, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 337 TSRMLS_CC);
							_6$$7 = !ZEPHIR_IS_LONG(_7$$7, 384);
						}
						_5$$7 = _6$$7;
					}
					_4$$7 = _5$$7;
				}
				if (_4$$7) {
					ZEPHIR_INIT_VAR(_8$$8);
					_9$$8 = zephir_fetch_nproperty_this(this_ptr, SL("functions"), PH_NOISY_CC);
					if (zephir_array_isset(_9$$8, str)) {
						_10$$8 = zephir_fetch_nproperty_this(this_ptr, SL("functions"), PH_NOISY_CC);
						zephir_array_fetch(&_8$$8, _10$$8, str, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 338 TSRMLS_CC);
					} else {
						ZEPHIR_CPY_WRT(_8$$8, str);
					}
					RETURN_CCTOR(_8$$8);
				}
				do {
					if (ZEPHIR_IS_STRING(str, "in")) {
						RETURN_MM_STRING(" as ", 1);
					}
					if (ZEPHIR_IS_STRING(str, "is")) {
						ZEPHIR_INIT_VAR(_11$$10);
						if (ZEPHIR_IS_STRING(next, "!")) {
							ZVAL_STRING(_11$$10, " != ", 1);
						} else {
							ZVAL_STRING(_11$$10, " == ", 1);
						}
						RETURN_CCTOR(_11$$10);
					}
					if (ZEPHIR_IS_STRING(str, "and")) {
						RETURN_MM_STRING(" && ", 1);
					}
					if (ZEPHIR_IS_STRING(str, "or")) {
						RETURN_MM_STRING(" || ", 1);
					}
					if (ZEPHIR_IS_STRING(str, "not")) {
						RETURN_MM_STRING("!", 1);
					}
					if (ZEPHIR_IS_STRING(str, "false") || ZEPHIR_IS_STRING(str, "true") || ZEPHIR_IS_STRING(str, "null")) {
						RETURN_CTOR(str);
					}
					_12$$15 = ZEPHIR_IS_STRING(prev, ".");
					if (!(_12$$15)) {
						_12$$15 = ZEPHIR_IS_STRING(next, "(");
					}
					_13$$15 = _12$$15;
					if (!(_13$$15)) {
						_14$$15 = ZEPHIR_STRING_OFFSET(str, 0);
						ZEPHIR_SINIT_VAR(_15$$15);
						ZVAL_STRINGL(&_15$$15, &_14$$15, 1, 1);
						ZEPHIR_CALL_FUNCTION(&_16$$15, "ctype_upper", NULL, 193, &_15$$15);
						zephir_check_call_status();
						_17$$15 = zephir_is_true(_16$$15);
						if (_17$$15) {
							_17$$15 = !ZEPHIR_IS_STRING(next, "|");
						}
						_13$$15 = _17$$15;
					}
					if (_13$$15) {
						RETURN_CTOR(str);
					}
					ZEPHIR_CONCAT_SV(return_value, "$", str);
					RETURN_MM();
				} while(0);

			}
			zephir_array_fetch_long(&_18$$17, token, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 362 TSRMLS_CC);
			RETURN_CTOR(_18$$17);
		} while(0);

	} else {
		do {
			if (ZEPHIR_IS_STRING(token, "-") || ZEPHIR_IS_STRING(token, "+") || ZEPHIR_IS_STRING(token, "*") || ZEPHIR_IS_STRING(token, "/") || ZEPHIR_IS_STRING(token, "%") || ZEPHIR_IS_STRING(token, "=") || ZEPHIR_IS_STRING(token, ">") || ZEPHIR_IS_STRING(token, "<")) {
				ZEPHIR_CONCAT_SVS(return_value, " ", token, " ");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(token, "~")) {
				RETURN_MM_STRING(" . ", 1);
			}
			if (ZEPHIR_IS_STRING(token, ",")) {
				RETURN_MM_STRING(", ", 1);
			}
			if (ZEPHIR_IS_STRING(token, ".")) {
				RETURN_MM_STRING("->", 1);
			}
			if (ZEPHIR_IS_STRING(token, ":")) {
				_19$$23 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
				ZEPHIR_MAKE_REF(_19$$23);
				ZEPHIR_CALL_FUNCTION(&_20$$23, "end", &_21, 194, _19$$23);
				ZEPHIR_UNREF(_19$$23);
				zephir_check_call_status();
				do {
					if (ZEPHIR_IS_LONG(_20$$23, 1)) {
						_22$$24 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
						ZEPHIR_MAKE_REF(_22$$24);
						ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_23, 195, _22$$24);
						ZEPHIR_UNREF(_22$$24);
						zephir_check_call_status();
						RETURN_MM_STRING(" : ", 1);
					}
					RETURN_MM_STRING(" => ", 1);
				} while(0);

			}
			if (ZEPHIR_IS_STRING(token, "?")) {
				ZEPHIR_INIT_ZVAL_NREF(_24$$26);
				ZVAL_LONG(_24$$26, 1);
				zephir_update_property_array_append(this_ptr, SL("env"), _24$$26 TSRMLS_CC);
				RETURN_MM_STRING(" ? ", 1);
			}
			if (ZEPHIR_IS_STRING(token, "[")) {
				ZEPHIR_INIT_ZVAL_NREF(_25$$27);
				ZVAL_LONG(_25$$27, 2);
				zephir_update_property_array_append(this_ptr, SL("env"), _25$$27 TSRMLS_CC);
				RETVAL_ZVAL(token, 1, 0);
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(token, "]")) {
				_26$$28 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
				ZEPHIR_MAKE_REF(_26$$28);
				ZEPHIR_CALL_FUNCTION(&_27$$28, "end", &_21, 194, _26$$28);
				ZEPHIR_UNREF(_26$$28);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(_27$$28, 2)) {
					_28$$29 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
					ZEPHIR_MAKE_REF(_28$$29);
					ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_23, 195, _28$$29);
					ZEPHIR_UNREF(_28$$29);
					zephir_check_call_status();
				}
				RETVAL_ZVAL(token, 1, 0);
				RETURN_MM();
			}
			RETVAL_ZVAL(token, 1, 0);
			RETURN_MM();
		} while(0);

	}
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Ice_Mvc_View_Engine_Sleet_Parser(zend_class_entry *class_type TSRMLS_DC) {

		zval *_3$$4, *_5$$5;
	zval *_0, *_2, *_4, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("env"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			zephir_create_array(_3$$4, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_3$$4, SS("capitalize"), SL("ucfirst"), 1);
			zephir_update_property_this(getThis(), SL("filters"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("functions"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			zephir_create_array(_5$$5, 5, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_5$$5, SS("content"), SL("$this->getContent"), 1);
			add_assoc_stringl_ex(_5$$5, SS("partial"), SL("$this->partial"), 1);
			add_assoc_stringl_ex(_5$$5, SS("load"), SL("$this->load"), 1);
			add_assoc_stringl_ex(_5$$5, SS("dump"), SL("$this->dump->vars"), 1);
			add_assoc_stringl_ex(_5$$5, SS("version"), SL("Ice\\Version::get"), 1);
			zephir_update_property_this(getThis(), SL("functions"), _5$$5 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

