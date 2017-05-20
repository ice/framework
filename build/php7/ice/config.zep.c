
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"


/**
 * Wrapper for configuration arrays.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
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

	zend_string *_2, *_5$$8;
	zend_ulong _1, _4$$8;
	zend_bool hasNumericKey = 0;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, __$null, key, value, subkey, subvalue, *_0, *_3$$8, _6$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&subkey);
	ZVAL_UNDEF(&subvalue);
	ZVAL_UNDEF(&_6$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	if (Z_TYPE_P(data) != IS_ARRAY) {
		if (Z_TYPE_P(data) != IS_NULL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The configuration must be an Array", "ice/config.zep", 27);
			return;
		} else {
			RETURN_MM_NULL();
		}
	}
	zephir_is_iterable(data, 0, "ice/config.zep", 56);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (Z_TYPE_P(&key) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Only string keys are allowed", "ice/config.zep", 35);
			return;
		}
		if (Z_TYPE_P(&value) == IS_ARRAY) {
			hasNumericKey = 0;
			zephir_is_iterable(&value, 0, "ice/config.zep", 47);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _4$$8, _5$$8, _3$$8)
			{
				ZEPHIR_INIT_NVAR(&subkey);
				if (_5$$8 != NULL) { 
					ZVAL_STR_COPY(&subkey, _5$$8);
				} else {
					ZVAL_LONG(&subkey, _4$$8);
				}
				ZEPHIR_INIT_NVAR(&subvalue);
				ZVAL_COPY(&subvalue, _3$$8);
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
				ZEPHIR_INIT_NVAR(&_6$$12);
				object_init_ex(&_6$$12, ice_config_ce);
				ZEPHIR_CALL_METHOD(NULL, &_6$$12, "__construct", &_7, 25, &value);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("data"), &key, &_6$$12 TSRMLS_CC);
			}
		} else {
			zephir_update_property_array(this_ptr, SL("data"), &key, &value TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

