
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
 * @copyright   (c) 2014-2018 Ice Team
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
 * @return object Filter
 */
PHP_METHOD(Ice_Filter, add) {

	zval *name_param = NULL, *body, body_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&body_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &body);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	if (Z_TYPE_P(body) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Filter must be an object", "ice/filter.zep", 28);
		return;
	}
	zephir_update_property_array(this_ptr, SL("filters"), &name, body TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sanitizes a value with a specified single or set of filters.
 *
 * @param mixed value
 * @param mixed filters
 * @return mixed
 */
PHP_METHOD(Ice_Filter, sanitize) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, *filters = NULL, filters_sub, filter, _0$$3, *_1$$4, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &filters);

	ZEPHIR_SEPARATE_PARAM(value);
	ZEPHIR_SEPARATE_PARAM(filters);


	if (Z_TYPE_P(filters) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_explode_str(&_0$$3, SL("|"), filters, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(filters, &_0$$3);
	}
	if (Z_TYPE_P(filters) == IS_ARRAY) {
		zephir_is_iterable(filters, 0, "ice/filter.zep", 55);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(filters), _1$$4)
		{
			ZEPHIR_INIT_NVAR(&filter);
			ZVAL_COPY(&filter, _1$$4);
			ZEPHIR_CALL_METHOD(&_2$$5, this_ptr, "dosanitize", &_3, 0, value, &filter);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, &_2$$5);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&filter);
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

	zval _1$$4, _30$$19, _32$$19;
	zephir_fcall_cache_entry *_14 = NULL, *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *filter_param = NULL, custom, _0, _2$$5, _3$$5, _4$$6, _5$$6, _6$$7, _7$$8, _8$$9, _9$$9, _10$$9, _11$$9, _12$$9, _13$$9, _15$$10, _16$$11, _17$$12, _18$$12, _19$$13, _20$$13, _21$$14, _23$$15, _24$$16, _25$$16, _26$$16, _27$$17, _28$$17, _29$$18, _31$$19, _33$$19, _34$$19, _35$$19, _37$$20, _38$$21, _39$$22, _40$$22, _41$$22;
	zval value, filter, _36$$20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&custom);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_34$$19);
	ZVAL_UNDEF(&_35$$19);
	ZVAL_UNDEF(&_37$$20);
	ZVAL_UNDEF(&_38$$21);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_40$$22);
	ZVAL_UNDEF(&_41$$22);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_32$$19);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value_param, &filter_param);

	zephir_get_strval(&value, value_param);
	if (UNEXPECTED(Z_TYPE_P(filter_param) != IS_STRING && Z_TYPE_P(filter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filter' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filter_param) == IS_STRING)) {
		zephir_get_strval(&filter, filter_param);
	} else {
		ZEPHIR_INIT_VAR(&filter);
		ZVAL_EMPTY_STRING(&filter);
	}


	ZEPHIR_OBS_VAR(&custom);
	zephir_read_property(&_0, this_ptr, SL("filters"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&custom, &_0, &filter, 0 TSRMLS_CC)) {
		if (zephir_instance_of_ev(&custom, zend_ce_closure TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_1$$4, &value);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &custom, &_1$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_METHOD(&custom, "sanitize", NULL, 0, &value);
		zephir_check_call_status();
		RETURN_MM();
	}
	do {
		if (ZEPHIR_IS_STRING(&filter, "cssmin")) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "Ice\\Filter\\Css");
			ZEPHIR_INIT_NVAR(&custom);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&custom, &_2$$5 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "cssmin");
			zephir_update_property_array(this_ptr, SL("filters"), &_3$$5, &custom TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(&custom, "sanitize", NULL, 0, &value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "jsmin")) {
			ZEPHIR_INIT_VAR(&_4$$6);
			ZVAL_STRING(&_4$$6, "Ice\\Filter\\Js");
			ZEPHIR_INIT_NVAR(&custom);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&custom, &_4$$6 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "jsmin");
			zephir_update_property_array(this_ptr, SL("filters"), &_5$$6, &custom TSRMLS_CC);
			ZEPHIR_RETURN_CALL_METHOD(&custom, "sanitize", NULL, 0, &value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "camelize")) {
			ZEPHIR_INIT_VAR(&_6$$7);
			zephir_camelize(&_6$$7, &value, NULL  );
			RETURN_CCTOR(&_6$$7);
		}
		if (ZEPHIR_IS_STRING(&filter, "uncamelize")) {
			ZEPHIR_INIT_VAR(&_7$$8);
			zephir_uncamelize(&_7$$8, &value, NULL  );
			RETURN_CCTOR(&_7$$8);
		}
		if (ZEPHIR_IS_STRING(&filter, "human")) {
			ZEPHIR_INIT_VAR(&_8$$9);
			ZEPHIR_INIT_VAR(&_9$$9);
			ZEPHIR_INIT_VAR(&_10$$9);
			ZEPHIR_INIT_VAR(&_11$$9);
			ZVAL_STRING(&_11$$9, "/(?<=\\w)(?=[A-Z])/");
			ZEPHIR_INIT_VAR(&_12$$9);
			ZVAL_STRING(&_12$$9, " $1");
			ZEPHIR_CALL_FUNCTION(&_13$$9, "preg_replace", &_14, 82, &_11$$9, &_12$$9, &value);
			zephir_check_call_status();
			zephir_fast_strtolower(&_10$$9, &_13$$9);
			ZEPHIR_INIT_NVAR(&_11$$9);
			ZVAL_STRING(&_11$$9, "_");
			ZEPHIR_INIT_NVAR(&_12$$9);
			ZVAL_STRING(&_12$$9, " ");
			zephir_fast_str_replace(&_9$$9, &_11$$9, &_12$$9, &_10$$9 TSRMLS_CC);
			zephir_fast_trim(&_8$$9, &_9$$9, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			zephir_ucfirst(return_value, &_8$$9);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "lower")) {
			ZEPHIR_INIT_VAR(&_15$$10);
			if ((zephir_function_exists_ex(SL("mb_strtolower") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_FUNCTION(&_15$$10, "mb_strtolower", NULL, 121, &value);
				zephir_check_call_status();
			} else {
				zephir_fast_strtolower(&_15$$10, &value);
			}
			RETURN_CCTOR(&_15$$10);
		}
		if (ZEPHIR_IS_STRING(&filter, "upper")) {
			ZEPHIR_INIT_VAR(&_16$$11);
			if ((zephir_function_exists_ex(SL("mb_strtoupper") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_FUNCTION(&_16$$11, "mb_strtoupper", NULL, 122, &value);
				zephir_check_call_status();
			} else {
				zephir_fast_strtoupper(&_16$$11, &value);
			}
			RETURN_CCTOR(&_16$$11);
		}
		if (ZEPHIR_IS_STRING(&filter, "alnum")) {
			ZEPHIR_INIT_VAR(&_17$$12);
			ZVAL_STRING(&_17$$12, "/[^a-z0-9]/i");
			ZEPHIR_INIT_VAR(&_18$$12);
			ZVAL_STRING(&_18$$12, "");
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_14, 82, &_17$$12, &_18$$12, &value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "alpha")) {
			ZEPHIR_INIT_VAR(&_19$$13);
			ZVAL_STRING(&_19$$13, "/[^a-z]/i");
			ZEPHIR_INIT_VAR(&_20$$13);
			ZVAL_STRING(&_20$$13, "");
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_14, 82, &_19$$13, &_20$$13, &value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "email")) {
			ZVAL_LONG(&_21$$14, 517);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_22, 123, &value, &_21$$14);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "bool") || ZEPHIR_IS_STRING(&filter, "boolean")) {
			ZVAL_LONG(&_23$$15, 258);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_22, 123, &value, &_23$$15);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "float")) {
			ZVAL_LONG(&_24$$16, 520);
			ZVAL_LONG(&_25$$16, 4096);
			ZEPHIR_CALL_FUNCTION(&_26$$16, "filter_var", &_22, 123, &value, &_24$$16, &_25$$16);
			zephir_check_call_status();
			RETURN_MM_DOUBLE(zephir_get_doubleval(&_26$$16));
		}
		if (ZEPHIR_IS_STRING(&filter, "int") || ZEPHIR_IS_STRING(&filter, "integer")) {
			ZVAL_LONG(&_27$$17, 519);
			ZEPHIR_CALL_FUNCTION(&_28$$17, "filter_var", &_22, 123, &value, &_27$$17);
			zephir_check_call_status();
			RETURN_MM_LONG(zephir_get_intval(&_28$$17));
		}
		if (ZEPHIR_IS_STRING(&filter, "string")) {
			ZVAL_LONG(&_29$$18, 513);
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_22, 123, &value, &_29$$18);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "repeats") || ZEPHIR_IS_STRING(&filter, "strip_repeats")) {
			ZEPHIR_INIT_VAR(&_30$$19);
			zephir_create_array(&_30$$19, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_31$$19);
			ZVAL_STRING(&_31$$19, "/[ ]{2,}/");
			zephir_array_fast_append(&_30$$19, &_31$$19);
			ZEPHIR_INIT_NVAR(&_31$$19);
			ZVAL_STRING(&_31$$19, "/((\\r\\n|\\n\\r|\\n|\\r){3,})/");
			zephir_array_fast_append(&_30$$19, &_31$$19);
			ZEPHIR_INIT_NVAR(&_31$$19);
			ZVAL_STRING(&_31$$19, "~(.?)\\1{3,}~");
			zephir_array_fast_append(&_30$$19, &_31$$19);
			ZEPHIR_INIT_VAR(&_32$$19);
			zephir_create_array(&_32$$19, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_31$$19);
			ZVAL_STRING(&_31$$19, " ");
			zephir_array_fast_append(&_32$$19, &_31$$19);
			ZEPHIR_INIT_NVAR(&_31$$19);
			ZEPHIR_GET_CONSTANT(&_31$$19, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_33$$19);
			ZEPHIR_GET_CONSTANT(&_33$$19, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_34$$19);
			ZEPHIR_CONCAT_VV(&_34$$19, &_31$$19, &_33$$19);
			zephir_array_fast_append(&_32$$19, &_34$$19);
			ZEPHIR_INIT_VAR(&_35$$19);
			ZVAL_STRING(&_35$$19, "$1$1$1");
			zephir_array_fast_append(&_32$$19, &_35$$19);
			ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_14, 82, &_30$$19, &_32$$19, &value);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "e") || ZEPHIR_IS_STRING(&filter, "escape") || ZEPHIR_IS_STRING(&filter, "strip_special")) {
			zephir_get_strval(&_36$$20, &value);
			ZVAL_LONG(&_37$$20, (3 | 48));
			ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 114, &_36$$20, &_37$$20);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&filter, "unescape") || ZEPHIR_IS_STRING(&filter, "unstrip_special")) {
			ZVAL_LONG(&_38$$21, (3 | 48));
			ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars_decode", NULL, 124, &value, &_38$$21);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_39$$22);
		object_init_ex(&_39$$22, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_40$$22);
		ZVAL_STRING(&_40$$22, "Filter '%s' is not supported");
		ZEPHIR_CALL_FUNCTION(&_41$$22, "sprintf", NULL, 11, &_40$$22, &filter);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_39$$22, "__construct", NULL, 12, &_41$$22);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_39$$22, "ice/filter.zep", 134 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

