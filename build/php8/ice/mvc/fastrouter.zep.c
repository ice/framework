
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
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/concat.h"
#include "kernel/variables.h"


/**
 * Router is the standard framework router. Routing is the process of taking a URI endpoint and decomposing it into
 * parameters to determine which module, controller, and action of that controller should receive the request.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 * @uses        FastRoute http:/github.com/nikic/FastRoute
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_FastRouter)
{
	ZEPHIR_REGISTER_CLASS(Ice\\Mvc, FastRouter, ice, mvc_fastrouter, ice_mvc_fastrouter_method_entry, 0);

	zend_declare_property_string(ice_mvc_fastrouter_ce, SL("defaultModule"), "default", ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_mvc_fastrouter_ce, SL("defaultHandler"), "index", ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_mvc_fastrouter_ce, SL("defaultAction"), "index", ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("method"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("module"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("handler"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("action"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("params"), ZEND_ACC_PROTECTED);
	zend_declare_property_bool(ice_mvc_fastrouter_ce, SL("ready"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_bool(ice_mvc_fastrouter_ce, SL("silent"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("options"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("routes"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("collector"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_fastrouter_ce, SL("dispatcher"), ZEND_ACC_PROTECTED);
	ice_mvc_fastrouter_ce->create_object = zephir_init_properties_Ice_Mvc_FastRouter;
	zephir_declare_class_constant_long(ice_mvc_fastrouter_ce, SL("NOT_FOUND"), 0);

	zephir_declare_class_constant_long(ice_mvc_fastrouter_ce, SL("FOUND"), 1);

	zephir_declare_class_constant_long(ice_mvc_fastrouter_ce, SL("METHOD_NOT_ALLOWED"), 2);

	return SUCCESS;
}

PHP_METHOD(Ice_Mvc_FastRouter, getDefaultModule)
{

	RETURN_MEMBER(getThis(), "defaultModule");
}

PHP_METHOD(Ice_Mvc_FastRouter, setDefaultModule)
{
	zval *defaultModule, defaultModule_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultModule_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultModule", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultModule)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &defaultModule);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 205, defaultModule);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_FastRouter, getDefaultHandler)
{

	RETURN_MEMBER(getThis(), "defaultHandler");
}

PHP_METHOD(Ice_Mvc_FastRouter, setDefaultHandler)
{
	zval *defaultHandler, defaultHandler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultHandler_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultHandler", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultHandler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &defaultHandler);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 206, defaultHandler);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_FastRouter, getDefaultAction)
{

	RETURN_MEMBER(getThis(), "defaultAction");
}

PHP_METHOD(Ice_Mvc_FastRouter, setDefaultAction)
{
	zval *defaultAction, defaultAction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultAction_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultAction", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultAction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &defaultAction);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 207, defaultAction);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_FastRouter, getMethod)
{

	RETURN_MEMBER(getThis(), "method");
}

PHP_METHOD(Ice_Mvc_FastRouter, getModule)
{

	RETURN_MEMBER(getThis(), "module");
}

PHP_METHOD(Ice_Mvc_FastRouter, getHandler)
{

	RETURN_MEMBER(getThis(), "handler");
}

PHP_METHOD(Ice_Mvc_FastRouter, getAction)
{

	RETURN_MEMBER(getThis(), "action");
}

PHP_METHOD(Ice_Mvc_FastRouter, getParams)
{

	RETURN_MEMBER(getThis(), "params");
}

PHP_METHOD(Ice_Mvc_FastRouter, setSilent)
{
	zval *silent, silent_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&silent_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("silent", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(silent)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &silent);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 208, silent);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_FastRouter, getOptions)
{

	RETURN_MEMBER(getThis(), "options");
}

PHP_METHOD(Ice_Mvc_FastRouter, getRoutes)
{

	RETURN_MEMBER(getThis(), "routes");
}

PHP_METHOD(Ice_Mvc_FastRouter, setRoutes)
{
	zval *routes, routes_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routes_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(routes)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &routes);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 209, routes);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_FastRouter, getCollector)
{

	RETURN_MEMBER(getThis(), "collector");
}

PHP_METHOD(Ice_Mvc_FastRouter, setCollector)
{
	zval *collector, collector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collector_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("collector", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(collector)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &collector);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 210, collector);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_FastRouter, getDispatcher)
{

	RETURN_MEMBER(getThis(), "dispatcher");
}

PHP_METHOD(Ice_Mvc_FastRouter, setDispatcher)
{
	zval *dispatcher, dispatcher_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dispatcher_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dispatcher", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(dispatcher)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &dispatcher);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 211, dispatcher);
	RETURN_THISW();
}

/**
 * Set defaults values
 *
 * @param array defaults
 * @return object Router
 */
PHP_METHOD(Ice_Mvc_FastRouter, setDefaults)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaults_param = NULL, module, handler, action;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&action);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("defaultHandler", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("defaultAction", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(defaults, defaults_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &defaults_param);
	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);
	zephir_memory_observe(&module);
	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 205, &module);
	}
	zephir_memory_observe(&handler);
	if (zephir_array_isset_string_fetch(&handler, &defaults, SL("handler"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 206, &handler);
	}
	zephir_memory_observe(&action);
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 207, &action);
	}
	RETURN_THIS();
}

/**
 * Set options.
 *
 * @param array options
 * @return object Router
 */
PHP_METHOD(Ice_Mvc_FastRouter, setOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 212, &options);
	RETURN_THIS();
}

/**
 * Prepare the FastRoute.
 * @return object Router
 */
PHP_METHOD(Ice_Mvc_FastRouter, fastRoute)
{
	zend_bool _3, _5, _24, _29, _31;
	zval _0, _13$$4, _14$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$false, __$true, options, data, route, handler, _1, _2, _4, _6, _12, _16, *_17, _18, *_19, _23, _28, _30, _32, _35, _44, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _15$$4, _20$$5, _21$$5, _22$$5, _25$$6, _26$$6, _27$$6, _33$$7, _34$$7, _36$$8, _37$$10, _38$$10, _39$$11, _40$$11, _41$$11, _42$$11, _43$$12;
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
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$11);
	ZVAL_UNDEF(&_40$$11);
	ZVAL_UNDEF(&_41$$11);
	ZVAL_UNDEF(&_42$$11);
	ZVAL_UNDEF(&_43$$12);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("collector", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("routes", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("dispatcher", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("ready", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	add_assoc_stringl_ex(&_0, SL("routeParser"), SL("Ice\\Mvc\\Route\\Parser\\Std"));
	add_assoc_stringl_ex(&_0, SL("dataGenerator"), SL("Ice\\Mvc\\Route\\DataGenerator\\GroupCount"));
	add_assoc_stringl_ex(&_0, SL("dispatcher"), SL("Ice\\Mvc\\Route\\Dispatcher\\GroupCount"));
	zephir_array_update_string(&_0, SL("cache"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 212, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&options);
	zephir_fast_array_merge(&options, &_0, &_1);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 212, &options);
	zephir_memory_observe(&_2);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 210, PH_NOISY_CC);
	_3 = Z_TYPE_P(&_2) != IS_OBJECT;
	if (!(_3)) {
		zephir_memory_observe(&_4);
		zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 210, PH_NOISY_CC);
		_5 = Z_TYPE_P(&_4) == IS_OBJECT;
		if (_5) {
			zephir_memory_observe(&_6);
			zephir_read_property_cached(&_6, this_ptr, _zephir_prop_1, 210, PH_NOISY_CC);
			_5 = !(zephir_instance_of_ev(&_6, ice_mvc_route_collector_ce));
		}
		_3 = _5;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_7$$3);
		object_init_ex(&_7$$3, ice_mvc_route_collector_ce);
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_memory_observe(&_9$$3);
		zephir_array_fetch_string(&_9$$3, &options, SL("routeParser"), PH_NOISY, "ice/mvc/fastrouter.zep", 98);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&_8$$3, &_9$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$3);
		zephir_memory_observe(&_11$$3);
		zephir_array_fetch_string(&_11$$3, &options, SL("dataGenerator"), PH_NOISY, "ice/mvc/fastrouter.zep", 98);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&_10$$3, &_11$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$3, "__construct", NULL, 179, &_8$$3, &_10$$3);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 210, &_7$$3);
	}
	zephir_read_property_cached(&_12, this_ptr, _zephir_prop_2, 209, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_12))) {
		ZEPHIR_INIT_VAR(&_13$$4);
		zephir_create_array(&_13$$4, 3, 0);
		ZEPHIR_INIT_VAR(&_14$$4);
		zephir_create_array(&_14$$4, 2, 0);
		ZEPHIR_INIT_VAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "*");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		ZEPHIR_INIT_NVAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "/{controller:[a-z]+}/{action:[a-z]+}[/{param}]");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		zephir_array_fast_append(&_13$$4, &_14$$4);
		ZEPHIR_INIT_NVAR(&_14$$4);
		zephir_create_array(&_14$$4, 2, 0);
		ZEPHIR_INIT_NVAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "*");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		ZEPHIR_INIT_NVAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "/{controller:[a-z]+}");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		zephir_array_fast_append(&_13$$4, &_14$$4);
		ZEPHIR_INIT_NVAR(&_14$$4);
		zephir_create_array(&_14$$4, 2, 0);
		ZEPHIR_INIT_NVAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "*");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		ZEPHIR_INIT_NVAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "");
		zephir_array_fast_append(&_14$$4, &_15$$4);
		zephir_array_fast_append(&_13$$4, &_14$$4);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 209, &_13$$4);
	}
	zephir_read_property_cached(&_16, this_ptr, _zephir_prop_2, 209, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_16) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_18);
		zephir_string_to_char_array(&_18, &_16);
		_17 = &_18;
	} else {
		_17 = &_16;
	}
	zephir_is_iterable(_17, 0, "ice/mvc/fastrouter.zep", 115);
	if (Z_TYPE_P(_17) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_17), _19)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _19);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_isset_long_fetch(&handler, &route, 2, 0);
			zephir_read_property_cached(&_20$$5, this_ptr, _zephir_prop_1, 210, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&_21$$5);
			zephir_array_fetch_long(&_21$$5, &route, 0, PH_NOISY, "ice/mvc/fastrouter.zep", 112);
			ZEPHIR_OBS_NVAR(&_22$$5);
			zephir_array_fetch_long(&_22$$5, &route, 1, PH_NOISY, "ice/mvc/fastrouter.zep", 112);
			ZEPHIR_CALL_METHOD(NULL, &_20$$5, "addroute", NULL, 0, &_21$$5, &_22$$5, &handler);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _17, "rewind", NULL, 0);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _17, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_23, _17, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, _17, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_isset_long_fetch(&handler, &route, 2, 0);
				zephir_read_property_cached(&_25$$6, this_ptr, _zephir_prop_1, 210, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_26$$6);
				zephir_array_fetch_long(&_26$$6, &route, 0, PH_NOISY, "ice/mvc/fastrouter.zep", 112);
				ZEPHIR_OBS_NVAR(&_27$$6);
				zephir_array_fetch_long(&_27$$6, &route, 1, PH_NOISY, "ice/mvc/fastrouter.zep", 112);
				ZEPHIR_CALL_METHOD(NULL, &_25$$6, "addroute", NULL, 0, &_26$$6, &_27$$6, &handler);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	zephir_memory_observe(&_28);
	zephir_read_property_cached(&_28, this_ptr, _zephir_prop_3, 211, PH_NOISY_CC);
	_29 = Z_TYPE_P(&_28) != IS_OBJECT;
	if (!(_29)) {
		zephir_memory_observe(&_30);
		zephir_read_property_cached(&_30, this_ptr, _zephir_prop_3, 211, PH_NOISY_CC);
		_31 = Z_TYPE_P(&_30) == IS_OBJECT;
		if (_31) {
			zephir_memory_observe(&_32);
			zephir_read_property_cached(&_32, this_ptr, _zephir_prop_3, 211, PH_NOISY_CC);
			_31 = !(zephir_instance_of_ev(&_32, ice_mvc_route_dispatcher_dispatcherinterface_ce));
		}
		_29 = _31;
	}
	if (_29) {
		ZEPHIR_INIT_VAR(&_33$$7);
		zephir_memory_observe(&_34$$7);
		zephir_array_fetch_string(&_34$$7, &options, SL("dispatcher"), PH_NOISY, "ice/mvc/fastrouter.zep", 116);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&_33$$7, &_34$$7);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 211, &_33$$7);
	}
	zephir_memory_observe(&_35);
	zephir_array_fetch_string(&_35, &options, SL("cache"), PH_NOISY, "ice/mvc/fastrouter.zep", 119);
	if (zephir_is_true(&_35)) {
		if (!(zephir_array_isset_value_string(&options, SL("cacheFile")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Must specify 'cacheFile' option", "ice/mvc/fastrouter.zep", 121);
			return;
		}
		zephir_memory_observe(&_36$$8);
		zephir_array_fetch_string(&_36$$8, &options, SL("cacheFile"), PH_NOISY, "ice/mvc/fastrouter.zep", 124);
		if ((zephir_file_exists(&_36$$8) == SUCCESS)) {
			zephir_memory_observe(&_37$$10);
			zephir_array_fetch_string(&_37$$10, &options, SL("cacheFile"), PH_NOISY, "ice/mvc/fastrouter.zep", 125);
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_38$$10);
			if (zephir_require_zval_ret(&_38$$10, &_37$$10) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(&data, &_38$$10);
		} else {
			zephir_read_property_cached(&_39$$11, this_ptr, _zephir_prop_1, 210, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&data, &_39$$11, "getdata", NULL, 0);
			zephir_check_call_status();
			zephir_memory_observe(&_40$$11);
			zephir_array_fetch_string(&_40$$11, &options, SL("cacheFile"), PH_NOISY, "ice/mvc/fastrouter.zep", 129);
			ZEPHIR_INIT_VAR(&_41$$11);
			ZEPHIR_INIT_NVAR(&_41$$11);
			zephir_var_export_ex(&_41$$11, &data);
			ZEPHIR_INIT_VAR(&_42$$11);
			ZEPHIR_CONCAT_SVS(&_42$$11, "<?php return ", &_41$$11, ";");
			zephir_file_put_contents(NULL, &_40$$11, &_42$$11);
		}
	} else {
		zephir_read_property_cached(&_43$$12, this_ptr, _zephir_prop_1, 210, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&data, &_43$$12, "getdata", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_44, this_ptr, _zephir_prop_3, 211, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_44, "setdata", NULL, 0, &data);
	zephir_check_call_status();
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 213, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 213, &__$false);
	}
	RETURN_THIS();
}

/**
 * Handles routing information received from the FastRoute engine.
 *
 * @param string uri
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_FastRouter, handle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, method_sub, *uri = NULL, uri_sub, __$null, module, handler, action, params, holders, data, route, response, _0, _1, _2, _3$$4, _8$$4, _9$$4, _10$$4, _4$$5, _5$$5, _6$$5, _7$$5, _12$$6, _17$$6, _18$$6, _19$$6, _13$$7, _14$$7, _15$$7, _16$$7, _20$$10, _21$$10, _22$$10, _23$$13, _24$$13, _25$$13, _26$$16, _27$$16, _28$$16;
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
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$16);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("defaultHandler", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("defaultAction", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("ready", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("dispatcher", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("silent", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("method", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("module", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("handler", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("action", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("params", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(method)
		Z_PARAM_ZVAL_OR_NULL(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &method, &uri);
	if (!method) {
		method = &method_sub;
		method = &__$null;
	}
	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}
	zephir_memory_observe(&module);
	zephir_read_property_cached(&module, this_ptr, _zephir_prop_0, 205, PH_NOISY_CC);
	zephir_memory_observe(&handler);
	zephir_read_property_cached(&handler, this_ptr, _zephir_prop_1, 206, PH_NOISY_CC);
	zephir_memory_observe(&action);
	zephir_read_property_cached(&action, this_ptr, _zephir_prop_2, 207, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 213, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fastroute", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_4, 211, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&route, &_1, "dispatch", NULL, 0, method, uri);
	zephir_check_call_status();
	zephir_memory_observe(&_2);
	zephir_array_fetch_long(&_2, &route, 0, PH_NOISY, "ice/mvc/fastrouter.zep", 164);
	if (ZEPHIR_IS_LONG(&_2, 0)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&_2, 2)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&_2, 1)) { goto zephir_switch_0_clause_2; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_5, 208, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_3$$4)) {
			ZEPHIR_CALL_CE_STATIC(&_4$$5, ice_di_ce, "fetch", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "response");
			ZEPHIR_CALL_METHOD(&response, &_4$$5, "get", NULL, 0, &_5$$5);
			zephir_check_call_status();
			ZVAL_LONG(&_6$$5, 404);
			ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", NULL, 0, &_6$$5);
			zephir_check_call_status();
			ZVAL_LONG(&_6$$5, 404);
			ZEPHIR_CALL_METHOD(&_7$$5, &response, "getmessage", NULL, 0, &_6$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &response, "setbody", NULL, 0, &_7$$5);
			zephir_check_call_status();
			RETURN_CCTOR(&response);
		}
		ZEPHIR_INIT_VAR(&_8$$4);
		object_init_ex(&_8$$4, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "The requested route could not be found");
		ZVAL_LONG(&_10$$4, 0);
		ZEPHIR_CALL_METHOD(NULL, &_8$$4, "__construct", &_11, 13, &_9$$4, &_10$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$4, "ice/mvc/fastrouter.zep", 174);
		ZEPHIR_MM_RESTORE();
		return;
	zephir_switch_0_clause_1: ;
		zephir_read_property_cached(&_12$$6, this_ptr, _zephir_prop_5, 208, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_12$$6)) {
			ZEPHIR_CALL_CE_STATIC(&_13$$7, ice_di_ce, "fetch", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_14$$7);
			ZVAL_STRING(&_14$$7, "response");
			ZEPHIR_CALL_METHOD(&response, &_13$$7, "get", NULL, 0, &_14$$7);
			zephir_check_call_status();
			ZVAL_LONG(&_15$$7, 405);
			ZEPHIR_CALL_METHOD(NULL, &response, "setstatus", NULL, 0, &_15$$7);
			zephir_check_call_status();
			ZVAL_LONG(&_15$$7, 405);
			ZEPHIR_CALL_METHOD(&_16$$7, &response, "getmessage", NULL, 0, &_15$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &response, "setbody", NULL, 0, &_16$$7);
			zephir_check_call_status();
			RETURN_CCTOR(&response);
		}
		ZEPHIR_INIT_VAR(&_17$$6);
		object_init_ex(&_17$$6, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_18$$6);
		ZVAL_STRING(&_18$$6, "A request was made of a resource using a request method not supported by that resource");
		ZVAL_LONG(&_19$$6, 2);
		ZEPHIR_CALL_METHOD(NULL, &_17$$6, "__construct", &_11, 13, &_18$$6, &_19$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_17$$6, "ice/mvc/fastrouter.zep", 184);
		ZEPHIR_MM_RESTORE();
		return;
	zephir_switch_0_clause_2: ;
		zephir_memory_observe(&holders);
		zephir_array_fetch_long(&holders, &route, 1, PH_NOISY, "ice/mvc/fastrouter.zep", 186);
		zephir_memory_observe(&data);
		zephir_array_fetch_long(&data, &route, 2, PH_NOISY, "ice/mvc/fastrouter.zep", 187);
		ZEPHIR_OBS_NVAR(&module);
		if (!(zephir_array_isset_string_fetch(&module, &holders, SL("module"), 0))) {
			ZEPHIR_OBS_NVAR(&module);
			if (zephir_array_isset_string_fetch(&module, &data, SL("module"), 0)) {
				ZEPHIR_INIT_VAR(&_20$$10);
				ZEPHIR_INIT_VAR(&_21$$10);
				ZVAL_STRING(&_21$$10, "/");
				ZEPHIR_INIT_VAR(&_22$$10);
				ZVAL_STRING(&_22$$10, "");
				zephir_fast_str_replace(&_20$$10, &_21$$10, &_22$$10, &module);
				ZEPHIR_CPY_WRT(&module, &_20$$10);
				zephir_array_unset_string(&data, SL("module"), PH_SEPARATE);
			} else {
				ZEPHIR_OBS_NVAR(&module);
				zephir_read_property_cached(&module, this_ptr, _zephir_prop_0, 205, PH_NOISY_CC);
			}
		}
		ZEPHIR_OBS_NVAR(&handler);
		if (!(zephir_array_isset_string_fetch(&handler, &holders, SL("controller"), 0))) {
			ZEPHIR_OBS_NVAR(&handler);
			if (zephir_array_isset_string_fetch(&handler, &data, SL("controller"), 0)) {
				ZEPHIR_INIT_VAR(&_23$$13);
				ZEPHIR_INIT_VAR(&_24$$13);
				ZVAL_STRING(&_24$$13, "/");
				ZEPHIR_INIT_VAR(&_25$$13);
				ZVAL_STRING(&_25$$13, "");
				zephir_fast_str_replace(&_23$$13, &_24$$13, &_25$$13, &handler);
				ZEPHIR_CPY_WRT(&handler, &_23$$13);
				zephir_array_unset_string(&data, SL("controller"), PH_SEPARATE);
			} else {
				ZEPHIR_OBS_NVAR(&handler);
				zephir_read_property_cached(&handler, this_ptr, _zephir_prop_1, 206, PH_NOISY_CC);
			}
		}
		ZEPHIR_OBS_NVAR(&action);
		if (!(zephir_array_isset_string_fetch(&action, &holders, SL("action"), 0))) {
			ZEPHIR_OBS_NVAR(&action);
			if (zephir_array_isset_string_fetch(&action, &data, SL("action"), 0)) {
				ZEPHIR_INIT_VAR(&_26$$16);
				ZEPHIR_INIT_VAR(&_27$$16);
				ZVAL_STRING(&_27$$16, "/");
				ZEPHIR_INIT_VAR(&_28$$16);
				ZVAL_STRING(&_28$$16, "");
				zephir_fast_str_replace(&_26$$16, &_27$$16, &_28$$16, &action);
				ZEPHIR_CPY_WRT(&action, &_26$$16);
				zephir_array_unset_string(&data, SL("action"), PH_SEPARATE);
			} else {
				ZEPHIR_OBS_NVAR(&action);
				zephir_read_property_cached(&action, this_ptr, _zephir_prop_2, 207, PH_NOISY_CC);
			}
		}
		ZEPHIR_CPY_WRT(&params, &data);
		goto zephir_switch_0_end;
	zephir_switch_0_end: ;

	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 214, method);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 215, &module);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 216, &handler);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 217, &action);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 218, &params);
	zephir_create_array(return_value, 4, 0);
	zephir_array_update_string(return_value, SL("module"), &module, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("action"), &action, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("params"), &params, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

zend_object *zephir_init_properties_Ice_Mvc_FastRouter(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

