
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Access class as array and the same time as object.
 *
 * @package     Ice/Arr
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2015 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Arr) {

	ZEPHIR_REGISTER_CLASS(Ice, Arr, ice, arr, ice_arr_method_entry, 0);

	zend_declare_property_null(ice_arr_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_arr_ce->create_object = zephir_init_properties_Ice_Arr;

	zend_class_implements(ice_arr_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(ice_arr_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(ice_arr_ce TSRMLS_CC, 1, zend_ce_aggregate);
	return SUCCESS;

}

PHP_METHOD(Ice_Arr, getData) {

	

	RETURN_MEMBER(this_ptr, "data");

}

/**
 * Arr constructor.
 *
 * @param array data Initial array
 */
PHP_METHOD(Ice_Arr, __construct) {

	zval *data_param = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	zephir_update_property_this(this_ptr, SL("data"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Whether or not an data exists by key.
 *
 * @param string key The data key
 * @return boolean
 */
PHP_METHOD(Ice_Arr, has) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

/**
 * Retrieve a single key from an array.
 * If the key does not exist in the array, the default value will be returned.
 *
 * @param string key The data key
 * @param mixed defaultValue The value to return if data key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Arr, get) {

	zval *key_param = NULL, *defaultValue = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	zephir_get_strval(key, key_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Assigns a value to the specified data.
 *
 * @param string key The data key
 * @param mixed value
 * @return void
 */
PHP_METHOD(Ice_Arr, set) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("data"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add data to set, replaces the existing data.
 *
 * @param array data
 * @return void
 */
PHP_METHOD(Ice_Arr, replace) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *key = NULL, *value = NULL, **_2;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;


	zephir_is_iterable(data, &_1, &_0, 0, 0, "ice/arr.zep", 85);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, key, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Fetch all data.
 *
 * @return array
 */
PHP_METHOD(Ice_Arr, all) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set data, clears and overwrites the current data.
 *
 * @param array data
 * @return void
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
	data = data_param;
	}


	zephir_update_property_this(this_ptr, SL("data"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Fetch set data keys.
 *
 * @return array
 */
PHP_METHOD(Ice_Arr, keys) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	return;

}

/**
 * Remove an data by key.
 *
 * @param string key The data key
 * @return void
 */
PHP_METHOD(Ice_Arr, remove) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Clear all values.
 *
 * @return void
 */
PHP_METHOD(Ice_Arr, clear) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("data"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Count all elements in a data.
 *
 * @return int
 */
PHP_METHOD(Ice_Arr, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Get a data iterator.
 *
 * return ArrayIterator
 */
PHP_METHOD(Ice_Arr, getIterator) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a value from an array using a dot separated path.
 *
 * <pre><code>
 *  // Get the value of $array['foo']['bar']
 *  $value = (new Arr($array))->getPath('foo.bar');
 * </code></pre>
 *
 * <pre><code>
 *  // Get the values of "color" in theme
 *  $colors = (new Arr($array))->getPath('theme.*.color');
 * </code></pre>
 *
 * @param mixed path Key path string (delimiter separated) or array of keys
 * @param mixed defaultValue Default value if the path is not set
 * @param string delimiter Key path delimiter
 * @return mixed
 */
PHP_METHOD(Ice_Arr, getPath) {

	HashTable *_13$$13;
	HashPosition _12$$13;
	int ZEPHIR_LAST_CALL_STATUS, _8$$7;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_16 = NULL, *_17 = NULL;
	zval *delimiter = NULL, *_3$$4, *_4$$4;
	zval *path = NULL, *defaultValue = NULL, *delimiter_param = NULL, *data = NULL, *keys = NULL, *key = NULL, *_0, *_1$$5, *_2$$4 = NULL, *_6$$6 = NULL, *_9$$9 = NULL, *_10$$10, *_11$$12, *values$$13 = NULL, *value$$13 = NULL, *arr$$13 = NULL, **_14$$13, *_15$$15 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path, &defaultValue, &delimiter_param);

	ZEPHIR_SEPARATE_PARAM(path);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(delimiter);
		ZVAL_STRING(delimiter, ".", 1);
	} else {
		zephir_get_strval(delimiter, delimiter_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(data, _0);
	if (Z_TYPE_P(path) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(keys, path);
	} else {
		if (zephir_array_key_exists(data, path TSRMLS_CC)) {
			zephir_array_fetch(&_1$$5, data, path, PH_NOISY | PH_READONLY, "ice/arr.zep", 189 TSRMLS_CC);
			RETURN_CTOR(_1$$5);
		}
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SVS(_3$$4, "{", delimiter, "} ");
		zephir_fast_trim(_2$$4, path, _3$$4, ZEPHIR_TRIM_LEFT TSRMLS_CC);
		ZEPHIR_CPY_WRT(path, _2$$4);
		ZEPHIR_INIT_NVAR(_2$$4);
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_CONCAT_SVS(_4$$4, "{", delimiter, "} *");
		zephir_fast_trim(_2$$4, path, _4$$4, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_CPY_WRT(path, _2$$4);
		ZEPHIR_INIT_NVAR(keys);
		zephir_fast_explode(keys, delimiter, path, LONG_MAX TSRMLS_CC);
	}
	do {
		ZEPHIR_MAKE_REF(keys);
		ZEPHIR_CALL_FUNCTION(&key, "array_shift", &_5, 2, keys);
		ZEPHIR_UNREF(keys);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_6$$6, "ctype_digit", &_7, 3, key);
		zephir_check_call_status();
		if (zephir_is_true(_6$$6)) {
			_8$$7 = zephir_get_intval(key);
			ZEPHIR_INIT_NVAR(key);
			ZVAL_LONG(key, _8$$7);
		}
		if (zephir_array_isset(data, key)) {
			if (zephir_is_true(keys)) {
				ZEPHIR_OBS_NVAR(_9$$9);
				zephir_array_fetch(&_9$$9, data, key, PH_NOISY, "ice/arr.zep", 210 TSRMLS_CC);
				if (Z_TYPE_P(_9$$9) == IS_ARRAY) {
					zephir_array_fetch(&_10$$10, data, key, PH_NOISY | PH_READONLY, "ice/arr.zep", 212 TSRMLS_CC);
					ZEPHIR_CPY_WRT(data, _10$$10);
				} else {
					break;
				}
			} else {
				zephir_array_fetch(&_11$$12, data, key, PH_NOISY | PH_READONLY, "ice/arr.zep", 219 TSRMLS_CC);
				RETURN_CTOR(_11$$12);
			}
		} else if (ZEPHIR_IS_STRING_IDENTICAL(key, "*")) {
			ZEPHIR_INIT_NVAR(values$$13);
			array_init(values$$13);
			zephir_is_iterable(data, &_13$$13, &_12$$13, 0, 0, "ice/arr.zep", 236);
			for (
			  ; zephir_hash_get_current_data_ex(_13$$13, (void**) &_14$$13, &_12$$13) == SUCCESS
			  ; zephir_hash_move_forward_ex(_13$$13, &_12$$13)
			) {
				ZEPHIR_GET_HVALUE(arr$$13, _14$$13);
				if (Z_TYPE_P(arr$$13) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(_15$$15);
					object_init_ex(_15$$15, ice_arr_ce);
					ZEPHIR_CALL_METHOD(NULL, _15$$15, "__construct", &_16, 4, arr$$13);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value$$13, _15$$15, "getpath", &_17, 5, keys);
					zephir_check_call_status();
					if (zephir_is_true(value$$13)) {
						zephir_array_append(&values$$13, value$$13, PH_SEPARATE, "ice/arr.zep", 232);
					}
				}
			}
			if (zephir_is_true(values$$13)) {
				RETURN_CCTOR(values$$13);
			} else {
				break;
			}
		} else {
			break;
		}
	} while (zephir_is_true(keys));
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Converts recursively the object to an array.
 *
 * @return array
 */
PHP_METHOD(Ice_Arr, toArray) {

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *tmp = NULL, *_0, **_3, *_4$$5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(tmp);
	array_init(tmp);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/arr.zep", 274);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(value) == IS_OBJECT) {
			if ((zephir_method_exists_ex(value, SS("toarray") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&_4$$5, value, "toarray", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&tmp, key, &_4$$5, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&tmp, key, &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_zval(&tmp, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(tmp);

}

/**
 * Whether or not an offset exists.
 *
 * @param string An offset to check for
 * @return boolean
 * @abstracting ArrayAccess
 */
PHP_METHOD(Ice_Arr, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(offset, offset_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the value at specified offset.
 *
 * @param string The offset to retrieve
 * @return mixed
 * @abstracting ArrayAccess
 */
PHP_METHOD(Ice_Arr, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(offset, offset_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Assigns a value to the specified offset.
 *
 * @param string The offset to assign the value to
 * @param mixed  The value to set
 * @return void
 * @abstracting ArrayAccess
 */
PHP_METHOD(Ice_Arr, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, *value;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset_param, &value);

	zephir_get_strval(offset, offset_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, offset, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Unsets an offset.
 *
 * @param string The offset to unset
 * @return void
 * @abstracting ArrayAccess
 */
PHP_METHOD(Ice_Arr, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(offset, offset_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, offset);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic isset, whether or not a key exists.
 */
PHP_METHOD(Ice_Arr, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic get, returns the value at specified key.
 * First check if property exist.
 */
PHP_METHOD(Ice_Arr, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	if (zephir_isset_property_zval(this_ptr, key TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_zval(&_0$$3, this_ptr, key, PH_NOISY_CC);
		RETURN_CCTOR(_0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic set, assigns a value to the specified key.
 * First check if property exist.
 */
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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, key, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic unset, unsets a key.
 */
PHP_METHOD(Ice_Arr, __unset) {

	zval *key, *_0;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);

}

zend_object_value zephir_init_properties_Ice_Arr(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("data"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

