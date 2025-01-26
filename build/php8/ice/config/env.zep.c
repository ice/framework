
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * Environment helper.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2025 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Config_Env)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Config, Env, ice, config_env, ice_config_ini_ce, ice_config_env_method_entry, 0);

	return SUCCESS;
}

/**
 * Env constructor.
 *
 * @param string data Path to the env file
 */
PHP_METHOD(Ice_Config_Env, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, _ENV, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_ENV);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_ENV, SL("_ENV"));
	zephir_fetch_params(1, 0, 1, &data);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	ZEPHIR_CALL_PARENT(NULL, ice_config_env_ce, getThis(), "__construct", NULL, 0, data);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_ENV, &_1);
	ZEPHIR_HASH_COPY(&_ENV, &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Check whether environment has the key.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Config_Env, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _ENV;
	zval key;

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_ENV);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_ENV, SL("_ENV"));
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);
	RETURN_MM_BOOL(zephir_array_isset(&_ENV, &key));
}

/**
 * Retrieve a single key from the environment.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Config_Env, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool required;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, *required_param = NULL, _ENV, __$null, value;
	zval key;

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_ENV);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(required)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_ENV, SL("_ENV"));
	zephir_fetch_params(1, 1, 2, &key_param, &defaultValue, &required_param);
	zephir_get_strval(&key, key_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!required_param) {
		required = 0;
	} else {
		}
	zephir_memory_observe(&value);
	if (zephir_array_isset_fetch(&value, &_ENV, &key, 0)) {
		RETURN_CCTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();
}

/**
 * Assigns a value to the specified environment key.
 *
 * @return object
 */
PHP_METHOD(Ice_Config_Env, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *value, value_sub, _ENV;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_ENV);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_ENV, SL("_ENV"));
	zephir_fetch_params(1, 2, 0, &key_param, &value);
	zephir_get_strval(&key, key_param);
	zephir_array_update_zval(&_ENV, &key, value, PH_COPY | PH_SEPARATE);
	RETURN_THIS();
}

/**
 * Remove environment key.
 *
 * @return object
 */
PHP_METHOD(Ice_Config_Env, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _ENV;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_ENV);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_ENV, SL("_ENV"));
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);
	zephir_array_unset(&_ENV, &key, PH_SEPARATE);
	RETURN_THIS();
}

/**
 * Fetch all data.
 *
 * @return array
 */
PHP_METHOD(Ice_Config_Env, getData)
{
	zval _ENV;

	ZVAL_UNDEF(&_ENV);
	zephir_get_global(&_ENV, SL("_ENV"));

	RETVAL_ZVAL(&_ENV, 1, 0);
	return;
}

