
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

	zend_declare_property_null(ice_pagination_ce, SL("_di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_pagination_ce, SL("_tag"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Pagination, getDi) {


	RETURN_MEMBER(this_ptr, "_di");

}

PHP_METHOD(Ice_Pagination, getTag) {


	RETURN_MEMBER(this_ptr, "_tag");

}

/**
 * Pagination constructor. Fetch di and tag.
 *
 * @param array options
 */
PHP_METHOD(Ice_Pagination, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zval *options_param = NULL, *di = NULL, *_2 = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, ice_pagination_ce, this_ptr, "__construct", &_0, options);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_di"), di TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, di, "gettag", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_tag"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a slice of the resultset to show in the pagination.
 *
 * @return object Pagination
 */
PHP_METHOD(Ice_Pagination, calculate) {

	zval *_13;
	zephir_nts_static zephir_fcall_cache_entry *_11 = NULL;
	zend_bool _2;
	int limit, page, pages, total, previous, next, ZEPHIR_LAST_CALL_STATUS;
	zval *items = NULL, *data = NULL, *_0, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, _6, _7, _8, _9, *_10 = NULL, *_12;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "data", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&items, this_ptr, "get", NULL, _1, _0);
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
		ZEPHIR_CALL_METHOD(&data, items, "all", NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(data, items);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "limit", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 10);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", NULL, _1, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	limit = zephir_get_intval(_3);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "page", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 1);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, _1, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	page = zephir_get_intval(_5);
	total = zephir_fast_count_int(items TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, limit);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_DOUBLE(&_7, zephir_safe_div_long_long(total, zephir_get_intval(&_6) TSRMLS_CC));
	zephir_ceil(_1, &_7 TSRMLS_CC);
	pages = zephir_get_intval(_1);
	if (page <= 0) {
		page = 1;
	}
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, (limit * ((page - 1))));
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, limit);
	ZEPHIR_CALL_FUNCTION(&_10, "array_slice", &_11, data, &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "items", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, _4, _10);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (page < pages) {
		next = (page + 1);
	} else {
		next = pages;
	}
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_LONG(_12, next);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, _4, _12);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (page > 1) {
		previous = (page - 1);
	} else {
		previous = 1;
	}
	ZEPHIR_INIT_VAR(_13);
	zephir_create_array(_13, 6, 0 TSRMLS_CC);
	add_assoc_long_ex(_13, SS("first"), 1);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, previous);
	zephir_array_update_string(&_13, SL("previous"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, page);
	zephir_array_update_string(&_13, SL("current"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, pages);
	zephir_array_update_string(&_13, SL("last"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, pages);
	zephir_array_update_string(&_13, SL("pages"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, total);
	zephir_array_update_string(&_13, SL("total"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, _13);
	zephir_check_call_status();
	RETURN_THIS();

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

	zephir_fcall_cache_entry *_17 = NULL, *_19 = NULL, *_20 = NULL, *_22 = NULL, *_23 = NULL;
	zend_bool _14;
	int i, ZEPHIR_LAST_CALL_STATUS, _15;
	zval *parameters = NULL, *_1, *_11 = NULL, *_21 = NULL;
	zval *url_param = NULL, *parameters_param = NULL, *html = NULL, *query = NULL, *i18n = NULL, *title = NULL, *_0, *_2 = NULL, *_3, *_4 = NULL, *_5, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9, *_10 = NULL, *_12 = NULL, *_13 = NULL, *_16 = NULL, *_18 = NULL, _24 = zval_used_for_init, *_25 = NULL, *_26 = NULL, *_27 = NULL;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("class"), SL("pagination"), 1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&html, _0, "taghtml", NULL, _2, parameters, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "getrequest", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, _4, "getquery", NULL);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "i18n", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&i18n, _5, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (ZEPHIR_GT(_6, _7)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _2, _8);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_11);
		zephir_create_array(_11, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_11, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&lsaquo;", 1);
		zephir_array_fast_append(_11, _2);
		zephir_array_fast_append(_11, title);
		ZEPHIR_CALL_METHOD(&_12, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_11, SL("query"), &_12, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_11, SS("rel"), SL("prev"), 1);
		ZEPHIR_CALL_METHOD(&_10, _9, "a", NULL, _11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_13);
		ZEPHIR_CONCAT_SVS(_13, "<li>", _10, "</li>");
		zephir_concat_self(&html, _13 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&lsaquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_16, _8);
	_15 = 1;
	_14 = 0;
	if (ZEPHIR_GE_LONG(_16, _15)) {
		while (1) {
			if (_14) {
				_15++;
				if (!(ZEPHIR_GE_LONG(_16, _15))) {
					break;
				}
			} else {
				_14 = 1;
			}
			i = _15;
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", &_17, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(title);
			if (!ZEPHIR_IS_LONG_IDENTICAL(_8, i)) {
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_LONG(_18, i);
				ZEPHIR_CALL_METHOD(NULL, query, "set", &_19, _2, _18);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				if (zephir_is_true(i18n)) {
					ZEPHIR_INIT_NVAR(_11);
					zephir_create_array(_11, 1, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_LONG(_2, i);
					zephir_array_fast_append(_11, _2);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "page: %d", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_20, _2, _11);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
				} else {
					ZVAL_NULL(title);
				}
				_9 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_21);
				zephir_create_array(_21, 4, 0 TSRMLS_CC);
				zephir_array_fast_append(_21, url);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_LONG(_2, i);
				zephir_array_fast_append(_21, _2);
				zephir_array_fast_append(_21, title);
				ZEPHIR_CALL_METHOD(&_12, query, "all", &_22);
				zephir_check_call_status();
				zephir_array_update_string(&_21, SL("query"), &_12, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_10, _9, "a", NULL, _21);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_SVS(_13, "<li>", _10, "</li>");
				zephir_concat_self(&html, _13 TSRMLS_CC);
			} else {
				if (zephir_is_true(i18n)) {
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_23, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(title);
					ZVAL_NULL(title);
				}
				ZEPHIR_SINIT_NVAR(_24);
				ZVAL_LONG(&_24, i);
				ZEPHIR_INIT_LNVAR(_25);
				ZEPHIR_CONCAT_SVSVS(_25, "<li class=\"active\" title=\"", title, "\"><span>", &_24, "</span></li>");
				zephir_concat_self(&html, _25 TSRMLS_CC);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", &_17, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", &_17, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (ZEPHIR_LT(_8, _10)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "get", &_17, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _2, _12);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_11);
		zephir_create_array(_11, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_11, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&rsaquo;", 1);
		zephir_array_fast_append(_11, _2);
		zephir_array_fast_append(_11, title);
		ZEPHIR_CALL_METHOD(&_27, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_11, SL("query"), &_27, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_11, SS("rel"), SL("next"), 1);
		ZEPHIR_CALL_METHOD(&_26, _9, "a", NULL, _11);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_13);
		ZEPHIR_CONCAT_SVS(_13, "<li>", _26, "</li>");
		zephir_concat_self(&html, _13 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&rsaquo;</span></li>") TSRMLS_CC);
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, _9, "endtag", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _8 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_19 = NULL, *_21 = NULL, *_22 = NULL, *_24 = NULL, *_25 = NULL;
	zend_bool _16;
	int i, ZEPHIR_LAST_CALL_STATUS, _17;
	zval *parameters = NULL, *_1, *_10 = NULL, *_23 = NULL;
	zval *url_param = NULL, *parameters_param = NULL, *html = NULL, *query = NULL, *i18n = NULL, *title = NULL, *_0, *_2 = NULL, *_3, *_4 = NULL, *_5, *_6 = NULL, *_7 = NULL, *_8, *_9 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_18 = NULL, *_20 = NULL, _26 = zval_used_for_init, *_27 = NULL;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("class"), SL("pagination"), 1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&html, _0, "taghtml", NULL, _2, parameters, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "getrequest", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, _4, "getquery", NULL);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "i18n", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&i18n, _5, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "first", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_6, _7)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "remove", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "first", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_10);
		zephir_create_array(_10, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_10, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&laquo;", 1);
		zephir_array_fast_append(_10, _2);
		zephir_array_fast_append(_10, title);
		ZEPHIR_CALL_METHOD(&_11, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_10, SL("query"), &_11, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_10, SS("rel"), SL("first"), 1);
		ZEPHIR_CALL_METHOD(&_9, _8, "a", NULL, _10);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_12);
		ZEPHIR_CONCAT_SVS(_12, "<li>", _9, "</li>");
		zephir_concat_self(&html, _12 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&laquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (ZEPHIR_GT(_9, _11)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _2, _13);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_10);
		zephir_create_array(_10, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_10, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&lsaquo;", 1);
		zephir_array_fast_append(_10, _2);
		zephir_array_fast_append(_10, title);
		ZEPHIR_CALL_METHOD(&_15, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_10, SL("query"), &_15, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_10, SS("rel"), SL("prev"), 1);
		ZEPHIR_CALL_METHOD(&_14, _8, "a", NULL, _10);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_12);
		ZEPHIR_CONCAT_SVS(_12, "<li>", _14, "</li>");
		zephir_concat_self(&html, _12 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&lsaquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_18, _9);
	_17 = 1;
	_16 = 0;
	if (ZEPHIR_GE_LONG(_18, _17)) {
		while (1) {
			if (_16) {
				_17++;
				if (!(ZEPHIR_GE_LONG(_18, _17))) {
					break;
				}
			} else {
				_16 = 1;
			}
			i = _17;
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", &_19, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(title);
			if (!ZEPHIR_IS_LONG_IDENTICAL(_9, i)) {
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_20);
				ZVAL_LONG(_20, i);
				ZEPHIR_CALL_METHOD(NULL, query, "set", &_21, _2, _20);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				if (zephir_is_true(i18n)) {
					ZEPHIR_INIT_NVAR(_10);
					zephir_create_array(_10, 1, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_LONG(_2, i);
					zephir_array_fast_append(_10, _2);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "page: %d", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_22, _2, _10);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
				} else {
					ZVAL_NULL(title);
				}
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_23);
				zephir_create_array(_23, 4, 0 TSRMLS_CC);
				zephir_array_fast_append(_23, url);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_LONG(_2, i);
				zephir_array_fast_append(_23, _2);
				zephir_array_fast_append(_23, title);
				ZEPHIR_CALL_METHOD(&_13, query, "all", &_24);
				zephir_check_call_status();
				zephir_array_update_string(&_23, SL("query"), &_13, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_11, _8, "a", NULL, _23);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_12);
				ZEPHIR_CONCAT_SVS(_12, "<li>", _11, "</li>");
				zephir_concat_self(&html, _12 TSRMLS_CC);
			} else {
				if (zephir_is_true(i18n)) {
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_25, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(title);
					ZVAL_NULL(title);
				}
				ZEPHIR_SINIT_NVAR(_26);
				ZVAL_LONG(&_26, i);
				ZEPHIR_INIT_LNVAR(_27);
				ZEPHIR_CONCAT_SVSVS(_27, "<li class=\"active\" title=\"", title, "\"><span>", &_26, "</span></li>");
				zephir_concat_self(&html, _27 TSRMLS_CC);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", &_19, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", &_19, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (ZEPHIR_LT(_9, _11)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", &_19, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _2, _13);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_10);
		zephir_create_array(_10, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_10, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&rsaquo;", 1);
		zephir_array_fast_append(_10, _2);
		zephir_array_fast_append(_10, title);
		ZEPHIR_CALL_METHOD(&_15, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_10, SL("query"), &_15, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_10, SS("rel"), SL("next"), 1);
		ZEPHIR_CALL_METHOD(&_14, _8, "a", NULL, _10);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_12);
		ZEPHIR_CONCAT_SVS(_12, "<li>", _14, "</li>");
		zephir_concat_self(&html, _12 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&rsaquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", &_19, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", &_19, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_9, _11)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "last", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", &_19, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _2, _13);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "last", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_10);
		zephir_create_array(_10, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_10, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&raquo;", 1);
		zephir_array_fast_append(_10, _2);
		zephir_array_fast_append(_10, title);
		ZEPHIR_CALL_METHOD(&_15, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_10, SL("query"), &_15, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_10, SS("rel"), SL("last"), 1);
		ZEPHIR_CALL_METHOD(&_14, _8, "a", NULL, _10);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_12);
		ZEPHIR_CONCAT_SVS(_12, "<li>", _14, "</li>");
		zephir_concat_self(&html, _12 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&raquo;</span></li>") TSRMLS_CC);
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, _8, "endtag", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _9 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_43 = NULL, *_44 = NULL, *_45 = NULL, *_47 = NULL, *_48 = NULL;
	HashTable *_41;
	HashPosition _40;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	zend_bool useMiddle, useN3, useN6, _10, _13, _15, _18, _22;
	int countOut, countIn, n1, n3, n6, i, ZEPHIR_LAST_CALL_STATUS, _16;
	zval *parameters = NULL, *_26, *_34 = NULL, *_46 = NULL;
	zval *url_param = NULL, *parameters_param = NULL, *countOut_param = NULL, *countIn_param = NULL, *html = NULL, *query = NULL, *i18n = NULL, *title = NULL, *links, *number = NULL, *content = NULL, *n2 = NULL, *n4 = NULL, *n5 = NULL, *n7 = NULL, *n8 = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9, *_11, *_12, *_14, *_17 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_23 = NULL, *_24 = NULL, *_25, *_27, *_28 = NULL, *_29, *_30 = NULL, *_31 = NULL, *_32, *_33 = NULL, *_35 = NULL, *_36 = NULL, *_37 = NULL, *_38 = NULL, *_39 = NULL, **_42, *_49 = NULL;
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(_0, 2)) {
		RETURN_MM_NULL();
	}
	n1 = 1;
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, countOut);
	ZEPHIR_CALL_FUNCTION(&n2, "min", &_3, _1, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, ((zephir_get_numberval(_4) - countOut) + 1));
	ZEPHIR_CALL_FUNCTION(&n7, "max", &_6, _1, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&n8, this_ptr, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(n2) + 1));
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, (zephir_get_numberval(_7) - countIn));
	ZEPHIR_CALL_FUNCTION(&n4, "max", &_6, _1, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(n7) - 1));
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, (zephir_get_numberval(_8) + countIn));
	ZEPHIR_CALL_FUNCTION(&n5, "min", &_3, _1, _5);
	zephir_check_call_status();
	useMiddle = (ZEPHIR_GE(n5, n4));
	ZEPHIR_INIT_VAR(_9);
	zephir_add_function_ex(_9, n2, n4 TSRMLS_CC);
	n3 = (int) zephir_safe_div_zval_long(_9, 2 TSRMLS_CC);
	_10 = useMiddle;
	if (_10) {
		ZEPHIR_INIT_VAR(_11);
		sub_function(_11, n4, n2 TSRMLS_CC);
		_10 = ZEPHIR_GT_LONG(_11, 1);
	}
	useN3 = _10;
	ZEPHIR_INIT_VAR(_12);
	zephir_add_function_ex(_12, n5, n7 TSRMLS_CC);
	n6 = (int) zephir_safe_div_zval_long(_12, 2 TSRMLS_CC);
	_13 = useMiddle;
	if (_13) {
		ZEPHIR_INIT_VAR(_14);
		sub_function(_14, n7, n5 TSRMLS_CC);
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
			zephir_array_update_long(&links, i, &_1, PH_COPY | PH_SEPARATE, "ice/pagination.zep", 278);
		}
	}
	if (useN3) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "&hellip;", 1);
		zephir_array_update_long(&links, n3, &_5, PH_COPY | PH_SEPARATE, "ice/pagination.zep", 282);
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
			zephir_array_update_long(&links, i, &_21, PH_COPY | PH_SEPARATE, "ice/pagination.zep", 286);
		}
	}
	if (useN6) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&hellip;", 1);
		zephir_array_update_long(&links, n6, &_21, PH_COPY | PH_SEPARATE, "ice/pagination.zep", 290);
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
			zephir_array_update_long(&links, i, &_21, PH_COPY | PH_SEPARATE, "ice/pagination.zep", 294);
		}
	}
	_25 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_26);
	zephir_create_array(_26, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_26, SS("class"), SL("pagination"), 1);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&html, _25, "taghtml", NULL, _21, parameters, _26);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	_27 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_28, _27, "getrequest", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, _28, "getquery", NULL);
	zephir_check_call_status();
	_29 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "i18n", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&i18n, _29, "get", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_30, this_ptr, "get", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "first", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_31, this_ptr, "get", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_30, _31)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "remove", NULL, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_STRING(_21, "first", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, _21);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_32 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_34);
		zephir_create_array(_34, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_34, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&laquo;", 1);
		zephir_array_fast_append(_34, _21);
		zephir_array_fast_append(_34, title);
		ZEPHIR_CALL_METHOD(&_35, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_34, SL("query"), &_35, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_34, SS("rel"), SL("first"), 1);
		ZEPHIR_CALL_METHOD(&_33, _32, "a", NULL, _34);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_36);
		ZEPHIR_CONCAT_SVS(_36, "<li>", _33, "</li>");
		zephir_concat_self(&html, _36 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&laquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "get", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (ZEPHIR_GT(_33, _35)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "previous", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", NULL, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _21, _37);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_STRING(_21, "previous", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, _21);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_32 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_34);
		zephir_create_array(_34, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_34, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&lsaquo;", 1);
		zephir_array_fast_append(_34, _21);
		zephir_array_fast_append(_34, title);
		ZEPHIR_CALL_METHOD(&_39, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_34, SL("query"), &_39, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_34, SS("rel"), SL("prev"), 1);
		ZEPHIR_CALL_METHOD(&_38, _32, "a", NULL, _34);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_36);
		ZEPHIR_CONCAT_SVS(_36, "<li>", _38, "</li>");
		zephir_concat_self(&html, _36 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&lsaquo;</span></li>") TSRMLS_CC);
	}
	zephir_is_iterable(links, &_41, &_40, 0, 0, "ice/pagination.zep", 336);
	for (
	  ; zephir_hash_get_current_data_ex(_41, (void**) &_42, &_40) == SUCCESS
	  ; zephir_hash_move_forward_ex(_41, &_40)
	) {
		ZEPHIR_GET_HMKEY(number, _41, _40);
		ZEPHIR_GET_HVALUE(content, _42);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_33, this_ptr, "get", &_43, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(title);
		if (!ZEPHIR_IS_IDENTICAL(number, _33)) {
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, query, "set", &_44, _21, number);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
			if (zephir_is_true(i18n)) {
				ZEPHIR_INIT_NVAR(_34);
				zephir_create_array(_34, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_34, number);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_STRING(_21, "page: %d", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_45, _21, _34);
				zephir_check_temp_parameter(_21);
				zephir_check_call_status();
			} else {
				ZVAL_NULL(title);
			}
			_32 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_46);
			zephir_create_array(_46, 5, 0 TSRMLS_CC);
			zephir_array_fast_append(_46, url);
			zephir_array_fast_append(_46, content);
			zephir_array_fast_append(_46, title);
			ZEPHIR_CALL_METHOD(&_37, query, "all", &_47);
			zephir_check_call_status();
			zephir_array_update_string(&_46, SL("query"), &_37, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_LNVAR(_36);
			if (ZEPHIR_IS_STRING(content, "&hellip;")) {
				ZEPHIR_INIT_NVAR(_36);
				ZVAL_STRING(_36, "text-muted", 1);
			} else {
				ZEPHIR_INIT_NVAR(_36);
				ZVAL_STRING(_36, "", 1);
			}
			zephir_array_update_string(&_46, SL("class"), &_36, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_35, _32, "a", NULL, _46);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_36);
			ZEPHIR_CONCAT_SVS(_36, "<li>", _35, "</li>");
			zephir_concat_self(&html, _36 TSRMLS_CC);
		} else {
			if (zephir_is_true(i18n)) {
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_48, _21);
				zephir_check_temp_parameter(_21);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(title);
				ZVAL_NULL(title);
			}
			ZEPHIR_INIT_LNVAR(_49);
			ZEPHIR_CONCAT_SVSVS(_49, "<li class=\"active\" title=\"", title, "\"><span>", content, "</span></li>");
			zephir_concat_self(&html, _49 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "get", &_43, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", &_43, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (ZEPHIR_LT(_33, _35)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "next", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", &_43, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _21, _37);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_STRING(_21, "next", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, _21);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_32 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_34);
		zephir_create_array(_34, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_34, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&rsaquo;", 1);
		zephir_array_fast_append(_34, _21);
		zephir_array_fast_append(_34, title);
		ZEPHIR_CALL_METHOD(&_39, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_34, SL("query"), &_39, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_34, SS("rel"), SL("next"), 1);
		ZEPHIR_CALL_METHOD(&_38, _32, "a", NULL, _34);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_36);
		ZEPHIR_CONCAT_SVS(_36, "<li>", _38, "</li>");
		zephir_concat_self(&html, _36 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&rsaquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "get", &_43, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", &_43, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_33, _35)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "last", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", &_43, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _21, _37);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_STRING(_21, "last", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, _21);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_32 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_34);
		zephir_create_array(_34, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_34, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&raquo;", 1);
		zephir_array_fast_append(_34, _21);
		zephir_array_fast_append(_34, title);
		ZEPHIR_CALL_METHOD(&_39, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_34, SL("query"), &_39, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_34, SS("rel"), SL("last"), 1);
		ZEPHIR_CALL_METHOD(&_38, _32, "a", NULL, _34);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_36);
		ZEPHIR_CONCAT_SVS(_36, "<li>", _38, "</li>");
		zephir_concat_self(&html, _36 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&raquo;</span></li>") TSRMLS_CC);
	}
	_32 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_33, _32, "endtag", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	zephir_concat_self(&html, _33 TSRMLS_CC);
	RETURN_CCTOR(html);

}

