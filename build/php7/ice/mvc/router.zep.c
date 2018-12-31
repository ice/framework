
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Router) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc, Router, ice, mvc_router, ice_mvc_router_method_entry, 0);

	zend_declare_property_null(ice_mvc_router_ce, SL("routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_router_ce, SL("route"), "default", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_router_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_mvc_router_ce, SL("silent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_router_ce, SL("defaultModule"), "default", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_router_ce, SL("defaultHandler"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_router_ce, SL("defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_zval(this_ptr, SL("silent"), silent);
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

	zephir_fetch_params(0, 1, 0, &defaultModule);



	zephir_update_property_zval(this_ptr, SL("defaultModule"), defaultModule);
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

	zephir_fetch_params(0, 1, 0, &defaultHandler);



	zephir_update_property_zval(this_ptr, SL("defaultHandler"), defaultHandler);
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

	zephir_fetch_params(0, 1, 0, &defaultAction);



	zephir_update_property_zval(this_ptr, SL("defaultAction"), defaultAction);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 153, &uri, &regex, method);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("routes"), &name, &_0 TSRMLS_CC);
	zephir_read_property(&_1, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_2, &_1, &name, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 59 TSRMLS_CC);
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

	zval *name_param = NULL, n, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

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
		zephir_read_property(&n, this_ptr, SL("route"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &n)) {
		zephir_read_property(&_2, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &n, PH_NOISY, "ice/mvc/router.zep", 80 TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *route, route_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route);



	zephir_read_property(&_0, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("array_search", NULL, 154, route, &_0);
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

	zval *file_param = NULL, _0$$3, _1$$3, _2$$3, _3$$4;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);

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
		zephir_read_property(&_1$$3, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0$$3);
		zephir_var_export_ex(&_0$$3, &_1$$3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "<?php return ", &_0$$3, ";");
		zephir_file_put_contents(NULL, &file, &_2$$3 TSRMLS_CC);
		RETURN_MM_BOOL(1);
	}
	if ((zephir_file_exists(&file TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_3$$4);
		if (zephir_require_zval_ret(&_3$$4, &file TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		zephir_update_property_zval(this_ptr, SL("routes"), &_3$$4);
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
	if (zephir_array_isset_string_fetch(&handler, &defaults, SL("controller"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultHandler"), &handler);
	}
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultAction"), &action);
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

	zend_bool _9$$4;
	zend_string *_5;
	zend_ulong _4;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routes_param = NULL, name, option, route, regex, defaults, *_3, _1$$3, _6$$4, _7$$4;
	zval routes, _0$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &routes_param);

	if (!routes_param) {
		ZEPHIR_INIT_VAR(&routes);
		array_init(&routes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&routes, routes_param);
	}


	if (ZEPHIR_IS_EMPTY(&routes)) {
		ZEPHIR_INIT_NVAR(&routes);
		zephir_create_array(&routes, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "*");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "[/{controller}[/{action}[/{id}[/{param}]]]]");
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_2$$3, SL("controller"), SL("\\w+"));
		add_assoc_stringl_ex(&_2$$3, SL("action"), SL("\\w+"));
		zephir_array_fast_append(&_0$$3, &_2$$3);
		zephir_array_fast_append(&routes, &_0$$3);
	}
	zephir_is_iterable(&routes, 0, "ice/mvc/router.zep", 194);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&routes), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&name, _5);
		} else {
			ZVAL_LONG(&name, _4);
		}
		ZEPHIR_INIT_NVAR(&option);
		ZVAL_COPY(&option, _3);
		ZEPHIR_OBS_NVAR(&regex);
		if (!(zephir_array_isset_long_fetch(&regex, &option, 2, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(&regex);
			array_init(&regex);
		}
		zephir_array_fetch_long(&_6$$4, &option, 1, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 188 TSRMLS_CC);
		zephir_array_fetch_long(&_7$$4, &option, 0, PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 188 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&route, this_ptr, "addroute", &_8, 0, &name, &_6$$4, &regex, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&defaults);
		_9$$4 = zephir_array_isset_long_fetch(&defaults, &option, 3, 0 TSRMLS_CC);
		if (_9$$4) {
			_9$$4 = Z_TYPE_P(&defaults) == IS_ARRAY;
		}
		if (_9$$4) {
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
PHP_METHOD(Ice_Mvc_Router, handle) {

	zval _21;
	zend_string *_5;
	zend_ulong _4;
	zephir_fcall_cache_entry *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *uri_param = NULL, name, route, params, matches, response, _0, _1, _2, *_3, _13, _20, _22, _6$$5, _7$$6, _8$$7, _9$$8, _10$$9, _11$$10, _12$$4, _14$$12, _16$$12, _17$$12, _18$$12, _19$$12;
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
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_21);

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
		zephir_fast_trim(&_0, &uri, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	}
	zephir_get_strval(&uri, &_0);
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	zephir_read_property(&_2, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_2, 0, "ice/mvc/router.zep", 256);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_2), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&name, _5);
		} else {
			ZVAL_LONG(&name, _4);
		}
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _3);
		ZEPHIR_CALL_METHOD(&params, &route, "matches", NULL, 0, &uri, &method);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&params))) {
			zephir_update_property_zval(this_ptr, SL("route"), &name);
			zephir_update_property_zval(this_ptr, SL("method"), &method);
			if (zephir_array_isset_string(&params, SL("module"))) {
				zephir_array_fetch_string(&_6$$5, &params, SL("module"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 219 TSRMLS_CC);
				zephir_update_property_zval(this_ptr, SL("module"), &_6$$5);
			} else {
				zephir_read_property(&_7$$6, this_ptr, SL("defaultModule"), PH_NOISY_CC | PH_READONLY);
				zephir_update_property_zval(this_ptr, SL("module"), &_7$$6);
			}
			if (zephir_array_isset_string(&params, SL("controller"))) {
				zephir_array_fetch_string(&_8$$7, &params, SL("controller"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 225 TSRMLS_CC);
				zephir_update_property_zval(this_ptr, SL("handler"), &_8$$7);
			} else {
				zephir_read_property(&_9$$8, this_ptr, SL("defaultHandler"), PH_NOISY_CC | PH_READONLY);
				zephir_update_property_zval(this_ptr, SL("handler"), &_9$$8);
			}
			if (zephir_array_isset_string(&params, SL("action"))) {
				zephir_array_fetch_string(&_10$$9, &params, SL("action"), PH_NOISY | PH_READONLY, "ice/mvc/router.zep", 231 TSRMLS_CC);
				zephir_update_property_zval(this_ptr, SL("action"), &_10$$9);
			} else {
				zephir_read_property(&_11$$10, this_ptr, SL("defaultAction"), PH_NOISY_CC | PH_READONLY);
				zephir_update_property_zval(this_ptr, SL("action"), &_11$$10);
			}
			zephir_array_unset_string(&params, SL("controller"), PH_SEPARATE);
			zephir_array_unset_string(&params, SL("action"), PH_SEPARATE);
			zephir_array_unset_string(&params, SL("module"), PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("params"), &params);
			zephir_create_array(return_value, 4, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_12$$4);
			zephir_read_property(&_12$$4, this_ptr, SL("module"), PH_NOISY_CC);
			zephir_array_update_string(return_value, SL("module"), &_12$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_12$$4);
			zephir_read_property(&_12$$4, this_ptr, SL("handler"), PH_NOISY_CC);
			zephir_array_update_string(return_value, SL("handler"), &_12$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_12$$4);
			zephir_read_property(&_12$$4, this_ptr, SL("action"), PH_NOISY_CC);
			zephir_array_update_string(return_value, SL("action"), &_12$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_12$$4);
			zephir_read_property(&_12$$4, this_ptr, SL("params"), PH_NOISY_CC);
			zephir_array_update_string(return_value, SL("params"), &_12$$4, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		} else if (ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
			ZEPHIR_INIT_NVAR(&matches);
			ZVAL_BOOL(&matches, 0);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_INIT_NVAR(&name);
	zephir_read_property(&_13, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_13)) {
		ZEPHIR_CALL_CE_STATIC(&_14$$12, ice_di_ce, "fetch", &_15, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_16$$12);
		ZVAL_STRING(&_16$$12, "response");
		ZEPHIR_CALL_METHOD(&response, &_14$$12, "get", NULL, 0, &_16$$12);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_17$$12);
		if (Z_TYPE_P(&matches) == IS_NULL) {
			ZEPHIR_INIT_NVAR(&_17$$12);
			ZVAL_LONG(&_17$$12, 404);
		} else {
			ZEPHIR_INIT_NVAR(&_17$$12);
			ZVAL_LONG(&_17$$12, 405);
		}
		ZEPHIR_CPY_WRT(&matches, &_17$$12);
		ZEPHIR_CALL_METHOD(&_18$$12, &response, "setstatus", NULL, 0, &matches);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_19$$12, &response, "getmessage", NULL, 0, &matches);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_18$$12, "setbody", NULL, 0, &_19$$12);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_20);
	object_init_ex(&_20, ice_exception_ce);
	ZEPHIR_INIT_VAR(&_21);
	zephir_create_array(&_21, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_22);
	if (Z_TYPE_P(&matches) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_22);
		ZVAL_STRING(&_22, "Unable to find a route to match the URI: %s");
	} else {
		ZEPHIR_INIT_NVAR(&_22);
		ZVAL_STRING(&_22, "Request method not supported by that resource: %s");
	}
	zephir_array_fast_append(&_21, &_22);
	zephir_array_fast_append(&_21, &uri);
	ZEPHIR_CALL_METHOD(NULL, &_20, "__construct", NULL, 12, &_21);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_20, "ice/mvc/router.zep", 270 TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *method_param = NULL, route, params, matches, _0, _1, _2, *_3;
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
		zephir_fast_trim(&_0, &uri, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	}
	zephir_get_strval(&uri, &_0);
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	zephir_read_property(&_2, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_2, 0, "ice/mvc/router.zep", 298);
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

	zend_bool _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method;
	zval *params_param = NULL, *method_param = NULL, route, uri, _0, *_1, _3$$3;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&method);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params_param, &method_param);

	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "*");
	} else {
		zephir_get_strval(&method, method_param);
	}


	zephir_read_property(&_0, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "ice/mvc/router.zep", 323);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _1);
		ZEPHIR_CALL_METHOD(&uri, &route, "uri", NULL, 0, &params);
		zephir_check_call_status();
		_2$$3 = !ZEPHIR_IS_FALSE_IDENTICAL(&uri);
		if (_2$$3) {
			ZEPHIR_CALL_METHOD(&_3$$3, &route, "checkmethod", NULL, 0, &method);
			zephir_check_call_status();
			_2$$3 = zephir_is_true(&_3$$3);
		}
		if (_2$$3) {
			RETURN_CCTOR(&uri);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	RETURN_MM_NULL();

}

zend_object *zephir_init_properties_Ice_Mvc_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("params"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("routes"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

