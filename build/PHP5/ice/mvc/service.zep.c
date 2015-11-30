
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


/**
 * Service is intermediary between Model and Controller.
 *
 * @package     Ice/Mvc
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Service) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, Service, ice, mvc_service, ice_di_access_ce, ice_mvc_service_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(ice_mvc_service_ce, SL("model"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Service, setModel) {

	zval *model;

	zephir_fetch_params(0, 1, 0, &model);



	zephir_update_property_this(this_ptr, SL("model"), model TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Service, getModel) {

	

	RETURN_MEMBER(this_ptr, "model");

}

/**
 * Controller constructor. Run onConstruct() if method exist.
 */
PHP_METHOD(Ice_Mvc_Service, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, ice_mvc_service_ce, this_ptr, "__construct", &_0, 29);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic method to call model's method.
 *
 * @param string method
 * @param mixed arguments
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_Service, __call) {

	zval *_3$$3;
	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, *_0, *_2, *_4$$3;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("model"), PH_NOISY_CC);
	_1 = Z_TYPE_P(_0) == IS_OBJECT;
	if (_1) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property_this(&_2, this_ptr, SL("model"), PH_NOISY_CC);
		_1 = zephir_instance_of_ev(_2, ice_mvc_model_ce TSRMLS_CC);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_create_array(_3$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_4$$3);
		zephir_read_property_this(&_4$$3, this_ptr, SL("model"), PH_NOISY_CC);
		zephir_array_fast_append(_3$$3, _4$$3);
		zephir_array_fast_append(_3$$3, method);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _3$$3, arguments);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The `model` property must be instance of Model", "ice/mvc/service.zep", 45);
		return;
	}

}

