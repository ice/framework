
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

PHP_METHOD(Ice_Dump, getSkipDi) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "skipDi");

}

PHP_METHOD(Ice_Dump, setSkipDi) {

	zval *skipDi, skipDi_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&skipDi_sub);

	zephir_fetch_params(0, 1, 0, &skipDi);



	zephir_update_property_zval(this_ptr, SL("skipDi"), skipDi);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 47);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 99);
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

	zend_bool _14$$5, _15$$5, _16$$5, _33$$8;
	zend_string *_7$$4, *_40$$11;
	zend_ulong _6$$4, _39$$11;
	zval _109, _0$$4, _10$$5, _24$$8, _63$$8, _29$$9, _42$$12, _56$$14, _73$$23, _79$$24, _87$$25, _91$$26, _94$$27, _97$$28, _102$$29, _106$$30;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_9 = NULL, *_20 = NULL, *_28 = NULL, *_49 = NULL, *_53 = NULL, *_58 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, *name = NULL, name_sub, *tab = NULL, tab_sub, __$null, key, value, output, space, type, attr, _90, _110, _111, _1$$4, _2$$4, *_5$$4, _22$$4, _23$$4, _8$$5, _11$$5, _12$$5, _13$$5, _17$$7, _18$$7, _19$$7, _21$$7, className$$8, _25$$8, _26$$8, _27$$8, _32$$8, _34$$8, _62$$8, _64$$8, _65$$8, _66$$8, _85$$8, _86$$8, _30$$9, _31$$9, _35$$10, _36$$10, _37$$11, *_38$$11, _41$$12, _43$$12, _44$$12, _45$$12, _46$$12, _47$$12, _48$$12, _50$$14, _51$$14, _52$$14, _55$$14, _57$$14, _59$$14, _60$$14, _61$$14, _54$$17, _67$$19, _68$$19, *_69$$20, _83$$20, _84$$20, _70$$21, _71$$23, _72$$23, _74$$23, _75$$23, _76$$23, _77$$24, _78$$24, _80$$24, _81$$24, _82$$24, _88$$25, _89$$25, _92$$26, _93$$26, _95$$27, _96$$27, _98$$28, _99$$28, _100$$28, _101$$28, _103$$29, _104$$29, _105$$29, _107$$30, _108$$30;
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
	ZVAL_UNDEF(&_90);
	ZVAL_UNDEF(&_110);
	ZVAL_UNDEF(&_111);
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
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_62$$8);
	ZVAL_UNDEF(&_64$$8);
	ZVAL_UNDEF(&_65$$8);
	ZVAL_UNDEF(&_66$$8);
	ZVAL_UNDEF(&_85$$8);
	ZVAL_UNDEF(&_86$$8);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$11);
	ZVAL_UNDEF(&_41$$12);
	ZVAL_UNDEF(&_43$$12);
	ZVAL_UNDEF(&_44$$12);
	ZVAL_UNDEF(&_45$$12);
	ZVAL_UNDEF(&_46$$12);
	ZVAL_UNDEF(&_47$$12);
	ZVAL_UNDEF(&_48$$12);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_51$$14);
	ZVAL_UNDEF(&_52$$14);
	ZVAL_UNDEF(&_55$$14);
	ZVAL_UNDEF(&_57$$14);
	ZVAL_UNDEF(&_59$$14);
	ZVAL_UNDEF(&_60$$14);
	ZVAL_UNDEF(&_61$$14);
	ZVAL_UNDEF(&_54$$17);
	ZVAL_UNDEF(&_67$$19);
	ZVAL_UNDEF(&_68$$19);
	ZVAL_UNDEF(&_83$$20);
	ZVAL_UNDEF(&_84$$20);
	ZVAL_UNDEF(&_70$$21);
	ZVAL_UNDEF(&_71$$23);
	ZVAL_UNDEF(&_72$$23);
	ZVAL_UNDEF(&_74$$23);
	ZVAL_UNDEF(&_75$$23);
	ZVAL_UNDEF(&_76$$23);
	ZVAL_UNDEF(&_77$$24);
	ZVAL_UNDEF(&_78$$24);
	ZVAL_UNDEF(&_80$$24);
	ZVAL_UNDEF(&_81$$24);
	ZVAL_UNDEF(&_82$$24);
	ZVAL_UNDEF(&_88$$25);
	ZVAL_UNDEF(&_89$$25);
	ZVAL_UNDEF(&_92$$26);
	ZVAL_UNDEF(&_93$$26);
	ZVAL_UNDEF(&_95$$27);
	ZVAL_UNDEF(&_96$$27);
	ZVAL_UNDEF(&_98$$28);
	ZVAL_UNDEF(&_99$$28);
	ZVAL_UNDEF(&_100$$28);
	ZVAL_UNDEF(&_101$$28);
	ZVAL_UNDEF(&_103$$29);
	ZVAL_UNDEF(&_104$$29);
	ZVAL_UNDEF(&_105$$29);
	ZVAL_UNDEF(&_107$$30);
	ZVAL_UNDEF(&_108$$30);
	ZVAL_UNDEF(&_109);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_63$$8);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_42$$12);
	ZVAL_UNDEF(&_56$$14);
	ZVAL_UNDEF(&_73$$23);
	ZVAL_UNDEF(&_79$$24);
	ZVAL_UNDEF(&_87$$25);
	ZVAL_UNDEF(&_91$$26);
	ZVAL_UNDEF(&_94$$27);
	ZVAL_UNDEF(&_97$$28);
	ZVAL_UNDEF(&_102$$29);
	ZVAL_UNDEF(&_106$$30);

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
		zephir_is_iterable(variable, 0, "ice/dump.zep", 167);
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
		zephir_read_property(&_32$$8, this_ptr, SL("skipDi"), PH_NOISY_CC | PH_READONLY);
		_33$$8 = zephir_is_true(&_32$$8);
		if (_33$$8) {
			_33$$8 = zephir_instance_of_ev(variable, ice_di_ce TSRMLS_CC);
		}
		zephir_read_property(&_34$$8, this_ptr, SL("detailed"), PH_NOISY_CC | PH_READONLY);
		if (_33$$8) {
			ZEPHIR_CALL_FUNCTION(&_35$$10, "str_repeat", &_9, 67, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_36$$10);
			ZEPHIR_CONCAT_VS(&_36$$10, &_35$$10, "[skipped]\n");
			zephir_concat_self(&output, &_36$$10 TSRMLS_CC);
		} else if (!(zephir_is_true(&_34$$8))) {
			ZEPHIR_CALL_FUNCTION(&_37$$11, "get_object_vars", NULL, 88, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_37$$11, 0, "ice/dump.zep", 190);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_37$$11), _39$$11, _40$$11, _38$$11)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_40$$11 != NULL) { 
					ZVAL_STR_COPY(&key, _40$$11);
				} else {
					ZVAL_LONG(&key, _39$$11);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _38$$11);
				ZEPHIR_CALL_FUNCTION(&_41$$12, "str_repeat", &_9, 67, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_42$$12);
				zephir_create_array(&_42$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_44$$12);
				ZVAL_STRING(&_44$$12, "obj");
				ZEPHIR_CALL_METHOD(&_43$$12, this_ptr, "getstyle", &_3, 0, &_44$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_42$$12, SL(":style"), &_43$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_42$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(&_42$$12, SL(":type"), SL("public"));
				ZEPHIR_INIT_NVAR(&_44$$12);
				ZVAL_STRING(&_44$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_43$$12, "strtr", &_4, 85, &_44$$12, &_42$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_45$$12);
				ZEPHIR_CONCAT_VV(&_45$$12, &_41$$12, &_43$$12);
				zephir_concat_self(&output, &_45$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_44$$12);
				ZVAL_STRING(&_44$$12, "");
				ZVAL_LONG(&_47$$12, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_46$$12, this_ptr, "output", &_20, 86, &value, &_44$$12, &_47$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_48$$12);
				ZEPHIR_CONCAT_VS(&_48$$12, &_46$$12, "\n");
				zephir_concat_self(&output, &_48$$12 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			do {
				ZEPHIR_MAKE_REF(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_49, 89, variable);
				ZEPHIR_UNREF(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(&attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&key);
				zephir_array_fetch_string(&key, &attr, SL("key"), PH_NOISY, "ice/dump.zep", 198 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_string(&value, &attr, SL("value"), PH_NOISY, "ice/dump.zep", 199 TSRMLS_CC);
				if (!(zephir_is_true(&key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_50$$14);
				ZVAL_LONG(&_51$$14, 0);
				ZEPHIR_CALL_FUNCTION(&_52$$14, "chr", &_53, 66, &_51$$14);
				zephir_check_call_status();
				zephir_fast_explode(&_50$$14, &_52$$14, &key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(&key, &_50$$14);
				ZEPHIR_INIT_NVAR(&type);
				ZVAL_STRING(&type, "public");
				if (zephir_array_isset_long(&key, 1)) {
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_STRING(&type, "private");
					zephir_array_fetch_long(&_54$$17, &key, 1, PH_NOISY | PH_READONLY, "ice/dump.zep", 212 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(&_54$$17, "*")) {
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "protected");
					}
				}
				ZEPHIR_CALL_FUNCTION(&_55$$14, "str_repeat", &_9, 67, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_56$$14);
				zephir_create_array(&_56$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_50$$14);
				ZVAL_STRING(&_50$$14, "obj");
				ZEPHIR_CALL_METHOD(&_57$$14, this_ptr, "getstyle", &_3, 0, &_50$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_56$$14, SL(":style"), &_57$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_MAKE_REF(&key);
				ZEPHIR_CALL_FUNCTION(&_57$$14, "end", &_58, 90, &key);
				ZEPHIR_UNREF(&key);
				zephir_check_call_status();
				zephir_array_update_string(&_56$$14, SL(":key"), &_57$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_56$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_50$$14);
				ZVAL_STRING(&_50$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_57$$14, "strtr", &_4, 85, &_50$$14, &_56$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_59$$14);
				ZEPHIR_CONCAT_VV(&_59$$14, &_55$$14, &_57$$14);
				zephir_concat_self(&output, &_59$$14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_50$$14);
				ZVAL_STRING(&_50$$14, "");
				ZVAL_LONG(&_51$$14, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_60$$14, this_ptr, "output", &_20, 86, &value, &_50$$14, &_51$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_61$$14);
				ZEPHIR_CONCAT_VS(&_61$$14, &_60$$14, "\n");
				zephir_concat_self(&output, &_61$$14 TSRMLS_CC);
			} while (zephir_is_true(&attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 91, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_62$$8, "str_repeat", &_9, 67, &space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_63$$8);
		zephir_create_array(&_63$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_26$$8);
		ZVAL_STRING(&_26$$8, "obj");
		ZEPHIR_CALL_METHOD(&_64$$8, this_ptr, "getstyle", &_3, 0, &_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_63$$8, SL(":style"), &_64$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_63$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_63$$8, SL(":count"), zephir_fast_count_int(&attr TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&_26$$8);
		ZVAL_STRING(&_26$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_64$$8, "strtr", &_4, 85, &_26$$8, &_63$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_65$$8);
		ZEPHIR_CONCAT_VV(&_65$$8, &_62$$8, &_64$$8);
		zephir_concat_self(&output, &_65$$8 TSRMLS_CC);
		zephir_read_property(&_66$$8, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&className$$8, &_66$$8 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_67$$19, "str_repeat", &_9, 67, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_68$$19);
			ZEPHIR_CONCAT_VS(&_68$$19, &_67$$19, "[already listed]\n");
			zephir_concat_self(&output, &_68$$19 TSRMLS_CC);
		} else {
			zephir_is_iterable(&attr, 0, "ice/dump.zep", 237);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _69$$20)
			{
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _69$$20);
				zephir_read_property(&_70$$21, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_fast_in_array(&className$$8, &_70$$21 TSRMLS_CC))) {
					zephir_update_property_array_append(this_ptr, SL("methods"), &className$$8 TSRMLS_CC);
				}
				if (ZEPHIR_IS_STRING(&value, "__construct")) {
					ZVAL_LONG(&_71$$23, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_72$$23, "str_repeat", &_9, 67, &space, &_71$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_73$$23);
					zephir_create_array(&_73$$23, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_75$$23);
					ZVAL_STRING(&_75$$23, "obj");
					ZEPHIR_CALL_METHOD(&_74$$23, this_ptr, "getstyle", &_3, 0, &_75$$23);
					zephir_check_call_status();
					zephir_array_update_string(&_73$$23, SL(":style"), &_74$$23, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_73$$23, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_75$$23);
					ZVAL_STRING(&_75$$23, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n");
					ZEPHIR_CALL_FUNCTION(&_74$$23, "strtr", &_4, 85, &_75$$23, &_73$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_76$$23);
					ZEPHIR_CONCAT_VV(&_76$$23, &_72$$23, &_74$$23);
					zephir_concat_self(&output, &_76$$23 TSRMLS_CC);
				} else {
					ZVAL_LONG(&_77$$24, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_78$$24, "str_repeat", &_9, 67, &space, &_77$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_79$$24);
					zephir_create_array(&_79$$24, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_81$$24);
					ZVAL_STRING(&_81$$24, "obj");
					ZEPHIR_CALL_METHOD(&_80$$24, this_ptr, "getstyle", &_3, 0, &_81$$24);
					zephir_check_call_status();
					zephir_array_update_string(&_79$$24, SL(":style"), &_80$$24, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_79$$24, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_81$$24);
					ZVAL_STRING(&_81$$24, "-><span style=':style'>:method</span>();\n");
					ZEPHIR_CALL_FUNCTION(&_80$$24, "strtr", &_4, 85, &_81$$24, &_79$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_82$$24);
					ZEPHIR_CONCAT_VV(&_82$$24, &_78$$24, &_80$$24);
					zephir_concat_self(&output, &_82$$24 TSRMLS_CC);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_CALL_FUNCTION(&_83$$20, "str_repeat", &_9, 67, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_84$$20);
			ZEPHIR_CONCAT_VS(&_84$$20, &_83$$20, ")\n");
			zephir_concat_self(&output, &_84$$20 TSRMLS_CC);
		}
		ZVAL_LONG(&_85$$8, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_86$$8, "str_repeat", &_9, 67, &space, &_85$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_86$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_87$$25);
		zephir_create_array(&_87$$25, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_89$$25);
		ZVAL_STRING(&_89$$25, "int");
		ZEPHIR_CALL_METHOD(&_88$$25, this_ptr, "getstyle", &_3, 0, &_89$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_87$$25, SL(":style"), &_88$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_87$$25, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_89$$25);
		ZVAL_STRING(&_89$$25, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_88$$25, "strtr", &_4, 85, &_89$$25, &_87$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_88$$25);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_90, "is_float", NULL, 92, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_90)) {
		ZEPHIR_INIT_VAR(&_91$$26);
		zephir_create_array(&_91$$26, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_93$$26);
		ZVAL_STRING(&_93$$26, "float");
		ZEPHIR_CALL_METHOD(&_92$$26, this_ptr, "getstyle", &_3, 0, &_93$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_91$$26, SL(":style"), &_92$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_91$$26, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_93$$26);
		ZVAL_STRING(&_93$$26, "<b style=':style'>float</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_92$$26, "strtr", &_4, 85, &_93$$26, &_91$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_92$$26);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_94$$27);
		zephir_create_array(&_94$$27, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_96$$27);
		ZVAL_STRING(&_96$$27, "num");
		ZEPHIR_CALL_METHOD(&_95$$27, this_ptr, "getstyle", &_3, 0, &_96$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_94$$27, SL(":style"), &_95$$27, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_94$$27, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_94$$27, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_96$$27);
		ZVAL_STRING(&_96$$27, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_95$$27, "strtr", &_4, 85, &_96$$27, &_94$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_95$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_97$$28);
		zephir_create_array(&_97$$28, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_99$$28);
		ZVAL_STRING(&_99$$28, "str");
		ZEPHIR_CALL_METHOD(&_98$$28, this_ptr, "getstyle", &_3, 0, &_99$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_97$$28, SL(":style"), &_98$$28, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_97$$28, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_100$$28, 4);
		ZEPHIR_INIT_NVAR(&_99$$28);
		ZVAL_STRING(&_99$$28, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_98$$28, "htmlentities", NULL, 93, variable, &_100$$28, &_99$$28);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_101$$28, "nl2br", NULL, 94, &_98$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_97$$28, SL(":var"), &_101$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_99$$28);
		ZVAL_STRING(&_99$$28, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_101$$28, "strtr", &_4, 85, &_99$$28, &_97$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_101$$28);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_102$$29);
		zephir_create_array(&_102$$29, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_104$$29);
		ZVAL_STRING(&_104$$29, "bool");
		ZEPHIR_CALL_METHOD(&_103$$29, this_ptr, "getstyle", &_3, 0, &_104$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_102$$29, SL(":style"), &_103$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_105$$29);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_105$$29);
			ZVAL_STRING(&_105$$29, "true");
		} else {
			ZEPHIR_INIT_NVAR(&_105$$29);
			ZVAL_STRING(&_105$$29, "false");
		}
		zephir_array_update_string(&_102$$29, SL(":var"), &_105$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_104$$29);
		ZVAL_STRING(&_104$$29, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_103$$29, "strtr", &_4, 85, &_104$$29, &_102$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_103$$29);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_106$$30);
		zephir_create_array(&_106$$30, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_108$$30);
		ZVAL_STRING(&_108$$30, "null");
		ZEPHIR_CALL_METHOD(&_107$$30, this_ptr, "getstyle", &_3, 0, &_108$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_106$$30, SL(":style"), &_107$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_108$$30);
		ZVAL_STRING(&_108$$30, "<b style=':style'>null</b>");
		ZEPHIR_CALL_FUNCTION(&_107$$30, "strtr", &_4, 85, &_108$$30, &_106$$30);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_107$$30);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_109);
	zephir_create_array(&_109, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_111);
	ZVAL_STRING(&_111, "other");
	ZEPHIR_CALL_METHOD(&_110, this_ptr, "getstyle", &_3, 0, &_111);
	zephir_check_call_status();
	zephir_array_update_string(&_109, SL(":style"), &_110, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_109, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_111);
	ZVAL_STRING(&_111, "(<span style=':style'>:var</span>)");
	ZEPHIR_CALL_FUNCTION(&_110, "strtr", &_4, 85, &_111, &_109);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_110);
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
	zephir_is_iterable(&_0, 0, "ice/dump.zep", 310);
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

zend_object *zephir_init_properties_Ice_Dump(zend_class_entry *class_type TSRMLS_DC) {

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

