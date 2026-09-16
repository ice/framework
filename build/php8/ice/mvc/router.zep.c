
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
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/variables.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * Router is the standard framework router. Routing is the process of taking a URI endpoint and decomposing it into
 * parameters to determine which module, controller, and action of that controller should receive the request.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Router)
{
	ZEPHIR_REGISTER_CLASS(Ice\\Mvc, Router, ice, mvc_router, ice_mvc_router_method_entry, 0);

	zend_declare_property_null(ice_mvc_router_ce, SL("routes"), ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_mvc_router_ce, SL("route"), "default", ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_router_ce, SL("method"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_router_ce, SL("module"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_router_ce, SL("handler"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_router_ce, SL("action"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(ice_mvc_router_ce, SL("params"), ZEND_ACC_PROTECTED);
	zend_declare_property_bool(ice_mvc_router_ce, SL("silent"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_mvc_router_ce, SL("defaultModule"), "default", ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_mvc_router_ce, SL("defaultHandler"), "index", ZEND_ACC_PROTECTED);
	zend_declare_property_string(ice_mvc_router_ce, SL("defaultAction"), "index", ZEND_ACC_PROTECTED);
	ice_mvc_router_ce->create_object = zephir_init_properties_Ice_Mvc_Router;

	return SUCCESS;
}

PHP_METHOD(Ice_Mvc_Router, getRoutes)
{

	RETURN_MEMBER(getThis(), "routes");
}

PHP_METHOD(Ice_Mvc_Router, getMethod)
{

	RETURN_MEMBER(getThis(), "method");
}

PHP_METHOD(Ice_Mvc_Router, getModule)
{

	RETURN_MEMBER(getThis(), "module");
}

PHP_METHOD(Ice_Mvc_Router, getHandler)
{

	RETURN_MEMBER(getThis(), "handler");
}

PHP_METHOD(Ice_Mvc_Router, getAction)
{

	RETURN_MEMBER(getThis(), "action");
}

PHP_METHOD(Ice_Mvc_Router, getParams)
{

	RETURN_MEMBER(getThis(), "params");
}

PHP_METHOD(Ice_Mvc_Router, getSilent)
{

	RETURN_MEMBER(getThis(), "silent");
}

PHP_METHOD(Ice_Mvc_Router, setSilent)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 229, silent);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_Router, getDefaultModule)
{

	RETURN_MEMBER(getThis(), "defaultModule");
}

PHP_METHOD(Ice_Mvc_Router, setDefaultModule)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 230, defaultModule);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_Router, getDefaultHandler)
{

	RETURN_MEMBER(getThis(), "defaultHandler");
}

PHP_METHOD(Ice_Mvc_Router, setDefaultHandler)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 231, defaultHandler);
	RETURN_THISW();
}

PHP_METHOD(Ice_Mvc_Router, getDefaultAction)
{

	RETURN_MEMBER(getThis(), "defaultAction");
}

PHP_METHOD(Ice_Mvc_Router, setDefaultAction)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 232, defaultAction);
	RETURN_THISW();
}

/**
 * Stores a named route and returns it.
 *
 * <pre><code>
 *     $router->addRoute("default", "[/{controller}[/{action}[/{id}]]]")
 *         ->setDefaults(["controller" => "hello"]);
 * </code></pre>
 *
 * @param string route name
 * @param string URI pattern
 * @param array regex patterns for route keys
 * @param mix method Request method limitation, * for no limit or an array of methods
 * @return object self
 */
PHP_METHOD(Ice_Mvc_Router, addRoute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval regex;
	zval name_zv, uri_zv, *regex_param = NULL, *method = NULL, method_sub, _0, _1, _2;
	zend_string *name = NULL, *uri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&uri_zv);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&regex);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(name)
		Z_PARAM_STR(uri)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY_OR_NULL(regex, regex_param)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		regex_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		method = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	if (!regex_param) {
		ZEPHIR_INIT_VAR(&regex);
	} else {
		zephir_get_arrval(&regex, regex_param);
	}
	if (!method) {
		method = &method_sub;
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "*");
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, ice_mvc_route_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 182, &uri_zv, &regex, method);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("routes"), &name_zv, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 233, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_2);
	zephir_array_fetch(&_2, &_1, &name_zv, PH_NOISY, "ice/mvc/router.zep", 59);
	RETURN_CCTOR(&_2);
}

/**
 * Retrieves a named route or the current matched route.
 *
 * <pre><code>
 *     $route = $router->getRoute("default");
 * </code></pre>
 *
 * @param   string route name
 * @return  Route|null
 */
PHP_METHOD(Ice_Mvc_Router, getRoute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, n, _0, _1, _2;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("route", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("routes", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_CPY_WRT(&n, &name_zv);
	if (Z_TYPE_P(&n) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&n);
		zephir_read_property_cached(&n, this_ptr, _zephir_prop_0, 234, PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 233, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_1, &n)) {
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 233, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch(&_0, &_2, &n, PH_NOISY, "ice/mvc/router.zep", 80);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);
}

/**
 * Get the name of a route.
 *
 * @param   object Route instance
 * @return  string
 */
PHP_METHOD(Ice_Mvc_Router, getRouteName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *route, route_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(route, ice_mvc_route_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &route);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 233, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("array_search", NULL, 183, route, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Saves or loads the route cache.
 *
 * <pre><code>
 *     if (! $router->cache()) {
 *         // set routes
 *         $router->addRoute("default", "[/{controller}[/{action}[/{id}]]]");
 *         // cache routes
 *         $router->cache($filePath);
 *     }
 * </code></pre>
 *
 * @param   string file Cache the current routes to the file
 * @return  self|boolean when saving routes or loading routes
 */
PHP_METHOD(Ice_Mvc_Router, cache)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval file_zv, _0$$3, _1$$3, _2$$3, _3$$4;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(file)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!file) {
		ZEPHIR_INIT_VAR(&file_zv);
	} else {
		zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	}
	if (!(ZEPHIR_IS_EMPTY(&file_zv))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 233, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0$$3);
		zephir_var_export_ex(&_0$$3, &_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "<?php return ", &_0$$3, ";");
		zephir_file_put_contents(NULL, &file_zv, &_2$$3);
		RETURN_MM_BOOL(1);
	}
	if ((zephir_file_exists(&file_zv) == SUCCESS)) {
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_3$$4);
		if (zephir_require_zval_ret(&_3$$4, &file_zv) == FAILURE) {
			RETURN_MM_NULL();
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 233, &_3$$4);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

/**
 * Set defaults values
 *
 * <pre><code>
 *     $route->defaults(["controller" => "hello", "action" => "world"]);
 * </code></pre>
 *
 * @param array defaults values
 * @return self
 */
PHP_METHOD(Ice_Mvc_Router, defaults)
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 230, &module);
	}
	zephir_memory_observe(&handler);
	if (zephir_array_isset_string_fetch(&handler, &defaults, SL("controller"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 231, &handler);
	}
	zephir_memory_observe(&action);
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 232, &action);
	}
	RETURN_THIS();
}

/**
 * Set an array of route rules.
 * httpMethod: *|null - no limit, GET, POST, PUT or PATCH
 * URI pattern: [] wrap for optional, {} wrap for regex placeholder key
 * regex: an associate array placeholder key and regex limitation pattern
 * defaults: default options for the module, handler and action
 *
 * <pre><code>
 *     // the rule format: ['name' => ["httpMethod", "URI pattern", "regex", "defaults"]]
 *     $route->setRoutes([
 *         ["default" => ["POST", "/{controller}[.ext]", ["controller" => "[a-z]+", "ext" => "(?:htm|html)"]]]
 *     ]);
 * </code></pre>
 *
 * @param array routes Route rules
 * @return self
 */
PHP_METHOD(Ice_Mvc_Router, setRoutes)
{
	zend_bool _10$$4;
	zend_string *_6;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routes_param = NULL, name, option, route, regex, defaults, *_4, _0$$3, _2$$3, _7$$4, _8$$4;
	zval routes, _1$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY_OR_NULL(routes, routes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &routes_param);
	if (!routes_param) {
		ZEPHIR_INIT_VAR(&routes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&routes, routes_param);
	}
	if (ZEPHIR_IS_EMPTY(&routes)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 3, 0);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "*");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "[/{controller}[/{action}[/{id}[/{param}]]]]");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0);
		add_assoc_stringl_ex(&_3$$3, SL("controller"), SL("\\w+"));
		add_assoc_stringl_ex(&_3$$3, SL("action"), SL("\\w+"));
		zephir_array_fast_append(&_1$$3, &_3$$3);
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_CPY_WRT(&routes, &_0$$3);
	}
	zephir_is_iterable(&routes, 0, "ice/mvc/router.zep", 194);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&routes), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&name, _6);
		} else {
			ZVAL_LONG(&name, _5);
		}
		ZEPHIR_INIT_NVAR(&option);
		ZVAL_COPY(&option, _4);
		ZEPHIR_OBS_NVAR(&regex);
		if (!(zephir_array_isset_long_fetch(&regex, &option, 2, 0))) {
			ZEPHIR_INIT_NVAR(&regex);
			array_init(&regex);
		}
		ZEPHIR_OBS_NVAR(&_7$$4);
		zephir_array_fetch_long(&_7$$4, &option, 1, PH_NOISY, "ice/mvc/router.zep", 188);
		ZEPHIR_OBS_NVAR(&_8$$4);
		zephir_array_fetch_long(&_8$$4, &option, 0, PH_NOISY, "ice/mvc/router.zep", 188);
		ZEPHIR_CALL_METHOD(&route, this_ptr, "addroute", &_9, 0, &name, &_7$$4, &regex, &_8$$4);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&defaults);
		_10$$4 = zephir_array_isset_long_fetch(&defaults, &option, 3, 0);
		if (_10$$4) {
			_10$$4 = Z_TYPE_P(&defaults) == IS_ARRAY;
		}
		if (_10$$4) {
			ZEPHIR_CALL_METHOD(NULL, &route, "setdefaults", NULL, 0, &defaults);
			zephir_check_call_status();
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&option);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_THIS();
}

/**
 * Handles routing information.
 *
 * @param string method
 * @param string uri
 * @return mixed
 */
PHP_METHOD(Ice_Mvc_Router, handle)
{
	zval _32;
	zend_bool _17;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri;
	zval method_zv, *uri_param = NULL, name, route, params, matches, response, _0, _1, _2, _3, *_4, _5, *_6, _16, _25, _31, _33, _9$$6, _10$$7, _11$$8, _12$$9, _13$$10, _14$$11, _15$$5, _18$$15, _19$$16, _20$$17, _21$$18, _22$$19, _23$$20, _24$$14, _26$$22, _27$$22, _28$$22, _29$$22, _30$$22;
	zend_string *method = NULL, *_8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_26$$22);
	ZVAL_UNDEF(&_27$$22);
	ZVAL_UNDEF(&_28$$22);
	ZVAL_UNDEF(&_29$$22);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_32);
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
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("route", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("method", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("module", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("defaultModule", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("handler", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("defaultHandler", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("action", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("defaultAction", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("params", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("silent", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(method)
		Z_PARAM_ZVAL_OR_NULL(uri_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		uri_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (!method) {
		ZEPHIR_INIT_VAR(&method_zv);
	} else {
		zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	}
	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
	} else {
		zephir_get_strval(&uri, uri_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_STRING(&uri, "/")) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "/");
	} else {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_STRING(&_1, "/");
		ZEPHIR_INIT_NVAR(&_0);
		zephir_fast_trim(&_0, &uri, &_1, ZEPHIR_TRIM_RIGHT);
	}
	zephir_get_strval(&uri, &_0);
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 233, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setroutes", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 233, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_3) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_3);
		_4 = &_5;
	} else {
		_4 = &_3;
	}
	zephir_is_iterable(_4, 0, "ice/mvc/router.zep", 261);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&name, _8);
			} else {
				ZVAL_LONG(&name, _7);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _6);
			ZEPHIR_CALL_METHOD(&params, &route, "matches", NULL, 0, &uri, &method_zv);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&params))) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 234, &name);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 235, &method_zv);
				if (zephir_array_isset_value_string(&params, SL("module"))) {
					ZEPHIR_OBS_NVAR(&_9$$6);
					zephir_array_fetch_string(&_9$$6, &params, SL("module"), PH_NOISY, "ice/mvc/router.zep", 224);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 236, &_9$$6);
				} else {
					zephir_read_property_cached(&_10$$7, this_ptr, _zephir_prop_4, 230, PH_NOISY_CC | PH_READONLY);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 236, &_10$$7);
				}
				if (zephir_array_isset_value_string(&params, SL("controller"))) {
					ZEPHIR_OBS_NVAR(&_11$$8);
					zephir_array_fetch_string(&_11$$8, &params, SL("controller"), PH_NOISY, "ice/mvc/router.zep", 230);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 237, &_11$$8);
				} else {
					zephir_read_property_cached(&_12$$9, this_ptr, _zephir_prop_6, 231, PH_NOISY_CC | PH_READONLY);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 237, &_12$$9);
				}
				if (zephir_array_isset_value_string(&params, SL("action"))) {
					ZEPHIR_OBS_NVAR(&_13$$10);
					zephir_array_fetch_string(&_13$$10, &params, SL("action"), PH_NOISY, "ice/mvc/router.zep", 236);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 238, &_13$$10);
				} else {
					zephir_read_property_cached(&_14$$11, this_ptr, _zephir_prop_8, 232, PH_NOISY_CC | PH_READONLY);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 238, &_14$$11);
				}
				zephir_array_unset_string(&params, SL("controller"), PH_SEPARATE);
				zephir_array_unset_string(&params, SL("action"), PH_SEPARATE);
				zephir_array_unset_string(&params, SL("module"), PH_SEPARATE);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 239, &params);
				zephir_create_array(return_value, 4, 0);
				ZEPHIR_OBS_NVAR(&_15$$5);
				zephir_read_property_cached(&_15$$5, this_ptr, _zephir_prop_3, 236, PH_NOISY_CC);
				zephir_array_update_string(return_value, SL("module"), &_15$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_15$$5);
				zephir_read_property_cached(&_15$$5, this_ptr, _zephir_prop_5, 237, PH_NOISY_CC);
				zephir_array_update_string(return_value, SL("handler"), &_15$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_15$$5);
				zephir_read_property_cached(&_15$$5, this_ptr, _zephir_prop_7, 238, PH_NOISY_CC);
				zephir_array_update_string(return_value, SL("action"), &_15$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_15$$5);
				zephir_read_property_cached(&_15$$5, this_ptr, _zephir_prop_9, 239, PH_NOISY_CC);
				zephir_array_update_string(return_value, SL("params"), &_15$$5, PH_COPY | PH_SEPARATE);
				RETURN_MM();
			} else if (ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_BOOL(&matches, 0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _4, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&params, &route, "matches", NULL, 0, &uri, &method_zv);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&params))) {
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 234, &name);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 235, &method_zv);
					if (zephir_array_isset_value_string(&params, SL("module"))) {
						ZEPHIR_OBS_NVAR(&_18$$15);
						zephir_array_fetch_string(&_18$$15, &params, SL("module"), PH_NOISY, "ice/mvc/router.zep", 224);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 236, &_18$$15);
					} else {
						zephir_read_property_cached(&_19$$16, this_ptr, _zephir_prop_4, 230, PH_NOISY_CC | PH_READONLY);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 236, &_19$$16);
					}
					if (zephir_array_isset_value_string(&params, SL("controller"))) {
						ZEPHIR_OBS_NVAR(&_20$$17);
						zephir_array_fetch_string(&_20$$17, &params, SL("controller"), PH_NOISY, "ice/mvc/router.zep", 230);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 237, &_20$$17);
					} else {
						zephir_read_property_cached(&_21$$18, this_ptr, _zephir_prop_6, 231, PH_NOISY_CC | PH_READONLY);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 237, &_21$$18);
					}
					if (zephir_array_isset_value_string(&params, SL("action"))) {
						ZEPHIR_OBS_NVAR(&_22$$19);
						zephir_array_fetch_string(&_22$$19, &params, SL("action"), PH_NOISY, "ice/mvc/router.zep", 236);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 238, &_22$$19);
					} else {
						zephir_read_property_cached(&_23$$20, this_ptr, _zephir_prop_8, 232, PH_NOISY_CC | PH_READONLY);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 238, &_23$$20);
					}
					zephir_array_unset_string(&params, SL("controller"), PH_SEPARATE);
					zephir_array_unset_string(&params, SL("action"), PH_SEPARATE);
					zephir_array_unset_string(&params, SL("module"), PH_SEPARATE);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 239, &params);
					zephir_create_array(return_value, 4, 0);
					ZEPHIR_OBS_NVAR(&_24$$14);
					zephir_read_property_cached(&_24$$14, this_ptr, _zephir_prop_3, 236, PH_NOISY_CC);
					zephir_array_update_string(return_value, SL("module"), &_24$$14, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_24$$14);
					zephir_read_property_cached(&_24$$14, this_ptr, _zephir_prop_5, 237, PH_NOISY_CC);
					zephir_array_update_string(return_value, SL("handler"), &_24$$14, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_24$$14);
					zephir_read_property_cached(&_24$$14, this_ptr, _zephir_prop_7, 238, PH_NOISY_CC);
					zephir_array_update_string(return_value, SL("action"), &_24$$14, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_24$$14);
					zephir_read_property_cached(&_24$$14, this_ptr, _zephir_prop_9, 239, PH_NOISY_CC);
					zephir_array_update_string(return_value, SL("params"), &_24$$14, PH_COPY | PH_SEPARATE);
					RETURN_MM();
				} else if (ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_BOOL(&matches, 0);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&name);
	zephir_read_property_cached(&_25, this_ptr, _zephir_prop_10, 229, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_25)) {
		ZEPHIR_CALL_CE_STATIC(&_26$$22, ice_di_ce, "fetch", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_27$$22);
		ZVAL_STRING(&_27$$22, "response");
		ZEPHIR_CALL_METHOD(&response, &_26$$22, "get", NULL, 0, &_27$$22);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_28$$22);
		if (Z_TYPE_P(&matches) == IS_NULL) {
			ZEPHIR_INIT_NVAR(&_28$$22);
			ZVAL_LONG(&_28$$22, 404);
		} else {
			ZEPHIR_INIT_NVAR(&_28$$22);
			ZVAL_LONG(&_28$$22, 405);
		}
		ZEPHIR_CPY_WRT(&matches, &_28$$22);
		ZEPHIR_CALL_METHOD(&_29$$22, &response, "setstatus", NULL, 0, &matches);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_30$$22, &response, "getmessage", NULL, 0, &matches);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_29$$22, "setbody", NULL, 0, &_30$$22);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_31);
	object_init_ex(&_31, ice_exception_ce);
	ZEPHIR_INIT_VAR(&_32);
	zephir_create_array(&_32, 2, 0);
	ZEPHIR_INIT_VAR(&_33);
	if (Z_TYPE_P(&matches) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_33);
		ZVAL_STRING(&_33, "Unable to find a route to match the URI: %s");
	} else {
		ZEPHIR_INIT_NVAR(&_33);
		ZVAL_STRING(&_33, "Request method not supported by that resource: %s");
	}
	zephir_array_fast_append(&_32, &_33);
	zephir_array_fast_append(&_32, &uri);
	ZEPHIR_CALL_METHOD(NULL, &_31, "__construct", NULL, 13, &_32);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_31, "ice/mvc/router.zep", 275);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Get route matched by uri and method.
 *
 * @param string uri
 * @param string method
 * @return Route|false|null
 */
PHP_METHOD(Ice_Mvc_Router, match)
{
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *method = NULL;
	zval *uri_param = NULL, method_zv, route, params, matches, _0, _1, _2, *_3, _4, *_5, _6;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(uri_param)
		Z_PARAM_STR_OR_NULL(method)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 0) {
		uri_param = ZEND_CALL_ARG(execute_data, 1);
	}
	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
	} else {
		zephir_get_strval(&uri, uri_param);
	}
	if (!method) {
		ZEPHIR_INIT_VAR(&method_zv);
	} else {
		zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	}
	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_STRING(&uri, "/")) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "/");
	} else {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_STRING(&_1, "/");
		ZEPHIR_INIT_NVAR(&_0);
		zephir_fast_trim(&_0, &uri, &_1, ZEPHIR_TRIM_RIGHT);
	}
	zephir_get_strval(&uri, &_0);
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 233, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_2) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &_2);
		_3 = &_4;
	} else {
		_3 = &_2;
	}
	zephir_is_iterable(_3, 0, "ice/mvc/router.zep", 303);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _5);
			ZEPHIR_CALL_METHOD(&params, &route, "matches", NULL, 0, &uri, &method_zv);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&params))) {
				RETURN_CCTOR(&route);
			} else if (ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_BOOL(&matches, 0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&params, &route, "matches", NULL, 0, &uri, &method_zv);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&params))) {
					RETURN_CCTOR(&route);
				} else if (ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_BOOL(&matches, 0);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	RETURN_CCTOR(&matches);
}

/**
 * Generates a URI based on the parameters given. (AKA. reverse route).
 *
 * <pre><code>
 *     $uri = $router->uri(["controller" => "blog", "action" => "post", "param" => 10]);
 * </code></pre>
 *
 * @param array URI parameters
 * @param string method
 * @return string|null
 */
PHP_METHOD(Ice_Mvc_Router, uri)
{
	zend_bool _7, _4$$3, _8$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *method = NULL;
	zval *params_param = NULL, method_zv, route, uri, _0, *_1, _2, *_3, _6, _5$$3, _9$$5;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("routes", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(method)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	params_param = ZEND_CALL_ARG(execute_data, 1);
	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	if (!method) {
		method = zend_string_init(ZEND_STRL("*"), 0);
		zephir_memory_observe(&method_zv);
		ZVAL_STR(&method_zv, method);
	} else {
		zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 233, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "ice/mvc/router.zep", 328);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _3);
			ZEPHIR_CALL_METHOD(&uri, &route, "uri", NULL, 0, &params);
			zephir_check_call_status();
			_4$$3 = !ZEPHIR_IS_FALSE_IDENTICAL(&uri);
			if (_4$$3) {
				ZEPHIR_CALL_METHOD(&_5$$3, &route, "checkmethod", NULL, 0, &method_zv);
				zephir_check_call_status();
				_4$$3 = zephir_is_true(&_5$$3);
			}
			if (_4$$3) {
				RETURN_CCTOR(&uri);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&uri, &route, "uri", NULL, 0, &params);
				zephir_check_call_status();
				_8$$5 = !ZEPHIR_IS_FALSE_IDENTICAL(&uri);
				if (_8$$5) {
					ZEPHIR_CALL_METHOD(&_9$$5, &route, "checkmethod", NULL, 0, &method_zv);
					zephir_check_call_status();
					_8$$5 = zephir_is_true(&_9$$5);
				}
				if (_8$$5) {
					RETURN_CCTOR(&uri);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	RETURN_MM_NULL();
}

zend_object *zephir_init_properties_Ice_Mvc_Router(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routes"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

