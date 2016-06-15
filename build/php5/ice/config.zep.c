
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

	HashTable *_1, *_4$$8;
	HashPosition _0, _3$$8;
	zend_bool hasNumericKey = 0;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *key = NULL, *value = NULL, *subkey = NULL, *subvalue = NULL, **_2, **_5$$8, *_6$$12 = NULL;

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
			zephir_is_iterable(value, &_4$$8, &_3$$8, 0, 0, "ice/config.zep", 47);
			for (
			  ; zephir_hash_get_current_data_ex(_4$$8, (void**) &_5$$8, &_3$$8) == SUCCESS
			  ; zephir_hash_move_forward_ex(_4$$8, &_3$$8)
			) {
				ZEPHIR_GET_HMKEY(subkey, _4$$8, _3$$8);
				ZEPHIR_GET_HVALUE(subvalue, _5$$8);
				if (Z_TYPE_P(subkey) == IS_LONG) {
					hasNumericKey = 1;
					break;
				}
			}
			if (hasNumericKey) {
				zephir_update_property_array(this_ptr, SL("data"), key, value TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(_6$$12);
				object_init_ex(_6$$12, ice_config_ce);
				ZEPHIR_CALL_METHOD(NULL, _6$$12, "__construct", &_7, 26, value);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("data"), key, _6$$12 TSRMLS_CC);
			}
		} else {
			zephir_update_property_array(this_ptr, SL("data"), key, value TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

