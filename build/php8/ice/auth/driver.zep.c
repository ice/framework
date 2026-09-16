
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


/**
 * User authorization library. Handles user login and logout, as well as secure password hashing.
 *
 * @package     Ice/Auth
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver)
{
	ZEPHIR_REGISTER_CLASS(Ice\\Auth, Driver, ice, auth_driver, ice_auth_driver_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_auth_driver_ce, SL("session"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_auth_driver_ce, SL("cookies"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_auth_driver_ce, SL("request"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_auth_driver_ce, SL("user"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_auth_driver_ce, SL("options"), ZEND_ACC_PROTECTED);
	ice_auth_driver_ce->create_object = zephir_init_properties_Ice_Auth_Driver;

	return SUCCESS;
}

/**
 * Loads services and configuration options.
 *
 * @param array options Config options
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, di, _0, _1, _2, _3, _4, _5;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("session", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("cookies", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("request", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 27, PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &options);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 27, &_0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "session");
	ZEPHIR_CALL_METHOD(&_2, &di, "get", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 28, &_2);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "cookies");
	ZEPHIR_CALL_METHOD(&_4, &di, "get", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 29, &_4);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "request");
	ZEPHIR_CALL_METHOD(&_5, &di, "get", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 30, &_5);
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks a plain text password and its hash version to check if the password matches.
 *
 * @param string password Password plain text
 * @param string hash Hash version of password
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver, checkHash)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval password_zv, hash_zv, _0, _1, _2$$3;
	zend_string *password = NULL, *hash = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password_zv);
	ZVAL_UNDEF(&hash_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(password)
		Z_PARAM_STR(hash)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&password_zv);
	ZVAL_STR_COPY(&password_zv, password);
	zephir_memory_observe(&hash_zv);
	ZVAL_STR_COPY(&hash_zv, hash);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 27, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_1);
	zephir_array_fetch_string(&_1, &_0, SL("hash_method"), PH_NOISY, "ice/auth/driver.zep", 58);
	if (Z_TYPE_P(&_1) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "hash", NULL, 0, &password_zv);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_hash_equals(&_2$$3, &hash_zv));
	} else {
		ZEPHIR_RETURN_CALL_FUNCTION("password_verify", NULL, 26, &password_zv, &hash_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
}

/**
 * Complete the login for a user by setting session data and eg. incrementing the logins.
 *
 * @param string user Complete the login for this user
 * @param array roles User's roles
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver, completeLogin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roles;
	zval user_zv, *roles_param = NULL, sessionRoles, _0, _1, _2, _3, _4, _6$$3;
	zend_string *user = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_zv);
	ZVAL_UNDEF(&sessionRoles);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&roles);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("session", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(user)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(roles, roles_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		roles_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&user_zv);
	ZVAL_STR_COPY(&user_zv, user);
	if (!roles_param) {
		ZEPHIR_INIT_VAR(&roles);
		array_init(&roles);
	} else {
		zephir_get_arrval(&roles, roles_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 28, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "regenerate", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 28, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "session_key");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "auth_user");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getoption", &_5, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_2, &user_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "session_roles");
	ZEPHIR_CALL_METHOD(&sessionRoles, this_ptr, "getoption", &_5, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&sessionRoles)) {
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 28, PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Ice_Auth_Driver, getOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval key_zv, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_memory_observe(&value);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 27, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &key_zv, 0)) {
		RETURN_CCTOR(&value);
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
PHP_METHOD(Ice_Auth_Driver, setOption)
{
	zval key_zv, *value, value_sub;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&key_zv, key);
	zephir_update_property_array(this_ptr, SL("options"), &key_zv, value);
	RETURN_THISW();
}

/**
 * Gets the currently logged in user from the session. Returns NULL if no user is currently logged in.
 *
 * @param mixed defaultValue Default value to return if the user is currently not logged in.
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver, getUser)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultValue = NULL, defaultValue_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("session", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 28, PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Ice_Auth_Driver, hash)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval password_zv, _0, _1, _2$$3, _3$$3, _4$$3, _5$$3, _6$$4, _7$$4, _8$$4, _9$$4;
	zend_string *password = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password_zv);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(password)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&password_zv);
	ZVAL_STR_COPY(&password_zv, password);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 27, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_1);
	zephir_array_fetch_string(&_1, &_0, SL("hash_method"), PH_NOISY, "ice/auth/driver.zep", 141);
	if (Z_TYPE_P(&_1) == IS_STRING) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 27, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_3$$3);
		zephir_array_fetch_string(&_3$$3, &_2$$3, SL("hash_method"), PH_NOISY, "ice/auth/driver.zep", 142);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 27, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_5$$3);
		zephir_array_fetch_string(&_5$$3, &_4$$3, SL("hash_key"), PH_NOISY, "ice/auth/driver.zep", 142);
		ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 27, &_3$$3, &password_zv, &_5$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		zephir_read_property_cached(&_6$$4, this_ptr, _zephir_prop_0, 27, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_7$$4);
		zephir_array_fetch_string(&_7$$4, &_6$$4, SL("hash_method"), PH_NOISY, "ice/auth/driver.zep", 144);
		zephir_read_property_cached(&_8$$4, this_ptr, _zephir_prop_0, 27, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_9$$4);
		zephir_array_fetch_string(&_9$$4, &_8$$4, SL("hash_option"), PH_NOISY, "ice/auth/driver.zep", 144);
		ZEPHIR_RETURN_CALL_FUNCTION("password_hash", NULL, 28, &password_zv, &_7$$4, &_9$$4);
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
PHP_METHOD(Ice_Auth_Driver, loggedIn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval role_zv, user, sessionRoles, roles, _0$$4, _1$$6;
	zend_string *role = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&role_zv);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&sessionRoles);
	ZVAL_UNDEF(&roles);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$6);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("session", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(role)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!role) {
		ZEPHIR_INIT_VAR(&role_zv);
	} else {
		zephir_memory_observe(&role_zv);
	ZVAL_STR_COPY(&role_zv, role);
	}
	ZEPHIR_CALL_METHOD(&user, this_ptr, "getuser", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&user))) {
		RETURN_MM_BOOL(0);
	} else {
		if (!(!(ZEPHIR_IS_EMPTY(&role_zv)))) {
			RETURN_MM_BOOL(1);
		}
		ZEPHIR_INIT_VAR(&_0$$4);
		ZVAL_STRING(&_0$$4, "session_roles");
		ZEPHIR_CALL_METHOD(&sessionRoles, this_ptr, "getoption", NULL, 0, &_0$$4);
		zephir_check_call_status();
		if (zephir_is_true(&sessionRoles)) {
			zephir_read_property_cached(&_1$$6, this_ptr, _zephir_prop_0, 28, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&roles, &_1$$6, "get", NULL, 0, &sessionRoles);
			zephir_check_call_status();
			RETURN_MM_BOOL(zephir_fast_in_array(&role_zv, &roles));
		} else {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasrole", NULL, 0, &user, &role_zv);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
}

/**
 * Log out a user by removing the related session variables.
 *
 * @param boolean destroy Completely destroy the session
 * @param boolean logoutAll Remove all tokens for user
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver, logout)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("session", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(destroy)
		Z_PARAM_BOOL(logoutAll)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &destroy_param, &logoutAll_param);
	if (!destroy_param) {
		destroy = 0;
	} else {
		}
	if (!logoutAll_param) {
		logoutAll = 0;
	} else {
		}
	if (destroy == 1) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 28, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "destroy", NULL, 0);
		zephir_check_call_status();
	} else {
		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_0, 28, PH_NOISY_CC | PH_READONLY);
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
			zephir_read_property_cached(&_5$$5, this_ptr, _zephir_prop_0, 28, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_5$$5, "remove", NULL, 0, &sessionRoles);
			zephir_check_call_status();
		}
		zephir_read_property_cached(&_6$$4, this_ptr, _zephir_prop_0, 28, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "regenerate", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "loggedin", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_7));
}

zend_object *zephir_init_properties_Ice_Auth_Driver(zend_class_entry *class_type)
{
		zval _1$$3;
	zval _0, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 6, 0);
			add_assoc_stringl_ex(&_1$$3, SL("hash_method"), SL("2y"));
			ZEPHIR_INIT_VAR(&_2$$3);
			array_init(&_2$$3);
			zephir_array_update_string(&_1$$3, SL("hash_option"), &_2$$3, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_1$$3, SL("hash_key"), SL(""));
			add_assoc_stringl_ex(&_1$$3, SL("session_key"), SL("auth_user"));
			add_assoc_stringl_ex(&_1$$3, SL("session_roles"), SL("auth_user_roles"));
			add_assoc_long_ex(&_1$$3, SL("lifetime"), 1209600);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

