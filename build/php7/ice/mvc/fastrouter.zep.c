
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        FastRoute http:/github.com/nikic/FastRoute
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_FastRouter) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc, FastRouter, ice, mvc_fastrouter, ice_mvc_fastrouter_method_entry, 0);

	zend_declare_property_string(ice_mvc_fastrouter_ce, SL("defaultModule"), "default", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_fastrouter_ce, SL("defaultHandler"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_fastrouter_ce, SL("defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_mvc_fastrouter_ce, SL("ready"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_mvc_fastrouter_ce, SL("silent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("collector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("dispatcher"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_mvc_fastrouter_ce->create_object = zephir_init_properties_Ice_Mvc_FastRouter;
	zephir_declare_class_constant_long(ice_mvc_fastrouter_ce, SL("NOT_FOUND"), 0);

	zephir_declare_class_constant_long(ice_mvc_fastrouter_ce, SL("FOUND"), 1);

	zephir_declare_class_constant_long(ice_mvc_fastrouter_ce, SL("METHOD_NOT_ALLOWED"), 2);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_FastRouter, getDefaultModule) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultModule");

}

PHP_METHOD(Ice_Mvc_FastRouter, setDefaultModule) {

	zval *defaultModule, defaultModule_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultModule_sub);

	zephir_fetch_params(0, 1, 0, &defaultModule);



	zephir_update_property_zval(this_ptr, SL("defaultModule"), defaultModule);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_FastRouter, getDefaultHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultHandler");

}

PHP_METHOD(Ice_Mvc_FastRouter, setDefaultHandler) {

	zval *defaultHandler, defaultHandler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultHandler_sub);

	zephir_fetch_params(0, 1, 0, &defaultHandler);



	zephir_update_property_zval(this_ptr, SL("defaultHandler"), defaultHandler);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_FastRouter, getDefaultAction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultAction");

}

PHP_METHOD(Ice_Mvc_FastRouter, setDefaultAction) {

	zval *defaultAction, defaultAction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultAction_sub);

	zephir_fetch_params(0, 1, 0, &defaultAction);



	zephir_update_property_zval(this_ptr, SL("defaultAction"), defaultAction);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_FastRouter, getMethod) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "method");

}

PHP_METHOD(Ice_Mvc_FastRouter, getModule) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "module");

}

PHP_METHOD(Ice_Mvc_FastRouter, getHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handler");

}

PHP_METHOD(Ice_Mvc_FastRouter, getAction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "action");

}

PHP_METHOD(Ice_Mvc_FastRouter, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "params");

}

PHP_METHOD(Ice_Mvc_FastRouter, setSilent) {

	zval *silent, silent_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&silent_sub);

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_zval(this_ptr, SL("silent"), silent);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_FastRouter, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "options");

}

PHP_METHOD(Ice_Mvc_FastRouter, getRoutes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "routes");

}

PHP_METHOD(Ice_Mvc_FastRouter, setRoutes) {

	zval *routes, routes_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routes_sub);

	zephir_fetch_params(0, 1, 0, &routes);



	zephir_update_property_zval(this_ptr, SL("routes"), routes);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_FastRouter, getCollector) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "collector");

}

PHP_METHOD(Ice_Mvc_FastRouter, setCollector) {

	zval *collector, collector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collector_sub);

	zephir_fetch_params(0, 1, 0, &collector);



	zephir_update_property_zval(this_ptr, SL("collector"), collector);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_FastRouter, getDispatcher) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dispatcher");

}

PHP_METHOD(Ice_Mvc_FastRouter, setDispatcher) {

	zval *dispatcher, dispatcher_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dispatcher_sub);

	zephir_fetch_params(0, 1, 0, &dispatcher);



	zephir_update_property_zval(this_ptr, SL("dispatcher"), dispatcher);
	RETURN_THISW();

}

/**
 * Set defaults values
 *
 * @param array defaults
 * @return object Router
 */
PHP_METHOD(Ice_Mvc_FastRouter, setDefaults) {

	zval *defaults_param = NULL, module, handler, action;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&action);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults_param);

	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);


	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultModule"), &module);
	}
	if (zephir_array_isset_string_fetch(&handler, &defaults, SL("handler"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultHandler"), &handler);
	}
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultAction"), &action);
	}
	RETURN_THIS();

}

/**
 * Set options.
 *
 * @param array options
 * @return object Router
 */
PHP_METHOD(Ice_Mvc_FastRouter, setOptions) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("options"), &options);
	RETURN_THIS();

}

/**
 * Prepare the FastRoute.
 * @return object Router
 */
PHP_METHOD(Ice_Mvc_FastRouter, fastRoute) {

	zend_bool _3, _5, _22, _24;
	zval _0, _13$$4, _14$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$false, __$true, options, data, route, handler, _1, _2, _4, _6, _12, _16, *_17, _21, _23, _25, _28, _37, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _15$$4, _18$$5, _19$$5, _20$$5, _26$$6, _27$$6, _29$$7, _30$$9, _31$$9, _32$$10, _33$$10, _34$$10, _35$$10, _36$$11;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_36$$11);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_0, SL("routeParser"), SL("Ice\\Mvc\\Route\\Parser\\Std"));
	add_assoc_stringl_ex(&_0, SL("dataGenerator"), SL("Ice\\Mvc\\Route\\DataGenerator\\GroupCount"));
	add_assoc_stringl_ex(&_0, SL("dispatcher"), SL("Ice\\Mvc\\Route\\Dispatcher\\GroupCount"));
	zephir_array_update_string(&_0, SL("cache"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_1, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&options);
	zephir_fast_array_merge(&options, &_0, &_1 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("collector"), PH_NOISY_CC);
	_3 = Z_TYPE_P(&_2) != IS_OBJECT;
	if (!(_3)) {
		ZEPHIR_OBS_VAR(&_4);
		zephir_read_property(&_4, this_ptr, SL("collector"), PH_NOISY_CC);
		_5 = Z_TYPE_P(&_4) == IS_OBJECT;
		if (_5) {
			ZEPHIR_OBS_VAR(&_6);
			zephir_read_property(&_6, this_ptr, SL("collector"), PH_NOISY_CC);
			_5 = !(zephir_instance_of_ev(&_6, ice_mvc_route_collector_ce TSRMLS_CC));
		}
		_3 = _5;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_7$$3);
		object_init_ex(&_7$$3, ice_mvc_route_collector_ce);
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_array_fetch_string(&_9$$3, &options, SL("routeParser"), PH_NOISY | PH_READONLY, "ice/mvc/fastrouter.zep", 99 TSRMLS_CC);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&_8$$3, &_9$$3 TSRMLS_CC);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$3);
		zephir_array_fetch_string(&_11$$3, &options, SL("dataGenerator"), PH_NOISY | PH_READONLY, "ice/mvc/fastrouter.zep", 99 TSRMLS_CC);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&_10$$3, &_11$$3 TSRMLS_CC);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$3, "__construct", NULL, 150, &_8$$3, &_10$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("collector"), &_7$$3);
	}
	zephir_read_property(&_12, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_12))) {
		ZEPHIR_INIT_VAR(&_13$$4);
		zephir_create_array(&_13$$4, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_14$$4);
		zephir_create_array(&_14$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "*");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		ZEPHIR_INIT_NVAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "/{controller:[a-z]+}/{action:[a-z]+}[/{param}]");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		zephir_array_fast_append(&_13$$4, &_14$$4);
		ZEPHIR_INIT_NVAR(&_14$$4);
		zephir_create_array(&_14$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "*");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		ZEPHIR_INIT_NVAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "/{controller:[a-z]+}");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		zephir_array_fast_append(&_13$$4, &_14$$4);
		ZEPHIR_INIT_NVAR(&_14$$4);
		zephir_create_array(&_14$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "*");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		ZEPHIR_INIT_NVAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		zephir_array_fast_append(&_13$$4, &_14$$4);
		zephir_update_property_zval(this_ptr, SL("routes"), &_13$$4);
	}
	zephir_read_property(&_16, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_16, 0, "ice/mvc/fastrouter.zep", 116);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_16), _17)
	{
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _17);
		ZEPHIR_OBS_NVAR(&handler);
		zephir_array_isset_long_fetch(&handler, &route, 2, 0 TSRMLS_CC);
		zephir_read_property(&_18$$5, this_ptr, SL("collector"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_19$$5, &route, 0, PH_NOISY | PH_READONLY, "ice/mvc/fastrouter.zep", 113 TSRMLS_CC);
		zephir_array_fetch_long(&_20$$5, &route, 1, PH_NOISY | PH_READONLY, "ice/mvc/fastrouter.zep", 113 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_18$$5, "addroute", NULL, 0, &_19$$5, &_20$$5, &handler);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_OBS_VAR(&_21);
	zephir_read_property(&_21, this_ptr, SL("dispatcher"), PH_NOISY_CC);
	_22 = Z_TYPE_P(&_21) != IS_OBJECT;
	if (!(_22)) {
		ZEPHIR_OBS_VAR(&_23);
		zephir_read_property(&_23, this_ptr, SL("dispatcher"), PH_NOISY_CC);
		_24 = Z_TYPE_P(&_23) == IS_OBJECT;
		if (_24) {
			ZEPHIR_OBS_VAR(&_25);
			zephir_read_property(&_25, this_ptr, SL("dispatcher"), PH_NOISY_CC);
			_24 = !(zephir_instance_of_ev(&_25, ice_mvc_route_dispatcher_dispatcherinterface_ce TSRMLS_CC));
		}
		_22 = _24;
	}
	if (_22) {
		ZEPHIR_INIT_VAR(&_26$$6);
		zephir_array_fetch_string(&_27$$6, &options, SL("dispatcher"), PH_NOISY | PH_READONLY, "ice/mvc/fastrouter.zep", 117 TSRMLS_CC);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&_26$$6, &_27$$6 TSRMLS_CC);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("dispatcher"), &_26$$6);
	}
	zephir_array_fetch_string(&_28, &options, SL("cache"), PH_NOISY | PH_READONLY, "ice/mvc/fastrouter.zep", 120 TSRMLS_CC);
	if (zephir_is_true(&_28)) {
		if (!(zephir_array_isset_string(&options, SL("cacheFile")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Must specify 'cacheFile' option", "ice/mvc/fastrouter.zep", 122);
			return;
		}
		zephir_array_fetch_string(&_29$$7, &options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/fastrouter.zep", 125 TSRMLS_CC);
		if ((zephir_file_exists(&_29$$7 TSRMLS_CC) == SUCCESS)) {
			zephir_array_fetch_string(&_30$$9, &options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/fastrouter.zep", 126 TSRMLS_CC);
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_31$$9);
			if (zephir_require_zval_ret(&_31$$9, &_30$$9 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(&data, &_31$$9);
		} else {
			zephir_read_property(&_32$$10, this_ptr, SL("collector"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&data, &_32$$10, "getdata", NULL, 0);
			zephir_check_call_status();
			zephir_array_fetch_string(&_33$$10, &options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/fastrouter.zep", 130 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_34$$10);
			ZEPHIR_INIT_NVAR(&_34$$10);
			zephir_var_export_ex(&_34$$10, &data TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_35$$10);
			ZEPHIR_CONCAT_SVS(&_35$$10, "<?php return ", &_34$$10, ";");
			zephir_file_put_contents(NULL, &_33$$10, &_35$$10 TSRMLS_CC);
		}
	} else {
		zephir_read_property(&_36$$11, this_ptr, SL("collector"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&data, &_36$$11, "getdata", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_37, this_ptr, SL("dispatcher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_37, "setdata", NULL, 0, &data);
	zephir_check_call_status();
	if (1) {
		zephir_update_property_zval(this_ptr, SL("ready"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("ready"), &__$false);
	}
	RETURN_THIS();

}

/**
 * Handles routing information received from the FastRoute engine.
 *
 * @param string uri
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_FastRouter, handle) {

	zephir_fcall_cache_entry *_5 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, method_sub, *uri = NULL, uri_sub, __$null, module, handler, action, params, holders, data, route, response, _0, _1, _2, _3$$4, _9$$4, _10$$4, _11$$4, _4$$5, _6$$5, _7$$5, _8$$5, _13$$6, _18$$6, _19$$6, _20$$6, _14$$7, _15$$7, _16$$7, _17$$7, _21$$10, _22$$10, _23$$10, _24$$13, _25$$13, _26$$13, _27$$16, _28$$16, _29$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&holders);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &method, &uri);

	if (!method) {
		method = &method_sub;
		method = &__$null;
	}
	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}


	ZEPHIR_OBS_VAR(&handler);
	zephir_read_property(&handler, this_ptr, SL("defaultHandler"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&action);
	zephir_read_property(&action, this_ptr, SL("defaultAction"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	zephir_read_property(&_0, this_ptr, SL("ready"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fastroute", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("dispatcher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&route, &_1, "dispatch", NULL, 0, method, uri);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &route, 0, PH_NOISY | PH_READONLY, "ice/mvc/fastrouter.zep", 164 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(&_2, 0)) {
			zephir_read_property(&_3$$4, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_3$$4)) {
				ZEPHIR_CALL_CE_STATIC(&_4$$5, ice_di_ce, "fetch", &_5, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_6$$5);
				ZVAL_STRING(&_6$$5, "response");
				ZEPHIR_CALL_METHOD(&response, &_4$$5, "get", NULL, 0, &_6$$5);
				zephir_check_call_status();
				ZVAL_LONG(&_7$$5, 404);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", NULL, 0, &_7$$5);
				zephir_check_call_status();
				ZVAL_LONG(&_7$$5, 404);
				ZEPHIR_CALL_METHOD(&_8$$5, &response, "getmessage", NULL, 0, &_7$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", NULL, 0, &_8$$5);
				zephir_check_call_status();
				RETURN_CCTOR(&response);
			}
			ZEPHIR_INIT_VAR(&_9$$4);
			object_init_ex(&_9$$4, ice_exception_ce);
			ZEPHIR_INIT_VAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "The requested route could not be found");
			ZVAL_LONG(&_11$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, &_9$$4, "__construct", &_12, 12, &_10$$4, &_11$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$4, "ice/mvc/fastrouter.zep", 174 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(&_2, 2)) {
			zephir_read_property(&_13$$6, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_13$$6)) {
				ZEPHIR_CALL_CE_STATIC(&_14$$7, ice_di_ce, "fetch", &_5, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_15$$7);
				ZVAL_STRING(&_15$$7, "response");
				ZEPHIR_CALL_METHOD(&response, &_14$$7, "get", NULL, 0, &_15$$7);
				zephir_check_call_status();
				ZVAL_LONG(&_16$$7, 405);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", NULL, 0, &_16$$7);
				zephir_check_call_status();
				ZVAL_LONG(&_16$$7, 405);
				ZEPHIR_CALL_METHOD(&_17$$7, &response, "getmessage", NULL, 0, &_16$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", NULL, 0, &_17$$7);
				zephir_check_call_status();
				RETURN_CCTOR(&response);
			}
			ZEPHIR_INIT_VAR(&_18$$6);
			object_init_ex(&_18$$6, ice_exception_ce);
			ZEPHIR_INIT_VAR(&_19$$6);
			ZVAL_STRING(&_19$$6, "A request was made of a resource using a request method not supported by that resource");
			ZVAL_LONG(&_20$$6, 2);
			ZEPHIR_CALL_METHOD(NULL, &_18$$6, "__construct", &_12, 12, &_19$$6, &_20$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_18$$6, "ice/mvc/fastrouter.zep", 184 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(&_2, 1)) {
			ZEPHIR_OBS_VAR(&holders);
			zephir_array_fetch_long(&holders, &route, 1, PH_NOISY, "ice/mvc/fastrouter.zep", 186 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&data);
			zephir_array_fetch_long(&data, &route, 2, PH_NOISY, "ice/mvc/fastrouter.zep", 187 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&module);
			if (!(zephir_array_isset_string_fetch(&module, &holders, SL("module"), 0))) {
				ZEPHIR_OBS_NVAR(&module);
				if (zephir_array_isset_string_fetch(&module, &data, SL("module"), 0)) {
					ZEPHIR_INIT_VAR(&_21$$10);
					ZEPHIR_INIT_VAR(&_22$$10);
					ZVAL_STRING(&_22$$10, "/");
					ZEPHIR_INIT_VAR(&_23$$10);
					ZVAL_STRING(&_23$$10, "");
					zephir_fast_str_replace(&_21$$10, &_22$$10, &_23$$10, &module TSRMLS_CC);
					ZEPHIR_CPY_WRT(&module, &_21$$10);
					zephir_array_unset_string(&data, SL("module"), PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(&module);
					zephir_read_property(&module, this_ptr, SL("defaultModule"), PH_NOISY_CC);
				}
			}
			ZEPHIR_OBS_NVAR(&handler);
			if (!(zephir_array_isset_string_fetch(&handler, &holders, SL("controller"), 0))) {
				ZEPHIR_OBS_NVAR(&handler);
				if (zephir_array_isset_string_fetch(&handler, &data, SL("controller"), 0)) {
					ZEPHIR_INIT_VAR(&_24$$13);
					ZEPHIR_INIT_VAR(&_25$$13);
					ZVAL_STRING(&_25$$13, "/");
					ZEPHIR_INIT_VAR(&_26$$13);
					ZVAL_STRING(&_26$$13, "");
					zephir_fast_str_replace(&_24$$13, &_25$$13, &_26$$13, &handler TSRMLS_CC);
					ZEPHIR_CPY_WRT(&handler, &_24$$13);
					zephir_array_unset_string(&data, SL("controller"), PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(&handler);
					zephir_read_property(&handler, this_ptr, SL("defaultHandler"), PH_NOISY_CC);
				}
			}
			ZEPHIR_OBS_NVAR(&action);
			if (!(zephir_array_isset_string_fetch(&action, &holders, SL("action"), 0))) {
				ZEPHIR_OBS_NVAR(&action);
				if (zephir_array_isset_string_fetch(&action, &data, SL("action"), 0)) {
					ZEPHIR_INIT_VAR(&_27$$16);
					ZEPHIR_INIT_VAR(&_28$$16);
					ZVAL_STRING(&_28$$16, "/");
					ZEPHIR_INIT_VAR(&_29$$16);
					ZVAL_STRING(&_29$$16, "");
					zephir_fast_str_replace(&_27$$16, &_28$$16, &_29$$16, &action TSRMLS_CC);
					ZEPHIR_CPY_WRT(&action, &_27$$16);
					zephir_array_unset_string(&data, SL("action"), PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(&action);
					zephir_read_property(&action, this_ptr, SL("defaultAction"), PH_NOISY_CC);
				}
			}
			ZEPHIR_CPY_WRT(&params, &data);
			break;
		}
	} while(0);

	zephir_update_property_zval(this_ptr, SL("method"), method);
	zephir_update_property_zval(this_ptr, SL("module"), &module);
	zephir_update_property_zval(this_ptr, SL("handler"), &handler);
	zephir_update_property_zval(this_ptr, SL("action"), &action);
	zephir_update_property_zval(this_ptr, SL("params"), &params);
	zephir_create_array(return_value, 4, 0 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("module"), &module, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("action"), &action, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("params"), &params, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

zend_object *zephir_init_properties_Ice_Mvc_FastRouter(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("params"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

