
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
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_App) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, App, ice, mvc_app, ice_di_access_ce, ice_mvc_app_method_entry, 0);

	zend_declare_property_null(ice_mvc_app_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_app_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_App, getDefaultModule) {


	RETURN_MEMBER(this_ptr, "_defaultModule");

}

PHP_METHOD(Ice_Mvc_App, setDefaultModule) {

	zval *defaultModule;

	zephir_fetch_params(0, 1, 0, &defaultModule);



	zephir_update_property_this(this_ptr, SL("_defaultModule"), defaultModule TSRMLS_CC);

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

	zephir_fcall_cache_entry *_8 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	zval *_4 = NULL, *_20;
	zend_bool _3, _21;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, *uri = NULL, *router = NULL, *request = NULL, *response = NULL, *module = NULL, *modules = NULL, *namespace = NULL, *path, *class = NULL, *loader, *dispatcher = NULL, *controller = NULL, *view = NULL, *_0, *_1 = NULL, *_2, _5 = zval_used_for_init, *_6 = NULL, *_9, *_10, *_11 = NULL, *_12, *_13 = NULL, *_14, *_15, *_16, *_17, *_18, *_19, *_22, *_23 = NULL, *_24 = NULL, *_25 = NULL, *_26 = NULL, *_27;

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
	_3 = Z_TYPE_P(response) == IS_OBJECT;
	if (_3) {
		_3 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
	}
	if (!(_3)) {
		ZEPHIR_OBS_VAR(module);
		zephir_array_fetch_string(&module, response, SL("module"), PH_NOISY, "ice/mvc/app.zep", 43 TSRMLS_CC);
		ZEPHIR_OBS_VAR(modules);
		zephir_read_property_this(&modules, this_ptr, SL("_modules"), PH_NOISY_CC);
		if (!(zephir_is_true(modules))) {
			ZEPHIR_INIT_NVAR(modules);
			array_init_size(modules, 2);
			ZEPHIR_INIT_VAR(_4);
			array_init_size(_4, 3);
			add_assoc_stringl_ex(_4, SS("namespace"), SL("App"), 1);
			add_assoc_stringl_ex(_4, SS("path"), SL("../app/"), 1);
			zephir_array_update_string(&modules, SL("default"), &_4, PH_COPY | PH_SEPARATE);
		}
		if (!(zephir_array_isset(modules, module))) {
			ZEPHIR_INIT_NVAR(_1);
			object_init_ex(_1, ice_exception_ce);
			ZEPHIR_SINIT_VAR(_5);
			ZVAL_STRING(&_5, "Module '%s' isn't registered in the application container", 0);
			ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_7, &_5, module);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_8, _6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "ice/mvc/app.zep", 55 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_fetch(&_9, modules, module, PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 58 TSRMLS_CC);
		ZEPHIR_CPY_WRT(module, _9);
		if (Z_TYPE_P(module) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Module definition must be an array", "ice/mvc/app.zep", 61);
			return;
		}
		ZEPHIR_OBS_VAR(path);
		if (zephir_array_isset_string_fetch(&path, module, SS("path"), 0 TSRMLS_CC)) {
			if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, ice_exception_ce);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "Module definition path '%s' doesn't exist", 0);
				ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_7, &_5, path);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_8, _6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "ice/mvc/app.zep", 66 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_OBS_VAR(class);
		if (!(zephir_array_isset_string_fetch(&class, module, SS("class"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(class);
			ZVAL_STRING(class, "Module", 1);
		}
		ZEPHIR_OBS_VAR(namespace);
		if (!(zephir_array_isset_string_fetch(&namespace, module, SS("namespace"), 0 TSRMLS_CC))) {
			ZEPHIR_CPY_WRT(namespace, class);
		}
		ZEPHIR_INIT_VAR(loader);
		object_init_ex(loader, ice_loader_ce);
		ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6, loader, "addnamespace", NULL, namespace, path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _6, "register", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_CONCAT_VSV(_10, namespace, "\\", class);
		ZEPHIR_INIT_NVAR(_4);
		array_init_size(_4, 2);
		ZEPHIR_OBS_VAR(_11);
		zephir_read_property_this(&_11, this_ptr, SL("_di"), PH_NOISY_CC);
		zephir_array_fast_append(_4, _11);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_1, _10, _4 TSRMLS_CC);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(module, _1);
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&dispatcher, _12, "getdispatcher", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13, dispatcher, "gethandlersuffix", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_14);
		ZEPHIR_CONCAT_VSV(_14, namespace, "\\", _13);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setdefaultnamespace", NULL, _14);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, module, "registerautoloaders", NULL);
		zephir_check_call_status();
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, module, "registerservices", NULL, _15);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmethod", NULL, method);
		zephir_check_call_status();
		zephir_array_fetch_string(&_9, response, SL("module"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 90 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setmodule", NULL, _9);
		zephir_check_call_status();
		zephir_array_fetch_string(&_16, response, SL("handler"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 91 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "sethandler", NULL, _16);
		zephir_check_call_status();
		zephir_array_fetch_string(&_17, response, SL("action"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 92 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setaction", NULL, _17);
		zephir_check_call_status();
		zephir_array_fetch_string(&_18, response, SL("params"), PH_NOISY | PH_READONLY, "ice/mvc/app.zep", 93 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "setparams", NULL, _18);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&response, dispatcher, "dispatch", NULL);
		zephir_check_call_status();
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_20);
		array_init_size(_20, 2);
		zephir_array_fast_append(_20, response);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "app.after.dispatch", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _19, "applyhook", NULL, _1, _20);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_21 = Z_TYPE_P(response) == IS_OBJECT;
		if (_21) {
			_21 = (zephir_instance_of_ev(response, ice_http_response_responseinterface_ce TSRMLS_CC));
		}
		if (!(_21)) {
			ZEPHIR_CPY_WRT(controller, response);
			_22 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&response, _22, "getresponse", NULL);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(_11);
			zephir_read_property(&_11, controller, SL("view"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(view, _11);
			ZEPHIR_CALL_METHOD(&_23, view, "getcontent", NULL);
			zephir_check_call_status();
			if (Z_TYPE_P(_23) == IS_NULL) {
				ZEPHIR_CALL_METHOD(&_24, view, "getfile", NULL);
				zephir_check_call_status();
				if (!(zephir_is_true(_24))) {
					ZEPHIR_INIT_NVAR(_1);
					ZVAL_BOOL(_1, 1);
					ZEPHIR_CALL_METHOD(NULL, view, "setsilent", NULL, _1);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_25, dispatcher, "gethandler", NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_26, dispatcher, "getaction", NULL);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(_27);
					ZEPHIR_CONCAT_VSV(_27, _25, "/", _26);
					ZEPHIR_CALL_METHOD(NULL, view, "setfile", NULL, _27);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_25, view, "count", NULL);
				zephir_check_call_status();
				if (!(zephir_is_true(_25))) {
					ZEPHIR_CALL_METHOD(&_26, dispatcher, "getparams", NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, view, "replace", NULL, _26);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_25, view, "render", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, view, "setcontent", NULL, _25);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_26, view, "getmainview", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_24, view, "layout", NULL, _26);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, _24);
			zephir_check_call_status();
		}
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	array_init_size(_4, 2);
	zephir_array_fast_append(_4, response);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "app.after.handle", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _12, "applyhook", NULL, _1, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(response, "send", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

