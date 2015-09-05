
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
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"


/**
 * Dumps information about a variable(s)
 *
 * @package     Ice/Dump
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 *
 * <pre><code>
 *  $foo = 123;
 *  echo (new \Ice\Dump())->variable($foo, "foo");
 * </code></pre>
 * 
 * <pre><code>
 *  $foo = "string";
 *  $bar = ["key" => "value"];
 *  $baz = new stdClass();
 *  echo (new \Ice\Dump())->vars($foo, $bar, $baz);
 * </code></pre>
 *
 * Sleet usage:
 * <pre><code>
 *  {{ dump('str', 1, 2.5, true, null, ['key': 'value']) }}
 * </code></pre>
 */
ZEPHIR_INIT_CLASS(Ice_Dump) {

	ZEPHIR_REGISTER_CLASS(Ice, Dump, ice, dump, ice_dump_method_entry, 0);

	zend_declare_property_bool(ice_dump_ce, SL("detailed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dump_ce, SL("methods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dump_ce, SL("styles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_dump_ce->create_object = zephir_init_properties_Ice_Dump;
	return SUCCESS;

}

PHP_METHOD(Ice_Dump, getDetailed) {


	RETURN_MEMBER(this_ptr, "detailed");

}

PHP_METHOD(Ice_Dump, setDetailed) {

	zval *detailed;

	zephir_fetch_params(0, 1, 0, &detailed);



	zephir_update_property_this(this_ptr, SL("detailed"), detailed TSRMLS_CC);

}

/**
 * Dump constructor
 *
 * @param boolean detailed debug object's private and protected properties
 * @param array styles
 */
PHP_METHOD(Ice_Dump, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *styles = NULL;
	zval *detailed_param = NULL, *styles_param = NULL;
	zend_bool detailed;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &detailed_param, &styles_param);

	if (!detailed_param) {
		detailed = 0;
	} else {
		detailed = zephir_get_boolval(detailed_param);
	}
	if (!styles_param) {
		ZEPHIR_INIT_VAR(styles);
		array_init(styles);
	} else {
		zephir_get_arrval(styles, styles_param);
	}


	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 46);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, styles);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("detailed"), detailed ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of vars() method
 *
 * <pre><code>
 *  echo (new \Ice\Dump())->all($foo, $bar, $baz);
 * </code></pre>
 *
 * @param mixed variable
 * @param ...
 * @return string
 */
PHP_METHOD(Ice_Dump, all) {

	zval *_1, *_2 = NULL;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "vars", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(&_2, "func_get_args", NULL, 84);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _0, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get style for type
 *
 * @param string type
 * @return string
 */
PHP_METHOD(Ice_Dump, getStyle) {

	zval *type_param = NULL, *style, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("styles"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&style, _0, type, 1 TSRMLS_CC)) {
		RETURN_CTOR(style);
	} else {
		RETURN_MM_STRING("color:gray", 1);
	}

}

/**
 * Set styles for vars type
 * Styles: pre, arr, bool, float, int, null, num, obj, other, res, str
 *
 * @param array styles
 * @return array
 */
PHP_METHOD(Ice_Dump, setStyles) {

	zval *styles_param = NULL, *defaultStyles, *_0;
	zval *styles = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &styles_param);

	if (!styles_param) {
		ZEPHIR_INIT_VAR(styles);
		array_init(styles);
	} else {
		zephir_get_arrval(styles, styles_param);
	}


	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 98);
		return;
	}
	ZEPHIR_INIT_VAR(defaultStyles);
	zephir_create_array(defaultStyles, 11, 0 TSRMLS_CC);
	add_assoc_stringl_ex(defaultStyles, SS("pre"), SL("background-color:#f9f9f9; font-size:11px; padding:10px; border:1px solid #ccc; text-align:left; color:#333"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("arr"), SL("color:red"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("bool"), SL("color:green"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("float"), SL("color:fuchsia"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("int"), SL("color:blue"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("null"), SL("color:black"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("num"), SL("color:navy"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("obj"), SL("color:purple"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("other"), SL("color:maroon"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("res"), SL("color:lime"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("str"), SL("color:teal"), 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_array_merge(_0, &(defaultStyles), &(styles) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("styles"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "styles");

}

/**
 * Alias of variable() method
 *
 * <pre><code>
 *  echo (new \Ice\Dump())->one($foo, "foo");
 * </code></pre>
 *
 * @param mixed variable
 * @param string name
 * @return string
 */
PHP_METHOD(Ice_Dump, one) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL;
	zval *variable, *name_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "variable", NULL, 0, variable, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepare an HTML string of information about a single variable.
 *
 * @param mixed variable
 * @param string name
 * @param integer tab
 * @return  string
 */
PHP_METHOD(Ice_Dump, output) {

	zend_bool _14, _15, _16;
	HashTable *_7, *_24, *_34;
	HashPosition _6, _23, _33;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_10 = NULL, *_19 = NULL, *_21 = NULL, *_28 = NULL, *_29 = NULL, *_31 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_11 = NULL, *_37 = NULL;
	zval *variable, *name = NULL, *tab = NULL, *key = NULL, *value = NULL, *output = NULL, *space, *type = NULL, *attr = NULL, *_1 = NULL, *_2 = NULL, _4 = zval_used_for_init, **_8, *_9 = NULL, *_12 = NULL, *_13 = NULL, *_17 = NULL, *_18 = NULL, *_20 = NULL, *className, *_22, **_25, *_26 = NULL, *_27 = NULL, *_30, *_32, **_35, *_36, *_38 = NULL, _39;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &variable, &name, &tab);

	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}
	if (!tab) {
		ZEPHIR_INIT_VAR(tab);
		ZVAL_LONG(tab, 1);
	}


	ZEPHIR_INIT_VAR(space);
	ZVAL_STRING(space, "  ", 1);
	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	if (zephir_is_true(name)) {
		ZEPHIR_INIT_NVAR(output);
		ZEPHIR_CONCAT_VS(output, name, " ");
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_create_array(_0, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "arr", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "<b style =':style'>array</b> (<span style =':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_5, 85, &_4, _0);
		zephir_check_call_status();
		zephir_concat_self(&output, _1 TSRMLS_CC);
		zephir_is_iterable(variable, &_7, &_6, 0, 0, "ice/dump.zep", 166);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HMKEY(key, _7, _6);
			ZEPHIR_GET_HVALUE(value, _8);
			ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, 68, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_11);
			zephir_create_array(_11, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "arr", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_3, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			zephir_array_update_string(&_11, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_11, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "[<span style=':style'>:key</span>] => ", 0);
			ZEPHIR_CALL_FUNCTION(&_12, "strtr", &_5, 85, &_4, _11);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_VV(_13, _9, _12);
			zephir_concat_self(&output, _13 TSRMLS_CC);
			_14 = ZEPHIR_IS_LONG(tab, 1);
			if (_14) {
				_14 = !ZEPHIR_IS_STRING(name, "");
			}
			_15 = _14;
			if (_15) {
				_15 = !(Z_TYPE_P(key) == IS_LONG);
			}
			_16 = _15;
			if (_16) {
				_16 = ZEPHIR_IS_EQUAL(name, key);
			}
			if (_16) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_LONG(_18, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_17, this_ptr, "output", &_19, 86, value, _2, _18);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _17, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, 68, space, &_4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(className);
		zephir_get_class(className, variable, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":class"), &className, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>object</b> :class", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_5, 85, &_4, _0);
		zephir_check_call_status();
		zephir_concat_self(&output, _1 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_12, "get_parent_class", &_21, 87, variable);
		zephir_check_call_status();
		if (zephir_is_true(_12)) {
			ZEPHIR_INIT_NVAR(_11);
			zephir_create_array(_11, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_17, this_ptr, "getstyle", &_3, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			zephir_array_update_string(&_11, SL(":style"), &_17, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_17, "get_parent_class", &_21, 87, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_11, SL(":parent"), &_17, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_CALL_FUNCTION(&_17, "strtr", &_5, 85, &_4, _11);
			zephir_check_call_status();
			zephir_concat_self(&output, _17 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		_22 = zephir_fetch_nproperty_this(this_ptr, SL("detailed"), PH_NOISY_CC);
		if (zephir_instance_of_ev(variable, ice_di_ce TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, 68, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_VS(_13, _9, "[skipped]\n");
			zephir_concat_self(&output, _13 TSRMLS_CC);
		} else if (!(zephir_is_true(_22))) {
			ZEPHIR_CALL_FUNCTION(&_9, "get_object_vars", NULL, 88, variable);
			zephir_check_call_status();
			zephir_is_iterable(_9, &_24, &_23, 0, 0, "ice/dump.zep", 189);
			for (
			  ; zephir_hash_get_current_data_ex(_24, (void**) &_25, &_23) == SUCCESS
			  ; zephir_hash_move_forward_ex(_24, &_23)
			) {
				ZEPHIR_GET_HMKEY(key, _24, _23);
				ZEPHIR_GET_HVALUE(value, _25);
				ZEPHIR_CALL_FUNCTION(&_12, "str_repeat", &_10, 68, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_11);
				zephir_create_array(_11, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_26, this_ptr, "getstyle", &_3, 0, _2);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				zephir_array_update_string(&_11, SL(":style"), &_26, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_11, SS(":type"), SL("public"), 1);
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_STRING(&_4, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_26, "strtr", &_5, 85, &_4, _11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_VV(_13, _12, _26);
				zephir_concat_self(&output, _13 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_LONG(_18, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_27, this_ptr, "output", &_19, 86, value, _2, _18);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _27, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			}
		} else {
			do {
				Z_SET_ISREF_P(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_28, 89, variable);
				Z_UNSET_ISREF_P(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(key);
				zephir_array_fetch_string(&key, attr, SL("key"), PH_NOISY, "ice/dump.zep", 197 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, attr, SL("value"), PH_NOISY, "ice/dump.zep", 198 TSRMLS_CC);
				if (!(zephir_is_true(key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(_2);
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_LONG(&_4, 0);
				ZEPHIR_CALL_FUNCTION(&_9, "chr", &_29, 67, &_4);
				zephir_check_call_status();
				zephir_fast_explode(_2, _9, key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(key, _2);
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				if (zephir_array_isset_long(key, 1)) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
					zephir_array_fetch_long(&_30, key, 1, PH_NOISY | PH_READONLY, "ice/dump.zep", 211 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_30, "*")) {
						ZEPHIR_INIT_NVAR(type);
						ZVAL_STRING(type, "protected", 1);
					}
				}
				ZEPHIR_CALL_FUNCTION(&_12, "str_repeat", &_10, 68, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_11);
				zephir_create_array(_11, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_17, this_ptr, "getstyle", &_3, 0, _2);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				zephir_array_update_string(&_11, SL(":style"), &_17, PH_COPY | PH_SEPARATE);
				Z_SET_ISREF_P(key);
				ZEPHIR_CALL_FUNCTION(&_17, "end", &_31, 90, key);
				Z_UNSET_ISREF_P(key);
				zephir_check_call_status();
				zephir_array_update_string(&_11, SL(":key"), &_17, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_STRING(&_4, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_17, "strtr", &_5, 85, &_4, _11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_VV(_13, _12, _17);
				zephir_concat_self(&output, _13 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_LONG(_18, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_26, this_ptr, "output", &_19, 86, value, _2, _18);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _26, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			} while (zephir_is_true(attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 91, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, 68, space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_11);
		zephir_create_array(_11, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_3, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_11, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11, SL(":class"), &className, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_11, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "strtr", &_5, 85, &_4, _11);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_13);
		ZEPHIR_CONCAT_VV(_13, _9, _12);
		zephir_concat_self(&output, _13 TSRMLS_CC);
		_32 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(className, _32 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_17, "str_repeat", &_10, 68, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_20);
			ZEPHIR_CONCAT_VS(_20, _17, "[already listed]\n");
			zephir_concat_self(&output, _20 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_34, &_33, 0, 0, "ice/dump.zep", 236);
			for (
			  ; zephir_hash_get_current_data_ex(_34, (void**) &_35, &_33) == SUCCESS
			  ; zephir_hash_move_forward_ex(_34, &_33)
			) {
				ZEPHIR_GET_HVALUE(value, _35);
				_36 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
				if (!(zephir_fast_in_array(className, _36 TSRMLS_CC))) {
					zephir_update_property_array_append(this_ptr, SL("methods"), className TSRMLS_CC);
				}
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_LONG(&_4, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, 68, space, &_4);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_11);
					zephir_create_array(_11, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_3, 0, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
					zephir_array_update_string(&_11, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_11, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_STRING(&_4, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_CALL_FUNCTION(&_12, "strtr", &_5, 85, &_4, _11);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_13);
					ZEPHIR_CONCAT_VV(_13, _9, _12);
					zephir_concat_self(&output, _13 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_LONG(&_4, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_26, "str_repeat", &_10, 68, space, &_4);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_37);
					zephir_create_array(_37, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_27, this_ptr, "getstyle", &_3, 0, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
					zephir_array_update_string(&_37, SL(":style"), &_27, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_37, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_STRING(&_4, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_CALL_FUNCTION(&_27, "strtr", &_5, 85, &_4, _37);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_38);
					ZEPHIR_CONCAT_VV(_38, _26, _27);
					zephir_concat_self(&output, _38 TSRMLS_CC);
				}
			}
			ZEPHIR_CALL_FUNCTION(&_17, "str_repeat", &_10, 68, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_20);
			ZEPHIR_CONCAT_VS(_20, _17, ")\n");
			zephir_concat_self(&output, _20 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, 68, space, &_4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_5, 85, &_4, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _1);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_1, "is_float", NULL, 92, variable);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_3, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>float</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "strtr", &_5, 85, &_4, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _12);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_5, 85, &_4, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _1);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 4);
		ZEPHIR_SINIT_VAR(_39);
		ZVAL_STRING(&_39, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "htmlentities", NULL, 93, variable, &_4, &_39);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_26, "nl2br", NULL, 94, _1);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":var"), &_26, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_26, "strtr", &_5, 85, &_4, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _26);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_13);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_13);
			ZVAL_STRING(_13, "true", 1);
		} else {
			ZEPHIR_INIT_NVAR(_13);
			ZVAL_STRING(_13, "false", 1);
		}
		zephir_array_update_string(&_0, SL(":var"), &_13, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_5, 85, &_4, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _1);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>null</b>", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_5, 85, &_4, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _1);
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_STRING(&_4, "(<span style=':style'>:var</span>)", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_5, 85, &_4, _0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, output, _1);
	RETURN_MM();

}

/**
 * Returns an HTML string of information about a single variable.
 *
 * <pre><code>
 *  $foo = 123;
 *  echo (new \Ice\Dump())->variable($foo, "foo");
 * </code></pre>
 *
 * @param mixed variable
 * @param string name
 * @return string
 */
PHP_METHOD(Ice_Dump, variable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *name = NULL;
	zval *variable, *name_param = NULL, *_1 = NULL, *_2, _3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "pre", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "output", NULL, 0, variable, name);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":output"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "<pre style=':style'>:output</pre>", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 85, &_3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an HTML string of debugging information about any number of
 * variables, each wrapped in a "pre" tag.
 *
 * <pre><code>
 *  $foo = "string";
 *  $bar = ["key" => "value"];
 *  $baz = new stdClass();
 *  echo (new \Ice\Dump())->vars($foo, $bar, $baz);
 * </code></pre>
 *
 * @param mixed variable
 * @param ...
 * @return string
 */
PHP_METHOD(Ice_Dump, vars) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *value = NULL, *output, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", NULL, 84);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/dump.zep", 309);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SV(_5, "var ", key);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "one", &_6, 0, value, _5);
		zephir_check_call_status();
		zephir_concat_self(&output, _4 TSRMLS_CC);
	}
	RETURN_CCTOR(output);

}

static zend_object_value zephir_init_properties_Ice_Dump(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("styles"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("styles"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("methods"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

