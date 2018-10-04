
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model, Users, ice, auth_driver_model_users, ice_mvc_model_ce, ice_auth_driver_model_users_method_entry, 0);

	/**
	 * Role class name must extend from Ice\Auth\Driver\Model\Roles
	 */
	zend_declare_property_string(ice_auth_driver_model_users_ce, SL("roleClass"), "Ice\\Auth\\Driver\\Model\\Roles", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Token class name must extend from Ice\Auth\Driver\Model\Users\Tokens
	 */
	zend_declare_property_string(ice_auth_driver_model_users_ce, SL("tokenClass"), "Ice\\Auth\\Driver\\Model\\Users\\Tokens", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * User class name must extend from Ice\Auth\Driver\Model\Roles\Users
	 */
	zend_declare_property_string(ice_auth_driver_model_users_ce, SL("userClass"), "Ice\\Auth\\Driver\\Model\\Roles\\Users", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Social class name must extend from Ice\Auth\Driver\Model\Users\Social
	 */
	zend_declare_property_string(ice_auth_driver_model_users_ce, SL("socialClass"), "Ice\\Auth\\Driver\\Model\\Users\\Social", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Initialize user's relations.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users, initialize) {

	zval *_1, *_4, *_6;
	zval *idKey = NULL, *_0, *_2 = NULL, *_3, *_5;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&idKey, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("tokenClass"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("alias"), SL("Tokens"), 1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, 0, idKey, _0, _2, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("userClass"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_4, SS("alias"), SL("Roles"), 1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, 0, idKey, _3, _2, _4);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("socialClass"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_6, SS("alias"), SL("Social"), 1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasone", NULL, 0, idKey, _5, _2, _6);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Complete the login for a user by incrementing the logins and saving login timestamp.
 *
 * @return object this
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users, completeLogin) {

	zval *_0 = NULL, *_1 = NULL, *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "logins", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(_0) + 1));
	zephir_update_property_this(getThis(), SL("logins"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_time(_2);
	zephir_update_property_this(getThis(), SL("lastlogin"), _2 TSRMLS_CC);
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
	zval *_0, *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *role = NULL, *roles = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_STRING(name, "login", 1);
	} else {
		zephir_get_strval(name, name_param);
	}


	ZEPHIR_OBS_VAR(roles);
	zephir_read_property_this(&roles, this_ptr, SL("roleClass"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("name"), &name, PH_COPY | PH_SEPARATE);
	_1 = zephir_fetch_class(roles TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&role, _1, "findone", NULL, 0, _0);
	zephir_check_call_status();
	if (!(zephir_is_true(role))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, role, "getid", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL("role_id"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&roles, this_ptr, "getroles", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CALL_METHOD(&_3, roles, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_CALL_METHOD(&_5, roles, "getiterator", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, _5, "current", NULL, 0);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(_4, 0);
	}
	RETURN_CCTOR(_4);

}

