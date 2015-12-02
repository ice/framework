
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
 * Model user's social auth.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users_Social) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model\\Users, Social, ice, auth_driver_model_users_social, ice_mvc_model_ce, ice_auth_driver_model_users_social_method_entry, 0);

	zend_declare_property_string(ice_auth_driver_model_users_social_ce, SL("from"), "user_social", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Initialize relations.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Social, initialize) {

	zval _7;
	zval auth, _0, _1, _2, _3, _4, _5, _6;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "auth");
	ZVAL_NULL(&_2);
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(&auth, &_0, "get", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "users");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "Ice\\Auth\\Driver\\Model\\Users");
	ZEPHIR_CALL_METHOD(&_4, &auth, "getoption", NULL, 0, &_1, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_7, SL("alias"), SL("User"));
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "user_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasone", NULL, 0, &_1, &_4, &_6, &_7);
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
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
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

