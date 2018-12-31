
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This class represents every route added to the router.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_Route) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc, Route, ice, mvc_route, ice_mvc_route_method_entry, 0);

	zend_declare_property_string(ice_mvc_route_ce, SL("routeUri"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_ce, SL("regexMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_ce, SL("routeRegex"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_ce, SL("defaults"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_ce, SL("method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_route_ce, SL("error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_mvc_route_ce->create_object = zephir_init_properties_Ice_Mvc_Route;
	zephir_declare_class_constant_string(ice_mvc_route_ce, SL("REGEX_KEYWORD"), "\\{([a-zA-Z0-9_]++)\\}");

	zephir_declare_class_constant_string(ice_mvc_route_ce, SL("REGEX_PLACEHOLDER"), "[^/.,;?\n]++");

	zephir_declare_class_constant_string(ice_mvc_route_ce, SL("REGEX_ESCAPE"), "[.\\+*?^$=!|]");

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route, getDefaults) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaults");

}

PHP_METHOD(Ice_Mvc_Route, setDefaults) {

	zval *defaults, defaults_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults_sub);

	zephir_fetch_params(0, 1, 0, &defaults);



	zephir_update_property_zval(this_ptr, SL("defaults"), defaults);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route, getMethod) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "method");

}

PHP_METHOD(Ice_Mvc_Route, getError) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "error");

}

/**
 * Constructs a route. Each {key} will be translated to a regular expression 
 * using a default regular expression pattern. You can override the default pattern
 * by providing a pattern for the key:
 *
 * <pre><code>
 *     // This route will only match when {id} is a digit
 *     new Route("/blog/{action}/{id}", ["id" => "\d+"], ['GET', 'POST']);
 *
 *     // This route will match when {path} is anything
 *     new Route("/{path}", ["path" => ".*"]);
 * </code></pre>
 *
 * It is also possible to create optional segments by using parentheses in
 * the URI definition:
 *
 * <pre><code>
 *     // This is the standard default route, and no keys are required
 *     new Route('/{module}[/{controller}[/{action}[/{id}[/params]]]]');
 *
 *     // This route only requires the {file} key
 *     new Route('[/{path}/]{file}[.{ext}]', ['path' => '.*', 'ext' => '\w+']);
 * </code></pre>
 *
 * <pre><code>
 *     $route = new Route($uri, $regex, ['GET', 'POST']);
 * </code></pre>
 *
 * @param string uri Route URI pattern
 * @param array regexMap Key patterns map
 * @param mix method Request method limitation, * for no limit or an array of methods
 */
PHP_METHOD(Ice_Mvc_Route, __construct) {

	zend_string *_21$$10;
	zend_ulong _20$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval regexMap, _13, _15, _9$$9, _11$$9;
	zval *uri_param = NULL, *regexMap_param = NULL, *method = NULL, method_sub, regex, search, replace, key, value, _5, _6, _7, _12, _14, _17, _25, _0$$5, _1$$7, _2$$7, _3$$8, _8$$9, _10$$9, _18$$10, *_19$$10, _24$$10, _22$$11, _23$$11;
	zval uri, _4, _16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&search);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&regexMap);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &uri_param, &regexMap_param, &method);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
		zephir_get_strval(&uri, uri_param);
	}
	if (!regexMap_param) {
		ZEPHIR_INIT_VAR(&regexMap);
		array_init(&regexMap);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&regexMap, regexMap_param);
	}
	if (!method) {
		method = &method_sub;
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "*");
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&uri, "")) {
		RETURN_MM_NULL();
	}
	zephir_update_property_zval(this_ptr, SL("routeUri"), &uri);
	if (!(ZEPHIR_IS_EMPTY(&regexMap))) {
		zephir_update_property_zval(this_ptr, SL("regexMap"), &regexMap);
	}
	if (ZEPHIR_IS_EMPTY(method)) {
		ZEPHIR_INIT_VAR(&_0$$5);
		ZEPHIR_INIT_NVAR(&_0$$5);
		ZVAL_STRING(&_0$$5, "*");
		zephir_update_property_zval(this_ptr, SL("method"), &_0$$5);
	} else {
		if (Z_TYPE_P(method) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$7);
			ZVAL_STRING(&_1$$7, "strtoupper");
			ZEPHIR_CALL_FUNCTION(&_2$$7, "array_map", NULL, 48, &_1$$7, method);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("method"), &_2$$7);
		} else {
			ZEPHIR_INIT_VAR(&_3$$8);
			zephir_fast_strtoupper(&_3$$8, method);
			zephir_update_property_zval(this_ptr, SL("method"), &_3$$8);
		}
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SSS(&_4, "#", "[.\\+*?^$=!|]", "#");
	zephir_read_property(&_5, this_ptr, SL("routeUri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "\\\\$0");
	ZEPHIR_CALL_FUNCTION(&regex, "preg_replace", NULL, 82, &_4, &_6, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "[");
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_strpos(&_7, &regex, &_6, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_7)) {
		ZEPHIR_INIT_VAR(&_8$$9);
		ZEPHIR_INIT_VAR(&_9$$9);
		zephir_create_array(&_9$$9, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_10$$9);
		ZVAL_STRING(&_10$$9, "[");
		zephir_array_fast_append(&_9$$9, &_10$$9);
		ZEPHIR_INIT_NVAR(&_10$$9);
		ZVAL_STRING(&_10$$9, "]");
		zephir_array_fast_append(&_9$$9, &_10$$9);
		ZEPHIR_INIT_VAR(&_11$$9);
		zephir_create_array(&_11$$9, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_10$$9);
		ZVAL_STRING(&_10$$9, "(?:");
		zephir_array_fast_append(&_11$$9, &_10$$9);
		ZEPHIR_INIT_NVAR(&_10$$9);
		ZVAL_STRING(&_10$$9, ")?");
		zephir_array_fast_append(&_11$$9, &_10$$9);
		zephir_fast_str_replace(&_8$$9, &_9$$9, &_11$$9, &regex TSRMLS_CC);
		ZEPHIR_CPY_WRT(&regex, &_8$$9);
	}
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "{");
	zephir_array_fast_append(&_13, &_14);
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "}");
	zephir_array_fast_append(&_13, &_14);
	ZEPHIR_INIT_VAR(&_15);
	zephir_create_array(&_15, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "(?P<");
	zephir_array_fast_append(&_15, &_14);
	ZEPHIR_INIT_VAR(&_16);
	ZEPHIR_CONCAT_SSS(&_16, ">", "[^/.,;?\n]++", ")");
	zephir_array_fast_append(&_15, &_16);
	zephir_fast_str_replace(&_12, &_13, &_15, &regex TSRMLS_CC);
	ZEPHIR_CPY_WRT(&regex, &_12);
	zephir_read_property(&_17, this_ptr, SL("regexMap"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_17))) {
		ZEPHIR_INIT_VAR(&search);
		array_init(&search);
		ZEPHIR_INIT_VAR(&replace);
		array_init(&replace);
		zephir_read_property(&_18$$10, this_ptr, SL("regexMap"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_18$$10, 0, "ice/mvc/route.zep", 120);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_18$$10), _20$$10, _21$$10, _19$$10)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_21$$10 != NULL) { 
				ZVAL_STR_COPY(&key, _21$$10);
			} else {
				ZVAL_LONG(&key, _20$$10);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _19$$10);
			ZEPHIR_INIT_LNVAR(_22$$11);
			ZEPHIR_CONCAT_SVSS(&_22$$11, "<", &key, ">", "[^/.,;?\n]++");
			zephir_array_append(&search, &_22$$11, PH_SEPARATE, "ice/mvc/route.zep", 116);
			ZEPHIR_INIT_LNVAR(_23$$11);
			ZEPHIR_CONCAT_SVSV(&_23$$11, "<", &key, ">", &value);
			zephir_array_append(&replace, &_23$$11, PH_SEPARATE, "ice/mvc/route.zep", 117);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZEPHIR_INIT_VAR(&_24$$10);
		zephir_fast_str_replace(&_24$$10, &search, &replace, &regex TSRMLS_CC);
		ZEPHIR_CPY_WRT(&regex, &_24$$10);
	}
	ZEPHIR_INIT_VAR(&_25);
	ZEPHIR_CONCAT_SVS(&_25, "#^", &regex, "$#uD");
	zephir_update_property_zval(this_ptr, SL("routeRegex"), &_25);
	ZEPHIR_MM_RESTORE();

}

/**
 * Tests if the route matches a given URI and method.
 *
 * <pre><code>
 *     // Params: controller = blog, action = edit, id = 10
 *     $params = route->matches("/blog/edit/10");
 * </code></pre>
 *
 * @param string URI to match
 * @param string method
 * @return array|false|null Routed parameters, method not allowed or no match
 */
PHP_METHOD(Ice_Mvc_Route, matches) {

	zend_bool _6$$5;
	zend_string *_5;
	zend_ulong _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *method_param = NULL, params, key, value, matches, _0, _1, _2, *_3;
	zval uri, method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri_param, &method_param);

	zephir_get_strval(&uri, uri_param);
	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "*");
	} else {
		zephir_get_strval(&method, method_param);
	}


	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkmethod", NULL, 0, &method);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, SL("routeRegex"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_preg_match(&_2, &_1, &uri, &matches, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_is_true(&_2))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&params);
	zephir_read_property(&params, this_ptr, SL("defaults"), PH_NOISY_CC);
	zephir_is_iterable(&matches, 0, "ice/mvc/route.zep", 161);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&matches), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&key, _5);
		} else {
			ZVAL_LONG(&key, _4);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _3);
		_6$$5 = Z_TYPE_P(&key) == IS_LONG;
		if (!(_6$$5)) {
			_6$$5 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
		}
		if (_6$$5) {
			continue;
		}
		zephir_array_update_zval(&params, &key, &value, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&params);

}

/**
 * Tests if the route allows a given method.
 *
 * @param string method
 * @return boolean
 */
PHP_METHOD(Ice_Mvc_Route, checkMethod) {

	zend_bool _1, _4$$3, _6$$3, _8$$3;
	zval *method_param = NULL, _0, _2$$4, _3$$3, _5$$3, _7$$3, _9$$3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(&method, method_param);


	zephir_read_property(&_0, this_ptr, SL("method"), PH_NOISY_CC | PH_READONLY);
	_1 = !ZEPHIR_IS_STRING(&_0, "*");
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(&method, "*");
	}
	if (_1) {
		if (!(ZEPHIR_IS_EMPTY(&method))) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_fast_strtoupper(&_2$$4, &method);
			zephir_get_strval(&method, &_2$$4);
		}
		if (ZEPHIR_IS_STRING_IDENTICAL(&method, "HEAD")) {
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_STRING(&method, "GET");
		}
		ZEPHIR_OBS_VAR(&_3$$3);
		zephir_read_property(&_3$$3, this_ptr, SL("method"), PH_NOISY_CC);
		_4$$3 = Z_TYPE_P(&_3$$3) == IS_STRING;
		if (_4$$3) {
			zephir_read_property(&_5$$3, this_ptr, SL("method"), PH_NOISY_CC | PH_READONLY);
			_4$$3 = !ZEPHIR_IS_EQUAL(&method, &_5$$3);
		}
		_6$$3 = _4$$3;
		if (!(_6$$3)) {
			ZEPHIR_OBS_VAR(&_7$$3);
			zephir_read_property(&_7$$3, this_ptr, SL("method"), PH_NOISY_CC);
			_8$$3 = Z_TYPE_P(&_7$$3) == IS_ARRAY;
			if (_8$$3) {
				zephir_read_property(&_9$$3, this_ptr, SL("method"), PH_NOISY_CC | PH_READONLY);
				_8$$3 = !(zephir_fast_in_array(&method, &_9$$3 TSRMLS_CC));
			}
			_6$$3 = _8$$3;
		}
		if (_6$$3) {
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Generates a URI for the current route based on the parameters given. (AKA. reverse route)
 *
 * <pre><code>
 *     // Using the "default" route: /blog/post/10
 *     $uri = $route->uri(["controller" => "blog", "action" => "post", "id" => 10]);
 *     if (!$uri) echo $route->getError();
 * </code></pre>
 *
 * @param array URI parameters
 * @return string|false
 */
PHP_METHOD(Ice_Mvc_Route, uri) {

	zval _17, _12$$5;
	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, defaults, uri, param, search, key, replace, matches, _0, _1, _2, _4, _5, _7, _8, _9, _18, _22, _23, _24, _25, _6$$4, _10$$5, _11$$5, _13$$5, _16$$5, _14$$7, _15$$7, _19$$10, _20$$9, _21$$9;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&search);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &params_param);

	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	}


	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	ZEPHIR_OBS_VAR(&uri);
	zephir_read_property(&uri, this_ptr, SL("routeUri"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("defaults"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&defaults, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "{");
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strpos(&_2, &uri, &_1, 0 );
	_3 = ZEPHIR_IS_FALSE_IDENTICAL(&_2);
	if (_3) {
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "[");
		ZEPHIR_INIT_VAR(&_5);
		zephir_fast_strpos(&_5, &uri, &_4, 0 );
		_3 = ZEPHIR_IS_FALSE_IDENTICAL(&_5);
	}
	if (_3) {
		RETURN_CCTOR(&uri);
	}
	if (!(ZEPHIR_IS_EMPTY(&params))) {
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_fast_array_merge(&_6$$4, &defaults, &params TSRMLS_CC);
		ZEPHIR_CPY_WRT(&defaults, &_6$$4);
	}
	while (1) {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "#\\[[^[\\]]++\\]#");
		ZEPHIR_INIT_NVAR(&_8);
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_STRING(&_9, "#\\[[^[\\]]++\\]#");
		zephir_preg_match(&_8, &_9, &uri, &matches, 0, 0 , 0  TSRMLS_CC);
		if (!(zephir_is_true(&_8))) {
			break;
		}
		ZEPHIR_OBS_NVAR(&search);
		zephir_array_fetch_long(&search, &matches, 0, PH_NOISY, "ice/mvc/route.zep", 219 TSRMLS_CC);
		ZVAL_LONG(&_10$$5, 1);
		ZVAL_LONG(&_11$$5, -1);
		ZEPHIR_INIT_NVAR(&replace);
		zephir_substr(&replace, &search, 1 , -1 , 0);
		while (1) {
			ZEPHIR_INIT_LNVAR(_12$$5);
			ZEPHIR_CONCAT_SSS(&_12$$5, "#", "\\{([a-zA-Z0-9_]++)\\}", "#");
			ZEPHIR_INIT_NVAR(&_13$$5);
			zephir_preg_match(&_13$$5, &_12$$5, &replace, &matches, 0, 0 , 0  TSRMLS_CC);
			if (!(zephir_is_true(&_13$$5))) {
				break;
			}
			ZEPHIR_OBS_NVAR(&key);
			zephir_array_fetch_long(&key, &matches, 0, PH_NOISY, "ice/mvc/route.zep", 225 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&param);
			zephir_array_fetch_long(&param, &matches, 1, PH_NOISY, "ice/mvc/route.zep", 226 TSRMLS_CC);
			if (zephir_array_isset(&defaults, &param)) {
				ZEPHIR_INIT_NVAR(&_14$$7);
				zephir_array_fetch(&_15$$7, &defaults, &param, PH_NOISY | PH_READONLY, "ice/mvc/route.zep", 230 TSRMLS_CC);
				zephir_fast_str_replace(&_14$$7, &key, &_15$$7, &replace TSRMLS_CC);
				ZEPHIR_CPY_WRT(&replace, &_14$$7);
			} else {
				ZEPHIR_INIT_NVAR(&replace);
				ZVAL_STRING(&replace, "");
				break;
			}
		}
		ZEPHIR_INIT_NVAR(&_16$$5);
		zephir_fast_str_replace(&_16$$5, &search, &replace, &uri TSRMLS_CC);
		ZEPHIR_CPY_WRT(&uri, &_16$$5);
	}
	while (1) {
		ZEPHIR_INIT_LNVAR(_17);
		ZEPHIR_CONCAT_SSS(&_17, "#", "\\{([a-zA-Z0-9_]++)\\}", "#");
		ZEPHIR_INIT_NVAR(&_18);
		zephir_preg_match(&_18, &_17, &uri, &matches, 0, 0 , 0  TSRMLS_CC);
		if (!(zephir_is_true(&_18))) {
			break;
		}
		ZEPHIR_OBS_NVAR(&key);
		zephir_array_fetch_long(&key, &matches, 0, PH_NOISY, "ice/mvc/route.zep", 242 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&param);
		zephir_array_fetch_long(&param, &matches, 1, PH_NOISY, "ice/mvc/route.zep", 243 TSRMLS_CC);
		if (!(zephir_array_isset(&defaults, &param))) {
			ZEPHIR_INIT_LNVAR(_19$$10);
			ZEPHIR_CONCAT_SV(&_19$$10, "Required route parameter not passed: ", &param);
			zephir_update_property_zval(this_ptr, SL("error"), &_19$$10);
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_20$$9);
		zephir_array_fetch(&_21$$9, &defaults, &param, PH_NOISY | PH_READONLY, "ice/mvc/route.zep", 251 TSRMLS_CC);
		zephir_fast_str_replace(&_20$$9, &key, &_21$$9, &uri TSRMLS_CC);
		ZEPHIR_CPY_WRT(&uri, &_20$$9);
	}
	ZEPHIR_INIT_VAR(&_22);
	ZEPHIR_INIT_VAR(&_23);
	ZVAL_STRING(&_23, "/");
	zephir_fast_trim(&_22, &uri, &_23, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_24);
	ZVAL_STRING(&_24, "#//+#");
	ZEPHIR_INIT_VAR(&_25);
	ZVAL_STRING(&_25, "/");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 82, &_24, &_25, &_22);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Ice_Mvc_Route(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("defaults"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("action"), SL("index"));
			zephir_update_property_zval(this_ptr, SL("defaults"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("regexMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("regexMap"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

