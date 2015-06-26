
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

	zend_declare_property_null(ice_pagination_ce, SL("_di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_pagination_ce, SL("_tag"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_pagination_ce->create_object = zephir_init_properties;
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
	zephir_update_property_this(this_ptr, SL("_di"), di TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_BOOL(_5, 1);
	ZEPHIR_CALL_METHOD(&_2, di, "get", NULL, 0, _3, _4, _5);
	zephir_check_temp_parameter(_3);
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

	zval *_11;
	zend_bool _2;
	int limit, page, pages, total, previous, next, ZEPHIR_LAST_CALL_STATUS;
	zval *items = NULL, *data = NULL, *_0, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, _6, _7, _8, _9, *_10 = NULL;

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
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", NULL, 0, _1, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	limit = zephir_get_intval(_3);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "page", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 1);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", NULL, 0, _1, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	page = zephir_get_intval(_5);
	total = zephir_fast_count_int(items TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, limit);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_DOUBLE(&_7, zephir_safe_div_long_long(total, zephir_get_intval(&_6) TSRMLS_CC));
	pages = (int) zephir_ceil(&_7 TSRMLS_CC);
	if (page <= 0) {
		page = 1;
	}
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, (limit * ((page - 1))));
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, limit);
	ZEPHIR_CALL_FUNCTION(&_10, "array_slice", NULL, 86, data, &_8, &_9);
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
 * Prepare minimal pagination.
 * Previous 1 [2] 3 4 5 6 Next
 *
 * @param string url URL with pagination
 * @param string parameters UL attributes to adding
 * @return string HTML
 */
PHP_METHOD(Ice_Pagination, minimal) {

	zephir_fcall_cache_entry *_19 = NULL, *_20 = NULL, *_22 = NULL, *_23 = NULL;
	zend_bool _16;
	int i, ZEPHIR_LAST_CALL_STATUS, _17;
	zval *parameters = NULL, *_1, *_13 = NULL, *_21 = NULL;
	zval *url_param = NULL, *parameters_param = NULL, *html = NULL, *query = NULL, *i18n = NULL, *title = NULL, *_0, *_2 = NULL, *_3, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11, *_12 = NULL, *_14 = NULL, *_15 = NULL, *_18 = NULL, _24 = zval_used_for_init, *_25 = NULL, *_26 = NULL, *_27 = NULL;
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
	ZEPHIR_CALL_METHOD(&html, _0, "taghtml", NULL, 0, _2, parameters, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_NULL(_5);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_BOOL(_6, 1);
	ZEPHIR_CALL_METHOD(&_4, _3, "get", NULL, 0, _2, _5, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, _4, "getquery", NULL, 0);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "i18n", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&i18n, _7, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (ZEPHIR_GT(_8, _9)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, 0, _2, _10);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_13);
		zephir_create_array(_13, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_13, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&lsaquo;", 1);
		zephir_array_fast_append(_13, _2);
		zephir_array_fast_append(_13, title);
		ZEPHIR_CALL_METHOD(&_14, query, "all", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_13, SL("query"), &_14, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_13, SS("rel"), SL("prev"), 1);
		ZEPHIR_CALL_METHOD(&_12, _11, "a", NULL, 0, _13);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_15);
		ZEPHIR_CONCAT_SVS(_15, "<li>", _12, "</li>");
		zephir_concat_self(&html, _15 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&lsaquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_18, _10);
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
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(title);
			if (!ZEPHIR_IS_LONG_IDENTICAL(_10, i)) {
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, i);
				ZEPHIR_CALL_METHOD(NULL, query, "set", &_19, 0, _2, _5);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				if (zephir_is_true(i18n)) {
					ZEPHIR_INIT_NVAR(_13);
					zephir_create_array(_13, 1, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_LONG(_2, i);
					zephir_array_fast_append(_13, _2);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "page: %d", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_20, 0, _2, _13);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
				} else {
					ZVAL_NULL(title);
				}
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_21);
				zephir_create_array(_21, 4, 0 TSRMLS_CC);
				zephir_array_fast_append(_21, url);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_LONG(_2, i);
				zephir_array_fast_append(_21, _2);
				zephir_array_fast_append(_21, title);
				ZEPHIR_CALL_METHOD(&_14, query, "all", &_22, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_21, SL("query"), &_14, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_12, _11, "a", NULL, 0, _21);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_15);
				ZEPHIR_CONCAT_SVS(_15, "<li>", _12, "</li>");
				zephir_concat_self(&html, _15 TSRMLS_CC);
			} else {
				if (zephir_is_true(i18n)) {
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_23, 0, _2);
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
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (ZEPHIR_LT(_10, _12)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_14, this_ptr, "get", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, 0, _2, _14);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_13);
		zephir_create_array(_13, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_13, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&rsaquo;", 1);
		zephir_array_fast_append(_13, _2);
		zephir_array_fast_append(_13, title);
		ZEPHIR_CALL_METHOD(&_27, query, "all", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_13, SL("query"), &_27, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_13, SS("rel"), SL("next"), 1);
		ZEPHIR_CALL_METHOD(&_26, _11, "a", NULL, 0, _13);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_15);
		ZEPHIR_CONCAT_SVS(_15, "<li>", _26, "</li>");
		zephir_concat_self(&html, _15 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&rsaquo;</span></li>") TSRMLS_CC);
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, _11, "endtag", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _10 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_21 = NULL, *_22 = NULL, *_24 = NULL, *_25 = NULL;
	zend_bool _18;
	int i, ZEPHIR_LAST_CALL_STATUS, _19;
	zval *parameters = NULL, *_1, *_12 = NULL, *_23 = NULL;
	zval *url_param = NULL, *parameters_param = NULL, *html = NULL, *query = NULL, *i18n = NULL, *title = NULL, *_0, *_2 = NULL, *_3, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8 = NULL, *_9 = NULL, *_10, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_20 = NULL, _26 = zval_used_for_init, *_27 = NULL;
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
	ZEPHIR_CALL_METHOD(&html, _0, "taghtml", NULL, 0, _2, parameters, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_NULL(_5);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_BOOL(_6, 1);
	ZEPHIR_CALL_METHOD(&_4, _3, "get", NULL, 0, _2, _5, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, _4, "getquery", NULL, 0);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "i18n", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&i18n, _7, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "first", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_8, _9)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "remove", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "first", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_12);
		zephir_create_array(_12, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_12, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&laquo;", 1);
		zephir_array_fast_append(_12, _2);
		zephir_array_fast_append(_12, title);
		ZEPHIR_CALL_METHOD(&_13, query, "all", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_12, SL("query"), &_13, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_12, SS("rel"), SL("first"), 1);
		ZEPHIR_CALL_METHOD(&_11, _10, "a", NULL, 0, _12);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_14);
		ZEPHIR_CONCAT_SVS(_14, "<li>", _11, "</li>");
		zephir_concat_self(&html, _14 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&laquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (ZEPHIR_GT(_11, _13)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_15, this_ptr, "get", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, 0, _2, _15);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "previous", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_12);
		zephir_create_array(_12, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_12, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&lsaquo;", 1);
		zephir_array_fast_append(_12, _2);
		zephir_array_fast_append(_12, title);
		ZEPHIR_CALL_METHOD(&_17, query, "all", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_12, SL("query"), &_17, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_12, SS("rel"), SL("prev"), 1);
		ZEPHIR_CALL_METHOD(&_16, _10, "a", NULL, 0, _12);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_14);
		ZEPHIR_CONCAT_SVS(_14, "<li>", _16, "</li>");
		zephir_concat_self(&html, _14 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&lsaquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_20, _11);
	_19 = 1;
	_18 = 0;
	if (ZEPHIR_GE_LONG(_20, _19)) {
		while (1) {
			if (_18) {
				_19++;
				if (!(ZEPHIR_GE_LONG(_20, _19))) {
					break;
				}
			} else {
				_18 = 1;
			}
			i = _19;
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(title);
			if (!ZEPHIR_IS_LONG_IDENTICAL(_11, i)) {
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, i);
				ZEPHIR_CALL_METHOD(NULL, query, "set", &_21, 0, _2, _5);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				if (zephir_is_true(i18n)) {
					ZEPHIR_INIT_NVAR(_12);
					zephir_create_array(_12, 1, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_LONG(_2, i);
					zephir_array_fast_append(_12, _2);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "page: %d", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_22, 0, _2, _12);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
				} else {
					ZVAL_NULL(title);
				}
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_23);
				zephir_create_array(_23, 4, 0 TSRMLS_CC);
				zephir_array_fast_append(_23, url);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_LONG(_2, i);
				zephir_array_fast_append(_23, _2);
				zephir_array_fast_append(_23, title);
				ZEPHIR_CALL_METHOD(&_15, query, "all", &_24, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_23, SL("query"), &_15, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_13, _10, "a", NULL, 0, _23);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_14);
				ZEPHIR_CONCAT_SVS(_14, "<li>", _13, "</li>");
				zephir_concat_self(&html, _14 TSRMLS_CC);
			} else {
				if (zephir_is_true(i18n)) {
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_25, 0, _2);
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
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (ZEPHIR_LT(_11, _13)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_15, this_ptr, "get", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, 0, _2, _15);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "next", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_12);
		zephir_create_array(_12, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_12, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&rsaquo;", 1);
		zephir_array_fast_append(_12, _2);
		zephir_array_fast_append(_12, title);
		ZEPHIR_CALL_METHOD(&_17, query, "all", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_12, SL("query"), &_17, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_12, SS("rel"), SL("next"), 1);
		ZEPHIR_CALL_METHOD(&_16, _10, "a", NULL, 0, _12);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_14);
		ZEPHIR_CONCAT_SVS(_14, "<li>", _16, "</li>");
		zephir_concat_self(&html, _14 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&rsaquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_11, _13)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "last", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_15, this_ptr, "get", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, 0, _2, _15);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "last", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_12);
		zephir_create_array(_12, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_12, url);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "&raquo;", 1);
		zephir_array_fast_append(_12, _2);
		zephir_array_fast_append(_12, title);
		ZEPHIR_CALL_METHOD(&_17, query, "all", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_12, SL("query"), &_17, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_12, SS("rel"), SL("last"), 1);
		ZEPHIR_CALL_METHOD(&_16, _10, "a", NULL, 0, _12);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_14);
		ZEPHIR_CONCAT_SVS(_14, "<li>", _16, "</li>");
		zephir_concat_self(&html, _14 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&raquo;</span></li>") TSRMLS_CC);
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_11, _10, "endtag", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_concat_self(&html, _11 TSRMLS_CC);
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

	HashTable *_43;
	HashPosition _42;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_45 = NULL, *_46 = NULL, *_48 = NULL, *_49 = NULL;
	zend_bool useMiddle, useN3, useN6, _10, _13, _15, _18, _22;
	int countOut, countIn, n1, n3, n6, i, ZEPHIR_LAST_CALL_STATUS, _16;
	zval *parameters = NULL, *_26, *_36 = NULL, *_47 = NULL;
	zval *url_param = NULL, *parameters_param = NULL, *countOut_param = NULL, *countIn_param = NULL, *html = NULL, *query = NULL, *i18n = NULL, *title = NULL, *links, *number = NULL, *content = NULL, *n2 = NULL, *n4 = NULL, *n5 = NULL, *n7 = NULL, *n8 = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9, *_11, *_12, *_14, *_17 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_23 = NULL, *_24 = NULL, *_25, *_27, *_28 = NULL, *_29, *_30, *_31, *_32 = NULL, *_33 = NULL, *_34, *_35 = NULL, *_37 = NULL, *_38 = NULL, *_39 = NULL, *_40 = NULL, *_41 = NULL, **_44, *_50 = NULL;
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
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, countOut);
	ZEPHIR_CALL_FUNCTION(&n2, "min", &_3, 145, _1, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, ((zephir_get_numberval(_4) - countOut) + 1));
	ZEPHIR_CALL_FUNCTION(&n7, "max", &_6, 31, _1, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&n8, this_ptr, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(n2) + 1));
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, (zephir_get_numberval(_7) - countIn));
	ZEPHIR_CALL_FUNCTION(&n4, "max", &_6, 31, _1, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(n7) - 1));
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, (zephir_get_numberval(_8) + countIn));
	ZEPHIR_CALL_FUNCTION(&n5, "min", &_3, 145, _1, _5);
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
	ZEPHIR_CALL_METHOD(&html, _25, "taghtml", NULL, 0, _21, parameters, _26);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	_27 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_29);
	ZVAL_NULL(_29);
	ZEPHIR_INIT_VAR(_30);
	ZVAL_BOOL(_30, 1);
	ZEPHIR_CALL_METHOD(&_28, _27, "get", NULL, 0, _21, _29, _30);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, _28, "getquery", NULL, 0);
	zephir_check_call_status();
	_31 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "i18n", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&i18n, _31, "get", NULL, 0, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_32, this_ptr, "get", NULL, 0, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "first", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "get", NULL, 0, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_32, _33)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "remove", NULL, 0, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_STRING(_21, "first", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _21);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_34 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_36);
		zephir_create_array(_36, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_36, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&laquo;", 1);
		zephir_array_fast_append(_36, _21);
		zephir_array_fast_append(_36, title);
		ZEPHIR_CALL_METHOD(&_37, query, "all", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_36, SL("query"), &_37, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_36, SS("rel"), SL("first"), 1);
		ZEPHIR_CALL_METHOD(&_35, _34, "a", NULL, 0, _36);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_38);
		ZEPHIR_CONCAT_SVS(_38, "<li>", _35, "</li>");
		zephir_concat_self(&html, _38 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&laquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", NULL, 0, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "previous", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", NULL, 0, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (ZEPHIR_GT(_35, _37)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "previous", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_39, this_ptr, "get", NULL, 0, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, 0, _21, _39);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_STRING(_21, "previous", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _21);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_34 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_36);
		zephir_create_array(_36, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_36, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&lsaquo;", 1);
		zephir_array_fast_append(_36, _21);
		zephir_array_fast_append(_36, title);
		ZEPHIR_CALL_METHOD(&_41, query, "all", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_36, SL("query"), &_41, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_36, SS("rel"), SL("prev"), 1);
		ZEPHIR_CALL_METHOD(&_40, _34, "a", NULL, 0, _36);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_38);
		ZEPHIR_CONCAT_SVS(_38, "<li>", _40, "</li>");
		zephir_concat_self(&html, _38 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&lsaquo;</span></li>") TSRMLS_CC);
	}
	zephir_is_iterable(links, &_43, &_42, 0, 0, "ice/pagination.zep", 336);
	for (
	  ; zephir_hash_get_current_data_ex(_43, (void**) &_44, &_42) == SUCCESS
	  ; zephir_hash_move_forward_ex(_43, &_42)
	) {
		ZEPHIR_GET_HMKEY(number, _43, _42);
		ZEPHIR_GET_HVALUE(content, _44);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", NULL, 0, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(title);
		if (!ZEPHIR_IS_IDENTICAL(number, _35)) {
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, query, "set", &_45, 0, _21, number);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
			if (zephir_is_true(i18n)) {
				ZEPHIR_INIT_NVAR(_36);
				zephir_create_array(_36, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_36, number);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_STRING(_21, "page: %d", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_46, 0, _21, _36);
				zephir_check_temp_parameter(_21);
				zephir_check_call_status();
			} else {
				ZVAL_NULL(title);
			}
			_34 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_47);
			zephir_create_array(_47, 5, 0 TSRMLS_CC);
			zephir_array_fast_append(_47, url);
			zephir_array_fast_append(_47, content);
			zephir_array_fast_append(_47, title);
			ZEPHIR_CALL_METHOD(&_39, query, "all", &_48, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_47, SL("query"), &_39, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_LNVAR(_38);
			if (ZEPHIR_IS_STRING(content, "&hellip;")) {
				ZEPHIR_INIT_NVAR(_38);
				ZVAL_STRING(_38, "text-muted", 1);
			} else {
				ZEPHIR_INIT_NVAR(_38);
				ZVAL_STRING(_38, "", 1);
			}
			zephir_array_update_string(&_47, SL("class"), &_38, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_37, _34, "a", NULL, 0, _47);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_38);
			ZEPHIR_CONCAT_SVS(_38, "<li>", _37, "</li>");
			zephir_concat_self(&html, _38 TSRMLS_CC);
		} else {
			if (zephir_is_true(i18n)) {
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&title, i18n, "translate", &_49, 0, _21);
				zephir_check_temp_parameter(_21);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(title);
				ZVAL_NULL(title);
			}
			ZEPHIR_INIT_LNVAR(_50);
			ZEPHIR_CONCAT_SVSVS(_50, "<li class=\"active\" title=\"", title, "\"><span>", content, "</span></li>");
			zephir_concat_self(&html, _50 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", NULL, 0, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", NULL, 0, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (ZEPHIR_LT(_35, _37)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "next", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_39, this_ptr, "get", NULL, 0, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, 0, _21, _39);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_STRING(_21, "next", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _21);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_34 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_36);
		zephir_create_array(_36, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_36, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&rsaquo;", 1);
		zephir_array_fast_append(_36, _21);
		zephir_array_fast_append(_36, title);
		ZEPHIR_CALL_METHOD(&_41, query, "all", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_36, SL("query"), &_41, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_36, SS("rel"), SL("next"), 1);
		ZEPHIR_CALL_METHOD(&_40, _34, "a", NULL, 0, _36);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_38);
		ZEPHIR_CONCAT_SVS(_38, "<li>", _40, "</li>");
		zephir_concat_self(&html, _38 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&rsaquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", NULL, 0, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", NULL, 0, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_35, _37)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "last", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_39, this_ptr, "get", NULL, 0, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, 0, _21, _39);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		if (zephir_is_true(i18n)) {
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_STRING(_21, "last", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&title, i18n, "translate", NULL, 0, _21);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(title);
			ZVAL_NULL(title);
		}
		_34 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_36);
		zephir_create_array(_36, 5, 0 TSRMLS_CC);
		zephir_array_fast_append(_36, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&raquo;", 1);
		zephir_array_fast_append(_36, _21);
		zephir_array_fast_append(_36, title);
		ZEPHIR_CALL_METHOD(&_41, query, "all", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_36, SL("query"), &_41, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_36, SS("rel"), SL("last"), 1);
		ZEPHIR_CALL_METHOD(&_40, _34, "a", NULL, 0, _36);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_38);
		ZEPHIR_CONCAT_SVS(_38, "<li>", _40, "</li>");
		zephir_concat_self(&html, _38 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&raquo;</span></li>") TSRMLS_CC);
	}
	_34 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_35, _34, "endtag", NULL, 0, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	zephir_concat_self(&html, _35 TSRMLS_CC);
	RETURN_CCTOR(html);

}

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_data"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

