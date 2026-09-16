
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
 * @copyright   (c) Ice Team
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

	RETURN_MEMBER(getThis(), "detailed");
}

PHP_METHOD(Ice_Dump, setDetailed)
{
	zval *detailed, detailed_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&detailed_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("detailed", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(detailed)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &detailed);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 153, detailed);
	RETURN_THISW();
}

PHP_METHOD(Ice_Dump, getPlain)
{

	RETURN_MEMBER(getThis(), "plain");
}

PHP_METHOD(Ice_Dump, setPlain)
{
	zval *plain, plain_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&plain_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("plain", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(plain)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &plain);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 154, plain);
	RETURN_THISW();
}

PHP_METHOD(Ice_Dump, getSkip)
{

	RETURN_MEMBER(getThis(), "skip");
}

PHP_METHOD(Ice_Dump, setSkip)
{
	zval *skip, skip_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&skip_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("skip", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(skip)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &skip);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 155, skip);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("plain", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("detailed", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(detailed)
		Z_PARAM_ZVAL(styles)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &detailed_param, &styles);
	if (!detailed_param) {
		detailed = 0;
	} else {
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 154, styles);
	}
	if (detailed) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 153, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 153, &__$false);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	zval type_zv, style, _0;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&style);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("styles", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_memory_observe(&style);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 156, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&style, &_0, &type_zv, 0)) {
		RETURN_CCTOR(&style);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("styles", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(styles, styles_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 156, &_0);
	RETURN_MM_MEMBER_TYPED(getThis(), "styles", IS_ARRAY);
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
	zend_string *name = NULL;
	zval *variable, variable_sub, name_zv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(variable)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	variable = ZEND_CALL_ARG(execute_data, 1);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "variable", NULL, 0, variable, &name_zv);
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
	zend_bool _30$$4, _21$$5, _22$$5, _23$$5, _38$$8, _39$$8, _40$$8, _86$$15, _117$$18, _169$$28;
	zend_string *_12$$4, *_74$$15;
	zend_ulong _11$$4, _73$$15;
	zval _230, _4$$4, _17$$5, _34$$8, _49$$11, _138$$11, _56$$12, _78$$16, _90$$17, _109$$19, _126$$23, _155$$31, _164$$32, _176$$35, _185$$36, _196$$37, _202$$38, _207$$39, _212$$40, _219$$41, _225$$42;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_14 = NULL, *_27 = NULL, *_53 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, *name = NULL, name_sub, *tab = NULL, tab_sub, __$null, key, value, output, space, type, attr, _199, _228, _229, _231, _232, _0$$4, _1$$4, _2$$4, _3$$4, _5$$4, _6$$4, *_9$$4, *_10$$4, _29$$4, _45$$4, _46$$4, _13$$5, _15$$5, _16$$5, _18$$5, _19$$5, _20$$5, _24$$7, _25$$7, _26$$7, _28$$7, _31$$8, _32$$8, _33$$8, _35$$8, _36$$8, _37$$8, _41$$10, _42$$10, _43$$10, _44$$10, className$$11, hash$$11, _47$$11, _48$$11, _50$$11, _51$$11, _52$$11, _59$$11, _60$$11, _61$$11, _62$$11, _133$$11, _134$$11, _135$$11, _136$$11, _137$$11, _139$$11, _140$$11, _141$$11, _142$$11, _192$$11, _193$$11, _54$$12, _55$$12, _57$$12, _58$$12, _63$$13, _64$$13, _65$$13, _66$$14, _67$$14, _68$$14, _69$$15, *_70$$15, _71$$15, *_72$$15, _85$$15, _75$$16, _76$$16, _77$$16, _79$$16, _80$$16, _81$$16, _82$$16, _83$$16, _84$$16, _87$$17, _88$$17, _89$$17, _91$$17, _92$$17, _93$$17, _94$$17, _95$$17, _96$$17, reflect$$18, _97$$18, *_98$$18, _99$$18, *_100$$18, _116$$18, _101$$19, _103$$19, _105$$19, _106$$19, _107$$19, _108$$19, _110$$19, _111$$19, _112$$19, _113$$19, _114$$19, _115$$19, _102$$20, _104$$21, _118$$23, _120$$23, _122$$23, _123$$23, _124$$23, _125$$23, _127$$23, _128$$23, _129$$23, _130$$23, _131$$23, _132$$23, _119$$24, _121$$25, _143$$27, _144$$27, _145$$27, *_146$$28, _147$$28, *_148$$28, _168$$28, _189$$28, _190$$28, _191$$28, _149$$29, _150$$31, _151$$31, _152$$31, _153$$31, _154$$31, _156$$31, _157$$31, _158$$31, _159$$32, _160$$32, _161$$32, _162$$32, _163$$32, _165$$32, _166$$32, _167$$32, _170$$33, _171$$35, _172$$35, _173$$35, _174$$35, _175$$35, _177$$35, _178$$35, _179$$35, _180$$36, _181$$36, _182$$36, _183$$36, _184$$36, _186$$36, _187$$36, _188$$36, _194$$37, _195$$37, _197$$37, _198$$37, _200$$38, _201$$38, _203$$38, _204$$38, _205$$39, _206$$39, _208$$39, _209$$39, _210$$40, _211$$40, _213$$40, _214$$40, _215$$40, _216$$40, _217$$41, _218$$41, _220$$41, _221$$41, _222$$41, _223$$42, _224$$42, _226$$42, _227$$42;
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
	ZVAL_UNDEF(&_199);
	ZVAL_UNDEF(&_228);
	ZVAL_UNDEF(&_229);
	ZVAL_UNDEF(&_231);
	ZVAL_UNDEF(&_232);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_29$$4);
	ZVAL_UNDEF(&_45$$4);
	ZVAL_UNDEF(&_46$$4);
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
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_37$$8);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&className$$11);
	ZVAL_UNDEF(&hash$$11);
	ZVAL_UNDEF(&_47$$11);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_51$$11);
	ZVAL_UNDEF(&_52$$11);
	ZVAL_UNDEF(&_59$$11);
	ZVAL_UNDEF(&_60$$11);
	ZVAL_UNDEF(&_61$$11);
	ZVAL_UNDEF(&_62$$11);
	ZVAL_UNDEF(&_133$$11);
	ZVAL_UNDEF(&_134$$11);
	ZVAL_UNDEF(&_135$$11);
	ZVAL_UNDEF(&_136$$11);
	ZVAL_UNDEF(&_137$$11);
	ZVAL_UNDEF(&_139$$11);
	ZVAL_UNDEF(&_140$$11);
	ZVAL_UNDEF(&_141$$11);
	ZVAL_UNDEF(&_142$$11);
	ZVAL_UNDEF(&_192$$11);
	ZVAL_UNDEF(&_193$$11);
	ZVAL_UNDEF(&_54$$12);
	ZVAL_UNDEF(&_55$$12);
	ZVAL_UNDEF(&_57$$12);
	ZVAL_UNDEF(&_58$$12);
	ZVAL_UNDEF(&_63$$13);
	ZVAL_UNDEF(&_64$$13);
	ZVAL_UNDEF(&_65$$13);
	ZVAL_UNDEF(&_66$$14);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_68$$14);
	ZVAL_UNDEF(&_69$$15);
	ZVAL_UNDEF(&_71$$15);
	ZVAL_UNDEF(&_85$$15);
	ZVAL_UNDEF(&_75$$16);
	ZVAL_UNDEF(&_76$$16);
	ZVAL_UNDEF(&_77$$16);
	ZVAL_UNDEF(&_79$$16);
	ZVAL_UNDEF(&_80$$16);
	ZVAL_UNDEF(&_81$$16);
	ZVAL_UNDEF(&_82$$16);
	ZVAL_UNDEF(&_83$$16);
	ZVAL_UNDEF(&_84$$16);
	ZVAL_UNDEF(&_87$$17);
	ZVAL_UNDEF(&_88$$17);
	ZVAL_UNDEF(&_89$$17);
	ZVAL_UNDEF(&_91$$17);
	ZVAL_UNDEF(&_92$$17);
	ZVAL_UNDEF(&_93$$17);
	ZVAL_UNDEF(&_94$$17);
	ZVAL_UNDEF(&_95$$17);
	ZVAL_UNDEF(&_96$$17);
	ZVAL_UNDEF(&reflect$$18);
	ZVAL_UNDEF(&_97$$18);
	ZVAL_UNDEF(&_99$$18);
	ZVAL_UNDEF(&_116$$18);
	ZVAL_UNDEF(&_101$$19);
	ZVAL_UNDEF(&_103$$19);
	ZVAL_UNDEF(&_105$$19);
	ZVAL_UNDEF(&_106$$19);
	ZVAL_UNDEF(&_107$$19);
	ZVAL_UNDEF(&_108$$19);
	ZVAL_UNDEF(&_110$$19);
	ZVAL_UNDEF(&_111$$19);
	ZVAL_UNDEF(&_112$$19);
	ZVAL_UNDEF(&_113$$19);
	ZVAL_UNDEF(&_114$$19);
	ZVAL_UNDEF(&_115$$19);
	ZVAL_UNDEF(&_102$$20);
	ZVAL_UNDEF(&_104$$21);
	ZVAL_UNDEF(&_118$$23);
	ZVAL_UNDEF(&_120$$23);
	ZVAL_UNDEF(&_122$$23);
	ZVAL_UNDEF(&_123$$23);
	ZVAL_UNDEF(&_124$$23);
	ZVAL_UNDEF(&_125$$23);
	ZVAL_UNDEF(&_127$$23);
	ZVAL_UNDEF(&_128$$23);
	ZVAL_UNDEF(&_129$$23);
	ZVAL_UNDEF(&_130$$23);
	ZVAL_UNDEF(&_131$$23);
	ZVAL_UNDEF(&_132$$23);
	ZVAL_UNDEF(&_119$$24);
	ZVAL_UNDEF(&_121$$25);
	ZVAL_UNDEF(&_143$$27);
	ZVAL_UNDEF(&_144$$27);
	ZVAL_UNDEF(&_145$$27);
	ZVAL_UNDEF(&_147$$28);
	ZVAL_UNDEF(&_168$$28);
	ZVAL_UNDEF(&_189$$28);
	ZVAL_UNDEF(&_190$$28);
	ZVAL_UNDEF(&_191$$28);
	ZVAL_UNDEF(&_149$$29);
	ZVAL_UNDEF(&_150$$31);
	ZVAL_UNDEF(&_151$$31);
	ZVAL_UNDEF(&_152$$31);
	ZVAL_UNDEF(&_153$$31);
	ZVAL_UNDEF(&_154$$31);
	ZVAL_UNDEF(&_156$$31);
	ZVAL_UNDEF(&_157$$31);
	ZVAL_UNDEF(&_158$$31);
	ZVAL_UNDEF(&_159$$32);
	ZVAL_UNDEF(&_160$$32);
	ZVAL_UNDEF(&_161$$32);
	ZVAL_UNDEF(&_162$$32);
	ZVAL_UNDEF(&_163$$32);
	ZVAL_UNDEF(&_165$$32);
	ZVAL_UNDEF(&_166$$32);
	ZVAL_UNDEF(&_167$$32);
	ZVAL_UNDEF(&_170$$33);
	ZVAL_UNDEF(&_171$$35);
	ZVAL_UNDEF(&_172$$35);
	ZVAL_UNDEF(&_173$$35);
	ZVAL_UNDEF(&_174$$35);
	ZVAL_UNDEF(&_175$$35);
	ZVAL_UNDEF(&_177$$35);
	ZVAL_UNDEF(&_178$$35);
	ZVAL_UNDEF(&_179$$35);
	ZVAL_UNDEF(&_180$$36);
	ZVAL_UNDEF(&_181$$36);
	ZVAL_UNDEF(&_182$$36);
	ZVAL_UNDEF(&_183$$36);
	ZVAL_UNDEF(&_184$$36);
	ZVAL_UNDEF(&_186$$36);
	ZVAL_UNDEF(&_187$$36);
	ZVAL_UNDEF(&_188$$36);
	ZVAL_UNDEF(&_194$$37);
	ZVAL_UNDEF(&_195$$37);
	ZVAL_UNDEF(&_197$$37);
	ZVAL_UNDEF(&_198$$37);
	ZVAL_UNDEF(&_200$$38);
	ZVAL_UNDEF(&_201$$38);
	ZVAL_UNDEF(&_203$$38);
	ZVAL_UNDEF(&_204$$38);
	ZVAL_UNDEF(&_205$$39);
	ZVAL_UNDEF(&_206$$39);
	ZVAL_UNDEF(&_208$$39);
	ZVAL_UNDEF(&_209$$39);
	ZVAL_UNDEF(&_210$$40);
	ZVAL_UNDEF(&_211$$40);
	ZVAL_UNDEF(&_213$$40);
	ZVAL_UNDEF(&_214$$40);
	ZVAL_UNDEF(&_215$$40);
	ZVAL_UNDEF(&_216$$40);
	ZVAL_UNDEF(&_217$$41);
	ZVAL_UNDEF(&_218$$41);
	ZVAL_UNDEF(&_220$$41);
	ZVAL_UNDEF(&_221$$41);
	ZVAL_UNDEF(&_222$$41);
	ZVAL_UNDEF(&_223$$42);
	ZVAL_UNDEF(&_224$$42);
	ZVAL_UNDEF(&_226$$42);
	ZVAL_UNDEF(&_227$$42);
	ZVAL_UNDEF(&_230);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_138$$11);
	ZVAL_UNDEF(&_56$$12);
	ZVAL_UNDEF(&_78$$16);
	ZVAL_UNDEF(&_90$$17);
	ZVAL_UNDEF(&_109$$19);
	ZVAL_UNDEF(&_126$$23);
	ZVAL_UNDEF(&_155$$31);
	ZVAL_UNDEF(&_164$$32);
	ZVAL_UNDEF(&_176$$35);
	ZVAL_UNDEF(&_185$$36);
	ZVAL_UNDEF(&_196$$37);
	ZVAL_UNDEF(&_202$$38);
	ZVAL_UNDEF(&_207$$39);
	ZVAL_UNDEF(&_212$$40);
	ZVAL_UNDEF(&_219$$41);
	ZVAL_UNDEF(&_225$$42);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("plain", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("skip", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("objects", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("detailed", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("methods", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(variable)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(name)
		Z_PARAM_ZVAL(tab)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_CALL_FUNCTION(&_5$$4, "strtr", &_8, 113, &_0$$4, &_4$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_5$$4);
		if (Z_TYPE_P(variable) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_6$$4);
			zephir_string_to_char_array(&_6$$4, variable);
			_9$$4 = &_6$$4;
		} else {
			_9$$4 = variable;
		}
		zephir_is_iterable(_9$$4, 0, "ice/dump.zep", 175);
		if (Z_TYPE_P(_9$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_9$$4), _11$$4, _12$$4, _10$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_12$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _12$$4);
				} else {
					ZVAL_LONG(&key, _11$$4);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _10$$4);
				ZEPHIR_CALL_FUNCTION(&_13$$5, "str_repeat", &_14, 96, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$5);
				zephir_read_property_cached(&_16$$5, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
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
				ZEPHIR_CALL_FUNCTION(&_18$$5, "strtr", &_8, 113, &_15$$5, &_17$$5);
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
					ZEPHIR_CALL_METHOD(&_24$$7, this_ptr, "output", &_27, 114, &value, &_25$$7, &_26$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZEPHIR_GET_CONSTANT(&_25$$7, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_28$$7);
					ZEPHIR_CONCAT_VV(&_28$$7, &_24$$7, &_25$$7);
					zephir_concat_self(&output, &_28$$7);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _9$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_30$$4 = 1;
			while (1) {
				if (_30$$4) {
					_30$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _9$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_29$$4, _9$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_29$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, _9$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, _9$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_31$$8, "str_repeat", &_14, 96, &space, tab);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_32$$8);
					zephir_read_property_cached(&_33$$8, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_33$$8)) {
						ZEPHIR_INIT_NVAR(&_32$$8);
						ZVAL_STRING(&_32$$8, "[:key] => ");
					} else {
						ZEPHIR_INIT_NVAR(&_32$$8);
						ZVAL_STRING(&_32$$8, "[<span style=':style'>:key</span>] => ");
					}
					ZEPHIR_INIT_NVAR(&_34$$8);
					zephir_create_array(&_34$$8, 2, 0);
					ZEPHIR_INIT_NVAR(&_36$$8);
					ZVAL_STRING(&_36$$8, "arr");
					ZEPHIR_CALL_METHOD(&_35$$8, this_ptr, "getstyle", &_7, 0, &_36$$8);
					zephir_check_call_status();
					zephir_array_update_string(&_34$$8, SL(":style"), &_35$$8, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_34$$8, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_35$$8, "strtr", &_8, 113, &_32$$8, &_34$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_37$$8);
					ZEPHIR_CONCAT_VV(&_37$$8, &_31$$8, &_35$$8);
					zephir_concat_self(&output, &_37$$8);
					_38$$8 = ZEPHIR_IS_LONG(tab, 1);
					if (_38$$8) {
						_38$$8 = !ZEPHIR_IS_STRING(name, "");
					}
					_39$$8 = _38$$8;
					if (_39$$8) {
						_39$$8 = !(Z_TYPE_P(&key) == IS_LONG);
					}
					_40$$8 = _39$$8;
					if (_40$$8) {
						_40$$8 = ZEPHIR_IS_EQUAL(name, &key);
					}
					if (_40$$8) {
						continue;
					} else {
						ZEPHIR_INIT_NVAR(&_42$$10);
						ZVAL_STRING(&_42$$10, "");
						ZVAL_LONG(&_43$$10, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_METHOD(&_41$$10, this_ptr, "output", &_27, 114, &value, &_42$$10, &_43$$10);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_42$$10);
						ZEPHIR_GET_CONSTANT(&_42$$10, "PHP_EOL");
						ZEPHIR_INIT_NVAR(&_44$$10);
						ZEPHIR_CONCAT_VV(&_44$$10, &_41$$10, &_42$$10);
						zephir_concat_self(&output, &_44$$10);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_45$$4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_46$$4, "str_repeat", &_14, 96, &space, &_45$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_46$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&className$$11);
		zephir_get_class(&className$$11, variable, 0);
		ZEPHIR_CPY_WRT(&className$$11, &className$$11);
		ZEPHIR_CALL_FUNCTION(&hash$$11, "spl_object_hash", NULL, 112, variable);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&hash$$11, &hash$$11);
		ZEPHIR_INIT_VAR(&_47$$11);
		zephir_read_property_cached(&_48$$11, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_48$$11)) {
			ZEPHIR_INIT_NVAR(&_47$$11);
			ZVAL_STRING(&_47$$11, "object :class");
		} else {
			ZEPHIR_INIT_NVAR(&_47$$11);
			ZVAL_STRING(&_47$$11, "<b style=':style'>object</b> :class");
		}
		ZEPHIR_INIT_VAR(&_49$$11);
		zephir_create_array(&_49$$11, 2, 0);
		ZEPHIR_INIT_VAR(&_51$$11);
		ZVAL_STRING(&_51$$11, "obj");
		ZEPHIR_CALL_METHOD(&_50$$11, this_ptr, "getstyle", &_7, 0, &_51$$11);
		zephir_check_call_status();
		zephir_array_update_string(&_49$$11, SL(":style"), &_50$$11, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_49$$11, SL(":class"), &className$$11, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_50$$11, "strtr", &_8, 113, &_47$$11, &_49$$11);
		zephir_check_call_status();
		zephir_concat_self(&output, &_50$$11);
		ZEPHIR_CALL_FUNCTION(&_52$$11, "get_parent_class", &_53, 115, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_52$$11)) {
			ZEPHIR_INIT_VAR(&_54$$12);
			zephir_read_property_cached(&_55$$12, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_55$$12)) {
				ZEPHIR_INIT_NVAR(&_54$$12);
				ZVAL_STRING(&_54$$12, " extends :parent");
			} else {
				ZEPHIR_INIT_NVAR(&_54$$12);
				ZVAL_STRING(&_54$$12, " <b style=':style'>extends</b> :parent");
			}
			ZEPHIR_INIT_VAR(&_56$$12);
			zephir_create_array(&_56$$12, 2, 0);
			ZEPHIR_INIT_VAR(&_58$$12);
			ZVAL_STRING(&_58$$12, "obj");
			ZEPHIR_CALL_METHOD(&_57$$12, this_ptr, "getstyle", &_7, 0, &_58$$12);
			zephir_check_call_status();
			zephir_array_update_string(&_56$$12, SL(":style"), &_57$$12, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_57$$12, "get_parent_class", &_53, 115, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_56$$12, SL(":parent"), &_57$$12, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_57$$12, "strtr", &_8, 113, &_54$$12, &_56$$12);
			zephir_check_call_status();
			zephir_concat_self(&output, &_57$$12);
		}
		ZEPHIR_INIT_NVAR(&_51$$11);
		ZEPHIR_GET_CONSTANT(&_51$$11, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_59$$11);
		ZEPHIR_CONCAT_SV(&_59$$11, " (", &_51$$11);
		zephir_concat_self(&output, &_59$$11);
		zephir_read_property_cached(&_60$$11, this_ptr, _zephir_prop_1, 155, PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&className$$11, &_60$$11)) {
			ZEPHIR_CALL_FUNCTION(&_63$$13, "str_repeat", &_14, 96, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_64$$13);
			ZEPHIR_GET_CONSTANT(&_64$$13, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_65$$13);
			ZEPHIR_CONCAT_VSV(&_65$$13, &_63$$13, "[skipped]", &_64$$13);
			zephir_concat_self(&output, &_65$$13);
		} else {
			zephir_read_property_cached(&_61$$11, this_ptr, _zephir_prop_2, 157, PH_NOISY_CC | PH_READONLY);
			if (zephir_fast_in_array(&hash$$11, &_61$$11)) {
				ZEPHIR_CALL_FUNCTION(&_66$$14, "str_repeat", &_14, 96, &space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_67$$14);
				ZEPHIR_GET_CONSTANT(&_67$$14, "PHP_EOL");
				ZEPHIR_INIT_VAR(&_68$$14);
				ZEPHIR_CONCAT_VSV(&_68$$14, &_66$$14, "[already listed]", &_67$$14);
				zephir_concat_self(&output, &_68$$14);
			} else {
				zephir_read_property_cached(&_62$$11, this_ptr, _zephir_prop_3, 153, PH_NOISY_CC | PH_READONLY);
				if (!(zephir_is_true(&_62$$11))) {
					ZEPHIR_CALL_FUNCTION(&_69$$15, "get_object_vars", NULL, 116, variable);
					zephir_check_call_status();
					if (Z_TYPE_P(&_69$$15) == IS_STRING) {
						ZEPHIR_INIT_VAR(&_71$$15);
						zephir_string_to_char_array(&_71$$15, &_69$$15);
						_70$$15 = &_71$$15;
					} else {
						_70$$15 = &_69$$15;
					}
					zephir_is_iterable(_70$$15, 0, "ice/dump.zep", 203);
					if (Z_TYPE_P(_70$$15) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_70$$15), _73$$15, _74$$15, _72$$15)
						{
							ZEPHIR_INIT_NVAR(&key);
							if (_74$$15 != NULL) { 
								ZVAL_STR_COPY(&key, _74$$15);
							} else {
								ZVAL_LONG(&key, _73$$15);
							}
							ZEPHIR_INIT_NVAR(&value);
							ZVAL_COPY(&value, _72$$15);
							zephir_update_property_array_append(this_ptr, SL("objects"), &hash$$11);
							ZEPHIR_CALL_FUNCTION(&_75$$16, "str_repeat", &_14, 96, &space, tab);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_76$$16);
							zephir_read_property_cached(&_77$$16, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_77$$16)) {
								ZEPHIR_INIT_NVAR(&_76$$16);
								ZVAL_STRING(&_76$$16, "->:key (:type) = ");
							} else {
								ZEPHIR_INIT_NVAR(&_76$$16);
								ZVAL_STRING(&_76$$16, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
							}
							ZEPHIR_INIT_NVAR(&_78$$16);
							zephir_create_array(&_78$$16, 3, 0);
							ZEPHIR_INIT_NVAR(&_80$$16);
							ZVAL_STRING(&_80$$16, "obj");
							ZEPHIR_CALL_METHOD(&_79$$16, this_ptr, "getstyle", &_7, 0, &_80$$16);
							zephir_check_call_status();
							zephir_array_update_string(&_78$$16, SL(":style"), &_79$$16, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_78$$16, SL(":key"), &key, PH_COPY | PH_SEPARATE);
							add_assoc_stringl_ex(&_78$$16, SL(":type"), SL("public"));
							ZEPHIR_CALL_FUNCTION(&_79$$16, "strtr", &_8, 113, &_76$$16, &_78$$16);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_81$$16);
							ZEPHIR_CONCAT_VV(&_81$$16, &_75$$16, &_79$$16);
							zephir_concat_self(&output, &_81$$16);
							ZEPHIR_INIT_NVAR(&_80$$16);
							ZVAL_STRING(&_80$$16, "");
							ZVAL_LONG(&_83$$16, (zephir_get_numberval(tab) + 1));
							ZEPHIR_CALL_METHOD(&_82$$16, this_ptr, "output", &_27, 114, &value, &_80$$16, &_83$$16);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_80$$16);
							ZEPHIR_GET_CONSTANT(&_80$$16, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_84$$16);
							ZEPHIR_CONCAT_VV(&_84$$16, &_82$$16, &_80$$16);
							zephir_concat_self(&output, &_84$$16);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _70$$15, "rewind", NULL, 0);
						zephir_check_call_status();
						_86$$15 = 1;
						while (1) {
							if (_86$$15) {
								_86$$15 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _70$$15, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_85$$15, _70$$15, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_85$$15)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&key, _70$$15, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&value, _70$$15, "current", NULL, 0);
							zephir_check_call_status();
								zephir_update_property_array_append(this_ptr, SL("objects"), &hash$$11);
								ZEPHIR_CALL_FUNCTION(&_87$$17, "str_repeat", &_14, 96, &space, tab);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_88$$17);
								zephir_read_property_cached(&_89$$17, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
								if (zephir_is_true(&_89$$17)) {
									ZEPHIR_INIT_NVAR(&_88$$17);
									ZVAL_STRING(&_88$$17, "->:key (:type) = ");
								} else {
									ZEPHIR_INIT_NVAR(&_88$$17);
									ZVAL_STRING(&_88$$17, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
								}
								ZEPHIR_INIT_NVAR(&_90$$17);
								zephir_create_array(&_90$$17, 3, 0);
								ZEPHIR_INIT_NVAR(&_92$$17);
								ZVAL_STRING(&_92$$17, "obj");
								ZEPHIR_CALL_METHOD(&_91$$17, this_ptr, "getstyle", &_7, 0, &_92$$17);
								zephir_check_call_status();
								zephir_array_update_string(&_90$$17, SL(":style"), &_91$$17, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_90$$17, SL(":key"), &key, PH_COPY | PH_SEPARATE);
								add_assoc_stringl_ex(&_90$$17, SL(":type"), SL("public"));
								ZEPHIR_CALL_FUNCTION(&_91$$17, "strtr", &_8, 113, &_88$$17, &_90$$17);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_93$$17);
								ZEPHIR_CONCAT_VV(&_93$$17, &_87$$17, &_91$$17);
								zephir_concat_self(&output, &_93$$17);
								ZEPHIR_INIT_NVAR(&_92$$17);
								ZVAL_STRING(&_92$$17, "");
								ZVAL_LONG(&_95$$17, (zephir_get_numberval(tab) + 1));
								ZEPHIR_CALL_METHOD(&_94$$17, this_ptr, "output", &_27, 114, &value, &_92$$17, &_95$$17);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_92$$17);
								ZEPHIR_GET_CONSTANT(&_92$$17, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_96$$17);
								ZEPHIR_CONCAT_VV(&_96$$17, &_94$$17, &_92$$17);
								zephir_concat_self(&output, &_96$$17);
						}
					}
					ZEPHIR_INIT_NVAR(&value);
					ZEPHIR_INIT_NVAR(&key);
				} else {
					if (zephir_is_instance_of(variable, SL("stdClass"))) {
						ZEPHIR_INIT_VAR(&reflect$$18);
						object_init_ex(&reflect$$18, zephir_get_internal_ce(SL("reflectionobject")));
						ZEPHIR_CALL_METHOD(NULL, &reflect$$18, "__construct", NULL, 117, variable);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&reflect$$18);
						object_init_ex(&reflect$$18, zephir_get_internal_ce(SL("reflectionclass")));
						ZEPHIR_CALL_METHOD(NULL, &reflect$$18, "__construct", NULL, 105, variable);
						zephir_check_call_status();
					}
					ZEPHIR_CPY_WRT(&reflect$$18, &reflect$$18);
					ZEPHIR_CALL_METHOD(&_97$$18, &reflect$$18, "getproperties", NULL, 118);
					zephir_check_call_status();
					if (Z_TYPE_P(&_97$$18) == IS_STRING) {
						ZEPHIR_INIT_VAR(&_99$$18);
						zephir_string_to_char_array(&_99$$18, &_97$$18);
						_98$$18 = &_99$$18;
					} else {
						_98$$18 = &_97$$18;
					}
					zephir_is_iterable(_98$$18, 0, "ice/dump.zep", 233);
					if (Z_TYPE_P(_98$$18) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_98$$18), _100$$18)
						{
							ZEPHIR_INIT_NVAR(&attr);
							ZVAL_COPY(&attr, _100$$18);
							ZEPHIR_CALL_METHOD(&key, &attr, "getname", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							ZVAL_STRING(&type, "public");
							ZEPHIR_CALL_METHOD(&_101$$19, &attr, "isprotected", NULL, 0);
							zephir_check_call_status();
							if (zephir_is_true(&_101$$19)) {
								ZVAL_BOOL(&_102$$20, 1);
								ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_102$$20);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&type);
								ZVAL_STRING(&type, "protected");
							}
							ZEPHIR_CALL_METHOD(&_103$$19, &attr, "isprivate", NULL, 0);
							zephir_check_call_status();
							if (zephir_is_true(&_103$$19)) {
								ZVAL_BOOL(&_104$$21, 1);
								ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_104$$21);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&type);
								ZVAL_STRING(&type, "private");
							}
							ZEPHIR_CALL_METHOD(&_105$$19, &attr, "isstatic", NULL, 0);
							zephir_check_call_status();
							if (zephir_is_true(&_105$$19)) {
								zephir_concat_self_str(&type, SL(" static"));
							}
							ZEPHIR_CALL_METHOD(&value, &attr, "getvalue", NULL, 0, variable);
							zephir_check_call_status();
							zephir_update_property_array_append(this_ptr, SL("objects"), &hash$$11);
							ZEPHIR_CALL_FUNCTION(&_106$$19, "str_repeat", &_14, 96, &space, tab);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_107$$19);
							zephir_read_property_cached(&_108$$19, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_108$$19)) {
								ZEPHIR_INIT_NVAR(&_107$$19);
								ZVAL_STRING(&_107$$19, "->:key (:type) = ");
							} else {
								ZEPHIR_INIT_NVAR(&_107$$19);
								ZVAL_STRING(&_107$$19, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
							}
							ZEPHIR_INIT_NVAR(&_109$$19);
							zephir_create_array(&_109$$19, 3, 0);
							ZEPHIR_INIT_NVAR(&_111$$19);
							ZVAL_STRING(&_111$$19, "obj");
							ZEPHIR_CALL_METHOD(&_110$$19, this_ptr, "getstyle", &_7, 0, &_111$$19);
							zephir_check_call_status();
							zephir_array_update_string(&_109$$19, SL(":style"), &_110$$19, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_109$$19, SL(":key"), &key, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_109$$19, SL(":type"), &type, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_FUNCTION(&_110$$19, "strtr", &_8, 113, &_107$$19, &_109$$19);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_112$$19);
							ZEPHIR_CONCAT_VV(&_112$$19, &_106$$19, &_110$$19);
							zephir_concat_self(&output, &_112$$19);
							ZEPHIR_INIT_NVAR(&_111$$19);
							ZVAL_STRING(&_111$$19, "");
							ZVAL_LONG(&_114$$19, (zephir_get_numberval(tab) + 1));
							ZEPHIR_CALL_METHOD(&_113$$19, this_ptr, "output", &_27, 114, &value, &_111$$19, &_114$$19);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_111$$19);
							ZEPHIR_GET_CONSTANT(&_111$$19, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_115$$19);
							ZEPHIR_CONCAT_VV(&_115$$19, &_113$$19, &_111$$19);
							zephir_concat_self(&output, &_115$$19);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _98$$18, "rewind", NULL, 0);
						zephir_check_call_status();
						_117$$18 = 1;
						while (1) {
							if (_117$$18) {
								_117$$18 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _98$$18, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_116$$18, _98$$18, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_116$$18)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attr, _98$$18, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&key, &attr, "getname", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&type);
								ZVAL_STRING(&type, "public");
								ZEPHIR_CALL_METHOD(&_118$$23, &attr, "isprotected", NULL, 0);
								zephir_check_call_status();
								if (zephir_is_true(&_118$$23)) {
									ZVAL_BOOL(&_119$$24, 1);
									ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_119$$24);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&type);
									ZVAL_STRING(&type, "protected");
								}
								ZEPHIR_CALL_METHOD(&_120$$23, &attr, "isprivate", NULL, 0);
								zephir_check_call_status();
								if (zephir_is_true(&_120$$23)) {
									ZVAL_BOOL(&_121$$25, 1);
									ZEPHIR_CALL_METHOD(NULL, &attr, "setaccessible", NULL, 0, &_121$$25);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&type);
									ZVAL_STRING(&type, "private");
								}
								ZEPHIR_CALL_METHOD(&_122$$23, &attr, "isstatic", NULL, 0);
								zephir_check_call_status();
								if (zephir_is_true(&_122$$23)) {
									zephir_concat_self_str(&type, SL(" static"));
								}
								ZEPHIR_CALL_METHOD(&value, &attr, "getvalue", NULL, 0, variable);
								zephir_check_call_status();
								zephir_update_property_array_append(this_ptr, SL("objects"), &hash$$11);
								ZEPHIR_CALL_FUNCTION(&_123$$23, "str_repeat", &_14, 96, &space, tab);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_124$$23);
								zephir_read_property_cached(&_125$$23, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
								if (zephir_is_true(&_125$$23)) {
									ZEPHIR_INIT_NVAR(&_124$$23);
									ZVAL_STRING(&_124$$23, "->:key (:type) = ");
								} else {
									ZEPHIR_INIT_NVAR(&_124$$23);
									ZVAL_STRING(&_124$$23, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
								}
								ZEPHIR_INIT_NVAR(&_126$$23);
								zephir_create_array(&_126$$23, 3, 0);
								ZEPHIR_INIT_NVAR(&_128$$23);
								ZVAL_STRING(&_128$$23, "obj");
								ZEPHIR_CALL_METHOD(&_127$$23, this_ptr, "getstyle", &_7, 0, &_128$$23);
								zephir_check_call_status();
								zephir_array_update_string(&_126$$23, SL(":style"), &_127$$23, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_126$$23, SL(":key"), &key, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_126$$23, SL(":type"), &type, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_FUNCTION(&_127$$23, "strtr", &_8, 113, &_124$$23, &_126$$23);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_129$$23);
								ZEPHIR_CONCAT_VV(&_129$$23, &_123$$23, &_127$$23);
								zephir_concat_self(&output, &_129$$23);
								ZEPHIR_INIT_NVAR(&_128$$23);
								ZVAL_STRING(&_128$$23, "");
								ZVAL_LONG(&_131$$23, (zephir_get_numberval(tab) + 1));
								ZEPHIR_CALL_METHOD(&_130$$23, this_ptr, "output", &_27, 114, &value, &_128$$23, &_131$$23);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_128$$23);
								ZEPHIR_GET_CONSTANT(&_128$$23, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_132$$23);
								ZEPHIR_CONCAT_VV(&_132$$23, &_130$$23, &_128$$23);
								zephir_concat_self(&output, &_132$$23);
						}
					}
					ZEPHIR_INIT_NVAR(&attr);
				}
			}
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 119, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_133$$11, "str_repeat", &_14, 96, &space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_134$$11);
		zephir_read_property_cached(&_135$$11, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_135$$11)) {
			ZEPHIR_INIT_VAR(&_136$$11);
			ZEPHIR_GET_CONSTANT(&_136$$11, "PHP_EOL");
			ZEPHIR_INIT_NVAR(&_134$$11);
			ZEPHIR_CONCAT_SV(&_134$$11, ":class methods: (:count) (", &_136$$11);
		} else {
			ZEPHIR_INIT_VAR(&_137$$11);
			ZEPHIR_GET_CONSTANT(&_137$$11, "PHP_EOL");
			ZEPHIR_INIT_NVAR(&_134$$11);
			ZEPHIR_CONCAT_SV(&_134$$11, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (", &_137$$11);
		}
		ZEPHIR_INIT_VAR(&_138$$11);
		zephir_create_array(&_138$$11, 3, 0);
		ZEPHIR_INIT_VAR(&_140$$11);
		ZVAL_STRING(&_140$$11, "obj");
		ZEPHIR_CALL_METHOD(&_139$$11, this_ptr, "getstyle", &_7, 0, &_140$$11);
		zephir_check_call_status();
		zephir_array_update_string(&_138$$11, SL(":style"), &_139$$11, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_138$$11, SL(":class"), &className$$11, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_138$$11, SL(":count"), zephir_fast_count_int(&attr));
		ZEPHIR_CALL_FUNCTION(&_139$$11, "strtr", &_8, 113, &_134$$11, &_138$$11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_141$$11);
		ZEPHIR_CONCAT_VV(&_141$$11, &_133$$11, &_139$$11);
		zephir_concat_self(&output, &_141$$11);
		zephir_read_property_cached(&_142$$11, this_ptr, _zephir_prop_4, 158, PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&className$$11, &_142$$11)) {
			ZEPHIR_CALL_FUNCTION(&_143$$27, "str_repeat", &_14, 96, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_144$$27);
			ZEPHIR_GET_CONSTANT(&_144$$27, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_145$$27);
			ZEPHIR_CONCAT_VSV(&_145$$27, &_143$$27, "[already listed]", &_144$$27);
			zephir_concat_self(&output, &_145$$27);
		} else {
			if (Z_TYPE_P(&attr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_147$$28);
				zephir_string_to_char_array(&_147$$28, &attr);
				_146$$28 = &_147$$28;
			} else {
				_146$$28 = &attr;
			}
			zephir_is_iterable(_146$$28, 0, "ice/dump.zep", 251);
			if (Z_TYPE_P(_146$$28) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_146$$28), _148$$28)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _148$$28);
					zephir_read_property_cached(&_149$$29, this_ptr, _zephir_prop_4, 158, PH_NOISY_CC | PH_READONLY);
					if (!(zephir_fast_in_array(&className$$11, &_149$$29))) {
						zephir_update_property_array_append(this_ptr, SL("methods"), &className$$11);
					}
					if (ZEPHIR_IS_STRING(&value, "__construct")) {
						ZVAL_LONG(&_150$$31, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_FUNCTION(&_151$$31, "str_repeat", &_14, 96, &space, &_150$$31);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_152$$31);
						zephir_read_property_cached(&_150$$31, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_150$$31)) {
							ZEPHIR_INIT_NVAR(&_153$$31);
							ZEPHIR_GET_CONSTANT(&_153$$31, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_152$$31);
							ZEPHIR_CONCAT_SV(&_152$$31, "->:method(); [constructor]", &_153$$31);
						} else {
							ZEPHIR_INIT_NVAR(&_154$$31);
							ZEPHIR_GET_CONSTANT(&_154$$31, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_152$$31);
							ZEPHIR_CONCAT_SV(&_152$$31, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]", &_154$$31);
						}
						ZEPHIR_INIT_NVAR(&_155$$31);
						zephir_create_array(&_155$$31, 2, 0);
						ZEPHIR_INIT_NVAR(&_157$$31);
						ZVAL_STRING(&_157$$31, "obj");
						ZEPHIR_CALL_METHOD(&_156$$31, this_ptr, "getstyle", &_7, 0, &_157$$31);
						zephir_check_call_status();
						zephir_array_update_string(&_155$$31, SL(":style"), &_156$$31, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_155$$31, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_156$$31, "strtr", &_8, 113, &_152$$31, &_155$$31);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_158$$31);
						ZEPHIR_CONCAT_VV(&_158$$31, &_151$$31, &_156$$31);
						zephir_concat_self(&output, &_158$$31);
					} else {
						ZVAL_LONG(&_159$$32, (zephir_get_numberval(tab) + 1));
						ZEPHIR_CALL_FUNCTION(&_160$$32, "str_repeat", &_14, 96, &space, &_159$$32);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_161$$32);
						zephir_read_property_cached(&_159$$32, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_159$$32)) {
							ZEPHIR_INIT_NVAR(&_162$$32);
							ZEPHIR_GET_CONSTANT(&_162$$32, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_161$$32);
							ZEPHIR_CONCAT_SV(&_161$$32, "->:method();", &_162$$32);
						} else {
							ZEPHIR_INIT_NVAR(&_163$$32);
							ZEPHIR_GET_CONSTANT(&_163$$32, "PHP_EOL");
							ZEPHIR_INIT_NVAR(&_161$$32);
							ZEPHIR_CONCAT_SV(&_161$$32, "-><span style=':style'>:method</span>();", &_163$$32);
						}
						ZEPHIR_INIT_NVAR(&_164$$32);
						zephir_create_array(&_164$$32, 2, 0);
						ZEPHIR_INIT_NVAR(&_166$$32);
						ZVAL_STRING(&_166$$32, "obj");
						ZEPHIR_CALL_METHOD(&_165$$32, this_ptr, "getstyle", &_7, 0, &_166$$32);
						zephir_check_call_status();
						zephir_array_update_string(&_164$$32, SL(":style"), &_165$$32, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_164$$32, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_165$$32, "strtr", &_8, 113, &_161$$32, &_164$$32);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_167$$32);
						ZEPHIR_CONCAT_VV(&_167$$32, &_160$$32, &_165$$32);
						zephir_concat_self(&output, &_167$$32);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _146$$28, "rewind", NULL, 0);
				zephir_check_call_status();
				_169$$28 = 1;
				while (1) {
					if (_169$$28) {
						_169$$28 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _146$$28, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_168$$28, _146$$28, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_168$$28)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, _146$$28, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property_cached(&_170$$33, this_ptr, _zephir_prop_4, 158, PH_NOISY_CC | PH_READONLY);
						if (!(zephir_fast_in_array(&className$$11, &_170$$33))) {
							zephir_update_property_array_append(this_ptr, SL("methods"), &className$$11);
						}
						if (ZEPHIR_IS_STRING(&value, "__construct")) {
							ZVAL_LONG(&_171$$35, (zephir_get_numberval(tab) + 1));
							ZEPHIR_CALL_FUNCTION(&_172$$35, "str_repeat", &_14, 96, &space, &_171$$35);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_173$$35);
							zephir_read_property_cached(&_171$$35, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_171$$35)) {
								ZEPHIR_INIT_NVAR(&_174$$35);
								ZEPHIR_GET_CONSTANT(&_174$$35, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_173$$35);
								ZEPHIR_CONCAT_SV(&_173$$35, "->:method(); [constructor]", &_174$$35);
							} else {
								ZEPHIR_INIT_NVAR(&_175$$35);
								ZEPHIR_GET_CONSTANT(&_175$$35, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_173$$35);
								ZEPHIR_CONCAT_SV(&_173$$35, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]", &_175$$35);
							}
							ZEPHIR_INIT_NVAR(&_176$$35);
							zephir_create_array(&_176$$35, 2, 0);
							ZEPHIR_INIT_NVAR(&_178$$35);
							ZVAL_STRING(&_178$$35, "obj");
							ZEPHIR_CALL_METHOD(&_177$$35, this_ptr, "getstyle", &_7, 0, &_178$$35);
							zephir_check_call_status();
							zephir_array_update_string(&_176$$35, SL(":style"), &_177$$35, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_176$$35, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_FUNCTION(&_177$$35, "strtr", &_8, 113, &_173$$35, &_176$$35);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_179$$35);
							ZEPHIR_CONCAT_VV(&_179$$35, &_172$$35, &_177$$35);
							zephir_concat_self(&output, &_179$$35);
						} else {
							ZVAL_LONG(&_180$$36, (zephir_get_numberval(tab) + 1));
							ZEPHIR_CALL_FUNCTION(&_181$$36, "str_repeat", &_14, 96, &space, &_180$$36);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_182$$36);
							zephir_read_property_cached(&_180$$36, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_180$$36)) {
								ZEPHIR_INIT_NVAR(&_183$$36);
								ZEPHIR_GET_CONSTANT(&_183$$36, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_182$$36);
								ZEPHIR_CONCAT_SV(&_182$$36, "->:method();", &_183$$36);
							} else {
								ZEPHIR_INIT_NVAR(&_184$$36);
								ZEPHIR_GET_CONSTANT(&_184$$36, "PHP_EOL");
								ZEPHIR_INIT_NVAR(&_182$$36);
								ZEPHIR_CONCAT_SV(&_182$$36, "-><span style=':style'>:method</span>();", &_184$$36);
							}
							ZEPHIR_INIT_NVAR(&_185$$36);
							zephir_create_array(&_185$$36, 2, 0);
							ZEPHIR_INIT_NVAR(&_187$$36);
							ZVAL_STRING(&_187$$36, "obj");
							ZEPHIR_CALL_METHOD(&_186$$36, this_ptr, "getstyle", &_7, 0, &_187$$36);
							zephir_check_call_status();
							zephir_array_update_string(&_185$$36, SL(":style"), &_186$$36, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_185$$36, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_FUNCTION(&_186$$36, "strtr", &_8, 113, &_182$$36, &_185$$36);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_188$$36);
							ZEPHIR_CONCAT_VV(&_188$$36, &_181$$36, &_186$$36);
							zephir_concat_self(&output, &_188$$36);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_CALL_FUNCTION(&_189$$28, "str_repeat", &_14, 96, &space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_190$$28);
			ZEPHIR_GET_CONSTANT(&_190$$28, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_191$$28);
			ZEPHIR_CONCAT_VSV(&_191$$28, &_189$$28, ")", &_190$$28);
			zephir_concat_self(&output, &_191$$28);
		}
		ZVAL_LONG(&_192$$11, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_193$$11, "str_repeat", &_14, 96, &space, &_192$$11);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_193$$11, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_194$$37);
		zephir_read_property_cached(&_195$$37, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_195$$37)) {
			ZEPHIR_INIT_NVAR(&_194$$37);
			ZVAL_STRING(&_194$$37, "integer (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_194$$37);
			ZVAL_STRING(&_194$$37, "<b style=':style'>integer</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_196$$37);
		zephir_create_array(&_196$$37, 2, 0);
		ZEPHIR_INIT_VAR(&_198$$37);
		ZVAL_STRING(&_198$$37, "int");
		ZEPHIR_CALL_METHOD(&_197$$37, this_ptr, "getstyle", &_7, 0, &_198$$37);
		zephir_check_call_status();
		zephir_array_update_string(&_196$$37, SL(":style"), &_197$$37, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_196$$37, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_197$$37, "strtr", &_8, 113, &_194$$37, &_196$$37);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_197$$37);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_199, "is_float", NULL, 120, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_199)) {
		ZEPHIR_INIT_VAR(&_200$$38);
		zephir_read_property_cached(&_201$$38, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_201$$38)) {
			ZEPHIR_INIT_NVAR(&_200$$38);
			ZVAL_STRING(&_200$$38, "float (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_200$$38);
			ZVAL_STRING(&_200$$38, "<b style=':style'>float</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_202$$38);
		zephir_create_array(&_202$$38, 2, 0);
		ZEPHIR_INIT_VAR(&_204$$38);
		ZVAL_STRING(&_204$$38, "float");
		ZEPHIR_CALL_METHOD(&_203$$38, this_ptr, "getstyle", &_7, 0, &_204$$38);
		zephir_check_call_status();
		zephir_array_update_string(&_202$$38, SL(":style"), &_203$$38, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_202$$38, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_203$$38, "strtr", &_8, 113, &_200$$38, &_202$$38);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_203$$38);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_205$$39);
		zephir_read_property_cached(&_206$$39, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_206$$39)) {
			ZEPHIR_INIT_NVAR(&_205$$39);
			ZVAL_STRING(&_205$$39, "numeric string (:length) \":var\"");
		} else {
			ZEPHIR_INIT_NVAR(&_205$$39);
			ZVAL_STRING(&_205$$39, "<b style=':style'>numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		}
		ZEPHIR_INIT_VAR(&_207$$39);
		zephir_create_array(&_207$$39, 3, 0);
		ZEPHIR_INIT_VAR(&_209$$39);
		ZVAL_STRING(&_209$$39, "num");
		ZEPHIR_CALL_METHOD(&_208$$39, this_ptr, "getstyle", &_7, 0, &_209$$39);
		zephir_check_call_status();
		zephir_array_update_string(&_207$$39, SL(":style"), &_208$$39, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_207$$39, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_207$$39, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_208$$39, "strtr", &_8, 113, &_205$$39, &_207$$39);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_208$$39);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_210$$40);
		zephir_read_property_cached(&_211$$40, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_211$$40)) {
			ZEPHIR_INIT_NVAR(&_210$$40);
			ZVAL_STRING(&_210$$40, "string (:length) \":var\"");
		} else {
			ZEPHIR_INIT_NVAR(&_210$$40);
			ZVAL_STRING(&_210$$40, "<b style=':style'>string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		}
		ZEPHIR_INIT_VAR(&_212$$40);
		zephir_create_array(&_212$$40, 3, 0);
		ZEPHIR_INIT_VAR(&_214$$40);
		ZVAL_STRING(&_214$$40, "str");
		ZEPHIR_CALL_METHOD(&_213$$40, this_ptr, "getstyle", &_7, 0, &_214$$40);
		zephir_check_call_status();
		zephir_array_update_string(&_212$$40, SL(":style"), &_213$$40, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_212$$40, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_215$$40, 4);
		ZEPHIR_INIT_NVAR(&_214$$40);
		ZVAL_STRING(&_214$$40, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_213$$40, "htmlentities", NULL, 121, variable, &_215$$40, &_214$$40);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_216$$40, "nl2br", NULL, 122, &_213$$40);
		zephir_check_call_status();
		zephir_array_update_string(&_212$$40, SL(":var"), &_216$$40, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_216$$40, "strtr", &_8, 113, &_210$$40, &_212$$40);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_216$$40);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_217$$41);
		zephir_read_property_cached(&_218$$41, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_218$$41)) {
			ZEPHIR_INIT_NVAR(&_217$$41);
			ZVAL_STRING(&_217$$41, "boolean (:var)");
		} else {
			ZEPHIR_INIT_NVAR(&_217$$41);
			ZVAL_STRING(&_217$$41, "<b style=':style'>boolean</b> (<span style=':style'>:var</span>)");
		}
		ZEPHIR_INIT_VAR(&_219$$41);
		zephir_create_array(&_219$$41, 2, 0);
		ZEPHIR_INIT_VAR(&_221$$41);
		ZVAL_STRING(&_221$$41, "bool");
		ZEPHIR_CALL_METHOD(&_220$$41, this_ptr, "getstyle", &_7, 0, &_221$$41);
		zephir_check_call_status();
		zephir_array_update_string(&_219$$41, SL(":style"), &_220$$41, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_222$$41);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_222$$41);
			ZVAL_STRING(&_222$$41, "true");
		} else {
			ZEPHIR_INIT_NVAR(&_222$$41);
			ZVAL_STRING(&_222$$41, "false");
		}
		zephir_array_update_string(&_219$$41, SL(":var"), &_222$$41, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_220$$41, "strtr", &_8, 113, &_217$$41, &_219$$41);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_220$$41);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_223$$42);
		zephir_read_property_cached(&_224$$42, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_224$$42)) {
			ZEPHIR_INIT_NVAR(&_223$$42);
			ZVAL_STRING(&_223$$42, "null");
		} else {
			ZEPHIR_INIT_NVAR(&_223$$42);
			ZVAL_STRING(&_223$$42, "<b style=':style'>null</b>");
		}
		ZEPHIR_INIT_VAR(&_225$$42);
		zephir_create_array(&_225$$42, 1, 0);
		ZEPHIR_INIT_VAR(&_227$$42);
		ZVAL_STRING(&_227$$42, "null");
		ZEPHIR_CALL_METHOD(&_226$$42, this_ptr, "getstyle", &_7, 0, &_227$$42);
		zephir_check_call_status();
		zephir_array_update_string(&_225$$42, SL(":style"), &_226$$42, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_226$$42, "strtr", &_8, 113, &_223$$42, &_225$$42);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_226$$42);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_228);
	zephir_read_property_cached(&_229, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_229)) {
		ZEPHIR_INIT_NVAR(&_228);
		ZVAL_STRING(&_228, "(:var)");
	} else {
		ZEPHIR_INIT_NVAR(&_228);
		ZVAL_STRING(&_228, "(<span style=':style'>:var</span>)");
	}
	ZEPHIR_INIT_VAR(&_230);
	zephir_create_array(&_230, 2, 0);
	ZEPHIR_INIT_VAR(&_232);
	ZVAL_STRING(&_232, "other");
	ZEPHIR_CALL_METHOD(&_231, this_ptr, "getstyle", &_7, 0, &_232);
	zephir_check_call_status();
	zephir_array_update_string(&_230, SL(":style"), &_231, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_230, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_231, "strtr", &_8, 113, &_228, &_230);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_231);
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
	zend_string *name = NULL;
	zval *variable, variable_sub, name_zv, _0, _1, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("plain", 5, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(variable)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	variable = ZEND_CALL_ARG(execute_data, 1);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
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
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "output", NULL, 0, variable, &name_zv);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL(":output"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 113, &_0, &_2);
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
	zend_bool _10;
	zend_string *_5;
	zend_ulong _4;
	zval key, value, output, _0, *_1, _2, *_3, _9, _6$$3, _7$$3, _11$$4, _12$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "ice/dump.zep", 324);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZEPHIR_CONCAT_SV(&_7$$3, "var ", &key);
			ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "one", &_8, 0, &value, &_7$$3);
			zephir_check_call_status();
			zephir_concat_self(&output, &_6$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZEPHIR_CONCAT_SV(&_12$$4, "var ", &key);
				ZEPHIR_CALL_METHOD(&_11$$4, this_ptr, "one", &_8, 0, &value, &_12$$4);
				zephir_check_call_status();
				zephir_concat_self(&output, &_11$$4);
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
	zval _5;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_12 = NULL, *_18 = NULL, *_19 = NULL, *_22 = NULL;
	zend_long line, padding, ZEPHIR_LAST_CALL_STATUS, i;
	zval filename_zv, *line_param = NULL, *padding_param = NULL, file, range, format, lines, row, _1, _2, _3, _4, _7$$4, _8$$4, _9$$7, _10$$7, _11$$7, _13$$8, _14$$8, _16$$8, _17$$8, _20$$8, _21$$8, _23$$9, _24$$9, _26$$9, _27$$9, _28$$9, _29$$9;
	zend_string *filename = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename_zv);
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_25$$9);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("plain", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(filename)
		Z_PARAM_LONG(line)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(padding)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	line_param = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		padding_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!padding_param) {
		padding = 5;
	} else {
		}
	i = 0;
	_0 = ZEPHIR_IS_EMPTY(&filename_zv);
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_readable", NULL, 123, &filename_zv);
		zephir_check_call_status();
		_0 = !zephir_is_true(&_1);
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "r");
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 124, &filename_zv, &_2);
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
	ZEPHIR_CALL_FUNCTION(&row, "fgets", &_6, 125, &file);
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
			ZEPHIR_CALL_FUNCTION(&_11$$7, "htmlspecialchars", &_12, 126, &row, &_9$$7, &_10$$7);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&row, &_11$$7);
			if (i == line) {
				ZEPHIR_INIT_NVAR(&_13$$8);
				zephir_read_property_cached(&_14$$8, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
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
				ZEPHIR_CALL_FUNCTION(&_16$$8, "strtr", &_19, 113, &_13$$8, &_15$$8);
				zephir_check_call_status();
				ZVAL_LONG(&_20$$8, i);
				ZEPHIR_CALL_FUNCTION(&_21$$8, "sprintf", &_22, 12, &format, &_20$$8);
				zephir_check_call_status();
				zephir_array_update_zval(&lines, &_21$$8, &_16$$8, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_23$$9);
				zephir_read_property_cached(&_24$$9, this_ptr, _zephir_prop_0, 154, PH_NOISY_CC | PH_READONLY);
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
				ZEPHIR_CALL_FUNCTION(&_26$$9, "strtr", &_19, 113, &_23$$9, &_25$$9);
				zephir_check_call_status();
				ZVAL_LONG(&_28$$9, i);
				ZEPHIR_CALL_FUNCTION(&_29$$9, "sprintf", &_22, 12, &format, &_28$$9);
				zephir_check_call_status();
				zephir_array_update_zval(&lines, &_29$$9, &_26$$9, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_CALL_FUNCTION(&row, "fgets", &_6, 125, &file);
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
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
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

