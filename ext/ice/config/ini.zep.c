
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/array.h"


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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *data = NULL, *ini = NULL, *raw = NULL, _1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		ZEPHIR_CPY_WRT(data, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}


	if (Z_TYPE_P(data) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The file path must be a string", "ice/config/ini.zep", 29);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ini, "parse_ini_file", &_0, 60, data, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&raw, "parse_ini_file", &_0, 60, data, ZEPHIR_GLOBAL(global_true), &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, this_ptr, "map", NULL, 61, ini, raw);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, ice_config_ini_ce, this_ptr, "__construct", &_2, 26, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * We have to cast values manually because parse_ini_file() has a poor implementation.
 *
 * @param mixed ini The array casted by `parse_ini_file`
 * @param mixed raw The same array but with raw strings
 * @return mixed
 */
PHP_METHOD(Ice_Config_Ini, cast) {

	zend_bool _0, _1, _2, _3, _4, _5, _6;
	zval *ini, *raw, *_7, *_8, _9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ini, &raw);



	if (Z_TYPE_P(ini) == IS_STRING) {
		_0 = ZEPHIR_IS_LONG(ini, 1);
		if (_0) {
			_1 = ZEPHIR_IS_STRING_IDENTICAL(raw, "true");
			if (!(_1)) {
				_1 = ZEPHIR_IS_STRING_IDENTICAL(raw, "yes");
			}
			_2 = _1;
			if (!(_2)) {
				_2 = ZEPHIR_IS_STRING_IDENTICAL(raw, "on");
			}
			_0 = _2;
		}
		if (_0) {
			RETURN_MM_BOOL(1);
		}
		_3 = ZEPHIR_IS_STRING_IDENTICAL(ini, "");
		if (_3) {
			_4 = ZEPHIR_IS_STRING_IDENTICAL(raw, "false");
			if (!(_4)) {
				_4 = ZEPHIR_IS_STRING_IDENTICAL(raw, "no");
			}
			_5 = _4;
			if (!(_5)) {
				_5 = ZEPHIR_IS_STRING_IDENTICAL(raw, "off");
			}
			_3 = _5;
		}
		if (_3) {
			RETURN_MM_BOOL(0);
		}
		_6 = ZEPHIR_IS_STRING_IDENTICAL(ini, "");
		if (_6) {
			_6 = ZEPHIR_IS_STRING_IDENTICAL(raw, "null");
		}
		if (_6) {
			RETURN_MM_NULL();
		}
		if (zephir_is_numeric(ini)) {
			ZEPHIR_INIT_VAR(_7);
			ZEPHIR_INIT_VAR(_8);
			ZEPHIR_SINIT_VAR(_9);
			ZVAL_STRING(&_9, "/[.]+/", 0);
			zephir_preg_match(_8, &_9, ini, _7, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(_8)) {
				RETURN_MM_DOUBLE(zephir_get_doubleval(ini));
			} else {
				RETURN_MM_LONG(zephir_get_intval(ini));
			}
		}
	}
	RETVAL_ZVAL(ini, 1, 0);
	RETURN_MM();

}

/**
 * Map the array recursively.
 *
 * @param array ini
 * @param array raw
 * @return array
 */
PHP_METHOD(Ice_Config_Ini, map) {

	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *ini, *raw, *key = NULL, *value = NULL, *data, **_2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ini, &raw);

	ZEPHIR_INIT_VAR(data);
	array_init(data);


	zephir_is_iterable(ini, &_1, &_0, 0, 0, "ice/config/ini.zep", 94);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(value) == IS_ARRAY) {
			zephir_array_fetch(&_4, raw, key, PH_NOISY | PH_READONLY, "ice/config/ini.zep", 89 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "map", &_5, 61, value, _4);
			zephir_check_call_status();
			zephir_array_update_zval(&data, key, &_3, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_fetch(&_4, raw, key, PH_NOISY | PH_READONLY, "ice/config/ini.zep", 91 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "cast", &_6, 62, value, _4);
			zephir_check_call_status();
			zephir_array_update_zval(&data, key, &_3, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(data);

}

