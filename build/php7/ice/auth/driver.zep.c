
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * User authorization library. Handles user login and logout, as well as secure password hashing.
 *
 * @package     Ice/Auth
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver) {

	ZEPHIR_REGISTER_CLASS(Ice\\Auth, Driver, ice, auth_driver, ice_auth_driver_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_auth_driver_ce, SL("session"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_driver_ce, SL("cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_driver_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_driver_ce, SL("user"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_auth_driver_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_auth_driver_ce->create_object = zephir_init_properties_Ice_Auth_Driver;
	return SUCCESS;

}

/**
 * Loads services and configuration options.
 *
 * @param array options Config options
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL, di, _1, _2, _3, _4, _5, _6;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_1, &_2, &options TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("options"), &_1);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "session");
	ZEPHIR_CALL_METHOD(&_3, &di, "get", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("session"), &_3);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "cookies");
	ZEPHIR_CALL_METHOD(&_5, &di, "get", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("cookies"), &_5);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "request");
	ZEPHIR_CALL_METHOD(&_6, &di, "get", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("request"), &_6);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks a plain text password and its hash version to check if the password matches.
 *
 * @param string password Password plain text
 * @param string hash Hash version of password
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver, checkHash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *password_param = NULL, *hash_param = NULL, _0, _1, _2$$3;
	zval password, hash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &password_param, &hash_param);

	zephir_get_strval(&password, password_param);
	zephir_get_strval(&hash, hash_param);


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_string(&_1, &_0, SL("hash_method"), PH_NOISY, "ice/auth/driver.zep", 59 TSRMLS_CC);
	if (Z_TYPE_P(&_1) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "hash", NULL, 0, &password);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_hash_equals(&_2$$3, &hash));
	} else {
		ZEPHIR_RETURN_CALL_FUNCTION("password_verify", NULL, 25, &password, &hash);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * Complete the login for a user by setting session data and eg. incrementing the logins.
 *
 * @param mixed user Complete the login for this user
 * @param array roles User's roles
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver, completeLogin) {

	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roles;
	zval *user, user_sub, *roles_param = NULL, sessionRoles, _0, _1, _2, _3, _4, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&sessionRoles);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&roles);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &roles_param);

	if (!roles_param) {
		ZEPHIR_INIT_VAR(&roles);
		array_init(&roles);
	} else {
		zephir_get_arrval(&roles, roles_param);
	}


	zephir_read_property(&_0, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "regenerate", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "session_key");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "auth_user");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getoption", &_5, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_2, user);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "session_roles");
	ZEPHIR_CALL_METHOD(&sessionRoles, this_ptr, "getoption", &_5, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&sessionRoles)) {
		zephir_read_property(&_6$$3, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "set", NULL, 0, &sessionRoles, &roles);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get option value with key.
 *
 * @param string key The option key
 * @param mixed defaultValue The value to return if option key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver, getOption) {

	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &key, 1 TSRMLS_CC)) {
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Assigns a value to the specified options.
 *
 * @param string key The option key
 * @param mixed value
 * @return object self
 */
PHP_METHOD(Ice_Auth_Driver, setOption) {

	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	zephir_update_property_array(this_ptr, SL("options"), &key, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the currently logged in user from the session. Returns NULL if no user is currently logged in.
 *
 * @param mixed defaultValue Default value to return if the user is currently not logged in.
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver, getUser) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultValue = NULL, defaultValue_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "session_key");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Perform a hmac hash, using the configured method.
 *
 * @param string password String to hash
 * @return string
 */
PHP_METHOD(Ice_Auth_Driver, hash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *password_param = NULL, _0, _1, _2$$3, _3$$3, _4$$3, _5$$3, _6$$4, _7$$4, _8$$4, _9$$4;
	zval password;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &password_param);

	zephir_get_strval(&password, password_param);


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_string(&_1, &_0, SL("hash_method"), PH_NOISY, "ice/auth/driver.zep", 142 TSRMLS_CC);
	if (Z_TYPE_P(&_1) == IS_STRING) {
		zephir_read_property(&_2$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3$$3, &_2$$3, SL("hash_method"), PH_NOISY | PH_READONLY, "ice/auth/driver.zep", 143 TSRMLS_CC);
		zephir_read_property(&_4$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_5$$3, &_4$$3, SL("hash_key"), PH_NOISY | PH_READONLY, "ice/auth/driver.zep", 143 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 26, &_3$$3, &password, &_5$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		zephir_read_property(&_6$$4, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_7$$4, &_6$$4, SL("hash_method"), PH_NOISY | PH_READONLY, "ice/auth/driver.zep", 145 TSRMLS_CC);
		zephir_read_property(&_8$$4, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_9$$4, &_8$$4, SL("hash_option"), PH_NOISY | PH_READONLY, "ice/auth/driver.zep", 145 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_FUNCTION("password_hash", NULL, 27, &password, &_7$$4, &_9$$4);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * Check if there is an active session. Optionally allows checking for a specific role.
 *
 * @param string role Role name
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver, loggedIn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *role_param = NULL, user, sessionRoles, roles, _0$$4, _1$$6;
	zval role;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&sessionRoles);
	ZVAL_UNDEF(&roles);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &role_param);

	if (!role_param) {
		ZEPHIR_INIT_VAR(&role);
		ZVAL_STRING(&role, "");
	} else {
		zephir_get_strval(&role, role_param);
	}


	ZEPHIR_CALL_METHOD(&user, this_ptr, "getuser", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&user))) {
		RETURN_MM_BOOL(0);
	} else {
		if (!(!(Z_TYPE_P(&role) == IS_UNDEF) && Z_STRLEN_P(&role))) {
			RETURN_MM_BOOL(1);
		}
		ZEPHIR_INIT_VAR(&_0$$4);
		ZVAL_STRING(&_0$$4, "session_roles");
		ZEPHIR_CALL_METHOD(&sessionRoles, this_ptr, "getoption", NULL, 0, &_0$$4);
		zephir_check_call_status();
		if (zephir_is_true(&sessionRoles)) {
			zephir_read_property(&_1$$6, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&roles, &_1$$6, "get", NULL, 0, &sessionRoles);
			zephir_check_call_status();
			RETURN_MM_BOOL(zephir_fast_in_array(&role, &roles TSRMLS_CC));
		} else {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasrole", NULL, 0, &user, &role);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Log out a user by removing the related session variables.
 *
 * @param boolean destroy Completely destroy the session
 * @param boolean logoutAll Remove all tokens for user
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver, logout) {

	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destroy_param = NULL, *logoutAll_param = NULL, sessionRoles, _7, _0$$3, _1$$4, _2$$4, _3$$4, _6$$4, _5$$5;
	zend_bool destroy, logoutAll;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionRoles);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &destroy_param, &logoutAll_param);

	if (!destroy_param) {
		destroy = 0;
	} else {
		destroy = zephir_get_boolval(destroy_param);
	}
	if (!logoutAll_param) {
		logoutAll = 0;
	} else {
		logoutAll = zephir_get_boolval(logoutAll_param);
	}


	if (destroy == 1) {
		zephir_read_property(&_0$$3, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "destroy", NULL, 0);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "session_key");
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getoption", &_4, 0, &_3$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "remove", NULL, 0, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "session_roles");
		ZEPHIR_CALL_METHOD(&sessionRoles, this_ptr, "getoption", &_4, 0, &_3$$4);
		zephir_check_call_status();
		if (zephir_is_true(&sessionRoles)) {
			zephir_read_property(&_5$$5, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_5$$5, "remove", NULL, 0, &sessionRoles);
			zephir_check_call_status();
		}
		zephir_read_property(&_6$$4, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "regenerate", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "loggedin", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_7));

}

zend_object *zephir_init_properties_Ice_Auth_Driver(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 6, 0 TSRMLS_CC);
			add_assoc_long_ex(&_1$$3, SL("hash_method"), 1);
			ZEPHIR_INIT_VAR(&_2$$3);
			array_init(&_2$$3);
			zephir_array_update_string(&_1$$3, SL("hash_option"), &_2$$3, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_1$$3, SL("hash_key"), SL(""));
			add_assoc_stringl_ex(&_1$$3, SL("session_key"), SL("auth_user"));
			add_assoc_stringl_ex(&_1$$3, SL("session_roles"), SL("auth_user_roles"));
			add_assoc_long_ex(&_1$$3, SL("lifetime"), 1209600);
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

