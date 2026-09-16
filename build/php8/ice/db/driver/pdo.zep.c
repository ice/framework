
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


/**
 * Pdo driver.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db_Driver_Pdo)
{
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

PHP_METHOD(Ice_Db_Driver_Pdo, getId)
{

	RETURN_MEMBER(getThis(), "id");
}

PHP_METHOD(Ice_Db_Driver_Pdo, getType)
{

	RETURN_MEMBER(getThis(), "type");
}

PHP_METHOD(Ice_Db_Driver_Pdo, getClient)
{

	RETURN_MEMBER(getThis(), "client");
}

PHP_METHOD(Ice_Db_Driver_Pdo, getDriverName)
{

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
PHP_METHOD(Ice_Db_Driver_Pdo, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zend_string *user = NULL, *password = NULL;
	zval *dsn_param = NULL, user_zv, password_zv, *options_param = NULL, _0, _1, _2, _9, _3$$3, _5$$4, _6$$5, _7$$6, _8$$7;
	zval dsn, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&user_zv);
	ZVAL_UNDEF(&password_zv);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("driverName", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("identifier", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("client", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_ZVAL(dsn_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(user)
		Z_PARAM_STR_OR_NULL(password)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	dsn_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 3) {
		options_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_get_strval(&dsn, dsn_param);
	if (!user) {
		ZEPHIR_INIT_VAR(&user_zv);
	} else {
		zephir_memory_observe(&user_zv);
	ZVAL_STR_COPY(&user_zv, user);
	}
	if (!password) {
		ZEPHIR_INIT_VAR(&password_zv);
	} else {
		zephir_memory_observe(&password_zv);
	ZVAL_STR_COPY(&password_zv, password);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_explode_str(&_0, SL(":"), &dsn, 2 );
	zephir_memory_observe(&_1);
	zephir_array_fetch_long(&_1, &_0, 0, PH_NOISY, "ice/db/driver/pdo.zep", 37);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 146, &_1);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 146, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_2, "mysql")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&_2, "sqlsrv")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&_2, "sqlite")) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_STRING(&_2, "oci")) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_STRING(&_2, "pgsql")) { goto zephir_switch_0_clause_4; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "`%s`");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 147, &_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_VS(&_4$$3, &dsn, ";charset=utf8");
		ZEPHIR_CPY_WRT(&dsn, &_4$$3);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_INIT_NVAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "[%s]");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 147, &_5$$4);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
		ZEPHIR_INIT_VAR(&_6$$5);
		ZEPHIR_INIT_NVAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "[%s]");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 147, &_6$$5);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_3: ;
		ZEPHIR_INIT_VAR(&_7$$6);
		ZEPHIR_INIT_NVAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "\"%s\"");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 147, &_7$$6);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_4: ;
		ZEPHIR_INIT_VAR(&_8$$7);
		ZEPHIR_INIT_NVAR(&_8$$7);
		ZVAL_STRING(&_8$$7, "\"%s\"");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 147, &_8$$7);
		goto zephir_switch_0_end;
	zephir_switch_0_end: ;

	ZEPHIR_INIT_VAR(&_9);
	object_init_ex(&_9, php_pdo_get_dbh_ce());
	ZEPHIR_CALL_METHOD(NULL, &_9, "__construct", NULL, 0, &dsn, &user_zv, &password_zv, &options);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 148, &_9);
	ZEPHIR_MM_RESTORE();
}

/**
 * Get the id value.
 *
 * @param string id
 * @return int
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getIdValue)
{
	zval *id, id_sub;

	ZVAL_UNDEF(&id_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
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
PHP_METHOD(Ice_Db_Driver_Pdo, getDateTime)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, *model = NULL, model_sub, __$null, __$false, date, _0$$3, _1$$4;

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&date);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
		Z_PARAM_ZVAL(model)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
PHP_METHOD(Ice_Db_Driver_Pdo, findOne)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, fields;
	zval from_zv, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, result, fetched, _0, _1, _2;
	zend_string *from = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from_zv);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&fetched);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		ZEPHIR_Z_PARAM_ARRAY(fields, fields_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filters = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		options_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		fields_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&from_zv);
	ZVAL_STR_COPY(&from_zv, from);
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
	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, &from_zv, filters, &options, &fields);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(&fetched, &result, "fetch", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	if (zephir_is_true(&fetched)) {
		ZEPHIR_INIT_NVAR(&_2);
		object_init_ex(&_2, ice_arr_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 4, &fetched);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_2);
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
PHP_METHOD(Ice_Db_Driver_Pdo, find)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, fields;
	zval from_zv, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, result, _0, _1;
	zend_string *from = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from_zv);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		ZEPHIR_Z_PARAM_ARRAY(fields, fields_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filters = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		options_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		fields_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&from_zv);
	ZVAL_STR_COPY(&from_zv, from);
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
	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, &from_zv, filters, &options, &fields);
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
PHP_METHOD(Ice_Db_Driver_Pdo, count)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval from_zv, *filters = NULL, filters_sub, result, _0, _2, _3;
	zend_string *from = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from_zv);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("total", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filters = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&from_zv);
	ZVAL_STR_COPY(&from_zv, from);
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
	ZEPHIR_CALL_METHOD(&result, this_ptr, "findone", NULL, 0, &from_zv, filters, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	if (zephir_is_true(&result)) {
		zephir_memory_observe(&_3);
		zephir_read_property_cached(&_3, &result, _zephir_prop_0, 0, PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_LONG(&_2, zephir_get_intval(&_3));
	} else {
		ZEPHIR_INIT_NVAR(&_2);
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
PHP_METHOD(Ice_Db_Driver_Pdo, where)
{
	zend_bool _52$$4, _32$$5, _26$$14, _44$$28, _75$$38, _69$$47, _87$$61;
	zend_string *_6$$4, *_22$$14, *_40$$28, *_65$$47, *_83$$61;
	zend_ulong _5$$4, _21$$14, _39$$28, _64$$47, _82$$61;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_13 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _0$$3;
	zval values, options, _8$$8, _54$$41;
	zval *filters = NULL, filters_sub, *values_param = NULL, *options_param = NULL, and, data, operator, key, item, value, or, is, index, i, sql, condition, column, _1, *_2$$4, _3$$4, *_4$$4, _51$$4, _94$$4, tmp$$8, _7$$8, *_9$$5, _10$$5, *_11$$5, _31$$5, _14$$9, _16$$10, _17$$12, j$$14, id$$14, ids$$14, *_18$$14, _19$$14, *_20$$14, _25$$14, _29$$14, _23$$15, _24$$15, _27$$16, _28$$16, _30$$19, _33$$23, _34$$24, _35$$26, j$$28, id$$28, ids$$28, *_36$$28, _37$$28, *_38$$28, _43$$28, _47$$28, _41$$29, _42$$29, _45$$30, _46$$30, _48$$33, _49$$37, _50$$37, tmp$$41, _53$$41, *_55$$38, _56$$38, *_57$$38, _74$$38, _58$$42, _59$$43, _60$$45, j$$47, id$$47, ids$$47, *_61$$47, _62$$47, *_63$$47, _68$$47, _72$$47, _66$$48, _67$$48, _70$$49, _71$$49, _73$$52, _76$$56, _77$$57, _78$$59, j$$61, id$$61, ids$$61, *_79$$61, _80$$61, *_81$$61, _86$$61, _90$$61, _84$$62, _85$$62, _88$$63, _89$$63, _91$$66, _92$$70, _93$$70, _95$$71, _96$$71, _97$$71, _98$$71;
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
	ZVAL_UNDEF(&_51$$4);
	ZVAL_UNDEF(&_94$$4);
	ZVAL_UNDEF(&tmp$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_31$$5);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&j$$14);
	ZVAL_UNDEF(&id$$14);
	ZVAL_UNDEF(&ids$$14);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_33$$23);
	ZVAL_UNDEF(&_34$$24);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&j$$28);
	ZVAL_UNDEF(&id$$28);
	ZVAL_UNDEF(&ids$$28);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_43$$28);
	ZVAL_UNDEF(&_47$$28);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&_45$$30);
	ZVAL_UNDEF(&_46$$30);
	ZVAL_UNDEF(&_48$$33);
	ZVAL_UNDEF(&_49$$37);
	ZVAL_UNDEF(&_50$$37);
	ZVAL_UNDEF(&tmp$$41);
	ZVAL_UNDEF(&_53$$41);
	ZVAL_UNDEF(&_56$$38);
	ZVAL_UNDEF(&_74$$38);
	ZVAL_UNDEF(&_58$$42);
	ZVAL_UNDEF(&_59$$43);
	ZVAL_UNDEF(&_60$$45);
	ZVAL_UNDEF(&j$$47);
	ZVAL_UNDEF(&id$$47);
	ZVAL_UNDEF(&ids$$47);
	ZVAL_UNDEF(&_62$$47);
	ZVAL_UNDEF(&_68$$47);
	ZVAL_UNDEF(&_72$$47);
	ZVAL_UNDEF(&_66$$48);
	ZVAL_UNDEF(&_67$$48);
	ZVAL_UNDEF(&_70$$49);
	ZVAL_UNDEF(&_71$$49);
	ZVAL_UNDEF(&_73$$52);
	ZVAL_UNDEF(&_76$$56);
	ZVAL_UNDEF(&_77$$57);
	ZVAL_UNDEF(&_78$$59);
	ZVAL_UNDEF(&j$$61);
	ZVAL_UNDEF(&id$$61);
	ZVAL_UNDEF(&ids$$61);
	ZVAL_UNDEF(&_80$$61);
	ZVAL_UNDEF(&_86$$61);
	ZVAL_UNDEF(&_90$$61);
	ZVAL_UNDEF(&_84$$62);
	ZVAL_UNDEF(&_85$$62);
	ZVAL_UNDEF(&_88$$63);
	ZVAL_UNDEF(&_89$$63);
	ZVAL_UNDEF(&_91$$66);
	ZVAL_UNDEF(&_92$$70);
	ZVAL_UNDEF(&_93$$70);
	ZVAL_UNDEF(&_95$$71);
	ZVAL_UNDEF(&_96$$71);
	ZVAL_UNDEF(&_97$$71);
	ZVAL_UNDEF(&_98$$71);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_54$$41);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("identifier", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("id", 2, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_INIT_VAR(&or);
	array_init(&or);
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
	if (ZEPHIR_IS_STRING(&_1, "array")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&_1, "integer")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&_1, "string")) { goto zephir_switch_0_clause_2; }
	goto zephir_switch_0_clause_3;
	zephir_switch_0_clause_0: ;
		if (Z_TYPE_P(filters) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_string_to_char_array(&_3$$4, filters);
			_2$$4 = &_3$$4;
		} else {
			_2$$4 = filters;
		}
		zephir_is_iterable(_2$$4, 0, "ice/db/driver/pdo.zep", 275);
		if (Z_TYPE_P(_2$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_2$$4), _5$$4, _6$$4, _4$$4)
			{
				ZEPHIR_INIT_NVAR(&operator);
				if (_6$$4 != NULL) { 
					ZVAL_STR_COPY(&operator, _6$$4);
				} else {
					ZVAL_LONG(&operator, _5$$4);
				}
				ZEPHIR_INIT_NVAR(&data);
				ZVAL_COPY(&data, _4$$4);
				if (ZEPHIR_IS_STRING(&operator, "OR")) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_STRING(&operator, "or")) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_STRING(&operator, "$or")) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_STRING(&operator, "AND")) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_STRING(&operator, "and")) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_STRING(&operator, "$and")) { goto zephir_switch_1_clause_5; }
				goto zephir_switch_1_clause_6;
				zephir_switch_1_clause_0: ;
				zephir_switch_1_clause_1: ;
				zephir_switch_1_clause_2: ;
					ZEPHIR_INIT_NVAR(&or);
					array_init(&or);
					ZEPHIR_INIT_NVAR(&operator);
					ZVAL_STRING(&operator, "OR");
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
				zephir_switch_1_clause_4: ;
				zephir_switch_1_clause_5: ;
					ZEPHIR_INIT_NVAR(&operator);
					ZVAL_STRING(&operator, "AND");
					goto zephir_switch_1_end;
				zephir_switch_1_clause_6: ;
					ZEPHIR_CPY_WRT(&tmp$$8, &data);
					ZEPHIR_INIT_NVAR(&_7$$8);
					zephir_create_array(&_7$$8, 1, 0);
					ZEPHIR_INIT_NVAR(&_8$$8);
					zephir_create_array(&_8$$8, 1, 0);
					zephir_array_update_zval(&_8$$8, &operator, &tmp$$8, PH_COPY);
					zephir_array_update_string(&_7$$8, SL("AND"), &_8$$8, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&data, &_7$$8);
					ZEPHIR_INIT_NVAR(&operator);
					ZVAL_STRING(&operator, "AND");
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

				if (Z_TYPE_P(&data) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_10$$5);
					zephir_string_to_char_array(&_10$$5, &data);
					_9$$5 = &_10$$5;
				} else {
					_9$$5 = &data;
				}
				zephir_is_iterable(_9$$5, 0, "ice/db/driver/pdo.zep", 271);
				if (Z_TYPE_P(_9$$5) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$5), _11$$5)
					{
						ZEPHIR_INIT_NVAR(&item);
						ZVAL_COPY(&item, _11$$5);
						ZEPHIR_CALL_FUNCTION(&key, "key", &_12, 103, &item);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&value, "current", &_13, 102, &item);
						zephir_check_call_status();
						zephir_read_property_cached(&_14$$9, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_FUNCTION(&column, "sprintf", &_15, 12, &_14$$9, &key);
						zephir_check_call_status();
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							ZEPHIR_CALL_FUNCTION(&is, "key", &_12, 103, &value);
							zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&_16$$10, "current", &_13, 102, &value);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&value, &_16$$10);
						} else {
							ZEPHIR_INIT_NVAR(&is);
							ZVAL_STRING(&is, "=");
						}
						do {
							ZEPHIR_INIT_NVAR(&index);
							ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
							ZEPHIR_INIT_NVAR(&_17$$12);
							if (zephir_is_true(&i)) {
								ZEPHIR_INIT_NVAR(&_17$$12);
								ZVAL_LONG(&_17$$12, (zephir_get_intval(&i) + 1));
							} else {
								ZEPHIR_INIT_NVAR(&_17$$12);
								ZVAL_LONG(&_17$$12, 1);
							}
							ZEPHIR_CPY_WRT(&i, &_17$$12);
						} while (zephir_array_isset_value(&values, &index));
						if (ZEPHIR_IS_STRING(&is, "IN")) { goto zephir_switch_2_clause_0; }
						if (ZEPHIR_IS_STRING(&is, "in")) { goto zephir_switch_2_clause_1; }
						if (ZEPHIR_IS_STRING(&is, "$in")) { goto zephir_switch_2_clause_2; }
						if (ZEPHIR_IS_STRING(&is, "IS")) { goto zephir_switch_2_clause_3; }
						if (ZEPHIR_IS_STRING(&is, "is")) { goto zephir_switch_2_clause_4; }
						if (ZEPHIR_IS_STRING(&is, "IS NOT")) { goto zephir_switch_2_clause_5; }
						if (ZEPHIR_IS_STRING(&is, "is not")) { goto zephir_switch_2_clause_6; }
						goto zephir_switch_2_clause_7;
						zephir_switch_2_clause_0: ;
						zephir_switch_2_clause_1: ;
						zephir_switch_2_clause_2: ;
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&ids$$14);
								array_init(&ids$$14);
								if (Z_TYPE_P(&value) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_19$$14);
									zephir_string_to_char_array(&_19$$14, &value);
									_18$$14 = &_19$$14;
								} else {
									_18$$14 = &value;
								}
								zephir_is_iterable(_18$$14, 0, "ice/db/driver/pdo.zep", 241);
								if (Z_TYPE_P(_18$$14) == IS_ARRAY) {
									ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_18$$14), _21$$14, _22$$14, _20$$14)
									{
										ZEPHIR_INIT_NVAR(&j$$14);
										if (_22$$14 != NULL) { 
											ZVAL_STR_COPY(&j$$14, _22$$14);
										} else {
											ZVAL_LONG(&j$$14, _21$$14);
										}
										ZEPHIR_INIT_NVAR(&id$$14);
										ZVAL_COPY(&id$$14, _20$$14);
										ZEPHIR_INIT_NVAR(&_23$$15);
										ZEPHIR_CONCAT_VV(&_23$$15, &index, &j$$14);
										zephir_array_append(&ids$$14, &_23$$15, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
										ZEPHIR_INIT_NVAR(&_24$$15);
										ZEPHIR_CONCAT_VV(&_24$$15, &index, &j$$14);
										zephir_array_update_zval(&values, &_24$$15, &id$$14, PH_COPY | PH_SEPARATE);
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, _18$$14, "rewind", NULL, 0);
									zephir_check_call_status();
									_26$$14 = 1;
									while (1) {
										if (_26$$14) {
											_26$$14 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, _18$$14, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_25$$14, _18$$14, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_25$$14)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&j$$14, _18$$14, "key", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&id$$14, _18$$14, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_27$$16);
											ZEPHIR_CONCAT_VV(&_27$$16, &index, &j$$14);
											zephir_array_append(&ids$$14, &_27$$16, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
											ZEPHIR_INIT_NVAR(&_28$$16);
											ZEPHIR_CONCAT_VV(&_28$$16, &index, &j$$14);
											zephir_array_update_zval(&values, &_28$$16, &id$$14, PH_COPY | PH_SEPARATE);
									}
								}
								ZEPHIR_INIT_NVAR(&id$$14);
								ZEPHIR_INIT_NVAR(&j$$14);
								ZEPHIR_INIT_NVAR(&_29$$14);
								zephir_fast_join_str(&_29$$14, SL(", "), &ids$$14);
								ZEPHIR_INIT_NVAR(&value);
								ZEPHIR_CONCAT_SVS(&value, "(", &_29$$14, ")");
							}
							ZEPHIR_INIT_NVAR(&condition);
							ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
							goto zephir_switch_2_end;
						zephir_switch_2_clause_3: ;
						zephir_switch_2_clause_4: ;
						zephir_switch_2_clause_5: ;
						zephir_switch_2_clause_6: ;
							ZEPHIR_INIT_NVAR(&condition);
							ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
							goto zephir_switch_2_end;
						zephir_switch_2_clause_7: ;
							if (zephir_array_isset_value_string(&options, SL("insensitive"))) {
								ZEPHIR_INIT_NVAR(&_30$$19);
								ZVAL_STRING(&_30$$19, "LOWER(%s) %s LOWER(%s)");
								ZEPHIR_CALL_FUNCTION(&condition, "sprintf", &_15, 12, &_30$$19, &column, &is, &index);
								zephir_check_call_status();
							} else {
								ZEPHIR_INIT_NVAR(&condition);
								ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &index);
							}
							zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
							goto zephir_switch_2_end;
						zephir_switch_2_end: ;

						if (ZEPHIR_IS_STRING(&operator, "AND")) {
							zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 265);
						} else {
							zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 267);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _9$$5, "rewind", NULL, 0);
					zephir_check_call_status();
					_32$$5 = 1;
					while (1) {
						if (_32$$5) {
							_32$$5 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _9$$5, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_31$$5, _9$$5, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_31$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&item, _9$$5, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&key, "key", &_12, 103, &item);
							zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&value, "current", &_13, 102, &item);
							zephir_check_call_status();
							zephir_read_property_cached(&_33$$23, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_FUNCTION(&column, "sprintf", &_15, 12, &_33$$23, &key);
							zephir_check_call_status();
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEPHIR_CALL_FUNCTION(&is, "key", &_12, 103, &value);
								zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_34$$24, "current", &_13, 102, &value);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&value, &_34$$24);
							} else {
								ZEPHIR_INIT_NVAR(&is);
								ZVAL_STRING(&is, "=");
							}
							do {
								ZEPHIR_INIT_NVAR(&index);
								ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
								ZEPHIR_INIT_NVAR(&_35$$26);
								if (zephir_is_true(&i)) {
									ZEPHIR_INIT_NVAR(&_35$$26);
									ZVAL_LONG(&_35$$26, (zephir_get_intval(&i) + 1));
								} else {
									ZEPHIR_INIT_NVAR(&_35$$26);
									ZVAL_LONG(&_35$$26, 1);
								}
								ZEPHIR_CPY_WRT(&i, &_35$$26);
							} while (zephir_array_isset_value(&values, &index));
							if (ZEPHIR_IS_STRING(&is, "IN")) { goto zephir_switch_3_clause_0; }
							if (ZEPHIR_IS_STRING(&is, "in")) { goto zephir_switch_3_clause_1; }
							if (ZEPHIR_IS_STRING(&is, "$in")) { goto zephir_switch_3_clause_2; }
							if (ZEPHIR_IS_STRING(&is, "IS")) { goto zephir_switch_3_clause_3; }
							if (ZEPHIR_IS_STRING(&is, "is")) { goto zephir_switch_3_clause_4; }
							if (ZEPHIR_IS_STRING(&is, "IS NOT")) { goto zephir_switch_3_clause_5; }
							if (ZEPHIR_IS_STRING(&is, "is not")) { goto zephir_switch_3_clause_6; }
							goto zephir_switch_3_clause_7;
							zephir_switch_3_clause_0: ;
							zephir_switch_3_clause_1: ;
							zephir_switch_3_clause_2: ;
								if (Z_TYPE_P(&value) == IS_ARRAY) {
									ZEPHIR_INIT_NVAR(&ids$$28);
									array_init(&ids$$28);
									if (Z_TYPE_P(&value) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_37$$28);
										zephir_string_to_char_array(&_37$$28, &value);
										_36$$28 = &_37$$28;
									} else {
										_36$$28 = &value;
									}
									zephir_is_iterable(_36$$28, 0, "ice/db/driver/pdo.zep", 241);
									if (Z_TYPE_P(_36$$28) == IS_ARRAY) {
										ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_36$$28), _39$$28, _40$$28, _38$$28)
										{
											ZEPHIR_INIT_NVAR(&j$$28);
											if (_40$$28 != NULL) { 
												ZVAL_STR_COPY(&j$$28, _40$$28);
											} else {
												ZVAL_LONG(&j$$28, _39$$28);
											}
											ZEPHIR_INIT_NVAR(&id$$28);
											ZVAL_COPY(&id$$28, _38$$28);
											ZEPHIR_INIT_NVAR(&_41$$29);
											ZEPHIR_CONCAT_VV(&_41$$29, &index, &j$$28);
											zephir_array_append(&ids$$28, &_41$$29, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
											ZEPHIR_INIT_NVAR(&_42$$29);
											ZEPHIR_CONCAT_VV(&_42$$29, &index, &j$$28);
											zephir_array_update_zval(&values, &_42$$29, &id$$28, PH_COPY | PH_SEPARATE);
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _36$$28, "rewind", NULL, 0);
										zephir_check_call_status();
										_44$$28 = 1;
										while (1) {
											if (_44$$28) {
												_44$$28 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _36$$28, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_43$$28, _36$$28, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_43$$28)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&j$$28, _36$$28, "key", NULL, 0);
											zephir_check_call_status();
											ZEPHIR_CALL_METHOD(&id$$28, _36$$28, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_45$$30);
												ZEPHIR_CONCAT_VV(&_45$$30, &index, &j$$28);
												zephir_array_append(&ids$$28, &_45$$30, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
												ZEPHIR_INIT_NVAR(&_46$$30);
												ZEPHIR_CONCAT_VV(&_46$$30, &index, &j$$28);
												zephir_array_update_zval(&values, &_46$$30, &id$$28, PH_COPY | PH_SEPARATE);
										}
									}
									ZEPHIR_INIT_NVAR(&id$$28);
									ZEPHIR_INIT_NVAR(&j$$28);
									ZEPHIR_INIT_NVAR(&_47$$28);
									zephir_fast_join_str(&_47$$28, SL(", "), &ids$$28);
									ZEPHIR_INIT_NVAR(&value);
									ZEPHIR_CONCAT_SVS(&value, "(", &_47$$28, ")");
								}
								ZEPHIR_INIT_NVAR(&condition);
								ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
								goto zephir_switch_3_end;
							zephir_switch_3_clause_3: ;
							zephir_switch_3_clause_4: ;
							zephir_switch_3_clause_5: ;
							zephir_switch_3_clause_6: ;
								ZEPHIR_INIT_NVAR(&condition);
								ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
								goto zephir_switch_3_end;
							zephir_switch_3_clause_7: ;
								if (zephir_array_isset_value_string(&options, SL("insensitive"))) {
									ZEPHIR_INIT_NVAR(&_48$$33);
									ZVAL_STRING(&_48$$33, "LOWER(%s) %s LOWER(%s)");
									ZEPHIR_CALL_FUNCTION(&condition, "sprintf", &_15, 12, &_48$$33, &column, &is, &index);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&condition);
									ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &index);
								}
								zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
								goto zephir_switch_3_end;
							zephir_switch_3_end: ;

							if (ZEPHIR_IS_STRING(&operator, "AND")) {
								zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 265);
							} else {
								zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 267);
							}
					}
				}
				ZEPHIR_INIT_NVAR(&item);
				if (ZEPHIR_IS_STRING(&operator, "OR")) {
					ZEPHIR_INIT_NVAR(&_49$$37);
					zephir_fast_join_str(&_49$$37, SL(" OR "), &or);
					ZEPHIR_INIT_NVAR(&_50$$37);
					ZEPHIR_CONCAT_SVS(&_50$$37, "(", &_49$$37, ")");
					zephir_array_append(&and, &_50$$37, PH_SEPARATE, "ice/db/driver/pdo.zep", 272);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _2$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_52$$4 = 1;
			while (1) {
				if (_52$$4) {
					_52$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _2$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_51$$4, _2$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_51$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&operator, _2$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&data, _2$$4, "current", NULL, 0);
				zephir_check_call_status();
					if (ZEPHIR_IS_STRING(&operator, "OR")) { goto zephir_switch_4_clause_0; }
					if (ZEPHIR_IS_STRING(&operator, "or")) { goto zephir_switch_4_clause_1; }
					if (ZEPHIR_IS_STRING(&operator, "$or")) { goto zephir_switch_4_clause_2; }
					if (ZEPHIR_IS_STRING(&operator, "AND")) { goto zephir_switch_4_clause_3; }
					if (ZEPHIR_IS_STRING(&operator, "and")) { goto zephir_switch_4_clause_4; }
					if (ZEPHIR_IS_STRING(&operator, "$and")) { goto zephir_switch_4_clause_5; }
					goto zephir_switch_4_clause_6;
					zephir_switch_4_clause_0: ;
					zephir_switch_4_clause_1: ;
					zephir_switch_4_clause_2: ;
						ZEPHIR_INIT_NVAR(&or);
						array_init(&or);
						ZEPHIR_INIT_NVAR(&operator);
						ZVAL_STRING(&operator, "OR");
						goto zephir_switch_4_end;
					zephir_switch_4_clause_3: ;
					zephir_switch_4_clause_4: ;
					zephir_switch_4_clause_5: ;
						ZEPHIR_INIT_NVAR(&operator);
						ZVAL_STRING(&operator, "AND");
						goto zephir_switch_4_end;
					zephir_switch_4_clause_6: ;
						ZEPHIR_CPY_WRT(&tmp$$41, &data);
						ZEPHIR_INIT_NVAR(&_53$$41);
						zephir_create_array(&_53$$41, 1, 0);
						ZEPHIR_INIT_NVAR(&_54$$41);
						zephir_create_array(&_54$$41, 1, 0);
						zephir_array_update_zval(&_54$$41, &operator, &tmp$$41, PH_COPY);
						zephir_array_update_string(&_53$$41, SL("AND"), &_54$$41, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&data, &_53$$41);
						ZEPHIR_INIT_NVAR(&operator);
						ZVAL_STRING(&operator, "AND");
						goto zephir_switch_4_end;
					zephir_switch_4_end: ;

					if (Z_TYPE_P(&data) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_56$$38);
						zephir_string_to_char_array(&_56$$38, &data);
						_55$$38 = &_56$$38;
					} else {
						_55$$38 = &data;
					}
					zephir_is_iterable(_55$$38, 0, "ice/db/driver/pdo.zep", 271);
					if (Z_TYPE_P(_55$$38) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_55$$38), _57$$38)
						{
							ZEPHIR_INIT_NVAR(&item);
							ZVAL_COPY(&item, _57$$38);
							ZEPHIR_CALL_FUNCTION(&key, "key", &_12, 103, &item);
							zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&value, "current", &_13, 102, &item);
							zephir_check_call_status();
							zephir_read_property_cached(&_58$$42, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_FUNCTION(&column, "sprintf", &_15, 12, &_58$$42, &key);
							zephir_check_call_status();
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEPHIR_CALL_FUNCTION(&is, "key", &_12, 103, &value);
								zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_59$$43, "current", &_13, 102, &value);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&value, &_59$$43);
							} else {
								ZEPHIR_INIT_NVAR(&is);
								ZVAL_STRING(&is, "=");
							}
							do {
								ZEPHIR_INIT_NVAR(&index);
								ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
								ZEPHIR_INIT_NVAR(&_60$$45);
								if (zephir_is_true(&i)) {
									ZEPHIR_INIT_NVAR(&_60$$45);
									ZVAL_LONG(&_60$$45, (zephir_get_intval(&i) + 1));
								} else {
									ZEPHIR_INIT_NVAR(&_60$$45);
									ZVAL_LONG(&_60$$45, 1);
								}
								ZEPHIR_CPY_WRT(&i, &_60$$45);
							} while (zephir_array_isset_value(&values, &index));
							if (ZEPHIR_IS_STRING(&is, "IN")) { goto zephir_switch_5_clause_0; }
							if (ZEPHIR_IS_STRING(&is, "in")) { goto zephir_switch_5_clause_1; }
							if (ZEPHIR_IS_STRING(&is, "$in")) { goto zephir_switch_5_clause_2; }
							if (ZEPHIR_IS_STRING(&is, "IS")) { goto zephir_switch_5_clause_3; }
							if (ZEPHIR_IS_STRING(&is, "is")) { goto zephir_switch_5_clause_4; }
							if (ZEPHIR_IS_STRING(&is, "IS NOT")) { goto zephir_switch_5_clause_5; }
							if (ZEPHIR_IS_STRING(&is, "is not")) { goto zephir_switch_5_clause_6; }
							goto zephir_switch_5_clause_7;
							zephir_switch_5_clause_0: ;
							zephir_switch_5_clause_1: ;
							zephir_switch_5_clause_2: ;
								if (Z_TYPE_P(&value) == IS_ARRAY) {
									ZEPHIR_INIT_NVAR(&ids$$47);
									array_init(&ids$$47);
									if (Z_TYPE_P(&value) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_62$$47);
										zephir_string_to_char_array(&_62$$47, &value);
										_61$$47 = &_62$$47;
									} else {
										_61$$47 = &value;
									}
									zephir_is_iterable(_61$$47, 0, "ice/db/driver/pdo.zep", 241);
									if (Z_TYPE_P(_61$$47) == IS_ARRAY) {
										ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_61$$47), _64$$47, _65$$47, _63$$47)
										{
											ZEPHIR_INIT_NVAR(&j$$47);
											if (_65$$47 != NULL) { 
												ZVAL_STR_COPY(&j$$47, _65$$47);
											} else {
												ZVAL_LONG(&j$$47, _64$$47);
											}
											ZEPHIR_INIT_NVAR(&id$$47);
											ZVAL_COPY(&id$$47, _63$$47);
											ZEPHIR_INIT_NVAR(&_66$$48);
											ZEPHIR_CONCAT_VV(&_66$$48, &index, &j$$47);
											zephir_array_append(&ids$$47, &_66$$48, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
											ZEPHIR_INIT_NVAR(&_67$$48);
											ZEPHIR_CONCAT_VV(&_67$$48, &index, &j$$47);
											zephir_array_update_zval(&values, &_67$$48, &id$$47, PH_COPY | PH_SEPARATE);
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _61$$47, "rewind", NULL, 0);
										zephir_check_call_status();
										_69$$47 = 1;
										while (1) {
											if (_69$$47) {
												_69$$47 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _61$$47, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_68$$47, _61$$47, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_68$$47)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&j$$47, _61$$47, "key", NULL, 0);
											zephir_check_call_status();
											ZEPHIR_CALL_METHOD(&id$$47, _61$$47, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_70$$49);
												ZEPHIR_CONCAT_VV(&_70$$49, &index, &j$$47);
												zephir_array_append(&ids$$47, &_70$$49, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
												ZEPHIR_INIT_NVAR(&_71$$49);
												ZEPHIR_CONCAT_VV(&_71$$49, &index, &j$$47);
												zephir_array_update_zval(&values, &_71$$49, &id$$47, PH_COPY | PH_SEPARATE);
										}
									}
									ZEPHIR_INIT_NVAR(&id$$47);
									ZEPHIR_INIT_NVAR(&j$$47);
									ZEPHIR_INIT_NVAR(&_72$$47);
									zephir_fast_join_str(&_72$$47, SL(", "), &ids$$47);
									ZEPHIR_INIT_NVAR(&value);
									ZEPHIR_CONCAT_SVS(&value, "(", &_72$$47, ")");
								}
								ZEPHIR_INIT_NVAR(&condition);
								ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
								goto zephir_switch_5_end;
							zephir_switch_5_clause_3: ;
							zephir_switch_5_clause_4: ;
							zephir_switch_5_clause_5: ;
							zephir_switch_5_clause_6: ;
								ZEPHIR_INIT_NVAR(&condition);
								ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
								goto zephir_switch_5_end;
							zephir_switch_5_clause_7: ;
								if (zephir_array_isset_value_string(&options, SL("insensitive"))) {
									ZEPHIR_INIT_NVAR(&_73$$52);
									ZVAL_STRING(&_73$$52, "LOWER(%s) %s LOWER(%s)");
									ZEPHIR_CALL_FUNCTION(&condition, "sprintf", &_15, 12, &_73$$52, &column, &is, &index);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&condition);
									ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &index);
								}
								zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
								goto zephir_switch_5_end;
							zephir_switch_5_end: ;

							if (ZEPHIR_IS_STRING(&operator, "AND")) {
								zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 265);
							} else {
								zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 267);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _55$$38, "rewind", NULL, 0);
						zephir_check_call_status();
						_75$$38 = 1;
						while (1) {
							if (_75$$38) {
								_75$$38 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _55$$38, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_74$$38, _55$$38, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_74$$38)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&item, _55$$38, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&key, "key", &_12, 103, &item);
								zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&value, "current", &_13, 102, &item);
								zephir_check_call_status();
								zephir_read_property_cached(&_76$$56, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_FUNCTION(&column, "sprintf", &_15, 12, &_76$$56, &key);
								zephir_check_call_status();
								if (Z_TYPE_P(&value) == IS_ARRAY) {
									ZEPHIR_CALL_FUNCTION(&is, "key", &_12, 103, &value);
									zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_77$$57, "current", &_13, 102, &value);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&value, &_77$$57);
								} else {
									ZEPHIR_INIT_NVAR(&is);
									ZVAL_STRING(&is, "=");
								}
								do {
									ZEPHIR_INIT_NVAR(&index);
									ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
									ZEPHIR_INIT_NVAR(&_78$$59);
									if (zephir_is_true(&i)) {
										ZEPHIR_INIT_NVAR(&_78$$59);
										ZVAL_LONG(&_78$$59, (zephir_get_intval(&i) + 1));
									} else {
										ZEPHIR_INIT_NVAR(&_78$$59);
										ZVAL_LONG(&_78$$59, 1);
									}
									ZEPHIR_CPY_WRT(&i, &_78$$59);
								} while (zephir_array_isset_value(&values, &index));
								if (ZEPHIR_IS_STRING(&is, "IN")) { goto zephir_switch_6_clause_0; }
								if (ZEPHIR_IS_STRING(&is, "in")) { goto zephir_switch_6_clause_1; }
								if (ZEPHIR_IS_STRING(&is, "$in")) { goto zephir_switch_6_clause_2; }
								if (ZEPHIR_IS_STRING(&is, "IS")) { goto zephir_switch_6_clause_3; }
								if (ZEPHIR_IS_STRING(&is, "is")) { goto zephir_switch_6_clause_4; }
								if (ZEPHIR_IS_STRING(&is, "IS NOT")) { goto zephir_switch_6_clause_5; }
								if (ZEPHIR_IS_STRING(&is, "is not")) { goto zephir_switch_6_clause_6; }
								goto zephir_switch_6_clause_7;
								zephir_switch_6_clause_0: ;
								zephir_switch_6_clause_1: ;
								zephir_switch_6_clause_2: ;
									if (Z_TYPE_P(&value) == IS_ARRAY) {
										ZEPHIR_INIT_NVAR(&ids$$61);
										array_init(&ids$$61);
										if (Z_TYPE_P(&value) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_80$$61);
											zephir_string_to_char_array(&_80$$61, &value);
											_79$$61 = &_80$$61;
										} else {
											_79$$61 = &value;
										}
										zephir_is_iterable(_79$$61, 0, "ice/db/driver/pdo.zep", 241);
										if (Z_TYPE_P(_79$$61) == IS_ARRAY) {
											ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_79$$61), _82$$61, _83$$61, _81$$61)
											{
												ZEPHIR_INIT_NVAR(&j$$61);
												if (_83$$61 != NULL) { 
													ZVAL_STR_COPY(&j$$61, _83$$61);
												} else {
													ZVAL_LONG(&j$$61, _82$$61);
												}
												ZEPHIR_INIT_NVAR(&id$$61);
												ZVAL_COPY(&id$$61, _81$$61);
												ZEPHIR_INIT_NVAR(&_84$$62);
												ZEPHIR_CONCAT_VV(&_84$$62, &index, &j$$61);
												zephir_array_append(&ids$$61, &_84$$62, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
												ZEPHIR_INIT_NVAR(&_85$$62);
												ZEPHIR_CONCAT_VV(&_85$$62, &index, &j$$61);
												zephir_array_update_zval(&values, &_85$$62, &id$$61, PH_COPY | PH_SEPARATE);
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _79$$61, "rewind", NULL, 0);
											zephir_check_call_status();
											_87$$61 = 1;
											while (1) {
												if (_87$$61) {
													_87$$61 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _79$$61, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_86$$61, _79$$61, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_86$$61)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&j$$61, _79$$61, "key", NULL, 0);
												zephir_check_call_status();
												ZEPHIR_CALL_METHOD(&id$$61, _79$$61, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_88$$63);
													ZEPHIR_CONCAT_VV(&_88$$63, &index, &j$$61);
													zephir_array_append(&ids$$61, &_88$$63, PH_SEPARATE, "ice/db/driver/pdo.zep", 237);
													ZEPHIR_INIT_NVAR(&_89$$63);
													ZEPHIR_CONCAT_VV(&_89$$63, &index, &j$$61);
													zephir_array_update_zval(&values, &_89$$63, &id$$61, PH_COPY | PH_SEPARATE);
											}
										}
										ZEPHIR_INIT_NVAR(&id$$61);
										ZEPHIR_INIT_NVAR(&j$$61);
										ZEPHIR_INIT_NVAR(&_90$$61);
										zephir_fast_join_str(&_90$$61, SL(", "), &ids$$61);
										ZEPHIR_INIT_NVAR(&value);
										ZEPHIR_CONCAT_SVS(&value, "(", &_90$$61, ")");
									}
									ZEPHIR_INIT_NVAR(&condition);
									ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
									goto zephir_switch_6_end;
								zephir_switch_6_clause_3: ;
								zephir_switch_6_clause_4: ;
								zephir_switch_6_clause_5: ;
								zephir_switch_6_clause_6: ;
									ZEPHIR_INIT_NVAR(&condition);
									ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &value);
									goto zephir_switch_6_end;
								zephir_switch_6_clause_7: ;
									if (zephir_array_isset_value_string(&options, SL("insensitive"))) {
										ZEPHIR_INIT_NVAR(&_91$$66);
										ZVAL_STRING(&_91$$66, "LOWER(%s) %s LOWER(%s)");
										ZEPHIR_CALL_FUNCTION(&condition, "sprintf", &_15, 12, &_91$$66, &column, &is, &index);
										zephir_check_call_status();
									} else {
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VSVSV(&condition, &column, " ", &is, " ", &index);
									}
									zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
									goto zephir_switch_6_end;
								zephir_switch_6_end: ;

								if (ZEPHIR_IS_STRING(&operator, "AND")) {
									zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 265);
								} else {
									zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 267);
								}
						}
					}
					ZEPHIR_INIT_NVAR(&item);
					if (ZEPHIR_IS_STRING(&operator, "OR")) {
						ZEPHIR_INIT_NVAR(&_92$$70);
						zephir_fast_join_str(&_92$$70, SL(" OR "), &or);
						ZEPHIR_INIT_NVAR(&_93$$70);
						ZEPHIR_CONCAT_SVS(&_93$$70, "(", &_92$$70, ")");
						zephir_array_append(&and, &_93$$70, PH_SEPARATE, "ice/db/driver/pdo.zep", 272);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&data);
		ZEPHIR_INIT_NVAR(&operator);
		ZEPHIR_INIT_VAR(&_94$$4);
		zephir_fast_join_str(&_94$$4, SL(" AND "), &and);
		zephir_concat_self(&sql, &_94$$4);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		zephir_read_property_cached(&_95$$71, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_96$$71, this_ptr, _zephir_prop_1, 149, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_97$$71, "sprintf", &_15, 12, &_95$$71, &_96$$71);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_98$$71);
		ZEPHIR_CONCAT_VSV(&_98$$71, &_97$$71, "=", filters);
		zephir_concat_self(&sql, &_98$$71);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
		zephir_concat_self(&sql, filters);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_3: ;
		zephir_concat_self_str(&sql, SL("TRUE"));
		goto zephir_switch_0_end;
	zephir_switch_0_end: ;

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
PHP_METHOD(Ice_Db_Driver_Pdo, select)
{
	zend_bool _42$$20;
	zend_ulong _36$$20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, fields, _10$$13, _11$$13;
	zval from_zv, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, columns, filtered, values, query, sql, _14, _15, _16, _18, _57, _58, _59, _0$$5, _1$$5, _2$$7, _3$$7, _4$$8, _5$$8, _6$$10, _7$$10, _8$$12, _9$$13, _12$$13, _13$$13, _19$$14, _20$$14, _21$$15, _22$$16, _23$$16, _24$$16, _25$$17, _26$$17, _27$$18, _28$$19, _29$$19, _30$$19, _31$$19, key$$20, value$$20, tmp$$20, _32$$20, *_33$$20, _34$$20, *_35$$20, _41$$20, _46$$20, _47$$20, _38$$21, _39$$21, _40$$21, _43$$22, _44$$22, _45$$22, _48$$23, _49$$23, _50$$23, _51$$24, _52$$24, _53$$25, _54$$25, _55$$26, _56$$26;
	zend_string *from = NULL, *_37$$20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from_zv);
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
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_59);
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
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&key$$20);
	ZVAL_UNDEF(&value$$20);
	ZVAL_UNDEF(&tmp$$20);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_41$$20);
	ZVAL_UNDEF(&_46$$20);
	ZVAL_UNDEF(&_47$$20);
	ZVAL_UNDEF(&_38$$21);
	ZVAL_UNDEF(&_39$$21);
	ZVAL_UNDEF(&_40$$21);
	ZVAL_UNDEF(&_43$$22);
	ZVAL_UNDEF(&_44$$22);
	ZVAL_UNDEF(&_45$$22);
	ZVAL_UNDEF(&_48$$23);
	ZVAL_UNDEF(&_49$$23);
	ZVAL_UNDEF(&_50$$23);
	ZVAL_UNDEF(&_51$$24);
	ZVAL_UNDEF(&_52$$24);
	ZVAL_UNDEF(&_53$$25);
	ZVAL_UNDEF(&_54$$25);
	ZVAL_UNDEF(&_55$$26);
	ZVAL_UNDEF(&_56$$26);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$13);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("driverName", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("identifier", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("client", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("error", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		ZEPHIR_Z_PARAM_ARRAY(fields, fields_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filters = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		options_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		fields_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&from_zv);
	ZVAL_STR_COPY(&from_zv, from);
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
	if (zephir_array_isset_value_string(&options, SL("limit"))) {
		zephir_read_property_cached(&_0$$5, this_ptr, _zephir_prop_0, 146, PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_STRING(&_0$$5, "sqlsrv")) {
			if (zephir_array_isset_value_string(&options, SL("offset"))) {
				zephir_memory_observe(&_2$$7);
				zephir_array_fetch_string(&_2$$7, &options, SL("limit"), PH_NOISY, "ice/db/driver/pdo.zep", 324);
				ZEPHIR_INIT_VAR(&_3$$7);
				ZEPHIR_CONCAT_SVS(&_3$$7, " ROWS FETCH NEXT ", &_2$$7, " ROWS ONLY");
				zephir_array_update_string(&options, SL("offset"), &_3$$7, PH_COPY | PH_SEPARATE);
			} else {
				zephir_memory_observe(&_4$$8);
				zephir_array_fetch_string(&_4$$8, &options, SL("limit"), PH_NOISY, "ice/db/driver/pdo.zep", 326);
				ZEPHIR_INIT_VAR(&_5$$8);
				ZEPHIR_CONCAT_SVS(&_5$$8, "TOP ", &_4$$8, " ");
				zephir_concat_self(&sql, &_5$$8);
			}
			zephir_array_unset_string(&options, SL("limit"), PH_SEPARATE);
		} else {
			zephir_read_property_cached(&_1$$5, this_ptr, _zephir_prop_0, 146, PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_STRING(&_1$$5, "oci")) {
				if (zephir_array_isset_value_string(&options, SL("offset"))) {
					zephir_memory_observe(&_6$$10);
					zephir_array_fetch_string(&_6$$10, &options, SL("limit"), PH_NOISY, "ice/db/driver/pdo.zep", 331);
					ZEPHIR_INIT_VAR(&_7$$10);
					ZEPHIR_CONCAT_SVS(&_7$$10, " ROWS FETCH NEXT ", &_6$$10, " ROWS ONLY");
					zephir_array_update_string(&options, SL("offset"), &_7$$10, PH_COPY | PH_SEPARATE);
				} else {
					if (ZEPHIR_IS_EMPTY(filters)) {
						zephir_memory_observe(&_8$$12);
						zephir_array_fetch_string(&_8$$12, &options, SL("limit"), PH_NOISY, "ice/db/driver/pdo.zep", 334);
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
						zephir_memory_observe(&_13$$13);
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
	}
	ZEPHIR_INIT_VAR(&_14);
	array_init(&_14);
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters, &_14, &options);
	zephir_check_call_status();
	zephir_read_property_cached(&_15, this_ptr, _zephir_prop_1, 147, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_16, "sprintf", &_17, 12, &_15, &from_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_18);
	ZEPHIR_CONCAT_VSV(&_18, &columns, " FROM ", &_16);
	zephir_concat_self(&sql, &_18);
	zephir_memory_observe(&values);
	zephir_array_fetch_long(&values, &filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 345);
	if (!(zephir_isempty_dim_long(&filtered, 0))) {
		zephir_memory_observe(&_19$$14);
		zephir_array_fetch_long(&_19$$14, &filtered, 0, PH_NOISY, "ice/db/driver/pdo.zep", 348);
		ZEPHIR_INIT_VAR(&_20$$14);
		ZEPHIR_CONCAT_SV(&_20$$14, " WHERE ", &_19$$14);
		zephir_concat_self(&sql, &_20$$14);
	}
	if (zephir_array_isset_value_string(&options, SL("group"))) {
		zephir_memory_observe(&_21$$15);
		zephir_array_fetch_string(&_21$$15, &options, SL("group"), PH_NOISY, "ice/db/driver/pdo.zep", 352);
		if (Z_TYPE_P(&_21$$15) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_22$$16);
			zephir_memory_observe(&_23$$16);
			zephir_array_fetch_string(&_23$$16, &options, SL("group"), PH_NOISY, "ice/db/driver/pdo.zep", 353);
			zephir_fast_join_str(&_22$$16, SL(", "), &_23$$16);
			ZEPHIR_INIT_VAR(&_24$$16);
			ZEPHIR_CONCAT_SV(&_24$$16, " GROUP BY ", &_22$$16);
			zephir_concat_self(&sql, &_24$$16);
		} else {
			zephir_memory_observe(&_25$$17);
			zephir_array_fetch_string(&_25$$17, &options, SL("group"), PH_NOISY, "ice/db/driver/pdo.zep", 355);
			ZEPHIR_INIT_VAR(&_26$$17);
			ZEPHIR_CONCAT_SV(&_26$$17, " GROUP BY ", &_25$$17);
			zephir_concat_self(&sql, &_26$$17);
		}
	}
	if (zephir_array_isset_value_string(&options, SL("order"))) {
		zephir_memory_observe(&_27$$18);
		zephir_array_fetch_string(&_27$$18, &options, SL("order"), PH_NOISY, "ice/db/driver/pdo.zep", 359);
		if (Z_TYPE_P(&_27$$18) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_28$$19);
			zephir_memory_observe(&_29$$19);
			zephir_array_fetch_string(&_29$$19, &options, SL("order"), PH_NOISY, "ice/db/driver/pdo.zep", 361);
			zephir_array_keys(&_28$$19, &_29$$19);
			ZEPHIR_INIT_VAR(&_30$$19);
			ZVAL_STRING(&_30$$19, "is_string");
			ZEPHIR_CALL_FUNCTION(&_31$$19, "array_filter", NULL, 8, &_28$$19, &_30$$19);
			zephir_check_call_status();
			if (zephir_fast_count_int(&_31$$19)) {
				ZEPHIR_INIT_VAR(&tmp$$20);
				array_init(&tmp$$20);
				zephir_memory_observe(&_32$$20);
				zephir_array_fetch_string(&_32$$20, &options, SL("order"), PH_NOISY, "ice/db/driver/pdo.zep", 364);
				if (Z_TYPE_P(&_32$$20) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_34$$20);
					zephir_string_to_char_array(&_34$$20, &_32$$20);
					_33$$20 = &_34$$20;
				} else {
					_33$$20 = &_32$$20;
				}
				zephir_is_iterable(_33$$20, 0, "ice/db/driver/pdo.zep", 368);
				if (Z_TYPE_P(_33$$20) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_33$$20), _36$$20, _37$$20, _35$$20)
					{
						ZEPHIR_INIT_NVAR(&key$$20);
						if (_37$$20 != NULL) { 
							ZVAL_STR_COPY(&key$$20, _37$$20);
						} else {
							ZVAL_LONG(&key$$20, _36$$20);
						}
						ZEPHIR_INIT_NVAR(&value$$20);
						ZVAL_COPY(&value$$20, _35$$20);
						zephir_read_property_cached(&_38$$21, this_ptr, _zephir_prop_1, 147, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_FUNCTION(&_39$$21, "sprintf", &_17, 12, &_38$$21, &key$$20);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_40$$21);
						ZEPHIR_CONCAT_VSV(&_40$$21, &_39$$21, " ", &value$$20);
						zephir_array_append(&tmp$$20, &_40$$21, PH_SEPARATE, "ice/db/driver/pdo.zep", 365);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _33$$20, "rewind", NULL, 0);
					zephir_check_call_status();
					_42$$20 = 1;
					while (1) {
						if (_42$$20) {
							_42$$20 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _33$$20, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_41$$20, _33$$20, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_41$$20)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key$$20, _33$$20, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value$$20, _33$$20, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property_cached(&_43$$22, this_ptr, _zephir_prop_1, 147, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_FUNCTION(&_44$$22, "sprintf", &_17, 12, &_43$$22, &key$$20);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_45$$22);
							ZEPHIR_CONCAT_VSV(&_45$$22, &_44$$22, " ", &value$$20);
							zephir_array_append(&tmp$$20, &_45$$22, PH_SEPARATE, "ice/db/driver/pdo.zep", 365);
					}
				}
				ZEPHIR_INIT_NVAR(&value$$20);
				ZEPHIR_INIT_NVAR(&key$$20);
				ZEPHIR_INIT_VAR(&_46$$20);
				zephir_fast_join_str(&_46$$20, SL(", "), &tmp$$20);
				ZEPHIR_INIT_VAR(&_47$$20);
				ZEPHIR_CONCAT_SV(&_47$$20, " ORDER BY ", &_46$$20);
				zephir_concat_self(&sql, &_47$$20);
			} else {
				ZEPHIR_INIT_VAR(&_48$$23);
				zephir_memory_observe(&_49$$23);
				zephir_array_fetch_string(&_49$$23, &options, SL("order"), PH_NOISY, "ice/db/driver/pdo.zep", 370);
				zephir_fast_join_str(&_48$$23, SL(", "), &_49$$23);
				ZEPHIR_INIT_VAR(&_50$$23);
				ZEPHIR_CONCAT_SV(&_50$$23, " ORDER BY ", &_48$$23);
				zephir_concat_self(&sql, &_50$$23);
			}
		} else {
			zephir_memory_observe(&_51$$24);
			zephir_array_fetch_string(&_51$$24, &options, SL("order"), PH_NOISY, "ice/db/driver/pdo.zep", 373);
			ZEPHIR_INIT_VAR(&_52$$24);
			ZEPHIR_CONCAT_SV(&_52$$24, " ORDER BY ", &_51$$24);
			zephir_concat_self(&sql, &_52$$24);
		}
	}
	if (zephir_array_isset_value_string(&options, SL("limit"))) {
		zephir_memory_observe(&_53$$25);
		zephir_array_fetch_string(&_53$$25, &options, SL("limit"), PH_NOISY, "ice/db/driver/pdo.zep", 377);
		ZEPHIR_INIT_VAR(&_54$$25);
		ZEPHIR_CONCAT_SV(&_54$$25, " LIMIT ", &_53$$25);
		zephir_concat_self(&sql, &_54$$25);
	}
	if (zephir_array_isset_value_string(&options, SL("offset"))) {
		zephir_memory_observe(&_55$$26);
		zephir_array_fetch_string(&_55$$26, &options, SL("offset"), PH_NOISY, "ice/db/driver/pdo.zep", 380);
		ZEPHIR_INIT_VAR(&_56$$26);
		ZEPHIR_CONCAT_SV(&_56$$26, " OFFSET ", &_55$$26);
		zephir_concat_self(&sql, &_56$$26);
	}
	zephir_read_property_cached(&_57, this_ptr, _zephir_prop_2, 148, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_57, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_58);
	ZEPHIR_CALL_METHOD(&_59, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	if (zephir_is_true(&_59)) {
		ZEPHIR_INIT_NVAR(&_58);
		ZVAL_NULL(&_58);
	} else {
		ZEPHIR_CALL_METHOD(&_58, &query, "errorinfo", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 150, &_58);
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
PHP_METHOD(Ice_Db_Driver_Pdo, insert)
{
	zend_bool _8;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval from_zv, *fields_param = NULL, key, value, columns, values, sql, query, status, *_0, _7, _12, _13, _14, _15, _16, _17, _18, _3$$3, _4$$3, _6$$3, _9$$4, _10$$4, _11$$4;
	zend_string *from = NULL, *_2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&fields);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("identifier", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("client", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("error", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(fields, fields_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		fields_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&from_zv);
	ZVAL_STR_COPY(&from_zv, from);
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
			zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", &_5, 12, &_3$$3, &key);
			zephir_check_call_status();
			zephir_array_append(&columns, &_4$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 409);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_CONCAT_SV(&_6$$3, ":", &key);
			zephir_array_update_zval(&values, &_6$$3, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &fields, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &fields, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property_cached(&_9$$4, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_10$$4, "sprintf", &_5, 12, &_9$$4, &key);
				zephir_check_call_status();
				zephir_array_append(&columns, &_10$$4, PH_SEPARATE, "ice/db/driver/pdo.zep", 409);
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZEPHIR_CONCAT_SV(&_11$$4, ":", &key);
				zephir_array_update_zval(&values, &_11$$4, &value, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_read_property_cached(&_12, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_13, "sprintf", &_5, 12, &_12, &from_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_14);
	zephir_fast_join_str(&_14, SL(", "), &columns);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_INIT_VAR(&_16);
	zephir_array_keys(&_16, &values);
	zephir_fast_join_str(&_15, SL(", "), &_16);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSVSVS(&sql, "INSERT INTO ", &_13, " (", &_14, ") VALUES (", &_15, ")");
	zephir_read_property_cached(&_17, this_ptr, _zephir_prop_1, 148, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_17, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_18);
	if (zephir_is_true(&status)) {
		ZEPHIR_INIT_NVAR(&_18);
		ZVAL_NULL(&_18);
	} else {
		ZEPHIR_CALL_METHOD(&_18, &query, "errorinfo", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 150, &_18);
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
PHP_METHOD(Ice_Db_Driver_Pdo, update)
{
	zend_bool _9;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval from_zv, *filters = NULL, filters_sub, *fields_param = NULL, key, value, columns, values, filtered, sql, query, status, *_0, _8, _14, _15, _16, _17, _18, _19, _20, _21, _3$$3, _4$$3, _5$$3, _7$$3, _10$$4, _11$$4, _12$$4, _13$$4;
	zend_string *from = NULL, *_2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from_zv);
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
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&fields);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("identifier", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("client", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("error", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
		ZEPHIR_Z_PARAM_ARRAY(fields, fields_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filters = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		fields_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&from_zv);
	ZVAL_STR_COPY(&from_zv, from);
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
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_CONCAT_SV(&_3$$3, ":", &key);
			zephir_array_update_zval(&values, &_3$$3, &value, PH_COPY | PH_SEPARATE);
			zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", &_6, 12, &_4$$3, &key);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZEPHIR_CONCAT_VSV(&_7$$3, &_5$$3, " = :", &key);
			zephir_array_append(&columns, &_7$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 442);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		_9 = 1;
		while (1) {
			if (_9) {
				_9 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_8, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &fields, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &fields, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$4);
				ZEPHIR_CONCAT_SV(&_10$$4, ":", &key);
				zephir_array_update_zval(&values, &_10$$4, &value, PH_COPY | PH_SEPARATE);
				zephir_read_property_cached(&_11$$4, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_12$$4, "sprintf", &_6, 12, &_11$$4, &key);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$4);
				ZEPHIR_CONCAT_VSV(&_13$$4, &_12$$4, " = :", &key);
				zephir_array_append(&columns, &_13$$4, PH_SEPARATE, "ice/db/driver/pdo.zep", 442);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters, &values);
	zephir_check_call_status();
	zephir_read_property_cached(&_14, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_15, "sprintf", &_6, 12, &_14, &from_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_16);
	zephir_fast_join_str(&_16, SL(", "), &columns);
	zephir_memory_observe(&_17);
	zephir_array_fetch_long(&_17, &filtered, 0, PH_NOISY, "ice/db/driver/pdo.zep", 446);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSVSV(&sql, "UPDATE ", &_15, " SET ", &_16, " WHERE ", &_17);
	ZEPHIR_INIT_VAR(&_18);
	zephir_memory_observe(&_19);
	zephir_array_fetch_long(&_19, &filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 447);
	zephir_fast_array_merge(&_18, &values, &_19);
	ZEPHIR_CPY_WRT(&values, &_18);
	zephir_read_property_cached(&_20, this_ptr, _zephir_prop_1, 148, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_20, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_21);
	if (zephir_is_true(&status)) {
		ZEPHIR_INIT_NVAR(&_21);
		ZVAL_NULL(&_21);
	} else {
		ZEPHIR_CALL_METHOD(&_21, &query, "errorinfo", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 150, &_21);
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
PHP_METHOD(Ice_Db_Driver_Pdo, delete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval from_zv, *filters = NULL, filters_sub, filtered, sql, values, query, status, _0, _1, _2, _3, _4;
	zend_string *from = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from_zv);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("identifier", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("client", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("error", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(from)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(filters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filters = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&from_zv);
	ZVAL_STR_COPY(&from_zv, from);
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 147, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", NULL, 12, &_0, &from_zv);
	zephir_check_call_status();
	zephir_memory_observe(&_2);
	zephir_array_fetch_long(&_2, &filtered, 0, PH_NOISY, "ice/db/driver/pdo.zep", 471);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSV(&sql, "DELETE FROM ", &_1, " WHERE ", &_2);
	zephir_memory_observe(&values);
	zephir_array_fetch_long(&values, &filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 472);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 148, PH_NOISY_CC | PH_READONLY);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 150, &_4);
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
PHP_METHOD(Ice_Db_Driver_Pdo, query)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval sql_zv, *values_param = NULL, *obj = NULL, obj_sub, __$null, query, result, status, _0, _1, _4, _3$$3;
	zend_string *sql = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql_zv);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("client", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("error", 5, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(sql)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
		Z_PARAM_ZVAL_OR_NULL(obj)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		values_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		obj = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&sql_zv);
	ZVAL_STR_COPY(&sql_zv, sql);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 148, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_0, "prepare", NULL, 0, &sql_zv);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 150, &_1);
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
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_NULL(&_4);
	}
	RETURN_CCTOR(&_4);
}

/**
 * Get last inserted ID.
 *
 * @return int
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getLastInsertId)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("client", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 148, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "lastinsertid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(&_1));
}

/**
 * Get an error message.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getError)
{
	zval error, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("error", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&error);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 150, PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_long_fetch(&error, &_0, 0, 0);
	RETURN_CCTOR(&error);
}

