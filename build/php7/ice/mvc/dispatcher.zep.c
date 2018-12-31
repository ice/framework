
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
#include "kernel/exception.h"


/**
 * Dispatching is the process of taking the request object, extracting the module name, controller name, action name,
 * and optional parameters contained in it, and then instantiating a controller and calling an action on it.
 *
 * @package     Ice/Dispatcher
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, Dispatcher, ice, mvc_dispatcher, ice_dispatcher_ce, ice_mvc_dispatcher_method_entry, 0);

	zend_declare_property_null(ice_mvc_dispatcher_ce, SL("method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_dispatcher_ce, SL("handlers"), "Controllers", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_dispatcher_ce, SL("handlerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_long(ice_mvc_dispatcher_ce, SL("REDIRECT_CYCLIC"), 5);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Dispatcher, getMethod) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "method");

}

PHP_METHOD(Ice_Mvc_Dispatcher, setMethod) {

	zval *method, method_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);

	zephir_fetch_params(0, 1, 0, &method);



	zephir_update_property_zval(this_ptr, SL("method"), method);
	RETURN_THISW();

}

/**
 * Get active method, first check whether a method with the HTTP method as prefix exist.
 *
 * @return string
 */
PHP_METHOD(Ice_Mvc_Dispatcher, getActiveMethod) {

	zval action, _0, _1, _2, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *this_ptr = getThis();

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
		RETURN_CCTOR(&action);
	}
	ZEPHIR_RETURN_CALL_PARENT(ice_mvc_dispatcher_ce, getThis(), "getactivemethod", &_6, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Mvc_Dispatcher, dispatch) {

	zval parent, response, _1, _2, _3, _4, _5$$3, _8$$3, _9$$3, _10$$3, _6$$4, _7$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parent);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(&parent, ice_mvc_dispatcher_ce, getThis(), "dispatch", &_0, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "response");
	ZEPHIR_CALL_METHOD(&response, &_1, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &response, "getredirects", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &response, "getloops", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_GT(&_3, &_4)) {
		zephir_read_property(&_5$$3, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_5$$3)) {
			ZVAL_LONG(&_6$$4, 310);
			ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", NULL, 0, &_6$$4);
			zephir_check_call_status();
			ZVAL_LONG(&_6$$4, 310);
			ZEPHIR_CALL_METHOD(&_7$$4, &response, "getmessage", NULL, 0, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &response, "setbody", NULL, 0, &_7$$4);
			zephir_check_call_status();
			RETURN_CCTOR(&response);
		}
		ZEPHIR_INIT_VAR(&_8$$3);
		object_init_ex(&_8$$3, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "This Webpage has a redirect loop");
		ZVAL_LONG(&_10$$3, 5);
		ZEPHIR_CALL_METHOD(NULL, &_8$$3, "__construct", NULL, 12, &_9$$3, &_10$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$3, "ice/mvc/dispatcher.zep", 59 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&parent);

}

