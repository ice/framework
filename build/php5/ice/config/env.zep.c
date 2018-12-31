
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
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Config_Env) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Config, Env, ice, config_env, ice_config_ini_ce, ice_config_env_method_entry, 0);

	return SUCCESS;

}

/**
 * Env constructor.
 *
 * @param string data Path to the env file
 */
PHP_METHOD(Ice_Config_Env, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data = NULL, *_ENV = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_ENV, SS("_ENV") TSRMLS_CC);
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_PARENT(NULL, ice_config_env_ce, getThis(), "__construct", &_0, 94, data);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_fast_array_merge(_1, &(_ENV), &(_2) TSRMLS_CC);
	ZEPHIR_CPY_WRT(_ENV, _1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether environment has the key.
 *
 * @return boolean
 */
PHP_METHOD(Ice_Config_Env, has) {

	zval *key_param = NULL, *_ENV;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_ENV, SS("_ENV") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	RETURN_MM_BOOL(zephir_array_isset(_ENV, key));

}

/**
 * Retrieve a single key from the environment.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Config_Env, get) {

	zend_bool required;
	zval *key_param = NULL, *defaultValue = NULL, *required_param = NULL, *_ENV, *value = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_ENV, SS("_ENV") TSRMLS_CC);
	zephir_fetch_params(1, 1, 2, &key_param, &defaultValue, &required_param);

	zephir_get_strval(key, key_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!required_param) {
		required = 0;
	} else {
		required = zephir_get_boolval(required_param);
	}


	if (zephir_array_isset_fetch(&value, _ENV, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Assigns a value to the specified environment key.
 *
 * @return object
 */
PHP_METHOD(Ice_Config_Env, set) {

	zval *key_param = NULL, *value, *_ENV;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_ENV, SS("_ENV") TSRMLS_CC);
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_array_update_zval(&_ENV, key, &value, PH_COPY | PH_SEPARATE);
	RETURN_THIS();

}

/**
 * Remove environment key.
 *
 * @return object
 */
PHP_METHOD(Ice_Config_Env, remove) {

	zval *key_param = NULL, *_ENV;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_ENV, SS("_ENV") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	zephir_array_unset(&_ENV, key, PH_SEPARATE);
	RETURN_THIS();

}

/**
 * Fetch all data.
 *
 * @return array
 */
PHP_METHOD(Ice_Config_Env, getData) {

	zval *_ENV;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_ENV, SS("_ENV") TSRMLS_CC);

	RETVAL_ZVAL(_ENV, 1, 0);
	RETURN_MM();

}

