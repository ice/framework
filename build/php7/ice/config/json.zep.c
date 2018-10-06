
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
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * Adapter for get config from json files.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Config_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Config, Json, ice, config_json, ice_config_ce, ice_config_json_method_entry, 0);

	return SUCCESS;

}

/**
 * Config json constructor.
 *
 * @param string data Path to the file or json string
 */
PHP_METHOD(Ice_Config_Json, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data = NULL, data_sub, __$true, __$null, _0$$4, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = &data_sub;
		ZEPHIR_CPY_WRT(data, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}


	if (Z_TYPE_P(data) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Data must be a json string or path to the file", "ice/config/json.zep", 27);
		return;
	}
	if ((zephir_file_exists(data TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_file_get_contents(&_0$$4, data TSRMLS_CC);
		ZEPHIR_CPY_WRT(data, &_0$$4);
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_json_decode(&_2, data, zephir_get_intval(&__$true) );
	ZEPHIR_CALL_PARENT(NULL, ice_config_json_ce, getThis(), "__construct", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

