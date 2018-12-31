
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
 * Auth database driver.
 *
 * @package     Ice/Auth
 * @category    Driver
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Db) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver, Db, ice, auth_driver_db, ice_auth_driver_ce, ice_auth_driver_db_method_entry, 0);

	zend_class_implements(ice_auth_driver_db_ce TSRMLS_CC, 1, ice_auth_driver_driverinterface_ce);
	return SUCCESS;

}

/**
 * Logs a user in, based on the autologin cookie.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Db, autoLogin) {

	zend_object_iterator *_9$$5;
	zend_bool _4$$4;
	zval _3$$3;
	zval token, user, userRoles, roles, role, _0, _1, _5$$4, _6$$4, _7$$4, _8$$4, _13$$5, _10$$6, _11$$6, _14$$7, _15$$7, _16$$7, _17$$7;
	zephir_fcall_cache_entry *_2 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&userRoles);
	ZVAL_UNDEF(&roles);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "auth_autologin");
	ZEPHIR_CALL_METHOD(&token, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&token)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_3$$3, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&token, ice_auth_driver_model_users_tokens_ce, "findone", &_2, 0, &_3$$3);
		zephir_check_call_status();
		if (zephir_is_true(&token)) {
			ZEPHIR_CALL_METHOD(&user, &token, "getuser", NULL, 0);
			zephir_check_call_status();
			_4$$4 = zephir_is_true(&user);
			if (_4$$4) {
				ZEPHIR_OBS_VAR(&_5$$4);
				zephir_read_property(&_5$$4, &token, SL("useragent"), PH_NOISY_CC);
				zephir_read_property(&_6$$4, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_7$$4, &_6$$4, "getuseragent", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_8$$4, "sha1", NULL, 58, &_7$$4);
				zephir_check_call_status();
				_4$$4 = ZEPHIR_IS_IDENTICAL(&_5$$4, &_8$$4);
			}
			if (_4$$4) {
				ZEPHIR_CALL_METHOD(&userRoles, &user, "getroles", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&roles);
				array_init(&roles);
				_9$$5 = zephir_get_iterator(&userRoles TSRMLS_CC);
				_9$$5->funcs->rewind(_9$$5 TSRMLS_CC);
				for (;_9$$5->funcs->valid(_9$$5 TSRMLS_CC) == SUCCESS && !EG(exception); _9$$5->funcs->move_forward(_9$$5 TSRMLS_CC)) {
					{
						ZEPHIR_ITERATOR_COPY(&role, _9$$5);
					}
					ZEPHIR_CALL_METHOD(&_10$$6, &role, "getrole", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&role, &_10$$6);
					ZEPHIR_INIT_NVAR(&_11$$6);
					ZVAL_STRING(&_11$$6, "name");
					ZEPHIR_CALL_METHOD(&_10$$6, &role, "get", &_12, 0, &_11$$6);
					zephir_check_call_status();
					zephir_array_append(&roles, &_10$$6, PH_SEPARATE, "ice/auth/driver/db.zep", 51);
				}
				zend_iterator_dtor(_9$$5);
				ZEPHIR_INIT_VAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "login");
				if (zephir_fast_in_array(&_13$$5, &roles TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, &token, "update", NULL, 0);
					zephir_check_call_status();
					zephir_read_property(&_14$$7, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_VAR(&_15$$7);
					zephir_read_property(&_15$$7, &token, SL("token"), PH_NOISY_CC);
					ZEPHIR_OBS_VAR(&_16$$7);
					zephir_read_property(&_16$$7, &token, SL("expires"), PH_NOISY_CC);
					ZEPHIR_INIT_VAR(&_17$$7);
					ZVAL_STRING(&_17$$7, "auth_autologin");
					ZEPHIR_CALL_METHOD(NULL, &_14$$7, "set", NULL, 0, &_17$$7, &_15$$7, &_16$$7);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "completelogin", NULL, 0, &user, &roles);
					zephir_check_call_status();
					RETURN_CCTOR(&user);
				}
			}
			ZEPHIR_CALL_METHOD(NULL, &token, "delete", NULL, 0);
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
PHP_METHOD(Ice_Auth_Driver_Db, completeLogin) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roles;
	zval *user, user_sub, *roles_param = NULL, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&roles);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &roles_param);

	if (!roles_param) {
		ZEPHIR_INIT_VAR(&roles);
		array_init(&roles);
	} else {
		zephir_get_arrval(&roles, roles_param);
	}


	if (zephir_instance_of_ev(user, ice_auth_driver_model_users_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, user, "completelogin", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_1$$3, "serialize", NULL, 13, user);
		zephir_check_call_status();
		ZEPHIR_CALL_PARENT(NULL, ice_auth_driver_db_ce, getThis(), "completelogin", &_0, 0, &_1$$3, &roles);
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
PHP_METHOD(Ice_Auth_Driver_Db, getUser) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *defaultValue = NULL, defaultValue_sub, __$null, data, _0, _2, user$$5, _3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&user$$5);
	ZVAL_UNDEF(&_3$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("user"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_PARENT(&data, ice_auth_driver_db_ce, getThis(), "getuser", &_1, 0, defaultValue);
		zephir_check_call_status();
		if (ZEPHIR_IS_IDENTICAL(&data, defaultValue)) {
			zephir_update_property_zval(this_ptr, SL("user"), defaultValue);
		} else if (Z_TYPE_P(&data) == IS_STRING) {
			ZEPHIR_CALL_FUNCTION(&user$$5, "unserialize", NULL, 16, &data);
			zephir_check_call_status();
			if (zephir_instance_of_ev(&user$$5, ice_auth_driver_model_users_ce TSRMLS_CC)) {
				zephir_update_property_zval(this_ptr, SL("user"), &user$$5);
			}
		}
	}
	zephir_read_property(&_2, this_ptr, SL("user"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_CALL_METHOD(&_3$$7, this_ptr, "autologin", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("user"), &_3$$7);
	}
	RETURN_MM_MEMBER(getThis(), "user");

}

/**
 * Check if user has the role.
 *
 * @param object user User Model object
 * @param string role Role name
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver_Db, hasRole) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval role;
	zval *user, user_sub, *role_param = NULL, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&role);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &role_param);

	if (!role_param) {
		ZEPHIR_INIT_VAR(&role);
		ZVAL_STRING(&role, "login");
	} else {
		zephir_get_strval(&role, role_param);
	}


	_0 = Z_TYPE_P(user) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(user, ice_auth_driver_model_users_ce TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CALL_METHOD(&_2$$3, user, "getrole", NULL, 0, &role);
		zephir_check_call_status();
		if (zephir_is_true(&_2$$3)) {
			ZVAL_BOOL(&_1$$3, 1);
		} else {
			ZVAL_BOOL(&_1$$3, 0);
		}
		RETURN_CCTOR(&_1$$3);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "User must be an object", "ice/auth/driver/db.zep", 138);
		return;
	}

}

/**
 * Logs a user in.
 *
 * @param mixed username
 * @param string password
 * @param boolean remember enable autologin
 * @param boolean force login without password
 * @return boolean
 */
PHP_METHOD(Ice_Auth_Driver_Db, login) {

	zend_object_iterator *_11$$9;
	zend_class_entry *_3$$5;
	zval _2$$5;
	zephir_fcall_cache_entry *_7 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember, force, _4, _5$$7, _10$$7;
	zval password;
	zval *username, username_sub, *password_param = NULL, *remember_param = NULL, *force_param = NULL, user, users, roles, userRoles, role, token, lifetime, _0$$5, _1$$5, _6$$7, _8$$7, _9$$7, _15$$9, _12$$10, _13$$10, _16$$12, _17$$12, _18$$12, _19$$12, _20$$12, _21$$12, _22$$12, _23$$12, _24$$13, _25$$13, _26$$13, _27$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&username_sub);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&users);
	ZVAL_UNDEF(&roles);
	ZVAL_UNDEF(&userRoles);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &username, &password_param, &remember_param, &force_param);

	zephir_get_strval(&password, password_param);
	if (!remember_param) {
		remember = 0;
	} else {
		remember = zephir_get_boolval(remember_param);
	}
	if (!force_param) {
		force = 0;
	} else {
		force = zephir_get_boolval(force_param);
	}


	ZEPHIR_INIT_VAR(&user);
	ZVAL_NULL(&user);
	if (zephir_is_true(username)) {
		if (Z_TYPE_P(username) == IS_OBJECT) {
			ZEPHIR_CPY_WRT(&user, username);
		} else {
			ZEPHIR_INIT_VAR(&_0$$5);
			ZVAL_STRING(&_0$$5, "users");
			ZEPHIR_INIT_VAR(&_1$$5);
			ZVAL_STRING(&_1$$5, "Ice\\Auth\\Driver\\Model\\Users");
			ZEPHIR_CALL_METHOD(&users, this_ptr, "getoption", NULL, 0, &_0$$5, &_1$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_2$$5);
			zephir_create_array(&_2$$5, 1, 0 TSRMLS_CC);
			zephir_array_update_string(&_2$$5, SL("username"), username, PH_COPY | PH_SEPARATE);
			_3$$5 = zephir_fetch_class(&users TSRMLS_CC);
			ZEPHIR_CALL_CE_STATIC(&user, _3$$5, "findone", NULL, 0, &_2$$5);
			zephir_check_call_status();
		}
	} else {
		RETURN_MM_NULL();
	}
	_4 = Z_TYPE_P(&user) == IS_OBJECT;
	if (_4) {
		_4 = (zephir_instance_of_ev(&user, ice_auth_driver_model_users_ce TSRMLS_CC));
	}
	if (_4) {
		_5$$7 = ZEPHIR_IS_EMPTY(&password);
		if (_5$$7) {
			_5$$7 = !force;
		}
		if (_5$$7) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_9$$7);
		ZVAL_STRING(&_9$$7, "password");
		ZEPHIR_CALL_METHOD(&_8$$7, &user, "get", NULL, 0, &_9$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_PARENT(&_6$$7, ice_auth_driver_db_ce, getThis(), "checkhash", &_7, 0, &password, &_8$$7);
		zephir_check_call_status();
		_10$$7 = zephir_is_true(&_6$$7);
		if (!(_10$$7)) {
			_10$$7 = force;
		}
		if (_10$$7) {
			ZEPHIR_CALL_METHOD(&userRoles, &user, "getroles", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&roles);
			array_init(&roles);
			_11$$9 = zephir_get_iterator(&userRoles TSRMLS_CC);
			_11$$9->funcs->rewind(_11$$9 TSRMLS_CC);
			for (;_11$$9->funcs->valid(_11$$9 TSRMLS_CC) == SUCCESS && !EG(exception); _11$$9->funcs->move_forward(_11$$9 TSRMLS_CC)) {
				{
					ZEPHIR_ITERATOR_COPY(&role, _11$$9);
				}
				ZEPHIR_CALL_METHOD(&_12$$10, &role, "getrole", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&role, &_12$$10);
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_STRING(&_13$$10, "name");
				ZEPHIR_CALL_METHOD(&_12$$10, &role, "get", &_14, 0, &_13$$10);
				zephir_check_call_status();
				zephir_array_append(&roles, &_12$$10, PH_SEPARATE, "ice/auth/driver/db.zep", 181);
			}
			zend_iterator_dtor(_11$$9);
			ZEPHIR_INIT_VAR(&_15$$9);
			ZVAL_STRING(&_15$$9, "login");
			if (zephir_fast_in_array(&_15$$9, &roles TSRMLS_CC)) {
				if (remember) {
					ZEPHIR_INIT_VAR(&_16$$12);
					ZVAL_STRING(&_16$$12, "lifetime");
					ZEPHIR_CALL_METHOD(&lifetime, this_ptr, "getoption", NULL, 0, &_16$$12);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&token);
					object_init_ex(&token, ice_auth_driver_model_users_tokens_ce);
					ZEPHIR_CALL_METHOD(NULL, &token, "__construct", NULL, 59);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_17$$12, &user, "getid", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval(&token, SL("user_id"), &_17$$12);
					zephir_read_property(&_18$$12, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_19$$12, &_18$$12, "getuseragent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_20$$12, "sha1", NULL, 58, &_19$$12);
					zephir_check_call_status();
					zephir_update_property_zval(&token, SL("useragent"), &_20$$12);
					ZEPHIR_INIT_NVAR(&_16$$12);
					zephir_time(&_16$$12);
					zephir_update_property_zval(&token, SL("created"), &_16$$12);
					ZEPHIR_INIT_VAR(&_21$$12);
					zephir_time(&_21$$12);
					ZEPHIR_INIT_VAR(&_22$$12);
					zephir_add_function(&_22$$12, &_21$$12, &lifetime);
					zephir_update_property_zval(&token, SL("expires"), &_22$$12);
					ZEPHIR_CALL_METHOD(&_23$$12, &token, "create", NULL, 60);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_23$$12)) {
						zephir_read_property(&_24$$13, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_VAR(&_26$$13);
						ZVAL_STRING(&_26$$13, "token");
						ZEPHIR_CALL_METHOD(&_25$$13, &token, "get", &_14, 0, &_26$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_26$$13);
						ZVAL_STRING(&_26$$13, "expires");
						ZEPHIR_CALL_METHOD(&_27$$13, &token, "get", &_14, 0, &_26$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_26$$13);
						ZVAL_STRING(&_26$$13, "auth_autologin");
						ZEPHIR_CALL_METHOD(NULL, &_24$$13, "set", NULL, 0, &_26$$13, &_25$$13, &_27$$13);
						zephir_check_call_status();
					}
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "completelogin", NULL, 0, &user, &roles);
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
PHP_METHOD(Ice_Auth_Driver_Db, loginBy) {

	zend_object_iterator *_7$$4;
	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_10 = NULL;
	zend_bool remember, _5, _6$$3;
	zval *social, social_sub, *remember_param = NULL, user, userSocial, roles, userRoles, role, token, lifetime, _2, _3, _4, _11$$4, _8$$5, _9$$5, _12$$7, _13$$7, _14$$7, _15$$7, _16$$7, _17$$7, _18$$7, _19$$7, _20$$8, _21$$8, _22$$8, _23$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&social_sub);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&userSocial);
	ZVAL_UNDEF(&roles);
	ZVAL_UNDEF(&userRoles);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &social, &remember_param);

	if (!remember_param) {
		remember = 0;
	} else {
		remember = zephir_get_boolval(remember_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "socialId");
	ZEPHIR_CALL_METHOD(&_2, social, "get", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("social_id"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, social, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_2, "getprovider", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("type"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&userSocial, ice_auth_driver_model_users_social_ce, "findone", &_0, 0, &_1);
	zephir_check_call_status();
	_5 = Z_TYPE_P(&userSocial) == IS_OBJECT;
	if (_5) {
		_5 = (zephir_instance_of_ev(&userSocial, ice_auth_driver_model_users_social_ce TSRMLS_CC));
	}
	if (_5) {
		ZEPHIR_CALL_METHOD(&user, &userSocial, "getuser", NULL, 0);
		zephir_check_call_status();
		_6$$3 = Z_TYPE_P(&user) == IS_OBJECT;
		if (_6$$3) {
			_6$$3 = (zephir_instance_of_ev(&user, ice_auth_driver_model_users_ce TSRMLS_CC));
		}
		if (_6$$3) {
			ZEPHIR_CALL_METHOD(&userRoles, &user, "getroles", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&roles);
			array_init(&roles);
			_7$$4 = zephir_get_iterator(&userRoles TSRMLS_CC);
			_7$$4->funcs->rewind(_7$$4 TSRMLS_CC);
			for (;_7$$4->funcs->valid(_7$$4 TSRMLS_CC) == SUCCESS && !EG(exception); _7$$4->funcs->move_forward(_7$$4 TSRMLS_CC)) {
				{
					ZEPHIR_ITERATOR_COPY(&role, _7$$4);
				}
				ZEPHIR_CALL_METHOD(&_8$$5, &role, "getrole", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&role, &_8$$5);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_STRING(&_9$$5, "name");
				ZEPHIR_CALL_METHOD(&_8$$5, &role, "get", &_10, 0, &_9$$5);
				zephir_check_call_status();
				zephir_array_append(&roles, &_8$$5, PH_SEPARATE, "ice/auth/driver/db.zep", 239);
			}
			zend_iterator_dtor(_7$$4);
			ZEPHIR_INIT_VAR(&_11$$4);
			ZVAL_STRING(&_11$$4, "login");
			if (zephir_fast_in_array(&_11$$4, &roles TSRMLS_CC)) {
				if (remember) {
					ZEPHIR_INIT_VAR(&_12$$7);
					ZVAL_STRING(&_12$$7, "lifetime");
					ZEPHIR_CALL_METHOD(&lifetime, this_ptr, "getoption", NULL, 0, &_12$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&token);
					object_init_ex(&token, ice_auth_driver_model_users_tokens_ce);
					ZEPHIR_CALL_METHOD(NULL, &token, "__construct", NULL, 59);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_13$$7, &user, "getid", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval(&token, SL("user_id"), &_13$$7);
					zephir_read_property(&_14$$7, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_15$$7, &_14$$7, "getuseragent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_16$$7, "sha1", NULL, 58, &_15$$7);
					zephir_check_call_status();
					zephir_update_property_zval(&token, SL("useragent"), &_16$$7);
					ZEPHIR_INIT_NVAR(&_12$$7);
					zephir_time(&_12$$7);
					zephir_update_property_zval(&token, SL("created"), &_12$$7);
					ZEPHIR_INIT_VAR(&_17$$7);
					zephir_time(&_17$$7);
					ZEPHIR_INIT_VAR(&_18$$7);
					zephir_add_function(&_18$$7, &_17$$7, &lifetime);
					zephir_update_property_zval(&token, SL("expires"), &_18$$7);
					ZEPHIR_CALL_METHOD(&_19$$7, &token, "create", NULL, 60);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_19$$7)) {
						zephir_read_property(&_20$$8, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_VAR(&_22$$8);
						ZVAL_STRING(&_22$$8, "token");
						ZEPHIR_CALL_METHOD(&_21$$8, &token, "get", &_10, 0, &_22$$8);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_22$$8);
						ZVAL_STRING(&_22$$8, "expires");
						ZEPHIR_CALL_METHOD(&_23$$8, &token, "get", &_10, 0, &_22$$8);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_22$$8);
						ZVAL_STRING(&_22$$8, "auth_autologin");
						ZEPHIR_CALL_METHOD(NULL, &_20$$8, "set", NULL, 0, &_22$$8, &_21$$8, &_23$$8);
						zephir_check_call_status();
					}
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "completelogin", NULL, 0, &user, &roles);
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
PHP_METHOD(Ice_Auth_Driver_Db, logout) {

	zval _5$$3, _6$$6;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destroy_param = NULL, *logoutAll_param = NULL, token, tokens, user, _0, _1, _9, _2$$3, _3$$3, _7$$6;
	zend_bool destroy, logoutAll;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&tokens);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$6);

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


	zephir_read_property(&_0, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "auth_autologin");
	ZEPHIR_CALL_METHOD(&token, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&token)) {
		zephir_read_property(&_2$$3, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "auth_autologin");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "remove", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_5$$3, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&token, ice_auth_driver_model_users_tokens_ce, "findone", &_4, 0, &_5$$3);
		zephir_check_call_status();
		if (zephir_is_true(&token)) {
			ZEPHIR_CALL_METHOD(NULL, &token, "delete", NULL, 0);
			zephir_check_call_status();
		}
	}
	if (logoutAll) {
		ZEPHIR_INIT_VAR(&tokens);
		object_init_ex(&tokens, ice_auth_driver_model_users_tokens_ce);
		ZEPHIR_CALL_METHOD(NULL, &tokens, "__construct", NULL, 59);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&user, this_ptr, "getuser", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&user)) {
			ZEPHIR_INIT_VAR(&_6$$6);
			zephir_create_array(&_6$$6, 1, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_7$$6, &user, "getid", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_6$$6, SL("user_id"), &_7$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &tokens, "delete", NULL, 61, &_6$$6);
			zephir_check_call_status();
		}
	}
	if (destroy) {
		ZVAL_BOOL(&_9, 1);
	} else {
		ZVAL_BOOL(&_9, 0);
	}
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_db_ce, getThis(), "logout", &_8, 0, &_9);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Refresh user data stored in the session.
 * Returns null if no user is currently logged in.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Db, refreshUser) {

	zend_object_iterator *_6$$5;
	zend_bool _0$$4, _1$$4;
	zval user, refreshed, userRoles, userRole, roles, role, _2$$4, _3$$4, _4$$5, _5$$5, _11$$5, _7$$6, _8$$6;
	zephir_fcall_cache_entry *_9 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&refreshed);
	ZVAL_UNDEF(&userRoles);
	ZVAL_UNDEF(&userRole);
	ZVAL_UNDEF(&roles);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&user, this_ptr, "getuser", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&user))) {
		RETURN_MM_NULL();
	} else {
		_0$$4 = Z_TYPE_P(&user) == IS_OBJECT;
		if (_0$$4) {
			_0$$4 = (zephir_instance_of_ev(&user, ice_auth_driver_model_users_ce TSRMLS_CC));
		}
		_1$$4 = _0$$4;
		if (_1$$4) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "session_roles");
			ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getoption", NULL, 0, &_3$$4);
			zephir_check_call_status();
			_1$$4 = zephir_is_true(&_2$$4);
		}
		if (_1$$4) {
			ZEPHIR_CALL_METHOD(&_5$$5, &user, "getprimary", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$5, &user, "get", NULL, 0, &_5$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&refreshed, &user, "loadone", NULL, 0, &_4$$5);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&user, &refreshed);
			ZEPHIR_CALL_METHOD(&userRoles, &user, "getroles", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&roles);
			array_init(&roles);
			_6$$5 = zephir_get_iterator(&userRoles TSRMLS_CC);
			_6$$5->funcs->rewind(_6$$5 TSRMLS_CC);
			for (;_6$$5->funcs->valid(_6$$5 TSRMLS_CC) == SUCCESS && !EG(exception); _6$$5->funcs->move_forward(_6$$5 TSRMLS_CC)) {
				{
					ZEPHIR_ITERATOR_COPY(&userRole, _6$$5);
				}
				ZEPHIR_CALL_METHOD(&_7$$6, &userRole, "getrole", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&role, &_7$$6);
				ZEPHIR_INIT_NVAR(&_8$$6);
				ZVAL_STRING(&_8$$6, "name");
				ZEPHIR_CALL_METHOD(&_7$$6, &role, "get", &_9, 0, &_8$$6);
				zephir_check_call_status();
				zephir_array_append(&roles, &_7$$6, PH_SEPARATE, "ice/auth/driver/db.zep", 334);
			}
			zend_iterator_dtor(_6$$5);
			ZEPHIR_CALL_FUNCTION(&_11$$5, "serialize", NULL, 13, &user);
			zephir_check_call_status();
			ZEPHIR_CALL_PARENT(NULL, ice_auth_driver_db_ce, getThis(), "completelogin", &_10, 0, &_11$$5, &roles);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("user"), &user);
		}
	}
	RETURN_CCTOR(&user);

}

