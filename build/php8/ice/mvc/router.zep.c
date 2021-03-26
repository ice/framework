
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
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Router) {

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

PHP_METHOD(Ice_Mvc_Router, getRoutes) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "routes");

}

PHP_METHOD(Ice_Mvc_Router, getMethod) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "method");

}

PHP_METHOD(Ice_Mvc_Router, getModule) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "module");

}

PHP_METHOD(Ice_Mvc_Router, getHandler) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "handler");

}

PHP_METHOD(Ice_Mvc_Router, getAction) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "action");

}

PHP_METHOD(Ice_Mvc_Router, getParams) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "params");

}

PHP_METHOD(Ice_Mvc_Router, getSilent) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "silent");

}

PHP_METHOD(Ice_Mvc_Router, setSilent) {

	zval *silent, silent_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&silent_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(silent)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &silent);



	zephir_update_property_zval(this_ptr, ZEND_STRL("silent"), silent);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Router, getDefaultModule) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultModule");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultModule) {

	zval *defaultModule, defaultModule_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultModule_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultModule)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &defaultModule);



	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), defaultModule);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Router, getDefaultHandler) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultHandler");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultHandler) {

	zval *defaultHandler, defaultHandler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultHandler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultHandler)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &defaultHandler);



	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultHandler"), defaultHandler);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Router, getDefaultAction) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultAction");

}

PHP_METHOD(Ice_Mvc_Router, setDefaultAction) {

	zval *defaultAction, defaultAction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultAction_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(defaultAction)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &defaultAction);



	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAction"), defaultAction);
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
PHP_METHOD(Ice_Mvc_Router, addRoute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval regex;
	zval *name_param = NULL, *uri_param = NULL, *regex_param = NULL, *method = NULL, method_sub, _0, _1, _2;
	zval name, uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&regex);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(name)
		Z_PARAM_STR(uri)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(regex)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &name_param, &uri_param, &regex_param, &method);

	zephir_get_strval(&name, name_param);
	zephir_get_strval(&uri, uri_param);
	if (!regex_param) {
		ZEPHIR_INIT_VAR(&regex);
		array_init(&regex);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 180, &uri, &regex, method);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("routes"), &name, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_2, &_1, &name, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 59);
	RETURN_CTOR(&_2);

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
PHP_METHOD(Ice_Mvc_Router, getRoute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, n, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_CPY_WRT(&n, &name);
	if (Z_TYPE_P(&n) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&n);
		zephir_read_property(&n, this_ptr, ZEND_STRL("route"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &n)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &n, PH_NOISY, "ice/mvc/router.zep", 80);
	} else {
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
PHP_METHOD(Ice_Mvc_Router, getRouteName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *route, route_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(route, ice_mvc_route_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("array_search", NULL, 181, route, &_0);
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
PHP_METHOD(Ice_Mvc_Router, cache) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *file_param = NULL, _0$$3, _1$$3, _2$$3, _3$$4;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(file)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &file_param);

	if (!file_param) {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_STRING(&file, "");
	} else {
		zephir_get_strval(&file, file_param);
	}


	if (!(Z_TYPE_P(&file) == IS_UNDEF) && Z_STRLEN_P(&file)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0$$3);
		zephir_var_export_ex(&_0$$3, &_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "<?php return ", &_0$$3, ";");
		zephir_file_put_contents(NULL, &file, &_2$$3);
		RETURN_MM_BOOL(1);
	}
	if ((zephir_file_exists(&file) == SUCCESS)) {
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_3$$4);
		if (zephir_require_zval_ret(&_3$$4, &file) == FAILURE) {
			RETURN_MM_NULL();
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("routes"), &_3$$4);
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
PHP_METHOD(Ice_Mvc_Router, defaults) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaults_param = NULL, module, handler, action;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&action);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(defaults)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults_param);

	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);


	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), &module);
	}
	if (zephir_array_isset_string_fetch(&handler, &defaults, SL("controller"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultHandler"), &handler);
	}
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultAction"), &action);
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
PHP_METHOD(Ice_Mvc_Router, setRoutes) {

	zend_bool _11$$4, _14$$7;
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routes_param = NULL, name, option, route, regex, defaults, *_4, _5, _0$$3, _2$$3, _8$$4, _9$$4, _12$$7, _13$$7;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(routes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &routes_param);

	if (!routes_param) {
		ZEPHIR_INIT_VAR(&routes);
		array_init(&routes);
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
	if (Z_TYPE_P(&routes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&routes), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&name, _7);
			} else {
				ZVAL_LONG(&name, _6);
			}
			ZEPHIR_INIT_NVAR(&option);
			ZVAL_COPY(&option, _4);
			ZEPHIR_OBS_NVAR(&regex);
			if (!(zephir_array_isset_long_fetch(&regex, &option, 2, 0))) {
				ZEPHIR_INIT_NVAR(&regex);
				array_init(&regex);
			}
			zephir_array_fetch_long(&_8$$4, &option, 1, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 188);
			zephir_array_fetch_long(&_9$$4, &option, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 188);
			ZEPHIR_CALL_METHOD(&route, this_ptr, "addroute", &_10, 0, &name, &_8$$4, &regex, &_9$$4);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&defaults);
			_11$$4 = zephir_array_isset_long_fetch(&defaults, &option, 3, 0);
			if (_11$$4) {
				_11$$4 = Z_TYPE_P(&defaults) == IS_ARRAY;
			}
			if (_11$$4) {
				ZEPHIR_CALL_METHOD(NULL, &route, "setdefaults", NULL, 0, &defaults);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &routes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &routes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &routes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&option, &routes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&regex);
				if (!(zephir_array_isset_long_fetch(&regex, &option, 2, 0))) {
					ZEPHIR_INIT_NVAR(&regex);
					array_init(&regex);
				}
				zephir_array_fetch_long(&_12$$7, &option, 1, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 188);
				zephir_array_fetch_long(&_13$$7, &option, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 188);
				ZEPHIR_CALL_METHOD(&route, this_ptr, "addroute", &_10, 0, &name, &_12$$7, &regex, &_13$$7);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&defaults);
				_14$$7 = zephir_array_isset_long_fetch(&defaults, &option, 3, 0);
				if (_14$$7) {
					_14$$7 = Z_TYPE_P(&defaults) == IS_ARRAY;
				}
				if (_14$$7) {
					ZEPHIR_CALL_METHOD(NULL, &route, "setdefaults", NULL, 0, &defaults);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &routes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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
PHP_METHOD(Ice_Mvc_Router, handle) {

	zval _30;
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_24 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *uri_param = NULL, name, route, params, matches, response, _0, _1, _2, _3, *_4, _5, _22, _29, _31, _8$$6, _9$$7, _10$$8, _11$$9, _12$$10, _13$$11, _14$$5, _15$$15, _16$$16, _17$$17, _18$$18, _19$$19, _20$$20, _21$$14, _23$$22, _25$$22, _26$$22, _27$$22, _28$$22;
	zval method, uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri);
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
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_23$$22);
	ZVAL_UNDEF(&_25$$22);
	ZVAL_UNDEF(&_26$$22);
	ZVAL_UNDEF(&_27$$22);
	ZVAL_UNDEF(&_28$$22);
	ZVAL_UNDEF(&_30);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(method)
		Z_PARAM_STR_OR_NULL(uri)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &method_param, &uri_param);

	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "");
	} else {
		zephir_get_strval(&method, method_param);
	}
	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
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
	zephir_read_property(&_2, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setroutes", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "ice/mvc/router.zep", 261);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&name, _7);
			} else {
				ZVAL_LONG(&name, _6);
			}
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _4);
			ZEPHIR_CALL_METHOD(&params, &route, "matches", NULL, 0, &uri, &method);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&params))) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("route"), &name);
				zephir_update_property_zval(this_ptr, ZEND_STRL("method"), &method);
				if (zephir_array_isset_string(&params, SL("module"))) {
					zephir_array_fetch_string(&_8$$6, &params, SL("module"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 224);
					zephir_update_property_zval(this_ptr, ZEND_STRL("module"), &_8$$6);
				} else {
					zephir_read_property(&_9$$7, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
					zephir_update_property_zval(this_ptr, ZEND_STRL("module"), &_9$$7);
				}
				if (zephir_array_isset_string(&params, SL("controller"))) {
					zephir_array_fetch_string(&_10$$8, &params, SL("controller"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 230);
					zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &_10$$8);
				} else {
					zephir_read_property(&_11$$9, this_ptr, ZEND_STRL("defaultHandler"), PH_NOISY_CC | PH_READONLY);
					zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &_11$$9);
				}
				if (zephir_array_isset_string(&params, SL("action"))) {
					zephir_array_fetch_string(&_12$$10, &params, SL("action"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 236);
					zephir_update_property_zval(this_ptr, ZEND_STRL("action"), &_12$$10);
				} else {
					zephir_read_property(&_13$$11, this_ptr, ZEND_STRL("defaultAction"), PH_NOISY_CC | PH_READONLY);
					zephir_update_property_zval(this_ptr, ZEND_STRL("action"), &_13$$11);
				}
				zephir_array_unset_string(&params, SL("controller"), PH_SEPARATE);
				zephir_array_unset_string(&params, SL("action"), PH_SEPARATE);
				zephir_array_unset_string(&params, SL("module"), PH_SEPARATE);
				zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &params);
				zephir_create_array(return_value, 4, 0);
				ZEPHIR_OBS_NVAR(&_14$$5);
				zephir_read_property(&_14$$5, this_ptr, ZEND_STRL("module"), PH_NOISY_CC);
				zephir_array_update_string(return_value, SL("module"), &_14$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_14$$5);
				zephir_read_property(&_14$$5, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
				zephir_array_update_string(return_value, SL("handler"), &_14$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_14$$5);
				zephir_read_property(&_14$$5, this_ptr, ZEND_STRL("action"), PH_NOISY_CC);
				zephir_array_update_string(return_value, SL("action"), &_14$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_14$$5);
				zephir_read_property(&_14$$5, this_ptr, ZEND_STRL("params"), PH_NOISY_CC);
				zephir_array_update_string(return_value, SL("params"), &_14$$5, PH_COPY | PH_SEPARATE);
				RETURN_MM();
			} else if (ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_BOOL(&matches, 0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &_3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&route, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&params, &route, "matches", NULL, 0, &uri, &method);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&params))) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("route"), &name);
					zephir_update_property_zval(this_ptr, ZEND_STRL("method"), &method);
					if (zephir_array_isset_string(&params, SL("module"))) {
						zephir_array_fetch_string(&_15$$15, &params, SL("module"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 224);
						zephir_update_property_zval(this_ptr, ZEND_STRL("module"), &_15$$15);
					} else {
						zephir_read_property(&_16$$16, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
						zephir_update_property_zval(this_ptr, ZEND_STRL("module"), &_16$$16);
					}
					if (zephir_array_isset_string(&params, SL("controller"))) {
						zephir_array_fetch_string(&_17$$17, &params, SL("controller"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 230);
						zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &_17$$17);
					} else {
						zephir_read_property(&_18$$18, this_ptr, ZEND_STRL("defaultHandler"), PH_NOISY_CC | PH_READONLY);
						zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &_18$$18);
					}
					if (zephir_array_isset_string(&params, SL("action"))) {
						zephir_array_fetch_string(&_19$$19, &params, SL("action"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 236);
						zephir_update_property_zval(this_ptr, ZEND_STRL("action"), &_19$$19);
					} else {
						zephir_read_property(&_20$$20, this_ptr, ZEND_STRL("defaultAction"), PH_NOISY_CC | PH_READONLY);
						zephir_update_property_zval(this_ptr, ZEND_STRL("action"), &_20$$20);
					}
					zephir_array_unset_string(&params, SL("controller"), PH_SEPARATE);
					zephir_array_unset_string(&params, SL("action"), PH_SEPARATE);
					zephir_array_unset_string(&params, SL("module"), PH_SEPARATE);
					zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &params);
					zephir_create_array(return_value, 4, 0);
					ZEPHIR_OBS_NVAR(&_21$$14);
					zephir_read_property(&_21$$14, this_ptr, ZEND_STRL("module"), PH_NOISY_CC);
					zephir_array_update_string(return_value, SL("module"), &_21$$14, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_21$$14);
					zephir_read_property(&_21$$14, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
					zephir_array_update_string(return_value, SL("handler"), &_21$$14, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_21$$14);
					zephir_read_property(&_21$$14, this_ptr, ZEND_STRL("action"), PH_NOISY_CC);
					zephir_array_update_string(return_value, SL("action"), &_21$$14, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_21$$14);
					zephir_read_property(&_21$$14, this_ptr, ZEND_STRL("params"), PH_NOISY_CC);
					zephir_array_update_string(return_value, SL("params"), &_21$$14, PH_COPY | PH_SEPARATE);
					RETURN_MM();
				} else if (ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_BOOL(&matches, 0);
				}
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&name);
	zephir_read_property(&_22, this_ptr, ZEND_STRL("silent"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_22)) {
		ZEPHIR_CALL_CE_STATIC(&_23$$22, ice_di_ce, "fetch", &_24, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_25$$22);
		ZVAL_STRING(&_25$$22, "response");
		ZEPHIR_CALL_METHOD(&response, &_23$$22, "get", NULL, 0, &_25$$22);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_26$$22);
		if (Z_TYPE_P(&matches) == IS_NULL) {
			ZEPHIR_INIT_NVAR(&_26$$22);
			ZVAL_LONG(&_26$$22, 404);
		} else {
			ZEPHIR_INIT_NVAR(&_26$$22);
			ZVAL_LONG(&_26$$22, 405);
		}
		ZEPHIR_CPY_WRT(&matches, &_26$$22);
		ZEPHIR_CALL_METHOD(&_27$$22, &response, "setstatus", NULL, 0, &matches);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_28$$22, &response, "getmessage", NULL, 0, &matches);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_27$$22, "setbody", NULL, 0, &_28$$22);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_29);
	object_init_ex(&_29, ice_exception_ce);
	ZEPHIR_INIT_VAR(&_30);
	zephir_create_array(&_30, 2, 0);
	ZEPHIR_INIT_VAR(&_31);
	if (Z_TYPE_P(&matches) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_31);
		ZVAL_STRING(&_31, "Unable to find a route to match the URI: %s");
	} else {
		ZEPHIR_INIT_NVAR(&_31);
		ZVAL_STRING(&_31, "Request method not supported by that resource: %s");
	}
	zephir_array_fast_append(&_30, &_31);
	zephir_array_fast_append(&_30, &uri);
	ZEPHIR_CALL_METHOD(NULL, &_29, "__construct", NULL, 12, &_30);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_29, "ice/mvc/router.zep", 275);
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
PHP_METHOD(Ice_Mvc_Router, match) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *method_param = NULL, route, params, matches, _0, _1, _2, *_3, _4;
	zval uri, method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(uri)
		Z_PARAM_STR_OR_NULL(method)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &uri_param, &method_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
		zephir_get_strval(&uri, uri_param);
	}
	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "");
	} else {
		zephir_get_strval(&method, method_param);
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
	zephir_read_property(&_2, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_2, 0, "ice/mvc/router.zep", 303);
	if (Z_TYPE_P(&_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _3)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _3);
			ZEPHIR_CALL_METHOD(&params, &route, "matches", NULL, 0, &uri, &method);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&params))) {
				RETURN_CCTOR(&route);
			} else if (ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_BOOL(&matches, 0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_2, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &_2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &_2, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&params, &route, "matches", NULL, 0, &uri, &method);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&params))) {
					RETURN_CCTOR(&route);
				} else if (ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_BOOL(&matches, 0);
				}
			ZEPHIR_CALL_METHOD(NULL, &_2, "next", NULL, 0);
			zephir_check_call_status();
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
PHP_METHOD(Ice_Mvc_Router, uri) {

	zend_bool _3$$3, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method;
	zval *params_param = NULL, *method_param = NULL, route, uri, _0, *_1, _2, _4$$3, _6$$5;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&method);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(params)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(method)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params_param, &method_param);

	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "*");
	} else {
		zephir_get_strval(&method, method_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "ice/mvc/router.zep", 328);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _1);
			ZEPHIR_CALL_METHOD(&uri, &route, "uri", NULL, 0, &params);
			zephir_check_call_status();
			_3$$3 = !ZEPHIR_IS_FALSE_IDENTICAL(&uri);
			if (_3$$3) {
				ZEPHIR_CALL_METHOD(&_4$$3, &route, "checkmethod", NULL, 0, &method);
				zephir_check_call_status();
				_3$$3 = zephir_is_true(&_4$$3);
			}
			if (_3$$3) {
				RETURN_CCTOR(&uri);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&uri, &route, "uri", NULL, 0, &params);
				zephir_check_call_status();
				_5$$5 = !ZEPHIR_IS_FALSE_IDENTICAL(&uri);
				if (_5$$5) {
					ZEPHIR_CALL_METHOD(&_6$$5, &route, "checkmethod", NULL, 0, &method);
					zephir_check_call_status();
					_5$$5 = zephir_is_true(&_6$$5);
				}
				if (_5$$5) {
					RETURN_CCTOR(&uri);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	RETURN_MM_NULL();

}

zend_object *zephir_init_properties_Ice_Mvc_Router(zend_class_entry *class_type) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
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

