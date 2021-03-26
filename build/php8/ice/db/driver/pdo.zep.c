
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
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db_Driver_Pdo) {

	ZEPHIR_REGISTER_CLASS(Ice\\Db\\Driver, Pdo, ice, db_driver_pdo, ice_db_driver_pdo_method_entry, 0);

	zend_declare_property_string(ice_db_driver_pdo_ce, SL("id"), "id", ZEND_ACC_PROTECTED);

	zend_declare_property_string(ice_db_driver_pdo_ce, SL("type"), "SQL", ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_db_driver_pdo_ce, SL("error"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_db_driver_pdo_ce, SL("client"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_db_driver_pdo_ce, SL("driverName"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(ice_db_driver_pdo_ce, SL("identifier"), "\"%s\"", ZEND_ACC_PROTECTED);

	zend_class_implements(ice_db_driver_pdo_ce, 1, ice_db_dbinterface_ce);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(dsn)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(user)
		Z_PARAM_STR_OR_NULL(password)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();

#endif


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
	zephir_fast_explode_str(&_0, SL(":"), &dsn, 2 );
	zephir_array_fetch_long(&_1, &_0, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 37);
	zephir_update_property_zval(this_ptr, ZEND_STRL("driverName"), &_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("driverName"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_STRING(&_2, "mysql")) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "`%s`");
			zephir_update_property_zval(this_ptr, ZEND_STRL("identifier"), &_3$$3);
			ZEPHIR_INIT_VAR(&_4$$3);
			ZEPHIR_CONCAT_VS(&_4$$3, &dsn, ";charset=utf8");
			ZEPHIR_CPY_WRT(&dsn, &_4$$3);
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "sqlsrv")) {
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_INIT_NVAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "[%s]");
			zephir_update_property_zval(this_ptr, ZEND_STRL("identifier"), &_5$$4);
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "sqlite")) {
			ZEPHIR_INIT_VAR(&_6$$5);
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "[%s]");
			zephir_update_property_zval(this_ptr, ZEND_STRL("identifier"), &_6$$5);
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "oci")) {
			ZEPHIR_INIT_VAR(&_7$$6);
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZVAL_STRING(&_7$$6, "\"%s\"");
			zephir_update_property_zval(this_ptr, ZEND_STRL("identifier"), &_7$$6);
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "pgsql")) {
			ZEPHIR_INIT_VAR(&_8$$7);
			ZEPHIR_INIT_NVAR(&_8$$7);
			ZVAL_STRING(&_8$$7, "\"%s\"");
			zephir_update_property_zval(this_ptr, ZEND_STRL("identifier"), &_8$$7);
			break;
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_9);
	object_init_ex(&_9, php_pdo_get_dbh_ce());
	ZEPHIR_CALL_METHOD(NULL, &_9, "__construct", NULL, 0, &dsn, &user, &password, &options);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("client"), &_9);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &id);



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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(value)
		Z_PARAM_ZVAL(model)
	ZEND_PARSE_PARAMETERS_END();

#endif


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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, result, fetched, _0, _1, _2;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&fetched);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
		Z_PARAM_ARRAY(options)
		Z_PARAM_ARRAY(fields)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be of the type string"));
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 1);
	zephir_array_update_string(&options, SL("limit"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, &from, filters, &options, &fields);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(&fetched, &result, "fetch", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	if (zephir_is_true(&fetched)) {
		object_init_ex(&_2, ice_arr_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 4, &fetched);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	RETURN_CCTOR(&_2);

}

/**
 * Find all records that match criteria.
 *
 * <pre><code>
 *  //SELECT * FROM users WHERE a=1 and b="q"
 *  $db->find("users", ["a" => 1, "b" => "q"]);
 *
 *  //SELECT * FROM users WHERE age>33
 *  $db->find("users", ["age" => [">" => 33]]);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
		Z_PARAM_ARRAY(options)
		Z_PARAM_ARRAY(fields)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be of the type string"));
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
 * Count rows that match criteria.
 *
 * <pre><code>
 *  //SELECT count(*) as total FROM users WHERE a=1
 *  $db->count("users", ["a" => 1]);
 * </code></pre>
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @return int
 */
PHP_METHOD(Ice_Db_Driver_Pdo, count) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *from_param = NULL, *filters = NULL, filters_sub, result, _0, _2, _3;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &filters);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be of the type string"));
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


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "count(*) AS total");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "findone", NULL, 0, &from, filters, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	if (zephir_is_true(&result)) {
		ZEPHIR_OBS_VAR(&_3);
		zephir_read_property(&_3, &result, ZEND_STRL("total"), PH_NOISY_CC);
		ZVAL_LONG(&_2, zephir_get_intval(&_3));
	} else {
		ZVAL_LONG(&_2, 0);
	}
	RETURN_CCTOR(&_2);

}

/**
 * Prepare SQL WHERE condition.
 *
 * @params mixed filters
 * @params array values
 * @param array options
 */
PHP_METHOD(Ice_Db_Driver_Pdo, where) {

	zend_string *_5$$4, *_19$$14, *_32$$28, *_51$$47, *_64$$61;
	zend_ulong _4$$4, _18$$14, _31$$28, _50$$47, _63$$61;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _0$$3;
	zval values, options, _7$$8, _42$$41;
	zval *filters = NULL, filters_sub, *values_param = NULL, *options_param = NULL, and, data, operator, key, item, value, or, is, index, i, sql, condition, column, _1, *_2$$4, _3$$4, _73$$4, tmp$$8, _6$$8, *_8$$5, _9$$5, _12$$9, _14$$10, _15$$12, j$$14, id$$14, ids$$14, *_16$$14, _17$$14, _24$$14, _20$$15, _21$$15, _22$$16, _23$$16, _25$$19, _26$$23, _27$$24, _28$$26, j$$28, id$$28, ids$$28, *_29$$28, _30$$28, _37$$28, _33$$29, _34$$29, _35$$30, _36$$30, _38$$33, _39$$37, _40$$37, tmp$$41, _41$$41, *_43$$38, _44$$38, _45$$42, _46$$43, _47$$45, j$$47, id$$47, ids$$47, *_48$$47, _49$$47, _56$$47, _52$$48, _53$$48, _54$$49, _55$$49, _57$$52, _58$$56, _59$$57, _60$$59, j$$61, id$$61, ids$$61, *_61$$61, _62$$61, _69$$61, _65$$62, _66$$62, _67$$63, _68$$63, _70$$66, _71$$70, _72$$70, _74$$71, _75$$71, _76$$71, _77$$71;
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
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_73$$4);
	ZVAL_UNDEF(&tmp$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&j$$14);
	ZVAL_UNDEF(&id$$14);
	ZVAL_UNDEF(&ids$$14);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&_27$$24);
	ZVAL_UNDEF(&_28$$26);
	ZVAL_UNDEF(&j$$28);
	ZVAL_UNDEF(&id$$28);
	ZVAL_UNDEF(&ids$$28);
	ZVAL_UNDEF(&_30$$28);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_33$$29);
	ZVAL_UNDEF(&_34$$29);
	ZVAL_UNDEF(&_35$$30);
	ZVAL_UNDEF(&_36$$30);
	ZVAL_UNDEF(&_38$$33);
	ZVAL_UNDEF(&_39$$37);
	ZVAL_UNDEF(&_40$$37);
	ZVAL_UNDEF(&tmp$$41);
	ZVAL_UNDEF(&_41$$41);
	ZVAL_UNDEF(&_44$$38);
	ZVAL_UNDEF(&_45$$42);
	ZVAL_UNDEF(&_46$$43);
	ZVAL_UNDEF(&_47$$45);
	ZVAL_UNDEF(&j$$47);
	ZVAL_UNDEF(&id$$47);
	ZVAL_UNDEF(&ids$$47);
	ZVAL_UNDEF(&_49$$47);
	ZVAL_UNDEF(&_56$$47);
	ZVAL_UNDEF(&_52$$48);
	ZVAL_UNDEF(&_53$$48);
	ZVAL_UNDEF(&_54$$49);
	ZVAL_UNDEF(&_55$$49);
	ZVAL_UNDEF(&_57$$52);
	ZVAL_UNDEF(&_58$$56);
	ZVAL_UNDEF(&_59$$57);
	ZVAL_UNDEF(&_60$$59);
	ZVAL_UNDEF(&j$$61);
	ZVAL_UNDEF(&id$$61);
	ZVAL_UNDEF(&ids$$61);
	ZVAL_UNDEF(&_62$$61);
	ZVAL_UNDEF(&_69$$61);
	ZVAL_UNDEF(&_65$$62);
	ZVAL_UNDEF(&_66$$62);
	ZVAL_UNDEF(&_67$$63);
	ZVAL_UNDEF(&_68$$63);
	ZVAL_UNDEF(&_70$$66);
	ZVAL_UNDEF(&_71$$70);
	ZVAL_UNDEF(&_72$$70);
	ZVAL_UNDEF(&_74$$71);
	ZVAL_UNDEF(&_75$$71);
	ZVAL_UNDEF(&_76$$71);
	ZVAL_UNDEF(&_77$$71);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_42$$41);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
		Z_PARAM_ARRAY(values)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &filters, &values_param, &options_param);

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
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
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
	zephir_gettype(&_1, filters);
	do {
		if (ZEPHIR_IS_STRING(&_1, "array")) {
			zephir_is_iterable(filters, 0, "ice/db/driver/pdo.zep", 275);
			if (Z_TYPE_P(filters) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(filters), _4$$4, _5$$4, _2$$4)
				{
					ZEPHIR_INIT_NVAR(&operator);
					if (_5$$4 != NULL) { 
						ZVAL_STR_COPY(&operator, _5$$4);
					} else {
						ZVAL_LONG(&operator, _4$$4);
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
						ZEPHIR_INIT_NVAR(&_6$$8);
						zephir_create_array(&_6$$8, 1, 0);
						ZEPHIR_INIT_NVAR(&_7$$8);
						zephir_create_array(&_7$$8, 1, 0);
						zephir_array_update_zval(&_7$$8, &operator, &tmp$$8, PH_COPY);
						zephir_array_update_string(&_6$$8, SL("AND"), &_7$$8, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&data, &_6$$8);
						ZEPHIR_INIT_NVAR(&operator);
						ZVAL_STRING(&operator, "AND");
						break;
					} while(0);

					zephir_is_iterable(&data, 0, "ice/db/driver/pdo.zep", 271);
					if (Z_TYPE_P(&data) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _8$$5)
						{
							ZEPHIR_INIT_NVAR(&item);
							ZVAL_COPY(&item, _8$$5);
							ZEPHIR_CALL_FUNCTION(&key, "key", &_10, 100, &item);
							zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&value, "current", &_11, 99, &item);
							zephir_check_call_status();
							zephir_read_property(&_12$$9, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_FUNCTION(&column, "sprintf", &_13, 11, &_12$$9, &key);
							zephir_check_call_status();
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEPHIR_CALL_FUNCTION(&is, "key", &_10, 100, &value);
								zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_14$$10, "current", &_11, 99, &value);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&value, &_14$$10);
							} else {
								ZEPHIR_INIT_NVAR(&is);
								ZVAL_STRING(&is, "=");
							}
							do {
								ZEPHIR_INIT_NVAR(&index);
								ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
								ZEPHIR_INIT_NVAR(&_15$$12);
								if (zephir_is_true(&i)) {
									ZEPHIR_INIT_NVAR(&_15$$12);
									ZVAL_LONG(&_15$$12, (zephir_get_intval(&i) + 1));
								} else {
									ZEPHIR_INIT_NVAR(&_15$$12);
									ZVAL_LONG(&_15$$12, 1);
								}
								ZEPHIR_CPY_WRT(&i, &_15$$12);
							} while (zephir_array_isset(&values, &index));
							do {
								if (ZEPHIR_IS_STRING(&is, "IN") || ZEPHIR_IS_STRING(&is, "in") || ZEPHIR_IS_STRING(&is, "$in")) {
									if (Z_TYPE_P(&value) == IS_ARRAY) {
										ZEPHIR_INIT_NVAR(&ids$$14);
										array_init(&ids$$14);
										zephir_is_iterable(&value, 0, "ice/db/driver/pdo.zep", 241);
										if (Z_TYPE_P(&value) == IS_ARRAY) {
											ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _18$$14, _19$$14, _16$$14)
											{
												ZEPHIR_INIT_NVAR(&j$$14);
												if (_19$$14 != NULL) { 
													ZVAL_STR_COPY(&j$$14, _19$$14);
												} else {
													ZVAL_LONG(&j$$14, _18$$14);
												}
												ZEPHIR_INIT_NVAR(&id$$14);
												ZVAL_COPY(&id$$14, _16$$14);
												ZEPHIR_INIT_NVAR(&_20$$15);
												ZEPHIR_CONCAT_VV(&_20$$15, &index, &j$$14);
												zephir_array_append(&ids$$14, &_20$$15, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
												ZEPHIR_INIT_NVAR(&_21$$15);
												ZEPHIR_CONCAT_VV(&_21$$15, &index, &j$$14);
												zephir_array_update_zval(&values, &_21$$15, &id$$14, PH_COPY | PH_SEPARATE);
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_17$$14, &value, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_17$$14)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&j$$14, &value, "key", NULL, 0);
												zephir_check_call_status();
												ZEPHIR_CALL_METHOD(&id$$14, &value, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_22$$16);
													ZEPHIR_CONCAT_VV(&_22$$16, &index, &j$$14);
													zephir_array_append(&ids$$14, &_22$$16, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
													ZEPHIR_INIT_NVAR(&_23$$16);
													ZEPHIR_CONCAT_VV(&_23$$16, &index, &j$$14);
													zephir_array_update_zval(&values, &_23$$16, &id$$14, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&id$$14);
										ZEPHIR_INIT_NVAR(&j$$14);
										ZEPHIR_INIT_NVAR(&_24$$14);
										zephir_fast_join_str(&_24$$14, SL(", "), &ids$$14);
										ZEPHIR_INIT_NVAR(&value);
										ZEPHIR_CONCAT_SVS(&value, "(", &_24$$14, ")");
									}
									ZEPHIR_INIT_NVAR(&condition);
									ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
									break;
								}
								if (ZEPHIR_IS_STRING(&is, "IS") || ZEPHIR_IS_STRING(&is, "is") || ZEPHIR_IS_STRING(&is, "IS NOT") || ZEPHIR_IS_STRING(&is, "is not")) {
									ZEPHIR_INIT_NVAR(&condition);
									ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
									break;
								}
								if (zephir_array_isset_string(&options, SL("insensitive"))) {
									ZEPHIR_INIT_NVAR(&_25$$19);
									ZVAL_STRING(&_25$$19, "LOWER(%s) %s LOWER(%s)");
									ZEPHIR_CALL_FUNCTION(&condition, "sprintf", &_13, 11, &_25$$19, &column, &is, &index);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&condition);
									ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &index);
								}
								zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
								break;
							} while(0);

							if (ZEPHIR_IS_STRING(&operator, "AND")) {
								zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 265);
							} else {
								zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 267);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_9$$5, &data, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_9$$5)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&item, &data, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&key, "key", &_10, 100, &item);
								zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&value, "current", &_11, 99, &item);
								zephir_check_call_status();
								zephir_read_property(&_26$$23, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_FUNCTION(&column, "sprintf", &_13, 11, &_26$$23, &key);
								zephir_check_call_status();
								if (Z_TYPE_P(&value) == IS_ARRAY) {
									ZEPHIR_CALL_FUNCTION(&is, "key", &_10, 100, &value);
									zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_27$$24, "current", &_11, 99, &value);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&value, &_27$$24);
								} else {
									ZEPHIR_INIT_NVAR(&is);
									ZVAL_STRING(&is, "=");
								}
								do {
									ZEPHIR_INIT_NVAR(&index);
									ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
									ZEPHIR_INIT_NVAR(&_28$$26);
									if (zephir_is_true(&i)) {
										ZEPHIR_INIT_NVAR(&_28$$26);
										ZVAL_LONG(&_28$$26, (zephir_get_intval(&i) + 1));
									} else {
										ZEPHIR_INIT_NVAR(&_28$$26);
										ZVAL_LONG(&_28$$26, 1);
									}
									ZEPHIR_CPY_WRT(&i, &_28$$26);
								} while (zephir_array_isset(&values, &index));
								do {
									if (ZEPHIR_IS_STRING(&is, "IN") || ZEPHIR_IS_STRING(&is, "in") || ZEPHIR_IS_STRING(&is, "$in")) {
										if (Z_TYPE_P(&value) == IS_ARRAY) {
											ZEPHIR_INIT_NVAR(&ids$$28);
											array_init(&ids$$28);
											zephir_is_iterable(&value, 0, "ice/db/driver/pdo.zep", 241);
											if (Z_TYPE_P(&value) == IS_ARRAY) {
												ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _31$$28, _32$$28, _29$$28)
												{
													ZEPHIR_INIT_NVAR(&j$$28);
													if (_32$$28 != NULL) { 
														ZVAL_STR_COPY(&j$$28, _32$$28);
													} else {
														ZVAL_LONG(&j$$28, _31$$28);
													}
													ZEPHIR_INIT_NVAR(&id$$28);
													ZVAL_COPY(&id$$28, _29$$28);
													ZEPHIR_INIT_NVAR(&_33$$29);
													ZEPHIR_CONCAT_VV(&_33$$29, &index, &j$$28);
													zephir_array_append(&ids$$28, &_33$$29, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
													ZEPHIR_INIT_NVAR(&_34$$29);
													ZEPHIR_CONCAT_VV(&_34$$29, &index, &j$$28);
													zephir_array_update_zval(&values, &_34$$29, &id$$28, PH_COPY | PH_SEPARATE);
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_30$$28, &value, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_30$$28)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&j$$28, &value, "key", NULL, 0);
													zephir_check_call_status();
													ZEPHIR_CALL_METHOD(&id$$28, &value, "current", NULL, 0);
													zephir_check_call_status();
														ZEPHIR_INIT_NVAR(&_35$$30);
														ZEPHIR_CONCAT_VV(&_35$$30, &index, &j$$28);
														zephir_array_append(&ids$$28, &_35$$30, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
														ZEPHIR_INIT_NVAR(&_36$$30);
														ZEPHIR_CONCAT_VV(&_36$$30, &index, &j$$28);
														zephir_array_update_zval(&values, &_36$$30, &id$$28, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&id$$28);
											ZEPHIR_INIT_NVAR(&j$$28);
											ZEPHIR_INIT_NVAR(&_37$$28);
											zephir_fast_join_str(&_37$$28, SL(", "), &ids$$28);
											ZEPHIR_INIT_NVAR(&value);
											ZEPHIR_CONCAT_SVS(&value, "(", &_37$$28, ")");
										}
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
										break;
									}
									if (ZEPHIR_IS_STRING(&is, "IS") || ZEPHIR_IS_STRING(&is, "is") || ZEPHIR_IS_STRING(&is, "IS NOT") || ZEPHIR_IS_STRING(&is, "is not")) {
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
										break;
									}
									if (zephir_array_isset_string(&options, SL("insensitive"))) {
										ZEPHIR_INIT_NVAR(&_38$$33);
										ZVAL_STRING(&_38$$33, "LOWER(%s) %s LOWER(%s)");
										ZEPHIR_CALL_FUNCTION(&condition, "sprintf", &_13, 11, &_38$$33, &column, &is, &index);
										zephir_check_call_status();
									} else {
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &index);
									}
									zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
									break;
								} while(0);

								if (ZEPHIR_IS_STRING(&operator, "AND")) {
									zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 265);
								} else {
									zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 267);
								}
							ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&item);
					if (ZEPHIR_IS_STRING(&operator, "OR")) {
						ZEPHIR_INIT_NVAR(&_39$$37);
						zephir_fast_join_str(&_39$$37, SL(" OR "), &or);
						ZEPHIR_INIT_NVAR(&_40$$37);
						ZEPHIR_CONCAT_SVS(&_40$$37, "(", &_39$$37, ")");
						zephir_array_append(&and, &_40$$37, PH_SEPARATE, "ice/db/driver/pdo.zep", 272);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, filters, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_3$$4, filters, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&operator, filters, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&data, filters, "current", NULL, 0);
					zephir_check_call_status();
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
							ZEPHIR_CPY_WRT(&tmp$$41, &data);
							ZEPHIR_INIT_NVAR(&_41$$41);
							zephir_create_array(&_41$$41, 1, 0);
							ZEPHIR_INIT_NVAR(&_42$$41);
							zephir_create_array(&_42$$41, 1, 0);
							zephir_array_update_zval(&_42$$41, &operator, &tmp$$41, PH_COPY);
							zephir_array_update_string(&_41$$41, SL("AND"), &_42$$41, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&data, &_41$$41);
							ZEPHIR_INIT_NVAR(&operator);
							ZVAL_STRING(&operator, "AND");
							break;
						} while(0);

						zephir_is_iterable(&data, 0, "ice/db/driver/pdo.zep", 271);
						if (Z_TYPE_P(&data) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _43$$38)
							{
								ZEPHIR_INIT_NVAR(&item);
								ZVAL_COPY(&item, _43$$38);
								ZEPHIR_CALL_FUNCTION(&key, "key", &_10, 100, &item);
								zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&value, "current", &_11, 99, &item);
								zephir_check_call_status();
								zephir_read_property(&_45$$42, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_FUNCTION(&column, "sprintf", &_13, 11, &_45$$42, &key);
								zephir_check_call_status();
								if (Z_TYPE_P(&value) == IS_ARRAY) {
									ZEPHIR_CALL_FUNCTION(&is, "key", &_10, 100, &value);
									zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_46$$43, "current", &_11, 99, &value);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&value, &_46$$43);
								} else {
									ZEPHIR_INIT_NVAR(&is);
									ZVAL_STRING(&is, "=");
								}
								do {
									ZEPHIR_INIT_NVAR(&index);
									ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
									ZEPHIR_INIT_NVAR(&_47$$45);
									if (zephir_is_true(&i)) {
										ZEPHIR_INIT_NVAR(&_47$$45);
										ZVAL_LONG(&_47$$45, (zephir_get_intval(&i) + 1));
									} else {
										ZEPHIR_INIT_NVAR(&_47$$45);
										ZVAL_LONG(&_47$$45, 1);
									}
									ZEPHIR_CPY_WRT(&i, &_47$$45);
								} while (zephir_array_isset(&values, &index));
								do {
									if (ZEPHIR_IS_STRING(&is, "IN") || ZEPHIR_IS_STRING(&is, "in") || ZEPHIR_IS_STRING(&is, "$in")) {
										if (Z_TYPE_P(&value) == IS_ARRAY) {
											ZEPHIR_INIT_NVAR(&ids$$47);
											array_init(&ids$$47);
											zephir_is_iterable(&value, 0, "ice/db/driver/pdo.zep", 241);
											if (Z_TYPE_P(&value) == IS_ARRAY) {
												ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _50$$47, _51$$47, _48$$47)
												{
													ZEPHIR_INIT_NVAR(&j$$47);
													if (_51$$47 != NULL) { 
														ZVAL_STR_COPY(&j$$47, _51$$47);
													} else {
														ZVAL_LONG(&j$$47, _50$$47);
													}
													ZEPHIR_INIT_NVAR(&id$$47);
													ZVAL_COPY(&id$$47, _48$$47);
													ZEPHIR_INIT_NVAR(&_52$$48);
													ZEPHIR_CONCAT_VV(&_52$$48, &index, &j$$47);
													zephir_array_append(&ids$$47, &_52$$48, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
													ZEPHIR_INIT_NVAR(&_53$$48);
													ZEPHIR_CONCAT_VV(&_53$$48, &index, &j$$47);
													zephir_array_update_zval(&values, &_53$$48, &id$$47, PH_COPY | PH_SEPARATE);
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_49$$47, &value, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_49$$47)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&j$$47, &value, "key", NULL, 0);
													zephir_check_call_status();
													ZEPHIR_CALL_METHOD(&id$$47, &value, "current", NULL, 0);
													zephir_check_call_status();
														ZEPHIR_INIT_NVAR(&_54$$49);
														ZEPHIR_CONCAT_VV(&_54$$49, &index, &j$$47);
														zephir_array_append(&ids$$47, &_54$$49, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
														ZEPHIR_INIT_NVAR(&_55$$49);
														ZEPHIR_CONCAT_VV(&_55$$49, &index, &j$$47);
														zephir_array_update_zval(&values, &_55$$49, &id$$47, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&id$$47);
											ZEPHIR_INIT_NVAR(&j$$47);
											ZEPHIR_INIT_NVAR(&_56$$47);
											zephir_fast_join_str(&_56$$47, SL(", "), &ids$$47);
											ZEPHIR_INIT_NVAR(&value);
											ZEPHIR_CONCAT_SVS(&value, "(", &_56$$47, ")");
										}
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
										break;
									}
									if (ZEPHIR_IS_STRING(&is, "IS") || ZEPHIR_IS_STRING(&is, "is") || ZEPHIR_IS_STRING(&is, "IS NOT") || ZEPHIR_IS_STRING(&is, "is not")) {
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
										break;
									}
									if (zephir_array_isset_string(&options, SL("insensitive"))) {
										ZEPHIR_INIT_NVAR(&_57$$52);
										ZVAL_STRING(&_57$$52, "LOWER(%s) %s LOWER(%s)");
										ZEPHIR_CALL_FUNCTION(&condition, "sprintf", &_13, 11, &_57$$52, &column, &is, &index);
										zephir_check_call_status();
									} else {
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &index);
									}
									zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
									break;
								} while(0);

								if (ZEPHIR_IS_STRING(&operator, "AND")) {
									zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 265);
								} else {
									zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 267);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_44$$38, &data, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_44$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&item, &data, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&key, "key", &_10, 100, &item);
									zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&value, "current", &_11, 99, &item);
									zephir_check_call_status();
									zephir_read_property(&_58$$56, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_FUNCTION(&column, "sprintf", &_13, 11, &_58$$56, &key);
									zephir_check_call_status();
									if (Z_TYPE_P(&value) == IS_ARRAY) {
										ZEPHIR_CALL_FUNCTION(&is, "key", &_10, 100, &value);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_59$$57, "current", &_11, 99, &value);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&value, &_59$$57);
									} else {
										ZEPHIR_INIT_NVAR(&is);
										ZVAL_STRING(&is, "=");
									}
									do {
										ZEPHIR_INIT_NVAR(&index);
										ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
										ZEPHIR_INIT_NVAR(&_60$$59);
										if (zephir_is_true(&i)) {
											ZEPHIR_INIT_NVAR(&_60$$59);
											ZVAL_LONG(&_60$$59, (zephir_get_intval(&i) + 1));
										} else {
											ZEPHIR_INIT_NVAR(&_60$$59);
											ZVAL_LONG(&_60$$59, 1);
										}
										ZEPHIR_CPY_WRT(&i, &_60$$59);
									} while (zephir_array_isset(&values, &index));
									do {
										if (ZEPHIR_IS_STRING(&is, "IN") || ZEPHIR_IS_STRING(&is, "in") || ZEPHIR_IS_STRING(&is, "$in")) {
											if (Z_TYPE_P(&value) == IS_ARRAY) {
												ZEPHIR_INIT_NVAR(&ids$$61);
												array_init(&ids$$61);
												zephir_is_iterable(&value, 0, "ice/db/driver/pdo.zep", 241);
												if (Z_TYPE_P(&value) == IS_ARRAY) {
													ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _63$$61, _64$$61, _61$$61)
													{
														ZEPHIR_INIT_NVAR(&j$$61);
														if (_64$$61 != NULL) { 
															ZVAL_STR_COPY(&j$$61, _64$$61);
														} else {
															ZVAL_LONG(&j$$61, _63$$61);
														}
														ZEPHIR_INIT_NVAR(&id$$61);
														ZVAL_COPY(&id$$61, _61$$61);
														ZEPHIR_INIT_NVAR(&_65$$62);
														ZEPHIR_CONCAT_VV(&_65$$62, &index, &j$$61);
														zephir_array_append(&ids$$61, &_65$$62, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
														ZEPHIR_INIT_NVAR(&_66$$62);
														ZEPHIR_CONCAT_VV(&_66$$62, &index, &j$$61);
														zephir_array_update_zval(&values, &_66$$62, &id$$61, PH_COPY | PH_SEPARATE);
													} ZEND_HASH_FOREACH_END();
												} else {
													ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
													zephir_check_call_status();
													while (1) {
														ZEPHIR_CALL_METHOD(&_62$$61, &value, "valid", NULL, 0);
														zephir_check_call_status();
														if (!zend_is_true(&_62$$61)) {
															break;
														}
														ZEPHIR_CALL_METHOD(&j$$61, &value, "key", NULL, 0);
														zephir_check_call_status();
														ZEPHIR_CALL_METHOD(&id$$61, &value, "current", NULL, 0);
														zephir_check_call_status();
															ZEPHIR_INIT_NVAR(&_67$$63);
															ZEPHIR_CONCAT_VV(&_67$$63, &index, &j$$61);
															zephir_array_append(&ids$$61, &_67$$63, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
															ZEPHIR_INIT_NVAR(&_68$$63);
															ZEPHIR_CONCAT_VV(&_68$$63, &index, &j$$61);
															zephir_array_update_zval(&values, &_68$$63, &id$$61, PH_COPY | PH_SEPARATE);
														ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
														zephir_check_call_status();
													}
												}
												ZEPHIR_INIT_NVAR(&id$$61);
												ZEPHIR_INIT_NVAR(&j$$61);
												ZEPHIR_INIT_NVAR(&_69$$61);
												zephir_fast_join_str(&_69$$61, SL(", "), &ids$$61);
												ZEPHIR_INIT_NVAR(&value);
												ZEPHIR_CONCAT_SVS(&value, "(", &_69$$61, ")");
											}
											ZEPHIR_INIT_NVAR(&condition);
											ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
											break;
										}
										if (ZEPHIR_IS_STRING(&is, "IS") || ZEPHIR_IS_STRING(&is, "is") || ZEPHIR_IS_STRING(&is, "IS NOT") || ZEPHIR_IS_STRING(&is, "is not")) {
											ZEPHIR_INIT_NVAR(&condition);
											ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
											break;
										}
										if (zephir_array_isset_string(&options, SL("insensitive"))) {
											ZEPHIR_INIT_NVAR(&_70$$66);
											ZVAL_STRING(&_70$$66, "LOWER(%s) %s LOWER(%s)");
											ZEPHIR_CALL_FUNCTION(&condition, "sprintf", &_13, 11, &_70$$66, &column, &is, &index);
											zephir_check_call_status();
										} else {
											ZEPHIR_INIT_NVAR(&condition);
											ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &index);
										}
										zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
										break;
									} while(0);

									if (ZEPHIR_IS_STRING(&operator, "AND")) {
										zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 265);
									} else {
										zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 267);
									}
								ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&item);
						if (ZEPHIR_IS_STRING(&operator, "OR")) {
							ZEPHIR_INIT_NVAR(&_71$$70);
							zephir_fast_join_str(&_71$$70, SL(" OR "), &or);
							ZEPHIR_INIT_NVAR(&_72$$70);
							ZEPHIR_CONCAT_SVS(&_72$$70, "(", &_71$$70, ")");
							zephir_array_append(&and, &_72$$70, PH_SEPARATE, "ice/db/driver/pdo.zep", 272);
						}
					ZEPHIR_CALL_METHOD(NULL, filters, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&data);
			ZEPHIR_INIT_NVAR(&operator);
			ZEPHIR_INIT_VAR(&_73$$4);
			zephir_fast_join_str(&_73$$4, SL(" AND "), &and);
			zephir_concat_self(&sql, &_73$$4);
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "integer")) {
			zephir_read_property(&_74$$71, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_75$$71, this_ptr, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_76$$71, "sprintf", &_13, 11, &_74$$71, &_75$$71);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_77$$71);
			ZEPHIR_CONCAT_VSV(&_77$$71, &_76$$71, "=", filters);
			zephir_concat_self(&sql, &_77$$71);
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "string")) {
			zephir_concat_self(&sql, filters);
			break;
		}
		zephir_concat_self_str(&sql, SL("TRUE"));
		break;
	} while(0);

	zephir_create_array(return_value, 2, 0);
	zephir_array_fast_append(return_value, &sql);
	zephir_array_fast_append(return_value, &values);
	RETURN_MM();

}

/**
 * SELECT record(s) that match criteria.
 *
 * <pre><code>
 *  // MySQL: SELECT * FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc LIMIT 10
 *  // MSSQL: SELECT TOP 10 * FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc
 *  $db->select("users", ["OR" => [["a" => 1], ["b" => 2]]], ["order" => ["a desc", "b asc"], "limit" => 10]);
 *
 *  // MySQL: SELECT x, y FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc LIMIT 10 offset 50
 *  // MSSQL: SELECT x, y FROM users WHERE a=1 or b=2 ORDER BY a desc,b asc offset 50 ROWS FETCH NEXT 10 ROWS ONLY
 *  $db->select("users", ["OR" => [["a" => 1], ["b" => 2]]], ["order" => ["a desc", "b asc"], "limit" => 10, "offset" => 50], ["x","y"]);
 * </code></pre>
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array options Options to limit/offset/group results
 * @param array fields Fields to retrieve, if not specified get all
 */
PHP_METHOD(Ice_Db_Driver_Pdo, select) {

	zend_string *_37$$20;
	zend_ulong _36$$20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, fields, _10$$13, _11$$13;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, columns, filtered, values, query, sql, _14, _15, _16, _18, _19, _55, _56, _57, _0$$5, _1$$5, _2$$7, _3$$7, _4$$8, _5$$8, _6$$10, _7$$10, _8$$12, _9$$13, _12$$13, _13$$13, _20$$14, _21$$14, _22$$15, _23$$16, _24$$16, _25$$16, _26$$17, _27$$17, _28$$18, _29$$19, _30$$19, _31$$19, _32$$19, key$$20, value$$20, tmp$$20, _33$$20, *_34$$20, _35$$20, _44$$20, _45$$20, _38$$21, _39$$21, _40$$21, _41$$22, _42$$22, _43$$22, _46$$23, _47$$23, _48$$23, _49$$24, _50$$24, _51$$25, _52$$25, _53$$26, _54$$26;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_56);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&key$$20);
	ZVAL_UNDEF(&value$$20);
	ZVAL_UNDEF(&tmp$$20);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_44$$20);
	ZVAL_UNDEF(&_45$$20);
	ZVAL_UNDEF(&_38$$21);
	ZVAL_UNDEF(&_39$$21);
	ZVAL_UNDEF(&_40$$21);
	ZVAL_UNDEF(&_41$$22);
	ZVAL_UNDEF(&_42$$22);
	ZVAL_UNDEF(&_43$$22);
	ZVAL_UNDEF(&_46$$23);
	ZVAL_UNDEF(&_47$$23);
	ZVAL_UNDEF(&_48$$23);
	ZVAL_UNDEF(&_49$$24);
	ZVAL_UNDEF(&_50$$24);
	ZVAL_UNDEF(&_51$$25);
	ZVAL_UNDEF(&_52$$25);
	ZVAL_UNDEF(&_53$$26);
	ZVAL_UNDEF(&_54$$26);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$13);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
		Z_PARAM_ARRAY(options)
		Z_PARAM_ARRAY(fields)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be of the type string"));
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
	if (zephir_fast_count_int(&fields)) {
		ZEPHIR_INIT_VAR(&columns);
		zephir_fast_join_str(&columns, SL(", "), &fields);
	} else {
		ZEPHIR_INIT_NVAR(&columns);
		ZVAL_STRING(&columns, "*");
	}
	if (zephir_array_isset_string(&options, SL("limit"))) {
		zephir_read_property(&_0$$5, this_ptr, ZEND_STRL("driverName"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_1$$5, this_ptr, ZEND_STRL("driverName"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_STRING(&_0$$5, "sqlsrv")) {
			if (zephir_array_isset_string(&options, SL("offset"))) {
				zephir_array_fetch_string(&_2$$7, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 324);
				ZEPHIR_INIT_VAR(&_3$$7);
				ZEPHIR_CONCAT_SVS(&_3$$7, " ROWS FETCH NEXT ", &_2$$7, " ROWS ONLY");
				zephir_array_update_string(&options, SL("offset"), &_3$$7, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_fetch_string(&_4$$8, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 326);
				ZEPHIR_INIT_VAR(&_5$$8);
				ZEPHIR_CONCAT_SVS(&_5$$8, "TOP ", &_4$$8, " ");
				zephir_concat_self(&sql, &_5$$8);
			}
			zephir_array_unset_string(&options, SL("limit"), PH_SEPARATE);
		} else if (ZEPHIR_IS_STRING(&_1$$5, "oci")) {
			if (zephir_array_isset_string(&options, SL("offset"))) {
				zephir_array_fetch_string(&_6$$10, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 331);
				ZEPHIR_INIT_VAR(&_7$$10);
				ZEPHIR_CONCAT_SVS(&_7$$10, " ROWS FETCH NEXT ", &_6$$10, " ROWS ONLY");
				zephir_array_update_string(&options, SL("offset"), &_7$$10, PH_COPY | PH_SEPARATE);
			} else {
				if (ZEPHIR_IS_EMPTY(filters)) {
					zephir_array_fetch_string(&_8$$12, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 334);
					ZEPHIR_INIT_NVAR(filters);
					ZEPHIR_CONCAT_SV(filters, "rownum = ", &_8$$12);
				} else {
					ZEPHIR_INIT_VAR(&_9$$13);
					zephir_create_array(&_9$$13, 1, 0);
					ZEPHIR_INIT_VAR(&_10$$13);
					zephir_create_array(&_10$$13, 2, 0);
					zephir_array_fast_append(&_10$$13, filters);
					ZEPHIR_INIT_VAR(&_11$$13);
					zephir_create_array(&_11$$13, 2, 0);
					ZEPHIR_INIT_VAR(&_12$$13);
					ZVAL_STRING(&_12$$13, "rownum");
					zephir_array_fast_append(&_11$$13, &_12$$13);
					ZEPHIR_OBS_VAR(&_13$$13);
					zephir_array_fetch_string(&_13$$13, &options, SL("limit"), PH_NOISY, "ice/db/driver/pdo.zep", 336);
					zephir_array_fast_append(&_11$$13, &_13$$13);
					zephir_array_fast_append(&_10$$13, &_11$$13);
					zephir_array_update_string(&_9$$13, SL("AND"), &_10$$13, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(filters, &_9$$13);
				}
			}
			zephir_array_unset_string(&options, SL("limit"), PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(&_14);
	array_init(&_14);
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters, &_14, &options);
	zephir_check_call_status();
	zephir_read_property(&_15, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_16, "sprintf", &_17, 11, &_15, &from);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_18);
	ZEPHIR_CONCAT_VSV(&_18, &columns, " FROM ", &_16);
	zephir_concat_self(&sql, &_18);
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_long(&values, &filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 345);
	zephir_array_fetch_long(&_19, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 347);
	if (!(ZEPHIR_IS_EMPTY(&_19))) {
		zephir_array_fetch_long(&_20$$14, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 348);
		ZEPHIR_INIT_VAR(&_21$$14);
		ZEPHIR_CONCAT_SV(&_21$$14, " WHERE ", &_20$$14);
		zephir_concat_self(&sql, &_21$$14);
	}
	if (zephir_array_isset_string(&options, SL("group"))) {
		ZEPHIR_OBS_VAR(&_22$$15);
		zephir_array_fetch_string(&_22$$15, &options, SL("group"), PH_NOISY, "ice/db/driver/pdo.zep", 352);
		if (Z_TYPE_P(&_22$$15) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_23$$16);
			zephir_array_fetch_string(&_24$$16, &options, SL("group"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 353);
			zephir_fast_join_str(&_23$$16, SL(", "), &_24$$16);
			ZEPHIR_INIT_VAR(&_25$$16);
			ZEPHIR_CONCAT_SV(&_25$$16, " GROUP BY ", &_23$$16);
			zephir_concat_self(&sql, &_25$$16);
		} else {
			zephir_array_fetch_string(&_26$$17, &options, SL("group"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 355);
			ZEPHIR_INIT_VAR(&_27$$17);
			ZEPHIR_CONCAT_SV(&_27$$17, " GROUP BY ", &_26$$17);
			zephir_concat_self(&sql, &_27$$17);
		}
	}
	if (zephir_array_isset_string(&options, SL("order"))) {
		ZEPHIR_OBS_VAR(&_28$$18);
		zephir_array_fetch_string(&_28$$18, &options, SL("order"), PH_NOISY, "ice/db/driver/pdo.zep", 359);
		if (Z_TYPE_P(&_28$$18) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_29$$19);
			zephir_array_fetch_string(&_30$$19, &options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 361);
			zephir_array_keys(&_29$$19, &_30$$19);
			ZEPHIR_INIT_VAR(&_31$$19);
			ZVAL_STRING(&_31$$19, "is_string");
			ZEPHIR_CALL_FUNCTION(&_32$$19, "array_filter", NULL, 7, &_29$$19, &_31$$19);
			zephir_check_call_status();
			if (zephir_fast_count_int(&_32$$19)) {
				ZEPHIR_INIT_VAR(&tmp$$20);
				array_init(&tmp$$20);
				zephir_array_fetch_string(&_33$$20, &options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 364);
				zephir_is_iterable(&_33$$20, 0, "ice/db/driver/pdo.zep", 368);
				if (Z_TYPE_P(&_33$$20) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_33$$20), _36$$20, _37$$20, _34$$20)
					{
						ZEPHIR_INIT_NVAR(&key$$20);
						if (_37$$20 != NULL) { 
							ZVAL_STR_COPY(&key$$20, _37$$20);
						} else {
							ZVAL_LONG(&key$$20, _36$$20);
						}
						ZEPHIR_INIT_NVAR(&value$$20);
						ZVAL_COPY(&value$$20, _34$$20);
						zephir_read_property(&_38$$21, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_FUNCTION(&_39$$21, "sprintf", &_17, 11, &_38$$21, &key$$20);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_40$$21);
						ZEPHIR_CONCAT_VSV(&_40$$21, &_39$$21, " ", &value$$20);
						zephir_array_append(&tmp$$20, &_40$$21, PH_SEPARATE, "ice/db/driver/pdo.zep", 365);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_33$$20, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_35$$20, &_33$$20, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_35$$20)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key$$20, &_33$$20, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value$$20, &_33$$20, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property(&_41$$22, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_FUNCTION(&_42$$22, "sprintf", &_17, 11, &_41$$22, &key$$20);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_43$$22);
							ZEPHIR_CONCAT_VSV(&_43$$22, &_42$$22, " ", &value$$20);
							zephir_array_append(&tmp$$20, &_43$$22, PH_SEPARATE, "ice/db/driver/pdo.zep", 365);
						ZEPHIR_CALL_METHOD(NULL, &_33$$20, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&value$$20);
				ZEPHIR_INIT_NVAR(&key$$20);
				ZEPHIR_INIT_VAR(&_44$$20);
				zephir_fast_join_str(&_44$$20, SL(", "), &tmp$$20);
				ZEPHIR_INIT_VAR(&_45$$20);
				ZEPHIR_CONCAT_SV(&_45$$20, " ORDER BY ", &_44$$20);
				zephir_concat_self(&sql, &_45$$20);
			} else {
				ZEPHIR_INIT_VAR(&_46$$23);
				zephir_array_fetch_string(&_47$$23, &options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 370);
				zephir_fast_join_str(&_46$$23, SL(", "), &_47$$23);
				ZEPHIR_INIT_VAR(&_48$$23);
				ZEPHIR_CONCAT_SV(&_48$$23, " ORDER BY ", &_46$$23);
				zephir_concat_self(&sql, &_48$$23);
			}
		} else {
			zephir_array_fetch_string(&_49$$24, &options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 373);
			ZEPHIR_INIT_VAR(&_50$$24);
			ZEPHIR_CONCAT_SV(&_50$$24, " ORDER BY ", &_49$$24);
			zephir_concat_self(&sql, &_50$$24);
		}
	}
	if (zephir_array_isset_string(&options, SL("limit"))) {
		zephir_array_fetch_string(&_51$$25, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 377);
		ZEPHIR_INIT_VAR(&_52$$25);
		ZEPHIR_CONCAT_SV(&_52$$25, " LIMIT ", &_51$$25);
		zephir_concat_self(&sql, &_52$$25);
	}
	if (zephir_array_isset_string(&options, SL("offset"))) {
		zephir_array_fetch_string(&_53$$26, &options, SL("offset"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 380);
		ZEPHIR_INIT_VAR(&_54$$26);
		ZEPHIR_CONCAT_SV(&_54$$26, " OFFSET ", &_53$$26);
		zephir_concat_self(&sql, &_54$$26);
	}
	zephir_read_property(&_55, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_55, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_56);
	ZEPHIR_CALL_METHOD(&_57, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	if (zephir_is_true(&_57)) {
		ZEPHIR_INIT_NVAR(&_56);
		ZVAL_NULL(&_56);
	} else {
		ZEPHIR_CALL_METHOD(&_56, &query, "errorinfo", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("error"), &_56);
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

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval *from_param = NULL, *fields_param = NULL, key, value, columns, values, sql, query, status, *_0, _1, _11, _12, _13, _14, _15, _16, _17, _4$$3, _5$$3, _7$$3, _8$$4, _9$$4, _10$$4;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&fields);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(fields)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be of the type string"));
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
	zephir_is_iterable(&fields, 0, "ice/db/driver/pdo.zep", 413);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", &_6, 11, &_4$$3, &key);
			zephir_check_call_status();
			zephir_array_append(&columns, &_5$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 409);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZEPHIR_CONCAT_SV(&_7$$3, ":", &key);
			zephir_array_update_zval(&values, &_7$$3, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &fields, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &fields, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_9$$4, "sprintf", &_6, 11, &_8$$4, &key);
				zephir_check_call_status();
				zephir_array_append(&columns, &_9$$4, PH_SEPARATE, "ice/db/driver/pdo.zep", 409);
				ZEPHIR_INIT_NVAR(&_10$$4);
				ZEPHIR_CONCAT_SV(&_10$$4, ":", &key);
				zephir_array_update_zval(&values, &_10$$4, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_12, "sprintf", &_6, 11, &_11, &from);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	zephir_fast_join_str(&_13, SL(", "), &columns);
	ZEPHIR_INIT_VAR(&_14);
	ZEPHIR_INIT_VAR(&_15);
	zephir_array_keys(&_15, &values);
	zephir_fast_join_str(&_14, SL(", "), &_15);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSVSVS(&sql, "INSERT INTO ", &_12, " (", &_13, ") VALUES (", &_14, ")");
	zephir_read_property(&_16, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_16, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_17);
	if (zephir_is_true(&status)) {
		ZEPHIR_INIT_NVAR(&_17);
		ZVAL_NULL(&_17);
	} else {
		ZEPHIR_CALL_METHOD(&_17, &query, "errorinfo", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("error"), &_17);
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

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *fields_param = NULL, key, value, columns, values, filtered, sql, query, status, *_0, _1, _13, _14, _15, _16, _17, _18, _19, _20, _4$$3, _5$$3, _6$$3, _8$$3, _9$$4, _10$$4, _11$$4, _12$$4;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&fields);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
		Z_PARAM_ARRAY(fields)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &from_param, &filters, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be of the type string"));
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
	zephir_is_iterable(&fields, 0, "ice/db/driver/pdo.zep", 445);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZEPHIR_CONCAT_SV(&_4$$3, ":", &key);
			zephir_array_update_zval(&values, &_4$$3, &value, PH_COPY | PH_SEPARATE);
			zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", &_7, 11, &_5$$3, &key);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZEPHIR_CONCAT_VSV(&_8$$3, &_6$$3, " = :", &key);
			zephir_array_append(&columns, &_8$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 442);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &fields, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &fields, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_CONCAT_SV(&_9$$4, ":", &key);
				zephir_array_update_zval(&values, &_9$$4, &value, PH_COPY | PH_SEPARATE);
				zephir_read_property(&_10$$4, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_11$$4, "sprintf", &_7, 11, &_10$$4, &key);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZEPHIR_CONCAT_VSV(&_12$$4, &_11$$4, " = :", &key);
				zephir_array_append(&columns, &_12$$4, PH_SEPARATE, "ice/db/driver/pdo.zep", 442);
			ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters, &values);
	zephir_check_call_status();
	zephir_read_property(&_13, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_14, "sprintf", &_7, 11, &_13, &from);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_15);
	zephir_fast_join_str(&_15, SL(", "), &columns);
	zephir_array_fetch_long(&_16, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 446);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSVSV(&sql, "UPDATE ", &_14, " SET ", &_15, " WHERE ", &_16);
	ZEPHIR_INIT_VAR(&_17);
	zephir_array_fetch_long(&_18, &filtered, 1, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 447);
	zephir_fast_array_merge(&_17, &values, &_18);
	ZEPHIR_CPY_WRT(&values, &_17);
	zephir_read_property(&_19, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_19, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_20);
	if (zephir_is_true(&status)) {
		ZEPHIR_INIT_NVAR(&_20);
		ZVAL_NULL(&_20);
	} else {
		ZEPHIR_CALL_METHOD(&_20, &query, "errorinfo", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("error"), &_20);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &filters);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be of the type string"));
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("identifier"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", NULL, 11, &_0, &from);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 471);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSV(&sql, "DELETE FROM ", &_1, " WHERE ", &_2);
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_long(&values, &filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 472);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_3, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	if (zephir_is_true(&status)) {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_NULL(&_4);
	} else {
		ZEPHIR_CALL_METHOD(&_4, &query, "errorinfo", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("error"), &_4);
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
 *  $m = $this->db->query('select * from t where id=? OR foo=?', [1, "bar"], '\Ice\Arr');
 * </code></pre>
 *
 * @param string sql SQL with kinda of placeholders
 * @param array values Replace placeholders in the sql
 * @param mixed obj The classname or arr object will be populated from query result
 * @return PDOStatement|object|null If fail return null
 */
PHP_METHOD(Ice_Db_Driver_Pdo, query) {

	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *sql_param = NULL, *values_param = NULL, *obj = NULL, obj_sub, __$null, query, result, status, _0, _1, _4, _3$$3;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&obj_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(sql)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(values)
		Z_PARAM_ZVAL(obj)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sql_param, &values_param, &obj);

	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be of the type string"));
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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_0, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_is_true(&status)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_NULL(&_1);
	} else {
		ZEPHIR_CALL_METHOD(&_1, &query, "errorinfo", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("error"), &_1);
	_2 = zephir_is_true(&status);
	if (_2) {
		_2 = zephir_is_true(obj);
	}
	if (_2) {
		if (Z_TYPE_P(obj) == IS_STRING) {
			ZEPHIR_RETURN_CALL_METHOD(&query, "fetchobject", NULL, 0, obj);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZVAL_LONG(&_3$$3, 2);
		ZEPHIR_CALL_METHOD(&result, &query, "fetch", NULL, 0, &_3$$3);
		zephir_check_call_status();
		if (zephir_is_true(&result)) {
			if (zephir_instance_of_ev(obj, ice_arr_ce)) {
				ZEPHIR_CALL_METHOD(NULL, obj, "merge", NULL, 0, &result);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(obj);
				object_init_ex(obj, ice_arr_ce);
				ZEPHIR_CALL_METHOD(NULL, obj, "__construct", NULL, 4, &result);
				zephir_check_call_status();
			}
			RETVAL_ZVAL(obj, 1, 0);
			RETURN_MM();
		} else {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&_4);
	if (zephir_is_true(&status)) {
		ZEPHIR_CPY_WRT(&_4, &query);
	} else {
		ZVAL_NULL(&_4);
	}
	RETURN_CCTOR(&_4);

}

/**
 * Get last inserted ID.
 *
 * @return int
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getLastInsertId) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
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



	zephir_read_property(&_0, this_ptr, ZEND_STRL("error"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_long_fetch(&error, &_0, 0, 1);
	RETURN_CTORW(&error);

}

