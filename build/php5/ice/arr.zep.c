
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
 * @copyright   (c) 2014-2018 Ice Team
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

	

	RETURN_MEMBER(getThis(), "data");

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


	zephir_update_property_this(getThis(), SL("data"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Whether or not a data exists by key.
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
 * @return object Arr
 */
PHP_METHOD(Ice_Arr, set) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("data"), key, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Add data to set, replaces the existing data.
 *
 * @param array data
 * @return Arr
 */
PHP_METHOD(Ice_Arr, replace) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *key = NULL, *value = NULL, **_2;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;


	zephir_is_iterable(data, &_1, &_0, 0, 0, "ice/arr.zep", 88);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, key, value);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Fetch all data.
 *
 * @return array
 */
PHP_METHOD(Ice_Arr, all) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fetch some data.
 *
 * @param array keys Keys to fetch
 * @param boolean strict Fetch key only if exist
 * @return array
 */
PHP_METHOD(Ice_Arr, only) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict, _3$$3, _4$$3;
	zval *keys_param = NULL, *strict_param = NULL, *key = NULL, *only = NULL, **_2, *_5$$3 = NULL, *_7$$4 = NULL;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keys_param, &strict_param);

	keys = keys_param;
	if (!strict_param) {
		strict = 1;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	ZEPHIR_INIT_VAR(only);
	array_init(only);
	zephir_is_iterable(keys, &_1, &_0, 0, 0, "ice/arr.zep", 117);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(key, _2);
		_3$$3 = !strict;
		if (!(_3$$3)) {
			_4$$3 = strict;
			if (_4$$3) {
				ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "has", &_6, 0, key);
				zephir_check_call_status();
				_4$$3 = zephir_is_true(_5$$3);
			}
			_3$$3 = _4$$3;
		}
		if (_3$$3) {
			ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "get", &_8, 0, key);
			zephir_check_call_status();
			zephir_array_update_zval(&only, key, &_7$$4, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(only);

}

/**
 * Gets value from data applying filters if needed.
 *
 * <pre><code>
 *  //Returns value from $arr["id"] without sanitizing
 *  $id = $arr->getValue("id");
 *
 *  //Returns value from $arr["title"] with sanitizing
 *  $title = $arr->getValue("title", "escape|repeats");
 *
 *  //Returns value from $arr["id"] with a default value
 *  $id = $arr->getValue("id", null, 150);
 * </code></pre>
 *
 * @param string key Index to get
 * @param string|array filters Filters to apply
 * @param mixed defaultValue Default value if key not exist or value is empty and allowEmpty is false
 * @param boolean allowEmpty
 * @return mixed
 */
PHP_METHOD(Ice_Arr, getValue) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowEmpty, _4, _5;
	zval *key_param = NULL, *filters = NULL, *defaultValue = NULL, *allowEmpty_param = NULL, *value = NULL, *filter = NULL, *_0$$3 = NULL, *_2$$3, *_3$$3 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &key_param, &filters, &defaultValue, &allowEmpty_param);

	zephir_get_strval(key, key_param);
	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!allowEmpty_param) {
		allowEmpty = 0;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	ZEPHIR_CALL_METHOD(&value, this_ptr, "get", NULL, 0, key, defaultValue);
	zephir_check_call_status();
	if (zephir_is_true(filters)) {
		ZEPHIR_CALL_CE_STATIC(&_0$$3, ice_di_ce, "fetch", &_1, 1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "filter", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&filter, _0$$3, "get", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, filter, "sanitize", NULL, 0, value, filters);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _3$$3);
	}
	_4 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
	if (!(_4)) {
		_4 = Z_TYPE_P(value) == IS_NULL;
	}
	_5 = _4;
	if (_5) {
		_5 = allowEmpty == 0;
	}
	if (_5) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CCTOR(value);

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


	zephir_update_property_this(getThis(), SL("data"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Fetch set data keys.
 *
 * @return array
 */
PHP_METHOD(Ice_Arr, keys) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	RETURN_MM();

}

/**
 * Remove a data by key.
 *
 * @param string key The data key
 * @return object Arr
 */
PHP_METHOD(Ice_Arr, remove) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	RETURN_THIS();

}

/**
 * Clear all values.
 *
 * @return object Arr
 */
PHP_METHOD(Ice_Arr, clear) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("data"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Count all elements in a data.
 *
 * @return int
 */
PHP_METHOD(Ice_Arr, count) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Get a data iterator.
 *
 * return ArrayIterator
 */
PHP_METHOD(Ice_Arr, getIterator) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 2, _0);
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

	HashTable *_12$$13;
	HashPosition _11$$13;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_15 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _7$$7;
	zval *delimiter = NULL, *_2$$4, *_3$$4;
	zval *path = NULL, *defaultValue = NULL, *delimiter_param = NULL, *data = NULL, *keys = NULL, *key = NULL, *_0$$5, *_1$$4 = NULL, *_5$$6 = NULL, *_8$$9 = NULL, *_9$$10, *_10$$12, *values$$13 = NULL, *value$$13 = NULL, *arr$$13 = NULL, **_13$$13, *_14$$15 = NULL;

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


	ZEPHIR_CALL_METHOD(&data, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(path) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(keys, path);
	} else {
		if (zephir_array_key_exists(data, path TSRMLS_CC)) {
			zephir_array_fetch(&_0$$5, data, path, PH_NOISY | PH_READONLY, "ice/arr.zep", 254 TSRMLS_CC);
			RETURN_CTOR(_0$$5);
		}
		ZEPHIR_INIT_VAR(_1$$4);
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SVS(_2$$4, "{", delimiter, "} ");
		zephir_fast_trim(_1$$4, path, _2$$4, ZEPHIR_TRIM_LEFT TSRMLS_CC);
		ZEPHIR_CPY_WRT(path, _1$$4);
		ZEPHIR_INIT_NVAR(_1$$4);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SVS(_3$$4, "{", delimiter, "} *");
		zephir_fast_trim(_1$$4, path, _3$$4, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_CPY_WRT(path, _1$$4);
		ZEPHIR_INIT_NVAR(keys);
		zephir_fast_explode(keys, delimiter, path, LONG_MAX TSRMLS_CC);
	}
	do {
		ZEPHIR_MAKE_REF(keys);
		ZEPHIR_CALL_FUNCTION(&key, "array_shift", &_4, 3, keys);
		ZEPHIR_UNREF(keys);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_5$$6, "ctype_digit", &_6, 4, key);
		zephir_check_call_status();
		if (zephir_is_true(_5$$6)) {
			_7$$7 = zephir_get_intval(key);
			ZEPHIR_INIT_NVAR(key);
			ZVAL_LONG(key, _7$$7);
		}
		if (zephir_array_isset(data, key)) {
			if (zephir_is_true(keys)) {
				ZEPHIR_OBS_NVAR(_8$$9);
				zephir_array_fetch(&_8$$9, data, key, PH_NOISY, "ice/arr.zep", 275 TSRMLS_CC);
				if (Z_TYPE_P(_8$$9) == IS_ARRAY) {
					zephir_array_fetch(&_9$$10, data, key, PH_NOISY | PH_READONLY, "ice/arr.zep", 277 TSRMLS_CC);
					ZEPHIR_CPY_WRT(data, _9$$10);
				} else {
					break;
				}
			} else {
				zephir_array_fetch(&_10$$12, data, key, PH_NOISY | PH_READONLY, "ice/arr.zep", 284 TSRMLS_CC);
				RETURN_CTOR(_10$$12);
			}
		} else if (ZEPHIR_IS_STRING_IDENTICAL(key, "*")) {
			ZEPHIR_INIT_NVAR(values$$13);
			array_init(values$$13);
			zephir_is_iterable(data, &_12$$13, &_11$$13, 0, 0, "ice/arr.zep", 301);
			for (
			  ; zend_hash_get_current_data_ex(_12$$13, (void**) &_13$$13, &_11$$13) == SUCCESS
			  ; zend_hash_move_forward_ex(_12$$13, &_11$$13)
			) {
				ZEPHIR_GET_HVALUE(arr$$13, _13$$13);
				if (Z_TYPE_P(arr$$13) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(_14$$15);
					object_init_ex(_14$$15, ice_arr_ce);
					ZEPHIR_CALL_METHOD(NULL, _14$$15, "__construct", &_15, 5, arr$$13);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value$$13, _14$$15, "getpath", &_16, 6, keys);
					zephir_check_call_status();
					if (zephir_is_true(value$$13)) {
						zephir_array_append(&values$$13, value$$13, PH_SEPARATE, "ice/arr.zep", 297);
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
	zval *key = NULL, *value = NULL, *tmp = NULL, *_0 = NULL, **_3, *_4$$5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(tmp);
	array_init(tmp);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "ice/arr.zep", 339);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset, &value);



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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, offset);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic isset, whether or not a key exists.
 */
PHP_METHOD(Ice_Arr, __isset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	if (zephir_isset_property_zval(this_ptr, key TSRMLS_CC)) {
		zephir_update_property_zval_zval(getThis(), key, value TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Ice_Arr(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("data"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

