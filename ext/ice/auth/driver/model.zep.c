
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/iterator.h"
#include "kernel/exception.h"


/**
 * Model Auth driver.
 *
 * @package     Ice/Auth
 * @category    Driver
 * @author      Ice Team
 * @copyright   (c) 2014 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver, Model, ice, auth_driver_model, ice_auth_driver_ce, ice_auth_driver_model_method_entry, 0);

	zend_class_implements(ice_auth_driver_model_ce TSRMLS_CC, 1, ice_auth_driver_driverinterface_ce);
	return SUCCESS;

}

/**
 * Logs a user in, based on the autologin cookie.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model, autoLogin) {

	zephir_fcall_cache_entry *_13 = NULL;
	zend_object_iterator *_11;
	zval *_5 = NULL, *_16 = NULL, *_18 = NULL;
	zend_bool _4;
	zval *_3;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *token = NULL, *user = NULL, *userRoles = NULL, *roles, *role = NULL, *_0, *_1 = NULL, *_6, *_7, *_8 = NULL, *_9 = NULL, *_12 = NULL, _14, *_15, *_17, *_19;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "auth_autologin", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&token, _0, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(token)) {
		ZEPHIR_INIT_VAR(_3);
		array_init_size(_3, 2);
		zephir_array_update_string(&_3, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&token, ice_auth_driver_model_users_tokens_ce, "findone", &_2, _3);
		zephir_check_call_status();
		if (zephir_is_true(token)) {
			ZEPHIR_CALL_METHOD(&user, token, "getuser",  NULL);
			zephir_check_call_status();
			_4 = zephir_is_true(user);
			if (_4) {
				ZEPHIR_INIT_VAR(_5);
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "useragent", 1);
				ZEPHIR_OBS_VAR(_6);
				zephir_read_property_zval(&_6, token, _5, PH_NOISY_CC);
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_request"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_8, _7, "getuseragent",  NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_9, "sha1", &_10, _8);
				zephir_check_call_status();
				_4 = ZEPHIR_IS_IDENTICAL(_6, _9);
			}
			if (_4) {
				ZEPHIR_CALL_METHOD(&userRoles, user, "getroles",  NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(roles);
				array_init(roles);
				_11 = zephir_get_iterator(userRoles TSRMLS_CC);
				_11->funcs->rewind(_11 TSRMLS_CC);
				for (;_11->funcs->valid(_11 TSRMLS_CC) == SUCCESS && !EG(exception); _11->funcs->move_forward(_11 TSRMLS_CC)) {
					{ zval **tmp; 
					_11->funcs->get_current_data(_11, &tmp TSRMLS_CC);
					role = *tmp;
					}
					ZEPHIR_CALL_METHOD(&_12, role, "getrole",  NULL);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(role, _12);
					ZEPHIR_INIT_NVAR(_1);
					ZVAL_STRING(_1, "name", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_12, role, "get", &_13, _1);
					zephir_check_temp_parameter(_1);
					zephir_check_call_status();
					zephir_array_append(&roles, _12, PH_SEPARATE, "ice/auth/driver/model.zep", 48);
				}
				_11->funcs->dtor(_11 TSRMLS_CC);
				ZEPHIR_SINIT_VAR(_14);
				ZVAL_STRING(&_14, "login", 0);
				if (zephir_fast_in_array(&_14, roles TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, token, "update", NULL);
					zephir_check_call_status();
					_15 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
					ZEPHIR_INIT_VAR(_16);
					ZEPHIR_INIT_NVAR(_16);
					ZVAL_STRING(_16, "token", 1);
					ZEPHIR_OBS_VAR(_17);
					zephir_read_property_zval(&_17, token, _16, PH_NOISY_CC);
					ZEPHIR_INIT_VAR(_18);
					ZEPHIR_INIT_NVAR(_18);
					ZVAL_STRING(_18, "expires", 1);
					ZEPHIR_OBS_VAR(_19);
					zephir_read_property_zval(&_19, token, _18, PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_1);
					ZVAL_STRING(_1, "auth_autologin", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, _15, "set", NULL, _1, _17, _19);
					zephir_check_temp_parameter(_1);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "completelogin", NULL, user, roles);
					zephir_check_call_status();
					RETURN_CCTOR(user);
				}
			}
			ZEPHIR_CALL_METHOD(NULL, token, "remove", NULL);
			zephir_check_call_status();
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Complete the login for a user by setting session data and eg. incrementing the logins.
 *
 * @param object user User Model object
 * @param array roles User's roles
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model, completeLogin) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roles = NULL;
	zval *user, *roles_param = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &roles_param);

	if (!roles_param) {
		ZEPHIR_INIT_VAR(roles);
		array_init(roles);
	} else {
		zephir_get_arrval(roles, roles_param);
	}


	if (zephir_instance_of_ev(user, ice_auth_driver_model_users_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, user, "completelogin", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, user, "serialize",  NULL);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_model_ce, this_ptr, "completelogin", &_0, _1, roles);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		RETURN_MM_BOOL(0);
	}

}

/**
 * Gets the currently logged in user from the session. Returns NULL if no user is currently logged in.
 *
 * @param mixed defaultValue Default value to return if the user is currently not logged in
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model, getUser) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *defaultValue = NULL, *data = NULL, *user, *_0, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultValue);

	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_user"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_PARENT(&data, ice_auth_driver_model_ce, this_ptr, "getuser", &_1, defaultValue);
		zephir_check_call_status();
		if (ZEPHIR_IS_IDENTICAL(data, defaultValue)) {
			zephir_update_property_this(this_ptr, SL("_user"), defaultValue TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(user);
			object_init_ex(user, ice_auth_driver_model_users_ce);
			ZEPHIR_CALL_METHOD(NULL, user, "__construct", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, user, "unserialize", NULL, data);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_user"), user TSRMLS_CC);
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_user"), PH_NOISY_CC);
	if (!(zephir_is_true(_2))) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "autologin",  NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_user"), _3 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "_user");

}

/**
 * Check if user has the role.
 *
 * @param object user User Model object
 * @param string role Role name
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver_Model, hasRole) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *role = NULL;
	zval *user, *role_param = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &role_param);

	if (!role_param) {
		ZEPHIR_INIT_VAR(role);
		ZVAL_STRING(role, "login", 1);
	} else {
		zephir_get_strval(role, role_param);
	}


	if (!(zephir_instance_of_ev(user, ice_auth_driver_model_users_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'user' must be an instance of 'Ice\\Auth\\Driver\\Model\\Users'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_METHOD(&_1, user, "getrole", NULL, role);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

/**
 * Logs a user in.
 *
 * @param mixed username
 * @param string password
 * @param boolean remember enable autologin
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver_Model, login) {

	zephir_fcall_cache_entry *_8 = NULL, *_15 = NULL;
	zend_object_iterator *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_2;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_13 = NULL;
	zend_bool remember, _3;
	zval *password = NULL;
	zval *username, *password_param = NULL, *remember_param = NULL, *user = NULL, *roles, *userRoles = NULL, *role = NULL, *token, *lifetime = NULL, *_0 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL, _9, *_10, *_11 = NULL, *_12 = NULL, *_14 = NULL, *_16 = NULL, *_17, *_18, *_19 = NULL, *_20 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &username, &password_param, &remember_param);

	zephir_get_strval(password, password_param);
	if (!remember_param) {
		remember = 0;
	} else {
		remember = zephir_get_boolval(remember_param);
	}


	ZEPHIR_INIT_VAR(user);
	ZVAL_NULL(user);
	if (ZEPHIR_IS_EMPTY(password)) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_is_true(username)) {
		if (Z_TYPE_P(username) == IS_OBJECT) {
			ZEPHIR_CPY_WRT(user, username);
		} else {
			ZEPHIR_INIT_VAR(_2);
			array_init_size(_2, 2);
			zephir_array_update_string(&_2, SL("username"), &username, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_CE_STATIC(&_0, ice_auth_driver_model_users_ce, "findone", &_1, _2);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(user, _0);
		}
	}
	_3 = Z_TYPE_P(user) == IS_OBJECT;
	if (_3) {
		_3 = (zephir_instance_of_ev(user, ice_auth_driver_model_users_ce TSRMLS_CC));
	}
	if (_3) {
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "password", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0, user, "get", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "hash", NULL, password);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(_0, _5)) {
			ZEPHIR_CALL_METHOD(&userRoles, user, "getroles",  NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(roles);
			array_init(roles);
			_6 = zephir_get_iterator(userRoles TSRMLS_CC);
			_6->funcs->rewind(_6 TSRMLS_CC);
			for (;_6->funcs->valid(_6 TSRMLS_CC) == SUCCESS && !EG(exception); _6->funcs->move_forward(_6 TSRMLS_CC)) {
				{ zval **tmp; 
				_6->funcs->get_current_data(_6, &tmp TSRMLS_CC);
				role = *tmp;
				}
				ZEPHIR_CALL_METHOD(&_7, role, "getrole",  NULL);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(role, _7);
				ZEPHIR_INIT_NVAR(_4);
				ZVAL_STRING(_4, "name", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_7, role, "get", &_8, _4);
				zephir_check_temp_parameter(_4);
				zephir_check_call_status();
				zephir_array_append(&roles, _7, PH_SEPARATE, "ice/auth/driver/model.zep", 168);
			}
			_6->funcs->dtor(_6 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_9);
			ZVAL_STRING(&_9, "login", 0);
			if (zephir_fast_in_array(&_9, roles TSRMLS_CC)) {
				if (remember) {
					ZEPHIR_INIT_NVAR(_4);
					ZVAL_STRING(_4, "lifetime", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&lifetime, this_ptr, "getoption", NULL, _4);
					zephir_check_temp_parameter(_4);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(token);
					object_init_ex(token, ice_auth_driver_model_users_tokens_ce);
					ZEPHIR_CALL_METHOD(NULL, token, "__construct", NULL);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_4);
					ZVAL_STRING(_4, "id", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_7, user, "get", &_8, _4);
					zephir_check_temp_parameter(_4);
					zephir_check_call_status();
					zephir_update_property_zval(token, SL("user_id"), _7 TSRMLS_CC);
					_10 = zephir_fetch_nproperty_this(this_ptr, SL("_request"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(&_11, _10, "getuseragent",  NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_12, "sha1", &_13, _11);
					zephir_check_call_status();
					zephir_update_property_zval(token, SL("useragent"), _12 TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(&_14, "time", &_15);
					zephir_check_call_status();
					zephir_update_property_zval(token, SL("created"), _14 TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(&_16, "time", &_15);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(_17);
					zephir_add_function(_17, _16, lifetime TSRMLS_CC);
					zephir_update_property_zval(token, SL("expires"), _17 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_16, token, "create",  NULL);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(_16)) {
						_18 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
						ZEPHIR_INIT_NVAR(_4);
						ZVAL_STRING(_4, "token", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(&_19, token, "get", &_8, _4);
						zephir_check_temp_parameter(_4);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(_4);
						ZVAL_STRING(_4, "expires", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(&_20, token, "get", &_8, _4);
						zephir_check_temp_parameter(_4);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(_4);
						ZVAL_STRING(_4, "auth_autologin", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _18, "set", NULL, _4, _19, _20);
						zephir_check_temp_parameter(_4);
						zephir_check_call_status();
					}
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "completelogin", NULL, user, roles);
				zephir_check_call_status();
				RETURN_MM_BOOL(1);
			}
		}
		RETURN_MM_BOOL(0);
	} else {
		RETURN_MM_NULL();
	}

}

/**
 * Log a user out and remove any autologin cookies.
 *
 * @param boolean destroy Completely destroy the session
 * @param boolean logoutAll Remove all tokens for user
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver_Model, logout) {

	zend_object_iterator *_10;
	zval *_8 = NULL;
	zval *_4, *_7;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *destroy_param = NULL, *logoutAll_param = NULL, *token = NULL, *tokens = NULL, *_token = NULL, *_0, *_1 = NULL, *_2, *_9;
	zend_bool destroy, logoutAll, _5;

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "auth_autologin", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&token, _0, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(token)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "auth_autologin", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2, "remove", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4);
		array_init_size(_4, 2);
		zephir_array_update_string(&_4, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&token, ice_auth_driver_model_users_tokens_ce, "findone", &_3, _4);
		zephir_check_call_status();
		_5 = zephir_is_true(token);
		if (_5) {
			_5 = logoutAll;
		}
		if (_5) {
			ZEPHIR_INIT_VAR(_7);
			array_init_size(_7, 2);
			ZEPHIR_INIT_VAR(_8);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_STRING(_8, "user_id", 1);
			ZEPHIR_OBS_VAR(_9);
			zephir_read_property_zval(&_9, token, _8, PH_NOISY_CC);
			zephir_array_update_string(&_7, SL("user_id"), &_9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_CE_STATIC(&tokens, ice_auth_driver_model_users_tokens_ce, "find", &_6, _7);
			zephir_check_call_status();
			_10 = zephir_get_iterator(tokens TSRMLS_CC);
			_10->funcs->rewind(_10 TSRMLS_CC);
			for (;_10->funcs->valid(_10 TSRMLS_CC) == SUCCESS && !EG(exception); _10->funcs->move_forward(_10 TSRMLS_CC)) {
				{ zval **tmp; 
				_10->funcs->get_current_data(_10, &tmp TSRMLS_CC);
				_token = *tmp;
				}
				ZEPHIR_CALL_METHOD(NULL, _token, "remove", NULL);
				zephir_check_call_status();
			}
			_10->funcs->dtor(_10 TSRMLS_CC);
		} else if (zephir_is_true(token)) {
			ZEPHIR_CALL_METHOD(NULL, token, "remove", NULL);
			zephir_check_call_status();
		}
	}
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_model_ce, this_ptr, "logout", &_11, (destroy ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

