
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
#include "ext/spl/spl_exceptions.h"


/**
 * Model connects business objects and database tables to create a persistable domain model where logic and data are
 * presented in one wrapping (ORM & ODM).
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Model) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, Model, ice, mvc_model, ice_arr_ce, ice_mvc_model_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_model_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_model_ce, SL("service"), "db", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("primary"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_mvc_model_ce, SL("autoincrement"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("fields"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("validation"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("relations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("labels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("rules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_model_ce, SL("isLoaded"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_mvc_model_ce->create_object = zephir_init_properties_Ice_Mvc_Model;
	zend_declare_class_constant_long(ice_mvc_model_ce, SL("BELONGS_TO"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_model_ce, SL("HAS_ONE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_model_ce, SL("HAS_MANY"), 3 TSRMLS_CC);

	zend_class_implements(ice_mvc_model_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Model, getDi) {

	

	RETURN_MEMBER(getThis(), "di");

}

PHP_METHOD(Ice_Mvc_Model, getDb) {

	

	RETURN_MEMBER(getThis(), "db");

}

PHP_METHOD(Ice_Mvc_Model, setFrom) {

	zval *from;

	zephir_fetch_params(0, 1, 0, &from);



	zephir_update_property_this(getThis(), SL("from"), from TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, setPrimary) {

	zval *primary;

	zephir_fetch_params(0, 1, 0, &primary);



	zephir_update_property_this(getThis(), SL("primary"), primary TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, getPrimary) {

	

	RETURN_MEMBER(getThis(), "primary");

}

PHP_METHOD(Ice_Mvc_Model, setAutoincrement) {

	zval *autoincrement;

	zephir_fetch_params(0, 1, 0, &autoincrement);



	zephir_update_property_this(getThis(), SL("autoincrement"), autoincrement TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, setFilters) {

	zval *filters;

	zephir_fetch_params(0, 1, 0, &filters);



	zephir_update_property_this(getThis(), SL("filters"), filters TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, getFilters) {

	

	RETURN_MEMBER(getThis(), "filters");

}

PHP_METHOD(Ice_Mvc_Model, setFields) {

	zval *fields;

	zephir_fetch_params(0, 1, 0, &fields);



	zephir_update_property_this(getThis(), SL("fields"), fields TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, getFields) {

	

	RETURN_MEMBER(getThis(), "fields");

}

PHP_METHOD(Ice_Mvc_Model, setValidation) {

	zval *validation;

	zephir_fetch_params(0, 1, 0, &validation);



	zephir_update_property_this(getThis(), SL("validation"), validation TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, getValidation) {

	

	RETURN_MEMBER(getThis(), "validation");

}

PHP_METHOD(Ice_Mvc_Model, getRelations) {

	

	RETURN_MEMBER(getThis(), "relations");

}

PHP_METHOD(Ice_Mvc_Model, setLabels) {

	zval *labels;

	zephir_fetch_params(0, 1, 0, &labels);



	zephir_update_property_this(getThis(), SL("labels"), labels TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, getMessages) {

	

	RETURN_MEMBER(getThis(), "messages");

}

PHP_METHOD(Ice_Mvc_Model, setMessages) {

	zval *messages;

	zephir_fetch_params(0, 1, 0, &messages);



	zephir_update_property_this(getThis(), SL("messages"), messages TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Model constructor. Fetch Di and set it as a property.
 *
 * @param mixed filters
 * @param array data
 * @param array options Options to limit/group/orderby results when filters is not null
 */
PHP_METHOD(Ice_Mvc_Model, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL;
	zval *data = NULL, *options = NULL;
	zval *filters = NULL, *data_param = NULL, *options_param = NULL, *di = NULL, *_1 = NULL, *_2, *_3, *_4, *_5 = NULL, *_7, *_10, *_8$$3, *_9$$3, *_11$$4, *_12$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &filters, &data_param, &options_param);

	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 1);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("di"), di TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("service"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, di, "get", NULL, 0, _2);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("db"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_5, "array_fill_keys", NULL, 7, _4, ZEPHIR_GLOBAL(global_null));
	zephir_check_call_status();
	zephir_fast_array_merge(_3, &(_5), &(data) TSRMLS_CC);
	ZEPHIR_CPY_WRT(data, _3);
	ZEPHIR_CALL_PARENT(NULL, ice_mvc_model_ce, getThis(), "__construct", &_6, 5, data);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	if (!(zephir_is_true(_7))) {
		ZEPHIR_INIT_VAR(_8$$3);
		ZEPHIR_INIT_VAR(_9$$3);
		zephir_get_class_ns(_9$$3, this_ptr, 0 TSRMLS_CC);
		zephir_uncamelize(_8$$3, _9$$3, NULL  );
		zephir_update_property_this(getThis(), SL("from"), _8$$3 TSRMLS_CC);
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
	if (!(zephir_is_true(_10))) {
		_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_12$$4, _11$$4, "getid", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("primary"), _12$$4 TSRMLS_CC);
	}
	if ((zephir_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	if (zephir_is_true(filters)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadone", NULL, 0, filters, options);
		zephir_check_call_status();
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
	zend_long ZEPHIR_LAST_CALL_STATUS;

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
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the date time object.
 *
 * @param mixed key
 * @param boolean model
 * @return object
 */
PHP_METHOD(Ice_Mvc_Model, getDateTime) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, *model = NULL, *value = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &model);

	if (!model) {
		model = ZEPHIR_GLOBAL(global_false);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&value, this_ptr, "get", NULL, 0, key);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(value, key);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "getdatetime", NULL, 0, value, model);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Load one result to the current object.
 *
 * @param mixed filters
 * @param array options Options to limit/group/orderby results
 * @return this|false
 */
PHP_METHOD(Ice_Mvc_Model, loadOne) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *filters, *options_param = NULL, *result = NULL, *_0, *_1, *_2$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filters, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	if (ZEPHIR_IS_EMPTY(filters)) {
		RETURN_MM_BOOL(0);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&result, _0, "findone", NULL, 0, _1, filters, options);
	zephir_check_call_status();
	if (zephir_is_true(result)) {
		ZEPHIR_CALL_METHOD(&_2$$4, result, "all", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, _2$$4);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_this(getThis(), SL("isLoaded"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("isLoaded"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		RETURN_THIS();
	} else {
		if (0) {
			zephir_update_property_this(getThis(), SL("isLoaded"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("isLoaded"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_MM_RESTORE();

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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *_5$$4 = NULL;
	zval *filters, *options_param = NULL, *result = NULL, *instances = NULL, *data = NULL, *model = NULL, *_0, *_1, *_2 = NULL, *_4$$4 = NULL;

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
			zephir_get_called_class(_4$$4 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_5$$4);
			zephir_create_array(_5$$4, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_5$$4, ZEPHIR_GLOBAL(global_null));
			zephir_array_fast_append(_5$$4, data);
			ZEPHIR_INIT_NVAR(model);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(model, _4$$4, _5$$4 TSRMLS_CC);
			zephir_check_call_status();
			if (1) {
				zephir_update_property_zval(model, SL("isLoaded"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_zval(model, SL("isLoaded"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
			zephir_array_append(&instances, model, PH_SEPARATE, "ice/mvc/model.zep", 167);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *_1;
	zval *filters = NULL, *options_param = NULL, *model = NULL, *_0, *_2 = NULL, *_3;

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


	ZEPHIR_INIT_VAR(_0);
	zephir_get_called_class(_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(_1, filters);
	zephir_array_fast_append(_1, ZEPHIR_GLOBAL(global_null));
	zephir_array_fast_append(_1, options);
	ZEPHIR_INIT_VAR(model);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(model, _0, _1 TSRMLS_CC);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, model, SL("isLoaded"), PH_NOISY_CC);
	if (zephir_is_true(_3)) {
		ZEPHIR_CPY_WRT(_2, model);
	} else {
		ZVAL_BOOL(_2, 0);
	}
	RETURN_CCTOR(_2);

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *filters = NULL, *options_param = NULL, *model = NULL, *_0;

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


	ZEPHIR_INIT_VAR(_0);
	zephir_get_called_class(_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(model);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(model, _0 TSRMLS_CC);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(model, "load", NULL, 0, filters, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepare fields for validation on create/update.
 *
 * @param mixed fields Fields to save or valid fields
 * @param boolean primary Keep primary key
 * @return array
 */
PHP_METHOD(Ice_Mvc_Model, fields) {

	HashTable *_32$$13, *_28$$14;
	HashPosition _31$$13, _27$$14;
	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool primary;
	zval *fields = NULL, *primary_param = NULL, *_0, *_1$$5, _2$$5, *_3$$5 = NULL, *_5$$6, *_6$$6 = NULL, *_7$$7 = NULL, *_8$$7 = NULL, *_11$$9 = NULL, *_12$$9, *_13$$9 = NULL, *_14$$10, _15$$10, *_16$$10 = NULL, *_17$$11, *_18$$11 = NULL, *_19$$11, *_20$$11 = NULL, *_21$$12 = NULL, *_22$$12 = NULL, *_23$$12, *_24$$12 = NULL, *key$$13 = NULL, *keys$$13 = NULL, *_25$$13, **_33$$13, *_26$$14, **_29$$14, *_30$$16;

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
	if (ZEPHIR_IS_EMPTY(_0)) {
		if (ZEPHIR_IS_EMPTY(fields)) {
			ZEPHIR_CALL_METHOD(&fields, this_ptr, "all", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_1$$5);
			zephir_array_keys(_1$$5, fields TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_2$$5);
			ZVAL_STRING(&_2$$5, "is_string", 0);
			ZEPHIR_CALL_FUNCTION(&_3$$5, "array_filter", &_4, 8, _1$$5, &_2$$5);
			zephir_check_call_status();
			if (zephir_is_true(_3$$5)) {
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
		if (ZEPHIR_IS_EMPTY(fields)) {
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
			if (zephir_is_true(_16$$10)) {
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
	if (!(primary)) {
		ZEPHIR_INIT_VAR(keys$$13);
		array_init(keys$$13);
		ZEPHIR_OBS_VAR(_25$$13);
		zephir_read_property_this(&_25$$13, this_ptr, SL("primary"), PH_NOISY_CC);
		if (Z_TYPE_P(_25$$13) == IS_ARRAY) {
			_26$$14 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
			zephir_is_iterable(_26$$14, &_28$$14, &_27$$14, 0, 0, "ice/mvc/model.zep", 273);
			for (
			  ; zend_hash_get_current_data_ex(_28$$14, (void**) &_29$$14, &_27$$14) == SUCCESS
			  ; zend_hash_move_forward_ex(_28$$14, &_27$$14)
			) {
				ZEPHIR_GET_HVALUE(key$$13, _29$$14);
				zephir_array_append(&keys$$13, key$$13, PH_SEPARATE, "ice/mvc/model.zep", 271);
			}
		} else {
			_30$$16 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
			zephir_array_append(&keys$$13, _30$$16, PH_SEPARATE, "ice/mvc/model.zep", 274);
		}
		zephir_is_iterable(keys$$13, &_32$$13, &_31$$13, 0, 0, "ice/mvc/model.zep", 280);
		for (
		  ; zend_hash_get_current_data_ex(_32$$13, (void**) &_33$$13, &_31$$13) == SUCCESS
		  ; zend_hash_move_forward_ex(_32$$13, &_31$$13)
		) {
			ZEPHIR_GET_HVALUE(key$$13, _33$$13);
			zephir_array_unset(&fields, key$$13, PH_SEPARATE);
		}
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
 * @return null|boolean If validate fail return null, else return insert status
 */
PHP_METHOD(Ice_Mvc_Model, create) {

	zend_bool _9, _11, _14$$5;
	zval *_7, *_37, *_40, *_50;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, *extra = NULL, *status = NULL, *_0 = NULL, *_1, *_2 = NULL, *_6, *_8, *_10, *_12, *_36, *_38, *_39, *_41, *_42, *_43 = NULL, *_49, *_3$$3 = NULL, *_4$$3 = NULL, *_5$$4, *_13$$5, *_15$$5, *_17$$5, *_18$$5 = NULL, *_21$$5, *_22$$5, *_23$$5, *_24$$5, *_25$$5, *_26$$5 = NULL, *_27$$5, *_28$$5 = NULL, *_29$$5, *_30$$5 = NULL, *_16$$6, *_19$$7, *_20$$7, *_31$$8, *_32$$8, *_33$$8, *_34$$8 = NULL, *_35$$8 = NULL, *_44$$10, *_45$$11, *_46$$11 = NULL, *_47$$11, *_48$$11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("autoincrement"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, !zephir_is_true(_1));
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fields", NULL, 0, fields, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, _0);
	zephir_check_call_status();
	if (zephir_is_true(extra)) {
		ZEPHIR_CALL_METHOD(NULL, extra, "validate", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, extra, "getmessages", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, _3$$3, "all", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("messages"), _4$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_5$$4);
		array_init(_5$$4);
		zephir_update_property_this(getThis(), SL("messages"), _5$$4 TSRMLS_CC);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_7, this_ptr);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "model.before.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _6, "applyhook", NULL, 0, _2, _7, this_ptr);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
	_9 = !(ZEPHIR_IS_EMPTY(_8));
	if (!(_9)) {
		ZEPHIR_OBS_VAR(_10);
		zephir_read_property_this(&_10, this_ptr, SL("validation"), PH_NOISY_CC);
		_11 = Z_TYPE_P(_10) == IS_OBJECT;
		if (_11) {
			ZEPHIR_OBS_VAR(_12);
			zephir_read_property_this(&_12, this_ptr, SL("validation"), PH_NOISY_CC);
			_11 = zephir_instance_of_ev(_12, ice_validation_ce TSRMLS_CC);
		}
		_9 = _11;
	}
	if (_9) {
		ZEPHIR_OBS_VAR(_13$$5);
		zephir_read_property_this(&_13$$5, this_ptr, SL("validation"), PH_NOISY_CC);
		_14$$5 = Z_TYPE_P(_13$$5) == IS_OBJECT;
		if (_14$$5) {
			ZEPHIR_OBS_VAR(_15$$5);
			zephir_read_property_this(&_15$$5, this_ptr, SL("validation"), PH_NOISY_CC);
			_14$$5 = zephir_instance_of_ev(_15$$5, ice_validation_ce TSRMLS_CC);
		}
		if (!(_14$$5)) {
			ZEPHIR_INIT_VAR(_16$$6);
			object_init_ex(_16$$6, ice_validation_ce);
			ZEPHIR_CALL_METHOD(NULL, _16$$6, "__construct", NULL, 11);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("validation"), _16$$6 TSRMLS_CC);
		}
		_17$$5 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_18$$5, _17$$5, "getrules", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_18$$5))) {
			_19$$7 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
			_20$$7 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _19$$7, "rules", NULL, 0, _20$$7);
			zephir_check_call_status();
		}
		_21$$5 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		_22$$5 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _21$$5, "setfilters", NULL, 0, _22$$5);
		zephir_check_call_status();
		_23$$5 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		_24$$5 = zephir_fetch_nproperty_this(this_ptr, SL("labels"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _23$$5, "setlabels", NULL, 0, _24$$5);
		zephir_check_call_status();
		_25$$5 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_26$$5, this_ptr, "getdata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _25$$5, "validate", NULL, 0, _26$$5);
		zephir_check_call_status();
		_27$$5 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_28$$5, _27$$5, "getvalues", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, _28$$5);
		zephir_check_call_status();
		_29$$5 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_30$$5, _29$$5, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_30$$5))) {
			ZEPHIR_INIT_VAR(_31$$8);
			_32$$8 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
			_33$$8 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_34$$8, _33$$8, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_35$$8, _34$$8, "all", NULL, 0);
			zephir_check_call_status();
			zephir_fast_array_merge(_31$$8, &(_32$$8), &(_35$$8) TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("messages"), _31$$8 TSRMLS_CC);
		}
	}
	_36 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_37);
	zephir_create_array(_37, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_37, this_ptr);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "model.after.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _36, "applyhook", NULL, 0, _2, _37, this_ptr);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_38 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_38))) {
		RETURN_MM_NULL();
	}
	_39 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_40);
	zephir_create_array(_40, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_40, this_ptr);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "model.before.create", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _39, "applyhook", NULL, 0, _2, _40, this_ptr);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_41 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_42 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_43, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, _41, "insert", NULL, 0, _42, _43);
	zephir_check_call_status();
	if (zephir_is_true(status)) {
		if (1) {
			zephir_update_property_this(getThis(), SL("isLoaded"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("isLoaded"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		_44$$10 = zephir_fetch_nproperty_this(this_ptr, SL("autoincrement"), PH_NOISY_CC);
		if (zephir_is_true(_44$$10)) {
			_45$$11 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_46$$11, _45$$11, "getid", NULL, 0);
			zephir_check_call_status();
			_47$$11 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_48$$11, _47$$11, "getlastinsertid", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, _46$$11, _48$$11);
			zephir_check_call_status();
		}
	}
	_49 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_50);
	zephir_create_array(_50, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_50, this_ptr);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "model.after.create", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _49, "applyhook", NULL, 0, _2, _50, this_ptr);
	zephir_check_temp_parameter(_2);
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
 * @return null|boolean If validate fail return null, else return update status
 */
PHP_METHOD(Ice_Mvc_Model, update) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool _19;
	zval *_16, *_33, *_36, *_44;
	zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, *extra = NULL, *data = NULL, *status = NULL, *primary = NULL, *key = NULL, *_0, *_10 = NULL, *_15, *_17 = NULL, *_18, *_20, *_32, *_34, *_35, *_37, *_38, *_39 = NULL, *_40 = NULL, *_41, *_43, *_1$$3, **_4$$3, *_5$$4 = NULL, *_7$$5, *_8$$5 = NULL, *_9$$5, *_12$$6 = NULL, *_13$$6 = NULL, *_14$$7, *_21$$8, *_22$$8 = NULL, *_23$$8, *_24$$8 = NULL, *_25$$8, *_26$$8 = NULL, *_27$$9, *_28$$9, *_29$$9, *_30$$9 = NULL, *_31$$9 = NULL, *_42$$12;

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
		zephir_is_iterable(_1$$3, &_3$$3, &_2$$3, 0, 0, "ice/mvc/model.zep", 386);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
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
		zephir_update_property_this(getThis(), SL("messages"), _13$$6 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_14$$7);
		array_init(_14$$7);
		zephir_update_property_this(getThis(), SL("messages"), _14$$7 TSRMLS_CC);
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_16);
	zephir_create_array(_16, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_16, this_ptr);
	ZEPHIR_INIT_VAR(_17);
	ZVAL_STRING(_17, "model.before.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _15, "applyhook", NULL, 0, _17, _16, this_ptr);
	zephir_check_temp_parameter(_17);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_18);
	zephir_read_property_this(&_18, this_ptr, SL("validation"), PH_NOISY_CC);
	_19 = Z_TYPE_P(_18) == IS_OBJECT;
	if (_19) {
		ZEPHIR_OBS_VAR(_20);
		zephir_read_property_this(&_20, this_ptr, SL("validation"), PH_NOISY_CC);
		_19 = zephir_instance_of_ev(_20, ice_validation_ce TSRMLS_CC);
	}
	if (_19) {
		_21$$8 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_22$$8, this_ptr, "getdata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _21$$8, "validate", NULL, 0, _22$$8);
		zephir_check_call_status();
		_23$$8 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_24$$8, _23$$8, "getvalues", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, _24$$8);
		zephir_check_call_status();
		_25$$8 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_26$$8, _25$$8, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_26$$8))) {
			ZEPHIR_INIT_VAR(_27$$9);
			_28$$9 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
			_29$$9 = zephir_fetch_nproperty_this(this_ptr, SL("validation"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_30$$9, _29$$9, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_31$$9, _30$$9, "all", NULL, 0);
			zephir_check_call_status();
			zephir_fast_array_merge(_27$$9, &(_28$$9), &(_31$$9) TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("messages"), _27$$9 TSRMLS_CC);
		}
	}
	_32 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_33);
	zephir_create_array(_33, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_33, this_ptr);
	ZEPHIR_INIT_NVAR(_17);
	ZVAL_STRING(_17, "model.after.validate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _32, "applyhook", NULL, 0, _17, _33, this_ptr);
	zephir_check_temp_parameter(_17);
	zephir_check_call_status();
	_34 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_34))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, data);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	_35 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_36);
	zephir_create_array(_36, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_36, this_ptr);
	ZEPHIR_INIT_NVAR(_17);
	ZVAL_STRING(_17, "model.before.update", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _35, "applyhook", NULL, 0, _17, _36, this_ptr);
	zephir_check_temp_parameter(_17);
	zephir_check_call_status();
	_37 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_38 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_40, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_41);
	zephir_read_property_this(&_41, this_ptr, SL("autoincrement"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_17);
	ZVAL_BOOL(_17, !zephir_is_true(_41));
	ZEPHIR_CALL_METHOD(&_39, this_ptr, "fields", &_11, 0, _40, _17);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, _37, "update", NULL, 0, _38, primary, _39);
	zephir_check_call_status();
	if (!(zephir_is_true(status))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, data);
		zephir_check_call_status();
	} else {
		if (1) {
			zephir_update_property_this(getThis(), SL("isLoaded"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("isLoaded"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(_42$$12);
		zephir_fast_array_merge(_42$$12, &(data), &(fields) TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, _42$$12);
		zephir_check_call_status();
	}
	_43 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_44);
	zephir_create_array(_44, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_44, this_ptr);
	ZEPHIR_INIT_NVAR(_17);
	ZVAL_STRING(_17, "model.after.update", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _43, "applyhook", NULL, 0, _17, _44, this_ptr);
	zephir_check_temp_parameter(_17);
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
 * @return null|boolean If validate fail return null, else return save status
 */
PHP_METHOD(Ice_Mvc_Model, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
 *  $status = (new Users())->delete(["status" => 0]);
 * </code></pre>
 *
 * @param filters
 * @return boolean
 */
PHP_METHOD(Ice_Mvc_Model, delete) {

	HashTable *_3$$4;
	HashPosition _2$$4;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
			zephir_is_iterable(_1$$4, &_3$$4, &_2$$4, 0, 0, "ice/mvc/model.zep", 494);
			for (
			  ; zend_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_3$$4, &_2$$4)
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
	ZEPHIR_CALL_METHOD(&status, _10, "delete", NULL, 0, _11, filters);
	zephir_check_call_status();
	if (zephir_is_true(status)) {
		if (0) {
			zephir_update_property_this(getThis(), SL("isLoaded"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("isLoaded"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_CCTOR(status);

}

/**
 * Get the record if exist.
 *
 * @param mixed filters
 * @return Model|false
 */
PHP_METHOD(Ice_Mvc_Model, exists) {

	zend_bool _10$$6, _16$$9;
	HashTable *_6$$5;
	HashPosition _5$$5;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, *key = NULL, *_0, *_1$$3 = NULL, *_2$$3, *_3$$4, *_4$$5, **_7$$5, *_8$$6 = NULL, *_11$$6 = NULL, *_13$$7 = NULL, *_14$$9 = NULL, *_15$$9, *_17$$9 = NULL, *_18$$9, *_19$$10, *_20$$10 = NULL, *_21$$10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filters);

	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	} else {
		ZEPHIR_SEPARATE_PARAM(filters);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("isLoaded"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		ZEPHIR_INIT_VAR(_1$$3);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("isLoaded"), PH_NOISY_CC);
		if (zephir_is_true(_2$$3)) {
			ZEPHIR_CPY_WRT(_1$$3, this_ptr);
		} else {
			ZVAL_BOOL(_1$$3, 0);
		}
		RETURN_CCTOR(_1$$3);
	}
	if (!(zephir_is_true(filters))) {
		ZEPHIR_INIT_NVAR(filters);
		array_init(filters);
		ZEPHIR_OBS_VAR(_3$$4);
		zephir_read_property_this(&_3$$4, this_ptr, SL("primary"), PH_NOISY_CC);
		if (Z_TYPE_P(_3$$4) == IS_ARRAY) {
			_4$$5 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
			zephir_is_iterable(_4$$5, &_6$$5, &_5$$5, 0, 0, "ice/mvc/model.zep", 534);
			for (
			  ; zend_hash_get_current_data_ex(_6$$5, (void**) &_7$$5, &_5$$5) == SUCCESS
			  ; zend_hash_move_forward_ex(_6$$5, &_5$$5)
			) {
				ZEPHIR_GET_HVALUE(key, _7$$5);
				ZEPHIR_CALL_METHOD(&_8$$6, this_ptr, "has", &_9, 0, key);
				zephir_check_call_status();
				_10$$6 = zephir_is_true(_8$$6);
				if (_10$$6) {
					ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "get", &_12, 0, key);
					zephir_check_call_status();
					_10$$6 = zephir_is_true(_11$$6);
				}
				if (_10$$6) {
					ZEPHIR_CALL_METHOD(&_13$$7, this_ptr, "get", &_12, 0, key);
					zephir_check_call_status();
					zephir_array_update_zval(&filters, key, &_13$$7, PH_COPY | PH_SEPARATE);
				} else {
					RETURN_MM_BOOL(0);
				}
			}
		} else {
			_15$$9 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_14$$9, this_ptr, "has", &_9, 0, _15$$9);
			zephir_check_call_status();
			_16$$9 = zephir_is_true(_14$$9);
			if (_16$$9) {
				_18$$9 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_17$$9, this_ptr, "get", &_12, 0, _18$$9);
				zephir_check_call_status();
				_16$$9 = zephir_is_true(_17$$9);
			}
			if (_16$$9) {
				ZEPHIR_INIT_NVAR(filters);
				zephir_create_array(filters, 1, 0 TSRMLS_CC);
				ZEPHIR_OBS_VAR(_19$$10);
				zephir_read_property_this(&_19$$10, this_ptr, SL("primary"), PH_NOISY_CC);
				_21$$10 = zephir_fetch_nproperty_this(this_ptr, SL("primary"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_20$$10, this_ptr, "get", &_12, 0, _21$$10);
				zephir_check_call_status();
				zephir_array_update_zval(&filters, _19$$10, &_20$$10, PH_COPY);
			} else {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "loadone", NULL, 0, filters);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;

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
 * @return object Model
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
	RETURN_THIS();

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
 * @return object Model
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
	RETURN_THIS();

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
 * @return object Model
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
	RETURN_THIS();

}

/**
 * Get related models.
 *
 * @param string alias
 * @param array filters
 * @param array options
 */
PHP_METHOD(Ice_Mvc_Model, getRelated) {

	zend_class_entry *_9$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, *options = NULL, *_6$$4;
	zval *alias_param = NULL, *filters_param = NULL, *options_param = NULL, *relation = NULL, *field = NULL, *referenceModel = NULL, *referencedField = NULL, *result = NULL, *_0, *_4, *_1$$3, _2$$3, *_3$$3 = NULL, *_5$$4, *_7$$4 = NULL, *_8$$6;
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
		zephir_throw_exception_debug(_1$$3, "ice/mvc/model.zep", 694 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(field);
	zephir_array_isset_string_fetch(&field, relation, SS("field"), 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(referenceModel);
	zephir_array_isset_string_fetch(&referenceModel, relation, SS("referenceModel"), 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(referencedField);
	zephir_array_isset_string_fetch(&referencedField, relation, SS("referencedField"), 0 TSRMLS_CC);
	zephir_array_fetch_string(&_4, relation, SL("type"), PH_NOISY | PH_READONLY, "ice/mvc/model.zep", 701 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_4, 1) || ZEPHIR_IS_LONG(_4, 2)) {
			ZEPHIR_OBS_VAR(_5$$4);
			zephir_read_property_zval(&_5$$4, this_ptr, field, PH_NOISY_CC);
			zephir_array_update_zval(&filters, referencedField, &_5$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(_6$$4);
			zephir_create_array(_6$$4, 3, 0 TSRMLS_CC);
			zephir_array_fast_append(_6$$4, filters);
			zephir_array_fast_append(_6$$4, ZEPHIR_GLOBAL(global_null));
			zephir_array_fast_append(_6$$4, options);
			ZEPHIR_INIT_VAR(result);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(result, referenceModel, _6$$4 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$4, result, "count", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_7$$4))) {
				RETURN_MM_BOOL(0);
			}
			RETURN_CCTOR(result);
		}
		if (ZEPHIR_IS_LONG(_4, 3)) {
			ZEPHIR_OBS_VAR(_8$$6);
			zephir_read_property_zval(&_8$$6, this_ptr, field, PH_NOISY_CC);
			zephir_array_update_zval(&filters, referencedField, &_8$$6, PH_COPY | PH_SEPARATE);
			_9$$6 = zephir_fetch_class(referenceModel TSRMLS_CC);
			ZEPHIR_CALL_CE_STATIC(&result, _9$$6, "find", NULL, 0, filters, options);
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
			zephir_is_iterable(fields, &_3$$4, &_2$$4, 0, 0, "ice/mvc/model.zep", 752);
			for (
			  ; zend_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_3$$4, &_2$$4)
			) {
				ZEPHIR_GET_HVALUE(field, _4$$4);
				_5$$5 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
				if (zephir_array_isset(_5$$5, field)) {
					_6$$6 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
					zephir_array_fetch(&_7$$6, _6$$6, field, PH_NOISY | PH_READONLY, "ice/mvc/model.zep", 748 TSRMLS_CC);
					zephir_array_update_zval(&rules, field, &_7$$6, PH_COPY | PH_SEPARATE);
				}
			}
			RETURN_CCTOR(rules);
		} else if (_0$$3) {
			_8$$7 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
			zephir_array_fetch(&_9$$7, _8$$7, fields, PH_NOISY | PH_READONLY, "ice/mvc/model.zep", 754 TSRMLS_CC);
			RETURN_CTOR(_9$$7);
		}
		RETURN_MM_NULL();
	}
	RETURN_MM_MEMBER(getThis(), "rules");

}

/**
 * Set rules for validation.
 *
 * @param array rules
 * @param boolean merge
 * @return object Model
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
		zephir_update_property_this(getThis(), SL("rules"), _0$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("rules"), rules TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Serialize the model's data.
 *
 * @return string
 */
PHP_METHOD(Ice_Mvc_Model, serialize) {

	zval *_0, *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

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
 * @return object Model
 */
PHP_METHOD(Ice_Mvc_Model, unserialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serialized, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serialized);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "base64_decode", NULL, 16, serialized);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "unserialize", NULL, 17, _0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("data"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Magic call to get related models.
 */
PHP_METHOD(Ice_Mvc_Model, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	zephir_throw_exception_debug(_3, "ice/mvc/model.zep", 815 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

zend_object_value zephir_init_properties_Ice_Mvc_Model(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_6, *_8, *_10, *_12, *_1$$3, *_3$$4, *_5$$5, *_7$$6, *_9$$7, *_11$$8, *_13$$9;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("messages"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("rules"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("labels"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(getThis(), SL("labels"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("relations"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(getThis(), SL("relations"), _7$$6 TSRMLS_CC);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
		if (Z_TYPE_P(_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(_9$$7);
			array_init(_9$$7);
			zephir_update_property_this(getThis(), SL("fields"), _9$$7 TSRMLS_CC);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (Z_TYPE_P(_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(_11$$8);
			array_init(_11$$8);
			zephir_update_property_this(getThis(), SL("data"), _11$$8 TSRMLS_CC);
		}
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
		if (Z_TYPE_P(_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(_13$$9);
			array_init(_13$$9);
			zephir_update_property_this(getThis(), SL("filters"), _13$$9 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

