
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
#include "kernel/time.h"


/**
 * Model Auth driver.
 *
 * @package     Ice/Auth
 * @category    Driver
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
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

	zend_object_iterator *_9;
	zend_bool _4;
	zval *_3;
	zephir_fcall_cache_entry *_2 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *token = NULL, *user = NULL, *userRoles = NULL, *roles, *role = NULL, *_0, *_1 = NULL, *_5, *_6, *_7 = NULL, *_8 = NULL, *_10 = NULL, _12, *_13, *_14, *_15;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cookies"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "auth_autologin", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&token, _0, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(token)) {
		ZEPHIR_INIT_VAR(_3);
		zephir_create_array(_3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_3, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&token, ice_auth_driver_model_users_tokens_ce, "findone", &_2, 41, _3);
		zephir_check_call_status();
		if (zephir_is_true(token)) {
			ZEPHIR_CALL_METHOD(&user, token, "getuser", NULL, 0);
			zephir_check_call_status();
			_4 = zephir_is_true(user);
			if (_4) {
				ZEPHIR_OBS_VAR(_5);
				zephir_read_property(&_5, token, SL("useragent"), PH_NOISY_CC);
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("request"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_7, _6, "getuseragent", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_8, "sha1", NULL, 42, _7);
				zephir_check_call_status();
				_4 = ZEPHIR_IS_IDENTICAL(_5, _8);
			}
			if (_4) {
				ZEPHIR_CALL_METHOD(&userRoles, user, "getroles", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(roles);
				array_init(roles);
				_9 = zephir_get_iterator(userRoles TSRMLS_CC);
				_9->funcs->rewind(_9 TSRMLS_CC);
				for (;_9->funcs->valid(_9 TSRMLS_CC) == SUCCESS && !EG(exception); _9->funcs->move_forward(_9 TSRMLS_CC)) {
					{
						zval **ZEPHIR_TMP_ITERATOR_PTR;
						_9->funcs->get_current_data(_9, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
						ZEPHIR_CPY_WRT(role, (*ZEPHIR_TMP_ITERATOR_PTR));
					}
					ZEPHIR_CALL_METHOD(&_10, role, "getrole", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(role, _10);
					ZEPHIR_INIT_NVAR(_1);
					ZVAL_STRING(_1, "name", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_10, role, "get", &_11, 0, _1);
					zephir_check_temp_parameter(_1);
					zephir_check_call_status();
					zephir_array_append(&roles, _10, PH_SEPARATE, "ice/auth/driver/model.zep", 51);
				}
				_9->funcs->dtor(_9 TSRMLS_CC);
				ZEPHIR_SINIT_VAR(_12);
				ZVAL_STRING(&_12, "login", 0);
				if (zephir_fast_in_array(&_12, roles TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, token, "update", NULL, 0);
					zephir_check_call_status();
					_13 = zephir_fetch_nproperty_this(this_ptr, SL("cookies"), PH_NOISY_CC);
					ZEPHIR_OBS_VAR(_14);
					zephir_read_property(&_14, token, SL("token"), PH_NOISY_CC);
					ZEPHIR_OBS_VAR(_15);
					zephir_read_property(&_15, token, SL("expires"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_1);
					ZVAL_STRING(_1, "auth_autologin", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, _13, "set", NULL, 0, _1, _14, _15);
					zephir_check_temp_parameter(_1);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "completelogin", NULL, 0, user, roles);
					zephir_check_call_status();
					RETURN_CCTOR(user);
				}
			}
			ZEPHIR_CALL_METHOD(NULL, token, "remove", NULL, 0);
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

	zephir_fcall_cache_entry *_0 = NULL;
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
		ZEPHIR_CALL_METHOD(NULL, user, "completelogin", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_1, "serialize", NULL, 14, user);
		zephir_check_call_status();
		ZEPHIR_CALL_PARENT(NULL, ice_auth_driver_model_ce, this_ptr, "completelogin", &_0, 43, _1, roles);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the currently logged in user from the session. Returns NULL if no user is currently logged in.
 *
 * @param mixed defaultValue Default value to return if the user is currently not logged in
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model, getUser) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *defaultValue = NULL, *data = NULL, *_0, *user = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultValue);

	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("user"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_PARENT(&data, ice_auth_driver_model_ce, this_ptr, "getuser", &_1, 40, defaultValue);
		zephir_check_call_status();
		if (ZEPHIR_IS_IDENTICAL(data, defaultValue)) {
			zephir_update_property_this(this_ptr, SL("user"), defaultValue TSRMLS_CC);
		} else if (Z_TYPE_P(data) == IS_STRING) {
			ZEPHIR_CALL_FUNCTION(&user, "unserialize", NULL, 17, data);
			zephir_check_call_status();
			if (zephir_instance_of_ev(user, ice_auth_driver_model_users_ce TSRMLS_CC)) {
				zephir_update_property_this(this_ptr, SL("user"), user TSRMLS_CC);
			}
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("user"), PH_NOISY_CC);
	if (!(zephir_is_true(_2))) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "autologin", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("user"), _3 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "user");

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
	zend_bool _0;
	zval *role = NULL;
	zval *user, *role_param = NULL, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &role_param);

	if (!role_param) {
		ZEPHIR_INIT_VAR(role);
		ZVAL_STRING(role, "login", 1);
	} else {
		zephir_get_strval(role, role_param);
	}


	_0 = Z_TYPE_P(user) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(user, ice_auth_driver_model_users_ce TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CALL_METHOD(&_2, user, "getrole", NULL, 0, role);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			ZVAL_BOOL(_1, 1);
		} else {
			ZVAL_BOOL(_1, 0);
		}
		RETURN_CCTOR(_1);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "User must be an object", "ice/auth/driver/model.zep", 138);
		return;
	}

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

	zephir_fcall_cache_entry *_9 = NULL;
	zend_object_iterator *_7;
	zend_class_entry *_3;
	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember, _4;
	zval *password = NULL;
	zval *username, *password_param = NULL, *remember_param = NULL, *user = NULL, *users = NULL, *roles, *userRoles = NULL, *role = NULL, *token, *lifetime = NULL, *_0 = NULL, *_1 = NULL, *_5 = NULL, *_6 = NULL, *_8 = NULL, _10, *_11, *_12 = NULL, *_13 = NULL, *_14, *_15 = NULL, *_16, *_17 = NULL, *_18 = NULL;

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
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "users", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "Ice\\Auth\\Driver\\Model\\Users", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&users, this_ptr, "getoption", NULL, 0, _0, _1);
			zephir_check_temp_parameter(_0);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_2);
			zephir_create_array(_2, 1, 0 TSRMLS_CC);
			zephir_array_update_string(&_2, SL("username"), &username, PH_COPY | PH_SEPARATE);
			_3 = zephir_fetch_class(users TSRMLS_CC);
			ZEPHIR_CALL_CE_STATIC(&user, _3, "findone", NULL, 0, _2);
			zephir_check_call_status();
		}
	}
	_4 = Z_TYPE_P(user) == IS_OBJECT;
	if (_4) {
		_4 = (zephir_instance_of_ev(user, ice_auth_driver_model_users_ce TSRMLS_CC));
	}
	if (_4) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "password", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5, user, "get", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "hash", NULL, 0, password);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(_5, _6)) {
			ZEPHIR_CALL_METHOD(&userRoles, user, "getroles", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(roles);
			array_init(roles);
			_7 = zephir_get_iterator(userRoles TSRMLS_CC);
			_7->funcs->rewind(_7 TSRMLS_CC);
			for (;_7->funcs->valid(_7 TSRMLS_CC) == SUCCESS && !EG(exception); _7->funcs->move_forward(_7 TSRMLS_CC)) {
				{
					zval **ZEPHIR_TMP_ITERATOR_PTR;
					_7->funcs->get_current_data(_7, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
					ZEPHIR_CPY_WRT(role, (*ZEPHIR_TMP_ITERATOR_PTR));
				}
				ZEPHIR_CALL_METHOD(&_8, role, "getrole", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(role, _8);
				ZEPHIR_INIT_NVAR(_0);
				ZVAL_STRING(_0, "name", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_8, role, "get", &_9, 0, _0);
				zephir_check_temp_parameter(_0);
				zephir_check_call_status();
				zephir_array_append(&roles, _8, PH_SEPARATE, "ice/auth/driver/model.zep", 177);
			}
			_7->funcs->dtor(_7 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_10);
			ZVAL_STRING(&_10, "login", 0);
			if (zephir_fast_in_array(&_10, roles TSRMLS_CC)) {
				if (remember) {
					ZEPHIR_INIT_NVAR(_0);
					ZVAL_STRING(_0, "lifetime", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&lifetime, this_ptr, "getoption", NULL, 0, _0);
					zephir_check_temp_parameter(_0);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(token);
					object_init_ex(token, ice_auth_driver_model_users_tokens_ce);
					ZEPHIR_CALL_METHOD(NULL, token, "__construct", NULL, 44);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8, user, "getid", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval(token, SL("user_id"), _8 TSRMLS_CC);
					_11 = zephir_fetch_nproperty_this(this_ptr, SL("request"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(&_12, _11, "getuseragent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_13, "sha1", NULL, 42, _12);
					zephir_check_call_status();
					zephir_update_property_zval(token, SL("useragent"), _13 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_0);
					zephir_time(_0);
					zephir_update_property_zval(token, SL("created"), _0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_1);
					zephir_time(_1);
					ZEPHIR_INIT_VAR(_14);
					zephir_add_function_ex(_14, _1, lifetime TSRMLS_CC);
					zephir_update_property_zval(token, SL("expires"), _14 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_15, token, "create", NULL, 45);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(_15)) {
						_16 = zephir_fetch_nproperty_this(this_ptr, SL("cookies"), PH_NOISY_CC);
						ZEPHIR_INIT_NVAR(_1);
						ZVAL_STRING(_1, "token", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(&_17, token, "get", &_9, 0, _1);
						zephir_check_temp_parameter(_1);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(_1);
						ZVAL_STRING(_1, "expires", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(&_18, token, "get", &_9, 0, _1);
						zephir_check_temp_parameter(_1);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(_1);
						ZVAL_STRING(_1, "auth_autologin", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _16, "set", NULL, 0, _1, _17, _18);
						zephir_check_temp_parameter(_1);
						zephir_check_call_status();
					}
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "completelogin", NULL, 0, user, roles);
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
 * Logs a user in through social network.
 *
 * @param mixed social
 * @param boolean remember enable autologin
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver_Model, loginBy) {

	zend_object_iterator *_7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zephir_fcall_cache_entry *_0 = NULL, *_8 = NULL;
	zend_bool remember, _5, _6;
	zval *social, *remember_param = NULL, *user = NULL, *userSocial = NULL, *roles, *userRoles = NULL, *role = NULL, *token, *lifetime = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, _9, *_10 = NULL, *_11, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15, *_16 = NULL, *_17, *_18 = NULL, *_19 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &social, &remember_param);

	if (!remember_param) {
		remember = 0;
	} else {
		remember = zephir_get_boolval(remember_param);
	}


	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "socialId", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, social, "get", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("social_id"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, social, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _2, "getprovider", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("type"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&userSocial, ice_auth_driver_model_users_social_ce, "findone", &_0, 41, _1);
	zephir_check_call_status();
	_5 = Z_TYPE_P(userSocial) == IS_OBJECT;
	if (_5) {
		_5 = (zephir_instance_of_ev(userSocial, ice_auth_driver_model_users_social_ce TSRMLS_CC));
	}
	if (_5) {
		ZEPHIR_CALL_METHOD(&user, userSocial, "getuser", NULL, 0);
		zephir_check_call_status();
		_6 = Z_TYPE_P(user) == IS_OBJECT;
		if (_6) {
			_6 = (zephir_instance_of_ev(user, ice_auth_driver_model_users_ce TSRMLS_CC));
		}
		if (_6) {
			ZEPHIR_CALL_METHOD(&userRoles, user, "getroles", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(roles);
			array_init(roles);
			_7 = zephir_get_iterator(userRoles TSRMLS_CC);
			_7->funcs->rewind(_7 TSRMLS_CC);
			for (;_7->funcs->valid(_7 TSRMLS_CC) == SUCCESS && !EG(exception); _7->funcs->move_forward(_7 TSRMLS_CC)) {
				{
					zval **ZEPHIR_TMP_ITERATOR_PTR;
					_7->funcs->get_current_data(_7, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
					ZEPHIR_CPY_WRT(role, (*ZEPHIR_TMP_ITERATOR_PTR));
				}
				ZEPHIR_CALL_METHOD(&_4, role, "getrole", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(role, _4);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "name", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_4, role, "get", &_8, 0, _3);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status();
				zephir_array_append(&roles, _4, PH_SEPARATE, "ice/auth/driver/model.zep", 235);
			}
			_7->funcs->dtor(_7 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_9);
			ZVAL_STRING(&_9, "login", 0);
			if (zephir_fast_in_array(&_9, roles TSRMLS_CC)) {
				if (remember) {
					ZEPHIR_INIT_NVAR(_3);
					ZVAL_STRING(_3, "lifetime", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&lifetime, this_ptr, "getoption", NULL, 0, _3);
					zephir_check_temp_parameter(_3);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(token);
					object_init_ex(token, ice_auth_driver_model_users_tokens_ce);
					ZEPHIR_CALL_METHOD(NULL, token, "__construct", NULL, 44);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_10, user, "getid", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval(token, SL("user_id"), _10 TSRMLS_CC);
					_11 = zephir_fetch_nproperty_this(this_ptr, SL("request"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(&_12, _11, "getuseragent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_13, "sha1", NULL, 42, _12);
					zephir_check_call_status();
					zephir_update_property_zval(token, SL("useragent"), _13 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_3);
					zephir_time(_3);
					zephir_update_property_zval(token, SL("created"), _3 TSRMLS_CC);
					ZEPHIR_INIT_VAR(_14);
					zephir_time(_14);
					ZEPHIR_INIT_VAR(_15);
					zephir_add_function_ex(_15, _14, lifetime TSRMLS_CC);
					zephir_update_property_zval(token, SL("expires"), _15 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_16, token, "create", NULL, 45);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(_16)) {
						_17 = zephir_fetch_nproperty_this(this_ptr, SL("cookies"), PH_NOISY_CC);
						ZEPHIR_INIT_NVAR(_14);
						ZVAL_STRING(_14, "token", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(&_18, token, "get", &_8, 0, _14);
						zephir_check_temp_parameter(_14);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(_14);
						ZVAL_STRING(_14, "expires", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(&_19, token, "get", &_8, 0, _14);
						zephir_check_temp_parameter(_14);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(_14);
						ZVAL_STRING(_14, "auth_autologin", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _17, "set", NULL, 0, _14, _18, _19);
						zephir_check_temp_parameter(_14);
						zephir_check_call_status();
					}
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "completelogin", NULL, 0, user, roles);
				zephir_check_call_status();
				RETURN_MM_BOOL(1);
			}
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Log a user out and remove any autologin cookies.
 *
 * @param boolean destroy Completely destroy the session
 * @param boolean logoutAll Remove all tokens for user
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver_Model, logout) {

	zval *_4 = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *destroy_param = NULL, *logoutAll_param = NULL, *token = NULL, *tokens, *user = NULL, *_0, *_1 = NULL, *_2, *_5 = NULL;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cookies"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "auth_autologin", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&token, _0, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(token)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("cookies"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "auth_autologin", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2, "remove", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4);
		zephir_create_array(_4, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_4, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&token, ice_auth_driver_model_users_tokens_ce, "findone", &_3, 41, _4);
		zephir_check_call_status();
		if (zephir_is_true(token)) {
			ZEPHIR_CALL_METHOD(NULL, token, "remove", NULL, 0);
			zephir_check_call_status();
		}
	}
	if (logoutAll) {
		ZEPHIR_INIT_VAR(tokens);
		object_init_ex(tokens, ice_auth_driver_model_users_tokens_ce);
		ZEPHIR_CALL_METHOD(NULL, tokens, "__construct", NULL, 44);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&user, this_ptr, "getuser", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(user)) {
			ZEPHIR_INIT_NVAR(_4);
			zephir_create_array(_4, 1, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5, user, "getid", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_4, SL("user_id"), &_5, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, tokens, "remove", NULL, 46, _4);
			zephir_check_call_status();
		}
	}
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_model_ce, this_ptr, "logout", &_6, 47, (destroy ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Refresh user data stored in the session.
 * Returns null if no user is currently logged in.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model, refreshUser) {

	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL;
	zend_object_iterator *_6;
	zend_bool _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *user = NULL, *refreshed = NULL, *userRoles = NULL, *userRole = NULL, *roles, *role = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&user, this_ptr, "getuser", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(user))) {
		RETURN_MM_NULL();
	} else {
		_0 = Z_TYPE_P(user) == IS_OBJECT;
		if (_0) {
			_0 = (zephir_instance_of_ev(user, ice_auth_driver_model_users_ce TSRMLS_CC));
		}
		_1 = _0;
		if (_1) {
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "session_roles", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "getoption", NULL, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			_1 = zephir_is_true(_2);
		}
		if (_1) {
			ZEPHIR_CALL_METHOD(&_5, user, "getprimary", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4, user, "get", NULL, 0, _5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&refreshed, user, "loadone", NULL, 0, _4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(user, refreshed);
			ZEPHIR_CALL_METHOD(&userRoles, user, "getroles", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(roles);
			array_init(roles);
			_6 = zephir_get_iterator(userRoles TSRMLS_CC);
			_6->funcs->rewind(_6 TSRMLS_CC);
			for (;_6->funcs->valid(_6 TSRMLS_CC) == SUCCESS && !EG(exception); _6->funcs->move_forward(_6 TSRMLS_CC)) {
				{
					zval **ZEPHIR_TMP_ITERATOR_PTR;
					_6->funcs->get_current_data(_6, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
					ZEPHIR_CPY_WRT(userRole, (*ZEPHIR_TMP_ITERATOR_PTR));
				}
				ZEPHIR_CALL_METHOD(&_7, userRole, "getrole", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(role, _7);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "name", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_7, role, "get", &_8, 0, _3);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status();
				zephir_array_append(&roles, _7, PH_SEPARATE, "ice/auth/driver/model.zep", 330);
			}
			_6->funcs->dtor(_6 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_7, "serialize", NULL, 14, user);
			zephir_check_call_status();
			ZEPHIR_CALL_PARENT(NULL, ice_auth_driver_model_ce, this_ptr, "completelogin", &_9, 43, _7, roles);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("user"), user TSRMLS_CC);
		}
	}
	RETURN_CCTOR(user);

}

