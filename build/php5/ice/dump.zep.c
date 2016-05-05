
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
	if (detailed) {
		zephir_update_property_this(this_ptr, SL("detailed"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("detailed"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
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

	zval *type_param = NULL, *style = NULL, *_0;
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

	zval *styles_param = NULL, *defaultStyles = NULL, *_0;
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

	zend_bool _16$$5, _17$$5, _18$$5;
	HashTable *_7$$4, *_40$$11, *_73$$20;
	HashPosition _6$$4, _39$$11, _72$$20;
	zval *_119, *_0$$4, *_11$$5 = NULL, *_25$$8, *_66$$8, *_31$$9, *_43$$12 = NULL, *_58$$14 = NULL, *_78$$23 = NULL, *_84$$24 = NULL, *_91$$25, *_96$$26, *_100$$27, *_104$$28, *_110$$29, *_115$$30;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_10 = NULL, *_22 = NULL, *_30 = NULL, *_51 = NULL, *_55 = NULL, *_60 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *variable, *name = NULL, *tab = NULL, *key = NULL, *value = NULL, *output = NULL, *space = NULL, *type = NULL, *attr = NULL, *_95 = NULL, *_120 = NULL, *_121, _122, *_1$$4 = NULL, *_2$$4, _4$$4 = zval_used_for_init, **_8$$4, *_24$$4 = NULL, *_9$$5 = NULL, *_12$$5 = NULL, *_13$$5 = NULL, _14$$5 = zval_used_for_init, *_15$$5 = NULL, *_19$$7 = NULL, *_20$$7 = NULL, *_21$$7 = NULL, *_23$$7 = NULL, *className$$8 = NULL, *_26$$8 = NULL, *_27$$8 = NULL, _28$$8 = zval_used_for_init, *_29$$8 = NULL, *_35$$8, *_65$$8 = NULL, *_67$$8 = NULL, *_68$$8, *_69$$8, *_90$$8 = NULL, *_32$$9 = NULL, *_33$$9, _34$$9, *_36$$10 = NULL, *_37$$10, *_38$$11 = NULL, **_41$$11, *_42$$12 = NULL, *_44$$12 = NULL, *_45$$12 = NULL, _46$$12 = zval_used_for_init, *_47$$12 = NULL, *_48$$12 = NULL, *_49$$12 = NULL, *_50$$12 = NULL, *_52$$14 = NULL, _53$$14 = zval_used_for_init, *_54$$14 = NULL, *_57$$14 = NULL, *_59$$14 = NULL, *_61$$14 = NULL, *_62$$14 = NULL, *_63$$14 = NULL, *_64$$14 = NULL, *_56$$17, *_70$$19 = NULL, *_71$$19, **_74$$20, *_88$$20 = NULL, *_89$$20, *_75$$21, _76$$23 = zval_used_for_init, *_77$$23 = NULL, *_79$$23 = NULL, *_80$$23 = NULL, *_81$$23 = NULL, _82$$24 = zval_used_for_init, *_83$$24 = NULL, *_85$$24 = NULL, *_86$$24 = NULL, *_87$$24 = NULL, *_92$$25 = NULL, *_93$$25, _94$$25, *_97$$26 = NULL, *_98$$26, _99$$26, *_101$$27 = NULL, *_102$$27, _103$$27, *_105$$28 = NULL, *_106$$28, _107$$28 = zval_used_for_init, _108$$28, *_109$$28 = NULL, *_111$$29 = NULL, *_112$$29, *_113$$29 = NULL, _114$$29, *_116$$30 = NULL, *_117$$30, _118$$30;

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
		ZEPHIR_INIT_VAR(_0$$4);
		zephir_create_array(_0$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "arr", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getstyle", &_3, 0, _2$$4);
		zephir_check_temp_parameter(_2$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_0$$4, SL(":style"), &_1$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0$$4, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_SINIT_VAR(_4$$4);
		ZVAL_STRING(&_4$$4, "<b style =':style'>array</b> (<span style =':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_1$$4, "strtr", &_5, 85, &_4$$4, _0$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, _1$$4 TSRMLS_CC);
		zephir_is_iterable(variable, &_7$$4, &_6$$4, 0, 0, "ice/dump.zep", 166);
		for (
		  ; zephir_hash_get_current_data_ex(_7$$4, (void**) &_8$$4, &_6$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7$$4, &_6$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _7$$4, _6$$4);
			ZEPHIR_GET_HVALUE(value, _8$$4);
			ZEPHIR_CALL_FUNCTION(&_9$$5, "str_repeat", &_10, 67, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_11$$5);
			zephir_create_array(_11$$5, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_13$$5);
			ZVAL_STRING(_13$$5, "arr", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getstyle", &_3, 0, _13$$5);
			zephir_check_temp_parameter(_13$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_11$$5, SL(":style"), &_12$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_11$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_14$$5);
			ZVAL_STRING(&_14$$5, "[<span style=':style'>:key</span>] => ", 0);
			ZEPHIR_CALL_FUNCTION(&_12$$5, "strtr", &_5, 85, &_14$$5, _11$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_15$$5);
			ZEPHIR_CONCAT_VV(_15$$5, _9$$5, _12$$5);
			zephir_concat_self(&output, _15$$5 TSRMLS_CC);
			_16$$5 = ZEPHIR_IS_LONG(tab, 1);
			if (_16$$5) {
				_16$$5 = !ZEPHIR_IS_STRING(name, "");
			}
			_17$$5 = _16$$5;
			if (_17$$5) {
				_17$$5 = !(Z_TYPE_P(key) == IS_LONG);
			}
			_18$$5 = _17$$5;
			if (_18$$5) {
				_18$$5 = ZEPHIR_IS_EQUAL(name, key);
			}
			if (_18$$5) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(_20$$7);
				ZVAL_STRING(_20$$7, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_21$$7);
				ZVAL_LONG(_21$$7, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_19$$7, this_ptr, "output", &_22, 86, value, _20$$7, _21$$7);
				zephir_check_temp_parameter(_20$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_23$$7);
				ZEPHIR_CONCAT_VS(_23$$7, _19$$7, "\n");
				zephir_concat_self(&output, _23$$7 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_4$$4);
		ZVAL_LONG(&_4$$4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_24$$4, "str_repeat", &_10, 67, space, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _24$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(className$$8);
		zephir_get_class(className$$8, variable, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_25$$8);
		zephir_create_array(_25$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_27$$8);
		ZVAL_STRING(_27$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_26$$8, this_ptr, "getstyle", &_3, 0, _27$$8);
		zephir_check_temp_parameter(_27$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_25$$8, SL(":style"), &_26$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_25$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_28$$8);
		ZVAL_STRING(&_28$$8, "<b style=':style'>object</b> :class", 0);
		ZEPHIR_CALL_FUNCTION(&_26$$8, "strtr", &_5, 85, &_28$$8, _25$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, _26$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_29$$8, "get_parent_class", &_30, 87, variable);
		zephir_check_call_status();
		if (zephir_is_true(_29$$8)) {
			ZEPHIR_INIT_VAR(_31$$9);
			zephir_create_array(_31$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_33$$9);
			ZVAL_STRING(_33$$9, "obj", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_32$$9, this_ptr, "getstyle", &_3, 0, _33$$9);
			zephir_check_temp_parameter(_33$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$9, SL(":style"), &_32$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_32$$9, "get_parent_class", &_30, 87, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$9, SL(":parent"), &_32$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_VAR(_34$$9);
			ZVAL_STRING(&_34$$9, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_CALL_FUNCTION(&_32$$9, "strtr", &_5, 85, &_34$$9, _31$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, _32$$9 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		_35$$8 = zephir_fetch_nproperty_this(this_ptr, SL("detailed"), PH_NOISY_CC);
		if (zephir_instance_of_ev(variable, ice_di_ce TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_36$$10, "str_repeat", &_10, 67, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_37$$10);
			ZEPHIR_CONCAT_VS(_37$$10, _36$$10, "[skipped]\n");
			zephir_concat_self(&output, _37$$10 TSRMLS_CC);
		} else if (!(zephir_is_true(_35$$8))) {
			ZEPHIR_CALL_FUNCTION(&_38$$11, "get_object_vars", NULL, 88, variable);
			zephir_check_call_status();
			zephir_is_iterable(_38$$11, &_40$$11, &_39$$11, 0, 0, "ice/dump.zep", 189);
			for (
			  ; zephir_hash_get_current_data_ex(_40$$11, (void**) &_41$$11, &_39$$11) == SUCCESS
			  ; zephir_hash_move_forward_ex(_40$$11, &_39$$11)
			) {
				ZEPHIR_GET_HMKEY(key, _40$$11, _39$$11);
				ZEPHIR_GET_HVALUE(value, _41$$11);
				ZEPHIR_CALL_FUNCTION(&_42$$12, "str_repeat", &_10, 67, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_43$$12);
				zephir_create_array(_43$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_45$$12);
				ZVAL_STRING(_45$$12, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_44$$12, this_ptr, "getstyle", &_3, 0, _45$$12);
				zephir_check_temp_parameter(_45$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_43$$12, SL(":style"), &_44$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_43$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_43$$12, SS(":type"), SL("public"), 1);
				ZEPHIR_SINIT_NVAR(_46$$12);
				ZVAL_STRING(&_46$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_44$$12, "strtr", &_5, 85, &_46$$12, _43$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_47$$12);
				ZEPHIR_CONCAT_VV(_47$$12, _42$$12, _44$$12);
				zephir_concat_self(&output, _47$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_45$$12);
				ZVAL_STRING(_45$$12, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_49$$12);
				ZVAL_LONG(_49$$12, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_48$$12, this_ptr, "output", &_22, 86, value, _45$$12, _49$$12);
				zephir_check_temp_parameter(_45$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_50$$12);
				ZEPHIR_CONCAT_VS(_50$$12, _48$$12, "\n");
				zephir_concat_self(&output, _50$$12 TSRMLS_CC);
			}
		} else {
			do {
				ZEPHIR_MAKE_REF(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_51, 89, variable);
				ZEPHIR_UNREF(variable);
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
				ZEPHIR_INIT_NVAR(_52$$14);
				ZEPHIR_SINIT_NVAR(_53$$14);
				ZVAL_LONG(&_53$$14, 0);
				ZEPHIR_CALL_FUNCTION(&_54$$14, "chr", &_55, 66, &_53$$14);
				zephir_check_call_status();
				zephir_fast_explode(_52$$14, _54$$14, key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(key, _52$$14);
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				if (zephir_array_isset_long(key, 1)) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
					zephir_array_fetch_long(&_56$$17, key, 1, PH_NOISY | PH_READONLY, "ice/dump.zep", 211 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_56$$17, "*")) {
						ZEPHIR_INIT_NVAR(type);
						ZVAL_STRING(type, "protected", 1);
					}
				}
				ZEPHIR_CALL_FUNCTION(&_57$$14, "str_repeat", &_10, 67, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_58$$14);
				zephir_create_array(_58$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_52$$14);
				ZVAL_STRING(_52$$14, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_59$$14, this_ptr, "getstyle", &_3, 0, _52$$14);
				zephir_check_temp_parameter(_52$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_58$$14, SL(":style"), &_59$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_MAKE_REF(key);
				ZEPHIR_CALL_FUNCTION(&_59$$14, "end", &_60, 90, key);
				ZEPHIR_UNREF(key);
				zephir_check_call_status();
				zephir_array_update_string(&_58$$14, SL(":key"), &_59$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_58$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_SINIT_NVAR(_53$$14);
				ZVAL_STRING(&_53$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_59$$14, "strtr", &_5, 85, &_53$$14, _58$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_61$$14);
				ZEPHIR_CONCAT_VV(_61$$14, _57$$14, _59$$14);
				zephir_concat_self(&output, _61$$14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_52$$14);
				ZVAL_STRING(_52$$14, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_63$$14);
				ZVAL_LONG(_63$$14, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_62$$14, this_ptr, "output", &_22, 86, value, _52$$14, _63$$14);
				zephir_check_temp_parameter(_52$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_64$$14);
				ZEPHIR_CONCAT_VS(_64$$14, _62$$14, "\n");
				zephir_concat_self(&output, _64$$14 TSRMLS_CC);
			} while (zephir_is_true(attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 91, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_65$$8, "str_repeat", &_10, 67, space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_66$$8);
		zephir_create_array(_66$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_27$$8);
		ZVAL_STRING(_27$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_67$$8, this_ptr, "getstyle", &_3, 0, _27$$8);
		zephir_check_temp_parameter(_27$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_66$$8, SL(":style"), &_67$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_66$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_66$$8, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_28$$8);
		ZVAL_STRING(&_28$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_67$$8, "strtr", &_5, 85, &_28$$8, _66$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_68$$8);
		ZEPHIR_CONCAT_VV(_68$$8, _65$$8, _67$$8);
		zephir_concat_self(&output, _68$$8 TSRMLS_CC);
		_69$$8 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(className$$8, _69$$8 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_70$$19, "str_repeat", &_10, 67, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_71$$19);
			ZEPHIR_CONCAT_VS(_71$$19, _70$$19, "[already listed]\n");
			zephir_concat_self(&output, _71$$19 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_73$$20, &_72$$20, 0, 0, "ice/dump.zep", 236);
			for (
			  ; zephir_hash_get_current_data_ex(_73$$20, (void**) &_74$$20, &_72$$20) == SUCCESS
			  ; zephir_hash_move_forward_ex(_73$$20, &_72$$20)
			) {
				ZEPHIR_GET_HVALUE(value, _74$$20);
				_75$$21 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
				if (!(zephir_fast_in_array(className$$8, _75$$21 TSRMLS_CC))) {
					zephir_update_property_array_append(this_ptr, SL("methods"), className$$8 TSRMLS_CC);
				}
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_76$$23);
					ZVAL_LONG(&_76$$23, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_77$$23, "str_repeat", &_10, 67, space, &_76$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_78$$23);
					zephir_create_array(_78$$23, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_80$$23);
					ZVAL_STRING(_80$$23, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_79$$23, this_ptr, "getstyle", &_3, 0, _80$$23);
					zephir_check_temp_parameter(_80$$23);
					zephir_check_call_status();
					zephir_array_update_string(&_78$$23, SL(":style"), &_79$$23, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_78$$23, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_76$$23);
					ZVAL_STRING(&_76$$23, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_CALL_FUNCTION(&_79$$23, "strtr", &_5, 85, &_76$$23, _78$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_81$$23);
					ZEPHIR_CONCAT_VV(_81$$23, _77$$23, _79$$23);
					zephir_concat_self(&output, _81$$23 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_82$$24);
					ZVAL_LONG(&_82$$24, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_83$$24, "str_repeat", &_10, 67, space, &_82$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_84$$24);
					zephir_create_array(_84$$24, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_86$$24);
					ZVAL_STRING(_86$$24, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_85$$24, this_ptr, "getstyle", &_3, 0, _86$$24);
					zephir_check_temp_parameter(_86$$24);
					zephir_check_call_status();
					zephir_array_update_string(&_84$$24, SL(":style"), &_85$$24, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_84$$24, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_82$$24);
					ZVAL_STRING(&_82$$24, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_CALL_FUNCTION(&_85$$24, "strtr", &_5, 85, &_82$$24, _84$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_87$$24);
					ZEPHIR_CONCAT_VV(_87$$24, _83$$24, _85$$24);
					zephir_concat_self(&output, _87$$24 TSRMLS_CC);
				}
			}
			ZEPHIR_CALL_FUNCTION(&_88$$20, "str_repeat", &_10, 67, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_89$$20);
			ZEPHIR_CONCAT_VS(_89$$20, _88$$20, ")\n");
			zephir_concat_self(&output, _89$$20 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_28$$8);
		ZVAL_LONG(&_28$$8, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_90$$8, "str_repeat", &_10, 67, space, &_28$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _90$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(_91$$25);
		zephir_create_array(_91$$25, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_93$$25);
		ZVAL_STRING(_93$$25, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_92$$25, this_ptr, "getstyle", &_3, 0, _93$$25);
		zephir_check_temp_parameter(_93$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_91$$25, SL(":style"), &_92$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_91$$25, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_94$$25);
		ZVAL_STRING(&_94$$25, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_92$$25, "strtr", &_5, 85, &_94$$25, _91$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _92$$25);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_95, "is_float", NULL, 92, variable);
	zephir_check_call_status();
	if (zephir_is_true(_95)) {
		ZEPHIR_INIT_VAR(_96$$26);
		zephir_create_array(_96$$26, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_98$$26);
		ZVAL_STRING(_98$$26, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_97$$26, this_ptr, "getstyle", &_3, 0, _98$$26);
		zephir_check_temp_parameter(_98$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_96$$26, SL(":style"), &_97$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_96$$26, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_99$$26);
		ZVAL_STRING(&_99$$26, "<b style=':style'>float</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_97$$26, "strtr", &_5, 85, &_99$$26, _96$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _97$$26);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(_100$$27);
		zephir_create_array(_100$$27, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_102$$27);
		ZVAL_STRING(_102$$27, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_101$$27, this_ptr, "getstyle", &_3, 0, _102$$27);
		zephir_check_temp_parameter(_102$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_100$$27, SL(":style"), &_101$$27, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_100$$27, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_100$$27, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_103$$27);
		ZVAL_STRING(&_103$$27, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_101$$27, "strtr", &_5, 85, &_103$$27, _100$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _101$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(_104$$28);
		zephir_create_array(_104$$28, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_106$$28);
		ZVAL_STRING(_106$$28, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_105$$28, this_ptr, "getstyle", &_3, 0, _106$$28);
		zephir_check_temp_parameter(_106$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_104$$28, SL(":style"), &_105$$28, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_104$$28, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_VAR(_107$$28);
		ZVAL_LONG(&_107$$28, 4);
		ZEPHIR_SINIT_VAR(_108$$28);
		ZVAL_STRING(&_108$$28, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_105$$28, "htmlentities", NULL, 93, variable, &_107$$28, &_108$$28);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_109$$28, "nl2br", NULL, 94, _105$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_104$$28, SL(":var"), &_109$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_107$$28);
		ZVAL_STRING(&_107$$28, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_109$$28, "strtr", &_5, 85, &_107$$28, _104$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _109$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_VAR(_110$$29);
		zephir_create_array(_110$$29, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_112$$29);
		ZVAL_STRING(_112$$29, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_111$$29, this_ptr, "getstyle", &_3, 0, _112$$29);
		zephir_check_temp_parameter(_112$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_110$$29, SL(":style"), &_111$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_113$$29);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_113$$29);
			ZVAL_STRING(_113$$29, "true", 1);
		} else {
			ZEPHIR_INIT_NVAR(_113$$29);
			ZVAL_STRING(_113$$29, "false", 1);
		}
		zephir_array_update_string(&_110$$29, SL(":var"), &_113$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_114$$29);
		ZVAL_STRING(&_114$$29, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_111$$29, "strtr", &_5, 85, &_114$$29, _110$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _111$$29);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(_115$$30);
		zephir_create_array(_115$$30, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_117$$30);
		ZVAL_STRING(_117$$30, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_116$$30, this_ptr, "getstyle", &_3, 0, _117$$30);
		zephir_check_temp_parameter(_117$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_115$$30, SL(":style"), &_116$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_118$$30);
		ZVAL_STRING(&_118$$30, "<b style=':style'>null</b>", 0);
		ZEPHIR_CALL_FUNCTION(&_116$$30, "strtr", &_5, 85, &_118$$30, _115$$30);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _116$$30);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_119);
	zephir_create_array(_119, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_121);
	ZVAL_STRING(_121, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_120, this_ptr, "getstyle", &_3, 0, _121);
	zephir_check_temp_parameter(_121);
	zephir_check_call_status();
	zephir_array_update_string(&_119, SL(":style"), &_120, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_119, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_122);
	ZVAL_STRING(&_122, "(<span style=':style'>:var</span>)", 0);
	ZEPHIR_CALL_FUNCTION(&_120, "strtr", &_5, 85, &_122, _119);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, output, _120);
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

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
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

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *output = NULL, *_0 = NULL, **_3, *_4$$3 = NULL, *_5$$3 = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

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
		ZEPHIR_INIT_LNVAR(_5$$3);
		ZEPHIR_CONCAT_SV(_5$$3, "var ", key);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "one", &_6, 0, value, _5$$3);
		zephir_check_call_status();
		zephir_concat_self(&output, _4$$3 TSRMLS_CC);
	}
	RETURN_CCTOR(output);

}

zend_object_value zephir_init_properties_Ice_Dump(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("styles"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("styles"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("methods"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

