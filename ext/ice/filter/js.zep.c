
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
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Minify js string.
 *
 * @package     Ice/Filter
 * @category    Minification
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 * @uses        jsmin.c www.crockford.com
 */
ZEPHIR_INIT_CLASS(Ice_Filter_Js) {

	ZEPHIR_REGISTER_CLASS(Ice\\Filter, Js, ice, filter_js, ice_filter_js_method_entry, 0);

	return SUCCESS;

}

/**
 * Minify the js.
 *
 * @param string js JS code to minify
 * @return string
 */
PHP_METHOD(Ice_Filter_Js, sanitize) {

	long _0;
	int i;
	char c, next;
	zval *js_param = NULL;
	zval *js = NULL, *min;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &js_param);

	zephir_get_strval(js, js_param);
	ZEPHIR_INIT_VAR(min);
	ZVAL_STRING(min, "", 1);


	for (_0 = 0; _0 < Z_STRLEN_P(js); _0++) {
		i = _0; 
		c = ZEPHIR_STRING_OFFSET(js, _0);
		next = ZEPHIR_STRING_OFFSET(js, i);
		next = next;
		zephir_concat_self_char(&min, c TSRMLS_CC);
	}
	RETURN_CTOR(min);

}

