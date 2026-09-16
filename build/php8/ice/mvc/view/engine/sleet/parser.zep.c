
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
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_array.h"


/**
 * Sleet file parser.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_Sleet_Parser)
{
	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\View\\Engine\\Sleet, Parser, ice, mvc_view_engine_sleet_parser, ice_mvc_view_engine_sleet_parser_method_entry, 0);

	zend_declare_property_null(ice_mvc_view_engine_sleet_parser_ce, SL("functions"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_view_engine_sleet_parser_ce, SL("filters"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_view_engine_sleet_parser_ce, SL("env"), ZEND_ACC_PROTECTED);
	ice_mvc_view_engine_sleet_parser_ce->create_object = zephir_init_properties_Ice_Mvc_View_Engine_Sleet_Parser;
	zephir_declare_class_constant_long(ice_mvc_view_engine_sleet_parser_ce, SL("NORMAL"), 0);

	zephir_declare_class_constant_long(ice_mvc_view_engine_sleet_parser_ce, SL("SHORTIF"), 1);

	zephir_declare_class_constant_long(ice_mvc_view_engine_sleet_parser_ce, SL("INARRAY"), 2);

	return SUCCESS;
}

/**
 * Sleet parser constructor. Fetch Ice\Tag methods.
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, __construct)
{
	zend_bool _13;
	zval tag, methods, functions, method, _0, _1, *_2, *_3, _12, _22, _23, _4$$3, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5, _14$$6, _15$$8, _16$$8, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&functions);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("name", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("functions", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&tag);
	object_init_ex(&tag, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Ice\\Tag");
	ZEPHIR_CALL_METHOD(NULL, &tag, "__construct", NULL, 105, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD(&methods, &tag, "getmethods", NULL, 187, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&functions);
	array_init(&functions);
	if (Z_TYPE_P(&methods) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_string_to_char_array(&_0, &methods);
		_2 = &_0;
	} else {
		_2 = &methods;
	}
	zephir_is_iterable(_2, 0, "ice/mvc/view/engine/sleet/parser.zep", 56);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _3)
		{
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_COPY(&method, _3);
			zephir_read_property_cached(&_4$$3, &method, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_STRING(&_4$$3, "__construct")) { goto zephir_switch_0_clause_0; }
			goto zephir_switch_0_clause_1;
			zephir_switch_0_clause_0: ;
				goto zephir_switch_0_end;
			zephir_switch_0_clause_1: ;
				zephir_read_property_cached(&_5$$5, &method, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZEPHIR_CONCAT_SV(&_6$$5, "$this->tag->", &_5$$5);
				ZEPHIR_OBS_NVAR(&_7$$5);
				zephir_read_property_cached(&_7$$5, &method, _zephir_prop_0, 0, PH_NOISY_CC);
				zephir_array_update_zval(&functions, &_7$$5, &_6$$5, PH_COPY | PH_SEPARATE);
				zephir_read_property_cached(&_8$$5, &method, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZEPHIR_CONCAT_SV(&_9$$5, "$this->tag->", &_8$$5);
				ZEPHIR_INIT_NVAR(&_10$$5);
				zephir_read_property_cached(&_11$$5, &method, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
				zephir_uncamelize(&_10$$5, &_11$$5, NULL );
				zephir_array_update_zval(&functions, &_10$$5, &_9$$5, PH_COPY | PH_SEPARATE);
			zephir_switch_0_end: ;

		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _2, "rewind", NULL, 0);
		zephir_check_call_status();
		_13 = 1;
		while (1) {
			if (_13) {
				_13 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_12, _2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, _2, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property_cached(&_14$$6, &method, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_STRING(&_14$$6, "__construct")) { goto zephir_switch_1_clause_0; }
				goto zephir_switch_1_clause_1;
				zephir_switch_1_clause_0: ;
					goto zephir_switch_1_end;
				zephir_switch_1_clause_1: ;
					zephir_read_property_cached(&_15$$8, &method, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_16$$8);
					ZEPHIR_CONCAT_SV(&_16$$8, "$this->tag->", &_15$$8);
					ZEPHIR_OBS_NVAR(&_17$$8);
					zephir_read_property_cached(&_17$$8, &method, _zephir_prop_0, 0, PH_NOISY_CC);
					zephir_array_update_zval(&functions, &_17$$8, &_16$$8, PH_COPY | PH_SEPARATE);
					zephir_read_property_cached(&_18$$8, &method, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_19$$8);
					ZEPHIR_CONCAT_SV(&_19$$8, "$this->tag->", &_18$$8);
					ZEPHIR_INIT_NVAR(&_20$$8);
					zephir_read_property_cached(&_21$$8, &method, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
					zephir_uncamelize(&_20$$8, &_21$$8, NULL );
					zephir_array_update_zval(&functions, &_20$$8, &_19$$8, PH_COPY | PH_SEPARATE);
				zephir_switch_1_end: ;

		}
	}
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_INIT_VAR(&_22);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 257, PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_22, &_1, &functions);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 257, &_22);
	ZVAL_UNDEF(&_23);
	ZVAL_LONG(&_23, 0);
	zephir_update_property_array_append(this_ptr, SL("env"), &_23);
	ZEPHIR_MM_RESTORE();
}

/**
 * Parse text.
 *
 * @param string text
 * @return string Parsed text
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, text)
{
	char ch = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, _17$$4, _36$$6, _54$$8;
	zephir_fcall_cache_entry *_11 = NULL, *_15 = NULL, *_16 = NULL, *_22 = NULL;
	zval text_zv, pos, start, parsedText, end, _0, _59, _1$$4, _2$$4, _3$$4, _4$$4, _5$$4, _18$$4, _19$$4, _20$$4, _21$$4, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _12$$5, _13$$5, _14$$5, _23$$6, _24$$6, _25$$6, _26$$6, _27$$6, _37$$6, _38$$6, _39$$6, _40$$6, _28$$7, _29$$7, _30$$7, _31$$7, _32$$7, _33$$7, _34$$7, _35$$7, _41$$8, _42$$8, _43$$8, _44$$8, _45$$8, _46$$9, _47$$9, _48$$9, _49$$9, _50$$9, _51$$9, _52$$9, _53$$9, _55$$10, _56$$10, _57$$10, _58$$3;
	zend_string *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&parsedText);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_59);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_37$$6);
	ZVAL_UNDEF(&_38$$6);
	ZVAL_UNDEF(&_39$$6);
	ZVAL_UNDEF(&_40$$6);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_41$$8);
	ZVAL_UNDEF(&_42$$8);
	ZVAL_UNDEF(&_43$$8);
	ZVAL_UNDEF(&_44$$8);
	ZVAL_UNDEF(&_45$$8);
	ZVAL_UNDEF(&_46$$9);
	ZVAL_UNDEF(&_47$$9);
	ZVAL_UNDEF(&_48$$9);
	ZVAL_UNDEF(&_49$$9);
	ZVAL_UNDEF(&_50$$9);
	ZVAL_UNDEF(&_51$$9);
	ZVAL_UNDEF(&_52$$9);
	ZVAL_UNDEF(&_53$$9);
	ZVAL_UNDEF(&_55$$10);
	ZVAL_UNDEF(&_56$$10);
	ZVAL_UNDEF(&_57$$10);
	ZVAL_UNDEF(&_58$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZEPHIR_INIT_VAR(&pos);
	ZVAL_LONG(&pos, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "{");
	ZEPHIR_INIT_VAR(&start);
	zephir_fast_strpos(&start, &text_zv, &_0, 0 );
	ZEPHIR_INIT_VAR(&parsedText);
	ZVAL_STRING(&parsedText, "");
	while (1) {
		if (!(!ZEPHIR_IS_FALSE_IDENTICAL(&start))) {
			break;
		}
		i = (zephir_get_numberval(&start) + 1);
		ch = zephir_string_offset_byte(&text_zv, i, PH_NOISY);
		ch = ch;
		if (ch == '{') { goto zephir_switch_0_clause_0; }
		if (ch == '%') { goto zephir_switch_0_clause_1; }
		if (ch == '#') { goto zephir_switch_0_clause_2; }
		goto zephir_switch_0_clause_3;
		zephir_switch_0_clause_0: ;
			ZEPHIR_INIT_NVAR(&_1$$4);
			zephir_sub_function(&_1$$4, &start, &pos);
			ZVAL_LONG(&_2$$4, zephir_get_intval(&_1$$4));
			ZEPHIR_INIT_NVAR(&_3$$4);
			zephir_substr(&_3$$4, &text_zv, zephir_get_intval(&pos), zephir_get_intval(&_2$$4), 0);
			zephir_concat_self(&parsedText, &_3$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "}}");
			ZVAL_LONG(&_5$$4, (zephir_get_numberval(&start) + 2));
			ZEPHIR_INIT_NVAR(&end);
			zephir_fast_strpos(&end, &text_zv, &_4$$4, zephir_get_intval(&_5$$4) );
			if (ZEPHIR_IS_FALSE_IDENTICAL(&end)) {
				ZEPHIR_INIT_NVAR(&_6$$5);
				object_init_ex(&_6$$5, ice_exception_ce);
				ZVAL_LONG(&_7$$5, 0);
				ZEPHIR_INIT_NVAR(&_8$$5);
				zephir_substr(&_8$$5, &text_zv, 0 , zephir_get_intval(&start), 0);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZEPHIR_GET_CONSTANT(&_9$$5, "PHP_EOL");
				ZEPHIR_CALL_FUNCTION(&_10$$5, "substr_count", &_11, 188, &_8$$5, &_9$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "Unclosed echo on the line %d");
				ZVAL_LONG(&_13$$5, (zephir_get_numberval(&_10$$5) + 1));
				ZEPHIR_CALL_FUNCTION(&_14$$5, "sprintf", &_15, 12, &_12$$5, &_13$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_16, 13, &_14$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$5, "ice/mvc/view/engine/sleet/parser.zep", 88);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_17$$4 = (zephir_get_numberval(&end) + 2);
			ZEPHIR_INIT_NVAR(&end);
			ZVAL_LONG(&end, _17$$4);
			ZEPHIR_INIT_NVAR(&_19$$4);
			zephir_sub_function(&_19$$4, &end, &start);
			ZVAL_LONG(&_20$$4, zephir_get_intval(&_19$$4));
			ZEPHIR_INIT_NVAR(&_21$$4);
			zephir_substr(&_21$$4, &text_zv, zephir_get_intval(&start), zephir_get_intval(&_20$$4), 0);
			ZEPHIR_CALL_METHOD(&_18$$4, this_ptr, "parse", &_22, 0, &_21$$4);
			zephir_check_call_status();
			zephir_concat_self(&parsedText, &_18$$4);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_1: ;
			ZEPHIR_INIT_NVAR(&_23$$6);
			zephir_sub_function(&_23$$6, &start, &pos);
			ZVAL_LONG(&_24$$6, zephir_get_intval(&_23$$6));
			ZEPHIR_INIT_NVAR(&_25$$6);
			zephir_substr(&_25$$6, &text_zv, zephir_get_intval(&pos), zephir_get_intval(&_24$$6), 0);
			zephir_concat_self(&parsedText, &_25$$6);
			ZEPHIR_INIT_NVAR(&_26$$6);
			ZVAL_STRING(&_26$$6, "%}");
			ZVAL_LONG(&_27$$6, (zephir_get_numberval(&start) + 2));
			ZEPHIR_INIT_NVAR(&end);
			zephir_fast_strpos(&end, &text_zv, &_26$$6, zephir_get_intval(&_27$$6) );
			if (ZEPHIR_IS_FALSE_IDENTICAL(&end)) {
				ZEPHIR_INIT_NVAR(&_28$$7);
				object_init_ex(&_28$$7, ice_exception_ce);
				ZVAL_LONG(&_29$$7, 0);
				ZEPHIR_INIT_NVAR(&_30$$7);
				zephir_substr(&_30$$7, &text_zv, 0 , zephir_get_intval(&start), 0);
				ZEPHIR_INIT_NVAR(&_31$$7);
				ZEPHIR_GET_CONSTANT(&_31$$7, "PHP_EOL");
				ZEPHIR_CALL_FUNCTION(&_32$$7, "substr_count", &_11, 188, &_30$$7, &_31$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_33$$7);
				ZVAL_STRING(&_33$$7, "Unclosed tag on the line %d");
				ZVAL_LONG(&_34$$7, (zephir_get_numberval(&_32$$7) + 1));
				ZEPHIR_CALL_FUNCTION(&_35$$7, "sprintf", &_15, 12, &_33$$7, &_34$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_28$$7, "__construct", &_16, 13, &_35$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_28$$7, "ice/mvc/view/engine/sleet/parser.zep", 101);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_36$$6 = (zephir_get_numberval(&end) + 2);
			ZEPHIR_INIT_NVAR(&end);
			ZVAL_LONG(&end, _36$$6);
			ZEPHIR_INIT_NVAR(&_38$$6);
			zephir_sub_function(&_38$$6, &end, &start);
			ZVAL_LONG(&_39$$6, zephir_get_intval(&_38$$6));
			ZEPHIR_INIT_NVAR(&_40$$6);
			zephir_substr(&_40$$6, &text_zv, zephir_get_intval(&start), zephir_get_intval(&_39$$6), 0);
			ZEPHIR_CALL_METHOD(&_37$$6, this_ptr, "parse", &_22, 0, &_40$$6);
			zephir_check_call_status();
			zephir_concat_self(&parsedText, &_37$$6);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_2: ;
			ZEPHIR_INIT_NVAR(&_41$$8);
			zephir_sub_function(&_41$$8, &start, &pos);
			ZVAL_LONG(&_42$$8, zephir_get_intval(&_41$$8));
			ZEPHIR_INIT_NVAR(&_43$$8);
			zephir_substr(&_43$$8, &text_zv, zephir_get_intval(&pos), zephir_get_intval(&_42$$8), 0);
			zephir_concat_self(&parsedText, &_43$$8);
			ZEPHIR_INIT_NVAR(&_44$$8);
			ZVAL_STRING(&_44$$8, "#}");
			ZVAL_LONG(&_45$$8, (zephir_get_numberval(&start) + 2));
			ZEPHIR_INIT_NVAR(&end);
			zephir_fast_strpos(&end, &text_zv, &_44$$8, zephir_get_intval(&_45$$8) );
			if (ZEPHIR_IS_FALSE_IDENTICAL(&end)) {
				ZEPHIR_INIT_NVAR(&_46$$9);
				object_init_ex(&_46$$9, ice_exception_ce);
				ZVAL_LONG(&_47$$9, 0);
				ZEPHIR_INIT_NVAR(&_48$$9);
				zephir_substr(&_48$$9, &text_zv, 0 , zephir_get_intval(&start), 0);
				ZEPHIR_INIT_NVAR(&_49$$9);
				ZEPHIR_GET_CONSTANT(&_49$$9, "PHP_EOL");
				ZEPHIR_CALL_FUNCTION(&_50$$9, "substr_count", &_11, 188, &_48$$9, &_49$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_51$$9);
				ZVAL_STRING(&_51$$9, "Unclosed comment block on the line %d");
				ZVAL_LONG(&_52$$9, (zephir_get_numberval(&_50$$9) + 1));
				ZEPHIR_CALL_FUNCTION(&_53$$9, "sprintf", &_15, 12, &_51$$9, &_52$$9);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_46$$9, "__construct", &_16, 13, &_53$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_46$$9, "ice/mvc/view/engine/sleet/parser.zep", 114);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_54$$8 = (zephir_get_numberval(&end) + 2);
			ZEPHIR_INIT_NVAR(&end);
			ZVAL_LONG(&end, _54$$8);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_3: ;
			ZEPHIR_INIT_NVAR(&_55$$10);
			zephir_sub_function(&_55$$10, &start, &pos);
			ZVAL_LONG(&_56$$10, (zephir_get_numberval(&_55$$10) + 1));
			ZEPHIR_INIT_NVAR(&_57$$10);
			zephir_substr(&_57$$10, &text_zv, zephir_get_intval(&pos), zephir_get_intval(&_56$$10), 0);
			zephir_concat_self(&parsedText, &_57$$10);
			ZEPHIR_INIT_NVAR(&end);
			ZVAL_LONG(&end, (zephir_get_numberval(&start) + 1));
			goto zephir_switch_0_end;
		zephir_switch_0_end: ;

		ZEPHIR_CPY_WRT(&pos, &end);
		ZEPHIR_INIT_NVAR(&_58$$3);
		ZVAL_STRING(&_58$$3, "{");
		ZEPHIR_INIT_NVAR(&start);
		zephir_fast_strpos(&start, &text_zv, &_58$$3, zephir_get_intval(&pos) );
	}
	ZEPHIR_INIT_VAR(&_59);
	zephir_substr(&_59, &text_zv, zephir_get_intval(&pos), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_concat_self(&parsedText, &_59);
	RETURN_CCTOR(&parsedText);
}

/**
 * Parse one sleet expression.
 *
 * @param string expression
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parse)
{
	zend_bool _14, _11$$5, _15$$7;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval expression_zv, php, tokenized, tokens, token, first, _1, *_9, *_10, _13, _17, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4, _7$$4, _12$$5, _16$$7, _18$$11, _19$$12, _20$$13, _21$$14, _23$$17;
	zend_string *expression = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_zv);
	ZVAL_UNDEF(&php);
	ZVAL_UNDEF(&tokenized);
	ZVAL_UNDEF(&tokens);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("env", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(expression)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&expression_zv);
	ZVAL_STR_COPY(&expression_zv, expression);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 258, &_0);
	ZEPHIR_INIT_VAR(&php);
	if (zephir_start_with_str(&expression_zv, SL("{{"))) {
		ZVAL_LONG(&_2$$3, 2);
		ZVAL_LONG(&_3$$3, -2);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_substr(&_4$$3, &expression_zv, 2 , -2 , 0);
		ZEPHIR_CONCAT_SV(&php, "<?php echo ", &_4$$3);
	} else {
		ZVAL_LONG(&_5$$4, 2);
		ZVAL_LONG(&_6$$4, -2);
		ZEPHIR_INIT_VAR(&_7$$4);
		zephir_substr(&_7$$4, &expression_zv, 2 , -2 , 0);
		ZEPHIR_CONCAT_SV(&php, "<?php ", &_7$$4);
	}
	ZEPHIR_CALL_FUNCTION(&tokenized, "token_get_all", NULL, 189, &php);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&tokens);
	array_init(&tokens);
	ZEPHIR_MAKE_REF(&tokenized);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_8, 2, &tokenized);
	ZEPHIR_UNREF(&tokenized);
	zephir_check_call_status();
	if (Z_TYPE_P(&tokenized) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_1);
		zephir_string_to_char_array(&_1, &tokenized);
		_9 = &_1;
	} else {
		_9 = &tokenized;
	}
	zephir_is_iterable(_9, 0, "ice/mvc/view/engine/sleet/parser.zep", 166);
	if (Z_TYPE_P(_9) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9), _10)
		{
			ZEPHIR_INIT_NVAR(&token);
			ZVAL_COPY(&token, _10);
			_11$$5 = Z_TYPE_P(&token) == IS_ARRAY;
			if (_11$$5) {
				ZEPHIR_OBS_NVAR(&_12$$5);
				zephir_array_fetch_long(&_12$$5, &token, 0, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 160);
				_11$$5 = ZEPHIR_IS_LONG(&_12$$5, 397);
			}
			if (_11$$5) {
				continue;
			}
			zephir_array_append(&tokens, &token, PH_SEPARATE, "ice/mvc/view/engine/sleet/parser.zep", 163);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _9, "rewind", NULL, 0);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _9, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_13, _9, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&token, _9, "current", NULL, 0);
			zephir_check_call_status();
				_15$$7 = Z_TYPE_P(&token) == IS_ARRAY;
				if (_15$$7) {
					ZEPHIR_OBS_NVAR(&_16$$7);
					zephir_array_fetch_long(&_16$$7, &token, 0, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 160);
					_15$$7 = ZEPHIR_IS_LONG(&_16$$7, 397);
				}
				if (_15$$7) {
					continue;
				}
				zephir_array_append(&tokens, &token, PH_SEPARATE, "ice/mvc/view/engine/sleet/parser.zep", 163);
		}
	}
	ZEPHIR_INIT_NVAR(&token);
	ZEPHIR_MAKE_REF(&tokens);
	ZEPHIR_CALL_FUNCTION(&first, "array_shift", &_8, 2, &tokens);
	ZEPHIR_UNREF(&tokens);
	zephir_check_call_status();
	if (Z_TYPE_P(&first) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unexpected first tag", "ice/mvc/view/engine/sleet/parser.zep", 169);
		return;
	}
	if (Z_TYPE_P(&tokens) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unexpected expression", "ice/mvc/view/engine/sleet/parser.zep", 173);
		return;
	}
	zephir_memory_observe(&_17);
	zephir_array_fetch_long(&_17, &first, 0, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 176);
	if (ZEPHIR_IS_LONG(&_17, 290)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&_17, 296)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&_17, 294)) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_LONG(&_17, 303)) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_LONG(&_17, 298)) { goto zephir_switch_0_clause_4; }
	if (ZEPHIR_IS_LONG(&_17, 307)) { goto zephir_switch_0_clause_5; }
	if (ZEPHIR_IS_LONG(&_17, 289)) { goto zephir_switch_0_clause_6; }
	if (ZEPHIR_IS_LONG(&_17, 305)) { goto zephir_switch_0_clause_7; }
	if (ZEPHIR_IS_LONG(&_17, 302)) { goto zephir_switch_0_clause_8; }
	if (ZEPHIR_IS_LONG(&_17, 304)) { goto zephir_switch_0_clause_9; }
	if (ZEPHIR_IS_LONG(&_17, 287)) { goto zephir_switch_0_clause_10; }
	if (ZEPHIR_IS_LONG(&_17, 288)) { goto zephir_switch_0_clause_11; }
	if (ZEPHIR_IS_LONG(&_17, 292)) { goto zephir_switch_0_clause_12; }
	if (ZEPHIR_IS_LONG(&_17, 295)) { goto zephir_switch_0_clause_13; }
	if (ZEPHIR_IS_LONG(&_17, 293)) { goto zephir_switch_0_clause_14; }
	if (ZEPHIR_IS_LONG(&_17, 297)) { goto zephir_switch_0_clause_15; }
	if (ZEPHIR_IS_LONG(&_17, 291)) { goto zephir_switch_0_clause_16; }
	if (ZEPHIR_IS_LONG(&_17, 331)) { goto zephir_switch_0_clause_17; }
	if (ZEPHIR_IS_LONG(&_17, 262)) { goto zephir_switch_0_clause_18; }
	if (ZEPHIR_IS_LONG(&_17, 318)) { goto zephir_switch_0_clause_19; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
	zephir_switch_0_clause_1: ;
	zephir_switch_0_clause_2: ;
	zephir_switch_0_clause_3: ;
	zephir_switch_0_clause_4: ;
		zephir_memory_observe(&_18$$11);
		zephir_array_fetch_long(&_18$$11, &first, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 182);
		ZEPHIR_CONCAT_SVS(return_value, "<?php ", &_18$$11, " ?>");
		RETURN_MM();
	zephir_switch_0_clause_5: ;
		zephir_memory_observe(&_19$$12);
		zephir_array_fetch_long(&_19$$12, &first, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 184);
		ZEPHIR_CONCAT_SVS(return_value, "<?php ", &_19$$12, "; ?>");
		RETURN_MM();
	zephir_switch_0_clause_6: ;
	zephir_switch_0_clause_7: ;
		zephir_memory_observe(&_20$$13);
		zephir_array_fetch_long(&_20$$13, &first, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 187);
		ZEPHIR_CONCAT_SVS(return_value, "<?php ", &_20$$13, ": ?>");
		RETURN_MM();
	zephir_switch_0_clause_8: ;
	zephir_switch_0_clause_9: ;
	zephir_switch_0_clause_10: ;
	zephir_switch_0_clause_11: ;
	zephir_switch_0_clause_12: ;
	zephir_switch_0_clause_13: ;
	zephir_switch_0_clause_14: ;
	zephir_switch_0_clause_15: ;
		zephir_memory_observe(&_21$$14);
		zephir_array_fetch_long(&_21$$14, &first, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 196);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parsecontrol", NULL, 190, &_21$$14, &tokens);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_16: ;
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseecho", NULL, 191, &tokens);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_17: ;
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseset", &_22, 192, &tokens);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_18: ;
		zephir_memory_observe(&_23$$17);
		zephir_array_fetch_long(&_23$$17, &first, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 202);
		if (ZEPHIR_IS_STRING(&_23$$17, "set")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseset", &_22, 192, &tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_19: ;
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseuse", NULL, 193, &tokens);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_end: ;

	RETURN_MM_STRING("");
}

/**
 * Parse control expression.
 *
 * @param string control Control structure
 * @param array expression Tokens
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseControl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *control, control_sub, *expression, expression_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&control_sub);
	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(control)
		Z_PARAM_ZVAL(expression)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &control, &expression);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 194, expression);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<?php ", control, "(", &_0, "): ?>");
	RETURN_MM();
}

/**
 * Parse echo expression.
 *
 * @param array expression Tokens
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseEcho)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expression, expression_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(expression)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expression);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 194, expression);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php echo ", &_0, " ?>");
	RETURN_MM();
}

/**
 * Parse set expression.
 *
 * @param array expression Tokens
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseSet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expression, expression_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(expression)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expression);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 194, expression);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php ", &_0, "; ?>");
	RETURN_MM();
}

/**
 * Parse use expression.
 *
 * @param array expression Tokens
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseUse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expression, expression_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(expression)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expression);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 194, expression);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php use ", &_0, "; ?>");
	RETURN_MM();
}

/**
 * Internal tokens parse.
 *
 * @param array tokens
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, doParse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_18 = NULL, *_24 = NULL, *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tokens, tokens_sub, i, parsed, prev, next, token, filter, seek, filters, _0, _3$$3, _4$$3, _6$$3, _8$$3, _26$$3, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4, _15$$4, _16$$4, _22$$4, _23$$4, _17$$5, _19$$5, _20$$6, _21$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tokens_sub);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&parsed);
	ZVAL_UNDEF(&prev);
	ZVAL_UNDEF(&next);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&seek);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("filters", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(tokens)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &tokens);
	ZEPHIR_INIT_VAR(&i);
	object_init_ex(&i, spl_ce_ArrayIterator);
	ZEPHIR_CALL_METHOD(NULL, &i, "__construct", NULL, 1, tokens);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&parsed);
	ZVAL_STRING(&parsed, "");
	ZEPHIR_INIT_VAR(&prev);
	ZVAL_STRING(&prev, "");
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, &i, "valid", &_1, 195);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&token, &i, "current", &_2, 196);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &i, "key", &_5, 197);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$3, (zephir_get_numberval(&_4$$3) + 1));
		ZEPHIR_CALL_METHOD(&_3$$3, &i, "offsetexists", &_7, 198, &_6$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			ZEPHIR_CALL_METHOD(&_8$$3, &i, "key", &_5, 197);
			zephir_check_call_status();
			ZVAL_LONG(&_6$$3, (zephir_get_numberval(&_8$$3) + 1));
			ZEPHIR_CALL_METHOD(&next, &i, "offsetget", &_9, 199, &_6$$3);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&next);
			ZVAL_NULL(&next);
		}
		if (ZEPHIR_IS_STRING(&next, "|")) {
			ZEPHIR_CALL_METHOD(&_10$$4, &i, "key", &_5, 197);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&seek);
			ZVAL_LONG(&seek, (zephir_get_numberval(&_10$$4) + 2));
			ZEPHIR_CALL_METHOD(&filter, &i, "offsetget", &_9, 199, &seek);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_11$$4);
			zephir_read_property_cached(&_12$$4, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&_13$$4);
			zephir_array_fetch_long(&_13$$4, &filter, 1, 0, "ice/mvc/view/engine/sleet/parser.zep", 278);
			if (zephir_array_isset_value(&_12$$4, &_13$$4)) {
				zephir_read_property_cached(&_14$$4, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_11$$4);
				ZEPHIR_OBS_NVAR(&_15$$4);
				zephir_array_fetch_long(&_15$$4, &filter, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 278);
				zephir_array_fetch(&_11$$4, &_14$$4, &_15$$4, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 278);
			} else {
				ZEPHIR_OBS_NVAR(&_11$$4);
				zephir_array_fetch_long(&_11$$4, &filter, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 278);
			}
			ZEPHIR_CPY_WRT(&filter, &_11$$4);
			ZEPHIR_INIT_NVAR(&filters);
			zephir_create_array(&filters, 17, 0);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "camelize");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "uncamelize");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "human");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "lower");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "upper");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "alnum");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "alpha");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "email");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "float");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "int");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "string");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "strip_repeats");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "e");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "escape");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "strip_special");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "unescape");
			zephir_array_fast_append(&filters, &_16$$4);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "unstrip_special");
			zephir_array_fast_append(&filters, &_16$$4);
			if (zephir_fast_in_array(&filter, &filters)) {
				ZEPHIR_CALL_METHOD(&_17$$5, this_ptr, "token", &_18, 200, &token, &prev, &next);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$5);
				ZEPHIR_CONCAT_SVSVS(&_19$$5, "$this->filter->sanitize(", &_17$$5, ", '", &filter, "'");
				zephir_concat_self(&parsed, &_19$$5);
			} else {
				ZEPHIR_CALL_METHOD(&_20$$6, this_ptr, "token", &_18, 200, &token, &prev, &next);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$6);
				ZEPHIR_CONCAT_VSV(&_21$$6, &filter, "(", &_20$$6);
				zephir_concat_self(&parsed, &_21$$6);
			}
			ZVAL_LONG(&_23$$4, (zephir_get_numberval(&seek) + 1));
			ZEPHIR_CALL_METHOD(&_22$$4, &i, "offsetexists", &_7, 198, &_23$$4);
			zephir_check_call_status();
			if (zephir_is_true(&_22$$4)) {
				ZVAL_LONG(&_23$$4, (zephir_get_numberval(&seek) + 1));
				ZEPHIR_CALL_METHOD(&next, &i, "offsetget", &_9, 199, &_23$$4);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&next);
				ZVAL_NULL(&next);
			}
			if (ZEPHIR_IS_STRING(&next, "(")) {
				zephir_concat_self_str(&parsed, SL(", "));
				SEPARATE_ZVAL(&seek);
				zephir_increment(&seek);
			} else {
				zephir_concat_self_str(&parsed, SL(")"));
			}
			ZEPHIR_CALL_METHOD(NULL, &i, "seek", &_24, 201, &seek);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &i, "next", &_25, 202);
			zephir_check_call_status();
			continue;
		}
		ZEPHIR_CALL_METHOD(&_26$$3, this_ptr, "token", &_18, 200, &token, &prev, &next);
		zephir_check_call_status();
		zephir_concat_self(&parsed, &_26$$3);
		ZEPHIR_CPY_WRT(&prev, &token);
		ZEPHIR_CALL_METHOD(NULL, &i, "next", &_25, 202);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&parsed);
}

/**
 * Internal token parse.
 *
 * @param mixed token
 * @param mixed prev
 * @param mixed next
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, token)
{
	unsigned char _14$$15;
	zend_bool _4$$7, _5$$7, _6$$7, _12$$15, _13$$15, _17$$15;
	zval str, _3$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_22 = NULL, *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *token, token_sub, *prev = NULL, prev_sub, *next = NULL, next_sub, __$null, _0$$3, _1$$4, _2$$7, _7$$7, _8$$8, _9$$8, _10$$8, _11$$10, _15$$15, _16$$15, _18$$17, _19$$23, *_20$$23, _21$$23, _23$$24, *_24$$24, _26$$26, _27$$27, _28$$28, *_29$$28, _30$$28, _31$$29, *_32$$29;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token_sub);
	ZVAL_UNDEF(&prev_sub);
	ZVAL_UNDEF(&next_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$23);
	ZVAL_UNDEF(&_21$$23);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&_26$$26);
	ZVAL_UNDEF(&_27$$27);
	ZVAL_UNDEF(&_28$$28);
	ZVAL_UNDEF(&_30$$28);
	ZVAL_UNDEF(&_31$$29);
	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_3$$7);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("functions", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("env", 3, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(token)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(prev)
		Z_PARAM_ZVAL_OR_NULL(next)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &token, &prev, &next);
	if (!prev) {
		prev = &prev_sub;
		prev = &__$null;
	}
	if (!next) {
		next = &next_sub;
		next = &__$null;
	}
	if (Z_TYPE_P(token) == IS_ARRAY) {
		zephir_memory_observe(&_0$$3);
		zephir_array_fetch_long(&_0$$3, token, 0, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 322);
		if (ZEPHIR_IS_LONG(&_0$$3, 301)) { goto zephir_switch_0_clause_0; }
		if (ZEPHIR_IS_LONG(&_0$$3, 284)) { goto zephir_switch_0_clause_1; }
		if (ZEPHIR_IS_LONG(&_0$$3, 283)) { goto zephir_switch_0_clause_2; }
		if (ZEPHIR_IS_LONG(&_0$$3, 370)) { goto zephir_switch_0_clause_3; }
		if (ZEPHIR_IS_LONG(&_0$$3, 371)) { goto zephir_switch_0_clause_4; }
		if (ZEPHIR_IS_LONG(&_0$$3, 372)) { goto zephir_switch_0_clause_5; }
		if (ZEPHIR_IS_LONG(&_0$$3, 373)) { goto zephir_switch_0_clause_6; }
		if (ZEPHIR_IS_LONG(&_0$$3, 374)) { goto zephir_switch_0_clause_7; }
		if (ZEPHIR_IS_LONG(&_0$$3, 375)) { goto zephir_switch_0_clause_8; }
		if (ZEPHIR_IS_LONG(&_0$$3, 277)) { goto zephir_switch_0_clause_9; }
		if (ZEPHIR_IS_LONG(&_0$$3, 279)) { goto zephir_switch_0_clause_10; }
		if (ZEPHIR_IS_LONG(&_0$$3, 262)) { goto zephir_switch_0_clause_11; }
		goto zephir_switch_0_clause_12;
		zephir_switch_0_clause_0: ;
		zephir_switch_0_clause_1: ;
		zephir_switch_0_clause_2: ;
		zephir_switch_0_clause_3: ;
		zephir_switch_0_clause_4: ;
		zephir_switch_0_clause_5: ;
		zephir_switch_0_clause_6: ;
		zephir_switch_0_clause_7: ;
		zephir_switch_0_clause_8: ;
			zephir_memory_observe(&_1$$4);
			zephir_array_fetch_long(&_1$$4, token, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 332);
			ZEPHIR_CONCAT_SVS(return_value, " ", &_1$$4, " ");
			RETURN_MM();
		zephir_switch_0_clause_9: ;
			RETURN_MM_STRING(" || ");
		zephir_switch_0_clause_10: ;
			RETURN_MM_STRING(" && ");
		zephir_switch_0_clause_11: ;
			zephir_memory_observe(&_2$$7);
			zephir_array_fetch_long(&_2$$7, token, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 338);
			zephir_cast_to_string(&_3$$7, &_2$$7);
			ZEPHIR_CPY_WRT(&str, &_3$$7);
			_4$$7 = ZEPHIR_IS_STRING(next, "(");
			if (_4$$7) {
				_5$$7 = !ZEPHIR_IS_STRING(prev, ".");
				if (!(_5$$7)) {
					_6$$7 = Z_TYPE_P(prev) == IS_ARRAY;
					if (_6$$7) {
						zephir_memory_observe(&_7$$7);
						zephir_array_fetch_long(&_7$$7, prev, 0, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 340);
						_6$$7 = !ZEPHIR_IS_LONG(&_7$$7, 402);
					}
					_5$$7 = _6$$7;
				}
				_4$$7 = _5$$7;
			}
			if (_4$$7) {
				ZEPHIR_INIT_VAR(&_8$$8);
				zephir_read_property_cached(&_9$$8, this_ptr, _zephir_prop_0, 257, PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset_value(&_9$$8, &str)) {
					zephir_read_property_cached(&_10$$8, this_ptr, _zephir_prop_0, 257, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_8$$8);
					zephir_array_fetch(&_8$$8, &_10$$8, &str, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 341);
				} else {
					ZEPHIR_CPY_WRT(&_8$$8, &str);
				}
				RETURN_CCTOR(&_8$$8);
			}
			if (ZEPHIR_IS_STRING(&str, "in")) { goto zephir_switch_1_clause_0; }
			if (ZEPHIR_IS_STRING(&str, "is")) { goto zephir_switch_1_clause_1; }
			if (ZEPHIR_IS_STRING(&str, "and")) { goto zephir_switch_1_clause_2; }
			if (ZEPHIR_IS_STRING(&str, "or")) { goto zephir_switch_1_clause_3; }
			if (ZEPHIR_IS_STRING(&str, "not")) { goto zephir_switch_1_clause_4; }
			if (ZEPHIR_IS_STRING(&str, "false")) { goto zephir_switch_1_clause_5; }
			if (ZEPHIR_IS_STRING(&str, "true")) { goto zephir_switch_1_clause_6; }
			if (ZEPHIR_IS_STRING(&str, "null")) { goto zephir_switch_1_clause_7; }
			goto zephir_switch_1_clause_8;
			zephir_switch_1_clause_0: ;
				RETURN_MM_STRING(" as ");
			zephir_switch_1_clause_1: ;
				ZEPHIR_INIT_VAR(&_11$$10);
				if (ZEPHIR_IS_STRING(next, "!")) {
					ZEPHIR_INIT_NVAR(&_11$$10);
					ZVAL_STRING(&_11$$10, " != ");
				} else {
					ZEPHIR_INIT_NVAR(&_11$$10);
					ZVAL_STRING(&_11$$10, " == ");
				}
				RETURN_CCTOR(&_11$$10);
			zephir_switch_1_clause_2: ;
				RETURN_MM_STRING(" && ");
			zephir_switch_1_clause_3: ;
				RETURN_MM_STRING(" || ");
			zephir_switch_1_clause_4: ;
				RETURN_MM_STRING("!");
			zephir_switch_1_clause_5: ;
			zephir_switch_1_clause_6: ;
			zephir_switch_1_clause_7: ;
				RETURN_CTOR(&str);
			zephir_switch_1_clause_8: ;
				_12$$15 = ZEPHIR_IS_STRING(prev, ".");
				if (!(_12$$15)) {
					_12$$15 = ZEPHIR_IS_STRING(next, "(");
				}
				_13$$15 = _12$$15;
				if (!(_13$$15)) {
					ZEPHIR_INIT_VAR(&_15$$15);
					zephir_string_offset_read(&_15$$15, &str, 0, PH_NOISY);
					ZEPHIR_CALL_FUNCTION(&_16$$15, "ctype_upper", NULL, 203, &_15$$15);
					zephir_check_call_status();
					_17$$15 = zephir_is_true(&_16$$15);
					if (_17$$15) {
						_17$$15 = !ZEPHIR_IS_STRING(next, "|");
					}
					_13$$15 = _17$$15;
				}
				if (_13$$15) {
					RETURN_CTOR(&str);
				}
				ZEPHIR_CONCAT_SV(return_value, "$", &str);
				RETURN_MM();

		zephir_switch_0_clause_12: ;
			zephir_memory_observe(&_18$$17);
			zephir_array_fetch_long(&_18$$17, token, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 365);
			RETURN_CCTOR(&_18$$17);

	} else {
		if (ZEPHIR_IS_STRING(token, "-")) { goto zephir_switch_2_clause_0; }
		if (ZEPHIR_IS_STRING(token, "+")) { goto zephir_switch_2_clause_1; }
		if (ZEPHIR_IS_STRING(token, "*")) { goto zephir_switch_2_clause_2; }
		if (ZEPHIR_IS_STRING(token, "/")) { goto zephir_switch_2_clause_3; }
		if (ZEPHIR_IS_STRING(token, "%")) { goto zephir_switch_2_clause_4; }
		if (ZEPHIR_IS_STRING(token, "=")) { goto zephir_switch_2_clause_5; }
		if (ZEPHIR_IS_STRING(token, ">")) { goto zephir_switch_2_clause_6; }
		if (ZEPHIR_IS_STRING(token, "<")) { goto zephir_switch_2_clause_7; }
		if (ZEPHIR_IS_STRING(token, "~")) { goto zephir_switch_2_clause_8; }
		if (ZEPHIR_IS_STRING(token, ",")) { goto zephir_switch_2_clause_9; }
		if (ZEPHIR_IS_STRING(token, ".")) { goto zephir_switch_2_clause_10; }
		if (ZEPHIR_IS_STRING(token, ":")) { goto zephir_switch_2_clause_11; }
		if (ZEPHIR_IS_STRING(token, "?")) { goto zephir_switch_2_clause_12; }
		if (ZEPHIR_IS_STRING(token, "[")) { goto zephir_switch_2_clause_13; }
		if (ZEPHIR_IS_STRING(token, "]")) { goto zephir_switch_2_clause_14; }
		goto zephir_switch_2_clause_15;
		zephir_switch_2_clause_0: ;
		zephir_switch_2_clause_1: ;
		zephir_switch_2_clause_2: ;
		zephir_switch_2_clause_3: ;
		zephir_switch_2_clause_4: ;
		zephir_switch_2_clause_5: ;
		zephir_switch_2_clause_6: ;
		zephir_switch_2_clause_7: ;
			ZEPHIR_CONCAT_SVS(return_value, " ", token, " ");
			RETURN_MM();
		zephir_switch_2_clause_8: ;
			RETURN_MM_STRING(" . ");
		zephir_switch_2_clause_9: ;
			RETURN_MM_STRING(", ");
		zephir_switch_2_clause_10: ;
			RETURN_MM_STRING("->");
		zephir_switch_2_clause_11: ;
			zephir_memory_observe(&_19$$23);
			_20$$23 = zephir_fetch_property_write(this_ptr, _zephir_prop_1, &_19$$23);
			ZEPHIR_MAKE_WRITE_REF(_20$$23);
			ZEPHIR_CALL_FUNCTION(&_21$$23, "end", &_22, 204, _20$$23);
			ZEPHIR_UNREF_WRITE(_20$$23);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&_21$$23, 1)) { goto zephir_switch_3_clause_0; }
			goto zephir_switch_3_clause_1;
			zephir_switch_3_clause_0: ;
				zephir_memory_observe(&_23$$24);
				_24$$24 = zephir_fetch_property_write(this_ptr, _zephir_prop_1, &_23$$24);
				ZEPHIR_MAKE_WRITE_REF(_24$$24);
				ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_25, 205, _24$$24);
				ZEPHIR_UNREF_WRITE(_24$$24);
				zephir_check_call_status();
				RETURN_MM_STRING(" : ");
			zephir_switch_3_clause_1: ;
				RETURN_MM_STRING(" => ");

		zephir_switch_2_clause_12: ;
			ZVAL_UNDEF(&_26$$26);
			ZVAL_LONG(&_26$$26, 1);
			zephir_update_property_array_append(this_ptr, SL("env"), &_26$$26);
			RETURN_MM_STRING(" ? ");
		zephir_switch_2_clause_13: ;
			ZVAL_UNDEF(&_27$$27);
			ZVAL_LONG(&_27$$27, 2);
			zephir_update_property_array_append(this_ptr, SL("env"), &_27$$27);
			RETVAL_ZVAL(token, 1, 0);
			RETURN_MM();
		zephir_switch_2_clause_14: ;
			zephir_memory_observe(&_28$$28);
			_29$$28 = zephir_fetch_property_write(this_ptr, _zephir_prop_1, &_28$$28);
			ZEPHIR_MAKE_WRITE_REF(_29$$28);
			ZEPHIR_CALL_FUNCTION(&_30$$28, "end", &_22, 204, _29$$28);
			ZEPHIR_UNREF_WRITE(_29$$28);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&_30$$28, 2)) {
				zephir_memory_observe(&_31$$29);
				_32$$29 = zephir_fetch_property_write(this_ptr, _zephir_prop_1, &_31$$29);
				ZEPHIR_MAKE_WRITE_REF(_32$$29);
				ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_25, 205, _32$$29);
				ZEPHIR_UNREF_WRITE(_32$$29);
				zephir_check_call_status();
			}
			RETVAL_ZVAL(token, 1, 0);
			RETURN_MM();
		zephir_switch_2_clause_15: ;
			RETVAL_ZVAL(token, 1, 0);
			RETURN_MM();

	}
}

zend_object *zephir_init_properties_Ice_Mvc_View_Engine_Sleet_Parser(zend_class_entry *class_type)
{
		zval _3$$4, _5$$5;
	zval _0, _2, _4, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("env"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("env"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0);
			add_assoc_stringl_ex(&_3$$4, SL("capitalize"), SL("ucfirst"));
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("filters"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("functions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_create_array(&_5$$5, 5, 0);
			add_assoc_stringl_ex(&_5$$5, SL("content"), SL("$this->getContent"));
			add_assoc_stringl_ex(&_5$$5, SL("partial"), SL("$this->partial"));
			add_assoc_stringl_ex(&_5$$5, SL("load"), SL("$this->load"));
			add_assoc_stringl_ex(&_5$$5, SL("dump"), SL("$this->dump->vars"));
			add_assoc_stringl_ex(&_5$$5, SL("version"), SL("Ice\\Version::get"));
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("functions"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

