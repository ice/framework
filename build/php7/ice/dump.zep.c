
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

	zend_declare_property_bool(ice_dump_ce, SL("detailed"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_bool(ice_dump_ce, SL("plain"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_dump_ce, SL("skip"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_dump_ce, SL("methods"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_dump_ce, SL("styles"), ZEND_ACC_PROTECTED);

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

	zephir_fetch_params_without_memory_grow(1, 0, &detailed);



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

	zephir_fetch_params_without_memory_grow(1, 0, &plain);



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

	zephir_fetch_params_without_memory_grow(1, 0, &skip);



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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, style, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&style);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("styles"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&style, &_0, &type, 1)) {
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_create_array(&defaultStyles, 13, 0);
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
	zephir_fast_array_merge(&_0, &defaultStyles, &styles);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zend_class_entry *_90$$17;
	zend_bool _21$$5, _22$$5, _23$$5, _36$$8, _37$$8, _38$$8;
	zend_string *_12$$4, *_67$$14;
	zend_ulong _11$$4, _66$$14;
	zval _216, _4$$4, _17$$5, _32$$8, _47$$11, _127$$11, _54$$12, _71$$15, _81$$16, _101$$18, _115$$21, _143$$28, _152$$29, _162$$32, _171$$33, _182$$34, _188$$35, _193$$36, _198$$37, _205$$38, _211$$39;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_14 = NULL, *_27 = NULL, *_51 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, *name = NULL, name_sub, *tab = NULL, tab_sub, __$null, key, value, output, space, type, attr, _185, _214, _215, _217, _218, _0$$4, _1$$4, _2$$4, _3$$4, _5$$4, _6$$4, *_9$$4, _10$$4, _43$$4, _44$$4, _13$$5, _15$$5, _16$$5, _18$$5, _19$$5, _20$$5, _24$$7, _25$$7, _26$$7, _28$$7, _29$$8, _30$$8, _31$$8, _33$$8, _34$$8, _35$$8, _39$$10, _40$$10, _41$$10, _42$$10, className$$11, _45$$11, _46$$11, _48$$11, _49$$11, _50$$11, _57$$11, _58$$11, _59$$11, _122$$11, _123$$11, _124$$11, _125$$11, _126$$11, _128$$11, _129$$11, _130$$11, _131$$11, _178$$11, _179$$11, _52$$12, _53$$12, _55$$12, _56$$12, _60$$13, _61$$13, _62$$13, _63$$14, *_64$$14, _65$$14, _68$$15, _69$$15, _70$$15, _72$$15, _73$$15, _74$$15, _75$$15, _76$$15, _77$$15, _78$$16, _79$$16, _80$$16, _82$$16, _83$$16, _84$$16, _85$$16, _86$$16, _87$$16, reflect$$17, _88$$17, _89$$17, _91$$17, *_92$$17, _93$$17, _94$$18, _96$$18, _98$$18, _99$$18, _100$$18, _102$$18, _103$$18, _104$$18, _105$$18, _106$$18, _107$$18, _95$$19, _97$$20, _108$$21, _110$$21, _112$$21, _113$$21, _114$$21, _116$$21, _117$$21, _118$$21, _119$$21, _120$$21, _121$$21, _109$$22, _111$$23, _132$$24, _133$$24, _134$$24, *_135$$25, _136$$25, _175$$25, _176$$25, _177$$25, _137$$26, _138$$28, _139$$28, _140$$28, _141$$28, _142$$28, _144$$28, _145$$28, _146$$28, _147$$29, _148$$29, _149$$29, _150$$29, _151$$29, _153$$29, _154$$29, _155$$29, _156$$30, _157$$32, _158$$32, _159$$32, _160$$32, _161$$32, _163$$32, _164$$32, _165$$32, _166$$33, _167$$33, _168$$33, _169$$33, _170$$33, _172$$33, _173$$33, _174$$33, _180$$34, _181$$34, _183$$34, _184$$34, _186$$35, _187$$35, _189$$35, _190$$35, _191$$36, _192$$36, _194$$36, _195$$36, _196$$37, _197$$37, _199$$37, _200$$37, _201$$37, _202$$37, _203$$38, _204$$38, _206$$38, _207$$38, _208$$38, _209$$39, _210$$39, _212$$39, _213$$39;
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
	ZVAL_UNDEF(&_185);
	ZVAL_UNDEF(&_214);
	ZVAL_UNDEF(&_215);
	ZVAL_UNDEF(&_217);
	ZVAL_UNDEF(&_218);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_43$$4);
	ZVAL_UNDEF(&_44$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&className$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_46$$11);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_57$$11);
	ZVAL_UNDEF(&_58$$11);
	ZVAL_UNDEF(&_59$$11);
	ZVAL_UNDEF(&_122$$11);
	ZVAL_UNDEF(&_123$$11);
	ZVAL_UNDEF(&_124$$11);
	ZVAL_UNDEF(&_125$$11);
	ZVAL_UNDEF(&_126$$11);
	ZVAL_UNDEF(&_128$$11);
	ZVAL_UNDEF(&_129$$11);
	ZVAL_UNDEF(&_130$$11);
	ZVAL_UNDEF(&_131$$11);
	ZVAL_UNDEF(&_178$$11);
	ZVAL_UNDEF(&_179$$11);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_53$$12);
	ZVAL_UNDEF(&_55$$12);
	ZVAL_UNDEF(&_56$$12);
	ZVAL_UNDEF(&_60$$13);
	ZVAL_UNDEF(&_61$$13);
	ZVAL_UNDEF(&_62$$13);
	ZVAL_UNDEF(&_63$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_68$$15);
	ZVAL_UNDEF(&_69$$15);
	ZVAL_UNDEF(&_70$$15);
	ZVAL_UNDEF(&_72$$15);
	ZVAL_UNDEF(&_73$$15);
	ZVAL_UNDEF(&_74$$15);
	ZVAL_UNDEF(&_75$$15);
	ZVAL_UNDEF(&_76$$15);
	ZVAL_UNDEF(&_77$$15);
	ZVAL_UNDEF(&_78$$16);
	ZVAL_UNDEF(&_79$$16);
	ZVAL_UNDEF(&_80$$16);
	ZVAL_UNDEF(&_82$$16);
	ZVAL_UNDEF(&_83$$16);
	ZVAL_UNDEF(&_84$$16);
	ZVAL_UNDEF(&_85$$16);
	ZVAL_UNDEF(&_86$$16);
	ZVAL_UNDEF(&_87$$16);
	ZVAL_UNDEF(&reflect$$17);
	ZVAL_UNDEF(&_88$$17);
	ZVAL_UNDEF(&_89$$17);
	ZVAL_UNDEF(&_91$$17);
	ZVAL_UNDEF(&_93$$17);
	ZVAL_UNDEF(&_94$$18);
	ZVAL_UNDEF(&_96$$18);
	ZVAL_UNDEF(&_98$$18);
	ZVAL_UNDEF(&_99$$18);
	ZVAL_UNDEF(&_100$$18);
	ZVAL_UNDEF(&_102$$18);
	ZVAL_UNDEF(&_103$$18);
	ZVAL_UNDEF(&_104$$18);
	ZVAL_UNDEF(&_105$$18);
	ZVAL_UNDEF(&_106$$18);
	ZVAL_UNDEF(&_107$$18);
	ZVAL_UNDEF(&_95$$19);
	ZVAL_UNDEF(&_97$$20);
	ZVAL_UNDEF(&_108$$21);
	ZVAL_UNDEF(&_110$$21);
	ZVAL_UNDEF(&_112$$21);
	ZVAL_UNDEF(&_113$$21);
	ZVAL_UNDEF(&_114$$21);
	ZVAL_UNDEF(&_116$$21);
	ZVAL_UNDEF(&_117$$21);
	ZVAL_UNDEF(&_118$$21);
	ZVAL_UNDEF(&_119$$21);
	ZVAL_UNDEF(&_120$$21);
	ZVAL_UNDEF(&_121$$21);
	ZVAL_UNDEF(&_109$$22);
	ZVAL_UNDEF(&_111$$23);
	ZVAL_UNDEF(&_132$$24);
	ZVAL_UNDEF(&_133$$24);
	ZVAL_UNDEF(&_134$$24);
	ZVAL_UNDEF(&_136$$25);
	ZVAL_UNDEF(&_175$$25);
	ZVAL_UNDEF(&_176$$25);
	ZVAL_UNDEF(&_177$$25);
	ZVAL_UNDEF(&_137$$26);
	ZVAL_UNDEF(&_138$$28);
	ZVAL_UNDEF(&_139$$28);
	ZVAL_UNDEF(&_140$$28);
	ZVAL_UNDEF(&_141$$28);
	ZVAL_UNDEF(&_142$$28);
	ZVAL_UNDEF(&_144$$28);
	ZVAL_UNDEF(&_145$$28);
	ZVAL_UNDEF(&_146$$28);
	ZVAL_UNDEF(&_147$$29);
	ZVAL_UNDEF(&_148$$29);
	ZVAL_UNDEF(&_149$$29);
	ZVAL_UNDEF(&_150$$29);
	ZVAL_UNDEF(&_151$$29);
	ZVAL_UNDEF(&_153$$29);
	ZVAL_UNDEF(&_154$$29);
	ZVAL_UNDEF(&_155$$29);
	ZVAL_UNDEF(&_156$$30);
	ZVAL_UNDEF(&_157$$32);
	ZVAL_UNDEF(&_158$$32);
	ZVAL_UNDEF(&_159$$32);
	ZVAL_UNDEF(&_160$$32);
	ZVAL_UNDEF(&_161$$32);
	ZVAL_UNDEF(&_163$$32);
	ZVAL_UNDEF(&_164$$32);
	ZVAL_UNDEF(&_165$$32);
	ZVAL_UNDEF(&_166$$33);
	ZVAL_UNDEF(&_167$$33);
	ZVAL_UNDEF(&_168$$33);
	ZVAL_UNDEF(&_169$$33);
	ZVAL_UNDEF(&_170$$33);
	ZVAL_UNDEF(&_172$$33);
	ZVAL_UNDEF(&_173$$33);
	ZVAL_UNDEF(&_174$$33);
	ZVAL_UNDEF(&_180$$34);
	ZVAL_UNDEF(&_181$$34);
	ZVAL_UNDEF(&_183$$34);
	ZVAL_UNDEF(&_184$$34);
	ZVAL_UNDEF(&_186$$35);
	ZVAL_UNDEF(&_187$$35);
	ZVAL_UNDEF(&_189$$35);
	ZVAL_UNDEF(&_190$$35);
	ZVAL_UNDEF(&_191$$36);
	ZVAL_UNDEF(&_192$$36);
	ZVAL_UNDEF(&_194$$36);
	ZVAL_UNDEF(&_195$$36);
	ZVAL_UNDEF(&_196$$37);
	ZVAL_UNDEF(&_197$$37);
	ZVAL_UNDEF(&_199$$37);
	ZVAL_UNDEF(&_200$$37);
	ZVAL_UNDEF(&_201$$37);
	ZVAL_UNDEF(&_202$$37);
	ZVAL_UNDEF(&_203$$38);
	ZVAL_UNDEF(&_204$$38);
	ZVAL_UNDEF(&_206$$38);
	ZVAL_UNDEF(&_207$$38);
	ZVAL_UNDEF(&_208$$38);
	ZVAL_UNDEF(&_209$$39);
	ZVAL_UNDEF(&_210$$39);
	ZVAL_UNDEF(&_212$$39);
	ZVAL_UNDEF(&_213$$39);
	ZVAL_UNDEF(&_216);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_47$$11);
	ZVAL_UNDEF(&_127$$11);
	ZVAL_UNDEF(&_54$$12);
	ZVAL_UNDEF(&_71$$15);
	ZVAL_UNDEF(&_81$$16);
	ZVAL_UNDEF(&_101$$18);
	ZVAL_UNDEF(&_115$$21);
	ZVAL_UNDEF(&_143$$28);
	ZVAL_UNDEF(&_152$$29);
	ZVAL_UNDEF(&_162$$32);
	ZVAL_UNDEF(&_171$$33);
	ZVAL_UNDEF(&_182$$34);
	ZVAL_UNDEF(&_188$$35);
	ZVAL_UNDEF(&_193$$36);
	ZVAL_UNDEF(&_198$$37);
	ZVAL_UNDEF(&_205$$38);
	ZVAL_UNDEF(&_211$$39);

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
		zephir_create_array(&_4$$4, 2, 0);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "arr");
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getstyle", &_7, 0, &_6$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_4$$4, SL(":style"), &_5$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_4$$4, SL(":count"), zephir_fast_count_int(variable));
		ZEPHIR_CALL_FUNCTION(&_5$$4, "strtr", &_8, 103, &_0$$4, &_4$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_5$$4);
		zephir_is_iterable(variable, 0, "ice/dump.zep", 171);
		if (Z_TYPE_P(variable) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(variable), _11$$4, _12$$4, _9$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_12$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _12$$4);
				} else {
					ZVAL_LONG(&key, _11$$4);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _9$$4);
				ZEPHIR_CALL_FUNCTION(&_13$$5, "str_repeat", &_14, 86, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$5);
				zephir_read_property(&_16$$5, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_16$$5)) {
					ZEPHIR_INIT_NVAR(&_15$$5);
					ZVAL_STRING(&_15$$5, "[:key] => ");
				} else {
					ZEPHIR_INIT_NVAR(&_15$$5);
					ZVAL_STRING(&_15$$5, "[<span style=':style'>:key</span>] => ");
				}
				ZEPHIR_INIT_NVAR(&_17$$5);
				zephir_create_array(&_17$$5, 2, 0);
				ZEPHIR_INIT_NVAR(&_19$$5);
				ZVAL_STRING(&_19$$5, "arr");
				ZEPHIR_CALL_METHOD(&_18$$5, this_ptr, "getstyle", &_7, 0, &_19$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_17$$5, SL(":style"), &_18$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_17$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_18$$5, "strtr", &_8, 103, &_15$$5, &_17$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$5);
				ZEPHIR_CONCAT_VV(&_20$$5, &_13$$5, &_18$$5);
				zephir_concat_self(&output, &_20$$5);
				_21$$5 = ZEPHIR_IS_LONG(tab, 1);
				if (_21$$5) {
					_21$$5 = !ZEPHIR_IS_STRING(name, "");
				}
				_22$$5 = _21$$5;
				if (_22$$5) {
					_22$$5 = !(Z_TYPE_P(&key) == IS_LONG);
				}
				_23$$5 = _22$$5;
				if (_23$$5) {
					_23$$5 = ZEPHIR_IS_EQUAL(name, &key);
				}
				if (_23$$5) {
					continue;
				} else {
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "");
					ZVAL_LONG(&_26$$7, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_METHOD(&_24$$7, this_ptr, "output", &_27, 104, &value, &_25$$7, &_26$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZEPHIR_GET_CONSTANT(&_25$$7, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_28$$7);
					ZEPHIR_CONCAT_VV(&_28$$7, &_24$$7, &_25$$7);
					zephir_concat_self(&output, &_28$$7);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, variable, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$4, variable, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, variable, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, variable, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_29$$8, "str_repeat", &_14, 86, &space, tab);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_30$$8);
					zephir_read_property(&_31$$8, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_31$$8)) {
						ZEPHIR_INIT_NVAR(&_30$$8);
						ZVAL_STRING(&_30$$8, "[:key] => ");
					} else {
						ZEPHIR_INIT_NVAR(&_30$$8);
						ZVAL_STRING(&_30$$8, "[<span style=':style'>:key</span>] => ");
					}
					ZEPHIR_INIT_NVAR(&_32$$8);
					zephir_create_array(&_32$$8, 2, 0);
					ZEPHIR_INIT_NVAR(&_34$$8);
					ZVAL_STRING(&_34$$8, "arr");
					ZEPHIR_CALL_METHOD(&_33$$8, this_ptr, "getstyle", &_7, 0, &_34$$8);
					zephir_check_call_status();
					zephir_array_update_string(&_32$$8, SL(":style"), &_33$$8, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_32$$8, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_33$$8, "strtr", &_8, 103, &_30$$8, &_32$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_35$$8);
					ZEPHIR_CONCAT_VV(&_35$$8, &_29$$8, &_33$$8);
					zephir_concat_self(&output, &_35$$8);
					_36$$8 = ZEPHIR_IS_LONG(tab, 1);
					if (_36$$8) {
						_36$$8 = !ZEPHIR_IS_STRING(name, "");
					}
					_37$$8 = _36$$8;
					if (_37$$8) {
						_37$$8 = !(Z_TYPE_P(&key) == IS_LONG);
					}
					_38$$8 = _37$$8;
					if (_38$$8) {
						_38$$8 = ZEPHIR_IS_EQUAL(name, &key);
					}
					if (_38$$8) {
						continue;
					} else {
						ZEPHIR_INIT_NVAR(&_40$$10);
						ZVAL_STRING(&_40$$10, "");
						ZVAL_LONG(&_41$$10, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_METHOD(&_39$$10, this_ptr, "output", &_27, 104, &value, &_40$$10, &_41$$10);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_40$$10);
						ZEPHIR_GET_CONSTANT(&_40$$10, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_42$$10);
						ZEPHIR_CONCAT_VV(&_42$$10, &_39$$10, &_40$$10);
						zephir_concat_self(&output, &_42$$10);
					}
				ZEPHIR_CALL_METHOD(NULL, variable, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_43$$4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_44$$4, "str_repeat", &_14, 86, &space, &_43$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_44$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&className$$11);
		zephir_get_class(&className$$11, variable, 0);
		ZEPHIR_INIT_VAR(&_45$$11);
		zephir_read_property(&_46$$11, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_46$$11)) {
			ZEPHIR_INIT_NVAR(&_45$$11);
			ZVAL_STRING(&_45$$11, "object :class");
		} else {
			ZEPHIR_INIT_NVAR(&_45$$11);
			ZVAL_STRING(&_45$$11, "<b style=':style'>object</b> :class");
		}
		ZEPHIR_INIT_VAR(&_47$$11);
		zephir_create_array(&_47$$11, 2, 0);
		ZEPHIR_INIT_VAR(&_49$$11);
		ZVAL_STRING(&_49$$11, "obj");
		ZEPHIR_CALL_METHOD(&_48$$11, this_ptr, "getstyle", &_7, 0, &_49$$11);
		zephir_check_call_status();
		zephir_array_update_string(&_47$$11, SL(":style"), &_48$$11, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_47$$11, SL(":class"), &className$$11, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_48$$11, "strtr", &_8, 103, &_45$$11, &_47$$11);
		zephir_check_call_status();
		zephir_concat_self(&output, &_48$$11);
		ZEPHIR_CALL_FUNCTION(&_50$$11, "get_parent_class", &_51, 105, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_50$$11)) {
			ZEPHIR_INIT_VAR(&_52$$12);
			zephir_read_property(&_53$$12, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_53$$12)) {
				ZEPHIR_INIT_NVAR(&_52$$12);
				ZVAL_STRING(&_52$$12, " extends :parent");
			} else {
				ZEPHIR_INIT_NVAR(&_52$$12);
				ZVAL_STRING(&_52$$12, " <b style=':style'>extends</b> :parent");
			}
			ZEPHIR_INIT_VAR(&_54$$12);
			zephir_create_array(&_54$$12, 2, 0);
			ZEPHIR_INIT_VAR(&_56$$12);
			ZVAL_STRING(&_56$$12, "obj");
			ZEPHIR_CALL_METHOD(&_55$$12, this_ptr, "getstyle", &_7, 0, &_56$$12);
			zephir_check_call_status();
			zephir_array_update_string(&_54$$12, SL(":style"), &_55$$12, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_55$$12, "get_parent_class", &_51, 105, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_54$$12, SL(":parent"), &_55$$12, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_55$$12, "strtr", &_8, 103, &_52$$12, &_54$$12);
			zephir_check_call_status();
			zephir_concat_self(&output, &_55$$12);
		}
		ZEPHIR_INIT_NVAR(&_49$$11);
		ZEPHIR_GET_CONSTANT(&_49$$11, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_57$$11);
		ZEPHIR_CONCAT_SV(&_57$$11, " (", &_49$$11);
		zephir_concat_self(&output, &_57$$11);
		zephir_read_property(&_58$$11, this_ptr, SL("skip"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_59$$11, this_ptr, SL("detailed"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&className$$11, &_58$$11)) {
			ZEPHIR_CALL_FUNCTION(&_60$$13, "str_repeat", &_14, 86, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_61$$13);
			ZEPHIR_GET_CONSTANT(&_61$$13, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_62$$13);
			ZEPHIR_CONCAT_VSV(&_62$$13, &_60$$13, "[skipped]", &_61$$13);
			zephir_concat_self(&output, &_62$$13);
		} else if (!(zephir_is_true(&_59$$11))) {
			ZEPHIR_CALL_FUNCTION(&_63$$14, "get_object_vars", NULL, 106, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_63$$14, 0, "ice/dump.zep", 194);
			if (Z_TYPE_P(&_63$$14) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_63$$14), _66$$14, _67$$14, _64$$14)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_67$$14 != NULL) { 
						ZVAL_STR_COPY(&key, _67$$14);
					} else {
						ZVAL_LONG(&key, _66$$14);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _64$$14);
					ZEPHIR_CALL_FUNCTION(&_68$$15, "str_repeat", &_14, 86, &space, tab);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_69$$15);
					zephir_read_property(&_70$$15, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_70$$15)) {
						ZEPHIR_INIT_NVAR(&_69$$15);
						ZVAL_STRING(&_69$$15, "->:key (:type) = ");
					} else {
						ZEPHIR_INIT_NVAR(&_69$$15);
						ZVAL_STRING(&_69$$15, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
					}
					ZEPHIR_INIT_NVAR(&_71$$15);
					zephir_create_array(&_71$$15, 3, 0);
					ZEPHIR_INIT_NVAR(&_73$$15);
					ZVAL_STRING(&_73$$15, "obj");
					ZEPHIR_CALL_METHOD(&_72$$15, this_ptr, "getstyle", &_7, 0, &_73$$15);
					zephir_check_call_status();
					zephir_array_update_string(&_71$$15, SL(":style"), &_72$$15, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_71$$15, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					add_assoc_stringl_ex(&_71$$15, SL(":type"), SL("public"));
					ZEPHIR_CALL_FUNCTION(&_72$$15, "strtr", &_8, 103, &_69$$15, &_71$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_74$$15);
					ZEPHIR_CONCAT_VV(&_74$$15, &_68$$15, &_72$$15);
					zephir_concat_self(&output, &_74$$15);
					ZEPHIR_INIT_NVAR(&_73$$15);
					ZVAL_STRING(&_73$$15, "");
					ZVAL_LONG(&_76$$15, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_METHOD(&_75$$15, this_ptr, "output", &_27, 104, &value, &_73$$15, &_76$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_73$$15);
					ZEPHIR_GET_CONSTANT(&_73$$15, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_77$$15);
					ZEPHIR_CONCAT_VV(&_77$$15, &_75$$15, &_73$$15);
					zephir_concat_self(&output, &_77$$15);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_63$$14, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_65$$14, &_63$$14, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_65$$14)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, &_63$$14, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, &_63$$14, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_78$$16, "str_repeat", &_14, 86, &space, tab);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_79$$16);
						zephir_read_property(&_80$$16, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_80$$16)) {
							ZEPHIR_INIT_NVAR(&_79$$16);
							ZVAL_STRING(&_79$$16, "->:key (:type) = ");
						} else {
							ZEPHIR_INIT_NVAR(&_79$$16);
							ZVAL_STRING(&_79$$16, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
						}
						ZEPHIR_INIT_NVAR(&_81$$16);
						zephir_create_array(&_81$$16, 3, 0);
						ZEPHIR_INIT_NVAR(&_83$$16);
						ZVAL_STRING(&_83$$16, "obj");
						ZEPHIR_CALL_METHOD(&_82$$16, this_ptr, "getstyle", &_7, 0, &_83$$16);
						zephir_check_call_status();
						zephir_array_update_string(&_81$$16, SL(":style"), &_82$$16, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_81$$16, SL(":key"), &key, PH_COPY | PH_SEPARATE);
						add_assoc_stringl_ex(&_81$$16, SL(":type"), SL("public"));
						ZEPHIR_CALL_FUNCTION(&_82$$16, "strtr", &_8, 103, &_79$$16, &_81$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_84$$16);
						ZEPHIR_CONCAT_VV(&_84$$16, &_78$$16, &_82$$16);
						zephir_concat_self(&output, &_84$$16);
						ZEPHIR_INIT_NVAR(&_83$$16);
						ZVAL_STRING(&_83$$16, "");
						ZVAL_LONG(&_86$$16, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_METHOD(&_85$$16, this_ptr, "output", &_27, 104, &value, &_83$$16, &_86$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_83$$16);
						ZEPHIR_GET_CONSTANT(&_83$$16, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_87$$16);
						ZEPHIR_CONCAT_VV(&_87$$16, &_85$$16, &_83$$16);
						zephir_concat_self(&output, &_87$$16);
					ZEPHIR_CALL_METHOD(NULL, &_63$$14, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			ZEPHIR_INIT_VAR(&reflect$$17);
			ZVAL_STRING(&reflect$$17, "ReflectionClass");
			ZEPHIR_INIT_VAR(&_88$$17);
			zephir_fetch_safe_class(&_89$$17, &reflect$$17);
			_90$$17 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_89$$17), Z_STRLEN_P(&_89$$17), ZEND_FETCH_CLASS_AUTO);
			if(!_90$$17) {
				RETURN_MM_NULL();
			}
			object_init_ex(&_88$$17, _90$$17);
			if (zephir_has_constructor(&_88$$17)) {
				ZEPHIR_CALL_METHOD(NULL, &_88$$17, "__construct", NULL, 0, variable);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_91$$17, &_88$$17, "getproperties", NULL, 0);
			zephir_check_call_status();
			zephir_is_iterable(&_91$$17, 0, "ice/dump.zep", 217);
			if (Z_TYPE_P(&_91$$17) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_91$$17), _92$$17)
				{
					ZEPHIR_INIT_NVAR(&attr);
					ZVAL_COPY(&attr, _92$$17);
					ZEPHIR_CALL_METHOD(&key, &attr, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_STRING(&type, "public");
					ZEPHIR_CALL_METHOD(&_94$$18, &attr, "isprotected", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&_94$$18)) {
						ZVAL_BOOL(&_95$$19, 1);
						ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_95$$19);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "protected");
					}
					ZEPHIR_CALL_METHOD(&_96$$18, &attr, "isprivate", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&_96$$18)) {
						ZVAL_BOOL(&_97$$20, 1);
						ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_97$$20);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "private");
					}
					ZEPHIR_CALL_METHOD(&value, &attr, "getvalue", NULL, 0, variable);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_98$$18, "str_repeat", &_14, 86, &space, tab);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_99$$18);
					zephir_read_property(&_100$$18, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_100$$18)) {
						ZEPHIR_INIT_NVAR(&_99$$18);
						ZVAL_STRING(&_99$$18, "->:key (:type) = ");
					} else {
						ZEPHIR_INIT_NVAR(&_99$$18);
						ZVAL_STRING(&_99$$18, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
					}
					ZEPHIR_INIT_NVAR(&_101$$18);
					zephir_create_array(&_101$$18, 3, 0);
					ZEPHIR_INIT_NVAR(&_103$$18);
					ZVAL_STRING(&_103$$18, "obj");
					ZEPHIR_CALL_METHOD(&_102$$18, this_ptr, "getstyle", &_7, 0, &_103$$18);
					zephir_check_call_status();
					zephir_array_update_string(&_101$$18, SL(":style"), &_102$$18, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_101$$18, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_101$$18, SL(":type"), &type, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_102$$18, "strtr", &_8, 103, &_99$$18, &_101$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_104$$18);
					ZEPHIR_CONCAT_VV(&_104$$18, &_98$$18, &_102$$18);
					zephir_concat_self(&output, &_104$$18);
					ZEPHIR_INIT_NVAR(&_103$$18);
					ZVAL_STRING(&_103$$18, "");
					ZVAL_LONG(&_106$$18, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_METHOD(&_105$$18, this_ptr, "output", &_27, 104, &value, &_103$$18, &_106$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_103$$18);
					ZEPHIR_GET_CONSTANT(&_103$$18, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_107$$18);
					ZEPHIR_CONCAT_VV(&_107$$18, &_105$$18, &_103$$18);
					zephir_concat_self(&output, &_107$$18);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_91$$17, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_93$$17, &_91$$17, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_93$$17)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&attr, &_91$$17, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&key, &attr, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "public");
						ZEPHIR_CALL_METHOD(&_108$$21, &attr, "isprotected", NULL, 0);
						zephir_check_call_status();
						if (zephir_is_true(&_108$$21)) {
							ZVAL_BOOL(&_109$$22, 1);
							ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_109$$22);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							ZVAL_STRING(&type, "protected");
						}
						ZEPHIR_CALL_METHOD(&_110$$21, &attr, "isprivate", NULL, 0);
						zephir_check_call_status();
						if (zephir_is_true(&_110$$21)) {
							ZVAL_BOOL(&_111$$23, 1);
							ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_111$$23);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							ZVAL_STRING(&type, "private");
						}
						ZEPHIR_CALL_METHOD(&value, &attr, "getvalue", NULL, 0, variable);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_112$$21, "str_repeat", &_14, 86, &space, tab);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_113$$21);
						zephir_read_property(&_114$$21, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_114$$21)) {
							ZEPHIR_INIT_NVAR(&_113$$21);
							ZVAL_STRING(&_113$$21, "->:key (:type) = ");
						} else {
							ZEPHIR_INIT_NVAR(&_113$$21);
							ZVAL_STRING(&_113$$21, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
						}
						ZEPHIR_INIT_NVAR(&_115$$21);
						zephir_create_array(&_115$$21, 3, 0);
						ZEPHIR_INIT_NVAR(&_117$$21);
						ZVAL_STRING(&_117$$21, "obj");
						ZEPHIR_CALL_METHOD(&_116$$21, this_ptr, "getstyle", &_7, 0, &_117$$21);
						zephir_check_call_status();
						zephir_array_update_string(&_115$$21, SL(":style"), &_116$$21, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_115$$21, SL(":key"), &key, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_115$$21, SL(":type"), &type, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_116$$21, "strtr", &_8, 103, &_113$$21, &_115$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_118$$21);
						ZEPHIR_CONCAT_VV(&_118$$21, &_112$$21, &_116$$21);
						zephir_concat_self(&output, &_118$$21);
						ZEPHIR_INIT_NVAR(&_117$$21);
						ZVAL_STRING(&_117$$21, "");
						ZVAL_LONG(&_120$$21, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_METHOD(&_119$$21, this_ptr, "output", &_27, 104, &value, &_117$$21, &_120$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_117$$21);
						ZEPHIR_GET_CONSTANT(&_117$$21, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_121$$21);
						ZEPHIR_CONCAT_VV(&_121$$21, &_119$$21, &_117$$21);
						zephir_concat_self(&output, &_121$$21);
					ZEPHIR_CALL_METHOD(NULL, &_91$$17, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&attr);
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 107, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_122$$11, "str_repeat", &_14, 86, &space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_123$$11);
		zephir_read_property(&_124$$11, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_124$$11)) {
			ZEPHIR_INIT_VAR(&_125$$11);
			ZEPHIR_GET_CONSTANT(&_125$$11, "PHP_EOL");
			ZEPHIR_INIT_NVAR(&_123$$11);
			ZEPHIR_CONCAT_SV(&_123$$11, ":class methods: (:count) (", &_125$$11);
		} else {
			ZEPHIR_INIT_VAR(&_126$$11);
			ZEPHIR_GET_CONSTANT(&_126$$11, "PHP_EOL");
			ZEPHIR_INIT_NVAR(&_123$$11);
			ZEPHIR_CONCAT_SV(&_123$$11, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (", &_126$$11);
		}
		ZEPHIR_INIT_VAR(&_127$$11);
		zephir_create_array(&_127$$11, 3, 0);
		ZEPHIR_INIT_VAR(&_129$$11);
		ZVAL_STRING(&_129$$11, "obj");
		ZEPHIR_CALL_METHOD(&_128$$11, this_ptr, "getstyle", &_7, 0, &_129$$11);
		zephir_check_call_status();
		zephir_array_update_string(&_127$$11, SL(":style"), &_128$$11, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_127$$11, SL(":class"), &className$$11, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_127$$11, SL(":count"), zephir_fast_count_int(&attr));
		ZEPHIR_CALL_FUNCTION(&_128$$11, "strtr", &_8, 103, &_123$$11, &_127$$11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_130$$11);
		ZEPHIR_CONCAT_VV(&_130$$11, &_122$$11, &_128$$11);
		zephir_concat_self(&output, &_130$$11);
		zephir_read_property(&_131$$11, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&className$$11, &_131$$11)) {
			ZEPHIR_CALL_FUNCTION(&_132$$24, "str_repeat", &_14, 86, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_133$$24);
			ZEPHIR_GET_CONSTANT(&_133$$24, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_134$$24);
			ZEPHIR_CONCAT_VSV(&_134$$24, &_132$$24, "[already listed]", &_133$$24);
			zephir_concat_self(&output, &_134$$24);
		} else {
			zephir_is_iterable(&attr, 0, "ice/dump.zep", 235);
			if (Z_TYPE_P(&attr) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _135$$25)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _135$$25);
					zephir_read_property(&_137$$26, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_fast_in_array(&className$$11, &_137$$26))) {
						zephir_update_property_array_append(this_ptr, SL("methods"), &className$$11);
					}
					if (ZEPHIR_IS_STRING(&value, "__construct")) {
						ZVAL_LONG(&_138$$28, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_FUNCTION(&_139$$28, "str_repeat", &_14, 86, &space, &_138$$28);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_140$$28);
						zephir_read_property(&_138$$28, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_138$$28)) {
							ZEPHIR_INIT_NVAR(&_141$$28);
							ZEPHIR_GET_CONSTANT(&_141$$28, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_140$$28);
							ZEPHIR_CONCAT_SV(&_140$$28, "->:method(); [constructor]", &_141$$28);
						} else {
							ZEPHIR_INIT_NVAR(&_142$$28);
							ZEPHIR_GET_CONSTANT(&_142$$28, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_140$$28);
							ZEPHIR_CONCAT_SV(&_140$$28, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]", &_142$$28);
						}
						ZEPHIR_INIT_NVAR(&_143$$28);
						zephir_create_array(&_143$$28, 2, 0);
						ZEPHIR_INIT_NVAR(&_145$$28);
						ZVAL_STRING(&_145$$28, "obj");
						ZEPHIR_CALL_METHOD(&_144$$28, this_ptr, "getstyle", &_7, 0, &_145$$28);
						zephir_check_call_status();
						zephir_array_update_string(&_143$$28, SL(":style"), &_144$$28, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_143$$28, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_144$$28, "strtr", &_8, 103, &_140$$28, &_143$$28);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_146$$28);
						ZEPHIR_CONCAT_VV(&_146$$28, &_139$$28, &_144$$28);
						zephir_concat_self(&output, &_146$$28);
					} else {
						ZVAL_LONG(&_147$$29, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_FUNCTION(&_148$$29, "str_repeat", &_14, 86, &space, &_147$$29);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_149$$29);
						zephir_read_property(&_147$$29, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_147$$29)) {
							ZEPHIR_INIT_NVAR(&_150$$29);
							ZEPHIR_GET_CONSTANT(&_150$$29, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_149$$29);
							ZEPHIR_CONCAT_SV(&_149$$29, "->:method();", &_150$$29);
						} else {
							ZEPHIR_INIT_NVAR(&_151$$29);
							ZEPHIR_GET_CONSTANT(&_151$$29, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_149$$29);
							ZEPHIR_CONCAT_SV(&_149$$29, "-><span style=':style'>:method</span>();", &_151$$29);
						}
						ZEPHIR_INIT_NVAR(&_152$$29);
						zephir_create_array(&_152$$29, 2, 0);
						ZEPHIR_INIT_NVAR(&_154$$29);
						ZVAL_STRING(&_154$$29, "obj");
						ZEPHIR_CALL_METHOD(&_153$$29, this_ptr, "getstyle", &_7, 0, &_154$$29);
						zephir_check_call_status();
						zephir_array_update_string(&_152$$29, SL(":style"), &_153$$29, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_152$$29, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_153$$29, "strtr", &_8, 103, &_149$$29, &_152$$29);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_155$$29);
						ZEPHIR_CONCAT_VV(&_155$$29, &_148$$29, &_153$$29);
						zephir_concat_self(&output, &_155$$29);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attr, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_136$$25, &attr, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_136$$25)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, &attr, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property(&_156$$30, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
						if (!(zephir_fast_in_array(&className$$11, &_156$$30))) {
							zephir_update_property_array_append(this_ptr, SL("methods"), &className$$11);
						}
						if (ZEPHIR_IS_STRING(&value, "__construct")) {
							ZVAL_LONG(&_157$$32, (zephir_get_numberval(tab) + 1));
							ZEPHIR_CALL_FUNCTION(&_158$$32, "str_repeat", &_14, 86, &space, &_157$$32);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_159$$32);
							zephir_read_property(&_157$$32, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_157$$32)) {
								ZEPHIR_INIT_NVAR(&_160$$32);
								ZEPHIR_GET_CONSTANT(&_160$$32, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_159$$32);
								ZEPHIR_CONCAT_SV(&_159$$32, "->:method(); [constructor]", &_160$$32);
							} else {
								ZEPHIR_INIT_NVAR(&_161$$32);
								ZEPHIR_GET_CONSTANT(&_161$$32, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_159$$32);
								ZEPHIR_CONCAT_SV(&_159$$32, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]", &_161$$32);
							}
							ZEPHIR_INIT_NVAR(&_162$$32);
							zephir_create_array(&_162$$32, 2, 0);
							ZEPHIR_INIT_NVAR(&_164$$32);
							ZVAL_STRING(&_164$$32, "obj");
							ZEPHIR_CALL_METHOD(&_163$$32, this_ptr, "getstyle", &_7, 0, &_164$$32);
							zephir_check_call_status();
							zephir_array_update_string(&_162$$32, SL(":style"), &_163$$32, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_162$$32, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_FUNCTION(&_163$$32, "strtr", &_8, 103, &_159$$32, &_162$$32);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_165$$32);
							ZEPHIR_CONCAT_VV(&_165$$32, &_158$$32, &_163$$32);
							zephir_concat_self(&output, &_165$$32);
						} else {
							ZVAL_LONG(&_166$$33, (zephir_get_numberval(tab) + 1));
							ZEPHIR_CALL_FUNCTION(&_167$$33, "str_repeat", &_14, 86, &space, &_166$$33);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_168$$33);
							zephir_read_property(&_166$$33, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_166$$33)) {
								ZEPHIR_INIT_NVAR(&_169$$33);
								ZEPHIR_GET_CONSTANT(&_169$$33, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_168$$33);
								ZEPHIR_CONCAT_SV(&_168$$33, "->:method();", &_169$$33);
							} else {
								ZEPHIR_INIT_NVAR(&_170$$33);
								ZEPHIR_GET_CONSTANT(&_170$$33, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_168$$33);
								ZEPHIR_CONCAT_SV(&_168$$33, "-><span style=':style'>:method</span>();", &_170$$33);
							}
							ZEPHIR_INIT_NVAR(&_171$$33);
							zephir_create_array(&_171$$33, 2, 0);
							ZEPHIR_INIT_NVAR(&_173$$33);
							ZVAL_STRING(&_173$$33, "obj");
							ZEPHIR_CALL_METHOD(&_172$$33, this_ptr, "getstyle", &_7, 0, &_173$$33);
							zephir_check_call_status();
							zephir_array_update_string(&_171$$33, SL(":style"), &_172$$33, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_171$$33, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_FUNCTION(&_172$$33, "strtr", &_8, 103, &_168$$33, &_171$$33);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_174$$33);
							ZEPHIR_CONCAT_VV(&_174$$33, &_167$$33, &_172$$33);
							zephir_concat_self(&output, &_174$$33);
						}
					ZEPHIR_CALL_METHOD(NULL, &attr, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_CALL_FUNCTION(&_175$$25, "str_repeat", &_14, 86, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_176$$25);
			ZEPHIR_GET_CONSTANT(&_176$$25, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_177$$25);
			ZEPHIR_CONCAT_VSV(&_177$$25, &_175$$25, ")", &_176$$25);
			zephir_concat_self(&output, &_177$$25);
		}
		ZVAL_LONG(&_178$$11, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_179$$11, "str_repeat", &_14, 86, &space, &_178$$11);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_179$$11, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_180$$34);
		zephir_read_property(&_181$$34, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_181$$34)) {
			ZEPHIR_INIT_NVAR(&_180$$34);
			ZVAL_STRING(&_180$$34, "integer (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_180$$34);
			ZVAL_STRING(&_180$$34, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_182$$34);
		zephir_create_array(&_182$$34, 2, 0);
		ZEPHIR_INIT_VAR(&_184$$34);
		ZVAL_STRING(&_184$$34, "int");
		ZEPHIR_CALL_METHOD(&_183$$34, this_ptr, "getstyle", &_7, 0, &_184$$34);
		zephir_check_call_status();
		zephir_array_update_string(&_182$$34, SL(":style"), &_183$$34, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_182$$34, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_183$$34, "strtr", &_8, 103, &_180$$34, &_182$$34);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_183$$34);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_185, "is_float", NULL, 108, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_185)) {
		ZEPHIR_INIT_VAR(&_186$$35);
		zephir_read_property(&_187$$35, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_187$$35)) {
			ZEPHIR_INIT_NVAR(&_186$$35);
			ZVAL_STRING(&_186$$35, "float (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_186$$35);
			ZVAL_STRING(&_186$$35, "<b style=':style'>float</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_188$$35);
		zephir_create_array(&_188$$35, 2, 0);
		ZEPHIR_INIT_VAR(&_190$$35);
		ZVAL_STRING(&_190$$35, "float");
		ZEPHIR_CALL_METHOD(&_189$$35, this_ptr, "getstyle", &_7, 0, &_190$$35);
		zephir_check_call_status();
		zephir_array_update_string(&_188$$35, SL(":style"), &_189$$35, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_188$$35, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_189$$35, "strtr", &_8, 103, &_186$$35, &_188$$35);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_189$$35);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_191$$36);
		zephir_read_property(&_192$$36, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_192$$36)) {
			ZEPHIR_INIT_NVAR(&_191$$36);
			ZVAL_STRING(&_191$$36, "numeric string (:length) \":var\"");
		} else {
			ZEPHIR_INIT_NVAR(&_191$$36);
			ZVAL_STRING(&_191$$36, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		}
		ZEPHIR_INIT_VAR(&_193$$36);
		zephir_create_array(&_193$$36, 3, 0);
		ZEPHIR_INIT_VAR(&_195$$36);
		ZVAL_STRING(&_195$$36, "num");
		ZEPHIR_CALL_METHOD(&_194$$36, this_ptr, "getstyle", &_7, 0, &_195$$36);
		zephir_check_call_status();
		zephir_array_update_string(&_193$$36, SL(":style"), &_194$$36, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_193$$36, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_193$$36, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_194$$36, "strtr", &_8, 103, &_191$$36, &_193$$36);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_194$$36);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_196$$37);
		zephir_read_property(&_197$$37, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_197$$37)) {
			ZEPHIR_INIT_NVAR(&_196$$37);
			ZVAL_STRING(&_196$$37, "string (:length) \":var\"");
		} else {
			ZEPHIR_INIT_NVAR(&_196$$37);
			ZVAL_STRING(&_196$$37, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		}
		ZEPHIR_INIT_VAR(&_198$$37);
		zephir_create_array(&_198$$37, 3, 0);
		ZEPHIR_INIT_VAR(&_200$$37);
		ZVAL_STRING(&_200$$37, "str");
		ZEPHIR_CALL_METHOD(&_199$$37, this_ptr, "getstyle", &_7, 0, &_200$$37);
		zephir_check_call_status();
		zephir_array_update_string(&_198$$37, SL(":style"), &_199$$37, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_198$$37, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_201$$37, 4);
		ZEPHIR_INIT_NVAR(&_200$$37);
		ZVAL_STRING(&_200$$37, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_199$$37, "htmlentities", NULL, 109, variable, &_201$$37, &_200$$37);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_202$$37, "nl2br", NULL, 110, &_199$$37);
		zephir_check_call_status();
		zephir_array_update_string(&_198$$37, SL(":var"), &_202$$37, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_202$$37, "strtr", &_8, 103, &_196$$37, &_198$$37);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_202$$37);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_203$$38);
		zephir_read_property(&_204$$38, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_204$$38)) {
			ZEPHIR_INIT_NVAR(&_203$$38);
			ZVAL_STRING(&_203$$38, "boolean (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_203$$38);
			ZVAL_STRING(&_203$$38, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_205$$38);
		zephir_create_array(&_205$$38, 2, 0);
		ZEPHIR_INIT_VAR(&_207$$38);
		ZVAL_STRING(&_207$$38, "bool");
		ZEPHIR_CALL_METHOD(&_206$$38, this_ptr, "getstyle", &_7, 0, &_207$$38);
		zephir_check_call_status();
		zephir_array_update_string(&_205$$38, SL(":style"), &_206$$38, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_208$$38);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_208$$38);
			ZVAL_STRING(&_208$$38, "true");
		} else {
			ZEPHIR_INIT_NVAR(&_208$$38);
			ZVAL_STRING(&_208$$38, "false");
		}
		zephir_array_update_string(&_205$$38, SL(":var"), &_208$$38, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_206$$38, "strtr", &_8, 103, &_203$$38, &_205$$38);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_206$$38);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_209$$39);
		zephir_read_property(&_210$$39, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_210$$39)) {
			ZEPHIR_INIT_NVAR(&_209$$39);
			ZVAL_STRING(&_209$$39, "null");
		} else {
			ZEPHIR_INIT_NVAR(&_209$$39);
			ZVAL_STRING(&_209$$39, "<b style=':style'>null</b>");
		}
		ZEPHIR_INIT_VAR(&_211$$39);
		zephir_create_array(&_211$$39, 1, 0);
		ZEPHIR_INIT_VAR(&_213$$39);
		ZVAL_STRING(&_213$$39, "null");
		ZEPHIR_CALL_METHOD(&_212$$39, this_ptr, "getstyle", &_7, 0, &_213$$39);
		zephir_check_call_status();
		zephir_array_update_string(&_211$$39, SL(":style"), &_212$$39, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_212$$39, "strtr", &_8, 103, &_209$$39, &_211$$39);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_212$$39);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_214);
	zephir_read_property(&_215, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_215)) {
		ZEPHIR_INIT_NVAR(&_214);
		ZVAL_STRING(&_214, "(:var)");
	} else {
		ZEPHIR_INIT_NVAR(&_214);
		ZVAL_STRING(&_214, "(<span style=':style'>:var</span>)");
	}
	ZEPHIR_INIT_VAR(&_216);
	zephir_create_array(&_216, 2, 0);
	ZEPHIR_INIT_VAR(&_218);
	ZVAL_STRING(&_218, "other");
	ZEPHIR_CALL_METHOD(&_217, this_ptr, "getstyle", &_7, 0, &_218);
	zephir_check_call_status();
	zephir_array_update_string(&_216, SL(":style"), &_217, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_216, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_217, "strtr", &_8, 103, &_214, &_216);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_217);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_create_array(&_2, 2, 0);
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

	zend_string *_4;
	zend_ulong _3;
	zval key, value, output, _0, *_1, _2, _5$$3, _6$$3, _8$$4, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_is_iterable(&_0, 0, "ice/dump.zep", 308);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_CONCAT_SV(&_6$$3, "var ", &key);
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "one", &_7, 0, &value, &_6$$3);
			zephir_check_call_status();
			zephir_concat_self(&output, &_5$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_CONCAT_SV(&_9$$4, "var ", &key);
				ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "one", &_7, 0, &value, &_9$$4);
				zephir_check_call_status();
				zephir_concat_self(&output, &_8$$4);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_create_array(&range, 2, 0);
	add_assoc_long_ex(&range, SL("start"), (line - padding));
	add_assoc_long_ex(&range, SL("end"), (line + padding));
	zephir_array_fetch_string(&_3, &range, SL("end"), PH_NOISY | PH_READONLY, "ice/dump.zep", 339);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_LONG(&_4, zephir_fast_strlen_ev(&_3));
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVS(&_5, "% ", &_4, "d");
	ZEPHIR_CPY_WRT(&format, &_5);
	ZEPHIR_INIT_VAR(&lines);
	array_init(&lines);
	ZEPHIR_CALL_FUNCTION(&row, "fgets", &_6, 113, &file);
	zephir_check_call_status();
	while (1) {
		if (!(!(zephir_feof(&file)))) {
			break;
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(&row)) {
			break;
		}
		i++;
		zephir_array_fetch_string(&_7$$4, &range, SL("end"), PH_NOISY | PH_READONLY, "ice/dump.zep", 351);
		if (ZEPHIR_LT_LONG(&_7$$4, i)) {
			break;
		}
		zephir_array_fetch_string(&_8$$4, &range, SL("start"), PH_NOISY | PH_READONLY, "ice/dump.zep", 355);
		if (ZEPHIR_LE_LONG(&_8$$4, i)) {
			ZVAL_LONG(&_9$$7, 0);
			ZEPHIR_INIT_NVAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "utf-8");
			ZEPHIR_CALL_FUNCTION(&_11$$7, "htmlspecialchars", &_12, 114, &row, &_9$$7, &_10$$7);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&row, &_11$$7);
			if (i == line) {
				ZEPHIR_INIT_NVAR(&_13$$8);
				zephir_read_property(&_14$$8, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_14$$8)) {
					ZEPHIR_INIT_NVAR(&_13$$8);
					ZVAL_STRING(&_13$$8, ":var");
				} else {
					ZEPHIR_INIT_NVAR(&_13$$8);
					ZVAL_STRING(&_13$$8, "<div class=':class'>:var</div>");
				}
				ZEPHIR_INIT_NVAR(&_15$$8);
				zephir_create_array(&_15$$8, 2, 0);
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
				ZEPHIR_INIT_NVAR(&_23$$9);
				zephir_read_property(&_24$$9, this_ptr, SL("plain"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_24$$9)) {
					ZEPHIR_INIT_NVAR(&_23$$9);
					ZVAL_STRING(&_23$$9, ":var");
				} else {
					ZEPHIR_INIT_NVAR(&_23$$9);
					ZVAL_STRING(&_23$$9, "<div class=':class'>:var</div>");
				}
				ZEPHIR_INIT_NVAR(&_25$$9);
				zephir_create_array(&_25$$9, 2, 0);
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
	zephir_fclose(&file);
	RETURN_CCTOR(&lines);

}

zend_object *zephir_init_properties_Ice_Dump(zend_class_entry *class_type TSRMLS_DC) {

		zval _5$$5;
	zval _0, _2, _4, _1$$3, _3$$4, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
			zephir_create_array(&_5$$5, 1, 0);
			ZEPHIR_INIT_VAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "Ice\\Di");
			zephir_array_fast_append(&_5$$5, &_6$$5);
			zephir_update_property_zval(this_ptr, SL("skip"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

