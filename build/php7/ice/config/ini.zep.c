
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
#include "kernel/array.h"


/**
 * Adapter for get config from ini files.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = &data_sub;
		ZEPHIR_CPY_WRT(data, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}


	if (Z_TYPE_P(data) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The file path must be a string", "ice/config/ini.zep", 29);
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
PHP_METHOD(Ice_Config_Ini, cast) {

	zend_bool _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3;
	zval *ini, ini_sub, *raw, raw_sub, _7$$7, _8$$7, _9$$7, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini_sub);
	ZVAL_UNDEF(&raw_sub);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);

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
			zephir_preg_match(&_9$$7, &_10$$7, ini, &_7$$7, 0, 0 , 0  TSRMLS_CC);
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
PHP_METHOD(Ice_Config_Ini, map) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ini, ini_sub, *raw, raw_sub, key, value, data, *_0, _3$$4, _4$$4, _6$$5, _7$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini_sub);
	ZVAL_UNDEF(&raw_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ini, &raw);



	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	zephir_is_iterable(ini, 0, "ice/config/ini.zep", 94);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(ini), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (Z_TYPE_P(&value) == IS_ARRAY) {
			zephir_array_fetch(&_4$$4, raw, &key, PH_NOISY | PH_READONLY, "ice/config/ini.zep", 89 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "map", &_5, 46, &value, &_4$$4);
			zephir_check_call_status();
			zephir_array_update_zval(&data, &key, &_3$$4, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_fetch(&_7$$5, raw, &key, PH_NOISY | PH_READONLY, "ice/config/ini.zep", 91 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "cast", &_8, 0, &value, &_7$$5);
			zephir_check_call_status();
			zephir_array_update_zval(&data, &key, &_6$$5, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&data);

}

