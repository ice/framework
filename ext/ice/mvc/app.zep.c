
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

	zval *_7, *_14 = NULL;
	zend_bool _2, _3, _15;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, *uri = NULL, *argv, *router = NULL, *request = NULL, *response = NULL, *dispatcher = NULL, *controller = NULL, *view = NULL, *_0, *_1 = NULL, *_SERVER, *_4, *_5, *_6, *_8, *_9, *_10, *_11, *_12, *_13, *_16, *_17, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_22, *_23;

	ZEPHIR_MM_GROW();
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
	ZEPHIR_CALL_METHOD(&request, _0, "getrequest", NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(method) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&method, request, "getmethod", NULL);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(uri) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "_url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&uri, request, "get", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	_2 = !zephir_is_true(method);
	if (_2) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_GET_CONSTANT(_1, "PHP_SAPI");
		_2 = ZEPHIR_IS_STRING_IDENTICAL(_1, "cli");
	}
	if (_2) {
		ZEPHIR_INIT_NVAR(method);
		ZVAL_STRING(method, "GET", 1);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		ZEPHIR_OBS_VAR(argv);
		zephir_array_fetch_string(&argv, _SERVER, SL("argv"), PH_NOISY, "ice/mvc/app.zep", 45 TSRMLS_CC);
		_3 = !zephir_is_true(uri);
		if (_3) {
			_3 = zephir_array_isset_long(argv, 1);
		}
		if (_3) {
			ZEPHIR_OBS_NVAR(uri);
			zephir_array_fetch_long(&uri, argv, 1, PH_NOISY, "ice/mvc/app.zep", 48 TSRMLS_CC);
		}
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&router, _4, "getrouter", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, router, "handle", NULL, method, uri);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&dispatcher, _5, "getdispatcher", NULL);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	array_init_size(_7, 2);
	zephir_array_fast_append(_7, response);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "app.after.router.handle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _6, "applyhook", NULL, _1, _7);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_3 = Z_TYPE_P(response) == IS_OBJECT;
	if (_3) {
		_3 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
	}
	if (!(_3)) {
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodules", NULL, _8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmethod", NULL, method);
		zephir_check_call_status();
		zephir_array_fetch_string(&_9, response, SL("module"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 61 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodule", NULL, _9);
		zephir_check_call_status();
		zephir_array_fetch_string(&_10, response, SL("handler"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 62 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "sethandler", NULL, _10);
		zephir_check_call_status();
		zephir_array_fetch_string(&_11, response, SL("action"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 63 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setaction", NULL, _11);
		zephir_check_call_status();
		zephir_array_fetch_string(&_12, response, SL("params"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 64 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, _12);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&response, dispatcher, "dispatch", NULL);
		zephir_check_call_status();
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_14);
		array_init_size(_14, 2);
		zephir_array_fast_append(_14, response);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "app.after.dispatcher.dispatch", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _13, "applyhook", NULL, _1, _14);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_15 = Z_TYPE_P(response) == IS_OBJECT;
		if (_15) {
			_15 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (!(_15)) {
			ZEPHIR_CPY_WRT(controller, response);
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&response, _16, "getresponse", NULL);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(_17);
			zephir_read_property(&_17, controller, SL("view"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(view, _17);
			ZEPHIR_CALL_METHOD(&_18, view, "getcontent", NULL);
			zephir_check_call_status();
			if (Z_TYPE_P(_18) == IS_NULL) {
				ZEPHIR_CALL_METHOD(&_19, view, "getfile", NULL);
				zephir_check_call_status();
				if (!(zephir_is_true(_19))) {
					ZEPHIR_INIT_NVAR(_1);
					ZVAL_BOOL(_1, 1);
					ZEPHIR_CALL_METHOD(NULL, view, "setsilent", NULL, _1);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_20, dispatcher, "gethandler", NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_21, dispatcher, "getaction", NULL);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(_22);
					ZEPHIR_CONCAT_VSV(_22, _20, "/", _21);
					ZEPHIR_CALL_METHOD(NULL, view, "setfile", NULL, _22);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_20, view, "count", NULL);
				zephir_check_call_status();
				if (!(zephir_is_true(_20))) {
					ZEPHIR_CALL_METHOD(&_21, dispatcher, "getparams", NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, view, "replace", NULL, _21);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_20, view, "render", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, view, "setcontent", NULL, _20);
				zephir_check_call_status();
			}
			_23 = zephir_fetch_nproperty_this(this_ptr, SL("_autoRender"), PH_NOISY_CC);
			if (zephir_is_true(_23)) {
				ZEPHIR_CALL_METHOD(&_21, view, "getmainview", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_19, view, "layout", NULL, _21);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, _19);
				zephir_check_call_status();
			}
		}
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_14);
	array_init_size(_14, 2);
	zephir_array_fast_append(_14, response);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "app.after.handle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _8, "applyhook", NULL, _1, _14);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(response, "send", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

