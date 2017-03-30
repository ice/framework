
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/main.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"


/**
 * Dumps information about a variable(s)
 *
 * @package     Ice/Dump
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
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

	zend_declare_property_bool(ice_dump_ce, SL("plain"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_dump_ce, SL("skipDi"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

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

PHP_METHOD(Ice_Dump, getPlain) {

	

	RETURN_MEMBER(this_ptr, "plain");

}

PHP_METHOD(Ice_Dump, setPlain) {

	zval *plain;

	zephir_fetch_params(0, 1, 0, &plain);



	zephir_update_property_this(this_ptr, SL("plain"), plain TSRMLS_CC);

}

PHP_METHOD(Ice_Dump, getSkipDi) {

	

	RETURN_MEMBER(this_ptr, "skipDi");

}

PHP_METHOD(Ice_Dump, setSkipDi) {

	zval *skipDi;

	zephir_fetch_params(0, 1, 0, &skipDi);



	zephir_update_property_this(this_ptr, SL("skipDi"), skipDi TSRMLS_CC);

}

/**
 * Dump constructor
 *
 * @param boolean detailed debug object's private and protected properties
 * @param mixed styles
 */
PHP_METHOD(Ice_Dump, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *detailed_param = NULL, *styles = NULL;
	zend_bool detailed;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &detailed_param, &styles);

	if (!detailed_param) {
		detailed = 0;
	} else {
		detailed = zephir_get_boolval(detailed_param);
	}
	if (!styles) {
		ZEPHIR_INIT_VAR(styles);
		array_init(styles);
	}


	if (Z_TYPE_P(styles) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, styles);
		zephir_check_call_status();
	} else if (Z_TYPE_P(styles) == IS_BOOL) {
		zephir_update_property_this(this_ptr, SL("plain"), styles TSRMLS_CC);
	}
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

	zval *_1 = NULL;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "vars", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_get_args(_1 TSRMLS_CC);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _0, _1);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 101);
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

	zend_bool _18$$5, _19$$5, _20$$5, _41$$8;
	HashTable *_8$$4, *_47$$11, *_85$$20;
	HashPosition _7$$4, _46$$11, _84$$20;
	zval *_145, *_2$$4, *_14$$5 = NULL, *_30$$8, *_78$$8, *_37$$9, *_52$$12 = NULL, *_68$$14 = NULL, *_92$$23 = NULL, *_100$$24 = NULL, *_110$$25, *_116$$26, *_121$$27, *_126$$28, *_134$$29, *_140$$30;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_11 = NULL, *_24 = NULL, *_34 = NULL, *_59 = NULL, *_63 = NULL, *_70 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *variable, *name = NULL, *tab = NULL, *key = NULL, *value = NULL, *output = NULL, *space = NULL, *type = NULL, *attr = NULL, *_113 = NULL, *_143 = NULL, *_144, *_146 = NULL, *_147, *_0$$4 = NULL, *_1$$4, *_3$$4 = NULL, *_4$$4, **_9$$4, _26$$4, *_27$$4 = NULL, *_10$$5 = NULL, *_12$$5 = NULL, *_13$$5, *_15$$5 = NULL, *_16$$5 = NULL, *_17$$5 = NULL, *_21$$7 = NULL, *_22$$7 = NULL, *_23$$7 = NULL, *_25$$7 = NULL, *className$$8 = NULL, *_28$$8 = NULL, *_29$$8, *_31$$8 = NULL, *_32$$8 = NULL, *_33$$8 = NULL, *_40$$8, *_42$$8, *_75$$8 = NULL, *_76$$8 = NULL, *_77$$8, *_79$$8 = NULL, *_80$$8, *_81$$8, _106$$8, *_107$$8 = NULL, *_35$$9 = NULL, *_36$$9, *_38$$9 = NULL, *_39$$9, *_43$$10 = NULL, *_44$$10, *_45$$11 = NULL, **_48$$11, *_49$$12 = NULL, *_50$$12 = NULL, *_51$$12, *_53$$12 = NULL, *_54$$12 = NULL, *_55$$12 = NULL, *_56$$12 = NULL, *_57$$12 = NULL, *_58$$12 = NULL, *_60$$14 = NULL, _61$$14 = zval_used_for_init, *_62$$14 = NULL, *_65$$14 = NULL, *_66$$14 = NULL, *_67$$14, *_69$$14 = NULL, *_71$$14 = NULL, *_72$$14 = NULL, *_73$$14 = NULL, *_74$$14 = NULL, *_64$$17, *_82$$19 = NULL, *_83$$19, **_86$$20, *_104$$20 = NULL, *_105$$20, *_87$$21, _88$$23 = zval_used_for_init, *_89$$23 = NULL, *_90$$23 = NULL, *_91$$23, *_93$$23 = NULL, *_94$$23 = NULL, *_95$$23 = NULL, _96$$24 = zval_used_for_init, *_97$$24 = NULL, *_98$$24 = NULL, *_99$$24, *_101$$24 = NULL, *_102$$24 = NULL, *_103$$24 = NULL, *_108$$25 = NULL, *_109$$25, *_111$$25 = NULL, *_112$$25, *_114$$26 = NULL, *_115$$26, *_117$$26 = NULL, *_118$$26, *_119$$27 = NULL, *_120$$27, *_122$$27 = NULL, *_123$$27, *_124$$28 = NULL, *_125$$28, *_127$$28 = NULL, *_128$$28, _129$$28, _130$$28, *_131$$28 = NULL, *_132$$29 = NULL, *_133$$29, *_135$$29 = NULL, *_136$$29, *_137$$29 = NULL, *_138$$30 = NULL, *_139$$30, *_141$$30 = NULL, *_142$$30;

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
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_1$$4)) {
			ZEPHIR_INIT_NVAR(_0$$4);
			ZVAL_STRING(_0$$4, "array (:count) (\n", 1);
		} else {
			ZEPHIR_INIT_NVAR(_0$$4);
			ZVAL_STRING(_0$$4, "<b style =':style'>array</b> (<span style =':style'>:count</span>) (\n", 1);
		}
		ZEPHIR_INIT_VAR(_2$$4);
		zephir_create_array(_2$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_STRING(_4$$4, "arr", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getstyle", &_5, 0, _4$$4);
		zephir_check_temp_parameter(_4$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_2$$4, SL(":style"), &_3$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_2$$4, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_3$$4, "strtr", &_6, 87, _0$$4, _2$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, _3$$4 TSRMLS_CC);
		zephir_is_iterable(variable, &_8$$4, &_7$$4, 0, 0, "ice/dump.zep", 169);
		for (
		  ; zephir_hash_get_current_data_ex(_8$$4, (void**) &_9$$4, &_7$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8$$4, &_7$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _8$$4, _7$$4);
			ZEPHIR_GET_HVALUE(value, _9$$4);
			ZEPHIR_CALL_FUNCTION(&_10$$5, "str_repeat", &_11, 67, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_12$$5);
			_13$$5 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
			if (zephir_is_true(_13$$5)) {
				ZEPHIR_INIT_NVAR(_12$$5);
				ZVAL_STRING(_12$$5, "[:key] => ", 1);
			} else {
				ZEPHIR_INIT_NVAR(_12$$5);
				ZVAL_STRING(_12$$5, "[<span style=':style'>:key</span>] => ", 1);
			}
			ZEPHIR_INIT_NVAR(_14$$5);
			zephir_create_array(_14$$5, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_16$$5);
			ZVAL_STRING(_16$$5, "arr", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_15$$5, this_ptr, "getstyle", &_5, 0, _16$$5);
			zephir_check_temp_parameter(_16$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_14$$5, SL(":style"), &_15$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_15$$5, "strtr", &_6, 87, _12$$5, _14$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_17$$5);
			ZEPHIR_CONCAT_VV(_17$$5, _10$$5, _15$$5);
			zephir_concat_self(&output, _17$$5 TSRMLS_CC);
			_18$$5 = ZEPHIR_IS_LONG(tab, 1);
			if (_18$$5) {
				_18$$5 = !ZEPHIR_IS_STRING(name, "");
			}
			_19$$5 = _18$$5;
			if (_19$$5) {
				_19$$5 = !(Z_TYPE_P(key) == IS_LONG);
			}
			_20$$5 = _19$$5;
			if (_20$$5) {
				_20$$5 = ZEPHIR_IS_EQUAL(name, key);
			}
			if (_20$$5) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(_22$$7);
				ZVAL_STRING(_22$$7, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_23$$7);
				ZVAL_LONG(_23$$7, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_21$$7, this_ptr, "output", &_24, 88, value, _22$$7, _23$$7);
				zephir_check_temp_parameter(_22$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_25$$7);
				ZEPHIR_CONCAT_VS(_25$$7, _21$$7, "\n");
				zephir_concat_self(&output, _25$$7 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_VAR(_26$$4);
		ZVAL_LONG(&_26$$4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_27$$4, "str_repeat", &_11, 67, space, &_26$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _27$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(className$$8);
		zephir_get_class(className$$8, variable, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_28$$8);
		_29$$8 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_29$$8)) {
			ZEPHIR_INIT_NVAR(_28$$8);
			ZVAL_STRING(_28$$8, "object :class", 1);
		} else {
			ZEPHIR_INIT_NVAR(_28$$8);
			ZVAL_STRING(_28$$8, "<b style=':style'>object</b> :class", 1);
		}
		ZEPHIR_INIT_VAR(_30$$8);
		zephir_create_array(_30$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_32$$8);
		ZVAL_STRING(_32$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_31$$8, this_ptr, "getstyle", &_5, 0, _32$$8);
		zephir_check_temp_parameter(_32$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_30$$8, SL(":style"), &_31$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_30$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_31$$8, "strtr", &_6, 87, _28$$8, _30$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, _31$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_33$$8, "get_parent_class", &_34, 89, variable);
		zephir_check_call_status();
		if (zephir_is_true(_33$$8)) {
			ZEPHIR_INIT_VAR(_35$$9);
			_36$$9 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
			if (zephir_is_true(_36$$9)) {
				ZEPHIR_INIT_NVAR(_35$$9);
				ZVAL_STRING(_35$$9, " extends :parent", 1);
			} else {
				ZEPHIR_INIT_NVAR(_35$$9);
				ZVAL_STRING(_35$$9, " <b style=':style'>extends</b> :parent", 1);
			}
			ZEPHIR_INIT_VAR(_37$$9);
			zephir_create_array(_37$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_39$$9);
			ZVAL_STRING(_39$$9, "obj", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_38$$9, this_ptr, "getstyle", &_5, 0, _39$$9);
			zephir_check_temp_parameter(_39$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_37$$9, SL(":style"), &_38$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_38$$9, "get_parent_class", &_34, 89, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_37$$9, SL(":parent"), &_38$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_38$$9, "strtr", &_6, 87, _35$$9, _37$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, _38$$9 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		_40$$8 = zephir_fetch_nproperty_this(this_ptr, SL("skipDi"), PH_NOISY_CC);
		_41$$8 = zephir_is_true(_40$$8);
		if (_41$$8) {
			_41$$8 = zephir_instance_of_ev(variable, ice_di_ce TSRMLS_CC);
		}
		_42$$8 = zephir_fetch_nproperty_this(this_ptr, SL("detailed"), PH_NOISY_CC);
		if (_41$$8) {
			ZEPHIR_CALL_FUNCTION(&_43$$10, "str_repeat", &_11, 67, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_44$$10);
			ZEPHIR_CONCAT_VS(_44$$10, _43$$10, "[skipped]\n");
			zephir_concat_self(&output, _44$$10 TSRMLS_CC);
		} else if (!(zephir_is_true(_42$$8))) {
			ZEPHIR_CALL_FUNCTION(&_45$$11, "get_object_vars", NULL, 90, variable);
			zephir_check_call_status();
			zephir_is_iterable(_45$$11, &_47$$11, &_46$$11, 0, 0, "ice/dump.zep", 192);
			for (
			  ; zephir_hash_get_current_data_ex(_47$$11, (void**) &_48$$11, &_46$$11) == SUCCESS
			  ; zephir_hash_move_forward_ex(_47$$11, &_46$$11)
			) {
				ZEPHIR_GET_HMKEY(key, _47$$11, _46$$11);
				ZEPHIR_GET_HVALUE(value, _48$$11);
				ZEPHIR_CALL_FUNCTION(&_49$$12, "str_repeat", &_11, 67, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_50$$12);
				_51$$12 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
				if (zephir_is_true(_51$$12)) {
					ZEPHIR_INIT_NVAR(_50$$12);
					ZVAL_STRING(_50$$12, "->:key (:type) = ", 1);
				} else {
					ZEPHIR_INIT_NVAR(_50$$12);
					ZVAL_STRING(_50$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 1);
				}
				ZEPHIR_INIT_NVAR(_52$$12);
				zephir_create_array(_52$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_54$$12);
				ZVAL_STRING(_54$$12, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_53$$12, this_ptr, "getstyle", &_5, 0, _54$$12);
				zephir_check_temp_parameter(_54$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_52$$12, SL(":style"), &_53$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_52$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_52$$12, SS(":type"), SL("public"), 1);
				ZEPHIR_CALL_FUNCTION(&_53$$12, "strtr", &_6, 87, _50$$12, _52$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_55$$12);
				ZEPHIR_CONCAT_VV(_55$$12, _49$$12, _53$$12);
				zephir_concat_self(&output, _55$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_54$$12);
				ZVAL_STRING(_54$$12, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_57$$12);
				ZVAL_LONG(_57$$12, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_56$$12, this_ptr, "output", &_24, 88, value, _54$$12, _57$$12);
				zephir_check_temp_parameter(_54$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_58$$12);
				ZEPHIR_CONCAT_VS(_58$$12, _56$$12, "\n");
				zephir_concat_self(&output, _58$$12 TSRMLS_CC);
			}
		} else {
			do {
				ZEPHIR_MAKE_REF(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_59, 91, variable);
				ZEPHIR_UNREF(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(key);
				zephir_array_fetch_string(&key, attr, SL("key"), PH_NOISY, "ice/dump.zep", 200 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, attr, SL("value"), PH_NOISY, "ice/dump.zep", 201 TSRMLS_CC);
				if (!(zephir_is_true(key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(_60$$14);
				ZEPHIR_SINIT_NVAR(_61$$14);
				ZVAL_LONG(&_61$$14, 0);
				ZEPHIR_CALL_FUNCTION(&_62$$14, "chr", &_63, 66, &_61$$14);
				zephir_check_call_status();
				zephir_fast_explode(_60$$14, _62$$14, key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(key, _60$$14);
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				if (zephir_array_isset_long(key, 1)) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
					zephir_array_fetch_long(&_64$$17, key, 1, PH_NOISY | PH_READONLY, "ice/dump.zep", 214 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_64$$17, "*")) {
						ZEPHIR_INIT_NVAR(type);
						ZVAL_STRING(type, "protected", 1);
					}
				}
				ZEPHIR_CALL_FUNCTION(&_65$$14, "str_repeat", &_11, 67, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_66$$14);
				_67$$14 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
				if (zephir_is_true(_67$$14)) {
					ZEPHIR_INIT_NVAR(_66$$14);
					ZVAL_STRING(_66$$14, "->:key (:type) = ", 1);
				} else {
					ZEPHIR_INIT_NVAR(_66$$14);
					ZVAL_STRING(_66$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 1);
				}
				ZEPHIR_INIT_NVAR(_68$$14);
				zephir_create_array(_68$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_60$$14);
				ZVAL_STRING(_60$$14, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_69$$14, this_ptr, "getstyle", &_5, 0, _60$$14);
				zephir_check_temp_parameter(_60$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_68$$14, SL(":style"), &_69$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_MAKE_REF(key);
				ZEPHIR_CALL_FUNCTION(&_69$$14, "end", &_70, 92, key);
				ZEPHIR_UNREF(key);
				zephir_check_call_status();
				zephir_array_update_string(&_68$$14, SL(":key"), &_69$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_68$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_69$$14, "strtr", &_6, 87, _66$$14, _68$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_71$$14);
				ZEPHIR_CONCAT_VV(_71$$14, _65$$14, _69$$14);
				zephir_concat_self(&output, _71$$14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_60$$14);
				ZVAL_STRING(_60$$14, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_73$$14);
				ZVAL_LONG(_73$$14, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_72$$14, this_ptr, "output", &_24, 88, value, _60$$14, _73$$14);
				zephir_check_temp_parameter(_60$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_74$$14);
				ZEPHIR_CONCAT_VS(_74$$14, _72$$14, "\n");
				zephir_concat_self(&output, _74$$14 TSRMLS_CC);
			} while (zephir_is_true(attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 93, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_75$$8, "str_repeat", &_11, 67, space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_76$$8);
		_77$$8 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_77$$8)) {
			ZEPHIR_INIT_NVAR(_76$$8);
			ZVAL_STRING(_76$$8, ":class methods: (:count) (\n", 1);
		} else {
			ZEPHIR_INIT_NVAR(_76$$8);
			ZVAL_STRING(_76$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 1);
		}
		ZEPHIR_INIT_VAR(_78$$8);
		zephir_create_array(_78$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_32$$8);
		ZVAL_STRING(_32$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_79$$8, this_ptr, "getstyle", &_5, 0, _32$$8);
		zephir_check_temp_parameter(_32$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_78$$8, SL(":style"), &_79$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_78$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_78$$8, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_79$$8, "strtr", &_6, 87, _76$$8, _78$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_80$$8);
		ZEPHIR_CONCAT_VV(_80$$8, _75$$8, _79$$8);
		zephir_concat_self(&output, _80$$8 TSRMLS_CC);
		_81$$8 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(className$$8, _81$$8 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_82$$19, "str_repeat", &_11, 67, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_83$$19);
			ZEPHIR_CONCAT_VS(_83$$19, _82$$19, "[already listed]\n");
			zephir_concat_self(&output, _83$$19 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_85$$20, &_84$$20, 0, 0, "ice/dump.zep", 239);
			for (
			  ; zephir_hash_get_current_data_ex(_85$$20, (void**) &_86$$20, &_84$$20) == SUCCESS
			  ; zephir_hash_move_forward_ex(_85$$20, &_84$$20)
			) {
				ZEPHIR_GET_HVALUE(value, _86$$20);
				_87$$21 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
				if (!(zephir_fast_in_array(className$$8, _87$$21 TSRMLS_CC))) {
					zephir_update_property_array_append(this_ptr, SL("methods"), className$$8 TSRMLS_CC);
				}
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_88$$23);
					ZVAL_LONG(&_88$$23, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_89$$23, "str_repeat", &_11, 67, space, &_88$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_90$$23);
					_91$$23 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
					if (zephir_is_true(_91$$23)) {
						ZEPHIR_INIT_NVAR(_90$$23);
						ZVAL_STRING(_90$$23, "->:method(); [constructor]\n", 1);
					} else {
						ZEPHIR_INIT_NVAR(_90$$23);
						ZVAL_STRING(_90$$23, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 1);
					}
					ZEPHIR_INIT_NVAR(_92$$23);
					zephir_create_array(_92$$23, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_94$$23);
					ZVAL_STRING(_94$$23, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_93$$23, this_ptr, "getstyle", &_5, 0, _94$$23);
					zephir_check_temp_parameter(_94$$23);
					zephir_check_call_status();
					zephir_array_update_string(&_92$$23, SL(":style"), &_93$$23, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_92$$23, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_93$$23, "strtr", &_6, 87, _90$$23, _92$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_95$$23);
					ZEPHIR_CONCAT_VV(_95$$23, _89$$23, _93$$23);
					zephir_concat_self(&output, _95$$23 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_96$$24);
					ZVAL_LONG(&_96$$24, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_97$$24, "str_repeat", &_11, 67, space, &_96$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_98$$24);
					_99$$24 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
					if (zephir_is_true(_99$$24)) {
						ZEPHIR_INIT_NVAR(_98$$24);
						ZVAL_STRING(_98$$24, "->:method();\n", 1);
					} else {
						ZEPHIR_INIT_NVAR(_98$$24);
						ZVAL_STRING(_98$$24, "-><span style=':style'>:method</span>();\n", 1);
					}
					ZEPHIR_INIT_NVAR(_100$$24);
					zephir_create_array(_100$$24, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_102$$24);
					ZVAL_STRING(_102$$24, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_101$$24, this_ptr, "getstyle", &_5, 0, _102$$24);
					zephir_check_temp_parameter(_102$$24);
					zephir_check_call_status();
					zephir_array_update_string(&_100$$24, SL(":style"), &_101$$24, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_100$$24, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_101$$24, "strtr", &_6, 87, _98$$24, _100$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_103$$24);
					ZEPHIR_CONCAT_VV(_103$$24, _97$$24, _101$$24);
					zephir_concat_self(&output, _103$$24 TSRMLS_CC);
				}
			}
			ZEPHIR_CALL_FUNCTION(&_104$$20, "str_repeat", &_11, 67, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_105$$20);
			ZEPHIR_CONCAT_VS(_105$$20, _104$$20, ")\n");
			zephir_concat_self(&output, _105$$20 TSRMLS_CC);
		}
		ZEPHIR_SINIT_VAR(_106$$8);
		ZVAL_LONG(&_106$$8, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_107$$8, "str_repeat", &_11, 67, space, &_106$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _107$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(_108$$25);
		_109$$25 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_109$$25)) {
			ZEPHIR_INIT_NVAR(_108$$25);
			ZVAL_STRING(_108$$25, "integer (:var)", 1);
		} else {
			ZEPHIR_INIT_NVAR(_108$$25);
			ZVAL_STRING(_108$$25, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)", 1);
		}
		ZEPHIR_INIT_VAR(_110$$25);
		zephir_create_array(_110$$25, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_112$$25);
		ZVAL_STRING(_112$$25, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_111$$25, this_ptr, "getstyle", &_5, 0, _112$$25);
		zephir_check_temp_parameter(_112$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_110$$25, SL(":style"), &_111$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_110$$25, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_111$$25, "strtr", &_6, 87, _108$$25, _110$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _111$$25);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_113, "is_float", NULL, 94, variable);
	zephir_check_call_status();
	if (zephir_is_true(_113)) {
		ZEPHIR_INIT_VAR(_114$$26);
		_115$$26 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_115$$26)) {
			ZEPHIR_INIT_NVAR(_114$$26);
			ZVAL_STRING(_114$$26, "float (:var)", 1);
		} else {
			ZEPHIR_INIT_NVAR(_114$$26);
			ZVAL_STRING(_114$$26, "<b style=':style'>float</b> (<span style=':style'>:var</span>)", 1);
		}
		ZEPHIR_INIT_VAR(_116$$26);
		zephir_create_array(_116$$26, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_118$$26);
		ZVAL_STRING(_118$$26, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_117$$26, this_ptr, "getstyle", &_5, 0, _118$$26);
		zephir_check_temp_parameter(_118$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_116$$26, SL(":style"), &_117$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_116$$26, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_117$$26, "strtr", &_6, 87, _114$$26, _116$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _117$$26);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(_119$$27);
		_120$$27 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_120$$27)) {
			ZEPHIR_INIT_NVAR(_119$$27);
			ZVAL_STRING(_119$$27, "numeric string (:length) \":var\"", 1);
		} else {
			ZEPHIR_INIT_NVAR(_119$$27);
			ZVAL_STRING(_119$$27, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 1);
		}
		ZEPHIR_INIT_VAR(_121$$27);
		zephir_create_array(_121$$27, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_123$$27);
		ZVAL_STRING(_123$$27, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_122$$27, this_ptr, "getstyle", &_5, 0, _123$$27);
		zephir_check_temp_parameter(_123$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_121$$27, SL(":style"), &_122$$27, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_121$$27, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_121$$27, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_122$$27, "strtr", &_6, 87, _119$$27, _121$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _122$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(_124$$28);
		_125$$28 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_125$$28)) {
			ZEPHIR_INIT_NVAR(_124$$28);
			ZVAL_STRING(_124$$28, "string (:length) \":var\"", 1);
		} else {
			ZEPHIR_INIT_NVAR(_124$$28);
			ZVAL_STRING(_124$$28, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 1);
		}
		ZEPHIR_INIT_VAR(_126$$28);
		zephir_create_array(_126$$28, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_128$$28);
		ZVAL_STRING(_128$$28, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_127$$28, this_ptr, "getstyle", &_5, 0, _128$$28);
		zephir_check_temp_parameter(_128$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_126$$28, SL(":style"), &_127$$28, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_126$$28, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_VAR(_129$$28);
		ZVAL_LONG(&_129$$28, 4);
		ZEPHIR_SINIT_VAR(_130$$28);
		ZVAL_STRING(&_130$$28, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_127$$28, "htmlentities", NULL, 95, variable, &_129$$28, &_130$$28);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_131$$28, "nl2br", NULL, 96, _127$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_126$$28, SL(":var"), &_131$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_131$$28, "strtr", &_6, 87, _124$$28, _126$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _131$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_VAR(_132$$29);
		_133$$29 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_133$$29)) {
			ZEPHIR_INIT_NVAR(_132$$29);
			ZVAL_STRING(_132$$29, "boolean (:var)", 1);
		} else {
			ZEPHIR_INIT_NVAR(_132$$29);
			ZVAL_STRING(_132$$29, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)", 1);
		}
		ZEPHIR_INIT_VAR(_134$$29);
		zephir_create_array(_134$$29, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_136$$29);
		ZVAL_STRING(_136$$29, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_135$$29, this_ptr, "getstyle", &_5, 0, _136$$29);
		zephir_check_temp_parameter(_136$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_134$$29, SL(":style"), &_135$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_137$$29);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_137$$29);
			ZVAL_STRING(_137$$29, "true", 1);
		} else {
			ZEPHIR_INIT_NVAR(_137$$29);
			ZVAL_STRING(_137$$29, "false", 1);
		}
		zephir_array_update_string(&_134$$29, SL(":var"), &_137$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_135$$29, "strtr", &_6, 87, _132$$29, _134$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _135$$29);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(_138$$30);
		_139$$30 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_139$$30)) {
			ZEPHIR_INIT_NVAR(_138$$30);
			ZVAL_STRING(_138$$30, "null", 1);
		} else {
			ZEPHIR_INIT_NVAR(_138$$30);
			ZVAL_STRING(_138$$30, "<b style=':style'>null</b>", 1);
		}
		ZEPHIR_INIT_VAR(_140$$30);
		zephir_create_array(_140$$30, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_142$$30);
		ZVAL_STRING(_142$$30, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_141$$30, this_ptr, "getstyle", &_5, 0, _142$$30);
		zephir_check_temp_parameter(_142$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_140$$30, SL(":style"), &_141$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_141$$30, "strtr", &_6, 87, _138$$30, _140$$30);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _141$$30);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_143);
	_144 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
	if (zephir_is_true(_144)) {
		ZEPHIR_INIT_NVAR(_143);
		ZVAL_STRING(_143, "(:var)", 1);
	} else {
		ZEPHIR_INIT_NVAR(_143);
		ZVAL_STRING(_143, "(<span style=':style'>:var</span>)", 1);
	}
	ZEPHIR_INIT_VAR(_145);
	zephir_create_array(_145, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_147);
	ZVAL_STRING(_147, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_146, this_ptr, "getstyle", &_5, 0, _147);
	zephir_check_temp_parameter(_147);
	zephir_check_call_status();
	zephir_array_update_string(&_145, SL(":style"), &_146, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_145, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_146, "strtr", &_6, 87, _143, _145);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, output, _146);
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

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL;
	zval *variable, *name_param = NULL, *_0 = NULL, *_1, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, ":output", 1);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "<pre style=':style'>:output</pre>", 1);
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "pre", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getstyle", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL(":style"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "output", NULL, 0, variable, name);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL(":output"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 87, _0, _2);
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
	zval *key = NULL, *value = NULL, *output = NULL, *_0, **_3, *_4$$3 = NULL, *_5$$3 = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_get_args(_0 TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/dump.zep", 312);
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

