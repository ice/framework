
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
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db_Driver_Mongo) {

	ZEPHIR_REGISTER_CLASS(Ice\\Db\\Driver, Mongo, ice, db_driver_mongo, ice_db_driver_mongo_method_entry, 0);

	zend_declare_property_string(ice_db_driver_mongo_ce, SL("_id"), "_id", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_db_driver_mongo_ce, SL("_type"), "NOSQL", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_mongo_ce, SL("_error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_mongo_ce, SL("_client"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_mongo_ce, SL("_lastInsertId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_db_driver_mongo_ce TSRMLS_CC, 1, ice_db_dbinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Db_Driver_Mongo, getId) {


	RETURN_MEMBER(this_ptr, "_id");

}

PHP_METHOD(Ice_Db_Driver_Mongo, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

PHP_METHOD(Ice_Db_Driver_Mongo, getClient) {


	RETURN_MEMBER(this_ptr, "_client");

}

PHP_METHOD(Ice_Db_Driver_Mongo, getLastInsertId) {


	RETURN_MEMBER(this_ptr, "_lastInsertId");

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
	zval *options = NULL;
	zval *dsn_param = NULL, *dbname_param = NULL, *options_param = NULL, *_0, *_1;
	zval *dsn = NULL, *dbname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &dsn_param, &dbname_param, &options_param);

	zephir_get_strval(dsn, dsn_param);
	if (!dbname_param) {
		ZEPHIR_INIT_VAR(dbname);
		ZVAL_EMPTY_STRING(dbname);
	} else {
		zephir_get_strval(dbname, dbname_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("mongodb") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("mongoclient") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, dsn, options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1, dbname);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_client"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

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
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *result = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		zephir_get_arrval(fields, fields_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_array_update_string(&options, SL("limit"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, from, filters, options, fields);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CALL_METHOD(&_2, result, "count", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		object_init_ex(_1, ice_arr_ce);
		ZEPHIR_CALL_METHOD(&_3, result, "getnext", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(_1, 0);
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
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *result = NULL, *_0 = NULL;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		zephir_get_arrval(fields, fields_param);
	}


	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, from, filters, options, fields);
	zephir_check_call_status();
	object_init_ex(return_value, ice_arr_ce);
	ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, result);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _0);
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
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *filtered = NULL, *collection = NULL, *result = NULL, *tmp = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6 = NULL;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		zephir_get_arrval(fields, fields_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, filters TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(_0, "array")) {
			ZEPHIR_CPY_WRT(filtered, filters);
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "integer") || ZEPHIR_IS_STRING(_0, "string")) {
			ZEPHIR_INIT_NVAR(filtered);
			array_init_size(filtered, 2);
			ZEPHIR_OBS_VAR(_1);
			zephir_read_property_this(&_1, this_ptr, SL("_id"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_2);
			object_init_ex(_2, zephir_get_internal_ce(SS("mongoid") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, filters);
			zephir_check_call_status();
			zephir_array_update_zval(&filtered, _1, &_2, PH_COPY);
			break;
		}
		ZEPHIR_INIT_NVAR(filtered);
		array_init(filtered);
		break;
	} while(0);

	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&collection, _3, "selectcollection", NULL, from);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, collection, "find", NULL, filtered, fields);
	zephir_check_call_status();
	if (zephir_array_isset_string(options, SS("order"))) {
		ZEPHIR_CPY_WRT(tmp, result);
		zephir_array_fetch_string(&_4, options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 113 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, tmp, "sort", NULL, _4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(options, SS("limit"))) {
		ZEPHIR_CPY_WRT(tmp, result);
		zephir_array_fetch_string(&_4, options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 117 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, tmp, "limit", NULL, _4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(options, SS("offset"))) {
		ZEPHIR_CPY_WRT(tmp, result);
		zephir_array_fetch_string(&_4, options, SL("offset"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 121 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, tmp, "skip", NULL, _4);
		zephir_check_call_status();
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_6, _5, "lasterror", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_error"), _6 TSRMLS_CC);
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
	zval *fields = NULL;
	zval *from_param = NULL, *fields_param = NULL, *collection = NULL, *status = NULL, *_0, *_1, *_2, *_3 = NULL, *_4;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		zephir_get_arrval(fields, fields_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&collection, _0, "selectcollection", NULL, from);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, collection, "insert", NULL, fields);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("_id"), PH_NOISY_CC);
	zephir_array_fetch(&_1, fields, _2, PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 141 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_lastInsertId"), _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_error"), status TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_array_fetch_string(&_4, status, SL("err"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 144 TSRMLS_CC);
	if (Z_TYPE_P(_4) == IS_NULL) {
		ZVAL_BOOL(_3, 1);
	} else {
		ZEPHIR_CPY_WRT(_3, status);
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
	zval *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *fields_param = NULL, *collection = NULL, *status = NULL, *_0, *_1 = NULL, *_2;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &from_param, &filters, &fields_param);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		zephir_get_arrval(fields, fields_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&collection, _0, "selectcollection", NULL, from);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, collection, "update", NULL, filters, fields);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_error"), status TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_array_fetch_string(&_2, status, SL("err"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 162 TSRMLS_CC);
	if (Z_TYPE_P(_2) == IS_NULL) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZEPHIR_CPY_WRT(_1, status);
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
	zval *from_param = NULL, *filters = NULL, *collection = NULL, *status = NULL, *_0, *_1 = NULL, *_2;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &filters);

	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&collection, _0, "selectcollection", NULL, from);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, collection, "remove", NULL, filters);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_error"), status TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_array_fetch_string(&_2, status, SL("err"), PH_NOISY | PH_READONLY, "ice/db/driver/mongo.zep", 179 TSRMLS_CC);
	if (Z_TYPE_P(_2) == IS_NULL) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZEPHIR_CPY_WRT(_1, status);
	}
	RETURN_CCTOR(_1);

}

/**
 * Get an error message.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Db_Driver_Mongo, getError) {

	zval *error, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_error"), PH_NOISY_CC);
	zephir_array_isset_string_fetch(&error, _0, SS("err"), 1 TSRMLS_CC);
	RETURN_CTORW(error);

}

