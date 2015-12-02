
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

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "autoRender");

}

PHP_METHOD(Ice_Mvc_App, setAutoRender) {

	zval *autoRender, autoRender_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&autoRender_sub);

	zephir_fetch_params(0, 1, 0, &autoRender);



	zephir_update_property_zval(this_ptr, SL("autoRender"), autoRender);

}

PHP_METHOD(Ice_Mvc_App, getModules) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "modules");

}

PHP_METHOD(Ice_Mvc_App, setModules) {

	zval *modules, modules_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&modules_sub);

	zephir_fetch_params(0, 1, 0, &modules);



	zephir_update_property_zval(this_ptr, SL("modules"), modules);

}

/**
 * App constructor
 *
 * @param Di $di
 */
PHP_METHOD(Ice_Mvc_App, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *di = NULL, di_sub, __$null, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&di_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &di);

	if (!di) {
		di = &di_sub;
		di = &__$null;
	}


	ZEPHIR_CALL_PARENT(NULL, ice_mvc_app_ce, this_ptr, "__construct", &_0, 29, di);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "app");
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_2, this_ptr);
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

	zval _10, _37, _19$$7;
	zend_bool _5, _11, _6$$5, _17$$7, _21$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, method_sub, *uri = NULL, uri_sub, _SERVER, __$null, argv, router, request, response, dispatcher, returned, controller, view, _0, _1, _2, _3, _7, _8, _9, _4$$4, _12$$7, _13$$7, _14$$7, _15$$7, _16$$7, _18$$7, _20$$7, _22$$9, _23$$9, _24$$9, _25$$9, _26$$10, _35$$10, _36$$10, _27$$11, _32$$11, _34$$11, _28$$12, _29$$12, _30$$12, _31$$12, _33$$13;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&argv);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&returned);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_34$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_19$$7);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 2, &method, &uri);

	if (!method) {
		method = &method_sub;
		ZEPHIR_CPY_WRT(method, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(method);
	}
	if (!uri) {
		uri = &uri_sub;
		ZEPHIR_CPY_WRT(uri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}


	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZVAL_NULL(&_2);
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(&request, &_0, "get", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(method) == IS_NULL) {
		ZEPHIR_CALL_METHOD(method, &request, "getmethod", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(uri) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "_url");
		ZEPHIR_CALL_METHOD(uri, &request, "get", NULL, 0, &_4$$4);
		zephir_check_call_status();
	}
	_5 = !zephir_is_true(method);
	if (_5) {
		ZEPHIR_INIT_NVAR(&_1);
		ZEPHIR_GET_CONSTANT(&_1, "PHP_SAPI");
		_5 = ZEPHIR_IS_STRING_IDENTICAL(&_1, "cli");
	}
	if (_5) {
		ZEPHIR_INIT_NVAR(method);
		ZVAL_STRING(method, "GET");
		ZEPHIR_OBS_VAR(&argv);
		zephir_array_fetch_string(&argv, &_SERVER, SL("argv"), PH_NOISY, "ice/mvc/app.zep", 60 TSRMLS_CC);
		_6$$5 = !zephir_is_true(uri);
		if (_6$$5) {
			_6$$5 = zephir_array_isset_long(&argv, 1);
		}
		if (_6$$5) {
			ZEPHIR_OBS_NVAR(uri);
			zephir_array_fetch_long(uri, &argv, 1, PH_NOISY, "ice/mvc/app.zep", 63 TSRMLS_CC);
		}
	}
	zephir_read_property(&_2, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "router");
	ZVAL_NULL(&_3);
	ZVAL_BOOL(&_8, 1);
	ZEPHIR_CALL_METHOD(&router, &_2, "get", NULL, 0, &_7, &_3, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &router, "handle", NULL, 0, method, uri);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "dispatcher");
	ZVAL_NULL(&_8);
	ZVAL_BOOL(&_9, 1);
	ZEPHIR_CALL_METHOD(&dispatcher, &_3, "get", NULL, 0, &_7, &_8, &_9);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_10, &response);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "app.after.router.handle");
	ZEPHIR_CALL_METHOD(NULL, &_8, "applyhook", NULL, 0, &_7, &_10);
	zephir_check_call_status();
	_11 = Z_TYPE_P(&response) == IS_OBJECT;
	if (_11) {
		_11 = (zephir_instance_of_ev(&response, ice_http_response_responseinterface_ce TSRMLS_CC));
	}
	if (!(_11)) {
		zephir_read_property(&_12$$7, this_ptr, SL("modules"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodules", NULL, 0, &_12$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmethod", NULL, 0, method);
		zephir_check_call_status();
		zephir_array_fetch_string(&_13$$7, &response, SL("module"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 76 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setmodule", NULL, 0, &_13$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_14$$7, &response, SL("handler"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 77 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "sethandler", NULL, 0, &_14$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_15$$7, &response, SL("action"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 78 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setaction", NULL, 0, &_15$$7);
		zephir_check_call_status();
		zephir_array_fetch_string(&_16$$7, &response, SL("params"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 79 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &dispatcher, "setparams", NULL, 0, &_16$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&response, &dispatcher, "dispatch", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&returned, &dispatcher, "getreturnedvalue", NULL, 0);
		zephir_check_call_status();
		_17$$7 = Z_TYPE_P(&returned) == IS_OBJECT;
		if (_17$$7) {
			_17$$7 = (zephir_instance_of_ev(&returned, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (_17$$7) {
			ZEPHIR_CPY_WRT(&response, &returned);
		}
		zephir_read_property(&_18$$7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_19$$7);
		zephir_create_array(&_19$$7, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_19$$7, &response);
		ZEPHIR_INIT_VAR(&_20$$7);
		ZVAL_STRING(&_20$$7, "app.after.dispatcher.dispatch");
		ZEPHIR_CALL_METHOD(NULL, &_18$$7, "applyhook", NULL, 0, &_20$$7, &_19$$7);
		zephir_check_call_status();
		_21$$7 = Z_TYPE_P(&response) == IS_OBJECT;
		if (_21$$7) {
			_21$$7 = (zephir_instance_of_ev(&response, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (!(_21$$7)) {
			ZEPHIR_CPY_WRT(&controller, &response);
			zephir_read_property(&_22$$9, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_23$$9);
			ZVAL_STRING(&_23$$9, "response");
			ZVAL_NULL(&_24$$9);
			ZVAL_BOOL(&_25$$9, 1);
			ZEPHIR_CALL_METHOD(&response, &_22$$9, "get", NULL, 0, &_23$$9, &_24$$9, &_25$$9);
			zephir_check_call_status();
			zephir_read_property(&_24$$9, &controller, SL("view"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&view, &_24$$9);
			zephir_read_property(&_24$$9, this_ptr, SL("autoRender"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_24$$9)) {
				ZEPHIR_CALL_METHOD(&_26$$10, &view, "getcontent", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&_26$$10) == IS_NULL) {
					ZEPHIR_CALL_METHOD(&_27$$11, &view, "getfile", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_27$$11))) {
						ZVAL_BOOL(&_28$$12, 1);
						ZEPHIR_CALL_METHOD(NULL, &view, "setsilent", NULL, 0, &_28$$12);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_29$$12, &dispatcher, "gethandler", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_30$$12, &dispatcher, "getaction", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_VAR(&_31$$12);
						ZEPHIR_CONCAT_VSV(&_31$$12, &_29$$12, "/", &_30$$12);
						ZEPHIR_CALL_METHOD(NULL, &view, "setfile", NULL, 0, &_31$$12);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_32$$11, &view, "count", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_32$$11))) {
						ZEPHIR_CALL_METHOD(&_33$$13, &dispatcher, "getparams", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &view, "replace", NULL, 0, &_33$$13);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_34$$11, &view, "render", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &view, "setcontent", NULL, 0, &_34$$11);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_36$$10, &view, "getmainview", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_35$$10, &view, "layout", NULL, 0, &_36$$10);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", NULL, 0, &_35$$10);
				zephir_check_call_status();
			}
		}
	}
	zephir_read_property(&_9, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_37);
	zephir_create_array(&_37, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_37, &response);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "app.after.handle");
	ZEPHIR_CALL_METHOD(NULL, &_9, "applyhook", NULL, 0, &_7, &_37);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&response, "send", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

