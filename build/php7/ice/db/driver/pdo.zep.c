
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
 * @copyright   (c) 2014-2020 Ice Team
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
	zephir_read_property(&_2, this_ptr, SL("driverName"), PH_NOISY_CC | PH_READONLY);
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
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, result, _0, _1, _2, _3, _4;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);

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
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, &result, "rowcount", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		object_init_ex(&_1, ice_arr_ce);
		ZVAL_LONG(&_4, 2);
		ZEPHIR_CALL_METHOD(&_3, &result, "fetch", NULL, 0, &_4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 4, &_3);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	RETURN_CCTOR(&_1);

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
 * Prepare SQL WHERE condition.
 *
 * @params mixed filters
 * @params array values
 */
PHP_METHOD(Ice_Db_Driver_Pdo, where) {

	zend_string *_5$$4, *_17$$14, *_35$$26, *_58$$43, *_75$$55;
	zend_ulong _4$$4, _16$$14, _34$$26, _57$$43, _74$$55;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL, *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _0$$3;
	zval values, _7$$8, _50$$37;
	zval *filters = NULL, filters_sub, *values_param = NULL, and, data, operator, key, item, value, or, is, index, i, sql, condition, _1, *_2$$4, _3$$4, _89$$4, tmp$$8, _6$$8, *_8$$5, _9$$5, _12$$10, _13$$12, j$$14, id$$14, ids$$14, *_14$$14, _15$$14, _22$$14, _18$$15, _19$$15, _20$$16, _21$$16, _23$$13, _24$$13, _26$$17, _27$$17, _28$$18, _29$$18, _30$$22, _31$$24, j$$26, id$$26, ids$$26, *_32$$26, _33$$26, _40$$26, _36$$27, _37$$27, _38$$28, _39$$28, _41$$25, _42$$25, _43$$29, _44$$29, _45$$30, _46$$30, _47$$33, _48$$33, tmp$$37, _49$$37, *_51$$34, _52$$34, _53$$39, _54$$41, j$$43, id$$43, ids$$43, *_55$$43, _56$$43, _63$$43, _59$$44, _60$$44, _61$$45, _62$$45, _64$$42, _65$$42, _66$$46, _67$$46, _68$$47, _69$$47, _70$$51, _71$$53, j$$55, id$$55, ids$$55, *_72$$55, _73$$55, _80$$55, _76$$56, _77$$56, _78$$57, _79$$57, _81$$54, _82$$54, _83$$58, _84$$58, _85$$59, _86$$59, _87$$62, _88$$62, _90$$63, _91$$63, _92$$63, _93$$63;
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
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_89$$4);
	ZVAL_UNDEF(&tmp$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&j$$14);
	ZVAL_UNDEF(&id$$14);
	ZVAL_UNDEF(&ids$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&j$$26);
	ZVAL_UNDEF(&id$$26);
	ZVAL_UNDEF(&ids$$26);
	ZVAL_UNDEF(&_33$$26);
	ZVAL_UNDEF(&_40$$26);
	ZVAL_UNDEF(&_36$$27);
	ZVAL_UNDEF(&_37$$27);
	ZVAL_UNDEF(&_38$$28);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&_41$$25);
	ZVAL_UNDEF(&_42$$25);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_45$$30);
	ZVAL_UNDEF(&_46$$30);
	ZVAL_UNDEF(&_47$$33);
	ZVAL_UNDEF(&_48$$33);
	ZVAL_UNDEF(&tmp$$37);
	ZVAL_UNDEF(&_49$$37);
	ZVAL_UNDEF(&_52$$34);
	ZVAL_UNDEF(&_53$$39);
	ZVAL_UNDEF(&_54$$41);
	ZVAL_UNDEF(&j$$43);
	ZVAL_UNDEF(&id$$43);
	ZVAL_UNDEF(&ids$$43);
	ZVAL_UNDEF(&_56$$43);
	ZVAL_UNDEF(&_63$$43);
	ZVAL_UNDEF(&_59$$44);
	ZVAL_UNDEF(&_60$$44);
	ZVAL_UNDEF(&_61$$45);
	ZVAL_UNDEF(&_62$$45);
	ZVAL_UNDEF(&_64$$42);
	ZVAL_UNDEF(&_65$$42);
	ZVAL_UNDEF(&_66$$46);
	ZVAL_UNDEF(&_67$$46);
	ZVAL_UNDEF(&_68$$47);
	ZVAL_UNDEF(&_69$$47);
	ZVAL_UNDEF(&_70$$51);
	ZVAL_UNDEF(&_71$$53);
	ZVAL_UNDEF(&j$$55);
	ZVAL_UNDEF(&id$$55);
	ZVAL_UNDEF(&ids$$55);
	ZVAL_UNDEF(&_73$$55);
	ZVAL_UNDEF(&_80$$55);
	ZVAL_UNDEF(&_76$$56);
	ZVAL_UNDEF(&_77$$56);
	ZVAL_UNDEF(&_78$$57);
	ZVAL_UNDEF(&_79$$57);
	ZVAL_UNDEF(&_81$$54);
	ZVAL_UNDEF(&_82$$54);
	ZVAL_UNDEF(&_83$$58);
	ZVAL_UNDEF(&_84$$58);
	ZVAL_UNDEF(&_85$$59);
	ZVAL_UNDEF(&_86$$59);
	ZVAL_UNDEF(&_87$$62);
	ZVAL_UNDEF(&_88$$62);
	ZVAL_UNDEF(&_90$$63);
	ZVAL_UNDEF(&_91$$63);
	ZVAL_UNDEF(&_92$$63);
	ZVAL_UNDEF(&_93$$63);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_50$$37);

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
	zephir_gettype(&_1, filters);
	do {
		if (ZEPHIR_IS_STRING(&_1, "array")) {
			zephir_is_iterable(filters, 0, "ice/db/driver/pdo.zep", 246);
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

					zephir_is_iterable(&data, 0, "ice/db/driver/pdo.zep", 242);
					if (Z_TYPE_P(&data) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _8$$5)
						{
							ZEPHIR_INIT_NVAR(&item);
							ZVAL_COPY(&item, _8$$5);
							ZEPHIR_CALL_FUNCTION(&key, "key", &_10, 101, &item);
							zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&value, "current", &_11, 99, &item);
							zephir_check_call_status();
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEPHIR_CALL_FUNCTION(&is, "key", &_10, 101, &value);
								zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&_12$$10, "current", &_11, 99, &value);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&value, &_12$$10);
							} else {
								ZEPHIR_INIT_NVAR(&is);
								ZVAL_STRING(&is, "=");
							}
							do {
								ZEPHIR_INIT_NVAR(&index);
								ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
								ZEPHIR_INIT_NVAR(&_13$$12);
								if (zephir_is_true(&i)) {
									ZEPHIR_INIT_NVAR(&_13$$12);
									ZVAL_LONG(&_13$$12, (zephir_get_intval(&i) + 1));
								} else {
									ZEPHIR_INIT_NVAR(&_13$$12);
									ZVAL_LONG(&_13$$12, 1);
								}
								ZEPHIR_CPY_WRT(&i, &_13$$12);
							} while (zephir_array_isset(&values, &index));
							do {
								if (ZEPHIR_IS_STRING(&is, "IN") || ZEPHIR_IS_STRING(&is, "in") || ZEPHIR_IS_STRING(&is, "$in")) {
									if (Z_TYPE_P(&value) == IS_ARRAY) {
										ZEPHIR_INIT_NVAR(&ids$$14);
										array_init(&ids$$14);
										zephir_is_iterable(&value, 0, "ice/db/driver/pdo.zep", 217);
										if (Z_TYPE_P(&value) == IS_ARRAY) {
											ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _16$$14, _17$$14, _14$$14)
											{
												ZEPHIR_INIT_NVAR(&j$$14);
												if (_17$$14 != NULL) { 
													ZVAL_STR_COPY(&j$$14, _17$$14);
												} else {
													ZVAL_LONG(&j$$14, _16$$14);
												}
												ZEPHIR_INIT_NVAR(&id$$14);
												ZVAL_COPY(&id$$14, _14$$14);
												ZEPHIR_INIT_NVAR(&_18$$15);
												ZEPHIR_CONCAT_VV(&_18$$15, &index, &j$$14);
												zephir_array_append(&ids$$14, &_18$$15, PH_SEPARATE, "ice/db/driver/pdo.zep", 213);
												ZEPHIR_INIT_NVAR(&_19$$15);
												ZEPHIR_CONCAT_VV(&_19$$15, &index, &j$$14);
												zephir_array_update_zval(&values, &_19$$15, &id$$14, PH_COPY | PH_SEPARATE);
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_15$$14, &value, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_15$$14)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&j$$14, &value, "key", NULL, 0);
												zephir_check_call_status();
												ZEPHIR_CALL_METHOD(&id$$14, &value, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_20$$16);
													ZEPHIR_CONCAT_VV(&_20$$16, &index, &j$$14);
													zephir_array_append(&ids$$14, &_20$$16, PH_SEPARATE, "ice/db/driver/pdo.zep", 213);
													ZEPHIR_INIT_NVAR(&_21$$16);
													ZEPHIR_CONCAT_VV(&_21$$16, &index, &j$$14);
													zephir_array_update_zval(&values, &_21$$16, &id$$14, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&id$$14);
										ZEPHIR_INIT_NVAR(&j$$14);
										ZEPHIR_INIT_NVAR(&_22$$14);
										zephir_fast_join_str(&_22$$14, SL(", "), &ids$$14);
										ZEPHIR_INIT_NVAR(&value);
										ZEPHIR_CONCAT_SVS(&value, "(", &_22$$14, ")");
									}
									zephir_read_property(&_23$$13, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_FUNCTION(&_24$$13, "sprintf", &_25, 11, &_23$$13, &key);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&condition);
									ZEPHIR_CONCAT_VVSV(&condition, &_24$$13, &is, " ", &value);
									break;
								}
								if (ZEPHIR_IS_STRING(&is, "IS") || ZEPHIR_IS_STRING(&is, "is") || ZEPHIR_IS_STRING(&is, "IS NOT") || ZEPHIR_IS_STRING(&is, "is not")) {
									zephir_read_property(&_26$$17, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_FUNCTION(&_27$$17, "sprintf", &_25, 11, &_26$$17, &key);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&condition);
									ZEPHIR_CONCAT_VVSV(&condition, &_27$$17, &is, " ", &value);
									break;
								}
								zephir_read_property(&_28$$18, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_FUNCTION(&_29$$18, "sprintf", &_25, 11, &_28$$18, &key);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&condition);
								ZEPHIR_CONCAT_VVSV(&condition, &_29$$18, &is, " ", &index);
								zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
								break;
							} while(0);

							if (ZEPHIR_IS_STRING(&operator, "AND")) {
								zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 236);
							} else {
								zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 238);
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
								ZEPHIR_CALL_FUNCTION(&key, "key", &_10, 101, &item);
								zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&value, "current", &_11, 99, &item);
								zephir_check_call_status();
								if (Z_TYPE_P(&value) == IS_ARRAY) {
									ZEPHIR_CALL_FUNCTION(&is, "key", &_10, 101, &value);
									zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_30$$22, "current", &_11, 99, &value);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&value, &_30$$22);
								} else {
									ZEPHIR_INIT_NVAR(&is);
									ZVAL_STRING(&is, "=");
								}
								do {
									ZEPHIR_INIT_NVAR(&index);
									ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
									ZEPHIR_INIT_NVAR(&_31$$24);
									if (zephir_is_true(&i)) {
										ZEPHIR_INIT_NVAR(&_31$$24);
										ZVAL_LONG(&_31$$24, (zephir_get_intval(&i) + 1));
									} else {
										ZEPHIR_INIT_NVAR(&_31$$24);
										ZVAL_LONG(&_31$$24, 1);
									}
									ZEPHIR_CPY_WRT(&i, &_31$$24);
								} while (zephir_array_isset(&values, &index));
								do {
									if (ZEPHIR_IS_STRING(&is, "IN") || ZEPHIR_IS_STRING(&is, "in") || ZEPHIR_IS_STRING(&is, "$in")) {
										if (Z_TYPE_P(&value) == IS_ARRAY) {
											ZEPHIR_INIT_NVAR(&ids$$26);
											array_init(&ids$$26);
											zephir_is_iterable(&value, 0, "ice/db/driver/pdo.zep", 217);
											if (Z_TYPE_P(&value) == IS_ARRAY) {
												ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _34$$26, _35$$26, _32$$26)
												{
													ZEPHIR_INIT_NVAR(&j$$26);
													if (_35$$26 != NULL) { 
														ZVAL_STR_COPY(&j$$26, _35$$26);
													} else {
														ZVAL_LONG(&j$$26, _34$$26);
													}
													ZEPHIR_INIT_NVAR(&id$$26);
													ZVAL_COPY(&id$$26, _32$$26);
													ZEPHIR_INIT_NVAR(&_36$$27);
													ZEPHIR_CONCAT_VV(&_36$$27, &index, &j$$26);
													zephir_array_append(&ids$$26, &_36$$27, PH_SEPARATE, "ice/db/driver/pdo.zep", 213);
													ZEPHIR_INIT_NVAR(&_37$$27);
													ZEPHIR_CONCAT_VV(&_37$$27, &index, &j$$26);
													zephir_array_update_zval(&values, &_37$$27, &id$$26, PH_COPY | PH_SEPARATE);
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_33$$26, &value, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_33$$26)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&j$$26, &value, "key", NULL, 0);
													zephir_check_call_status();
													ZEPHIR_CALL_METHOD(&id$$26, &value, "current", NULL, 0);
													zephir_check_call_status();
														ZEPHIR_INIT_NVAR(&_38$$28);
														ZEPHIR_CONCAT_VV(&_38$$28, &index, &j$$26);
														zephir_array_append(&ids$$26, &_38$$28, PH_SEPARATE, "ice/db/driver/pdo.zep", 213);
														ZEPHIR_INIT_NVAR(&_39$$28);
														ZEPHIR_CONCAT_VV(&_39$$28, &index, &j$$26);
														zephir_array_update_zval(&values, &_39$$28, &id$$26, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&id$$26);
											ZEPHIR_INIT_NVAR(&j$$26);
											ZEPHIR_INIT_NVAR(&_40$$26);
											zephir_fast_join_str(&_40$$26, SL(", "), &ids$$26);
											ZEPHIR_INIT_NVAR(&value);
											ZEPHIR_CONCAT_SVS(&value, "(", &_40$$26, ")");
										}
										zephir_read_property(&_41$$25, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_CALL_FUNCTION(&_42$$25, "sprintf", &_25, 11, &_41$$25, &key);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VVSV(&condition, &_42$$25, &is, " ", &value);
										break;
									}
									if (ZEPHIR_IS_STRING(&is, "IS") || ZEPHIR_IS_STRING(&is, "is") || ZEPHIR_IS_STRING(&is, "IS NOT") || ZEPHIR_IS_STRING(&is, "is not")) {
										zephir_read_property(&_43$$29, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_CALL_FUNCTION(&_44$$29, "sprintf", &_25, 11, &_43$$29, &key);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VVSV(&condition, &_44$$29, &is, " ", &value);
										break;
									}
									zephir_read_property(&_45$$30, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_FUNCTION(&_46$$30, "sprintf", &_25, 11, &_45$$30, &key);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&condition);
									ZEPHIR_CONCAT_VVSV(&condition, &_46$$30, &is, " ", &index);
									zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
									break;
								} while(0);

								if (ZEPHIR_IS_STRING(&operator, "AND")) {
									zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 236);
								} else {
									zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 238);
								}
							ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&item);
					if (ZEPHIR_IS_STRING(&operator, "OR")) {
						ZEPHIR_INIT_NVAR(&_47$$33);
						zephir_fast_join_str(&_47$$33, SL(" OR "), &or);
						ZEPHIR_INIT_NVAR(&_48$$33);
						ZEPHIR_CONCAT_SVS(&_48$$33, "(", &_47$$33, ")");
						zephir_array_append(&and, &_48$$33, PH_SEPARATE, "ice/db/driver/pdo.zep", 243);
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
							ZEPHIR_CPY_WRT(&tmp$$37, &data);
							ZEPHIR_INIT_NVAR(&_49$$37);
							zephir_create_array(&_49$$37, 1, 0);
							ZEPHIR_INIT_NVAR(&_50$$37);
							zephir_create_array(&_50$$37, 1, 0);
							zephir_array_update_zval(&_50$$37, &operator, &tmp$$37, PH_COPY);
							zephir_array_update_string(&_49$$37, SL("AND"), &_50$$37, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&data, &_49$$37);
							ZEPHIR_INIT_NVAR(&operator);
							ZVAL_STRING(&operator, "AND");
							break;
						} while(0);

						zephir_is_iterable(&data, 0, "ice/db/driver/pdo.zep", 242);
						if (Z_TYPE_P(&data) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _51$$34)
							{
								ZEPHIR_INIT_NVAR(&item);
								ZVAL_COPY(&item, _51$$34);
								ZEPHIR_CALL_FUNCTION(&key, "key", &_10, 101, &item);
								zephir_check_call_status();
								ZEPHIR_CALL_FUNCTION(&value, "current", &_11, 99, &item);
								zephir_check_call_status();
								if (Z_TYPE_P(&value) == IS_ARRAY) {
									ZEPHIR_CALL_FUNCTION(&is, "key", &_10, 101, &value);
									zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_53$$39, "current", &_11, 99, &value);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&value, &_53$$39);
								} else {
									ZEPHIR_INIT_NVAR(&is);
									ZVAL_STRING(&is, "=");
								}
								do {
									ZEPHIR_INIT_NVAR(&index);
									ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
									ZEPHIR_INIT_NVAR(&_54$$41);
									if (zephir_is_true(&i)) {
										ZEPHIR_INIT_NVAR(&_54$$41);
										ZVAL_LONG(&_54$$41, (zephir_get_intval(&i) + 1));
									} else {
										ZEPHIR_INIT_NVAR(&_54$$41);
										ZVAL_LONG(&_54$$41, 1);
									}
									ZEPHIR_CPY_WRT(&i, &_54$$41);
								} while (zephir_array_isset(&values, &index));
								do {
									if (ZEPHIR_IS_STRING(&is, "IN") || ZEPHIR_IS_STRING(&is, "in") || ZEPHIR_IS_STRING(&is, "$in")) {
										if (Z_TYPE_P(&value) == IS_ARRAY) {
											ZEPHIR_INIT_NVAR(&ids$$43);
											array_init(&ids$$43);
											zephir_is_iterable(&value, 0, "ice/db/driver/pdo.zep", 217);
											if (Z_TYPE_P(&value) == IS_ARRAY) {
												ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _57$$43, _58$$43, _55$$43)
												{
													ZEPHIR_INIT_NVAR(&j$$43);
													if (_58$$43 != NULL) { 
														ZVAL_STR_COPY(&j$$43, _58$$43);
													} else {
														ZVAL_LONG(&j$$43, _57$$43);
													}
													ZEPHIR_INIT_NVAR(&id$$43);
													ZVAL_COPY(&id$$43, _55$$43);
													ZEPHIR_INIT_NVAR(&_59$$44);
													ZEPHIR_CONCAT_VV(&_59$$44, &index, &j$$43);
													zephir_array_append(&ids$$43, &_59$$44, PH_SEPARATE, "ice/db/driver/pdo.zep", 213);
													ZEPHIR_INIT_NVAR(&_60$$44);
													ZEPHIR_CONCAT_VV(&_60$$44, &index, &j$$43);
													zephir_array_update_zval(&values, &_60$$44, &id$$43, PH_COPY | PH_SEPARATE);
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_56$$43, &value, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_56$$43)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&j$$43, &value, "key", NULL, 0);
													zephir_check_call_status();
													ZEPHIR_CALL_METHOD(&id$$43, &value, "current", NULL, 0);
													zephir_check_call_status();
														ZEPHIR_INIT_NVAR(&_61$$45);
														ZEPHIR_CONCAT_VV(&_61$$45, &index, &j$$43);
														zephir_array_append(&ids$$43, &_61$$45, PH_SEPARATE, "ice/db/driver/pdo.zep", 213);
														ZEPHIR_INIT_NVAR(&_62$$45);
														ZEPHIR_CONCAT_VV(&_62$$45, &index, &j$$43);
														zephir_array_update_zval(&values, &_62$$45, &id$$43, PH_COPY | PH_SEPARATE);
													ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&id$$43);
											ZEPHIR_INIT_NVAR(&j$$43);
											ZEPHIR_INIT_NVAR(&_63$$43);
											zephir_fast_join_str(&_63$$43, SL(", "), &ids$$43);
											ZEPHIR_INIT_NVAR(&value);
											ZEPHIR_CONCAT_SVS(&value, "(", &_63$$43, ")");
										}
										zephir_read_property(&_64$$42, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_CALL_FUNCTION(&_65$$42, "sprintf", &_25, 11, &_64$$42, &key);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VVSV(&condition, &_65$$42, &is, " ", &value);
										break;
									}
									if (ZEPHIR_IS_STRING(&is, "IS") || ZEPHIR_IS_STRING(&is, "is") || ZEPHIR_IS_STRING(&is, "IS NOT") || ZEPHIR_IS_STRING(&is, "is not")) {
										zephir_read_property(&_66$$46, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_CALL_FUNCTION(&_67$$46, "sprintf", &_25, 11, &_66$$46, &key);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VVSV(&condition, &_67$$46, &is, " ", &value);
										break;
									}
									zephir_read_property(&_68$$47, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_FUNCTION(&_69$$47, "sprintf", &_25, 11, &_68$$47, &key);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&condition);
									ZEPHIR_CONCAT_VVSV(&condition, &_69$$47, &is, " ", &index);
									zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
									break;
								} while(0);

								if (ZEPHIR_IS_STRING(&operator, "AND")) {
									zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 236);
								} else {
									zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 238);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_52$$34, &data, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_52$$34)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&item, &data, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&key, "key", &_10, 101, &item);
									zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&value, "current", &_11, 99, &item);
									zephir_check_call_status();
									if (Z_TYPE_P(&value) == IS_ARRAY) {
										ZEPHIR_CALL_FUNCTION(&is, "key", &_10, 101, &value);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_70$$51, "current", &_11, 99, &value);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&value, &_70$$51);
									} else {
										ZEPHIR_INIT_NVAR(&is);
										ZVAL_STRING(&is, "=");
									}
									do {
										ZEPHIR_INIT_NVAR(&index);
										ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
										ZEPHIR_INIT_NVAR(&_71$$53);
										if (zephir_is_true(&i)) {
											ZEPHIR_INIT_NVAR(&_71$$53);
											ZVAL_LONG(&_71$$53, (zephir_get_intval(&i) + 1));
										} else {
											ZEPHIR_INIT_NVAR(&_71$$53);
											ZVAL_LONG(&_71$$53, 1);
										}
										ZEPHIR_CPY_WRT(&i, &_71$$53);
									} while (zephir_array_isset(&values, &index));
									do {
										if (ZEPHIR_IS_STRING(&is, "IN") || ZEPHIR_IS_STRING(&is, "in") || ZEPHIR_IS_STRING(&is, "$in")) {
											if (Z_TYPE_P(&value) == IS_ARRAY) {
												ZEPHIR_INIT_NVAR(&ids$$55);
												array_init(&ids$$55);
												zephir_is_iterable(&value, 0, "ice/db/driver/pdo.zep", 217);
												if (Z_TYPE_P(&value) == IS_ARRAY) {
													ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _74$$55, _75$$55, _72$$55)
													{
														ZEPHIR_INIT_NVAR(&j$$55);
														if (_75$$55 != NULL) { 
															ZVAL_STR_COPY(&j$$55, _75$$55);
														} else {
															ZVAL_LONG(&j$$55, _74$$55);
														}
														ZEPHIR_INIT_NVAR(&id$$55);
														ZVAL_COPY(&id$$55, _72$$55);
														ZEPHIR_INIT_NVAR(&_76$$56);
														ZEPHIR_CONCAT_VV(&_76$$56, &index, &j$$55);
														zephir_array_append(&ids$$55, &_76$$56, PH_SEPARATE, "ice/db/driver/pdo.zep", 213);
														ZEPHIR_INIT_NVAR(&_77$$56);
														ZEPHIR_CONCAT_VV(&_77$$56, &index, &j$$55);
														zephir_array_update_zval(&values, &_77$$56, &id$$55, PH_COPY | PH_SEPARATE);
													} ZEND_HASH_FOREACH_END();
												} else {
													ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
													zephir_check_call_status();
													while (1) {
														ZEPHIR_CALL_METHOD(&_73$$55, &value, "valid", NULL, 0);
														zephir_check_call_status();
														if (!zend_is_true(&_73$$55)) {
															break;
														}
														ZEPHIR_CALL_METHOD(&j$$55, &value, "key", NULL, 0);
														zephir_check_call_status();
														ZEPHIR_CALL_METHOD(&id$$55, &value, "current", NULL, 0);
														zephir_check_call_status();
															ZEPHIR_INIT_NVAR(&_78$$57);
															ZEPHIR_CONCAT_VV(&_78$$57, &index, &j$$55);
															zephir_array_append(&ids$$55, &_78$$57, PH_SEPARATE, "ice/db/driver/pdo.zep", 213);
															ZEPHIR_INIT_NVAR(&_79$$57);
															ZEPHIR_CONCAT_VV(&_79$$57, &index, &j$$55);
															zephir_array_update_zval(&values, &_79$$57, &id$$55, PH_COPY | PH_SEPARATE);
														ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
														zephir_check_call_status();
													}
												}
												ZEPHIR_INIT_NVAR(&id$$55);
												ZEPHIR_INIT_NVAR(&j$$55);
												ZEPHIR_INIT_NVAR(&_80$$55);
												zephir_fast_join_str(&_80$$55, SL(", "), &ids$$55);
												ZEPHIR_INIT_NVAR(&value);
												ZEPHIR_CONCAT_SVS(&value, "(", &_80$$55, ")");
											}
											zephir_read_property(&_81$$54, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
											ZEPHIR_CALL_FUNCTION(&_82$$54, "sprintf", &_25, 11, &_81$$54, &key);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&condition);
											ZEPHIR_CONCAT_VVSV(&condition, &_82$$54, &is, " ", &value);
											break;
										}
										if (ZEPHIR_IS_STRING(&is, "IS") || ZEPHIR_IS_STRING(&is, "is") || ZEPHIR_IS_STRING(&is, "IS NOT") || ZEPHIR_IS_STRING(&is, "is not")) {
											zephir_read_property(&_83$$58, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
											ZEPHIR_CALL_FUNCTION(&_84$$58, "sprintf", &_25, 11, &_83$$58, &key);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&condition);
											ZEPHIR_CONCAT_VVSV(&condition, &_84$$58, &is, " ", &value);
											break;
										}
										zephir_read_property(&_85$$59, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_CALL_FUNCTION(&_86$$59, "sprintf", &_25, 11, &_85$$59, &key);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&condition);
										ZEPHIR_CONCAT_VVSV(&condition, &_86$$59, &is, " ", &index);
										zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
										break;
									} while(0);

									if (ZEPHIR_IS_STRING(&operator, "AND")) {
										zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 236);
									} else {
										zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 238);
									}
								ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&item);
						if (ZEPHIR_IS_STRING(&operator, "OR")) {
							ZEPHIR_INIT_NVAR(&_87$$62);
							zephir_fast_join_str(&_87$$62, SL(" OR "), &or);
							ZEPHIR_INIT_NVAR(&_88$$62);
							ZEPHIR_CONCAT_SVS(&_88$$62, "(", &_87$$62, ")");
							zephir_array_append(&and, &_88$$62, PH_SEPARATE, "ice/db/driver/pdo.zep", 243);
						}
					ZEPHIR_CALL_METHOD(NULL, filters, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&data);
			ZEPHIR_INIT_NVAR(&operator);
			ZEPHIR_INIT_VAR(&_89$$4);
			zephir_fast_join_str(&_89$$4, SL(" AND "), &and);
			zephir_concat_self(&sql, &_89$$4);
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "integer")) {
			zephir_read_property(&_90$$63, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_91$$63, this_ptr, SL("id"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_92$$63, "sprintf", &_25, 11, &_90$$63, &_91$$63);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_93$$63);
			ZEPHIR_CONCAT_VSV(&_93$$63, &_92$$63, "=", filters);
			zephir_concat_self(&sql, &_93$$63);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, fields, _10$$13, _11$$13;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, columns, filtered, values, query, sql, _14, _15, _16, _17, _36, _37, _38, _0$$5, _1$$5, _2$$7, _3$$7, _4$$8, _5$$8, _6$$10, _7$$10, _8$$12, _9$$13, _12$$13, _13$$13, _18$$14, _19$$14, _20$$15, _21$$16, _22$$16, _23$$16, _24$$17, _25$$17, _26$$18, _27$$19, _28$$19, _29$$19, _30$$20, _31$$20, _32$$21, _33$$21, _34$$22, _35$$22;
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
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
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
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_35$$22);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$13);

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
		zephir_read_property(&_0$$5, this_ptr, SL("driverName"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_1$$5, this_ptr, SL("driverName"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_STRING(&_0$$5, "sqlsrv")) {
			if (zephir_array_isset_string(&options, SL("offset"))) {
				zephir_array_fetch_string(&_2$$7, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 295);
				ZEPHIR_INIT_VAR(&_3$$7);
				ZEPHIR_CONCAT_SVS(&_3$$7, " ROWS FETCH NEXT ", &_2$$7, " ROWS ONLY");
				zephir_array_update_string(&options, SL("offset"), &_3$$7, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_fetch_string(&_4$$8, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 297);
				ZEPHIR_INIT_VAR(&_5$$8);
				ZEPHIR_CONCAT_SVS(&_5$$8, "TOP ", &_4$$8, " ");
				zephir_concat_self(&sql, &_5$$8);
			}
			zephir_array_unset_string(&options, SL("limit"), PH_SEPARATE);
		} else if (ZEPHIR_IS_STRING(&_1$$5, "oci")) {
			if (zephir_array_isset_string(&options, SL("offset"))) {
				zephir_array_fetch_string(&_6$$10, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 302);
				ZEPHIR_INIT_VAR(&_7$$10);
				ZEPHIR_CONCAT_SVS(&_7$$10, " ROWS FETCH NEXT ", &_6$$10, " ROWS ONLY");
				zephir_array_update_string(&options, SL("offset"), &_7$$10, PH_COPY | PH_SEPARATE);
			} else {
				if (ZEPHIR_IS_EMPTY(filters)) {
					zephir_array_fetch_string(&_8$$12, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 305);
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
					zephir_array_fetch_string(&_13$$13, &options, SL("limit"), PH_NOISY, "ice/db/driver/pdo.zep", 307);
					zephir_array_fast_append(&_11$$13, &_13$$13);
					zephir_array_fast_append(&_10$$13, &_11$$13);
					zephir_array_update_string(&_9$$13, SL("AND"), &_10$$13, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(filters, &_9$$13);
				}
			}
			zephir_array_unset_string(&options, SL("limit"), PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters);
	zephir_check_call_status();
	zephir_read_property(&_14, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_15, "sprintf", NULL, 11, &_14, &from);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_16);
	ZEPHIR_CONCAT_VSV(&_16, &columns, " FROM ", &_15);
	zephir_concat_self(&sql, &_16);
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_long(&values, &filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 316);
	zephir_array_fetch_long(&_17, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 318);
	if (!(ZEPHIR_IS_EMPTY(&_17))) {
		zephir_array_fetch_long(&_18$$14, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 319);
		ZEPHIR_INIT_VAR(&_19$$14);
		ZEPHIR_CONCAT_SV(&_19$$14, " WHERE ", &_18$$14);
		zephir_concat_self(&sql, &_19$$14);
	}
	if (zephir_array_isset_string(&options, SL("group"))) {
		ZEPHIR_OBS_VAR(&_20$$15);
		zephir_array_fetch_string(&_20$$15, &options, SL("group"), PH_NOISY, "ice/db/driver/pdo.zep", 323);
		if (Z_TYPE_P(&_20$$15) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_21$$16);
			zephir_array_fetch_string(&_22$$16, &options, SL("group"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 324);
			zephir_fast_join_str(&_21$$16, SL(", "), &_22$$16);
			ZEPHIR_INIT_VAR(&_23$$16);
			ZEPHIR_CONCAT_SV(&_23$$16, " GROUP BY ", &_21$$16);
			zephir_concat_self(&sql, &_23$$16);
		} else {
			zephir_array_fetch_string(&_24$$17, &options, SL("group"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 326);
			ZEPHIR_INIT_VAR(&_25$$17);
			ZEPHIR_CONCAT_SV(&_25$$17, " GROUP BY ", &_24$$17);
			zephir_concat_self(&sql, &_25$$17);
		}
	}
	if (zephir_array_isset_string(&options, SL("order"))) {
		ZEPHIR_OBS_VAR(&_26$$18);
		zephir_array_fetch_string(&_26$$18, &options, SL("order"), PH_NOISY, "ice/db/driver/pdo.zep", 330);
		if (Z_TYPE_P(&_26$$18) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_27$$19);
			zephir_array_fetch_string(&_28$$19, &options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 331);
			zephir_fast_join_str(&_27$$19, SL(", "), &_28$$19);
			ZEPHIR_INIT_VAR(&_29$$19);
			ZEPHIR_CONCAT_SV(&_29$$19, " ORDER BY ", &_27$$19);
			zephir_concat_self(&sql, &_29$$19);
		} else {
			zephir_array_fetch_string(&_30$$20, &options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 333);
			ZEPHIR_INIT_VAR(&_31$$20);
			ZEPHIR_CONCAT_SV(&_31$$20, " ORDER BY ", &_30$$20);
			zephir_concat_self(&sql, &_31$$20);
		}
	}
	if (zephir_array_isset_string(&options, SL("limit"))) {
		zephir_array_fetch_string(&_32$$21, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 337);
		ZEPHIR_INIT_VAR(&_33$$21);
		ZEPHIR_CONCAT_SV(&_33$$21, " LIMIT ", &_32$$21);
		zephir_concat_self(&sql, &_33$$21);
	}
	if (zephir_array_isset_string(&options, SL("offset"))) {
		zephir_array_fetch_string(&_34$$22, &options, SL("offset"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 340);
		ZEPHIR_INIT_VAR(&_35$$22);
		ZEPHIR_CONCAT_SV(&_35$$22, " OFFSET ", &_34$$22);
		zephir_concat_self(&sql, &_35$$22);
	}
	zephir_read_property(&_36, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_36, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_37);
	ZEPHIR_CALL_METHOD(&_38, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	if (zephir_is_true(&_38)) {
		ZEPHIR_INIT_NVAR(&_37);
		ZVAL_NULL(&_37);
	} else {
		ZEPHIR_CALL_METHOD(&_37, &query, "errorinfo", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("error"), &_37);
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
	zephir_is_iterable(&fields, 0, "ice/db/driver/pdo.zep", 373);
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
			zephir_read_property(&_4$$3, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", &_6, 11, &_4$$3, &key);
			zephir_check_call_status();
			zephir_array_append(&columns, &_5$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 369);
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
				zephir_read_property(&_8$$4, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_9$$4, "sprintf", &_6, 11, &_8$$4, &key);
				zephir_check_call_status();
				zephir_array_append(&columns, &_9$$4, PH_SEPARATE, "ice/db/driver/pdo.zep", 369);
				ZEPHIR_INIT_NVAR(&_10$$4);
				ZEPHIR_CONCAT_SV(&_10$$4, ":", &key);
				zephir_array_update_zval(&values, &_10$$4, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_read_property(&_11, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property(&_16, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
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
	zephir_is_iterable(&fields, 0, "ice/db/driver/pdo.zep", 405);
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
			zephir_read_property(&_5$$3, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", &_7, 11, &_5$$3, &key);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZEPHIR_CONCAT_VSV(&_8$$3, &_6$$3, " = :", &key);
			zephir_array_append(&columns, &_8$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 402);
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
				zephir_read_property(&_10$$4, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_11$$4, "sprintf", &_7, 11, &_10$$4, &key);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZEPHIR_CONCAT_VSV(&_12$$4, &_11$$4, " = :", &key);
				zephir_array_append(&columns, &_12$$4, PH_SEPARATE, "ice/db/driver/pdo.zep", 402);
			ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters, &values);
	zephir_check_call_status();
	zephir_read_property(&_13, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_14, "sprintf", &_7, 11, &_13, &from);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_15);
	zephir_fast_join_str(&_15, SL(", "), &columns);
	zephir_array_fetch_long(&_16, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 406);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSVSV(&sql, "UPDATE ", &_14, " SET ", &_15, " WHERE ", &_16);
	ZEPHIR_INIT_VAR(&_17);
	zephir_array_fetch_long(&_18, &filtered, 1, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 407);
	zephir_fast_array_merge(&_17, &values, &_18);
	ZEPHIR_CPY_WRT(&values, &_17);
	zephir_read_property(&_19, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property(&_0, this_ptr, SL("identifier"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", NULL, 11, &_0, &from);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 431);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSV(&sql, "DELETE FROM ", &_1, " WHERE ", &_2);
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_long(&values, &filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 432);
	zephir_read_property(&_3, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
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


	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
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
				ZEPHIR_CALL_METHOD(NULL, obj, "replace", NULL, 0, &result);
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
	zephir_array_isset_long_fetch(&error, &_0, 0, 1);
	RETURN_CTORW(&error);

}

