
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

ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_Sleet_Parser) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\View\\Engine\\Sleet, Parser, ice, mvc_view_engine_sleet_parser, ice_mvc_view_engine_sleet_parser_method_entry, 0);

	zend_declare_property_null(ice_mvc_view_engine_sleet_parser_ce, SL("functions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_engine_sleet_parser_ce, SL("filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_engine_sleet_parser_ce, SL("env"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_mvc_view_engine_sleet_parser_ce->create_object = zephir_init_properties;
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *tag, *methods = NULL, *functions, *method = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11, *_12, *_13;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(tag);
	object_init_ex(tag, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Ice\\Tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, tag, "__construct", NULL, 127, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 256);
	ZEPHIR_CALL_METHOD(&methods, tag, "getmethods", NULL, 128, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(functions);
	array_init(functions);
	zephir_is_iterable(methods, &_2, &_1, 0, 0, "ice/mvc/view/engine/sleet/parser.zep", 57);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(method, _3);
		ZEPHIR_OBS_NVAR(_4);
		zephir_read_property(&_4, method, SL("name"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_STRING(_4, "__construct")) {
				continue;
			}
			ZEPHIR_OBS_NVAR(_5);
			zephir_read_property(&_5, method, SL("name"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_SV(_6, "$this->tag->", _5);
			ZEPHIR_OBS_NVAR(_7);
			zephir_read_property(&_7, method, SL("name"), PH_NOISY_CC);
			zephir_array_update_zval(&functions, _7, &_6, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(_8);
			zephir_read_property(&_8, method, SL("name"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_SV(_9, "$this->tag->", _8);
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_OBS_NVAR(_10);
			zephir_read_property(&_10, method, SL("name"), PH_NOISY_CC);
			zephir_uncamelize(_0, _10);
			zephir_array_update_zval(&functions, _0, &_9, PH_COPY | PH_SEPARATE);
		} while(0);

	}
	ZEPHIR_INIT_VAR(_11);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("functions"), PH_NOISY_CC);
	zephir_fast_array_merge(_11, &(_12), &(functions) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("functions"), _11 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3;
	HashPosition _2;
	zval *text_param = NULL, *parsed, *key = NULL, *line = NULL, *_0, *_1, **_4, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_9 = NULL;
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
		ZEPHIR_INIT_LNVAR(_5);
		if (zephir_is_true(key)) {
			ZEPHIR_INIT_NVAR(_5);
			ZEPHIR_GET_CONSTANT(_5, "PHP_EOL");
		} else {
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "", 1);
		}
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, (zephir_get_numberval(key) + 1));
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "line", &_8, 0, line, _7);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_VV(_9, _5, _6);
		zephir_concat_self(&parsed, _9 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_15 = NULL;
	unsigned char _1;
	int no, i, ZEPHIR_LAST_CALL_STATUS, _13;
	zval *line_param = NULL, *no_param = NULL, *pos = NULL, *start = NULL, *parsedLine, *end = NULL, *ch = NULL, _0, *_2 = NULL, _3 = zval_used_for_init, *_4 = NULL, _5 = zval_used_for_init, _6 = zval_used_for_init, *_7 = NULL, _8 = zval_used_for_init, _9 = zval_used_for_init, *_10 = NULL, *_14 = NULL, *_16 = NULL, _17 = zval_used_for_init, *_18 = NULL;
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
		_1 = ZEPHIR_STRING_OFFSET(line, i);
		ZEPHIR_INIT_NVAR(ch);
		ZVAL_LONG(ch, _1);
		do {
			if (ZEPHIR_IS_LONG(ch, '{')) {
				ZEPHIR_INIT_LNVAR(_2);
				sub_function(_2, start, pos TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, zephir_get_intval(_2));
				ZEPHIR_INIT_NVAR(_4);
				zephir_substr(_4, line, zephir_get_intval(pos), zephir_get_intval(&_3), 0);
				zephir_concat_self(&parsedLine, _4 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "}}", 0);
				ZEPHIR_SINIT_NVAR(_6);
				ZVAL_LONG(&_6, (zephir_get_numberval(start) + 2));
				ZEPHIR_INIT_NVAR(end);
				zephir_fast_strpos(end, line, &_5, zephir_get_intval(&_6) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(end)) {
					ZEPHIR_INIT_NVAR(_7);
					object_init_ex(_7, ice_exception_ce);
					ZEPHIR_SINIT_NVAR(_8);
					ZVAL_STRING(&_8, "Unclosed tag on the line %d", 0);
					ZEPHIR_SINIT_NVAR(_9);
					ZVAL_LONG(&_9, (no + 1));
					ZEPHIR_CALL_FUNCTION(&_10, "sprintf", &_11, 1, &_8, &_9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, _7, "__construct", &_12, 2, _10);
					zephir_check_call_status();
					zephir_throw_exception_debug(_7, "ice/mvc/view/engine/sleet/parser.zep", 107 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_13 = (zephir_get_numberval(end) + 2);
				ZEPHIR_INIT_NVAR(end);
				ZVAL_LONG(end, _13);
				ZEPHIR_INIT_LNVAR(_14);
				sub_function(_14, end, start TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_8);
				ZVAL_LONG(&_8, zephir_get_intval(_14));
				ZEPHIR_INIT_NVAR(_7);
				zephir_substr(_7, line, zephir_get_intval(start), zephir_get_intval(&_8), 0);
				ZEPHIR_CALL_METHOD(&_10, this_ptr, "parse", &_15, 0, _7);
				zephir_check_call_status();
				zephir_concat_self(&parsedLine, _10 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(ch, '%')) {
				ZEPHIR_INIT_LNVAR(_2);
				sub_function(_2, start, pos TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, zephir_get_intval(_2));
				ZEPHIR_INIT_NVAR(_4);
				zephir_substr(_4, line, zephir_get_intval(pos), zephir_get_intval(&_3), 0);
				zephir_concat_self(&parsedLine, _4 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "%}", 0);
				ZEPHIR_SINIT_NVAR(_6);
				ZVAL_LONG(&_6, (zephir_get_numberval(start) + 2));
				ZEPHIR_INIT_NVAR(end);
				zephir_fast_strpos(end, line, &_5, zephir_get_intval(&_6) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(end)) {
					ZEPHIR_INIT_NVAR(_16);
					object_init_ex(_16, ice_exception_ce);
					ZEPHIR_SINIT_NVAR(_9);
					ZVAL_STRING(&_9, "Unclosed tag on the line %d", 0);
					ZEPHIR_SINIT_NVAR(_17);
					ZVAL_LONG(&_17, (no + 1));
					ZEPHIR_CALL_FUNCTION(&_18, "sprintf", &_11, 1, &_9, &_17);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, _16, "__construct", &_12, 2, _18);
					zephir_check_call_status();
					zephir_throw_exception_debug(_16, "ice/mvc/view/engine/sleet/parser.zep", 120 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_13 = (zephir_get_numberval(end) + 2);
				ZEPHIR_INIT_NVAR(end);
				ZVAL_LONG(end, _13);
				ZEPHIR_INIT_LNVAR(_14);
				sub_function(_14, end, start TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_8);
				ZVAL_LONG(&_8, zephir_get_intval(_14));
				ZEPHIR_INIT_NVAR(_7);
				zephir_substr(_7, line, zephir_get_intval(start), zephir_get_intval(&_8), 0);
				ZEPHIR_CALL_METHOD(&_10, this_ptr, "parse", &_15, 0, _7);
				zephir_check_call_status();
				zephir_concat_self(&parsedLine, _10 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(ch, '#')) {
				ZEPHIR_INIT_LNVAR(_2);
				sub_function(_2, start, pos TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, zephir_get_intval(_2));
				ZEPHIR_INIT_NVAR(_4);
				zephir_substr(_4, line, zephir_get_intval(pos), zephir_get_intval(&_3), 0);
				zephir_concat_self(&parsedLine, _4 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "#}", 0);
				ZEPHIR_SINIT_NVAR(_6);
				ZVAL_LONG(&_6, (zephir_get_numberval(start) + 2));
				ZEPHIR_INIT_NVAR(end);
				zephir_fast_strpos(end, line, &_5, zephir_get_intval(&_6) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(end)) {
					ZEPHIR_INIT_NVAR(_16);
					object_init_ex(_16, ice_exception_ce);
					ZEPHIR_SINIT_NVAR(_9);
					ZVAL_STRING(&_9, "Unclosed comment block on the line %d", 0);
					ZEPHIR_SINIT_NVAR(_17);
					ZVAL_LONG(&_17, (no + 1));
					ZEPHIR_CALL_FUNCTION(&_18, "sprintf", &_11, 1, &_9, &_17);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, _16, "__construct", &_12, 2, _18);
					zephir_check_call_status();
					zephir_throw_exception_debug(_16, "ice/mvc/view/engine/sleet/parser.zep", 133 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_13 = (zephir_get_numberval(end) + 2);
				ZEPHIR_INIT_NVAR(end);
				ZVAL_LONG(end, _13);
				break;
			}
			ZEPHIR_SINIT_NVAR(_3);
			sub_function(&_3, start, pos TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, (zephir_get_numberval(&_3) + 1));
			ZEPHIR_INIT_NVAR(_4);
			zephir_substr(_4, line, zephir_get_intval(pos), zephir_get_intval(&_5), 0);
			zephir_concat_self(&parsedLine, _4 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(end);
			ZVAL_LONG(end, (zephir_get_numberval(start) + 1));
			break;
		} while(0);

		ZEPHIR_CPY_WRT(pos, end);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "{", 0);
		ZEPHIR_INIT_NVAR(start);
		zephir_fast_strpos(start, line, &_3, zephir_get_intval(pos) );
	}
	ZEPHIR_INIT_NVAR(_4);
	zephir_substr(_4, line, zephir_get_intval(pos), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_concat_self(&parsedLine, _4 TSRMLS_CC);
	RETURN_CCTOR(parsedLine);

}

/**
 * Parse one sleet expression.
 *
 * @param string expression
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parse) {

	zend_bool _7;
	HashTable *_5;
	HashPosition _4;
	zephir_fcall_cache_entry *_3 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *expression_param = NULL, *php, *tokenized = NULL, *tokens, *token = NULL, *first = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2 = NULL, **_6, *_8, *_9;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression_param);

	zephir_get_strval(expression, expression_param);


	ZEPHIR_INIT_VAR(php);
	if (zephir_start_with_str(expression, SL("{{"))) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 2);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, -2);
		ZEPHIR_INIT_VAR(_2);
		zephir_substr(_2, expression, 2 , -2 , 0);
		ZEPHIR_CONCAT_SV(php, "<?php echo ", _2);
	} else {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 2);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, -2);
		ZEPHIR_INIT_NVAR(_2);
		zephir_substr(_2, expression, 2 , -2 , 0);
		ZEPHIR_CONCAT_SV(php, "<?php ", _2);
	}
	ZEPHIR_CALL_FUNCTION(&tokenized, "token_get_all", NULL, 129, php);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(tokens);
	array_init(tokens);
	Z_SET_ISREF_P(tokenized);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_3, 4, tokenized);
	Z_UNSET_ISREF_P(tokenized);
	zephir_check_call_status();
	zephir_is_iterable(tokenized, &_5, &_4, 0, 0, "ice/mvc/view/engine/sleet/parser.zep", 182);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(token, _6);
		_7 = Z_TYPE_P(token) == IS_ARRAY;
		if (_7) {
			zephir_array_fetch_long(&_8, token, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 176 TSRMLS_CC);
			_7 = ZEPHIR_IS_LONG(_8, 379);
		}
		if (_7) {
			continue;
		}
		zephir_array_append(&tokens, token, PH_SEPARATE, "ice/mvc/view/engine/sleet/parser.zep", 179);
	}
	Z_SET_ISREF_P(tokens);
	ZEPHIR_CALL_FUNCTION(&first, "array_shift", &_3, 4, tokens);
	Z_UNSET_ISREF_P(tokens);
	zephir_check_call_status();
	if (Z_TYPE_P(first) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unexpected first tag", "ice/mvc/view/engine/sleet/parser.zep", 185);
		return;
	}
	if (Z_TYPE_P(tokens) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unexpected expression", "ice/mvc/view/engine/sleet/parser.zep", 189);
		return;
	}
	zephir_array_fetch_long(&_8, first, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 192 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_8, 307) || ZEPHIR_IS_LONG(_8, 324) || ZEPHIR_IS_LONG(_8, 322) || ZEPHIR_IS_LONG(_8, 331) || ZEPHIR_IS_LONG(_8, 326)) {
			zephir_array_fetch_long(&_9, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 198 TSRMLS_CC);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", _9, " ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_8, 334)) {
			zephir_array_fetch_long(&_8, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 200 TSRMLS_CC);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", _8, "; ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_8, 306) || ZEPHIR_IS_LONG(_8, 333)) {
			zephir_array_fetch_long(&_8, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 203 TSRMLS_CC);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", _8, ": ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_8, 330) || ZEPHIR_IS_LONG(_8, 332) || ZEPHIR_IS_LONG(_8, 304) || ZEPHIR_IS_LONG(_8, 305) || ZEPHIR_IS_LONG(_8, 320) || ZEPHIR_IS_LONG(_8, 323) || ZEPHIR_IS_LONG(_8, 321) || ZEPHIR_IS_LONG(_8, 325)) {
			zephir_array_fetch_long(&_8, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 212 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parsecontrol", NULL, 130, _8, tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_8, 319)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseecho", NULL, 131, tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_8, 353)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseset", &_10, 132, tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(_8, 310)) {
			zephir_array_fetch_long(&_8, first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 218 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(_8, "set")) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseset", &_10, 132, tokens);
				zephir_check_call_status();
				RETURN_MM();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(_8, 344)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseuse", NULL, 133, tokens);
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



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 134, expression);
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



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 134, expression);
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



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 134, expression);
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



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 134, expression);
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

	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_17 = NULL, *_19 = NULL, *_20 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *tokens, *i, *parsed, *prev = NULL, *next = NULL, *token = NULL, *filter = NULL, *seek = NULL, *filters = NULL, *_0 = NULL, *_3 = NULL, *_4 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_12, *_13, *_14, *_15 = NULL, *_16 = NULL, *_18 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tokens);



	ZEPHIR_INIT_VAR(i);
	object_init_ex(i, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, i, "__construct", NULL, 3, tokens);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(parsed);
	ZVAL_STRING(parsed, "", 1);
	ZEPHIR_INIT_VAR(prev);
	ZVAL_STRING(prev, "", 1);
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, i, "valid", &_1, 135);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&token, i, "current", &_2, 136);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, i, "key", &_5, 137);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, (zephir_get_numberval(_4) + 1));
		ZEPHIR_CALL_METHOD(&_3, i, "offsetexists", &_7, 138, _6);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			ZEPHIR_CALL_METHOD(&_8, i, "key", &_5, 137);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, (zephir_get_numberval(_8) + 1));
			ZEPHIR_CALL_METHOD(&next, i, "offsetget", &_9, 139, _6);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(next);
			ZVAL_NULL(next);
		}
		if (ZEPHIR_IS_STRING(next, "|")) {
			ZEPHIR_CALL_METHOD(&_10, i, "key", &_5, 137);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(seek);
			ZVAL_LONG(seek, (zephir_get_numberval(_10) + 2));
			ZEPHIR_CALL_METHOD(&filter, i, "offsetget", &_9, 139, seek);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_11);
			_12 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
			zephir_array_fetch_long(&_13, filter, 1, PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 294 TSRMLS_CC);
			if (zephir_array_isset(_12, _13)) {
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
				ZEPHIR_OBS_NVAR(_11);
				ZEPHIR_OBS_NVAR(_15);
				zephir_array_fetch_long(&_15, filter, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 294 TSRMLS_CC);
				zephir_array_fetch(&_11, _14, _15, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 294 TSRMLS_CC);
			} else {
				ZEPHIR_OBS_NVAR(_11);
				zephir_array_fetch_long(&_11, filter, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 294 TSRMLS_CC);
			}
			ZEPHIR_CPY_WRT(filter, _11);
			ZEPHIR_INIT_NVAR(filters);
			zephir_create_array(filters, 17, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "camelize", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "uncamelize", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "human", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "lower", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "upper", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "alnum", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "alpha", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "email", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "float", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "int", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "string", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "strip_repeats", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "e", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "escape", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "strip_special", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "unescape", 1);
			zephir_array_fast_append(filters, _6);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "unstrip_special", 1);
			zephir_array_fast_append(filters, _6);
			if (zephir_fast_in_array(filter, filters TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&_16, this_ptr, "token", &_17, 140, token, prev, next);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_11);
				ZEPHIR_CONCAT_SVSVS(_11, "$this->filter->sanitize(", _16, ", '", filter, "'");
				zephir_concat_self(&parsed, _11 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_METHOD(&_16, this_ptr, "token", &_17, 140, token, prev, next);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_18);
				ZEPHIR_CONCAT_VSV(_18, filter, "(", _16);
				zephir_concat_self(&parsed, _18 TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, (zephir_get_numberval(seek) + 1));
			ZEPHIR_CALL_METHOD(&_16, i, "offsetexists", &_7, 138, _6);
			zephir_check_call_status();
			if (zephir_is_true(_16)) {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, (zephir_get_numberval(seek) + 1));
				ZEPHIR_CALL_METHOD(&next, i, "offsetget", &_9, 139, _6);
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
			ZEPHIR_CALL_METHOD(NULL, i, "seek", &_19, 141, seek);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, i, "next", &_20, 142);
			zephir_check_call_status();
			continue;
		}
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "token", &_17, 140, token, prev, next);
		zephir_check_call_status();
		zephir_concat_self(&parsed, _10 TSRMLS_CC);
		ZEPHIR_CPY_WRT(prev, token);
		ZEPHIR_CALL_METHOD(NULL, i, "next", &_20, 142);
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

	zephir_fcall_cache_entry *_16 = NULL, *_17 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	unsigned char _12;
	zend_bool _4, _5, _6, _10, _11, _15;
	zval *str = NULL, *_3 = NULL;
	zval *token, *prev = NULL, *next = NULL, *_0, *_1, *_2, *_7 = NULL, *_8, *_9, _13, *_14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &token, &prev, &next);

	if (!prev) {
		prev = ZEPHIR_GLOBAL(global_null);
	}
	if (!next) {
		next = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(token) == IS_ARRAY) {
		zephir_array_fetch_long(&_0, token, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 338 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_0, 329) || ZEPHIR_IS_LONG(_0, 285) || ZEPHIR_IS_LONG(_0, 284) || ZEPHIR_IS_LONG(_0, 283) || ZEPHIR_IS_LONG(_0, 282) || ZEPHIR_IS_LONG(_0, 287) || ZEPHIR_IS_LONG(_0, 286)) {
				zephir_array_fetch_long(&_1, token, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 346 TSRMLS_CC);
				ZEPHIR_CONCAT_SVS(return_value, " ", _1, " ");
				RETURN_MM();
			}
			if (ZEPHIR_IS_LONG(_0, 263)) {
				RETURN_MM_STRING(" || ", 1);
			}
			if (ZEPHIR_IS_LONG(_0, 265)) {
				RETURN_MM_STRING(" && ", 1);
			}
			if (ZEPHIR_IS_LONG(_0, 310)) {
				ZEPHIR_OBS_VAR(_2);
				zephir_array_fetch_long(&_2, token, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 352 TSRMLS_CC);
				zephir_get_strval(_3, _2);
				ZEPHIR_CPY_WRT(str, _3);
				_4 = ZEPHIR_IS_STRING(next, "(");
				if (_4) {
					_5 = !ZEPHIR_IS_STRING(prev, ".");
					if (!(_5)) {
						_6 = Z_TYPE_P(prev) == IS_ARRAY;
						if (_6) {
							zephir_array_fetch_long(&_1, prev, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 354 TSRMLS_CC);
							_6 = !ZEPHIR_IS_LONG(_1, 384);
						}
						_5 = _6;
					}
					_4 = _5;
				}
				if (_4) {
					ZEPHIR_INIT_VAR(_7);
					_8 = zephir_fetch_nproperty_this(this_ptr, SL("functions"), PH_NOISY_CC);
					if (zephir_array_isset(_8, str)) {
						_9 = zephir_fetch_nproperty_this(this_ptr, SL("functions"), PH_NOISY_CC);
						zephir_array_fetch(&_7, _9, str, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 355 TSRMLS_CC);
					} else {
						ZEPHIR_CPY_WRT(_7, str);
					}
					RETURN_CCTOR(_7);
				}
				do {
					if (ZEPHIR_IS_STRING(str, "in")) {
						RETURN_MM_STRING(" as ", 1);
					}
					if (ZEPHIR_IS_STRING(str, "is")) {
						if (ZEPHIR_IS_STRING(next, "!")) {
							ZVAL_STRING(_7, " != ", 1);
						} else {
							ZVAL_STRING(_7, " == ", 1);
						}
						RETURN_CCTOR(_7);
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
					_10 = ZEPHIR_IS_STRING(prev, ".");
					if (!(_10)) {
						_10 = ZEPHIR_IS_STRING(next, "(");
					}
					_11 = _10;
					if (!(_11)) {
						_12 = ZEPHIR_STRING_OFFSET(str, 0);
						ZEPHIR_SINIT_VAR(_13);
						ZVAL_LONG(&_13, _12);
						ZEPHIR_CALL_FUNCTION(&_14, "ctype_upper", NULL, 143, &_13);
						zephir_check_call_status();
						_15 = zephir_is_true(_14);
						if (_15) {
							_15 = !ZEPHIR_IS_STRING(next, "|");
						}
						_11 = _15;
					}
					if (_11) {
						RETURN_CTOR(str);
					}
					ZEPHIR_CONCAT_SV(return_value, "$", str);
					RETURN_MM();
				} while(0);

			}
			zephir_array_fetch_long(&_1, token, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 379 TSRMLS_CC);
			RETURN_CTOR(_1);
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
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
				Z_SET_ISREF_P(_8);
				ZEPHIR_CALL_FUNCTION(&_14, "end", &_16, 81, _8);
				Z_UNSET_ISREF_P(_8);
				zephir_check_call_status();
				do {
					if (ZEPHIR_IS_LONG(_14, 1)) {
						_9 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
						Z_SET_ISREF_P(_9);
						ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_17, 144, _9);
						Z_UNSET_ISREF_P(_9);
						zephir_check_call_status();
						RETURN_MM_STRING(" : ", 1);
					}
					RETURN_MM_STRING(" => ", 1);
				} while(0);

			}
			if (ZEPHIR_IS_STRING(token, "?")) {
				ZEPHIR_INIT_ZVAL_NREF(_8);
				ZVAL_LONG(_8, 1);
				zephir_update_property_array_append(this_ptr, SL("env"), _8 TSRMLS_CC);
				RETURN_MM_STRING(" ? ", 1);
			}
			if (ZEPHIR_IS_STRING(token, "[")) {
				ZEPHIR_INIT_ZVAL_NREF(_8);
				ZVAL_LONG(_8, 2);
				zephir_update_property_array_append(this_ptr, SL("env"), _8 TSRMLS_CC);
				RETVAL_ZVAL(token, 1, 0);
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(token, "]")) {
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
				Z_SET_ISREF_P(_8);
				ZEPHIR_CALL_FUNCTION(&_14, "end", &_16, 81, _8);
				Z_UNSET_ISREF_P(_8);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(_14, 2)) {
					_9 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
					Z_SET_ISREF_P(_9);
					ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_17, 144, _9);
					Z_UNSET_ISREF_P(_9);
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

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC) {

		zval *_3 = NULL;
		zval *_0, *_1, *_2, *_4;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("env"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3);
			zephir_create_array(_3, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_3, SS("capitalize"), SL("ucfirst"), 1);
			zephir_update_property_this(this_ptr, SL("filters"), _3 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("functions"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_3);
			zephir_create_array(_3, 5, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_3, SS("content"), SL("$this->getContent"), 1);
			add_assoc_stringl_ex(_3, SS("partial"), SL("$this->partial"), 1);
			add_assoc_stringl_ex(_3, SS("load"), SL("$this->load"), 1);
			add_assoc_stringl_ex(_3, SS("dump"), SL("$this->dump->vars"), 1);
			add_assoc_stringl_ex(_3, SS("version"), SL("Ice\\Version::get"), 1);
			zephir_update_property_this(this_ptr, SL("functions"), _3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

