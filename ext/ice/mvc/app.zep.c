
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
 * Handles a MVC request
 *
 * @param string method
 * @param string uri
 * @return ResponseInterface
 */
PHP_METHOD(Ice_Mvc_App, handle) {

	zend_bool _6, _14;
	zval *_5, *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, *uri = NULL, *router = NULL, *request = NULL, *response = NULL, *dispatcher = NULL, *controller = NULL, *view = NULL, *_0, *_1 = NULL, *_2, *_3, *_4, *_7, *_8, *_9, *_10, *_11, *_12, *_15, *_16, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_21, *_22;

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
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&router, _2, "getrouter", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, router, "handle", NULL, method, uri);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&dispatcher, _3, "getdispatcher", NULL);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	array_init_size(_5, 2);
	zephir_array_fast_append(_5, response);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "app.after.router.handle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _4, "applyhook", NULL, _1, _5);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_6 = Z_TYPE_P(response) == IS_OBJECT;
	if (_6) {
		_6 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
	}
	if (!(_6)) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_modules"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodules", NULL, _7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmethod", NULL, method);
		zephir_check_call_status();
		zephir_array_fetch_string(&_8, response, SL("module"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 42 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodule", NULL, _8);
		zephir_check_call_status();
		zephir_array_fetch_string(&_9, response, SL("handler"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 43 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "sethandler", NULL, _9);
		zephir_check_call_status();
		zephir_array_fetch_string(&_10, response, SL("action"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 44 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setaction", NULL, _10);
		zephir_check_call_status();
		zephir_array_fetch_string(&_11, response, SL("params"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 45 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, _11);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&response, dispatcher, "dispatch", NULL);
		zephir_check_call_status();
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_13);
		array_init_size(_13, 2);
		zephir_array_fast_append(_13, response);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "app.after.dispatcher.dispatch", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _12, "applyhook", NULL, _1, _13);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_14 = Z_TYPE_P(response) == IS_OBJECT;
		if (_14) {
			_14 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (!(_14)) {
			ZEPHIR_CPY_WRT(controller, response);
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&response, _15, "getresponse", NULL);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(_16);
			zephir_read_property(&_16, controller, SL("view"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(view, _16);
			ZEPHIR_CALL_METHOD(&_17, view, "getcontent", NULL);
			zephir_check_call_status();
			if (Z_TYPE_P(_17) == IS_NULL) {
				ZEPHIR_CALL_METHOD(&_18, view, "getfile", NULL);
				zephir_check_call_status();
				if (!(zephir_is_true(_18))) {
					ZEPHIR_INIT_NVAR(_1);
					ZVAL_BOOL(_1, 1);
					ZEPHIR_CALL_METHOD(NULL, view, "setsilent", NULL, _1);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_19, dispatcher, "gethandler", NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_20, dispatcher, "getaction", NULL);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(_21);
					ZEPHIR_CONCAT_VSV(_21, _19, "/", _20);
					ZEPHIR_CALL_METHOD(NULL, view, "setfile", NULL, _21);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_19, view, "count", NULL);
				zephir_check_call_status();
				if (!(zephir_is_true(_19))) {
					ZEPHIR_CALL_METHOD(&_20, dispatcher, "getparams", NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, view, "replace", NULL, _20);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_19, view, "render", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, view, "setcontent", NULL, _19);
				zephir_check_call_status();
			}
			_22 = zephir_fetch_nproperty_this(this_ptr, SL("_autoRender"), PH_NOISY_CC);
			if (zephir_is_true(_22)) {
				ZEPHIR_CALL_METHOD(&_20, view, "getmainview", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_18, view, "layout", NULL, _20);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, _18);
				zephir_check_call_status();
			}
		}
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_13);
	array_init_size(_13, 2);
	zephir_array_fast_append(_13, response);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "app.after.handle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _7, "applyhook", NULL, _1, _13);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(response, "send", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

