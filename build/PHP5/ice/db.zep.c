
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

	

	RETURN_MEMBER(this_ptr, "driver");

}

PHP_METHOD(Ice_Db, setDriver) {

	zval *driver;

	zephir_fetch_params(0, 1, 0, &driver);



	zephir_update_property_this(this_ptr, SL("driver"), driver TSRMLS_CC);

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
	zval *host = NULL, *name = NULL, *user = NULL, *password = NULL;
	zval *driver, *host_param = NULL, *port_param = NULL, *name_param = NULL, *user_param = NULL, *password_param = NULL, *_1$$5, _2$$5, *_3$$5, *_4$$6, _5$$6, *_6$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &driver, &host_param, &port_param, &name_param, &user_param, &password_param);

	if (!host_param) {
		ZEPHIR_INIT_VAR(host);
		ZVAL_EMPTY_STRING(host);
	} else {
		zephir_get_strval(host, host_param);
	}
	if (!port_param) {
		port = 0;
	} else {
		port = zephir_get_intval(port_param);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!user_param) {
		ZEPHIR_INIT_VAR(user);
		ZVAL_EMPTY_STRING(user);
	} else {
		zephir_get_strval(user, user_param);
	}
	if (!password_param) {
		ZEPHIR_INIT_VAR(password);
		ZVAL_EMPTY_STRING(password);
	} else {
		zephir_get_strval(password, password_param);
	}


	_0 = Z_TYPE_P(driver) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(driver, ice_db_dbinterface_ce TSRMLS_CC));
	}
	if (_0) {
		zephir_update_property_this(this_ptr, SL("driver"), driver TSRMLS_CC);
	} else if (Z_TYPE_P(driver) == IS_STRING) {
		if (ZEPHIR_IS_STRING(driver, "mongodb")) {
			ZEPHIR_INIT_VAR(_1$$5);
			object_init_ex(_1$$5, ice_db_driver_mongo_ce);
			ZEPHIR_SINIT_VAR(_2$$5);
			ZVAL_LONG(&_2$$5, port);
			ZEPHIR_INIT_VAR(_3$$5);
			ZEPHIR_CONCAT_VSVSVSVSVSV(_3$$5, driver, "://", user, ":", password, "@", host, ":", &_2$$5, "/", name);
			ZEPHIR_CALL_METHOD(NULL, _1$$5, "__construct", NULL, 70, _3$$5, name);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("driver"), _1$$5 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_4$$6);
			object_init_ex(_4$$6, ice_db_driver_pdo_ce);
			ZEPHIR_SINIT_VAR(_5$$6);
			ZVAL_LONG(&_5$$6, port);
			ZEPHIR_INIT_VAR(_6$$6);
			ZEPHIR_CONCAT_VSVSVSV(_6$$6, driver, ":host=", host, ";port=", &_5$$6, ";dbname=", name);
			ZEPHIR_CALL_METHOD(NULL, _4$$6, "__construct", NULL, 71, _6$$6, user, password);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("driver"), _4$$6 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic call, call driver's method.
 */
PHP_METHOD(Ice_Db, __call) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, *_1;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	zephir_get_strval(method, method_param);
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("driver"), PH_NOISY_CC);
	zephir_array_fast_append(_0, _1);
	zephir_array_fast_append(_0, method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _0, arguments);
	zephir_check_call_status();
	RETURN_MM();

}

