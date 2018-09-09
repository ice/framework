
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_App) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, App, ice, mvc_app, ice_di_access_ce, ice_mvc_app_method_entry, 0);

	zend_declare_property_bool(ice_mvc_app_ce, SL("autoRender"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_app_ce, SL("modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_App, getAutoRender) {

	

	RETURN_MEMBER(getThis(), "autoRender");

}

PHP_METHOD(Ice_Mvc_App, setAutoRender) {

	zval *autoRender;

	zephir_fetch_params(0, 1, 0, &autoRender);



	zephir_update_property_this(getThis(), SL("autoRender"), autoRender TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_App, getModules) {

	

	RETURN_MEMBER(getThis(), "modules");

}

PHP_METHOD(Ice_Mvc_App, setModules) {

	zval *modules;

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_this(getThis(), SL("modules"), modules TSRMLS_CC);
	RETURN_THISW();

}

/**
 * App constructor
 *
 * @param Di $di
 */
PHP_METHOD(Ice_Mvc_App, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &di);

	if (!di) {
		di = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(getThis(), SL("di"), di TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "app", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, _1, this_ptr);
	zephir_check_temp_parameter(_1);
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

	zval *_9, *_41, *_18$$7;
	zend_bool _3, _10, _4$$5, _16$$7, _20$$7, _25$$9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, *uri = NULL, *_SERVER, *argv = NULL, *router = NULL, *request = NULL, *response = NULL, *dispatcher = NULL, *returned = NULL, *controller = NULL, *view = NULL, *_0, *_1 = NULL, *_5, *_6 = NULL, *_7, *_8, *_40, *_2$$4, *_11$$7, *_12$$7, *_13$$7, *_14$$7, *_15$$7, *_17$$7, *_19$$7, *_21$$9, *_22$$9, *_23$$9, *_24$$9, *_26$$9 = NULL, *_27$$10 = NULL, *_36$$10 = NULL, *_28$$11 = NULL, *_33$$11 = NULL, *_35$$11 = NULL, *_29$$12, *_30$$12 = NULL, *_31$$12 = NULL, *_32$$12, *_34$$13 = NULL, *_37$$14 = NULL, *_38$$14 = NULL, *_39$$15 = NULL;

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
	ZEPHIR_CALL_METHOD(&request, _0, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (Z_TYPE_P(method) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&method, request, "getmethod", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(uri) == IS_NULL) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "_url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&uri, request, "get", NULL, 0, _2$$4);
		zephir_check_temp_parameter(_2$$4);
		zephir_check_call_status();
	}
	_3 = !zephir_is_true(method);
	if (_3) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_GET_CONSTANT(_1, "PHP_SAPI");
		_3 = ZEPHIR_IS_STRING_IDENTICAL(_1, "cli");
	}
	if (_3) {
		ZEPHIR_INIT_NVAR(method);
		ZVAL_STRING(method, "GET", 1);
		ZEPHIR_OBS_VAR(argv);
		zephir_array_fetch_string(&argv, _SERVER, SL("argv"), PH_NOISY, "ice/mvc/app.zep", 60 TSRMLS_CC);
		_4$$5 = !zephir_is_true(uri);
		if (_4$$5) {
			_4$$5 = zephir_array_isset_long(argv, 1);
		}
		if (_4$$5) {
			ZEPHIR_OBS_NVAR(uri);
			zephir_array_fetch_long(&uri, argv, 1, PH_NOISY, "ice/mvc/app.zep", 63 TSRMLS_CC);
		}
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&router, _5, "get", NULL, 0, _6);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, router, "handle", NULL, 0, method, uri);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&dispatcher, _7, "get", NULL, 0, _6);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_9);
	zephir_create_array(_9, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_9, response);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "app.after.router.handle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _8, "applyhook", NULL, 0, _6, _9);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	_10 = Z_TYPE_P(response) == IS_OBJECT;
	if (_10) {
		_10 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
	}
	if (!(_10)) {
		_11$$7 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodules", NULL, 0, _11$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmethod", NULL, 0, method);
		zephir_check_call_status();
		zephir_array_fetch_string(&_12$$7, response, SL("module"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 76 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodule", NULL, 0, _12$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_13$$7, response, SL("handler"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 77 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "sethandler", NULL, 0, _13$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_14$$7, response, SL("action"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 78 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setaction", NULL, 0, _14$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_15$$7, response, SL("params"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 79 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, 0, _15$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&response, dispatcher, "dispatch", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&returned, dispatcher, "getreturnedvalue", NULL, 0);
		zephir_check_call_status();
		_16$$7 = Z_TYPE_P(returned) == IS_OBJECT;
		if (_16$$7) {
			_16$$7 = (zephir_instance_of_ev(returned, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (_16$$7) {
			ZEPHIR_CPY_WRT(response, returned);
		}
		_17$$7 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_18$$7);
		zephir_create_array(_18$$7, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_18$$7, response);
		ZEPHIR_INIT_VAR(_19$$7);
		ZVAL_STRING(_19$$7, "app.after.dispatcher.dispatch", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _17$$7, "applyhook", NULL, 0, _19$$7, _18$$7);
		zephir_check_temp_parameter(_19$$7);
		zephir_check_call_status();
		_20$$7 = Z_TYPE_P(response) == IS_OBJECT;
		if (_20$$7) {
			_20$$7 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (!(_20$$7)) {
			ZEPHIR_CPY_WRT(controller, response);
			_21$$9 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_22$$9);
			ZVAL_STRING(_22$$9, "response", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&response, _21$$9, "get", NULL, 0, _22$$9);
			zephir_check_temp_parameter(_22$$9);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(_23$$9);
			zephir_read_property(&_23$$9, controller, SL("view"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(view, _23$$9);
			_24$$9 = zephir_fetch_nproperty_this(this_ptr, SL("autoRender"), PH_NOISY_CC);
			_25$$9 = zephir_is_true(_24$$9);
			if (_25$$9) {
				ZEPHIR_CALL_METHOD(&_26$$9, response, "getbody", NULL, 0);
				zephir_check_call_status();
				_25$$9 = Z_TYPE_P(_26$$9) == IS_NULL;
			}
			if (_25$$9) {
				ZEPHIR_CALL_METHOD(&_27$$10, view, "getcontent", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(_27$$10) == IS_NULL) {
					ZEPHIR_CALL_METHOD(&_28$$11, view, "getfile", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(_28$$11))) {
						ZEPHIR_INIT_VAR(_29$$12);
						ZVAL_BOOL(_29$$12, 1);
						ZEPHIR_CALL_METHOD(NULL, view, "setsilent", NULL, 0, _29$$12);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_30$$12, dispatcher, "gethandler", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_31$$12, dispatcher, "getaction", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_VAR(_32$$12);
						ZEPHIR_CONCAT_VSV(_32$$12, _30$$12, "/", _31$$12);
						ZEPHIR_CALL_METHOD(NULL, view, "setfile", NULL, 0, _32$$12);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_33$$11, view, "count", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(_33$$11))) {
						ZEPHIR_CALL_METHOD(&_34$$13, dispatcher, "getparams", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, view, "replace", NULL, 0, _34$$13);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_35$$11, view, "render", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, view, "setcontent", NULL, 0, _35$$11);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_36$$10, view, "getmainview", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(_36$$10)) {
					ZEPHIR_CALL_METHOD(&_38$$14, view, "getmainview", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_37$$14, view, "layout", NULL, 0, _38$$14);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 0, _37$$14);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(&_39$$15, view, "getcontent", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 0, _39$$15);
					zephir_check_call_status();
				}
			}
		}
	}
	_40 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_41);
	zephir_create_array(_41, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_41, response);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "app.after.handle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _40, "applyhook", NULL, 0, _6, _41);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(response, "send", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add module with its dir path, initial class name and namespace
 *
 * @param string name
 * @param array options The keys can be [path|class|namespace]
 * @return object App
 */
PHP_METHOD(Ice_Mvc_App, addModule) {

	zval *options = NULL;
	zval *name_param = NULL, *options_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &options_param);

	zephir_get_strval(name, name_param);
	zephir_get_arrval(options, options_param);


	zephir_update_property_array(this_ptr, SL("modules"), name, options TSRMLS_CC);
	RETURN_THIS();

}

