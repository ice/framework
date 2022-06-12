
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
 * @copyright   (c) 2014-2021 Ice Team
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
ZEPHIR_INIT_CLASS(Ice_Dump)
{
	ZEPHIR_REGISTER_CLASS(Ice, Dump, ice, dump, ice_dump_method_entry, 0);

	zend_declare_property_bool(ice_dump_ce, SL("detailed"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_bool(ice_dump_ce, SL("plain"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_dump_ce, SL("skip"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_dump_ce, SL("methods"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_dump_ce, SL("objects"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_dump_ce, SL("styles"), ZEND_ACC_PROTECTED);
	ice_dump_ce->create_object = zephir_init_properties_Ice_Dump;

	return SUCCESS;
}

PHP_METHOD(Ice_Dump, getDetailed)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "detailed");
}

PHP_METHOD(Ice_Dump, setDetailed)
{
	zval *detailed, detailed_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&detailed_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(detailed)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &detailed);


	zephir_update_property_zval(this_ptr, ZEND_STRL("detailed"), detailed);
	RETURN_THISW();
}

PHP_METHOD(Ice_Dump, getPlain)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "plain");
}

PHP_METHOD(Ice_Dump, setPlain)
{
	zval *plain, plain_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&plain_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(plain)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &plain);


	zephir_update_property_zval(this_ptr, ZEND_STRL("plain"), plain);
	RETURN_THISW();
}

PHP_METHOD(Ice_Dump, getSkip)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "skip");
}

PHP_METHOD(Ice_Dump, setSkip)
{
	zval *skip, skip_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&skip_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(skip)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &skip);


	zephir_update_property_zval(this_ptr, ZEND_STRL("skip"), skip);
	RETURN_THISW();
}

/**
 * Dump constructor
 *
 * @param boolean detailed debug object's private and protected properties
 * @param mixed styles
 */
PHP_METHOD(Ice_Dump, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *detailed_param = NULL, *styles = NULL, styles_sub, __$true, __$false;
	zend_bool detailed;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&styles_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(detailed)
		Z_PARAM_ZVAL(styles)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		zephir_update_property_zval(this_ptr, ZEND_STRL("plain"), styles);
	}
	if (detailed) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("detailed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("detailed"), &__$false);
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
PHP_METHOD(Ice_Dump, all)
{
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
PHP_METHOD(Ice_Dump, getStyle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, style, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&style);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("styles"), PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Ice_Dump, setStyles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *styles_param = NULL, defaultStyles, _0;
	zval styles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&styles);
	ZVAL_UNDEF(&defaultStyles);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(styles)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &styles_param);
	if (!styles_param) {
		ZEPHIR_INIT_VAR(&styles);
		array_init(&styles);
	} else {
		zephir_get_arrval(&styles, styles_param);
	}


	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The styles must be an array", "ice/dump.zep", 105);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("styles"), &_0);
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
PHP_METHOD(Ice_Dump, one)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *variable, variable_sub, *name_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(variable)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
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
PHP_METHOD(Ice_Dump, output)
{
	zend_bool _21$$5, _22$$5, _23$$5, _36$$8, _37$$8, _38$$8;
	zend_string *_12$$4, *_71$$15;
	zend_ulong _11$$4, _70$$15;
	zval _219, _4$$4, _17$$5, _32$$8, _47$$11, _130$$11, _54$$12, _75$$16, _85$$17, _103$$19, _118$$23, _146$$31, _155$$32, _165$$35, _174$$36, _185$$37, _191$$38, _196$$39, _201$$40, _208$$41, _214$$42;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_14 = NULL, *_27 = NULL, *_51 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, *name = NULL, name_sub, *tab = NULL, tab_sub, __$null, key, value, output, space, type, attr, _188, _217, _218, _220, _221, _0$$4, _1$$4, _2$$4, _3$$4, _5$$4, _6$$4, *_9$$4, _10$$4, _43$$4, _44$$4, _13$$5, _15$$5, _16$$5, _18$$5, _19$$5, _20$$5, _24$$7, _25$$7, _26$$7, _28$$7, _29$$8, _30$$8, _31$$8, _33$$8, _34$$8, _35$$8, _39$$10, _40$$10, _41$$10, _42$$10, className$$11, hash$$11, _45$$11, _46$$11, _48$$11, _49$$11, _50$$11, _57$$11, _58$$11, _59$$11, _60$$11, _125$$11, _126$$11, _127$$11, _128$$11, _129$$11, _131$$11, _132$$11, _133$$11, _134$$11, _181$$11, _182$$11, _52$$12, _53$$12, _55$$12, _56$$12, _61$$13, _62$$13, _63$$13, _64$$14, _65$$14, _66$$14, _67$$15, *_68$$15, _69$$15, _72$$16, _73$$16, _74$$16, _76$$16, _77$$16, _78$$16, _79$$16, _80$$16, _81$$16, _82$$17, _83$$17, _84$$17, _86$$17, _87$$17, _88$$17, _89$$17, _90$$17, _91$$17, reflect$$18, _92$$18, *_93$$18, _94$$18, _95$$19, _97$$19, _99$$19, _100$$19, _101$$19, _102$$19, _104$$19, _105$$19, _106$$19, _107$$19, _108$$19, _109$$19, _96$$20, _98$$21, _110$$23, _112$$23, _114$$23, _115$$23, _116$$23, _117$$23, _119$$23, _120$$23, _121$$23, _122$$23, _123$$23, _124$$23, _111$$24, _113$$25, _135$$27, _136$$27, _137$$27, *_138$$28, _139$$28, _178$$28, _179$$28, _180$$28, _140$$29, _141$$31, _142$$31, _143$$31, _144$$31, _145$$31, _147$$31, _148$$31, _149$$31, _150$$32, _151$$32, _152$$32, _153$$32, _154$$32, _156$$32, _157$$32, _158$$32, _159$$33, _160$$35, _161$$35, _162$$35, _163$$35, _164$$35, _166$$35, _167$$35, _168$$35, _169$$36, _170$$36, _171$$36, _172$$36, _173$$36, _175$$36, _176$$36, _177$$36, _183$$37, _184$$37, _186$$37, _187$$37, _189$$38, _190$$38, _192$$38, _193$$38, _194$$39, _195$$39, _197$$39, _198$$39, _199$$40, _200$$40, _202$$40, _203$$40, _204$$40, _205$$40, _206$$41, _207$$41, _209$$41, _210$$41, _211$$41, _212$$42, _213$$42, _215$$42, _216$$42;
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
	ZVAL_UNDEF(&_188);
	ZVAL_UNDEF(&_217);
	ZVAL_UNDEF(&_218);
	ZVAL_UNDEF(&_220);
	ZVAL_UNDEF(&_221);
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
	ZVAL_UNDEF(&hash$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_46$$11);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_57$$11);
	ZVAL_UNDEF(&_58$$11);
	ZVAL_UNDEF(&_59$$11);
	ZVAL_UNDEF(&_60$$11);
	ZVAL_UNDEF(&_125$$11);
	ZVAL_UNDEF(&_126$$11);
	ZVAL_UNDEF(&_127$$11);
	ZVAL_UNDEF(&_128$$11);
	ZVAL_UNDEF(&_129$$11);
	ZVAL_UNDEF(&_131$$11);
	ZVAL_UNDEF(&_132$$11);
	ZVAL_UNDEF(&_133$$11);
	ZVAL_UNDEF(&_134$$11);
	ZVAL_UNDEF(&_181$$11);
	ZVAL_UNDEF(&_182$$11);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_53$$12);
	ZVAL_UNDEF(&_55$$12);
	ZVAL_UNDEF(&_56$$12);
	ZVAL_UNDEF(&_61$$13);
	ZVAL_UNDEF(&_62$$13);
	ZVAL_UNDEF(&_63$$13);
	ZVAL_UNDEF(&_64$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_66$$14);
	ZVAL_UNDEF(&_67$$15);
	ZVAL_UNDEF(&_69$$15);
	ZVAL_UNDEF(&_72$$16);
	ZVAL_UNDEF(&_73$$16);
	ZVAL_UNDEF(&_74$$16);
	ZVAL_UNDEF(&_76$$16);
	ZVAL_UNDEF(&_77$$16);
	ZVAL_UNDEF(&_78$$16);
	ZVAL_UNDEF(&_79$$16);
	ZVAL_UNDEF(&_80$$16);
	ZVAL_UNDEF(&_81$$16);
	ZVAL_UNDEF(&_82$$17);
	ZVAL_UNDEF(&_83$$17);
	ZVAL_UNDEF(&_84$$17);
	ZVAL_UNDEF(&_86$$17);
	ZVAL_UNDEF(&_87$$17);
	ZVAL_UNDEF(&_88$$17);
	ZVAL_UNDEF(&_89$$17);
	ZVAL_UNDEF(&_90$$17);
	ZVAL_UNDEF(&_91$$17);
	ZVAL_UNDEF(&reflect$$18);
	ZVAL_UNDEF(&_92$$18);
	ZVAL_UNDEF(&_94$$18);
	ZVAL_UNDEF(&_95$$19);
	ZVAL_UNDEF(&_97$$19);
	ZVAL_UNDEF(&_99$$19);
	ZVAL_UNDEF(&_100$$19);
	ZVAL_UNDEF(&_101$$19);
	ZVAL_UNDEF(&_102$$19);
	ZVAL_UNDEF(&_104$$19);
	ZVAL_UNDEF(&_105$$19);
	ZVAL_UNDEF(&_106$$19);
	ZVAL_UNDEF(&_107$$19);
	ZVAL_UNDEF(&_108$$19);
	ZVAL_UNDEF(&_109$$19);
	ZVAL_UNDEF(&_96$$20);
	ZVAL_UNDEF(&_98$$21);
	ZVAL_UNDEF(&_110$$23);
	ZVAL_UNDEF(&_112$$23);
	ZVAL_UNDEF(&_114$$23);
	ZVAL_UNDEF(&_115$$23);
	ZVAL_UNDEF(&_116$$23);
	ZVAL_UNDEF(&_117$$23);
	ZVAL_UNDEF(&_119$$23);
	ZVAL_UNDEF(&_120$$23);
	ZVAL_UNDEF(&_121$$23);
	ZVAL_UNDEF(&_122$$23);
	ZVAL_UNDEF(&_123$$23);
	ZVAL_UNDEF(&_124$$23);
	ZVAL_UNDEF(&_111$$24);
	ZVAL_UNDEF(&_113$$25);
	ZVAL_UNDEF(&_135$$27);
	ZVAL_UNDEF(&_136$$27);
	ZVAL_UNDEF(&_137$$27);
	ZVAL_UNDEF(&_139$$28);
	ZVAL_UNDEF(&_178$$28);
	ZVAL_UNDEF(&_179$$28);
	ZVAL_UNDEF(&_180$$28);
	ZVAL_UNDEF(&_140$$29);
	ZVAL_UNDEF(&_141$$31);
	ZVAL_UNDEF(&_142$$31);
	ZVAL_UNDEF(&_143$$31);
	ZVAL_UNDEF(&_144$$31);
	ZVAL_UNDEF(&_145$$31);
	ZVAL_UNDEF(&_147$$31);
	ZVAL_UNDEF(&_148$$31);
	ZVAL_UNDEF(&_149$$31);
	ZVAL_UNDEF(&_150$$32);
	ZVAL_UNDEF(&_151$$32);
	ZVAL_UNDEF(&_152$$32);
	ZVAL_UNDEF(&_153$$32);
	ZVAL_UNDEF(&_154$$32);
	ZVAL_UNDEF(&_156$$32);
	ZVAL_UNDEF(&_157$$32);
	ZVAL_UNDEF(&_158$$32);
	ZVAL_UNDEF(&_159$$33);
	ZVAL_UNDEF(&_160$$35);
	ZVAL_UNDEF(&_161$$35);
	ZVAL_UNDEF(&_162$$35);
	ZVAL_UNDEF(&_163$$35);
	ZVAL_UNDEF(&_164$$35);
	ZVAL_UNDEF(&_166$$35);
	ZVAL_UNDEF(&_167$$35);
	ZVAL_UNDEF(&_168$$35);
	ZVAL_UNDEF(&_169$$36);
	ZVAL_UNDEF(&_170$$36);
	ZVAL_UNDEF(&_171$$36);
	ZVAL_UNDEF(&_172$$36);
	ZVAL_UNDEF(&_173$$36);
	ZVAL_UNDEF(&_175$$36);
	ZVAL_UNDEF(&_176$$36);
	ZVAL_UNDEF(&_177$$36);
	ZVAL_UNDEF(&_183$$37);
	ZVAL_UNDEF(&_184$$37);
	ZVAL_UNDEF(&_186$$37);
	ZVAL_UNDEF(&_187$$37);
	ZVAL_UNDEF(&_189$$38);
	ZVAL_UNDEF(&_190$$38);
	ZVAL_UNDEF(&_192$$38);
	ZVAL_UNDEF(&_193$$38);
	ZVAL_UNDEF(&_194$$39);
	ZVAL_UNDEF(&_195$$39);
	ZVAL_UNDEF(&_197$$39);
	ZVAL_UNDEF(&_198$$39);
	ZVAL_UNDEF(&_199$$40);
	ZVAL_UNDEF(&_200$$40);
	ZVAL_UNDEF(&_202$$40);
	ZVAL_UNDEF(&_203$$40);
	ZVAL_UNDEF(&_204$$40);
	ZVAL_UNDEF(&_205$$40);
	ZVAL_UNDEF(&_206$$41);
	ZVAL_UNDEF(&_207$$41);
	ZVAL_UNDEF(&_209$$41);
	ZVAL_UNDEF(&_210$$41);
	ZVAL_UNDEF(&_211$$41);
	ZVAL_UNDEF(&_212$$42);
	ZVAL_UNDEF(&_213$$42);
	ZVAL_UNDEF(&_215$$42);
	ZVAL_UNDEF(&_216$$42);
	ZVAL_UNDEF(&_219);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_47$$11);
	ZVAL_UNDEF(&_130$$11);
	ZVAL_UNDEF(&_54$$12);
	ZVAL_UNDEF(&_75$$16);
	ZVAL_UNDEF(&_85$$17);
	ZVAL_UNDEF(&_103$$19);
	ZVAL_UNDEF(&_118$$23);
	ZVAL_UNDEF(&_146$$31);
	ZVAL_UNDEF(&_155$$32);
	ZVAL_UNDEF(&_165$$35);
	ZVAL_UNDEF(&_174$$36);
	ZVAL_UNDEF(&_185$$37);
	ZVAL_UNDEF(&_191$$38);
	ZVAL_UNDEF(&_196$$39);
	ZVAL_UNDEF(&_201$$40);
	ZVAL_UNDEF(&_208$$41);
	ZVAL_UNDEF(&_214$$42);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(variable)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(name)
		Z_PARAM_ZVAL(tab)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_CALL_FUNCTION(&_5$$4, "strtr", &_8, 110, &_0$$4, &_4$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_5$$4);
		zephir_is_iterable(variable, 0, "ice/dump.zep", 175);
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
				ZEPHIR_CALL_FUNCTION(&_13$$5, "str_repeat", &_14, 93, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$5);
				zephir_read_property(&_16$$5, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
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
				ZEPHIR_CALL_FUNCTION(&_18$$5, "strtr", &_8, 110, &_15$$5, &_17$$5);
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
					ZEPHIR_CALL_METHOD(&_24$$7, this_ptr, "output", &_27, 111, &value, &_25$$7, &_26$$7);
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
					ZEPHIR_CALL_FUNCTION(&_29$$8, "str_repeat", &_14, 93, &space, tab);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_30$$8);
					zephir_read_property(&_31$$8, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
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
					ZEPHIR_CALL_FUNCTION(&_33$$8, "strtr", &_8, 110, &_30$$8, &_32$$8);
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
						ZEPHIR_CALL_METHOD(&_39$$10, this_ptr, "output", &_27, 111, &value, &_40$$10, &_41$$10);
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
		ZEPHIR_CALL_FUNCTION(&_44$$4, "str_repeat", &_14, 93, &space, &_43$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_44$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&className$$11);
		zephir_get_class(&className$$11, variable, 0);
		ZEPHIR_CALL_FUNCTION(&hash$$11, "spl_object_hash", NULL, 109, variable);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_45$$11);
		zephir_read_property(&_46$$11, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_CALL_FUNCTION(&_48$$11, "strtr", &_8, 110, &_45$$11, &_47$$11);
		zephir_check_call_status();
		zephir_concat_self(&output, &_48$$11);
		ZEPHIR_CALL_FUNCTION(&_50$$11, "get_parent_class", &_51, 112, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_50$$11)) {
			ZEPHIR_INIT_VAR(&_52$$12);
			zephir_read_property(&_53$$12, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
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
			ZEPHIR_CALL_FUNCTION(&_55$$12, "get_parent_class", &_51, 112, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_54$$12, SL(":parent"), &_55$$12, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_55$$12, "strtr", &_8, 110, &_52$$12, &_54$$12);
			zephir_check_call_status();
			zephir_concat_self(&output, &_55$$12);
		}
		ZEPHIR_INIT_NVAR(&_49$$11);
		ZEPHIR_GET_CONSTANT(&_49$$11, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_57$$11);
		ZEPHIR_CONCAT_SV(&_57$$11, " (", &_49$$11);
		zephir_concat_self(&output, &_57$$11);
		zephir_read_property(&_58$$11, this_ptr, ZEND_STRL("skip"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_59$$11, this_ptr, ZEND_STRL("objects"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_60$$11, this_ptr, ZEND_STRL("detailed"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&className$$11, &_58$$11)) {
			ZEPHIR_CALL_FUNCTION(&_61$$13, "str_repeat", &_14, 93, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_62$$13);
			ZEPHIR_GET_CONSTANT(&_62$$13, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_63$$13);
			ZEPHIR_CONCAT_VSV(&_63$$13, &_61$$13, "[skipped]", &_62$$13);
			zephir_concat_self(&output, &_63$$13);
		} else if (zephir_fast_in_array(&hash$$11, &_59$$11)) {
			ZEPHIR_CALL_FUNCTION(&_64$$14, "str_repeat", &_14, 93, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_65$$14);
			ZEPHIR_GET_CONSTANT(&_65$$14, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_66$$14);
			ZEPHIR_CONCAT_VSV(&_66$$14, &_64$$14, "[already listed]", &_65$$14);
			zephir_concat_self(&output, &_66$$14);
		} else if (!(zephir_is_true(&_60$$11))) {
			ZEPHIR_CALL_FUNCTION(&_67$$15, "get_object_vars", NULL, 113, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_67$$15, 0, "ice/dump.zep", 203);
			if (Z_TYPE_P(&_67$$15) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_67$$15), _70$$15, _71$$15, _68$$15)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_71$$15 != NULL) { 
						ZVAL_STR_COPY(&key, _71$$15);
					} else {
						ZVAL_LONG(&key, _70$$15);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _68$$15);
					zephir_update_property_array_append(this_ptr, SL("objects"), &hash$$11);
					ZEPHIR_CALL_FUNCTION(&_72$$16, "str_repeat", &_14, 93, &space, tab);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_73$$16);
					zephir_read_property(&_74$$16, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_74$$16)) {
						ZEPHIR_INIT_NVAR(&_73$$16);
						ZVAL_STRING(&_73$$16, "->:key (:type) = ");
					} else {
						ZEPHIR_INIT_NVAR(&_73$$16);
						ZVAL_STRING(&_73$$16, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
					}
					ZEPHIR_INIT_NVAR(&_75$$16);
					zephir_create_array(&_75$$16, 3, 0);
					ZEPHIR_INIT_NVAR(&_77$$16);
					ZVAL_STRING(&_77$$16, "obj");
					ZEPHIR_CALL_METHOD(&_76$$16, this_ptr, "getstyle", &_7, 0, &_77$$16);
					zephir_check_call_status();
					zephir_array_update_string(&_75$$16, SL(":style"), &_76$$16, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_75$$16, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					add_assoc_stringl_ex(&_75$$16, SL(":type"), SL("public"));
					ZEPHIR_CALL_FUNCTION(&_76$$16, "strtr", &_8, 110, &_73$$16, &_75$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_78$$16);
					ZEPHIR_CONCAT_VV(&_78$$16, &_72$$16, &_76$$16);
					zephir_concat_self(&output, &_78$$16);
					ZEPHIR_INIT_NVAR(&_77$$16);
					ZVAL_STRING(&_77$$16, "");
					ZVAL_LONG(&_80$$16, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_METHOD(&_79$$16, this_ptr, "output", &_27, 111, &value, &_77$$16, &_80$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_77$$16);
					ZEPHIR_GET_CONSTANT(&_77$$16, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_81$$16);
					ZEPHIR_CONCAT_VV(&_81$$16, &_79$$16, &_77$$16);
					zephir_concat_self(&output, &_81$$16);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_67$$15, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_69$$15, &_67$$15, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_69$$15)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, &_67$$15, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, &_67$$15, "current", NULL, 0);
					zephir_check_call_status();
						zephir_update_property_array_append(this_ptr, SL("objects"), &hash$$11);
						ZEPHIR_CALL_FUNCTION(&_82$$17, "str_repeat", &_14, 93, &space, tab);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_83$$17);
						zephir_read_property(&_84$$17, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_84$$17)) {
							ZEPHIR_INIT_NVAR(&_83$$17);
							ZVAL_STRING(&_83$$17, "->:key (:type) = ");
						} else {
							ZEPHIR_INIT_NVAR(&_83$$17);
							ZVAL_STRING(&_83$$17, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
						}
						ZEPHIR_INIT_NVAR(&_85$$17);
						zephir_create_array(&_85$$17, 3, 0);
						ZEPHIR_INIT_NVAR(&_87$$17);
						ZVAL_STRING(&_87$$17, "obj");
						ZEPHIR_CALL_METHOD(&_86$$17, this_ptr, "getstyle", &_7, 0, &_87$$17);
						zephir_check_call_status();
						zephir_array_update_string(&_85$$17, SL(":style"), &_86$$17, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_85$$17, SL(":key"), &key, PH_COPY | PH_SEPARATE);
						add_assoc_stringl_ex(&_85$$17, SL(":type"), SL("public"));
						ZEPHIR_CALL_FUNCTION(&_86$$17, "strtr", &_8, 110, &_83$$17, &_85$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_88$$17);
						ZEPHIR_CONCAT_VV(&_88$$17, &_82$$17, &_86$$17);
						zephir_concat_self(&output, &_88$$17);
						ZEPHIR_INIT_NVAR(&_87$$17);
						ZVAL_STRING(&_87$$17, "");
						ZVAL_LONG(&_90$$17, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_METHOD(&_89$$17, this_ptr, "output", &_27, 111, &value, &_87$$17, &_90$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_87$$17);
						ZEPHIR_GET_CONSTANT(&_87$$17, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_91$$17);
						ZEPHIR_CONCAT_VV(&_91$$17, &_89$$17, &_87$$17);
						zephir_concat_self(&output, &_91$$17);
					ZEPHIR_CALL_METHOD(NULL, &_67$$15, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			if (zephir_is_instance_of(variable, SL("stdClass"))) {
				ZEPHIR_INIT_VAR(&reflect$$18);
				object_init_ex(&reflect$$18, zephir_get_internal_ce(SL("reflectionobject")));
				ZEPHIR_CALL_METHOD(NULL, &reflect$$18, "__construct", NULL, 114, variable);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&reflect$$18);
				object_init_ex(&reflect$$18, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD(NULL, &reflect$$18, "__construct", NULL, 102, variable);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_92$$18, &reflect$$18, "getproperties", NULL, 115);
			zephir_check_call_status();
			zephir_is_iterable(&_92$$18, 0, "ice/dump.zep", 233);
			if (Z_TYPE_P(&_92$$18) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_92$$18), _93$$18)
				{
					ZEPHIR_INIT_NVAR(&attr);
					ZVAL_COPY(&attr, _93$$18);
					ZEPHIR_CALL_METHOD(&key, &attr, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_STRING(&type, "public");
					ZEPHIR_CALL_METHOD(&_95$$19, &attr, "isprotected", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&_95$$19)) {
						ZVAL_BOOL(&_96$$20, 1);
						ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_96$$20);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "protected");
					}
					ZEPHIR_CALL_METHOD(&_97$$19, &attr, "isprivate", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&_97$$19)) {
						ZVAL_BOOL(&_98$$21, 1);
						ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_98$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "private");
					}
					ZEPHIR_CALL_METHOD(&_99$$19, &attr, "isstatic", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&_99$$19)) {
						zephir_concat_self_str(&type, SL(" static"));
					}
					ZEPHIR_CALL_METHOD(&value, &attr, "getvalue", NULL, 0, variable);
					zephir_check_call_status();
					zephir_update_property_array_append(this_ptr, SL("objects"), &hash$$11);
					ZEPHIR_CALL_FUNCTION(&_100$$19, "str_repeat", &_14, 93, &space, tab);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_101$$19);
					zephir_read_property(&_102$$19, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_102$$19)) {
						ZEPHIR_INIT_NVAR(&_101$$19);
						ZVAL_STRING(&_101$$19, "->:key (:type) = ");
					} else {
						ZEPHIR_INIT_NVAR(&_101$$19);
						ZVAL_STRING(&_101$$19, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
					}
					ZEPHIR_INIT_NVAR(&_103$$19);
					zephir_create_array(&_103$$19, 3, 0);
					ZEPHIR_INIT_NVAR(&_105$$19);
					ZVAL_STRING(&_105$$19, "obj");
					ZEPHIR_CALL_METHOD(&_104$$19, this_ptr, "getstyle", &_7, 0, &_105$$19);
					zephir_check_call_status();
					zephir_array_update_string(&_103$$19, SL(":style"), &_104$$19, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_103$$19, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_103$$19, SL(":type"), &type, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_104$$19, "strtr", &_8, 110, &_101$$19, &_103$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_106$$19);
					ZEPHIR_CONCAT_VV(&_106$$19, &_100$$19, &_104$$19);
					zephir_concat_self(&output, &_106$$19);
					ZEPHIR_INIT_NVAR(&_105$$19);
					ZVAL_STRING(&_105$$19, "");
					ZVAL_LONG(&_108$$19, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_METHOD(&_107$$19, this_ptr, "output", &_27, 111, &value, &_105$$19, &_108$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_105$$19);
					ZEPHIR_GET_CONSTANT(&_105$$19, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_109$$19);
					ZEPHIR_CONCAT_VV(&_109$$19, &_107$$19, &_105$$19);
					zephir_concat_self(&output, &_109$$19);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_92$$18, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_94$$18, &_92$$18, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_94$$18)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&attr, &_92$$18, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&key, &attr, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "public");
						ZEPHIR_CALL_METHOD(&_110$$23, &attr, "isprotected", NULL, 0);
						zephir_check_call_status();
						if (zephir_is_true(&_110$$23)) {
							ZVAL_BOOL(&_111$$24, 1);
							ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_111$$24);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							ZVAL_STRING(&type, "protected");
						}
						ZEPHIR_CALL_METHOD(&_112$$23, &attr, "isprivate", NULL, 0);
						zephir_check_call_status();
						if (zephir_is_true(&_112$$23)) {
							ZVAL_BOOL(&_113$$25, 1);
							ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_113$$25);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							ZVAL_STRING(&type, "private");
						}
						ZEPHIR_CALL_METHOD(&_114$$23, &attr, "isstatic", NULL, 0);
						zephir_check_call_status();
						if (zephir_is_true(&_114$$23)) {
							zephir_concat_self_str(&type, SL(" static"));
						}
						ZEPHIR_CALL_METHOD(&value, &attr, "getvalue", NULL, 0, variable);
						zephir_check_call_status();
						zephir_update_property_array_append(this_ptr, SL("objects"), &hash$$11);
						ZEPHIR_CALL_FUNCTION(&_115$$23, "str_repeat", &_14, 93, &space, tab);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_116$$23);
						zephir_read_property(&_117$$23, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_117$$23)) {
							ZEPHIR_INIT_NVAR(&_116$$23);
							ZVAL_STRING(&_116$$23, "->:key (:type) = ");
						} else {
							ZEPHIR_INIT_NVAR(&_116$$23);
							ZVAL_STRING(&_116$$23, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
						}
						ZEPHIR_INIT_NVAR(&_118$$23);
						zephir_create_array(&_118$$23, 3, 0);
						ZEPHIR_INIT_NVAR(&_120$$23);
						ZVAL_STRING(&_120$$23, "obj");
						ZEPHIR_CALL_METHOD(&_119$$23, this_ptr, "getstyle", &_7, 0, &_120$$23);
						zephir_check_call_status();
						zephir_array_update_string(&_118$$23, SL(":style"), &_119$$23, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_118$$23, SL(":key"), &key, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_118$$23, SL(":type"), &type, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_119$$23, "strtr", &_8, 110, &_116$$23, &_118$$23);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_121$$23);
						ZEPHIR_CONCAT_VV(&_121$$23, &_115$$23, &_119$$23);
						zephir_concat_self(&output, &_121$$23);
						ZEPHIR_INIT_NVAR(&_120$$23);
						ZVAL_STRING(&_120$$23, "");
						ZVAL_LONG(&_123$$23, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_METHOD(&_122$$23, this_ptr, "output", &_27, 111, &value, &_120$$23, &_123$$23);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_120$$23);
						ZEPHIR_GET_CONSTANT(&_120$$23, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_124$$23);
						ZEPHIR_CONCAT_VV(&_124$$23, &_122$$23, &_120$$23);
						zephir_concat_self(&output, &_124$$23);
					ZEPHIR_CALL_METHOD(NULL, &_92$$18, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&attr);
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 116, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_125$$11, "str_repeat", &_14, 93, &space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_126$$11);
		zephir_read_property(&_127$$11, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_127$$11)) {
			ZEPHIR_INIT_VAR(&_128$$11);
			ZEPHIR_GET_CONSTANT(&_128$$11, "PHP_EOL");
			ZEPHIR_INIT_NVAR(&_126$$11);
			ZEPHIR_CONCAT_SV(&_126$$11, ":class methods: (:count) (", &_128$$11);
		} else {
			ZEPHIR_INIT_VAR(&_129$$11);
			ZEPHIR_GET_CONSTANT(&_129$$11, "PHP_EOL");
			ZEPHIR_INIT_NVAR(&_126$$11);
			ZEPHIR_CONCAT_SV(&_126$$11, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (", &_129$$11);
		}
		ZEPHIR_INIT_VAR(&_130$$11);
		zephir_create_array(&_130$$11, 3, 0);
		ZEPHIR_INIT_VAR(&_132$$11);
		ZVAL_STRING(&_132$$11, "obj");
		ZEPHIR_CALL_METHOD(&_131$$11, this_ptr, "getstyle", &_7, 0, &_132$$11);
		zephir_check_call_status();
		zephir_array_update_string(&_130$$11, SL(":style"), &_131$$11, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_130$$11, SL(":class"), &className$$11, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_130$$11, SL(":count"), zephir_fast_count_int(&attr));
		ZEPHIR_CALL_FUNCTION(&_131$$11, "strtr", &_8, 110, &_126$$11, &_130$$11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_133$$11);
		ZEPHIR_CONCAT_VV(&_133$$11, &_125$$11, &_131$$11);
		zephir_concat_self(&output, &_133$$11);
		zephir_read_property(&_134$$11, this_ptr, ZEND_STRL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&className$$11, &_134$$11)) {
			ZEPHIR_CALL_FUNCTION(&_135$$27, "str_repeat", &_14, 93, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_136$$27);
			ZEPHIR_GET_CONSTANT(&_136$$27, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_137$$27);
			ZEPHIR_CONCAT_VSV(&_137$$27, &_135$$27, "[already listed]", &_136$$27);
			zephir_concat_self(&output, &_137$$27);
		} else {
			zephir_is_iterable(&attr, 0, "ice/dump.zep", 251);
			if (Z_TYPE_P(&attr) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _138$$28)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _138$$28);
					zephir_read_property(&_140$$29, this_ptr, ZEND_STRL("methods"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_fast_in_array(&className$$11, &_140$$29))) {
						zephir_update_property_array_append(this_ptr, SL("methods"), &className$$11);
					}
					if (ZEPHIR_IS_STRING(&value, "__construct")) {
						ZVAL_LONG(&_141$$31, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_FUNCTION(&_142$$31, "str_repeat", &_14, 93, &space, &_141$$31);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_143$$31);
						zephir_read_property(&_141$$31, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_141$$31)) {
							ZEPHIR_INIT_NVAR(&_144$$31);
							ZEPHIR_GET_CONSTANT(&_144$$31, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_143$$31);
							ZEPHIR_CONCAT_SV(&_143$$31, "->:method(); [constructor]", &_144$$31);
						} else {
							ZEPHIR_INIT_NVAR(&_145$$31);
							ZEPHIR_GET_CONSTANT(&_145$$31, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_143$$31);
							ZEPHIR_CONCAT_SV(&_143$$31, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]", &_145$$31);
						}
						ZEPHIR_INIT_NVAR(&_146$$31);
						zephir_create_array(&_146$$31, 2, 0);
						ZEPHIR_INIT_NVAR(&_148$$31);
						ZVAL_STRING(&_148$$31, "obj");
						ZEPHIR_CALL_METHOD(&_147$$31, this_ptr, "getstyle", &_7, 0, &_148$$31);
						zephir_check_call_status();
						zephir_array_update_string(&_146$$31, SL(":style"), &_147$$31, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_146$$31, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_147$$31, "strtr", &_8, 110, &_143$$31, &_146$$31);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_149$$31);
						ZEPHIR_CONCAT_VV(&_149$$31, &_142$$31, &_147$$31);
						zephir_concat_self(&output, &_149$$31);
					} else {
						ZVAL_LONG(&_150$$32, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_FUNCTION(&_151$$32, "str_repeat", &_14, 93, &space, &_150$$32);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_152$$32);
						zephir_read_property(&_150$$32, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_150$$32)) {
							ZEPHIR_INIT_NVAR(&_153$$32);
							ZEPHIR_GET_CONSTANT(&_153$$32, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_152$$32);
							ZEPHIR_CONCAT_SV(&_152$$32, "->:method();", &_153$$32);
						} else {
							ZEPHIR_INIT_NVAR(&_154$$32);
							ZEPHIR_GET_CONSTANT(&_154$$32, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_152$$32);
							ZEPHIR_CONCAT_SV(&_152$$32, "-><span style=':style'>:method</span>();", &_154$$32);
						}
						ZEPHIR_INIT_NVAR(&_155$$32);
						zephir_create_array(&_155$$32, 2, 0);
						ZEPHIR_INIT_NVAR(&_157$$32);
						ZVAL_STRING(&_157$$32, "obj");
						ZEPHIR_CALL_METHOD(&_156$$32, this_ptr, "getstyle", &_7, 0, &_157$$32);
						zephir_check_call_status();
						zephir_array_update_string(&_155$$32, SL(":style"), &_156$$32, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_155$$32, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_156$$32, "strtr", &_8, 110, &_152$$32, &_155$$32);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_158$$32);
						ZEPHIR_CONCAT_VV(&_158$$32, &_151$$32, &_156$$32);
						zephir_concat_self(&output, &_158$$32);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attr, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_139$$28, &attr, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_139$$28)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, &attr, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property(&_159$$33, this_ptr, ZEND_STRL("methods"), PH_NOISY_CC | PH_READONLY);
						if (!(zephir_fast_in_array(&className$$11, &_159$$33))) {
							zephir_update_property_array_append(this_ptr, SL("methods"), &className$$11);
						}
						if (ZEPHIR_IS_STRING(&value, "__construct")) {
							ZVAL_LONG(&_160$$35, (zephir_get_numberval(tab) + 1));
							ZEPHIR_CALL_FUNCTION(&_161$$35, "str_repeat", &_14, 93, &space, &_160$$35);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_162$$35);
							zephir_read_property(&_160$$35, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_160$$35)) {
								ZEPHIR_INIT_NVAR(&_163$$35);
								ZEPHIR_GET_CONSTANT(&_163$$35, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_162$$35);
								ZEPHIR_CONCAT_SV(&_162$$35, "->:method(); [constructor]", &_163$$35);
							} else {
								ZEPHIR_INIT_NVAR(&_164$$35);
								ZEPHIR_GET_CONSTANT(&_164$$35, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_162$$35);
								ZEPHIR_CONCAT_SV(&_162$$35, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]", &_164$$35);
							}
							ZEPHIR_INIT_NVAR(&_165$$35);
							zephir_create_array(&_165$$35, 2, 0);
							ZEPHIR_INIT_NVAR(&_167$$35);
							ZVAL_STRING(&_167$$35, "obj");
							ZEPHIR_CALL_METHOD(&_166$$35, this_ptr, "getstyle", &_7, 0, &_167$$35);
							zephir_check_call_status();
							zephir_array_update_string(&_165$$35, SL(":style"), &_166$$35, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_165$$35, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_FUNCTION(&_166$$35, "strtr", &_8, 110, &_162$$35, &_165$$35);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_168$$35);
							ZEPHIR_CONCAT_VV(&_168$$35, &_161$$35, &_166$$35);
							zephir_concat_self(&output, &_168$$35);
						} else {
							ZVAL_LONG(&_169$$36, (zephir_get_numberval(tab) + 1));
							ZEPHIR_CALL_FUNCTION(&_170$$36, "str_repeat", &_14, 93, &space, &_169$$36);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_171$$36);
							zephir_read_property(&_169$$36, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_169$$36)) {
								ZEPHIR_INIT_NVAR(&_172$$36);
								ZEPHIR_GET_CONSTANT(&_172$$36, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_171$$36);
								ZEPHIR_CONCAT_SV(&_171$$36, "->:method();", &_172$$36);
							} else {
								ZEPHIR_INIT_NVAR(&_173$$36);
								ZEPHIR_GET_CONSTANT(&_173$$36, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_171$$36);
								ZEPHIR_CONCAT_SV(&_171$$36, "-><span style=':style'>:method</span>();", &_173$$36);
							}
							ZEPHIR_INIT_NVAR(&_174$$36);
							zephir_create_array(&_174$$36, 2, 0);
							ZEPHIR_INIT_NVAR(&_176$$36);
							ZVAL_STRING(&_176$$36, "obj");
							ZEPHIR_CALL_METHOD(&_175$$36, this_ptr, "getstyle", &_7, 0, &_176$$36);
							zephir_check_call_status();
							zephir_array_update_string(&_174$$36, SL(":style"), &_175$$36, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_174$$36, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_FUNCTION(&_175$$36, "strtr", &_8, 110, &_171$$36, &_174$$36);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_177$$36);
							ZEPHIR_CONCAT_VV(&_177$$36, &_170$$36, &_175$$36);
							zephir_concat_self(&output, &_177$$36);
						}
					ZEPHIR_CALL_METHOD(NULL, &attr, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_CALL_FUNCTION(&_178$$28, "str_repeat", &_14, 93, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_179$$28);
			ZEPHIR_GET_CONSTANT(&_179$$28, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_180$$28);
			ZEPHIR_CONCAT_VSV(&_180$$28, &_178$$28, ")", &_179$$28);
			zephir_concat_self(&output, &_180$$28);
		}
		ZVAL_LONG(&_181$$11, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_182$$11, "str_repeat", &_14, 93, &space, &_181$$11);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_182$$11, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_183$$37);
		zephir_read_property(&_184$$37, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_184$$37)) {
			ZEPHIR_INIT_NVAR(&_183$$37);
			ZVAL_STRING(&_183$$37, "integer (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_183$$37);
			ZVAL_STRING(&_183$$37, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_185$$37);
		zephir_create_array(&_185$$37, 2, 0);
		ZEPHIR_INIT_VAR(&_187$$37);
		ZVAL_STRING(&_187$$37, "int");
		ZEPHIR_CALL_METHOD(&_186$$37, this_ptr, "getstyle", &_7, 0, &_187$$37);
		zephir_check_call_status();
		zephir_array_update_string(&_185$$37, SL(":style"), &_186$$37, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_185$$37, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_186$$37, "strtr", &_8, 110, &_183$$37, &_185$$37);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_186$$37);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_188, "is_float", NULL, 117, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_188)) {
		ZEPHIR_INIT_VAR(&_189$$38);
		zephir_read_property(&_190$$38, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_190$$38)) {
			ZEPHIR_INIT_NVAR(&_189$$38);
			ZVAL_STRING(&_189$$38, "float (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_189$$38);
			ZVAL_STRING(&_189$$38, "<b style=':style'>float</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_191$$38);
		zephir_create_array(&_191$$38, 2, 0);
		ZEPHIR_INIT_VAR(&_193$$38);
		ZVAL_STRING(&_193$$38, "float");
		ZEPHIR_CALL_METHOD(&_192$$38, this_ptr, "getstyle", &_7, 0, &_193$$38);
		zephir_check_call_status();
		zephir_array_update_string(&_191$$38, SL(":style"), &_192$$38, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_191$$38, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_192$$38, "strtr", &_8, 110, &_189$$38, &_191$$38);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_192$$38);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_194$$39);
		zephir_read_property(&_195$$39, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_195$$39)) {
			ZEPHIR_INIT_NVAR(&_194$$39);
			ZVAL_STRING(&_194$$39, "numeric string (:length) \":var\"");
		} else {
			ZEPHIR_INIT_NVAR(&_194$$39);
			ZVAL_STRING(&_194$$39, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		}
		ZEPHIR_INIT_VAR(&_196$$39);
		zephir_create_array(&_196$$39, 3, 0);
		ZEPHIR_INIT_VAR(&_198$$39);
		ZVAL_STRING(&_198$$39, "num");
		ZEPHIR_CALL_METHOD(&_197$$39, this_ptr, "getstyle", &_7, 0, &_198$$39);
		zephir_check_call_status();
		zephir_array_update_string(&_196$$39, SL(":style"), &_197$$39, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_196$$39, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_196$$39, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_197$$39, "strtr", &_8, 110, &_194$$39, &_196$$39);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_197$$39);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_199$$40);
		zephir_read_property(&_200$$40, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_200$$40)) {
			ZEPHIR_INIT_NVAR(&_199$$40);
			ZVAL_STRING(&_199$$40, "string (:length) \":var\"");
		} else {
			ZEPHIR_INIT_NVAR(&_199$$40);
			ZVAL_STRING(&_199$$40, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		}
		ZEPHIR_INIT_VAR(&_201$$40);
		zephir_create_array(&_201$$40, 3, 0);
		ZEPHIR_INIT_VAR(&_203$$40);
		ZVAL_STRING(&_203$$40, "str");
		ZEPHIR_CALL_METHOD(&_202$$40, this_ptr, "getstyle", &_7, 0, &_203$$40);
		zephir_check_call_status();
		zephir_array_update_string(&_201$$40, SL(":style"), &_202$$40, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_201$$40, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_204$$40, 4);
		ZEPHIR_INIT_NVAR(&_203$$40);
		ZVAL_STRING(&_203$$40, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_202$$40, "htmlentities", NULL, 118, variable, &_204$$40, &_203$$40);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_205$$40, "nl2br", NULL, 119, &_202$$40);
		zephir_check_call_status();
		zephir_array_update_string(&_201$$40, SL(":var"), &_205$$40, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_205$$40, "strtr", &_8, 110, &_199$$40, &_201$$40);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_205$$40);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_206$$41);
		zephir_read_property(&_207$$41, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_207$$41)) {
			ZEPHIR_INIT_NVAR(&_206$$41);
			ZVAL_STRING(&_206$$41, "boolean (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_206$$41);
			ZVAL_STRING(&_206$$41, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_208$$41);
		zephir_create_array(&_208$$41, 2, 0);
		ZEPHIR_INIT_VAR(&_210$$41);
		ZVAL_STRING(&_210$$41, "bool");
		ZEPHIR_CALL_METHOD(&_209$$41, this_ptr, "getstyle", &_7, 0, &_210$$41);
		zephir_check_call_status();
		zephir_array_update_string(&_208$$41, SL(":style"), &_209$$41, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_211$$41);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_211$$41);
			ZVAL_STRING(&_211$$41, "true");
		} else {
			ZEPHIR_INIT_NVAR(&_211$$41);
			ZVAL_STRING(&_211$$41, "false");
		}
		zephir_array_update_string(&_208$$41, SL(":var"), &_211$$41, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_209$$41, "strtr", &_8, 110, &_206$$41, &_208$$41);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_209$$41);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_212$$42);
		zephir_read_property(&_213$$42, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_213$$42)) {
			ZEPHIR_INIT_NVAR(&_212$$42);
			ZVAL_STRING(&_212$$42, "null");
		} else {
			ZEPHIR_INIT_NVAR(&_212$$42);
			ZVAL_STRING(&_212$$42, "<b style=':style'>null</b>");
		}
		ZEPHIR_INIT_VAR(&_214$$42);
		zephir_create_array(&_214$$42, 1, 0);
		ZEPHIR_INIT_VAR(&_216$$42);
		ZVAL_STRING(&_216$$42, "null");
		ZEPHIR_CALL_METHOD(&_215$$42, this_ptr, "getstyle", &_7, 0, &_216$$42);
		zephir_check_call_status();
		zephir_array_update_string(&_214$$42, SL(":style"), &_215$$42, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_215$$42, "strtr", &_8, 110, &_212$$42, &_214$$42);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_215$$42);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_217);
	zephir_read_property(&_218, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_218)) {
		ZEPHIR_INIT_NVAR(&_217);
		ZVAL_STRING(&_217, "(:var)");
	} else {
		ZEPHIR_INIT_NVAR(&_217);
		ZVAL_STRING(&_217, "(<span style=':style'>:var</span>)");
	}
	ZEPHIR_INIT_VAR(&_219);
	zephir_create_array(&_219, 2, 0);
	ZEPHIR_INIT_VAR(&_221);
	ZVAL_STRING(&_221, "other");
	ZEPHIR_CALL_METHOD(&_220, this_ptr, "getstyle", &_7, 0, &_221);
	zephir_check_call_status();
	zephir_array_update_string(&_219, SL(":style"), &_220, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_219, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_220, "strtr", &_8, 110, &_217, &_219);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_220);
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
PHP_METHOD(Ice_Dump, variable)
{
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(variable)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 110, &_0, &_2);
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
PHP_METHOD(Ice_Dump, vars)
{
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
	zephir_is_iterable(&_0, 0, "ice/dump.zep", 324);
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
PHP_METHOD(Ice_Dump, source)
{
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(filename)
		Z_PARAM_LONG(line)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(padding)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		ZEPHIR_CALL_FUNCTION(&_1, "is_readable", NULL, 120, &filename);
		zephir_check_call_status();
		_0 = !zephir_is_true(&_1);
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "r");
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 121, &filename, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&range);
	zephir_create_array(&range, 2, 0);
	add_assoc_long_ex(&range, SL("start"), (line - padding));
	add_assoc_long_ex(&range, SL("end"), (line + padding));
	zephir_array_fetch_string(&_3, &range, SL("end"), PH_NOISY | PH_READONLY, "ice/dump.zep", 355);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_LONG(&_4, zephir_fast_strlen_ev(&_3));
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVS(&_5, "% ", &_4, "d");
	ZEPHIR_CPY_WRT(&format, &_5);
	ZEPHIR_INIT_VAR(&lines);
	array_init(&lines);
	ZEPHIR_CALL_FUNCTION(&row, "fgets", &_6, 122, &file);
	zephir_check_call_status();
	while (1) {
		if (!(!(zephir_feof(&file)))) {
			break;
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(&row)) {
			break;
		}
		i++;
		zephir_array_fetch_string(&_7$$4, &range, SL("end"), PH_NOISY | PH_READONLY, "ice/dump.zep", 367);
		if (ZEPHIR_LT_LONG(&_7$$4, i)) {
			break;
		}
		zephir_array_fetch_string(&_8$$4, &range, SL("start"), PH_NOISY | PH_READONLY, "ice/dump.zep", 371);
		if (ZEPHIR_LE_LONG(&_8$$4, i)) {
			ZVAL_LONG(&_9$$7, 0);
			ZEPHIR_INIT_NVAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "utf-8");
			ZEPHIR_CALL_FUNCTION(&_11$$7, "htmlspecialchars", &_12, 123, &row, &_9$$7, &_10$$7);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&row, &_11$$7);
			if (i == line) {
				ZEPHIR_INIT_NVAR(&_13$$8);
				zephir_read_property(&_14$$8, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
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
				ZEPHIR_CALL_FUNCTION(&_16$$8, "strtr", &_19, 110, &_13$$8, &_15$$8);
				zephir_check_call_status();
				ZVAL_LONG(&_20$$8, i);
				ZEPHIR_CALL_FUNCTION(&_21$$8, "sprintf", &_22, 11, &format, &_20$$8);
				zephir_check_call_status();
				zephir_array_update_zval(&lines, &_21$$8, &_16$$8, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_23$$9);
				zephir_read_property(&_24$$9, this_ptr, ZEND_STRL("plain"), PH_NOISY_CC | PH_READONLY);
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
				ZEPHIR_CALL_FUNCTION(&_26$$9, "strtr", &_19, 110, &_23$$9, &_25$$9);
				zephir_check_call_status();
				ZVAL_LONG(&_28$$9, i);
				ZEPHIR_CALL_FUNCTION(&_29$$9, "sprintf", &_22, 11, &format, &_28$$9);
				zephir_check_call_status();
				zephir_array_update_zval(&lines, &_29$$9, &_26$$9, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_CALL_FUNCTION(&row, "fgets", &_6, 122, &file);
		zephir_check_call_status();
	}
	zephir_fclose(&file);
	RETURN_CCTOR(&lines);
}

zend_object *zephir_init_properties_Ice_Dump(zend_class_entry *class_type)
{
		zval _7$$6;
	zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_7$$6);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("styles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("styles"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("objects"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("objects"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("methods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("methods"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("skip"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			zephir_create_array(&_7$$6, 1, 0);
			ZEPHIR_INIT_VAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "Ice\\Di");
			zephir_array_fast_append(&_7$$6, &_8$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("skip"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

