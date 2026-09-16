
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * Database component.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db)
{
	ZEPHIR_REGISTER_CLASS(Ice, Db, ice, db, ice_db_method_entry, 0);

	zend_declare_property_null(ice_db_ce, SL("driver"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Ice_Db, getDriver)
{

	RETURN_MEMBER(getThis(), "driver");
}

PHP_METHOD(Ice_Db, setDriver)
{
	zval *driver, driver_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driver_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("driver", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(driver)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &driver);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 141, driver);
	RETURN_THISW();
}

/**
 * Db constructor.
 *
 * @param mixed dsn
 * @param string host
 * @param int port
 * @param string name
 * @param string user
 * @param string password
 * @param array options
 */
PHP_METHOD(Ice_Db, __construct)
{
	zval _2$$5, _6$$6, _8$$8, _10$$9, _11$$10;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zend_long port, ZEPHIR_LAST_CALL_STATUS;
	zend_string *host = NULL, *name = NULL, *user = NULL, *password = NULL;
	zval *dsn = NULL, dsn_sub, host_zv, *port_param = NULL, name_zv, user_zv, password_zv, *options_param = NULL, tns$$5, _1$$5, _3$$5, _4$$5, _5$$6, _7$$6, settings$$7, _14$$7, _9$$9, _12$$11, _13$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn_sub);
	ZVAL_UNDEF(&host_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&user_zv);
	ZVAL_UNDEF(&password_zv);
	ZVAL_UNDEF(&tns$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&settings$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("driver", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 7)
		Z_PARAM_ZVAL(dsn)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(host)
		Z_PARAM_LONG_OR_NULL(port, is_null_true)
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_STR_OR_NULL(user)
		Z_PARAM_STR_OR_NULL(password)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	dsn = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		port_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 6) {
		options_param = ZEND_CALL_ARG(execute_data, 7);
	}
	if (!host) {
		ZEPHIR_INIT_VAR(&host_zv);
	} else {
		zephir_memory_observe(&host_zv);
	ZVAL_STR_COPY(&host_zv, host);
	}
	if (!port_param) {
		port = 0;
	} else {
		}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
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
	_0 = Z_TYPE_P(dsn) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(dsn, ice_db_dbinterface_ce));
	}
	if (_0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 141, dsn);
	} else if (Z_TYPE_P(dsn) == IS_STRING) {
		if (ZEPHIR_IS_STRING(dsn, "oci")) { goto zephir_switch_0_clause_0; }
		if (ZEPHIR_IS_STRING(dsn, "mongodb")) { goto zephir_switch_0_clause_1; }
		goto zephir_switch_0_clause_2;
		zephir_switch_0_clause_0: ;
			ZEPHIR_INIT_VAR(&_1$$5);
			ZVAL_LONG(&_1$$5, port);
			ZEPHIR_INIT_VAR(&_2$$5);
			ZEPHIR_CONCAT_SVSVS(&_2$$5, "(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=", &host_zv, ")(PORT=", &_1$$5, "))(CONNECT_DATA=(SID=orcl)))");
			ZEPHIR_CPY_WRT(&tns$$5, &_2$$5);
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, ice_db_driver_pdo_ce);
			ZEPHIR_INIT_VAR(&_4$$5);
			ZEPHIR_CONCAT_SV(&_4$$5, "oci:dbname=", &tns$$5);
			ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 98, &_4$$5, &user_zv, &password_zv, &options);
			zephir_check_call_status();
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 141, &_3$$5);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_1: ;
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_LONG(&_5$$6, port);
			ZEPHIR_INIT_VAR(&_6$$6);
			ZEPHIR_CONCAT_SVSVSVSVSV(&_6$$6, "mongodb://", &user_zv, ":", &password_zv, "@", &host_zv, ":", &_5$$6, "/", &name_zv);
			ZEPHIR_CPY_WRT(dsn, &_6$$6);
			ZEPHIR_INIT_VAR(&_7$$6);
			object_init_ex(&_7$$6, ice_db_driver_mongodb_ce);
			ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", NULL, 99, dsn, &name_zv, &options);
			zephir_check_call_status();
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 141, &_7$$6);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_2: ;
			ZEPHIR_INIT_VAR(&settings$$7);
			array_init(&settings$$7);
			if (!(ZEPHIR_IS_EMPTY(&host_zv))) {
				ZEPHIR_INIT_VAR(&_8$$8);
				ZEPHIR_CONCAT_SV(&_8$$8, "host=", &host_zv);
				zephir_array_append(&settings$$7, &_8$$8, PH_SEPARATE, "ice/db.zep", 50);
			}
			if (port) {
				ZEPHIR_INIT_VAR(&_9$$9);
				ZVAL_LONG(&_9$$9, port);
				ZEPHIR_INIT_VAR(&_10$$9);
				ZEPHIR_CONCAT_SV(&_10$$9, "port=", &_9$$9);
				zephir_array_append(&settings$$7, &_10$$9, PH_SEPARATE, "ice/db.zep", 54);
			}
			if (!(ZEPHIR_IS_EMPTY(&name_zv))) {
				ZEPHIR_INIT_VAR(&_11$$10);
				ZEPHIR_CONCAT_SV(&_11$$10, "dbname=", &name_zv);
				zephir_array_append(&settings$$7, &_11$$10, PH_SEPARATE, "ice/db.zep", 58);
			}
			if (zephir_fast_count_int(&settings$$7)) {
				ZEPHIR_INIT_VAR(&_12$$11);
				zephir_fast_join_str(&_12$$11, SL(";"), &settings$$7);
				ZEPHIR_INIT_VAR(&_13$$11);
				ZEPHIR_CONCAT_SV(&_13$$11, ":", &_12$$11);
				zephir_concat_self(dsn, &_13$$11);
			}
			ZEPHIR_INIT_VAR(&_14$$7);
			object_init_ex(&_14$$7, ice_db_driver_pdo_ce);
			ZEPHIR_CALL_METHOD(NULL, &_14$$7, "__construct", NULL, 98, dsn, &user_zv, &password_zv, &options);
			zephir_check_call_status();
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 141, &_14$$7);
			goto zephir_switch_0_end;
		zephir_switch_0_end: ;

	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic call, call driver's method.
 */
PHP_METHOD(Ice_Db, __call)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv, *arguments = NULL, arguments_sub, __$null, _1;
	zend_string *method = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("driver", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(method)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		arguments = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_memory_observe(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 141, PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &method_zv);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, arguments);
	zephir_check_call_status();
	RETURN_MM();
}

