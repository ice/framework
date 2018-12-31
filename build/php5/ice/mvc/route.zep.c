
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
	zend_declare_class_constant_string(ice_mvc_route_ce, SL("REGEX_KEYWORD"), "\\{([a-zA-Z0-9_]++)\\}" TSRMLS_CC);

	zend_declare_class_constant_string(ice_mvc_route_ce, SL("REGEX_PLACEHOLDER"), "[^/.,;?\n]++" TSRMLS_CC);

	zend_declare_class_constant_string(ice_mvc_route_ce, SL("REGEX_ESCAPE"), "[.\\+*?^$=!|]" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_Route, getDefaults) {

	

	RETURN_MEMBER(getThis(), "defaults");

}

PHP_METHOD(Ice_Mvc_Route, setDefaults) {

	zval *defaults;

	zephir_fetch_params(0, 1, 0, &defaults);



	zephir_update_property_this(getThis(), SL("defaults"), defaults TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Ice_Mvc_Route, getMethod) {

	

	RETURN_MEMBER(getThis(), "method");

}

PHP_METHOD(Ice_Mvc_Route, getError) {

	

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

	HashTable *_20$$10;
	HashPosition _19$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *regexMap = NULL, *_13, *_15, *_9$$9, *_11$$9;
	zval *uri_param = NULL, *regexMap_param = NULL, *method = NULL, *regex = NULL, *search = NULL, *replace = NULL, *key = NULL, *value = NULL, *_5, *_6 = NULL, _7, *_12, *_14 = NULL, *_17, *_25, *_0$$5, _1$$7, *_2$$7 = NULL, *_3$$8, *_8$$9, *_10$$9 = NULL, *_18$$10, **_21$$10, *_24$$10, *_22$$11 = NULL, *_23$$11 = NULL;
	zval *uri = NULL, *_4, *_16;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &uri_param, &regexMap_param, &method);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	} else {
		zephir_get_strval(uri, uri_param);
	}
	if (!regexMap_param) {
		ZEPHIR_INIT_VAR(regexMap);
		array_init(regexMap);
	} else {
	regexMap = regexMap_param;
	}
	if (!method) {
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "*", 1);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(uri, "")) {
		RETURN_MM_NULL();
	}
	zephir_update_property_this(getThis(), SL("routeUri"), uri TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(regexMap))) {
		zephir_update_property_this(getThis(), SL("regexMap"), regexMap TSRMLS_CC);
	}
	if (ZEPHIR_IS_EMPTY(method)) {
		ZEPHIR_INIT_ZVAL_NREF(_0$$5);
		ZVAL_STRING(_0$$5, "*", 1);
		zephir_update_property_this(getThis(), SL("method"), _0$$5 TSRMLS_CC);
	} else {
		if (Z_TYPE_P(method) == IS_ARRAY) {
			ZEPHIR_SINIT_VAR(_1$$7);
			ZVAL_STRING(&_1$$7, "strtoupper", 0);
			ZEPHIR_CALL_FUNCTION(&_2$$7, "array_map", NULL, 50, &_1$$7, method);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("method"), _2$$7 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_3$$8);
			zephir_fast_strtoupper(_3$$8, method);
			zephir_update_property_this(getThis(), SL("method"), _3$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SSS(_4, "#", "[.\\+*?^$=!|]", "#");
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("routeUri"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "\\\\$0", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&regex, "preg_replace", NULL, 93, _4, _6, _5);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "[", 0);
	ZEPHIR_INIT_NVAR(_6);
	zephir_fast_strpos(_6, regex, &_7, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(_6)) {
		ZEPHIR_INIT_VAR(_8$$9);
		ZEPHIR_INIT_VAR(_9$$9);
		zephir_create_array(_9$$9, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10$$9);
		ZVAL_STRING(_10$$9, "[", 1);
		zephir_array_fast_append(_9$$9, _10$$9);
		ZEPHIR_INIT_NVAR(_10$$9);
		ZVAL_STRING(_10$$9, "]", 1);
		zephir_array_fast_append(_9$$9, _10$$9);
		ZEPHIR_INIT_VAR(_11$$9);
		zephir_create_array(_11$$9, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_10$$9);
		ZVAL_STRING(_10$$9, "(?:", 1);
		zephir_array_fast_append(_11$$9, _10$$9);
		ZEPHIR_INIT_NVAR(_10$$9);
		ZVAL_STRING(_10$$9, ")?", 1);
		zephir_array_fast_append(_11$$9, _10$$9);
		zephir_fast_str_replace(&_8$$9, _9$$9, _11$$9, regex TSRMLS_CC);
		ZEPHIR_CPY_WRT(regex, _8$$9);
	}
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_INIT_VAR(_13);
	zephir_create_array(_13, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_STRING(_14, "{", 1);
	zephir_array_fast_append(_13, _14);
	ZEPHIR_INIT_NVAR(_14);
	ZVAL_STRING(_14, "}", 1);
	zephir_array_fast_append(_13, _14);
	ZEPHIR_INIT_VAR(_15);
	zephir_create_array(_15, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_14);
	ZVAL_STRING(_14, "(?P<", 1);
	zephir_array_fast_append(_15, _14);
	ZEPHIR_INIT_VAR(_16);
	ZEPHIR_CONCAT_SSS(_16, ">", "[^/.,;?\n]++", ")");
	zephir_array_fast_append(_15, _16);
	zephir_fast_str_replace(&_12, _13, _15, regex TSRMLS_CC);
	ZEPHIR_CPY_WRT(regex, _12);
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("regexMap"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_17))) {
		ZEPHIR_INIT_VAR(search);
		array_init(search);
		ZEPHIR_INIT_VAR(replace);
		array_init(replace);
		_18$$10 = zephir_fetch_nproperty_this(this_ptr, SL("regexMap"), PH_NOISY_CC);
		zephir_is_iterable(_18$$10, &_20$$10, &_19$$10, 0, 0, "ice/mvc/route.zep", 120);
		for (
		  ; zend_hash_get_current_data_ex(_20$$10, (void**) &_21$$10, &_19$$10) == SUCCESS
		  ; zend_hash_move_forward_ex(_20$$10, &_19$$10)
		) {
			ZEPHIR_GET_HMKEY(key, _20$$10, _19$$10);
			ZEPHIR_GET_HVALUE(value, _21$$10);
			ZEPHIR_INIT_LNVAR(_22$$11);
			ZEPHIR_CONCAT_SVSS(_22$$11, "<", key, ">", "[^/.,;?\n]++");
			zephir_array_append(&search, _22$$11, PH_SEPARATE, "ice/mvc/route.zep", 116);
			ZEPHIR_INIT_LNVAR(_23$$11);
			ZEPHIR_CONCAT_SVSV(_23$$11, "<", key, ">", value);
			zephir_array_append(&replace, _23$$11, PH_SEPARATE, "ice/mvc/route.zep", 117);
		}
		ZEPHIR_INIT_VAR(_24$$10);
		zephir_fast_str_replace(&_24$$10, search, replace, regex TSRMLS_CC);
		ZEPHIR_CPY_WRT(regex, _24$$10);
	}
	ZEPHIR_INIT_VAR(_25);
	ZEPHIR_CONCAT_SVS(_25, "#^", regex, "$#uD");
	zephir_update_property_this(getThis(), SL("routeRegex"), _25 TSRMLS_CC);
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
	HashTable *_4;
	HashPosition _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *method_param = NULL, *params = NULL, *key = NULL, *value = NULL, *matches = NULL, *_0 = NULL, *_1, *_2, **_5;
	zval *uri = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri_param, &method_param);

	zephir_get_strval(uri, uri_param);
	if (!method_param) {
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "*", 1);
	} else {
		zephir_get_strval(method, method_param);
	}


	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkmethod", NULL, 0, method);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("routeRegex"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_preg_match(_2, _1, uri, matches, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_is_true(_2))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(params);
	zephir_read_property_this(&params, this_ptr, SL("defaults"), PH_NOISY_CC);
	zephir_is_iterable(matches, &_4, &_3, 0, 0, "ice/mvc/route.zep", 161);
	for (
	  ; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(key, _4, _3);
		ZEPHIR_GET_HVALUE(value, _5);
		_6$$5 = Z_TYPE_P(key) == IS_LONG;
		if (!(_6$$5)) {
			_6$$5 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
		}
		if (_6$$5) {
			continue;
		}
		zephir_array_update_zval(&params, key, &value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(params);

}

/**
 * Tests if the route allows a given method.
 *
 * @param string method
 * @return boolean
 */
PHP_METHOD(Ice_Mvc_Route, checkMethod) {

	zend_bool _1, _4$$3, _6$$3, _8$$3;
	zval *method_param = NULL, *_0, *_2$$4, *_3$$3, *_5$$3, *_7$$3, *_9$$3;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(method, method_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	_1 = !ZEPHIR_IS_STRING(_0, "*");
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(method, "*");
	}
	if (_1) {
		if (!(ZEPHIR_IS_EMPTY(method))) {
			ZEPHIR_INIT_VAR(_2$$4);
			zephir_fast_strtoupper(_2$$4, method);
			zephir_get_strval(method, _2$$4);
		}
		if (ZEPHIR_IS_STRING_IDENTICAL(method, "HEAD")) {
			ZEPHIR_INIT_NVAR(method);
			ZVAL_STRING(method, "GET", 1);
		}
		ZEPHIR_OBS_VAR(_3$$3);
		zephir_read_property_this(&_3$$3, this_ptr, SL("method"), PH_NOISY_CC);
		_4$$3 = Z_TYPE_P(_3$$3) == IS_STRING;
		if (_4$$3) {
			_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
			_4$$3 = !ZEPHIR_IS_EQUAL(method, _5$$3);
		}
		_6$$3 = _4$$3;
		if (!(_6$$3)) {
			ZEPHIR_OBS_VAR(_7$$3);
			zephir_read_property_this(&_7$$3, this_ptr, SL("method"), PH_NOISY_CC);
			_8$$3 = Z_TYPE_P(_7$$3) == IS_ARRAY;
			if (_8$$3) {
				_9$$3 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
				_8$$3 = !(zephir_fast_in_array(method, _9$$3 TSRMLS_CC));
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

	zval *_17 = NULL, *_12$$5 = NULL;
	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, *defaults = NULL, *uri = NULL, *param = NULL, *search = NULL, *key = NULL, *replace = NULL, *matches = NULL, *_0, _1, *_2, _4, *_5, _7 = zval_used_for_init, *_8 = NULL, _9 = zval_used_for_init, *_18 = NULL, *_22, _23, *_24, *_25, *_6$$4, _10$$5 = zval_used_for_init, _11$$5 = zval_used_for_init, *_13$$5 = NULL, *_16$$5 = NULL, *_14$$7 = NULL, *_15$$7, *_19$$10 = NULL, *_20$$9 = NULL, *_21$$9;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &params_param);

	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
	params = params_param;
	}


	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_OBS_VAR(uri);
	zephir_read_property_this(&uri, this_ptr, SL("routeUri"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("defaults"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(defaults, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "{", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_strpos(_2, uri, &_1, 0 );
	_3 = ZEPHIR_IS_FALSE_IDENTICAL(_2);
	if (_3) {
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "[", 0);
		ZEPHIR_INIT_VAR(_5);
		zephir_fast_strpos(_5, uri, &_4, 0 );
		_3 = ZEPHIR_IS_FALSE_IDENTICAL(_5);
	}
	if (_3) {
		RETURN_CCTOR(uri);
	}
	if (!(ZEPHIR_IS_EMPTY(params))) {
		ZEPHIR_INIT_VAR(_6$$4);
		zephir_fast_array_merge(_6$$4, &(defaults), &(params) TSRMLS_CC);
		ZEPHIR_CPY_WRT(defaults, _6$$4);
	}
	while (1) {
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_STRING(&_7, "#\\[[^[\\]]++\\]#", 0);
		ZEPHIR_INIT_NVAR(_8);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "#\\[[^[\\]]++\\]#", 0);
		zephir_preg_match(_8, &_9, uri, matches, 0, 0 , 0  TSRMLS_CC);
		if (!(zephir_is_true(_8))) {
			break;
		}
		ZEPHIR_OBS_NVAR(search);
		zephir_array_fetch_long(&search, matches, 0, PH_NOISY, "ice/mvc/route.zep", 219 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_10$$5);
		ZVAL_LONG(&_10$$5, 1);
		ZEPHIR_SINIT_NVAR(_11$$5);
		ZVAL_LONG(&_11$$5, -1);
		ZEPHIR_INIT_NVAR(replace);
		zephir_substr(replace, search, 1 , -1 , 0);
		while (1) {
			ZEPHIR_INIT_LNVAR(_12$$5);
			ZEPHIR_CONCAT_SSS(_12$$5, "#", "\\{([a-zA-Z0-9_]++)\\}", "#");
			ZEPHIR_INIT_NVAR(_13$$5);
			zephir_preg_match(_13$$5, _12$$5, replace, matches, 0, 0 , 0  TSRMLS_CC);
			if (!(zephir_is_true(_13$$5))) {
				break;
			}
			ZEPHIR_OBS_NVAR(key);
			zephir_array_fetch_long(&key, matches, 0, PH_NOISY, "ice/mvc/route.zep", 225 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(param);
			zephir_array_fetch_long(&param, matches, 1, PH_NOISY, "ice/mvc/route.zep", 226 TSRMLS_CC);
			if (zephir_array_isset(defaults, param)) {
				ZEPHIR_INIT_NVAR(_14$$7);
				zephir_array_fetch(&_15$$7, defaults, param, PH_NOISY | PH_READONLY, "ice/mvc/route.zep", 230 TSRMLS_CC);
				zephir_fast_str_replace(&_14$$7, key, _15$$7, replace TSRMLS_CC);
				ZEPHIR_CPY_WRT(replace, _14$$7);
			} else {
				ZEPHIR_INIT_NVAR(replace);
				ZVAL_STRING(replace, "", 1);
				break;
			}
		}
		ZEPHIR_INIT_NVAR(_16$$5);
		zephir_fast_str_replace(&_16$$5, search, replace, uri TSRMLS_CC);
		ZEPHIR_CPY_WRT(uri, _16$$5);
	}
	while (1) {
		ZEPHIR_INIT_LNVAR(_17);
		ZEPHIR_CONCAT_SSS(_17, "#", "\\{([a-zA-Z0-9_]++)\\}", "#");
		ZEPHIR_INIT_NVAR(_18);
		zephir_preg_match(_18, _17, uri, matches, 0, 0 , 0  TSRMLS_CC);
		if (!(zephir_is_true(_18))) {
			break;
		}
		ZEPHIR_OBS_NVAR(key);
		zephir_array_fetch_long(&key, matches, 0, PH_NOISY, "ice/mvc/route.zep", 242 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(param);
		zephir_array_fetch_long(&param, matches, 1, PH_NOISY, "ice/mvc/route.zep", 243 TSRMLS_CC);
		if (!(zephir_array_isset(defaults, param))) {
			ZEPHIR_INIT_LNVAR(_19$$10);
			ZEPHIR_CONCAT_SV(_19$$10, "Required route parameter not passed: ", param);
			zephir_update_property_this(getThis(), SL("error"), _19$$10 TSRMLS_CC);
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_20$$9);
		zephir_array_fetch(&_21$$9, defaults, param, PH_NOISY | PH_READONLY, "ice/mvc/route.zep", 251 TSRMLS_CC);
		zephir_fast_str_replace(&_20$$9, key, _21$$9, uri TSRMLS_CC);
		ZEPHIR_CPY_WRT(uri, _20$$9);
	}
	ZEPHIR_INIT_VAR(_22);
	ZEPHIR_SINIT_VAR(_23);
	ZVAL_STRING(&_23, "/", 0);
	zephir_fast_trim(_22, uri, &_23, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_24);
	ZVAL_STRING(_24, "#//+#", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_25);
	ZVAL_STRING(_25, "/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 93, _24, _25, _22);
	zephir_check_temp_parameter(_24);
	zephir_check_temp_parameter(_25);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object_value zephir_init_properties_Ice_Mvc_Route(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0, *_2, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("defaults"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1$$3, SS("action"), SL("index"), 1);
			zephir_update_property_this(getThis(), SL("defaults"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("regexMap"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("regexMap"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

