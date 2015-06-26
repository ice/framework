
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
#include "kernel/operators.h"


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

	zend_declare_property_null(ice_mvc_dispatcher_ce, SL("_method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_dispatcher_ce, SL("_handlerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_mvc_dispatcher_ce->create_object = zephir_init_properties;
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Dispatcher, getMethod) {


	RETURN_MEMBER(this_ptr, "_method");

}

PHP_METHOD(Ice_Mvc_Dispatcher, setMethod) {

	zval *method;

	zephir_fetch_params(0, 1, 0, &method);



	zephir_update_property_this(this_ptr, SL("_method"), method TSRMLS_CC);

}

/**
 * Get active method, first check whether a method with the HTTP method as prefix exist.
 *
 * @return string
 */
PHP_METHOD(Ice_Mvc_Dispatcher, getActiveMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *action, *_0, *_1, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_method"), PH_NOISY_CC);
	zephir_fast_strtolower(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_action"), PH_NOISY_CC);
	zephir_ucfirst(_2, _3);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(action);
	ZEPHIR_CONCAT_VVV(action, _0, _2, _4);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_activeHandler"), PH_NOISY_CC);
	if ((zephir_method_exists(_5, action TSRMLS_CC)  == SUCCESS)) {
		RETURN_CCTOR(action);
	}
	ZEPHIR_RETURN_CALL_PARENT(ice_mvc_dispatcher_ce, this_ptr, "getactivemethod", &_6, 112);
	zephir_check_call_status();
	RETURN_MM();

}

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_params"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_modules"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

