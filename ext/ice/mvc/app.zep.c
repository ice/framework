
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * This component allows to create MVC applications.
 *
 * @package     Ice/Mvc
 * @category    Application
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_App) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, App, ice, mvc_app, ice_di_access_ce, ice_mvc_app_method_entry, 0);

	zend_declare_property_bool(ice_mvc_app_ce, SL("_autoRender"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_app_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_App, getAutoRender) {


	RETURN_MEMBER(this_ptr, "_autoRender");

}

PHP_METHOD(Ice_Mvc_App, setAutoRender) {

	zval *autoRender;

	zephir_fetch_params(0, 1, 0, &autoRender);



	zephir_update_property_this(this_ptr, SL("_autoRender"), autoRender TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_App, getModules) {


	RETURN_MEMBER(this_ptr, "_modules");

}

PHP_METHOD(Ice_Mvc_App, setModules) {

	zval *modules;

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_this(this_ptr, SL("_modules"), modules TSRMLS_CC);

}

/**
 * Handles a MVC request.
 *
 * @param string method
 * @param string uri
 * @return ResponseInterface|boolean
 */
PHP_METHOD(Ice_Mvc_App, handle) {

	zval *_10, *_18 = NULL;
	zend_bool _4, _5, _16, _19;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, *uri = NULL, *argv, *router = NULL, *request = NULL, *response = NULL, *dispatcher = NULL, *returned = NULL, *controller = NULL, *view = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_SERVER, *_6, *_7 = NULL, *_8, *_9, *_11, *_12, *_13, *_14, *_15, *_17, *_20, *_21, *_22, *_23 = NULL, *_24 = NULL, *_25 = NULL, *_26 = NULL, *_27;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 0, 2, &method, &uri);

	if (!method) {
		ZEPHIR_CPY_WRT(method, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(method);
	}
	if (!uri) {
		ZEPHIR_CPY_WRT(uri, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(&request, _0, "get", NULL, 0, _1, _2, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (Z_TYPE_P(method) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&method, request, "getmethod", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(uri) == IS_NULL) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "_url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&uri, request, "get", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	_4 = !zephir_is_true(method);
	if (_4) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_GET_CONSTANT(_1, "PHP_SAPI");
		_4 = ZEPHIR_IS_STRING_IDENTICAL(_1, "cli");
	}
	if (_4) {
		ZEPHIR_INIT_NVAR(method);
		ZVAL_STRING(method, "GET", 1);
		ZEPHIR_OBS_VAR(argv);
		zephir_array_fetch_string(&argv, _SERVER, SL("argv"), PH_NOISY, "ice/mvc/app.zep", 45 TSRMLS_CC);
		_5 = !zephir_is_true(uri);
		if (_5) {
			_5 = zephir_array_isset_long(argv, 1);
		}
		if (_5) {
			ZEPHIR_OBS_NVAR(uri);
			zephir_array_fetch_long(&uri, argv, 1, PH_NOISY, "ice/mvc/app.zep", 48 TSRMLS_CC);
		}
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_NULL(_3);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_BOOL(_7, 1);
	ZEPHIR_CALL_METHOD(&router, _6, "get", NULL, 0, _2, _3, _7);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, router, "handle", NULL, 0, method, uri);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_NULL(_3);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_BOOL(_7, 1);
	ZEPHIR_CALL_METHOD(&dispatcher, _8, "get", NULL, 0, _2, _3, _7);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_10);
	zephir_create_array(_10, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_10, response);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "app.after.router.handle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _9, "applyhook", NULL, 0, _2, _10);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_5 = Z_TYPE_P(response) == IS_OBJECT;
	if (_5) {
		_5 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
	}
	if (!(_5)) {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodules", NULL, 0, _11);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmethod", NULL, 0, method);
		zephir_check_call_status();
		zephir_array_fetch_string(&_12, response, SL("module"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 61 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodule", NULL, 0, _12);
		zephir_check_call_status();
		zephir_array_fetch_string(&_13, response, SL("handler"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 62 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "sethandler", NULL, 0, _13);
		zephir_check_call_status();
		zephir_array_fetch_string(&_14, response, SL("action"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 63 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setaction", NULL, 0, _14);
		zephir_check_call_status();
		zephir_array_fetch_string(&_15, response, SL("params"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 64 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, 0, _15);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&response, dispatcher, "dispatch", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&returned, dispatcher, "getreturnedvalue", NULL, 0);
		zephir_check_call_status();
		_16 = Z_TYPE_P(returned) == IS_OBJECT;
		if (_16) {
			_16 = (zephir_instance_of_ev(returned, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (_16) {
			ZEPHIR_CPY_WRT(response, returned);
		}
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_18);
		zephir_create_array(_18, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_18, response);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "app.after.dispatcher.dispatch", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _17, "applyhook", NULL, 0, _2, _18);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		_19 = Z_TYPE_P(response) == IS_OBJECT;
		if (_19) {
			_19 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (!(_19)) {
			ZEPHIR_CPY_WRT(controller, response);
			_20 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "response", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_NULL(_3);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_BOOL(_7, 1);
			ZEPHIR_CALL_METHOD(&response, _20, "get", NULL, 0, _2, _3, _7);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(_21);
			zephir_read_property(&_21, controller, SL("view"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(view, _21);
			_22 = zephir_fetch_nproperty_this(this_ptr, SL("_autoRender"), PH_NOISY_CC);
			if (zephir_is_true(_22)) {
				ZEPHIR_CALL_METHOD(&_23, view, "getcontent", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(_23) == IS_NULL) {
					ZEPHIR_CALL_METHOD(&_24, view, "getfile", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(_24))) {
						ZEPHIR_INIT_NVAR(_2);
						ZVAL_BOOL(_2, 1);
						ZEPHIR_CALL_METHOD(NULL, view, "setsilent", NULL, 0, _2);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_25, dispatcher, "gethandler", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_26, dispatcher, "getaction", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_VAR(_27);
						ZEPHIR_CONCAT_VSV(_27, _25, "/", _26);
						ZEPHIR_CALL_METHOD(NULL, view, "setfile", NULL, 0, _27);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_25, view, "count", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(_25))) {
						ZEPHIR_CALL_METHOD(&_26, dispatcher, "getparams", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, view, "replace", NULL, 0, _26);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_25, view, "render", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, view, "setcontent", NULL, 0, _25);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_26, view, "getmainview", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_24, view, "layout", NULL, 0, _26);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 0, _24);
				zephir_check_call_status();
			}
		}
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_18);
	zephir_create_array(_18, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_18, response);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "app.after.handle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _11, "applyhook", NULL, 0, _2, _18);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(response, "send", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

