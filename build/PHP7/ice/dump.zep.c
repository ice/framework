
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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "detailed");

}

PHP_METHOD(Ice_Dump, setDetailed) {

	zval *detailed, detailed_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&detailed_sub);

	zephir_fetch_params(0, 1, 0, &detailed);



	zephir_update_property_zval(this_ptr, SL("detailed"), detailed);

}

/**
 * Dump constructor
 *
 * @param boolean detailed debug object's private and protected properties
 * @param array styles
 */
PHP_METHOD(Ice_Dump, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval styles;
	zval *detailed_param = NULL, *styles_param = NULL, __$true, __$false;
	zend_bool detailed;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&styles);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &detailed_param, &styles_param);

	if (!detailed_param) {
		detailed = 0;
	} else {
		detailed = zephir_get_boolval(detailed_param);
	}
	if (!styles_param) {
		ZEPHIR_INIT_VAR(&styles);
		array_init(&styles);
	} else {
		zephir_get_arrval(&styles, styles_param);
	}


	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 46);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, &styles);
	zephir_check_call_status();
	if (detailed) {
		zephir_update_property_zval(this_ptr, SL("detailed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("detailed"), &__$false);
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

	zval _1, _2;
	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "vars");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(&_2, "func_get_args", NULL, 84);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &_2);
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

	zval *type_param = NULL, style, _0;
	zval type;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&style);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("styles"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&style, &_0, &type, 1 TSRMLS_CC)) {
		RETURN_CTOR(style);
	} else {
		RETURN_MM_STRING("color:gray");
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

	zval *styles_param = NULL, defaultStyles, _0;
	zval styles;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&styles);
	ZVAL_UNDEF(&defaultStyles);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &styles_param);

	if (!styles_param) {
		ZEPHIR_INIT_VAR(&styles);
		array_init(&styles);
	} else {
		zephir_get_arrval(&styles, styles_param);
	}


	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 98);
		return;
	}
	ZEPHIR_INIT_VAR(&defaultStyles);
	zephir_create_array(&defaultStyles, 11, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&defaultStyles, SL("pre"), SL("background-color:#f9f9f9; font-size:11px; padding:10px; border:1px solid #ccc; text-align:left; color:#333"));
	add_assoc_stringl_ex(&defaultStyles, SL("arr"), SL("color:red"));
	add_assoc_stringl_ex(&defaultStyles, SL("bool"), SL("color:green"));
	add_assoc_stringl_ex(&defaultStyles, SL("float"), SL("color:fuchsia"));
	add_assoc_stringl_ex(&defaultStyles, SL("int"), SL("color:blue"));
	add_assoc_stringl_ex(&defaultStyles, SL("null"), SL("color:black"));
	add_assoc_stringl_ex(&defaultStyles, SL("num"), SL("color:navy"));
	add_assoc_stringl_ex(&defaultStyles, SL("obj"), SL("color:purple"));
	add_assoc_stringl_ex(&defaultStyles, SL("other"), SL("color:maroon"));
	add_assoc_stringl_ex(&defaultStyles, SL("res"), SL("color:lime"));
	add_assoc_stringl_ex(&defaultStyles, SL("str"), SL("color:teal"));
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &defaultStyles, &styles TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("styles"), &_0);
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
	zval name;
	zval *variable, variable_sub, *name_param = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "variable", NULL, 0, variable, &name);
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

	zend_bool _14$$5, _15$$5, _16$$5;
	zend_string *_7$$4, *_38$$11;
	zend_ulong _6$$4, _37$$11;
	zval _107, _0$$4, _10$$5, _24$$8, _61$$8, _29$$9, _40$$12, _54$$14, _71$$23, _77$$24, _85$$25, _89$$26, _92$$27, _95$$28, _100$$29, _104$$30;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_9 = NULL, *_20 = NULL, *_28 = NULL, *_47 = NULL, *_51 = NULL, *_56 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, *name = NULL, name_sub, *tab = NULL, tab_sub, __$null, key, value, output, space, type, attr, _88, _108, _109, _1$$4, _2$$4, *_5$$4, _22$$4, _23$$4, _8$$5, _11$$5, _12$$5, _13$$5, _17$$7, _18$$7, _19$$7, _21$$7, className$$8, _25$$8, _26$$8, _27$$8, _32$$8, _60$$8, _62$$8, _63$$8, _64$$8, _83$$8, _84$$8, _30$$9, _31$$9, _33$$10, _34$$10, _35$$11, *_36$$11, _39$$12, _41$$12, _42$$12, _43$$12, _44$$12, _45$$12, _46$$12, _48$$14, _49$$14, _50$$14, _53$$14, _55$$14, _57$$14, _58$$14, _59$$14, _52$$17, _65$$19, _66$$19, *_67$$20, _81$$20, _82$$20, _68$$21, _69$$23, _70$$23, _72$$23, _73$$23, _74$$23, _75$$24, _76$$24, _78$$24, _79$$24, _80$$24, _86$$25, _87$$25, _90$$26, _91$$26, _93$$27, _94$$27, _96$$28, _97$$28, _98$$28, _99$$28, _101$$29, _102$$29, _103$$29, _105$$30, _106$$30;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&tab_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_88);
	ZVAL_UNDEF(&_108);
	ZVAL_UNDEF(&_109);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&className$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_60$$8);
	ZVAL_UNDEF(&_62$$8);
	ZVAL_UNDEF(&_63$$8);
	ZVAL_UNDEF(&_64$$8);
	ZVAL_UNDEF(&_83$$8);
	ZVAL_UNDEF(&_84$$8);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_35$$11);
	ZVAL_UNDEF(&_39$$12);
	ZVAL_UNDEF(&_41$$12);
	ZVAL_UNDEF(&_42$$12);
	ZVAL_UNDEF(&_43$$12);
	ZVAL_UNDEF(&_44$$12);
	ZVAL_UNDEF(&_45$$12);
	ZVAL_UNDEF(&_46$$12);
	ZVAL_UNDEF(&_48$$14);
	ZVAL_UNDEF(&_49$$14);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_53$$14);
	ZVAL_UNDEF(&_55$$14);
	ZVAL_UNDEF(&_57$$14);
	ZVAL_UNDEF(&_58$$14);
	ZVAL_UNDEF(&_59$$14);
	ZVAL_UNDEF(&_52$$17);
	ZVAL_UNDEF(&_65$$19);
	ZVAL_UNDEF(&_66$$19);
	ZVAL_UNDEF(&_81$$20);
	ZVAL_UNDEF(&_82$$20);
	ZVAL_UNDEF(&_68$$21);
	ZVAL_UNDEF(&_69$$23);
	ZVAL_UNDEF(&_70$$23);
	ZVAL_UNDEF(&_72$$23);
	ZVAL_UNDEF(&_73$$23);
	ZVAL_UNDEF(&_74$$23);
	ZVAL_UNDEF(&_75$$24);
	ZVAL_UNDEF(&_76$$24);
	ZVAL_UNDEF(&_78$$24);
	ZVAL_UNDEF(&_79$$24);
	ZVAL_UNDEF(&_80$$24);
	ZVAL_UNDEF(&_86$$25);
	ZVAL_UNDEF(&_87$$25);
	ZVAL_UNDEF(&_90$$26);
	ZVAL_UNDEF(&_91$$26);
	ZVAL_UNDEF(&_93$$27);
	ZVAL_UNDEF(&_94$$27);
	ZVAL_UNDEF(&_96$$28);
	ZVAL_UNDEF(&_97$$28);
	ZVAL_UNDEF(&_98$$28);
	ZVAL_UNDEF(&_99$$28);
	ZVAL_UNDEF(&_101$$29);
	ZVAL_UNDEF(&_102$$29);
	ZVAL_UNDEF(&_103$$29);
	ZVAL_UNDEF(&_105$$30);
	ZVAL_UNDEF(&_106$$30);
	ZVAL_UNDEF(&_107);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_61$$8);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_40$$12);
	ZVAL_UNDEF(&_54$$14);
	ZVAL_UNDEF(&_71$$23);
	ZVAL_UNDEF(&_77$$24);
	ZVAL_UNDEF(&_85$$25);
	ZVAL_UNDEF(&_89$$26);
	ZVAL_UNDEF(&_92$$27);
	ZVAL_UNDEF(&_95$$28);
	ZVAL_UNDEF(&_100$$29);
	ZVAL_UNDEF(&_104$$30);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &variable, &name, &tab);

	if (!name) {
		name = &name_sub;
		name = &__$null;
	}
	if (!tab) {
		tab = &tab_sub;
		ZEPHIR_INIT_VAR(tab);
		ZVAL_LONG(tab, 1);
	}


	ZEPHIR_INIT_VAR(&space);
	ZVAL_STRING(&space, "  ");
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	if (zephir_is_true(name)) {
		ZEPHIR_INIT_NVAR(&output);
		ZEPHIR_CONCAT_VS(&output, name, " ");
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_create_array(&_0$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "arr");
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getstyle", &_3, 0, &_2$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_0$$4, SL(":style"), &_1$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_0$$4, SL(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "<b style =':style'>array</b> (<span style =':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_1$$4, "strtr", &_4, 85, &_2$$4, &_0$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_1$$4 TSRMLS_CC);
		zephir_is_iterable(variable, 0, "ice/dump.zep", 166);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(variable), _6$$4, _7$$4, _5$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _7$$4);
			} else {
				ZVAL_LONG(&key, _6$$4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _5$$4);
			ZEPHIR_CALL_FUNCTION(&_8$$5, "str_repeat", &_9, 67, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$5);
			zephir_create_array(&_10$$5, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_12$$5);
			ZVAL_STRING(&_12$$5, "arr");
			ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "getstyle", &_3, 0, &_12$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_10$$5, SL(":style"), &_11$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_12$$5);
			ZVAL_STRING(&_12$$5, "[<span style=':style'>:key</span>] => ");
			ZEPHIR_CALL_FUNCTION(&_11$$5, "strtr", &_4, 85, &_12$$5, &_10$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_13$$5);
			ZEPHIR_CONCAT_VV(&_13$$5, &_8$$5, &_11$$5);
			zephir_concat_self(&output, &_13$$5 TSRMLS_CC);
			_14$$5 = ZEPHIR_IS_LONG(tab, 1);
			if (_14$$5) {
				_14$$5 = !ZEPHIR_IS_STRING(name, "");
			}
			_15$$5 = _14$$5;
			if (_15$$5) {
				_15$$5 = !(Z_TYPE_P(&key) == IS_LONG);
			}
			_16$$5 = _15$$5;
			if (_16$$5) {
				_16$$5 = ZEPHIR_IS_EQUAL(name, &key);
			}
			if (_16$$5) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(&_18$$7);
				ZVAL_STRING(&_18$$7, "");
				ZVAL_LONG(&_19$$7, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_17$$7, this_ptr, "output", &_20, 86, &value, &_18$$7, &_19$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_21$$7);
				ZEPHIR_CONCAT_VS(&_21$$7, &_17$$7, "\n");
				zephir_concat_self(&output, &_21$$7 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_22$$4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_23$$4, "str_repeat", &_9, 67, &space, &_22$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_23$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&className$$8);
		zephir_get_class(&className$$8, variable, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_24$$8);
		zephir_create_array(&_24$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_26$$8);
		ZVAL_STRING(&_26$$8, "obj");
		ZEPHIR_CALL_METHOD(&_25$$8, this_ptr, "getstyle", &_3, 0, &_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_24$$8, SL(":style"), &_25$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_24$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_26$$8);
		ZVAL_STRING(&_26$$8, "<b style=':style'>object</b> :class");
		ZEPHIR_CALL_FUNCTION(&_25$$8, "strtr", &_4, 85, &_26$$8, &_24$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, &_25$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_27$$8, "get_parent_class", &_28, 87, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_27$$8)) {
			ZEPHIR_INIT_VAR(&_29$$9);
			zephir_create_array(&_29$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_31$$9);
			ZVAL_STRING(&_31$$9, "obj");
			ZEPHIR_CALL_METHOD(&_30$$9, this_ptr, "getstyle", &_3, 0, &_31$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_29$$9, SL(":style"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_30$$9, "get_parent_class", &_28, 87, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_29$$9, SL(":parent"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_31$$9);
			ZVAL_STRING(&_31$$9, " <b style=':style'>extends</b> :parent");
			ZEPHIR_CALL_FUNCTION(&_30$$9, "strtr", &_4, 85, &_31$$9, &_29$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, &_30$$9 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		zephir_read_property(&_32$$8, this_ptr, SL("detailed"), PH_NOISY_CC | PH_READONLY);
		if (zephir_instance_of_ev(variable, ice_di_ce TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_33$$10, "str_repeat", &_9, 67, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_34$$10);
			ZEPHIR_CONCAT_VS(&_34$$10, &_33$$10, "[skipped]\n");
			zephir_concat_self(&output, &_34$$10 TSRMLS_CC);
		} else if (!(zephir_is_true(&_32$$8))) {
			ZEPHIR_CALL_FUNCTION(&_35$$11, "get_object_vars", NULL, 88, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_35$$11, 0, "ice/dump.zep", 189);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_35$$11), _37$$11, _38$$11, _36$$11)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_38$$11 != NULL) { 
					ZVAL_STR_COPY(&key, _38$$11);
				} else {
					ZVAL_LONG(&key, _37$$11);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _36$$11);
				ZEPHIR_CALL_FUNCTION(&_39$$12, "str_repeat", &_9, 67, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$12);
				zephir_create_array(&_40$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_42$$12);
				ZVAL_STRING(&_42$$12, "obj");
				ZEPHIR_CALL_METHOD(&_41$$12, this_ptr, "getstyle", &_3, 0, &_42$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_40$$12, SL(":style"), &_41$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_40$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(&_40$$12, SL(":type"), SL("public"));
				ZEPHIR_INIT_NVAR(&_42$$12);
				ZVAL_STRING(&_42$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_41$$12, "strtr", &_4, 85, &_42$$12, &_40$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_43$$12);
				ZEPHIR_CONCAT_VV(&_43$$12, &_39$$12, &_41$$12);
				zephir_concat_self(&output, &_43$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_42$$12);
				ZVAL_STRING(&_42$$12, "");
				ZVAL_LONG(&_45$$12, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_44$$12, this_ptr, "output", &_20, 86, &value, &_42$$12, &_45$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_46$$12);
				ZEPHIR_CONCAT_VS(&_46$$12, &_44$$12, "\n");
				zephir_concat_self(&output, &_46$$12 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			do {
				ZEPHIR_MAKE_REF(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_47, 89, variable);
				ZEPHIR_UNREF(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(&attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&key);
				zephir_array_fetch_string(&key, &attr, SL("key"), PH_NOISY, "ice/dump.zep", 197 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_string(&value, &attr, SL("value"), PH_NOISY, "ice/dump.zep", 198 TSRMLS_CC);
				if (!(zephir_is_true(&key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_48$$14);
				ZVAL_LONG(&_49$$14, 0);
				ZEPHIR_CALL_FUNCTION(&_50$$14, "chr", &_51, 66, &_49$$14);
				zephir_check_call_status();
				zephir_fast_explode(&_48$$14, &_50$$14, &key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(&key, &_48$$14);
				ZEPHIR_INIT_NVAR(&type);
				ZVAL_STRING(&type, "public");
				if (zephir_array_isset_long(&key, 1)) {
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_STRING(&type, "private");
					zephir_array_fetch_long(&_52$$17, &key, 1, PH_NOISY | PH_READONLY, "ice/dump.zep", 211 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(&_52$$17, "*")) {
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "protected");
					}
				}
				ZEPHIR_CALL_FUNCTION(&_53$$14, "str_repeat", &_9, 67, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_54$$14);
				zephir_create_array(&_54$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_48$$14);
				ZVAL_STRING(&_48$$14, "obj");
				ZEPHIR_CALL_METHOD(&_55$$14, this_ptr, "getstyle", &_3, 0, &_48$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_54$$14, SL(":style"), &_55$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_MAKE_REF(&key);
				ZEPHIR_CALL_FUNCTION(&_55$$14, "end", &_56, 90, &key);
				ZEPHIR_UNREF(&key);
				zephir_check_call_status();
				zephir_array_update_string(&_54$$14, SL(":key"), &_55$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_54$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_48$$14);
				ZVAL_STRING(&_48$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_55$$14, "strtr", &_4, 85, &_48$$14, &_54$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_57$$14);
				ZEPHIR_CONCAT_VV(&_57$$14, &_53$$14, &_55$$14);
				zephir_concat_self(&output, &_57$$14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_48$$14);
				ZVAL_STRING(&_48$$14, "");
				ZVAL_LONG(&_49$$14, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_58$$14, this_ptr, "output", &_20, 86, &value, &_48$$14, &_49$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_59$$14);
				ZEPHIR_CONCAT_VS(&_59$$14, &_58$$14, "\n");
				zephir_concat_self(&output, &_59$$14 TSRMLS_CC);
			} while (zephir_is_true(&attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 91, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_60$$8, "str_repeat", &_9, 67, &space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_61$$8);
		zephir_create_array(&_61$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_26$$8);
		ZVAL_STRING(&_26$$8, "obj");
		ZEPHIR_CALL_METHOD(&_62$$8, this_ptr, "getstyle", &_3, 0, &_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_61$$8, SL(":style"), &_62$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_61$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_61$$8, SL(":count"), zephir_fast_count_int(&attr TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&_26$$8);
		ZVAL_STRING(&_26$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_62$$8, "strtr", &_4, 85, &_26$$8, &_61$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_63$$8);
		ZEPHIR_CONCAT_VV(&_63$$8, &_60$$8, &_62$$8);
		zephir_concat_self(&output, &_63$$8 TSRMLS_CC);
		zephir_read_property(&_64$$8, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&className$$8, &_64$$8 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_65$$19, "str_repeat", &_9, 67, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_66$$19);
			ZEPHIR_CONCAT_VS(&_66$$19, &_65$$19, "[already listed]\n");
			zephir_concat_self(&output, &_66$$19 TSRMLS_CC);
		} else {
			zephir_is_iterable(&attr, 0, "ice/dump.zep", 236);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _67$$20)
			{
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _67$$20);
				zephir_read_property(&_68$$21, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_fast_in_array(&className$$8, &_68$$21 TSRMLS_CC))) {
					zephir_update_property_array_append(this_ptr, SL("methods"), &className$$8 TSRMLS_CC);
				}
				if (ZEPHIR_IS_STRING(&value, "__construct")) {
					ZVAL_LONG(&_69$$23, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_70$$23, "str_repeat", &_9, 67, &space, &_69$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_71$$23);
					zephir_create_array(&_71$$23, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_73$$23);
					ZVAL_STRING(&_73$$23, "obj");
					ZEPHIR_CALL_METHOD(&_72$$23, this_ptr, "getstyle", &_3, 0, &_73$$23);
					zephir_check_call_status();
					zephir_array_update_string(&_71$$23, SL(":style"), &_72$$23, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_71$$23, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_73$$23);
					ZVAL_STRING(&_73$$23, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n");
					ZEPHIR_CALL_FUNCTION(&_72$$23, "strtr", &_4, 85, &_73$$23, &_71$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_74$$23);
					ZEPHIR_CONCAT_VV(&_74$$23, &_70$$23, &_72$$23);
					zephir_concat_self(&output, &_74$$23 TSRMLS_CC);
				} else {
					ZVAL_LONG(&_75$$24, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_76$$24, "str_repeat", &_9, 67, &space, &_75$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_77$$24);
					zephir_create_array(&_77$$24, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_79$$24);
					ZVAL_STRING(&_79$$24, "obj");
					ZEPHIR_CALL_METHOD(&_78$$24, this_ptr, "getstyle", &_3, 0, &_79$$24);
					zephir_check_call_status();
					zephir_array_update_string(&_77$$24, SL(":style"), &_78$$24, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_77$$24, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_79$$24);
					ZVAL_STRING(&_79$$24, "-><span style=':style'>:method</span>();\n");
					ZEPHIR_CALL_FUNCTION(&_78$$24, "strtr", &_4, 85, &_79$$24, &_77$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_80$$24);
					ZEPHIR_CONCAT_VV(&_80$$24, &_76$$24, &_78$$24);
					zephir_concat_self(&output, &_80$$24 TSRMLS_CC);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_CALL_FUNCTION(&_81$$20, "str_repeat", &_9, 67, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_82$$20);
			ZEPHIR_CONCAT_VS(&_82$$20, &_81$$20, ")\n");
			zephir_concat_self(&output, &_82$$20 TSRMLS_CC);
		}
		ZVAL_LONG(&_83$$8, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_84$$8, "str_repeat", &_9, 67, &space, &_83$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_84$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_85$$25);
		zephir_create_array(&_85$$25, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_87$$25);
		ZVAL_STRING(&_87$$25, "int");
		ZEPHIR_CALL_METHOD(&_86$$25, this_ptr, "getstyle", &_3, 0, &_87$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_85$$25, SL(":style"), &_86$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_85$$25, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_87$$25);
		ZVAL_STRING(&_87$$25, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_86$$25, "strtr", &_4, 85, &_87$$25, &_85$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_86$$25);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_88, "is_float", NULL, 92, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_88)) {
		ZEPHIR_INIT_VAR(&_89$$26);
		zephir_create_array(&_89$$26, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_91$$26);
		ZVAL_STRING(&_91$$26, "float");
		ZEPHIR_CALL_METHOD(&_90$$26, this_ptr, "getstyle", &_3, 0, &_91$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_89$$26, SL(":style"), &_90$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_89$$26, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_91$$26);
		ZVAL_STRING(&_91$$26, "<b style=':style'>float</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_90$$26, "strtr", &_4, 85, &_91$$26, &_89$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_90$$26);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_92$$27);
		zephir_create_array(&_92$$27, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_94$$27);
		ZVAL_STRING(&_94$$27, "num");
		ZEPHIR_CALL_METHOD(&_93$$27, this_ptr, "getstyle", &_3, 0, &_94$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_92$$27, SL(":style"), &_93$$27, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_92$$27, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_92$$27, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_94$$27);
		ZVAL_STRING(&_94$$27, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_93$$27, "strtr", &_4, 85, &_94$$27, &_92$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_93$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_95$$28);
		zephir_create_array(&_95$$28, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_97$$28);
		ZVAL_STRING(&_97$$28, "str");
		ZEPHIR_CALL_METHOD(&_96$$28, this_ptr, "getstyle", &_3, 0, &_97$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_95$$28, SL(":style"), &_96$$28, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_95$$28, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_98$$28, 4);
		ZEPHIR_INIT_NVAR(&_97$$28);
		ZVAL_STRING(&_97$$28, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_96$$28, "htmlentities", NULL, 93, variable, &_98$$28, &_97$$28);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_99$$28, "nl2br", NULL, 94, &_96$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_95$$28, SL(":var"), &_99$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_97$$28);
		ZVAL_STRING(&_97$$28, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_99$$28, "strtr", &_4, 85, &_97$$28, &_95$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_99$$28);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_100$$29);
		zephir_create_array(&_100$$29, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_102$$29);
		ZVAL_STRING(&_102$$29, "bool");
		ZEPHIR_CALL_METHOD(&_101$$29, this_ptr, "getstyle", &_3, 0, &_102$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_100$$29, SL(":style"), &_101$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_103$$29);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_103$$29);
			ZVAL_STRING(&_103$$29, "true");
		} else {
			ZEPHIR_INIT_NVAR(&_103$$29);
			ZVAL_STRING(&_103$$29, "false");
		}
		zephir_array_update_string(&_100$$29, SL(":var"), &_103$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_102$$29);
		ZVAL_STRING(&_102$$29, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_101$$29, "strtr", &_4, 85, &_102$$29, &_100$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_101$$29);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_104$$30);
		zephir_create_array(&_104$$30, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_106$$30);
		ZVAL_STRING(&_106$$30, "null");
		ZEPHIR_CALL_METHOD(&_105$$30, this_ptr, "getstyle", &_3, 0, &_106$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_104$$30, SL(":style"), &_105$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_106$$30);
		ZVAL_STRING(&_106$$30, "<b style=':style'>null</b>");
		ZEPHIR_CALL_FUNCTION(&_105$$30, "strtr", &_4, 85, &_106$$30, &_104$$30);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_105$$30);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_107);
	zephir_create_array(&_107, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_109);
	ZVAL_STRING(&_109, "other");
	ZEPHIR_CALL_METHOD(&_108, this_ptr, "getstyle", &_3, 0, &_109);
	zephir_check_call_status();
	zephir_array_update_string(&_107, SL(":style"), &_108, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_107, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_109);
	ZVAL_STRING(&_109, "(<span style=':style'>:var</span>)");
	ZEPHIR_CALL_FUNCTION(&_108, "strtr", &_4, 85, &_109, &_107);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_108);
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

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *variable, variable_sub, *name_param = NULL, _1, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "pre");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "output", NULL, 0, variable, &name);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":output"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "<pre style=':style'>:output</pre>");
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 85, &_2, &_0);
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

	zend_string *_3;
	zend_ulong _2;
	zval key, value, output, _0, *_1, _4$$3, _5$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", NULL, 84);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "ice/dump.zep", 309);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_INIT_LNVAR(_5$$3);
		ZEPHIR_CONCAT_SV(&_5$$3, "var ", &key);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "one", &_6, 0, &value, &_5$$3);
		zephir_check_call_status();
		zephir_concat_self(&output, &_4$$3 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(output);

}

static zend_object *zephir_init_properties_Ice_Dump(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("styles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("styles"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("methods"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

