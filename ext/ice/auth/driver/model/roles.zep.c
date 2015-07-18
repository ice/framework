
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


/**
 * Model Roles.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Roles) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model, Roles, ice, auth_driver_model_roles, ice_mvc_model_ce, ice_auth_driver_model_roles_method_entry, 0);

	return SUCCESS;

}

/**
 * Initialize role's relations.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Roles, initialize) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("alias"), SL("RolesUsers"), 1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "Ice\\Auth\\Driver\\Model\\Roles\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "role_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "hasmany", NULL, 0, _0, _2, _3, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

