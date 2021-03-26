
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
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db) {

	ZEPHIR_REGISTER_CLASS(Ice, Db, ice, db, ice_db_method_entry, 0);

	zend_declare_property_null(ice_db_ce, SL("driver"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(Ice_Db, getDriver) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "driver");

}

PHP_METHOD(Ice_Db, setDriver) {

	zval *driver, driver_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driver_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(driver)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &driver);



	zephir_update_property_zval(this_ptr, ZEND_STRL("driver"), driver);
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
PHP_METHOD(Ice_Db, __construct) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zend_long port, ZEPHIR_LAST_CALL_STATUS;
	zval host, name, user, password, _2$$5, _6$$6, _8$$8, _10$$9, _11$$10;
	zval *dsn, dsn_sub, *host_param = NULL, *port_param = NULL, *name_param = NULL, *user_param = NULL, *password_param = NULL, *options_param = NULL, tns$$5, _1$$5, _3$$5, _4$$5, dsn$$6, _5$$6, _7$$6, settings$$7, _14$$7, _9$$9, _12$$11, _13$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn_sub);
	ZVAL_UNDEF(&tns$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&dsn$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&settings$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 7)
		Z_PARAM_ZVAL(dsn)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(host)
		Z_PARAM_LONG_OR_NULL(port, is_null_true)
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_STR_OR_NULL(user)
		Z_PARAM_STR_OR_NULL(password)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &dsn, &host_param, &port_param, &name_param, &user_param, &password_param, &options_param);

	if (!host_param) {
		ZEPHIR_INIT_VAR(&host);
		ZVAL_STRING(&host, "");
	} else {
		zephir_get_strval(&host, host_param);
	}
	if (!port_param) {
		port = 0;
	} else {
		port = zephir_get_intval(port_param);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}
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


	_0 = Z_TYPE_P(dsn) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(dsn, ice_db_dbinterface_ce));
	}
	if (_0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("driver"), dsn);
	} else if (Z_TYPE_P(dsn) == IS_STRING) {
		do {
			if (ZEPHIR_IS_STRING(dsn, "oci")) {
				ZEPHIR_INIT_VAR(&_1$$5);
				ZVAL_LONG(&_1$$5, port);
				ZEPHIR_INIT_VAR(&_2$$5);
				ZEPHIR_CONCAT_SVSVS(&_2$$5, "(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=", &host, ")(PORT=", &_1$$5, "))(CONNECT_DATA=(SID=orcl)))");
				ZEPHIR_CPY_WRT(&tns$$5, &_2$$5);
				ZEPHIR_INIT_VAR(&_3$$5);
				object_init_ex(&_3$$5, ice_db_driver_pdo_ce);
				ZEPHIR_INIT_VAR(&_4$$5);
				ZEPHIR_CONCAT_SV(&_4$$5, "oci:dbname=", &tns$$5);
				ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 95, &_4$$5, &user, &password, &options);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, ZEND_STRL("driver"), &_3$$5);
				break;
			}
			if (ZEPHIR_IS_STRING(dsn, "mongodb")) {
				ZEPHIR_INIT_VAR(&_5$$6);
				ZVAL_LONG(&_5$$6, port);
				ZEPHIR_INIT_VAR(&_6$$6);
				ZEPHIR_CONCAT_SVSVSVSVSV(&_6$$6, "mongodb://", &user, ":", &password, "@", &host, ":", &_5$$6, "/", &name);
				ZEPHIR_CPY_WRT(&dsn$$6, &_6$$6);
				ZEPHIR_INIT_VAR(&_7$$6);
				object_init_ex(&_7$$6, ice_db_driver_mongodb_ce);
				ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", NULL, 96, &dsn$$6, &name, &options);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, ZEND_STRL("driver"), &_7$$6);
				break;
			}
			ZEPHIR_INIT_VAR(&settings$$7);
			array_init(&settings$$7);
			if (!(Z_TYPE_P(&host) == IS_UNDEF) && Z_STRLEN_P(&host)) {
				ZEPHIR_INIT_VAR(&_8$$8);
				ZEPHIR_CONCAT_SV(&_8$$8, "host=", &host);
				zephir_array_append(&settings$$7, &_8$$8, PH_SEPARATE, "ice/db.zep", 50);
			}
			if (port) {
				ZEPHIR_INIT_VAR(&_9$$9);
				ZVAL_LONG(&_9$$9, port);
				ZEPHIR_INIT_VAR(&_10$$9);
				ZEPHIR_CONCAT_SV(&_10$$9, "port=", &_9$$9);
				zephir_array_append(&settings$$7, &_10$$9, PH_SEPARATE, "ice/db.zep", 54);
			}
			if (!(Z_TYPE_P(&name) == IS_UNDEF) && Z_STRLEN_P(&name)) {
				ZEPHIR_INIT_VAR(&_11$$10);
				ZEPHIR_CONCAT_SV(&_11$$10, "dbname=", &name);
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
			ZEPHIR_CALL_METHOD(NULL, &_14$$7, "__construct", NULL, 95, dsn, &user, &password, &options);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("driver"), &_14$$7);
			break;
		} while(0);

	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic call, call driver's method.
 */
PHP_METHOD(Ice_Db, __call) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, arguments_sub, __$null, _1;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(method)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(arguments)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	zephir_get_strval(&method, method_param);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, arguments);
	zephir_check_call_status();
	RETURN_MM();

}

