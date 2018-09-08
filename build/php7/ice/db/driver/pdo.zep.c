
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
#include "kernel/concat.h"
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

/**
 * Instantiate pdo connection.
 *
 * @param string dsn
 * @param string user
 * @param string password
 * @param array options
 */
PHP_METHOD(Ice_Db_Driver_Pdo, __construct) {

	zend_class_entry *_8;
	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *dsn_param = NULL, *user_param = NULL, *password_param = NULL, *options_param = NULL, __$true, parts, pdo, _0, _1, _3, _4, _5, _7;
	zval dsn, user, password, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&pdo);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
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


	ZEPHIR_INIT_VAR(&parts);
	ZVAL_NULL(&parts);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/^.+?(?:dbname|database)=(.+?)(?=;|$)/i");
	zephir_preg_match(&_0, &_1, &dsn, &parts, 0, 0 , 0  TSRMLS_CC);
	_2 = zephir_array_isset_long(&parts, 0);
	if (_2) {
		zephir_array_fetch_long(&_3, &parts, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 40 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, ":");
		ZEPHIR_CALL_FUNCTION(&_5, "strstr", NULL, 67, &_3, &_4, &__$true);
		zephir_check_call_status();
		_2 = ZEPHIR_IS_STRING(&_5, "mysql");
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_VS(&_6$$3, &dsn, ";charset=utf8");
		ZEPHIR_CPY_WRT(&dsn, &_6$$3);
	}
	ZEPHIR_INIT_VAR(&pdo);
	ZVAL_STRING(&pdo, "Pdo");
	ZEPHIR_INIT_NVAR(&_4);
	zephir_fetch_safe_class(&_7, &pdo);
	_8 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_7), Z_STRLEN_P(&_7), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&_4, _8);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 0, &dsn, &user, &password, &options);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("client"), &_4);
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
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zval values, _5$$8;
	zval *filters = NULL, filters_sub, *values_param = NULL, and, data, operator, key, item, value, or, is, index, i, sql, condition, _1, *_2$$4, _19$$4, tmp$$8, *_6$$5, _9$$10, _10$$12, j$$14, id$$14, ids$$14, *_11$$14, _16$$14, _14$$15, _15$$15, _17$$20, _18$$20, _20$$21;
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
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&tmp$$8);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&j$$14);
	ZVAL_UNDEF(&id$$14);
	ZVAL_UNDEF(&ids$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_17$$20);
	ZVAL_UNDEF(&_18$$20);
	ZVAL_UNDEF(&_20$$21);
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
			zephir_is_iterable(filters, 0, "ice/db/driver/pdo.zep", 228);
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

				zephir_is_iterable(&data, 0, "ice/db/driver/pdo.zep", 224);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _6$$5)
				{
					ZEPHIR_INIT_NVAR(&item);
					ZVAL_COPY(&item, _6$$5);
					ZEPHIR_CALL_FUNCTION(&key, "key", &_7, 68, &item);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&value, "current", &_8, 65, &item);
					zephir_check_call_status();
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEPHIR_CALL_FUNCTION(&is, "key", &_7, 68, &value);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_9$$10, "current", &_8, 65, &value);
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
								zephir_is_iterable(&value, 0, "ice/db/driver/pdo.zep", 199);
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
									zephir_array_append(&ids$$14, &_14$$15, PH_SEPARATE, "ice/db/driver/pdo.zep", 195);
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
							ZEPHIR_INIT_NVAR(&condition);
							ZEPHIR_CONCAT_SVSVSV(&condition, "`", &key, "` ", &is, " ", &value);
							break;
						}
						if (ZEPHIR_IS_STRING(&is, "IS") || ZEPHIR_IS_STRING(&is, "is") || ZEPHIR_IS_STRING(&is, "IS NOT") || ZEPHIR_IS_STRING(&is, "is not")) {
							ZEPHIR_INIT_NVAR(&condition);
							ZEPHIR_CONCAT_SVSVSV(&condition, "`", &key, "` ", &is, " ", &value);
							break;
						}
						ZEPHIR_INIT_NVAR(&condition);
						ZEPHIR_CONCAT_SVSVSV(&condition, "`", &key, "` ", &is, " ", &index);
						zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
						break;
					} while(0);

					if (ZEPHIR_IS_STRING(&operator, "AND")) {
						zephir_array_append(&and, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 218);
					} else {
						zephir_array_append(&or, &condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 220);
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&item);
				if (ZEPHIR_IS_STRING(&operator, "OR")) {
					ZEPHIR_INIT_NVAR(&_17$$20);
					zephir_fast_join_str(&_17$$20, SL(" OR "), &or TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_18$$20);
					ZEPHIR_CONCAT_SVS(&_18$$20, "(", &_17$$20, ")");
					zephir_array_append(&and, &_18$$20, PH_SEPARATE, "ice/db/driver/pdo.zep", 225);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&data);
			ZEPHIR_INIT_NVAR(&operator);
			ZEPHIR_INIT_VAR(&_19$$4);
			zephir_fast_join_str(&_19$$4, SL(" AND "), &and TSRMLS_CC);
			zephir_concat_self(&sql, &_19$$4 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "integer")) {
			ZEPHIR_INIT_VAR(&_20$$21);
			ZEPHIR_CONCAT_SV(&_20$$21, "`id` = ", filters);
			zephir_concat_self(&sql, &_20$$21 TSRMLS_CC);
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
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 */
PHP_METHOD(Ice_Db_Driver_Pdo, select) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *options_param = NULL, *fields_param = NULL, columns, sql, filtered, values, query, _0, _11, _12, _1$$5, _2$$5, _3$$5, _4$$6, _5$$6, _6$$6, _7$$7, _8$$7, _9$$8, _10$$8;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
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


	if (zephir_fast_count_int(&fields TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&columns);
		zephir_fast_join_str(&columns, SL(", "), &fields TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&columns);
		ZVAL_STRING(&columns, "*");
	}
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 263 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSVSV(&sql, "SELECT ", &columns, " FROM `", &from, "` WHERE ", &_0);
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_long(&values, &filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 264 TSRMLS_CC);
	if (zephir_array_isset_string(&options, SL("group"))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		zephir_array_fetch_string(&_2$$5, &options, SL("group"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 267 TSRMLS_CC);
		zephir_fast_join_str(&_1$$5, SL(", "), &_2$$5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CONCAT_SV(&_3$$5, " GROUP BY ", &_1$$5);
		zephir_concat_self(&sql, &_3$$5 TSRMLS_CC);
	}
	if (zephir_array_isset_string(&options, SL("order"))) {
		ZEPHIR_INIT_VAR(&_4$$6);
		zephir_array_fetch_string(&_5$$6, &options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 270 TSRMLS_CC);
		zephir_fast_join_str(&_4$$6, SL(", "), &_5$$6 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$6);
		ZEPHIR_CONCAT_SV(&_6$$6, " ORDER BY ", &_4$$6);
		zephir_concat_self(&sql, &_6$$6 TSRMLS_CC);
	}
	if (zephir_array_isset_string(&options, SL("limit"))) {
		zephir_array_fetch_string(&_7$$7, &options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 273 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_8$$7);
		ZEPHIR_CONCAT_SV(&_8$$7, " LIMIT ", &_7$$7);
		zephir_concat_self(&sql, &_8$$7 TSRMLS_CC);
	}
	if (zephir_array_isset_string(&options, SL("offset"))) {
		zephir_array_fetch_string(&_9$$8, &options, SL("offset"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 276 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_10$$8);
		ZEPHIR_CONCAT_SV(&_10$$8, " OFFSET ", &_9$$8);
		zephir_concat_self(&sql, &_10$$8 TSRMLS_CC);
	}
	zephir_read_property(&_11, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_11, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, &query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_12);
	RETURN_CCTOR(query);

}

/**
 * INSERT record into table.
 *
 * @param string from Table name
 * @param array fields Fields to insert, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Pdo, insert) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval *from_param = NULL, *fields_param = NULL, key, value, columns, values, sql, query, status, *_0, _5, _6, _7, _8, _9, _3$$3, _4$$3;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
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
	zephir_is_iterable(&fields, 0, "ice/db/driver/pdo.zep", 306);
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
		ZEPHIR_CONCAT_SVS(&_3$$3, "`", &key, "`");
		zephir_array_append(&columns, &_3$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 302);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SV(&_4$$3, ":", &key);
		zephir_array_update_zval(&values, &_4$$3, &value, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_5);
	zephir_fast_join_str(&_5, SL(", "), &columns TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_INIT_VAR(&_7);
	zephir_array_keys(&_7, &values TSRMLS_CC);
	zephir_fast_join_str(&_6, SL(", "), &_7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSVSVS(&sql, "INSERT INTO `", &from, "` (", &_5, ") VALUES (", &_6, ")");
	zephir_read_property(&_8, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_8, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, &query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_9);
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

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *fields_param = NULL, key, value, columns, values, filtered, sql, query, status, *_0, _5, _6, _7, _8, _9, _10, _3$$3, _4$$3;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
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
	zephir_is_iterable(&fields, 0, "ice/db/driver/pdo.zep", 333);
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
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SVSV(&_4$$3, "`", &key, "` = :", &key);
		zephir_array_append(&columns, &_4$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 330);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters, &values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_fast_join_str(&_5, SL(", "), &columns TSRMLS_CC);
	zephir_array_fetch_long(&_6, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 334 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSVSV(&sql, "UPDATE `", &from, "` SET ", &_5, " WHERE ", &_6);
	ZEPHIR_INIT_VAR(&_7);
	zephir_array_fetch_long(&_8, &filtered, 1, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 335 TSRMLS_CC);
	zephir_fast_array_merge(&_7, &values, &_8 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&values, &_7);
	zephir_read_property(&_9, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_9, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, &query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_10);
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
	zval *from_param = NULL, *filters = NULL, filters_sub, filtered, sql, values, query, status, _0, _1, _2;
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
	zephir_array_fetch_long(&_0, &filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 354 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSV(&sql, "DELETE FROM `", &from, "` WHERE ", &_0);
	ZEPHIR_OBS_VAR(&values);
	zephir_array_fetch_long(&values, &filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 355 TSRMLS_CC);
	zephir_read_property(&_1, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_1, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_2);
	RETURN_CCTOR(status);

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
	RETURN_CTORW(error);

}

