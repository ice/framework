
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * User authorization library. Handles user login and logout, as well as secure password hashing.
 *
 * @package     Ice/Auth
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL, *di = NULL, *_1, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	zephir_fast_array_merge(_1, &(_2), &(options) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("options"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_NULL(_5);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_BOOL(_6, 1);
	ZEPHIR_CALL_METHOD(&_3, di, "get", NULL, 0, _4, _5, _6);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("session"), _3 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "cookies", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_NULL(_5);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_BOOL(_6, 1);
	ZEPHIR_CALL_METHOD(&_7, di, "get", NULL, 0, _4, _5, _6);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("cookies"), _7 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_NULL(_5);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_BOOL(_6, 1);
	ZEPHIR_CALL_METHOD(&_8, di, "get", NULL, 0, _4, _5, _6);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("request"), _8 TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *password_param = NULL, *hash_param = NULL, *_0 = NULL;
	zval *password = NULL, *hash = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &password_param, &hash_param);

	zephir_get_strval(password, password_param);
	zephir_get_strval(hash, hash_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hash", NULL, 0, password);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(_0, hash));

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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roles = NULL;
	zval *user, *roles_param = NULL, *sessionRoles = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &roles_param);

	if (!roles_param) {
		ZEPHIR_INIT_VAR(roles);
		array_init(roles);
	} else {
		zephir_get_arrval(roles, roles_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "regenerate", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "session_key", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "auth_user", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getoption", &_5, 0, _3, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _1, "set", NULL, 0, _2, user);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "session_roles", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&sessionRoles, this_ptr, "getoption", &_5, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	if (zephir_is_true(sessionRoles)) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _6, "set", NULL, 0, sessionRoles, roles);
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

	zval *key_param = NULL, *defaultValue = NULL, *value, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Gets the currently logged in user from the session. Returns NULL if no user is currently logged in.
 *
 * @param mixed defaultValue Default value to return if the user is currently not logged in.
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver, getUser) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *defaultValue = NULL, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultValue);

	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "session_key", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, _1, defaultValue);
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

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *password_param = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL;
	zval *password = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &password_param);

	zephir_get_strval(password, password_param);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "hash_method", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", &_2, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "hash_key", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoption", &_2, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 25, _0, password, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if there is an active session. Optionally allows checking for a specific role.
 *
 * @param string role Role name
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver, loggedIn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *role_param = NULL, *user = NULL, *sessionRoles = NULL, *roles = NULL, *_0, *_1;
	zval *role = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &role_param);

	if (!role_param) {
		ZEPHIR_INIT_VAR(role);
		ZVAL_EMPTY_STRING(role);
	} else {
		zephir_get_strval(role, role_param);
	}


	ZEPHIR_CALL_METHOD(&user, this_ptr, "getuser", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(user))) {
		RETURN_MM_BOOL(0);
	} else {
		if (!(role && Z_STRLEN_P(role))) {
			RETURN_MM_BOOL(1);
		}
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "session_roles", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&sessionRoles, this_ptr, "getoption", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (zephir_is_true(sessionRoles)) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&roles, _1, "get", NULL, 0, sessionRoles);
			zephir_check_call_status();
			RETURN_MM_BOOL(zephir_fast_in_array(role, roles TSRMLS_CC));
		} else {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasrole", NULL, 0, user, role);
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

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *destroy_param = NULL, *logoutAll_param = NULL, *sessionRoles = NULL, *_0, *_1 = NULL, *_2 = NULL, *_4;
	zend_bool destroy, logoutAll;

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
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _0, "destroy", NULL, 0);
		zephir_check_call_status();
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "session_key", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", &_3, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, 0, _1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "session_roles", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&sessionRoles, this_ptr, "getoption", &_3, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(sessionRoles)) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _4, "remove", NULL, 0, sessionRoles);
			zephir_check_call_status();
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("session"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _4, "regenerate", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "loggedin", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(_1));

}

static zend_object_value zephir_init_properties_Ice_Auth_Driver(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1;
		zval *_0;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			zephir_create_array(_1, 5, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1, SS("hash_method"), SL("sha256"), 1);
			add_assoc_stringl_ex(_1, SS("hash_key"), SL(""), 1);
			add_assoc_stringl_ex(_1, SS("session_key"), SL("auth_user"), 1);
			add_assoc_stringl_ex(_1, SS("session_roles"), SL("auth_user_roles"), 1);
			add_assoc_long_ex(_1, SS("lifetime"), 1209600);
			zephir_update_property_this(this_ptr, SL("options"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

