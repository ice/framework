
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

	HashTable *_2$$4;
	HashPosition _1$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, *filters = NULL, *filter = NULL, *_0$$3, **_3$$4, *_4$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &filters);

	ZEPHIR_SEPARATE_PARAM(value);
	ZEPHIR_SEPARATE_PARAM(filters);


	if (Z_TYPE_P(filters) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_fast_explode_str(_0$$3, SL("|"), filters, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(filters, _0$$3);
	}
	if (Z_TYPE_P(filters) == IS_ARRAY) {
		zephir_is_iterable(filters, &_2$$4, &_1$$4, 0, 0, "ice/filter.zep", 52);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$4, (void**) &_3$$4, &_1$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$4, &_1$$4)
		) {
			ZEPHIR_GET_HVALUE(filter, _3$$4);
			ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "dosanitize", &_5, 0, value, filter);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _4$$5);
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

	zval *_1$$4, *_31$$18, *_33$$18;
	zephir_fcall_cache_entry *_14 = NULL, *_24 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *filter_param = NULL, *custom = NULL, *_0, _2$$5, *_3$$5, _4$$6, *_5$$6, *_6$$7, *_7$$8, *_8$$9, *_9$$9, *_10$$9, *_11$$9, *_12$$9, *_13$$9 = NULL, _15$$9, _16$$9, *_17$$10 = NULL, *_18$$11 = NULL, *_19$$12, *_20$$12, *_21$$13, *_22$$13, _23$$14, _25$$15, _26$$15, *_27$$15 = NULL, _28$$16, *_29$$16 = NULL, _30$$17, *_32$$18 = NULL, *_34$$18, *_35$$18, *_36$$18, _38$$19, _39$$20, *_40$$21, _41$$21, *_42$$21 = NULL;
	zval *value = NULL, *filter = NULL, *_37$$19 = NULL;

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
			ZEPHIR_INIT_VAR(_1$$4);
			zephir_create_array(_1$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_1$$4, value);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, custom, _1$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_METHOD(custom, "sanitize", NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	do {
		if (ZEPHIR_IS_STRING(filter, "cssmin")) {
			ZEPHIR_SINIT_VAR(_2$$5);
			ZVAL_STRING(&_2$$5, "Ice\\Filter\\Css", 0);
			ZEPHIR_INIT_NVAR(custom);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(custom, &_2$$5 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_3$$5);
			ZVAL_STRING(_3$$5, "cssmin", 1);
			zephir_update_property_array(this_ptr, SL("filters"), _3$$5, custom TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(custom, "sanitize", NULL, 0, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "jsmin")) {
			ZEPHIR_SINIT_VAR(_4$$6);
			ZVAL_STRING(&_4$$6, "Ice\\Filter\\Js", 0);
			ZEPHIR_INIT_NVAR(custom);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(custom, &_4$$6 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_5$$6);
			ZVAL_STRING(_5$$6, "jsmin", 1);
			zephir_update_property_array(this_ptr, SL("filters"), _5$$6, custom TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(custom, "sanitize", NULL, 0, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "camelize")) {
			ZEPHIR_INIT_VAR(_6$$7);
			zephir_camelize(_6$$7, value);
			RETURN_CCTOR(_6$$7);
		}
		if (ZEPHIR_IS_STRING(filter, "uncamelize")) {
			ZEPHIR_INIT_VAR(_7$$8);
			zephir_uncamelize(_7$$8, value);
			RETURN_CCTOR(_7$$8);
		}
		if (ZEPHIR_IS_STRING(filter, "human")) {
			ZEPHIR_INIT_VAR(_8$$9);
			ZEPHIR_INIT_VAR(_9$$9);
			ZEPHIR_INIT_VAR(_10$$9);
			ZEPHIR_INIT_VAR(_11$$9);
			ZVAL_STRING(_11$$9, "/(?<=\\w)(?=[A-Z])/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_12$$9);
			ZVAL_STRING(_12$$9, " $1", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_13$$9, "preg_replace", &_14, 98, _11$$9, _12$$9, value);
			zephir_check_temp_parameter(_11$$9);
			zephir_check_temp_parameter(_12$$9);
			zephir_check_call_status();
			zephir_fast_strtolower(_10$$9, _13$$9);
			ZEPHIR_SINIT_VAR(_15$$9);
			ZVAL_STRING(&_15$$9, "_", 0);
			ZEPHIR_SINIT_VAR(_16$$9);
			ZVAL_STRING(&_16$$9, " ", 0);
			zephir_fast_str_replace(&_9$$9, &_15$$9, &_16$$9, _10$$9 TSRMLS_CC);
			zephir_fast_trim(_8$$9, _9$$9, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			zephir_ucfirst(return_value, _8$$9);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "lower")) {
			ZEPHIR_INIT_VAR(_17$$10);
			if ((zephir_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_FUNCTION(&_17$$10, "mb_strtolower", NULL, 99, value);
				zephir_check_call_status();
			} else {
				zephir_fast_strtolower(_17$$10, value);
			}
			RETURN_CCTOR(_17$$10);
		}
		if (ZEPHIR_IS_STRING(filter, "upper")) {
			ZEPHIR_INIT_VAR(_18$$11);
			if ((zephir_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_FUNCTION(&_18$$11, "mb_strtoupper", NULL, 100, value);
				zephir_check_call_status();
			} else {
				zephir_fast_strtoupper(_18$$11, value);
			}
			RETURN_CCTOR(_18$$11);
		}
		if (ZEPHIR_IS_STRING(filter, "alnum")) {
			ZEPHIR_INIT_VAR(_19$$12);
			ZVAL_STRING(_19$$12, "/[^a-z0-9]/i", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_20$$12);
			ZVAL_STRING(_20$$12, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_14, 98, _19$$12, _20$$12, value);
			zephir_check_temp_parameter(_19$$12);
			zephir_check_temp_parameter(_20$$12);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "alpha")) {
			ZEPHIR_INIT_VAR(_21$$13);
			ZVAL_STRING(_21$$13, "/[^a-z]/i", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_22$$13);
			ZVAL_STRING(_22$$13, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_14, 98, _21$$13, _22$$13, value);
			zephir_check_temp_parameter(_21$$13);
			zephir_check_temp_parameter(_22$$13);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "email")) {
			ZEPHIR_SINIT_VAR(_23$$14);
			ZVAL_LONG(&_23$$14, 517);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_24, 101, value, &_23$$14);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "float")) {
			ZEPHIR_SINIT_VAR(_25$$15);
			ZVAL_LONG(&_25$$15, 520);
			ZEPHIR_SINIT_VAR(_26$$15);
			ZVAL_LONG(&_26$$15, 4096);
			ZEPHIR_CALL_FUNCTION(&_27$$15, "filter_var", &_24, 101, value, &_25$$15, &_26$$15);
			zephir_check_call_status();
			RETURN_MM_DOUBLE(zephir_get_doubleval(_27$$15));
		}
		if (ZEPHIR_IS_STRING(filter, "int")) {
			ZEPHIR_SINIT_VAR(_28$$16);
			ZVAL_LONG(&_28$$16, 519);
			ZEPHIR_CALL_FUNCTION(&_29$$16, "filter_var", &_24, 101, value, &_28$$16);
			zephir_check_call_status();
			RETURN_MM_LONG(zephir_get_intval(_29$$16));
		}
		if (ZEPHIR_IS_STRING(filter, "string")) {
			ZEPHIR_SINIT_VAR(_30$$17);
			ZVAL_LONG(&_30$$17, 513);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_24, 101, value, &_30$$17);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "repeats") || ZEPHIR_IS_STRING(filter, "strip_repeats")) {
			ZEPHIR_INIT_VAR(_31$$18);
			zephir_create_array(_31$$18, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_32$$18);
			ZVAL_STRING(_32$$18, "/[ ]{2,}/", 1);
			zephir_array_fast_append(_31$$18, _32$$18);
			ZEPHIR_INIT_NVAR(_32$$18);
			ZVAL_STRING(_32$$18, "/((\\r\\n|\\n\\r|\\n|\\r){3,})/", 1);
			zephir_array_fast_append(_31$$18, _32$$18);
			ZEPHIR_INIT_NVAR(_32$$18);
			ZVAL_STRING(_32$$18, "~(.?)\\1{3,}~", 1);
			zephir_array_fast_append(_31$$18, _32$$18);
			ZEPHIR_INIT_VAR(_33$$18);
			zephir_create_array(_33$$18, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_32$$18);
			ZVAL_STRING(_32$$18, " ", 1);
			zephir_array_fast_append(_33$$18, _32$$18);
			ZEPHIR_INIT_NVAR(_32$$18);
			ZEPHIR_GET_CONSTANT(_32$$18, "PHP_EOL");
			ZEPHIR_INIT_VAR(_34$$18);
			ZEPHIR_GET_CONSTANT(_34$$18, "PHP_EOL");
			ZEPHIR_INIT_VAR(_35$$18);
			ZEPHIR_CONCAT_VV(_35$$18, _32$$18, _34$$18);
			zephir_array_fast_append(_33$$18, _35$$18);
			ZEPHIR_INIT_VAR(_36$$18);
			ZVAL_STRING(_36$$18, "$1$1$1", 1);
			zephir_array_fast_append(_33$$18, _36$$18);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_14, 98, _31$$18, _33$$18, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "e") || ZEPHIR_IS_STRING(filter, "escape") || ZEPHIR_IS_STRING(filter, "strip_special")) {
			zephir_get_strval(_37$$19, value);
			ZEPHIR_SINIT_VAR(_38$$19);
			ZVAL_LONG(&_38$$19, (3 | 48));
			ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 102, _37$$19, &_38$$19);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(filter, "unescape") || ZEPHIR_IS_STRING(filter, "unstrip_special")) {
			ZEPHIR_SINIT_VAR(_39$$20);
			ZVAL_LONG(&_39$$20, (3 | 48));
			ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars_decode", NULL, 103, value, &_39$$20);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(_40$$21);
		object_init_ex(_40$$21, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_41$$21);
		ZVAL_STRING(&_41$$21, "Filter '%s' is not supported", 0);
		ZEPHIR_CALL_FUNCTION(&_42$$21, "sprintf", NULL, 1, &_41$$21, filter);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _40$$21, "__construct", NULL, 2, _42$$21);
		zephir_check_call_status();
		zephir_throw_exception_debug(_40$$21, "ice/filter.zep", 127 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

