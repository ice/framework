
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(Ice_Arr) {

	ZEPHIR_REGISTER_CLASS(Ice, Arr, ice, arr, ice_arr_method_entry, 0);

	zend_declare_property_null(ice_arr_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_arr_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(ice_arr_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(ice_arr_ce TSRMLS_CC, 1, zend_ce_aggregate);
	return SUCCESS;

}

PHP_METHOD(Ice_Arr, getData) {


	RETURN_MEMBER(this_ptr, "_data");

}

PHP_METHOD(Ice_Arr, __construct) {

	zval *data_param = NULL, *_0;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_data"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Does this set contain a key?
 * @param  string  $key The data key
 * @return boolean
 */
PHP_METHOD(Ice_Arr, has) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

/**
 * Get data value with key
 * @param string $key The data key
 * @param mixed $defaultValue The value to return if data key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Arr, get) {

	zval *key_param = NULL, *defaultValue = NULL, *value, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	zephir_get_strval(key, key_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Set data key to value
 * @param string $key The data key
 * @param mixed
 */
PHP_METHOD(Ice_Arr, set) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("_data"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add data to set, replaces the existing data
 * @param array
 */
PHP_METHOD(Ice_Arr, replace) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *data_param = NULL, *key = NULL, *value = NULL, **_2;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	if (unlikely(Z_TYPE_P(data_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		data = data_param;



	zephir_is_iterable(data, &_1, &_0, 0, 0, "ice/arr.zep", 62);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, key, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Fetch all data
 * @return array
 */
PHP_METHOD(Ice_Arr, all) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdata", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set data, clears and overwrites the current data
 * @param array
 */
PHP_METHOD(Ice_Arr, setData) {

	zval *data_param = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
	if (unlikely(Z_TYPE_P(data_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		data = data_param;

	}


	zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Fetch set data keys
 * @return array
 */
PHP_METHOD(Ice_Arr, keys) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	return;

}

/**
 * Remove value with key from this set
 * @param  string $key The data key
 */
PHP_METHOD(Ice_Arr, remove) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Clear all values
 */
PHP_METHOD(Ice_Arr, clear) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_data"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Arr, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

PHP_METHOD(Ice_Arr, getIterator) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Arr, getPath) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *delimiter = NULL;
	zval *path, *defaultValue = NULL, *delimiter_param = NULL, *parts = NULL, *value = NULL, *part = NULL, **_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path, &defaultValue, &delimiter_param);

	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(delimiter);
		ZVAL_STRING(delimiter, ".", 1);
	} else {
		zephir_get_strval(delimiter, delimiter_param);
	}


	if (Z_TYPE_P(path) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(parts, path);
	} else {
		ZEPHIR_INIT_NVAR(parts);
		zephir_fast_explode(parts, delimiter, path, LONG_MAX TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "toarray",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(parts, &_1, &_0, 0, 0, "ice/arr.zep", 142);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(part, _2);
		if (zephir_array_isset(value, part)) {
			zephir_array_fetch(&_3, value, part, PH_NOISY | PH_READONLY, "ice/arr.zep", 135 TSRMLS_CC);
			ZEPHIR_CPY_WRT(value, _3);
		} else {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
	}
	RETURN_CCTOR(value);

}

/**
 * Converts recursively the object to an array
 *
 * @return array
 */
PHP_METHOD(Ice_Arr, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *tmp, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(tmp);
	array_init(tmp);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/arr.zep", 166);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(value) == IS_OBJECT) {
			if ((zephir_method_exists_ex(value, SS("toarray") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&_4, value, "toarray",  NULL);
				zephir_check_call_status();
				zephir_array_update_zval(&tmp, key, &_4, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&tmp, key, &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_zval(&tmp, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(tmp);

}

PHP_METHOD(Ice_Arr, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Arr, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	if (zephir_isset_property_zval(this_ptr, key TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_zval(&_0, this_ptr, key, PH_NOISY_CC);
		RETURN_CCTOR(_0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Arr, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	if (zephir_isset_property_zval(this_ptr, key TSRMLS_CC)) {
		zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, key, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Arr, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "remove", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Arr, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(offset, offset_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, offset);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Arr, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(offset, offset_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, offset);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Ice_Arr, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, *value;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset_param, &value);

	zephir_get_strval(offset, offset_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, offset, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_Arr, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(offset, offset_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, offset);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

