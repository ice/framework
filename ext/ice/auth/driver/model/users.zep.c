
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

	ice_auth_driver_model_users_ce->create_object = zephir_init_properties;
	return SUCCESS;

}

/**
 * Initialize user's relations.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users, initialize) {

	zval *_1, *_5, *_7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("alias"), SL("Tokens"), 1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Users\\Tokens", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, 0, _0, _2, _3, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_5, SS("alias"), SL("Roles"), 1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Roles\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, 0, _4, _2, _3, _5);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_7, SS("alias"), SL("Social"), 1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Users\\Social", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasone", NULL, 0, _6, _2, _3, _7);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Complete the login for a user by incrementing the logins and saving login timestamp.
 *
 * @return object this
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users, completeLogin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "logins", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(_0) + 1));
	zephir_update_property_zval(this_ptr, SL("logins"),  _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_time(_2);
	zephir_update_property_zval(this_ptr, SL("lastlogin"), _2 TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_2, *_3;
	zephir_fcall_cache_entry *_1 = NULL;
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
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("name"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&_0, ice_auth_driver_model_roles_ce, "findone", &_1, 35, _2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(role, _0);
	if (!(zephir_is_true(role))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, role, "getid", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_3, SL("role_id"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&roles, this_ptr, "getroles", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CALL_METHOD(&_0, roles, "count", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_5, roles, "getiterator", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, _5, "current", NULL, 0);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(_4, 0);
	}
	RETURN_CCTOR(_4);

}

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6, *_7;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("messages"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("messages"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("rules"), _1 TSRMLS_CC);
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("labels"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("labels"), _1 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("relations"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("relations"), _1 TSRMLS_CC);
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
		if (Z_TYPE_P(_5) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("fields"), _1 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("data"), _1 TSRMLS_CC);
		}
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("filters"), PH_NOISY_CC);
		if (Z_TYPE_P(_7) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("filters"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

