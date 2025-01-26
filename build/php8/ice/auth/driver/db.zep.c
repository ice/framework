
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
 * @copyright   (c) 2014-2025 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Db)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver, Db, ice, auth_driver_db, ice_auth_driver_ce, ice_auth_driver_db_method_entry, 0);

	zend_class_implements(ice_auth_driver_db_ce, 1, ice_auth_driver_driverinterface_ce);
	return SUCCESS;
}

/**
 * Logs a user in, based on the autologin cookie.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Db, autoLogin)
{
	zend_object_iterator *_8$$5;
	zend_bool _3$$4;
	zval _2$$3;
	zval token, user, userRoles, roles, role, _0, _1, _4$$4, _5$$4, _6$$4, _7$$4, _12$$5, _9$$6, _10$$6, _13$$7, _14$$7, _15$$7, _16$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&userRoles);
	ZVAL_UNDEF(&roles);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_2$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "auth_autologin");
	ZEPHIR_CALL_METHOD(&token, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&token)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0);
		zephir_array_update_string(&_2$$3, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&token, ice_auth_driver_model_users_tokens_ce, "findone", NULL, 0, &_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(&token)) {
			ZEPHIR_CALL_METHOD(&user, &token, "getuser", NULL, 0);
			zephir_check_call_status();
			_3$$4 = zephir_is_true(&user);
			if (_3$$4) {
				zephir_memory_observe(&_4$$4);
				zephir_read_property(&_4$$4, &token, ZEND_STRL("useragent"), PH_NOISY_CC);
				zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_6$$4, &_5$$4, "getuseragent", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_7$$4, "sha1", NULL, 67, &_6$$4);
				zephir_check_call_status();
				_3$$4 = ZEPHIR_IS_IDENTICAL(&_4$$4, &_7$$4);
			}
			if (_3$$4) {
				ZEPHIR_CALL_METHOD(&userRoles, &user, "getroles", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&roles);
				array_init(&roles);
				_8$$5 = zephir_get_iterator(&userRoles);
				_8$$5->funcs->rewind(_8$$5);
				for (;_8$$5->funcs->valid(_8$$5) == SUCCESS && !EG(exception); _8$$5->funcs->move_forward(_8$$5)) {
					{
						ZEPHIR_ITERATOR_COPY(&role, _8$$5);
					}
					ZEPHIR_CALL_METHOD(&_9$$6, &role, "getrole", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&role, &_9$$6);
					ZEPHIR_INIT_NVAR(&_10$$6);
					ZVAL_STRING(&_10$$6, "name");
					ZEPHIR_CALL_METHOD(&_9$$6, &role, "get", &_11, 0, &_10$$6);
					zephir_check_call_status();
					zephir_array_append(&roles, &_9$$6, PH_SEPARATE, "ice/auth/driver/db.zep", 50);
				}
				zend_iterator_dtor(_8$$5);
				ZEPHIR_INIT_VAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "login");
				if (zephir_fast_in_array(&_12$$5, &roles)) {
					ZEPHIR_CALL_METHOD(NULL, &token, "update", NULL, 0);
					zephir_check_call_status();
					zephir_read_property(&_13$$7, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
					zephir_memory_observe(&_14$$7);
					zephir_read_property(&_14$$7, &token, ZEND_STRL("token"), PH_NOISY_CC);
					zephir_memory_observe(&_15$$7);
					zephir_read_property(&_15$$7, &token, ZEND_STRL("expires"), PH_NOISY_CC);
					ZEPHIR_INIT_VAR(&_16$$7);
					ZVAL_STRING(&_16$$7, "auth_autologin");
					ZEPHIR_CALL_METHOD(NULL, &_13$$7, "set", NULL, 0, &_16$$7, &_14$$7, &_15$$7);
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
PHP_METHOD(Ice_Auth_Driver_Db, completeLogin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roles;
	zval *user, user_sub, *roles_param = NULL, _0$$3;

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&roles);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(user)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(roles)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &user, &roles_param);
	if (!roles_param) {
		ZEPHIR_INIT_VAR(&roles);
		array_init(&roles);
	} else {
		zephir_get_arrval(&roles, roles_param);
	}
	if (zephir_instance_of_ev(user, ice_auth_driver_model_users_ce)) {
		ZEPHIR_CALL_METHOD(NULL, user, "completelogin", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_0$$3, "serialize", NULL, 13, user);
		zephir_check_call_status();
		ZEPHIR_CALL_PARENT(NULL, ice_auth_driver_db_ce, getThis(), "completelogin", NULL, 0, &_0$$3, &roles);
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
PHP_METHOD(Ice_Auth_Driver_Db, getUser)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultValue = NULL, defaultValue_sub, __$null, data, _0, _1, user$$5, _2$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&user$$5);
	ZVAL_UNDEF(&_2$$7);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_PARENT(&data, ice_auth_driver_db_ce, getThis(), "getuser", NULL, 0, defaultValue);
		zephir_check_call_status();
		if (ZEPHIR_IS_IDENTICAL(&data, defaultValue)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("user"), defaultValue);
		} else if (Z_TYPE_P(&data) == IS_STRING) {
			ZEPHIR_CALL_FUNCTION(&user$$5, "unserialize", NULL, 16, &data);
			zephir_check_call_status();
			if (zephir_instance_of_ev(&user$$5, ice_auth_driver_model_users_ce)) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &user$$5);
			}
		}
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_CALL_METHOD(&_2$$7, this_ptr, "autologin", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &_2$$7);
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
PHP_METHOD(Ice_Auth_Driver_Db, hasRole)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval role;
	zval *user, user_sub, *role_param = NULL, _1$$3, _2$$3;

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&role);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(user)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(role)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &user, &role_param);
	if (!role_param) {
		ZEPHIR_INIT_VAR(&role);
		ZVAL_STRING(&role, "login");
	} else {
		zephir_get_strval(&role, role_param);
	}
	_0 = Z_TYPE_P(user) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(user, ice_auth_driver_model_users_ce));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CALL_METHOD(&_2$$3, user, "getrole", NULL, 0, &role);
		zephir_check_call_status();
		if (zephir_is_true(&_2$$3)) {
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_BOOL(&_1$$3, 1);
		} else {
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_BOOL(&_1$$3, 0);
		}
		RETURN_CCTOR(&_1$$3);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "User must be an object", "ice/auth/driver/db.zep", 137);
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
PHP_METHOD(Ice_Auth_Driver_Db, login)
{
	zend_object_iterator *_10$$9;
	zend_class_entry *_3$$5;
	zval _2$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember, force, _4, _5$$7, _9$$7;
	zval password;
	zval *username, username_sub, *password_param = NULL, *remember_param = NULL, *force_param = NULL, user, users, roles, userRoles, role, token, lifetime, _0$$5, _1$$5, _6$$7, _7$$7, _8$$7, _14$$9, _11$$10, _12$$10, _15$$12, _16$$12, _17$$12, _18$$12, _19$$12, _20$$12, _21$$12, _22$$12, _23$$13, _24$$13, _25$$13, _26$$13;
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
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&_2$$5);
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_ZVAL(username)
		Z_PARAM_STR(password)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(remember)
		Z_PARAM_BOOL(force)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 2, &username, &password_param, &remember_param, &force_param);
	zephir_get_strval(&password, password_param);
	if (!remember_param) {
		remember = 0;
	} else {
		}
	if (!force_param) {
		force = 0;
	} else {
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
			zephir_create_array(&_2$$5, 1, 0);
			zephir_array_update_string(&_2$$5, SL("username"), username, PH_COPY | PH_SEPARATE);
			_3$$5 = zephir_fetch_class(&users);
			ZEPHIR_CALL_CE_STATIC(&user, _3$$5, "findone", NULL, 0, &_2$$5);
			zephir_check_call_status();
		}
	} else {
		RETURN_MM_NULL();
	}
	_4 = Z_TYPE_P(&user) == IS_OBJECT;
	if (_4) {
		_4 = (zephir_instance_of_ev(&user, ice_auth_driver_model_users_ce));
	}
	if (_4) {
		_5$$7 = ZEPHIR_IS_EMPTY(&password);
		if (_5$$7) {
			_5$$7 = !force;
		}
		if (_5$$7) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_8$$7);
		ZVAL_STRING(&_8$$7, "password");
		ZEPHIR_CALL_METHOD(&_7$$7, &user, "get", NULL, 0, &_8$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_PARENT(&_6$$7, ice_auth_driver_db_ce, getThis(), "checkhash", NULL, 0, &password, &_7$$7);
		zephir_check_call_status();
		_9$$7 = zephir_is_true(&_6$$7);
		if (!(_9$$7)) {
			_9$$7 = force;
		}
		if (_9$$7) {
			ZEPHIR_CALL_METHOD(&userRoles, &user, "getroles", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&roles);
			array_init(&roles);
			_10$$9 = zephir_get_iterator(&userRoles);
			_10$$9->funcs->rewind(_10$$9);
			for (;_10$$9->funcs->valid(_10$$9) == SUCCESS && !EG(exception); _10$$9->funcs->move_forward(_10$$9)) {
				{
					ZEPHIR_ITERATOR_COPY(&role, _10$$9);
				}
				ZEPHIR_CALL_METHOD(&_11$$10, &role, "getrole", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&role, &_11$$10);
				ZEPHIR_INIT_NVAR(&_12$$10);
				ZVAL_STRING(&_12$$10, "name");
				ZEPHIR_CALL_METHOD(&_11$$10, &role, "get", &_13, 0, &_12$$10);
				zephir_check_call_status();
				zephir_array_append(&roles, &_11$$10, PH_SEPARATE, "ice/auth/driver/db.zep", 180);
			}
			zend_iterator_dtor(_10$$9);
			ZEPHIR_INIT_VAR(&_14$$9);
			ZVAL_STRING(&_14$$9, "login");
			if (zephir_fast_in_array(&_14$$9, &roles)) {
				if (remember) {
					ZEPHIR_INIT_VAR(&_15$$12);
					ZVAL_STRING(&_15$$12, "lifetime");
					ZEPHIR_CALL_METHOD(&lifetime, this_ptr, "getoption", NULL, 0, &_15$$12);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&token);
					object_init_ex(&token, ice_auth_driver_model_users_tokens_ce);
					ZEPHIR_CALL_METHOD(NULL, &token, "__construct", NULL, 68);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_16$$12, &user, "getid", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval(&token, ZEND_STRL("user_id"), &_16$$12);
					zephir_read_property(&_17$$12, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_18$$12, &_17$$12, "getuseragent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_19$$12, "sha1", NULL, 67, &_18$$12);
					zephir_check_call_status();
					zephir_update_property_zval(&token, ZEND_STRL("useragent"), &_19$$12);
					ZEPHIR_INIT_NVAR(&_15$$12);
					zephir_time(&_15$$12);
					zephir_update_property_zval(&token, ZEND_STRL("created"), &_15$$12);
					ZEPHIR_INIT_VAR(&_20$$12);
					zephir_time(&_20$$12);
					ZEPHIR_INIT_VAR(&_21$$12);
					zephir_add_function(&_21$$12, &_20$$12, &lifetime);
					zephir_update_property_zval(&token, ZEND_STRL("expires"), &_21$$12);
					ZEPHIR_CALL_METHOD(&_22$$12, &token, "create", NULL, 69);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_22$$12)) {
						zephir_read_property(&_23$$13, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_VAR(&_25$$13);
						ZVAL_STRING(&_25$$13, "token");
						ZEPHIR_CALL_METHOD(&_24$$13, &token, "get", &_13, 0, &_25$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_25$$13);
						ZVAL_STRING(&_25$$13, "expires");
						ZEPHIR_CALL_METHOD(&_26$$13, &token, "get", &_13, 0, &_25$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_25$$13);
						ZVAL_STRING(&_25$$13, "auth_autologin");
						ZEPHIR_CALL_METHOD(NULL, &_23$$13, "set", NULL, 0, &_25$$13, &_24$$13, &_26$$13);
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
PHP_METHOD(Ice_Auth_Driver_Db, loginBy)
{
	zend_object_iterator *_6$$4;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember, _4, _5$$3;
	zval *social, social_sub, *remember_param = NULL, user, userSocial, roles, userRoles, role, token, lifetime, _1, _2, _3, _10$$4, _7$$5, _8$$5, _11$$7, _12$$7, _13$$7, _14$$7, _15$$7, _16$$7, _17$$7, _18$$7, _19$$8, _20$$8, _21$$8, _22$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&social_sub);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&userSocial);
	ZVAL_UNDEF(&roles);
	ZVAL_UNDEF(&userRoles);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(social, ice_auth_social_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(remember)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &social, &remember_param);
	if (!remember_param) {
		remember = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "socialId");
	ZEPHIR_CALL_METHOD(&_1, social, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("social_id"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, social, "getadapter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &_1, "getprovider", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("type"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&userSocial, ice_auth_driver_model_users_social_ce, "findone", NULL, 0, &_0);
	zephir_check_call_status();
	_4 = Z_TYPE_P(&userSocial) == IS_OBJECT;
	if (_4) {
		_4 = (zephir_instance_of_ev(&userSocial, ice_auth_driver_model_users_social_ce));
	}
	if (_4) {
		ZEPHIR_CALL_METHOD(&user, &userSocial, "getuser", NULL, 0);
		zephir_check_call_status();
		_5$$3 = Z_TYPE_P(&user) == IS_OBJECT;
		if (_5$$3) {
			_5$$3 = (zephir_instance_of_ev(&user, ice_auth_driver_model_users_ce));
		}
		if (_5$$3) {
			ZEPHIR_CALL_METHOD(&userRoles, &user, "getroles", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&roles);
			array_init(&roles);
			_6$$4 = zephir_get_iterator(&userRoles);
			_6$$4->funcs->rewind(_6$$4);
			for (;_6$$4->funcs->valid(_6$$4) == SUCCESS && !EG(exception); _6$$4->funcs->move_forward(_6$$4)) {
				{
					ZEPHIR_ITERATOR_COPY(&role, _6$$4);
				}
				ZEPHIR_CALL_METHOD(&_7$$5, &role, "getrole", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&role, &_7$$5);
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZVAL_STRING(&_8$$5, "name");
				ZEPHIR_CALL_METHOD(&_7$$5, &role, "get", &_9, 0, &_8$$5);
				zephir_check_call_status();
				zephir_array_append(&roles, &_7$$5, PH_SEPARATE, "ice/auth/driver/db.zep", 238);
			}
			zend_iterator_dtor(_6$$4);
			ZEPHIR_INIT_VAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "login");
			if (zephir_fast_in_array(&_10$$4, &roles)) {
				if (remember) {
					ZEPHIR_INIT_VAR(&_11$$7);
					ZVAL_STRING(&_11$$7, "lifetime");
					ZEPHIR_CALL_METHOD(&lifetime, this_ptr, "getoption", NULL, 0, &_11$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&token);
					object_init_ex(&token, ice_auth_driver_model_users_tokens_ce);
					ZEPHIR_CALL_METHOD(NULL, &token, "__construct", NULL, 68);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_12$$7, &user, "getid", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval(&token, ZEND_STRL("user_id"), &_12$$7);
					zephir_read_property(&_13$$7, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_14$$7, &_13$$7, "getuseragent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_15$$7, "sha1", NULL, 67, &_14$$7);
					zephir_check_call_status();
					zephir_update_property_zval(&token, ZEND_STRL("useragent"), &_15$$7);
					ZEPHIR_INIT_NVAR(&_11$$7);
					zephir_time(&_11$$7);
					zephir_update_property_zval(&token, ZEND_STRL("created"), &_11$$7);
					ZEPHIR_INIT_VAR(&_16$$7);
					zephir_time(&_16$$7);
					ZEPHIR_INIT_VAR(&_17$$7);
					zephir_add_function(&_17$$7, &_16$$7, &lifetime);
					zephir_update_property_zval(&token, ZEND_STRL("expires"), &_17$$7);
					ZEPHIR_CALL_METHOD(&_18$$7, &token, "create", NULL, 69);
					zephir_check_call_status();
					if (ZEPHIR_IS_TRUE_IDENTICAL(&_18$$7)) {
						zephir_read_property(&_19$$8, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_VAR(&_21$$8);
						ZVAL_STRING(&_21$$8, "token");
						ZEPHIR_CALL_METHOD(&_20$$8, &token, "get", &_9, 0, &_21$$8);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_21$$8);
						ZVAL_STRING(&_21$$8, "expires");
						ZEPHIR_CALL_METHOD(&_22$$8, &token, "get", &_9, 0, &_21$$8);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_21$$8);
						ZVAL_STRING(&_21$$8, "auth_autologin");
						ZEPHIR_CALL_METHOD(NULL, &_19$$8, "set", NULL, 0, &_21$$8, &_20$$8, &_22$$8);
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
PHP_METHOD(Ice_Auth_Driver_Db, logout)
{
	zval _4$$3, _5$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destroy_param = NULL, *logoutAll_param = NULL, __$null, token, tokens, user, _0, _1, _7, _2$$3, _3$$3, _6$$6;
	zend_bool destroy, logoutAll;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&tokens);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$6);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "auth_autologin");
	ZEPHIR_CALL_METHOD(&token, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&token)) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "auth_autologin");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "remove", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 1, 0);
		zephir_array_update_string(&_4$$3, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&token, ice_auth_driver_model_users_tokens_ce, "findone", NULL, 0, &_4$$3);
		zephir_check_call_status();
		if (zephir_is_true(&token)) {
			ZEPHIR_CALL_METHOD(NULL, &token, "delete", NULL, 0);
			zephir_check_call_status();
		}
	}
	if (logoutAll) {
		ZEPHIR_INIT_VAR(&tokens);
		object_init_ex(&tokens, ice_auth_driver_model_users_tokens_ce);
		ZEPHIR_CALL_METHOD(NULL, &tokens, "__construct", NULL, 68);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&user, this_ptr, "getuser", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&user)) {
			ZEPHIR_INIT_VAR(&_5$$6);
			zephir_create_array(&_5$$6, 1, 0);
			ZEPHIR_CALL_METHOD(&_6$$6, &user, "getid", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&_5$$6, SL("user_id"), &_6$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &tokens, "delete", NULL, 70, &_5$$6);
			zephir_check_call_status();
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &__$null);
	if (destroy) {
		ZVAL_BOOL(&_7, 1);
	} else {
		ZVAL_BOOL(&_7, 0);
	}
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_db_ce, getThis(), "logout", NULL, 0, &_7);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Refresh user data stored in the session.
 * Returns null if no user is currently logged in.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Db, refreshUser)
{
	zend_object_iterator *_6$$5;
	zend_bool _0$$4, _1$$4;
	zval user, refreshed, userRoles, userRole, roles, role, _2$$4, _3$$4, _4$$5, _5$$5, _10$$5, _7$$6, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
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
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&user, this_ptr, "getuser", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&user))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "logout", NULL, 0);
		zephir_check_call_status();
		RETURN_MM_NULL();
	} else {
		_0$$4 = Z_TYPE_P(&user) == IS_OBJECT;
		if (_0$$4) {
			_0$$4 = (zephir_instance_of_ev(&user, ice_auth_driver_model_users_ce));
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
			_6$$5 = zephir_get_iterator(&userRoles);
			_6$$5->funcs->rewind(_6$$5);
			for (;_6$$5->funcs->valid(_6$$5) == SUCCESS && !EG(exception); _6$$5->funcs->move_forward(_6$$5)) {
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
				zephir_array_append(&roles, &_7$$6, PH_SEPARATE, "ice/auth/driver/db.zep", 337);
			}
			zend_iterator_dtor(_6$$5);
			ZEPHIR_CALL_FUNCTION(&_10$$5, "serialize", NULL, 13, &user);
			zephir_check_call_status();
			ZEPHIR_CALL_PARENT(NULL, ice_auth_driver_db_ce, getThis(), "completelogin", NULL, 0, &_10$$5, &roles);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &user);
		}
	}
	RETURN_CCTOR(&user);
}

