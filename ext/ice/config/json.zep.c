
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Adapter for get config from json files.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Config_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Config, Json, ice, config_json, ice_config_ce, ice_config_json_method_entry, 0);

	return SUCCESS;

}

/**
 * Config json constructor.
 *
 * @param string data Path to the json file
 */
PHP_METHOD(Ice_Config_Json, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL, *_1, *_2;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	if (unlikely(Z_TYPE_P(data_param) != IS_STRING && Z_TYPE_P(data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(data_param) == IS_STRING)) {
		zephir_get_strval(data, data_param);
	} else {
		ZEPHIR_INIT_VAR(data);
		ZVAL_EMPTY_STRING(data);
	}


	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_file_get_contents(_2, data TSRMLS_CC);
	zephir_json_decode(_1, &(_1), _2, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, ice_config_json_ce, this_ptr, "__construct", &_0, 26, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

