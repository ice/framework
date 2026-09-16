
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * Filter component provides a set of commonly needed data filters.
 *
 * @package     Ice/Filter
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Filter)
{
	ZEPHIR_REGISTER_CLASS(Ice, Filter, ice, filter, ice_filter_method_entry, 0);

	zend_declare_property_null(ice_filter_ce, SL("filters"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Adds a user-defined filter.
 *
 * @param string name
 * @param callable body
 * @return object Filter
 */
PHP_METHOD(Ice_Filter, add)
{
	zval name_zv, *body, body_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&body_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(body)
	ZEND_PARSE_PARAMETERS_END();
	body = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	if (Z_TYPE_P(body) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(ice_exception_ce, "Filter must be an object", "ice/filter.zep", 27);
		return;
	}
	zephir_update_property_array(this_ptr, SL("filters"), &name_zv, body);
	RETURN_THISW();
}

/**
 * Sanitizes a value with a specified single or set of filters.
 *
 * @param mixed value
 * @param mixed filters
 * @return mixed
 */
PHP_METHOD(Ice_Filter, sanitize)
{
	zend_bool _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, *filters = NULL, filters_sub, filter, _0$$3, *_1$$4, _2$$4, *_3$$4, _6$$4, _4$$5, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$6);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(value)
		Z_PARAM_ZVAL(filters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &value, &filters);
	ZEPHIR_SEPARATE_PARAM(value);
	ZEPHIR_SEPARATE_PARAM(filters);
	if (Z_TYPE_P(filters) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_explode_str(&_0$$3, SL("|"), filters, ZEND_LONG_MAX);
		ZEPHIR_CPY_WRT(filters, &_0$$3);
	}
	if (Z_TYPE_P(filters) == IS_ARRAY) {
		if (Z_TYPE_P(filters) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_string_to_char_array(&_2$$4, filters);
			_1$$4 = &_2$$4;
		} else {
			_1$$4 = filters;
		}
		zephir_is_iterable(_1$$4, 0, "ice/filter.zep", 54);
		if (Z_TYPE_P(_1$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1$$4), _3$$4)
			{
				ZEPHIR_INIT_NVAR(&filter);
				ZVAL_COPY(&filter, _3$$4);
				ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "dosanitize", &_5, 0, value, &filter);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(value, &_4$$5);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_7$$4 = 1;
			while (1) {
				if (_7$$4) {
					_7$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _1$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_6$$4, _1$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&filter, _1$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8$$6, this_ptr, "dosanitize", &_5, 0, value, &filter);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(value, &_8$$6);
			}
		}
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
PHP_METHOD(Ice_Filter, doSanitize)
{
	zval _34$$20;
	zval _1$$4, _28$$19, _30$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *filter = NULL;
	zval *value, value_sub, filter_zv, custom, _0, _2$$5, _3$$5, _4$$6, _5$$6, _6$$9, _7$$9, _8$$9, _9$$9, _10$$9, _11$$9, _13$$10, _14$$11, _15$$12, _16$$12, _17$$13, _18$$13, _19$$14, _21$$15, _22$$16, _23$$16, _24$$16, _25$$17, _26$$17, _27$$18, _29$$19, _31$$19, _32$$19, _33$$19, _35$$20, _36$$21, _37$$22, _38$$22, _39$$22;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&filter_zv);
	ZVAL_UNDEF(&custom);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_38$$22);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_34$$20);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("filters", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(value)
		Z_PARAM_STR(filter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&filter_zv);
	ZVAL_STR_COPY(&filter_zv, filter);
	zephir_memory_observe(&custom);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 159, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&custom, &_0, &filter_zv, 0)) {
		if (zephir_is_instance_of(&custom, SL("Closure"))) {
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0);
			zephir_array_fast_append(&_1$$4, value);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &custom, &_1$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_METHOD(&custom, "sanitize", NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&filter_zv, "cssmin")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&filter_zv, "jsmin")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&filter_zv, "camelize")) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_STRING(&filter_zv, "uncamelize")) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_STRING(&filter_zv, "human")) { goto zephir_switch_0_clause_4; }
	if (ZEPHIR_IS_STRING(&filter_zv, "lower")) { goto zephir_switch_0_clause_5; }
	if (ZEPHIR_IS_STRING(&filter_zv, "upper")) { goto zephir_switch_0_clause_6; }
	if (ZEPHIR_IS_STRING(&filter_zv, "alnum")) { goto zephir_switch_0_clause_7; }
	if (ZEPHIR_IS_STRING(&filter_zv, "alpha")) { goto zephir_switch_0_clause_8; }
	if (ZEPHIR_IS_STRING(&filter_zv, "email")) { goto zephir_switch_0_clause_9; }
	if (ZEPHIR_IS_STRING(&filter_zv, "bool")) { goto zephir_switch_0_clause_10; }
	if (ZEPHIR_IS_STRING(&filter_zv, "boolean")) { goto zephir_switch_0_clause_11; }
	if (ZEPHIR_IS_STRING(&filter_zv, "float")) { goto zephir_switch_0_clause_12; }
	if (ZEPHIR_IS_STRING(&filter_zv, "int")) { goto zephir_switch_0_clause_13; }
	if (ZEPHIR_IS_STRING(&filter_zv, "integer")) { goto zephir_switch_0_clause_14; }
	if (ZEPHIR_IS_STRING(&filter_zv, "string")) { goto zephir_switch_0_clause_15; }
	if (ZEPHIR_IS_STRING(&filter_zv, "repeats")) { goto zephir_switch_0_clause_16; }
	if (ZEPHIR_IS_STRING(&filter_zv, "strip_repeats")) { goto zephir_switch_0_clause_17; }
	if (ZEPHIR_IS_STRING(&filter_zv, "e")) { goto zephir_switch_0_clause_18; }
	if (ZEPHIR_IS_STRING(&filter_zv, "escape")) { goto zephir_switch_0_clause_19; }
	if (ZEPHIR_IS_STRING(&filter_zv, "strip_special")) { goto zephir_switch_0_clause_20; }
	if (ZEPHIR_IS_STRING(&filter_zv, "unescape")) { goto zephir_switch_0_clause_21; }
	if (ZEPHIR_IS_STRING(&filter_zv, "unstrip_special")) { goto zephir_switch_0_clause_22; }
	goto zephir_switch_0_clause_23;
	zephir_switch_0_clause_0: ;
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "Ice\\Filter\\Css");
		ZEPHIR_INIT_NVAR(&custom);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&custom, &_2$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "cssmin");
		zephir_update_property_array(this_ptr, SL("filters"), &_3$$5, &custom);
		ZEPHIR_RETURN_CALL_METHOD(&custom, "sanitize", NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_1: ;
		ZEPHIR_INIT_VAR(&_4$$6);
		ZVAL_STRING(&_4$$6, "Ice\\Filter\\Js");
		ZEPHIR_INIT_NVAR(&custom);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&custom, &_4$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$6);
		ZVAL_STRING(&_5$$6, "jsmin");
		zephir_update_property_array(this_ptr, SL("filters"), &_5$$6, &custom);
		ZEPHIR_RETURN_CALL_METHOD(&custom, "sanitize", NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_2: ;
		ZEPHIR_RETURN_CALL_METHOD(value, "camelize", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_3: ;
		ZEPHIR_RETURN_CALL_METHOD(value, "uncamelize", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_4: ;
		ZEPHIR_INIT_VAR(&_6$$9);
		ZEPHIR_INIT_VAR(&_7$$9);
		ZEPHIR_INIT_VAR(&_8$$9);
		ZEPHIR_INIT_VAR(&_9$$9);
		ZVAL_STRING(&_9$$9, "/(?<=\\w)(?=[A-Z])/");
		ZEPHIR_INIT_VAR(&_10$$9);
		ZVAL_STRING(&_10$$9, " $1");
		ZEPHIR_CALL_FUNCTION(&_11$$9, "preg_replace", &_12, 53, &_9$$9, &_10$$9, value);
		zephir_check_call_status();
		zephir_fast_strtolower(&_8$$9, &_11$$9);
		ZEPHIR_INIT_NVAR(&_9$$9);
		ZVAL_STRING(&_9$$9, "_");
		ZEPHIR_INIT_NVAR(&_10$$9);
		ZVAL_STRING(&_10$$9, " ");
		zephir_fast_str_replace(&_7$$9, &_9$$9, &_10$$9, &_8$$9);
		zephir_fast_trim(&_6$$9, &_7$$9, NULL , ZEPHIR_TRIM_BOTH);
		zephir_ucfirst(return_value, &_6$$9);
		RETURN_MM();
	zephir_switch_0_clause_5: ;
		ZEPHIR_INIT_VAR(&_13$$10);
		if ((zephir_function_exists_ex(ZEND_STRL("mb_strtolower")) == SUCCESS)) {
			ZEPHIR_CALL_FUNCTION(&_13$$10, "mb_strtolower", NULL, 133, value);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&_13$$10);
			zephir_fast_strtolower(&_13$$10, value);
		}
		RETURN_CCTOR(&_13$$10);
	zephir_switch_0_clause_6: ;
		ZEPHIR_INIT_VAR(&_14$$11);
		if ((zephir_function_exists_ex(ZEND_STRL("mb_strtoupper")) == SUCCESS)) {
			ZEPHIR_CALL_FUNCTION(&_14$$11, "mb_strtoupper", NULL, 134, value);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&_14$$11);
			zephir_fast_strtoupper(&_14$$11, value);
		}
		RETURN_CCTOR(&_14$$11);
	zephir_switch_0_clause_7: ;
		ZEPHIR_INIT_VAR(&_15$$12);
		ZVAL_STRING(&_15$$12, "/[^a-z0-9]/i");
		ZEPHIR_INIT_VAR(&_16$$12);
		ZVAL_STRING(&_16$$12, "");
		ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_12, 53, &_15$$12, &_16$$12, value);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_8: ;
		ZEPHIR_INIT_VAR(&_17$$13);
		ZVAL_STRING(&_17$$13, "/[^a-z]/i");
		ZEPHIR_INIT_VAR(&_18$$13);
		ZVAL_STRING(&_18$$13, "");
		ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_12, 53, &_17$$13, &_18$$13, value);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_9: ;
		ZVAL_LONG(&_19$$14, 517);
		ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_20, 135, value, &_19$$14);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_10: ;
	zephir_switch_0_clause_11: ;
		ZVAL_LONG(&_21$$15, 258);
		ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_20, 135, value, &_21$$15);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_12: ;
		ZVAL_LONG(&_22$$16, 520);
		ZVAL_LONG(&_23$$16, 4096);
		ZEPHIR_CALL_FUNCTION(&_24$$16, "filter_var", &_20, 135, value, &_22$$16, &_23$$16);
		zephir_check_call_status();
		RETURN_MM_DOUBLE(zephir_get_doubleval(&_24$$16));
	zephir_switch_0_clause_13: ;
	zephir_switch_0_clause_14: ;
		ZVAL_LONG(&_25$$17, 519);
		ZEPHIR_CALL_FUNCTION(&_26$$17, "filter_var", &_20, 135, value, &_25$$17);
		zephir_check_call_status();
		RETURN_MM_LONG(zephir_get_intval(&_26$$17));
	zephir_switch_0_clause_15: ;
		ZVAL_LONG(&_27$$18, 516);
		ZEPHIR_RETURN_CALL_FUNCTION("filter_var", &_20, 135, value, &_27$$18);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_16: ;
	zephir_switch_0_clause_17: ;
		ZEPHIR_INIT_VAR(&_28$$19);
		zephir_create_array(&_28$$19, 3, 0);
		ZEPHIR_INIT_VAR(&_29$$19);
		ZVAL_STRING(&_29$$19, "/[ ]{2,}/");
		zephir_array_fast_append(&_28$$19, &_29$$19);
		ZEPHIR_INIT_NVAR(&_29$$19);
		ZVAL_STRING(&_29$$19, "/((\\r\\n|\\n\\r|\\n|\\r){3,})/");
		zephir_array_fast_append(&_28$$19, &_29$$19);
		ZEPHIR_INIT_NVAR(&_29$$19);
		ZVAL_STRING(&_29$$19, "~(.?)\\1{3,}~");
		zephir_array_fast_append(&_28$$19, &_29$$19);
		ZEPHIR_INIT_VAR(&_30$$19);
		zephir_create_array(&_30$$19, 3, 0);
		ZEPHIR_INIT_NVAR(&_29$$19);
		ZVAL_STRING(&_29$$19, " ");
		zephir_array_fast_append(&_30$$19, &_29$$19);
		ZEPHIR_INIT_NVAR(&_29$$19);
		ZEPHIR_GET_CONSTANT(&_29$$19, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_31$$19);
		ZEPHIR_GET_CONSTANT(&_31$$19, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_32$$19);
		ZEPHIR_CONCAT_VV(&_32$$19, &_29$$19, &_31$$19);
		zephir_array_fast_append(&_30$$19, &_32$$19);
		ZEPHIR_INIT_VAR(&_33$$19);
		ZVAL_STRING(&_33$$19, "$1$1$1");
		zephir_array_fast_append(&_30$$19, &_33$$19);
		ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_12, 53, &_28$$19, &_30$$19, value);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_18: ;
	zephir_switch_0_clause_19: ;
	zephir_switch_0_clause_20: ;
		zephir_cast_to_string(&_34$$20, value);
		ZVAL_LONG(&_35$$20, (3 | 48));
		ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 126, &_34$$20, &_35$$20);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_21: ;
	zephir_switch_0_clause_22: ;
		ZVAL_LONG(&_36$$21, (3 | 48));
		ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars_decode", NULL, 136, value, &_36$$21);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_23: ;
		ZEPHIR_INIT_VAR(&_37$$22);
		object_init_ex(&_37$$22, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_38$$22);
		ZVAL_STRING(&_38$$22, "Filter '%s' is not supported");
		ZEPHIR_CALL_FUNCTION(&_39$$22, "sprintf", NULL, 12, &_38$$22, &filter_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_37$$22, "__construct", NULL, 13, &_39$$22);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_37$$22, "ice/filter.zep", 133);
		ZEPHIR_MM_RESTORE();
		return;

}

