
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
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Allows to validate array data.
 *
 * @package     Ice/Validation
 * @category    Security
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
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
ZEPHIR_INIT_CLASS(Ice_Validation) {

	ZEPHIR_REGISTER_CLASS(Ice, Validation, ice, validation, ice_validation_method_entry, 0);

	zend_declare_property_null(ice_validation_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("rules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("validators"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("labels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_validation_ce, SL("valid"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("aliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_validation_ce, SL("translate"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_validation_ce, SL("humanLabels"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("defaultMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_validation_ce->create_object = zephir_init_properties_Ice_Validation;
	return SUCCESS;

}

PHP_METHOD(Ice_Validation, getDi) {

	

	RETURN_MEMBER(this_ptr, "di");

}

PHP_METHOD(Ice_Validation, setRules) {

	zval *rules;

	zephir_fetch_params(0, 1, 0, &rules);



	zephir_update_property_this(this_ptr, SL("rules"), rules TSRMLS_CC);

}

PHP_METHOD(Ice_Validation, getRules) {

	

	RETURN_MEMBER(this_ptr, "rules");

}

PHP_METHOD(Ice_Validation, setFilters) {

	zval *filters;

	zephir_fetch_params(0, 1, 0, &filters);



	zephir_update_property_this(this_ptr, SL("filters"), filters TSRMLS_CC);

}

PHP_METHOD(Ice_Validation, setLabels) {

	zval *labels;

	zephir_fetch_params(0, 1, 0, &labels);



	zephir_update_property_this(this_ptr, SL("labels"), labels TSRMLS_CC);

}

PHP_METHOD(Ice_Validation, setAliases) {

	zval *aliases;

	zephir_fetch_params(0, 1, 0, &aliases);



	zephir_update_property_this(this_ptr, SL("aliases"), aliases TSRMLS_CC);

}

PHP_METHOD(Ice_Validation, setTranslate) {

	zval *translate;

	zephir_fetch_params(0, 1, 0, &translate);



	zephir_update_property_this(this_ptr, SL("translate"), translate TSRMLS_CC);

}

PHP_METHOD(Ice_Validation, getTranslate) {

	

	RETURN_MEMBER(this_ptr, "translate");

}

PHP_METHOD(Ice_Validation, setHumanLabels) {

	zval *humanLabels;

	zephir_fetch_params(0, 1, 0, &humanLabels);



	zephir_update_property_this(this_ptr, SL("humanLabels"), humanLabels TSRMLS_CC);

}

/**
 * Validation constructor. Fetch Di and set the data if given.
 *
 * @param array data Data to validate
 */
PHP_METHOD(Ice_Validation, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data_param = NULL, *_0 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 8);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("data"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Resolve one rule.
 *
 * @param string alias
 * @param string field
 * @param mixed options
 * @return void
 */
PHP_METHOD(Ice_Validation, resolve) {

	zval *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *field_param = NULL, *options = NULL, *rule = NULL, *_0, *_5, *_1$$3, *_2$$4, _3$$4, *_4$$4 = NULL;
	zval *alias = NULL, *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &alias_param, &field_param, &options);

	zephir_get_strval(alias, alias_param);
	zephir_get_strval(field, field_param);
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(rule);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("aliases"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&rule, _0, alias, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_camelize(_1$$3, alias);
		ZEPHIR_INIT_NVAR(rule);
		ZEPHIR_CONCAT_SV(rule, "Ice\\Validation\\Validator\\", _1$$3);
		if (!(zephir_class_exists(rule, 1 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_2$$4);
			object_init_ex(_2$$4, ice_exception_ce);
			ZEPHIR_SINIT_VAR(_3$$4);
			ZVAL_STRING(&_3$$4, "Validator %s not found", 0);
			ZEPHIR_CALL_FUNCTION(&_4$$4, "sprintf", NULL, 1, &_3$$4, alias);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_2$$4, "ice/validation.zep", 101 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_6, options);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_5, rule, _6 TSRMLS_CC);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("rules"), &_5 TSRMLS_CC, SL("za"), 2, field);
	ZEPHIR_MM_RESTORE();

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
 * @return void
 */
PHP_METHOD(Ice_Validation, rule) {

	zend_bool _7$$7;
	HashTable *_2$$4, *_12$$9;
	HashPosition _1$$4, _11$$9;
	zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *validators, *options = NULL, *validator = NULL, *rules = NULL, *rule = NULL, *alias = NULL, *values = NULL, *_0, **_3$$4, _5$$7, *_6$$7, _8$$7, *_9$$7, **_13$$9;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &field_param, &validators, &options);

	zephir_get_strval(field, field_param);
	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, validators TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(_0, "object")) {
			zephir_update_property_array_multi(this_ptr, SL("rules"), &validators TSRMLS_CC, SL("za"), 2, field);
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "array")) {
			zephir_is_iterable(validators, &_2$$4, &_1$$4, 0, 0, "ice/validation.zep", 144);
			for (
			  ; zephir_hash_get_current_data_ex(_2$$4, (void**) &_3$$4, &_1$$4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2$$4, &_1$$4)
			) {
				ZEPHIR_GET_HMKEY(validator, _2$$4, _1$$4);
				ZEPHIR_GET_HVALUE(options, _3$$4);
				if (Z_TYPE_P(validator) == IS_LONG) {
					ZEPHIR_CPY_WRT(validator, options);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rule", &_4, 160, field, validator, options);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "string")) {
			ZEPHIR_SINIT_VAR(_5$$7);
			ZVAL_STRING(&_5$$7, "|", 0);
			ZEPHIR_INIT_VAR(_6$$7);
			zephir_fast_strpos(_6$$7, validators, &_5$$7, 0 );
			_7$$7 = ZEPHIR_IS_FALSE_IDENTICAL(_6$$7);
			if (_7$$7) {
				ZEPHIR_SINIT_VAR(_8$$7);
				ZVAL_STRING(&_8$$7, ":", 0);
				ZEPHIR_INIT_VAR(_9$$7);
				zephir_fast_strpos(_9$$7, validators, &_8$$7, 0 );
				_7$$7 = ZEPHIR_IS_FALSE_IDENTICAL(_9$$7);
			}
			if (_7$$7) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolve", &_10, 0, validators, field, options);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(rules);
				zephir_fast_explode_str(rules, SL("|"), validators, LONG_MAX TSRMLS_CC);
				zephir_is_iterable(rules, &_12$$9, &_11$$9, 0, 0, "ice/validation.zep", 163);
				for (
				  ; zephir_hash_get_current_data_ex(_12$$9, (void**) &_13$$9, &_11$$9) == SUCCESS
				  ; zephir_hash_move_forward_ex(_12$$9, &_11$$9)
				) {
					ZEPHIR_GET_HVALUE(rule, _13$$9);
					ZEPHIR_INIT_NVAR(options);
					zephir_fast_explode_str(options, SL(":"), rule, LONG_MAX TSRMLS_CC);
					ZEPHIR_MAKE_REF(options);
					ZEPHIR_CALL_FUNCTION(&alias, "array_shift", &_14, 4, options);
					ZEPHIR_UNREF(options);
					zephir_check_call_status();
					if (!ZEPHIR_IS_STRING(alias, "regex")) {
						ZEPHIR_OBS_NVAR(values);
						if (zephir_array_isset_long_fetch(&values, options, 0, 0 TSRMLS_CC)) {
							ZEPHIR_INIT_NVAR(options);
							zephir_fast_explode_str(options, SL(","), values, LONG_MAX TSRMLS_CC);
						}
					}
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolve", &_10, 0, alias, field, options);
					zephir_check_call_status();
				}
			}
			break;
		}
	} while(0);

	ZEPHIR_MM_RESTORE();

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
 * @return void
 */
PHP_METHOD(Ice_Validation, rules) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *validators_param = NULL, *field = NULL, *rules = NULL, **_2;
	zval *validators = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validators_param);

	validators = validators_param;


	zephir_is_iterable(validators, &_1, &_0, 0, 0, "ice/validation.zep", 196);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(field, _1, _0);
		ZEPHIR_GET_HVALUE(rules, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rule", &_3, 0, field, rules);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Validate the data.
 *
 * @param array data Data to validate
 * @return boolean
 */
PHP_METHOD(Ice_Validation, validate) {

	HashTable *_2, *_5$$4;
	HashPosition _1, _4$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *field = NULL, *rules = NULL, *rule = NULL, *_0, **_3, *_8, **_6$$4, *_7$$5 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	if (zephir_fast_count_int(data TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("data"), data TSRMLS_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/validation.zep", 222);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(field, _2, _1);
		ZEPHIR_GET_HVALUE(rules, _3);
		zephir_is_iterable(rules, &_5$$4, &_4$$4, 0, 0, "ice/validation.zep", 219);
		for (
		  ; zephir_hash_get_current_data_ex(_5$$4, (void**) &_6$$4, &_4$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5$$4, &_4$$4)
		) {
			ZEPHIR_GET_HVALUE(rule, _6$$4);
			ZEPHIR_CALL_METHOD(&_7$$5, rule, "validate", NULL, 0, this_ptr, field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_7$$5)) {
				if (0) {
					zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
				} else {
					zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				}
			}
		}
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
	if (zephir_fast_count_int(_8 TSRMLS_CC)) {
		if (0) {
			zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_MM_MEMBER(this_ptr, "valid");

}

/**
 * Check if validation passed.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Validation, valid) {

	

	RETURN_MEMBER(this_ptr, "valid");

}

/**
 * Whether or not a value exists by field.
 *
 * @param string field The data key
 * @return boolean
 */
PHP_METHOD(Ice_Validation, hasValue) {

	zval *field_param = NULL, *_0;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, field));

}

/**
 * Get a value by field.
 *
 * @param string field The data key
 * @param boolean filtered Get the filtered value or original
 * @return mixed
 */
PHP_METHOD(Ice_Validation, getValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool filtered, _1, _5;
	zval *field_param = NULL, *filtered_param = NULL, *value = NULL, *filters = NULL, *_0, *_2, *_3 = NULL, *_4, *_6, *_7$$3, *_8$$3 = NULL, *_9$$3, *_10$$3 = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field_param, &filtered_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}
	if (!filtered_param) {
		filtered = 1;
	} else {
		filtered = zephir_get_boolval(filtered_param);
	}


	ZEPHIR_OBS_VAR(value);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_array_isset_fetch(&value, _0, field, 0 TSRMLS_CC);
	_1 = filtered;
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "filter", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, _2, "has", NULL, 0, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		_1 = zephir_is_true(_3);
	}
	_5 = _1;
	if (_5) {
		ZEPHIR_OBS_VAR(filters);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
		_5 = zephir_array_isset_fetch(&filters, _6, field, 0 TSRMLS_CC);
	}
	if (_5) {
		_7$$3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_STRING(_9$$3, "filter", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8$$3, _7$$3, "get", NULL, 0, _9$$3);
		zephir_check_temp_parameter(_9$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_10$$3, _8$$3, "sanitize", NULL, 0, value, filters);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _10$$3);
	}
	RETURN_CCTOR(value);

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
PHP_METHOD(Ice_Validation, getValues) {

	HashTable *_3$$3, *_10$$6;
	HashPosition _2$$3, _9$$6;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool filtered;
	zval *fields = NULL, *filtered_param = NULL, *data = NULL, *field = NULL, *_0$$3, *_1$$3 = NULL, **_4$$3, *_5$$4 = NULL, *_6$$4 = NULL, *_8$$5, **_11$$6, *_12$$7, *_13$$8 = NULL, *_14$$8 = NULL, *_15$$9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &filtered_param);

	if (!fields) {
		fields = ZEPHIR_GLOBAL(global_null);
	}
	if (!filtered_param) {
		filtered = 1;
	} else {
		filtered = zephir_get_boolval(filtered_param);
	}


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	if (Z_TYPE_P(fields) == IS_NULL) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_is_iterable(_0$$3, &_3$$3, &_2$$3, 0, 0, "ice/validation.zep", 300);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(field, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(_1$$3, _4$$3);
			ZEPHIR_INIT_NVAR(_6$$4);
			if (filtered) {
				ZVAL_BOOL(_6$$4, 1);
			} else {
				ZVAL_BOOL(_6$$4, 0);
			}
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getvalue", &_7, 0, field, _6$$4);
			zephir_check_call_status();
			zephir_array_update_zval(&data, field, &_5$$4, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_INIT_VAR(_8$$5);
		zephir_gettype(_8$$5, fields TSRMLS_CC);
		do {
			if (ZEPHIR_IS_STRING(_8$$5, "array")) {
				zephir_is_iterable(fields, &_10$$6, &_9$$6, 0, 0, "ice/validation.zep", 308);
				for (
				  ; zephir_hash_get_current_data_ex(_10$$6, (void**) &_11$$6, &_9$$6) == SUCCESS
				  ; zephir_hash_move_forward_ex(_10$$6, &_9$$6)
				) {
					ZEPHIR_GET_HVALUE(field, _11$$6);
					_12$$7 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
					if (zephir_array_isset(_12$$7, field)) {
						ZEPHIR_INIT_NVAR(_14$$8);
						if (filtered) {
							ZVAL_BOOL(_14$$8, 1);
						} else {
							ZVAL_BOOL(_14$$8, 0);
						}
						ZEPHIR_CALL_METHOD(&_13$$8, this_ptr, "getvalue", &_7, 0, field, _14$$8);
						zephir_check_call_status();
						zephir_array_update_zval(&data, field, &_13$$8, PH_COPY | PH_SEPARATE);
					}
				}
				break;
			}
			if (ZEPHIR_IS_STRING(_8$$5, "string")) {
				ZEPHIR_INIT_VAR(_15$$9);
				if (filtered) {
					ZVAL_BOOL(_15$$9, 1);
				} else {
					ZVAL_BOOL(_15$$9, 0);
				}
				ZEPHIR_CALL_METHOD(&data, this_ptr, "getvalue", &_7, 0, fields, _15$$9);
				zephir_check_call_status();
				break;
			}
		} while(0);

	}
	RETURN_CCTOR(data);

}

/**
 * Get the label of a field.
 * Humanize a label if humanLabels attribute and filter service is available
 *
 * @param string field The data key
 * @return string
 */
PHP_METHOD(Ice_Validation, getLabel) {

	zend_bool _2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *label = NULL, *_0, *_1$$3, *_3$$3, *_4$$3 = NULL, *_5$$3, *_6$$4, *_7$$4 = NULL, *_8$$4 = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_OBS_VAR(label);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("labels"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&label, _0, field, 0 TSRMLS_CC))) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("humanLabels"), PH_NOISY_CC);
		_2$$3 = zephir_is_true(_1$$3);
		if (_2$$3) {
			_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_5$$3);
			ZVAL_STRING(_5$$3, "filter", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_4$$3, _3$$3, "has", NULL, 0, _5$$3);
			zephir_check_temp_parameter(_5$$3);
			zephir_check_call_status();
			_2$$3 = zephir_is_true(_4$$3);
		}
		if (_2$$3) {
			_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_8$$4);
			ZVAL_STRING(_8$$4, "filter", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7$$4, _6$$4, "get", NULL, 0, _8$$4);
			zephir_check_temp_parameter(_8$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_8$$4);
			ZVAL_STRING(_8$$4, "human", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, _7$$4, "sanitize", NULL, 0, field, _8$$4);
			zephir_check_temp_parameter(_8$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(label, field);
		}
	}
	RETURN_CCTOR(label);

}

/**
 * Set the default messages.
 *
 * @param array messages
 * @return void
 */
PHP_METHOD(Ice_Validation, setDefaultMessages) {

	zval *messages_param = NULL, *_0, *_1;
	zval *messages = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &messages_param);

	if (!messages_param) {
		ZEPHIR_INIT_VAR(messages);
		array_init(messages);
	} else {
		zephir_get_arrval(messages, messages_param);
	}


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("defaultMessages"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(messages) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("defaultMessages"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a default message for the type.
 *
 * @param string type Type of message
 * @return string
 */
PHP_METHOD(Ice_Validation, getDefaultMessage) {

	zval *type_param = NULL, *message = NULL, *_0, *_1$$3;
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


	ZEPHIR_OBS_VAR(message);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("defaultMessages"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&message, _0, type, 0 TSRMLS_CC))) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("defaultMessages"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(message);
		zephir_array_fetch_string(&message, _1$$3, SL("default"), PH_NOISY, "ice/validation.zep", 363 TSRMLS_CC);
	}
	RETURN_CCTOR(message);

}

/**
 * Add a message to the field.
 *
 * @param string field
 * @param string message
 * @return void
 */
PHP_METHOD(Ice_Validation, addMessage) {

	zval *field_param = NULL, *message_param = NULL;
	zval *field = NULL, *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &message_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}
	zephir_get_strval(message, message_param);


	zephir_update_property_array_multi(this_ptr, SL("messages"), &message TSRMLS_CC, SL("za"), 2, field);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the validation's messages.
 *
 * @return Arr
 */
PHP_METHOD(Ice_Validation, getMessages) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, ice_arr_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 6, _0);
	zephir_check_call_status();
	RETURN_MM();

}

static zend_object_value zephir_init_properties_Ice_Validation(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0, *_2, *_4, *_6, *_8, *_10, *_12, *_14, *_3$$4, *_5$$5, *_7$$6, *_9$$7, *_11$$8, *_13$$9, *_15$$10;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("defaultMessages"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 23, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1$$3, SS("alnum"), SL("Field :field must contain only letters and numbers"), 1);
			add_assoc_stringl_ex(_1$$3, SS("alpha"), SL("Field :field must contain only letters"), 1);
			add_assoc_stringl_ex(_1$$3, SS("between"), SL("Field :field must be within the range of :min to :max"), 1);
			add_assoc_stringl_ex(_1$$3, SS("digit"), SL("Field :field must be numeric"), 1);
			add_assoc_stringl_ex(_1$$3, SS("default"), SL("Field :field is not valid"), 1);
			add_assoc_stringl_ex(_1$$3, SS("email"), SL("Field :field must be an email address"), 1);
			add_assoc_stringl_ex(_1$$3, SS("fileEmpty"), SL("Field :field must not be empty"), 1);
			add_assoc_stringl_ex(_1$$3, SS("fileIniSize"), SL("File :field exceeds the maximum file size"), 1);
			add_assoc_stringl_ex(_1$$3, SS("fileMaxResolution"), SL("File :field must not exceed :max resolution"), 1);
			add_assoc_stringl_ex(_1$$3, SS("fileMinResolution"), SL("File :field must be at least :min resolution"), 1);
			add_assoc_stringl_ex(_1$$3, SS("fileSize"), SL("File :field exceeds the size of :max"), 1);
			add_assoc_stringl_ex(_1$$3, SS("fileType"), SL("File :field must be of type: :types"), 1);
			add_assoc_stringl_ex(_1$$3, SS("in"), SL("Field :field must be a part of list: :values"), 1);
			add_assoc_stringl_ex(_1$$3, SS("lengthMax"), SL("Field :field must not exceed :max characters long"), 1);
			add_assoc_stringl_ex(_1$$3, SS("lengthMin"), SL("Field :field must be at least :min characters long"), 1);
			add_assoc_stringl_ex(_1$$3, SS("notIn"), SL("Field :field must not be a part of list: :values"), 1);
			add_assoc_stringl_ex(_1$$3, SS("regex"), SL("Field :field does not match the required format"), 1);
			add_assoc_stringl_ex(_1$$3, SS("required"), SL("Field :field is required"), 1);
			add_assoc_stringl_ex(_1$$3, SS("same"), SL("Field :field and :other must match"), 1);
			add_assoc_stringl_ex(_1$$3, SS("unique"), SL("Field :field must be unique"), 1);
			add_assoc_stringl_ex(_1$$3, SS("url"), SL("Field :field must be a url"), 1);
			add_assoc_stringl_ex(_1$$3, SS("with"), SL("Field :field must occur together with :fields"), 1);
			add_assoc_stringl_ex(_1$$3, SS("without"), SL("Field :field must not occur together with :fields"), 1);
			zephir_update_property_this(this_ptr, SL("defaultMessages"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("aliases"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("aliases"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(this_ptr, SL("messages"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("labels"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(this_ptr, SL("labels"), _7$$6 TSRMLS_CC);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
		if (Z_TYPE_P(_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(_9$$7);
			array_init(_9$$7);
			zephir_update_property_this(this_ptr, SL("filters"), _9$$7 TSRMLS_CC);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("validators"), PH_NOISY_CC);
		if (Z_TYPE_P(_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(_11$$8);
			array_init(_11$$8);
			zephir_update_property_this(this_ptr, SL("validators"), _11$$8 TSRMLS_CC);
		}
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
		if (Z_TYPE_P(_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(_13$$9);
			array_init(_13$$9);
			zephir_update_property_this(this_ptr, SL("rules"), _13$$9 TSRMLS_CC);
		}
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (Z_TYPE_P(_14) == IS_NULL) {
			ZEPHIR_INIT_VAR(_15$$10);
			array_init(_15$$10);
			zephir_update_property_this(this_ptr, SL("data"), _15$$10 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

