
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
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * Database component.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
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
 */
PHP_METHOD(Ice_Db, __construct) {

	zend_class_entry *_5$$5;
	zend_bool _0;
	zend_long port, ZEPHIR_LAST_CALL_STATUS;
	zval host, name, user, password, _2$$4;
	zval *driver = NULL, driver_sub, *host_param = NULL, *port_param = NULL, *name_param = NULL, *user_param = NULL, *password_param = NULL, dsn$$4, _1$$4, _3$$5, _4$$5, _6$$6, _7$$7, _8$$7, _9$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driver_sub);
	ZVAL_UNDEF(&dsn$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &driver, &host_param, &port_param, &name_param, &user_param, &password_param);

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


	_0 = Z_TYPE_P(driver) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(driver, ice_db_dbinterface_ce TSRMLS_CC));
	}
	if (_0) {
		zephir_update_property_zval(this_ptr, SL("driver"), driver);
	} else if (Z_TYPE_P(driver) == IS_STRING) {
		ZEPHIR_SINIT_VAR(_1$$4);
		ZVAL_LONG(&_1$$4, port);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SVSVSVSVSV(&_2$$4, "mongodb://", &user, ":", &password, "@", &host, ":", &_1$$4, "/", &name);
		ZEPHIR_CPY_WRT(&dsn$$4, &_2$$4);
		do {
			if (ZEPHIR_IS_STRING(driver, "mongo")) {
				ZEPHIR_INIT_NVAR(driver);
				ZVAL_STRING(driver, "Ice\\Db\\Driver\\Mongo");
				ZEPHIR_INIT_VAR(&_3$$5);
				zephir_fetch_safe_class(&_4$$5, driver);
				_5$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_4$$5), Z_STRLEN_P(&_4$$5), ZEND_FETCH_CLASS_AUTO);
				object_init_ex(&_3$$5, _5$$5);
				if (zephir_has_constructor(&_3$$5 TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0, &dsn$$4, &name);
					zephir_check_call_status();
				}
				zephir_update_property_zval(this_ptr, SL("driver"), &_3$$5);
				break;
			}
			if (ZEPHIR_IS_STRING(driver, "mongodb")) {
				ZEPHIR_INIT_VAR(&_6$$6);
				object_init_ex(&_6$$6, ice_db_driver_mongodb_ce);
				ZEPHIR_CALL_METHOD(NULL, &_6$$6, "__construct", NULL, 62, &dsn$$4, &name);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("driver"), &_6$$6);
				break;
			}
			ZEPHIR_INIT_VAR(&_7$$7);
			object_init_ex(&_7$$7, ice_db_driver_pdo_ce);
			ZEPHIR_SINIT_VAR(_8$$7);
			ZVAL_LONG(&_8$$7, port);
			ZEPHIR_INIT_VAR(&_9$$7);
			ZEPHIR_CONCAT_VSVSVSV(&_9$$7, driver, ":host=", &host, ";port=", &_8$$7, ";dbname=", &name);
			ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", NULL, 63, &_9$$7, &user, &password);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("driver"), &_7$$7);
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

