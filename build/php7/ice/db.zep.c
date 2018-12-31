
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


/**
 * Database component.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db) {

	ZEPHIR_REGISTER_CLASS(Ice, Db, ice, db, ice_db_method_entry, 0);

	zend_declare_property_null(ice_db_ce, SL("driver"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zephir_fetch_params(0, 1, 0, &driver);



	zephir_update_property_zval(this_ptr, SL("driver"), driver);
	RETURN_THISW();

}

/**
 * Db constructor.
 *
 * @param mixed driver
 * @param string host
 * @param int port
 * @param string name
 * @param string user
 * @param string password
 * @param array options
 */
PHP_METHOD(Ice_Db, __construct) {

	zend_bool _0;
	zval options;
	zend_long port, ZEPHIR_LAST_CALL_STATUS;
	zval host, name, user, password, _2$$5, _6$$6;
	zval *driver, driver_sub, *host_param = NULL, *port_param = NULL, *name_param = NULL, *user_param = NULL, *password_param = NULL, *options_param = NULL, tns$$5, _1$$5, _3$$5, _4$$5, dsn$$6, _5$$6, _7$$6, _8$$7, _9$$7, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driver_sub);
	ZVAL_UNDEF(&tns$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&dsn$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &driver, &host_param, &port_param, &name_param, &user_param, &password_param, &options_param);

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


	_0 = Z_TYPE_P(driver) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(driver, ice_db_dbinterface_ce TSRMLS_CC));
	}
	if (_0) {
		zephir_update_property_zval(this_ptr, SL("driver"), driver);
	} else if (Z_TYPE_P(driver) == IS_STRING) {
		do {
			if (ZEPHIR_IS_STRING(driver, "oci")) {
				ZEPHIR_SINIT_VAR(_1$$5);
				ZVAL_LONG(&_1$$5, port);
				ZEPHIR_INIT_VAR(&_2$$5);
				ZEPHIR_CONCAT_SVSVS(&_2$$5, "(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=", &host, ")(PORT=", &_1$$5, "))(CONNECT_DATA=(SID=orcl)))");
				ZEPHIR_CPY_WRT(&tns$$5, &_2$$5);
				ZEPHIR_INIT_VAR(&_3$$5);
				object_init_ex(&_3$$5, ice_db_driver_pdo_ce);
				ZEPHIR_INIT_VAR(&_4$$5);
				ZEPHIR_CONCAT_SV(&_4$$5, "oci:dbname=", &tns$$5);
				ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 88, &_4$$5, &user, &password, &options);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("driver"), &_3$$5);
				break;
			}
			if (ZEPHIR_IS_STRING(driver, "mongodb")) {
				ZEPHIR_SINIT_VAR(_5$$6);
				ZVAL_LONG(&_5$$6, port);
				ZEPHIR_INIT_VAR(&_6$$6);
				ZEPHIR_CONCAT_SVSVSVSVSV(&_6$$6, "mongodb://", &user, ":", &password, "@", &host, ":", &_5$$6, "/", &name);
				ZEPHIR_CPY_WRT(&dsn$$6, &_6$$6);
				ZEPHIR_INIT_VAR(&_7$$6);
				object_init_ex(&_7$$6, ice_db_driver_mongodb_ce);
				ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", NULL, 89, &dsn$$6, &name, &options);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("driver"), &_7$$6);
				break;
			}
			ZEPHIR_INIT_VAR(&_8$$7);
			object_init_ex(&_8$$7, ice_db_driver_pdo_ce);
			ZEPHIR_SINIT_VAR(_9$$7);
			ZVAL_LONG(&_9$$7, port);
			ZEPHIR_INIT_VAR(&_10$$7);
			ZEPHIR_CONCAT_VSVSVSV(&_10$$7, driver, ":host=", &host, ";port=", &_9$$7, ";dbname=", &name);
			ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", NULL, 88, &_10$$7, &user, &password, &options);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("driver"), &_8$$7);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, arguments_sub, __$null, _1;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	zephir_get_strval(&method, method_param);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("driver"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, arguments);
	zephir_check_call_status();
	RETURN_MM();

}

