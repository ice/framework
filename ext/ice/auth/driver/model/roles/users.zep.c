
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
#include "kernel/object.h"
#include "kernel/operators.h"


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

	ice_auth_driver_model_roles_users_ce->create_object = zephir_init_properties;
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

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "auth", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(&auth, _0, "get", NULL, 0, _1, _2, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, auth, "getoption", NULL, 0, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_6, SS("alias"), SL("User"), 1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, 0, _1, _4, _5, _6);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_8, SS("alias"), SL("Role"), 1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "role_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Roles", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, 0, _1, _2, _7, _8);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6, *_7;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_messages"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_rules"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_rules"), _1 TSRMLS_CC);
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_labels"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_labels"), _1 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_relations"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_relations"), _1 TSRMLS_CC);
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_fields"), PH_NOISY_CC);
		if (Z_TYPE_P(_5) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_fields"), _1 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_data"), _1 TSRMLS_CC);
		}
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
		if (Z_TYPE_P(_7) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_filters"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

