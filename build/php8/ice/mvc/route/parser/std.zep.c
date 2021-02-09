
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Parses route strings of the following form:
 *
 * "/user/{name}[/{id:[0-9]+}]"
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Parser_Std) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route\\Parser, Std, ice, mvc_route_parser_std, ice_mvc_route_parser_std_method_entry, 0);

	zephir_declare_class_constant_string(ice_mvc_route_parser_std_ce, SL("VARIABLE_REGEX"), "\\{ \\s* ([a-zA-Z_][a-zA-Z0-9_-]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}");

	zephir_declare_class_constant_string(ice_mvc_route_parser_std_ce, SL("DEFAULT_DISPATCH_REGEX"), "[^/]+");

	zend_class_implements(ice_mvc_route_parser_std_ce, 1, ice_mvc_route_parser_parserinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Parser_Std, parse) {

	zend_bool _9$$5, _12$$7;
	zend_string *_8;
	zend_ulong _7;
	zval _1, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *route, route_sub, routeWithoutClosingOptionals, numOptionals, segments, currentRoute, routeDatas, n, segment, _0, *_5, _6, _2$$3, _4$$3, _10$$5, _13$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&routeWithoutClosingOptionals);
	ZVAL_UNDEF(&numOptionals);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&currentRoute);
	ZVAL_UNDEF(&routeDatas);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&segment);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "]");
	ZEPHIR_INIT_VAR(&routeWithoutClosingOptionals);
	zephir_fast_trim(&routeWithoutClosingOptionals, route, &_0, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&numOptionals);
	ZVAL_LONG(&numOptionals, (zephir_fast_strlen_ev(route) - zephir_fast_strlen_ev(&routeWithoutClosingOptionals)));
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SSS(&_1, "~", "\\{ \\s* ([a-zA-Z_][a-zA-Z0-9_-]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}", "(*SKIP)(*F) | \\[~x");
	ZEPHIR_CALL_FUNCTION(&segments, "preg_split", NULL, 178, &_1, &routeWithoutClosingOptionals);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&numOptionals, (zephir_fast_count_int(&segments) - 1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SSS(&_3$$3, "~", "\\{ \\s* ([a-zA-Z_][a-zA-Z0-9_-]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}", "(*SKIP)(*F) | \\]~x");
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_preg_match(&_4$$3, &_3$$3, &routeWithoutClosingOptionals, &_2$$3, 0, 0 , 0 );
		if (zephir_is_true(&_4$$3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Optional segments can only occur at the end of a route", "ice/mvc/route/parser/std.zep", 30);
			return;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Number of opening '[' and closing ']' does not match", "ice/mvc/route/parser/std.zep", 33);
		return;
	}
	ZEPHIR_INIT_VAR(&currentRoute);
	ZVAL_STRING(&currentRoute, "");
	ZEPHIR_INIT_VAR(&routeDatas);
	array_init(&routeDatas);
	zephir_is_iterable(&segments, 0, "ice/mvc/route/parser/std.zep", 48);
	if (Z_TYPE_P(&segments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&segments), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&n);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&n, _8);
			} else {
				ZVAL_LONG(&n, _7);
			}
			ZEPHIR_INIT_NVAR(&segment);
			ZVAL_COPY(&segment, _5);
			_9$$5 = ZEPHIR_IS_STRING_IDENTICAL(&segment, "");
			if (_9$$5) {
				_9$$5 = !ZEPHIR_IS_LONG_IDENTICAL(&n, 0);
			}
			if (_9$$5) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Empty optional part", "ice/mvc/route/parser/std.zep", 41);
				return;
			}
			zephir_concat_self(&currentRoute, &segment);
			ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "parseplaceholders", &_11, 179, &currentRoute);
			zephir_check_call_status();
			zephir_array_append(&routeDatas, &_10$$5, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 45);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &segments, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &segments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&n, &segments, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&segment, &segments, "current", NULL, 0);
			zephir_check_call_status();
				_12$$7 = ZEPHIR_IS_STRING_IDENTICAL(&segment, "");
				if (_12$$7) {
					_12$$7 = !ZEPHIR_IS_LONG_IDENTICAL(&n, 0);
				}
				if (_12$$7) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Empty optional part", "ice/mvc/route/parser/std.zep", 41);
					return;
				}
				zephir_concat_self(&currentRoute, &segment);
				ZEPHIR_CALL_METHOD(&_13$$7, this_ptr, "parseplaceholders", &_11, 179, &currentRoute);
				zephir_check_call_status();
				zephir_array_append(&routeDatas, &_13$$7, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 45);
			ZEPHIR_CALL_METHOD(NULL, &segments, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&segment);
	ZEPHIR_INIT_NVAR(&n);
	RETURN_CCTOR(&routeDatas);

}

/**
 * Parses a route string that does not contain optional segments.
 */
PHP_METHOD(Ice_Mvc_Route_Parser_Std, parsePlaceholders) {

	zval _12$$4, _28$$6;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *route, route_sub, matches, routeData, value, offset, _1, _2, _3, *_4, _5, _6$$4, _7$$4, _13$$4, _14$$4, _15$$4, _16$$4, _17$$4, _18$$4, _19$$4, _20$$4, _21$$4, _8$$5, _9$$5, _10$$5, _11$$5, _22$$6, _23$$6, _29$$6, _30$$6, _31$$6, _32$$6, _33$$6, _34$$6, _35$$6, _36$$6, _37$$6, _24$$7, _25$$7, _26$$7, _27$$7, _38$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&routeData);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_30$$6);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_32$$6);
	ZVAL_UNDEF(&_33$$6);
	ZVAL_UNDEF(&_34$$6);
	ZVAL_UNDEF(&_35$$6);
	ZVAL_UNDEF(&_36$$6);
	ZVAL_UNDEF(&_37$$6);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_38$$8);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_28$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route);



	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SSS(&_0, "~", "\\{ \\s* ([a-zA-Z_][a-zA-Z0-9_-]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}", "~x");
	ZVAL_LONG(&_1, (256 | 2));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_3, (256 | 2));
	zephir_preg_match(&_2, &_0, route, &matches, 1, zephir_get_intval(&_1) , 0 );
	if (!(zephir_is_true(&_2))) {
		zephir_create_array(return_value, 1, 0);
		zephir_array_fast_append(return_value, route);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&offset);
	ZVAL_LONG(&offset, 0);
	ZEPHIR_INIT_VAR(&routeData);
	array_init(&routeData);
	zephir_is_iterable(&matches, 0, "ice/mvc/route/parser/std.zep", 79);
	if (Z_TYPE_P(&matches) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _4)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _4);
			zephir_array_fetch_long(&_6$$4, &value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 68);
			zephir_array_fetch_long(&_7$$4, &_6$$4, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 68);
			if (ZEPHIR_GT(&_7$$4, &offset)) {
				zephir_array_fetch_long(&_8$$5, &value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 69);
				zephir_array_fetch_long(&_9$$5, &_8$$5, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 69);
				ZEPHIR_INIT_NVAR(&_10$$5);
				zephir_sub_function(&_10$$5, &_9$$5, &offset);
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_substr(&_11$$5, route, zephir_get_intval(&offset), zephir_get_intval(&_10$$5), 0);
				zephir_array_append(&routeData, &_11$$5, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 69);
			}
			ZEPHIR_INIT_NVAR(&_12$$4);
			zephir_create_array(&_12$$4, 2, 0);
			zephir_array_fetch_long(&_13$$4, &value, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 73);
			ZEPHIR_OBS_NVAR(&_14$$4);
			zephir_array_fetch_long(&_14$$4, &_13$$4, 0, PH_NOISY, "ice/mvc/route/parser/std.zep", 73);
			zephir_array_fast_append(&_12$$4, &_14$$4);
			ZEPHIR_INIT_NVAR(&_15$$4);
			if (zephir_array_isset_long(&value, 2)) {
				zephir_array_fetch_long(&_16$$4, &value, 2, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 74);
				zephir_array_fetch_long(&_17$$4, &_16$$4, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 74);
				ZEPHIR_INIT_NVAR(&_15$$4);
				zephir_fast_trim(&_15$$4, &_17$$4, NULL , ZEPHIR_TRIM_BOTH);
			} else {
				ZEPHIR_INIT_NVAR(&_15$$4);
				ZVAL_STRING(&_15$$4, "[^/]+");
			}
			zephir_array_fast_append(&_12$$4, &_15$$4);
			zephir_array_append(&routeData, &_12$$4, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 75);
			zephir_array_fetch_long(&_18$$4, &value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76);
			zephir_array_fetch_long(&_19$$4, &_18$$4, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76);
			zephir_array_fetch_long(&_20$$4, &value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76);
			zephir_array_fetch_long(&_21$$4, &_20$$4, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76);
			ZEPHIR_INIT_NVAR(&offset);
			ZVAL_LONG(&offset, (zephir_get_numberval(&_19$$4) + zephir_fast_strlen_ev(&_21$$4)));
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &matches, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &matches, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &matches, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_long(&_22$$6, &value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 68);
				zephir_array_fetch_long(&_23$$6, &_22$$6, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 68);
				if (ZEPHIR_GT(&_23$$6, &offset)) {
					zephir_array_fetch_long(&_24$$7, &value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 69);
					zephir_array_fetch_long(&_25$$7, &_24$$7, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 69);
					ZEPHIR_INIT_NVAR(&_26$$7);
					zephir_sub_function(&_26$$7, &_25$$7, &offset);
					ZEPHIR_INIT_NVAR(&_27$$7);
					zephir_substr(&_27$$7, route, zephir_get_intval(&offset), zephir_get_intval(&_26$$7), 0);
					zephir_array_append(&routeData, &_27$$7, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 69);
				}
				ZEPHIR_INIT_NVAR(&_28$$6);
				zephir_create_array(&_28$$6, 2, 0);
				zephir_array_fetch_long(&_29$$6, &value, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 73);
				ZEPHIR_OBS_NVAR(&_30$$6);
				zephir_array_fetch_long(&_30$$6, &_29$$6, 0, PH_NOISY, "ice/mvc/route/parser/std.zep", 73);
				zephir_array_fast_append(&_28$$6, &_30$$6);
				ZEPHIR_INIT_NVAR(&_31$$6);
				if (zephir_array_isset_long(&value, 2)) {
					zephir_array_fetch_long(&_32$$6, &value, 2, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 74);
					zephir_array_fetch_long(&_33$$6, &_32$$6, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 74);
					ZEPHIR_INIT_NVAR(&_31$$6);
					zephir_fast_trim(&_31$$6, &_33$$6, NULL , ZEPHIR_TRIM_BOTH);
				} else {
					ZEPHIR_INIT_NVAR(&_31$$6);
					ZVAL_STRING(&_31$$6, "[^/]+");
				}
				zephir_array_fast_append(&_28$$6, &_31$$6);
				zephir_array_append(&routeData, &_28$$6, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 75);
				zephir_array_fetch_long(&_34$$6, &value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76);
				zephir_array_fetch_long(&_35$$6, &_34$$6, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76);
				zephir_array_fetch_long(&_36$$6, &value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76);
				zephir_array_fetch_long(&_37$$6, &_36$$6, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76);
				ZEPHIR_INIT_NVAR(&offset);
				ZVAL_LONG(&offset, (zephir_get_numberval(&_35$$6) + zephir_fast_strlen_ev(&_37$$6)));
			ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	if (!ZEPHIR_IS_LONG(&offset, zephir_fast_strlen_ev(route))) {
		ZEPHIR_INIT_VAR(&_38$$8);
		zephir_substr(&_38$$8, route, zephir_get_intval(&offset), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_array_append(&routeData, &_38$$8, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 80);
	}
	RETURN_CCTOR(&routeData);

}

