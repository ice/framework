
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/memory.h"
#include "kernel/require.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Wrapper for configuration arrays.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Config) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Config, ice, config, ice_arr_ce, ice_config_method_entry, 0);

	return SUCCESS;

}

/**
 * Config constructor.
 *
 * @param array data Initial config
 */
PHP_METHOD(Ice_Config, __construct) {

	zval _3$$5;
	zend_string *_8, *_11$$11;
	zend_ulong _7, _10$$11;
	zend_bool hasNumericKey = 0, _0;
	zephir_fcall_cache_entry *_5 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, __$null, key, value, subkey, subvalue, *_6, _1$$4, _2$$5, _4$$5, *_9$$11, _12$$15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&subkey);
	ZVAL_UNDEF(&subvalue);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = &data_sub;
		ZEPHIR_CPY_WRT(data, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}


	_0 = Z_TYPE_P(data) == IS_STRING;
	if (_0) {
		_0 = !ZEPHIR_IS_STRING(data, "");
	}
	if (_0) {
		if ((zephir_file_exists(data TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_1$$4);
			if (zephir_require_zval_ret(&_1$$4, data TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(data, &_1$$4);
		} else {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, ice_exception_ce);
			ZEPHIR_INIT_VAR(&_3$$5);
			zephir_create_array(&_3$$5, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "Config file '%s' doesn't exist");
			zephir_array_fast_append(&_3$$5, &_4$$5);
			zephir_array_fast_append(&_3$$5, data);
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", &_5, 12, &_3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "ice/config.zep", 29 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		if (Z_TYPE_P(data) != IS_NULL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The configuration must be an Array", "ice/config.zep", 35);
			return;
		} else {
			RETURN_MM_NULL();
		}
	}
	zephir_is_iterable(data, 0, "ice/config.zep", 64);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _7, _8, _6)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_8 != NULL) { 
			ZVAL_STR_COPY(&key, _8);
		} else {
			ZVAL_LONG(&key, _7);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _6);
		if (Z_TYPE_P(&key) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Only string keys are allowed", "ice/config.zep", 43);
			return;
		}
		if (Z_TYPE_P(&value) == IS_ARRAY) {
			hasNumericKey = 0;
			zephir_is_iterable(&value, 0, "ice/config.zep", 55);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _10$$11, _11$$11, _9$$11)
			{
				ZEPHIR_INIT_NVAR(&subkey);
				if (_11$$11 != NULL) { 
					ZVAL_STR_COPY(&subkey, _11$$11);
				} else {
					ZVAL_LONG(&subkey, _10$$11);
				}
				ZEPHIR_INIT_NVAR(&subvalue);
				ZVAL_COPY(&subvalue, _9$$11);
				if (Z_TYPE_P(&subkey) == IS_LONG) {
					hasNumericKey = 1;
					break;
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&subvalue);
			ZEPHIR_INIT_NVAR(&subkey);
			if (hasNumericKey) {
				zephir_update_property_array(this_ptr, SL("data"), &key, &value TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(&_12$$15);
				object_init_ex(&_12$$15, ice_config_ce);
				ZEPHIR_CALL_METHOD(NULL, &_12$$15, "__construct", &_13, 24, &value);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("data"), &key, &_12$$15 TSRMLS_CC);
			}
		} else {
			zephir_update_property_array(this_ptr, SL("data"), &key, &value TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

