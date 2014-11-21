
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


/**
 * Model user's Roles.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Roles_Users) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model\\Roles, Users, ice, auth_driver_model_roles_users, ice_mvc_model_ce, ice_auth_driver_model_roles_users_method_entry, 0);

	zend_declare_property_string(ice_auth_driver_model_roles_users_ce, SL("_from"), "roles_users", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Initialize roles-users relations
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Roles_Users, initialize) {

	zval *_5, *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *auth = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_7;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&auth, _0, "getauth", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "Ice\\Auth\\Driver\\Model\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, auth, "getoption", NULL, _3, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	array_init_size(_5, 2);
	add_assoc_stringl_ex(_5, SS("alias"), SL("User"), 1);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, _3, _2, _4, _5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	array_init_size(_6, 2);
	add_assoc_stringl_ex(_6, SS("alias"), SL("Role"), 1);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "role_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Ice\\Auth\\Driver\\Model\\Roles", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, _3, _4, _7, _6);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

