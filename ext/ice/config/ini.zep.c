
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
#include "kernel/operators.h"
#include "kernel/hash.h"


/**
 * Adapter for get config from ini files.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Config_Ini) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Config, Ini, ice, config_ini, ice_config_ce, ice_config_ini_method_entry, 0);

	return SUCCESS;

}

/**
 * Config ini constructor.
 *
 * @param string file Path to the ini file
 */
PHP_METHOD(Ice_Config_Ini, __construct) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL, *_5 = NULL;
	zval *file_param = NULL, *ini = NULL, *_1 = NULL, *_3;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &file_param);

	if (!file_param) {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	} else {
		zephir_get_strval(file, file_param);
	}


	ZEPHIR_CALL_FUNCTION(&ini, "parse_ini_file", &_0, file, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 3);
	zephir_array_fast_append(_2, this_ptr);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "cast", 1);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "arraymaprecursive", &_4, _2, ini);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(ini, _1);
	ZEPHIR_CALL_PARENT(NULL, ice_config_ini_ce, this_ptr, "__construct", &_5, ini);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Return real type from a string, eg. "true" => true.
 *
 * @param string value
 * @return mixed
 */
PHP_METHOD(Ice_Config_Ini, cast) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *value, *_0 = NULL, *_1 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "/[^0-9.]+/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_1, "preg_match", &_2, _0, value);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (!(zephir_is_true(_1))) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "/[.]+/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_3, "preg_match", &_2, _0, value);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
			if (zephir_is_true(_3)) {
				RETURN_MM_DOUBLE(zephir_get_doubleval(value));
			} else {
				RETURN_MM_LONG(zephir_get_intval(value));
			}
		}
		do {
			if (ZEPHIR_IS_STRING(value, "false") || ZEPHIR_IS_STRING(value, "FALSE")) {
				RETURN_MM_BOOL(0);
			}
			if (ZEPHIR_IS_STRING(value, "true") || ZEPHIR_IS_STRING(value, "TRUE")) {
				RETURN_MM_BOOL(1);
			}
			if (ZEPHIR_IS_STRING(value, "null") || ZEPHIR_IS_STRING(value, "NULL")) {
				RETURN_MM_NULL();
			}
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
		} while(0);

	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Map the array recursively.
 *
 * @param object callback Callback to apply
 * @param array data Data to convert
 * @return array
 */
PHP_METHOD(Ice_Config_Ini, arrayMapRecursive) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *callback, *data, *key = NULL, *value = NULL, **_2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &callback, &data);

	ZEPHIR_SEPARATE_PARAM(data);


	zephir_is_iterable(data, &_1, &_0, 1, 0, "ice/config/ini.zep", 86);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(value) == IS_ARRAY) {
			zephir_array_fetch(&_4, data, key, PH_NOISY | PH_READONLY, "ice/config/ini.zep", 80 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "arraymaprecursive", &_5, callback, _4);
			zephir_check_call_status();
			zephir_array_update_zval(&data, key, &_3, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_fetch(&_4, data, key, PH_NOISY | PH_READONLY, "ice/config/ini.zep", 83 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_3, "call_user_func", &_6, callback, _4);
			zephir_check_call_status();
			zephir_array_update_zval(&data, key, &_3, PH_COPY | PH_SEPARATE);
		}
	}
	RETVAL_ZVAL(data, 1, 0);
	RETURN_MM();

}

