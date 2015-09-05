
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
#include "kernel/hash.h"
#include "kernel/array.h"


/**
 * Parses route strings of the following form:
 *
 * "/user/{name}[/{id:[0-9]+}]"
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Parser_Std) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route\\Parser, Std, ice, mvc_route_parser_std, ice_mvc_route_parser_std_method_entry, 0);

	zend_declare_class_constant_string(ice_mvc_route_parser_std_ce, SL("VARIABLE_REGEX"), "\\{ \\s* ([a-zA-Z][a-zA-Z0-9_]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}" TSRMLS_CC);

	zend_declare_class_constant_string(ice_mvc_route_parser_std_ce, SL("DEFAULT_DISPATCH_REGEX"), "[^/]+" TSRMLS_CC);

	zend_class_implements(ice_mvc_route_parser_std_ce TSRMLS_CC, 1, ice_mvc_route_parser_parserinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Parser_Std, parse) {

	zephir_fcall_cache_entry *_10 = NULL;
	zend_bool _8;
	HashTable *_6;
	HashPosition _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1, *_4;
	zval *route, *routeWithoutClosingOptionals, numOptionals, *segments = NULL, *currentRoute, *routeDatas, *n = NULL, *segment = NULL, _0, *_2, *_3, **_7, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, ']');
	ZEPHIR_INIT_VAR(routeWithoutClosingOptionals);
	zephir_fast_trim(routeWithoutClosingOptionals, route, &_0, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_SINIT_VAR(numOptionals);
	ZVAL_LONG(&numOptionals, (zephir_fast_strlen_ev(route) - zephir_fast_strlen_ev(routeWithoutClosingOptionals)));
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SSS(_1, "~", "\\{ \\s* ([a-zA-Z][a-zA-Z0-9_]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}", "(*SKIP)(*F) | \\[~x");
	ZEPHIR_CALL_FUNCTION(&segments, "preg_split", NULL, 123, _1, routeWithoutClosingOptionals);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&numOptionals, (zephir_fast_count_int(segments TSRMLS_CC) - 1))) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SSS(_4, "~", "\\{ \\s* ([a-zA-Z][a-zA-Z0-9_]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}", "(*SKIP)(*F) | \\]~x");
		zephir_preg_match(_3, _4, routeWithoutClosingOptionals, _2, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(_3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Optional segments can only occur at the end of a route", "ice/mvc/route/parser/std.zep", 30);
			return;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Number of opening '[' and closing ']' does not match", "ice/mvc/route/parser/std.zep", 33);
		return;
	}
	ZEPHIR_INIT_VAR(currentRoute);
	ZVAL_STRING(currentRoute, "", 1);
	ZEPHIR_INIT_VAR(routeDatas);
	array_init(routeDatas);
	zephir_is_iterable(segments, &_6, &_5, 0, 0, "ice/mvc/route/parser/std.zep", 48);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(n, _6, _5);
		ZEPHIR_GET_HVALUE(segment, _7);
		_8 = ZEPHIR_IS_STRING_IDENTICAL(segment, "");
		if (_8) {
			_8 = !ZEPHIR_IS_LONG_IDENTICAL(n, 0);
		}
		if (_8) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Empty optional part", "ice/mvc/route/parser/std.zep", 41);
			return;
		}
		zephir_concat_self(&currentRoute, segment TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_9, this_ptr, "parseplaceholders", &_10, 124, currentRoute);
		zephir_check_call_status();
		zephir_array_append(&routeDatas, _9, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 45);
	}
	RETURN_CCTOR(routeDatas);

}

/**
 * Parses a route string that does not contain optional segments.
 */
PHP_METHOD(Ice_Mvc_Route_Parser_Std, parsePlaceholders) {

	zval *_11 = NULL;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *route, *matches, *routeData, *value = NULL, *offset = NULL, *_1 = NULL, *_2 = NULL, **_5, *_6, *_7, *_8, *_9, _10 = zval_used_for_init, *_12 = NULL, *_13 = NULL, *_14, *_15, *_16, *_17, *_18, *_19;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route);



	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SSS(_0, "~", "\\{ \\s* ([a-zA-Z][a-zA-Z0-9_]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}", "~x");
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, (256 | 2));
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match_all", NULL, 125, _0, route, matches, _1);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(return_value, route);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(offset);
	ZVAL_LONG(offset, 0);
	ZEPHIR_INIT_VAR(routeData);
	array_init(routeData);
	zephir_is_iterable(matches, &_4, &_3, 0, 0, "ice/mvc/route/parser/std.zep", 79);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(value, _5);
		zephir_array_fetch_long(&_6, value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 68 TSRMLS_CC);
		zephir_array_fetch_long(&_7, _6, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 68 TSRMLS_CC);
		if (ZEPHIR_GT(_7, offset)) {
			zephir_array_fetch_long(&_8, value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 69 TSRMLS_CC);
			zephir_array_fetch_long(&_9, _8, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 69 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_10);
			sub_function(&_10, _9, offset TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_1);
			zephir_substr(_1, route, zephir_get_intval(offset), zephir_get_intval(&_10), 0);
			zephir_array_append(&routeData, _1, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 69);
		}
		ZEPHIR_INIT_NVAR(_11);
		zephir_create_array(_11, 2, 0 TSRMLS_CC);
		zephir_array_fetch_long(&_8, value, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 73 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_12);
		zephir_array_fetch_long(&_12, _8, 0, PH_NOISY, "ice/mvc/route/parser/std.zep", 73 TSRMLS_CC);
		zephir_array_fast_append(_11, _12);
		ZEPHIR_INIT_LNVAR(_13);
		if (zephir_array_isset_long(value, 2)) {
			zephir_array_fetch_long(&_9, value, 2, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 74 TSRMLS_CC);
			zephir_array_fetch_long(&_14, _9, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 74 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_13);
			zephir_fast_trim(_13, _14, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_13);
			ZVAL_STRING(_13, "[^/]+", 1);
		}
		zephir_array_fast_append(_11, _13);
		zephir_array_append(&routeData, _11, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 75);
		zephir_array_fetch_long(&_15, value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76 TSRMLS_CC);
		zephir_array_fetch_long(&_16, _15, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76 TSRMLS_CC);
		zephir_array_fetch_long(&_17, value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76 TSRMLS_CC);
		zephir_array_fetch_long(&_18, _17, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 76 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(offset);
		ZVAL_LONG(offset, (zephir_get_numberval(_16) + zephir_fast_strlen_ev(_18)));
	}
	if (!ZEPHIR_IS_LONG(offset, zephir_fast_strlen_ev(route))) {
		ZEPHIR_INIT_VAR(_19);
		zephir_substr(_19, route, zephir_get_intval(offset), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_array_append(&routeData, _19, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 80);
	}
	RETURN_CCTOR(routeData);

}

