
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

ZEPHIR_INIT_CLASS(Ice_Dump) {

	ZEPHIR_REGISTER_CLASS(Ice, Dump, ice, dump, ice_dump_method_entry, 0);

	zend_declare_property_bool(ice_dump_ce, SL("_detailed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dump_ce, SL("_methods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dump_ce, SL("_styles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Dump, getDetailed) {


	RETURN_MEMBER(this_ptr, "_detailed");

}

PHP_METHOD(Ice_Dump, setDetailed) {

	zval *detailed;

	zephir_fetch_params(0, 1, 0, &detailed);



	zephir_update_property_this(this_ptr, SL("_detailed"), detailed TSRMLS_CC);

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
	zval *detailed_param = NULL, *styles_param = NULL, *_0, *_1;
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


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_styles"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_methods"), _1 TSRMLS_CC);
	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 46);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, styles);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_detailed"), detailed ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *_1, *_2 = NULL;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "vars", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(&_2, "func_get_args", &_3);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_styles"), PH_NOISY_CC);
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
	array_init_size(defaultStyles, 14);
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
	zephir_update_property_this(this_ptr, SL("_styles"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "_styles");

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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "variable", NULL, variable, name);
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
	zephir_fcall_cache_entry *_12 = NULL, *_19 = NULL;
	HashTable *_6, *_25, *_37;
	HashPosition _5, _24, _36;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL, *_21 = NULL, *_23 = NULL, *_29 = NULL, *_30 = NULL, *_31 = NULL, *_33 = NULL, *_34 = NULL, *_42 = NULL, *_44 = NULL, *_45 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_10 = NULL, *_40 = NULL;
	zval *variable, *name = NULL, *tab = NULL, *key = NULL, *value = NULL, *output = NULL, *space, *type = NULL, *attr = NULL, *_1 = NULL, *_2 = NULL, _3 = zval_used_for_init, **_7, *_8 = NULL, *_11 = NULL, *_13 = NULL, *_17 = NULL, *_18 = NULL, *_20 = NULL, *className, *_22, **_26, *_27 = NULL, *_28 = NULL, *_32, *_35, **_38, *_39, *_41 = NULL, _43;

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
		array_init_size(_0, 3);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "arr", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "<b style =':style'>array</b> (<span style =':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_4, &_3, _0);
		zephir_check_call_status();
		zephir_concat_self(&output, _1 TSRMLS_CC);
		zephir_is_iterable(variable, &_6, &_5, 0, 0, "ice/dump.zep", 165);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HMKEY(key, _6, _5);
			ZEPHIR_GET_HVALUE(value, _7);
			ZEPHIR_CALL_FUNCTION(&_8, "str_repeat", &_9, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_10);
			array_init_size(_10, 3);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "arr", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_11, this_ptr, "getstyle", &_12, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			zephir_array_update_string(&_10, SL(":style"), &_11, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "[<span style=':style'>:key</span>] => ", 0);
			ZEPHIR_CALL_FUNCTION(&_11, "strtr", &_4, &_3, _10);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_VV(_13, _8, _11);
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
				ZEPHIR_CALL_METHOD(&_17, this_ptr, "output", &_19, value, _2, _18);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _17, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_8, "str_repeat", &_9, space, &_3);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(className);
		zephir_get_class(className, variable, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_12, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":class"), &className, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>object</b> :class", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_4, &_3, _0);
		zephir_check_call_status();
		zephir_concat_self(&output, _1 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "get_parent_class", &_21, variable);
		zephir_check_call_status();
		if (zephir_is_true(_11)) {
			ZEPHIR_INIT_NVAR(_10);
			array_init_size(_10, 3);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_17, this_ptr, "getstyle", &_12, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			zephir_array_update_string(&_10, SL(":style"), &_17, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_17, "get_parent_class", &_21, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_10, SL(":parent"), &_17, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_CALL_FUNCTION(&_17, "strtr", &_4, &_3, _10);
			zephir_check_call_status();
			zephir_concat_self(&output, _17 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		_22 = zephir_fetch_nproperty_this(this_ptr, SL("_detailed"), PH_NOISY_CC);
		if (!(zephir_is_true(_22))) {
			ZEPHIR_CALL_FUNCTION(&_8, "get_object_vars", &_23, variable);
			zephir_check_call_status();
			zephir_is_iterable(_8, &_25, &_24, 0, 0, "ice/dump.zep", 184);
			for (
			  ; zephir_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
			  ; zephir_hash_move_forward_ex(_25, &_24)
			) {
				ZEPHIR_GET_HMKEY(key, _25, _24);
				ZEPHIR_GET_HVALUE(value, _26);
				ZEPHIR_CALL_FUNCTION(&_11, "str_repeat", &_9, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_10);
				array_init_size(_10, 4);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_27, this_ptr, "getstyle", &_12, _2);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				zephir_array_update_string(&_10, SL(":style"), &_27, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_10, SS(":type"), SL("public"), 1);
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_STRING(&_3, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_27, "strtr", &_4, &_3, _10);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_VV(_13, _11, _27);
				zephir_concat_self(&output, _13 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_LONG(_18, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_28, this_ptr, "output", &_19, value, _2, _18);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _28, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			}
		} else {
			do {
				Z_SET_ISREF_P(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_29, variable);
				Z_UNSET_ISREF_P(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(key);
				zephir_array_fetch_string(&key, attr, SL("key"), PH_NOISY, "ice/dump.zep", 191 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, attr, SL("value"), PH_NOISY, "ice/dump.zep", 192 TSRMLS_CC);
				if (!(zephir_is_true(key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(_2);
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_STRING(&_3, "\\x00", 0);
				ZEPHIR_CALL_FUNCTION(&_8, "ord", &_30, &_3);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_11, "chr", &_31, _8);
				zephir_check_call_status();
				zephir_fast_explode(_2, _11, key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(key, _2);
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				if (zephir_array_isset_long(key, 1)) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
					zephir_array_fetch_long(&_32, key, 1, PH_NOISY | PH_READONLY, "ice/dump.zep", 203 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_32, "*")) {
						ZEPHIR_INIT_NVAR(type);
						ZVAL_STRING(type, "protected", 1);
					}
				}
				ZEPHIR_CALL_FUNCTION(&_17, "str_repeat", &_9, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_10);
				array_init_size(_10, 4);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_27, this_ptr, "getstyle", &_12, _2);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				zephir_array_update_string(&_10, SL(":style"), &_27, PH_COPY | PH_SEPARATE);
				Z_SET_ISREF_P(key);
				ZEPHIR_CALL_FUNCTION(&_27, "end", &_33, key);
				Z_UNSET_ISREF_P(key);
				zephir_check_call_status();
				zephir_array_update_string(&_10, SL(":key"), &_27, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_STRING(&_3, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_27, "strtr", &_4, &_3, _10);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_VV(_13, _17, _27);
				zephir_concat_self(&output, _13 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_LONG(_18, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_28, this_ptr, "output", &_19, value, _2, _18);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _28, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			} while (zephir_is_true(attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", &_34, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_8, "str_repeat", &_9, space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_10);
		array_init_size(_10, 4);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "getstyle", &_12, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_10, SL(":style"), &_11, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_10, SL(":class"), &className, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_10, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_11, "strtr", &_4, &_3, _10);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_13);
		ZEPHIR_CONCAT_VV(_13, _8, _11);
		zephir_concat_self(&output, _13 TSRMLS_CC);
		_35 = zephir_fetch_nproperty_this(this_ptr, SL("_methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(className, _35 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_17, "str_repeat", &_9, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_20);
			ZEPHIR_CONCAT_VS(_20, _17, "[already listed]\n");
			zephir_concat_self(&output, _20 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_37, &_36, 0, 0, "ice/dump.zep", 228);
			for (
			  ; zephir_hash_get_current_data_ex(_37, (void**) &_38, &_36) == SUCCESS
			  ; zephir_hash_move_forward_ex(_37, &_36)
			) {
				ZEPHIR_GET_HVALUE(value, _38);
				_39 = zephir_fetch_nproperty_this(this_ptr, SL("_methods"), PH_NOISY_CC);
				if (!(zephir_fast_in_array(className, _39 TSRMLS_CC))) {
					zephir_update_property_array_append(this_ptr, SL("_methods"), className TSRMLS_CC);
				}
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_LONG(&_3, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_8, "str_repeat", &_9, space, &_3);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_10);
					array_init_size(_10, 3);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_11, this_ptr, "getstyle", &_12, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
					zephir_array_update_string(&_10, SL(":style"), &_11, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_10, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_STRING(&_3, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_CALL_FUNCTION(&_11, "strtr", &_4, &_3, _10);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_13);
					ZEPHIR_CONCAT_VV(_13, _8, _11);
					zephir_concat_self(&output, _13 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_LONG(&_3, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_27, "str_repeat", &_9, space, &_3);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_40);
					array_init_size(_40, 3);
					ZEPHIR_INIT_NVAR(_2);
					ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_28, this_ptr, "getstyle", &_12, _2);
					zephir_check_temp_parameter(_2);
					zephir_check_call_status();
					zephir_array_update_string(&_40, SL(":style"), &_28, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_40, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_STRING(&_3, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_CALL_FUNCTION(&_28, "strtr", &_4, &_3, _40);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_41);
					ZEPHIR_CONCAT_VV(_41, _27, _28);
					zephir_concat_self(&output, _41 TSRMLS_CC);
				}
			}
			ZEPHIR_CALL_FUNCTION(&_17, "str_repeat", &_9, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_20);
			ZEPHIR_CONCAT_VS(_20, _17, ")\n");
			zephir_concat_self(&output, _20 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_8, "str_repeat", &_9, space, &_3);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_12, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_4, &_3, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _1);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_1, "is_float", &_42, variable);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "getstyle", &_12, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_11, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>float</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_11, "strtr", &_4, &_3, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _11);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 4);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_12, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_4, &_3, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _1);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 4);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_12, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 4);
		ZEPHIR_SINIT_VAR(_43);
		ZVAL_STRING(&_43, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "htmlentities", &_44, variable, &_3, &_43);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_27, "nl2br", &_45, _1);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":var"), &_27, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_27, "strtr", &_4, &_3, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_12, _2);
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
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_4, &_3, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _1);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 2);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_12, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>null</b>", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_4, &_3, _0);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _1);
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_12, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_STRING(&_3, "(<span style=':style'>:var</span>)", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_4, &_3, _0);
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

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
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
	array_init_size(_0, 3);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "pre", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "output", NULL, variable, name);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":output"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "<pre style=':style'>:output</pre>", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_4, &_3, _0);
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

	zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *key = NULL, *value = NULL, *output, *_0 = NULL, **_4, *_5 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", &_1);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "ice/dump.zep", 300);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_SV(_6, "var ", key);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "one", &_7, value, _6);
		zephir_check_call_status();
		zephir_concat_self(&output, _5 TSRMLS_CC);
	}
	RETURN_CCTOR(output);

}

