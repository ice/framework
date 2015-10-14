
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
#include "kernel/hash.h"


/**
 * Provide the multi-page pagination component.
 *
 * @package     Ice/Pagination
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
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


	RETURN_MEMBER(this_ptr, "di");

}

PHP_METHOD(Ice_Pagination, getTag) {


	RETURN_MEMBER(this_ptr, "tag");

}

/**
 * Pagination constructor. Fetch di and tag.
 *
 * @param array options
 */
PHP_METHOD(Ice_Pagination, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zval *options_param = NULL, *di = NULL, *_2 = NULL, *_3, *_4, *_5;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, ice_pagination_ce, this_ptr, "__construct", &_0, 6, options);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_1, 8);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_BOOL(_5, 1);
	ZEPHIR_CALL_METHOD(&_2, di, "get", NULL, 0, _3, _4, _5);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("tag"), _2 TSRMLS_CC);
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
	int limit = 0, page = 0, pages = 0, total = 0, previous = 0, next = 0, ZEPHIR_LAST_CALL_STATUS;
	zval *items = NULL, *data = NULL, *_0, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, _7, _8, _9, *_10 = NULL;

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
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", NULL, 27, _1, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	limit = zephir_get_intval(_3);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "page", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 1);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 27, _1, _4);
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
	ZEPHIR_CALL_FUNCTION(&_10, "array_slice", NULL, 95, data, &_8, &_9);
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
 * @param string url URL with pagination
 * @param boolean active If active create link else span
 * @param string symbol HTML symbol to add
 * @return string HTML
 */
PHP_METHOD(Ice_Pagination, prepareButton) {

	zval *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool active, pages, _9;
	zval *url = NULL;
	zval *page = NULL, *url_param = NULL, *active_param = NULL, *symbol = NULL, *query = NULL, *i18n = NULL, *title = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5, *_6, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_12, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &page, &url_param, &active_param, &symbol);

	ZEPHIR_SEPARATE_PARAM(page);
	if (!url_param) {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	} else {
		zephir_get_strval(url, url_param);
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
		ZEPHIR_INIT_VAR(_0);
		if (!(zephir_is_true(symbol))) {
			ZEPHIR_CPY_WRT(_0, page);
		} else {
			ZEPHIR_CPY_WRT(_0, symbol);
		}
		ZEPHIR_CPY_WRT(symbol, _0);
		pages = 1;
		break;
	} while(0);

	if (!(active)) {
		ZEPHIR_INIT_LNVAR(_0);
		if (pages) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "active", 1);
		} else {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "disabled", 1);
		}
		ZEPHIR_CONCAT_SVSVS(return_value, "<li class=\"", _0, "\"><span>", symbol, "</span></li>");
		RETURN_MM();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_BOOL(_5, 1);
	ZEPHIR_CALL_METHOD(&_2, _1, "get", NULL, 0, _3, _4, _5);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, _2, "getquery", NULL, 0);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "i18n", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&i18n, _6, "get", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(title);
	if (pages) {
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_VAR(_7);
			zephir_create_array(_7, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_7, page);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "page: %d", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _3, _7);
			zephir_check_temp_parameter(_3);
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
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, 0, page);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(page, _8);
	}
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "query", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "has", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	_9 = zephir_is_true(_8);
	if (_9) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "query", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", NULL, 27, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		_9 = !zephir_is_true(_10);
	}
	if (_9) {
		ZEPHIR_INIT_LNVAR(_0);
		if (!(!url) && Z_STRLEN_P(url)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "/", 1);
		} else {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "", 1);
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "hash", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, 27, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_12);
		ZEPHIR_CONCAT_VVV(_12, _0, page, _11);
		zephir_concat_self(&url, _12 TSRMLS_CC);
	} else {
		if (ZEPHIR_GT_LONG(page, 1)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "page", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, 0, _3, page);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "page", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, query, "remove", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		}
	}
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_7);
	zephir_create_array(_7, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(_7, url);
	zephir_array_fast_append(_7, symbol);
	zephir_array_fast_append(_7, title);
	ZEPHIR_CALL_METHOD(&_11, query, "all", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_7, SL("query"), &_11, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_8, _13, "a", NULL, 0, _7);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<li>", _8, "</li>");
	RETURN_MM();

}

/**
 * Prepare minimal pagination.
 * Previous 1 [2] 3 4 5 6 Next
 *
 * @param string url URL with pagination
 * @param string parameters UL attributes to adding
 * @return string HTML
 */
PHP_METHOD(Ice_Pagination, minimal) {

	zend_bool _9;
	zephir_fcall_cache_entry *_7 = NULL;
	int i = 0, ZEPHIR_LAST_CALL_STATUS, _10;
	zval *parameters = NULL, *_1;
	zval *url_param = NULL, *parameters_param = NULL, *html = NULL, *_0, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_8 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15, *_16 = NULL;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &url_param, &parameters_param);

	if (!url_param) {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	} else {
		zephir_get_strval(url, url_param);
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
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 27, _2);
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
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, 27, _2);
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
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_12, this_ptr, "get", NULL, 27, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, i);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_BOOL(_6, !ZEPHIR_IS_LONG_IDENTICAL(_12, i));
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "preparebutton", &_7, 0, _2, url, _6);
			zephir_check_call_status();
			zephir_concat_self(&html, _8 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", NULL, 27, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "get", NULL, 27, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_BOOL(_6, ZEPHIR_LT(_13, _14));
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "preparebutton", &_7, 0, _2, url, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _12 TSRMLS_CC);
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_16, _15, "endtag", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _16 TSRMLS_CC);
	RETURN_CCTOR(html);

}

/**
 * Prepare basic pagination.
 * First Previous 1 [2] 3 4 5 6 Next Last
 *
 * @param string url URL with pagination
 * @param string parameters UL attributes to adding
 * @return string HTML
 */
PHP_METHOD(Ice_Pagination, basic) {

	zend_bool _12;
	zephir_fcall_cache_entry *_7 = NULL;
	int i = 0, ZEPHIR_LAST_CALL_STATUS, _13;
	zval *parameters = NULL, *_1;
	zval *url_param = NULL, *parameters_param = NULL, *html = NULL, *_0, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_21, *_22 = NULL;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &url_param, &parameters_param);

	if (!url_param) {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	} else {
		zephir_get_strval(url, url_param);
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
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 27, _2);
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
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", NULL, 27, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", NULL, 27, _2);
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
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, 27, _2);
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
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_15, this_ptr, "get", NULL, 27, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, i);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_BOOL(_6, !ZEPHIR_IS_LONG_IDENTICAL(_15, i));
			ZEPHIR_CALL_METHOD(&_11, this_ptr, "preparebutton", &_7, 0, _2, url, _6);
			zephir_check_call_status();
			zephir_concat_self(&html, _11 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_16, this_ptr, "get", NULL, 27, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "get", NULL, 27, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_BOOL(_6, ZEPHIR_LT(_16, _17));
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "preparebutton", &_7, 0, _2, url, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _15 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_19, this_ptr, "get", NULL, 27, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_20, this_ptr, "get", NULL, 27, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_BOOL(_6, !ZEPHIR_IS_EQUAL(_19, _20));
	ZEPHIR_CALL_METHOD(&_18, this_ptr, "preparebutton", &_7, 0, _2, url, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _18 TSRMLS_CC);
	_21 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_22, _21, "endtag", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _22 TSRMLS_CC);
	RETURN_CCTOR(html);

}

/**
 * Prepare floating pagination.
 * First Previous 1 2 3 ... 23 24 25 26 [27] 28 29 30 31 ... 48 49 50 Next Last
 *
 * @param string url URL with pagination
 * @param string parameters UL attributes to adding
 * @param int countOut Number of page links in the begin and end of whole range
 * @param int countIn Number of page links on each side of current page
 * @return string HTML
 */
PHP_METHOD(Ice_Pagination, floating) {

	HashTable *_36;
	HashPosition _35;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_31 = NULL;
	zend_bool useMiddle = 0, useN3 = 0, useN6 = 0, _10, _13, _15, _18, _22;
	int countOut, countIn, n1 = 0, n3 = 0, n6 = 0, i = 0, ZEPHIR_LAST_CALL_STATUS, _16;
	zval *parameters = NULL, *_26;
	zval *url_param = NULL, *parameters_param = NULL, *countOut_param = NULL, *countIn_param = NULL, *html = NULL, *links = NULL, *page = NULL, *content = NULL, *n2 = NULL, *n4 = NULL, *n5 = NULL, *n7 = NULL, *n8 = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9, *_11, *_12, *_14, *_17 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_23 = NULL, *_24 = NULL, *_25, *_27 = NULL, *_28 = NULL, *_29 = NULL, *_30 = NULL, *_32 = NULL, *_33 = NULL, *_34 = NULL, **_37, *_38 = NULL, *_39 = NULL, *_40 = NULL, *_41 = NULL, *_42 = NULL, *_43 = NULL, *_44, *_45 = NULL;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &url_param, &parameters_param, &countOut_param, &countIn_param);

	if (!url_param) {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	} else {
		zephir_get_strval(url, url_param);
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
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "get", NULL, 27, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, countOut);
	ZEPHIR_CALL_FUNCTION(&n2, "min", &_3, 151, _1, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 27, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, ((zephir_get_numberval(_4) - countOut) + 1));
	ZEPHIR_CALL_FUNCTION(&n7, "max", &_6, 32, _1, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&n8, this_ptr, "get", NULL, 27, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "get", NULL, 27, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(n2) + 1));
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, (zephir_get_numberval(_7) - countIn));
	ZEPHIR_CALL_FUNCTION(&n4, "max", &_6, 32, _1, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, 27, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(n7) - 1));
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, (zephir_get_numberval(_8) + countIn));
	ZEPHIR_CALL_FUNCTION(&n5, "min", &_3, 151, _1, _5);
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
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, i);
			zephir_array_update_long(&links, i, &_1, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	if (useN3) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "&hellip;", 1);
		zephir_array_update_long(&links, n3, &_5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_CPY_WRT(_20, n5);
	ZEPHIR_CPY_WRT(_19, n4);
	_18 = 0;
	if (ZEPHIR_LE(_19, _20)) {
		while (1) {
			if (_18) {
				ZEPHIR_SEPARATE(_19);
				zephir_increment(_19);
				if (!(ZEPHIR_LE(_19, _20))) {
					break;
				}
			} else {
				_18 = 1;
			}
			i = zephir_get_numberval(_19);
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_LONG(_21, i);
			zephir_array_update_long(&links, i, &_21, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	if (useN6) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&hellip;", 1);
		zephir_array_update_long(&links, n6, &_21, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_CPY_WRT(_24, n8);
	ZEPHIR_CPY_WRT(_23, n7);
	_22 = 0;
	if (ZEPHIR_LE(_23, _24)) {
		while (1) {
			if (_22) {
				ZEPHIR_SEPARATE(_23);
				zephir_increment(_23);
				if (!(ZEPHIR_LE(_23, _24))) {
					break;
				}
			} else {
				_22 = 1;
			}
			i = zephir_get_numberval(_23);
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_LONG(_21, i);
			zephir_array_update_long(&links, i, &_21, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	_25 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_26);
	zephir_create_array(_26, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_26, SS("class"), SL("pagination"), 1);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&html, _25, "taghtml", NULL, 0, _21, parameters, _26);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_28, this_ptr, "get", NULL, 27, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "first", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_29, this_ptr, "get", NULL, 27, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "first", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_30);
	ZVAL_BOOL(_30, !ZEPHIR_IS_EQUAL(_28, _29));
	ZEPHIR_CALL_METHOD(&_27, this_ptr, "preparebutton", &_31, 0, _21, url, _30);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	zephir_concat_self(&html, _27 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "get", NULL, 27, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_34, this_ptr, "get", NULL, 27, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_30);
	ZVAL_BOOL(_30, ZEPHIR_GT(_33, _34));
	ZEPHIR_CALL_METHOD(&_32, this_ptr, "preparebutton", &_31, 0, _21, url, _30);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	zephir_concat_self(&html, _32 TSRMLS_CC);
	zephir_is_iterable(links, &_36, &_35, 0, 0, "ice/pagination.zep", 312);
	for (
	  ; zephir_hash_get_current_data_ex(_36, (void**) &_37, &_35) == SUCCESS
	  ; zephir_hash_move_forward_ex(_36, &_35)
	) {
		ZEPHIR_GET_HMKEY(page, _36, _35);
		ZEPHIR_GET_HVALUE(content, _37);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_39, this_ptr, "get", NULL, 27, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_BOOL(_21, !ZEPHIR_IS_IDENTICAL(page, _39));
		ZEPHIR_CALL_METHOD(&_38, this_ptr, "preparebutton", &_31, 0, page, url, _21, content);
		zephir_check_call_status();
		zephir_concat_self(&html, _38 TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_39, this_ptr, "get", NULL, 27, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_40, this_ptr, "get", NULL, 27, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_30);
	ZVAL_BOOL(_30, ZEPHIR_LT(_39, _40));
	ZEPHIR_CALL_METHOD(&_38, this_ptr, "preparebutton", &_31, 0, _21, url, _30);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	zephir_concat_self(&html, _38 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_42, this_ptr, "get", NULL, 27, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_43, this_ptr, "get", NULL, 27, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_30);
	ZVAL_BOOL(_30, !ZEPHIR_IS_EQUAL(_42, _43));
	ZEPHIR_CALL_METHOD(&_41, this_ptr, "preparebutton", &_31, 0, _21, url, _30);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	zephir_concat_self(&html, _41 TSRMLS_CC);
	_44 = zephir_fetch_nproperty_this(this_ptr, SL("tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_45, _44, "endtag", NULL, 0, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	zephir_concat_self(&html, _45 TSRMLS_CC);
	RETURN_CCTOR(html);

}

