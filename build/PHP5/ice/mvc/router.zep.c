
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


/**
 * Router is the standard framework router. Routing is the process of taking a URI endpoint and decomposing it into
 * parameters to determine which module, controller, and action of that controller should receive the request.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 * @uses        FastRoute http:/github.com/nikic/FastRoute
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Router) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc, Router, ice, mvc_router, ice_mvc_router_method_entry, 0);

	zend_declare_property_null(ice_mvc_router_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
 * Router constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Mvc_Router, __construct) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 6);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

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

	HashTable *_14$$5;
	HashPosition _13$$5;
	zend_class_entry *_8$$3, *_11$$3, *_24$$7;
	zend_bool _3, _4, _20, _21;
	zval *_0;
	zval *options = NULL, *dispatcher = NULL, *data = NULL, *collector = NULL, *parser = NULL, *generator = NULL, *route = NULL, *handler = NULL, *_1, *_2, *_19, *_25, *_5$$3, *_6$$3, *_7$$3 = NULL, *_9$$3, *_10$$3 = NULL, *_12$$5, **_15$$5, *_16$$6, *_17$$6, *_18$$6, *_22$$7, *_23$$7 = NULL, *_26$$8, *_27$$10, *_28$$10 = NULL, *_29$$11, *_30$$11, *_31$$11 = NULL, *_32$$11, *_33$$12;
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
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("collector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(collector, _2);
	_3 = Z_TYPE_P(collector) != IS_OBJECT;
	if (!(_3)) {
		_4 = Z_TYPE_P(collector) == IS_OBJECT;
		if (_4) {
			_4 = !((zephir_instance_of_ev(collector, ice_mvc_route_collector_ce TSRMLS_CC)));
		}
		_3 = _4;
	}
	if (_3) {
		ZEPHIR_OBS_VAR(parser);
		zephir_array_isset_string_fetch(&parser, options, SS("routeParser"), 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(generator);
		zephir_array_isset_string_fetch(&generator, options, SS("dataGenerator"), 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, ice_mvc_route_collector_ce);
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_fetch_safe_class(_7$$3, parser);
			_8$$3 = zend_fetch_class(Z_STRVAL_P(_7$$3), Z_STRLEN_P(_7$$3), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_6$$3, _8$$3);
		if (zephir_has_constructor(_6$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _6$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_9$$3);
		zephir_fetch_safe_class(_10$$3, generator);
			_11$$3 = zend_fetch_class(Z_STRVAL_P(_10$$3), Z_STRLEN_P(_10$$3), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_9$$3, _11$$3);
		if (zephir_has_constructor(_9$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _9$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 126, _6$$3, _9$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("collector"), _5$$3 TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("routes"), PH_NOISY_CC);
	if (!(zephir_is_true(_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "There are no routes.", "ice/mvc/router.zep", 113);
		return;
	} else {
		_12$$5 = zephir_fetch_nproperty_this(this_ptr, SL("routes"), PH_NOISY_CC);
		zephir_is_iterable(_12$$5, &_14$$5, &_13$$5, 0, 0, "ice/mvc/router.zep", 119);
		for (
		  ; zephir_hash_get_current_data_ex(_14$$5, (void**) &_15$$5, &_13$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_14$$5, &_13$$5)
		) {
			ZEPHIR_GET_HVALUE(route, _15$$5);
			ZEPHIR_OBS_NVAR(handler);
			zephir_array_isset_long_fetch(&handler, route, 2, 0 TSRMLS_CC);
			_16$$6 = zephir_fetch_nproperty_this(this_ptr, SL("collector"), PH_NOISY_CC);
			zephir_array_fetch_long(&_17$$6, route, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 117 TSRMLS_CC);
			zephir_array_fetch_long(&_18$$6, route, 1, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 117 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, _16$$6, "addroute", NULL, 0, _17$$6, _18$$6, handler);
			zephir_check_call_status();
		}
	}
	_19 = zephir_fetch_nproperty_this(this_ptr, SL("dispatcher"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dispatcher, _19);
	_20 = Z_TYPE_P(dispatcher) != IS_OBJECT;
	if (!(_20)) {
		_21 = Z_TYPE_P(dispatcher) == IS_OBJECT;
		if (_21) {
			_21 = !((zephir_instance_of_ev(dispatcher, ice_mvc_route_dispatcher_dispatcherinterface_ce TSRMLS_CC)));
		}
		_20 = _21;
	}
	if (_20) {
		ZEPHIR_OBS_NVAR(dispatcher);
		zephir_array_fetch_string(&dispatcher, options, SL("dispatcher"), PH_NOISY, "ice/mvc/router.zep", 124 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_22$$7);
		zephir_fetch_safe_class(_23$$7, dispatcher);
			_24$$7 = zend_fetch_class(Z_STRVAL_P(_23$$7), Z_STRLEN_P(_23$$7), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_22$$7, _24$$7);
		if (zephir_has_constructor(_22$$7 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _22$$7, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("dispatcher"), _22$$7 TSRMLS_CC);
	}
	zephir_array_fetch_string(&_25, options, SL("cache"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 128 TSRMLS_CC);
	if (zephir_is_true(_25)) {
		if (!(zephir_array_isset_string(options, SS("cacheFile")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Must specify 'cacheFile' option", "ice/mvc/router.zep", 130);
			return;
		}
		zephir_array_fetch_string(&_26$$8, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 133 TSRMLS_CC);
		if ((zephir_file_exists(_26$$8 TSRMLS_CC) == SUCCESS)) {
			zephir_array_fetch_string(&_27$$10, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 134 TSRMLS_CC);
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_28$$10);
			if (zephir_require_zval_ret(&_28$$10, _27$$10 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(data, _28$$10);
		} else {
			_29$$11 = zephir_fetch_nproperty_this(this_ptr, SL("collector"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&data, _29$$11, "getdata", NULL, 0);
			zephir_check_call_status();
			zephir_array_fetch_string(&_30$$11, options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 138 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_31$$11);
			ZEPHIR_INIT_NVAR(_31$$11);
			zephir_var_export_ex(_31$$11, &data TSRMLS_CC);
			ZEPHIR_INIT_VAR(_32$$11);
			ZEPHIR_CONCAT_SVS(_32$$11, "<?php return ", _31$$11, ";");
			zephir_file_put_contents(NULL, _30$$11, _32$$11 TSRMLS_CC);
		}
	} else {
		_33$$12 = zephir_fetch_nproperty_this(this_ptr, SL("collector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&data, _33$$12, "getdata", NULL, 0);
		zephir_check_call_status();
	}
	_19 = zephir_fetch_nproperty_this(this_ptr, SL("dispatcher"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _19, "setdata", NULL, 0, data);
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

	zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, *uri = NULL, *module = NULL, *handler = NULL, *action = NULL, *params = NULL, *holders = NULL, *data = NULL, *route = NULL, *response = NULL, *_0, *_1, *_2, *_3$$4, *_7$$4, *_8$$4, *_9$$4, *_4$$5, *_5$$5 = NULL, *_6$$5 = NULL, *_11$$6, *_15$$6, *_16$$6, *_17$$6, *_12$$7, *_13$$7 = NULL, *_14$$7 = NULL, *_18$$10, _19$$10, _20$$10, *_21$$13, _22$$13, _23$$13, *_24$$16, _25$$16, _26$$16;

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
	zephir_array_fetch_long(&_2, route, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 170 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_2, 0)) {
			_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_3$$4)) {
				_4$$5 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_5$$5);
				ZVAL_STRING(_5$$5, "response", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&response, _4$$5, "get", NULL, 0, _5$$5);
				zephir_check_temp_parameter(_5$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_5$$5);
				ZVAL_LONG(_5$$5, 404);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", NULL, 0, _5$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_5$$5);
				ZVAL_LONG(_5$$5, 404);
				ZEPHIR_CALL_METHOD(&_6$$5, response, "getmessage", NULL, 0, _5$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 0, _6$$5);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_VAR(_7$$4);
			object_init_ex(_7$$4, ice_exception_ce);
			ZEPHIR_INIT_VAR(_8$$4);
			ZVAL_STRING(_8$$4, "The requested route could not be found", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_9$$4);
			ZVAL_LONG(_9$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, _7$$4, "__construct", &_10, 13, _8$$4, _9$$4);
			zephir_check_temp_parameter(_8$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$4, "ice/mvc/router.zep", 180 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(_2, 2)) {
			_11$$6 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
			if (zephir_is_true(_11$$6)) {
				_12$$7 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_13$$7);
				ZVAL_STRING(_13$$7, "response", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&response, _12$$7, "get", NULL, 0, _13$$7);
				zephir_check_temp_parameter(_13$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_13$$7);
				ZVAL_LONG(_13$$7, 405);
				ZEPHIR_CALL_METHOD(NULL, response, "setstatus", NULL, 0, _13$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_13$$7);
				ZVAL_LONG(_13$$7, 405);
				ZEPHIR_CALL_METHOD(&_14$$7, response, "getmessage", NULL, 0, _13$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, response, "setbody", NULL, 0, _14$$7);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_VAR(_15$$6);
			object_init_ex(_15$$6, ice_exception_ce);
			ZEPHIR_INIT_VAR(_16$$6);
			ZVAL_STRING(_16$$6, "A request was made of a resource using a request method not supported by that resource", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_17$$6);
			ZVAL_LONG(_17$$6, 2);
			ZEPHIR_CALL_METHOD(NULL, _15$$6, "__construct", &_10, 13, _16$$6, _17$$6);
			zephir_check_temp_parameter(_16$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_15$$6, "ice/mvc/router.zep", 190 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(_2, 1)) {
			ZEPHIR_OBS_VAR(holders);
			zephir_array_fetch_long(&holders, route, 1, PH_NOISY, "ice/mvc/router.zep", 192 TSRMLS_CC);
			ZEPHIR_OBS_VAR(data);
			zephir_array_fetch_long(&data, route, 2, PH_NOISY, "ice/mvc/router.zep", 193 TSRMLS_CC);
			ZEPHIR_OBS_VAR(module);
			if (!(zephir_array_isset_string_fetch(&module, holders, SS("module"), 0 TSRMLS_CC))) {
				ZEPHIR_OBS_NVAR(module);
				if (zephir_array_isset_string_fetch(&module, data, SS("module"), 0 TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(_18$$10);
					ZEPHIR_SINIT_VAR(_19$$10);
					ZVAL_STRING(&_19$$10, "/", 0);
					ZEPHIR_SINIT_VAR(_20$$10);
					ZVAL_STRING(&_20$$10, "", 0);
					zephir_fast_str_replace(&_18$$10, &_19$$10, &_20$$10, module TSRMLS_CC);
					ZEPHIR_CPY_WRT(module, _18$$10);
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
					ZEPHIR_INIT_VAR(_21$$13);
					ZEPHIR_SINIT_VAR(_22$$13);
					ZVAL_STRING(&_22$$13, "/", 0);
					ZEPHIR_SINIT_VAR(_23$$13);
					ZVAL_STRING(&_23$$13, "", 0);
					zephir_fast_str_replace(&_21$$13, &_22$$13, &_23$$13, handler TSRMLS_CC);
					ZEPHIR_CPY_WRT(handler, _21$$13);
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
					ZEPHIR_INIT_VAR(_24$$16);
					ZEPHIR_SINIT_VAR(_25$$16);
					ZVAL_STRING(&_25$$16, "/", 0);
					ZEPHIR_SINIT_VAR(_26$$16);
					ZVAL_STRING(&_26$$16, "", 0);
					zephir_fast_str_replace(&_24$$16, &_25$$16, &_26$$16, action TSRMLS_CC);
					ZEPHIR_CPY_WRT(action, _24$$16);
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

static zend_object_value zephir_init_properties_Ice_Mvc_Router(zend_class_entry *class_type TSRMLS_DC) {

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

