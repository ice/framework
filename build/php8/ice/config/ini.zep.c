
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * Adapter for get config from ini files.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2023 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Config_Ini)
{
	ZEPHIR_REGISTER_CLASS_EX(Ice\\Config, Ini, ice, config_ini, ice_config_ce, ice_config_ini_method_entry, 0);

	return SUCCESS;
}

/**
 * Config ini constructor.
 *
 * @param string file Path to the ini file
 */
PHP_METHOD(Ice_Config_Ini, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *data = NULL, data_sub, __$true, __$null, ini, raw, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&ini);
	ZVAL_UNDEF(&raw);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);
	if (!data) {
		data = &data_sub;
		ZEPHIR_CPY_WRT(data, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}


	if (Z_TYPE_P(data) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The file path must be a string", "ice/config/ini.zep", 28);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ini, "parse_ini_file", &_0, 45, data, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&raw, "parse_ini_file", &_0, 45, data, &__$true, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(data, this_ptr, "map", NULL, 0, &ini, &raw);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, ice_config_ini_ce, getThis(), "__construct", &_2, 0, data);
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
PHP_METHOD(Ice_Config_Ini, cast)
{
	zend_bool _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *ini, ini_sub, *raw, raw_sub, _7$$7, _8$$7, _9$$7, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini_sub);
	ZVAL_UNDEF(&raw_sub);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(ini)
		Z_PARAM_ZVAL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ini, &raw);


	if (Z_TYPE_P(ini) == IS_STRING) {
		_0$$3 = ZEPHIR_IS_STRING(ini, "1");
		if (_0$$3) {
			_1$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "true");
			if (!(_1$$3)) {
				_1$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "yes");
			}
			_2$$3 = _1$$3;
			if (!(_2$$3)) {
				_2$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "on");
			}
			_0$$3 = _2$$3;
		}
		if (_0$$3) {
			RETURN_MM_BOOL(1);
		}
		_3$$3 = ZEPHIR_IS_STRING_IDENTICAL(ini, "");
		if (_3$$3) {
			_4$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "false");
			if (!(_4$$3)) {
				_4$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "no");
			}
			_5$$3 = _4$$3;
			if (!(_5$$3)) {
				_5$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "off");
			}
			_3$$3 = _5$$3;
		}
		if (_3$$3) {
			RETURN_MM_BOOL(0);
		}
		_6$$3 = ZEPHIR_IS_STRING_IDENTICAL(ini, "");
		if (_6$$3) {
			_6$$3 = ZEPHIR_IS_STRING_IDENTICAL(raw, "null");
		}
		if (_6$$3) {
			RETURN_MM_NULL();
		}
		if (zephir_is_numeric(ini)) {
			ZEPHIR_INIT_VAR(&_7$$7);
			ZEPHIR_INIT_VAR(&_8$$7);
			ZVAL_STRING(&_8$$7, "/[.]+/");
			ZEPHIR_INIT_VAR(&_9$$7);
			ZEPHIR_INIT_VAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "/[.]+/");
			zephir_preg_match(&_9$$7, &_10$$7, ini, &_7$$7, 0, 0 , 0 );
			if (zephir_is_true(&_9$$7)) {
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
PHP_METHOD(Ice_Config_Ini, map)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ini, ini_sub, *raw, raw_sub, key, value, data, *_0, _1, _4$$4, _5$$4, _7$$5, _8$$5, _10$$7, _11$$7, _12$$8, _13$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini_sub);
	ZVAL_UNDEF(&raw_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(ini)
		Z_PARAM_ZVAL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ini, &raw);


	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	zephir_is_iterable(ini, 0, "ice/config/ini.zep", 93);
	if (Z_TYPE_P(ini) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(ini), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				zephir_array_fetch(&_5$$4, raw, &key, PH_NOISY | PH_READONLY, "ice/config/ini.zep", 88);
				ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "map", &_6, 46, &value, &_5$$4);
				zephir_check_call_status();
				zephir_array_update_zval(&data, &key, &_4$$4, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_fetch(&_8$$5, raw, &key, PH_NOISY | PH_READONLY, "ice/config/ini.zep", 90);
				ZEPHIR_CALL_METHOD(&_7$$5, this_ptr, "cast", &_9, 0, &value, &_8$$5);
				zephir_check_call_status();
				zephir_array_update_zval(&data, &key, &_7$$5, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, ini, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, ini, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, ini, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, ini, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					zephir_array_fetch(&_11$$7, raw, &key, PH_NOISY | PH_READONLY, "ice/config/ini.zep", 88);
					ZEPHIR_CALL_METHOD(&_10$$7, this_ptr, "map", &_6, 46, &value, &_11$$7);
					zephir_check_call_status();
					zephir_array_update_zval(&data, &key, &_10$$7, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch(&_13$$8, raw, &key, PH_NOISY | PH_READONLY, "ice/config/ini.zep", 90);
					ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "cast", &_9, 0, &value, &_13$$8);
					zephir_check_call_status();
					zephir_array_update_zval(&data, &key, &_12$$8, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, ini, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&data);
}

