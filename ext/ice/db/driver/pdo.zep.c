
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/pdo/php_pdo_driver.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


/**
 * Pdo driver.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db_Driver_Pdo) {

	ZEPHIR_REGISTER_CLASS(Ice\\Db\\Driver, Pdo, ice, db_driver_pdo, ice_db_driver_pdo_method_entry, 0);

	zend_declare_property_string(ice_db_driver_pdo_ce, SL("id"), "id", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_db_driver_pdo_ce, SL("type"), "SQL", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_pdo_ce, SL("error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_pdo_ce, SL("client"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_db_driver_pdo_ce TSRMLS_CC, 1, ice_db_dbinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Db_Driver_Pdo, getId) {


	RETURN_MEMBER(this_ptr, "id");

}

PHP_METHOD(Ice_Db_Driver_Pdo, getType) {


	RETURN_MEMBER(this_ptr, "type");

}

PHP_METHOD(Ice_Db_Driver_Pdo, getClient) {


	RETURN_MEMBER(this_ptr, "client");

}

/**
 * Instantiate pdo connection.
 *
 * @param string dsn
 * @param string user
 * @param string password
 * @param array options
 */
PHP_METHOD(Ice_Db_Driver_Pdo, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _2;
	zval *options = NULL;
	zval *dsn_param = NULL, *user_param = NULL, *password_param = NULL, *options_param = NULL, *parts, *_0, _1, *_3, _4, *_5 = NULL, *_6 = NULL;
	zval *dsn = NULL, *user = NULL, *password = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &dsn_param, &user_param, &password_param, &options_param);

	zephir_get_strval(dsn, dsn_param);
	if (!user_param) {
		ZEPHIR_INIT_VAR(user);
		ZVAL_EMPTY_STRING(user);
	} else {
		zephir_get_strval(user, user_param);
	}
	if (!password_param) {
		ZEPHIR_INIT_VAR(password);
		ZVAL_EMPTY_STRING(password);
	} else {
		zephir_get_strval(password, password_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(parts);
	array_init(parts);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/^.+?(?:dbname|database)=(.+?)(?=;|$)/i", 0);
	zephir_preg_match(_0, &_1, dsn, parts, 0, 0 , 0  TSRMLS_CC);
	_2 = zephir_array_isset_long(parts, 0);
	if (_2) {
		zephir_array_fetch_long(&_3, parts, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 40 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, ":", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "strstr", NULL, 74, _3, &_4, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_2 = ZEPHIR_IS_STRING(_5, "mysql");
	}
	if (_2) {
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "SET NAMES utf8;", 1);
		zephir_array_update_long(&options, 1002, &_6, PH_COPY | PH_SEPARATE, "ice/db/driver/pdo.zep", 41);
	}
	ZEPHIR_INIT_NVAR(_6);
	object_init_ex(_6, php_pdo_get_dbh_ce());
	ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 0, dsn, user, password, options);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("client"), _6 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the id value.
 *
 * @param string id
 * @return int
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getIdValue) {

	zval *id;

	zephir_fetch_params(0, 1, 0, &id);



	RETURN_LONG(zephir_get_intval(id));

}

/**
 * Find one row that match criteria.
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 * @return Arr|false
 */
PHP_METHOD(Ice_Db_Driver_Pdo, findOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *result = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4;
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
	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, from, filters, options, fields);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CALL_METHOD(&_2, result, "rowcount", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		object_init_ex(_1, ice_arr_ce);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 2);
		ZEPHIR_CALL_METHOD(&_3, result, "fetch", NULL, 0, _4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 6, _3);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(_1, 0);
	}
	RETURN_CCTOR(_1);

}

/**
 * Find all records that match criteria.
 *
 * <pre><code>
 *  //SELECT * FROM users WHERE a=1 and b="q"
 *  $db->find("users", array("a" => 1, "b" => "q"));
 * 
 *  //SELECT * FROM users WHERE age>33 
 *  $db->find("users", array("age" => array(">" => 33)));
 * 
 *  //SELECT * FROM users WHERE a=1 or b=2 
 *  $db->find("users", array("OR" => array(array("a" => 1), array("b" => 2))));
 * </code></pre>
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 * @return Arr
 */
PHP_METHOD(Ice_Db_Driver_Pdo, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *result = NULL, *_0 = NULL, *_1;
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


	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, from, filters, options, fields);
	zephir_check_call_status();
	object_init_ex(return_value, ice_arr_ce);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_METHOD(&_0, result, "fetchall", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 6, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepare SQL WHERE condition.
 *
 * @params mixed filters
 * @params array values
 */
PHP_METHOD(Ice_Db_Driver_Pdo, where) {

	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL;
	HashTable *_3, *_6, *_15;
	HashPosition _2, _5, _14;
	int _0, ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *filters = NULL, *values_param = NULL, *and, *data = NULL, *operator = NULL, *key = NULL, *item = NULL, *value = NULL, *or = NULL, *is = NULL, *index = NULL, *i = NULL, *sql, *_1, **_4, **_7, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, **_16;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &filters, &values_param);

	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	} else {
		ZEPHIR_SEPARATE_PARAM(filters);
	}
	if (!values_param) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	} else {
		zephir_get_arrval(values, values_param);
	}


	ZEPHIR_INIT_VAR(and);
	array_init(and);
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "", 1);
	ZEPHIR_INIT_VAR(i);
	ZVAL_STRING(i, "", 1);
	if (zephir_is_numeric(filters)) {
		_0 = zephir_get_intval(filters);
		ZEPHIR_INIT_NVAR(filters);
		ZVAL_LONG(filters, _0);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_gettype(_1, filters TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(_1, "array")) {
			zephir_is_iterable(filters, &_3, &_2, 0, 0, "ice/db/driver/pdo.zep", 198);
			for (
			  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			  ; zephir_hash_move_forward_ex(_3, &_2)
			) {
				ZEPHIR_GET_HMKEY(operator, _3, _2);
				ZEPHIR_GET_HVALUE(data, _4);
				do {
					if (ZEPHIR_IS_STRING(operator, "OR") || ZEPHIR_IS_STRING(operator, "or") || ZEPHIR_IS_STRING(operator, "$or")) {
						ZEPHIR_INIT_NVAR(or);
						array_init(or);
						zephir_is_iterable(data, &_6, &_5, 0, 0, "ice/db/driver/pdo.zep", 151);
						for (
						  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
						  ; zephir_hash_move_forward_ex(_6, &_5)
						) {
							ZEPHIR_GET_HVALUE(item, _7);
							Z_SET_ISREF_P(item);
							ZEPHIR_CALL_FUNCTION(&key, "key", &_8, 75, item);
							Z_UNSET_ISREF_P(item);
							zephir_check_call_status();
							Z_SET_ISREF_P(item);
							ZEPHIR_CALL_FUNCTION(&value, "current", &_9, 76, item);
							Z_UNSET_ISREF_P(item);
							zephir_check_call_status();
							if (Z_TYPE_P(value) == IS_ARRAY) {
								Z_SET_ISREF_P(value);
								ZEPHIR_CALL_FUNCTION(&is, "key", &_8, 75, value);
								Z_UNSET_ISREF_P(value);
								zephir_check_call_status();
								Z_SET_ISREF_P(value);
								ZEPHIR_CALL_FUNCTION(&_10, "current", &_9, 76, value);
								Z_UNSET_ISREF_P(value);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(value, _10);
							} else {
								ZEPHIR_INIT_NVAR(is);
								ZVAL_STRING(is, "=", 1);
							}
							do {
								ZEPHIR_INIT_NVAR(index);
								ZEPHIR_CONCAT_SVV(index, ":", key, i);
								ZEPHIR_INIT_LNVAR(_11);
								if (zephir_is_true(i)) {
									ZEPHIR_INIT_NVAR(_11);
									ZVAL_LONG(_11, (zephir_get_intval(i) + 1));
								} else {
									ZEPHIR_INIT_NVAR(_11);
									ZVAL_LONG(_11, 1);
								}
								ZEPHIR_CPY_WRT(i, _11);
							} while (zephir_array_isset(values, index));
							ZEPHIR_INIT_LNVAR(_11);
							ZEPHIR_CONCAT_SVSVSV(_11, "`", key, "` ", is, " ", index);
							zephir_array_append(&or, _11, PH_SEPARATE, "ice/db/driver/pdo.zep", 148);
							zephir_array_update_zval(&values, index, &value, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_INIT_NVAR(_12);
						zephir_fast_join_str(_12, SL(" OR "), or TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_13);
						ZEPHIR_CONCAT_SVS(_13, "(", _12, ")");
						zephir_array_append(&and, _13, PH_SEPARATE, "ice/db/driver/pdo.zep", 151);
						break;
					}
					if (ZEPHIR_IS_STRING(operator, "AND") || ZEPHIR_IS_STRING(operator, "and") || ZEPHIR_IS_STRING(operator, "$and")) {
						zephir_is_iterable(data, &_15, &_14, 0, 0, "ice/db/driver/pdo.zep", 175);
						for (
						  ; zephir_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
						  ; zephir_hash_move_forward_ex(_15, &_14)
						) {
							ZEPHIR_GET_HVALUE(item, _16);
							Z_SET_ISREF_P(item);
							ZEPHIR_CALL_FUNCTION(&key, "key", &_8, 75, item);
							Z_UNSET_ISREF_P(item);
							zephir_check_call_status();
							Z_SET_ISREF_P(item);
							ZEPHIR_CALL_FUNCTION(&value, "current", &_9, 76, item);
							Z_UNSET_ISREF_P(item);
							zephir_check_call_status();
							if (Z_TYPE_P(value) == IS_ARRAY) {
								Z_SET_ISREF_P(value);
								ZEPHIR_CALL_FUNCTION(&is, "key", &_8, 75, value);
								Z_UNSET_ISREF_P(value);
								zephir_check_call_status();
								Z_SET_ISREF_P(value);
								ZEPHIR_CALL_FUNCTION(&_10, "current", &_9, 76, value);
								Z_UNSET_ISREF_P(value);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(value, _10);
							} else {
								ZEPHIR_INIT_NVAR(is);
								ZVAL_STRING(is, "=", 1);
							}
							do {
								ZEPHIR_INIT_NVAR(index);
								ZEPHIR_CONCAT_SVV(index, ":", key, i);
								ZEPHIR_INIT_LNVAR(_11);
								if (zephir_is_true(i)) {
									ZEPHIR_INIT_NVAR(_11);
									ZVAL_LONG(_11, (zephir_get_intval(i) + 1));
								} else {
									ZEPHIR_INIT_NVAR(_11);
									ZVAL_LONG(_11, 1);
								}
								ZEPHIR_CPY_WRT(i, _11);
							} while (zephir_array_isset(values, index));
							ZEPHIR_INIT_LNVAR(_11);
							ZEPHIR_CONCAT_SVSVSV(_11, "`", key, "` ", is, " ", index);
							zephir_array_append(&and, _11, PH_SEPARATE, "ice/db/driver/pdo.zep", 172);
							zephir_array_update_zval(&values, index, &value, PH_COPY | PH_SEPARATE);
						}
						break;
					}
					ZEPHIR_CPY_WRT(key, operator);
					ZEPHIR_CPY_WRT(value, data);
					if (Z_TYPE_P(value) == IS_ARRAY) {
						Z_SET_ISREF_P(value);
						ZEPHIR_CALL_FUNCTION(&is, "key", &_8, 75, value);
						Z_UNSET_ISREF_P(value);
						zephir_check_call_status();
						Z_SET_ISREF_P(value);
						ZEPHIR_CALL_FUNCTION(&_10, "current", &_9, 76, value);
						Z_UNSET_ISREF_P(value);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(value, _10);
					} else {
						ZEPHIR_INIT_NVAR(is);
						ZVAL_STRING(is, "=", 1);
					}
					do {
						ZEPHIR_INIT_NVAR(index);
						ZEPHIR_CONCAT_SVV(index, ":", key, i);
						ZEPHIR_INIT_LNVAR(_13);
						if (zephir_is_true(i)) {
							ZEPHIR_INIT_NVAR(_13);
							ZVAL_LONG(_13, (zephir_get_intval(i) + 1));
						} else {
							ZEPHIR_INIT_NVAR(_13);
							ZVAL_LONG(_13, 1);
						}
						ZEPHIR_CPY_WRT(i, _13);
					} while (zephir_array_isset(values, index));
					ZEPHIR_INIT_LNVAR(_13);
					ZEPHIR_CONCAT_SVSVSV(_13, "`", key, "` ", is, " ", index);
					zephir_array_append(&and, _13, PH_SEPARATE, "ice/db/driver/pdo.zep", 193);
					zephir_array_update_zval(&values, index, &value, PH_COPY | PH_SEPARATE);
					break;
				} while(0);

			}
			ZEPHIR_INIT_NVAR(_12);
			zephir_fast_join_str(_12, SL(" AND "), and TSRMLS_CC);
			zephir_concat_self(&sql, _12 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "integer")) {
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_SV(_13, "`id` = ", filters);
			zephir_concat_self(&sql, _13 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "string")) {
			zephir_concat_self(&sql, filters TSRMLS_CC);
			break;
		}
		zephir_concat_self_str(&sql, SL("TRUE") TSRMLS_CC);
		break;
	} while(0);

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, sql);
	zephir_array_fast_append(return_value, values);
	RETURN_MM();

}

/**
 * SELECT record(s) that match criteria.
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 */
PHP_METHOD(Ice_Db_Driver_Pdo, select) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *columns = NULL, *sql, *filtered = NULL, *values, *query = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4, *_5 = NULL;
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


	if (zephir_fast_count_int(fields TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(columns);
		zephir_fast_join_str(columns, SL(", "), fields TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(columns);
		ZVAL_STRING(columns, "*", 1);
	}
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 77, filters);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 233 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSVSV(sql, "SELECT ", columns, " FROM `", from, "` WHERE ", _0);
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_long(&values, filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 234 TSRMLS_CC);
	if (zephir_array_isset_string(options, SS("group"))) {
		ZEPHIR_INIT_VAR(_1);
		zephir_array_fetch_string(&_2, options, SL("group"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 237 TSRMLS_CC);
		zephir_fast_join_str(_1, SL(", "), _2 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SV(_3, " GROUP BY ", _1);
		zephir_concat_self(&sql, _3 TSRMLS_CC);
	}
	if (zephir_array_isset_string(options, SS("order"))) {
		ZEPHIR_INIT_NVAR(_1);
		zephir_array_fetch_string(&_2, options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 240 TSRMLS_CC);
		zephir_fast_join_str(_1, SL(", "), _2 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SV(_3, " ORDER BY ", _1);
		zephir_concat_self(&sql, _3 TSRMLS_CC);
	}
	if (zephir_array_isset_string(options, SS("limit"))) {
		zephir_array_fetch_string(&_2, options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 243 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SV(_3, " LIMIT ", _2);
		zephir_concat_self(&sql, _3 TSRMLS_CC);
	}
	if (zephir_array_isset_string(options, SS("offset"))) {
		zephir_array_fetch_string(&_2, options, SL("offset"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 246 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SV(_3, " OFFSET ", _2);
		zephir_concat_self(&sql, _3 TSRMLS_CC);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _4, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("error"), _5 TSRMLS_CC);
	RETURN_CCTOR(query);

}

/**
 * INSERT record into table.
 *
 * @param string from Table name
 * @param array fields Fields to insert, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Pdo, insert) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *fields = NULL;
	zval *from_param = NULL, *fields_param = NULL, *key = NULL, *value = NULL, *columns, *values, *sql, *query = NULL, *status = NULL, **_2, *_3 = NULL, *_4 = NULL, *_5, *_6, *_7, *_8, *_9 = NULL;
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


	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	zephir_is_iterable(fields, &_1, &_0, 0, 0, "ice/db/driver/pdo.zep", 276);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "`", key, "`");
		zephir_array_append(&columns, _3, PH_SEPARATE, "ice/db/driver/pdo.zep", 272);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, ":", key);
		zephir_array_update_zval(&values, _4, &value, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), columns TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_INIT_VAR(_7);
	zephir_array_keys(_7, values TSRMLS_CC);
	zephir_fast_join_str(_6, SL(", "), _7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSVSVS(sql, "INSERT INTO `", from, "` (", _5, ") VALUES (", _6, ")");
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _8, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("error"), _9 TSRMLS_CC);
	RETURN_CCTOR(status);

}

/**
 * UPDATE records in the table.
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array fields Fields to update, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Pdo, update) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *fields_param = NULL, *key = NULL, *value = NULL, *columns, *values = NULL, *filtered = NULL, *sql, *query = NULL, *status = NULL, **_2, *_3 = NULL, *_4 = NULL, *_5, *_6, *_7, *_8, *_9, *_10 = NULL;
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


	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	zephir_is_iterable(fields, &_1, &_0, 0, 0, "ice/db/driver/pdo.zep", 303);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SV(_3, ":", key);
		zephir_array_update_zval(&values, _3, &value, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVSV(_4, "`", key, "` = :", key);
		zephir_array_append(&columns, _4, PH_SEPARATE, "ice/db/driver/pdo.zep", 300);
	}
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 77, filters, values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), columns TSRMLS_CC);
	zephir_array_fetch_long(&_6, filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 304 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSVSV(sql, "UPDATE `", from, "` SET ", _5, " WHERE ", _6);
	ZEPHIR_INIT_VAR(_7);
	zephir_array_fetch_long(&_8, filtered, 1, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 305 TSRMLS_CC);
	zephir_fast_array_merge(_7, &(values), &(_8) TSRMLS_CC);
	ZEPHIR_CPY_WRT(values, _7);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _9, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("error"), _10 TSRMLS_CC);
	RETURN_CCTOR(status);

}

/**
 * Remove records from the table.
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 */
PHP_METHOD(Ice_Db_Driver_Pdo, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *from_param = NULL, *filters = NULL, *filtered = NULL, *sql, *values, *query = NULL, *status = NULL, *_0, *_1, *_2 = NULL;
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


	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 77, filters);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 324 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSV(sql, "DELETE FROM `", from, "` WHERE ", _0);
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_long(&values, filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 325 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _1, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("error"), _2 TSRMLS_CC);
	RETURN_CCTOR(status);

}

/**
 * Get last inserted ID.
 *
 * @return int
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getLastInsertId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "lastinsertid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(_1));

}

/**
 * Get an error message.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getError) {

	zval *error, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("error"), PH_NOISY_CC);
	zephir_array_isset_long_fetch(&error, _0, 0, 1 TSRMLS_CC);
	RETURN_CTORW(error);

}

