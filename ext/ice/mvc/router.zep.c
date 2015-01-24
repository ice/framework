
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/concat.h"
#include "kernel/variables.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(Ice_Mvc_Router) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc, Router, ice, mvc_router, ice_mvc_router_method_entry, 0);

	zend_declare_property_null(ice_mvc_router_ce, SL("_di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_router_ce, SL("_defaultModule"), "default", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_router_ce, SL("_defaultHandler"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_router_ce, SL("_defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("_method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("_module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("_handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("_action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_mvc_router_ce, SL("_ready"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_mvc_router_ce, SL("_silent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("_collector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("_dispatcher"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_router_ce, SL("NOT_FOUND"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_router_ce, SL("FOUND"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_router_ce, SL("METHOD_NOT_ALLOWED"), 2 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Router, getDefaultModule) {


	RETURN_MEMBER(this_ptr, "_defaultModule");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultModule) {

	zval *defaultModule;

	zephir_fetch_params(0, 1, 0, &defaultModule);



	zephir_update_property_this(this_ptr, SL("_defaultModule"), defaultModule TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getDefaultHandler) {


	RETURN_MEMBER(this_ptr, "_defaultHandler");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultHandler) {

	zval *defaultHandler;

	zephir_fetch_params(0, 1, 0, &defaultHandler);



	zephir_update_property_this(this_ptr, SL("_defaultHandler"), defaultHandler TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getDefaultAction) {


	RETURN_MEMBER(this_ptr, "_defaultAction");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultAction) {

	zval *defaultAction;

	zephir_fetch_params(0, 1, 0, &defaultAction);



	zephir_update_property_this(this_ptr, SL("_defaultAction"), defaultAction TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getMethod) {


	RETURN_MEMBER(this_ptr, "_method");

}

PHP_METHOD(Ice_Mvc_Router, getModule) {


	RETURN_MEMBER(this_ptr, "_module");

}

PHP_METHOD(Ice_Mvc_Router, getHandler) {


	RETURN_MEMBER(this_ptr, "_handler");

}

PHP_METHOD(Ice_Mvc_Router, getAction) {


	RETURN_MEMBER(this_ptr, "_action");

}

PHP_METHOD(Ice_Mvc_Router, getParams) {


	RETURN_MEMBER(this_ptr, "_params");

}

PHP_METHOD(Ice_Mvc_Router, setSilent) {

	zval *silent;

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_this(this_ptr, SL("_silent"), silent TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getOptions) {


	RETURN_MEMBER(this_ptr, "_options");

}

PHP_METHOD(Ice_Mvc_Router, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getRoutes) {


	RETURN_MEMBER(this_ptr, "_routes");

}

PHP_METHOD(Ice_Mvc_Router, setRoutes) {

	zval *routes;

	zephir_fetch_params(0, 1, 0, &routes);



	zephir_update_property_this(this_ptr, SL("_routes"), routes TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getCollector) {


	RETURN_MEMBER(this_ptr, "_collector");

}

PHP_METHOD(Ice_Mvc_Router, setCollector) {

	zval *collector;

	zephir_fetch_params(0, 1, 0, &collector);



	zephir_update_property_this(this_ptr, SL("_collector"), collector TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getDispatcher) {


	RETURN_MEMBER(this_ptr, "_dispatcher");

}

PHP_METHOD(Ice_Mvc_Router, setDispatcher) {

	zval *dispatcher;

	zephir_fetch_params(0, 1, 0, &dispatcher);



	zephir_update_property_this(this_ptr, SL("_dispatcher"), dispatcher TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_params"), _0 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_1, ice_di_ce, "fetch", &_2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_di"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Mvc_Router, setDefaults) {

	zval *defaults_param = NULL, *module, *handler, *action;
	zval *defaults = NULL;

	zephir_fetch_params(0, 1, 0, &defaults_param);

	defaults = defaults_param;



	if (zephir_array_isset_string_fetch(&module, defaults, SS("module"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultModule"), module TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&handler, defaults, SS("handler"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultHandler"), handler TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&action, defaults, SS("action"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_defaultAction"), action TSRMLS_CC);
	}

}

PHP_METHOD(Ice_Mvc_Router, fastRoute) {

	HashTable *_13;
	HashPosition _12;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_7, *_10, *_21;
	zend_bool _2, _3, _18, _19;
	zval *options = NULL, *_1;
	zval *routeDefinitionCallback = NULL, *options_param = NULL, *dispatcher = NULL, *data = NULL, *collector, *parser, *generator, *route = NULL, *handler = NULL, *_0, *_4 = NULL, *_5, *_6 = NULL, *_8, *_9 = NULL, *_11, **_14, *_15, *_16, *_17, *_20 = NULL, *_22 = NULL, *_23;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &routeDefinitionCallback, &options_param);

	if (!routeDefinitionCallback) {
		routeDefinitionCallback = ZEPHIR_GLOBAL(global_null);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 6);
	add_assoc_stringl_ex(_1, SS("routeParser"), SL("Ice\\Mvc\\Route\\Parser\\Std"), 1);
	add_assoc_stringl_ex(_1, SS("dataGenerator"), SL("Ice\\Mvc\\Route\\DataGenerator\\GroupCount"), 1);
	add_assoc_stringl_ex(_1, SS("dispatcher"), SL("Ice\\Mvc\\Route\\Dispatcher\\GroupCount"), 1);
	zephir_array_update_string(&_1, SL("cache"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(_0, &(_1), &(options) TSRMLS_CC);
	ZEPHIR_CPY_WRT(options, _0);
	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	ZEPHIR_OBS_VAR(collector);
	zephir_read_property_this(&collector, this_ptr, SL("_collector"), PH_NOISY_CC);
	_2 = Z_TYPE_P(collector) != IS_OBJECT;
	if (!(_2)) {
		_3 = Z_TYPE_P(collector) == IS_OBJECT;
		if (_3) {
			_3 = !(zephir_instance_of_ev(collector, ice_mvc_route_collector_ce TSRMLS_CC));
		}
		_2 = _3;
	}
	if (_2) {
		ZEPHIR_OBS_VAR(parser);
		zephir_array_isset_string_fetch(&parser, options, SS("routeParser"), 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(generator);
		zephir_array_isset_string_fetch(&generator, options, SS("dataGenerator"), 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, ice_mvc_route_collector_ce);
		ZEPHIR_INIT_VAR(_5);
		zephir_fetch_safe_class(_6, parser);
		_7 = zend_fetch_class(Z_STRVAL_P(_6), Z_STRLEN_P(_6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_5, _7);
		if (zephir_has_constructor(_5 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_8);
		zephir_fetch_safe_class(_9, generator);
		_10 = zend_fetch_class(Z_STRVAL_P(_9), Z_STRLEN_P(_9), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_8, _10);
		if (zephir_has_constructor(_8 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _8, "__construct", NULL);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _5, _8);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_collector"), _4 TSRMLS_CC);
	}
	if (zephir_is_callable(routeDefinitionCallback TSRMLS_CC) == 1) {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_collector"), PH_NOISY_CC);
		ZEPHIR_CALL_ZVAL_FUNCTION(NULL, routeDefinitionCallback, NULL, _11);
		zephir_check_call_status();
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	if (!(zephir_is_true(_11))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "There are no routes.", "ice/mvc/router.zep", 89);
		return;
	} else {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
		zephir_is_iterable(_11, &_13, &_12, 0, 0, "ice/mvc/router.zep", 95);
		for (
		  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
		  ; zephir_hash_move_forward_ex(_13, &_12)
		) {
			ZEPHIR_GET_HVALUE(route, _14);
			ZEPHIR_OBS_NVAR(handler);
			zephir_array_isset_long_fetch(&handler, route, 2, 0 TSRMLS_CC);
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("_collector"), PH_NOISY_CC);
			zephir_array_fetch_long(&_16, route, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 93 TSRMLS_CC);
			zephir_array_fetch_long(&_17, route, 1, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 93 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, _15, "addroute", NULL, _16, _17, handler);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(dispatcher);
	zephir_read_property_this(&dispatcher, this_ptr, SL("_dispatcher"), PH_NOISY_CC);
	_18 = Z_TYPE_P(dispatcher) != IS_OBJECT;
	if (!(_18)) {
		_19 = Z_TYPE_P(dispatcher) == IS_OBJECT;
		if (_19) {
			_19 = !(zephir_instance_of_ev(dispatcher, ice_mvc_route_dispatcher_dispatcherinterface_ce TSRMLS_CC));
		}
		_18 = _19;
	}
	if (_18) {
		ZEPHIR_OBS_NVAR(dispatcher);
		zephir_array_fetch_string(&dispatcher, options, SL("dispatcher"), PH_NOISY, "ice/mvc/router.zep", 99 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4);
		zephir_fetch_safe_class(_20, dispatcher);
		_21 = zend_fetch_class(Z_STRVAL_P(_20), Z_STRLEN_P(_20), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_4, _21);
		if (zephir_has_constructor(_4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("_dispatcher"), _4 TSRMLS_CC);
	}
	zephir_array_fetch_string(&_16, options, SL("cache"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 103 TSRMLS_CC);
	if (zephir_is_true(_16)) {
		if (!(zephir_array_isset_string(options, SS("cacheFile")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Must specify 'cacheFile' option", "ice/mvc/router.zep", 105);
			return;
		}
		zephir_array_fetch_string(&_16, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 108 TSRMLS_CC);
		if ((zephir_file_exists(_16 TSRMLS_CC) == SUCCESS)) {
			zephir_array_fetch_string(&_17, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 109 TSRMLS_CC);
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_22);
			if (zephir_require_zval_ret(&_22, _17 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(data, _22);
		} else {
			zephir_array_fetch_string(&_16, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 111 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_4);
			zephir_var_export_ex(_4, &(data) TSRMLS_CC);
			ZEPHIR_INIT_VAR(_23);
			ZEPHIR_CONCAT_SVS(_23, "<?php return ", _4, ";");
			zephir_file_put_contents(NULL, _16, _23 TSRMLS_CC);
		}
	} else {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_collector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&data, _11, "getdata", NULL);
		zephir_check_call_status();
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_dispatcher"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _11, "setdata", NULL, data);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_ready"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles routing information received from the rewrite engine
 *
 * @param string uri
 * @return array
 */
PHP_METHOD(Ice_Mvc_Router, handle) {

	zephir_fcall_cache_entry *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, *uri = NULL, *module = NULL, *handler = NULL, *action = NULL, *params = NULL, *holders, *data, *route = NULL, *response = NULL, *_0, *_1, *_2, *_3, *_4, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, _10 = zval_used_for_init, _11 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &method, &uri);

	if (!method) {
		method = ZEPHIR_GLOBAL(global_null);
	}
	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(handler);
	zephir_read_property_this(&handler, this_ptr, SL("_defaultHandler"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(action);
	zephir_read_property_this(&action, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_ready"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fastroute", NULL);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dispatcher"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&route, _1, "dispatch", NULL, method, uri);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, route, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 143 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_2, 0)) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_silent"), PH_NOISY_CC);
			if (zephir_is_true(_3)) {
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&response, _4, "getresponse", NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_5);
				ZVAL_LONG(_5, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", NULL, _5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 404);
				ZEPHIR_CALL_METHOD(&_6, response, "getmessage", NULL, _5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, _6);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_5);
			object_init_ex(_5, ice_exception_ce);
			ZEPHIR_INIT_VAR(_7);
			ZVAL_STRING(_7, "The requested route could not be found", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_8);
			ZVAL_LONG(_8, 0);
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_9, _7, _8);
			zephir_check_temp_parameter(_7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "ice/mvc/router.zep", 153 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(_2, 2)) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_silent"), PH_NOISY_CC);
			if (zephir_is_true(_3)) {
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&response, _4, "getresponse", NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 405);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", NULL, _5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 405);
				ZEPHIR_CALL_METHOD(&_6, response, "getmessage", NULL, _5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, _6);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_5);
			object_init_ex(_5, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "A request was made of a resource using a request method not supported by that resource", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, 2);
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_9, _7, _8);
			zephir_check_temp_parameter(_7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "ice/mvc/router.zep", 163 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(_2, 1)) {
			ZEPHIR_OBS_VAR(holders);
			zephir_array_fetch_long(&holders, route, 1, PH_NOISY, "ice/mvc/router.zep", 165 TSRMLS_CC);
			ZEPHIR_OBS_VAR(data);
			zephir_array_fetch_long(&data, route, 2, PH_NOISY, "ice/mvc/router.zep", 166 TSRMLS_CC);
			ZEPHIR_OBS_VAR(module);
			if (!(zephir_array_isset_string_fetch(&module, holders, SS("module"), 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(module);
				if (zephir_array_isset_string_fetch(&module, data, SS("module"), 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_5);
					ZEPHIR_SINIT_VAR(_10);
					ZVAL_STRING(&_10, "/", 0);
					ZEPHIR_SINIT_VAR(_11);
					ZVAL_STRING(&_11, "", 0);
					zephir_fast_str_replace(_5, &_10, &_11, module TSRMLS_CC);
					ZEPHIR_CPY_WRT(module, _5);
					zephir_array_unset_string(&data, SS("module"), PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(module);
					zephir_read_property_this(&module, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
				}
			}
			ZEPHIR_OBS_NVAR(handler);
			if (!(zephir_array_isset_string_fetch(&handler, holders, SS("controller"), 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(handler);
				if (zephir_array_isset_string_fetch(&handler, data, SS("controller"), 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_5);
					ZEPHIR_SINIT_NVAR(_10);
					ZVAL_STRING(&_10, "/", 0);
					ZEPHIR_SINIT_NVAR(_11);
					ZVAL_STRING(&_11, "", 0);
					zephir_fast_str_replace(_5, &_10, &_11, handler TSRMLS_CC);
					ZEPHIR_CPY_WRT(handler, _5);
					zephir_array_unset_string(&data, SS("controller"), PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(handler);
					zephir_read_property_this(&handler, this_ptr, SL("_defaultHandler"), PH_NOISY_CC);
				}
			}
			ZEPHIR_OBS_NVAR(action);
			if (!(zephir_array_isset_string_fetch(&action, holders, SS("action"), 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(action);
				if (zephir_array_isset_string_fetch(&action, data, SS("action"), 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_5);
					ZEPHIR_SINIT_NVAR(_10);
					ZVAL_STRING(&_10, "/", 0);
					ZEPHIR_SINIT_NVAR(_11);
					ZVAL_STRING(&_11, "", 0);
					zephir_fast_str_replace(_5, &_10, &_11, action TSRMLS_CC);
					ZEPHIR_CPY_WRT(action, _5);
					zephir_array_unset_string(&data, SS("action"), PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(action);
					zephir_read_property_this(&action, this_ptr, SL("_defaultAction"), PH_NOISY_CC);
				}
			}
			ZEPHIR_CPY_WRT(params, data);
			break;
		}
	} while(0);

	zephir_update_property_this(this_ptr, SL("_method"), method TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_module"), module TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_action"), action TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	array_init_size(return_value, 6);
	zephir_array_update_string(&return_value, SL("module"), &module, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("action"), &action, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("params"), &params, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

