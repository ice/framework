
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


/**
 * Provide the multi-page pagination component.
 *
 * @package     Ice/Pagination
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Pagination) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Pagination, ice, pagination, ice_arr_ce, ice_pagination_method_entry, 0);

	return SUCCESS;

}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return object Pagination
 */
PHP_METHOD(Ice_Pagination, calculate) {

	zval *_12;
	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL;
	zend_bool _2;
	int limit, page, pages, total, before, next, ZEPHIR_LAST_CALL_STATUS;
	zval *items = NULL, *floor = NULL, *data = NULL, *_0, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, _6, _7 = zval_used_for_init, _9, *_10 = NULL;

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
		_2 = !(zephir_is_instance_of(items, SL("Traversable") TSRMLS_CC));
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Invalid data for pagination", "ice/pagination.zep", 34);
		return;
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
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, limit);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_DOUBLE(&_7, zephir_safe_div_long_long(total, zephir_get_intval(&_6) TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&floor, "floor", &_8, &_7);
	zephir_check_call_status();
	pages = zephir_get_intval(floor);
	if (ZEPHIR_LE_LONG(floor, 0)) {
		pages = 1;
	}
	if (page <= 0) {
		page = 1;
	}
	if (zephir_instance_of_ev(items, ice_arr_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&data, items, "all", NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(data, items);
	}
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, (limit * ((page - 1))));
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, limit);
	ZEPHIR_CALL_FUNCTION(&_10, "array_slice", &_11, data, &_7, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "items", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, _1, _10);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, _1, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (page > 1) {
		before = (page - 1);
	} else {
		before = 1;
	}
	ZEPHIR_INIT_VAR(_12);
	array_init_size(_12, 8);
	add_assoc_long_ex(_12, SS("first"), 1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, before);
	zephir_array_update_string(&_12, SL("before"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, page);
	zephir_array_update_string(&_12, SL("current"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, pages);
	zephir_array_update_string(&_12, SL("last"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, pages);
	zephir_array_update_string(&_12, SL("pages"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, total);
	zephir_array_update_string(&_12, SL("total"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, _12);
	zephir_check_call_status();
	RETURN_THIS();

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

	zephir_fcall_cache_entry *_45 = NULL, *_46 = NULL, *_47 = NULL, *_48 = NULL;
	HashTable *_43;
	HashPosition _42;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_25 = NULL, *_30 = NULL;
	zend_bool useMiddle, useN3, useN6, _10, _13, _15, _18, _22;
	int countOut, countIn, n1, n3, n6, i, ZEPHIR_LAST_CALL_STATUS, _16;
	zval *parameters = NULL, *_32, *_36 = NULL;
	zval *url_param = NULL, *parameters_param = NULL, *countOut_param = NULL, *countIn_param = NULL, *html = NULL, *di = NULL, *tag = NULL, *i18n = NULL, *query = NULL, *links, *number = NULL, *content = NULL, *n2 = NULL, *n4 = NULL, *n5 = NULL, *n7 = NULL, *n8 = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9, *_11, *_12, *_14, *_17 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_23 = NULL, *_24 = NULL, *_26 = NULL, *_27 = NULL, *_28 = NULL, _29, *_31, *_33 = NULL, *_34 = NULL, *_35 = NULL, *_37 = NULL, *_38 = NULL, *_39 = NULL, *_40 = NULL, *_41 = NULL, **_44, *_49 = NULL;
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
			zephir_array_update_long(&links, i, &_1, PH_COPY | PH_SEPARATE, "ice/pagination.zep", 132);
		}
	}
	if (useN3) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "&hellip;", 1);
		zephir_array_update_long(&links, n3, &_5, PH_COPY | PH_SEPARATE, "ice/pagination.zep", 136);
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
			zephir_array_update_long(&links, i, &_21, PH_COPY | PH_SEPARATE, "ice/pagination.zep", 140);
		}
	}
	if (useN6) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&hellip;", 1);
		zephir_array_update_long(&links, n6, &_21, PH_COPY | PH_SEPARATE, "ice/pagination.zep", 144);
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
			zephir_array_update_long(&links, i, &_21, PH_COPY | PH_SEPARATE, "ice/pagination.zep", 148);
		}
	}
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_25);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&tag, di, "gettag", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&i18n, di, "geti18n", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_26, di, "getrequest", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, _26, "getget", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_27);
	if (url && Z_STRLEN_P(url)) {
		ZEPHIR_CPY_WRT(_27, url);
	} else {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "_url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_28, query, "get", NULL, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_29);
		ZVAL_LONG(&_29, 1);
		ZEPHIR_CALL_FUNCTION(&_27, "substr", &_30, _28, &_29);
		zephir_check_call_status();
	}
	zephir_get_strval(url, _27);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_31);
	ZVAL_LONG(_31, 1);
	ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _21, _31);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "_url", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, query, "remove", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_32);
	array_init_size(_32, 2);
	add_assoc_stringl_ex(_32, SS("class"), SL("pagination"), 1);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&html, tag, "taghtml", NULL, _21, parameters, _32);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "get", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "first", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_34, this_ptr, "get", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_33, _34)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "remove", NULL, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_36);
		array_init_size(_36, 7);
		zephir_array_fast_append(_36, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&laquo;", 1);
		zephir_array_fast_append(_36, _21);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "First", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_37, i18n, "_", NULL, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		zephir_array_fast_append(_36, _37);
		ZEPHIR_CALL_METHOD(&_37, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_36, SL("query"), &_37, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_36, SS("rel"), SL("first"), 1);
		ZEPHIR_CALL_METHOD(&_35, tag, "a", NULL, _36);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_38);
		ZEPHIR_CONCAT_SVS(_38, "<li>", _35, "</li>");
		zephir_concat_self(&html, _38 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&laquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "before", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (ZEPHIR_GT(_35, _37)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "before", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_39, this_ptr, "get", NULL, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _21, _39);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_36);
		array_init_size(_36, 7);
		zephir_array_fast_append(_36, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&lsaquo;", 1);
		zephir_array_fast_append(_36, _21);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "Previous", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_41, i18n, "_", NULL, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		zephir_array_fast_append(_36, _41);
		ZEPHIR_CALL_METHOD(&_41, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_36, SL("query"), &_41, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_36, SS("rel"), SL("prev"), 1);
		ZEPHIR_CALL_METHOD(&_40, tag, "a", NULL, _36);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_38);
		ZEPHIR_CONCAT_SVS(_38, "<li>", _40, "</li>");
		zephir_concat_self(&html, _38 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&lsaquo;</span></li>") TSRMLS_CC);
	}
	zephir_is_iterable(links, &_43, &_42, 0, 0, "ice/pagination.zep", 194);
	for (
	  ; zephir_hash_get_current_data_ex(_43, (void**) &_44, &_42) == SUCCESS
	  ; zephir_hash_move_forward_ex(_43, &_42)
	) {
		ZEPHIR_GET_HMKEY(number, _43, _42);
		ZEPHIR_GET_HVALUE(content, _44);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", &_45, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		if (!ZEPHIR_IS_IDENTICAL(number, _35)) {
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, query, "set", &_46, _21, number);
			zephir_check_temp_parameter(_21);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_36);
			array_init_size(_36, 6);
			zephir_array_fast_append(_36, url);
			zephir_array_fast_append(_36, content);
			ZEPHIR_CALL_METHOD(&_39, query, "all", &_47);
			zephir_check_call_status();
			zephir_array_update_string(&_36, SL("query"), &_39, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_LNVAR(_38);
			if (ZEPHIR_IS_STRING(content, "&hellip;")) {
				ZEPHIR_INIT_NVAR(_38);
				ZVAL_STRING(_38, "text-muted", 1);
			} else {
				ZEPHIR_INIT_NVAR(_38);
				ZVAL_STRING(_38, "", 1);
			}
			zephir_array_update_string(&_36, SL("class"), &_38, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_37, tag, "a", &_48, _36);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_38);
			ZEPHIR_CONCAT_SVS(_38, "<li>", _37, "</li>");
			zephir_concat_self(&html, _38 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_LNVAR(_49);
			ZEPHIR_CONCAT_SVS(_49, "<li class=\"active\"><span>", content, "</span></li>");
			zephir_concat_self(&html, _49 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", &_45, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "next", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", &_45, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (ZEPHIR_LT(_35, _37)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "next", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_39, this_ptr, "get", &_45, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _21, _39);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_36);
		array_init_size(_36, 7);
		zephir_array_fast_append(_36, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&rsaquo;", 1);
		zephir_array_fast_append(_36, _21);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "Next", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_41, i18n, "_", NULL, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		zephir_array_fast_append(_36, _41);
		ZEPHIR_CALL_METHOD(&_41, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_36, SL("query"), &_41, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_36, SS("rel"), SL("next"), 1);
		ZEPHIR_CALL_METHOD(&_40, tag, "a", NULL, _36);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_38);
		ZEPHIR_CONCAT_SVS(_38, "<li>", _40, "</li>");
		zephir_concat_self(&html, _38 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&rsaquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "current", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "get", &_45, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "last", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_37, this_ptr, "get", &_45, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_35, _37)) {
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "last", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_39, this_ptr, "get", &_45, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "page", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, query, "set", NULL, _21, _39);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_36);
		array_init_size(_36, 7);
		zephir_array_fast_append(_36, url);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "&raquo;", 1);
		zephir_array_fast_append(_36, _21);
		ZEPHIR_INIT_NVAR(_21);
		ZVAL_STRING(_21, "Last", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_41, i18n, "_", NULL, _21);
		zephir_check_temp_parameter(_21);
		zephir_check_call_status();
		zephir_array_fast_append(_36, _41);
		ZEPHIR_CALL_METHOD(&_41, query, "all", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_36, SL("query"), &_41, PH_COPY | PH_SEPARATE);
		add_assoc_stringl_ex(_36, SS("rel"), SL("last"), 1);
		ZEPHIR_CALL_METHOD(&_40, tag, "a", NULL, _36);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_38);
		ZEPHIR_CONCAT_SVS(_38, "<li>", _40, "</li>");
		zephir_concat_self(&html, _38 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&html, SL("<li class=\"disabled\"><span>&raquo;</span></li>") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "ul", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_35, tag, "endtag", NULL, _21);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	zephir_concat_self(&html, _35 TSRMLS_CC);
	RETURN_CCTOR(html);

}

