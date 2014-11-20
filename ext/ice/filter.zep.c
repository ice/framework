
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Ice_Filter) {

	ZEPHIR_REGISTER_CLASS(Ice, Filter, ice, filter, ice_filter_method_entry, 0);

	zend_declare_property_null(ice_filter_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Adds a user-defined filter
 *
 * @param string name
 * @param callable body
 */
PHP_METHOD(Ice_Filter, add) {

	zval *name_param = NULL, *body;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &body);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	if (Z_TYPE_P(body) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Filter must be an object", "ice/filter.zep", 18);
		return;
	}
	zephir_update_property_array(this_ptr, SL("_filters"), name, body TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sanitizes a value with a specified single or set of filters
 *
 * @param mixed value
 * @param mixed filters
 * @return mixed
 */
PHP_METHOD(Ice_Filter, sanitize) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *value = NULL, *filters = NULL, *filter = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &filters);

	ZEPHIR_SEPARATE_PARAM(value);
	ZEPHIR_SEPARATE_PARAM(filters);


	if (Z_TYPE_P(filters) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_explode_str(_0, SL("|"), filters, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(filters, _0);
	}
	if (Z_TYPE_P(filters) == IS_ARRAY) {
		zephir_is_iterable(filters, &_2, &_1, 0, 0, "ice/filter.zep", 43);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(filter, _3);
			ZEPHIR_CALL_METHOD(&_4, this_ptr, "_sanitize", &_5, value, filter);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _4);
		}
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Internal sanitize
 *
 * @param mixed value
 * @param string filter
 * @return mixed
 */
PHP_METHOD(Ice_Filter, _sanitize) {

	zephir_fcall_cache_entry *_12 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL;
	zval *_1 = NULL, *_13;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *filter_param = NULL, *custom, *_0, *_2 = NULL, *_3 = NULL, *_4, *_5, *_6, *_7 = NULL, _9 = zval_used_for_init, _10 = zval_used_for_init;
	zval *value = NULL, *filter = NULL, *_14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value_param, &filter_param);

	zephir_get_strval(value, value_param);
	if (unlikely(Z_TYPE_P(filter_param) != IS_STRING && Z_TYPE_P(filter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filter' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(filter_param) == IS_STRING)) {
		zephir_get_strval(filter, filter_param);
	} else {
		ZEPHIR_INIT_VAR(filter);
		ZVAL_EMPTY_STRING(filter);
	}


	ZEPHIR_OBS_VAR(custom);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&custom, _0, filter, 0 TSRMLS_CC)) {
		if (zephir_instance_of_ev(custom, zend_ce_closure TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_1);
			array_init_size(_1, 2);
			zephir_array_fast_append(_1, value);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, custom, _1);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_METHOD(custom, "sanitize", NULL, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	do {
		if (ZEPHIR_IS_STRING(filter, "camelize")) {
			ZEPHIR_INIT_VAR(_2);
			zephir_camelize(_2, value);
			RETURN_CCTOR(_2);
		}
		if (ZEPHIR_IS_STRING(filter, "uncamelize")) {
			ZEPHIR_INIT_NVAR(_2);
			zephir_uncamelize(_2, value);
			RETURN_CCTOR(_2);
		}
		if (ZEPHIR_IS_STRING(filter, "human")) {
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_INIT_VAR(_5);
			ZVAL_STRING(_5, "/(?<=\\w)(?=[A-Z])/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_6);
			ZVAL_STRING(_6, " $1", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_7, "preg_replace", &_8, _5, _6, value);
			zephir_check_temp_parameter(_5);
			zephir_check_temp_parameter(_6);
			zephir_check_call_status();
			zephir_fast_strtolower(_4, _7);
			ZEPHIR_SINIT_VAR(_9);
			ZVAL_STRING(&_9, "_", 0);
			ZEPHIR_SINIT_VAR(_10);
			ZVAL_STRING(&_10, " ", 0);
			zephir_fast_str_replace(_3, &_9, &_10, _4 TSRMLS_CC);
			zephir_fast_trim(_2, _3, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_RETURN_CALL_FUNCTION("ucfirst", &_11, _2);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "lower")) {
			ZEPHIR_INIT_NVAR(_2);
			if ((zephir_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_FUNCTION(&_2, "mb_strtolower", NULL, value);
				zephir_check_call_status();
			} else {
				zephir_fast_strtolower(_2, value);
			}
			RETURN_CCTOR(_2);
		}
		if (ZEPHIR_IS_STRING(filter, "upper")) {
			ZEPHIR_INIT_NVAR(_2);
			if ((zephir_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_FUNCTION(&_2, "mb_strtoupper", NULL, value);
				zephir_check_call_status();
			} else {
				zephir_fast_strtoupper(_2, value);
			}
			RETURN_CCTOR(_2);
		}
		if (ZEPHIR_IS_STRING(filter, "alnum")) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "/[^a-z0-9]/i", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_8, _2, _3, value);
			zephir_check_temp_parameter(_2);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "alpha")) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "/[^a-z]/i", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_8, _2, _3, value);
			zephir_check_temp_parameter(_2);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "email")) {
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_LONG(&_9, 517);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_12, value, &_9);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "float")) {
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_LONG(&_9, 520);
			ZEPHIR_SINIT_NVAR(_10);
			ZVAL_LONG(&_10, 4096);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_12, value, &_9, &_10);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "int")) {
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_LONG(&_9, 519);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_12, value, &_9);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "string")) {
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_LONG(&_9, 513);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_12, value, &_9);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "strip_repeats")) {
			ZEPHIR_INIT_NVAR(_1);
			array_init_size(_1, 4);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "/[ ]{2,}/", 1);
			zephir_array_fast_append(_1, _2);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "/((\\r\\n|\\n\\r|\\n|\\r){3,})/", 1);
			zephir_array_fast_append(_1, _2);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "~(.?)\\1{3,}~", 1);
			zephir_array_fast_append(_1, _2);
			ZEPHIR_INIT_VAR(_13);
			array_init_size(_13, 4);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, " ", 1);
			zephir_array_fast_append(_13, _2);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "\\n\\n", 1);
			zephir_array_fast_append(_13, _2);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "$1$1$1", 1);
			zephir_array_fast_append(_13, _2);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_8, _1, _13, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "e") || ZEPHIR_IS_STRING(filter, "escape") || ZEPHIR_IS_STRING(filter, "strip_special")) {
			zephir_get_strval(_14, value);
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_LONG(&_9, (3 | 48));
			ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", &_15, _14, &_9);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "unescape") || ZEPHIR_IS_STRING(filter, "unstrip_special")) {
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_LONG(&_9, (3 | 48));
			ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars_decode", &_16, value, &_9);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, ice_exception_ce);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "Filter '%s' is not supported", 0);
		ZEPHIR_CALL_FUNCTION(&_7, "sprintf", &_17, &_9, filter);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "ice/filter.zep", 108 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

