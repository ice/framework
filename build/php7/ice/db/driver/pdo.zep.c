
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/fcall.h"
#include "ext/date/php_date.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Pdo driver.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db_Driver_Pdo) {

	ZEPHIR_REGISTER_CLASS(Ice\\Db\\Driver, Pdo, ice, db_driver_pdo, ice_db_driver_pdo_method_entry, 0);

	zend_declare_property_string(ice_db_driver_pdo_ce, SL("id"), "id", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_db_driver_pdo_ce, SL("type"), "SQL", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_pdo_ce, SL("error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_pdo_ce, SL("client"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_pdo_ce, SL("driverName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_db_driver_pdo_ce, SL("identifier"), "\"%s\"", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_db_driver_pdo_ce TSRMLS_CC, 1, ice_db_dbinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Db_Driver_Pdo, getId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "id");

}

PHP_METHOD(Ice_Db_Driver_Pdo, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

PHP_METHOD(Ice_Db_Driver_Pdo, getClient) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "client");

}

PHP_METHOD(Ice_Db_Driver_Pdo, getDriverName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "driverName");

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *dsn_param = NULL, *user_param = NULL, *password_param = NULL, *options_param = NULL, _0, _1, _2, _9, _3$$3, _5$$4, _6$$5, _7$$6, _8$$7;
	zval dsn, user, password, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &dsn_param, &user_param, &password_param, &options_param);

	zephir_get_strval(&dsn, dsn_param);
	if (!user_param) {
		ZEPHIR_INIT_VAR(&user);
		ZVAL_STRING(&user, "");
	} else {
		zephir_get_strval(&user, user_param);
	}
	if (!password_param) {
		ZEPHIR_INIT_VAR(&password);
		ZVAL_STRING(&password, "");
	} else {
		zephir_get_strval(&password, password_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_explode_str(&_0, SL(":"), &dsn, 2  TSRMLS_CC);
	zephir_array_fetch_long(&_1, &_0, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 38 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("driverName"), &_1);
	zephir_read_property(&_2, this_ptr, SL("driverName"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_STRING(&_2, "mysql")) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "`%s`");
			zephir_update_property_zval(this_ptr, SL("identifier"), &_3$$3);
			ZEPHIR_INIT_VAR(&_4$$3);
			ZEPHIR_CONCAT_VS(&_4$$3, &dsn, ";charset=utf8");
			ZEPHIR_CPY_WRT(&dsn, &_4$$3);
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "sqlsrv")) {
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_INIT_NVAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "[%s]");
			zephir_update_property_zval(this_ptr, SL("identifier"), &_5$$4);
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "sqlite")) {
			ZEPHIR_INIT_VAR(&_6$$5);
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "[%s]");
			zephir_update_property_zval(this_ptr, SL("identifier"), &_6$$5);
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "oci")) {
			ZEPHIR_INIT_VAR(&_7$$6);
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZVAL_STRING(&_7$$6, "\"%s\"");
			zephir_update_property_zval(this_ptr, SL("identifier"), &_7$$6);
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "pgsql")) {
			ZEPHIR_INIT_VAR(&_8$$7);
			ZEPHIR_INIT_NVAR(&_8$$7);
			ZVAL_STRING(&_8$$7, "\"%s\"");
			zephir_update_property_zval(this_ptr, SL("identifier"), &_8$$7);
			break;
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_9);
	object_init_ex(&_9, php_pdo_get_dbh_ce());
	ZEPHIR_CALL_METHOD(NULL, &_9, "__construct", NULL, 0, &dsn, &user, &password, &options);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("client"), &_9);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the id value.
 *
 * @param string id
 * @return int
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getIdValue) {

	zval *id, id_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);

	zephir_fetch_params(0, 1, 0, &id);



	RETURN_LONG(zephir_get_intval(id));

}

/**
 * Get a date time object.
 *
 * @param mixed value
 * @param boolean model
 * @return object
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getDateTime) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, *model = NULL, model_sub, __$null, __$false, date, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&date);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &value, &model);

	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}
	if (!model) {
		model = &model_sub;
		model = &__$false;
	}


	if (Z_TYPE_P(value) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, "@", value);
		ZEPHIR_CPY_WRT(value, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&date);
	object_init_ex(&date, php_date_get_date_ce());
	ZEPHIR_CALL_METHOD(NULL, &date, "__construct", NULL, 0, value);
	zephir_check_call_status();
	if (zephir_is_true(model)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "Y-m-d H:i:s.u");
		ZEPHIR_RETURN_CALL_METHOD(&date, "format", NULL, 0, &_1$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&date);

}

/**
 * Find one row that match criteria.
 *
 * <pre><code>
 *  //SELECT x, y FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc Limit 1
 *  $db->findOne("users", ["OR" => [["a" => 1], ["b" => 2]]], ["order" => ["a desc", "b asc"]], ["x","y"]);
 * </code></pre>
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 * @return Arr|false
 */
PHP_METHOD(Ice_Db_Driver_Pdo, findOne) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, fields, _4$$4;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, result, _0, _1, _7, _8, _9, _10, _2$$3, _3$$4, _5$$4, _6$$5;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
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


	zephir_read_property(&_0, this_ptr, SL("driverName"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("driverName"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_0, "sqlsrv")) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_LONG(&_2$$3, 1);
		zephir_array_update_string(&options, SL("top"), &_2$$3, PH_COPY | PH_SEPARATE);
	} else if (ZEPHIR_IS_STRING(&_1, "oci")) {
		ZEPHIR_INIT_VAR(&_3$$4);
		if (ZEPHIR_IS_EMPTY(filters)) {
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "rownum=1");
		} else {
			ZEPHIR_INIT_NVAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_create_array(&_4$$4, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_4$$4, filters);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "rownum=1");
			zephir_array_fast_append(&_4$$4, &_5$$4);
			zephir_array_update_string(&_3$$4, SL("and"), &_4$$4, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_CPY_WRT(filters, &_3$$4);
	} else {
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_LONG(&_6$$5, 1);
		zephir_array_update_string(&options, SL("limit"), &_6$$5, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, &from, filters, &options, &fields);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CALL_METHOD(&_8, &result, "rowcount", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		object_init_ex(&_7, ice_arr_ce);
		ZVAL_LONG(&_10, 2);
		ZEPHIR_CALL_METHOD(&_9, &result, "fetch", NULL, 0, &_10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 4, &_9);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_7, 0);
	}
	RETURN_CCTOR(&_7);

}

/**
 * Find all records that match criteria.
 *
 * <pre><code>
 *  //SELECT * FROM users WHERE a=1 and b="q"
 *  $db->find("users", ["a" => 1, "b" => "q"]];
 *
 *  //SELECT * FROM users WHERE age>33
 *  $db->find("users", ["age" => [">" => 33]]];
 *
 *  //SELECT x, y FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc
 *  $db->find("users", ["OR" => [["a" => 1], ["b" => 2]]], ["order" => ["a desc", "b asc"]], ["x","y"]);
 * </code></pre>
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array options Options to limit[top]/group results
 * @param array fields Fields to retrieve, if not specified get all
 * @return Arr
 */
PHP_METHOD(Ice_Db_Driver_Pdo, find) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, result, _0, _1;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
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
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(&_0, &result, "fetchall", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 4, &_0);
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

	zend_string *_4$$4, *_13$$14;
	zend_ulong _3$$4, _12$$14;
	zend_long ZEPHIR_LAST_CALL_STATUS, _0$$3;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL, *_19 = NULL;
	zval values, _5$$8;
	zval *filters = NULL, filters_sub, *values_param = NULL, and, data, operator, key, item, value, or, is, index, i, sql, condition, _1, *_2$$4, _26$$4, tmp$$8, *_6$$5, _9$$10, _10$$12, j$$14, id$$14, ids$$14, *_11$$14, _16$$14, _14$$15, _15$$15, _17$$13, _18$$13, _20$$16, _21$$16, _22$$17, _23$$17, _24$$20, _25$$20, _27$$21, _28$$21, _29$$21, _30$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&and);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&or);
	ZVAL_UNDEF(&is);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&tmp$$8);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&j$$14);
	ZVAL_UNDEF(&id$$14);
	ZVAL_UNDEF(&ids$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_5$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &filters, &values_param);

	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	} else {
		ZEPHIR_SEPARATE_PARAM(filters);
	}
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}


	ZEPHIR_INIT_VAR(&and);
	array_init(&and);
	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "");
	ZEPHIR_INIT_VAR(&i);
	ZVAL_STRING(&i, "");
	if (zephir_is_numeric(filters)) {
		_0$$3 = zephir_get_intval(filters);
		ZEPHIR_INIT_NVAR(filters);
		ZVAL_LONG(filters, _0$$3);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_gettype(&_1, filters TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(&_1, "array")) {
			zephir_is_iterable(filters, 0, "ice/db/driver/pdo.zep", 254);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(filters), _3$$4, _4$$4, _2$$4)
			{
				ZEPHIR_INIT_NVAR(&operator);
				if (_4$$4 != NULL) { 
					ZVAL_STR_COPY(&operator, _4$$4);
				} else {
					ZVAL_LONG(&operator, _3$$4);
				}
				ZEPHIR_INIT_NVAR(&data);
				ZVAL_COPY(&data, _2$$4);
				do {
					if (ZEPHIR_IS_STRING(&operator, "OR") || ZEPHIR_IS_STRING(&operator, "or") || ZEPHIR_IS_STRING(&operator, "$or")) {
						ZEPHIR_INIT_NVAR(&or);
						array_init(&or);
						ZEPHIR_INIT_NVAR(&operator);
						ZVAL_STRING(&operator, "OR");
						break;
					}
					if (ZEPHIR_IS_STRING(&operator, "AND") || ZEPHIR_IS_STRING(&operator, "and") || ZEPHIR_IS_STRING(&operator, "$and")) {
						ZEPHIR_INIT_NVAR(&operator);
						ZVAL_STRING(&operator, "AND");
						break;
					}
					ZEPHIR_CPY_WRT(&tmp$$8, &data);
					ZEPHIR_INIT_NVAR(&data);
					zephir_create_array(&data, 1, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_5$$8);
					zephir_create_array(&_5$$8, 1, 0 TSRMLS_CC);
					zephir_array_update_zval(&_5$$8, &operator, &tmp$$8, PH_COPY);
					zephir_array_update_string(&data, SL("AND"), &_5$$8, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&operator);
					ZVAL_STRING(&operator, "AND");
					break;
				} while(0);

				zephir_is_iterable(&data, 0, "ice/db/driver/pdo.zep", 250);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _6$$5)
				{
					ZEPHIR_INIT_NVAR(&item);
					ZVAL_COPY(&item, _6$$5);
					ZEPHIR_CALL_FUNCTION(&key, "key", &_7, 95, &item);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&value, "current", &_8, 93, &item);
					zephir_check_call_status();
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEPHIR_CALL_FUNCTION(&is, "key", &_7, 95, &value);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_9$$10, "current", &_8, 93, &value);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&value, &_9$$10);
					} else {
						ZEPHIR_INIT_NVAR(&is);
						ZVAL_STRING(&is, "=");
					}
					do {
						ZEPHIR_INIT_NVAR(&index);
						ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
						ZEPHIR_INIT_LNVAR(_10$$12);
						if (zephir_is_true(&i)) {
							ZEPHIR_INIT_NVAR(&_10$$12);
							ZVAL_LONG(&_10$$12, (zephir_get_intval(&i) + 1));
						} else {
							ZEPHIR_INIT_NVAR(&_10$$12);
							ZVAL_LONG(&_10$$12, 1);
						}
						ZEPHIR_CPY_WRT(&i, &_10$$12);
					} while (zephir_array_isset(&values, &index));
					do {
						if (ZEPHIR_IS_STRING(&is, "IN") || ZEPHIR_IS_STRING(&is, "in") || ZEPHIR_IS_STRING(&is, "$in")) {
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&ids$$14);
								array_init(&ids$$14);
								zephir_is_iterable(&value, 0, "ice/db/driver/pdo.zep", 225);
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _12$$14, _13$$14, _11$$14)
								{
									ZEPHIR_INIT_NVAR(&j$$14);
									if (_13$$14 != NULL) { 
										ZVAL_STR_COPY(&j$$14, _13$$14);
									} else {
										ZVAL_LONG(&j$$14, _12$$14);
									}
									ZEPHIR_INIT_NVAR(&id$$14);
									ZVAL_COPY(&id$$14, _11$$14);
									ZEPHIR_INIT_LNVAR(_14$$15);
									ZEPHIR_CONCAT_VV(&_14$$15, &index, &j$$14);
									zephir_array_append(&ids$$14, &_14$$15, PH_SEPARATE, "ice/db/driver/pdo.zep", 221);
									ZEPHIR_INIT_LNVAR(_15$$15);
									ZEPHIR_CONCAT_VV(&_15$$15, &index, &j$$14);
									zephir_array_update_zval(&values, &_15$$15, &id$$14, PH_COPY | PH_SEPARATE);
								} ZEND_HASH_FOREACH_END();
								ZEPHIR_INIT_NVAR(&id$$14);
								ZEPHIR_INIT_NVAR(&j$$14);
								ZEPHIR_INIT_NVAR(&_16$$14);
								zephir_fast_join_str(&_16$$14, SL(", "), &ids$$14 TSRMLS_CC);
								ZEPHIR_INIT_NVAR(&value);
								ZEPHIR_CONCAT_SVS(&value, "(", &_16$$14, ")");
							}
							zephir_read_property(&_17$$13, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_FUNCTION(&_18$$13, "sprintf", &_19, 12, &_17$$13, &key);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&condition);
							ZEPHIR_CONCAT_VVSV(&condition, &_18$$13, &is, " ", &value);
							break;
						}
						if (ZEPHIR_IS_STRING(&is, "IS") || ZEPHIR_IS_STRING(&is, "is") || ZEPHIR_IS_STRING(&is, "IS NOT") || ZEPHIR_IS_STRING(&is, "is not")) {
							zephir_read_property(&_20$$16, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_FUNCTION(&_21$$16, "sprintf", &_19, 12, &_20$$16, &key);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&condition);
							ZEPHIR_CONCAT_VVSV(&condition, &_21$$16, &is, " ", &value);
							break;
						}
						zephir_read_property(&_22$$17, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_FUNCTION(&_23$$17, "sprintf", &_19, 12, &_22$$17, &key);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&condition);
						ZEPHIR_CONCAT_VVSV(&condition, &_23$$17, &is, " ", &index);
						zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
						break;
					} while(0);

					if (ZEPHIR_IS_STRING(&operator, "AND")) {
						zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 244);
					} else {
						zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 246);
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&item);
				if (ZEPHIR_IS_STRING(&operator, "OR")) {
					ZEPHIR_INIT_NVAR(&_24$$20);
					zephir_fast_join_str(&_24$$20, SL(" OR "), &or TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_25$$20);
					ZEPHIR_CONCAT_SVS(&_25$$20, "(", &_24$$20, ")");
					zephir_array_append(&and, &_25$$20, PH_SEPARATE, "ice/db/driver/pdo.zep", 251);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&data);
			ZEPHIR_INIT_NVAR(&operator);
			ZEPHIR_INIT_VAR(&_26$$4);
			zephir_fast_join_str(&_26$$4, SL(" AND "), &and TSRMLS_CC);
			zephir_concat_self(&sql, &_26$$4 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "integer")) {
			zephir_read_property(&_27$$21, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_28$$21, this_ptr, SL("id"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_29$$21, "sprintf", &_19, 12, &_27$$21, &_28$$21);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_30$$21);
			ZEPHIR_CONCAT_VSV(&_30$$21, &_29$$21, "=", filters);
			zephir_concat_self(&sql, &_30$$21 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "string")) {
			zephir_concat_self(&sql, filters TSRMLS_CC);
			break;
		}
		zephir_concat_self_str(&sql, SL("TRUE") TSRMLS_CC);
		break;
	} while(0);

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &sql);
	zephir_array_fast_append(return_value, &values);
	RETURN_MM();

}

/**
 * SELECT record(s) that match criteria.
 *
 * <pre><code>
 *  //SELECT * FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc LIMIT 10
 *  $db->select("users", ["OR" => [["a" => 1], ["b" => 2]]], ["order" => ["a desc", "b asc"], "limit" => 10]);
 *
 *  //SELECT top 10 x, y FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc
 *  $db->select("users", ["OR" => [["a" => 1], ["b" => 2]]], ["order" => ["a desc", "b asc"], "top" => 10], ["x","y"]);
 * </code></pre>
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array options Options to limit[top]/group results
 * @param array fields Fields to retrieve, if not specified get all
 */
PHP_METHOD(Ice_Db_Driver_Pdo, select) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, columns, filtered, values, query, sql, _3, _4, _5, _6, _23, _24, _0$$5, _1$$5, _7$$6, _8$$7, _9$$7, _10$$7, _11$$8, _12$$8, _13$$9, _14$$10, _15$$10, _16$$10, _17$$11, _18$$11, _19$$12, _20$$12, _21$$13, _22$$13;
	zval from, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
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


	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "SELECT ");
	if (zephir_fast_count_int(&fields TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&columns);
		zephir_fast_join_str(&columns, SL(", "), &fields TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&columns);
		ZVAL_STRING(&columns, "*");
	}
	if (zephir_array_isset_string(&options, SL("top"))) {
		ZEPHIR_OBS_VAR(&_0$$5);
		zephir_array_fetch_string(&_0$$5, &options, SL("top"), PH_NOISY, "ice/db/driver/pdo.zep", 298 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_1$$5);
		ZVAL_LONG(&_1$$5, zephir_get_intval(&_0$$5));
		ZEPHIR_INIT_VAR(&_2$$5);
		ZEPHIR_CONCAT_VS(&_2$$5, &_1$$5, " ");
		zephir_concat_self(&sql, &_2$$5 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 12, &_3, &from);
	zephir_check_call_status();
	zephir_array_fetch_long(&_5, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 302 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_VSVSV(&_6, &columns, " FROM ", &_4, " WHERE ", &_5);
	zephir_concat_self(&sql, &_6 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_long(&values, &filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 303 TSRMLS_CC);
	if (zephir_array_isset_string(&options, SL("group"))) {
		ZEPHIR_OBS_VAR(&_7$$6);
		zephir_array_fetch_string(&_7$$6, &options, SL("group"), PH_NOISY, "ice/db/driver/pdo.zep", 306 TSRMLS_CC);
		if (Z_TYPE_P(&_7$$6) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_8$$7);
			zephir_array_fetch_string(&_9$$7, &options, SL("group"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 307 TSRMLS_CC);
			zephir_fast_join_str(&_8$$7, SL(", "), &_9$$7 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_10$$7);
			ZEPHIR_CONCAT_SV(&_10$$7, " GROUP BY ", &_8$$7);
			zephir_concat_self(&sql, &_10$$7 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_11$$8, &options, SL("group"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 309 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_12$$8);
			ZEPHIR_CONCAT_SV(&_12$$8, " GROUP BY ", &_11$$8);
			zephir_concat_self(&sql, &_12$$8 TSRMLS_CC);
		}
	}
	if (zephir_array_isset_string(&options, SL("order"))) {
		ZEPHIR_OBS_VAR(&_13$$9);
		zephir_array_fetch_string(&_13$$9, &options, SL("order"), PH_NOISY, "ice/db/driver/pdo.zep", 313 TSRMLS_CC);
		if (Z_TYPE_P(&_13$$9) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_14$$10);
			zephir_array_fetch_string(&_15$$10, &options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 314 TSRMLS_CC);
			zephir_fast_join_str(&_14$$10, SL(", "), &_15$$10 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_16$$10);
			ZEPHIR_CONCAT_SV(&_16$$10, " ORDER BY ", &_14$$10);
			zephir_concat_self(&sql, &_16$$10 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_17$$11, &options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 316 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_18$$11);
			ZEPHIR_CONCAT_SV(&_18$$11, " ORDER BY ", &_17$$11);
			zephir_concat_self(&sql, &_18$$11 TSRMLS_CC);
		}
	}
	if (zephir_array_isset_string(&options, SL("limit"))) {
		zephir_array_fetch_string(&_19$$12, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 320 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_20$$12);
		ZEPHIR_CONCAT_SV(&_20$$12, " LIMIT ", &_19$$12);
		zephir_concat_self(&sql, &_20$$12 TSRMLS_CC);
	}
	if (zephir_array_isset_string(&options, SL("offset"))) {
		zephir_array_fetch_string(&_21$$13, &options, SL("offset"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 323 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_22$$13);
		ZEPHIR_CONCAT_SV(&_22$$13, " OFFSET ", &_21$$13);
		zephir_concat_self(&sql, &_22$$13 TSRMLS_CC);
	}
	zephir_read_property(&_23, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_23, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_24, &query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_24);
	RETURN_CCTOR(&query);

}

/**
 * INSERT record into table.
 *
 * <pre><code>
 *  //INSERT INTO users (a,b) VALUES (1, 2)
 *  $db->insert("users", [["a" => 1], ["b" => 2]]);
 * </code></pre>
 *
 * @param string from Table name
 * @param array fields Fields to insert, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Pdo, insert) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval fields;
	zval *from_param = NULL, *fields_param = NULL, key, value, columns, values, sql, query, status, *_0, _7, _8, _9, _10, _11, _12, _13, _3$$3, _4$$3, _6$$3;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
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


	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	zephir_is_iterable(&fields, 0, "ice/db/driver/pdo.zep", 358);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		zephir_read_property(&_3$$3, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", &_5, 12, &_3$$3, &key);
		zephir_check_call_status();
		zephir_array_append(&columns, &_4$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 354);
		ZEPHIR_INIT_LNVAR(_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, ":", &key);
		zephir_array_update_zval(&values, &_6$$3, &value, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_read_property(&_7, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_8, "sprintf", &_5, 12, &_7, &from);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	zephir_fast_join_str(&_9, SL(", "), &columns TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_INIT_VAR(&_11);
	zephir_array_keys(&_11, &values TSRMLS_CC);
	zephir_fast_join_str(&_10, SL(", "), &_11 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSVSVS(&sql, "INSERT INTO ", &_8, " (", &_9, ") VALUES (", &_10, ")");
	zephir_read_property(&_12, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_12, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_13, &query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_13);
	RETURN_CCTOR(&status);

}

/**
 * UPDATE records in the table.
 *
 * <pre><code>
 *  //UPDATE users SET a=1, b=2 WHERE id=10 OR foo="bar"
 *  $db->update("users", ["OR" => ["id" => 10, "foo" => "bar"]], [["a" => 1], ["b" => 2]]);
 * </code></pre>
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array fields Fields to update, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Pdo, update) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *fields_param = NULL, key, value, columns, values, filtered, sql, query, status, *_0, _8, _9, _10, _11, _12, _13, _14, _15, _3$$3, _4$$3, _5$$3, _7$$3;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &from_param, &filters, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
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


	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	zephir_is_iterable(&fields, 0, "ice/db/driver/pdo.zep", 390);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, ":", &key);
		zephir_array_update_zval(&values, &_3$$3, &value, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_4$$3, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", &_6, 12, &_4$$3, &key);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_7$$3);
		ZEPHIR_CONCAT_VSV(&_7$$3, &_5$$3, " = :", &key);
		zephir_array_append(&columns, &_7$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 387);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters, &values);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_6, 12, &_8, &from);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_10);
	zephir_fast_join_str(&_10, SL(", "), &columns TSRMLS_CC);
	zephir_array_fetch_long(&_11, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 391 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSVSV(&sql, "UPDATE ", &_9, " SET ", &_10, " WHERE ", &_11);
	ZEPHIR_INIT_VAR(&_12);
	zephir_array_fetch_long(&_13, &filtered, 1, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 392 TSRMLS_CC);
	zephir_fast_array_merge(&_12, &values, &_13 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&values, &_12);
	zephir_read_property(&_14, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_14, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_15, &query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_15);
	RETURN_CCTOR(&status);

}

/**
 * Remove records from the table.
 *
 * <pre><code>
 *  //DELETE FROM users WHERE id=10 OR foo="bar"
 *  $db->delete("users", ["OR" => ["id" => 10, "foo" => "bar"]]);
 * </code></pre>
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 */
PHP_METHOD(Ice_Db_Driver_Pdo, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *from_param = NULL, *filters = NULL, filters_sub, filtered, sql, values, query, status, _0, _1, _2, _3, _4;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &filters);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
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


	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", NULL, 12, &_0, &from);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 416 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSV(&sql, "DELETE FROM ", &_1, " WHERE ", &_2);
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_long(&values, &filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 417 TSRMLS_CC);
	zephir_read_property(&_3, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_3, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_4);
	RETURN_CCTOR(&status);

}

/**
 * Query sql statement. execute the statement and populate into Model object:
 *
 * <pre><code>
 *  //select * from t where id=1
 *  $m = $this->db->query('select * from t where id=:id', [':id' => 1], new stdClass);
 *
 *  //select * from t where id=1 OR foo='bar'
 *  $m = $this->db->query('select * from t where id=? OR foo=?', [1, "bar"], new stdClass);
 * </code></pre>
 *
 * @param string sql SQL with kinda of placeholders
 * @param array values Replace placeholders in the sql
 * @param mixed obj The object will be populated from query result
 * @return PDOStatement|object|null
 */
PHP_METHOD(Ice_Db_Driver_Pdo, query) {

	zend_class_entry *_5$$4;
	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values, _8$$8;
	zval *sql_param = NULL, *values_param = NULL, *obj = NULL, obj_sub, __$null, query, result, _0, _1, _2, _4$$4, _6$$5, _7$$8, _9$$8;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&obj_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_8$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sql_param, &values_param, &obj);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(&sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(&sql);
		ZVAL_EMPTY_STRING(&sql);
	}
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}
	if (!obj) {
		obj = &obj_sub;
		ZEPHIR_CPY_WRT(obj, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(obj);
	}


	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_0, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_1);
	zephir_read_property(&_2, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
	_3 = ZEPHIR_IS_EMPTY(&_2);
	if (_3) {
		_3 = zephir_is_true(obj);
	}
	if (_3) {
		if (Z_TYPE_P(obj) == IS_STRING) {
			ZEPHIR_INIT_NVAR(obj);
			zephir_fetch_safe_class(&_4$$4, obj);
			_5$$4 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_4$$4), Z_STRLEN_P(&_4$$4), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(obj, _5$$4);
			if (zephir_has_constructor(obj TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, obj, "__construct", NULL, 0);
				zephir_check_call_status();
			}
		}
		if (zephir_instance_of_ev(obj, ice_arr_ce TSRMLS_CC)) {
			ZVAL_LONG(&_6$$5, 2);
			ZEPHIR_CALL_METHOD(&result, &query, "fetch", NULL, 0, &_6$$5);
			zephir_check_call_status();
			if (zephir_is_true(&result)) {
				ZEPHIR_CALL_METHOD(NULL, obj, "replace", NULL, 0, &result);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(obj);
				ZVAL_NULL(obj);
			}
			RETVAL_ZVAL(obj, 1, 0);
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(&_7$$8);
			object_init_ex(&_7$$8, ice_exception_ce);
			ZEPHIR_INIT_VAR(&_8$$8);
			zephir_create_array(&_8$$8, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_9$$8);
			ZVAL_STRING(&_9$$8, "Only instance of Arr is allowed for populate the result. %s given");
			zephir_array_fast_append(&_8$$8, &_9$$8);
			ZEPHIR_INIT_NVAR(&_9$$8);
			zephir_get_class(&_9$$8, obj, 0 TSRMLS_CC);
			zephir_array_fast_append(&_8$$8, &_9$$8);
			ZEPHIR_CALL_METHOD(NULL, &_7$$8, "__construct", NULL, 13, &_8$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$8, "ice/db/driver/pdo.zep", 464 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&query);

}

/**
 * Get last inserted ID.
 *
 * @return int
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getLastInsertId) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "lastinsertid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(&_1));

}

/**
 * Get an error message.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getError) {

	zval error, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_long_fetch(&error, &_0, 0, 1 TSRMLS_CC);
	RETURN_CTORW(&error);

}

