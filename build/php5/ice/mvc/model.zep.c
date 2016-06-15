
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
#include "kernel/exception.h"
#include "kernel/iterator.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Model connects business objects and database tables to create a persistable domain model where logic and data are
 * presented in one wrapping (ORM & ODM).
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Model) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, Model, ice, mvc_model, ice_arr_ce, ice_mvc_model_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_model_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("primary"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("fields"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("validation"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("relations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("labels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("rules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_mvc_model_ce->create_object = zephir_init_properties_Ice_Mvc_Model;
	zend_declare_class_constant_long(ice_mvc_model_ce, SL("BELONGS_TO"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_model_ce, SL("HAS_ONE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_model_ce, SL("HAS_MANY"), 3 TSRMLS_CC);

	zend_class_implements(ice_mvc_model_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Model, getDi) {

	

	RETURN_MEMBER(this_ptr, "di");

}

PHP_METHOD(Ice_Mvc_Model, getDb) {

	

	RETURN_MEMBER(this_ptr, "db");

}

PHP_METHOD(Ice_Mvc_Model, setFrom) {

	zval *from;

	zephir_fetch_params(0, 1, 0, &from);



	zephir_update_property_this(this_ptr, SL("from"), from TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, setPrimary) {

	zval *primary;

	zephir_fetch_params(0, 1, 0, &primary);



	zephir_update_property_this(this_ptr, SL("primary"), primary TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, getPrimary) {

	

	RETURN_MEMBER(this_ptr, "primary");

}

PHP_METHOD(Ice_Mvc_Model, setFilters) {

	zval *filters;

	zephir_fetch_params(0, 1, 0, &filters);



	zephir_update_property_this(this_ptr, SL("filters"), filters TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, getFilters) {

	

	RETURN_MEMBER(this_ptr, "filters");

}

PHP_METHOD(Ice_Mvc_Model, setFields) {

	zval *fields;

	zephir_fetch_params(0, 1, 0, &fields);



	zephir_update_property_this(this_ptr, SL("fields"), fields TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, getFields) {

	

	RETURN_MEMBER(this_ptr, "fields");

}

PHP_METHOD(Ice_Mvc_Model, setValidation) {

	zval *validation;

	zephir_fetch_params(0, 1, 0, &validation);



	zephir_update_property_this(this_ptr, SL("validation"), validation TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, getValidation) {

	

	RETURN_MEMBER(this_ptr, "validation");

}

PHP_METHOD(Ice_Mvc_Model, getRelations) {

	

	RETURN_MEMBER(this_ptr, "relations");

}

PHP_METHOD(Ice_Mvc_Model, setLabels) {

	zval *labels;

	zephir_fetch_params(0, 1, 0, &labels);



	zephir_update_property_this(this_ptr, SL("labels"), labels TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Model, getMessages) {

	

	RETURN_MEMBER(this_ptr, "messages");

}

PHP_METHOD(Ice_Mvc_Model, setMessages) {

	zval *messages;

	zephir_fetch_params(0, 1, 0, &messages);



	zephir_update_property_this(this_ptr, SL("messages"), messages TSRMLS_CC);

}

/**
 * Model constructor. Fetch Di and set it as a property.
 *
 * @param mixed filters
 * @param array data
 */
PHP_METHOD(Ice_Mvc_Model, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *data = NULL;
	zval *filters = NULL, *data_param = NULL, *di = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_6, *_9, *_7$$3, *_8$$3, *_10$$4, *_11$$4 = NULL, *_12$$6 = NULL;

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


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "db", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, di, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("db"), _1 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "array_fill_keys", NULL, 7, _3, ZEPHIR_GLOBAL(global_null));
	zephir_check_call_status();
	zephir_fast_array_merge(_2, &(_4), &(data) TSRMLS_CC);
	ZEPHIR_CPY_WRT(data, _2);
	ZEPHIR_CALL_PARENT(NULL, ice_mvc_model_ce, this_ptr, "__construct", &_5, 5, data);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	if (!(zephir_is_true(_6))) {
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_INIT_VAR(_8$$3);
		zephir_get_class_ns(_8$$3, this_ptr, 0 TSRMLS_CC);
		zephir_uncamelize(_7$$3, _8$$3, NULL  );
		zephir_update_property_this(this_ptr, SL("from"), _7$$3 TSRMLS_CC);
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
	if (!(zephir_is_true(_9))) {
		_10$$4 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_11$$4, _10$$4, "getid", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("primary"), _11$$4 TSRMLS_CC);
	}
	if ((zephir_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	if (zephir_is_true(filters)) {
		ZEPHIR_CALL_METHOD(&_12$$6, this_ptr, "loadone", NULL, 0, filters);
		zephir_check_call_status();
		if (!(zephir_is_true(_12$$6))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Not Found", "ice/mvc/model.zep", 70);
			return;
		}
	}
	if ((zephir_method_exists_ex(this_ptr, SS("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the id.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_Model, getId) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the id key depending on db driver.
 *
 * @return string
 */
PHP_METHOD(Ice_Mvc_Model, getIdKey) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Load one result to the current object.
 *
 * @param mixed filters
 * @param array options
 * @return this|false
 */
PHP_METHOD(Ice_Mvc_Model, loadOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *filters, *options_param = NULL, *result = NULL, *_0, *_1, *_2$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filters, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&result, _0, "findone", NULL, 0, _1, filters, options);
	zephir_check_call_status();
	if (zephir_is_true(result)) {
		ZEPHIR_CALL_METHOD(&_2$$3, result, "all", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, _2$$3);
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
 * @param array options
 * @return object Arr
 */
PHP_METHOD(Ice_Mvc_Model, load) {

	zend_object_iterator *_3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *_6$$4 = NULL;
	zval *filters, *options_param = NULL, *result = NULL, *instances = NULL, *data = NULL, *_0, *_1, *_2 = NULL, *_4$$4 = NULL, *_5$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filters, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&result, _0, "find", NULL, 0, _1, filters, options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(instances);
	array_init(instances);
	ZEPHIR_CALL_METHOD(&_2, result, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		_3$$3 = zephir_get_iterator(result TSRMLS_CC);
		_3$$3->funcs->rewind(_3$$3 TSRMLS_CC);
		for (;_3$$3->funcs->valid(_3$$3 TSRMLS_CC) == SUCCESS && !EG(exception); _3$$3->funcs->move_forward(_3$$3 TSRMLS_CC)) {
			{
				zval **ZEPHIR_TMP_ITERATOR_PTR;
				_3$$3->funcs->get_current_data(_3$$3, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
				ZEPHIR_CPY_WRT(data, (*ZEPHIR_TMP_ITERATOR_PTR));
			}
			ZEPHIR_INIT_NVAR(_4$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			zephir_get_called_class(_5$$4 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_6$$4);
			zephir_create_array(_6$$4, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_6$$4, ZEPHIR_GLOBAL(global_null));
			zephir_array_fast_append(_6$$4, data);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_4$$4, _5$$4, _6$$4 TSRMLS_CC);
			zephir_check_call_status();
			zephir_array_append(&instances, _4$$4, PH_SEPARATE, "ice/mvc/model.zep", 136);
		}
		_3$$3->funcs->dtor(_3$$3 TSRMLS_CC);
	}
	object_init_ex(return_value, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 5, instances);
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
 * @param array options
 * @return this|false
 */
PHP_METHOD(Ice_Mvc_Model, findOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *filters = NULL, *options_param = NULL, *result = NULL, *model = NULL, *instance = NULL;

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
	ZEPHIR_CALL_METHOD(&result, instance, "loadone", NULL, 0, filters, options);
	zephir_check_call_status();
	RETURN_CCTOR(result);

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
 * @param array options
 * @return object Arr
 */
PHP_METHOD(Ice_Mvc_Model, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *filters = NULL, *options_param = NULL, *result = NULL, *model = NULL, *instance = NULL;

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
	ZEPHIR_CALL_METHOD(&result, instance, "load", NULL, 0, filters, options);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

/**
 * Prepare fields for validation on create/update.
 *
 * @param mixed fields Fields to save or valid fields
 * @param booleat primary Keept primary keys
 * @return array
 */
PHP_METHOD(Ice_Mvc_Model, fields) {

	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool primary, _26;
	zval *fields = NULL, *primary_param = NULL, *_0, *_25, *_1$$5, _2$$5, *_3$$5 = NULL, *_5$$6, *_6$$6 = NULL, *_7$$7 = NULL, *_8$$7 = NULL, *_11$$9 = NULL, *_12$$9, *_13$$9 = NULL, *_14$$10, _15$$10, *_16$$10 = NULL, *_17$$11, *_18$$11 = NULL, *_19$$11, *_20$$11 = NULL, *_21$$12 = NULL, *_22$$12 = NULL, *_23$$12, *_24$$12 = NULL, *_27$$13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &primary_param);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		ZEPHIR_SEPARATE_PARAM(fields);
	}
	if (!primary_param) {
		primary = 1;
	} else {
		primary = zephir_get_boolval(primary_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	if (!(zephir_fast_count_int(_0 TSRMLS_CC))) {
		if (!(zephir_fast_count_int(fields TSRMLS_CC))) {
			ZEPHIR_CALL_METHOD(&fields, this_ptr, "all", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_1$$5);
			zephir_array_keys(_1$$5, fields TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_2$$5);
			ZVAL_STRING(&_2$$5, "is_string", 0);
			ZEPHIR_CALL_FUNCTION(&_3$$5, "array_filter", &_4, 8, _1$$5, &_2$$5);
			zephir_check_call_status();
			if (zephir_fast_count_int(_3$$5 TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_5$$6);
				ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "all", NULL, 0);
				zephir_check_call_status();
				zephir_fast_array_merge(_5$$6, &(_6$$6), &(fields) TSRMLS_CC);
				ZEPHIR_CPY_WRT(fields, _5$$6);
			} else {
				ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "all", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_8$$7, "array_flip", &_9, 9, fields);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&fields, "array_intersect_key", &_10, 10, _7$$7, _8$$7);
				zephir_check_call_status();
			}
		}
	} else {
		if (!(zephir_fast_count_int(fields TSRMLS_CC))) {
			ZEPHIR_CALL_METHOD(&_11$$9, this_ptr, "all", NULL, 0);
			zephir_check_call_status();
			_12$$9 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&_13$$9, "array_flip", &_9, 9, _12$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&fields, "array_intersect_key", &_10, 10, _11$$9, _13$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_14$$10);
			zephir_array_keys(_14$$10, fields TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_15$$10);
			ZVAL_STRING(&_15$$10, "is_string", 0);
			ZEPHIR_CALL_FUNCTION(&_16$$10, "array_filter", &_4, 8, _14$$10, &_15$$10);
			zephir_check_call_status();
			if (zephir_fast_count_int(_16$$10 TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_17$$11);
				ZEPHIR_CALL_METHOD(&_18$$11, this_ptr, "all", NULL, 0);
				zephir_check_call_status();
				zephir_fast_array_merge(_17$$11, &(_18$$11), &(fields) TSRMLS_CC);
				_19$$11 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_20$$11, "array_flip", &_9, 9, _19$$11);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&fields, "array_intersect_key", &_10, 10, _17$$11, _20$$11);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&_21$$12, this_ptr, "all", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_22$$12, "array_flip", &_9, 9, fields);
				zephir_check_call_status();
				_23$$12 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_24$$12, "array_flip", &_9, 9, _23$$12);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&fields, "array_intersect_key", &_10, 10, _21$$12, _22$$12, _24$$12);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_OBS_VAR(_25);
	zephir_read_property_this(&_25, this_ptr, SL("primary"), PH_NOISY_CC);
	_26 = Z_TYPE_P(_25) == IS_STRING;
	if (_26) {
		_26 = !primary;
	}
	if (_26) {
		_27$$13 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
		zephir_array_unset(&fields, _27$$13, PH_SEPARATE);
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

	zend_bool _8$$4;
	zval *_5, *_29, *_32, *_41;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, *extra = NULL, *status = NULL, *_0 = NULL, *_1 = NULL, *_4, *_6, *_28, *_30, *_31, *_33, *_34, *_35 = NULL, *_40, *_2$$3 = NULL, *_3$$3 = NULL, *_7$$4, *_9$$4, *_11$$4, *_12$$4, *_13$$4, *_14$$4, *_15$$4, *_16$$4, *_17$$4, *_18$$4 = NULL, *_19$$4, *_20$$4 = NULL, *_21$$4, *_22$$4 = NULL, *_10$$5, *_23$$6, *_24$$6, *_25$$6, *_26$$6 = NULL, *_27$$6 = NULL, *_36$$8, *_37$$8 = NULL, *_38$$8, *_39$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fields", NULL, 0, fields, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, _0);
	zephir_check_call_status();
	if (zephir_is_true(extra)) {
		ZEPHIR_CALL_METHOD(NULL, extra, "validate", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, extra, "getmessages", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, _2$$3, "all", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("messages"), _3$$3 TSRMLS_CC);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_5, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "model.before.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _4, "applyhook", NULL, 0, _1, _5);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
	if (zephir_fast_count_int(_6 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_7$$4);
		zephir_read_property_this(&_7$$4, this_ptr, SL("validation"), PH_NOISY_CC);
		_8$$4 = Z_TYPE_P(_7$$4) == IS_OBJECT;
		if (_8$$4) {
			ZEPHIR_OBS_VAR(_9$$4);
			zephir_read_property_this(&_9$$4, this_ptr, SL("validation"), PH_NOISY_CC);
			_8$$4 = zephir_instance_of_ev(_9$$4, ice_validation_ce TSRMLS_CC);
		}
		if (!(_8$$4)) {
			ZEPHIR_INIT_VAR(_10$$5);
			object_init_ex(_10$$5, ice_validation_ce);
			ZEPHIR_CALL_METHOD(NULL, _10$$5, "__construct", NULL, 11);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("validation"), _10$$5 TSRMLS_CC);
		}
		_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		_12$$4 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _11$$4, "rules", NULL, 0, _12$$4);
		zephir_check_call_status();
		_13$$4 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		_14$$4 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _13$$4, "setfilters", NULL, 0, _14$$4);
		zephir_check_call_status();
		_15$$4 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		_16$$4 = zephir_fetch_nproperty_this(this_ptr, SL("labels"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _15$$4, "setlabels", NULL, 0, _16$$4);
		zephir_check_call_status();
		_17$$4 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_18$$4, this_ptr, "getdata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _17$$4, "validate", NULL, 0, _18$$4);
		zephir_check_call_status();
		_19$$4 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_20$$4, _19$$4, "getvalues", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, _20$$4);
		zephir_check_call_status();
		_21$$4 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_22$$4, _21$$4, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_22$$4))) {
			ZEPHIR_INIT_VAR(_23$$6);
			_24$$6 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
			_25$$6 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_26$$6, _25$$6, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_27$$6, _26$$6, "all", NULL, 0);
			zephir_check_call_status();
			zephir_fast_array_merge(_23$$6, &(_24$$6), &(_27$$6) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("messages"), _23$$6 TSRMLS_CC);
		}
	}
	_28 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_29);
	zephir_create_array(_29, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_29, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "model.after.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _28, "applyhook", NULL, 0, _1, _29);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_30 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
	if (zephir_fast_count_int(_30 TSRMLS_CC)) {
		RETURN_MM_BOOL(0);
	}
	_31 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_32);
	zephir_create_array(_32, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_32, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "model.before.create", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _31, "applyhook", NULL, 0, _1, _32);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_33 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_34 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, _33, "insert", NULL, 0, _34, _35);
	zephir_check_call_status();
	if (zephir_is_true(status)) {
		_36$$8 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_37$$8, _36$$8, "getid", NULL, 0);
		zephir_check_call_status();
		_38$$8 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_39$$8, _38$$8, "getlastinsertid", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, _37$$8, _39$$8);
		zephir_check_call_status();
	}
	_40 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_41);
	zephir_create_array(_41, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_41, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "model.after.create", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _40, "applyhook", NULL, 0, _1, _41);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
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

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool _18;
	zval *_15, *_32, *_35, *_41;
	zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, *extra = NULL, *data = NULL, *status = NULL, *primary = NULL, *key = NULL, *_0, *_10 = NULL, *_14, *_16 = NULL, *_17, *_19, *_31, *_33, *_34, *_36, *_37, *_38 = NULL, *_39 = NULL, *_40, *_1$$3, **_4$$3, *_5$$4 = NULL, *_7$$5, *_8$$5 = NULL, *_9$$5, *_12$$6 = NULL, *_13$$6 = NULL, *_20$$7, *_21$$7 = NULL, *_22$$7, *_23$$7 = NULL, *_24$$7, *_25$$7 = NULL, *_26$$8, *_27$$8, *_28$$8, *_29$$8 = NULL, *_30$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&data, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(primary);
	array_init(primary);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("primary"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
		zephir_is_iterable(_1$$3, &_3$$3, &_2$$3, 0, 0, "ice/mvc/model.zep", 335);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HVALUE(key, _4$$3);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "get", &_6, 0, key);
			zephir_check_call_status();
			zephir_array_update_zval(&primary, key, &_5$$4, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_INIT_NVAR(primary);
		zephir_create_array(primary, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_7$$5);
		zephir_read_property_this(&_7$$5, this_ptr, SL("primary"), PH_NOISY_CC);
		_9$$5 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "get", &_6, 0, _9$$5);
		zephir_check_call_status();
		zephir_array_update_zval(&primary, _7$$5, &_8$$5, PH_COPY);
	}
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "fields", &_11, 0, fields);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, _10);
	zephir_check_call_status();
	if (zephir_is_true(extra)) {
		ZEPHIR_CALL_METHOD(NULL, extra, "validate", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_12$$6, extra, "getmessages", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13$$6, _12$$6, "all", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("messages"), _13$$6 TSRMLS_CC);
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_15);
	zephir_create_array(_15, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_15, this_ptr);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_STRING(_16, "model.before.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _14, "applyhook", NULL, 0, _16, _15);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_17);
	zephir_read_property_this(&_17, this_ptr, SL("validation"), PH_NOISY_CC);
	_18 = Z_TYPE_P(_17) == IS_OBJECT;
	if (_18) {
		ZEPHIR_OBS_VAR(_19);
		zephir_read_property_this(&_19, this_ptr, SL("validation"), PH_NOISY_CC);
		_18 = zephir_instance_of_ev(_19, ice_validation_ce TSRMLS_CC);
	}
	if (_18) {
		_20$$7 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_21$$7, this_ptr, "getdata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _20$$7, "validate", NULL, 0, _21$$7);
		zephir_check_call_status();
		_22$$7 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_23$$7, _22$$7, "getvalues", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, _23$$7);
		zephir_check_call_status();
		_24$$7 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_25$$7, _24$$7, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_25$$7))) {
			ZEPHIR_INIT_VAR(_26$$8);
			_27$$8 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
			_28$$8 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_29$$8, _28$$8, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_30$$8, _29$$8, "all", NULL, 0);
			zephir_check_call_status();
			zephir_fast_array_merge(_26$$8, &(_27$$8), &(_30$$8) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("messages"), _26$$8 TSRMLS_CC);
		}
	}
	_31 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_32);
	zephir_create_array(_32, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_32, this_ptr);
	ZEPHIR_INIT_NVAR(_16);
	ZVAL_STRING(_16, "model.after.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _31, "applyhook", NULL, 0, _16, _32);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
	_33 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
	if (zephir_fast_count_int(_33 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, data);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_34 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_35);
	zephir_create_array(_35, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_35, this_ptr);
	ZEPHIR_INIT_NVAR(_16);
	ZVAL_STRING(_16, "model.before.update", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _34, "applyhook", NULL, 0, _16, _35);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
	_36 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_37 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_39, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_16);
	ZVAL_BOOL(_16, 0);
	ZEPHIR_CALL_METHOD(&_38, this_ptr, "fields", &_11, 0, _39, _16);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, _36, "update", NULL, 0, _37, primary, _38);
	zephir_check_call_status();
	if (!(zephir_is_true(status))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, data);
		zephir_check_call_status();
	}
	_40 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_41);
	zephir_create_array(_41, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_41, this_ptr);
	ZEPHIR_INIT_NVAR(_16);
	ZVAL_STRING(_16, "model.after.update", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _40, "applyhook", NULL, 0, _16, _41);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
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
	zval *fields = NULL, *extra = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "update", NULL, 0, fields, extra);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "create", NULL, 0, fields, extra);
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

	HashTable *_3$$4;
	HashPosition _2$$4;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, *key = NULL, *status = NULL, *_10, *_11, *_0$$3, *_1$$4, **_4$$4, *_5$$5 = NULL, *_7$$6, *_8$$6 = NULL, *_9$$6;

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
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_this(&_0$$3, this_ptr, SL("primary"), PH_NOISY_CC);
		if (Z_TYPE_P(_0$$3) == IS_ARRAY) {
			_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
			zephir_is_iterable(_1$$4, &_3$$4, &_2$$4, 0, 0, "ice/mvc/model.zep", 437);
			for (
			  ; zephir_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_3$$4, &_2$$4)
			) {
				ZEPHIR_GET_HVALUE(key, _4$$4);
				ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "get", &_6, 0, key);
				zephir_check_call_status();
				zephir_array_update_zval(&filters, key, &_5$$5, PH_COPY | PH_SEPARATE);
			}
		} else {
			ZEPHIR_INIT_NVAR(filters);
			zephir_create_array(filters, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(_7$$6);
			zephir_read_property_this(&_7$$6, this_ptr, SL("primary"), PH_NOISY_CC);
			_9$$6 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_8$$6, this_ptr, "get", &_6, 0, _9$$6);
			zephir_check_call_status();
			zephir_array_update_zval(&filters, _7$$6, &_8$$6, PH_COPY);
		}
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&status, _10, "remove", NULL, 0, _11, filters);
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

	zend_bool _7$$5, _13$$8;
	HashTable *_3$$4;
	HashPosition _2$$4;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, *key = NULL, *_0$$3, *_1$$4, **_4$$4, *_5$$5 = NULL, *_8$$5 = NULL, *_10$$6 = NULL, *_11$$8 = NULL, *_12$$8, *_14$$8 = NULL, *_15$$8, *_16$$9, *_17$$9 = NULL, *_18$$9;

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
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_this(&_0$$3, this_ptr, SL("primary"), PH_NOISY_CC);
		if (Z_TYPE_P(_0$$3) == IS_ARRAY) {
			_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
			zephir_is_iterable(_1$$4, &_3$$4, &_2$$4, 0, 0, "ice/mvc/model.zep", 468);
			for (
			  ; zephir_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_3$$4, &_2$$4)
			) {
				ZEPHIR_GET_HVALUE(key, _4$$4);
				ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "has", &_6, 0, key);
				zephir_check_call_status();
				_7$$5 = zephir_is_true(_5$$5);
				if (_7$$5) {
					ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "get", &_9, 0, key);
					zephir_check_call_status();
					_7$$5 = zephir_is_true(_8$$5);
				}
				if (_7$$5) {
					ZEPHIR_CALL_METHOD(&_10$$6, this_ptr, "get", &_9, 0, key);
					zephir_check_call_status();
					zephir_array_update_zval(&filters, key, &_10$$6, PH_COPY | PH_SEPARATE);
				} else {
					RETURN_MM_BOOL(0);
				}
			}
		} else {
			_12$$8 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_11$$8, this_ptr, "has", &_6, 0, _12$$8);
			zephir_check_call_status();
			_13$$8 = zephir_is_true(_11$$8);
			if (_13$$8) {
				_15$$8 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_14$$8, this_ptr, "get", &_9, 0, _15$$8);
				zephir_check_call_status();
				_13$$8 = zephir_is_true(_14$$8);
			}
			if (_13$$8) {
				ZEPHIR_INIT_NVAR(filters);
				zephir_create_array(filters, 1, 0 TSRMLS_CC);
				ZEPHIR_OBS_VAR(_16$$9);
				zephir_read_property_this(&_16$$9, this_ptr, SL("primary"), PH_NOISY_CC);
				_18$$9 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_17$$9, this_ptr, "get", &_9, 0, _18$$9);
				zephir_check_call_status();
				zephir_array_update_zval(&filters, _16$$9, &_17$$9, PH_COPY);
			} else {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_RETURN_CALL_SELF("findone", NULL, 0, filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the last Db error.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_Model, getError) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "geterror", NULL, 0);
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
	zephir_create_array(_0, 5, 0 TSRMLS_CC);
	add_assoc_long_ex(_0, SS("type"), 1);
	zephir_array_update_string(&_0, SL("field"), &field, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referenceModel"), &referenceModel, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedField"), &referencedField, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("options"), &options, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("relations"), alias, _0 TSRMLS_CC);
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
	zephir_create_array(_0, 5, 0 TSRMLS_CC);
	add_assoc_long_ex(_0, SS("type"), 2);
	zephir_array_update_string(&_0, SL("field"), &field, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referenceModel"), &referenceModel, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedField"), &referencedField, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("options"), &options, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("relations"), alias, _0 TSRMLS_CC);
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
	zephir_create_array(_0, 5, 0 TSRMLS_CC);
	add_assoc_long_ex(_0, SS("type"), 3);
	zephir_array_update_string(&_0, SL("field"), &field, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referenceModel"), &referenceModel, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedField"), &referencedField, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("options"), &options, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("relations"), alias, _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get related models.
 *
 * @param string alias
 * @param array filters
 * @param array options
 */
PHP_METHOD(Ice_Mvc_Model, getRelated) {

	zend_class_entry *_14$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, *options = NULL, *_7$$4, *_9$$4, *_12$$6;
	zval *alias_param = NULL, *filters_param = NULL, *options_param = NULL, *relation = NULL, *field = NULL, *referenceModel = NULL, *referencedField = NULL, *from = NULL, *result = NULL, *_0, *_4, *_5, *_1$$3, _2$$3, *_3$$3 = NULL, *_6$$4, *_8$$4, *_10$$4 = NULL, *_11$$6, *_13$$6;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &alias_param, &filters_param, &options_param);

	zephir_get_strval(alias, alias_param);
	if (!filters_param) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	} else {
		zephir_get_arrval(filters, filters_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_OBS_VAR(relation);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("relations"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&relation, _0, alias, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "Alias '%s' not found", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 12, &_2$$3, alias);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 13, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "ice/mvc/model.zep", 619 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(field);
	zephir_array_isset_string_fetch(&field, relation, SS("field"), 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(referenceModel);
	zephir_array_isset_string_fetch(&referenceModel, relation, SS("referenceModel"), 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(referencedField);
	zephir_array_isset_string_fetch(&referencedField, relation, SS("referencedField"), 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_get_class_ns(_4, referenceModel, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(from);
	zephir_uncamelize(from, _4, NULL  );
	zephir_array_fetch_string(&_5, relation, SL("type"), PH_NOISY | PH_READONLY, "ice/mvc/model.zep", 628 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_5, 1) || ZEPHIR_IS_LONG(_5, 2)) {
			ZEPHIR_INIT_VAR(_6$$4);
			ZEPHIR_INIT_VAR(_7$$4);
			zephir_create_array(_7$$4, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(_8$$4);
			zephir_read_property_zval(&_8$$4, this_ptr, field, PH_NOISY_CC);
			zephir_array_update_zval(&_7$$4, referencedField, &_8$$4, PH_COPY);
			zephir_fast_array_merge(_6$$4, &(filters), &(_7$$4) TSRMLS_CC);
			ZEPHIR_CPY_WRT(filters, _6$$4);
			ZEPHIR_INIT_VAR(_9$$4);
			zephir_create_array(_9$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_9$$4, filters);
			ZEPHIR_INIT_VAR(result);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(result, referenceModel, _9$$4 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_10$$4, result, "count", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_10$$4))) {
				RETURN_MM_BOOL(0);
			}
			RETURN_CCTOR(result);
		}
		if (ZEPHIR_IS_LONG(_5, 3)) {
			ZEPHIR_INIT_VAR(_11$$6);
			ZEPHIR_INIT_VAR(_12$$6);
			zephir_create_array(_12$$6, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(_13$$6);
			zephir_read_property_zval(&_13$$6, this_ptr, field, PH_NOISY_CC);
			zephir_array_update_zval(&_12$$6, referencedField, &_13$$6, PH_COPY);
			zephir_fast_array_merge(_11$$6, &(filters), &(_12$$6) TSRMLS_CC);
			ZEPHIR_CPY_WRT(filters, _11$$6);
			_14$$6 = zephir_fetch_class(referenceModel TSRMLS_CC);
			ZEPHIR_CALL_CE_STATIC(&result, _14$$6, "find", NULL, 0, filters, options);
			zephir_check_call_status();
			RETURN_CCTOR(result);
		}
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Get rules for validation.
 *
 * <pre><code>
 *  // Get rules for one field
 *  $this->getRules('password');
 *  
 *  // Get rules for multiple fields
 *  $this->getRules(['fullName', 'about']);
 *  
 *  // Get all rules
 *  $this->getRules();
 * </code></pre>
 *
 * @param mixed fields
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_Model, getRules) {

	HashTable *_3$$4;
	HashPosition _2$$4;
	zend_bool _0$$3;
	zval *fields = NULL, *rules = NULL, *field = NULL, *_1$$3, **_4$$4, *_5$$5, *_6$$6, *_7$$6, *_8$$7, *_9$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fields);

	if (!fields) {
		fields = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(fields)) {
		_0$$3 = Z_TYPE_P(fields) == IS_STRING;
		if (_0$$3) {
			_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
			_0$$3 = zephir_array_isset(_1$$3, fields);
		}
		if (Z_TYPE_P(fields) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(rules);
			array_init(rules);
			zephir_is_iterable(fields, &_3$$4, &_2$$4, 0, 0, "ice/mvc/model.zep", 679);
			for (
			  ; zephir_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_3$$4, &_2$$4)
			) {
				ZEPHIR_GET_HVALUE(field, _4$$4);
				_5$$5 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
				if (zephir_array_isset(_5$$5, field)) {
					_6$$6 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
					zephir_array_fetch(&_7$$6, _6$$6, field, PH_NOISY | PH_READONLY, "ice/mvc/model.zep", 675 TSRMLS_CC);
					zephir_array_update_zval(&rules, field, &_7$$6, PH_COPY | PH_SEPARATE);
				}
			}
			RETURN_CCTOR(rules);
		} else if (_0$$3) {
			_8$$7 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
			zephir_array_fetch(&_9$$7, _8$$7, fields, PH_NOISY | PH_READONLY, "ice/mvc/model.zep", 681 TSRMLS_CC);
			RETURN_CTOR(_9$$7);
		}
	}
	RETURN_MM_MEMBER(this_ptr, "rules");

}

/**
 * Set rules for validation.
 *
 * @param array rules
 * @param boolean merge
 */
PHP_METHOD(Ice_Mvc_Model, setRules) {

	zend_bool merge;
	zval *rules_param = NULL, *merge_param = NULL, *_0$$3, *_1$$3;
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
		ZEPHIR_INIT_VAR(_0$$3);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
		zephir_fast_array_merge(_0$$3, &(_1$$3), &(rules) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("rules"), _0$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("rules"), rules TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Serialize the model's data.
 *
 * @return string
 */
PHP_METHOD(Ice_Mvc_Model, serialize) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "serialize", NULL, 14, _0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 15, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserialize and set the data.
 */
PHP_METHOD(Ice_Mvc_Model, unserialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *_0 = NULL, *_1 = NULL;
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "base64_decode", NULL, 16, data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "unserialize", NULL, 17, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("data"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic call to get related models.
 */
PHP_METHOD(Ice_Mvc_Model, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, *filters = NULL, *options = NULL, *_3, _4, *_5 = NULL, *_0$$3, _1$$3, *_2$$3;
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
		ZEPHIR_OBS_VAR(options);
		zephir_array_isset_long_fetch(&options, arguments, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, 3);
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_substr(_2$$3, method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_ucfirst(_0$$3, _2$$3);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelated", NULL, 0, _0$$3, filters, options);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, ice_exception_ce);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "The method '%s' doesn't exist", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 12, &_4, method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 13, _5);
	zephir_check_call_status();
	zephir_throw_exception_debug(_3, "ice/mvc/model.zep", 736 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

zend_object_value zephir_init_properties_Ice_Mvc_Model(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_6, *_8, *_10, *_12, *_1$$3, *_3$$4, *_5$$5, *_7$$6, *_9$$7, *_11$$8, *_13$$9;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("messages"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("rules"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("labels"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(this_ptr, SL("labels"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("relations"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(this_ptr, SL("relations"), _7$$6 TSRMLS_CC);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
		if (Z_TYPE_P(_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(_9$$7);
			array_init(_9$$7);
			zephir_update_property_this(this_ptr, SL("fields"), _9$$7 TSRMLS_CC);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (Z_TYPE_P(_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(_11$$8);
			array_init(_11$$8);
			zephir_update_property_this(this_ptr, SL("data"), _11$$8 TSRMLS_CC);
		}
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
		if (Z_TYPE_P(_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(_13$$9);
			array_init(_13$$9);
			zephir_update_property_this(this_ptr, SL("filters"), _13$$9 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

