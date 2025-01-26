
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
#include "kernel/object.h"


/**
 * Adapter for get config from json files.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2025 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Config_Json)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Config, Json, ice, config_json, ice_config_ce, ice_config_json_method_entry, 0);

	return SUCCESS;
}

/**
 * Config json constructor.
 *
 * @param string data Path to the file or json string
 */
PHP_METHOD(Ice_Config_Json, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, __$true, __$null, _0$$4, _1;

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &data);
	if (!data) {
		data = &data_sub;
		ZEPHIR_CPY_WRT(data, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}
	if (Z_TYPE_P(data) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Data must be a json string or path to the file", "ice/config/json.zep", 26);
		return;
	}
	if ((zephir_file_exists(data) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_file_get_contents(&_0$$4, data);
		ZEPHIR_CPY_WRT(data, &_0$$4);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_json_decode(&_1, data, zephir_get_intval(&__$true) );
	ZEPHIR_CALL_PARENT(NULL, ice_config_json_ce, getThis(), "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

