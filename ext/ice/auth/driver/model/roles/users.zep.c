
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * Model user's Roles.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Roles_Users) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model\\Roles, Users, ice, auth_driver_model_roles_users, ice_mvc_model_ce, ice_auth_driver_model_roles_users_method_entry, 0);

	zend_declare_property_string(ice_auth_driver_model_roles_users_ce, SL("_from"), "roles_users", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Initialize roles-users relations.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Roles_Users, initialize) {

	zval *_6, *_8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *auth = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_5 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "auth", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(&auth, _0, "get", NULL, _1, _2, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, auth, "getoption", NULL, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getidkey", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_6, SS("alias"), SL("User"), 1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, _1, _4, _5, _6);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getidkey", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_8, SS("alias"), SL("Role"), 1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "role_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Roles", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, _1, _2, _7, _8);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

