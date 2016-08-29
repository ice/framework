
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 47);
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
	ZEPHIR_CALL_FUNCTION(&_2, "func_get_args", NULL, 87);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 99);
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

	zend_bool _16$$5, _17$$5, _18$$5, _36$$8;
	HashTable *_7$$4, *_42$$11, *_75$$20;
	HashPosition _6$$4, _41$$11, _74$$20;
	zval *_121, *_0$$4, *_11$$5 = NULL, *_25$$8, *_68$$8, *_31$$9, *_45$$12 = NULL, *_60$$14 = NULL, *_80$$23 = NULL, *_86$$24 = NULL, *_93$$25, *_98$$26, *_102$$27, *_106$$28, *_112$$29, *_117$$30;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_10 = NULL, *_22 = NULL, *_30 = NULL, *_53 = NULL, *_57 = NULL, *_62 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *variable, *name = NULL, *tab = NULL, *key = NULL, *value = NULL, *output = NULL, *space = NULL, *type = NULL, *attr = NULL, *_97 = NULL, *_122 = NULL, *_123, _124, *_1$$4 = NULL, *_2$$4, _4$$4 = zval_used_for_init, **_8$$4, *_24$$4 = NULL, *_9$$5 = NULL, *_12$$5 = NULL, *_13$$5 = NULL, _14$$5 = zval_used_for_init, *_15$$5 = NULL, *_19$$7 = NULL, *_20$$7 = NULL, *_21$$7 = NULL, *_23$$7 = NULL, *className$$8 = NULL, *_26$$8 = NULL, *_27$$8 = NULL, _28$$8 = zval_used_for_init, *_29$$8 = NULL, *_35$$8, *_37$$8, *_67$$8 = NULL, *_69$$8 = NULL, *_70$$8, *_71$$8, *_92$$8 = NULL, *_32$$9 = NULL, *_33$$9, _34$$9, *_38$$10 = NULL, *_39$$10, *_40$$11 = NULL, **_43$$11, *_44$$12 = NULL, *_46$$12 = NULL, *_47$$12 = NULL, _48$$12 = zval_used_for_init, *_49$$12 = NULL, *_50$$12 = NULL, *_51$$12 = NULL, *_52$$12 = NULL, *_54$$14 = NULL, _55$$14 = zval_used_for_init, *_56$$14 = NULL, *_59$$14 = NULL, *_61$$14 = NULL, *_63$$14 = NULL, *_64$$14 = NULL, *_65$$14 = NULL, *_66$$14 = NULL, *_58$$17, *_72$$19 = NULL, *_73$$19, **_76$$20, *_90$$20 = NULL, *_91$$20, *_77$$21, _78$$23 = zval_used_for_init, *_79$$23 = NULL, *_81$$23 = NULL, *_82$$23 = NULL, *_83$$23 = NULL, _84$$24 = zval_used_for_init, *_85$$24 = NULL, *_87$$24 = NULL, *_88$$24 = NULL, *_89$$24 = NULL, *_94$$25 = NULL, *_95$$25, _96$$25, *_99$$26 = NULL, *_100$$26, _101$$26, *_103$$27 = NULL, *_104$$27, _105$$27, *_107$$28 = NULL, *_108$$28, _109$$28 = zval_used_for_init, _110$$28, *_111$$28 = NULL, *_113$$29 = NULL, *_114$$29, *_115$$29 = NULL, _116$$29, *_118$$30 = NULL, *_119$$30, _120$$30;

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
		ZEPHIR_CALL_FUNCTION(&_1$$4, "strtr", &_5, 88, &_4$$4, _0$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, _1$$4 TSRMLS_CC);
		zephir_is_iterable(variable, &_7$$4, &_6$$4, 0, 0, "ice/dump.zep", 167);
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
			ZEPHIR_CALL_FUNCTION(&_12$$5, "strtr", &_5, 88, &_14$$5, _11$$5);
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
				ZEPHIR_CALL_METHOD(&_19$$7, this_ptr, "output", &_22, 89, value, _20$$7, _21$$7);
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
		ZEPHIR_CALL_FUNCTION(&_26$$8, "strtr", &_5, 88, &_28$$8, _25$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, _26$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_29$$8, "get_parent_class", &_30, 90, variable);
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
			ZEPHIR_CALL_FUNCTION(&_32$$9, "get_parent_class", &_30, 90, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$9, SL(":parent"), &_32$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_VAR(_34$$9);
			ZVAL_STRING(&_34$$9, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_CALL_FUNCTION(&_32$$9, "strtr", &_5, 88, &_34$$9, _31$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, _32$$9 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		_35$$8 = zephir_fetch_nproperty_this(this_ptr, SL("skipDi"), PH_NOISY_CC);
		_36$$8 = zephir_is_true(_35$$8);
		if (_36$$8) {
			_36$$8 = zephir_instance_of_ev(variable, ice_di_ce TSRMLS_CC);
		}
		_37$$8 = zephir_fetch_nproperty_this(this_ptr, SL("detailed"), PH_NOISY_CC);
		if (_36$$8) {
			ZEPHIR_CALL_FUNCTION(&_38$$10, "str_repeat", &_10, 67, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_39$$10);
			ZEPHIR_CONCAT_VS(_39$$10, _38$$10, "[skipped]\n");
			zephir_concat_self(&output, _39$$10 TSRMLS_CC);
		} else if (!(zephir_is_true(_37$$8))) {
			ZEPHIR_CALL_FUNCTION(&_40$$11, "get_object_vars", NULL, 91, variable);
			zephir_check_call_status();
			zephir_is_iterable(_40$$11, &_42$$11, &_41$$11, 0, 0, "ice/dump.zep", 190);
			for (
			  ; zephir_hash_get_current_data_ex(_42$$11, (void**) &_43$$11, &_41$$11) == SUCCESS
			  ; zephir_hash_move_forward_ex(_42$$11, &_41$$11)
			) {
				ZEPHIR_GET_HMKEY(key, _42$$11, _41$$11);
				ZEPHIR_GET_HVALUE(value, _43$$11);
				ZEPHIR_CALL_FUNCTION(&_44$$12, "str_repeat", &_10, 67, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_45$$12);
				zephir_create_array(_45$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_47$$12);
				ZVAL_STRING(_47$$12, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_46$$12, this_ptr, "getstyle", &_3, 0, _47$$12);
				zephir_check_temp_parameter(_47$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_45$$12, SL(":style"), &_46$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_45$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_45$$12, SS(":type"), SL("public"), 1);
				ZEPHIR_SINIT_NVAR(_48$$12);
				ZVAL_STRING(&_48$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_46$$12, "strtr", &_5, 88, &_48$$12, _45$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_49$$12);
				ZEPHIR_CONCAT_VV(_49$$12, _44$$12, _46$$12);
				zephir_concat_self(&output, _49$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_47$$12);
				ZVAL_STRING(_47$$12, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_51$$12);
				ZVAL_LONG(_51$$12, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_50$$12, this_ptr, "output", &_22, 89, value, _47$$12, _51$$12);
				zephir_check_temp_parameter(_47$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_52$$12);
				ZEPHIR_CONCAT_VS(_52$$12, _50$$12, "\n");
				zephir_concat_self(&output, _52$$12 TSRMLS_CC);
			}
		} else {
			do {
				ZEPHIR_MAKE_REF(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_53, 92, variable);
				ZEPHIR_UNREF(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(key);
				zephir_array_fetch_string(&key, attr, SL("key"), PH_NOISY, "ice/dump.zep", 198 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, attr, SL("value"), PH_NOISY, "ice/dump.zep", 199 TSRMLS_CC);
				if (!(zephir_is_true(key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(_54$$14);
				ZEPHIR_SINIT_NVAR(_55$$14);
				ZVAL_LONG(&_55$$14, 0);
				ZEPHIR_CALL_FUNCTION(&_56$$14, "chr", &_57, 66, &_55$$14);
				zephir_check_call_status();
				zephir_fast_explode(_54$$14, _56$$14, key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(key, _54$$14);
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				if (zephir_array_isset_long(key, 1)) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
					zephir_array_fetch_long(&_58$$17, key, 1, PH_NOISY | PH_READONLY, "ice/dump.zep", 212 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_58$$17, "*")) {
						ZEPHIR_INIT_NVAR(type);
						ZVAL_STRING(type, "protected", 1);
					}
				}
				ZEPHIR_CALL_FUNCTION(&_59$$14, "str_repeat", &_10, 67, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_60$$14);
				zephir_create_array(_60$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_54$$14);
				ZVAL_STRING(_54$$14, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_61$$14, this_ptr, "getstyle", &_3, 0, _54$$14);
				zephir_check_temp_parameter(_54$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_60$$14, SL(":style"), &_61$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_MAKE_REF(key);
				ZEPHIR_CALL_FUNCTION(&_61$$14, "end", &_62, 93, key);
				ZEPHIR_UNREF(key);
				zephir_check_call_status();
				zephir_array_update_string(&_60$$14, SL(":key"), &_61$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_60$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_SINIT_NVAR(_55$$14);
				ZVAL_STRING(&_55$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_61$$14, "strtr", &_5, 88, &_55$$14, _60$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_63$$14);
				ZEPHIR_CONCAT_VV(_63$$14, _59$$14, _61$$14);
				zephir_concat_self(&output, _63$$14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_54$$14);
				ZVAL_STRING(_54$$14, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_65$$14);
				ZVAL_LONG(_65$$14, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_64$$14, this_ptr, "output", &_22, 89, value, _54$$14, _65$$14);
				zephir_check_temp_parameter(_54$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_66$$14);
				ZEPHIR_CONCAT_VS(_66$$14, _64$$14, "\n");
				zephir_concat_self(&output, _66$$14 TSRMLS_CC);
			} while (zephir_is_true(attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 94, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_67$$8, "str_repeat", &_10, 67, space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_68$$8);
		zephir_create_array(_68$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_27$$8);
		ZVAL_STRING(_27$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_69$$8, this_ptr, "getstyle", &_3, 0, _27$$8);
		zephir_check_temp_parameter(_27$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_68$$8, SL(":style"), &_69$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_68$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_68$$8, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_28$$8);
		ZVAL_STRING(&_28$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_69$$8, "strtr", &_5, 88, &_28$$8, _68$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_70$$8);
		ZEPHIR_CONCAT_VV(_70$$8, _67$$8, _69$$8);
		zephir_concat_self(&output, _70$$8 TSRMLS_CC);
		_71$$8 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(className$$8, _71$$8 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_72$$19, "str_repeat", &_10, 67, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_73$$19);
			ZEPHIR_CONCAT_VS(_73$$19, _72$$19, "[already listed]\n");
			zephir_concat_self(&output, _73$$19 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_75$$20, &_74$$20, 0, 0, "ice/dump.zep", 237);
			for (
			  ; zephir_hash_get_current_data_ex(_75$$20, (void**) &_76$$20, &_74$$20) == SUCCESS
			  ; zephir_hash_move_forward_ex(_75$$20, &_74$$20)
			) {
				ZEPHIR_GET_HVALUE(value, _76$$20);
				_77$$21 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
				if (!(zephir_fast_in_array(className$$8, _77$$21 TSRMLS_CC))) {
					zephir_update_property_array_append(this_ptr, SL("methods"), className$$8 TSRMLS_CC);
				}
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_78$$23);
					ZVAL_LONG(&_78$$23, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_79$$23, "str_repeat", &_10, 67, space, &_78$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_80$$23);
					zephir_create_array(_80$$23, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_82$$23);
					ZVAL_STRING(_82$$23, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_81$$23, this_ptr, "getstyle", &_3, 0, _82$$23);
					zephir_check_temp_parameter(_82$$23);
					zephir_check_call_status();
					zephir_array_update_string(&_80$$23, SL(":style"), &_81$$23, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_80$$23, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_78$$23);
					ZVAL_STRING(&_78$$23, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_CALL_FUNCTION(&_81$$23, "strtr", &_5, 88, &_78$$23, _80$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_83$$23);
					ZEPHIR_CONCAT_VV(_83$$23, _79$$23, _81$$23);
					zephir_concat_self(&output, _83$$23 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_84$$24);
					ZVAL_LONG(&_84$$24, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_85$$24, "str_repeat", &_10, 67, space, &_84$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_86$$24);
					zephir_create_array(_86$$24, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_88$$24);
					ZVAL_STRING(_88$$24, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_87$$24, this_ptr, "getstyle", &_3, 0, _88$$24);
					zephir_check_temp_parameter(_88$$24);
					zephir_check_call_status();
					zephir_array_update_string(&_86$$24, SL(":style"), &_87$$24, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_86$$24, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_84$$24);
					ZVAL_STRING(&_84$$24, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_CALL_FUNCTION(&_87$$24, "strtr", &_5, 88, &_84$$24, _86$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_89$$24);
					ZEPHIR_CONCAT_VV(_89$$24, _85$$24, _87$$24);
					zephir_concat_self(&output, _89$$24 TSRMLS_CC);
				}
			}
			ZEPHIR_CALL_FUNCTION(&_90$$20, "str_repeat", &_10, 67, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_91$$20);
			ZEPHIR_CONCAT_VS(_91$$20, _90$$20, ")\n");
			zephir_concat_self(&output, _91$$20 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_28$$8);
		ZVAL_LONG(&_28$$8, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_92$$8, "str_repeat", &_10, 67, space, &_28$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _92$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(_93$$25);
		zephir_create_array(_93$$25, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_95$$25);
		ZVAL_STRING(_95$$25, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_94$$25, this_ptr, "getstyle", &_3, 0, _95$$25);
		zephir_check_temp_parameter(_95$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_93$$25, SL(":style"), &_94$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_93$$25, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_96$$25);
		ZVAL_STRING(&_96$$25, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_94$$25, "strtr", &_5, 88, &_96$$25, _93$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _94$$25);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_97, "is_float", NULL, 95, variable);
	zephir_check_call_status();
	if (zephir_is_true(_97)) {
		ZEPHIR_INIT_VAR(_98$$26);
		zephir_create_array(_98$$26, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_100$$26);
		ZVAL_STRING(_100$$26, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_99$$26, this_ptr, "getstyle", &_3, 0, _100$$26);
		zephir_check_temp_parameter(_100$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_98$$26, SL(":style"), &_99$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_98$$26, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_101$$26);
		ZVAL_STRING(&_101$$26, "<b style=':style'>float</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_99$$26, "strtr", &_5, 88, &_101$$26, _98$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _99$$26);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(_102$$27);
		zephir_create_array(_102$$27, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_104$$27);
		ZVAL_STRING(_104$$27, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_103$$27, this_ptr, "getstyle", &_3, 0, _104$$27);
		zephir_check_temp_parameter(_104$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_102$$27, SL(":style"), &_103$$27, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_102$$27, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_102$$27, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_105$$27);
		ZVAL_STRING(&_105$$27, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_103$$27, "strtr", &_5, 88, &_105$$27, _102$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _103$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(_106$$28);
		zephir_create_array(_106$$28, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_108$$28);
		ZVAL_STRING(_108$$28, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_107$$28, this_ptr, "getstyle", &_3, 0, _108$$28);
		zephir_check_temp_parameter(_108$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_106$$28, SL(":style"), &_107$$28, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_106$$28, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_VAR(_109$$28);
		ZVAL_LONG(&_109$$28, 4);
		ZEPHIR_SINIT_VAR(_110$$28);
		ZVAL_STRING(&_110$$28, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_107$$28, "htmlentities", NULL, 96, variable, &_109$$28, &_110$$28);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_111$$28, "nl2br", NULL, 97, _107$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_106$$28, SL(":var"), &_111$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_109$$28);
		ZVAL_STRING(&_109$$28, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_111$$28, "strtr", &_5, 88, &_109$$28, _106$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _111$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_VAR(_112$$29);
		zephir_create_array(_112$$29, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_114$$29);
		ZVAL_STRING(_114$$29, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_113$$29, this_ptr, "getstyle", &_3, 0, _114$$29);
		zephir_check_temp_parameter(_114$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_112$$29, SL(":style"), &_113$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_115$$29);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_115$$29);
			ZVAL_STRING(_115$$29, "true", 1);
		} else {
			ZEPHIR_INIT_NVAR(_115$$29);
			ZVAL_STRING(_115$$29, "false", 1);
		}
		zephir_array_update_string(&_112$$29, SL(":var"), &_115$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_116$$29);
		ZVAL_STRING(&_116$$29, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_113$$29, "strtr", &_5, 88, &_116$$29, _112$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _113$$29);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(_117$$30);
		zephir_create_array(_117$$30, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_119$$30);
		ZVAL_STRING(_119$$30, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_118$$30, this_ptr, "getstyle", &_3, 0, _119$$30);
		zephir_check_temp_parameter(_119$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_117$$30, SL(":style"), &_118$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_120$$30);
		ZVAL_STRING(&_120$$30, "<b style=':style'>null</b>", 0);
		ZEPHIR_CALL_FUNCTION(&_118$$30, "strtr", &_5, 88, &_120$$30, _117$$30);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _118$$30);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_121);
	zephir_create_array(_121, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_123);
	ZVAL_STRING(_123, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_122, this_ptr, "getstyle", &_3, 0, _123);
	zephir_check_temp_parameter(_123);
	zephir_check_call_status();
	zephir_array_update_string(&_121, SL(":style"), &_122, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_121, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_124);
	ZVAL_STRING(&_124, "(<span style=':style'>:var</span>)", 0);
	ZEPHIR_CALL_FUNCTION(&_122, "strtr", &_5, 88, &_124, _121);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, output, _122);
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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 88, &_3, _0);
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
	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", NULL, 87);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/dump.zep", 310);
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

