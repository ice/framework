
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
	zephir_declare_class_constant_long(ice_mvc_router_ce, SL("NOT_FOUND"), 0);

	zephir_declare_class_constant_long(ice_mvc_router_ce, SL("FOUND"), 1);

	zephir_declare_class_constant_long(ice_mvc_router_ce, SL("METHOD_NOT_ALLOWED"), 2);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Router, getDefaultModule) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "defaultModule");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultModule) {

	zval *defaultModule, defaultModule_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&defaultModule_sub);

	zephir_fetch_params(0, 1, 0, &defaultModule);



	zephir_update_property_zval(this_ptr, SL("defaultModule"), defaultModule);

}

PHP_METHOD(Ice_Mvc_Router, getDefaultHandler) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "defaultHandler");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultHandler) {

	zval *defaultHandler, defaultHandler_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&defaultHandler_sub);

	zephir_fetch_params(0, 1, 0, &defaultHandler);



	zephir_update_property_zval(this_ptr, SL("defaultHandler"), defaultHandler);

}

PHP_METHOD(Ice_Mvc_Router, getDefaultAction) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "defaultAction");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultAction) {

	zval *defaultAction, defaultAction_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&defaultAction_sub);

	zephir_fetch_params(0, 1, 0, &defaultAction);



	zephir_update_property_zval(this_ptr, SL("defaultAction"), defaultAction);

}

PHP_METHOD(Ice_Mvc_Router, getMethod) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "method");

}

PHP_METHOD(Ice_Mvc_Router, getModule) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "module");

}

PHP_METHOD(Ice_Mvc_Router, getHandler) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "handler");

}

PHP_METHOD(Ice_Mvc_Router, getAction) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "action");

}

PHP_METHOD(Ice_Mvc_Router, getParams) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "params");

}

PHP_METHOD(Ice_Mvc_Router, setSilent) {

	zval *silent, silent_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&silent_sub);

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_zval(this_ptr, SL("silent"), silent);

}

PHP_METHOD(Ice_Mvc_Router, getOptions) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "options");

}

PHP_METHOD(Ice_Mvc_Router, setOptions) {

	zval *options, options_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&options_sub);

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_zval(this_ptr, SL("options"), options);

}

PHP_METHOD(Ice_Mvc_Router, getRoutes) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "routes");

}

PHP_METHOD(Ice_Mvc_Router, setRoutes) {

	zval *routes, routes_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&routes_sub);

	zephir_fetch_params(0, 1, 0, &routes);



	zephir_update_property_zval(this_ptr, SL("routes"), routes);

}

PHP_METHOD(Ice_Mvc_Router, getCollector) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "collector");

}

PHP_METHOD(Ice_Mvc_Router, setCollector) {

	zval *collector, collector_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&collector_sub);

	zephir_fetch_params(0, 1, 0, &collector);



	zephir_update_property_zval(this_ptr, SL("collector"), collector);

}

PHP_METHOD(Ice_Mvc_Router, getDispatcher) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "dispatcher");

}

PHP_METHOD(Ice_Mvc_Router, setDispatcher) {

	zval *dispatcher, dispatcher_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&dispatcher_sub);

	zephir_fetch_params(0, 1, 0, &dispatcher);



	zephir_update_property_zval(this_ptr, SL("dispatcher"), dispatcher);

}

/**
 * Router constructor. Fetch Di and set it as a property.
 */
PHP_METHOD(Ice_Mvc_Router, __construct) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, ice_di_ce, "fetch", &_1, 8);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("di"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set defaults values
 *
 * @param array defaults
 */
PHP_METHOD(Ice_Mvc_Router, setDefaults) {

	zval *defaults_param = NULL, module, handler, action;
	zval defaults;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&action);

	zephir_fetch_params(0, 1, 0, &defaults_param);

	ZVAL_COPY_VALUE(&defaults, defaults_param);


	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultModule"), &module);
	}
	if (zephir_array_isset_string_fetch(&handler, &defaults, SL("handler"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultHandler"), &handler);
	}
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultAction"), &action);
	}

}

/**
 * Prepare the FastRoute.
 */
PHP_METHOD(Ice_Mvc_Router, fastRoute) {

	zend_class_entry *_8$$3, *_11$$3, *_22$$7;
	zend_bool _3, _4, _18, _19;
	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval __$false, __$true, options, dispatcher, data, collector, parser, generator, route, handler, _1, _2, _17, _23, _5$$3, _6$$3, _7$$3, _9$$3, _10$$3, _12$$5, *_13$$5, _14$$6, _15$$6, _16$$6, _20$$7, _21$$7, _24$$8, _25$$10, _26$$10, _27$$11, _28$$11, _29$$11, _30$$11, _31$$12;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&collector);
	ZVAL_UNDEF(&parser);
	ZVAL_UNDEF(&generator);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_0);

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
	zephir_read_property(&_2, this_ptr, SL("collector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&collector, &_2);
	_3 = Z_TYPE_P(&collector) != IS_OBJECT;
	if (!(_3)) {
		_4 = Z_TYPE_P(&collector) == IS_OBJECT;
		if (_4) {
			_4 = !((zephir_instance_of_ev(&collector, ice_mvc_route_collector_ce TSRMLS_CC)));
		}
		_3 = _4;
	}
	if (_3) {
		ZEPHIR_OBS_VAR(&parser);
		zephir_array_isset_string_fetch(&parser, &options, SL("routeParser"), 0);
		ZEPHIR_OBS_VAR(&generator);
		zephir_array_isset_string_fetch(&generator, &options, SL("dataGenerator"), 0);
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, ice_mvc_route_collector_ce);
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_fetch_safe_class(_7$$3, parser);
		_8$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_7$$3), Z_STRLEN_P(&_7$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_6$$3, _8$$3);
		if (zephir_has_constructor(&_6$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_6$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_fetch_safe_class(_10$$3, generator);
		_11$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_10$$3), Z_STRLEN_P(&_10$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_9$$3, _11$$3);
		if (zephir_has_constructor(&_9$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_9$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 123, &_6$$3, &_9$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("collector"), &_5$$3);
	}
	zephir_read_property(&_2, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "There are no routes.", "ice/mvc/router.zep", 100);
		return;
	} else {
		zephir_read_property(&_12$$5, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_12$$5, 0, "ice/mvc/router.zep", 106);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_12$$5), _13$$5)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _13$$5);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_isset_long_fetch(&handler, &route, 2, 0 TSRMLS_CC);
			zephir_read_property(&_14$$6, this_ptr, SL("collector"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_long(&_15$$6, &route, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 104 TSRMLS_CC);
			zephir_array_fetch_long(&_16$$6, &route, 1, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 104 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &_14$$6, "addroute", NULL, 0, &_15$$6, &_16$$6, &handler);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&route);
	}
	zephir_read_property(&_17, this_ptr, SL("dispatcher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dispatcher, &_17);
	_18 = Z_TYPE_P(&dispatcher) != IS_OBJECT;
	if (!(_18)) {
		_19 = Z_TYPE_P(&dispatcher) == IS_OBJECT;
		if (_19) {
			_19 = !((zephir_instance_of_ev(&dispatcher, ice_mvc_route_dispatcher_dispatcherinterface_ce TSRMLS_CC)));
		}
		_18 = _19;
	}
	if (_18) {
		ZEPHIR_OBS_NVAR(&dispatcher);
		zephir_array_fetch_string(&dispatcher, &options, SL("dispatcher"), PH_NOISY, "ice/mvc/router.zep", 111 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_20$$7);
		zephir_fetch_safe_class(_21$$7, dispatcher);
		_22$$7 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_21$$7), Z_STRLEN_P(&_21$$7), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_20$$7, _22$$7);
		if (zephir_has_constructor(&_20$$7 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_20$$7, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("dispatcher"), &_20$$7);
	}
	zephir_array_fetch_string(&_23, &options, SL("cache"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 115 TSRMLS_CC);
	if (zephir_is_true(&_23)) {
		if (!(zephir_array_isset_string(&options, SL("cacheFile")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Must specify 'cacheFile' option", "ice/mvc/router.zep", 117);
			return;
		}
		zephir_array_fetch_string(&_24$$8, &options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 120 TSRMLS_CC);
		if ((zephir_file_exists(&_24$$8 TSRMLS_CC) == SUCCESS)) {
			zephir_array_fetch_string(&_25$$10, &options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 121 TSRMLS_CC);
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_26$$10);
			if (zephir_require_zval_ret(&_26$$10, &_25$$10 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(&data, &_26$$10);
		} else {
			zephir_read_property(&_27$$11, this_ptr, SL("collector"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&data, &_27$$11, "getdata", NULL, 0);
			zephir_check_call_status();
			zephir_array_fetch_string(&_28$$11, &options, SL("cacheFile"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 125 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_29$$11);
			ZEPHIR_INIT_NVAR(&_29$$11);
			zephir_var_export_ex(&_29$$11, &data TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_30$$11);
			ZEPHIR_CONCAT_SVS(&_30$$11, "<?php return ", &_29$$11, ";");
			zephir_file_put_contents(NULL, &_28$$11, &_30$$11 TSRMLS_CC);
		}
	} else {
		zephir_read_property(&_31$$12, this_ptr, SL("collector"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&data, &_31$$12, "getdata", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_17, this_ptr, SL("dispatcher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_17, "setdata", NULL, 0, &data);
	zephir_check_call_status();
	if (1) {
		zephir_update_property_zval(this_ptr, SL("ready"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("ready"), &__$false);
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

	zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, method_sub, *uri = NULL, uri_sub, __$null, module, handler, action, params, holders, data, route, response, _0, _1, _2, _3$$4, _9$$4, _10$$4, _11$$4, _4$$5, _5$$5, _6$$5, _7$$5, _8$$5, _13$$6, _19$$6, _20$$6, _21$$6, _14$$7, _15$$7, _16$$7, _17$$7, _18$$7, _22$$10, _23$$10, _24$$10, _25$$13, _26$$13, _27$$13, _28$$16, _29$$16, _30$$16;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
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
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_30$$16);

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
	zephir_array_fetch_long(&_2, &route, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 157 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(&_2, 0)) {
			zephir_read_property(&_3$$4, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_3$$4)) {
				zephir_read_property(&_4$$5, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "response");
				ZVAL_NULL(&_6$$5);
				ZVAL_BOOL(&_7$$5, 1);
				ZEPHIR_CALL_METHOD(&response, &_4$$5, "get", NULL, 0, &_5$$5, &_6$$5, &_7$$5);
				zephir_check_call_status();
				ZVAL_LONG(&_6$$5, 404);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", NULL, 0, &_6$$5);
				zephir_check_call_status();
				ZVAL_LONG(&_6$$5, 404);
				ZEPHIR_CALL_METHOD(&_8$$5, &response, "getmessage", NULL, 0, &_6$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", NULL, 0, &_8$$5);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_VAR(&_9$$4);
			object_init_ex(&_9$$4, ice_exception_ce);
			ZEPHIR_INIT_VAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "The requested route could not be found");
			ZVAL_LONG(&_11$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, &_9$$4, "__construct", &_12, 2, &_10$$4, &_11$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$4, "ice/mvc/router.zep", 167 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(&_2, 2)) {
			zephir_read_property(&_13$$6, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_13$$6)) {
				zephir_read_property(&_14$$7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_15$$7);
				ZVAL_STRING(&_15$$7, "response");
				ZVAL_NULL(&_16$$7);
				ZVAL_BOOL(&_17$$7, 1);
				ZEPHIR_CALL_METHOD(&response, &_14$$7, "get", NULL, 0, &_15$$7, &_16$$7, &_17$$7);
				zephir_check_call_status();
				ZVAL_LONG(&_16$$7, 405);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", NULL, 0, &_16$$7);
				zephir_check_call_status();
				ZVAL_LONG(&_16$$7, 405);
				ZEPHIR_CALL_METHOD(&_18$$7, &response, "getmessage", NULL, 0, &_16$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setbody", NULL, 0, &_18$$7);
				zephir_check_call_status();
				RETURN_CCTOR(response);
			}
			ZEPHIR_INIT_VAR(&_19$$6);
			object_init_ex(&_19$$6, ice_exception_ce);
			ZEPHIR_INIT_VAR(&_20$$6);
			ZVAL_STRING(&_20$$6, "A request was made of a resource using a request method not supported by that resource");
			ZVAL_LONG(&_21$$6, 2);
			ZEPHIR_CALL_METHOD(NULL, &_19$$6, "__construct", &_12, 2, &_20$$6, &_21$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_19$$6, "ice/mvc/router.zep", 177 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(&_2, 1)) {
			ZEPHIR_OBS_VAR(&holders);
			zephir_array_fetch_long(&holders, &route, 1, PH_NOISY, "ice/mvc/router.zep", 179 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&data);
			zephir_array_fetch_long(&data, &route, 2, PH_NOISY, "ice/mvc/router.zep", 180 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&module);
			if (!(zephir_array_isset_string_fetch(&module, &holders, SL("module"), 0))) {
				ZEPHIR_OBS_NVAR(&module);
				if (zephir_array_isset_string_fetch(&module, &data, SL("module"), 0)) {
					ZEPHIR_INIT_VAR(&_22$$10);
					ZEPHIR_INIT_VAR(&_23$$10);
					ZVAL_STRING(&_23$$10, "/");
					ZEPHIR_INIT_VAR(&_24$$10);
					ZVAL_STRING(&_24$$10, "");
					zephir_fast_str_replace(&_22$$10, &_23$$10, &_24$$10, &module TSRMLS_CC);
					ZEPHIR_CPY_WRT(&module, &_22$$10);
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
					ZEPHIR_INIT_VAR(&_25$$13);
					ZEPHIR_INIT_VAR(&_26$$13);
					ZVAL_STRING(&_26$$13, "/");
					ZEPHIR_INIT_VAR(&_27$$13);
					ZVAL_STRING(&_27$$13, "");
					zephir_fast_str_replace(&_25$$13, &_26$$13, &_27$$13, &handler TSRMLS_CC);
					ZEPHIR_CPY_WRT(&handler, &_25$$13);
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
					ZEPHIR_INIT_VAR(&_28$$16);
					ZEPHIR_INIT_VAR(&_29$$16);
					ZVAL_STRING(&_29$$16, "/");
					ZEPHIR_INIT_VAR(&_30$$16);
					ZVAL_STRING(&_30$$16, "");
					zephir_fast_str_replace(&_28$$16, &_29$$16, &_30$$16, &action TSRMLS_CC);
					ZEPHIR_CPY_WRT(&action, &_28$$16);
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

static zend_object *zephir_init_properties_Ice_Mvc_Router(zend_class_entry *class_type TSRMLS_DC) {

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

