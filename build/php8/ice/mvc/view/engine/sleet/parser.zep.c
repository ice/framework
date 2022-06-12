
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
#include "ext/spl/spl_array.h"


/**
 * Sleet file parser.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
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
	zval tag, methods, functions, method, _0, _1, *_2, _3, _20, _4$$3, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5, _12$$6, _13$$8, _14$$8, _15$$8, _16$$8, _17$$8, _18$$8, _19$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&functions);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tag);
	object_init_ex(&tag, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Ice\\Tag");
	ZEPHIR_CALL_METHOD(NULL, &tag, "__construct", NULL, 102, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD(&methods, &tag, "getmethods", NULL, 185, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&functions);
	array_init(&functions);
	zephir_is_iterable(&methods, 0, "ice/mvc/view/engine/sleet/parser.zep", 56);
	if (Z_TYPE_P(&methods) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _2)
		{
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_COPY(&method, _2);
			zephir_read_property(&_4$$3, &method, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
			do {
				if (ZEPHIR_IS_STRING(&_4$$3, "__construct")) {
					continue;
				}
				zephir_read_property(&_5$$5, &method, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZEPHIR_CONCAT_SV(&_6$$5, "$this->tag->", &_5$$5);
				ZEPHIR_OBS_NVAR(&_7$$5);
				zephir_read_property(&_7$$5, &method, ZEND_STRL("name"), PH_NOISY_CC);
				zephir_array_update_zval(&functions, &_7$$5, &_6$$5, PH_COPY | PH_SEPARATE);
				zephir_read_property(&_8$$5, &method, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZEPHIR_CONCAT_SV(&_9$$5, "$this->tag->", &_8$$5);
				ZEPHIR_INIT_NVAR(&_10$$5);
				zephir_read_property(&_11$$5, &method, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
				zephir_uncamelize(&_10$$5, &_11$$5, NULL  );
				zephir_array_update_zval(&functions, &_10$$5, &_9$$5, PH_COPY | PH_SEPARATE);
			} while(0);

		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &methods, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &methods, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_12$$6, &method, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
				do {
					if (ZEPHIR_IS_STRING(&_12$$6, "__construct")) {
						continue;
					}
					zephir_read_property(&_13$$8, &method, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZEPHIR_CONCAT_SV(&_14$$8, "$this->tag->", &_13$$8);
					ZEPHIR_OBS_NVAR(&_15$$8);
					zephir_read_property(&_15$$8, &method, ZEND_STRL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&functions, &_15$$8, &_14$$8, PH_COPY | PH_SEPARATE);
					zephir_read_property(&_16$$8, &method, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_17$$8);
					ZEPHIR_CONCAT_SV(&_17$$8, "$this->tag->", &_16$$8);
					ZEPHIR_INIT_NVAR(&_18$$8);
					zephir_read_property(&_19$$8, &method, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
					zephir_uncamelize(&_18$$8, &_19$$8, NULL  );
					zephir_array_update_zval(&functions, &_18$$8, &_17$$8, PH_COPY | PH_SEPARATE);
				} while(0);

			ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("functions"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &functions);
	zephir_update_property_zval(this_ptr, ZEND_STRL("functions"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_20);
	ZVAL_LONG(&_20, 0);
	zephir_update_property_array_append(this_ptr, SL("env"), &_20);
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
	unsigned char _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, _18$$4, _37$$6, _55$$8;
	zephir_fcall_cache_entry *_12 = NULL, *_16 = NULL, *_17 = NULL, *_23 = NULL;
	zval *text_param = NULL, pos, start, parsedText, end, ch, _0, _60, _59$$3, _2$$4, _3$$4, _4$$4, _5$$4, _6$$4, _19$$4, _20$$4, _21$$4, _22$$4, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5, _13$$5, _14$$5, _15$$5, _24$$6, _25$$6, _26$$6, _27$$6, _28$$6, _38$$6, _39$$6, _40$$6, _41$$6, _29$$7, _30$$7, _31$$7, _32$$7, _33$$7, _34$$7, _35$$7, _36$$7, _42$$8, _43$$8, _44$$8, _45$$8, _46$$8, _47$$9, _48$$9, _49$$9, _50$$9, _51$$9, _52$$9, _53$$9, _54$$9, _56$$10, _57$$10, _58$$10;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&parsedText);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_60);
	ZVAL_UNDEF(&_59$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_38$$6);
	ZVAL_UNDEF(&_39$$6);
	ZVAL_UNDEF(&_40$$6);
	ZVAL_UNDEF(&_41$$6);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_36$$7);
	ZVAL_UNDEF(&_42$$8);
	ZVAL_UNDEF(&_43$$8);
	ZVAL_UNDEF(&_44$$8);
	ZVAL_UNDEF(&_45$$8);
	ZVAL_UNDEF(&_46$$8);
	ZVAL_UNDEF(&_47$$9);
	ZVAL_UNDEF(&_48$$9);
	ZVAL_UNDEF(&_49$$9);
	ZVAL_UNDEF(&_50$$9);
	ZVAL_UNDEF(&_51$$9);
	ZVAL_UNDEF(&_52$$9);
	ZVAL_UNDEF(&_53$$9);
	ZVAL_UNDEF(&_54$$9);
	ZVAL_UNDEF(&_56$$10);
	ZVAL_UNDEF(&_57$$10);
	ZVAL_UNDEF(&_58$$10);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);
	zephir_get_strval(&text, text_param);


	ZEPHIR_INIT_VAR(&pos);
	ZVAL_LONG(&pos, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "{");
	ZEPHIR_INIT_VAR(&start);
	zephir_fast_strpos(&start, &text, &_0, 0 );
	ZEPHIR_INIT_VAR(&parsedText);
	ZVAL_STRING(&parsedText, "");
	while (1) {
		if (!(!ZEPHIR_IS_FALSE_IDENTICAL(&start))) {
			break;
		}
		i = (zephir_get_numberval(&start) + 1);
		_1$$3 = ZEPHIR_STRING_OFFSET(&text, i);
		ZEPHIR_INIT_NVAR(&ch);
		ZVAL_LONG(&ch, _1$$3);
		do {
			if (ZEPHIR_IS_LONG(&ch, '{')) {
				ZEPHIR_INIT_NVAR(&_2$$4);
				zephir_sub_function(&_2$$4, &start, &pos);
				ZVAL_LONG(&_3$$4, zephir_get_intval(&_2$$4));
				ZEPHIR_INIT_NVAR(&_4$$4);
				zephir_substr(&_4$$4, &text, zephir_get_intval(&pos), zephir_get_intval(&_3$$4), 0);
				zephir_concat_self(&parsedText, &_4$$4);
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZVAL_STRING(&_5$$4, "}}");
				ZVAL_LONG(&_6$$4, (zephir_get_numberval(&start) + 2));
				ZEPHIR_INIT_NVAR(&end);
				zephir_fast_strpos(&end, &text, &_5$$4, zephir_get_intval(&_6$$4) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(&end)) {
					ZEPHIR_INIT_NVAR(&_7$$5);
					object_init_ex(&_7$$5, ice_exception_ce);
					ZVAL_LONG(&_8$$5, 0);
					ZEPHIR_INIT_NVAR(&_9$$5);
					zephir_substr(&_9$$5, &text, 0 , zephir_get_intval(&start), 0);
					ZEPHIR_INIT_NVAR(&_10$$5);
					ZEPHIR_GET_CONSTANT(&_10$$5, "PHP_EOL");
					ZEPHIR_CALL_FUNCTION(&_11$$5, "substr_count", &_12, 186, &_9$$5, &_10$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_13$$5);
					ZVAL_STRING(&_13$$5, "Unclosed echo on the line %d");
					ZVAL_LONG(&_14$$5, (zephir_get_numberval(&_11$$5) + 1));
					ZEPHIR_CALL_FUNCTION(&_15$$5, "sprintf", &_16, 11, &_13$$5, &_14$$5);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", &_17, 12, &_15$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$5, "ice/mvc/view/engine/sleet/parser.zep", 87);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_18$$4 = (zephir_get_numberval(&end) + 2);
				ZEPHIR_INIT_NVAR(&end);
				ZVAL_LONG(&end, _18$$4);
				ZEPHIR_INIT_NVAR(&_20$$4);
				zephir_sub_function(&_20$$4, &end, &start);
				ZVAL_LONG(&_21$$4, zephir_get_intval(&_20$$4));
				ZEPHIR_INIT_NVAR(&_22$$4);
				zephir_substr(&_22$$4, &text, zephir_get_intval(&start), zephir_get_intval(&_21$$4), 0);
				ZEPHIR_CALL_METHOD(&_19$$4, this_ptr, "parse", &_23, 0, &_22$$4);
				zephir_check_call_status();
				zephir_concat_self(&parsedText, &_19$$4);
				break;
			}
			if (ZEPHIR_IS_LONG(&ch, '%')) {
				ZEPHIR_INIT_NVAR(&_24$$6);
				zephir_sub_function(&_24$$6, &start, &pos);
				ZVAL_LONG(&_25$$6, zephir_get_intval(&_24$$6));
				ZEPHIR_INIT_NVAR(&_26$$6);
				zephir_substr(&_26$$6, &text, zephir_get_intval(&pos), zephir_get_intval(&_25$$6), 0);
				zephir_concat_self(&parsedText, &_26$$6);
				ZEPHIR_INIT_NVAR(&_27$$6);
				ZVAL_STRING(&_27$$6, "%}");
				ZVAL_LONG(&_28$$6, (zephir_get_numberval(&start) + 2));
				ZEPHIR_INIT_NVAR(&end);
				zephir_fast_strpos(&end, &text, &_27$$6, zephir_get_intval(&_28$$6) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(&end)) {
					ZEPHIR_INIT_NVAR(&_29$$7);
					object_init_ex(&_29$$7, ice_exception_ce);
					ZVAL_LONG(&_30$$7, 0);
					ZEPHIR_INIT_NVAR(&_31$$7);
					zephir_substr(&_31$$7, &text, 0 , zephir_get_intval(&start), 0);
					ZEPHIR_INIT_NVAR(&_32$$7);
					ZEPHIR_GET_CONSTANT(&_32$$7, "PHP_EOL");
					ZEPHIR_CALL_FUNCTION(&_33$$7, "substr_count", &_12, 186, &_31$$7, &_32$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_34$$7);
					ZVAL_STRING(&_34$$7, "Unclosed tag on the line %d");
					ZVAL_LONG(&_35$$7, (zephir_get_numberval(&_33$$7) + 1));
					ZEPHIR_CALL_FUNCTION(&_36$$7, "sprintf", &_16, 11, &_34$$7, &_35$$7);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_29$$7, "__construct", &_17, 12, &_36$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_29$$7, "ice/mvc/view/engine/sleet/parser.zep", 100);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_37$$6 = (zephir_get_numberval(&end) + 2);
				ZEPHIR_INIT_NVAR(&end);
				ZVAL_LONG(&end, _37$$6);
				ZEPHIR_INIT_NVAR(&_39$$6);
				zephir_sub_function(&_39$$6, &end, &start);
				ZVAL_LONG(&_40$$6, zephir_get_intval(&_39$$6));
				ZEPHIR_INIT_NVAR(&_41$$6);
				zephir_substr(&_41$$6, &text, zephir_get_intval(&start), zephir_get_intval(&_40$$6), 0);
				ZEPHIR_CALL_METHOD(&_38$$6, this_ptr, "parse", &_23, 0, &_41$$6);
				zephir_check_call_status();
				zephir_concat_self(&parsedText, &_38$$6);
				break;
			}
			if (ZEPHIR_IS_LONG(&ch, '#')) {
				ZEPHIR_INIT_NVAR(&_42$$8);
				zephir_sub_function(&_42$$8, &start, &pos);
				ZVAL_LONG(&_43$$8, zephir_get_intval(&_42$$8));
				ZEPHIR_INIT_NVAR(&_44$$8);
				zephir_substr(&_44$$8, &text, zephir_get_intval(&pos), zephir_get_intval(&_43$$8), 0);
				zephir_concat_self(&parsedText, &_44$$8);
				ZEPHIR_INIT_NVAR(&_45$$8);
				ZVAL_STRING(&_45$$8, "#}");
				ZVAL_LONG(&_46$$8, (zephir_get_numberval(&start) + 2));
				ZEPHIR_INIT_NVAR(&end);
				zephir_fast_strpos(&end, &text, &_45$$8, zephir_get_intval(&_46$$8) );
				if (ZEPHIR_IS_FALSE_IDENTICAL(&end)) {
					ZEPHIR_INIT_NVAR(&_47$$9);
					object_init_ex(&_47$$9, ice_exception_ce);
					ZVAL_LONG(&_48$$9, 0);
					ZEPHIR_INIT_NVAR(&_49$$9);
					zephir_substr(&_49$$9, &text, 0 , zephir_get_intval(&start), 0);
					ZEPHIR_INIT_NVAR(&_50$$9);
					ZEPHIR_GET_CONSTANT(&_50$$9, "PHP_EOL");
					ZEPHIR_CALL_FUNCTION(&_51$$9, "substr_count", &_12, 186, &_49$$9, &_50$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_52$$9);
					ZVAL_STRING(&_52$$9, "Unclosed comment block on the line %d");
					ZVAL_LONG(&_53$$9, (zephir_get_numberval(&_51$$9) + 1));
					ZEPHIR_CALL_FUNCTION(&_54$$9, "sprintf", &_16, 11, &_52$$9, &_53$$9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_47$$9, "__construct", &_17, 12, &_54$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_47$$9, "ice/mvc/view/engine/sleet/parser.zep", 113);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_55$$8 = (zephir_get_numberval(&end) + 2);
				ZEPHIR_INIT_NVAR(&end);
				ZVAL_LONG(&end, _55$$8);
				break;
			}
			ZEPHIR_INIT_NVAR(&_56$$10);
			zephir_sub_function(&_56$$10, &start, &pos);
			ZVAL_LONG(&_57$$10, (zephir_get_numberval(&_56$$10) + 1));
			ZEPHIR_INIT_NVAR(&_58$$10);
			zephir_substr(&_58$$10, &text, zephir_get_intval(&pos), zephir_get_intval(&_57$$10), 0);
			zephir_concat_self(&parsedText, &_58$$10);
			ZEPHIR_INIT_NVAR(&end);
			ZVAL_LONG(&end, (zephir_get_numberval(&start) + 1));
			break;
		} while(0);

		ZEPHIR_CPY_WRT(&pos, &end);
		ZEPHIR_INIT_NVAR(&_59$$3);
		ZVAL_STRING(&_59$$3, "{");
		ZEPHIR_INIT_NVAR(&start);
		zephir_fast_strpos(&start, &text, &_59$$3, zephir_get_intval(&pos) );
	}
	ZEPHIR_INIT_VAR(&_60);
	zephir_substr(&_60, &text, zephir_get_intval(&pos), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_concat_self(&parsedText, &_60);
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
	zend_bool _9$$5, _11$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expression_param = NULL, php, tokenized, tokens, token, first, *_7, _8, _13, _0$$3, _1$$3, _2$$3, _3$$4, _4$$4, _5$$4, _10$$5, _12$$7, _14$$11, _15$$12, _16$$13, _17$$14, _19$$17;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&php);
	ZVAL_UNDEF(&tokenized);
	ZVAL_UNDEF(&tokens);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_19$$17);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(expression)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression_param);
	zephir_get_strval(&expression, expression_param);


	ZEPHIR_INIT_VAR(&php);
	if (zephir_start_with_str(&expression, SL("{{"))) {
		ZVAL_LONG(&_0$$3, 2);
		ZVAL_LONG(&_1$$3, -2);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_substr(&_2$$3, &expression, 2 , -2 , 0);
		ZEPHIR_CONCAT_SV(&php, "<?php echo ", &_2$$3);
	} else {
		ZVAL_LONG(&_3$$4, 2);
		ZVAL_LONG(&_4$$4, -2);
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_substr(&_5$$4, &expression, 2 , -2 , 0);
		ZEPHIR_CONCAT_SV(&php, "<?php ", &_5$$4);
	}
	ZEPHIR_CALL_FUNCTION(&tokenized, "token_get_all", NULL, 187, &php);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&tokens);
	array_init(&tokens);
	ZEPHIR_MAKE_REF(&tokenized);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_6, 2, &tokenized);
	ZEPHIR_UNREF(&tokenized);
	zephir_check_call_status();
	zephir_is_iterable(&tokenized, 0, "ice/mvc/view/engine/sleet/parser.zep", 162);
	if (Z_TYPE_P(&tokenized) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tokenized), _7)
		{
			ZEPHIR_INIT_NVAR(&token);
			ZVAL_COPY(&token, _7);
			_9$$5 = Z_TYPE_P(&token) == IS_ARRAY;
			if (_9$$5) {
				zephir_array_fetch_long(&_10$$5, &token, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 156);
				_9$$5 = ZEPHIR_IS_LONG(&_10$$5, 392);
			}
			if (_9$$5) {
				continue;
			}
			zephir_array_append(&tokens, &token, PH_SEPARATE, "ice/mvc/view/engine/sleet/parser.zep", 159);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &tokenized, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &tokenized, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&token, &tokenized, "current", NULL, 0);
			zephir_check_call_status();
				_11$$7 = Z_TYPE_P(&token) == IS_ARRAY;
				if (_11$$7) {
					zephir_array_fetch_long(&_12$$7, &token, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 156);
					_11$$7 = ZEPHIR_IS_LONG(&_12$$7, 392);
				}
				if (_11$$7) {
					continue;
				}
				zephir_array_append(&tokens, &token, PH_SEPARATE, "ice/mvc/view/engine/sleet/parser.zep", 159);
			ZEPHIR_CALL_METHOD(NULL, &tokenized, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&token);
	ZEPHIR_MAKE_REF(&tokens);
	ZEPHIR_CALL_FUNCTION(&first, "array_shift", &_6, 2, &tokens);
	ZEPHIR_UNREF(&tokens);
	zephir_check_call_status();
	if (Z_TYPE_P(&first) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unexpected first tag", "ice/mvc/view/engine/sleet/parser.zep", 165);
		return;
	}
	if (Z_TYPE_P(&tokens) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Unexpected expression", "ice/mvc/view/engine/sleet/parser.zep", 169);
		return;
	}
	zephir_array_fetch_long(&_13, &first, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 172);
	do {
		if (ZEPHIR_IS_LONG(&_13, 290) || ZEPHIR_IS_LONG(&_13, 296) || ZEPHIR_IS_LONG(&_13, 294) || ZEPHIR_IS_LONG(&_13, 303) || ZEPHIR_IS_LONG(&_13, 298)) {
			zephir_array_fetch_long(&_14$$11, &first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 178);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", &_14$$11, " ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_13, 307)) {
			zephir_array_fetch_long(&_15$$12, &first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 180);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", &_15$$12, "; ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_13, 289) || ZEPHIR_IS_LONG(&_13, 305)) {
			zephir_array_fetch_long(&_16$$13, &first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 183);
			ZEPHIR_CONCAT_SVS(return_value, "<?php ", &_16$$13, ": ?>");
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_13, 302) || ZEPHIR_IS_LONG(&_13, 304) || ZEPHIR_IS_LONG(&_13, 287) || ZEPHIR_IS_LONG(&_13, 288) || ZEPHIR_IS_LONG(&_13, 292) || ZEPHIR_IS_LONG(&_13, 295) || ZEPHIR_IS_LONG(&_13, 293) || ZEPHIR_IS_LONG(&_13, 297)) {
			zephir_array_fetch_long(&_17$$14, &first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 192);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parsecontrol", NULL, 188, &_17$$14, &tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_13, 291)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseecho", NULL, 189, &tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_13, 328)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseset", &_18, 190, &tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_13, 262)) {
			zephir_array_fetch_long(&_19$$17, &first, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 198);
			if (ZEPHIR_IS_STRING(&_19$$17, "set")) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseset", &_18, 190, &tokens);
				zephir_check_call_status();
				RETURN_MM();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&_13, 318)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseuse", NULL, 191, &tokens);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(control)
		Z_PARAM_ZVAL(expression)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &control, &expression);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 192, expression);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(expression)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 192, expression);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(expression)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 192, expression);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(expression)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "doparse", NULL, 192, expression);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(tokens)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
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
		ZEPHIR_CALL_METHOD(&_0, &i, "valid", &_1, 193);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&token, &i, "current", &_2, 194);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &i, "key", &_5, 195);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$3, (zephir_get_numberval(&_4$$3) + 1));
		ZEPHIR_CALL_METHOD(&_3$$3, &i, "offsetexists", &_7, 196, &_6$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			ZEPHIR_CALL_METHOD(&_8$$3, &i, "key", &_5, 195);
			zephir_check_call_status();
			ZVAL_LONG(&_6$$3, (zephir_get_numberval(&_8$$3) + 1));
			ZEPHIR_CALL_METHOD(&next, &i, "offsetget", &_9, 197, &_6$$3);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&next);
			ZVAL_NULL(&next);
		}
		if (ZEPHIR_IS_STRING(&next, "|")) {
			ZEPHIR_CALL_METHOD(&_10$$4, &i, "key", &_5, 195);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&seek);
			ZVAL_LONG(&seek, (zephir_get_numberval(&_10$$4) + 2));
			ZEPHIR_CALL_METHOD(&filter, &i, "offsetget", &_9, 197, &seek);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_11$$4);
			zephir_read_property(&_12$$4, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_long(&_13$$4, &filter, 1, PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 274);
			if (zephir_array_isset(&_12$$4, &_13$$4)) {
				zephir_read_property(&_14$$4, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_11$$4);
				ZEPHIR_OBS_NVAR(&_15$$4);
				zephir_array_fetch_long(&_15$$4, &filter, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 274);
				zephir_array_fetch(&_11$$4, &_14$$4, &_15$$4, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 274);
			} else {
				ZEPHIR_OBS_NVAR(&_11$$4);
				zephir_array_fetch_long(&_11$$4, &filter, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 274);
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
				ZEPHIR_CALL_METHOD(&_17$$5, this_ptr, "token", &_18, 198, &token, &prev, &next);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$5);
				ZEPHIR_CONCAT_SVSVS(&_19$$5, "$this->filter->sanitize(", &_17$$5, ", '", &filter, "'");
				zephir_concat_self(&parsed, &_19$$5);
			} else {
				ZEPHIR_CALL_METHOD(&_20$$6, this_ptr, "token", &_18, 198, &token, &prev, &next);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$6);
				ZEPHIR_CONCAT_VSV(&_21$$6, &filter, "(", &_20$$6);
				zephir_concat_self(&parsed, &_21$$6);
			}
			ZVAL_LONG(&_23$$4, (zephir_get_numberval(&seek) + 1));
			ZEPHIR_CALL_METHOD(&_22$$4, &i, "offsetexists", &_7, 196, &_23$$4);
			zephir_check_call_status();
			if (zephir_is_true(&_22$$4)) {
				ZVAL_LONG(&_23$$4, (zephir_get_numberval(&seek) + 1));
				ZEPHIR_CALL_METHOD(&next, &i, "offsetget", &_9, 197, &_23$$4);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&next);
				ZVAL_NULL(&next);
			}
			if (ZEPHIR_IS_STRING(&next, "(")) {
				zephir_concat_self_str(&parsed, SL(", "));
				ZEPHIR_SEPARATE(&seek);
				zephir_increment(&seek);
			} else {
				zephir_concat_self_str(&parsed, SL(")"));
			}
			ZEPHIR_CALL_METHOD(NULL, &i, "seek", &_24, 199, &seek);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &i, "next", &_25, 200);
			zephir_check_call_status();
			continue;
		}
		ZEPHIR_CALL_METHOD(&_26$$3, this_ptr, "token", &_18, 198, &token, &prev, &next);
		zephir_check_call_status();
		zephir_concat_self(&parsed, &_26$$3);
		ZEPHIR_CPY_WRT(&prev, &token);
		ZEPHIR_CALL_METHOD(NULL, &i, "next", &_25, 200);
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
	zephir_fcall_cache_entry *_21 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *token, token_sub, *prev = NULL, prev_sub, *next = NULL, next_sub, __$null, _0$$3, _1$$4, _2$$7, _7$$7, _8$$8, _9$$8, _10$$8, _11$$10, _15$$15, _16$$15, _18$$17, _19$$23, _20$$23, _22$$24, _24$$26, _25$$27, _26$$28, _27$$28, _28$$29;
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
	ZVAL_UNDEF(&_20$$23);
	ZVAL_UNDEF(&_22$$24);
	ZVAL_UNDEF(&_24$$26);
	ZVAL_UNDEF(&_25$$27);
	ZVAL_UNDEF(&_26$$28);
	ZVAL_UNDEF(&_27$$28);
	ZVAL_UNDEF(&_28$$29);
	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_3$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(token)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(prev)
		Z_PARAM_ZVAL_OR_NULL(next)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
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
		zephir_array_fetch_long(&_0$$3, token, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 318);
		do {
			if (ZEPHIR_IS_LONG(&_0$$3, 301) || ZEPHIR_IS_LONG(&_0$$3, 284) || ZEPHIR_IS_LONG(&_0$$3, 283) || ZEPHIR_IS_LONG(&_0$$3, 366) || ZEPHIR_IS_LONG(&_0$$3, 367) || ZEPHIR_IS_LONG(&_0$$3, 368) || ZEPHIR_IS_LONG(&_0$$3, 369) || ZEPHIR_IS_LONG(&_0$$3, 370) || ZEPHIR_IS_LONG(&_0$$3, 371)) {
				zephir_array_fetch_long(&_1$$4, token, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 328);
				ZEPHIR_CONCAT_SVS(return_value, " ", &_1$$4, " ");
				RETURN_MM();
			}
			if (ZEPHIR_IS_LONG(&_0$$3, 277)) {
				RETURN_MM_STRING(" || ");
			}
			if (ZEPHIR_IS_LONG(&_0$$3, 279)) {
				RETURN_MM_STRING(" && ");
			}
			if (ZEPHIR_IS_LONG(&_0$$3, 262)) {
				ZEPHIR_OBS_VAR(&_2$$7);
				zephir_array_fetch_long(&_2$$7, token, 1, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 334);
				zephir_cast_to_string(&_3$$7, &_2$$7);
				ZEPHIR_CPY_WRT(&str, &_3$$7);
				_4$$7 = ZEPHIR_IS_STRING(next, "(");
				if (_4$$7) {
					_5$$7 = !ZEPHIR_IS_STRING(prev, ".");
					if (!(_5$$7)) {
						_6$$7 = Z_TYPE_P(prev) == IS_ARRAY;
						if (_6$$7) {
							zephir_array_fetch_long(&_7$$7, prev, 0, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 336);
							_6$$7 = !ZEPHIR_IS_LONG(&_7$$7, 397);
						}
						_5$$7 = _6$$7;
					}
					_4$$7 = _5$$7;
				}
				if (_4$$7) {
					ZEPHIR_INIT_VAR(&_8$$8);
					zephir_read_property(&_9$$8, this_ptr, ZEND_STRL("functions"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_9$$8, &str)) {
						zephir_read_property(&_10$$8, this_ptr, ZEND_STRL("functions"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_8$$8, &_10$$8, &str, PH_NOISY, "ice/mvc/view/engine/sleet/parser.zep", 337);
					} else {
						ZEPHIR_CPY_WRT(&_8$$8, &str);
					}
					RETURN_CCTOR(&_8$$8);
				}
				do {
					if (ZEPHIR_IS_STRING(&str, "in")) {
						RETURN_MM_STRING(" as ");
					}
					if (ZEPHIR_IS_STRING(&str, "is")) {
						ZEPHIR_INIT_VAR(&_11$$10);
						if (ZEPHIR_IS_STRING(next, "!")) {
							ZVAL_STRING(&_11$$10, " != ");
						} else {
							ZVAL_STRING(&_11$$10, " == ");
						}
						RETURN_CCTOR(&_11$$10);
					}
					if (ZEPHIR_IS_STRING(&str, "and")) {
						RETURN_MM_STRING(" && ");
					}
					if (ZEPHIR_IS_STRING(&str, "or")) {
						RETURN_MM_STRING(" || ");
					}
					if (ZEPHIR_IS_STRING(&str, "not")) {
						RETURN_MM_STRING("!");
					}
					if (ZEPHIR_IS_STRING(&str, "false") || ZEPHIR_IS_STRING(&str, "true") || ZEPHIR_IS_STRING(&str, "null")) {
						RETURN_CTOR(&str);
					}
					_12$$15 = ZEPHIR_IS_STRING(prev, ".");
					if (!(_12$$15)) {
						_12$$15 = ZEPHIR_IS_STRING(next, "(");
					}
					_13$$15 = _12$$15;
					if (!(_13$$15)) {
						_14$$15 = ZEPHIR_STRING_OFFSET(&str, 0);
						ZEPHIR_INIT_VAR(&_15$$15);
						ZVAL_STRINGL(&_15$$15, &_14$$15, 1);
						ZEPHIR_CALL_FUNCTION(&_16$$15, "ctype_upper", NULL, 201, &_15$$15);
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
				} while(0);

			}
			zephir_array_fetch_long(&_18$$17, token, 1, PH_NOISY | PH_READONLY, "ice/mvc/view/engine/sleet/parser.zep", 361);
			RETURN_CTOR(&_18$$17);
		} while(0);

	} else {
		do {
			if (ZEPHIR_IS_STRING(token, "-") || ZEPHIR_IS_STRING(token, "+") || ZEPHIR_IS_STRING(token, "*") || ZEPHIR_IS_STRING(token, "/") || ZEPHIR_IS_STRING(token, "%") || ZEPHIR_IS_STRING(token, "=") || ZEPHIR_IS_STRING(token, ">") || ZEPHIR_IS_STRING(token, "<")) {
				ZEPHIR_CONCAT_SVS(return_value, " ", token, " ");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(token, "~")) {
				RETURN_MM_STRING(" . ");
			}
			if (ZEPHIR_IS_STRING(token, ",")) {
				RETURN_MM_STRING(", ");
			}
			if (ZEPHIR_IS_STRING(token, ".")) {
				RETURN_MM_STRING("->");
			}
			if (ZEPHIR_IS_STRING(token, ":")) {
				zephir_read_property(&_19$$23, this_ptr, ZEND_STRL("env"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_MAKE_REF(&_19$$23);
				ZEPHIR_CALL_FUNCTION(&_20$$23, "end", &_21, 202, &_19$$23);
				ZEPHIR_UNREF(&_19$$23);
				zephir_check_call_status();
				do {
					if (ZEPHIR_IS_LONG(&_20$$23, 1)) {
						zephir_read_property(&_22$$24, this_ptr, ZEND_STRL("env"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_MAKE_REF(&_22$$24);
						ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_23, 203, &_22$$24);
						ZEPHIR_UNREF(&_22$$24);
						zephir_check_call_status();
						RETURN_MM_STRING(" : ");
					}
					RETURN_MM_STRING(" => ");
				} while(0);

			}
			if (ZEPHIR_IS_STRING(token, "?")) {
				ZEPHIR_INIT_ZVAL_NREF(_24$$26);
				ZVAL_LONG(&_24$$26, 1);
				zephir_update_property_array_append(this_ptr, SL("env"), &_24$$26);
				RETURN_MM_STRING(" ? ");
			}
			if (ZEPHIR_IS_STRING(token, "[")) {
				ZEPHIR_INIT_ZVAL_NREF(_25$$27);
				ZVAL_LONG(&_25$$27, 2);
				zephir_update_property_array_append(this_ptr, SL("env"), &_25$$27);
				RETVAL_ZVAL(token, 1, 0);
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(token, "]")) {
				zephir_read_property(&_26$$28, this_ptr, ZEND_STRL("env"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_MAKE_REF(&_26$$28);
				ZEPHIR_CALL_FUNCTION(&_27$$28, "end", &_21, 202, &_26$$28);
				ZEPHIR_UNREF(&_26$$28);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_27$$28, 2)) {
					zephir_read_property(&_28$$29, this_ptr, ZEND_STRL("env"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_MAKE_REF(&_28$$29);
					ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_23, 203, &_28$$29);
					ZEPHIR_UNREF(&_28$$29);
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
	

		ZEPHIR_MM_GROW();
	
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

