
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
	zephir_declare_class_constant_long(ice_mvc_model_ce, SL("BELONGS_TO"), 1);

	zephir_declare_class_constant_long(ice_mvc_model_ce, SL("HAS_ONE"), 2);

	zephir_declare_class_constant_long(ice_mvc_model_ce, SL("HAS_MANY"), 3);

	zend_class_implements(ice_mvc_model_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Model, getDi) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "di");

}

PHP_METHOD(Ice_Mvc_Model, getDb) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "db");

}

PHP_METHOD(Ice_Mvc_Model, setFrom) {

	zval *from, from_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from_sub);

	zephir_fetch_params(0, 1, 0, &from);



	zephir_update_property_zval(this_ptr, SL("from"), from);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, setPrimary) {

	zval *primary, primary_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&primary_sub);

	zephir_fetch_params(0, 1, 0, &primary);



	zephir_update_property_zval(this_ptr, SL("primary"), primary);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, getPrimary) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "primary");

}

PHP_METHOD(Ice_Mvc_Model, setAutoincrement) {

	zval *autoincrement, autoincrement_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&autoincrement_sub);

	zephir_fetch_params(0, 1, 0, &autoincrement);



	zephir_update_property_zval(this_ptr, SL("autoincrement"), autoincrement);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, setFilters) {

	zval *filters, filters_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);

	zephir_fetch_params(0, 1, 0, &filters);



	zephir_update_property_zval(this_ptr, SL("filters"), filters);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, getFilters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "filters");

}

PHP_METHOD(Ice_Mvc_Model, setFields) {

	zval *fields, fields_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);

	zephir_fetch_params(0, 1, 0, &fields);



	zephir_update_property_zval(this_ptr, SL("fields"), fields);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, getFields) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "fields");

}

PHP_METHOD(Ice_Mvc_Model, setValidation) {

	zval *validation, validation_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);

	zephir_fetch_params(0, 1, 0, &validation);



	zephir_update_property_zval(this_ptr, SL("validation"), validation);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, getValidation) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "validation");

}

PHP_METHOD(Ice_Mvc_Model, getRelations) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "relations");

}

PHP_METHOD(Ice_Mvc_Model, setLabels) {

	zval *labels, labels_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&labels_sub);

	zephir_fetch_params(0, 1, 0, &labels);



	zephir_update_property_zval(this_ptr, SL("labels"), labels);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Model, getMessages) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "messages");

}

PHP_METHOD(Ice_Mvc_Model, setMessages) {

	zval *messages, messages_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages_sub);

	zephir_fetch_params(0, 1, 0, &messages);



	zephir_update_property_zval(this_ptr, SL("messages"), messages);
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
	zval data, options;
	zval *filters = NULL, filters_sub, *data_param = NULL, *options_param = NULL, __$null, di, _1, _2, _3, _4, _5, _7, _10, _8$$3, _9$$3, _11$$4, _12$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &filters, &data_param, &options_param);

	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("di"), &di);
	zephir_read_property(&_2, this_ptr, SL("service"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &di, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("db"), &_1);
	ZEPHIR_INIT_VAR(&_3);
	zephir_read_property(&_4, this_ptr, SL("fields"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_5, "array_fill_keys", NULL, 6, &_4, &__$null);
	zephir_check_call_status();
	zephir_fast_array_merge(&_3, &_5, &data TSRMLS_CC);
	ZEPHIR_CPY_WRT(&data, &_3);
	ZEPHIR_CALL_PARENT(NULL, ice_mvc_model_ce, getThis(), "__construct", &_6, 0, &data);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, SL("from"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_7))) {
		ZEPHIR_INIT_VAR(&_8$$3);
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_get_class_ns(&_9$$3, this_ptr, 0 TSRMLS_CC);
		zephir_uncamelize(&_8$$3, &_9$$3, NULL  );
		zephir_update_property_zval(this_ptr, SL("from"), &_8$$3);
	}
	zephir_read_property(&_10, this_ptr, SL("primary"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_10))) {
		zephir_read_property(&_11$$4, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_12$$4, &_11$$4, "getid", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("primary"), &_12$$4);
	}
	if ((zephir_method_exists_ex(this_ptr, SL("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	if (zephir_is_true(filters)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadone", NULL, 0, filters, &options);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(this_ptr, SL("initialize") TSRMLS_CC) == SUCCESS)) {
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

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the id key depending on db driver.
 *
 * @return string
 */
PHP_METHOD(Ice_Mvc_Model, getIdKey) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getid", NULL, 0);
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
	zval *key, key_sub, *model = NULL, model_sub, __$false, value, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &model);

	if (!model) {
		model = &model_sub;
		model = &__$false;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&value, this_ptr, "get", NULL, 0, key);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&value, key);
	}
	zephir_read_property(&_1, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getdatetime", NULL, 0, &value, model);
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
	zval options;
	zval *filters, filters_sub, *options_param = NULL, __$true, __$false, result, _0, _1, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filters, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	if (ZEPHIR_IS_EMPTY(filters)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_0, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("from"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "findone", NULL, 0, &_1, filters, &options);
	zephir_check_call_status();
	if (zephir_is_true(&result)) {
		ZEPHIR_CALL_METHOD(&_2$$4, &result, "all", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, &_2$$4);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_zval(this_ptr, SL("isLoaded"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("isLoaded"), &__$false);
		}
		RETURN_THIS();
	} else {
		if (0) {
			zephir_update_property_zval(this_ptr, SL("isLoaded"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("isLoaded"), &__$false);
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
	zval options, _5$$4;
	zval *filters, filters_sub, *options_param = NULL, __$null, __$true, __$false, result, instances, data, model, _0, _1, _2, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&instances);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filters, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_read_property(&_0, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("from"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "find", NULL, 0, &_1, filters, &options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&instances);
	array_init(&instances);
	ZEPHIR_CALL_METHOD(&_2, &result, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		_3$$3 = zephir_get_iterator(&result TSRMLS_CC);
		_3$$3->funcs->rewind(_3$$3 TSRMLS_CC);
		for (;_3$$3->funcs->valid(_3$$3 TSRMLS_CC) == SUCCESS && !EG(exception); _3$$3->funcs->move_forward(_3$$3 TSRMLS_CC)) {
			{
				ZEPHIR_ITERATOR_COPY(&data, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&_4$$4);
			zephir_get_called_class(&_4$$4 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_5$$4);
			zephir_create_array(&_5$$4, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_5$$4, &__$null);
			zephir_array_fast_append(&_5$$4, &data);
			ZEPHIR_INIT_NVAR(&model);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&model, &_4$$4, &_5$$4 TSRMLS_CC);
			zephir_check_call_status();
			if (1) {
				zephir_update_property_zval(&model, SL("isLoaded"), &__$true);
			} else {
				zephir_update_property_zval(&model, SL("isLoaded"), &__$false);
			}
			zephir_array_append(&instances, &model, PH_SEPARATE, "ice/mvc/model.zep", 167);
		}
		zend_iterator_dtor(_3$$3);
	}
	object_init_ex(return_value, ice_arr_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 4, &instances);
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
	zval options, _1;
	zval *filters = NULL, filters_sub, *options_param = NULL, __$null, model, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &filters, &options_param);

	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_called_class(&_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, filters);
	zephir_array_fast_append(&_1, &__$null);
	zephir_array_fast_append(&_1, &options);
	ZEPHIR_INIT_VAR(&model);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&model, &_0, &_1 TSRMLS_CC);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_read_property(&_3, &model, SL("isLoaded"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		ZEPHIR_CPY_WRT(&_2, &model);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	RETURN_CCTOR(&_2);

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
	zval options;
	zval *filters = NULL, filters_sub, *options_param = NULL, __$null, model, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &filters, &options_param);

	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_called_class(&_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&model);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&model, &_0 TSRMLS_CC);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&model, "load", NULL, 0, filters, &options);
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

	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool primary, _26;
	zval *fields = NULL, fields_sub, *primary_param = NULL, _0, _25, _1$$5, _2$$5, _3$$5, _5$$6, _6$$6, _7$$7, _8$$7, _11$$9, _12$$9, _13$$9, _14$$10, _15$$10, _16$$10, _17$$11, _18$$11, _19$$11, _20$$11, _21$$12, _22$$12, _23$$12, _24$$12, _27$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_27$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &primary_param);

	if (!fields) {
		fields = &fields_sub;
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


	zephir_read_property(&_0, this_ptr, SL("fields"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		if (ZEPHIR_IS_EMPTY(fields)) {
			ZEPHIR_CALL_METHOD(fields, this_ptr, "all", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_1$$5);
			zephir_array_keys(&_1$$5, fields TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "is_string");
			ZEPHIR_CALL_FUNCTION(&_3$$5, "array_filter", &_4, 7, &_1$$5, &_2$$5);
			zephir_check_call_status();
			if (zephir_is_true(&_3$$5)) {
				ZEPHIR_INIT_VAR(&_5$$6);
				ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "all", NULL, 0);
				zephir_check_call_status();
				zephir_fast_array_merge(&_5$$6, &_6$$6, fields TSRMLS_CC);
				ZEPHIR_CPY_WRT(fields, &_5$$6);
			} else {
				ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "all", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_8$$7, "array_flip", &_9, 8, fields);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(fields, "array_intersect_key", &_10, 9, &_7$$7, &_8$$7);
				zephir_check_call_status();
			}
		}
	} else {
		if (ZEPHIR_IS_EMPTY(fields)) {
			ZEPHIR_CALL_METHOD(&_11$$9, this_ptr, "all", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_12$$9, this_ptr, SL("fields"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_13$$9, "array_flip", &_9, 8, &_12$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(fields, "array_intersect_key", &_10, 9, &_11$$9, &_13$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_14$$10);
			zephir_array_keys(&_14$$10, fields TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_15$$10);
			ZVAL_STRING(&_15$$10, "is_string");
			ZEPHIR_CALL_FUNCTION(&_16$$10, "array_filter", &_4, 7, &_14$$10, &_15$$10);
			zephir_check_call_status();
			if (zephir_is_true(&_16$$10)) {
				ZEPHIR_INIT_VAR(&_17$$11);
				ZEPHIR_CALL_METHOD(&_18$$11, this_ptr, "all", NULL, 0);
				zephir_check_call_status();
				zephir_fast_array_merge(&_17$$11, &_18$$11, fields TSRMLS_CC);
				zephir_read_property(&_19$$11, this_ptr, SL("fields"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_20$$11, "array_flip", &_9, 8, &_19$$11);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(fields, "array_intersect_key", &_10, 9, &_17$$11, &_20$$11);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&_21$$12, this_ptr, "all", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_22$$12, "array_flip", &_9, 8, fields);
				zephir_check_call_status();
				zephir_read_property(&_23$$12, this_ptr, SL("fields"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_24$$12, "array_flip", &_9, 8, &_23$$12);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(fields, "array_intersect_key", &_10, 9, &_21$$12, &_22$$12, &_24$$12);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_OBS_VAR(&_25);
	zephir_read_property(&_25, this_ptr, SL("primary"), PH_NOISY_CC);
	_26 = Z_TYPE_P(&_25) == IS_STRING;
	if (_26) {
		_26 = !primary;
	}
	if (_26) {
		zephir_read_property(&_27$$13, this_ptr, SL("primary"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(fields, &_27$$13, PH_SEPARATE);
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

	zend_bool _8, _10, _13$$4;
	zval _5, _36, _39, _49;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, *extra = NULL, extra_sub, __$true, __$false, __$null, status, _0, _1, _2, _6, _7, _9, _11, _35, _37, _38, _40, _41, _42, _48, _3$$3, _4$$3, _12$$4, _14$$4, _16$$4, _17$$4, _20$$4, _21$$4, _22$$4, _23$$4, _24$$4, _25$$4, _26$$4, _27$$4, _28$$4, _29$$4, _15$$5, _18$$6, _19$$6, _30$$7, _31$$7, _32$$7, _33$$7, _34$$7, _43$$9, _44$$10, _45$$10, _46$$10, _47$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&extra_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_27$$4);
	ZVAL_UNDEF(&_28$$4);
	ZVAL_UNDEF(&_29$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_47$$10);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_49);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = &extra_sub;
		extra = &__$null;
	}


	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("autoincrement"), PH_NOISY_CC);
	ZVAL_BOOL(&_2, !zephir_is_true(&_1));
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fields", NULL, 0, fields, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(extra)) {
		ZEPHIR_CALL_METHOD(NULL, extra, "validate", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, extra, "getmessages", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "all", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("messages"), &_4$$3);
	}
	zephir_read_property(&_2, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_5, this_ptr);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "model.before.validate");
	ZEPHIR_CALL_METHOD(NULL, &_2, "applyhook", NULL, 0, &_6, &_5);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, SL("rules"), PH_NOISY_CC | PH_READONLY);
	_8 = !(ZEPHIR_IS_EMPTY(&_7));
	if (!(_8)) {
		ZEPHIR_OBS_VAR(&_9);
		zephir_read_property(&_9, this_ptr, SL("validation"), PH_NOISY_CC);
		_10 = Z_TYPE_P(&_9) == IS_OBJECT;
		if (_10) {
			ZEPHIR_OBS_VAR(&_11);
			zephir_read_property(&_11, this_ptr, SL("validation"), PH_NOISY_CC);
			_10 = zephir_instance_of_ev(&_11, ice_validation_ce TSRMLS_CC);
		}
		_8 = _10;
	}
	if (_8) {
		ZEPHIR_OBS_VAR(&_12$$4);
		zephir_read_property(&_12$$4, this_ptr, SL("validation"), PH_NOISY_CC);
		_13$$4 = Z_TYPE_P(&_12$$4) == IS_OBJECT;
		if (_13$$4) {
			ZEPHIR_OBS_VAR(&_14$$4);
			zephir_read_property(&_14$$4, this_ptr, SL("validation"), PH_NOISY_CC);
			_13$$4 = zephir_instance_of_ev(&_14$$4, ice_validation_ce TSRMLS_CC);
		}
		if (!(_13$$4)) {
			ZEPHIR_INIT_VAR(&_15$$5);
			object_init_ex(&_15$$5, ice_validation_ce);
			ZEPHIR_CALL_METHOD(NULL, &_15$$5, "__construct", NULL, 10);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("validation"), &_15$$5);
		}
		zephir_read_property(&_16$$4, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_17$$4, &_16$$4, "getrules", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_17$$4))) {
			zephir_read_property(&_18$$6, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_19$$6, this_ptr, SL("rules"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_18$$6, "rules", NULL, 0, &_19$$6);
			zephir_check_call_status();
		}
		zephir_read_property(&_20$$4, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_21$$4, this_ptr, SL("filters"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_20$$4, "setfilters", NULL, 0, &_21$$4);
		zephir_check_call_status();
		zephir_read_property(&_22$$4, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_23$$4, this_ptr, SL("labels"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_22$$4, "setlabels", NULL, 0, &_23$$4);
		zephir_check_call_status();
		zephir_read_property(&_24$$4, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_25$$4, this_ptr, "getdata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_24$$4, "validate", NULL, 0, &_25$$4);
		zephir_check_call_status();
		zephir_read_property(&_26$$4, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_27$$4, &_26$$4, "getvalues", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, &_27$$4);
		zephir_check_call_status();
		zephir_read_property(&_28$$4, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_29$$4, &_28$$4, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_29$$4))) {
			ZEPHIR_INIT_VAR(&_30$$7);
			zephir_read_property(&_31$$7, this_ptr, SL("messages"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_32$$7, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_33$$7, &_32$$7, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_34$$7, &_33$$7, "all", NULL, 0);
			zephir_check_call_status();
			zephir_fast_array_merge(&_30$$7, &_31$$7, &_34$$7 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("messages"), &_30$$7);
		}
	}
	zephir_read_property(&_35, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_36);
	zephir_create_array(&_36, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_36, this_ptr);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "model.after.validate");
	ZEPHIR_CALL_METHOD(NULL, &_35, "applyhook", NULL, 0, &_6, &_36);
	zephir_check_call_status();
	zephir_read_property(&_37, this_ptr, SL("messages"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_37))) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_38, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_39);
	zephir_create_array(&_39, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_39, this_ptr);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "model.before.create");
	ZEPHIR_CALL_METHOD(NULL, &_38, "applyhook", NULL, 0, &_6, &_39);
	zephir_check_call_status();
	zephir_read_property(&_40, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_41, this_ptr, SL("from"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_42, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &_40, "insert", NULL, 0, &_41, &_42);
	zephir_check_call_status();
	if (zephir_is_true(&status)) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("isLoaded"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("isLoaded"), &__$false);
		}
		zephir_read_property(&_43$$9, this_ptr, SL("autoincrement"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_43$$9)) {
			zephir_read_property(&_44$$10, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_45$$10, &_44$$10, "getid", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_46$$10, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_47$$10, &_46$$10, "getlastinsertid", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_45$$10, &_47$$10);
			zephir_check_call_status();
		}
	}
	zephir_read_property(&_48, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_49);
	zephir_create_array(&_49, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_49, this_ptr);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "model.after.create");
	ZEPHIR_CALL_METHOD(NULL, &_48, "applyhook", NULL, 0, &_6, &_49);
	zephir_check_call_status();
	RETURN_CCTOR(&status);

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

	zend_bool _16;
	zval _13, _30, _33, _40;
	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, *extra = NULL, extra_sub, __$true, __$false, __$null, data, status, primary, key, _0, _8, _12, _14, _15, _17, _29, _31, _32, _34, _35, _36, _37, _38, _39, _1$$3, *_2$$3, _3$$4, _5$$5, _6$$5, _7$$5, _10$$6, _11$$6, _18$$7, _19$$7, _20$$7, _21$$7, _22$$7, _23$$7, _24$$8, _25$$8, _26$$8, _27$$8, _28$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&extra_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&primary);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_40);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = &extra_sub;
		extra = &__$null;
	}


	ZEPHIR_CALL_METHOD(&data, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&primary);
	array_init(&primary);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("primary"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		zephir_read_property(&_1$$3, this_ptr, SL("primary"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "ice/mvc/model.zep", 370);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _2$$3);
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "get", &_4, 0, &key);
			zephir_check_call_status();
			zephir_array_update_zval(&primary, &key, &_3$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_INIT_NVAR(&primary);
		zephir_create_array(&primary, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_5$$5);
		zephir_read_property(&_5$$5, this_ptr, SL("primary"), PH_NOISY_CC);
		zephir_read_property(&_7$$5, this_ptr, SL("primary"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "get", &_4, 0, &_7$$5);
		zephir_check_call_status();
		zephir_array_update_zval(&primary, &_5$$5, &_6$$5, PH_COPY);
	}
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "fields", &_9, 0, fields);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, &_8);
	zephir_check_call_status();
	if (zephir_is_true(extra)) {
		ZEPHIR_CALL_METHOD(NULL, extra, "validate", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_10$$6, extra, "getmessages", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_11$$6, &_10$$6, "all", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("messages"), &_11$$6);
	}
	zephir_read_property(&_12, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_13, this_ptr);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "model.before.validate");
	ZEPHIR_CALL_METHOD(NULL, &_12, "applyhook", NULL, 0, &_14, &_13);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_15);
	zephir_read_property(&_15, this_ptr, SL("validation"), PH_NOISY_CC);
	_16 = Z_TYPE_P(&_15) == IS_OBJECT;
	if (_16) {
		ZEPHIR_OBS_VAR(&_17);
		zephir_read_property(&_17, this_ptr, SL("validation"), PH_NOISY_CC);
		_16 = zephir_instance_of_ev(&_17, ice_validation_ce TSRMLS_CC);
	}
	if (_16) {
		zephir_read_property(&_18$$7, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_19$$7, this_ptr, "getdata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_18$$7, "validate", NULL, 0, &_19$$7);
		zephir_check_call_status();
		zephir_read_property(&_20$$7, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_21$$7, &_20$$7, "getvalues", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, &_21$$7);
		zephir_check_call_status();
		zephir_read_property(&_22$$7, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_23$$7, &_22$$7, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_23$$7))) {
			ZEPHIR_INIT_VAR(&_24$$8);
			zephir_read_property(&_25$$8, this_ptr, SL("messages"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_26$$8, this_ptr, SL("validation"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_27$$8, &_26$$8, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_28$$8, &_27$$8, "all", NULL, 0);
			zephir_check_call_status();
			zephir_fast_array_merge(&_24$$8, &_25$$8, &_28$$8 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("messages"), &_24$$8);
		}
	}
	zephir_read_property(&_29, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_30);
	zephir_create_array(&_30, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_30, this_ptr);
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "model.after.validate");
	ZEPHIR_CALL_METHOD(NULL, &_29, "applyhook", NULL, 0, &_14, &_30);
	zephir_check_call_status();
	zephir_read_property(&_31, this_ptr, SL("messages"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_31))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, &data);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_32, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_33);
	zephir_create_array(&_33, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_33, this_ptr);
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "model.before.update");
	ZEPHIR_CALL_METHOD(NULL, &_32, "applyhook", NULL, 0, &_14, &_33);
	zephir_check_call_status();
	zephir_read_property(&_34, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_35, this_ptr, SL("from"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_37, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_38);
	zephir_read_property(&_38, this_ptr, SL("autoincrement"), PH_NOISY_CC);
	ZVAL_BOOL(&_39, !zephir_is_true(&_38));
	ZEPHIR_CALL_METHOD(&_36, this_ptr, "fields", &_9, 0, &_37, &_39);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &_34, "update", NULL, 0, &_35, &primary, &_36);
	zephir_check_call_status();
	if (!(zephir_is_true(&status))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, &data);
		zephir_check_call_status();
	} else {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("isLoaded"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("isLoaded"), &__$false);
		}
	}
	zephir_read_property(&_39, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_40);
	zephir_create_array(&_40, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_40, this_ptr);
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "model.after.update");
	ZEPHIR_CALL_METHOD(NULL, &_39, "applyhook", NULL, 0, &_14, &_40);
	zephir_check_call_status();
	RETURN_CCTOR(&status);

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, *extra = NULL, extra_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&extra_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = &extra_sub;
		extra = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
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

	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, filters_sub, __$true, __$false, key, status, _8, _9, _0$$3, _1$$4, *_2$$4, _3$$5, _5$$6, _6$$6, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filters);

	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	} else {
		ZEPHIR_SEPARATE_PARAM(filters);
	}


	if (!(zephir_is_true(filters))) {
		ZEPHIR_INIT_NVAR(filters);
		array_init(filters);
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property(&_0$$3, this_ptr, SL("primary"), PH_NOISY_CC);
		if (Z_TYPE_P(&_0$$3) == IS_ARRAY) {
			zephir_read_property(&_1$$4, this_ptr, SL("primary"), PH_NOISY_CC | PH_READONLY);
			zephir_is_iterable(&_1$$4, 0, "ice/mvc/model.zep", 474);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$4), _2$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				ZVAL_COPY(&key, _2$$4);
				ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "get", &_4, 0, &key);
				zephir_check_call_status();
				zephir_array_update_zval(filters, &key, &_3$$5, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&key);
		} else {
			ZEPHIR_INIT_NVAR(filters);
			zephir_create_array(filters, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&_5$$6);
			zephir_read_property(&_5$$6, this_ptr, SL("primary"), PH_NOISY_CC);
			zephir_read_property(&_7$$6, this_ptr, SL("primary"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "get", &_4, 0, &_7$$6);
			zephir_check_call_status();
			zephir_array_update_zval(filters, &_5$$6, &_6$$6, PH_COPY);
		}
	}
	zephir_read_property(&_8, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_9, this_ptr, SL("from"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&status, &_8, "remove", NULL, 0, &_9, filters);
	zephir_check_call_status();
	if (zephir_is_true(&status)) {
		if (0) {
			zephir_update_property_zval(this_ptr, SL("isLoaded"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("isLoaded"), &__$false);
		}
	}
	RETURN_CCTOR(&status);

}

/**
 * Get the record if exist.
 *
 * @param mixed filters
 * @return Model|false
 */
PHP_METHOD(Ice_Mvc_Model, exists) {

	zend_bool _8$$6, _14$$9;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, filters_sub, key, _0, _1$$3, _2$$3, _3$$4, _4$$5, *_5$$5, _6$$6, _9$$6, _11$$7, _12$$9, _13$$9, _15$$9, _16$$9, _17$$10, _18$$10, _19$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filters);

	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	} else {
		ZEPHIR_SEPARATE_PARAM(filters);
	}


	zephir_read_property(&_0, this_ptr, SL("isLoaded"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("isLoaded"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_2$$3)) {
			ZEPHIR_CPY_WRT(&_1$$3, this_ptr);
		} else {
			ZVAL_BOOL(&_1$$3, 0);
		}
		RETURN_CCTOR(&_1$$3);
	}
	if (!(zephir_is_true(filters))) {
		ZEPHIR_INIT_NVAR(filters);
		array_init(filters);
		ZEPHIR_OBS_VAR(&_3$$4);
		zephir_read_property(&_3$$4, this_ptr, SL("primary"), PH_NOISY_CC);
		if (Z_TYPE_P(&_3$$4) == IS_ARRAY) {
			zephir_read_property(&_4$$5, this_ptr, SL("primary"), PH_NOISY_CC | PH_READONLY);
			zephir_is_iterable(&_4$$5, 0, "ice/mvc/model.zep", 514);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4$$5), _5$$5)
			{
				ZEPHIR_INIT_NVAR(&key);
				ZVAL_COPY(&key, _5$$5);
				ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "has", &_7, 0, &key);
				zephir_check_call_status();
				_8$$6 = zephir_is_true(&_6$$6);
				if (_8$$6) {
					ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "get", &_10, 0, &key);
					zephir_check_call_status();
					_8$$6 = zephir_is_true(&_9$$6);
				}
				if (_8$$6) {
					ZEPHIR_CALL_METHOD(&_11$$7, this_ptr, "get", &_10, 0, &key);
					zephir_check_call_status();
					zephir_array_update_zval(filters, &key, &_11$$7, PH_COPY | PH_SEPARATE);
				} else {
					RETURN_MM_BOOL(0);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&key);
		} else {
			zephir_read_property(&_13$$9, this_ptr, SL("primary"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_12$$9, this_ptr, "has", &_7, 0, &_13$$9);
			zephir_check_call_status();
			_14$$9 = zephir_is_true(&_12$$9);
			if (_14$$9) {
				zephir_read_property(&_16$$9, this_ptr, SL("primary"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_15$$9, this_ptr, "get", &_10, 0, &_16$$9);
				zephir_check_call_status();
				_14$$9 = zephir_is_true(&_15$$9);
			}
			if (_14$$9) {
				ZEPHIR_INIT_NVAR(filters);
				zephir_create_array(filters, 1, 0 TSRMLS_CC);
				ZEPHIR_OBS_VAR(&_17$$10);
				zephir_read_property(&_17$$10, this_ptr, SL("primary"), PH_NOISY_CC);
				zephir_read_property(&_19$$10, this_ptr, SL("primary"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_18$$10, this_ptr, "get", &_10, 0, &_19$$10);
				zephir_check_call_status();
				zephir_array_update_zval(filters, &_17$$10, &_18$$10, PH_COPY);
			} else {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_RETURN_CALL_STATIC("findone", NULL, 0, filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the last Db error.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_Model, getError) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "geterror", NULL, 0);
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

	zval options, _0;
	zval *field_param = NULL, *referenceModel_param = NULL, *referencedField_param = NULL, *options_param = NULL, alias;
	zval field, referenceModel, referencedField;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referenceModel);
	ZVAL_UNDEF(&referencedField);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &field_param, &referenceModel_param, &referencedField_param, &options_param);

	zephir_get_strval(&field, field_param);
	zephir_get_strval(&referenceModel, referenceModel_param);
	zephir_get_strval(&referencedField, referencedField_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_OBS_VAR(&alias);
	if (!(zephir_array_isset_string_fetch(&alias, &options, SL("alias"), 0))) {
		ZEPHIR_CPY_WRT(&alias, &referenceModel);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 5, 0 TSRMLS_CC);
	add_assoc_long_ex(&_0, SL("type"), 1);
	zephir_array_update_string(&_0, SL("field"), &field, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referenceModel"), &referenceModel, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedField"), &referencedField, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("options"), &options, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("relations"), &alias, &_0 TSRMLS_CC);
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

	zval options, _0;
	zval *field_param = NULL, *referenceModel_param = NULL, *referencedField_param = NULL, *options_param = NULL, alias;
	zval field, referenceModel, referencedField;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referenceModel);
	ZVAL_UNDEF(&referencedField);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &field_param, &referenceModel_param, &referencedField_param, &options_param);

	zephir_get_strval(&field, field_param);
	zephir_get_strval(&referenceModel, referenceModel_param);
	zephir_get_strval(&referencedField, referencedField_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_OBS_VAR(&alias);
	if (!(zephir_array_isset_string_fetch(&alias, &options, SL("alias"), 0))) {
		ZEPHIR_CPY_WRT(&alias, &referenceModel);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 5, 0 TSRMLS_CC);
	add_assoc_long_ex(&_0, SL("type"), 2);
	zephir_array_update_string(&_0, SL("field"), &field, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referenceModel"), &referenceModel, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedField"), &referencedField, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("options"), &options, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("relations"), &alias, &_0 TSRMLS_CC);
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

	zval options, _0;
	zval *field_param = NULL, *referenceModel_param = NULL, *referencedField_param = NULL, *options_param = NULL, alias;
	zval field, referenceModel, referencedField;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referenceModel);
	ZVAL_UNDEF(&referencedField);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &field_param, &referenceModel_param, &referencedField_param, &options_param);

	zephir_get_strval(&field, field_param);
	zephir_get_strval(&referenceModel, referenceModel_param);
	zephir_get_strval(&referencedField, referencedField_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_OBS_VAR(&alias);
	if (!(zephir_array_isset_string_fetch(&alias, &options, SL("alias"), 0))) {
		ZEPHIR_CPY_WRT(&alias, &referenceModel);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 5, 0 TSRMLS_CC);
	add_assoc_long_ex(&_0, SL("type"), 3);
	zephir_array_update_string(&_0, SL("field"), &field, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referenceModel"), &referenceModel, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedField"), &referencedField, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("options"), &options, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("relations"), &alias, &_0 TSRMLS_CC);
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
	zval filters, options, _6$$4;
	zval *alias_param = NULL, *filters_param = NULL, *options_param = NULL, __$null, relation, field, referenceModel, referencedField, result, _0, _4, _1$$3, _2$$3, _3$$3, _5$$4, _7$$4, _8$$6;
	zval alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referenceModel);
	ZVAL_UNDEF(&referencedField);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &alias_param, &filters_param, &options_param);

	zephir_get_strval(&alias, alias_param);
	if (!filters_param) {
		ZEPHIR_INIT_VAR(&filters);
		array_init(&filters);
	} else {
		zephir_get_arrval(&filters, filters_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_OBS_VAR(&relation);
	zephir_read_property(&_0, this_ptr, SL("relations"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&relation, &_0, &alias, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Alias '%s' not found");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 11, &_2$$3, &alias);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 12, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "ice/mvc/model.zep", 674 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&field);
	zephir_array_isset_string_fetch(&field, &relation, SL("field"), 0);
	ZEPHIR_OBS_VAR(&referenceModel);
	zephir_array_isset_string_fetch(&referenceModel, &relation, SL("referenceModel"), 0);
	ZEPHIR_OBS_VAR(&referencedField);
	zephir_array_isset_string_fetch(&referencedField, &relation, SL("referencedField"), 0);
	zephir_array_fetch_string(&_4, &relation, SL("type"), PH_NOISY | PH_READONLY, "ice/mvc/model.zep", 681 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(&_4, 1) || ZEPHIR_IS_LONG(&_4, 2)) {
			ZEPHIR_OBS_VAR(&_5$$4);
			zephir_read_property_zval(&_5$$4, this_ptr, &field, PH_NOISY_CC);
			zephir_array_update_zval(&filters, &referencedField, &_5$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_6$$4);
			zephir_create_array(&_6$$4, 3, 0 TSRMLS_CC);
			zephir_array_fast_append(&_6$$4, &filters);
			zephir_array_fast_append(&_6$$4, &__$null);
			zephir_array_fast_append(&_6$$4, &options);
			ZEPHIR_INIT_VAR(&result);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&result, &referenceModel, &_6$$4 TSRMLS_CC);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$4, &result, "count", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_7$$4))) {
				RETURN_MM_BOOL(0);
			}
			RETURN_CCTOR(&result);
		}
		if (ZEPHIR_IS_LONG(&_4, 3)) {
			ZEPHIR_OBS_VAR(&_8$$6);
			zephir_read_property_zval(&_8$$6, this_ptr, &field, PH_NOISY_CC);
			zephir_array_update_zval(&filters, &referencedField, &_8$$6, PH_COPY | PH_SEPARATE);
			_9$$6 = zephir_fetch_class(&referenceModel TSRMLS_CC);
			ZEPHIR_CALL_CE_STATIC(&result, _9$$6, "find", NULL, 0, &filters, &options);
			zephir_check_call_status();
			RETURN_CCTOR(&result);
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

	zend_bool _0$$3;
	zval *fields = NULL, fields_sub, __$null, rules, field, _1$$3, *_2$$4, _3$$5, _4$$6, _5$$6, _6$$7, _7$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&rules);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fields);

	if (!fields) {
		fields = &fields_sub;
		fields = &__$null;
	}


	if (zephir_is_true(fields)) {
		_0$$3 = Z_TYPE_P(fields) == IS_STRING;
		if (_0$$3) {
			zephir_read_property(&_1$$3, this_ptr, SL("rules"), PH_NOISY_CC | PH_READONLY);
			_0$$3 = zephir_array_isset(&_1$$3, fields);
		}
		if (Z_TYPE_P(fields) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&rules);
			array_init(&rules);
			zephir_is_iterable(fields, 0, "ice/mvc/model.zep", 732);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(fields), _2$$4)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _2$$4);
				zephir_read_property(&_3$$5, this_ptr, SL("rules"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_3$$5, &field)) {
					zephir_read_property(&_4$$6, this_ptr, SL("rules"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_5$$6, &_4$$6, &field, PH_NOISY | PH_READONLY, "ice/mvc/model.zep", 728 TSRMLS_CC);
					zephir_array_update_zval(&rules, &field, &_5$$6, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&field);
			RETURN_CCTOR(&rules);
		} else if (_0$$3) {
			zephir_read_property(&_6$$7, this_ptr, SL("rules"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_7$$7, &_6$$7, fields, PH_NOISY | PH_READONLY, "ice/mvc/model.zep", 734 TSRMLS_CC);
			RETURN_CTOR(&_7$$7);
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
	zval *rules_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval rules;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rules);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &rules_param, &merge_param);

	if (!rules_param) {
		ZEPHIR_INIT_VAR(&rules);
		array_init(&rules);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&rules, rules_param);
	}
	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("rules"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &rules TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("rules"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("rules"), &rules);
	}
	RETURN_THIS();

}

/**
 * Serialize the model's data.
 *
 * @return string
 */
PHP_METHOD(Ice_Mvc_Model, serialize) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "serialize", NULL, 13, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 14, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserialize and set the data.
 * @return object Model
 */
PHP_METHOD(Ice_Mvc_Model, unserialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serialized, serialized_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serialized_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serialized);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "base64_decode", NULL, 15, serialized);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "unserialize", NULL, 16, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("data"), &_1);
	RETURN_THIS();

}

/**
 * Magic call to get related models.
 */
PHP_METHOD(Ice_Mvc_Model, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, arguments_sub, __$null, filters, options, _3, _4, _5, _0$$3, _1$$3, _2$$3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	zephir_get_strval(&method, method_param);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	if (zephir_start_with_str(&method, SL("get"))) {
		ZEPHIR_OBS_VAR(&filters);
		zephir_array_isset_long_fetch(&filters, arguments, 0, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&options);
		zephir_array_isset_long_fetch(&options, arguments, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_LONG(&_1$$3, 3);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_substr(&_2$$3, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_ucfirst(&_0$$3, &_2$$3);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrelated", NULL, 0, &_0$$3, &filters, &options);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, ice_exception_ce);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "The method '%s' doesn't exist");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 11, &_4, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 12, &_5);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_3, "ice/mvc/model.zep", 795 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

zend_object *zephir_init_properties_Ice_Mvc_Model(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _10, _12, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("messages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("messages"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("rules"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("rules"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("labels"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("labels"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("relations"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("relations"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("fields"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("fields"), &_9$$7);
		}
		zephir_read_property(&_10, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval(this_ptr, SL("data"), &_11$$8);
		}
		zephir_read_property(&_12, this_ptr, SL("filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval(this_ptr, SL("filters"), &_13$$9);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

