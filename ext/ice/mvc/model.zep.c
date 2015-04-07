
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/iterator.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"

ZEPHIR_INIT_CLASS(Ice_Mvc_Model) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, Model, ice, mvc_model, ice_arr_ce, ice_mvc_model_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_model_ce, SL("_di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("_db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("_from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("_primary"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("_fields"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("_validation"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("_relations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("_labels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("_rules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_model_ce, SL("BELONGS_TO"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_model_ce, SL("HAS_ONE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_model_ce, SL("HAS_MANY"), 3 TSRMLS_CC);

	zend_class_implements(ice_mvc_model_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Model, getDi) {


	RETURN_MEMBER(this_ptr, "_di");

}

PHP_METHOD(Ice_Mvc_Model, getDb) {


	RETURN_MEMBER(this_ptr, "_db");

}

PHP_METHOD(Ice_Mvc_Model, setFrom) {

	zval *from;

	zephir_fetch_params(0, 1, 0, &from);



	zephir_update_property_this(this_ptr, SL("_from"), from TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, setPrimary) {

	zval *primary;

	zephir_fetch_params(0, 1, 0, &primary);



	zephir_update_property_this(this_ptr, SL("_primary"), primary TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, getPrimary) {


	RETURN_MEMBER(this_ptr, "_primary");

}

PHP_METHOD(Ice_Mvc_Model, setFilters) {

	zval *filters;

	zephir_fetch_params(0, 1, 0, &filters);



	zephir_update_property_this(this_ptr, SL("_filters"), filters TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, getFilters) {


	RETURN_MEMBER(this_ptr, "_filters");

}

PHP_METHOD(Ice_Mvc_Model, setFields) {

	zval *fields;

	zephir_fetch_params(0, 1, 0, &fields);



	zephir_update_property_this(this_ptr, SL("_fields"), fields TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, getFields) {


	RETURN_MEMBER(this_ptr, "_fields");

}

PHP_METHOD(Ice_Mvc_Model, setValidation) {

	zval *validation;

	zephir_fetch_params(0, 1, 0, &validation);



	zephir_update_property_this(this_ptr, SL("_validation"), validation TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, getValidation) {


	RETURN_MEMBER(this_ptr, "_validation");

}

PHP_METHOD(Ice_Mvc_Model, getRelations) {


	RETURN_MEMBER(this_ptr, "_relations");

}

PHP_METHOD(Ice_Mvc_Model, setLabels) {

	zval *labels;

	zephir_fetch_params(0, 1, 0, &labels);



	zephir_update_property_this(this_ptr, SL("_labels"), labels TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, getMessages) {


	RETURN_MEMBER(this_ptr, "_messages");

}

/**
 * Model constructor. Fetch Di and set it as a property.
 *
 * @param mixed filters
 * @param array data
 */
PHP_METHOD(Ice_Mvc_Model, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL, *_12 = NULL;
	zval *data = NULL;
	zval *filters = NULL, *data_param = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *di = NULL, *_7 = NULL, *_8, *_9, *_10 = NULL, *_13, *_14, *_15, *_16, *_17, *_18 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &filters, &data_param);

	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_messages"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_rules"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_labels"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("_relations"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init(_4);
	zephir_update_property_this(this_ptr, SL("_fields"), _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	zephir_update_property_this(this_ptr, SL("_filters"), _5 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_6);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_di"), di TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_7, di, "getdb", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_db"), _7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_fields"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_10, "array_fill_keys", &_11, _9, ZEPHIR_GLOBAL(global_null));
	zephir_check_call_status();
	zephir_fast_array_merge(_8, &(_10), &(data) TSRMLS_CC);
	ZEPHIR_CPY_WRT(data, _8);
	ZEPHIR_CALL_PARENT(NULL, ice_mvc_model_ce, this_ptr, "__construct", &_12, data);
	zephir_check_call_status();
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("_from"), PH_NOISY_CC);
	if (!(zephir_is_true(_13))) {
		ZEPHIR_INIT_VAR(_14);
		ZEPHIR_INIT_VAR(_15);
		zephir_get_class_ns(_15, this_ptr, 0 TSRMLS_CC);
		zephir_uncamelize(_14, _15);
		zephir_update_property_this(this_ptr, SL("_from"), _14 TSRMLS_CC);
	}
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("_primary"), PH_NOISY_CC);
	if (!(zephir_is_true(_16))) {
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_18, _17, "getid", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_primary"), _18 TSRMLS_CC);
	}
	if ((zephir_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL);
		zephir_check_call_status();
	}
	if (zephir_is_true(filters)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadone", NULL, filters);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(this_ptr, SS("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Load one result to the current object.
 *
 * @param mixed filters
 */
PHP_METHOD(Ice_Mvc_Model, loadOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *filters, *result = NULL, *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filters);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&result, _0, "findone", NULL, _1, filters);
	zephir_check_call_status();
	if (zephir_is_true(result)) {
		ZEPHIR_CALL_METHOD(&_2, result, "all", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, _2);
		zephir_check_call_status();
		RETURN_THIS();
	} else {
		RETURN_MM_BOOL(0);
	}

}

/**
 * Load results to the current object.
 *
 * @param mixed filters
 * @return Arr
 */
PHP_METHOD(Ice_Mvc_Model, load) {

	zend_object_iterator *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *_6 = NULL;
	zval *filters, *options_param = NULL, *result = NULL, *instances, *data = NULL, *_0, *_1, *_2 = NULL, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filters, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&result, _0, "find", NULL, _1, filters, options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(instances);
	array_init(instances);
	ZEPHIR_CALL_METHOD(&_2, result, "count", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		_3 = zephir_get_iterator(result TSRMLS_CC);
		_3->funcs->rewind(_3 TSRMLS_CC);
		for (;_3->funcs->valid(_3 TSRMLS_CC) == SUCCESS && !EG(exception); _3->funcs->move_forward(_3 TSRMLS_CC)) {
			{ zval **tmp; 
			_3->funcs->get_current_data(_3, &tmp TSRMLS_CC);
			data = *tmp;
			}
			ZEPHIR_INIT_NVAR(_4);
			ZEPHIR_INIT_NVAR(_5);
			zephir_get_called_class(_5 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_6);
			array_init_size(_6, 3);
			zephir_array_fast_append(_6, ZEPHIR_GLOBAL(global_null));
			zephir_array_fast_append(_6, data);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_4, _5, _6 TSRMLS_CC);
			zephir_check_call_status();
			zephir_array_append(&instances, _4, PH_SEPARATE, "ice/mvc/model.zep", 111);
		}
		_3->funcs->dtor(_3 TSRMLS_CC);
	}
	object_init_ex(return_value, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, instances);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to query one record that match the specified conditions.
 *
 * <pre><code>
 *  //Get the user from users by id 2
 *  $user = Users::findOne(2);
 *  echo "The user name is ", $user->username;
 *
 *  //Get one active user with age > 18
 *  $user = Users::findOne(array("status" => 1, "age" => array(">" => 18)));
 * </code></pre>
 *
 * @param array filters
 * @return Model|false
 */
PHP_METHOD(Ice_Mvc_Model, findOne) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, *result, *model, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filters);

	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(model);
	zephir_get_called_class(model TSRMLS_CC);
	ZEPHIR_INIT_VAR(result);
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	zephir_array_fast_append(_0, filters);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(result, model, _0 TSRMLS_CC);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, result, "count", NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		RETURN_MM_BOOL(0);
	} else {
		RETURN_CCTOR(result);
	}

}

/**
 * Allows to query all records that match the specified conditions.
 *
 * <pre><code>
 *  //Get all active users with age > 18
 *  $user = Users::find(array("status" => 1, "age" => array(">" => 18)));
 * </code></pre>
 *
 * @param array filters
 * @return Arr
 */
PHP_METHOD(Ice_Mvc_Model, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *filters = NULL, *options_param = NULL, *result = NULL, *model, *instance;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &filters, &options_param);

	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(model);
	zephir_get_called_class(model TSRMLS_CC);
	ZEPHIR_INIT_VAR(instance);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(instance, model TSRMLS_CC);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, instance, "load", NULL, filters, options);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

/**
 * Prepare fields for validation on create/update.
 *
 * @param mixed fields
 * @return array
 */
PHP_METHOD(Ice_Mvc_Model, fields) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, *_0, *_1 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_10, *_11 = NULL, *_12, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fields);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		ZEPHIR_SEPARATE_PARAM(fields);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_fields"), PH_NOISY_CC);
	if (!(zephir_fast_count_int(_0 TSRMLS_CC))) {
		if (!(zephir_fast_count_int(fields TSRMLS_CC))) {
			ZEPHIR_CALL_METHOD(&fields, this_ptr, "all", NULL);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_1);
			zephir_array_keys(_1, fields TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_2);
			ZVAL_STRING(&_2, "is_string", 0);
			ZEPHIR_CALL_FUNCTION(&_3, "array_filter", &_4, _1, &_2);
			zephir_check_call_status();
			if (zephir_fast_count_int(_3 TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_5);
				ZEPHIR_CALL_METHOD(&_6, this_ptr, "all", NULL);
				zephir_check_call_status();
				zephir_fast_array_merge(_5, &(_6), &(fields) TSRMLS_CC);
				ZEPHIR_CPY_WRT(fields, _5);
			} else {
				ZEPHIR_CALL_METHOD(&_6, this_ptr, "all", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_7, "array_flip", &_8, fields);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&fields, "array_intersect_key", &_9, _6, _7);
				zephir_check_call_status();
			}
		}
	} else {
		if (!(zephir_fast_count_int(fields TSRMLS_CC))) {
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "all", NULL);
			zephir_check_call_status();
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_fields"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&_6, "array_flip", &_8, _10);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&fields, "array_intersect_key", &_9, _3, _6);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_1);
			zephir_array_keys(_1, fields TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_STRING(&_2, "is_string", 0);
			ZEPHIR_CALL_FUNCTION(&_3, "array_filter", &_4, _1, &_2);
			zephir_check_call_status();
			if (zephir_fast_count_int(_3 TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(_5);
				ZEPHIR_CALL_METHOD(&_7, this_ptr, "all", NULL);
				zephir_check_call_status();
				zephir_fast_array_merge(_5, &(_7), &(fields) TSRMLS_CC);
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("_fields"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_11, "array_flip", &_8, _10);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&fields, "array_intersect_key", &_9, _5, _11);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&_6, this_ptr, "all", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_7, "array_flip", &_8, fields);
				zephir_check_call_status();
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_fields"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_11, "array_flip", &_8, _12);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&fields, "array_intersect_key", &_9, _6, _7, _11);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_OBS_VAR(_13);
	zephir_read_property_this(&_13, this_ptr, SL("_primary"), PH_NOISY_CC);
	if (Z_TYPE_P(_13) == IS_STRING) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_primary"), PH_NOISY_CC);
		zephir_array_unset(&fields, _10, PH_SEPARATE);
	}
	RETVAL_ZVAL(fields, 1, 0);
	RETURN_MM();

}

/**
 * Insert a new object to the database.
 *
 * <pre><code>
 *  //Creating a new user
 *  $user = new Users();
 *  $user->lastname = "Kowalski";
 *  $user->status = 1;
 *  $user->create();
 * </code></pre>
 *
 * @param array fields Fields to save or valid fields
 * @param object extra Validation for fields such as a CSRF token, password verification, or a CAPTCHA
 */
PHP_METHOD(Ice_Mvc_Model, create) {

	zval *_3, *_22;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _7, _19, _20;
	zval *fields = NULL, *extra = NULL, *status = NULL, *valid = NULL, *extraValid = NULL, *messages = NULL, *extraMessages = NULL, *_1 = NULL, *_2, *_4 = NULL, *_5, *_6, *_8, *_9, *_10, *_11, *_12, *_13, *_14, *_15, *_16 = NULL, *_17, *_18 = NULL, *_21 = NULL, *_23 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		ZEPHIR_SEPARATE_PARAM(fields);
	}
	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(extra) != IS_NULL;
	if (_0) {
		_0 = !(zephir_instance_of_ev(extra, ice_validation_ce TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'extra' must be an instance of 'Ice\\Validation'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "fields", NULL, fields);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(fields, _1);
	ZEPHIR_INIT_VAR(extraValid);
	ZVAL_BOOL(extraValid, 0);
	ZEPHIR_INIT_VAR(extraMessages);
	array_init(extraMessages);
	ZEPHIR_INIT_VAR(valid);
	ZVAL_BOOL(valid, 0);
	ZEPHIR_INIT_VAR(messages);
	array_init(messages);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, fields);
	zephir_check_call_status();
	if (zephir_is_true(extra)) {
		ZEPHIR_CALL_METHOD(&extraValid, extra, "validate", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, extra, "getmessages", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&extraMessages, _1, "all", NULL);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 2);
	zephir_array_fast_append(_3, this_ptr);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "model.before.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "applyhook", NULL, _4, _3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_rules"), PH_NOISY_CC);
	if (zephir_fast_count_int(_5 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_6);
		zephir_read_property_this(&_6, this_ptr, SL("_validation"), PH_NOISY_CC);
		_7 = Z_TYPE_P(_6) == IS_OBJECT;
		if (_7) {
			ZEPHIR_OBS_VAR(_8);
			zephir_read_property_this(&_8, this_ptr, SL("_validation"), PH_NOISY_CC);
			_7 = zephir_instance_of_ev(_8, ice_validation_ce TSRMLS_CC);
		}
		if (!(_7)) {
			ZEPHIR_INIT_NVAR(_4);
			object_init_ex(_4, ice_validation_ce);
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_validation"), _4 TSRMLS_CC);
		}
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_validation"), PH_NOISY_CC);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_rules"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _9, "rules", NULL, _10);
		zephir_check_call_status();
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_validation"), PH_NOISY_CC);
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _11, "setfilters", NULL, _12);
		zephir_check_call_status();
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_validation"), PH_NOISY_CC);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_labels"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _13, "setlabels", NULL, _14);
		zephir_check_call_status();
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_16, this_ptr, "getdata", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&valid, _15, "validate", NULL, _16);
		zephir_check_call_status();
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_18, _17, "getmessages", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&messages, _18, "all", NULL);
		zephir_check_call_status();
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_rules"), PH_NOISY_CC);
	_7 = (zephir_fast_count_int(_9 TSRMLS_CC)) ? 1 : 0;
	if (_7) {
		_7 = !zephir_is_true(valid);
	}
	_19 = _7;
	if (!(_19)) {
		_20 = zephir_is_true(extra);
		if (_20) {
			_20 = !zephir_is_true(extraValid);
		}
		_19 = _20;
	}
	if (_19) {
		ZEPHIR_INIT_VAR(_21);
		zephir_fast_array_merge(_21, &(extraMessages), &(messages) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_messages"), _21 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_22);
	array_init_size(_22, 2);
	zephir_array_fast_append(_22, this_ptr);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "model.after.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _9, "applyhook", NULL, _21, _22);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_16, this_ptr, "getdata", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, _10, "insert", NULL, _11, _16);
	zephir_check_call_status();
	if (zephir_is_true(status)) {
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_18, _12, "getid", NULL);
		zephir_check_call_status();
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_23, _13, "getlastinsertid", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, _18, _23);
		zephir_check_call_status();
	}
	RETURN_CCTOR(status);

}

/**
 * Update an existing object in the database.
 *
 * <pre><code>
 *  //Updating a user last name
 *  $user = Users::findOne(100);
 *  $user->lastname = "Nowak";
 *  $user->update();
 * </code></pre>
 *
 * @param array fields Fields to save or valid fields
 * @param object extra Validation for fields such as a CSRF token, password verification, or a CAPTCHA
 */
PHP_METHOD(Ice_Mvc_Model, update) {

	zephir_fcall_cache_entry *_14 = NULL;
	HashTable *_11;
	HashPosition _10;
	zval *_3, *_7;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _5;
	zval *fields = NULL, *extra = NULL, *status = NULL, *primary = NULL, *key = NULL, *extraValid = NULL, *extraMessages = NULL, *_1 = NULL, *_2, *_4 = NULL, *_6, *_8, *_9, **_12, *_13 = NULL, *_15, *_16;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		ZEPHIR_SEPARATE_PARAM(fields);
	}
	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(extra) != IS_NULL;
	if (_0) {
		_0 = !(zephir_instance_of_ev(extra, ice_validation_ce TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'extra' must be an instance of 'Ice\\Validation'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "fields", NULL, fields);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(fields, _1);
	ZEPHIR_INIT_VAR(extraValid);
	ZVAL_BOOL(extraValid, 0);
	ZEPHIR_INIT_VAR(extraMessages);
	array_init(extraMessages);
	ZEPHIR_INIT_VAR(primary);
	array_init(primary);
	if (zephir_is_true(extra)) {
		ZEPHIR_CALL_METHOD(&extraValid, extra, "validate", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, extra, "getmessages", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&extraMessages, _1, "all", NULL);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 2);
	zephir_array_fast_append(_3, this_ptr);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "model.before.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "applyhook", NULL, _4, _3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	_5 = zephir_is_true(extra);
	if (_5) {
		_5 = !zephir_is_true(extraValid);
	}
	if (_5) {
		zephir_update_property_this(this_ptr, SL("_messages"), extraMessages TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	array_init_size(_7, 2);
	zephir_array_fast_append(_7, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "model.after.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _6, "applyhook", NULL, _4, _7);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_8);
	zephir_read_property_this(&_8, this_ptr, SL("_primary"), PH_NOISY_CC);
	if (Z_TYPE_P(_8) == IS_ARRAY) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_primary"), PH_NOISY_CC);
		zephir_is_iterable(_9, &_11, &_10, 0, 0, "ice/mvc/model.zep", 324);
		for (
		  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HVALUE(key, _12);
			ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", &_14, key);
			zephir_check_call_status();
			zephir_array_update_zval(&primary, key, &_13, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_INIT_NVAR(primary);
		array_init_size(primary, 2);
		ZEPHIR_OBS_VAR(_15);
		zephir_read_property_this(&_15, this_ptr, SL("_primary"), PH_NOISY_CC);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_primary"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "get", &_14, _9);
		zephir_check_call_status();
		zephir_array_update_zval(&primary, _15, &_13, PH_COPY);
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("_from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&status, _9, "update", NULL, _16, primary, fields);
	zephir_check_call_status();
	if (zephir_is_true(status)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, fields);
		zephir_check_call_status();
	}
	RETURN_CCTOR(status);

}

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
 *
 * <pre><code>
 *  //Creating a new user
 *  $user = new Users();
 *  $user->lastname = "Kowalski";
 *  $user->status = 1;
 *  $user->save();
 *
 *  //Updating a user last name
 *  $user = Users::findOne(100);
 *  $user->lastname = "Nowak";
 *  $user->save();
 * </code></pre>
 *
 * @param array fields
 * @param Validation extra
 * @return boolean
 */
PHP_METHOD(Ice_Mvc_Model, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *fields = NULL, *extra = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(extra) != IS_NULL;
	if (_0) {
		_0 = !(zephir_instance_of_ev(extra, ice_validation_ce TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'extra' must be an instance of 'Ice\\Validation'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "exists", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "update", NULL, fields, extra);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "create", NULL, fields, extra);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * Removes a model instance(s). Returning true on success or false otherwise.
 *
 * <pre><code>
 *  //Remove current user
 *  $user = Users::findOne(100);
 *  $user->delete();
 *  
 *  //Remove all unactive users
 *  $status = (new Users())->remove(["status" => 0]);
 * </code></pre>
 *
 * @param filters
 * @return boolean
 */
PHP_METHOD(Ice_Mvc_Model, remove) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3;
	HashPosition _2;
	zval *filters = NULL, *key = NULL, *status = NULL, *_0, *_1, **_4, *_5 = NULL, *_7, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filters);

	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	} else {
		ZEPHIR_SEPARATE_PARAM(filters);
	}


	if (!(zephir_is_true(filters))) {
		ZEPHIR_INIT_NVAR(filters);
		array_init(filters);
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("_primary"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_ARRAY) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_primary"), PH_NOISY_CC);
			zephir_is_iterable(_1, &_3, &_2, 0, 0, "ice/mvc/model.zep", 392);
			for (
			  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			  ; zephir_hash_move_forward_ex(_3, &_2)
			) {
				ZEPHIR_GET_HVALUE(key, _4);
				ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", &_6, key);
				zephir_check_call_status();
				zephir_array_update_zval(&filters, key, &_5, PH_COPY | PH_SEPARATE);
			}
		} else {
			ZEPHIR_INIT_NVAR(filters);
			array_init_size(filters, 2);
			ZEPHIR_OBS_VAR(_7);
			zephir_read_property_this(&_7, this_ptr, SL("_primary"), PH_NOISY_CC);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_primary"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "get", &_6, _1);
			zephir_check_call_status();
			zephir_array_update_zval(&filters, _7, &_5, PH_COPY);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&status, _1, "remove", NULL, _8, filters);
	zephir_check_call_status();
	RETURN_CCTOR(status);

}

/**
 * Get the record if exist.
 *
 * @param mixed filters
 * @return Model|false
 */
PHP_METHOD(Ice_Mvc_Model, exists) {

	zend_bool _7;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3;
	HashPosition _2;
	zval *filters = NULL, *key = NULL, *_0, *_1, **_4, *_5 = NULL, *_8 = NULL, *_10 = NULL, *_11, *_12, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filters);

	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	} else {
		ZEPHIR_SEPARATE_PARAM(filters);
	}


	if (!(zephir_is_true(filters))) {
		ZEPHIR_INIT_NVAR(filters);
		array_init(filters);
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("_primary"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_ARRAY) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_primary"), PH_NOISY_CC);
			zephir_is_iterable(_1, &_3, &_2, 0, 0, "ice/mvc/model.zep", 423);
			for (
			  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			  ; zephir_hash_move_forward_ex(_3, &_2)
			) {
				ZEPHIR_GET_HVALUE(key, _4);
				ZEPHIR_CALL_METHOD(&_5, this_ptr, "has", &_6, key);
				zephir_check_call_status();
				_7 = zephir_is_true(_5);
				if (_7) {
					ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", &_9, key);
					zephir_check_call_status();
					_7 = zephir_is_true(_8);
				}
				if (_7) {
					ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", &_9, key);
					zephir_check_call_status();
					zephir_array_update_zval(&filters, key, &_10, PH_COPY | PH_SEPARATE);
				} else {
					RETURN_MM_BOOL(0);
				}
			}
		} else {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_primary"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "has", &_6, _1);
			zephir_check_call_status();
			_7 = zephir_is_true(_5);
			if (_7) {
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("_primary"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_8, this_ptr, "get", &_9, _11);
				zephir_check_call_status();
				_7 = zephir_is_true(_8);
			}
			if (_7) {
				ZEPHIR_INIT_NVAR(filters);
				array_init_size(filters, 2);
				ZEPHIR_OBS_VAR(_12);
				zephir_read_property_this(&_12, this_ptr, SL("_primary"), PH_NOISY_CC);
				_13 = zephir_fetch_nproperty_this(this_ptr, SL("_primary"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", &_9, _13);
				zephir_check_call_status();
				zephir_array_update_zval(&filters, _12, &_10, PH_COPY);
			} else {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_RETURN_CALL_SELF("findone", NULL, filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the last Db error.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_Model, getError) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_db"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "geterror", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup a relation reverse 1-1 between two models.
 *
 * <pre><code>
 *  class Posts extends Model
 *  {
 *      public function initialize()
 *      {
 *          //Relation with user, be able to get post's author
 *          $this->belongsTo('user_id', __NAMESPACE__ . '\Users', 'id', ['alias' => 'User']);
 *      }
 *  }
 *
 *  //Get post's author
 *  $post = Posts::findOne(100);
 *  echo $post->getUser()->username;
 * </code></pre>
 *
 * @param string field
 * @param string referenceModel
 * @param string referencedField
 * @param array options
 */
PHP_METHOD(Ice_Mvc_Model, belongsTo) {

	zval *options = NULL, *_0;
	zval *field_param = NULL, *referenceModel_param = NULL, *referencedField_param = NULL, *options_param = NULL, *alias = NULL;
	zval *field = NULL, *referenceModel = NULL, *referencedField = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &field_param, &referenceModel_param, &referencedField_param, &options_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(referenceModel, referenceModel_param);
	zephir_get_strval(referencedField, referencedField_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_OBS_VAR(alias);
	if (!(zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(alias, referenceModel);
	}
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 7);
	add_assoc_long_ex(_0, SS("type"), 1);
	zephir_array_update_string(&_0, SL("field"), &field, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referenceModel"), &referenceModel, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedField"), &referencedField, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("options"), &options, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("_relations"), alias, _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Setup a 1-1 relation between two models
 *
 * <pre><code>
 *  class Users extends Model
 *  {
 *      public function initialize()
 *      {
 *          $this->hasOne('id', __NAMESPACE__ . '\UsersDescriptions', 'user_id', ['alias' => 'Description']);
 *      }
 *  }
 * </code></pre>
 *
 * @param string field
 * @param string referenceModel
 * @param string referencedField
 * @param array options
 */
PHP_METHOD(Ice_Mvc_Model, hasOne) {

	zval *options = NULL, *_0;
	zval *field_param = NULL, *referenceModel_param = NULL, *referencedField_param = NULL, *options_param = NULL, *alias = NULL;
	zval *field = NULL, *referenceModel = NULL, *referencedField = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &field_param, &referenceModel_param, &referencedField_param, &options_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(referenceModel, referenceModel_param);
	zephir_get_strval(referencedField, referencedField_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_OBS_VAR(alias);
	if (!(zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(alias, referenceModel);
	}
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 7);
	add_assoc_long_ex(_0, SS("type"), 2);
	zephir_array_update_string(&_0, SL("field"), &field, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referenceModel"), &referenceModel, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedField"), &referencedField, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("options"), &options, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("_relations"), alias, _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Setup a relation 1-n between two models.
 *
 * <pre><code>
 *  class Users extends Model
 *  {
 *      public function initialize()
 *      {
 *          //Relation with posts, be able to get user's posts
 *          $this->hasMany('id', __NAMESPACE__ . '\Posts', 'user_id', ['alias' => 'Posts']);
 *      }
 *  }
 *
 *  //Get user's posts
 *  $user = Users::findOne(2);
 *  foreach ($user->getPosts() as $post) {
 *      echo $post->title;
 *  }
 * </code></pre>
 *
 * @param string field
 * @param string referenceModel
 * @param string referencedField
 * @param array options
 */
PHP_METHOD(Ice_Mvc_Model, hasMany) {

	zval *options = NULL, *_0;
	zval *field_param = NULL, *referenceModel_param = NULL, *referencedField_param = NULL, *options_param = NULL, *alias = NULL;
	zval *field = NULL, *referenceModel = NULL, *referencedField = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &field_param, &referenceModel_param, &referencedField_param, &options_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(referenceModel, referenceModel_param);
	zephir_get_strval(referencedField, referencedField_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_OBS_VAR(alias);
	if (!(zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(alias, referenceModel);
	}
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 7);
	add_assoc_long_ex(_0, SS("type"), 3);
	zephir_array_update_string(&_0, SL("field"), &field, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referenceModel"), &referenceModel, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedField"), &referencedField, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("options"), &options, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("_relations"), alias, _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get related models.
 *
 * @param string alias
 * @param array filters
 */
PHP_METHOD(Ice_Mvc_Model, getRelated) {

	zend_class_entry *_10;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *filters = NULL, *_7 = NULL, *_9;
	zval *alias_param = NULL, *filters_param = NULL, *relation, *field, *referenceModel, *referencedField, *from, *result = NULL, *_0, *_1 = NULL, _2, *_3 = NULL, *_5, *_6, *_8 = NULL;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &alias_param, &filters_param);

	zephir_get_strval(alias, alias_param);
	if (!filters_param) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	} else {
		zephir_get_arrval(filters, filters_param);
	}


	ZEPHIR_OBS_VAR(relation);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_relations"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&relation, _0, alias, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "Alias '%s' not found", 0);
		ZEPHIR_CALL_FUNCTION(&_3, "sprintf", &_4, &_2, alias);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "ice/mvc/model.zep", 573 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(field);
	zephir_array_isset_string_fetch(&field, relation, SS("field"), 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(referenceModel);
	zephir_array_isset_string_fetch(&referenceModel, relation, SS("referenceModel"), 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(referencedField);
	zephir_array_isset_string_fetch(&referencedField, relation, SS("referencedField"), 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(from);
	ZEPHIR_INIT_NVAR(_1);
	zephir_get_class_ns(_1, referenceModel, 0 TSRMLS_CC);
	zephir_uncamelize(from, _1);
	zephir_array_fetch_string(&_5, relation, SL("type"), PH_NOISY | PH_READONLY, "ice/mvc/model.zep", 582 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_5, 1) || ZEPHIR_IS_LONG(_5, 2)) {
			ZEPHIR_INIT_VAR(_6);
			ZEPHIR_INIT_VAR(_7);
			array_init_size(_7, 2);
			ZEPHIR_OBS_VAR(_8);
			zephir_read_property_zval(&_8, this_ptr, field, PH_NOISY_CC);
			zephir_array_update_zval(&_7, referencedField, &_8, PH_COPY);
			zephir_fast_array_merge(_6, &(filters), &(_7) TSRMLS_CC);
			ZEPHIR_CPY_WRT(filters, _6);
			ZEPHIR_INIT_VAR(result);
			ZEPHIR_INIT_VAR(_9);
			array_init_size(_9, 2);
			zephir_array_fast_append(_9, filters);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(result, referenceModel, _9 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_3, result, "count", NULL);
			zephir_check_call_status();
			if (!(zephir_is_true(_3))) {
				RETURN_MM_BOOL(0);
			}
			RETURN_CCTOR(result);
		}
		if (ZEPHIR_IS_LONG(_5, 3)) {
			ZEPHIR_INIT_NVAR(_1);
			ZEPHIR_INIT_NVAR(_7);
			array_init_size(_7, 2);
			ZEPHIR_OBS_NVAR(_8);
			zephir_read_property_zval(&_8, this_ptr, field, PH_NOISY_CC);
			zephir_array_update_zval(&_7, referencedField, &_8, PH_COPY);
			zephir_fast_array_merge(_1, &(filters), &(_7) TSRMLS_CC);
			ZEPHIR_CPY_WRT(filters, _1);
			_10 = zend_fetch_class(Z_STRVAL_P(referenceModel), Z_STRLEN_P(referenceModel), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			ZEPHIR_CALL_CE_STATIC(&result, _10, "find", NULL, filters);
			zephir_check_call_status();
			RETURN_CCTOR(result);
		}
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Set rules for validation.
 *
 * @param array rules
 * @param boolean merge
 */
PHP_METHOD(Ice_Mvc_Model, setRules) {

	zend_bool merge;
	zval *rules_param = NULL, *merge_param = NULL, *_0, *_1;
	zval *rules = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &rules_param, &merge_param);

	if (!rules_param) {
		ZEPHIR_INIT_VAR(rules);
		array_init(rules);
	} else {
	rules = rules_param;

	}
	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_rules"), PH_NOISY_CC);
		zephir_fast_array_merge(_0, &(_1), &(rules) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_rules"), _0 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_rules"), rules TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Serialize the model's data.
 *
 * @return string
 */
PHP_METHOD(Ice_Mvc_Model, serialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "serialize", &_2, _0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", &_3, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserialize and set the data.
 */
PHP_METHOD(Ice_Mvc_Model, unserialize) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *_0 = NULL, *_2 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	if (unlikely(Z_TYPE_P(data_param) != IS_STRING && Z_TYPE_P(data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(data_param) == IS_STRING)) {
		zephir_get_strval(data, data_param);
	} else {
		ZEPHIR_INIT_VAR(data);
		ZVAL_EMPTY_STRING(data);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "base64_decode", &_1, data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "unserialize", &_3, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_data"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic call to get related models.
 */
PHP_METHOD(Ice_Mvc_Model, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_6 = NULL;
	zval *method_param = NULL, *arguments = NULL, *filters, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, *_5;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	zephir_get_strval(method, method_param);
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_start_with_str(method, SL("get"))) {
		ZEPHIR_OBS_VAR(filters);
		zephir_array_isset_long_fetch(&filters, arguments, 0, 0 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 3);
		ZEPHIR_CALL_FUNCTION(&_1, "substr", &_2, method, &_0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_3, "ucfirst", &_4, _1);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelated", NULL, _3, filters);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_5);
	object_init_ex(_5, ice_exception_ce);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "The method '%s' doesn't exist", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", &_6, &_0, method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _1);
	zephir_check_call_status();
	zephir_throw_exception_debug(_5, "ice/mvc/model.zep", 649 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

