
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

	

	RETURN_MEMBER(getThis(), "di");

}

PHP_METHOD(Ice_Pagination, getTag) {

	

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
	zval *options_param = NULL, *di = NULL, *_2 = NULL, *_3;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, ice_pagination_ce, getThis(), "__construct", &_0, 5, options);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_1, 1);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("di"), di TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, di, "get", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("tag"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a slice of the resultset to show in the pagination.
 *
 * @return object Pagination
 */
PHP_METHOD(Ice_Pagination, calculate) {

	zval *_11;
	zend_bool _2;
	zval *items = NULL, *data = NULL, *_0, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, _7, _8, _9, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, limit = 0, page = 0, pages = 0, total = 0, previous = 0, next = 0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "data", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&items, this_ptr, "get", NULL, 0, _1, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = Z_TYPE_P(items) != IS_ARRAY;
	if (_2) {
		_2 = !((zephir_instance_of_ev(items, ice_arr_ce TSRMLS_CC)));
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid data for pagination", "ice/pagination.zep", 49);
		return;
	}
	if (zephir_instance_of_ev(items, ice_arr_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&data, items, "all", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(data, items);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "limit", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 10);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", NULL, 107, _1, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	limit = zephir_get_intval(_3);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "page", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 1);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 107, _1, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	page = zephir_get_intval(_5);
	total = zephir_fast_count_int(items TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	if (limit) {
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, limit);
	} else {
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 1);
	}
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_DOUBLE(&_7, zephir_safe_div_long_long(total, zephir_get_intval(_6) TSRMLS_CC));
	pages = (int) zephir_ceil(&_7 TSRMLS_CC);
	if (page <= 0) {
		page = 1;
	}
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, (limit * ((page - 1))));
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, limit);
	ZEPHIR_CALL_FUNCTION(&_10, "array_slice", NULL, 128, data, &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "items", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, _1, _10);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (page < pages) {
		next = (page + 1);
	} else {
		next = pages;
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, next);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, _1, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (page > 1) {
		previous = (page - 1);
	} else {
		previous = 1;
	}
	ZEPHIR_INIT_VAR(_11);
	zephir_create_array(_11, 6, 0 TSRMLS_CC);
	add_assoc_long_ex(_11, SS("first"), 1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, previous);
	zephir_array_update_string(&_11, SL("previous"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, page);
	zephir_array_update_string(&_11, SL("current"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, pages);
	zephir_array_update_string(&_11, SL("last"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, pages);
	zephir_array_update_string(&_11, SL("pages"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, total);
	zephir_array_update_string(&_11, SL("total"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, _11);
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

	zval *_26, *_8$$9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool active, pages, _12;
	zval *page = NULL, *url = NULL, *active_param = NULL, *symbol = NULL, *query = NULL, *i18n = NULL, *title = NULL, *liClass = NULL, *spanClass = NULL, *aClass = NULL, *_1 = NULL, *_5, *_6 = NULL, *_7, *_11 = NULL, *_13 = NULL, *_23 = NULL, *_24, *_25 = NULL, *_27 = NULL, *_0$$7 = NULL, *_2$$8 = NULL, *_3$$8 = NULL, *_4$$8 = NULL, *_9$$9, *_10$$10 = NULL, *_14$$12, *_15$$12 = NULL, *_16$$12 = NULL, *_17$$11 = NULL, *_18$$11 = NULL, *_19$$11, *_20$$11, *_21$$14, *_22$$15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &page, &url, &active_param, &symbol);

	ZEPHIR_SEPARATE_PARAM(page);
	if (!url) {
		ZEPHIR_CPY_WRT(url, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(url);
	}
	if (!active_param) {
		active = 0;
	} else {
		active = zephir_get_boolval(active_param);
	}
	if (!symbol) {
		ZEPHIR_CPY_WRT(symbol, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(symbol);
	}


	pages = 0;
	do {
		if (ZEPHIR_IS_STRING(page, "first")) {
			ZEPHIR_INIT_NVAR(symbol);
			ZVAL_STRING(symbol, "&laquo;", 1);
			break;
		}
		if (ZEPHIR_IS_STRING(page, "previous")) {
			ZEPHIR_INIT_NVAR(symbol);
			ZVAL_STRING(symbol, "&lsaquo;", 1);
			break;
		}
		if (ZEPHIR_IS_STRING(page, "next")) {
			ZEPHIR_INIT_NVAR(symbol);
			ZVAL_STRING(symbol, "&rsaquo;", 1);
			break;
		}
		if (ZEPHIR_IS_STRING(page, "last")) {
			ZEPHIR_INIT_NVAR(symbol);
			ZVAL_STRING(symbol, "&raquo;", 1);
			break;
		}
		ZEPHIR_INIT_VAR(_0$$7);
		if (!(zephir_is_true(symbol))) {
			ZEPHIR_CPY_WRT(_0$$7, page);
		} else {
			ZEPHIR_CPY_WRT(_0$$7, symbol);
		}
		ZEPHIR_CPY_WRT(symbol, _0$$7);
		pages = 1;
		break;
	} while(0);

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "liClass", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&liClass, this_ptr, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "spanClass", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&spanClass, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "aClass", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&aClass, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(active)) {
		ZEPHIR_INIT_VAR(_2$$8);
		if (pages) {
			ZEPHIR_INIT_NVAR(_2$$8);
			ZVAL_STRING(_2$$8, "active", 1);
		} else {
			ZEPHIR_INIT_NVAR(_2$$8);
			ZVAL_STRING(_2$$8, "disabled", 1);
		}
		ZEPHIR_INIT_VAR(_3$$8);
		if (zephir_is_true(liClass)) {
			ZEPHIR_INIT_NVAR(_3$$8);
			ZEPHIR_CONCAT_SV(_3$$8, " ", liClass);
		} else {
			ZEPHIR_INIT_NVAR(_3$$8);
			ZVAL_STRING(_3$$8, "", 1);
		}
		ZEPHIR_INIT_VAR(_4$$8);
		if (zephir_is_true(spanClass)) {
			ZEPHIR_INIT_NVAR(_4$$8);
			ZEPHIR_CONCAT_SVS(_4$$8, " class=\"", spanClass, "\"");
		} else {
			ZEPHIR_INIT_NVAR(_4$$8);
			ZVAL_STRING(_4$$8, "", 1);
		}
		ZEPHIR_CONCAT_SVVSVSVS(return_value, "<li class=\"", _2$$8, _3$$8, "\"><span", _4$$8, ">", symbol, "</span></li>");
		RETURN_MM();
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_6, _5, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, _6, "getquery", NULL, 0);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "i18n", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&i18n, _7, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(title);
	if (pages) {
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_VAR(_8$$9);
			zephir_create_array(_8$$9, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_8$$9, page);
			ZEPHIR_INIT_VAR(_9$$9);
			ZVAL_STRING(_9$$9, "page: %d", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _9$$9, _8$$9);
			zephir_check_temp_parameter(_9$$9);
			zephir_check_call_status();
		} else {
			ZVAL_NULL(title);
		}
	} else {
		if (zephir_is_true(i18n)) {
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, page);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		ZEPHIR_CALL_METHOD(&_10$$10, this_ptr, "get", NULL, 107, page);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(page, _10$$10);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "query", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "has", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_12 = zephir_is_true(_11);
	if (_12) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "query", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", NULL, 107, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_12 = !zephir_is_true(_13);
	}
	if (_12) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(url)) {
			_14$$12 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_16$$12);
			ZVAL_STRING(_16$$12, "url", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_15$$12, _14$$12, "get", NULL, 0, _16$$12);
			zephir_check_temp_parameter(_16$$12);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_16$$12);
			ZVAL_BOOL(_16$$12, 0);
			ZEPHIR_CALL_METHOD(&url, _15$$12, "get", NULL, 0, _16$$12);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_17$$11);
		if (zephir_is_true(url)) {
			ZEPHIR_INIT_NVAR(_17$$11);
			ZVAL_STRING(_17$$11, "/", 1);
		} else {
			ZEPHIR_INIT_NVAR(_17$$11);
			ZVAL_STRING(_17$$11, "", 1);
		}
		ZEPHIR_INIT_VAR(_19$$11);
		ZVAL_STRING(_19$$11, "hash", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_18$$11, this_ptr, "get", NULL, 107, _19$$11);
		zephir_check_temp_parameter(_19$$11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_20$$11);
		ZEPHIR_CONCAT_VVV(_20$$11, _17$$11, page, _18$$11);
		zephir_concat_self(&url, _20$$11 TSRMLS_CC);
	} else {
		if (ZEPHIR_GT_LONG(page, 1)) {
			ZEPHIR_INIT_VAR(_21$$14);
			ZVAL_STRING(_21$$14, "page", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, 0, _21$$14, page);
			zephir_check_temp_parameter(_21$$14);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_22$$15);
			ZVAL_STRING(_22$$15, "page", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, query, "remove", NULL, 0, _22$$15);
			zephir_check_temp_parameter(_22$$15);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(_23);
	if (zephir_is_true(liClass)) {
		ZEPHIR_INIT_NVAR(_23);
		ZEPHIR_CONCAT_SVS(_23, " class=\"", liClass, "\"");
	} else {
		ZEPHIR_INIT_NVAR(_23);
		ZVAL_STRING(_23, "", 1);
	}
	_24 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_26);
	zephir_create_array(_26, 5, 0 TSRMLS_CC);
	zephir_array_fast_append(_26, url);
	zephir_array_fast_append(_26, symbol);
	zephir_array_fast_append(_26, title);
	ZEPHIR_CALL_METHOD(&_27, query, "all", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_26, SL("query"), &_27, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_26, SL("class"), &aClass, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_25, _24, "a", NULL, 0, _26);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<li", _23, ">", _25, "</li>");
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
	zval *parameters = NULL, *_1;
	zval *url = NULL, *parameters_param = NULL, *html = NULL, *_0, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_8 = NULL, *_11 = NULL, *_16 = NULL, *_17 = NULL, *_18, *_19 = NULL, *_12$$3 = NULL, *_13$$3 = NULL, *_14$$3 = NULL, *_15$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &url, &parameters_param);

	if (!url) {
		url = ZEPHIR_GLOBAL(global_null);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("class"), SL("pagination"), 1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&html, _0, "taghtml", NULL, 0, _2, parameters, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_BOOL(_6, ZEPHIR_GT(_4, _5));
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "preparebutton", &_7, 0, _2, url, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _3 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_11, _8);
	_10 = 1;
	_9 = 0;
	if (ZEPHIR_GE_LONG(_11, _10)) {
		while (1) {
			if (_9) {
				_10++;
				if (!(ZEPHIR_GE_LONG(_11, _10))) {
					break;
				}
			} else {
				_9 = 1;
			}
			i = _10;
			ZEPHIR_INIT_NVAR(_14$$3);
			ZVAL_STRING(_14$$3, "current", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_13$$3, this_ptr, "get", NULL, 107, _14$$3);
			zephir_check_temp_parameter(_14$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_14$$3);
			ZVAL_LONG(_14$$3, i);
			ZEPHIR_INIT_NVAR(_15$$3);
			ZVAL_BOOL(_15$$3, !ZEPHIR_IS_LONG_IDENTICAL(_13$$3, i));
			ZEPHIR_CALL_METHOD(&_12$$3, this_ptr, "preparebutton", &_7, 0, _14$$3, url, _15$$3);
			zephir_check_call_status();
			zephir_concat_self(&html, _12$$3 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_16, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_BOOL(_6, ZEPHIR_LT(_16, _17));
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "preparebutton", &_7, 0, _2, url, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _8 TSRMLS_CC);
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_19, _18, "endtag", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _19 TSRMLS_CC);
	RETURN_CCTOR(html);

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
	zval *parameters = NULL, *_1;
	zval *url = NULL, *parameters_param = NULL, *html = NULL, *_0, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_14 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL, *_23 = NULL, *_24, *_25 = NULL, *_15$$3 = NULL, *_16$$3 = NULL, *_17$$3 = NULL, *_18$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &url, &parameters_param);

	if (!url) {
		url = ZEPHIR_GLOBAL(global_null);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("class"), SL("pagination"), 1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&html, _0, "taghtml", NULL, 0, _2, parameters, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "first", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "first", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_BOOL(_6, !ZEPHIR_IS_EQUAL(_4, _5));
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "preparebutton", &_7, 0, _2, url, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _3 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_BOOL(_6, ZEPHIR_GT(_9, _10));
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "preparebutton", &_7, 0, _2, url, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _8 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_14, _11);
	_13 = 1;
	_12 = 0;
	if (ZEPHIR_GE_LONG(_14, _13)) {
		while (1) {
			if (_12) {
				_13++;
				if (!(ZEPHIR_GE_LONG(_14, _13))) {
					break;
				}
			} else {
				_12 = 1;
			}
			i = _13;
			ZEPHIR_INIT_NVAR(_17$$3);
			ZVAL_STRING(_17$$3, "current", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_16$$3, this_ptr, "get", NULL, 107, _17$$3);
			zephir_check_temp_parameter(_17$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_17$$3);
			ZVAL_LONG(_17$$3, i);
			ZEPHIR_INIT_NVAR(_18$$3);
			ZVAL_BOOL(_18$$3, !ZEPHIR_IS_LONG_IDENTICAL(_16$$3, i));
			ZEPHIR_CALL_METHOD(&_15$$3, this_ptr, "preparebutton", &_7, 0, _17$$3, url, _18$$3);
			zephir_check_call_status();
			zephir_concat_self(&html, _15$$3 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_19, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_20, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_BOOL(_6, ZEPHIR_LT(_19, _20));
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "preparebutton", &_7, 0, _2, url, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _11 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_22, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "get", NULL, 107, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_BOOL(_6, !ZEPHIR_IS_EQUAL(_22, _23));
	ZEPHIR_CALL_METHOD(&_21, this_ptr, "preparebutton", &_7, 0, _2, url, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _21 TSRMLS_CC);
	_24 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_25, _24, "endtag", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _25 TSRMLS_CC);
	RETURN_CCTOR(html);

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

	HashTable *_39;
	HashPosition _38;
	zend_bool useMiddle = 0, useN3 = 0, useN6 = 0, _10, _13, _15, _20, _25;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_34 = NULL;
	zend_long countOut, countIn, ZEPHIR_LAST_CALL_STATUS, n1 = 0, n3 = 0, n6 = 0, i = 0, _16;
	zval *parameters = NULL, *_30;
	zval *url = NULL, *parameters_param = NULL, *countOut_param = NULL, *countIn_param = NULL, *html = NULL, *links = NULL, *page = NULL, *content = NULL, *n2 = NULL, *n4 = NULL, *n5 = NULL, *n7 = NULL, *n8 = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9, *_11, *_12, *_14, *_17 = NULL, *_21 = NULL, *_22 = NULL, *_26 = NULL, *_27 = NULL, *_29, *_31 = NULL, *_32 = NULL, *_33 = NULL, *_35 = NULL, *_36 = NULL, *_37 = NULL, **_40, *_44 = NULL, *_45 = NULL, *_46 = NULL, *_47 = NULL, *_48 = NULL, *_49 = NULL, *_50, *_51 = NULL, *_18$$4 = NULL, *_19$$5, *_23$$6 = NULL, *_24$$7, *_28$$8 = NULL, *_41$$9 = NULL, *_42$$9 = NULL, *_43$$9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &url, &parameters_param, &countOut_param, &countIn_param);

	if (!url) {
		url = ZEPHIR_GLOBAL(global_null);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
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


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(_0, 2)) {
		RETURN_MM_NULL();
	}
	n1 = 1;
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, countOut);
	ZEPHIR_CALL_FUNCTION(&n2, "min", &_3, 32, _1, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, ((zephir_get_numberval(_4) - countOut) + 1));
	ZEPHIR_CALL_FUNCTION(&n7, "max", &_6, 51, _1, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&n8, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(n2) + 1));
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, (zephir_get_numberval(_7) - countIn));
	ZEPHIR_CALL_FUNCTION(&n4, "max", &_6, 51, _1, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(n7) - 1));
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, (zephir_get_numberval(_8) + countIn));
	ZEPHIR_CALL_FUNCTION(&n5, "min", &_3, 32, _1, _5);
	zephir_check_call_status();
	useMiddle = (ZEPHIR_GE(n5, n4));
	ZEPHIR_INIT_VAR(_9);
	zephir_add_function(_9, n2, n4);
	n3 = (int) zephir_safe_div_zval_long(_9, 2 TSRMLS_CC);
	_10 = useMiddle;
	if (_10) {
		ZEPHIR_INIT_VAR(_11);
		zephir_sub_function(_11, n4, n2);
		_10 = ZEPHIR_GT_LONG(_11, 1);
	}
	useN3 = _10;
	ZEPHIR_INIT_VAR(_12);
	zephir_add_function(_12, n5, n7);
	n6 = (int) zephir_safe_div_zval_long(_12, 2 TSRMLS_CC);
	_13 = useMiddle;
	if (_13) {
		ZEPHIR_INIT_VAR(_14);
		zephir_sub_function(_14, n7, n5);
		_13 = ZEPHIR_GT_LONG(_14, 1);
	}
	useN6 = _13;
	ZEPHIR_INIT_VAR(links);
	array_init(links);
	ZEPHIR_CPY_WRT(_17, n2);
	_16 = n1;
	_15 = 0;
	if (ZEPHIR_GE_LONG(_17, _16)) {
		while (1) {
			if (_15) {
				_16++;
				if (!(ZEPHIR_GE_LONG(_17, _16))) {
					break;
				}
			} else {
				_15 = 1;
			}
			i = _16;
			ZEPHIR_INIT_NVAR(_18$$4);
			ZVAL_LONG(_18$$4, i);
			zephir_array_update_long(&links, i, &_18$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	if (useN3) {
		ZEPHIR_INIT_VAR(_19$$5);
		ZVAL_STRING(_19$$5, "&hellip;", 1);
		zephir_array_update_long(&links, n3, &_19$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_CPY_WRT(_22, n5);
	ZEPHIR_CPY_WRT(_21, n4);
	_20 = 0;
	if (ZEPHIR_LE(_21, _22)) {
		while (1) {
			if (_20) {
				ZEPHIR_SEPARATE(_21);
				zephir_increment(_21);
				if (!(ZEPHIR_LE(_21, _22))) {
					break;
				}
			} else {
				_20 = 1;
			}
			i = zephir_get_numberval(_21);
			ZEPHIR_INIT_NVAR(_23$$6);
			ZVAL_LONG(_23$$6, i);
			zephir_array_update_long(&links, i, &_23$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	if (useN6) {
		ZEPHIR_INIT_VAR(_24$$7);
		ZVAL_STRING(_24$$7, "&hellip;", 1);
		zephir_array_update_long(&links, n6, &_24$$7, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_CPY_WRT(_27, n8);
	ZEPHIR_CPY_WRT(_26, n7);
	_25 = 0;
	if (ZEPHIR_LE(_26, _27)) {
		while (1) {
			if (_25) {
				ZEPHIR_SEPARATE(_26);
				zephir_increment(_26);
				if (!(ZEPHIR_LE(_26, _27))) {
					break;
				}
			} else {
				_25 = 1;
			}
			i = zephir_get_numberval(_26);
			ZEPHIR_INIT_NVAR(_28$$8);
			ZVAL_LONG(_28$$8, i);
			zephir_array_update_long(&links, i, &_28$$8, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	_29 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_30);
	zephir_create_array(_30, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_30, SS("class"), SL("pagination"), 1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&html, _29, "taghtml", NULL, 0, _1, parameters, _30);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_32, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "first", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "first", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_BOOL(_5, !ZEPHIR_IS_EQUAL(_32, _33));
	ZEPHIR_CALL_METHOD(&_31, this_ptr, "preparebutton", &_34, 0, _1, url, _5);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_concat_self(&html, _31 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_36, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_BOOL(_5, ZEPHIR_GT(_36, _37));
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "preparebutton", &_34, 0, _1, url, _5);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_concat_self(&html, _35 TSRMLS_CC);
	zephir_is_iterable(links, &_39, &_38, 0, 0, "ice/pagination.zep", 321);
	for (
	  ; zend_hash_get_current_data_ex(_39, (void**) &_40, &_38) == SUCCESS
	  ; zend_hash_move_forward_ex(_39, &_38)
	) {
		ZEPHIR_GET_HMKEY(page, _39, _38);
		ZEPHIR_GET_HVALUE(content, _40);
		ZEPHIR_INIT_NVAR(_43$$9);
		ZVAL_STRING(_43$$9, "current", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_42$$9, this_ptr, "get", NULL, 107, _43$$9);
		zephir_check_temp_parameter(_43$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_43$$9);
		ZVAL_BOOL(_43$$9, !ZEPHIR_IS_IDENTICAL(page, _42$$9));
		ZEPHIR_CALL_METHOD(&_41$$9, this_ptr, "preparebutton", &_34, 0, page, url, _43$$9, content);
		zephir_check_call_status();
		zephir_concat_self(&html, _41$$9 TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_45, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_46, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_BOOL(_5, ZEPHIR_LT(_45, _46));
	ZEPHIR_CALL_METHOD(&_44, this_ptr, "preparebutton", &_34, 0, _1, url, _5);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_concat_self(&html, _44 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_48, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_49, this_ptr, "get", NULL, 107, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_BOOL(_5, !ZEPHIR_IS_EQUAL(_48, _49));
	ZEPHIR_CALL_METHOD(&_47, this_ptr, "preparebutton", &_34, 0, _1, url, _5);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_concat_self(&html, _47 TSRMLS_CC);
	_50 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_51, _50, "endtag", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_concat_self(&html, _51 TSRMLS_CC);
	RETURN_CCTOR(html);

}

