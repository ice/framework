
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"


/**
 * Parses routes of the following form:
 *
 * "/user/{name}/{id:[0-9]+}"
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Parser_Std) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc\\Route\\Parser, Std, ice, mvc_route_parser_std, ice_mvc_route_parser_std_method_entry, 0);

	zend_declare_class_constant_string(ice_mvc_route_parser_std_ce, SL("VARIABLE_REGEX"), "~\\{ \\s* ([a-zA-Z][a-zA-Z0-9_]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}~x" TSRMLS_CC);

	zend_declare_class_constant_string(ice_mvc_route_parser_std_ce, SL("DEFAULT_DISPATCH_REGEX"), "[^/]+" TSRMLS_CC);

	zend_class_implements(ice_mvc_route_parser_std_ce TSRMLS_CC, 1, ice_mvc_route_parser_parserinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route_Parser_Std, parse) {

	zval *_12 = NULL;
	HashTable *_4;
	HashPosition _3;
	int offset = 0, ZEPHIR_LAST_CALL_STATUS;
	zval *route, *matches, *routeData, *value = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, **_5, *_6, *_7, *_8, *_9, _10 = zval_used_for_init, _11 = zval_used_for_init, *_13 = NULL, *_14 = NULL, *_15, *_16, *_17, *_18, *_19;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route);



	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "~\\{ \\s* ([a-zA-Z][a-zA-Z0-9_]*) \\s* (?: : \\s* ([^{}]*(?:\\{(?-1)\\}[^{}]*)*) )? \\}~x", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, (256 | 2));
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match_all", NULL, 113, _0, route, matches, _1);
	zephir_check_temp_parameter(_0);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		zephir_create_array(return_value, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(return_value, route);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(routeData);
	array_init(routeData);
	zephir_is_iterable(matches, &_4, &_3, 0, 0, "ice/mvc/route/parser/std.zep", 41);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(value, _5);
		zephir_array_fetch_long(&_6, value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 29 TSRMLS_CC);
		zephir_array_fetch_long(&_7, _6, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 29 TSRMLS_CC);
		if (ZEPHIR_GT_LONG(_7, offset)) {
			zephir_array_fetch_long(&_8, value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 30 TSRMLS_CC);
			zephir_array_fetch_long(&_9, _8, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 30 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_10);
			ZVAL_LONG(&_10, offset);
			ZEPHIR_SINIT_NVAR(_11);
			ZVAL_LONG(&_11, (zephir_get_numberval(_9) - offset));
			ZEPHIR_INIT_NVAR(_0);
			zephir_substr(_0, route, zephir_get_intval(&_10), zephir_get_intval(&_11), 0);
			zephir_array_append(&routeData, _0, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 30);
		}
		ZEPHIR_INIT_NVAR(_12);
		zephir_create_array(_12, 2, 0 TSRMLS_CC);
		zephir_array_fetch_long(&_8, value, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 34 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_13);
		zephir_array_fetch_long(&_13, _8, 0, PH_NOISY, "ice/mvc/route/parser/std.zep", 34 TSRMLS_CC);
		zephir_array_fast_append(_12, _13);
		ZEPHIR_INIT_LNVAR(_14);
		if (zephir_array_isset_long(value, 2)) {
			zephir_array_fetch_long(&_9, value, 2, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 35 TSRMLS_CC);
			zephir_array_fetch_long(&_15, _9, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 35 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_14);
			zephir_fast_trim(_14, _15, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_14);
			ZVAL_STRING(_14, "[^/]+", 1);
		}
		zephir_array_fast_append(_12, _14);
		zephir_array_append(&routeData, _12, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 36);
		zephir_array_fetch_long(&_16, value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 38 TSRMLS_CC);
		zephir_array_fetch_long(&_17, _16, 1, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 38 TSRMLS_CC);
		zephir_array_fetch_long(&_18, value, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 38 TSRMLS_CC);
		zephir_array_fetch_long(&_19, _18, 0, PH_NOISY | PH_READONLY, "ice/mvc/route/parser/std.zep", 38 TSRMLS_CC);
		offset = (zephir_get_numberval(_17) + zephir_fast_strlen_ev(_19));
	}
	if (offset != zephir_fast_strlen_ev(route)) {
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, offset);
		ZEPHIR_INIT_NVAR(_1);
		zephir_substr(_1, route, zephir_get_intval(&_10), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_array_append(&routeData, _1, PH_SEPARATE, "ice/mvc/route/parser/std.zep", 42);
	}
	RETURN_CCTOR(routeData);

}

