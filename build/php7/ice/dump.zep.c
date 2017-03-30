
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

PHP_METHOD(Ice_Dump, getPlain) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "plain");

}

PHP_METHOD(Ice_Dump, setPlain) {

	zval *plain, plain_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&plain_sub);

	zephir_fetch_params(0, 1, 0, &plain);



	zephir_update_property_zval(this_ptr, SL("plain"), plain);

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
 * @param mixed styles
 */
PHP_METHOD(Ice_Dump, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *detailed_param = NULL, *styles = NULL, styles_sub, __$true, __$false;
	zend_bool detailed;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&styles_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &detailed_param, &styles);

	if (!detailed_param) {
		detailed = 0;
	} else {
		detailed = zephir_get_boolval(detailed_param);
	}
	if (!styles) {
		styles = &styles_sub;
		ZEPHIR_INIT_VAR(styles);
		array_init(styles);
	}


	if (Z_TYPE_P(styles) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, styles);
		zephir_check_call_status();
	} else if (((Z_TYPE_P(styles) == IS_TRUE || Z_TYPE_P(styles) == IS_FALSE) == 1)) {
		zephir_update_property_zval(this_ptr, SL("plain"), styles);
	}
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

	zval _1;
	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "vars");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_get_args(&_1);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &_1);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 101);
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

	zend_bool _18$$5, _19$$5, _20$$5, _41$$8;
	zend_string *_9$$4, *_48$$11;
	zend_ulong _8$$4, _47$$11;
	zval _139, _2$$4, _14$$5, _30$$8, _77$$8, _37$$9, _52$$12, _67$$14, _88$$23, _95$$24, _105$$25, _111$$26, _116$$27, _121$$28, _128$$29, _134$$30;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_11 = NULL, *_24 = NULL, *_34 = NULL, *_59 = NULL, *_63 = NULL, *_69 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, *name = NULL, name_sub, *tab = NULL, tab_sub, __$null, key, value, output, space, type, attr, _108, _137, _138, _140, _141, _0$$4, _1$$4, _3$$4, _4$$4, *_7$$4, _26$$4, _27$$4, _10$$5, _12$$5, _13$$5, _15$$5, _16$$5, _17$$5, _21$$7, _22$$7, _23$$7, _25$$7, className$$8, _28$$8, _29$$8, _31$$8, _32$$8, _33$$8, _40$$8, _42$$8, _74$$8, _75$$8, _76$$8, _78$$8, _79$$8, _80$$8, _101$$8, _102$$8, _35$$9, _36$$9, _38$$9, _39$$9, _43$$10, _44$$10, _45$$11, *_46$$11, _49$$12, _50$$12, _51$$12, _53$$12, _54$$12, _55$$12, _56$$12, _57$$12, _58$$12, _60$$14, _61$$14, _62$$14, _65$$14, _66$$14, _68$$14, _70$$14, _71$$14, _72$$14, _73$$14, _64$$17, _81$$19, _82$$19, *_83$$20, _99$$20, _100$$20, _84$$21, _85$$23, _86$$23, _87$$23, _89$$23, _90$$23, _91$$23, _92$$24, _93$$24, _94$$24, _96$$24, _97$$24, _98$$24, _103$$25, _104$$25, _106$$25, _107$$25, _109$$26, _110$$26, _112$$26, _113$$26, _114$$27, _115$$27, _117$$27, _118$$27, _119$$28, _120$$28, _122$$28, _123$$28, _124$$28, _125$$28, _126$$29, _127$$29, _129$$29, _130$$29, _131$$29, _132$$30, _133$$30, _135$$30, _136$$30;
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
	ZVAL_UNDEF(&_108);
	ZVAL_UNDEF(&_137);
	ZVAL_UNDEF(&_138);
	ZVAL_UNDEF(&_140);
	ZVAL_UNDEF(&_141);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_27$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&className$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_40$$8);
	ZVAL_UNDEF(&_42$$8);
	ZVAL_UNDEF(&_74$$8);
	ZVAL_UNDEF(&_75$$8);
	ZVAL_UNDEF(&_76$$8);
	ZVAL_UNDEF(&_78$$8);
	ZVAL_UNDEF(&_79$$8);
	ZVAL_UNDEF(&_80$$8);
	ZVAL_UNDEF(&_101$$8);
	ZVAL_UNDEF(&_102$$8);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_49$$12);
	ZVAL_UNDEF(&_50$$12);
	ZVAL_UNDEF(&_51$$12);
	ZVAL_UNDEF(&_53$$12);
	ZVAL_UNDEF(&_54$$12);
	ZVAL_UNDEF(&_55$$12);
	ZVAL_UNDEF(&_56$$12);
	ZVAL_UNDEF(&_57$$12);
	ZVAL_UNDEF(&_58$$12);
	ZVAL_UNDEF(&_60$$14);
	ZVAL_UNDEF(&_61$$14);
	ZVAL_UNDEF(&_62$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_66$$14);
	ZVAL_UNDEF(&_68$$14);
	ZVAL_UNDEF(&_70$$14);
	ZVAL_UNDEF(&_71$$14);
	ZVAL_UNDEF(&_72$$14);
	ZVAL_UNDEF(&_73$$14);
	ZVAL_UNDEF(&_64$$17);
	ZVAL_UNDEF(&_81$$19);
	ZVAL_UNDEF(&_82$$19);
	ZVAL_UNDEF(&_99$$20);
	ZVAL_UNDEF(&_100$$20);
	ZVAL_UNDEF(&_84$$21);
	ZVAL_UNDEF(&_85$$23);
	ZVAL_UNDEF(&_86$$23);
	ZVAL_UNDEF(&_87$$23);
	ZVAL_UNDEF(&_89$$23);
	ZVAL_UNDEF(&_90$$23);
	ZVAL_UNDEF(&_91$$23);
	ZVAL_UNDEF(&_92$$24);
	ZVAL_UNDEF(&_93$$24);
	ZVAL_UNDEF(&_94$$24);
	ZVAL_UNDEF(&_96$$24);
	ZVAL_UNDEF(&_97$$24);
	ZVAL_UNDEF(&_98$$24);
	ZVAL_UNDEF(&_103$$25);
	ZVAL_UNDEF(&_104$$25);
	ZVAL_UNDEF(&_106$$25);
	ZVAL_UNDEF(&_107$$25);
	ZVAL_UNDEF(&_109$$26);
	ZVAL_UNDEF(&_110$$26);
	ZVAL_UNDEF(&_112$$26);
	ZVAL_UNDEF(&_113$$26);
	ZVAL_UNDEF(&_114$$27);
	ZVAL_UNDEF(&_115$$27);
	ZVAL_UNDEF(&_117$$27);
	ZVAL_UNDEF(&_118$$27);
	ZVAL_UNDEF(&_119$$28);
	ZVAL_UNDEF(&_120$$28);
	ZVAL_UNDEF(&_122$$28);
	ZVAL_UNDEF(&_123$$28);
	ZVAL_UNDEF(&_124$$28);
	ZVAL_UNDEF(&_125$$28);
	ZVAL_UNDEF(&_126$$29);
	ZVAL_UNDEF(&_127$$29);
	ZVAL_UNDEF(&_129$$29);
	ZVAL_UNDEF(&_130$$29);
	ZVAL_UNDEF(&_131$$29);
	ZVAL_UNDEF(&_132$$30);
	ZVAL_UNDEF(&_133$$30);
	ZVAL_UNDEF(&_135$$30);
	ZVAL_UNDEF(&_136$$30);
	ZVAL_UNDEF(&_139);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_77$$8);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_88$$23);
	ZVAL_UNDEF(&_95$$24);
	ZVAL_UNDEF(&_105$$25);
	ZVAL_UNDEF(&_111$$26);
	ZVAL_UNDEF(&_116$$27);
	ZVAL_UNDEF(&_121$$28);
	ZVAL_UNDEF(&_128$$29);
	ZVAL_UNDEF(&_134$$30);

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
		zephir_read_property(&_1$$4, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_1$$4)) {
			ZEPHIR_INIT_NVAR(&_0$$4);
			ZVAL_STRING(&_0$$4, "array (:count) (\n");
		} else {
			ZEPHIR_INIT_NVAR(&_0$$4);
			ZVAL_STRING(&_0$$4, "<b style =':style'>array</b> (<span style =':style'>:count</span>) (\n");
		}
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "arr");
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getstyle", &_5, 0, &_4$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_2$$4, SL(":style"), &_3$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_2$$4, SL(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_3$$4, "strtr", &_6, 77, &_0$$4, &_2$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_3$$4 TSRMLS_CC);
		zephir_is_iterable(variable, 0, "ice/dump.zep", 169);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(variable), _8$$4, _9$$4, _7$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_9$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _9$$4);
			} else {
				ZVAL_LONG(&key, _8$$4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _7$$4);
			ZEPHIR_CALL_FUNCTION(&_10$$5, "str_repeat", &_11, 59, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_12$$5);
			zephir_read_property(&_13$$5, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_13$$5)) {
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "[:key] => ");
			} else {
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "[<span style=':style'>:key</span>] => ");
			}
			ZEPHIR_INIT_NVAR(&_14$$5);
			zephir_create_array(&_14$$5, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_16$$5);
			ZVAL_STRING(&_16$$5, "arr");
			ZEPHIR_CALL_METHOD(&_15$$5, this_ptr, "getstyle", &_5, 0, &_16$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_14$$5, SL(":style"), &_15$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_15$$5, "strtr", &_6, 77, &_12$$5, &_14$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_17$$5);
			ZEPHIR_CONCAT_VV(&_17$$5, &_10$$5, &_15$$5);
			zephir_concat_self(&output, &_17$$5 TSRMLS_CC);
			_18$$5 = ZEPHIR_IS_LONG(tab, 1);
			if (_18$$5) {
				_18$$5 = !ZEPHIR_IS_STRING(name, "");
			}
			_19$$5 = _18$$5;
			if (_19$$5) {
				_19$$5 = !(Z_TYPE_P(&key) == IS_LONG);
			}
			_20$$5 = _19$$5;
			if (_20$$5) {
				_20$$5 = ZEPHIR_IS_EQUAL(name, &key);
			}
			if (_20$$5) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(&_22$$7);
				ZVAL_STRING(&_22$$7, "");
				ZVAL_LONG(&_23$$7, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_21$$7, this_ptr, "output", &_24, 78, &value, &_22$$7, &_23$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_25$$7);
				ZEPHIR_CONCAT_VS(&_25$$7, &_21$$7, "\n");
				zephir_concat_self(&output, &_25$$7 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_26$$4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_27$$4, "str_repeat", &_11, 59, &space, &_26$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_27$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&className$$8);
		zephir_get_class(&className$$8, variable, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_28$$8);
		zephir_read_property(&_29$$8, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_29$$8)) {
			ZEPHIR_INIT_NVAR(&_28$$8);
			ZVAL_STRING(&_28$$8, "object :class");
		} else {
			ZEPHIR_INIT_NVAR(&_28$$8);
			ZVAL_STRING(&_28$$8, "<b style=':style'>object</b> :class");
		}
		ZEPHIR_INIT_VAR(&_30$$8);
		zephir_create_array(&_30$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_32$$8);
		ZVAL_STRING(&_32$$8, "obj");
		ZEPHIR_CALL_METHOD(&_31$$8, this_ptr, "getstyle", &_5, 0, &_32$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_30$$8, SL(":style"), &_31$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_30$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_31$$8, "strtr", &_6, 77, &_28$$8, &_30$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, &_31$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_33$$8, "get_parent_class", &_34, 79, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_33$$8)) {
			ZEPHIR_INIT_VAR(&_35$$9);
			zephir_read_property(&_36$$9, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_36$$9)) {
				ZEPHIR_INIT_NVAR(&_35$$9);
				ZVAL_STRING(&_35$$9, " extends :parent");
			} else {
				ZEPHIR_INIT_NVAR(&_35$$9);
				ZVAL_STRING(&_35$$9, " <b style=':style'>extends</b> :parent");
			}
			ZEPHIR_INIT_VAR(&_37$$9);
			zephir_create_array(&_37$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_39$$9);
			ZVAL_STRING(&_39$$9, "obj");
			ZEPHIR_CALL_METHOD(&_38$$9, this_ptr, "getstyle", &_5, 0, &_39$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_37$$9, SL(":style"), &_38$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_38$$9, "get_parent_class", &_34, 79, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_37$$9, SL(":parent"), &_38$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_38$$9, "strtr", &_6, 77, &_35$$9, &_37$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, &_38$$9 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		zephir_read_property(&_40$$8, this_ptr, SL("skipDi"), PH_NOISY_CC | PH_READONLY);
		_41$$8 = zephir_is_true(&_40$$8);
		if (_41$$8) {
			_41$$8 = zephir_instance_of_ev(variable, ice_di_ce TSRMLS_CC);
		}
		zephir_read_property(&_42$$8, this_ptr, SL("detailed"), PH_NOISY_CC | PH_READONLY);
		if (_41$$8) {
			ZEPHIR_CALL_FUNCTION(&_43$$10, "str_repeat", &_11, 59, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_44$$10);
			ZEPHIR_CONCAT_VS(&_44$$10, &_43$$10, "[skipped]\n");
			zephir_concat_self(&output, &_44$$10 TSRMLS_CC);
		} else if (!(zephir_is_true(&_42$$8))) {
			ZEPHIR_CALL_FUNCTION(&_45$$11, "get_object_vars", NULL, 80, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_45$$11, 0, "ice/dump.zep", 192);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_45$$11), _47$$11, _48$$11, _46$$11)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_48$$11 != NULL) { 
					ZVAL_STR_COPY(&key, _48$$11);
				} else {
					ZVAL_LONG(&key, _47$$11);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _46$$11);
				ZEPHIR_CALL_FUNCTION(&_49$$12, "str_repeat", &_11, 59, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_50$$12);
				zephir_read_property(&_51$$12, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_51$$12)) {
					ZEPHIR_INIT_NVAR(&_50$$12);
					ZVAL_STRING(&_50$$12, "->:key (:type) = ");
				} else {
					ZEPHIR_INIT_NVAR(&_50$$12);
					ZVAL_STRING(&_50$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				}
				ZEPHIR_INIT_NVAR(&_52$$12);
				zephir_create_array(&_52$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_54$$12);
				ZVAL_STRING(&_54$$12, "obj");
				ZEPHIR_CALL_METHOD(&_53$$12, this_ptr, "getstyle", &_5, 0, &_54$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_52$$12, SL(":style"), &_53$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_52$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(&_52$$12, SL(":type"), SL("public"));
				ZEPHIR_CALL_FUNCTION(&_53$$12, "strtr", &_6, 77, &_50$$12, &_52$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_55$$12);
				ZEPHIR_CONCAT_VV(&_55$$12, &_49$$12, &_53$$12);
				zephir_concat_self(&output, &_55$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_54$$12);
				ZVAL_STRING(&_54$$12, "");
				ZVAL_LONG(&_57$$12, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_56$$12, this_ptr, "output", &_24, 78, &value, &_54$$12, &_57$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_58$$12);
				ZEPHIR_CONCAT_VS(&_58$$12, &_56$$12, "\n");
				zephir_concat_self(&output, &_58$$12 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			do {
				ZEPHIR_MAKE_REF(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_59, 81, variable);
				ZEPHIR_UNREF(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(&attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&key);
				zephir_array_fetch_string(&key, &attr, SL("key"), PH_NOISY, "ice/dump.zep", 200 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_string(&value, &attr, SL("value"), PH_NOISY, "ice/dump.zep", 201 TSRMLS_CC);
				if (!(zephir_is_true(&key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_60$$14);
				ZVAL_LONG(&_61$$14, 0);
				ZEPHIR_CALL_FUNCTION(&_62$$14, "chr", &_63, 58, &_61$$14);
				zephir_check_call_status();
				zephir_fast_explode(&_60$$14, &_62$$14, &key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(&key, &_60$$14);
				ZEPHIR_INIT_NVAR(&type);
				ZVAL_STRING(&type, "public");
				if (zephir_array_isset_long(&key, 1)) {
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_STRING(&type, "private");
					zephir_array_fetch_long(&_64$$17, &key, 1, PH_NOISY | PH_READONLY, "ice/dump.zep", 214 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(&_64$$17, "*")) {
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "protected");
					}
				}
				ZEPHIR_CALL_FUNCTION(&_65$$14, "str_repeat", &_11, 59, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_66$$14);
				zephir_read_property(&_61$$14, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_61$$14)) {
					ZEPHIR_INIT_NVAR(&_66$$14);
					ZVAL_STRING(&_66$$14, "->:key (:type) = ");
				} else {
					ZEPHIR_INIT_NVAR(&_66$$14);
					ZVAL_STRING(&_66$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				}
				ZEPHIR_INIT_NVAR(&_67$$14);
				zephir_create_array(&_67$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_60$$14);
				ZVAL_STRING(&_60$$14, "obj");
				ZEPHIR_CALL_METHOD(&_68$$14, this_ptr, "getstyle", &_5, 0, &_60$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_67$$14, SL(":style"), &_68$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_MAKE_REF(&key);
				ZEPHIR_CALL_FUNCTION(&_68$$14, "end", &_69, 82, &key);
				ZEPHIR_UNREF(&key);
				zephir_check_call_status();
				zephir_array_update_string(&_67$$14, SL(":key"), &_68$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_67$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_68$$14, "strtr", &_6, 77, &_66$$14, &_67$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_70$$14);
				ZEPHIR_CONCAT_VV(&_70$$14, &_65$$14, &_68$$14);
				zephir_concat_self(&output, &_70$$14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_60$$14);
				ZVAL_STRING(&_60$$14, "");
				ZVAL_LONG(&_72$$14, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_71$$14, this_ptr, "output", &_24, 78, &value, &_60$$14, &_72$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_73$$14);
				ZEPHIR_CONCAT_VS(&_73$$14, &_71$$14, "\n");
				zephir_concat_self(&output, &_73$$14 TSRMLS_CC);
			} while (zephir_is_true(&attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 83, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_74$$8, "str_repeat", &_11, 59, &space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_75$$8);
		zephir_read_property(&_76$$8, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_76$$8)) {
			ZEPHIR_INIT_NVAR(&_75$$8);
			ZVAL_STRING(&_75$$8, ":class methods: (:count) (\n");
		} else {
			ZEPHIR_INIT_NVAR(&_75$$8);
			ZVAL_STRING(&_75$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n");
		}
		ZEPHIR_INIT_VAR(&_77$$8);
		zephir_create_array(&_77$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_32$$8);
		ZVAL_STRING(&_32$$8, "obj");
		ZEPHIR_CALL_METHOD(&_78$$8, this_ptr, "getstyle", &_5, 0, &_32$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_77$$8, SL(":style"), &_78$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_77$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_77$$8, SL(":count"), zephir_fast_count_int(&attr TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_78$$8, "strtr", &_6, 77, &_75$$8, &_77$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_79$$8);
		ZEPHIR_CONCAT_VV(&_79$$8, &_74$$8, &_78$$8);
		zephir_concat_self(&output, &_79$$8 TSRMLS_CC);
		zephir_read_property(&_80$$8, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&className$$8, &_80$$8 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_81$$19, "str_repeat", &_11, 59, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_82$$19);
			ZEPHIR_CONCAT_VS(&_82$$19, &_81$$19, "[already listed]\n");
			zephir_concat_self(&output, &_82$$19 TSRMLS_CC);
		} else {
			zephir_is_iterable(&attr, 0, "ice/dump.zep", 239);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _83$$20)
			{
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _83$$20);
				zephir_read_property(&_84$$21, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_fast_in_array(&className$$8, &_84$$21 TSRMLS_CC))) {
					zephir_update_property_array_append(this_ptr, SL("methods"), &className$$8 TSRMLS_CC);
				}
				if (ZEPHIR_IS_STRING(&value, "__construct")) {
					ZVAL_LONG(&_85$$23, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_86$$23, "str_repeat", &_11, 59, &space, &_85$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_87$$23);
					zephir_read_property(&_85$$23, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_85$$23)) {
						ZEPHIR_INIT_NVAR(&_87$$23);
						ZVAL_STRING(&_87$$23, "->:method(); [constructor]\n");
					} else {
						ZEPHIR_INIT_NVAR(&_87$$23);
						ZVAL_STRING(&_87$$23, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n");
					}
					ZEPHIR_INIT_NVAR(&_88$$23);
					zephir_create_array(&_88$$23, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_90$$23);
					ZVAL_STRING(&_90$$23, "obj");
					ZEPHIR_CALL_METHOD(&_89$$23, this_ptr, "getstyle", &_5, 0, &_90$$23);
					zephir_check_call_status();
					zephir_array_update_string(&_88$$23, SL(":style"), &_89$$23, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_88$$23, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_89$$23, "strtr", &_6, 77, &_87$$23, &_88$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_91$$23);
					ZEPHIR_CONCAT_VV(&_91$$23, &_86$$23, &_89$$23);
					zephir_concat_self(&output, &_91$$23 TSRMLS_CC);
				} else {
					ZVAL_LONG(&_92$$24, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_93$$24, "str_repeat", &_11, 59, &space, &_92$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_94$$24);
					zephir_read_property(&_92$$24, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_92$$24)) {
						ZEPHIR_INIT_NVAR(&_94$$24);
						ZVAL_STRING(&_94$$24, "->:method();\n");
					} else {
						ZEPHIR_INIT_NVAR(&_94$$24);
						ZVAL_STRING(&_94$$24, "-><span style=':style'>:method</span>();\n");
					}
					ZEPHIR_INIT_NVAR(&_95$$24);
					zephir_create_array(&_95$$24, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_97$$24);
					ZVAL_STRING(&_97$$24, "obj");
					ZEPHIR_CALL_METHOD(&_96$$24, this_ptr, "getstyle", &_5, 0, &_97$$24);
					zephir_check_call_status();
					zephir_array_update_string(&_95$$24, SL(":style"), &_96$$24, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_95$$24, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_96$$24, "strtr", &_6, 77, &_94$$24, &_95$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_98$$24);
					ZEPHIR_CONCAT_VV(&_98$$24, &_93$$24, &_96$$24);
					zephir_concat_self(&output, &_98$$24 TSRMLS_CC);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_CALL_FUNCTION(&_99$$20, "str_repeat", &_11, 59, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_100$$20);
			ZEPHIR_CONCAT_VS(&_100$$20, &_99$$20, ")\n");
			zephir_concat_self(&output, &_100$$20 TSRMLS_CC);
		}
		ZVAL_LONG(&_101$$8, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_102$$8, "str_repeat", &_11, 59, &space, &_101$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_102$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_103$$25);
		zephir_read_property(&_104$$25, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_104$$25)) {
			ZEPHIR_INIT_NVAR(&_103$$25);
			ZVAL_STRING(&_103$$25, "integer (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_103$$25);
			ZVAL_STRING(&_103$$25, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_105$$25);
		zephir_create_array(&_105$$25, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_107$$25);
		ZVAL_STRING(&_107$$25, "int");
		ZEPHIR_CALL_METHOD(&_106$$25, this_ptr, "getstyle", &_5, 0, &_107$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_105$$25, SL(":style"), &_106$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_105$$25, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_106$$25, "strtr", &_6, 77, &_103$$25, &_105$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_106$$25);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_108, "is_float", NULL, 84, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_108)) {
		ZEPHIR_INIT_VAR(&_109$$26);
		zephir_read_property(&_110$$26, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_110$$26)) {
			ZEPHIR_INIT_NVAR(&_109$$26);
			ZVAL_STRING(&_109$$26, "float (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_109$$26);
			ZVAL_STRING(&_109$$26, "<b style=':style'>float</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_111$$26);
		zephir_create_array(&_111$$26, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_113$$26);
		ZVAL_STRING(&_113$$26, "float");
		ZEPHIR_CALL_METHOD(&_112$$26, this_ptr, "getstyle", &_5, 0, &_113$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_111$$26, SL(":style"), &_112$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_111$$26, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_112$$26, "strtr", &_6, 77, &_109$$26, &_111$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_112$$26);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_114$$27);
		zephir_read_property(&_115$$27, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_115$$27)) {
			ZEPHIR_INIT_NVAR(&_114$$27);
			ZVAL_STRING(&_114$$27, "numeric string (:length) \":var\"");
		} else {
			ZEPHIR_INIT_NVAR(&_114$$27);
			ZVAL_STRING(&_114$$27, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		}
		ZEPHIR_INIT_VAR(&_116$$27);
		zephir_create_array(&_116$$27, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_118$$27);
		ZVAL_STRING(&_118$$27, "num");
		ZEPHIR_CALL_METHOD(&_117$$27, this_ptr, "getstyle", &_5, 0, &_118$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_116$$27, SL(":style"), &_117$$27, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_116$$27, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_116$$27, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_117$$27, "strtr", &_6, 77, &_114$$27, &_116$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_117$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_119$$28);
		zephir_read_property(&_120$$28, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_120$$28)) {
			ZEPHIR_INIT_NVAR(&_119$$28);
			ZVAL_STRING(&_119$$28, "string (:length) \":var\"");
		} else {
			ZEPHIR_INIT_NVAR(&_119$$28);
			ZVAL_STRING(&_119$$28, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		}
		ZEPHIR_INIT_VAR(&_121$$28);
		zephir_create_array(&_121$$28, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_123$$28);
		ZVAL_STRING(&_123$$28, "str");
		ZEPHIR_CALL_METHOD(&_122$$28, this_ptr, "getstyle", &_5, 0, &_123$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_121$$28, SL(":style"), &_122$$28, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_121$$28, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_124$$28, 4);
		ZEPHIR_INIT_NVAR(&_123$$28);
		ZVAL_STRING(&_123$$28, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_122$$28, "htmlentities", NULL, 85, variable, &_124$$28, &_123$$28);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_125$$28, "nl2br", NULL, 86, &_122$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_121$$28, SL(":var"), &_125$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_125$$28, "strtr", &_6, 77, &_119$$28, &_121$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_125$$28);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_126$$29);
		zephir_read_property(&_127$$29, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_127$$29)) {
			ZEPHIR_INIT_NVAR(&_126$$29);
			ZVAL_STRING(&_126$$29, "boolean (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_126$$29);
			ZVAL_STRING(&_126$$29, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_128$$29);
		zephir_create_array(&_128$$29, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_130$$29);
		ZVAL_STRING(&_130$$29, "bool");
		ZEPHIR_CALL_METHOD(&_129$$29, this_ptr, "getstyle", &_5, 0, &_130$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_128$$29, SL(":style"), &_129$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_131$$29);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_131$$29);
			ZVAL_STRING(&_131$$29, "true");
		} else {
			ZEPHIR_INIT_NVAR(&_131$$29);
			ZVAL_STRING(&_131$$29, "false");
		}
		zephir_array_update_string(&_128$$29, SL(":var"), &_131$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_129$$29, "strtr", &_6, 77, &_126$$29, &_128$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_129$$29);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_132$$30);
		zephir_read_property(&_133$$30, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_133$$30)) {
			ZEPHIR_INIT_NVAR(&_132$$30);
			ZVAL_STRING(&_132$$30, "null");
		} else {
			ZEPHIR_INIT_NVAR(&_132$$30);
			ZVAL_STRING(&_132$$30, "<b style=':style'>null</b>");
		}
		ZEPHIR_INIT_VAR(&_134$$30);
		zephir_create_array(&_134$$30, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_136$$30);
		ZVAL_STRING(&_136$$30, "null");
		ZEPHIR_CALL_METHOD(&_135$$30, this_ptr, "getstyle", &_5, 0, &_136$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_134$$30, SL(":style"), &_135$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_135$$30, "strtr", &_6, 77, &_132$$30, &_134$$30);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_135$$30);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_137);
	zephir_read_property(&_138, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_138)) {
		ZEPHIR_INIT_NVAR(&_137);
		ZVAL_STRING(&_137, "(:var)");
	} else {
		ZEPHIR_INIT_NVAR(&_137);
		ZVAL_STRING(&_137, "(<span style=':style'>:var</span>)");
	}
	ZEPHIR_INIT_VAR(&_139);
	zephir_create_array(&_139, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_141);
	ZVAL_STRING(&_141, "other");
	ZEPHIR_CALL_METHOD(&_140, this_ptr, "getstyle", &_5, 0, &_141);
	zephir_check_call_status();
	zephir_array_update_string(&_139, SL(":style"), &_140, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_139, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_140, "strtr", &_6, 77, &_137, &_139);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_140);
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

	zval _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *variable, variable_sub, *name_param = NULL, _0, _1, _3, _4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, ":output");
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "<pre style=':style'>:output</pre>");
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "pre");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getstyle", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL(":style"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "output", NULL, 0, variable, &name);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL(":output"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 77, &_0, &_2);
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
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_is_iterable(&_0, 0, "ice/dump.zep", 312);
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

