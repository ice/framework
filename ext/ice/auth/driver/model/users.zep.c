
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * Model Users.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model, Users, ice, auth_driver_model_users, ice_mvc_model_ce, ice_auth_driver_model_users_method_entry, 0);

	return SUCCESS;

}

/**
 * Initialize user's relations
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users, initialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zval *_0, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	add_assoc_stringl_ex(_0, SS("alias"), SL("Tokens"), 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Users\\Tokens", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, _1, _2, _3, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	array_init_size(_4, 2);
	add_assoc_stringl_ex(_4, SS("alias"), SL("Roles"), 1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Roles\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, _1, _2, _3, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Complete the login for a user by incrementing the logins and saving login timestamp
 *
 * @return object this
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users, completeLogin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "logins", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(_0) + 1));
	zephir_update_property_zval(this_ptr, SL("logins"),  _1 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "time", NULL);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("lastlogin"), _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "update", NULL);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Get user's role
 *
 * @param string name Role name to get
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users, getRole) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_2, *_3;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *name_param = NULL, *role = NULL, *roles = NULL, *_0 = NULL, *_4 = NULL, *_5 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_STRING(name, "login", 1);
	} else {
		zephir_get_strval(name, name_param);
	}


	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 2);
	zephir_array_update_string(&_2, SL("name"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&_0, ice_auth_driver_model_roles_ce, "findone", &_1, _2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(role, _0);
	if (!(zephir_is_true(role))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 2);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, role, "get", NULL, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_3, SL("role_id"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&roles, this_ptr, "getroles", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_4);
	ZEPHIR_CALL_METHOD(&_0, roles, "count", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_5, roles, "getiterator", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, _5, "current", NULL);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(_4, 0);
	}
	RETURN_CCTOR(_4);

}

