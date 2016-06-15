
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Mongo driver.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db_Driver_Mongo) {

	ZEPHIR_REGISTER_CLASS(Ice\\Db\\Driver, Mongo, ice, db_driver_mongo, ice_db_driver_mongo_method_entry, 0);

	zend_declare_property_string(ice_db_driver_mongo_ce, SL("id"), "_id", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_db_driver_mongo_ce, SL("type"), "NOSQL", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_mongo_ce, SL("error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_mongo_ce, SL("client"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_mongo_ce, SL("lastInsertId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_db_driver_mongo_ce TSRMLS_CC, 1, ice_db_dbinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Db_Driver_Mongo, getId) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "id");

}

PHP_METHOD(Ice_Db_Driver_Mongo, getType) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "type");

}

PHP_METHOD(Ice_Db_Driver_Mongo, getClient) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "client");

}

PHP_METHOD(Ice_Db_Driver_Mongo, getLastInsertId) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "lastInsertId");

}

/**
 * Instantiate mongo connection.
 *
 * @param string dsn
 * @param string dbname
 * @param array options
 */
PHP_METHOD(Ice_Db_Driver_Mongo, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *dsn_param = NULL, *dbname_param = NULL, *options_param = NULL, _0, _1;
	zval dsn, dbname;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&dbname);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &dsn_param, &dbname_param, &options_param);

	zephir_get_strval(&dsn, dsn_param);
	if (!dbname_param) {
		ZEPHIR_INIT_VAR(&dbname);
		ZVAL_STRING(&dbname, "");
	} else {
		zephir_get_strval(&dbname, dbname_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("mongodb")));
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("mongoclient")));
	if (zephir_has_constructor(&_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &dsn, &options);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_1, &dbname);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("client"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the id value.
 *
 * @param string id
 * @return object
 */
PHP_METHOD(Ice_Db_Driver_Mongo, getIdValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL;
	zval id;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&id);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	object_init_ex(return_value, zephir_get_internal_ce(SL("mongoid")));
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &id);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * Find one document that match criteria.
 *
 * @param string from Collection name
 * @param mixed filters Criteria
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 * @return Arr
 */
PHP_METHOD(Ice_Db_Driver_Mongo, findOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval options, fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, result, _0, _1, _2, _3;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
		zephir_get_arrval(&fields, fields_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 1);
	zephir_array_update_string(&options, SL("limit"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, &from, filters, &options, &fields);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, &result, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		object_init_ex(&_1, ice_arr_ce);
		ZEPHIR_CALL_METHOD(&_3, &result, "getnext", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 5, &_3);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	RETURN_CCTOR(_1);

}

/**
 * Find all documents that match criteria.
 *
 * <pre><code>
 *  $db->find("users", array("a" => 1, "b" => "q"));
 *  $db->find("users", array("age" => array(">" => 33)));
 *  $db->find("users", array("OR" => array(array("a" => 1), array("b" => 2))));
 * </code></pre>
 *
 * @param string from Collection name
 * @param mixed filters Criteria
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 * @return Arr
 */
PHP_METHOD(Ice_Db_Driver_Mongo, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval options, fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, result, _0;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
		zephir_get_arrval(&fields, fields_param);
	}


	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, &from, filters, &options, &fields);
	zephir_check_call_status();
	object_init_ex(return_value, ice_arr_ce);
	ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, 72, &result);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 5, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * SELECT document(s) that match criteria.
 *
 * @param string from Collection name
 * @param mixed filters Criteria
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 */
PHP_METHOD(Ice_Db_Driver_Mongo, select) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval options, fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, filtered, collection, result, tmp, _0, _4, _8, _9, _1$$4, _2$$7, _3$$7, _5$$9, _6$$10, _7$$11;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
		zephir_get_arrval(&fields, fields_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_gettype(&_0, filters TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(&_0, "object")) {
			if (zephir_instance_of_ev(filters, zephir_get_internal_ce(SL("mongoid")) TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(&filtered);
				zephir_create_array(&filtered, 1, 0 TSRMLS_CC);
				ZEPHIR_OBS_VAR(&_1$$4);
				zephir_read_property(&_1$$4, this_ptr, SL("id"), PH_NOISY_CC);
				zephir_array_update_zval(&filtered, &_1$$4, filters, PH_COPY);
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Object must be an MongoId instance", "ice/db/driver/mongo.zep", 110);
				return;
			}
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "array")) {
			ZEPHIR_CPY_WRT(&filtered, filters);
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "integer") || ZEPHIR_IS_STRING(&_0, "string")) {
			ZEPHIR_INIT_NVAR(&filtered);
			zephir_create_array(&filtered, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&_2$$7);
			zephir_read_property(&_2$$7, this_ptr, SL("id"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_3$$7, this_ptr, "getidvalue", NULL, 0, filters);
			zephir_check_call_status();
			zephir_array_update_zval(&filtered, &_2$$7, &_3$$7, PH_COPY);
			break;
		}
		ZEPHIR_INIT_NVAR(&filtered);
		array_init(&filtered);
		break;
	} while(0);

	zephir_read_property(&_4, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&collection, &_4, "selectcollection", NULL, 0, &from);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &collection, "find", NULL, 0, &filtered, &fields);
	zephir_check_call_status();
	if (zephir_array_isset_string(&options, SL("order"))) {
		ZEPHIR_CPY_WRT(&tmp, &result);
		zephir_array_fetch_string(&_5$$9, &options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 133 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, &tmp, "sort", NULL, 0, &_5$$9);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&options, SL("limit"))) {
		ZEPHIR_CPY_WRT(&tmp, &result);
		zephir_array_fetch_string(&_6$$10, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 137 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, &tmp, "limit", NULL, 0, &_6$$10);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&options, SL("offset"))) {
		ZEPHIR_CPY_WRT(&tmp, &result);
		zephir_array_fetch_string(&_7$$11, &options, SL("offset"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 141 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, &tmp, "skip", NULL, 0, &_7$$11);
		zephir_check_call_status();
	}
	zephir_read_property(&_8, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_9, &_8, "lasterror", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_9);
	RETURN_CCTOR(result);

}

/**
 * INSERT document into collection.
 *
 * @param string from Collection name
 * @param array fields Fields to insert, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Mongo, insert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval *from_param = NULL, *fields_param = NULL, collection, status, _0, _1, _2, _3, _4;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
		zephir_get_arrval(&fields, fields_param);
	}


	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&collection, &_0, "selectcollection", NULL, 0, &from);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &collection, "insert", NULL, 0, &fields);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("id"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &fields, &_2, PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 161 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("lastInsertId"), &_1);
	zephir_update_property_zval(this_ptr, SL("error"), &status);
	ZEPHIR_INIT_VAR(&_3);
	zephir_array_fetch_string(&_4, &status, SL("err"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 164 TSRMLS_CC);
	if (Z_TYPE_P(&_4) == IS_NULL) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZEPHIR_CPY_WRT(&_3, &status);
	}
	RETURN_CCTOR(_3);

}

/**
 * UPDATE documents in the collection.
 *
 * @param string from Collection name
 * @param mixed filters Criteria
 * @param array fields Fields to update, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Mongo, update) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *fields_param = NULL, collection, status, _0, _1, _2;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &from_param, &filters, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
		zephir_get_arrval(&fields, fields_param);
	}


	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&collection, &_0, "selectcollection", NULL, 0, &from);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &collection, "update", NULL, 0, filters, &fields);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &status);
	ZEPHIR_INIT_VAR(&_1);
	zephir_array_fetch_string(&_2, &status, SL("err"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 182 TSRMLS_CC);
	if (Z_TYPE_P(&_2) == IS_NULL) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZEPHIR_CPY_WRT(&_1, &status);
	}
	RETURN_CCTOR(_1);

}

/**
 * Remove documents from the collection.
 *
 * @param string from Collection name
 * @param mixed filters Criteria
 */
PHP_METHOD(Ice_Db_Driver_Mongo, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *from_param = NULL, *filters = NULL, filters_sub, collection, status, _0, _1, _2;
	zval from;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &filters);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}


	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&collection, &_0, "selectcollection", NULL, 0, &from);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &collection, "remove", NULL, 0, filters);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &status);
	ZEPHIR_INIT_VAR(&_1);
	zephir_array_fetch_string(&_2, &status, SL("err"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 199 TSRMLS_CC);
	if (Z_TYPE_P(&_2) == IS_NULL) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZEPHIR_CPY_WRT(&_1, &status);
	}
	RETURN_CCTOR(_1);

}

/**
 * Get an error message.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Db_Driver_Mongo, getError) {

	zval error, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_string_fetch(&error, &_0, SL("err"), 1);
	RETURN_CTORW(error);

}

