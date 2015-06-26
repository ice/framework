
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
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * Wrapper for configuration arrays.
 *
 * @package     Ice/Config
 * @category    Configuration
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Config) {

	ZEPHIR_REGISTER_CLASS_EX(Ice, Config, ice, config, ice_arr_ce, ice_config_method_entry, 0);

	ice_config_ce->create_object = zephir_init_properties;
	return SUCCESS;

}

/**
 * Config constructor.
 *
 * @param array data Initial config
 */
PHP_METHOD(Ice_Config, __construct) {

	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_4;
	HashPosition _0, _3;
	zend_bool hasNumericKey;
	zval *data = NULL, *key = NULL, *value = NULL, *subkey = NULL, *subvalue = NULL, **_2, **_5, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(data) != IS_ARRAY) {
		if (Z_TYPE_P(data) != IS_NULL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "The configuration must be an Array", "ice/config.zep", 27);
			return;
		} else {
			RETURN_MM_NULL();
		}
	}
	zephir_is_iterable(data, &_1, &_0, 0, 0, "ice/config.zep", 56);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(key) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "Only string keys are allowed", "ice/config.zep", 35);
			return;
		}
		if (Z_TYPE_P(value) == IS_ARRAY) {
			hasNumericKey = 0;
			zephir_is_iterable(value, &_4, &_3, 0, 0, "ice/config.zep", 47);
			for (
			  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
			  ; zephir_hash_move_forward_ex(_4, &_3)
			) {
				ZEPHIR_GET_HMKEY(subkey, _4, _3);
				ZEPHIR_GET_HVALUE(subvalue, _5);
				if (Z_TYPE_P(subkey) == IS_LONG) {
					hasNumericKey = 1;
					break;
				}
			}
			if (hasNumericKey) {
				zephir_update_property_array(this_ptr, SL("_data"), key, value TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(_6);
				object_init_ex(_6, ice_config_ce);
				ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_7, 28, value);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("_data"), key, _6 TSRMLS_CC);
			}
		} else {
			zephir_update_property_array(this_ptr, SL("_data"), key, value TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_data"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

