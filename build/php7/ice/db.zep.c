
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
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db) {

	ZEPHIR_REGISTER_CLASS(Ice, Db, ice, db, ice_db_method_entry, 0);

	zend_declare_property_null(ice_db_ce, SL("driver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Db, getDriver) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "driver");

}

PHP_METHOD(Ice_Db, setDriver) {

	zval *driver, driver_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&driver_sub);

	zephir_fetch_params(0, 1, 0, &driver);



	zephir_update_property_zval(this_ptr, SL("driver"), driver);

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

	zephir_nts_static zend_class_entry *_5$$5 = NULL;
	zend_bool _0, _1$$4;
	int port, ZEPHIR_LAST_CALL_STATUS;
	zval host, name, user, password, _3$$5;
	zval *driver, driver_sub, *host_param = NULL, *port_param = NULL, *name_param = NULL, *user_param = NULL, *password_param = NULL, dsn$$5, _2$$5, _4$$5, _6$$6, _7$$6, _8$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&driver_sub);
	ZVAL_UNDEF(&dsn$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&_3$$5);

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
		_1$$4 = ZEPHIR_IS_STRING(driver, "mongodb");
		if (!(_1$$4)) {
			_1$$4 = ZEPHIR_IS_STRING(driver, "mongo");
		}
		if (_1$$4) {
			ZEPHIR_SINIT_VAR(_2$$5);
			ZVAL_LONG(&_2$$5, port);
			ZEPHIR_INIT_VAR(&_3$$5);
			ZEPHIR_CONCAT_SVSVSVSVSV(&_3$$5, "mongodb://", &user, ":", &password, "@", &host, ":", &_2$$5, "/", &name);
			ZEPHIR_CPY_WRT(&dsn$$5, &_3$$5);
			ZEPHIR_INIT_VAR(&_4$$5);
			if (ZEPHIR_IS_STRING(driver, "mongo")) {
				ZEPHIR_INIT_NVAR(&_4$$5);
				if (!_5$$5) {
				_5$$5 = zephir_fetch_class_str_ex(SL("Ice\\Db\\Driver\\Mongo"), ZEND_FETCH_CLASS_AUTO);
				}
				object_init_ex(&_4$$5, _5$$5);
				if (zephir_has_constructor(&_4$$5 TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", NULL, 0, &dsn$$5, &name);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_INIT_NVAR(&_4$$5);
				object_init_ex(&_4$$5, ice_db_driver_mongodb_ce);
				ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", NULL, 62, &dsn$$5, &name);
				zephir_check_call_status();
			}
			zephir_update_property_zval(this_ptr, SL("driver"), &_4$$5);
		} else {
			ZEPHIR_INIT_VAR(&_6$$6);
			object_init_ex(&_6$$6, ice_db_driver_pdo_ce);
			ZEPHIR_SINIT_VAR(_7$$6);
			ZVAL_LONG(&_7$$6, port);
			ZEPHIR_INIT_VAR(&_8$$6);
			ZEPHIR_CONCAT_VSVSVSV(&_8$$6, driver, ":host=", &host, ";port=", &_7$$6, ";dbname=", &name);
			ZEPHIR_CALL_METHOD(NULL, &_6$$6, "__construct", NULL, 63, &_8$$6, &user, &password);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("driver"), &_6$$6);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic call, call driver's method.
 */
PHP_METHOD(Ice_Db, __call) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, arguments_sub, __$null, _1;
	zval method;
	ZEPHIR_INIT_THIS();

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

