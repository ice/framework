
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
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * Model Roles.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Roles) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model, Roles, ice, auth_driver_model_roles, ice_mvc_model_ce, ice_auth_driver_model_roles_method_entry, 0);

	/**
	 * User class name.
	 */
	zend_declare_property_string(ice_auth_driver_model_roles_ce, SL("userClass"), "Ice\\Auth\\Driver\\Model\\Roles\\Users", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Initialize role's relations.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Roles, initialize) {

	zval _2;
	zval _0, _1, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("userClass"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_2, SL("alias"), SL("RolesUsers"));
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "role_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, 0, &_0, &_1, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

