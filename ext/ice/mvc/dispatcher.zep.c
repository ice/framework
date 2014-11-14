
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


ZEPHIR_INIT_CLASS(Ice_Mvc_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, Dispatcher, ice, mvc_dispatcher, ice_dispatcher_ce, ice_mvc_dispatcher_method_entry, 0);

	zend_declare_property_null(ice_mvc_dispatcher_ce, SL("_method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_dispatcher_ce, SL("_handlerSuffix"), "Controller", ZEND_ACC_PROTECTED TSRMLS_CC);

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

PHP_METHOD(Ice_Mvc_Dispatcher, getActiveMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zval *action, *_0, *_1, *_2, *_3 = NULL, *_5, *_6;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_method"), PH_NOISY_CC);
	zephir_fast_strtolower(_0, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_action"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "ucfirst", &_4, _2);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_actionSuffix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(action);
	ZEPHIR_CONCAT_VVV(action, _0, _3, _5);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_activeHandler"), PH_NOISY_CC);
	if ((zephir_method_exists(_6, action TSRMLS_CC)  == SUCCESS)) {
		RETURN_CCTOR(action);
	}
	ZEPHIR_RETURN_CALL_PARENT(ice_mvc_dispatcher_ce, this_ptr, "getactivemethod", &_7);
	zephir_check_call_status();
	RETURN_MM();

}

