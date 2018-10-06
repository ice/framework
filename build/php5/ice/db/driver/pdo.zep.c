
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

	zend_declare_property_string(ice_db_driver_pdo_ce, SL("identifier"), "\"%s\"", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_db_driver_pdo_ce TSRMLS_CC, 1, ice_db_dbinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Db_Driver_Pdo, getId) {

	

	RETURN_MEMBER(getThis(), "id");

}

PHP_METHOD(Ice_Db_Driver_Pdo, getType) {

	

	RETURN_MEMBER(getThis(), "type");

}

PHP_METHOD(Ice_Db_Driver_Pdo, getClient) {

	

	RETURN_MEMBER(getThis(), "client");

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

	zend_class_entry *_9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *dsn_param = NULL, *user_param = NULL, *password_param = NULL, *options_param = NULL, *driver = NULL, *pdo = NULL, *_0, *_7, *_8 = NULL, *_1$$3, *_3$$4, *_4$$5, *_5$$6, *_6$$7;
	zval *dsn = NULL, *user = NULL, *password = NULL, *_2$$3;

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


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_explode_str(_0, SL(":"), dsn, 2  TSRMLS_CC);
	ZEPHIR_OBS_VAR(driver);
	zephir_array_fetch_long(&driver, _0, 0, PH_NOISY, "ice/db/driver/pdo.zep", 39 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(driver, "mysql")) {
			ZEPHIR_INIT_ZVAL_NREF(_1$$3);
			ZVAL_STRING(_1$$3, "`%s`", 1);
			zephir_update_property_this(getThis(), SL("identifier"), _1$$3 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_2$$3);
			ZEPHIR_CONCAT_VS(_2$$3, dsn, ";charset=utf8");
			ZEPHIR_CPY_WRT(dsn, _2$$3);
			break;
		}
		if (ZEPHIR_IS_STRING(driver, "sqlsrv")) {
			ZEPHIR_INIT_ZVAL_NREF(_3$$4);
			ZVAL_STRING(_3$$4, "[%s]", 1);
			zephir_update_property_this(getThis(), SL("identifier"), _3$$4 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(driver, "sqlite")) {
			ZEPHIR_INIT_ZVAL_NREF(_4$$5);
			ZVAL_STRING(_4$$5, "[%s]", 1);
			zephir_update_property_this(getThis(), SL("identifier"), _4$$5 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(driver, "oci")) {
			ZEPHIR_INIT_ZVAL_NREF(_5$$6);
			ZVAL_STRING(_5$$6, "\"%s\"", 1);
			zephir_update_property_this(getThis(), SL("identifier"), _5$$6 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(driver, "pgsql")) {
			ZEPHIR_INIT_ZVAL_NREF(_6$$7);
			ZVAL_STRING(_6$$7, "\"%s\"", 1);
			zephir_update_property_this(getThis(), SL("identifier"), _6$$7 TSRMLS_CC);
			break;
		}
	} while(0);

	ZEPHIR_INIT_VAR(pdo);
	ZVAL_STRING(pdo, "Pdo", 1);
	ZEPHIR_INIT_VAR(_7);
	zephir_fetch_safe_class(_8, pdo);
		_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_7, _9);
	ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 0, dsn, user, password, options);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("client"), _7 TSRMLS_CC);
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
 * Get a date time object.
 *
 * @param mixed value
 * @param boolean model
 * @return object
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getDateTime) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, *model = NULL, *date = NULL, *_0$$3, *_1$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &value, &model);

	if (!value) {
		ZEPHIR_CPY_WRT(value, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}
	if (!model) {
		model = ZEPHIR_GLOBAL(global_false);
	}


	if (Z_TYPE_P(value) == IS_LONG) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_SV(_0$$3, "@", value);
		ZEPHIR_CPY_WRT(value, _0$$3);
	}
	ZEPHIR_INIT_VAR(date);
	object_init_ex(date, php_date_get_date_ce());
	ZEPHIR_CALL_METHOD(NULL, date, "__construct", NULL, 0, value);
	zephir_check_call_status();
	if (zephir_is_true(model)) {
		ZEPHIR_INIT_VAR(_1$$4);
		ZVAL_STRING(_1$$4, "Y-m-d H:i:s.u", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_RETURN_CALL_METHOD(date, "format", NULL, 0, _1$$4);
		zephir_check_temp_parameter(_1$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(date);

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *result = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
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
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 5, _3);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *result = NULL, *_0 = NULL, *_1;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 5, _0);
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

	HashTable *_3$$4, *_7$$5, *_14$$14;
	HashPosition _2$$4, _6$$5, _13$$14;
	zend_long ZEPHIR_LAST_CALL_STATUS, _0$$3;
	zephir_fcall_cache_entry *_9 = NULL, *_10 = NULL, *_21 = NULL;
	zval *values = NULL, *_5$$8 = NULL;
	zval *filters = NULL, *values_param = NULL, *and = NULL, *data = NULL, *operator = NULL, *key = NULL, *item = NULL, *value = NULL, *or = NULL, *is = NULL, *index = NULL, *i = NULL, *sql = NULL, *condition = NULL, *_1, **_4$$4, *_28$$4, *tmp$$8 = NULL, **_8$$5, *_11$$10 = NULL, *_12$$12 = NULL, *j$$14 = NULL, *id$$14 = NULL, *ids$$14 = NULL, **_15$$14, *_18$$14 = NULL, *_16$$15 = NULL, *_17$$15 = NULL, *_19$$13, *_20$$13 = NULL, *_22$$16, *_23$$16 = NULL, *_24$$17, *_25$$17 = NULL, *_26$$20 = NULL, *_27$$20 = NULL, *_29$$21, *_30$$21, *_31$$21 = NULL, *_32$$21;

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
		_0$$3 = zephir_get_intval(filters);
		ZEPHIR_INIT_NVAR(filters);
		ZVAL_LONG(filters, _0$$3);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_gettype(_1, filters TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(_1, "array")) {
			zephir_is_iterable(filters, &_3$$4, &_2$$4, 0, 0, "ice/db/driver/pdo.zep", 244);
			for (
			  ; zend_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_3$$4, &_2$$4)
			) {
				ZEPHIR_GET_HMKEY(operator, _3$$4, _2$$4);
				ZEPHIR_GET_HVALUE(data, _4$$4);
				do {
					if (ZEPHIR_IS_STRING(operator, "OR") || ZEPHIR_IS_STRING(operator, "or") || ZEPHIR_IS_STRING(operator, "$or")) {
						ZEPHIR_INIT_NVAR(or);
						array_init(or);
						ZEPHIR_INIT_NVAR(operator);
						ZVAL_STRING(operator, "OR", 1);
						break;
					}
					if (ZEPHIR_IS_STRING(operator, "AND") || ZEPHIR_IS_STRING(operator, "and") || ZEPHIR_IS_STRING(operator, "$and")) {
						ZEPHIR_INIT_NVAR(operator);
						ZVAL_STRING(operator, "AND", 1);
						break;
					}
					ZEPHIR_CPY_WRT(tmp$$8, data);
					ZEPHIR_INIT_NVAR(data);
					zephir_create_array(data, 1, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_5$$8);
					zephir_create_array(_5$$8, 1, 0 TSRMLS_CC);
					zephir_array_update_zval(&_5$$8, operator, &tmp$$8, PH_COPY);
					zephir_array_update_string(&data, SL("AND"), &_5$$8, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(operator);
					ZVAL_STRING(operator, "AND", 1);
					break;
				} while(0);

				zephir_is_iterable(data, &_7$$5, &_6$$5, 0, 0, "ice/db/driver/pdo.zep", 240);
				for (
				  ; zend_hash_get_current_data_ex(_7$$5, (void**) &_8$$5, &_6$$5) == SUCCESS
				  ; zend_hash_move_forward_ex(_7$$5, &_6$$5)
				) {
					ZEPHIR_GET_HVALUE(item, _8$$5);
					ZEPHIR_MAKE_REF(item);
					ZEPHIR_CALL_FUNCTION(&key, "key", &_9, 107, item);
					ZEPHIR_UNREF(item);
					zephir_check_call_status();
					ZEPHIR_MAKE_REF(item);
					ZEPHIR_CALL_FUNCTION(&value, "current", &_10, 105, item);
					ZEPHIR_UNREF(item);
					zephir_check_call_status();
					if (Z_TYPE_P(value) == IS_ARRAY) {
						ZEPHIR_MAKE_REF(value);
						ZEPHIR_CALL_FUNCTION(&is, "key", &_9, 107, value);
						ZEPHIR_UNREF(value);
						zephir_check_call_status();
						ZEPHIR_MAKE_REF(value);
						ZEPHIR_CALL_FUNCTION(&_11$$10, "current", &_10, 105, value);
						ZEPHIR_UNREF(value);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(value, _11$$10);
					} else {
						ZEPHIR_INIT_NVAR(is);
						ZVAL_STRING(is, "=", 1);
					}
					do {
						ZEPHIR_INIT_NVAR(index);
						ZEPHIR_CONCAT_SVV(index, ":", key, i);
						ZEPHIR_INIT_LNVAR(_12$$12);
						if (zephir_is_true(i)) {
							ZEPHIR_INIT_NVAR(_12$$12);
							ZVAL_LONG(_12$$12, (zephir_get_intval(i) + 1));
						} else {
							ZEPHIR_INIT_NVAR(_12$$12);
							ZVAL_LONG(_12$$12, 1);
						}
						ZEPHIR_CPY_WRT(i, _12$$12);
					} while (zephir_array_isset(values, index));
					do {
						if (ZEPHIR_IS_STRING(is, "IN") || ZEPHIR_IS_STRING(is, "in") || ZEPHIR_IS_STRING(is, "$in")) {
							if (Z_TYPE_P(value) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(ids$$14);
								array_init(ids$$14);
								zephir_is_iterable(value, &_14$$14, &_13$$14, 0, 0, "ice/db/driver/pdo.zep", 215);
								for (
								  ; zend_hash_get_current_data_ex(_14$$14, (void**) &_15$$14, &_13$$14) == SUCCESS
								  ; zend_hash_move_forward_ex(_14$$14, &_13$$14)
								) {
									ZEPHIR_GET_HMKEY(j$$14, _14$$14, _13$$14);
									ZEPHIR_GET_HVALUE(id$$14, _15$$14);
									ZEPHIR_INIT_LNVAR(_16$$15);
									ZEPHIR_CONCAT_VV(_16$$15, index, j$$14);
									zephir_array_append(&ids$$14, _16$$15, PH_SEPARATE, "ice/db/driver/pdo.zep", 211);
									ZEPHIR_INIT_LNVAR(_17$$15);
									ZEPHIR_CONCAT_VV(_17$$15, index, j$$14);
									zephir_array_update_zval(&values, _17$$15, &id$$14, PH_COPY | PH_SEPARATE);
								}
								ZEPHIR_INIT_NVAR(_18$$14);
								zephir_fast_join_str(_18$$14, SL(", "), ids$$14 TSRMLS_CC);
								ZEPHIR_INIT_NVAR(value);
								ZEPHIR_CONCAT_SVS(value, "(", _18$$14, ")");
							}
							_19$$13 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
							ZEPHIR_CALL_FUNCTION(&_20$$13, "sprintf", &_21, 13, _19$$13, key);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(condition);
							ZEPHIR_CONCAT_VVSV(condition, _20$$13, is, " ", value);
							break;
						}
						if (ZEPHIR_IS_STRING(is, "IS") || ZEPHIR_IS_STRING(is, "is") || ZEPHIR_IS_STRING(is, "IS NOT") || ZEPHIR_IS_STRING(is, "is not")) {
							_22$$16 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
							ZEPHIR_CALL_FUNCTION(&_23$$16, "sprintf", &_21, 13, _22$$16, key);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(condition);
							ZEPHIR_CONCAT_VVSV(condition, _23$$16, is, " ", value);
							break;
						}
						_24$$17 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
						ZEPHIR_CALL_FUNCTION(&_25$$17, "sprintf", &_21, 13, _24$$17, key);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(condition);
						ZEPHIR_CONCAT_VVSV(condition, _25$$17, is, " ", index);
						zephir_array_update_zval(&values, index, &value, PH_COPY | PH_SEPARATE);
						break;
					} while(0);

					if (ZEPHIR_IS_STRING(operator, "AND")) {
						zephir_array_append(&and, condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 234);
					} else {
						zephir_array_append(&or, condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 236);
					}
				}
				if (ZEPHIR_IS_STRING(operator, "OR")) {
					ZEPHIR_INIT_NVAR(_26$$20);
					zephir_fast_join_str(_26$$20, SL(" OR "), or TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_27$$20);
					ZEPHIR_CONCAT_SVS(_27$$20, "(", _26$$20, ")");
					zephir_array_append(&and, _27$$20, PH_SEPARATE, "ice/db/driver/pdo.zep", 241);
				}
			}
			ZEPHIR_INIT_VAR(_28$$4);
			zephir_fast_join_str(_28$$4, SL(" AND "), and TSRMLS_CC);
			zephir_concat_self(&sql, _28$$4 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "integer")) {
			_29$$21 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
			_30$$21 = zephir_fetch_nproperty_this(this_ptr, SL("id"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&_31$$21, "sprintf", &_21, 13, _29$$21, _30$$21);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_32$$21);
			ZEPHIR_CONCAT_VSV(_32$$21, _31$$21, "=", filters);
			zephir_concat_self(&sql, _32$$21 TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *columns = NULL, *sql = NULL, *filtered = NULL, *values = NULL, *query = NULL, *_0, *_1 = NULL, *_2, *_13, *_14 = NULL, *_3$$5, *_4$$5, *_5$$5, *_6$$6, *_7$$6, *_8$$6, *_9$$7, *_10$$7, *_11$$8, *_12$$8;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
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
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", NULL, 13, _0, from);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 279 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSVSV(sql, "SELECT ", columns, " FROM ", _1, " WHERE ", _2);
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_long(&values, filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 280 TSRMLS_CC);
	if (zephir_array_isset_string(options, SS("group"))) {
		ZEPHIR_INIT_VAR(_3$$5);
		zephir_array_fetch_string(&_4$$5, options, SL("group"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 283 TSRMLS_CC);
		zephir_fast_join_str(_3$$5, SL(", "), _4$$5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5$$5);
		ZEPHIR_CONCAT_SV(_5$$5, " GROUP BY ", _3$$5);
		zephir_concat_self(&sql, _5$$5 TSRMLS_CC);
	}
	if (zephir_array_isset_string(options, SS("order"))) {
		ZEPHIR_INIT_VAR(_6$$6);
		zephir_array_fetch_string(&_7$$6, options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 286 TSRMLS_CC);
		zephir_fast_join_str(_6$$6, SL(", "), _7$$6 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8$$6);
		ZEPHIR_CONCAT_SV(_8$$6, " ORDER BY ", _6$$6);
		zephir_concat_self(&sql, _8$$6 TSRMLS_CC);
	}
	if (zephir_array_isset_string(options, SS("limit"))) {
		zephir_array_fetch_string(&_9$$7, options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 289 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10$$7);
		ZEPHIR_CONCAT_SV(_10$$7, " LIMIT ", _9$$7);
		zephir_concat_self(&sql, _10$$7 TSRMLS_CC);
	}
	if (zephir_array_isset_string(options, SS("offset"))) {
		zephir_array_fetch_string(&_11$$8, options, SL("offset"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 292 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_12$$8);
		ZEPHIR_CONCAT_SV(_12$$8, " OFFSET ", _11$$8);
		zephir_concat_self(&sql, _12$$8 TSRMLS_CC);
	}
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _13, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_14, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("error"), _14 TSRMLS_CC);
	RETURN_CCTOR(query);

}

/**
 * INSERT record into table.
 *
 * @param string from Table name
 * @param array fields Fields to insert, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Pdo, insert) {

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *fields = NULL;
	zval *from_param = NULL, *fields_param = NULL, *key = NULL, *value = NULL, *columns = NULL, *values = NULL, *sql = NULL, *query = NULL, *status = NULL, **_2, *_7, *_8 = NULL, *_9, *_10, *_11, *_12, *_13 = NULL, *_3$$3, *_4$$3 = NULL, *_6$$3 = NULL;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
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
	zephir_is_iterable(fields, &_1, &_0, 0, 0, "ice/db/driver/pdo.zep", 322);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", &_5, 13, _3$$3, key);
		zephir_check_call_status();
		zephir_array_append(&columns, _4$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 318);
		ZEPHIR_INIT_LNVAR(_6$$3);
		ZEPHIR_CONCAT_SV(_6$$3, ":", key);
		zephir_array_update_zval(&values, _6$$3, &value, PH_COPY | PH_SEPARATE);
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_8, "sprintf", &_5, 13, _7, from);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_9);
	zephir_fast_join_str(_9, SL(", "), columns TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_INIT_VAR(_11);
	zephir_array_keys(_11, values TSRMLS_CC);
	zephir_fast_join_str(_10, SL(", "), _11 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSVSVS(sql, "INSERT INTO ", _8, " (", _9, ") VALUES (", _10, ")");
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _12, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_13, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("error"), _13 TSRMLS_CC);
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

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *fields_param = NULL, *key = NULL, *value = NULL, *columns = NULL, *values = NULL, *filtered = NULL, *sql = NULL, *query = NULL, *status = NULL, **_2, *_8, *_9 = NULL, *_10, *_11, *_12, *_13, *_14, *_15 = NULL, *_3$$3 = NULL, *_4$$3, *_5$$3 = NULL, *_7$$3 = NULL;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &from_param, &filters, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
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
	zephir_is_iterable(fields, &_1, &_0, 0, 0, "ice/db/driver/pdo.zep", 349);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, ":", key);
		zephir_array_update_zval(&values, _3$$3, &value, PH_COPY | PH_SEPARATE);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", &_6, 13, _4$$3, key);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_7$$3);
		ZEPHIR_CONCAT_VSV(_7$$3, _5$$3, " = :", key);
		zephir_array_append(&columns, _7$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 346);
	}
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters, values);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_6, 13, _8, from);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_10);
	zephir_fast_join_str(_10, SL(", "), columns TSRMLS_CC);
	zephir_array_fetch_long(&_11, filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 350 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSVSV(sql, "UPDATE ", _9, " SET ", _10, " WHERE ", _11);
	ZEPHIR_INIT_VAR(_12);
	zephir_array_fetch_long(&_13, filtered, 1, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 351 TSRMLS_CC);
	zephir_fast_array_merge(_12, &(values), &(_13) TSRMLS_CC);
	ZEPHIR_CPY_WRT(values, _12);
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _14, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_15, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("error"), _15 TSRMLS_CC);
	RETURN_CCTOR(status);

}

/**
 * Remove records from the table.
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 */
PHP_METHOD(Ice_Db_Driver_Pdo, remove) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *from_param = NULL, *filters = NULL, *filtered = NULL, *sql = NULL, *values = NULL, *query = NULL, *status = NULL, *_0, *_1 = NULL, *_2, *_3, *_4 = NULL;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &filters);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}


	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", NULL, 13, _0, from);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 370 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSV(sql, "DELETE FROM ", _1, " WHERE ", _2);
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_long(&values, filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 371 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _3, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("error"), _4 TSRMLS_CC);
	RETURN_CCTOR(status);

}

/**
 * Query sql statement. execute the statement and populate into Model object:
 * $m = $this->db->query('select*from t where id=:id', [':id' => 1], new static);
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
	zval *values = NULL, *_8$$8;
	zval *sql_param = NULL, *values_param = NULL, *obj = NULL, *query = NULL, *result = NULL, *_0, *_1 = NULL, *_2, *_4$$4 = NULL, *_6$$5, *_7$$8, *_9$$8 = NULL;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sql_param, &values_param, &obj);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(sql);
		ZVAL_EMPTY_STRING(sql);
	}
	if (!values_param) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	} else {
		zephir_get_arrval(values, values_param);
	}
	if (!obj) {
		ZEPHIR_CPY_WRT(obj, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(obj);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _0, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("error"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("error"), PH_NOISY_CC);
	_3 = ZEPHIR_IS_EMPTY(_2);
	if (_3) {
		_3 = zephir_is_true(obj);
	}
	if (_3) {
		if (Z_TYPE_P(obj) == IS_STRING) {
			ZEPHIR_INIT_NVAR(obj);
			zephir_fetch_safe_class(_4$$4, obj);
				_5$$4 = zend_fetch_class(Z_STRVAL_P(_4$$4), Z_STRLEN_P(_4$$4), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(obj, _5$$4);
			if (zephir_has_constructor(obj TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, obj, "__construct", NULL, 0);
				zephir_check_call_status();
			}
		}
		if (zephir_instance_of_ev(obj, ice_arr_ce TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_6$$5);
			ZVAL_LONG(_6$$5, 2);
			ZEPHIR_CALL_METHOD(&result, query, "fetch", NULL, 0, _6$$5);
			zephir_check_call_status();
			if (zephir_is_true(result)) {
				ZEPHIR_CALL_METHOD(NULL, obj, "replace", NULL, 0, result);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(obj);
				ZVAL_NULL(obj);
			}
			RETVAL_ZVAL(obj, 1, 0);
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(_7$$8);
			object_init_ex(_7$$8, ice_exception_ce);
			ZEPHIR_INIT_VAR(_8$$8);
			zephir_create_array(_8$$8, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_9$$8);
			ZVAL_STRING(_9$$8, "Only instance of Arr is allowed for populate the result. %s given", 1);
			zephir_array_fast_append(_8$$8, _9$$8);
			ZEPHIR_INIT_NVAR(_9$$8);
			zephir_get_class(_9$$8, obj, 0 TSRMLS_CC);
			zephir_array_fast_append(_8$$8, _9$$8);
			ZEPHIR_CALL_METHOD(NULL, _7$$8, "__construct", NULL, 14, _8$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$8, "ice/db/driver/pdo.zep", 411 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(query);

}

/**
 * Get last inserted ID.
 *
 * @return int
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getLastInsertId) {

	zval *_0, *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

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

	zval *error = NULL, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("error"), PH_NOISY_CC);
	zephir_array_isset_long_fetch(&error, _0, 0, 1 TSRMLS_CC);
	RETURN_CTORW(error);

}

