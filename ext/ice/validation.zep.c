
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

ZEPHIR_INIT_CLASS(Ice_Validation) {

	ZEPHIR_REGISTER_CLASS(Ice, Validation, ice, validation, ice_validation_method_entry, 0);

	zend_declare_property_null(ice_validation_ce, SL("_di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("_rules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("_labels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_validation_ce, SL("_valid"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("_aliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_validation_ce, SL("_translate"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_validation_ce, SL("_humanLabels"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_validation_ce, SL("_defaultMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Validation, getDi) {


	RETURN_MEMBER(this_ptr, "_di");

}

PHP_METHOD(Ice_Validation, setRules) {

	zval *rules;

	zephir_fetch_params(0, 1, 0, &rules);



	zephir_update_property_this(this_ptr, SL("_rules"), rules TSRMLS_CC);

}

PHP_METHOD(Ice_Validation, setFilters) {

	zval *filters;

	zephir_fetch_params(0, 1, 0, &filters);



	zephir_update_property_this(this_ptr, SL("_filters"), filters TSRMLS_CC);

}

PHP_METHOD(Ice_Validation, setLabels) {

	zval *labels;

	zephir_fetch_params(0, 1, 0, &labels);



	zephir_update_property_this(this_ptr, SL("_labels"), labels TSRMLS_CC);

}

PHP_METHOD(Ice_Validation, setAliases) {

	zval *aliases;

	zephir_fetch_params(0, 1, 0, &aliases);



	zephir_update_property_this(this_ptr, SL("_aliases"), aliases TSRMLS_CC);

}

PHP_METHOD(Ice_Validation, setTranslate) {

	zval *translate;

	zephir_fetch_params(0, 1, 0, &translate);



	zephir_update_property_this(this_ptr, SL("_translate"), translate TSRMLS_CC);

}

PHP_METHOD(Ice_Validation, setHumanLabels) {

	zval *humanLabels;

	zephir_fetch_params(0, 1, 0, &humanLabels);



	zephir_update_property_this(this_ptr, SL("_humanLabels"), humanLabels TSRMLS_CC);

}

/**
 * Validation constructor. Fetch Di and set the data if given
 */
PHP_METHOD(Ice_Validation, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL;
	zval *data_param = NULL, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8 = NULL;
	zval *data = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 29);
	add_assoc_stringl_ex(_0, SS("alnum"), SL("Field :field must contain only letters and numbers"), 1);
	add_assoc_stringl_ex(_0, SS("alpha"), SL("Field :field must contain only letters"), 1);
	add_assoc_stringl_ex(_0, SS("between"), SL("Field :field must be within the range of :min to :max"), 1);
	add_assoc_stringl_ex(_0, SS("digit"), SL("Field :field must be numeric"), 1);
	add_assoc_stringl_ex(_0, SS("default"), SL("Field :field is not valid"), 1);
	add_assoc_stringl_ex(_0, SS("email"), SL("Field :field must be an email address"), 1);
	add_assoc_stringl_ex(_0, SS("fileEmpty"), SL("Field :field must not be empty"), 1);
	add_assoc_stringl_ex(_0, SS("fileIniSize"), SL("File :field exceeds the maximum file size"), 1);
	add_assoc_stringl_ex(_0, SS("fileMaxResolution"), SL("File :field must not exceed :max resolution"), 1);
	add_assoc_stringl_ex(_0, SS("fileMinResolution"), SL("File :field must be at least :min resolution"), 1);
	add_assoc_stringl_ex(_0, SS("fileSize"), SL("File :field exceeds the size of :max"), 1);
	add_assoc_stringl_ex(_0, SS("fileType"), SL("File :field must be of type: :types"), 1);
	add_assoc_stringl_ex(_0, SS("in"), SL("Field :field must be a part of list: :values"), 1);
	add_assoc_stringl_ex(_0, SS("lengthMax"), SL("Field :field must not exceed :max characters long"), 1);
	add_assoc_stringl_ex(_0, SS("lengthMin"), SL("Field :field must be at least :min characters long"), 1);
	add_assoc_stringl_ex(_0, SS("notIn"), SL("Field :field must not be a part of list: :values"), 1);
	add_assoc_stringl_ex(_0, SS("regex"), SL("Field :field does not match the required format"), 1);
	add_assoc_stringl_ex(_0, SS("required"), SL("Field :field is required"), 1);
	add_assoc_stringl_ex(_0, SS("same"), SL("Field :field and :other must match"), 1);
	add_assoc_stringl_ex(_0, SS("unique"), SL("Field :field must be unique"), 1);
	add_assoc_stringl_ex(_0, SS("url"), SL("Field :field must be a url"), 1);
	add_assoc_stringl_ex(_0, SS("with"), SL("Field :field must occur together with :fields"), 1);
	add_assoc_stringl_ex(_0, SS("without"), SL("Field :field must not occur together with :fields"), 1);
	zephir_update_property_this(this_ptr, SL("_defaultMessages"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_aliases"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_messages"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("_labels"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init(_4);
	zephir_update_property_this(this_ptr, SL("_filters"), _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	zephir_update_property_this(this_ptr, SL("_validators"), _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	array_init(_6);
	zephir_update_property_this(this_ptr, SL("_rules"), _6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	array_init(_7);
	zephir_update_property_this(this_ptr, SL("_data"), _7 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_8, ice_di_ce, "fetch", &_9);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_di"), _8 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Resolve one rule
 *
 * @param string alias
 * @param string field
 * @param mixed options
 * @return void
 */
PHP_METHOD(Ice_Validation, resolve) {

	zval *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	zval *alias_param = NULL, *field_param = NULL, *options = NULL, *rule = NULL, *_0, *_1 = NULL, *_2, _3, *_4 = NULL;
	zval *alias = NULL, *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &alias_param, &field_param, &options);

	zephir_get_strval(alias, alias_param);
	zephir_get_strval(field, field_param);
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(rule);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_aliases"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&rule, _0, alias, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		zephir_camelize(_1, alias);
		ZEPHIR_INIT_NVAR(rule);
		ZEPHIR_CONCAT_SV(rule, "Ice\\Validation\\Validator\\", _1);
		if (!(zephir_class_exists(rule, 1 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_2);
			object_init_ex(_2, ice_exception_ce);
			ZEPHIR_SINIT_VAR(_3);
			ZVAL_STRING(&_3, "Validator %s not found", 0);
			ZEPHIR_CALL_FUNCTION(&_4, "sprintf", &_5, &_3, alias);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_2, "ice/validation.zep", 82 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_INIT_VAR(_6);
	array_init_size(_6, 2);
	zephir_array_fast_append(_6, options);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_1, rule, _6 TSRMLS_CC);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("_rules"), &_1 TSRMLS_CC, SL("za"), 1, field);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add one rule
 *
 * @param string field
 * @param mixed validators
 * @param mixed options
 * @return void
 */
PHP_METHOD(Ice_Validation, rule) {

	zephir_nts_static zephir_fcall_cache_entry *_13 = NULL;
	zend_bool _7;
	zephir_fcall_cache_entry *_4 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_11;
	HashPosition _1, _10;
	zval *field_param = NULL, *validators, *options = NULL, *validator = NULL, *rules, *rule = NULL, *alias = NULL, *values = NULL, *_0, **_3, _5, *_6, _8, *_9, **_12;
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
			zephir_update_property_array_multi(this_ptr, SL("_rules"), &validators TSRMLS_CC, SL("za"), 1, field);
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "array")) {
			zephir_is_iterable(validators, &_2, &_1, 0, 0, "ice/validation.zep", 112);
			for (
			  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HMKEY(validator, _2, _1);
				ZEPHIR_GET_HVALUE(options, _3);
				if (Z_TYPE_P(validator) == IS_LONG) {
					ZEPHIR_CPY_WRT(validator, options);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rule", &_4, field, validator, options);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "string")) {
			ZEPHIR_SINIT_VAR(_5);
			ZVAL_STRING(&_5, "|", 0);
			ZEPHIR_INIT_VAR(_6);
			zephir_fast_strpos(_6, validators, &_5, 0 );
			_7 = ZEPHIR_IS_FALSE_IDENTICAL(_6);
			if (_7) {
				ZEPHIR_SINIT_VAR(_8);
				ZVAL_STRING(&_8, ":", 0);
				ZEPHIR_INIT_VAR(_9);
				zephir_fast_strpos(_9, validators, &_8, 0 );
				_7 = ZEPHIR_IS_FALSE_IDENTICAL(_9);
			}
			if (_7) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolve", NULL, validators, field, options);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(rules);
				zephir_fast_explode_str(rules, SL("|"), validators, LONG_MAX TSRMLS_CC);
				zephir_is_iterable(rules, &_11, &_10, 0, 0, "ice/validation.zep", 131);
				for (
				  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
				  ; zephir_hash_move_forward_ex(_11, &_10)
				) {
					ZEPHIR_GET_HVALUE(rule, _12);
					ZEPHIR_INIT_NVAR(options);
					zephir_fast_explode_str(options, SL(":"), rule, LONG_MAX TSRMLS_CC);
					Z_SET_ISREF_P(options);
					ZEPHIR_CALL_FUNCTION(&alias, "array_shift", &_13, options);
					Z_UNSET_ISREF_P(options);
					zephir_check_call_status();
					if (!ZEPHIR_IS_STRING(alias, "regex")) {
						ZEPHIR_OBS_NVAR(values);
						if (zephir_array_isset_long_fetch(&values, options, 0, 0 TSRMLS_CC)) {
							ZEPHIR_INIT_NVAR(options);
							zephir_fast_explode_str(options, SL(","), values, LONG_MAX TSRMLS_CC);
						}
					}
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolve", &_14, alias, field, options);
					zephir_check_call_status();
				}
			}
			break;
		}
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Add multiple rules at once
 *
 * @param array validators
 * @return void
 */
PHP_METHOD(Ice_Validation, rules) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *validators_param = NULL, *field = NULL, *rules = NULL, **_2;
	zval *validators = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validators_param);

	validators = validators_param;



	zephir_is_iterable(validators, &_1, &_0, 0, 0, "ice/validation.zep", 149);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(field, _1, _0);
		ZEPHIR_GET_HVALUE(rules, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rule", &_3, field, rules);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Validate the data
 *
 * @param array data Data to validate
 * @return boolean
 */
PHP_METHOD(Ice_Validation, validate) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_5;
	HashPosition _1, _4;
	zval *data_param = NULL, *field = NULL, *rules = NULL, *rule = NULL, *_0, **_3, **_6, *_7 = NULL, *_8;
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
		zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_rules"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/validation.zep", 175);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(field, _2, _1);
		ZEPHIR_GET_HVALUE(rules, _3);
		zephir_is_iterable(rules, &_5, &_4, 0, 0, "ice/validation.zep", 172);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HVALUE(rule, _6);
			ZEPHIR_CALL_METHOD(&_7, rule, "validate", NULL, this_ptr, field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_7)) {
				zephir_update_property_this(this_ptr, SL("_valid"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
		}
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	if (zephir_fast_count_int(_8 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_valid"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "_valid");

}

/**
 * Check if validation passed
 *
 * @return boolean
 */
PHP_METHOD(Ice_Validation, valid) {


	RETURN_MEMBER(this_ptr, "_valid");

}

/**
 * Whether or not a value exists by field
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, field));

}

/**
 * Get a value by field
 *
 * @param string field The data key
 * @param boolean filtered Get the filtered value or original
 * @return mixed
 */
PHP_METHOD(Ice_Validation, getValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool filtered, _1, _5;
	zval *field_param = NULL, *filtered_param = NULL, *value = NULL, *filters, *_0, *_2, *_3 = NULL, *_4 = NULL, *_6, *_7, *_8 = NULL, *_9 = NULL;
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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	zephir_array_isset_fetch(&value, _0, field, 0 TSRMLS_CC);
	_1 = filtered;
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "filter", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, _2, "has", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		_1 = zephir_is_true(_3);
	}
	_5 = _1;
	if (_5) {
		ZEPHIR_OBS_VAR(filters);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
		_5 = zephir_array_isset_fetch(&filters, _6, field, 0 TSRMLS_CC);
	}
	if (_5) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "filter", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8, _7, "get", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_9, _8, "sanitize", NULL, value, filters);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _9);
	}
	RETURN_CCTOR(value);

}

/**
 * Get the label of a field
 * Humanize a label if humanLabels attribute and filter service is available
 * Translate label if translate attribute and i18n service is available
 *
 * @param string field The data key
 * @return string
 */
PHP_METHOD(Ice_Validation, getLabel) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _2;
	zval *field_param = NULL, *label = NULL, *_0, *_1, *_3, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL, *_8 = NULL;
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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_labels"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&label, _0, field, 0 TSRMLS_CC))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_humanLabels"), PH_NOISY_CC);
		_2 = zephir_is_true(_1);
		if (_2) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_5);
			ZVAL_STRING(_5, "filter", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_4, _3, "has", NULL, _5);
			zephir_check_temp_parameter(_5);
			zephir_check_call_status();
			_2 = zephir_is_true(_4);
		}
		if (_2) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "filter", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7, _6, "get", NULL, _5);
			zephir_check_temp_parameter(_5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "human", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&label, _7, "sanitize", NULL, field, _5);
			zephir_check_temp_parameter(_5);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(label, field);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
	_2 = zephir_is_true(_1);
	if (_2) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "i18n", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4, _3, "has", NULL, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		_2 = zephir_is_true(_4);
	}
	if (_2) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "i18n", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_7, _6, "get", NULL, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_8, _7, "translate", NULL, label);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(label, _8);
	}
	RETURN_CCTOR(label);

}

/**
 * Set the default messages
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
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultMessages"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(messages) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_defaultMessages"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a default message for the type
 * Translate message if translate attribute and i18n service is available
 *
 * @param string type Type of message
 * @return string
 */
PHP_METHOD(Ice_Validation, getDefaultMessage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _3;
	zval *type_param = NULL, *message = NULL, *_0, *_1, *_2, *_4, *_5 = NULL, *_6 = NULL, *_7, *_8 = NULL, *_9 = NULL;
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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultMessages"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&message, _0, type, 0 TSRMLS_CC))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultMessages"), PH_NOISY_CC);
		zephir_array_fetch_string(&_2, _1, SL("default"), PH_NOISY | PH_READONLY, "ice/validation.zep", 276 TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
	_3 = zephir_is_true(_1);
	if (_3) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "i18n", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, _4, "has", NULL, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		_3 = zephir_is_true(_5);
	}
	if (_3) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "i18n", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8, _7, "get", NULL, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_9, _8, "translate", NULL, message);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(message, _9);
	}
	RETURN_CCTOR(message);

}

/**
 * Add a message to the field
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


	zephir_update_property_array_multi(this_ptr, SL("_messages"), &message TSRMLS_CC, SL("za"), 1, field);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the validation's messages
 *
 * @return Arr
 */
PHP_METHOD(Ice_Validation, getMessages) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, ice_arr_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

