
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
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/iterator.h"


/**
 * Allows to validate array data.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 * @uses        Ice\Filter (if service is available)
 * @uses        Ice\I18n (if service is available)
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *
 *  $validation->rules([
 *      'fullName' => 'required',
 *      'email' => 'required|email',
 *      'repeatEmail' => 'same:email',
 *      'about' => 'required|length:10,5000',
 *  ]);
 *
 *  $valid = $validation->validate($_POST);
 *
 *  if (!$valid) {
 *      $messages = $validation->getMessages();
 *  }
 * </code></pre>
 */
ZEPHIR_INIT_CLASS(Ice_Validation)
{
	ZEPHIR_REGISTER_CLASS(Ice, Validation, ice, validation, ice_validation_method_entry, 0);

	zend_declare_property_null(ice_validation_ce, SL("di"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_validation_ce, SL("data"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_validation_ce, SL("rules"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_validation_ce, SL("validators"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_validation_ce, SL("filters"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_validation_ce, SL("labels"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_validation_ce, SL("messages"), ZEND_ACC_PROTECTED);
	zend_declare_property_bool(ice_validation_ce, SL("valid"), 1, ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_validation_ce, SL("aliases"), ZEND_ACC_PROTECTED);
	zend_declare_property_bool(ice_validation_ce, SL("translate"), 1, ZEND_ACC_PROTECTED);
	zend_declare_property_bool(ice_validation_ce, SL("humanLabels"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_validation_ce, SL("defaultMessages"), ZEND_ACC_PROTECTED);
	ice_validation_ce->create_object = zephir_init_properties_Ice_Validation;

	return SUCCESS;
}

PHP_METHOD(Ice_Validation, getDi)
{

	RETURN_MEMBER(getThis(), "di");
}

PHP_METHOD(Ice_Validation, getData)
{

	RETURN_MEMBER(getThis(), "data");
}

PHP_METHOD(Ice_Validation, setRules)
{
	zval *rules, rules_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rules_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rules", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(rules)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &rules);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 270, rules);
	RETURN_THISW();
}

PHP_METHOD(Ice_Validation, getRules)
{

	RETURN_MEMBER(getThis(), "rules");
}

PHP_METHOD(Ice_Validation, setFilters)
{
	zval *filters, filters_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("filters", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(filters)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &filters);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 271, filters);
	RETURN_THISW();
}

PHP_METHOD(Ice_Validation, setLabels)
{
	zval *labels, labels_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&labels_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("labels", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(labels)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &labels);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 272, labels);
	RETURN_THISW();
}

PHP_METHOD(Ice_Validation, setAliases)
{
	zval *aliases, aliases_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&aliases_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(aliases)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &aliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 273, aliases);
	RETURN_THISW();
}

PHP_METHOD(Ice_Validation, setTranslate)
{
	zval *translate, translate_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translate_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("translate", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(translate)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &translate);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 274, translate);
	RETURN_THISW();
}

PHP_METHOD(Ice_Validation, getTranslate)
{

	RETURN_MEMBER(getThis(), "translate");
}

PHP_METHOD(Ice_Validation, setHumanLabels)
{
	zval *humanLabels, humanLabels_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&humanLabels_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("humanLabels", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(humanLabels)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &humanLabels);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 275, humanLabels);
	RETURN_THISW();
}

/**
 * Validation constructor. Fetch Di and set the data if given.
 *
 * @param array data Data to validate
 */
PHP_METHOD(Ice_Validation, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, _0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("di", 2, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("data", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &data_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 276, &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 4, &data);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 277, &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolve one rule.
 *
 * @param string alias
 * @param string field
 * @param array options
 * @return object Validation
 */
PHP_METHOD(Ice_Validation, resolve)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _6;
	zval alias_zv, field_zv, *options_param = NULL, rule, _0, _5, _1$$3, _2$$4, _3$$4, _4$$4;
	zend_string *alias = NULL, *field = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_zv);
	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&rule);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_6);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("aliases", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(alias)
		Z_PARAM_STR(field)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		options_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&alias_zv);
	ZVAL_STR_COPY(&alias_zv, alias);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_memory_observe(&rule);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 273, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&rule, &_0, &alias_zv, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_camelize(&_1$$3, &alias_zv, NULL );
		ZEPHIR_INIT_NVAR(&rule);
		ZEPHIR_CONCAT_SV(&rule, "Ice\\Validation\\Validator\\", &_1$$3);
		if (!(zephir_class_exists(&rule, 1))) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, ice_exception_ce);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "Validator %s not found");
			ZEPHIR_CALL_FUNCTION(&_4$$4, "sprintf", NULL, 12, &_3$$4, &alias_zv);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 13, &_4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "ice/validation.zep", 101);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	zephir_array_fast_append(&_6, &options);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_5, &rule, &_6);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("rules"), &_5, SL("za"), 2, &field_zv);
	RETURN_THIS();
}

/**
 * Add one rule.
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *
 *  $validation->rule('email', 'required|email');
 *  $validation->rule('content', [
 *      'length' => [
 *          'max' => 1000,
 *          'messageMin' => 'Too long!',
 *          'label' => 'Desctiption'
 *      ]
 *  ]);
 * </code></pre>
 *
 * @param string field
 * @param mixed validators
 * @param mixed options
 * @return object Validation
 */
PHP_METHOD(Ice_Validation, rule)
{
	zend_bool _8$$4, _11$$9;
	zend_ulong _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_14 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field_zv, *validators, validators_sub, *options = NULL, options_sub, __$null, validator, rules, rule, alias, values, _0, *_1$$4, _2$$4, *_3$$4, _7$$4, _9$$9, _10$$9, _12$$9, _13$$9, *_15$$12, _16$$12, *_17$$12;
	zend_string *field = NULL, *_5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&validators_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&rules);
	ZVAL_UNDEF(&rule);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_16$$12);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(field)
		Z_PARAM_ZVAL(validators)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	validators = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		options = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	if (!options) {
		options = &options_sub;
		ZEPHIR_CPY_WRT(options, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_gettype(&_0, validators);
	if (ZEPHIR_IS_STRING(&_0, "object")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&_0, "array")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&_0, "string")) { goto zephir_switch_0_clause_2; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
		zephir_update_property_array_multi(this_ptr, SL("rules"), validators, SL("za"), 2, &field_zv);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		if (Z_TYPE_P(validators) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_string_to_char_array(&_2$$4, validators);
			_1$$4 = &_2$$4;
		} else {
			_1$$4 = validators;
		}
		zephir_is_iterable(_1$$4, 0, "ice/validation.zep", 147);
		if (Z_TYPE_P(_1$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1$$4), _4$$4, _5$$4, _3$$4)
			{
				ZEPHIR_INIT_NVAR(&validator);
				if (_5$$4 != NULL) { 
					ZVAL_STR_COPY(&validator, _5$$4);
				} else {
					ZVAL_LONG(&validator, _4$$4);
				}
				ZEPHIR_INIT_NVAR(options);
				ZVAL_COPY(options, _3$$4);
				if (Z_TYPE_P(&validator) == IS_LONG) {
					ZEPHIR_CPY_WRT(&validator, options);
					ZEPHIR_INIT_NVAR(options);
					array_init(options);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rule", &_6, 217, &field_zv, &validator, options);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_8$$4 = 1;
			while (1) {
				if (_8$$4) {
					_8$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _1$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_7$$4, _1$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&validator, _1$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(options, _1$$4, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&validator) == IS_LONG) {
						ZEPHIR_CPY_WRT(&validator, options);
						ZEPHIR_INIT_NVAR(options);
						array_init(options);
					}
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "rule", &_6, 217, &field_zv, &validator, options);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(options);
		ZEPHIR_INIT_NVAR(&validator);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
		ZEPHIR_INIT_VAR(&_9$$9);
		ZVAL_STRING(&_9$$9, "|");
		ZEPHIR_INIT_VAR(&_10$$9);
		zephir_fast_strpos(&_10$$9, validators, &_9$$9, 0 );
		_11$$9 = ZEPHIR_IS_FALSE_IDENTICAL(&_10$$9);
		if (_11$$9) {
			ZEPHIR_INIT_VAR(&_12$$9);
			ZVAL_STRING(&_12$$9, ":");
			ZEPHIR_INIT_VAR(&_13$$9);
			zephir_fast_strpos(&_13$$9, validators, &_12$$9, 0 );
			_11$$9 = ZEPHIR_IS_FALSE_IDENTICAL(&_13$$9);
		}
		if (_11$$9) {
			if (Z_TYPE_P(options) == IS_NULL) {
				ZEPHIR_INIT_NVAR(options);
				array_init(options);
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolve", &_14, 0, validators, &field_zv, options);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&rules);
			zephir_fast_explode_str(&rules, SL("|"), validators, ZEND_LONG_MAX);
			if (Z_TYPE_P(&rules) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_16$$12);
				zephir_string_to_char_array(&_16$$12, &rules);
				_15$$12 = &_16$$12;
			} else {
				_15$$12 = &rules;
			}
			zephir_is_iterable(_15$$12, 0, "ice/validation.zep", 170);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_15$$12), _17$$12)
			{
				ZEPHIR_INIT_NVAR(&rule);
				ZVAL_COPY(&rule, _17$$12);
				ZEPHIR_INIT_NVAR(options);
				zephir_fast_explode_str(options, SL(":"), &rule, ZEND_LONG_MAX);
				ZEPHIR_MAKE_REF(options);
				ZEPHIR_CALL_FUNCTION(&alias, "array_shift", &_18, 2, options);
				ZEPHIR_UNREF(options);
				zephir_check_call_status();
				if (!ZEPHIR_IS_STRING(&alias, "regex")) {
					ZEPHIR_OBS_NVAR(&values);
					if (zephir_array_isset_long_fetch(&values, options, 0, 0)) {
						ZEPHIR_INIT_NVAR(options);
						zephir_fast_explode_str(options, SL(","), &values, ZEND_LONG_MAX);
					}
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolve", &_14, 0, &alias, &field_zv, options);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&rule);
		}
		goto zephir_switch_0_end;
	zephir_switch_0_end: ;

	RETURN_THIS();
}

/**
 * Add multiple rules at once.
 *
 * <pre><code>
 *  $validation = new Ice\Validation();
 *
 *  $validation->rules([
 *      'username' => 'required|length:4,24|notIn:admin,user,root|unique:users',
 *      'password'  => 'required|length:5,32',
 *      'repeatPassword'  => 'same:password',
 *      'email'  => 'email',
 *      'status'  => 'required|digit|in:0,1,2',
 *      'website'  => 'url',
 *      'title'  => 'length:,100',
 *      'age'  => 'required|between:18,21',
 *  ]);
 * </code></pre>
 *
 * @param array validators
 * @param boolean merge
 * @return object Validation
 */
PHP_METHOD(Ice_Validation, rules)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool merge, _6;
	zval *validators_param = NULL, *merge_param = NULL, field, rules, *_1, _5, _0$$3;
	zval validators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&rules);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("rules", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(validators, validators_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &validators_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&validators, validators_param);
	if (!merge_param) {
		merge = 1;
	} else {
		}
	if (!(merge)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 270, &_0$$3);
	}
	zephir_is_iterable(&validators, 0, "ice/validation.zep", 210);
	if (Z_TYPE_P(&validators) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&validators), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&field, _3);
			} else {
				ZVAL_LONG(&field, _2);
			}
			ZEPHIR_INIT_NVAR(&rules);
			ZVAL_COPY(&rules, _1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rule", &_4, 0, &field, &rules);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &validators, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &validators, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&rules, &validators, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rule", &_4, 217, &field, &rules);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&rules);
	ZEPHIR_INIT_NVAR(&field);
	RETURN_THIS();
}

/**
 * Validate the data.
 *
 * @param array data Data to validate
 * @param boolean clear Clear messages before
 * @return boolean
 */
PHP_METHOD(Ice_Validation, validate)
{
	zend_string *_6;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool clear, _15, _12$$5, _21$$10;
	zval *data_param = NULL, *clear_param = NULL, __$true, __$false, tmp, field, rules, rule, _1, *_2, _3, *_4, _14, _23, _0$$4, *_7$$5, _8$$5, *_9$$5, _11$$5, _10$$6, _13$$8, *_16$$10, _17$$10, *_18$$10, _20$$10, _19$$11, _22$$13;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&rules);
	ZVAL_UNDEF(&rule);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_22$$13);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("valid", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("messages", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("rules", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_BOOL(clear)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &data_param, &clear_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	if (!clear_param) {
		clear = 1;
	} else {
		}
	if (zephir_fast_count_int(&data)) {
		zephir_memory_observe(&tmp);
		zephir_read_property_cached(&tmp, this_ptr, _zephir_prop_0, 277, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, &tmp, "setdata", NULL, 0, &data);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 277, &tmp);
	}
	if (clear) {
		if (1) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$false);
		}
		ZEPHIR_INIT_VAR(&_0$$4);
		array_init(&_0$$4);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 279, &_0$$4);
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_3, 270, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_1) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &_1);
		_2 = &_3;
	} else {
		_2 = &_1;
	}
	zephir_is_iterable(_2, 0, "ice/validation.zep", 247);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_2), _5, _6, _4)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&field, _6);
			} else {
				ZVAL_LONG(&field, _5);
			}
			ZEPHIR_INIT_NVAR(&rules);
			ZVAL_COPY(&rules, _4);
			if (Z_TYPE_P(&rules) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_8$$5);
				zephir_string_to_char_array(&_8$$5, &rules);
				_7$$5 = &_8$$5;
			} else {
				_7$$5 = &rules;
			}
			zephir_is_iterable(_7$$5, 0, "ice/validation.zep", 244);
			if (Z_TYPE_P(_7$$5) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_7$$5), _9$$5)
				{
					ZEPHIR_INIT_NVAR(&rule);
					ZVAL_COPY(&rule, _9$$5);
					ZEPHIR_CALL_METHOD(&_10$$6, &rule, "validate", NULL, 0, this_ptr, &field);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_10$$6)) {
						if (0) {
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$true);
						} else {
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$false);
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _7$$5, "rewind", NULL, 0);
				zephir_check_call_status();
				_12$$5 = 1;
				while (1) {
					if (_12$$5) {
						_12$$5 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _7$$5, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_11$$5, _7$$5, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_11$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&rule, _7$$5, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_13$$8, &rule, "validate", NULL, 0, this_ptr, &field);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_13$$8)) {
							if (0) {
								zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$true);
							} else {
								zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$false);
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&rule);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _2, "rewind", NULL, 0);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_14, _2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, _2, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&rules, _2, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&rules) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_17$$10);
					zephir_string_to_char_array(&_17$$10, &rules);
					_16$$10 = &_17$$10;
				} else {
					_16$$10 = &rules;
				}
				zephir_is_iterable(_16$$10, 0, "ice/validation.zep", 244);
				if (Z_TYPE_P(_16$$10) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_16$$10), _18$$10)
					{
						ZEPHIR_INIT_NVAR(&rule);
						ZVAL_COPY(&rule, _18$$10);
						ZEPHIR_CALL_METHOD(&_19$$11, &rule, "validate", NULL, 0, this_ptr, &field);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_19$$11)) {
							if (0) {
								zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$true);
							} else {
								zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$false);
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _16$$10, "rewind", NULL, 0);
					zephir_check_call_status();
					_21$$10 = 1;
					while (1) {
						if (_21$$10) {
							_21$$10 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _16$$10, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_20$$10, _16$$10, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_20$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&rule, _16$$10, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_22$$13, &rule, "validate", NULL, 0, this_ptr, &field);
							zephir_check_call_status();
							if (ZEPHIR_IS_FALSE_IDENTICAL(&_22$$13)) {
								if (0) {
									zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$true);
								} else {
									zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$false);
								}
							}
					}
				}
				ZEPHIR_INIT_NVAR(&rule);
		}
	}
	ZEPHIR_INIT_NVAR(&rules);
	ZEPHIR_INIT_NVAR(&field);
	zephir_read_property_cached(&_23, this_ptr, _zephir_prop_2, 279, PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_23)) {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 278, &__$false);
		}
	}
	RETURN_MM_MEMBER(getThis(), "valid");
}

/**
 * Check if validation passed.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Validation, valid)
{

	RETURN_MEMBER(getThis(), "valid");
}

/**
 * Whether or not a value exists by field.
 *
 * @param string field The data key
 * @return boolean
 */
PHP_METHOD(Ice_Validation, hasValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field_zv, _0;
	zend_string *field = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 277, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, &field_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get a value by field.
 *
 * @param string field The data key
 * @param boolean filtered Get the filtered value or original
 * @return mixed
 */
PHP_METHOD(Ice_Validation, getValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filtered;
	zval field_zv, *filtered_param = NULL, filters, _1, _0$$3;
	zend_string *field = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("filters", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("data", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(field)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filtered)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filtered_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	if (!filtered_param) {
		filtered = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&filters);
	ZVAL_NULL(&filters);
	if (filtered) {
		ZEPHIR_OBS_NVAR(&filters);
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 271, PH_NOISY_CC | PH_READONLY);
		zephir_array_isset_fetch(&filters, &_0$$3, &field_zv, 0);
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 277, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getvalue", NULL, 0, &field_zv, &filters);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get the values by fields.
 * Values are automatically filtered out if filters have been setted.
 *
 * <pre><code>
 *  // Get value for one field
 *  $validation->getValues('password');
 *
 *  // Get values for multiple fields
 *  $validation->getValues(['fullName', 'about']);
 *
 *  // Get all values
 *  $validation->getValues();
 * </code></pre>
 *
 * @param mixed fields The data keys
 * @param boolean filtered Get the filtered value or original
 * @return mixed
 */
PHP_METHOD(Ice_Validation, getValues)
{
	zend_object_iterator *_0$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filtered, _14$$6;
	zval *fields = NULL, fields_sub, *filtered_param = NULL, __$null, data, field, _1$$3, _2$$3, _3$$4, _4$$4, _6$$5, *_7$$6, _8$$6, *_9$$6, _13$$6, _10$$7, _11$$8, _12$$8, _15$$9, _16$$10, _17$$10, _18$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$11);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(fields)
		Z_PARAM_BOOL(filtered)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &fields, &filtered_param);
	if (!fields) {
		fields = &fields_sub;
		fields = &__$null;
	}
	if (!filtered_param) {
		filtered = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	if (Z_TYPE_P(fields) == IS_NULL) {
		zephir_memory_observe(&_1$$3);
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 277, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		_0$$3 = zephir_get_iterator(&_1$$3);
		if (EXPECTED(_0$$3 != NULL)) {
			_0$$3->funcs->rewind(_0$$3);
			for (;_0$$3->funcs->valid(_0$$3) == SUCCESS && !EG(exception); _0$$3->funcs->move_forward(_0$$3)) {
			ZEPHIR_GET_IMKEY(field, _0$$3);
			{
				ZEPHIR_ITERATOR_COPY(&_2$$3, _0$$3);
			}
			if (filtered) {
				ZVAL_BOOL(&_4$$4, 1);
			} else {
				ZVAL_BOOL(&_4$$4, 0);
			}
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getvalue", &_5, 0, &field, &_4$$4);
			zephir_check_call_status();
			zephir_array_update_zval(&data, &field, &_3$$4, PH_COPY | PH_SEPARATE);
		}
		zend_iterator_dtor(_0$$3);
		}
	} else {
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_gettype(&_6$$5, fields);
		if (ZEPHIR_IS_STRING(&_6$$5, "array")) { goto zephir_switch_0_clause_0; }
		if (ZEPHIR_IS_STRING(&_6$$5, "string")) { goto zephir_switch_0_clause_1; }
		goto zephir_switch_0_end;
		zephir_switch_0_clause_0: ;
			if (Z_TYPE_P(fields) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_8$$6);
				zephir_string_to_char_array(&_8$$6, fields);
				_7$$6 = &_8$$6;
			} else {
				_7$$6 = fields;
			}
			zephir_is_iterable(_7$$6, 0, "ice/validation.zep", 330);
			if (Z_TYPE_P(_7$$6) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_7$$6), _9$$6)
				{
					ZEPHIR_INIT_NVAR(&field);
					ZVAL_COPY(&field, _9$$6);
					zephir_read_property_cached(&_10$$7, this_ptr, _zephir_prop_0, 277, PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset_value(&_10$$7, &field)) {
						if (filtered) {
							ZVAL_BOOL(&_12$$8, 1);
						} else {
							ZVAL_BOOL(&_12$$8, 0);
						}
						ZEPHIR_CALL_METHOD(&_11$$8, this_ptr, "getvalue", &_5, 0, &field, &_12$$8);
						zephir_check_call_status();
						zephir_array_update_zval(&data, &field, &_11$$8, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _7$$6, "rewind", NULL, 0);
				zephir_check_call_status();
				_14$$6 = 1;
				while (1) {
					if (_14$$6) {
						_14$$6 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _7$$6, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_13$$6, _7$$6, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&field, _7$$6, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property_cached(&_15$$9, this_ptr, _zephir_prop_0, 277, PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset_value(&_15$$9, &field)) {
							if (filtered) {
								ZVAL_BOOL(&_17$$10, 1);
							} else {
								ZVAL_BOOL(&_17$$10, 0);
							}
							ZEPHIR_CALL_METHOD(&_16$$10, this_ptr, "getvalue", &_5, 0, &field, &_17$$10);
							zephir_check_call_status();
							zephir_array_update_zval(&data, &field, &_16$$10, PH_COPY | PH_SEPARATE);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&field);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_1: ;
			if (filtered) {
				ZVAL_BOOL(&_18$$11, 1);
			} else {
				ZVAL_BOOL(&_18$$11, 0);
			}
			ZEPHIR_CALL_METHOD(&data, this_ptr, "getvalue", &_5, 0, fields, &_18$$11);
			zephir_check_call_status();
			goto zephir_switch_0_end;
		zephir_switch_0_end: ;

	}
	RETURN_CCTOR(&data);
}

/**
 * Get the label of a field.
 * Humanize a label if humanLabels attribute and filter service is available
 *
 * @param string field The data key
 * @return string
 */
PHP_METHOD(Ice_Validation, getLabel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field_zv, label, _0, _1$$3, _2$$4, _3$$4, _4$$4;
	zend_string *field = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("labels", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("humanLabels", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("di", 2, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	zephir_memory_observe(&label);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 272, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&label, &_0, &field_zv, 0))) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 275, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_1$$3)) {
			zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_2, 276, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "filter");
			ZEPHIR_CALL_METHOD(&_3$$4, &_2$$4, "get", NULL, 0, &_4$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "human");
			ZEPHIR_CALL_METHOD(&label, &_3$$4, "sanitize", NULL, 0, &field_zv, &_4$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&label, &field_zv);
		}
	}
	RETURN_CCTOR(&label);
}

/**
 * Set the default messages.
 *
 * @param array messages
 * @return object Validation
 */
PHP_METHOD(Ice_Validation, setDefaultMessages)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *messages_param = NULL, _0, _1;
	zval messages;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultMessages", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(messages, messages_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &messages_param);
	if (!messages_param) {
		ZEPHIR_INIT_VAR(&messages);
		array_init(&messages);
	} else {
		zephir_get_arrval(&messages, messages_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 280, PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &messages);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 280, &_0);
	RETURN_THIS();
}

/**
 * Get a default message for the type.
 *
 * @param string type Type of message
 * @return string
 */
PHP_METHOD(Ice_Validation, getDefaultMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval type_zv, message, _0, _1$$3;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultMessages", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_memory_observe(&message);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 280, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&message, &_0, &type_zv, 0))) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 280, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&message);
		zephir_array_fetch_string(&message, &_1$$3, SL("default"), PH_NOISY, "ice/validation.zep", 387);
	}
	RETURN_CCTOR(&message);
}

/**
 * Add a message to the field.
 *
 * @param string field
 * @param string message
 * @return object Validation
 */
PHP_METHOD(Ice_Validation, addMessage)
{
	zval field_zv, message_zv;
	zend_string *field = NULL, *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&message_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(field)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&field_zv, field);
	ZVAL_STR(&message_zv, message);
	zephir_update_property_array_multi(this_ptr, SL("messages"), &message_zv, SL("za"), 2, &field_zv);
	RETURN_THISW();
}

/**
 * Get the validation's messages.
 *
 * @return object Arr
 */
PHP_METHOD(Ice_Validation, getMessages)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, ice_arr_ce);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 279, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 4, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Ice_Validation(zend_class_entry *class_type)
{
		zval _1$$3;
	zval _0, _2, _4, _6, _8, _10, _12, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("defaultMessages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 24, 0);
			add_assoc_stringl_ex(&_1$$3, SL("alnum"), SL("Field :field must contain only letters and numbers"));
			add_assoc_stringl_ex(&_1$$3, SL("alpha"), SL("Field :field must contain only letters"));
			add_assoc_stringl_ex(&_1$$3, SL("between"), SL("Field :field must be within the range of :min to :max"));
			add_assoc_stringl_ex(&_1$$3, SL("digit"), SL("Field :field must be numeric"));
			add_assoc_stringl_ex(&_1$$3, SL("default"), SL("Field :field is not valid"));
			add_assoc_stringl_ex(&_1$$3, SL("email"), SL("Field :field must be an email address"));
			add_assoc_stringl_ex(&_1$$3, SL("exists"), SL("Field :field must exist"));
			add_assoc_stringl_ex(&_1$$3, SL("fileEmpty"), SL("Field :field must not be empty"));
			add_assoc_stringl_ex(&_1$$3, SL("fileIniSize"), SL("File :field exceeds the maximum file size"));
			add_assoc_stringl_ex(&_1$$3, SL("fileMaxResolution"), SL("File :field must not exceed :max resolution"));
			add_assoc_stringl_ex(&_1$$3, SL("fileMinResolution"), SL("File :field must be at least :min resolution"));
			add_assoc_stringl_ex(&_1$$3, SL("fileSize"), SL("File :field exceeds the size of :max"));
			add_assoc_stringl_ex(&_1$$3, SL("fileType"), SL("File :field must be of type: :types"));
			add_assoc_stringl_ex(&_1$$3, SL("in"), SL("Field :field must be a part of list: :values"));
			add_assoc_stringl_ex(&_1$$3, SL("lengthMax"), SL("Field :field must not exceed :max characters long"));
			add_assoc_stringl_ex(&_1$$3, SL("lengthMin"), SL("Field :field must be at least :min characters long"));
			add_assoc_stringl_ex(&_1$$3, SL("notIn"), SL("Field :field must not be a part of list: :values"));
			add_assoc_stringl_ex(&_1$$3, SL("regex"), SL("Field :field does not match the required format"));
			add_assoc_stringl_ex(&_1$$3, SL("required"), SL("Field :field is required"));
			add_assoc_stringl_ex(&_1$$3, SL("same"), SL("Field :field and :other must match"));
			add_assoc_stringl_ex(&_1$$3, SL("unique"), SL("Field :field must be unique"));
			add_assoc_stringl_ex(&_1$$3, SL("url"), SL("Field :field must be a url"));
			add_assoc_stringl_ex(&_1$$3, SL("with"), SL("Field :field must occur together with :fields"));
			add_assoc_stringl_ex(&_1$$3, SL("without"), SL("Field :field must not occur together with :fields"));
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("defaultMessages"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("aliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("aliases"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("messages"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("labels"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("labels"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("filters"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("validators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("validators"), &_11$$8);
		}
		zephir_read_property_ex(&_12, this_ptr, ZEND_STRL("rules"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("rules"), &_13$$9);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

