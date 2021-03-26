
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/math.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * Provide the multi-page pagination component.
 *
 * @package     Ice/Pagination
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 * @uses        Ice\Tag
 */
ZEPHIR_INIT_CLASS(Ice_Pagination) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Pagination, ice, pagination, ice_arr_ce, ice_pagination_method_entry, 0);

	zend_declare_property_null(ice_pagination_ce, SL("di"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_pagination_ce, SL("tag"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(Ice_Pagination, getDi) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "di");

}

PHP_METHOD(Ice_Pagination, getTag) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "tag");

}

/**
 * Pagination constructor. Fetch di and tag.
 *
 * @param array options
 */
PHP_METHOD(Ice_Pagination, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zval *options_param = NULL, di, _2, _3;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, ice_pagination_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_1, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("di"), &di);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "tag");
	ZEPHIR_CALL_METHOD(&_2, &di, "get", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("tag"), &_2);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a slice of the resultset to show in the pagination.
 *
 * @return object Pagination
 */
PHP_METHOD(Ice_Pagination, calculate) {

	zval _15;
	zend_bool _9, _3$$3;
	zval items, data, total, _0, _4, _5, _6, _7, _8, _14, _1$$3, _2$$3, _10$$8, _11$$8, _12$$8, _13$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, limit = 0, page = 0, pages = 0, previous = 0, next = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&total);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_15);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "total");
	ZEPHIR_CALL_METHOD(&total, this_ptr, "get", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&total) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "data");
		ZEPHIR_CALL_METHOD(&data, this_ptr, "get", NULL, 0, &_2$$3, &_1$$3);
		zephir_check_call_status();
		_3$$3 = Z_TYPE_P(&data) == IS_OBJECT;
		if (_3$$3) {
			_3$$3 = (zephir_instance_of_ev(&data, ice_arr_ce));
		}
		if (_3$$3) {
			ZEPHIR_CALL_METHOD(&items, &data, "all", NULL, 0);
			zephir_check_call_status();
		} else if (Z_TYPE_P(&data) == IS_ARRAY) {
			ZEPHIR_CPY_WRT(&items, &data);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid data for pagination", "ice/pagination.zep", 58);
			return;
		}
		ZEPHIR_INIT_NVAR(&total);
		ZVAL_LONG(&total, zephir_fast_count_int(&items));
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "limit");
	ZVAL_LONG(&_5, 10);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 0, &_0, &_5);
	zephir_check_call_status();
	limit = zephir_get_intval(&_4);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "page");
	ZVAL_LONG(&_5, 1);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "get", NULL, 0, &_0, &_5);
	zephir_check_call_status();
	page = zephir_get_intval(&_6);
	ZEPHIR_INIT_VAR(&_7);
	if (limit) {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_LONG(&_7, limit);
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_LONG(&_7, 1);
	}
	ZVAL_DOUBLE(&_5, zephir_safe_div_zval_long(&total, zephir_get_intval(&_7)));
	pages = (int) zephir_ceil(&_5);
	if (page <= 0) {
		page = 1;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "items");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "has", NULL, 0, &_0);
	zephir_check_call_status();
	_9 = !zephir_is_true(&_8);
	if (_9) {
		_9 = zephir_is_true(&items);
	}
	if (_9) {
		ZVAL_LONG(&_10$$8, (limit * ((page - 1))));
		ZVAL_LONG(&_11$$8, limit);
		ZEPHIR_CALL_FUNCTION(&_12$$8, "array_slice", NULL, 124, &items, &_10$$8, &_11$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$8);
		ZVAL_STRING(&_13$$8, "items");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_13$$8, &_12$$8);
		zephir_check_call_status();
	}
	if (page < pages) {
		next = (page + 1);
	} else {
		next = pages;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "next");
	ZVAL_LONG(&_14, next);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_0, &_14);
	zephir_check_call_status();
	if (page > 1) {
		previous = (page - 1);
	} else {
		previous = 1;
	}
	ZEPHIR_INIT_VAR(&_15);
	zephir_create_array(&_15, 6, 0);
	add_assoc_long_ex(&_15, SL("first"), 1);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, previous);
	zephir_array_update_string(&_15, SL("previous"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, page);
	zephir_array_update_string(&_15, SL("current"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pages);
	zephir_array_update_string(&_15, SL("last"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pages);
	zephir_array_update_string(&_15, SL("pages"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_15, SL("total"), &total, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", NULL, 0, &_15);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Prepare list button.
 *
 * @param mixed page Name or page number
 * @param mixed url URL with pagination
 * @param boolean active If active create link else span
 * @param string symbol HTML symbol to add
 * @return string HTML
 */
PHP_METHOD(Ice_Pagination, prepareButton) {

	zval _27, _8$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool active, pages, _12;
	zval *page = NULL, page_sub, *url = NULL, url_sub, *active_param = NULL, *symbol = NULL, symbol_sub, __$null, query, i18n, title, liClass, spanClass, aClass, _1, _5, _6, _7, _11, _13, _24, _25, _26, _28, _0$$7, _2$$8, _3$$8, _4$$8, _9$$9, _10$$10, _14$$12, _15$$12, _16$$12, _17$$12, _18$$11, _19$$11, _20$$11, _21$$11, _22$$14, _23$$15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&page_sub);
	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&symbol_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&title);
	ZVAL_UNDEF(&liClass);
	ZVAL_UNDEF(&spanClass);
	ZVAL_UNDEF(&aClass);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_0$$7);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_8$$9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_ZVAL(page)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(url)
		Z_PARAM_BOOL(active)
		Z_PARAM_ZVAL(symbol)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &page, &url, &active_param, &symbol);

	ZEPHIR_SEPARATE_PARAM(page);
	if (!url) {
		url = &url_sub;
		ZEPHIR_CPY_WRT(url, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(url);
	}
	if (!active_param) {
		active = 0;
	} else {
		active = zephir_get_boolval(active_param);
	}
	if (!symbol) {
		symbol = &symbol_sub;
		ZEPHIR_CPY_WRT(symbol, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(symbol);
	}


	pages = 0;
	do {
		if (ZEPHIR_IS_STRING(page, "first")) {
			ZEPHIR_INIT_NVAR(symbol);
			ZVAL_STRING(symbol, "&laquo;");
			break;
		}
		if (ZEPHIR_IS_STRING(page, "previous")) {
			ZEPHIR_INIT_NVAR(symbol);
			ZVAL_STRING(symbol, "&lsaquo;");
			break;
		}
		if (ZEPHIR_IS_STRING(page, "next")) {
			ZEPHIR_INIT_NVAR(symbol);
			ZVAL_STRING(symbol, "&rsaquo;");
			break;
		}
		if (ZEPHIR_IS_STRING(page, "last")) {
			ZEPHIR_INIT_NVAR(symbol);
			ZVAL_STRING(symbol, "&raquo;");
			break;
		}
		ZEPHIR_INIT_VAR(&_0$$7);
		if (!(zephir_is_true(symbol))) {
			ZEPHIR_CPY_WRT(&_0$$7, page);
		} else {
			ZEPHIR_CPY_WRT(&_0$$7, symbol);
		}
		ZEPHIR_CPY_WRT(symbol, &_0$$7);
		pages = 1;
		break;
	} while(0);

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "liClass");
	ZEPHIR_CALL_METHOD(&liClass, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "spanClass");
	ZEPHIR_CALL_METHOD(&spanClass, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "aClass");
	ZEPHIR_CALL_METHOD(&aClass, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(active)) {
		ZEPHIR_INIT_VAR(&_2$$8);
		if (pages) {
			ZEPHIR_INIT_NVAR(&_2$$8);
			ZVAL_STRING(&_2$$8, "active");
		} else {
			ZEPHIR_INIT_NVAR(&_2$$8);
			ZVAL_STRING(&_2$$8, "disabled");
		}
		ZEPHIR_INIT_VAR(&_3$$8);
		if (zephir_is_true(&liClass)) {
			ZEPHIR_INIT_NVAR(&_3$$8);
			ZEPHIR_CONCAT_SV(&_3$$8, " ", &liClass);
		} else {
			ZEPHIR_INIT_NVAR(&_3$$8);
			ZVAL_STRING(&_3$$8, "");
		}
		ZEPHIR_INIT_VAR(&_4$$8);
		if (zephir_is_true(&spanClass)) {
			ZEPHIR_INIT_NVAR(&_4$$8);
			ZEPHIR_CONCAT_SVS(&_4$$8, " class=\"", &spanClass, "\"");
		} else {
			ZEPHIR_INIT_NVAR(&_4$$8);
			ZVAL_STRING(&_4$$8, "");
		}
		ZEPHIR_CONCAT_SVVSVSVS(return_value, "<li class=\"", &_2$$8, &_3$$8, "\"><span", &_4$$8, ">", symbol, "</span></li>");
		RETURN_MM();
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_6, &_5, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, &_6, "getquery", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "i18n");
	ZEPHIR_CALL_METHOD(&i18n, &_7, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&title);
	if (pages) {
		if (zephir_is_true(&i18n)) {
			ZEPHIR_INIT_VAR(&_8$$9);
			zephir_create_array(&_8$$9, 1, 0);
			zephir_array_fast_append(&_8$$9, page);
			ZEPHIR_INIT_VAR(&_9$$9);
			ZVAL_STRING(&_9$$9, "page: %d");
			ZEPHIR_CALL_METHOD(&title, &i18n, "translate", NULL, 0, &_9$$9, &_8$$9);
			zephir_check_call_status();
		} else {
			ZVAL_NULL(&title);
		}
	} else {
		if (zephir_is_true(&i18n)) {
			ZEPHIR_CALL_METHOD(&title, &i18n, "translate", NULL, 0, page);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&title);
			ZVAL_NULL(&title);
		}
		ZEPHIR_CALL_METHOD(&_10$$10, this_ptr, "get", NULL, 0, page);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(page, &_10$$10);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "query");
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "has", NULL, 0, &_1);
	zephir_check_call_status();
	_12 = zephir_is_true(&_11);
	if (_12) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "query");
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", NULL, 0, &_1);
		zephir_check_call_status();
		_12 = !zephir_is_true(&_13);
	}
	if (_12) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(url)) {
			zephir_read_property(&_14$$12, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_16$$12);
			ZVAL_STRING(&_16$$12, "url");
			ZEPHIR_CALL_METHOD(&_15$$12, &_14$$12, "get", NULL, 0, &_16$$12);
			zephir_check_call_status();
			ZVAL_BOOL(&_17$$12, 0);
			ZEPHIR_CALL_METHOD(url, &_15$$12, "rel", NULL, 0, &_17$$12);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_18$$11);
		if (zephir_is_true(url)) {
			ZEPHIR_INIT_NVAR(&_18$$11);
			ZVAL_STRING(&_18$$11, "/");
		} else {
			ZEPHIR_INIT_NVAR(&_18$$11);
			ZVAL_STRING(&_18$$11, "");
		}
		ZEPHIR_INIT_VAR(&_20$$11);
		ZVAL_STRING(&_20$$11, "hash");
		ZEPHIR_CALL_METHOD(&_19$$11, this_ptr, "get", NULL, 0, &_20$$11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_21$$11);
		ZEPHIR_CONCAT_VVV(&_21$$11, &_18$$11, page, &_19$$11);
		zephir_concat_self(url, &_21$$11);
	} else {
		if (ZEPHIR_GT_LONG(page, 1)) {
			ZEPHIR_INIT_VAR(&_22$$14);
			ZVAL_STRING(&_22$$14, "page");
			ZEPHIR_CALL_METHOD(NULL, &query, "set", NULL, 0, &_22$$14, page);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_23$$15);
			ZVAL_STRING(&_23$$15, "page");
			ZEPHIR_CALL_METHOD(NULL, &query, "remove", NULL, 0, &_23$$15);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(&_24);
	if (zephir_is_true(&liClass)) {
		ZEPHIR_INIT_NVAR(&_24);
		ZEPHIR_CONCAT_SVS(&_24, " class=\"", &liClass, "\"");
	} else {
		ZEPHIR_INIT_NVAR(&_24);
		ZVAL_STRING(&_24, "");
	}
	zephir_read_property(&_25, this_ptr, ZEND_STRL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_27);
	zephir_create_array(&_27, 5, 0);
	zephir_array_fast_append(&_27, url);
	zephir_array_fast_append(&_27, symbol);
	zephir_array_fast_append(&_27, &title);
	ZEPHIR_CALL_METHOD(&_28, &query, "all", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_27, SL("query"), &_28, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_27, SL("class"), &aClass, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_26, &_25, "a", NULL, 0, &_27);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<li", &_24, ">", &_26, "</li>");
	RETURN_MM();

}

/**
 * Prepare minimal pagination.
 * Previous 1 [2] 3 4 5 6 Next
 *
 * @param mixed url URL with pagination
 * @param array parameters UL attributes to adding
 * @return string HTML
 */
PHP_METHOD(Ice_Pagination, minimal) {

	zend_bool _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, _10;
	zval parameters, _1;
	zval *url = NULL, url_sub, *parameters_param = NULL, __$null, html, _0, _2, _3, _4, _5, _6, _8, _11, _17, _18, _19, _12$$3, _13$$3, _14$$3, _15$$3, _16$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(url)
		Z_PARAM_ARRAY(parameters)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &url, &parameters_param);

	if (!url) {
		url = &url_sub;
		url = &__$null;
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	add_assoc_stringl_ex(&_1, SL("class"), SL("pagination"));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "ul");
	ZEPHIR_CALL_METHOD(&html, &_0, "taghtml", NULL, 0, &_2, &parameters, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "current");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "previous");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "previous");
	ZVAL_BOOL(&_6, ZEPHIR_GT(&_4, &_5));
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "preparebutton", &_7, 0, &_2, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_3);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "pages");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&_11, &_8);
	_10 = 1;
	_9 = 0;
	if (ZEPHIR_GE_LONG(&_11, _10)) {
		while (1) {
			if (_9) {
				_10++;
				if (!(ZEPHIR_GE_LONG(&_11, _10))) {
					break;
				}
			} else {
				_9 = 1;
			}
			i = _10;
			ZEPHIR_INIT_NVAR(&_14$$3);
			ZVAL_STRING(&_14$$3, "current");
			ZEPHIR_CALL_METHOD(&_13$$3, this_ptr, "get", NULL, 0, &_14$$3);
			zephir_check_call_status();
			ZVAL_LONG(&_15$$3, i);
			ZVAL_BOOL(&_16$$3, !ZEPHIR_IS_LONG_IDENTICAL(&_13$$3, i));
			ZEPHIR_CALL_METHOD(&_12$$3, this_ptr, "preparebutton", &_7, 0, &_15$$3, url, &_16$$3);
			zephir_check_call_status();
			zephir_concat_self(&html, &_12$$3);
		}
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "current");
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "next");
	ZEPHIR_CALL_METHOD(&_18, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "next");
	ZVAL_BOOL(&_6, ZEPHIR_LT(&_17, &_18));
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "preparebutton", &_7, 0, &_2, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_8);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ul");
	ZEPHIR_CALL_METHOD(&_19, &_6, "endtag", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_concat_self(&html, &_19);
	RETURN_CCTOR(&html);

}

/**
 * Prepare basic pagination.
 * First Previous 1 [2] 3 4 5 6 Next Last
 *
 * @param mixed url URL with pagination
 * @param array parameters UL attributes to adding
 * @return string HTML
 */
PHP_METHOD(Ice_Pagination, basic) {

	zend_bool _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0, _13;
	zval parameters, _1;
	zval *url = NULL, url_sub, *parameters_param = NULL, __$null, html, _0, _2, _3, _4, _5, _6, _8, _9, _10, _11, _14, _20, _21, _22, _23, _24, _25, _15$$3, _16$$3, _17$$3, _18$$3, _19$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(url)
		Z_PARAM_ARRAY(parameters)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &url, &parameters_param);

	if (!url) {
		url = &url_sub;
		url = &__$null;
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	add_assoc_stringl_ex(&_1, SL("class"), SL("pagination"));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "ul");
	ZEPHIR_CALL_METHOD(&html, &_0, "taghtml", NULL, 0, &_2, &parameters, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "current");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "first");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "first");
	ZVAL_BOOL(&_6, !ZEPHIR_IS_EQUAL(&_4, &_5));
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "preparebutton", &_7, 0, &_2, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_3);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "current");
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "previous");
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "previous");
	ZVAL_BOOL(&_6, ZEPHIR_GT(&_9, &_10));
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "preparebutton", &_7, 0, &_2, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_8);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "pages");
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&_14, &_11);
	_13 = 1;
	_12 = 0;
	if (ZEPHIR_GE_LONG(&_14, _13)) {
		while (1) {
			if (_12) {
				_13++;
				if (!(ZEPHIR_GE_LONG(&_14, _13))) {
					break;
				}
			} else {
				_12 = 1;
			}
			i = _13;
			ZEPHIR_INIT_NVAR(&_17$$3);
			ZVAL_STRING(&_17$$3, "current");
			ZEPHIR_CALL_METHOD(&_16$$3, this_ptr, "get", NULL, 0, &_17$$3);
			zephir_check_call_status();
			ZVAL_LONG(&_18$$3, i);
			ZVAL_BOOL(&_19$$3, !ZEPHIR_IS_LONG_IDENTICAL(&_16$$3, i));
			ZEPHIR_CALL_METHOD(&_15$$3, this_ptr, "preparebutton", &_7, 0, &_18$$3, url, &_19$$3);
			zephir_check_call_status();
			zephir_concat_self(&html, &_15$$3);
		}
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "current");
	ZEPHIR_CALL_METHOD(&_20, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "next");
	ZEPHIR_CALL_METHOD(&_21, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "next");
	ZVAL_BOOL(&_6, ZEPHIR_LT(&_20, &_21));
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "preparebutton", &_7, 0, &_2, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_11);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "current");
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "last");
	ZEPHIR_CALL_METHOD(&_24, this_ptr, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "last");
	ZVAL_BOOL(&_6, !ZEPHIR_IS_EQUAL(&_23, &_24));
	ZEPHIR_CALL_METHOD(&_22, this_ptr, "preparebutton", &_7, 0, &_2, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_22);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ul");
	ZEPHIR_CALL_METHOD(&_25, &_6, "endtag", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_concat_self(&html, &_25);
	RETURN_CCTOR(&html);

}

/**
 * Prepare floating pagination.
 * First Previous 1 2 3 ... 23 24 25 26 [27] 28 29 30 31 ... 48 49 50 Next Last
 *
 * @param mixed url URL with pagination
 * @param array parameters UL attributes to adding
 * @param int countOut Number of page links in the begin and end of whole range
 * @param int countIn Number of page links on each side of current page
 * @return string HTML
 */
PHP_METHOD(Ice_Pagination, floating) {

	zend_string *_41;
	zend_ulong _40;
	zend_bool useMiddle = 0, useN3 = 0, useN6 = 0, _11, _14, _16, _21, _26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_34 = NULL;
	zend_long countOut, countIn, ZEPHIR_LAST_CALL_STATUS, n1 = 0, n3 = 0, n6 = 0, i = 0, _17;
	zval parameters, _30;
	zval *url = NULL, url_sub, *parameters_param = NULL, *countOut_param = NULL, *countIn_param = NULL, __$null, html, links, page, content, n2, n4, n5, n7, n8, _0, _1, _2, _3, _5, _6, _8, _9, _10, _12, _13, _15, _18, _22, _23, _27, _28, _31, _32, _33, _35, _36, _37, *_38, _39, _50, _51, _52, _53, _54, _55, _56, _19$$4, _20$$5, _24$$6, _25$$7, _29$$8, _42$$9, _43$$9, _44$$9, _45$$9, _46$$10, _47$$10, _48$$10, _49$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&links);
	ZVAL_UNDEF(&page);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&n2);
	ZVAL_UNDEF(&n4);
	ZVAL_UNDEF(&n5);
	ZVAL_UNDEF(&n7);
	ZVAL_UNDEF(&n8);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_50);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_53);
	ZVAL_UNDEF(&_54);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_56);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_44$$9);
	ZVAL_UNDEF(&_45$$9);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_47$$10);
	ZVAL_UNDEF(&_48$$10);
	ZVAL_UNDEF(&_49$$10);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_30);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(url)
		Z_PARAM_ARRAY(parameters)
		Z_PARAM_LONG(countOut)
		Z_PARAM_LONG(countIn)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &url, &parameters_param, &countOut_param, &countIn_param);

	if (!url) {
		url = &url_sub;
		url = &__$null;
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}
	if (!countOut_param) {
		countOut = 0;
	} else {
		countOut = zephir_get_intval(countOut_param);
	}
	if (!countIn_param) {
		countIn = 2;
	} else {
		countIn = zephir_get_intval(countIn_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "pages");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(&_0, 2)) {
		RETURN_MM_NULL();
	}
	n1 = 1;
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "pages");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_3, countOut);
	ZEPHIR_CALL_FUNCTION(&n2, "min", &_4, 31, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "pages");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 1);
	ZVAL_LONG(&_6, ((zephir_get_numberval(&_5) - countOut) + 1));
	ZEPHIR_CALL_FUNCTION(&n7, "max", &_7, 50, &_3, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "pages");
	ZEPHIR_CALL_METHOD(&n8, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "current");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_3, (zephir_get_numberval(&n2) + 1));
	ZVAL_LONG(&_6, (zephir_get_numberval(&_8) - countIn));
	ZEPHIR_CALL_FUNCTION(&n4, "max", &_7, 50, &_3, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "current");
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_3, (zephir_get_numberval(&n7) - 1));
	ZVAL_LONG(&_6, (zephir_get_numberval(&_9) + countIn));
	ZEPHIR_CALL_FUNCTION(&n5, "min", &_4, 31, &_3, &_6);
	zephir_check_call_status();
	useMiddle = (ZEPHIR_GE(&n5, &n4));
	ZEPHIR_INIT_VAR(&_10);
	zephir_add_function(&_10, &n2, &n4);
	n3 = (int) zephir_safe_div_zval_long(&_10, 2);
	_11 = useMiddle;
	if (_11) {
		ZEPHIR_INIT_VAR(&_12);
		zephir_sub_function(&_12, &n4, &n2);
		_11 = ZEPHIR_GT_LONG(&_12, 1);
	}
	useN3 = _11;
	ZEPHIR_INIT_VAR(&_13);
	zephir_add_function(&_13, &n5, &n7);
	n6 = (int) zephir_safe_div_zval_long(&_13, 2);
	_14 = useMiddle;
	if (_14) {
		ZEPHIR_INIT_VAR(&_15);
		zephir_sub_function(&_15, &n7, &n5);
		_14 = ZEPHIR_GT_LONG(&_15, 1);
	}
	useN6 = _14;
	ZEPHIR_INIT_VAR(&links);
	array_init(&links);
	ZEPHIR_CPY_WRT(&_18, &n2);
	_17 = n1;
	_16 = 0;
	if (ZEPHIR_GE_LONG(&_18, _17)) {
		while (1) {
			if (_16) {
				_17++;
				if (!(ZEPHIR_GE_LONG(&_18, _17))) {
					break;
				}
			} else {
				_16 = 1;
			}
			i = _17;
			ZEPHIR_INIT_NVAR(&_19$$4);
			ZVAL_LONG(&_19$$4, i);
			zephir_array_update_long(&links, i, &_19$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	if (useN3) {
		ZEPHIR_INIT_VAR(&_20$$5);
		ZVAL_STRING(&_20$$5, "&hellip;");
		zephir_array_update_long(&links, n3, &_20$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_CPY_WRT(&_23, &n5);
	ZEPHIR_CPY_WRT(&_22, &n4);
	_21 = 0;
	if (ZEPHIR_LE(&_22, &_23)) {
		while (1) {
			if (_21) {
				ZEPHIR_SEPARATE(&_22);
				zephir_increment(&_22);
				if (!(ZEPHIR_LE(&_22, &_23))) {
					break;
				}
			} else {
				_21 = 1;
			}
			i = zephir_get_numberval(&_22);
			ZEPHIR_INIT_NVAR(&_24$$6);
			ZVAL_LONG(&_24$$6, i);
			zephir_array_update_long(&links, i, &_24$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	if (useN6) {
		ZEPHIR_INIT_VAR(&_25$$7);
		ZVAL_STRING(&_25$$7, "&hellip;");
		zephir_array_update_long(&links, n6, &_25$$7, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_CPY_WRT(&_28, &n8);
	ZEPHIR_CPY_WRT(&_27, &n7);
	_26 = 0;
	if (ZEPHIR_LE(&_27, &_28)) {
		while (1) {
			if (_26) {
				ZEPHIR_SEPARATE(&_27);
				zephir_increment(&_27);
				if (!(ZEPHIR_LE(&_27, &_28))) {
					break;
				}
			} else {
				_26 = 1;
			}
			i = zephir_get_numberval(&_27);
			ZEPHIR_INIT_NVAR(&_29$$8);
			ZVAL_LONG(&_29$$8, i);
			zephir_array_update_long(&links, i, &_29$$8, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_30);
	zephir_create_array(&_30, 1, 0);
	add_assoc_stringl_ex(&_30, SL("class"), SL("pagination"));
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ul");
	ZEPHIR_CALL_METHOD(&html, &_3, "taghtml", NULL, 0, &_1, &parameters, &_30);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "current");
	ZEPHIR_CALL_METHOD(&_32, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "first");
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "first");
	ZVAL_BOOL(&_6, !ZEPHIR_IS_EQUAL(&_32, &_33));
	ZEPHIR_CALL_METHOD(&_31, this_ptr, "preparebutton", &_34, 0, &_1, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_31);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "current");
	ZEPHIR_CALL_METHOD(&_36, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "previous");
	ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "previous");
	ZVAL_BOOL(&_6, ZEPHIR_GT(&_36, &_37));
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "preparebutton", &_34, 0, &_1, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_35);
	zephir_is_iterable(&links, 0, "ice/pagination.zep", 329);
	if (Z_TYPE_P(&links) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&links), _40, _41, _38)
		{
			ZEPHIR_INIT_NVAR(&page);
			if (_41 != NULL) { 
				ZVAL_STR_COPY(&page, _41);
			} else {
				ZVAL_LONG(&page, _40);
			}
			ZEPHIR_INIT_NVAR(&content);
			ZVAL_COPY(&content, _38);
			ZEPHIR_INIT_NVAR(&_44$$9);
			ZVAL_STRING(&_44$$9, "current");
			ZEPHIR_CALL_METHOD(&_43$$9, this_ptr, "get", NULL, 0, &_44$$9);
			zephir_check_call_status();
			ZVAL_BOOL(&_45$$9, !ZEPHIR_IS_IDENTICAL(&page, &_43$$9));
			ZEPHIR_CALL_METHOD(&_42$$9, this_ptr, "preparebutton", &_34, 0, &page, url, &_45$$9, &content);
			zephir_check_call_status();
			zephir_concat_self(&html, &_42$$9);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &links, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_39, &links, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_39)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&page, &links, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&content, &links, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_48$$10);
				ZVAL_STRING(&_48$$10, "current");
				ZEPHIR_CALL_METHOD(&_47$$10, this_ptr, "get", NULL, 0, &_48$$10);
				zephir_check_call_status();
				ZVAL_BOOL(&_49$$10, !ZEPHIR_IS_IDENTICAL(&page, &_47$$10));
				ZEPHIR_CALL_METHOD(&_46$$10, this_ptr, "preparebutton", &_34, 0, &page, url, &_49$$10, &content);
				zephir_check_call_status();
				zephir_concat_self(&html, &_46$$10);
			ZEPHIR_CALL_METHOD(NULL, &links, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&content);
	ZEPHIR_INIT_NVAR(&page);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "current");
	ZEPHIR_CALL_METHOD(&_51, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "next");
	ZEPHIR_CALL_METHOD(&_52, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "next");
	ZVAL_BOOL(&_6, ZEPHIR_LT(&_51, &_52));
	ZEPHIR_CALL_METHOD(&_50, this_ptr, "preparebutton", &_34, 0, &_1, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_50);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "current");
	ZEPHIR_CALL_METHOD(&_54, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "last");
	ZEPHIR_CALL_METHOD(&_55, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "last");
	ZVAL_BOOL(&_6, !ZEPHIR_IS_EQUAL(&_54, &_55));
	ZEPHIR_CALL_METHOD(&_53, this_ptr, "preparebutton", &_34, 0, &_1, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_53);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ul");
	ZEPHIR_CALL_METHOD(&_56, &_6, "endtag", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_concat_self(&html, &_56);
	RETURN_CCTOR(&html);

}

