
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"


/**
 * Dispatching is the process of taking the request object, extracting the module name, controller name, action name,
 * and optional parameters contained in it, and then instantiating a controller and calling an action on it.
 *
 * @package     Ice/Dispatcher
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, Dispatcher, ice, mvc_dispatcher, ice_dispatcher_ce, ice_mvc_dispatcher_method_entry, 0);

	zend_declare_property_null(ice_mvc_dispatcher_ce, SL("method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_dispatcher_ce, SL("handlerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Dispatcher, getMethod) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "method");

}

PHP_METHOD(Ice_Mvc_Dispatcher, setMethod) {

	zval *method, method_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&method_sub);

	zephir_fetch_params(0, 1, 0, &method);



	zephir_update_property_zval(this_ptr, SL("method"), method);

}

/**
 * Get active method, first check whether a method with the HTTP method as prefix exist.
 *
 * @return string
 */
PHP_METHOD(Ice_Mvc_Dispatcher, getActiveMethod) {

	zval action, _0, _1, _2, _3, _4, _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("method"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_strtolower(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_read_property(&_3, this_ptr, SL("action"), PH_NOISY_CC | PH_READONLY);
	zephir_ucfirst(&_2, &_3);
	zephir_read_property(&_4, this_ptr, SL("actionSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&action);
	ZEPHIR_CONCAT_VVV(&action, &_0, &_2, &_4);
	zephir_read_property(&_5, this_ptr, SL("activeHandler"), PH_NOISY_CC | PH_READONLY);
	if ((zephir_method_exists(&_5, &action TSRMLS_CC)  == SUCCESS)) {
		RETURN_CCTOR(action);
	}
	ZEPHIR_RETURN_CALL_PARENT(ice_mvc_dispatcher_ce, this_ptr, "getactivemethod", &_6, 119);
	zephir_check_call_status();
	RETURN_MM();

}

