
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/**
 * File Auth driver.
 *
 * @package     Ice/Auth
 * @category    Driver
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_File) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver, File, ice, auth_driver_file, ice_auth_driver_ce, ice_auth_driver_file_method_entry, 0);

	zend_declare_property_null(ice_auth_driver_file_ce, SL("users"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_auth_driver_file_ce TSRMLS_CC, 1, ice_auth_driver_driverinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Auth_Driver_File, setUsers) {

	zval *users, users_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&users_sub);

	zephir_fetch_params(0, 1, 0, &users);



	zephir_update_property_zval(this_ptr, SL("users"), users);

}

/**
 * Gets the currently logged in user from the session. Returns NULL if no user is currently logged in.
 *
 * @param mixed defaultValue Default value to return if the user is currently not logged in
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_File, getUser) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *defaultValue = NULL, defaultValue_sub, __$null, username, user, _0, _3, _2$$5, _4$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&username);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("user"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_PARENT(&username, ice_auth_driver_file_ce, this_ptr, "getuser", &_1, 40, defaultValue);
		zephir_check_call_status();
		if (ZEPHIR_IS_IDENTICAL(&username, defaultValue)) {
			zephir_update_property_zval(this_ptr, SL("user"), defaultValue);
		} else {
			ZEPHIR_OBS_VAR(&user);
			zephir_read_property(&_2$$5, this_ptr, SL("users"), PH_NOISY_CC | PH_READONLY);
			zephir_array_isset_fetch(&user, &_2$$5, &username, 0 TSRMLS_CC);
			zephir_array_update_string(&user, SL("username"), &username, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("user"), &user);
		}
	}
	zephir_read_property(&_3, this_ptr, SL("user"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		object_init_ex(return_value, ice_arr_ce);
		zephir_read_property(&_4$$6, this_ptr, SL("user"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 4, &_4$$6);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_MEMBER(this_ptr, "user");

}

/**
 * Check if user has the role.
 *
 * @param array user User data
 * @param string role Role name
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver_File, hasRole) {

	zval role;
	zval *user, user_sub, *role_param = NULL, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&role);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &role_param);

	if (!role_param) {
		ZEPHIR_INIT_VAR(&role);
		ZVAL_STRING(&role, "login");
	} else {
		zephir_get_strval(&role, role_param);
	}


	if (Z_TYPE_P(user) == IS_ARRAY) {
		zephir_array_fetch_string(&_0$$3, user, SL("roles"), PH_NOISY | PH_READONLY, "ice/auth/driver/file.zep", 62 TSRMLS_CC);
		RETURN_MM_BOOL(zephir_fast_in_array(&role, &_0$$3 TSRMLS_CC));
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "User must be an array", "ice/auth/driver/file.zep", 64);
		return;
	}

}

/**
 * Logs a user in.
 *
 * @param string username Username
 * @param string password Password
 * @param boolean remember Enable autologin (not supported)
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver_File, login) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember, _0;
	zval *username_param = NULL, *password_param = NULL, *remember_param = NULL, user, _1, _2$$3, _3$$3, _4$$5;
	zval username, password;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&username);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &username_param, &password_param, &remember_param);

	zephir_get_strval(&username, username_param);
	zephir_get_strval(&password, password_param);
	if (!remember_param) {
		remember = 0;
	} else {
		remember = zephir_get_boolval(remember_param);
	}


	_0 = zephir_is_true(&username);
	if (_0) {
		ZEPHIR_OBS_VAR(&user);
		zephir_read_property(&_1, this_ptr, SL("users"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_array_isset_fetch(&user, &_1, &username, 0 TSRMLS_CC);
	}
	if (_0) {
		if (ZEPHIR_IS_EMPTY(&password)) {
			RETURN_MM_BOOL(0);
		}
		zephir_array_fetch_string(&_2$$3, &user, SL("password"), PH_NOISY | PH_READONLY, "ice/auth/driver/file.zep", 85 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "hash", NULL, 0, &password);
		zephir_check_call_status();
		if (ZEPHIR_IS_IDENTICAL(&_2$$3, &_3$$3)) {
			zephir_array_fetch_string(&_4$$5, &user, SL("roles"), PH_NOISY | PH_READONLY, "ice/auth/driver/file.zep", 87 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "completelogin", NULL, 0, &username, &_4$$5);
			zephir_check_call_status();
			RETURN_MM_BOOL(1);
		}
		RETURN_MM_BOOL(0);
	} else {
		RETURN_MM_NULL();
	}

}

