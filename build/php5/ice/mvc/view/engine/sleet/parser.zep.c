
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
#include "kernel/hash.h"
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
 * @copyright   (c) 2014-2015 Ice Team
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
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(tag);
	object_init_ex(tag, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Ice\\Tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, tag, "__construct", NULL, 77, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 256);
	ZEPHIR_CALL_METHOD(&methods, tag, "getmethods", NULL, 135, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(functions);
	array_init(functions);
	zephir_is_iterable(methods, &_2, &_1, 0, 0, "ice/mvc/view/engine/sleet/parser.zep", 57);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
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
	zephir_update_property_this(this_ptr, SL("functions"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_13);
	ZVAL_LONG(_13, 0);
	zephir_update_property_array_append(this_ptr, SL("env"), _13 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Parse text, line by line.
 *
 * @param string text
 * @return string Parsed text
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, text) {

	HashTable *_3;
	HashPosition _2;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *parsed = NULL, *key = NULL, *line = NULL, *_0, *_1, **_4, *_5$$3 = NULL, *_6$$3 = NULL, *_7$$3 = NULL, *_9$$3 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(text, text_param);


	ZEPHIR_INIT_VAR(parsed);
	ZVAL_STRING(parsed, "", 1);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
	zephir_fast_explode(_0, _1, text, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "ice/mvc/view/engine/sleet/parser.zep", 76);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(line, _4);
		ZEPHIR_INIT_LNVAR(_5$$3);
		if (zephir_is_true(key)) {
			ZEPHIR_INIT_NVAR(_5$$3);
			ZEPHIR_GET_CONSTANT(_5$$3, "PHP_EOL");
		} else {
			ZEPHIR_INIT_NVAR(_5$$3);
			ZVAL_STRING(_5$$3, "", 1);
		}
		ZEPHIR_INIT_NVAR(_7$$3);
		ZVAL_LONG(_7$$3, (zephir_get_numberval(key) + 1));
		ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "line", &_8, 0, line, _7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_9$$3);
		ZEPHIR_CONCAT_VV(_9$$3, _5$$3, _6$$3);
		zephir_concat_self(&parsed, _9$$3 TSRMLS_CC);
	}
	RETURN_CCTOR(parsed);

}

/**
 * Parse one line - detect the expressions.
 *
 * @param string line
 * @param int no Line number
 * @return string Parsed line
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, line) {

	unsigned char _1$$3;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_18 = NULL;
	int no, ZEPHIR_LAST_CALL_STATUS, i = 0, _13$$4, _28$$6, _42$$8;
	zval *line_param = NULL, *no_param = NULL, *pos = NULL, *start = NULL, *parsedLine = NULL, *end = NULL, *ch = NULL, _0, *_47, _46$$3 = zval_used_for_init, *_2$$4 = NULL, _3$$4 = zval_used_for_init, *_4$$4 = NULL, _5$$4 = zval_used_for_init, _6$$4 = zval_used_for_init, *_14$$4 = NULL, *_15$$4 = NULL, _16$$4 = zval_used_for_init, *_17$$4 = NULL, *_7$$5 = NULL, _8$$5 = zval_used_for_init, _9$$5 = zval_used_for_init, *_10$$5 = NULL, *_19$$6 = NULL, _20$$6 = zval_used_for_init, *_21$$6 = NULL, _22$$6 = zval_used_for_init, _23$$6 = zval_used_for_init, *_29$$6 = NULL, *_30$$6 = NULL, _31$$6 = zval_used_for_init, *_32$$6 = NULL, *_24$$7 = NULL, _25$$7 = zval_used_for_init, _26$$7 = zval_used_for_init, *_27$$7 = NULL, *_33$$8 = NULL, _34$$8 = zval_used_for_init, *_35$$8 = NULL, _36$$8 = zval_used_for_init, _37$$8 = zval_used_for_init, *_38$$9 = NULL, _39$$9 = zval_used_for_init, _40$$9 = zval_used_for_init, *_41$$9 = NULL, _43$$10 = zval_used_for_init, _44$$10 = zval_used_for_init, *_45$$10 = NULL;
	zval *line = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &line_param, &no_param);

	zephir_get_strval(line, line_param);
	if (!no_param) {
		no = 1;
	} else {
		no = zephir_get_intval(no_param);
	}


	ZEPHIR_INIT_VAR(pos);
	ZVAL_LONG(pos, 0);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "{", 0);
	ZEPHIR_INIT_VAR(start);
	zephir_fast_strpos(start, line, &_0, 0 );
	ZEPHIR_INIT_VAR(parsedLine);
	ZVAL_STRING(parsedLine, "", 1);
	while (1) {
		if (!(!ZEPHIR_IS_FALSE_IDENTICAL(start))) {
			break;
		}
		i = (zephir_get_numberval(start) + 1);
		_1$$3 = ZEPHIR_STRING_OFFSET(line, i);
		ZEPHIR_INIT_NVAR(ch);
		ZVAL_LONG(ch, _1$$3);
		do {
			if (ZEPHIR_IS_LONG(ch, '{')) {
				ZEPHIR_INIT_LNVAR(_2$$4);
				zephir_sub_function(_2$$4, start, pos);
				ZEPHIR_SINIT_NVAR(_3$$4);
				ZVAL_LONG(&_3$$4, zephir_get_intval(_2$$4));
				ZEPHIR_INIT_NVAR(_4$$4);
				zephir_substr(_4$$4, line, zephir_get_intval(pos), zephir_get_intval(&_3$$4), 0);
				zephir_concat_self(&parsedLine, _4$$4 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_5$$4);
				ZVAL_STRING(&_5$$4, "}}", 0);
				ZEPHIR_SINIT_NVAR(_6$$4);
				ZVAL_LONG(&_6$$4, (zephir_get_numberval(start) + 2));
				ZEPHIR_INIT_NVAR(end);
				zephir_fast_strpos(end, line, &_5$$4, zephir_get_intval(&_6$$4) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(end)) {
					ZEPHIR_INIT_NVAR(_7$$5);
					object_init_ex(_7$$5, ice_exception_ce);
					ZEPHIR_SINIT_NVAR(_8$$5);
					ZVAL_STRING(&_8$$5, "Unclosed tag on the line %d", 0);
					ZEPHIR_SINIT_NVAR(_9$$5);
					ZVAL_LONG(&_9$$5, (no + 1));
					ZEPHIR_CALL_FUNCTION(&_10$$5, "sprintf", &_11, 12, &_8$$5, &_9$$5);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", &_12, 13, _10$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(_7$$5, "ice/mvc/view/engine/sleet/parser.zep", 107 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_13$$4 = (zephir_get_numberval(end) + 2);
				ZEPHIR_INIT_NVAR(end);
				ZVAL_LONG(end, _13$$4);
				ZEPHIR_INIT_LNVAR(_15$$4);
				zephir_sub_function(_15$$4, end, start);
				ZEPHIR_SINIT_NVAR(_16$$4);
				ZVAL_LONG(&_16$$4, zephir_get_intval(_15$$4));
				ZEPHIR_INIT_NVAR(_17$$4);
				zephir_substr(_17$$4, line, zephir_get_intval(start), zephir_get_intval(&_16$$4), 0);
				ZEPHIR_CALL_METHOD(&_14$$4, this_ptr, "parse", &_18, 0, _17$$4);
				zephir_check_call_status();
				zephir_concat_self(&parsedLine, _14$$4 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(ch, '%')) {
				ZEPHIR_INIT_LNVAR(_19$$6);
				zephir_sub_function(_19$$6, start, pos);
				ZEPHIR_SINIT_NVAR(_20$$6);
				ZVAL_LONG(&_20$$6, zephir_get_intval(_19$$6));
				ZEPHIR_INIT_NVAR(_21$$6);
				zephir_substr(_21$$6, line, zephir_get_intval(pos), zephir_get_intval(&_20$$6), 0);
				zephir_concat_self(&parsedLine, _21$$6 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_22$$6);
				ZVAL_STRING(&_22$$6, "%}", 0);
				ZEPHIR_SINIT_NVAR(_23$$6);
				ZVAL_LONG(&_23$$6, (zephir_get_numberval(start) + 2));
				ZEPHIR_INIT_NVAR(end);
				zephir_fast_strpos(end, line, &_22$$6, zephir_get_intval(&_23$$6) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(end)) {
					ZEPHIR_INIT_NVAR(_24$$7);
					object_init_ex(_24$$7, ice_exception_ce);
					ZEPHIR_SINIT_NVAR(_25$$7);
					ZVAL_STRING(&_25$$7, "Unclosed tag on the line %d", 0);
					ZEPHIR_SINIT_NVAR(_26$$7);
					ZVAL_LONG(&_26$$7, (no + 1));
					ZEPHIR_CALL_FUNCTION(&_27$$7, "sprintf", &_11, 12, &_25$$7, &_26$$7);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, _24$$7, "__construct", &_12, 13, _27$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(_24$$7, "ice/mvc/view/engine/sleet/parser.zep", 120 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_28$$6 = (zephir_get_numberval(end) + 2);
				ZEPHIR_INIT_NVAR(end);
				ZVAL_LONG(end, _28$$6);
				ZEPHIR_INIT_LNVAR(_30$$6);
				zephir_sub_function(_30$$6, end, start);
				ZEPHIR_SINIT_NVAR(_31$$6);
				ZVAL_LONG(&_31$$6, zephir_get_intval(_30$$6));
				ZEPHIR_INIT_NVAR(_32$$6);
				zephir_substr(_32$$6, line, zephir_get_intval(start), zephir_get_intval(&_31$$6), 0);
				ZEPHIR_CALL_METHOD(&_29$$6, this_ptr, "parse", &_18, 0, _32$$6);
				zephir_check_call_status();
				zephir_concat_self(&parsedLine, _29$$6 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(ch, '#')) {
				ZEPHIR_INIT_LNVAR(_33$$8);
				zephir_sub_function(_33$$8, start, pos);
				ZEPHIR_SINIT_NVAR(_34$$8);
				ZVAL_LONG(&_34$$8, zephir_get_intval(_33$$8));
				ZEPHIR_INIT_NVAR(_35$$8);
				zephir_substr(_35$$8, line, zephir_get_intval(pos), zephir_get_intval(&_34$$8), 0);
				zephir_concat_self(&parsedLine, _35$$8 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_36$$8);
				ZVAL_STRING(&_36$$8, "#}", 0);
				ZEPHIR_SINIT_NVAR(_37$$8);
				ZVAL_LONG(&_37$$8, (zephir_get_numberval(start) + 2));
				ZEPHIR_INIT_NVAR(end);
				zephir_fast_strpos(end, line, &_36$$8, zephir_get_intval(&_37$$8) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(end)) {
					ZEPHIR_INIT_NVAR(_38$$9);
					object_init_ex(_38$$9, ice_exception_ce);
					ZEPHIR_SINIT_NVAR(_39$$9);
					ZVAL_STRING(&_39$$9, "Unclosed comment block on the line %d", 0);
					ZEPHIR_SINIT_NVAR(_40$$9);
					ZVAL_LONG(&_40$$9, (no + 1));
					ZEPHIR_CALL_FUNCTION(&_41$$9, "sprintf", &_11, 12, &_39$$9, &_40$$9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, _38$$9, "__construct", &_12, 13, _41$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(_38$$9, "ice/mvc/view/engine/sleet/parser.zep", 133 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_42$$8 = (zephir_get_numberval(end) + 2);
				ZEPHIR_INIT_NVAR(end);
				ZVAL_LONG(end, _42$$8);
				break;
			}
			ZEPHIR_SINIT_NVAR(_43$$10);
			zephir_sub_function(&_43$$10, start, pos);
			ZEPHIR_SINIT_NVAR(_44$$10);
			ZVAL_LONG(&_44$$10, (zephir_get_numberval(&_43$$10) + 1));
			ZEPHIR_INIT_NVAR(_45$$10);
			zephir_substr(_45$$10, line, zephir_get_intval(pos), zephir_get_intval(&_44$$10), 0);
			zephir_concat_self(&parsedLine, _45$$10 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(end);
			ZVAL_LONG(end, (zephir_get_numberval(start) + 1));
			break;
		} while(0);

		ZEPHIR_CPY_WRT(pos, end);
		ZEPHIR_SINIT_NVAR(_46$$3);
		ZVAL_STRING(&_46$$3, "{", 0);
		ZEPHIR_INIT_NVAR(start);
		zephir_fast_strpos(start, line, &_46$$3, zephir_get_intval(pos) );
	}
	ZEPHIR_INIT_VAR(_47);
	zephir_substr(_47, line, zephir_get_intval(pos), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_concat_self(&parsedLine, _47 TSRMLS_CC);
	RETURN_CCTOR(parsedLine);

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
	int ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_CALL_FUNCTION(&tokenized, "token_get_all", NULL, 136, php);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(tokens);
	array_init(tokens);
	ZEPHIR_MAKE_REF(tokenized);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_6, 3, tokenized);
	ZEPHIR_UNREF(tokenized);
	zephir_check_call_status();
	zephir_is_iterable(tokenized, &_8, &_7, 0, 0, "ice/mvc/view/engine/sleet/parser.zep", 182);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HVALUE(token, _9);
		_10$$5 = Z_TYPE_P(token) == IS_ARRAY;
		if (_10$$5) {
			zephir_array_fetch_long(&_11$$5, token, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 176 TSRMLS_CC);
			_10$$5 = ZEPHIR_IS_LONG(_11$$5, 379);
		}
		if (_10$$5) {
			continue;
		}
		zephir_array_append(&tokens, token, PH_SEPARATE, "ice/mvc/view/engine/sleet/parser.zep", 179);
	}
	ZEPHIR_MAKE_REF(tokens);
	ZEPHIR_CALL_FUNCTION(&first, "array_shift", &_6, 3, tokens);
	ZEPHIR_UNREF(tokens);
	zephir_check_call_status();
	if (Z_TYPE_P(first) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unexpected first tag", "ice/mvc/view/engine/sleet/parser.zep", 185);
		return;
	}
	if (Z_TYPE_P(tokens) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unexpected expression", "ice/mvc/view/engine/sleet/parser.zep", 189);
		return;
	}
	zephir_array_fetch_long(&_12, first, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 192 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_12, 307) || ZEPHIR_IS_LONG(_12, 324) || ZEPHIR_IS_LONG(_12, 322) || ZEPHIR_IS_LONG(_12, 331) || ZEPHIR_IS_LONG(_12, 326)) {
			zephir_array_fetch_long(&_13$$9, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 198 TSRMLS_CC);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", _13$$9, " ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 334)) {
			zephir_array_fetch_long(&_14$$10, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 200 TSRMLS_CC);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", _14$$10, "; ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 306) || ZEPHIR_IS_LONG(_12, 333)) {
			zephir_array_fetch_long(&_15$$11, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 203 TSRMLS_CC);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", _15$$11, ": ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 330) || ZEPHIR_IS_LONG(_12, 332) || ZEPHIR_IS_LONG(_12, 304) || ZEPHIR_IS_LONG(_12, 305) || ZEPHIR_IS_LONG(_12, 320) || ZEPHIR_IS_LONG(_12, 323) || ZEPHIR_IS_LONG(_12, 321) || ZEPHIR_IS_LONG(_12, 325)) {
			zephir_array_fetch_long(&_16$$12, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 212 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parsecontrol", NULL, 137, _16$$12, tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 319)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseecho", NULL, 138, tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 353)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseset", &_17, 139, tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_12, 310)) {
			zephir_array_fetch_long(&_18$$15, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 218 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(_18$$15, "set")) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseset", &_17, 139, tokens);
				zephir_check_call_status();
				RETURN_MM();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(_12, 344)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseuse", NULL, 140, tokens);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *control, *expression, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &control, &expression);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 141, expression);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *expression, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 141, expression);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *expression, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 141, expression);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *expression, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 141, expression);
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
	int ZEPHIR_LAST_CALL_STATUS;
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
		ZEPHIR_CALL_METHOD(&_0, i, "valid", &_1, 142);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&token, i, "current", &_2, 143);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, i, "key", &_5, 144);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_LONG(_6$$3, (zephir_get_numberval(_4$$3) + 1));
		ZEPHIR_CALL_METHOD(&_3$$3, i, "offsetexists", &_7, 145, _6$$3);
		zephir_check_call_status();
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_CALL_METHOD(&_8$$3, i, "key", &_5, 144);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_6$$3);
			ZVAL_LONG(_6$$3, (zephir_get_numberval(_8$$3) + 1));
			ZEPHIR_CALL_METHOD(&next, i, "offsetget", &_9, 146, _6$$3);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(next);
			ZVAL_NULL(next);
		}
		if (ZEPHIR_IS_STRING(next, "|")) {
			ZEPHIR_CALL_METHOD(&_10$$4, i, "key", &_5, 144);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(seek);
			ZVAL_LONG(seek, (zephir_get_numberval(_10$$4) + 2));
			ZEPHIR_CALL_METHOD(&filter, i, "offsetget", &_9, 146, seek);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_11$$4);
			_12$$4 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
			zephir_array_fetch_long(&_13$$4, filter, 1, PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 294 TSRMLS_CC);
			if (zephir_array_isset(_12$$4, _13$$4)) {
				_14$$4 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
				ZEPHIR_OBS_NVAR(_11$$4);
				ZEPHIR_OBS_NVAR(_15$$4);
				zephir_array_fetch_long(&_15$$4, filter, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 294 TSRMLS_CC);
				zephir_array_fetch(&_11$$4, _14$$4, _15$$4, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 294 TSRMLS_CC);
			} else {
				ZEPHIR_OBS_NVAR(_11$$4);
				zephir_array_fetch_long(&_11$$4, filter, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 294 TSRMLS_CC);
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
				ZEPHIR_CALL_METHOD(&_17$$5, this_ptr, "token", &_18, 147, token, prev, next);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_19$$5);
				ZEPHIR_CONCAT_SVSVS(_19$$5, "$this->filter->sanitize(", _17$$5, ", '", filter, "'");
				zephir_concat_self(&parsed, _19$$5 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_METHOD(&_20$$6, this_ptr, "token", &_18, 147, token, prev, next);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_21$$6);
				ZEPHIR_CONCAT_VSV(_21$$6, filter, "(", _20$$6);
				zephir_concat_self(&parsed, _21$$6 TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(_16$$4);
			ZVAL_LONG(_16$$4, (zephir_get_numberval(seek) + 1));
			ZEPHIR_CALL_METHOD(&_22$$4, i, "offsetexists", &_7, 145, _16$$4);
			zephir_check_call_status();
			if (zephir_is_true(_22$$4)) {
				ZEPHIR_INIT_NVAR(_16$$4);
				ZVAL_LONG(_16$$4, (zephir_get_numberval(seek) + 1));
				ZEPHIR_CALL_METHOD(&next, i, "offsetget", &_9, 146, _16$$4);
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
			ZEPHIR_CALL_METHOD(NULL, i, "seek", &_23, 148, seek);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, i, "next", &_24, 149);
			zephir_check_call_status();
			continue;
		}
		ZEPHIR_CALL_METHOD(&_25$$3, this_ptr, "token", &_18, 147, token, prev, next);
		zephir_check_call_status();
		zephir_concat_self(&parsed, _25$$3 TSRMLS_CC);
		ZEPHIR_CPY_WRT(prev, token);
		ZEPHIR_CALL_METHOD(NULL, i, "next", &_24, 149);
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
	int ZEPHIR_LAST_CALL_STATUS;
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
		zephir_array_fetch_long(&_0$$3, token, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 338 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_0$$3, 329) || ZEPHIR_IS_LONG(_0$$3, 302) || ZEPHIR_IS_LONG(_0$$3, 290) || ZEPHIR_IS_LONG(_0$$3, 285) || ZEPHIR_IS_LONG(_0$$3, 284) || ZEPHIR_IS_LONG(_0$$3, 283) || ZEPHIR_IS_LONG(_0$$3, 282) || ZEPHIR_IS_LONG(_0$$3, 287) || ZEPHIR_IS_LONG(_0$$3, 286)) {
				zephir_array_fetch_long(&_1$$4, token, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 348 TSRMLS_CC);
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
				zephir_array_fetch_long(&_2$$7, token, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 354 TSRMLS_CC);
				zephir_get_strval(_3$$7, _2$$7);
				ZEPHIR_CPY_WRT(str, _3$$7);
				_4$$7 = ZEPHIR_IS_STRING(next, "(");
				if (_4$$7) {
					_5$$7 = !ZEPHIR_IS_STRING(prev, ".");
					if (!(_5$$7)) {
						_6$$7 = Z_TYPE_P(prev) == IS_ARRAY;
						if (_6$$7) {
							zephir_array_fetch_long(&_7$$7, prev, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 356 TSRMLS_CC);
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
						zephir_array_fetch(&_8$$8, _10$$8, str, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 357 TSRMLS_CC);
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
						ZVAL_LONG(&_15$$15, _14$$15);
						ZEPHIR_CALL_FUNCTION(&_16$$15, "ctype_upper", NULL, 150, &_15$$15);
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
			zephir_array_fetch_long(&_18$$17, token, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 381 TSRMLS_CC);
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
				ZEPHIR_CALL_FUNCTION(&_20$$23, "end", &_21, 90, _19$$23);
				ZEPHIR_UNREF(_19$$23);
				zephir_check_call_status();
				do {
					if (ZEPHIR_IS_LONG(_20$$23, 1)) {
						_22$$24 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
						ZEPHIR_MAKE_REF(_22$$24);
						ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_23, 151, _22$$24);
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
				ZEPHIR_CALL_FUNCTION(&_27$$28, "end", &_21, 90, _26$$28);
				ZEPHIR_UNREF(_26$$28);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(_27$$28, 2)) {
					_28$$29 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
					ZEPHIR_MAKE_REF(_28$$29);
					ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_23, 151, _28$$29);
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
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("env"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			zephir_create_array(_3$$4, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_3$$4, SS("capitalize"), SL("ucfirst"), 1);
			zephir_update_property_this(this_ptr, SL("filters"), _3$$4 TSRMLS_CC);
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
			zephir_update_property_this(this_ptr, SL("functions"), _5$$5 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

