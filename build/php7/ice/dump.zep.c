
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "detailed");

}

PHP_METHOD(Ice_Dump, setDetailed) {

	zval *detailed, detailed_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&detailed_sub);

	zephir_fetch_params(0, 1, 0, &detailed);



	zephir_update_property_zval(this_ptr, SL("detailed"), detailed);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dump, getPlain) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "plain");

}

PHP_METHOD(Ice_Dump, setPlain) {

	zval *plain, plain_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&plain_sub);

	zephir_fetch_params(0, 1, 0, &plain);



	zephir_update_property_zval(this_ptr, SL("plain"), plain);
	RETURN_THISW();

}

PHP_METHOD(Ice_Dump, getSkip) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "skip");

}

PHP_METHOD(Ice_Dump, setSkip) {

	zval *skip, skip_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&skip_sub);

	zephir_fetch_params(0, 1, 0, &skip);



	zephir_update_property_zval(this_ptr, SL("skip"), skip);
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
	zval *detailed_param = NULL, *styles = NULL, styles_sub, __$true, __$false;
	zend_bool detailed;
	zval *this_ptr = getThis();

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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&style);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("styles"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&style, &_0, &type, 1 TSRMLS_CC)) {
		RETURN_CTOR(&style);
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
	zval *this_ptr = getThis();

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
	zephir_create_array(&defaultStyles, 13, 0 TSRMLS_CC);
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
	add_assoc_stringl_ex(&defaultStyles, SL("line"), SL("highlight-block"));
	add_assoc_stringl_ex(&defaultStyles, SL("lines"), SL(""));
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &defaultStyles, &styles TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("styles"), &_0);
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
	zval name;
	zval *variable, variable_sub, *name_param = NULL;
	zval *this_ptr = getThis();

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

	zend_class_entry *_64$$13;
	zend_bool _20$$5, _21$$5, _22$$5;
	zend_string *_11$$4, *_51$$11;
	zend_ulong _10$$4, _50$$11;
	zval _155, _4$$4, _16$$5, _32$$8, _86$$8, _39$$9, _55$$12, _74$$14, _101$$21, _110$$22, _121$$23, _127$$24, _132$$25, _137$$26, _144$$27, _150$$28;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_13 = NULL, *_26 = NULL, *_36 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, *name = NULL, name_sub, *tab = NULL, tab_sub, __$null, key, value, output, space, type, attr, _124, _153, _154, _156, _157, _0$$4, _1$$4, _2$$4, _3$$4, _5$$4, _6$$4, *_9$$4, _28$$4, _29$$4, _12$$5, _14$$5, _15$$5, _17$$5, _18$$5, _19$$5, _23$$7, _24$$7, _25$$7, _27$$7, className$$8, _30$$8, _31$$8, _33$$8, _34$$8, _35$$8, _42$$8, _43$$8, _44$$8, _81$$8, _82$$8, _83$$8, _84$$8, _85$$8, _87$$8, _88$$8, _89$$8, _90$$8, _117$$8, _118$$8, _37$$9, _38$$9, _40$$9, _41$$9, _45$$10, _46$$10, _47$$10, _48$$11, *_49$$11, _52$$12, _53$$12, _54$$12, _56$$12, _57$$12, _58$$12, _59$$12, _60$$12, _61$$12, reflect$$13, _62$$13, _63$$13, _65$$13, *_66$$13, _67$$14, _69$$14, _71$$14, _72$$14, _73$$14, _75$$14, _76$$14, _77$$14, _78$$14, _79$$14, _80$$14, _68$$15, _70$$16, _91$$17, _92$$17, _93$$17, *_94$$18, _114$$18, _115$$18, _116$$18, _95$$19, _96$$21, _97$$21, _98$$21, _99$$21, _100$$21, _102$$21, _103$$21, _104$$21, _105$$22, _106$$22, _107$$22, _108$$22, _109$$22, _111$$22, _112$$22, _113$$22, _119$$23, _120$$23, _122$$23, _123$$23, _125$$24, _126$$24, _128$$24, _129$$24, _130$$25, _131$$25, _133$$25, _134$$25, _135$$26, _136$$26, _138$$26, _139$$26, _140$$26, _141$$26, _142$$27, _143$$27, _145$$27, _146$$27, _147$$27, _148$$28, _149$$28, _151$$28, _152$$28;
	zval *this_ptr = getThis();

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
	ZVAL_UNDEF(&_124);
	ZVAL_UNDEF(&_153);
	ZVAL_UNDEF(&_154);
	ZVAL_UNDEF(&_156);
	ZVAL_UNDEF(&_157);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_28$$4);
	ZVAL_UNDEF(&_29$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&className$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_42$$8);
	ZVAL_UNDEF(&_43$$8);
	ZVAL_UNDEF(&_44$$8);
	ZVAL_UNDEF(&_81$$8);
	ZVAL_UNDEF(&_82$$8);
	ZVAL_UNDEF(&_83$$8);
	ZVAL_UNDEF(&_84$$8);
	ZVAL_UNDEF(&_85$$8);
	ZVAL_UNDEF(&_87$$8);
	ZVAL_UNDEF(&_88$$8);
	ZVAL_UNDEF(&_89$$8);
	ZVAL_UNDEF(&_90$$8);
	ZVAL_UNDEF(&_117$$8);
	ZVAL_UNDEF(&_118$$8);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_47$$10);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_53$$12);
	ZVAL_UNDEF(&_54$$12);
	ZVAL_UNDEF(&_56$$12);
	ZVAL_UNDEF(&_57$$12);
	ZVAL_UNDEF(&_58$$12);
	ZVAL_UNDEF(&_59$$12);
	ZVAL_UNDEF(&_60$$12);
	ZVAL_UNDEF(&_61$$12);
	ZVAL_UNDEF(&reflect$$13);
	ZVAL_UNDEF(&_62$$13);
	ZVAL_UNDEF(&_63$$13);
	ZVAL_UNDEF(&_65$$13);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_69$$14);
	ZVAL_UNDEF(&_71$$14);
	ZVAL_UNDEF(&_72$$14);
	ZVAL_UNDEF(&_73$$14);
	ZVAL_UNDEF(&_75$$14);
	ZVAL_UNDEF(&_76$$14);
	ZVAL_UNDEF(&_77$$14);
	ZVAL_UNDEF(&_78$$14);
	ZVAL_UNDEF(&_79$$14);
	ZVAL_UNDEF(&_80$$14);
	ZVAL_UNDEF(&_68$$15);
	ZVAL_UNDEF(&_70$$16);
	ZVAL_UNDEF(&_91$$17);
	ZVAL_UNDEF(&_92$$17);
	ZVAL_UNDEF(&_93$$17);
	ZVAL_UNDEF(&_114$$18);
	ZVAL_UNDEF(&_115$$18);
	ZVAL_UNDEF(&_116$$18);
	ZVAL_UNDEF(&_95$$19);
	ZVAL_UNDEF(&_96$$21);
	ZVAL_UNDEF(&_97$$21);
	ZVAL_UNDEF(&_98$$21);
	ZVAL_UNDEF(&_99$$21);
	ZVAL_UNDEF(&_100$$21);
	ZVAL_UNDEF(&_102$$21);
	ZVAL_UNDEF(&_103$$21);
	ZVAL_UNDEF(&_104$$21);
	ZVAL_UNDEF(&_105$$22);
	ZVAL_UNDEF(&_106$$22);
	ZVAL_UNDEF(&_107$$22);
	ZVAL_UNDEF(&_108$$22);
	ZVAL_UNDEF(&_109$$22);
	ZVAL_UNDEF(&_111$$22);
	ZVAL_UNDEF(&_112$$22);
	ZVAL_UNDEF(&_113$$22);
	ZVAL_UNDEF(&_119$$23);
	ZVAL_UNDEF(&_120$$23);
	ZVAL_UNDEF(&_122$$23);
	ZVAL_UNDEF(&_123$$23);
	ZVAL_UNDEF(&_125$$24);
	ZVAL_UNDEF(&_126$$24);
	ZVAL_UNDEF(&_128$$24);
	ZVAL_UNDEF(&_129$$24);
	ZVAL_UNDEF(&_130$$25);
	ZVAL_UNDEF(&_131$$25);
	ZVAL_UNDEF(&_133$$25);
	ZVAL_UNDEF(&_134$$25);
	ZVAL_UNDEF(&_135$$26);
	ZVAL_UNDEF(&_136$$26);
	ZVAL_UNDEF(&_138$$26);
	ZVAL_UNDEF(&_139$$26);
	ZVAL_UNDEF(&_140$$26);
	ZVAL_UNDEF(&_141$$26);
	ZVAL_UNDEF(&_142$$27);
	ZVAL_UNDEF(&_143$$27);
	ZVAL_UNDEF(&_145$$27);
	ZVAL_UNDEF(&_146$$27);
	ZVAL_UNDEF(&_147$$27);
	ZVAL_UNDEF(&_148$$28);
	ZVAL_UNDEF(&_149$$28);
	ZVAL_UNDEF(&_151$$28);
	ZVAL_UNDEF(&_152$$28);
	ZVAL_UNDEF(&_155);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_86$$8);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_55$$12);
	ZVAL_UNDEF(&_74$$14);
	ZVAL_UNDEF(&_101$$21);
	ZVAL_UNDEF(&_110$$22);
	ZVAL_UNDEF(&_121$$23);
	ZVAL_UNDEF(&_127$$24);
	ZVAL_UNDEF(&_132$$25);
	ZVAL_UNDEF(&_137$$26);
	ZVAL_UNDEF(&_144$$27);
	ZVAL_UNDEF(&_150$$28);

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
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_GET_CONSTANT(&_2$$4, "PHP_EOL");
			ZEPHIR_INIT_NVAR(&_0$$4);
			ZEPHIR_CONCAT_SV(&_0$$4, "array (:count) (", &_2$$4);
		} else {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_GET_CONSTANT(&_3$$4, "PHP_EOL");
			ZEPHIR_INIT_NVAR(&_0$$4);
			ZEPHIR_CONCAT_SV(&_0$$4, "<b style =':style'>array</b> (<span style =':style'>:count</span>) (", &_3$$4);
		}
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_create_array(&_4$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "arr");
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getstyle", &_7, 0, &_6$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_4$$4, SL(":style"), &_5$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_4$$4, SL(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_5$$4, "strtr", &_8, 103, &_0$$4, &_4$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_5$$4 TSRMLS_CC);
		zephir_is_iterable(variable, 0, "ice/dump.zep", 171);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(variable), _10$$4, _11$$4, _9$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_11$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _11$$4);
			} else {
				ZVAL_LONG(&key, _10$$4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _9$$4);
			ZEPHIR_CALL_FUNCTION(&_12$$5, "str_repeat", &_13, 86, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_14$$5);
			zephir_read_property(&_15$$5, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_15$$5)) {
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZVAL_STRING(&_14$$5, "[:key] => ");
			} else {
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZVAL_STRING(&_14$$5, "[<span style=':style'>:key</span>] => ");
			}
			ZEPHIR_INIT_NVAR(&_16$$5);
			zephir_create_array(&_16$$5, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_18$$5);
			ZVAL_STRING(&_18$$5, "arr");
			ZEPHIR_CALL_METHOD(&_17$$5, this_ptr, "getstyle", &_7, 0, &_18$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_16$$5, SL(":style"), &_17$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_17$$5, "strtr", &_8, 103, &_14$$5, &_16$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_19$$5);
			ZEPHIR_CONCAT_VV(&_19$$5, &_12$$5, &_17$$5);
			zephir_concat_self(&output, &_19$$5 TSRMLS_CC);
			_20$$5 = ZEPHIR_IS_LONG(tab, 1);
			if (_20$$5) {
				_20$$5 = !ZEPHIR_IS_STRING(name, "");
			}
			_21$$5 = _20$$5;
			if (_21$$5) {
				_21$$5 = !(Z_TYPE_P(&key) == IS_LONG);
			}
			_22$$5 = _21$$5;
			if (_22$$5) {
				_22$$5 = ZEPHIR_IS_EQUAL(name, &key);
			}
			if (_22$$5) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(&_24$$7);
				ZVAL_STRING(&_24$$7, "");
				ZVAL_LONG(&_25$$7, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_23$$7, this_ptr, "output", &_26, 104, &value, &_24$$7, &_25$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_24$$7);
				ZEPHIR_GET_CONSTANT(&_24$$7, "PHP_EOL");
				ZEPHIR_INIT_LNVAR(_27$$7);
				ZEPHIR_CONCAT_VV(&_27$$7, &_23$$7, &_24$$7);
				zephir_concat_self(&output, &_27$$7 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_28$$4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_29$$4, "str_repeat", &_13, 86, &space, &_28$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_29$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&className$$8);
		zephir_get_class(&className$$8, variable, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_30$$8);
		zephir_read_property(&_31$$8, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_31$$8)) {
			ZEPHIR_INIT_NVAR(&_30$$8);
			ZVAL_STRING(&_30$$8, "object :class");
		} else {
			ZEPHIR_INIT_NVAR(&_30$$8);
			ZVAL_STRING(&_30$$8, "<b style=':style'>object</b> :class");
		}
		ZEPHIR_INIT_VAR(&_32$$8);
		zephir_create_array(&_32$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_34$$8);
		ZVAL_STRING(&_34$$8, "obj");
		ZEPHIR_CALL_METHOD(&_33$$8, this_ptr, "getstyle", &_7, 0, &_34$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_32$$8, SL(":style"), &_33$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_32$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_33$$8, "strtr", &_8, 103, &_30$$8, &_32$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, &_33$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_35$$8, "get_parent_class", &_36, 105, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_35$$8)) {
			ZEPHIR_INIT_VAR(&_37$$9);
			zephir_read_property(&_38$$9, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_38$$9)) {
				ZEPHIR_INIT_NVAR(&_37$$9);
				ZVAL_STRING(&_37$$9, " extends :parent");
			} else {
				ZEPHIR_INIT_NVAR(&_37$$9);
				ZVAL_STRING(&_37$$9, " <b style=':style'>extends</b> :parent");
			}
			ZEPHIR_INIT_VAR(&_39$$9);
			zephir_create_array(&_39$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_41$$9);
			ZVAL_STRING(&_41$$9, "obj");
			ZEPHIR_CALL_METHOD(&_40$$9, this_ptr, "getstyle", &_7, 0, &_41$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_39$$9, SL(":style"), &_40$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_40$$9, "get_parent_class", &_36, 105, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_39$$9, SL(":parent"), &_40$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_40$$9, "strtr", &_8, 103, &_37$$9, &_39$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, &_40$$9 TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(&_34$$8);
		ZEPHIR_GET_CONSTANT(&_34$$8, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_42$$8);
		ZEPHIR_CONCAT_SV(&_42$$8, " (", &_34$$8);
		zephir_concat_self(&output, &_42$$8 TSRMLS_CC);
		zephir_read_property(&_43$$8, this_ptr, SL("skip"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_44$$8, this_ptr, SL("detailed"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&className$$8, &_43$$8 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_45$$10, "str_repeat", &_13, 86, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_46$$10);
			ZEPHIR_GET_CONSTANT(&_46$$10, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_47$$10);
			ZEPHIR_CONCAT_VSV(&_47$$10, &_45$$10, "[skipped]", &_46$$10);
			zephir_concat_self(&output, &_47$$10 TSRMLS_CC);
		} else if (!(zephir_is_true(&_44$$8))) {
			ZEPHIR_CALL_FUNCTION(&_48$$11, "get_object_vars", NULL, 106, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_48$$11, 0, "ice/dump.zep", 194);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_48$$11), _50$$11, _51$$11, _49$$11)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_51$$11 != NULL) { 
					ZVAL_STR_COPY(&key, _51$$11);
				} else {
					ZVAL_LONG(&key, _50$$11);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _49$$11);
				ZEPHIR_CALL_FUNCTION(&_52$$12, "str_repeat", &_13, 86, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_53$$12);
				zephir_read_property(&_54$$12, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_54$$12)) {
					ZEPHIR_INIT_NVAR(&_53$$12);
					ZVAL_STRING(&_53$$12, "->:key (:type) = ");
				} else {
					ZEPHIR_INIT_NVAR(&_53$$12);
					ZVAL_STRING(&_53$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				}
				ZEPHIR_INIT_NVAR(&_55$$12);
				zephir_create_array(&_55$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_57$$12);
				ZVAL_STRING(&_57$$12, "obj");
				ZEPHIR_CALL_METHOD(&_56$$12, this_ptr, "getstyle", &_7, 0, &_57$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_55$$12, SL(":style"), &_56$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_55$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(&_55$$12, SL(":type"), SL("public"));
				ZEPHIR_CALL_FUNCTION(&_56$$12, "strtr", &_8, 103, &_53$$12, &_55$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_58$$12);
				ZEPHIR_CONCAT_VV(&_58$$12, &_52$$12, &_56$$12);
				zephir_concat_self(&output, &_58$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_57$$12);
				ZVAL_STRING(&_57$$12, "");
				ZVAL_LONG(&_60$$12, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_59$$12, this_ptr, "output", &_26, 104, &value, &_57$$12, &_60$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_57$$12);
				ZEPHIR_GET_CONSTANT(&_57$$12, "PHP_EOL");
				ZEPHIR_INIT_LNVAR(_61$$12);
				ZEPHIR_CONCAT_VV(&_61$$12, &_59$$12, &_57$$12);
				zephir_concat_self(&output, &_61$$12 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			ZEPHIR_INIT_VAR(&reflect$$13);
			ZVAL_STRING(&reflect$$13, "ReflectionClass");
			ZEPHIR_INIT_VAR(&_62$$13);
			zephir_fetch_safe_class(&_63$$13, &reflect$$13);
			_64$$13 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_63$$13), Z_STRLEN_P(&_63$$13), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(&_62$$13, _64$$13);
			if (zephir_has_constructor(&_62$$13 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &_62$$13, "__construct", NULL, 0, variable);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_65$$13, &_62$$13, "getproperties", NULL, 0);
			zephir_check_call_status();
			zephir_is_iterable(&_65$$13, 0, "ice/dump.zep", 217);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_65$$13), _66$$13)
			{
				ZEPHIR_INIT_NVAR(&attr);
				ZVAL_COPY(&attr, _66$$13);
				ZEPHIR_CALL_METHOD(&key, &attr, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&type);
				ZVAL_STRING(&type, "public");
				ZEPHIR_CALL_METHOD(&_67$$14, &attr, "isprotected", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_67$$14)) {
					ZVAL_BOOL(&_68$$15, 1);
					ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_68$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_STRING(&type, "protected");
				}
				ZEPHIR_CALL_METHOD(&_69$$14, &attr, "isprivate", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_69$$14)) {
					ZVAL_BOOL(&_70$$16, 1);
					ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_70$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_STRING(&type, "private");
				}
				ZEPHIR_CALL_METHOD(&value, &attr, "getvalue", NULL, 0, variable);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_71$$14, "str_repeat", &_13, 86, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_72$$14);
				zephir_read_property(&_73$$14, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_73$$14)) {
					ZEPHIR_INIT_NVAR(&_72$$14);
					ZVAL_STRING(&_72$$14, "->:key (:type) = ");
				} else {
					ZEPHIR_INIT_NVAR(&_72$$14);
					ZVAL_STRING(&_72$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				}
				ZEPHIR_INIT_NVAR(&_74$$14);
				zephir_create_array(&_74$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_76$$14);
				ZVAL_STRING(&_76$$14, "obj");
				ZEPHIR_CALL_METHOD(&_75$$14, this_ptr, "getstyle", &_7, 0, &_76$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_74$$14, SL(":style"), &_75$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_74$$14, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_74$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_75$$14, "strtr", &_8, 103, &_72$$14, &_74$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_77$$14);
				ZEPHIR_CONCAT_VV(&_77$$14, &_71$$14, &_75$$14);
				zephir_concat_self(&output, &_77$$14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_76$$14);
				ZVAL_STRING(&_76$$14, "");
				ZVAL_LONG(&_79$$14, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_78$$14, this_ptr, "output", &_26, 104, &value, &_76$$14, &_79$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_76$$14);
				ZEPHIR_GET_CONSTANT(&_76$$14, "PHP_EOL");
				ZEPHIR_INIT_LNVAR(_80$$14);
				ZEPHIR_CONCAT_VV(&_80$$14, &_78$$14, &_76$$14);
				zephir_concat_self(&output, &_80$$14 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&attr);
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 107, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_81$$8, "str_repeat", &_13, 86, &space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_82$$8);
		zephir_read_property(&_83$$8, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_83$$8)) {
			ZEPHIR_INIT_VAR(&_84$$8);
			ZEPHIR_GET_CONSTANT(&_84$$8, "PHP_EOL");
			ZEPHIR_INIT_NVAR(&_82$$8);
			ZEPHIR_CONCAT_SV(&_82$$8, ":class methods: (:count) (", &_84$$8);
		} else {
			ZEPHIR_INIT_VAR(&_85$$8);
			ZEPHIR_GET_CONSTANT(&_85$$8, "PHP_EOL");
			ZEPHIR_INIT_NVAR(&_82$$8);
			ZEPHIR_CONCAT_SV(&_82$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (", &_85$$8);
		}
		ZEPHIR_INIT_VAR(&_86$$8);
		zephir_create_array(&_86$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_88$$8);
		ZVAL_STRING(&_88$$8, "obj");
		ZEPHIR_CALL_METHOD(&_87$$8, this_ptr, "getstyle", &_7, 0, &_88$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_86$$8, SL(":style"), &_87$$8, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_86$$8, SL(":class"), &className$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_86$$8, SL(":count"), zephir_fast_count_int(&attr TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_87$$8, "strtr", &_8, 103, &_82$$8, &_86$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_89$$8);
		ZEPHIR_CONCAT_VV(&_89$$8, &_81$$8, &_87$$8);
		zephir_concat_self(&output, &_89$$8 TSRMLS_CC);
		zephir_read_property(&_90$$8, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&className$$8, &_90$$8 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_91$$17, "str_repeat", &_13, 86, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_92$$17);
			ZEPHIR_GET_CONSTANT(&_92$$17, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_93$$17);
			ZEPHIR_CONCAT_VSV(&_93$$17, &_91$$17, "[already listed]", &_92$$17);
			zephir_concat_self(&output, &_93$$17 TSRMLS_CC);
		} else {
			zephir_is_iterable(&attr, 0, "ice/dump.zep", 235);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _94$$18)
			{
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _94$$18);
				zephir_read_property(&_95$$19, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_fast_in_array(&className$$8, &_95$$19 TSRMLS_CC))) {
					zephir_update_property_array_append(this_ptr, SL("methods"), &className$$8 TSRMLS_CC);
				}
				if (ZEPHIR_IS_STRING(&value, "__construct")) {
					ZVAL_LONG(&_96$$21, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_97$$21, "str_repeat", &_13, 86, &space, &_96$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_98$$21);
					zephir_read_property(&_96$$21, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_96$$21)) {
						ZEPHIR_INIT_NVAR(&_99$$21);
						ZEPHIR_GET_CONSTANT(&_99$$21, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_98$$21);
						ZEPHIR_CONCAT_SV(&_98$$21, "->:method(); [constructor]", &_99$$21);
					} else {
						ZEPHIR_INIT_NVAR(&_100$$21);
						ZEPHIR_GET_CONSTANT(&_100$$21, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_98$$21);
						ZEPHIR_CONCAT_SV(&_98$$21, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]", &_100$$21);
					}
					ZEPHIR_INIT_NVAR(&_101$$21);
					zephir_create_array(&_101$$21, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_103$$21);
					ZVAL_STRING(&_103$$21, "obj");
					ZEPHIR_CALL_METHOD(&_102$$21, this_ptr, "getstyle", &_7, 0, &_103$$21);
					zephir_check_call_status();
					zephir_array_update_string(&_101$$21, SL(":style"), &_102$$21, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_101$$21, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_102$$21, "strtr", &_8, 103, &_98$$21, &_101$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_104$$21);
					ZEPHIR_CONCAT_VV(&_104$$21, &_97$$21, &_102$$21);
					zephir_concat_self(&output, &_104$$21 TSRMLS_CC);
				} else {
					ZVAL_LONG(&_105$$22, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_106$$22, "str_repeat", &_13, 86, &space, &_105$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_107$$22);
					zephir_read_property(&_105$$22, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_105$$22)) {
						ZEPHIR_INIT_NVAR(&_108$$22);
						ZEPHIR_GET_CONSTANT(&_108$$22, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_107$$22);
						ZEPHIR_CONCAT_SV(&_107$$22, "->:method();", &_108$$22);
					} else {
						ZEPHIR_INIT_NVAR(&_109$$22);
						ZEPHIR_GET_CONSTANT(&_109$$22, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_107$$22);
						ZEPHIR_CONCAT_SV(&_107$$22, "-><span style=':style'>:method</span>();", &_109$$22);
					}
					ZEPHIR_INIT_NVAR(&_110$$22);
					zephir_create_array(&_110$$22, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_112$$22);
					ZVAL_STRING(&_112$$22, "obj");
					ZEPHIR_CALL_METHOD(&_111$$22, this_ptr, "getstyle", &_7, 0, &_112$$22);
					zephir_check_call_status();
					zephir_array_update_string(&_110$$22, SL(":style"), &_111$$22, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_110$$22, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_111$$22, "strtr", &_8, 103, &_107$$22, &_110$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_113$$22);
					ZEPHIR_CONCAT_VV(&_113$$22, &_106$$22, &_111$$22);
					zephir_concat_self(&output, &_113$$22 TSRMLS_CC);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_CALL_FUNCTION(&_114$$18, "str_repeat", &_13, 86, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_115$$18);
			ZEPHIR_GET_CONSTANT(&_115$$18, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_116$$18);
			ZEPHIR_CONCAT_VSV(&_116$$18, &_114$$18, ")", &_115$$18);
			zephir_concat_self(&output, &_116$$18 TSRMLS_CC);
		}
		ZVAL_LONG(&_117$$8, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_118$$8, "str_repeat", &_13, 86, &space, &_117$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_118$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_119$$23);
		zephir_read_property(&_120$$23, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_120$$23)) {
			ZEPHIR_INIT_NVAR(&_119$$23);
			ZVAL_STRING(&_119$$23, "integer (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_119$$23);
			ZVAL_STRING(&_119$$23, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_121$$23);
		zephir_create_array(&_121$$23, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_123$$23);
		ZVAL_STRING(&_123$$23, "int");
		ZEPHIR_CALL_METHOD(&_122$$23, this_ptr, "getstyle", &_7, 0, &_123$$23);
		zephir_check_call_status();
		zephir_array_update_string(&_121$$23, SL(":style"), &_122$$23, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_121$$23, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_122$$23, "strtr", &_8, 103, &_119$$23, &_121$$23);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_122$$23);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_124, "is_float", NULL, 108, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_124)) {
		ZEPHIR_INIT_VAR(&_125$$24);
		zephir_read_property(&_126$$24, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_126$$24)) {
			ZEPHIR_INIT_NVAR(&_125$$24);
			ZVAL_STRING(&_125$$24, "float (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_125$$24);
			ZVAL_STRING(&_125$$24, "<b style=':style'>float</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_127$$24);
		zephir_create_array(&_127$$24, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_129$$24);
		ZVAL_STRING(&_129$$24, "float");
		ZEPHIR_CALL_METHOD(&_128$$24, this_ptr, "getstyle", &_7, 0, &_129$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_127$$24, SL(":style"), &_128$$24, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_127$$24, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_128$$24, "strtr", &_8, 103, &_125$$24, &_127$$24);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_128$$24);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_130$$25);
		zephir_read_property(&_131$$25, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_131$$25)) {
			ZEPHIR_INIT_NVAR(&_130$$25);
			ZVAL_STRING(&_130$$25, "numeric string (:length) \":var\"");
		} else {
			ZEPHIR_INIT_NVAR(&_130$$25);
			ZVAL_STRING(&_130$$25, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		}
		ZEPHIR_INIT_VAR(&_132$$25);
		zephir_create_array(&_132$$25, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_134$$25);
		ZVAL_STRING(&_134$$25, "num");
		ZEPHIR_CALL_METHOD(&_133$$25, this_ptr, "getstyle", &_7, 0, &_134$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_132$$25, SL(":style"), &_133$$25, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_132$$25, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_132$$25, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_133$$25, "strtr", &_8, 103, &_130$$25, &_132$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_133$$25);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_135$$26);
		zephir_read_property(&_136$$26, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_136$$26)) {
			ZEPHIR_INIT_NVAR(&_135$$26);
			ZVAL_STRING(&_135$$26, "string (:length) \":var\"");
		} else {
			ZEPHIR_INIT_NVAR(&_135$$26);
			ZVAL_STRING(&_135$$26, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		}
		ZEPHIR_INIT_VAR(&_137$$26);
		zephir_create_array(&_137$$26, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_139$$26);
		ZVAL_STRING(&_139$$26, "str");
		ZEPHIR_CALL_METHOD(&_138$$26, this_ptr, "getstyle", &_7, 0, &_139$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_137$$26, SL(":style"), &_138$$26, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_137$$26, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_140$$26, 4);
		ZEPHIR_INIT_NVAR(&_139$$26);
		ZVAL_STRING(&_139$$26, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_138$$26, "htmlentities", NULL, 109, variable, &_140$$26, &_139$$26);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_141$$26, "nl2br", NULL, 110, &_138$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_137$$26, SL(":var"), &_141$$26, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_141$$26, "strtr", &_8, 103, &_135$$26, &_137$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_141$$26);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_142$$27);
		zephir_read_property(&_143$$27, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_143$$27)) {
			ZEPHIR_INIT_NVAR(&_142$$27);
			ZVAL_STRING(&_142$$27, "boolean (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_142$$27);
			ZVAL_STRING(&_142$$27, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_144$$27);
		zephir_create_array(&_144$$27, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_146$$27);
		ZVAL_STRING(&_146$$27, "bool");
		ZEPHIR_CALL_METHOD(&_145$$27, this_ptr, "getstyle", &_7, 0, &_146$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_144$$27, SL(":style"), &_145$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_147$$27);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_147$$27);
			ZVAL_STRING(&_147$$27, "true");
		} else {
			ZEPHIR_INIT_NVAR(&_147$$27);
			ZVAL_STRING(&_147$$27, "false");
		}
		zephir_array_update_string(&_144$$27, SL(":var"), &_147$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_145$$27, "strtr", &_8, 103, &_142$$27, &_144$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_145$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_148$$28);
		zephir_read_property(&_149$$28, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_149$$28)) {
			ZEPHIR_INIT_NVAR(&_148$$28);
			ZVAL_STRING(&_148$$28, "null");
		} else {
			ZEPHIR_INIT_NVAR(&_148$$28);
			ZVAL_STRING(&_148$$28, "<b style=':style'>null</b>");
		}
		ZEPHIR_INIT_VAR(&_150$$28);
		zephir_create_array(&_150$$28, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_152$$28);
		ZVAL_STRING(&_152$$28, "null");
		ZEPHIR_CALL_METHOD(&_151$$28, this_ptr, "getstyle", &_7, 0, &_152$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_150$$28, SL(":style"), &_151$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_151$$28, "strtr", &_8, 103, &_148$$28, &_150$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_151$$28);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_153);
	zephir_read_property(&_154, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_154)) {
		ZEPHIR_INIT_NVAR(&_153);
		ZVAL_STRING(&_153, "(:var)");
	} else {
		ZEPHIR_INIT_NVAR(&_153);
		ZVAL_STRING(&_153, "(<span style=':style'>:var</span>)");
	}
	ZEPHIR_INIT_VAR(&_155);
	zephir_create_array(&_155, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_157);
	ZVAL_STRING(&_157, "other");
	ZEPHIR_CALL_METHOD(&_156, this_ptr, "getstyle", &_7, 0, &_157);
	zephir_check_call_status();
	zephir_array_update_string(&_155, SL(":style"), &_156, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_155, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_156, "strtr", &_8, 103, &_153, &_155);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_156);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *variable, variable_sub, *name_param = NULL, _0, _1, _3, _4;
	zval *this_ptr = getThis();

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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 103, &_0, &_2);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

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
	zephir_is_iterable(&_0, 0, "ice/dump.zep", 308);
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
	RETURN_CCTOR(&output);

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

	zval _15$$8, _25$$9;
	zend_bool _0;
	zephir_fcall_cache_entry *_6 = NULL, *_12 = NULL, *_18 = NULL, *_19 = NULL, *_22 = NULL;
	zend_long line, padding, ZEPHIR_LAST_CALL_STATUS, i;
	zval *filename_param = NULL, *line_param = NULL, *padding_param = NULL, file, range, format, lines, row, _1, _2, _3, _4, _7$$4, _8$$4, _9$$7, _10$$7, _11$$7, _13$$8, _14$$8, _16$$8, _17$$8, _20$$8, _21$$8, _23$$9, _24$$9, _26$$9, _27$$9, _28$$9, _29$$9;
	zval filename, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&range);
	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_25$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &filename_param, &line_param, &padding_param);

	zephir_get_strval(&filename, filename_param);
	line = zephir_get_intval(line_param);
	if (!padding_param) {
		padding = 5;
	} else {
		padding = zephir_get_intval(padding_param);
	}


	i = 0;
	_0 = ZEPHIR_IS_EMPTY(&filename);
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_readable", NULL, 111, &filename);
		zephir_check_call_status();
		_0 = !zephir_is_true(&_1);
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "r");
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 112, &filename, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&range);
	zephir_create_array(&range, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(&range, SL("start"), (line - padding));
	add_assoc_long_ex(&range, SL("end"), (line + padding));
	zephir_array_fetch_string(&_3, &range, SL("end"), PH_NOISY | PH_READONLY, "ice/dump.zep", 339 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, zephir_fast_strlen_ev(&_3));
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVS(&_5, "% ", &_4, "d");
	ZEPHIR_CPY_WRT(&format, &_5);
	ZEPHIR_INIT_VAR(&lines);
	array_init(&lines);
	ZEPHIR_CALL_FUNCTION(&row, "fgets", &_6, 113, &file);
	zephir_check_call_status();
	while (1) {
		if (!(!(zephir_feof(&file TSRMLS_CC)))) {
			break;
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(&row)) {
			break;
		}
		i++;
		zephir_array_fetch_string(&_7$$4, &range, SL("end"), PH_NOISY | PH_READONLY, "ice/dump.zep", 351 TSRMLS_CC);
		if (ZEPHIR_LT_LONG(&_7$$4, i)) {
			break;
		}
		zephir_array_fetch_string(&_8$$4, &range, SL("start"), PH_NOISY | PH_READONLY, "ice/dump.zep", 355 TSRMLS_CC);
		if (ZEPHIR_LE_LONG(&_8$$4, i)) {
			ZVAL_LONG(&_9$$7, 0);
			ZEPHIR_INIT_NVAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "utf-8");
			ZEPHIR_CALL_FUNCTION(&_11$$7, "htmlspecialchars", &_12, 114, &row, &_9$$7, &_10$$7);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&row, &_11$$7);
			if (i == line) {
				ZEPHIR_INIT_LNVAR(_13$$8);
				zephir_read_property(&_14$$8, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_14$$8)) {
					ZEPHIR_INIT_NVAR(&_13$$8);
					ZVAL_STRING(&_13$$8, ":var");
				} else {
					ZEPHIR_INIT_NVAR(&_13$$8);
					ZVAL_STRING(&_13$$8, "<div class=':class'>:var</div>");
				}
				ZEPHIR_INIT_NVAR(&_15$$8);
				zephir_create_array(&_15$$8, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_17$$8);
				ZVAL_STRING(&_17$$8, "line");
				ZEPHIR_CALL_METHOD(&_16$$8, this_ptr, "getstyle", &_18, 0, &_17$$8);
				zephir_check_call_status();
				zephir_array_update_string(&_15$$8, SL(":class"), &_16$$8, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_15$$8, SL(":var"), &row, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_16$$8, "strtr", &_19, 103, &_13$$8, &_15$$8);
				zephir_check_call_status();
				ZVAL_LONG(&_20$$8, i);
				ZEPHIR_CALL_FUNCTION(&_21$$8, "sprintf", &_22, 11, &format, &_20$$8);
				zephir_check_call_status();
				zephir_array_update_zval(&lines, &_21$$8, &_16$$8, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_LNVAR(_23$$9);
				zephir_read_property(&_24$$9, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_24$$9)) {
					ZEPHIR_INIT_NVAR(&_23$$9);
					ZVAL_STRING(&_23$$9, ":var");
				} else {
					ZEPHIR_INIT_NVAR(&_23$$9);
					ZVAL_STRING(&_23$$9, "<div class=':class'>:var</div>");
				}
				ZEPHIR_INIT_NVAR(&_25$$9);
				zephir_create_array(&_25$$9, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_27$$9);
				ZVAL_STRING(&_27$$9, "lines");
				ZEPHIR_CALL_METHOD(&_26$$9, this_ptr, "getstyle", &_18, 0, &_27$$9);
				zephir_check_call_status();
				zephir_array_update_string(&_25$$9, SL(":class"), &_26$$9, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_25$$9, SL(":var"), &row, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_26$$9, "strtr", &_19, 103, &_23$$9, &_25$$9);
				zephir_check_call_status();
				ZVAL_LONG(&_28$$9, i);
				ZEPHIR_CALL_FUNCTION(&_29$$9, "sprintf", &_22, 11, &format, &_28$$9);
				zephir_check_call_status();
				zephir_array_update_zval(&lines, &_29$$9, &_26$$9, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_CALL_FUNCTION(&row, "fgets", &_6, 113, &file);
		zephir_check_call_status();
	}
	zephir_fclose(&file TSRMLS_CC);
	RETURN_CCTOR(&lines);

}

zend_object *zephir_init_properties_Ice_Dump(zend_class_entry *class_type TSRMLS_DC) {

		zval _5$$5;
	zval _0, _2, _4, _1$$3, _3$$4, _6$$5;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_5$$5);

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
		zephir_read_property(&_4, this_ptr, SL("skip"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_create_array(&_5$$5, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "Ice\\Di");
			zephir_array_fast_append(&_5$$5, &_6$$5);
			zephir_update_property_zval(this_ptr, SL("skip"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

