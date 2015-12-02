
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * Database component.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db) {

	ZEPHIR_REGISTER_CLASS(Ice, Db, ice, db, ice_db_method_entry, 0);

	zend_declare_property_null(ice_db_ce, SL("driver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Db, getDriver) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "driver");

}

PHP_METHOD(Ice_Db, setDriver) {

	zval *driver, driver_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
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

	zend_bool _0;
	int port, ZEPHIR_LAST_CALL_STATUS;
	zval host, name, user, password;
	zval *driver, driver_sub, *host_param = NULL, *port_param = NULL, *name_param = NULL, *user_param = NULL, *password_param = NULL, _1$$5, _2$$5, _3$$5, _4$$6, _5$$6, _6$$6;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&driver_sub);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&password);

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
		if (ZEPHIR_IS_STRING(driver, "mongodb")) {
			ZEPHIR_INIT_VAR(&_1$$5);
			object_init_ex(&_1$$5, ice_db_driver_mongo_ce);
			ZEPHIR_SINIT_VAR(_2$$5);
			ZVAL_LONG(&_2$$5, port);
			ZEPHIR_INIT_VAR(&_3$$5);
			ZEPHIR_CONCAT_VSVSVSVSVSV(&_3$$5, driver, "://", &user, ":", &password, "@", &host, ":", &_2$$5, "/", &name);
			ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 71, &_3$$5, &name);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("driver"), &_1$$5);
		} else {
			ZEPHIR_INIT_VAR(&_4$$6);
			object_init_ex(&_4$$6, ice_db_driver_pdo_ce);
			ZEPHIR_SINIT_VAR(_5$$6);
			ZVAL_LONG(&_5$$6, port);
			ZEPHIR_INIT_VAR(&_6$$6);
			ZEPHIR_CONCAT_VSVSVSV(&_6$$6, driver, ":host=", &host, ";port=", &_5$$6, ";dbname=", &name);
			ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 72, &_6$$6, &user, &password);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("driver"), &_4$$6);
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
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
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

