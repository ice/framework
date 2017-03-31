
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/concat.h"
#include "kernel/variables.h"
#include "kernel/string.h"


/**
 * Router is the standard framework router. Routing is the process of taking a URI endpoint and decomposing it into
 * parameters to determine which module, controller, and action of that controller should receive the request.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 * @uses        FastRoute http:/github.com/nikic/FastRoute
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Router) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc, Router, ice, mvc_router, ice_mvc_router_method_entry, 0);

	zend_declare_property_string(ice_mvc_router_ce, SL("defaultModule"), "default", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_router_ce, SL("defaultHandler"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_router_ce, SL("defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_mvc_router_ce, SL("ready"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_mvc_router_ce, SL("silent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("collector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("dispatcher"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_mvc_router_ce->create_object = zephir_init_properties_Ice_Mvc_Router;
	zend_declare_class_constant_long(ice_mvc_router_ce, SL("NOT_FOUND"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_router_ce, SL("FOUND"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(ice_mvc_router_ce, SL("METHOD_NOT_ALLOWED"), 2 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Router, getDefaultModule) {

	

	RETURN_MEMBER(this_ptr, "defaultModule");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultModule) {

	zval *defaultModule;

	zephir_fetch_params(0, 1, 0, &defaultModule);



	zephir_update_property_this(this_ptr, SL("defaultModule"), defaultModule TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getDefaultHandler) {

	

	RETURN_MEMBER(this_ptr, "defaultHandler");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultHandler) {

	zval *defaultHandler;

	zephir_fetch_params(0, 1, 0, &defaultHandler);



	zephir_update_property_this(this_ptr, SL("defaultHandler"), defaultHandler TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getDefaultAction) {

	

	RETURN_MEMBER(this_ptr, "defaultAction");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultAction) {

	zval *defaultAction;

	zephir_fetch_params(0, 1, 0, &defaultAction);



	zephir_update_property_this(this_ptr, SL("defaultAction"), defaultAction TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getMethod) {

	

	RETURN_MEMBER(this_ptr, "method");

}

PHP_METHOD(Ice_Mvc_Router, getModule) {

	

	RETURN_MEMBER(this_ptr, "module");

}

PHP_METHOD(Ice_Mvc_Router, getHandler) {

	

	RETURN_MEMBER(this_ptr, "handler");

}

PHP_METHOD(Ice_Mvc_Router, getAction) {

	

	RETURN_MEMBER(this_ptr, "action");

}

PHP_METHOD(Ice_Mvc_Router, getParams) {

	

	RETURN_MEMBER(this_ptr, "params");

}

PHP_METHOD(Ice_Mvc_Router, setSilent) {

	zval *silent;

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_this(this_ptr, SL("silent"), silent TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getOptions) {

	

	RETURN_MEMBER(this_ptr, "options");

}

PHP_METHOD(Ice_Mvc_Router, getRoutes) {

	

	RETURN_MEMBER(this_ptr, "routes");

}

PHP_METHOD(Ice_Mvc_Router, setRoutes) {

	zval *routes;

	zephir_fetch_params(0, 1, 0, &routes);



	zephir_update_property_this(this_ptr, SL("routes"), routes TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getCollector) {

	

	RETURN_MEMBER(this_ptr, "collector");

}

PHP_METHOD(Ice_Mvc_Router, setCollector) {

	zval *collector;

	zephir_fetch_params(0, 1, 0, &collector);



	zephir_update_property_this(this_ptr, SL("collector"), collector TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_Router, getDispatcher) {

	

	RETURN_MEMBER(this_ptr, "dispatcher");

}

PHP_METHOD(Ice_Mvc_Router, setDispatcher) {

	zval *dispatcher;

	zephir_fetch_params(0, 1, 0, &dispatcher);



	zephir_update_property_this(this_ptr, SL("dispatcher"), dispatcher TSRMLS_CC);

}

/**
 * Set defaults values
 *
 * @param array defaults
 */
PHP_METHOD(Ice_Mvc_Router, setDefaults) {

	zval *defaults_param = NULL, *module = NULL, *handler = NULL, *action = NULL;
	zval *defaults = NULL;

	zephir_fetch_params(0, 1, 0, &defaults_param);

	defaults = defaults_param;


	if (zephir_array_isset_string_fetch(&module, defaults, SS("module"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("defaultModule"), module TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&handler, defaults, SS("handler"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("defaultHandler"), handler TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&action, defaults, SS("action"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("defaultAction"), action TSRMLS_CC);
	}

}

/**
 * Set options.
 *
 * @param array options
 * @return object this
 */
PHP_METHOD(Ice_Mvc_Router, setOptions) {

	zval *options_param = NULL;
	zval *options = NULL;

	zephir_fetch_params(0, 1, 0, &options_param);

	options = options_param;


	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Prepare the FastRoute.
 */
PHP_METHOD(Ice_Mvc_Router, fastRoute) {

	HashTable *_18;
	HashPosition _17;
	zend_bool _3, _5, _24, _26;
	zval *_0, *_13$$4, *_14$$4 = NULL;
	zval *options = NULL, *data = NULL, *route = NULL, *handler = NULL, *_1, *_2, *_4, *_6, *_12, *_16, **_19, *_23, *_25, *_27, *_30, *_39, *_7$$3, *_8$$3, *_9$$3, *_10$$3, *_11$$3, *_15$$4 = NULL, *_20$$5, *_21$$5, *_22$$5, *_28$$6, *_29$$6, *_31$$7, *_32$$9, *_33$$9 = NULL, *_34$$10, *_35$$10, *_36$$10 = NULL, *_37$$10, *_38$$11;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("routeParser"), SL("Ice\\Mvc\\Route\\Parser\\Std"), 1);
	add_assoc_stringl_ex(_0, SS("dataGenerator"), SL("Ice\\Mvc\\Route\\DataGenerator\\GroupCount"), 1);
	add_assoc_stringl_ex(_0, SS("dispatcher"), SL("Ice\\Mvc\\Route\\Dispatcher\\GroupCount"), 1);
	zephir_array_update_string(&_0, SL("cache"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(options);
	zephir_fast_array_merge(options, &(_0), &(_1) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("collector"), PH_NOISY_CC);
	_3 = Z_TYPE_P(_2) != IS_OBJECT;
	if (!(_3)) {
		ZEPHIR_OBS_VAR(_4);
		zephir_read_property_this(&_4, this_ptr, SL("collector"), PH_NOISY_CC);
		_5 = Z_TYPE_P(_4) == IS_OBJECT;
		if (_5) {
			ZEPHIR_OBS_VAR(_6);
			zephir_read_property_this(&_6, this_ptr, SL("collector"), PH_NOISY_CC);
			_5 = !(zephir_instance_of_ev(_6, ice_mvc_route_collector_ce TSRMLS_CC));
		}
		_3 = _5;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(_7$$3);
		object_init_ex(_7$$3, ice_mvc_route_collector_ce);
		ZEPHIR_INIT_VAR(_8$$3);
		zephir_array_fetch_string(&_9$$3, options, SL("routeParser"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 96 TSRMLS_CC);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(_8$$3, _9$$3 TSRMLS_CC);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_10$$3);
		zephir_array_fetch_string(&_11$$3, options, SL("dataGenerator"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 96 TSRMLS_CC);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(_10$$3, _11$$3 TSRMLS_CC);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _7$$3, "__construct", NULL, 128, _8$$3, _10$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("collector"), _7$$3 TSRMLS_CC);
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("routes"), PH_NOISY_CC);
	if (!(zephir_is_true(_12))) {
		ZEPHIR_INIT_VAR(_13$$4);
		zephir_create_array(_13$$4, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_14$$4);
		zephir_create_array(_14$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_15$$4);
		ZVAL_STRING(_15$$4, "*", 1);
		zephir_array_fast_append(_14$$4, _15$$4);
		ZEPHIR_INIT_NVAR(_15$$4);
		ZVAL_STRING(_15$$4, "/{controller:[a-z]+}/{action:[a-z]+}[/{param}]", 1);
		zephir_array_fast_append(_14$$4, _15$$4);
		zephir_array_fast_append(_13$$4, _14$$4);
		ZEPHIR_INIT_NVAR(_14$$4);
		zephir_create_array(_14$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_15$$4);
		ZVAL_STRING(_15$$4, "*", 1);
		zephir_array_fast_append(_14$$4, _15$$4);
		ZEPHIR_INIT_NVAR(_15$$4);
		ZVAL_STRING(_15$$4, "/{controller:[a-z]+}", 1);
		zephir_array_fast_append(_14$$4, _15$$4);
		zephir_array_fast_append(_13$$4, _14$$4);
		ZEPHIR_INIT_NVAR(_14$$4);
		zephir_create_array(_14$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_15$$4);
		ZVAL_STRING(_15$$4, "*", 1);
		zephir_array_fast_append(_14$$4, _15$$4);
		ZEPHIR_INIT_NVAR(_15$$4);
		ZVAL_STRING(_15$$4, "", 1);
		zephir_array_fast_append(_14$$4, _15$$4);
		zephir_array_fast_append(_13$$4, _14$$4);
		zephir_update_property_this(this_ptr, SL("routes"), _13$$4 TSRMLS_CC);
	}
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("routes"), PH_NOISY_CC);
	zephir_is_iterable(_16, &_18, &_17, 0, 0, "ice/mvc/router.zep", 113);
	for (
	  ; zephir_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS
	  ; zephir_hash_move_forward_ex(_18, &_17)
	) {
		ZEPHIR_GET_HVALUE(route, _19);
		ZEPHIR_OBS_NVAR(handler);
		zephir_array_isset_long_fetch(&handler, route, 2, 0 TSRMLS_CC);
		_20$$5 = zephir_fetch_nproperty_this(this_ptr, SL("collector"), PH_NOISY_CC);
		zephir_array_fetch_long(&_21$$5, route, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 110 TSRMLS_CC);
		zephir_array_fetch_long(&_22$$5, route, 1, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 110 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _20$$5, "addroute", NULL, 0, _21$$5, _22$$5, handler);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(_23);
	zephir_read_property_this(&_23, this_ptr, SL("dispatcher"), PH_NOISY_CC);
	_24 = Z_TYPE_P(_23) != IS_OBJECT;
	if (!(_24)) {
		ZEPHIR_OBS_VAR(_25);
		zephir_read_property_this(&_25, this_ptr, SL("dispatcher"), PH_NOISY_CC);
		_26 = Z_TYPE_P(_25) == IS_OBJECT;
		if (_26) {
			ZEPHIR_OBS_VAR(_27);
			zephir_read_property_this(&_27, this_ptr, SL("dispatcher"), PH_NOISY_CC);
			_26 = !(zephir_instance_of_ev(_27, ice_mvc_route_dispatcher_dispatcherinterface_ce TSRMLS_CC));
		}
		_24 = _26;
	}
	if (_24) {
		ZEPHIR_INIT_VAR(_28$$6);
		zephir_array_fetch_string(&_29$$6, options, SL("dispatcher"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 114 TSRMLS_CC);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(_28$$6, _29$$6 TSRMLS_CC);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("dispatcher"), _28$$6 TSRMLS_CC);
	}
	zephir_array_fetch_string(&_30, options, SL("cache"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 117 TSRMLS_CC);
	if (zephir_is_true(_30)) {
		if (!(zephir_array_isset_string(options, SS("cacheFile")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Must specify 'cacheFile' option", "ice/mvc/router.zep", 119);
			return;
		}
		zephir_array_fetch_string(&_31$$7, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 122 TSRMLS_CC);
		if ((zephir_file_exists(_31$$7 TSRMLS_CC) == SUCCESS)) {
			zephir_array_fetch_string(&_32$$9, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 123 TSRMLS_CC);
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_33$$9);
			if (zephir_require_zval_ret(&_33$$9, _32$$9 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(data, _33$$9);
		} else {
			_34$$10 = zephir_fetch_nproperty_this(this_ptr, SL("collector"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&data, _34$$10, "getdata", NULL, 0);
			zephir_check_call_status();
			zephir_array_fetch_string(&_35$$10, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 127 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_36$$10);
			ZEPHIR_INIT_NVAR(_36$$10);
			zephir_var_export_ex(_36$$10, &data TSRMLS_CC);
			ZEPHIR_INIT_VAR(_37$$10);
			ZEPHIR_CONCAT_SVS(_37$$10, "<?php return ", _36$$10, ";");
			zephir_file_put_contents(NULL, _35$$10, _37$$10 TSRMLS_CC);
		}
	} else {
		_38$$11 = zephir_fetch_nproperty_this(this_ptr, SL("collector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&data, _38$$11, "getdata", NULL, 0);
		zephir_check_call_status();
	}
	_39 = zephir_fetch_nproperty_this(this_ptr, SL("dispatcher"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _39, "setdata", NULL, 0, data);
	zephir_check_call_status();
	if (1) {
		zephir_update_property_this(this_ptr, SL("ready"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("ready"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles routing information received from the FastRoute engine.
 *
 * @param string uri
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_Router, handle) {

	zephir_fcall_cache_entry *_5 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, *uri = NULL, *module = NULL, *handler = NULL, *action = NULL, *params = NULL, *holders = NULL, *data = NULL, *route = NULL, *response = NULL, *_0, *_1, *_2, *_3$$4, *_8$$4, *_9$$4, *_10$$4, *_4$$5 = NULL, *_6$$5 = NULL, *_7$$5 = NULL, *_12$$6, *_16$$6, *_17$$6, *_18$$6, *_13$$7 = NULL, *_14$$7 = NULL, *_15$$7 = NULL, *_19$$10, _20$$10, _21$$10, *_22$$13, _23$$13, _24$$13, *_25$$16, _26$$16, _27$$16;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &method, &uri);

	if (!method) {
		method = ZEPHIR_GLOBAL(global_null);
	}
	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(handler);
	zephir_read_property_this(&handler, this_ptr, SL("defaultHandler"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(action);
	zephir_read_property_this(&action, this_ptr, SL("defaultAction"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("ready"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fastroute", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("dispatcher"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&route, _1, "dispatch", NULL, 0, method, uri);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, route, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 159 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_2, 0)) {
			_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_3$$4)) {
				ZEPHIR_CALL_CE_STATIC(&_4$$5, ice_di_ce, "fetch", &_5, 1);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_6$$5);
				ZVAL_STRING(_6$$5, "response", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&response, _4$$5, "get", NULL, 0, _6$$5);
				zephir_check_temp_parameter(_6$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_6$$5);
				ZVAL_LONG(_6$$5, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", NULL, 0, _6$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_6$$5);
				ZVAL_LONG(_6$$5, 404);
				ZEPHIR_CALL_METHOD(&_7$$5, response, "getmessage", NULL, 0, _6$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 0, _7$$5);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_VAR(_8$$4);
			object_init_ex(_8$$4, ice_exception_ce);
			ZEPHIR_INIT_VAR(_9$$4);
			ZVAL_STRING(_9$$4, "The requested route could not be found", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_10$$4);
			ZVAL_LONG(_10$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, _8$$4, "__construct", &_11, 13, _9$$4, _10$$4);
			zephir_check_temp_parameter(_9$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_8$$4, "ice/mvc/router.zep", 169 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(_2, 2)) {
			_12$$6 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_12$$6)) {
				ZEPHIR_CALL_CE_STATIC(&_13$$7, ice_di_ce, "fetch", &_5, 1);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_14$$7);
				ZVAL_STRING(_14$$7, "response", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&response, _13$$7, "get", NULL, 0, _14$$7);
				zephir_check_temp_parameter(_14$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_14$$7);
				ZVAL_LONG(_14$$7, 405);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", NULL, 0, _14$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_14$$7);
				ZVAL_LONG(_14$$7, 405);
				ZEPHIR_CALL_METHOD(&_15$$7, response, "getmessage", NULL, 0, _14$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 0, _15$$7);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_VAR(_16$$6);
			object_init_ex(_16$$6, ice_exception_ce);
			ZEPHIR_INIT_VAR(_17$$6);
			ZVAL_STRING(_17$$6, "A request was made of a resource using a request method not supported by that resource", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_18$$6);
			ZVAL_LONG(_18$$6, 2);
			ZEPHIR_CALL_METHOD(NULL, _16$$6, "__construct", &_11, 13, _17$$6, _18$$6);
			zephir_check_temp_parameter(_17$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_16$$6, "ice/mvc/router.zep", 179 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(_2, 1)) {
			ZEPHIR_OBS_VAR(holders);
			zephir_array_fetch_long(&holders, route, 1, PH_NOISY, "ice/mvc/router.zep", 181 TSRMLS_CC);
			ZEPHIR_OBS_VAR(data);
			zephir_array_fetch_long(&data, route, 2, PH_NOISY, "ice/mvc/router.zep", 182 TSRMLS_CC);
			ZEPHIR_OBS_VAR(module);
			if (!(zephir_array_isset_string_fetch(&module, holders, SS("module"), 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(module);
				if (zephir_array_isset_string_fetch(&module, data, SS("module"), 0 TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(_19$$10);
					ZEPHIR_SINIT_VAR(_20$$10);
					ZVAL_STRING(&_20$$10, "/", 0);
					ZEPHIR_SINIT_VAR(_21$$10);
					ZVAL_STRING(&_21$$10, "", 0);
					zephir_fast_str_replace(&_19$$10, &_20$$10, &_21$$10, module TSRMLS_CC);
					ZEPHIR_CPY_WRT(module, _19$$10);
					zephir_array_unset_string(&data, SS("module"), PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(module);
					zephir_read_property_this(&module, this_ptr, SL("defaultModule"), PH_NOISY_CC);
				}
			}
			ZEPHIR_OBS_NVAR(handler);
			if (!(zephir_array_isset_string_fetch(&handler, holders, SS("controller"), 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(handler);
				if (zephir_array_isset_string_fetch(&handler, data, SS("controller"), 0 TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(_22$$13);
					ZEPHIR_SINIT_VAR(_23$$13);
					ZVAL_STRING(&_23$$13, "/", 0);
					ZEPHIR_SINIT_VAR(_24$$13);
					ZVAL_STRING(&_24$$13, "", 0);
					zephir_fast_str_replace(&_22$$13, &_23$$13, &_24$$13, handler TSRMLS_CC);
					ZEPHIR_CPY_WRT(handler, _22$$13);
					zephir_array_unset_string(&data, SS("controller"), PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(handler);
					zephir_read_property_this(&handler, this_ptr, SL("defaultHandler"), PH_NOISY_CC);
				}
			}
			ZEPHIR_OBS_NVAR(action);
			if (!(zephir_array_isset_string_fetch(&action, holders, SS("action"), 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(action);
				if (zephir_array_isset_string_fetch(&action, data, SS("action"), 0 TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(_25$$16);
					ZEPHIR_SINIT_VAR(_26$$16);
					ZVAL_STRING(&_26$$16, "/", 0);
					ZEPHIR_SINIT_VAR(_27$$16);
					ZVAL_STRING(&_27$$16, "", 0);
					zephir_fast_str_replace(&_25$$16, &_26$$16, &_27$$16, action TSRMLS_CC);
					ZEPHIR_CPY_WRT(action, _25$$16);
					zephir_array_unset_string(&data, SS("action"), PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(action);
					zephir_read_property_this(&action, this_ptr, SL("defaultAction"), PH_NOISY_CC);
				}
			}
			ZEPHIR_CPY_WRT(params, data);
			break;
		}
	} while(0);

	zephir_update_property_this(this_ptr, SL("method"), method TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("module"), module TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("handler"), handler TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("action"), action TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("params"), params TSRMLS_CC);
	zephir_create_array(return_value, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&return_value, SL("module"), &module, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("action"), &action, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("params"), &params, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

zend_object_value zephir_init_properties_Ice_Mvc_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("options"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("params"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

