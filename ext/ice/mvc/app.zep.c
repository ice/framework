
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

	zend_declare_property_bool(ice_mvc_app_ce, SL("autoRender"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_app_ce, SL("modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_App, getAutoRender) {

	

	RETURN_MEMBER(this_ptr, "autoRender");

}

PHP_METHOD(Ice_Mvc_App, setAutoRender) {

	zval *autoRender;

	zephir_fetch_params(0, 1, 0, &autoRender);



	zephir_update_property_this(this_ptr, SL("autoRender"), autoRender TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_App, getModules) {

	

	RETURN_MEMBER(this_ptr, "modules");

}

PHP_METHOD(Ice_Mvc_App, setModules) {

	zval *modules;

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_this(this_ptr, SL("modules"), modules TSRMLS_CC);

}

/**
 * App constructor
 *
 * @param Di $di
 */
PHP_METHOD(Ice_Mvc_App, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *di = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &di);

	if (!di) {
		di = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_PARENT(NULL, ice_mvc_app_ce, this_ptr, "__construct", &_0, 29, di);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "app", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _1, "set", NULL, 0, _2, this_ptr);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles a MVC request.
 *
 * @param string method
 * @param string uri
 * @return ResponseInterface|boolean
 */
PHP_METHOD(Ice_Mvc_App, handle) {

	zval *_11, *_41, *_20$$7;
	zend_bool _5, _12, _6$$5, _18$$7, _22$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, *uri = NULL, *_SERVER, *argv = NULL, *router = NULL, *request = NULL, *response = NULL, *dispatcher = NULL, *returned = NULL, *controller = NULL, *view = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_7, *_8 = NULL, *_9, *_10, *_40, *_4$$4, *_13$$7, *_14$$7, *_15$$7, *_16$$7, *_17$$7, *_19$$7, *_21$$7, *_23$$9, *_24$$9, *_25$$9, *_26$$9, *_27$$9, *_28$$9, *_29$$10 = NULL, *_38$$10 = NULL, *_39$$10 = NULL, *_30$$11 = NULL, *_35$$11 = NULL, *_37$$11 = NULL, *_31$$12, *_32$$12 = NULL, *_33$$12 = NULL, *_34$$12, *_36$$13 = NULL;

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
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
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_STRING(_4$$4, "_url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&uri, request, "get", NULL, 0, _4$$4);
		zephir_check_temp_parameter(_4$$4);
		zephir_check_call_status();
	}
	_5 = !zephir_is_true(method);
	if (_5) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_GET_CONSTANT(_1, "PHP_SAPI");
		_5 = ZEPHIR_IS_STRING_IDENTICAL(_1, "cli");
	}
	if (_5) {
		ZEPHIR_INIT_NVAR(method);
		ZVAL_STRING(method, "GET", 1);
		ZEPHIR_OBS_VAR(argv);
		zephir_array_fetch_string(&argv, _SERVER, SL("argv"), PH_NOISY, "ice/mvc/app.zep", 60 TSRMLS_CC);
		_6$$5 = !zephir_is_true(uri);
		if (_6$$5) {
			_6$$5 = zephir_array_isset_long(argv, 1);
		}
		if (_6$$5) {
			ZEPHIR_OBS_NVAR(uri);
			zephir_array_fetch_long(&uri, argv, 1, PH_NOISY, "ice/mvc/app.zep", 63 TSRMLS_CC);
		}
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_NULL(_3);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_BOOL(_8, 1);
	ZEPHIR_CALL_METHOD(&router, _7, "get", NULL, 0, _2, _3, _8);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, router, "handle", NULL, 0, method, uri);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_NULL(_3);
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_BOOL(_8, 1);
	ZEPHIR_CALL_METHOD(&dispatcher, _9, "get", NULL, 0, _2, _3, _8);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_11);
	zephir_create_array(_11, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_11, response);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "app.after.router.handle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _10, "applyhook", NULL, 0, _2, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_12 = Z_TYPE_P(response) == IS_OBJECT;
	if (_12) {
		_12 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
	}
	if (!(_12)) {
		_13$$7 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodules", NULL, 0, _13$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmethod", NULL, 0, method);
		zephir_check_call_status();
		zephir_array_fetch_string(&_14$$7, response, SL("module"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 76 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodule", NULL, 0, _14$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_15$$7, response, SL("handler"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 77 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "sethandler", NULL, 0, _15$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_16$$7, response, SL("action"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 78 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setaction", NULL, 0, _16$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_17$$7, response, SL("params"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 79 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, 0, _17$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&response, dispatcher, "dispatch", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&returned, dispatcher, "getreturnedvalue", NULL, 0);
		zephir_check_call_status();
		_18$$7 = Z_TYPE_P(returned) == IS_OBJECT;
		if (_18$$7) {
			_18$$7 = (zephir_instance_of_ev(returned, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (_18$$7) {
			ZEPHIR_CPY_WRT(response, returned);
		}
		_19$$7 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_20$$7);
		zephir_create_array(_20$$7, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_20$$7, response);
		ZEPHIR_INIT_VAR(_21$$7);
		ZVAL_STRING(_21$$7, "app.after.dispatcher.dispatch", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _19$$7, "applyhook", NULL, 0, _21$$7, _20$$7);
		zephir_check_temp_parameter(_21$$7);
		zephir_check_call_status();
		_22$$7 = Z_TYPE_P(response) == IS_OBJECT;
		if (_22$$7) {
			_22$$7 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (!(_22$$7)) {
			ZEPHIR_CPY_WRT(controller, response);
			_23$$9 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_24$$9);
			ZVAL_STRING(_24$$9, "response", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_25$$9);
			ZVAL_NULL(_25$$9);
			ZEPHIR_INIT_VAR(_26$$9);
			ZVAL_BOOL(_26$$9, 1);
			ZEPHIR_CALL_METHOD(&response, _23$$9, "get", NULL, 0, _24$$9, _25$$9, _26$$9);
			zephir_check_temp_parameter(_24$$9);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(_27$$9);
			zephir_read_property(&_27$$9, controller, SL("view"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(view, _27$$9);
			_28$$9 = zephir_fetch_nproperty_this(this_ptr, SL("autoRender"), PH_NOISY_CC);
			if (zephir_is_true(_28$$9)) {
				ZEPHIR_CALL_METHOD(&_29$$10, view, "getcontent", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(_29$$10) == IS_NULL) {
					ZEPHIR_CALL_METHOD(&_30$$11, view, "getfile", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(_30$$11))) {
						ZEPHIR_INIT_VAR(_31$$12);
						ZVAL_BOOL(_31$$12, 1);
						ZEPHIR_CALL_METHOD(NULL, view, "setsilent", NULL, 0, _31$$12);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_32$$12, dispatcher, "gethandler", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_33$$12, dispatcher, "getaction", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_VAR(_34$$12);
						ZEPHIR_CONCAT_VSV(_34$$12, _32$$12, "/", _33$$12);
						ZEPHIR_CALL_METHOD(NULL, view, "setfile", NULL, 0, _34$$12);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_35$$11, view, "count", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(_35$$11))) {
						ZEPHIR_CALL_METHOD(&_36$$13, dispatcher, "getparams", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, view, "replace", NULL, 0, _36$$13);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_37$$11, view, "render", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, view, "setcontent", NULL, 0, _37$$11);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_39$$10, view, "getmainview", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_38$$10, view, "layout", NULL, 0, _39$$10);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 0, _38$$10);
				zephir_check_call_status();
			}
		}
	}
	_40 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_41);
	zephir_create_array(_41, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_41, response);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "app.after.handle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _40, "applyhook", NULL, 0, _2, _41);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(response, "send", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

