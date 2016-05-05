
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/time.h"


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
 * Initialize user's relations.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users, initialize) {

	zval _1, _5, _7;
	zval _0, _2, _3, _4, _6;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_1, SL("alias"), SL("Tokens"));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Ice\\Auth\\Driver\\Model\\Users\\Tokens");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "user_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, 0, &_0, &_2, &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_5, SL("alias"), SL("Roles"));
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Ice\\Auth\\Driver\\Model\\Roles\\Users");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "user_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, 0, &_4, &_2, &_3, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_7, SL("alias"), SL("Social"));
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Ice\\Auth\\Driver\\Model\\Users\\Social");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "user_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasone", NULL, 0, &_6, &_2, &_3, &_7);
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
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

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
	zephir_update_property_zval(this_ptr, SL("logins"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	zephir_update_property_zval(this_ptr, SL("lastlogin"), &_2);
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

	zval _2, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *name_param = NULL, role, roles, _0, _4, _5;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&roles);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "login");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("name"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&_0, ice_auth_driver_model_roles_ce, "findone", &_1, 41, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&role, &_0);
	if (!(zephir_is_true(&role))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, &role, "getid", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_3, SL("role_id"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&roles, this_ptr, "getroles", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CALL_METHOD(&_0, &roles, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_5, &roles, "getiterator", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, &_5, "current", NULL, 0);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	RETURN_CCTOR(_4);

}

