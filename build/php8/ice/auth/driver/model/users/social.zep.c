
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
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * Model user's social auth.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users_Social) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model\\Users, Social, ice, auth_driver_model_users_social, ice_mvc_model_ce, ice_auth_driver_model_users_social_method_entry, 0);

	zend_declare_property_string(ice_auth_driver_model_users_social_ce, SL("from"), "user_social", ZEND_ACC_PROTECTED);

	/**
	 * User class name.
	 */
	zend_declare_property_string(ice_auth_driver_model_users_social_ce, SL("userClass"), "Ice\\Auth\\Driver\\Model\\Users", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Initialize relations.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Social, initialize) {

	zval _5;
	zval auth, _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "auth");
	ZEPHIR_CALL_METHOD(&auth, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("userClass"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "users");
	ZEPHIR_CALL_METHOD(&_2, &auth, "getoption", NULL, 0, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	add_assoc_stringl_ex(&_5, SL("alias"), SL("User"));
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "user_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasone", NULL, 0, &_1, &_2, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set PRIMARY key.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Social, onConstruct) {

	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "social_id");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "type");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprimary", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

