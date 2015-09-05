
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
#include "kernel/concat.h"


/**
 * Filter component provides a set of commonly needed data filters.
 *
 * @package     Ice/Filter
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Filter) {

	ZEPHIR_REGISTER_CLASS(Ice, Filter, ice, filter, ice_filter_method_entry, 0);

	zend_declare_property_null(ice_filter_ce, SL("filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Adds a user-defined filter.
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Filter must be an object", "ice/filter.zep", 27);
		return;
	}
	zephir_update_property_array(this_ptr, SL("filters"), name, body TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sanitizes a value with a specified single or set of filters.
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
		zephir_is_iterable(filters, &_2, &_1, 0, 0, "ice/filter.zep", 52);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(filter, _3);
			ZEPHIR_CALL_METHOD(&_4, this_ptr, "dosanitize", &_5, 0, value, filter);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _4);
		}
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Internal sanitize.
 *
 * @param mixed value
 * @param string filter
 * @return mixed
 */
PHP_METHOD(Ice_Filter, doSanitize) {

	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL;
	zval *_1 = NULL, *_12;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *filter_param = NULL, *custom = NULL, *_0, _2 = zval_used_for_init, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8 = NULL, _10 = zval_used_for_init, *_13;
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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&custom, _0, filter, 0 TSRMLS_CC)) {
		if (zephir_instance_of_ev(custom, zend_ce_closure TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_1);
			zephir_create_array(_1, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_1, value);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, custom, _1);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_METHOD(custom, "sanitize", NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	do {
		if (ZEPHIR_IS_STRING(filter, "cssmin")) {
			ZEPHIR_SINIT_VAR(_2);
			ZVAL_STRING(&_2, "Ice\\Filter\\Css", 0);
			ZEPHIR_INIT_NVAR(custom);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(custom, &_2 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "cssmin", 1);
			zephir_update_property_array(this_ptr, SL("filters"), _3, custom TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(custom, "sanitize", NULL, 0, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "jsmin")) {
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_STRING(&_2, "Ice\\Filter\\Js", 0);
			ZEPHIR_INIT_NVAR(custom);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(custom, &_2 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "jsmin", 1);
			zephir_update_property_array(this_ptr, SL("filters"), _3, custom TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(custom, "sanitize", NULL, 0, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "camelize")) {
			ZEPHIR_INIT_NVAR(_3);
			zephir_camelize(_3, value);
			RETURN_CCTOR(_3);
		}
		if (ZEPHIR_IS_STRING(filter, "uncamelize")) {
			ZEPHIR_INIT_NVAR(_3);
			zephir_uncamelize(_3, value);
			RETURN_CCTOR(_3);
		}
		if (ZEPHIR_IS_STRING(filter, "human")) {
			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_INIT_VAR(_6);
			ZVAL_STRING(_6, "/(?<=\\w)(?=[A-Z])/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_7);
			ZVAL_STRING(_7, " $1", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, 101, _6, _7, value);
			zephir_check_temp_parameter(_6);
			zephir_check_temp_parameter(_7);
			zephir_check_call_status();
			zephir_fast_strtolower(_5, _8);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_STRING(&_2, "_", 0);
			ZEPHIR_SINIT_VAR(_10);
			ZVAL_STRING(&_10, " ", 0);
			zephir_fast_str_replace(&_4, &_2, &_10, _5 TSRMLS_CC);
			zephir_fast_trim(_3, _4, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			zephir_ucfirst(return_value, _3);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "lower")) {
			ZEPHIR_INIT_NVAR(_3);
			if ((zephir_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_FUNCTION(&_3, "mb_strtolower", NULL, 102, value);
				zephir_check_call_status();
			} else {
				zephir_fast_strtolower(_3, value);
			}
			RETURN_CCTOR(_3);
		}
		if (ZEPHIR_IS_STRING(filter, "upper")) {
			ZEPHIR_INIT_NVAR(_3);
			if ((zephir_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_FUNCTION(&_3, "mb_strtoupper", NULL, 103, value);
				zephir_check_call_status();
			} else {
				zephir_fast_strtoupper(_3, value);
			}
			RETURN_CCTOR(_3);
		}
		if (ZEPHIR_IS_STRING(filter, "alnum")) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "/[^a-z0-9]/i", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_9, 101, _3, _4, value);
			zephir_check_temp_parameter(_3);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "alpha")) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "/[^a-z]/i", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_9, 101, _3, _4, value);
			zephir_check_temp_parameter(_3);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "email")) {
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 517);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_11, 104, value, &_2);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "float")) {
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 520);
			ZEPHIR_SINIT_NVAR(_10);
			ZVAL_LONG(&_10, 4096);
			ZEPHIR_CALL_FUNCTION(&_8, "filter_var", &_11, 104, value, &_2, &_10);
			zephir_check_call_status();
			RETURN_MM_DOUBLE(zephir_get_doubleval(_8));
		}
		if (ZEPHIR_IS_STRING(filter, "int")) {
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 519);
			ZEPHIR_CALL_FUNCTION(&_8, "filter_var", &_11, 104, value, &_2);
			zephir_check_call_status();
			RETURN_MM_LONG(zephir_get_intval(_8));
		}
		if (ZEPHIR_IS_STRING(filter, "string")) {
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 513);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_11, 104, value, &_2);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "repeats") || ZEPHIR_IS_STRING(filter, "strip_repeats")) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_create_array(_1, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "/[ ]{2,}/", 1);
			zephir_array_fast_append(_1, _3);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "/((\\r\\n|\\n\\r|\\n|\\r){3,})/", 1);
			zephir_array_fast_append(_1, _3);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "~(.?)\\1{3,}~", 1);
			zephir_array_fast_append(_1, _3);
			ZEPHIR_INIT_VAR(_12);
			zephir_create_array(_12, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, " ", 1);
			zephir_array_fast_append(_12, _3);
			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_GET_CONSTANT(_3, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_4);
			ZEPHIR_GET_CONSTANT(_4, "PHP_EOL");
			ZEPHIR_INIT_VAR(_13);
			ZEPHIR_CONCAT_VV(_13, _3, _4);
			zephir_array_fast_append(_12, _13);
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "$1$1$1", 1);
			zephir_array_fast_append(_12, _5);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_9, 101, _1, _12, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "e") || ZEPHIR_IS_STRING(filter, "escape") || ZEPHIR_IS_STRING(filter, "strip_special")) {
			zephir_get_strval(_14, value);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, (3 | 48));
			ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 105, _14, &_2);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "unescape") || ZEPHIR_IS_STRING(filter, "unstrip_special")) {
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, (3 | 48));
			ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars_decode", NULL, 106, value, &_2);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, ice_exception_ce);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "Filter '%s' is not supported", 0);
		ZEPHIR_CALL_FUNCTION(&_8, "sprintf", NULL, 1, &_2, filter);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 2, _8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "ice/filter.zep", 127 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

