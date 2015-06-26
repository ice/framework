
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

	ice_mvc_router_ce->create_object = zephir_init_properties;
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

/**
 * Router constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Mvc_Router, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 8);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_di"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set defaults values
 *
 * @param array defaults
 */
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

/**
 * Prepare the FastRoute.
 */
PHP_METHOD(Ice_Mvc_Router, fastRoute) {

	HashTable *_14;
	HashPosition _13;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_7, *_10, *_22;
	zend_bool _2, _3, _19, _20;
	zval *_0;
	zval *options, *dispatcher = NULL, *data = NULL, *collector, *parser, *generator, *route = NULL, *handler = NULL, *_1, *_4 = NULL, *_5, *_6 = NULL, *_8, *_9 = NULL, *_11, *_12, **_15, *_16, *_17, *_18, *_21 = NULL, *_23 = NULL, *_24;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("routeParser"), SL("Ice\\Mvc\\Route\\Parser\\Std"), 1);
	add_assoc_stringl_ex(_0, SS("dataGenerator"), SL("Ice\\Mvc\\Route\\DataGenerator\\GroupCount"), 1);
	add_assoc_stringl_ex(_0, SS("dispatcher"), SL("Ice\\Mvc\\Route\\Dispatcher\\GroupCount"), 1);
	zephir_array_update_string(&_0, SL("cache"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(options);
	zephir_fast_array_merge(options, &(_0), &(_1) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	ZEPHIR_OBS_VAR(collector);
	zephir_read_property_this(&collector, this_ptr, SL("_collector"), PH_NOISY_CC);
	_2 = Z_TYPE_P(collector) != IS_OBJECT;
	if (!(_2)) {
		_3 = Z_TYPE_P(collector) == IS_OBJECT;
		if (_3) {
			_3 = !((zephir_instance_of_ev(collector, ice_mvc_route_collector_ce TSRMLS_CC)));
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
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_8);
		zephir_fetch_safe_class(_9, generator);
		_10 = zend_fetch_class(Z_STRVAL_P(_9), Z_STRLEN_P(_9), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_8, _10);
		if (zephir_has_constructor(_8 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _8, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 114, _5, _8);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_collector"), _4 TSRMLS_CC);
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	if (!(zephir_is_true(_11))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "There are no routes.", "ice/mvc/router.zep", 100);
		return;
	} else {
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
		zephir_is_iterable(_12, &_14, &_13, 0, 0, "ice/mvc/router.zep", 106);
		for (
		  ; zephir_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
		  ; zephir_hash_move_forward_ex(_14, &_13)
		) {
			ZEPHIR_GET_HVALUE(route, _15);
			ZEPHIR_OBS_NVAR(handler);
			zephir_array_isset_long_fetch(&handler, route, 2, 0 TSRMLS_CC);
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("_collector"), PH_NOISY_CC);
			zephir_array_fetch_long(&_17, route, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 104 TSRMLS_CC);
			zephir_array_fetch_long(&_18, route, 1, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 104 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, _16, "addroute", NULL, 0, _17, _18, handler);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(dispatcher);
	zephir_read_property_this(&dispatcher, this_ptr, SL("_dispatcher"), PH_NOISY_CC);
	_19 = Z_TYPE_P(dispatcher) != IS_OBJECT;
	if (!(_19)) {
		_20 = Z_TYPE_P(dispatcher) == IS_OBJECT;
		if (_20) {
			_20 = !((zephir_instance_of_ev(dispatcher, ice_mvc_route_dispatcher_dispatcherinterface_ce TSRMLS_CC)));
		}
		_19 = _20;
	}
	if (_19) {
		ZEPHIR_OBS_NVAR(dispatcher);
		zephir_array_fetch_string(&dispatcher, options, SL("dispatcher"), PH_NOISY, "ice/mvc/router.zep", 111 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4);
		zephir_fetch_safe_class(_21, dispatcher);
		_22 = zend_fetch_class(Z_STRVAL_P(_21), Z_STRLEN_P(_21), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_4, _22);
		if (zephir_has_constructor(_4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("_dispatcher"), _4 TSRMLS_CC);
	}
	zephir_array_fetch_string(&_17, options, SL("cache"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 115 TSRMLS_CC);
	if (zephir_is_true(_17)) {
		if (!(zephir_array_isset_string(options, SS("cacheFile")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Must specify 'cacheFile' option", "ice/mvc/router.zep", 117);
			return;
		}
		zephir_array_fetch_string(&_17, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 120 TSRMLS_CC);
		if ((zephir_file_exists(_17 TSRMLS_CC) == SUCCESS)) {
			zephir_array_fetch_string(&_18, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 121 TSRMLS_CC);
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_23);
			if (zephir_require_zval_ret(&_23, _18 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(data, _23);
		} else {
			_12 = zephir_fetch_nproperty_this(this_ptr, SL("_collector"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&data, _12, "getdata", NULL, 0);
			zephir_check_call_status();
			zephir_array_fetch_string(&_17, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 125 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_4);
			zephir_var_export_ex(_4, &(data) TSRMLS_CC);
			ZEPHIR_INIT_VAR(_24);
			ZEPHIR_CONCAT_SVS(_24, "<?php return ", _4, ";");
			zephir_file_put_contents(NULL, _17, _24 TSRMLS_CC);
		}
	} else {
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_collector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&data, _12, "getdata", NULL, 0);
		zephir_check_call_status();
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_dispatcher"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _12, "setdata", NULL, 0, data);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_ready"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles routing information received from the FastRoute engine.
 *
 * @param string uri
 * @return mixed
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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fastroute", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dispatcher"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&route, _1, "dispatch", NULL, 0, method, uri);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, route, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 157 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_2, 0)) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_silent"), PH_NOISY_CC);
			if (zephir_is_true(_3)) {
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_5);
				ZVAL_STRING(_5, "response", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_VAR(_6);
				ZVAL_NULL(_6);
				ZEPHIR_INIT_VAR(_7);
				ZVAL_BOOL(_7, 1);
				ZEPHIR_CALL_METHOD(&response, _4, "get", NULL, 0, _5, _6, _7);
				zephir_check_temp_parameter(_5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", NULL, 0, _5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 404);
				ZEPHIR_CALL_METHOD(&_8, response, "getmessage", NULL, 0, _5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 0, _8);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_5);
			object_init_ex(_5, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "The requested route could not be found", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, 0);
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_9, 2, _6, _7);
			zephir_check_temp_parameter(_6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "ice/mvc/router.zep", 167 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(_2, 2)) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_silent"), PH_NOISY_CC);
			if (zephir_is_true(_3)) {
				_4 = zephir_fetch_nproperty_this(this_ptr, SL("_di"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "response", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_NULL(_6);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_BOOL(_7, 1);
				ZEPHIR_CALL_METHOD(&response, _4, "get", NULL, 0, _5, _6, _7);
				zephir_check_temp_parameter(_5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 405);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", NULL, 0, _5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 405);
				ZEPHIR_CALL_METHOD(&_8, response, "getmessage", NULL, 0, _5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 0, _8);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_NVAR(_5);
			object_init_ex(_5, ice_exception_ce);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "A request was made of a resource using a request method not supported by that resource", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, 2);
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_9, 2, _6, _7);
			zephir_check_temp_parameter(_6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "ice/mvc/router.zep", 177 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(_2, 1)) {
			ZEPHIR_OBS_VAR(holders);
			zephir_array_fetch_long(&holders, route, 1, PH_NOISY, "ice/mvc/router.zep", 179 TSRMLS_CC);
			ZEPHIR_OBS_VAR(data);
			zephir_array_fetch_long(&data, route, 2, PH_NOISY, "ice/mvc/router.zep", 180 TSRMLS_CC);
			ZEPHIR_OBS_VAR(module);
			if (!(zephir_array_isset_string_fetch(&module, holders, SS("module"), 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(module);
				if (zephir_array_isset_string_fetch(&module, data, SS("module"), 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_5);
					ZEPHIR_SINIT_VAR(_10);
					ZVAL_STRING(&_10, "/", 0);
					ZEPHIR_SINIT_VAR(_11);
					ZVAL_STRING(&_11, "", 0);
					zephir_fast_str_replace(&_5, &_10, &_11, module TSRMLS_CC);
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
					zephir_fast_str_replace(&_5, &_10, &_11, handler TSRMLS_CC);
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
					zephir_fast_str_replace(&_5, &_10, &_11, action TSRMLS_CC);
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
	zephir_create_array(return_value, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&return_value, SL("module"), &module, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("action"), &action, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("params"), &params, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_options"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_params"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

