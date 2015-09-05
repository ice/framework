
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * PHP template engine.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_Php) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc\\View\\Engine, Php, ice, mvc_view_engine_php, ice_mvc_view_engine_ce, ice_mvc_view_engine_php_method_entry, 0);

	return SUCCESS;

}

/**
 * Render the PHP file.
 *
 * @param string path
 * @param array data
 * @return string
 */
PHP_METHOD(Ice_Mvc_View_Engine_Php, render) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *path_param = NULL, *data_param = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &data_param);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	Z_SET_ISREF_P(data);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 128, data);
	Z_UNSET_ISREF_P(data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 129);
	zephir_check_call_status();
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 130);
	zephir_check_call_status();
	RETURN_MM();

}

