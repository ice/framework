
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This class represents every route added to the router.
 *
 * @package     Ice/Router
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 * @uses        FastRoute https://github.com/nikic/FastRoute/commit/30470b69c785f7c28a0203be86692f4780a43bdf
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_FastRoute) {

	ZEPHIR_REGISTER_CLASS(Ice\\Mvc, FastRoute, ice, mvc_fastroute, ice_mvc_fastroute_method_entry, 0);

	zend_declare_property_null(ice_mvc_fastroute_ce, SL("httpMethod"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastroute_ce, SL("regex"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastroute_ce, SL("variables"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(ice_mvc_fastroute_ce, SL("handler"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructs a route (value object).
 *
 * @param string httpMethod
 * @param mixed handler
 * @param string regex
 * @param array variables
 */
PHP_METHOD(Ice_Mvc_FastRoute, __construct) {

	zval variables;
	zval *httpMethod_param = NULL, *handler, handler_sub, *regex_param = NULL, *variables_param = NULL;
	zval httpMethod, regex;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethod);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&variables);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &httpMethod_param, &handler, &regex_param, &variables_param);

	zephir_get_strval(&httpMethod, httpMethod_param);
	zephir_get_strval(&regex, regex_param);
	zephir_get_arrval(&variables, variables_param);


	zephir_update_property_zval(this_ptr, SL("httpMethod"), &httpMethod);
	zephir_update_property_zval(this_ptr, SL("handler"), handler);
	zephir_update_property_zval(this_ptr, SL("regex"), &regex);
	zephir_update_property_zval(this_ptr, SL("variables"), &variables);
	ZEPHIR_MM_RESTORE();

}

/**
 * Tests whether this route matches the given string.
 *
 * @param string str
 * @return bool
 */
PHP_METHOD(Ice_Mvc_FastRoute, matches) {

	zval *str_param = NULL, regex, _0, _1, _2, _3;
	zval str;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(&str, str_param);


	zephir_read_property(&_0, this_ptr, SL("regex"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "~^", &_0, "$~");
	ZEPHIR_CPY_WRT(&regex, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_preg_match(&_3, &regex, &str, &_2, 0, 0 , 0  TSRMLS_CC);
	RETURN_MM_BOOL(zephir_get_boolval(&_3));

}

