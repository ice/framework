
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
#include "kernel/string.h"
#include "kernel/file.h"


/**
 * Dumps information about a variable(s)
 *
 * @package     Ice/Dump
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
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

	zend_declare_property_null(ice_dump_ce, SL("skip"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dump_ce, SL("methods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_dump_ce, SL("styles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_dump_ce->create_object = zephir_init_properties_Ice_Dump;
	return SUCCESS;

}

PHP_METHOD(Ice_Dump, getDetailed) {

	

	RETURN_MEMBER(getThis(), "detailed");

}

PHP_METHOD(Ice_Dump, setDetailed) {

	zval *detailed;

	zephir_fetch_params(0, 1, 0, &detailed);



	zephir_update_property_this(getThis(), SL("detailed"), detailed TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dump, getPlain) {

	

	RETURN_MEMBER(getThis(), "plain");

}

PHP_METHOD(Ice_Dump, setPlain) {

	zval *plain;

	zephir_fetch_params(0, 1, 0, &plain);



	zephir_update_property_this(getThis(), SL("plain"), plain TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dump, getSkip) {

	

	RETURN_MEMBER(getThis(), "skip");

}

PHP_METHOD(Ice_Dump, setSkip) {

	zval *skip;

	zephir_fetch_params(0, 1, 0, &skip);



	zephir_update_property_this(getThis(), SL("skip"), skip TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Dump constructor
 *
 * @param boolean detailed debug object's private and protected properties
 * @param mixed styles
 */
PHP_METHOD(Ice_Dump, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
		zephir_update_property_this(getThis(), SL("plain"), styles TSRMLS_CC);
	}
	if (detailed) {
		zephir_update_property_this(getThis(), SL("detailed"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("detailed"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;

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

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
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
	zephir_create_array(defaultStyles, 13, 0 TSRMLS_CC);
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
	add_assoc_stringl_ex(defaultStyles, SS("line"), SL("highlight-block"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("lines"), SL(""), 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_array_merge(_0, &(defaultStyles), &(styles) TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("styles"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(getThis(), "styles");

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zend_class_entry *_64$$13;
	zend_bool _20$$5, _21$$5, _22$$5;
	HashTable *_10$$4, *_50$$11, *_67$$13, *_97$$18;
	HashPosition _9$$4, _49$$11, _66$$13, _96$$18;
	zval *_162, *_4$$4, *_16$$5 = NULL, *_32$$8, *_88$$8, *_39$$9, *_55$$12 = NULL, *_76$$14 = NULL, *_106$$21 = NULL, *_116$$22 = NULL, *_127$$23, *_133$$24, *_138$$25, *_143$$26, *_151$$27, *_157$$28;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_13 = NULL, *_26 = NULL, *_36 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, *name = NULL, *tab = NULL, *key = NULL, *value = NULL, *output = NULL, *space = NULL, *type = NULL, *attr = NULL, *_130 = NULL, *_160 = NULL, *_161, *_163 = NULL, *_164, *_0$$4 = NULL, *_1$$4, *_2$$4, *_3$$4, *_5$$4 = NULL, *_6$$4, **_11$$4, _28$$4, *_29$$4 = NULL, *_12$$5 = NULL, *_14$$5 = NULL, *_15$$5, *_17$$5 = NULL, *_18$$5 = NULL, *_19$$5 = NULL, *_23$$7 = NULL, *_24$$7 = NULL, *_25$$7 = NULL, *_27$$7 = NULL, *className$$8 = NULL, *_30$$8 = NULL, *_31$$8, *_33$$8 = NULL, *_34$$8 = NULL, *_35$$8 = NULL, *_42$$8, *_43$$8, *_44$$8, *_83$$8 = NULL, *_84$$8 = NULL, *_85$$8, *_86$$8, *_87$$8, *_89$$8 = NULL, *_90$$8, *_91$$8, *_92$$8, _123$$8, *_124$$8 = NULL, *_37$$9 = NULL, *_38$$9, *_40$$9 = NULL, *_41$$9, *_45$$10 = NULL, *_46$$10, *_47$$10, *_48$$11 = NULL, **_51$$11, *_52$$12 = NULL, *_53$$12 = NULL, *_54$$12, *_56$$12 = NULL, *_57$$12 = NULL, *_58$$12 = NULL, *_59$$12 = NULL, *_60$$12 = NULL, *_61$$12 = NULL, *reflect$$13 = NULL, *_62$$13, *_63$$13 = NULL, *_65$$13 = NULL, **_68$$13, *_69$$14 = NULL, *_71$$14 = NULL, *_73$$14 = NULL, *_74$$14 = NULL, *_75$$14, *_77$$14 = NULL, *_78$$14 = NULL, *_79$$14 = NULL, *_80$$14 = NULL, *_81$$14 = NULL, *_82$$14 = NULL, *_70$$15 = NULL, *_72$$16 = NULL, *_93$$17 = NULL, *_94$$17, *_95$$17, **_98$$18, *_120$$18 = NULL, *_121$$18, *_122$$18, *_99$$19, _100$$21 = zval_used_for_init, *_101$$21 = NULL, *_102$$21 = NULL, *_103$$21, *_104$$21 = NULL, *_105$$21 = NULL, *_107$$21 = NULL, *_108$$21 = NULL, *_109$$21 = NULL, _110$$22 = zval_used_for_init, *_111$$22 = NULL, *_112$$22 = NULL, *_113$$22, *_114$$22 = NULL, *_115$$22 = NULL, *_117$$22 = NULL, *_118$$22 = NULL, *_119$$22 = NULL, *_125$$23 = NULL, *_126$$23, *_128$$23 = NULL, *_129$$23, *_131$$24 = NULL, *_132$$24, *_134$$24 = NULL, *_135$$24, *_136$$25 = NULL, *_137$$25, *_139$$25 = NULL, *_140$$25, *_141$$26 = NULL, *_142$$26, *_144$$26 = NULL, *_145$$26, _146$$26, _147$$26, *_148$$26 = NULL, *_149$$27 = NULL, *_150$$27, *_152$$27 = NULL, *_153$$27, *_154$$27 = NULL, *_155$$28 = NULL, *_156$$28, *_158$$28 = NULL, *_159$$28;

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
			ZEPHIR_INIT_VAR(_2$$4);
			ZEPHIR_GET_CONSTANT(_2$$4, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_0$$4);
			ZEPHIR_CONCAT_SV(_0$$4, "array (:count) (", _2$$4);
		} else {
			ZEPHIR_INIT_VAR(_3$$4);
			ZEPHIR_GET_CONSTANT(_3$$4, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_0$$4);
			ZEPHIR_CONCAT_SV(_0$$4, "<b style =':style'>array</b> (<span style =':style'>:count</span>) (", _3$$4);
		}
		ZEPHIR_INIT_VAR(_4$$4);
		zephir_create_array(_4$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6$$4);
		ZVAL_STRING(_6$$4, "arr", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getstyle", &_7, 0, _6$$4);
		zephir_check_temp_parameter(_6$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_4$$4, SL(":style"), &_5$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_4$$4, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_5$$4, "strtr", &_8, 116, _0$$4, _4$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, _5$$4 TSRMLS_CC);
		zephir_is_iterable(variable, &_10$$4, &_9$$4, 0, 0, "ice/dump.zep", 171);
		for (
		  ; zend_hash_get_current_data_ex(_10$$4, (void**) &_11$$4, &_9$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_10$$4, &_9$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _10$$4, _9$$4);
			ZEPHIR_GET_HVALUE(value, _11$$4);
			ZEPHIR_CALL_FUNCTION(&_12$$5, "str_repeat", &_13, 98, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_14$$5);
			_15$$5 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
			if (zephir_is_true(_15$$5)) {
				ZEPHIR_INIT_NVAR(_14$$5);
				ZVAL_STRING(_14$$5, "[:key] => ", 1);
			} else {
				ZEPHIR_INIT_NVAR(_14$$5);
				ZVAL_STRING(_14$$5, "[<span style=':style'>:key</span>] => ", 1);
			}
			ZEPHIR_INIT_NVAR(_16$$5);
			zephir_create_array(_16$$5, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_18$$5);
			ZVAL_STRING(_18$$5, "arr", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_17$$5, this_ptr, "getstyle", &_7, 0, _18$$5);
			zephir_check_temp_parameter(_18$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_16$$5, SL(":style"), &_17$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_17$$5, "strtr", &_8, 116, _14$$5, _16$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_19$$5);
			ZEPHIR_CONCAT_VV(_19$$5, _12$$5, _17$$5);
			zephir_concat_self(&output, _19$$5 TSRMLS_CC);
			_20$$5 = ZEPHIR_IS_LONG(tab, 1);
			if (_20$$5) {
				_20$$5 = !ZEPHIR_IS_STRING(name, "");
			}
			_21$$5 = _20$$5;
			if (_21$$5) {
				_21$$5 = !(Z_TYPE_P(key) == IS_LONG);
			}
			_22$$5 = _21$$5;
			if (_22$$5) {
				_22$$5 = ZEPHIR_IS_EQUAL(name, key);
			}
			if (_22$$5) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(_24$$7);
				ZVAL_STRING(_24$$7, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_25$$7);
				ZVAL_LONG(_25$$7, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_23$$7, this_ptr, "output", &_26, 117, value, _24$$7, _25$$7);
				zephir_check_temp_parameter(_24$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_24$$7);
				ZEPHIR_GET_CONSTANT(_24$$7, "PHP_EOL");
				ZEPHIR_INIT_LNVAR(_27$$7);
				ZEPHIR_CONCAT_VV(_27$$7, _23$$7, _24$$7);
				zephir_concat_self(&output, _27$$7 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_VAR(_28$$4);
		ZVAL_LONG(&_28$$4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_29$$4, "str_repeat", &_13, 98, space, &_28$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _29$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(className$$8);
		zephir_get_class(className$$8, variable, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_30$$8);
		_31$$8 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_31$$8)) {
			ZEPHIR_INIT_NVAR(_30$$8);
			ZVAL_STRING(_30$$8, "object :class", 1);
		} else {
			ZEPHIR_INIT_NVAR(_30$$8);
			ZVAL_STRING(_30$$8, "<b style=':style'>object</b> :class", 1);
		}
		ZEPHIR_INIT_VAR(_32$$8);
		zephir_create_array(_32$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_34$$8);
		ZVAL_STRING(_34$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_33$$8, this_ptr, "getstyle", &_7, 0, _34$$8);
		zephir_check_temp_parameter(_34$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_32$$8, SL(":style"), &_33$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_32$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_33$$8, "strtr", &_8, 116, _30$$8, _32$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, _33$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_35$$8, "get_parent_class", &_36, 118, variable);
		zephir_check_call_status();
		if (zephir_is_true(_35$$8)) {
			ZEPHIR_INIT_VAR(_37$$9);
			_38$$9 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
			if (zephir_is_true(_38$$9)) {
				ZEPHIR_INIT_NVAR(_37$$9);
				ZVAL_STRING(_37$$9, " extends :parent", 1);
			} else {
				ZEPHIR_INIT_NVAR(_37$$9);
				ZVAL_STRING(_37$$9, " <b style=':style'>extends</b> :parent", 1);
			}
			ZEPHIR_INIT_VAR(_39$$9);
			zephir_create_array(_39$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_41$$9);
			ZVAL_STRING(_41$$9, "obj", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_40$$9, this_ptr, "getstyle", &_7, 0, _41$$9);
			zephir_check_temp_parameter(_41$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_39$$9, SL(":style"), &_40$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_40$$9, "get_parent_class", &_36, 118, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_39$$9, SL(":parent"), &_40$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_40$$9, "strtr", &_8, 116, _37$$9, _39$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, _40$$9 TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(_34$$8);
		ZEPHIR_GET_CONSTANT(_34$$8, "PHP_EOL");
		ZEPHIR_INIT_VAR(_42$$8);
		ZEPHIR_CONCAT_SV(_42$$8, " (", _34$$8);
		zephir_concat_self(&output, _42$$8 TSRMLS_CC);
		_43$$8 = zephir_fetch_nproperty_this(this_ptr, SL("skip"), PH_NOISY_CC);
		_44$$8 = zephir_fetch_nproperty_this(this_ptr, SL("detailed"), PH_NOISY_CC);
		if (zephir_fast_in_array(className$$8, _43$$8 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_45$$10, "str_repeat", &_13, 98, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_46$$10);
			ZEPHIR_GET_CONSTANT(_46$$10, "PHP_EOL");
			ZEPHIR_INIT_VAR(_47$$10);
			ZEPHIR_CONCAT_VSV(_47$$10, _45$$10, "[skipped]", _46$$10);
			zephir_concat_self(&output, _47$$10 TSRMLS_CC);
		} else if (!(zephir_is_true(_44$$8))) {
			ZEPHIR_CALL_FUNCTION(&_48$$11, "get_object_vars", NULL, 119, variable);
			zephir_check_call_status();
			zephir_is_iterable(_48$$11, &_50$$11, &_49$$11, 0, 0, "ice/dump.zep", 194);
			for (
			  ; zend_hash_get_current_data_ex(_50$$11, (void**) &_51$$11, &_49$$11) == SUCCESS
			  ; zend_hash_move_forward_ex(_50$$11, &_49$$11)
			) {
				ZEPHIR_GET_HMKEY(key, _50$$11, _49$$11);
				ZEPHIR_GET_HVALUE(value, _51$$11);
				ZEPHIR_CALL_FUNCTION(&_52$$12, "str_repeat", &_13, 98, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_53$$12);
				_54$$12 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
				if (zephir_is_true(_54$$12)) {
					ZEPHIR_INIT_NVAR(_53$$12);
					ZVAL_STRING(_53$$12, "->:key (:type) = ", 1);
				} else {
					ZEPHIR_INIT_NVAR(_53$$12);
					ZVAL_STRING(_53$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 1);
				}
				ZEPHIR_INIT_NVAR(_55$$12);
				zephir_create_array(_55$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_57$$12);
				ZVAL_STRING(_57$$12, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_56$$12, this_ptr, "getstyle", &_7, 0, _57$$12);
				zephir_check_temp_parameter(_57$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_55$$12, SL(":style"), &_56$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_55$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_55$$12, SS(":type"), SL("public"), 1);
				ZEPHIR_CALL_FUNCTION(&_56$$12, "strtr", &_8, 116, _53$$12, _55$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_58$$12);
				ZEPHIR_CONCAT_VV(_58$$12, _52$$12, _56$$12);
				zephir_concat_self(&output, _58$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_57$$12);
				ZVAL_STRING(_57$$12, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_60$$12);
				ZVAL_LONG(_60$$12, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_59$$12, this_ptr, "output", &_26, 117, value, _57$$12, _60$$12);
				zephir_check_temp_parameter(_57$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_57$$12);
				ZEPHIR_GET_CONSTANT(_57$$12, "PHP_EOL");
				ZEPHIR_INIT_LNVAR(_61$$12);
				ZEPHIR_CONCAT_VV(_61$$12, _59$$12, _57$$12);
				zephir_concat_self(&output, _61$$12 TSRMLS_CC);
			}
		} else {
			ZEPHIR_INIT_VAR(reflect$$13);
			ZVAL_STRING(reflect$$13, "ReflectionClass", 1);
			ZEPHIR_INIT_VAR(_62$$13);
			zephir_fetch_safe_class(_63$$13, reflect$$13);
				_64$$13 = zend_fetch_class(Z_STRVAL_P(_63$$13), Z_STRLEN_P(_63$$13), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(_62$$13, _64$$13);
			if (zephir_has_constructor(_62$$13 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, _62$$13, "__construct", NULL, 0, variable);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_65$$13, _62$$13, "getproperties", NULL, 0);
			zephir_check_call_status();
			zephir_is_iterable(_65$$13, &_67$$13, &_66$$13, 0, 0, "ice/dump.zep", 217);
			for (
			  ; zend_hash_get_current_data_ex(_67$$13, (void**) &_68$$13, &_66$$13) == SUCCESS
			  ; zend_hash_move_forward_ex(_67$$13, &_66$$13)
			) {
				ZEPHIR_GET_HVALUE(attr, _68$$13);
				ZEPHIR_CALL_METHOD(&key, attr, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				ZEPHIR_CALL_METHOD(&_69$$14, attr, "isprotected", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(_69$$14)) {
					ZEPHIR_INIT_NVAR(_70$$15);
					ZVAL_BOOL(_70$$15, 1);
					ZEPHIR_CALL_METHOD(NULL, attr, "setaccessible", NULL, 0, _70$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "protected", 1);
				}
				ZEPHIR_CALL_METHOD(&_71$$14, attr, "isprivate", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(_71$$14)) {
					ZEPHIR_INIT_NVAR(_72$$16);
					ZVAL_BOOL(_72$$16, 1);
					ZEPHIR_CALL_METHOD(NULL, attr, "setaccessible", NULL, 0, _72$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
				}
				ZEPHIR_CALL_METHOD(&value, attr, "getvalue", NULL, 0, variable);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_73$$14, "str_repeat", &_13, 98, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_74$$14);
				_75$$14 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
				if (zephir_is_true(_75$$14)) {
					ZEPHIR_INIT_NVAR(_74$$14);
					ZVAL_STRING(_74$$14, "->:key (:type) = ", 1);
				} else {
					ZEPHIR_INIT_NVAR(_74$$14);
					ZVAL_STRING(_74$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 1);
				}
				ZEPHIR_INIT_NVAR(_76$$14);
				zephir_create_array(_76$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_78$$14);
				ZVAL_STRING(_78$$14, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_77$$14, this_ptr, "getstyle", &_7, 0, _78$$14);
				zephir_check_temp_parameter(_78$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_76$$14, SL(":style"), &_77$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_76$$14, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_76$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_77$$14, "strtr", &_8, 116, _74$$14, _76$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_79$$14);
				ZEPHIR_CONCAT_VV(_79$$14, _73$$14, _77$$14);
				zephir_concat_self(&output, _79$$14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_78$$14);
				ZVAL_STRING(_78$$14, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_81$$14);
				ZVAL_LONG(_81$$14, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_80$$14, this_ptr, "output", &_26, 117, value, _78$$14, _81$$14);
				zephir_check_temp_parameter(_78$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_78$$14);
				ZEPHIR_GET_CONSTANT(_78$$14, "PHP_EOL");
				ZEPHIR_INIT_LNVAR(_82$$14);
				ZEPHIR_CONCAT_VV(_82$$14, _80$$14, _78$$14);
				zephir_concat_self(&output, _82$$14 TSRMLS_CC);
			}
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 120, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_83$$8, "str_repeat", &_13, 98, space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_84$$8);
		_85$$8 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_85$$8)) {
			ZEPHIR_INIT_VAR(_86$$8);
			ZEPHIR_GET_CONSTANT(_86$$8, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_84$$8);
			ZEPHIR_CONCAT_SV(_84$$8, ":class methods: (:count) (", _86$$8);
		} else {
			ZEPHIR_INIT_VAR(_87$$8);
			ZEPHIR_GET_CONSTANT(_87$$8, "PHP_EOL");
			ZEPHIR_INIT_NVAR(_84$$8);
			ZEPHIR_CONCAT_SV(_84$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (", _87$$8);
		}
		ZEPHIR_INIT_VAR(_88$$8);
		zephir_create_array(_88$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_90$$8);
		ZVAL_STRING(_90$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_89$$8, this_ptr, "getstyle", &_7, 0, _90$$8);
		zephir_check_temp_parameter(_90$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_88$$8, SL(":style"), &_89$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_88$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_88$$8, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_89$$8, "strtr", &_8, 116, _84$$8, _88$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_91$$8);
		ZEPHIR_CONCAT_VV(_91$$8, _83$$8, _89$$8);
		zephir_concat_self(&output, _91$$8 TSRMLS_CC);
		_92$$8 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(className$$8, _92$$8 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_93$$17, "str_repeat", &_13, 98, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_94$$17);
			ZEPHIR_GET_CONSTANT(_94$$17, "PHP_EOL");
			ZEPHIR_INIT_VAR(_95$$17);
			ZEPHIR_CONCAT_VSV(_95$$17, _93$$17, "[already listed]", _94$$17);
			zephir_concat_self(&output, _95$$17 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_97$$18, &_96$$18, 0, 0, "ice/dump.zep", 235);
			for (
			  ; zend_hash_get_current_data_ex(_97$$18, (void**) &_98$$18, &_96$$18) == SUCCESS
			  ; zend_hash_move_forward_ex(_97$$18, &_96$$18)
			) {
				ZEPHIR_GET_HVALUE(value, _98$$18);
				_99$$19 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
				if (!(zephir_fast_in_array(className$$8, _99$$19 TSRMLS_CC))) {
					zephir_update_property_array_append(this_ptr, SL("methods"), className$$8 TSRMLS_CC);
				}
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_100$$21);
					ZVAL_LONG(&_100$$21, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_101$$21, "str_repeat", &_13, 98, space, &_100$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_102$$21);
					_103$$21 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
					if (zephir_is_true(_103$$21)) {
						ZEPHIR_INIT_NVAR(_104$$21);
						ZEPHIR_GET_CONSTANT(_104$$21, "PHP_EOL");
						ZEPHIR_INIT_NVAR(_102$$21);
						ZEPHIR_CONCAT_SV(_102$$21, "->:method(); [constructor]", _104$$21);
					} else {
						ZEPHIR_INIT_NVAR(_105$$21);
						ZEPHIR_GET_CONSTANT(_105$$21, "PHP_EOL");
						ZEPHIR_INIT_NVAR(_102$$21);
						ZEPHIR_CONCAT_SV(_102$$21, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]", _105$$21);
					}
					ZEPHIR_INIT_NVAR(_106$$21);
					zephir_create_array(_106$$21, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_108$$21);
					ZVAL_STRING(_108$$21, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_107$$21, this_ptr, "getstyle", &_7, 0, _108$$21);
					zephir_check_temp_parameter(_108$$21);
					zephir_check_call_status();
					zephir_array_update_string(&_106$$21, SL(":style"), &_107$$21, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_106$$21, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_107$$21, "strtr", &_8, 116, _102$$21, _106$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_109$$21);
					ZEPHIR_CONCAT_VV(_109$$21, _101$$21, _107$$21);
					zephir_concat_self(&output, _109$$21 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_110$$22);
					ZVAL_LONG(&_110$$22, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_111$$22, "str_repeat", &_13, 98, space, &_110$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_112$$22);
					_113$$22 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
					if (zephir_is_true(_113$$22)) {
						ZEPHIR_INIT_NVAR(_114$$22);
						ZEPHIR_GET_CONSTANT(_114$$22, "PHP_EOL");
						ZEPHIR_INIT_NVAR(_112$$22);
						ZEPHIR_CONCAT_SV(_112$$22, "->:method();", _114$$22);
					} else {
						ZEPHIR_INIT_NVAR(_115$$22);
						ZEPHIR_GET_CONSTANT(_115$$22, "PHP_EOL");
						ZEPHIR_INIT_NVAR(_112$$22);
						ZEPHIR_CONCAT_SV(_112$$22, "-><span style=':style'>:method</span>();", _115$$22);
					}
					ZEPHIR_INIT_NVAR(_116$$22);
					zephir_create_array(_116$$22, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_118$$22);
					ZVAL_STRING(_118$$22, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_117$$22, this_ptr, "getstyle", &_7, 0, _118$$22);
					zephir_check_temp_parameter(_118$$22);
					zephir_check_call_status();
					zephir_array_update_string(&_116$$22, SL(":style"), &_117$$22, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_116$$22, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_117$$22, "strtr", &_8, 116, _112$$22, _116$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_119$$22);
					ZEPHIR_CONCAT_VV(_119$$22, _111$$22, _117$$22);
					zephir_concat_self(&output, _119$$22 TSRMLS_CC);
				}
			}
			ZEPHIR_CALL_FUNCTION(&_120$$18, "str_repeat", &_13, 98, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_121$$18);
			ZEPHIR_GET_CONSTANT(_121$$18, "PHP_EOL");
			ZEPHIR_INIT_VAR(_122$$18);
			ZEPHIR_CONCAT_VSV(_122$$18, _120$$18, ")", _121$$18);
			zephir_concat_self(&output, _122$$18 TSRMLS_CC);
		}
		ZEPHIR_SINIT_VAR(_123$$8);
		ZVAL_LONG(&_123$$8, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_124$$8, "str_repeat", &_13, 98, space, &_123$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _124$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(_125$$23);
		_126$$23 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_126$$23)) {
			ZEPHIR_INIT_NVAR(_125$$23);
			ZVAL_STRING(_125$$23, "integer (:var)", 1);
		} else {
			ZEPHIR_INIT_NVAR(_125$$23);
			ZVAL_STRING(_125$$23, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)", 1);
		}
		ZEPHIR_INIT_VAR(_127$$23);
		zephir_create_array(_127$$23, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_129$$23);
		ZVAL_STRING(_129$$23, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_128$$23, this_ptr, "getstyle", &_7, 0, _129$$23);
		zephir_check_temp_parameter(_129$$23);
		zephir_check_call_status();
		zephir_array_update_string(&_127$$23, SL(":style"), &_128$$23, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_127$$23, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_128$$23, "strtr", &_8, 116, _125$$23, _127$$23);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _128$$23);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_130, "is_float", NULL, 121, variable);
	zephir_check_call_status();
	if (zephir_is_true(_130)) {
		ZEPHIR_INIT_VAR(_131$$24);
		_132$$24 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_132$$24)) {
			ZEPHIR_INIT_NVAR(_131$$24);
			ZVAL_STRING(_131$$24, "float (:var)", 1);
		} else {
			ZEPHIR_INIT_NVAR(_131$$24);
			ZVAL_STRING(_131$$24, "<b style=':style'>float</b> (<span style=':style'>:var</span>)", 1);
		}
		ZEPHIR_INIT_VAR(_133$$24);
		zephir_create_array(_133$$24, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_135$$24);
		ZVAL_STRING(_135$$24, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_134$$24, this_ptr, "getstyle", &_7, 0, _135$$24);
		zephir_check_temp_parameter(_135$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_133$$24, SL(":style"), &_134$$24, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_133$$24, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_134$$24, "strtr", &_8, 116, _131$$24, _133$$24);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _134$$24);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(_136$$25);
		_137$$25 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_137$$25)) {
			ZEPHIR_INIT_NVAR(_136$$25);
			ZVAL_STRING(_136$$25, "numeric string (:length) \":var\"", 1);
		} else {
			ZEPHIR_INIT_NVAR(_136$$25);
			ZVAL_STRING(_136$$25, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 1);
		}
		ZEPHIR_INIT_VAR(_138$$25);
		zephir_create_array(_138$$25, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_140$$25);
		ZVAL_STRING(_140$$25, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_139$$25, this_ptr, "getstyle", &_7, 0, _140$$25);
		zephir_check_temp_parameter(_140$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_138$$25, SL(":style"), &_139$$25, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_138$$25, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_138$$25, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_139$$25, "strtr", &_8, 116, _136$$25, _138$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _139$$25);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(_141$$26);
		_142$$26 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_142$$26)) {
			ZEPHIR_INIT_NVAR(_141$$26);
			ZVAL_STRING(_141$$26, "string (:length) \":var\"", 1);
		} else {
			ZEPHIR_INIT_NVAR(_141$$26);
			ZVAL_STRING(_141$$26, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 1);
		}
		ZEPHIR_INIT_VAR(_143$$26);
		zephir_create_array(_143$$26, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_145$$26);
		ZVAL_STRING(_145$$26, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_144$$26, this_ptr, "getstyle", &_7, 0, _145$$26);
		zephir_check_temp_parameter(_145$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_143$$26, SL(":style"), &_144$$26, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_143$$26, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_VAR(_146$$26);
		ZVAL_LONG(&_146$$26, 4);
		ZEPHIR_SINIT_VAR(_147$$26);
		ZVAL_STRING(&_147$$26, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_144$$26, "htmlentities", NULL, 122, variable, &_146$$26, &_147$$26);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_148$$26, "nl2br", NULL, 123, _144$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_143$$26, SL(":var"), &_148$$26, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_148$$26, "strtr", &_8, 116, _141$$26, _143$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _148$$26);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_VAR(_149$$27);
		_150$$27 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_150$$27)) {
			ZEPHIR_INIT_NVAR(_149$$27);
			ZVAL_STRING(_149$$27, "boolean (:var)", 1);
		} else {
			ZEPHIR_INIT_NVAR(_149$$27);
			ZVAL_STRING(_149$$27, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)", 1);
		}
		ZEPHIR_INIT_VAR(_151$$27);
		zephir_create_array(_151$$27, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_153$$27);
		ZVAL_STRING(_153$$27, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_152$$27, this_ptr, "getstyle", &_7, 0, _153$$27);
		zephir_check_temp_parameter(_153$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_151$$27, SL(":style"), &_152$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_154$$27);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_154$$27);
			ZVAL_STRING(_154$$27, "true", 1);
		} else {
			ZEPHIR_INIT_NVAR(_154$$27);
			ZVAL_STRING(_154$$27, "false", 1);
		}
		zephir_array_update_string(&_151$$27, SL(":var"), &_154$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_152$$27, "strtr", &_8, 116, _149$$27, _151$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _152$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(_155$$28);
		_156$$28 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
		if (zephir_is_true(_156$$28)) {
			ZEPHIR_INIT_NVAR(_155$$28);
			ZVAL_STRING(_155$$28, "null", 1);
		} else {
			ZEPHIR_INIT_NVAR(_155$$28);
			ZVAL_STRING(_155$$28, "<b style=':style'>null</b>", 1);
		}
		ZEPHIR_INIT_VAR(_157$$28);
		zephir_create_array(_157$$28, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_159$$28);
		ZVAL_STRING(_159$$28, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_158$$28, this_ptr, "getstyle", &_7, 0, _159$$28);
		zephir_check_temp_parameter(_159$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_157$$28, SL(":style"), &_158$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_158$$28, "strtr", &_8, 116, _155$$28, _157$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _158$$28);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_160);
	_161 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
	if (zephir_is_true(_161)) {
		ZEPHIR_INIT_NVAR(_160);
		ZVAL_STRING(_160, "(:var)", 1);
	} else {
		ZEPHIR_INIT_NVAR(_160);
		ZVAL_STRING(_160, "(<span style=':style'>:var</span>)", 1);
	}
	ZEPHIR_INIT_VAR(_162);
	zephir_create_array(_162, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_164);
	ZVAL_STRING(_164, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_163, this_ptr, "getstyle", &_7, 0, _164);
	zephir_check_temp_parameter(_164);
	zephir_check_call_status();
	zephir_array_update_string(&_162, SL(":style"), &_163, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_162, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_163, "strtr", &_8, 116, _160, _162);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, output, _163);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 116, _0, _2);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_get_args(_0 TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/dump.zep", 308);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
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

/**
 * Returns an HTML string, highlighting a specific line of a file, with some number of lines padded above and below.
 *
 * @param string file File to open
 * @param integer line Line number to highlight
 * @param integer padding Number of padding lines
 * @return array Source of file, false if file is unreadable
 */
PHP_METHOD(Ice_Dump, source) {

	zval *_14$$8 = NULL, *_24$$9 = NULL;
	zend_bool _0;
	zephir_fcall_cache_entry *_5 = NULL, *_11 = NULL, *_17 = NULL, *_18 = NULL, *_21 = NULL;
	zend_long line, padding, ZEPHIR_LAST_CALL_STATUS, i;
	zval *filename_param = NULL, *line_param = NULL, *padding_param = NULL, *file = NULL, *range = NULL, *format = NULL, *lines = NULL, *row = NULL, *_1 = NULL, _2 = zval_used_for_init, *_3, *_6$$4, *_7$$4, _8$$7 = zval_used_for_init, _9$$7 = zval_used_for_init, *_10$$7 = NULL, *_12$$8 = NULL, *_13$$8, *_15$$8 = NULL, *_16$$8 = NULL, _19$$8 = zval_used_for_init, *_20$$8 = NULL, *_22$$9 = NULL, *_23$$9, *_25$$9 = NULL, *_26$$9 = NULL, _27$$9 = zval_used_for_init, *_28$$9 = NULL;
	zval *filename = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &filename_param, &line_param, &padding_param);

	zephir_get_strval(filename, filename_param);
	line = zephir_get_intval(line_param);
	if (!padding_param) {
		padding = 5;
	} else {
		padding = zephir_get_intval(padding_param);
	}


	i = 0;
	_0 = ZEPHIR_IS_EMPTY(filename);
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_readable", NULL, 124, filename);
		zephir_check_call_status();
		_0 = !zephir_is_true(_1);
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "r", 0);
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 125, filename, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(range);
	zephir_create_array(range, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(range, SS("start"), (line - padding));
	add_assoc_long_ex(range, SS("end"), (line + padding));
	zephir_array_fetch_string(&_3, range, SL("end"), PH_NOISY | PH_READONLY, "ice/dump.zep", 339 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, zephir_fast_strlen_ev(_3));
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVS(_4, "% ", &_2, "d");
	ZEPHIR_CPY_WRT(format, _4);
	ZEPHIR_INIT_VAR(lines);
	array_init(lines);
	ZEPHIR_CALL_FUNCTION(&row, "fgets", &_5, 126, file);
	zephir_check_call_status();
	while (1) {
		if (!(!(zephir_feof(file TSRMLS_CC)))) {
			break;
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(row)) {
			break;
		}
		i++;
		zephir_array_fetch_string(&_6$$4, range, SL("end"), PH_NOISY | PH_READONLY, "ice/dump.zep", 351 TSRMLS_CC);
		if (ZEPHIR_LT_LONG(_6$$4, i)) {
			break;
		}
		zephir_array_fetch_string(&_7$$4, range, SL("start"), PH_NOISY | PH_READONLY, "ice/dump.zep", 355 TSRMLS_CC);
		if (ZEPHIR_LE_LONG(_7$$4, i)) {
			ZEPHIR_SINIT_NVAR(_8$$7);
			ZVAL_LONG(&_8$$7, 0);
			ZEPHIR_SINIT_NVAR(_9$$7);
			ZVAL_STRING(&_9$$7, "utf-8", 0);
			ZEPHIR_CALL_FUNCTION(&_10$$7, "htmlspecialchars", &_11, 127, row, &_8$$7, &_9$$7);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(row, _10$$7);
			if (i == line) {
				ZEPHIR_INIT_LNVAR(_12$$8);
				_13$$8 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
				if (zephir_is_true(_13$$8)) {
					ZEPHIR_INIT_NVAR(_12$$8);
					ZVAL_STRING(_12$$8, ":var", 1);
				} else {
					ZEPHIR_INIT_NVAR(_12$$8);
					ZVAL_STRING(_12$$8, "<div class=':class'>:var</div>", 1);
				}
				ZEPHIR_INIT_NVAR(_14$$8);
				zephir_create_array(_14$$8, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_16$$8);
				ZVAL_STRING(_16$$8, "line", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_15$$8, this_ptr, "getstyle", &_17, 0, _16$$8);
				zephir_check_temp_parameter(_16$$8);
				zephir_check_call_status();
				zephir_array_update_string(&_14$$8, SL(":class"), &_15$$8, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_14$$8, SL(":var"), &row, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_15$$8, "strtr", &_18, 116, _12$$8, _14$$8);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_19$$8);
				ZVAL_LONG(&_19$$8, i);
				ZEPHIR_CALL_FUNCTION(&_20$$8, "sprintf", &_21, 12, format, &_19$$8);
				zephir_check_call_status();
				zephir_array_update_zval(&lines, _20$$8, &_15$$8, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_LNVAR(_22$$9);
				_23$$9 = zephir_fetch_nproperty_this(this_ptr, SL("plain"), PH_NOISY_CC);
				if (zephir_is_true(_23$$9)) {
					ZEPHIR_INIT_NVAR(_22$$9);
					ZVAL_STRING(_22$$9, ":var", 1);
				} else {
					ZEPHIR_INIT_NVAR(_22$$9);
					ZVAL_STRING(_22$$9, "<div class=':class'>:var</div>", 1);
				}
				ZEPHIR_INIT_NVAR(_24$$9);
				zephir_create_array(_24$$9, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_26$$9);
				ZVAL_STRING(_26$$9, "lines", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_25$$9, this_ptr, "getstyle", &_17, 0, _26$$9);
				zephir_check_temp_parameter(_26$$9);
				zephir_check_call_status();
				zephir_array_update_string(&_24$$9, SL(":class"), &_25$$9, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$9, SL(":var"), &row, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_25$$9, "strtr", &_18, 116, _22$$9, _24$$9);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_27$$9);
				ZVAL_LONG(&_27$$9, i);
				ZEPHIR_CALL_FUNCTION(&_28$$9, "sprintf", &_21, 12, format, &_27$$9);
				zephir_check_call_status();
				zephir_array_update_zval(&lines, _28$$9, &_25$$9, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_CALL_FUNCTION(&row, "fgets", &_5, 126, file);
		zephir_check_call_status();
	}
	zephir_fclose(file TSRMLS_CC);
	RETURN_CCTOR(lines);

}

zend_object_value zephir_init_properties_Ice_Dump(zend_class_entry *class_type TSRMLS_DC) {

		zval *_5$$5;
	zval *_0, *_2, *_4, *_1$$3, *_3$$4, *_6$$5;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("styles"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("styles"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("methods"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("skip"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			zephir_create_array(_5$$5, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_6$$5);
			ZVAL_STRING(_6$$5, "Ice\\Di", 1);
			zephir_array_fast_append(_5$$5, _6$$5);
			zephir_update_property_this(getThis(), SL("skip"), _5$$5 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

