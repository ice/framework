
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/time.h"


/**
 * Model Users.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model, Users, ice, auth_driver_model_users, ice_mvc_model_ce, ice_auth_driver_model_users_method_entry, 0);

	/**
	 * Role class name must extend from Ice\Auth\Driver\Model\Roles
	 */
	zend_declare_property_string(ice_auth_driver_model_users_ce, SL("roleClass"), "Ice\\Auth\\Driver\\Model\\Roles", ZEND_ACC_PROTECTED);

	/**
	 * Token class name must extend from Ice\Auth\Driver\Model\Users\Tokens
	 */
	zend_declare_property_string(ice_auth_driver_model_users_ce, SL("tokenClass"), "Ice\\Auth\\Driver\\Model\\Users\\Tokens", ZEND_ACC_PROTECTED);

	/**
	 * User class name must extend from Ice\Auth\Driver\Model\Roles\Users
	 */
	zend_declare_property_string(ice_auth_driver_model_users_ce, SL("userClass"), "Ice\\Auth\\Driver\\Model\\Roles\\Users", ZEND_ACC_PROTECTED);

	/**
	 * Social class name must extend from Ice\Auth\Driver\Model\Users\Social
	 */
	zend_declare_property_string(ice_auth_driver_model_users_ce, SL("socialClass"), "Ice\\Auth\\Driver\\Model\\Users\\Social", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Initialize user's relations.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users, initialize) {

	zval _1, _4, _6;
	zval idKey, _0, _2, _3, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&idKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&idKey, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("tokenClass"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	add_assoc_stringl_ex(&_1, SL("alias"), SL("Tokens"));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "user_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, 0, &idKey, &_0, &_2, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("userClass"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0);
	add_assoc_stringl_ex(&_4, SL("alias"), SL("Roles"));
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "user_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, 0, &idKey, &_3, &_2, &_4);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("socialClass"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	add_assoc_stringl_ex(&_6, SL("alias"), SL("Social"));
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "user_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasone", NULL, 0, &idKey, &_5, &_2, &_6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Complete the login for a user by incrementing the logins and saving login timestamp.
 *
 * @return object this
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users, completeLogin) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "logins");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) + 1));
	zephir_update_property_zval(this_ptr, ZEND_STRL("logins"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("lastlogin"), &_2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "update", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Get user's role.
 *
 * @param string name Role name to get
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users, getRole) {

	zend_class_entry *_1;
	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, role, roles, _3, _4, _5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&roles);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "login");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_OBS_VAR(&roles);
	zephir_read_property(&roles, this_ptr, ZEND_STRL("roleClass"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	zephir_array_update_string(&_0, SL("name"), &name, PH_COPY | PH_SEPARATE);
	_1 = zephir_fetch_class(&roles);
	ZEPHIR_CALL_CE_STATIC(&role, _1, "findone", NULL, 0, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&role))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_CALL_METHOD(&_3, &role, "getid", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL("role_id"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&roles, this_ptr, "getroles", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CALL_METHOD(&_3, &roles, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(&_5, &roles, "getiterator", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, &_5, "current", NULL, 0);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	RETURN_CCTOR(&_4);

}

