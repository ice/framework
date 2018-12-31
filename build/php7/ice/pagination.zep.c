
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        Ice\Tag
 */
ZEPHIR_INIT_CLASS(Ice_Pagination) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Pagination, ice, pagination, ice_arr_ce, ice_pagination_method_entry, 0);

	zend_declare_property_null(ice_pagination_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_pagination_ce, SL("tag"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zval *options_param = NULL, di, _2, _3;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

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
	zephir_update_property_zval(this_ptr, SL("di"), &di);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "tag");
	ZEPHIR_CALL_METHOD(&_2, &di, "get", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("tag"), &_2);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a slice of the resultset to show in the pagination.
 *
 * @return object Pagination
 */
PHP_METHOD(Ice_Pagination, calculate) {

	zval _10;
	zend_bool _2;
	zval items, data, _0, _1, _3, _4, _5, _6, _7, _8, _9;
	zend_long ZEPHIR_LAST_CALL_STATUS, limit = 0, page = 0, pages = 0, total = 0, previous = 0, next = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "data");
	ZEPHIR_CALL_METHOD(&items, this_ptr, "get", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	_2 = Z_TYPE_P(&items) != IS_ARRAY;
	if (_2) {
		_2 = !((zephir_instance_of_ev(&items, ice_arr_ce TSRMLS_CC)));
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid data for pagination", "ice/pagination.zep", 49);
		return;
	}
	if (zephir_instance_of_ev(&items, ice_arr_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&data, &items, "all", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&data, &items);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "limit");
	ZVAL_LONG(&_4, 10);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", NULL, 0, &_1, &_4);
	zephir_check_call_status();
	limit = zephir_get_intval(&_3);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "page");
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 0, &_1, &_4);
	zephir_check_call_status();
	page = zephir_get_intval(&_5);
	total = zephir_fast_count_int(&items TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	if (limit) {
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_LONG(&_6, limit);
	} else {
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_LONG(&_6, 1);
	}
	ZVAL_DOUBLE(&_4, zephir_safe_div_long_long(total, zephir_get_intval(&_6) TSRMLS_CC));
	pages = (int) zephir_ceil(&_4 TSRMLS_CC);
	if (page <= 0) {
		page = 1;
	}
	ZVAL_LONG(&_7, (limit * ((page - 1))));
	ZVAL_LONG(&_8, limit);
	ZEPHIR_CALL_FUNCTION(&_9, "array_slice", NULL, 115, &data, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "items");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_1, &_9);
	zephir_check_call_status();
	if (page < pages) {
		next = (page + 1);
	} else {
		next = pages;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "next");
	ZVAL_LONG(&_7, next);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_1, &_7);
	zephir_check_call_status();
	if (page > 1) {
		previous = (page - 1);
	} else {
		previous = 1;
	}
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 6, 0 TSRMLS_CC);
	add_assoc_long_ex(&_10, SL("first"), 1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, previous);
	zephir_array_update_string(&_10, SL("previous"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, page);
	zephir_array_update_string(&_10, SL("current"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, pages);
	zephir_array_update_string(&_10, SL("last"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, pages);
	zephir_array_update_string(&_10, SL("pages"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, total);
	zephir_array_update_string(&_10, SL("total"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, &_10);
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
	zephir_read_property(&_5, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_6, &_5, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, &_6, "getquery", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "i18n");
	ZEPHIR_CALL_METHOD(&i18n, &_7, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&title);
	if (pages) {
		if (zephir_is_true(&i18n)) {
			ZEPHIR_INIT_VAR(&_8$$9);
			zephir_create_array(&_8$$9, 1, 0 TSRMLS_CC);
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
			zephir_read_property(&_14$$12, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_16$$12);
			ZVAL_STRING(&_16$$12, "url");
			ZEPHIR_CALL_METHOD(&_15$$12, &_14$$12, "get", NULL, 0, &_16$$12);
			zephir_check_call_status();
			ZVAL_BOOL(&_17$$12, 0);
			ZEPHIR_CALL_METHOD(url, &_15$$12, "get", NULL, 0, &_17$$12);
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
		zephir_concat_self(url, &_21$$11 TSRMLS_CC);
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
	zephir_read_property(&_25, this_ptr, SL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_27);
	zephir_create_array(&_27, 5, 0 TSRMLS_CC);
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


	zephir_read_property(&_0, this_ptr, SL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
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
	zephir_concat_self(&html, &_3 TSRMLS_CC);
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
			zephir_concat_self(&html, &_12$$3 TSRMLS_CC);
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
	zephir_concat_self(&html, &_8 TSRMLS_CC);
	zephir_read_property(&_6, this_ptr, SL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ul");
	ZEPHIR_CALL_METHOD(&_19, &_6, "endtag", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_concat_self(&html, &_19 TSRMLS_CC);
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


	zephir_read_property(&_0, this_ptr, SL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
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
	zephir_concat_self(&html, &_3 TSRMLS_CC);
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
	zephir_concat_self(&html, &_8 TSRMLS_CC);
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
			zephir_concat_self(&html, &_15$$3 TSRMLS_CC);
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
	zephir_concat_self(&html, &_11 TSRMLS_CC);
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
	zephir_concat_self(&html, &_22 TSRMLS_CC);
	zephir_read_property(&_6, this_ptr, SL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ul");
	ZEPHIR_CALL_METHOD(&_25, &_6, "endtag", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_concat_self(&html, &_25 TSRMLS_CC);
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

	zend_string *_40;
	zend_ulong _39;
	zend_bool useMiddle = 0, useN3 = 0, useN6 = 0, _11, _14, _16, _21, _26;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_34 = NULL;
	zend_long countOut, countIn, ZEPHIR_LAST_CALL_STATUS, n1 = 0, n3 = 0, n6 = 0, i = 0, _17;
	zval parameters, _30;
	zval *url = NULL, url_sub, *parameters_param = NULL, *countOut_param = NULL, *countIn_param = NULL, __$null, html, links, page, content, n2, n4, n5, n7, n8, _0, _1, _2, _3, _5, _6, _8, _9, _10, _12, _13, _15, _18, _22, _23, _27, _28, _31, _32, _33, _35, _36, _37, *_38, _45, _46, _47, _48, _49, _50, _51, _19$$4, _20$$5, _24$$6, _25$$7, _29$$8, _41$$9, _42$$9, _43$$9, _44$$9;
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
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_50);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_44$$9);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_30);

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
	ZEPHIR_CALL_FUNCTION(&n7, "max", &_7, 49, &_3, &_6);
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
	ZEPHIR_CALL_FUNCTION(&n4, "max", &_7, 49, &_3, &_6);
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
	n3 = (int) zephir_safe_div_zval_long(&_10, 2 TSRMLS_CC);
	_11 = useMiddle;
	if (_11) {
		ZEPHIR_INIT_VAR(&_12);
		zephir_sub_function(&_12, &n4, &n2);
		_11 = ZEPHIR_GT_LONG(&_12, 1);
	}
	useN3 = _11;
	ZEPHIR_INIT_VAR(&_13);
	zephir_add_function(&_13, &n5, &n7);
	n6 = (int) zephir_safe_div_zval_long(&_13, 2 TSRMLS_CC);
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
	zephir_read_property(&_3, this_ptr, SL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_30);
	zephir_create_array(&_30, 1, 0 TSRMLS_CC);
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
	zephir_concat_self(&html, &_31 TSRMLS_CC);
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
	zephir_concat_self(&html, &_35 TSRMLS_CC);
	zephir_is_iterable(&links, 0, "ice/pagination.zep", 321);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&links), _39, _40, _38)
	{
		ZEPHIR_INIT_NVAR(&page);
		if (_40 != NULL) { 
			ZVAL_STR_COPY(&page, _40);
		} else {
			ZVAL_LONG(&page, _39);
		}
		ZEPHIR_INIT_NVAR(&content);
		ZVAL_COPY(&content, _38);
		ZEPHIR_INIT_NVAR(&_43$$9);
		ZVAL_STRING(&_43$$9, "current");
		ZEPHIR_CALL_METHOD(&_42$$9, this_ptr, "get", NULL, 0, &_43$$9);
		zephir_check_call_status();
		ZVAL_BOOL(&_44$$9, !ZEPHIR_IS_IDENTICAL(&page, &_42$$9));
		ZEPHIR_CALL_METHOD(&_41$$9, this_ptr, "preparebutton", &_34, 0, &page, url, &_44$$9, &content);
		zephir_check_call_status();
		zephir_concat_self(&html, &_41$$9 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&content);
	ZEPHIR_INIT_NVAR(&page);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "current");
	ZEPHIR_CALL_METHOD(&_46, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "next");
	ZEPHIR_CALL_METHOD(&_47, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "next");
	ZVAL_BOOL(&_6, ZEPHIR_LT(&_46, &_47));
	ZEPHIR_CALL_METHOD(&_45, this_ptr, "preparebutton", &_34, 0, &_1, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_45 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "current");
	ZEPHIR_CALL_METHOD(&_49, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "last");
	ZEPHIR_CALL_METHOD(&_50, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "last");
	ZVAL_BOOL(&_6, !ZEPHIR_IS_EQUAL(&_49, &_50));
	ZEPHIR_CALL_METHOD(&_48, this_ptr, "preparebutton", &_34, 0, &_1, url, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_48 TSRMLS_CC);
	zephir_read_property(&_6, this_ptr, SL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ul");
	ZEPHIR_CALL_METHOD(&_51, &_6, "endtag", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_concat_self(&html, &_51 TSRMLS_CC);
	RETURN_CCTOR(&html);

}

