
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "ext/spl/spl_array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Access class as array and the same time as object.
 *
 * @package     Ice/Arr
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2023 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Arr)
{
	ZEPHIR_REGISTER_CLASS(Ice, Arr, ice, arr, ice_arr_method_entry, 0);

	zend_declare_property_null(ice_arr_ce, SL("data"), ZEND_ACC_PROTECTED);
	ice_arr_ce->create_object = zephir_init_properties_Ice_Arr;

	zend_class_implements(ice_arr_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(ice_arr_ce, 1, zend_ce_countable);
	zend_class_implements(ice_arr_ce, 1, zend_ce_aggregate);
	return SUCCESS;
}

PHP_METHOD(Ice_Arr, getData)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "data");
}

/**
 * Arr constructor.
 *
 * @param array data Initial array
 */
PHP_METHOD(Ice_Arr, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	ZEPHIR_MM_RESTORE();
}

/**
 * Whether or not a data exists by key.
 *
 * @param string key The data key
 * @return boolean
 */
PHP_METHOD(Ice_Arr, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &key));
}

/**
 * Retrieve a single key from an array.
 * If the key does not exist in the array, the default value will be returned.
 *
 * @param string key The data key
 * @param mixed defaultValue The value to return if data key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Arr, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);
	zephir_get_strval(&key, key_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &key, 1)) {
		RETURN_CTOR(&value);
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
PHP_METHOD(Ice_Arr, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);
	zephir_get_strval(&key, key_param);


	zephir_update_property_array(this_ptr, SL("data"), &key, value);
	RETURN_THIS();
}

/**
 * Add data to set, replaces the existing data.
 *
 * @param array data
 * @return Arr
 */
PHP_METHOD(Ice_Arr, merge)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, key, value, *_0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);


	zephir_is_iterable(&data, 0, "ice/arr.zep", 87);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &key, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &key, &value);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();
}

/**
 * Alias of the `merge` method.
 *
 * @deprecated
 * @see self::merge()
 */
PHP_METHOD(Ice_Arr, replace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "merge", NULL, 0, &data);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Fetch all data.
 *
 * @return array
 */
PHP_METHOD(Ice_Arr, all)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



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
PHP_METHOD(Ice_Arr, only)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict, _2$$3, _3$$3, _8$$5, _9$$5;
	zval *keys_param = NULL, *strict_param = NULL, key, only, *_0, _1, _4$$3, _6$$4, _10$$5, _11$$6;
	zval keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&only);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(keys)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(strict)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keys_param, &strict_param);
	ZEPHIR_OBS_COPY_OR_DUP(&keys, keys_param);
	if (!strict_param) {
		strict = 1;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	ZEPHIR_INIT_VAR(&only);
	array_init(&only);
	zephir_is_iterable(&keys, 0, "ice/arr.zep", 127);
	if (Z_TYPE_P(&keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _0);
			_2$$3 = !strict;
			if (!(_2$$3)) {
				_3$$3 = strict;
				if (_3$$3) {
					ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "has", &_5, 0, &key);
					zephir_check_call_status();
					_3$$3 = zephir_is_true(&_4$$3);
				}
				_2$$3 = _3$$3;
			}
			if (_2$$3) {
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "get", &_7, 0, &key);
				zephir_check_call_status();
				zephir_array_update_zval(&only, &key, &_6$$4, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &keys, "current", NULL, 0);
			zephir_check_call_status();
				_8$$5 = !strict;
				if (!(_8$$5)) {
					_9$$5 = strict;
					if (_9$$5) {
						ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "has", &_5, 0, &key);
						zephir_check_call_status();
						_9$$5 = zephir_is_true(&_10$$5);
					}
					_8$$5 = _9$$5;
				}
				if (_8$$5) {
					ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "get", &_7, 0, &key);
					zephir_check_call_status();
					zephir_array_update_zval(&only, &key, &_11$$6, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&only);
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
PHP_METHOD(Ice_Arr, getValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowEmpty, _4, _5;
	zval *key_param = NULL, *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, *allowEmpty_param = NULL, __$null, value, filter, _0$$3, _2$$3, _3$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(allowEmpty)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &key_param, &filters, &defaultValue, &allowEmpty_param);
	zephir_get_strval(&key, key_param);
	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!allowEmpty_param) {
		allowEmpty = 0;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	ZEPHIR_CALL_METHOD(&value, this_ptr, "get", NULL, 0, &key, defaultValue);
	zephir_check_call_status();
	if (zephir_is_true(filters)) {
		ZEPHIR_CALL_CE_STATIC(&_0$$3, ice_di_ce, "fetch", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "filter");
		ZEPHIR_CALL_METHOD(&filter, &_0$$3, "get", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, &filter, "sanitize", NULL, 0, &value, filters);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&value, &_3$$3);
	}
	_4 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
	if (!(_4)) {
		_4 = Z_TYPE_P(&value) == IS_NULL;
	}
	_5 = _4;
	if (_5) {
		_5 = allowEmpty == 0;
	}
	if (_5) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CCTOR(&value);
}

/**
 * Set data, clears and overwrites the current data.
 *
 * @param array data
 * @return void
 */
PHP_METHOD(Ice_Arr, setData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	ZEPHIR_MM_RESTORE();
}

/**
 * Fetch set data keys.
 *
 * @return array
 */
PHP_METHOD(Ice_Arr, keys)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	zephir_array_keys(return_value, &_0);
	RETURN_MM();
}

/**
 * Remove a data by key.
 *
 * @param string key The data key
 * @return object Arr
 */
PHP_METHOD(Ice_Arr, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	zephir_unset_property_array(this_ptr, ZEND_STRL("data"), &key);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &key, PH_SEPARATE);
	RETURN_THIS();
}

/**
 * Clear all values.
 *
 * @return object Arr
 */
PHP_METHOD(Ice_Arr, clear)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_0);
	RETURN_THIS();
}

/**
 * Count all elements in a data.
 *
 * @return int
 */
PHP_METHOD(Ice_Arr, count)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(&_0));
}

/**
 * Get a data iterator.
 *
 * return ArrayIterator
 */
PHP_METHOD(Ice_Arr, getIterator)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, spl_ce_ArrayIterator);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, &_0);
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
PHP_METHOD(Ice_Arr, getPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_14 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _7$$7;
	zval delimiter, _2$$4, _3$$4;
	zval *path = NULL, path_sub, *defaultValue = NULL, defaultValue_sub, *delimiter_param = NULL, __$null, data, keys, key, _0$$5, _1$$4, _5$$6, _8$$9, _9$$10, _10$$12, values$$13, value$$13, arr$$13, *_11$$13, _12$$13, _13$$15, _16$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&values$$13);
	ZVAL_UNDEF(&value$$13);
	ZVAL_UNDEF(&arr$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_16$$18);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR(delimiter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path, &defaultValue, &delimiter_param);
	ZEPHIR_SEPARATE_PARAM(path);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
		ZVAL_STRING(&delimiter, ".");
	} else {
		zephir_get_strval(&delimiter, delimiter_param);
	}


	ZEPHIR_CALL_METHOD(&data, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(path) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&keys, path);
	} else {
		if (zephir_array_key_exists(&data, path)) {
			zephir_array_fetch(&_0$$5, &data, path, PH_NOISY | PH_READONLY, "ice/arr.zep", 264);
			RETURN_CTOR(&_0$$5);
		}
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SVS(&_2$$4, "{", &delimiter, "} ");
		zephir_fast_trim(&_1$$4, path, &_2$$4, ZEPHIR_TRIM_LEFT);
		ZEPHIR_CPY_WRT(path, &_1$$4);
		ZEPHIR_INIT_NVAR(&_1$$4);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_SVS(&_3$$4, "{", &delimiter, "} *");
		zephir_fast_trim(&_1$$4, path, &_3$$4, ZEPHIR_TRIM_RIGHT);
		ZEPHIR_CPY_WRT(path, &_1$$4);
		ZEPHIR_INIT_NVAR(&keys);
		zephir_fast_explode(&keys, &delimiter, path, LONG_MAX);
	}
	do {
		ZEPHIR_MAKE_REF(&keys);
		ZEPHIR_CALL_FUNCTION(&key, "array_shift", &_4, 2, &keys);
		ZEPHIR_UNREF(&keys);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_5$$6, "ctype_digit", &_6, 3, &key);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$6)) {
			_7$$7 = zephir_get_intval(&key);
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_LONG(&key, _7$$7);
		}
		if (zephir_array_isset(&data, &key)) {
			if (zephir_is_true(&keys)) {
				ZEPHIR_OBS_NVAR(&_8$$9);
				zephir_array_fetch(&_8$$9, &data, &key, PH_NOISY, "ice/arr.zep", 285);
				if (Z_TYPE_P(&_8$$9) == IS_ARRAY) {
					zephir_array_fetch(&_9$$10, &data, &key, PH_NOISY | PH_READONLY, "ice/arr.zep", 287);
					ZEPHIR_CPY_WRT(&data, &_9$$10);
				} else {
					break;
				}
			} else {
				zephir_array_fetch(&_10$$12, &data, &key, PH_NOISY | PH_READONLY, "ice/arr.zep", 294);
				RETURN_CTOR(&_10$$12);
			}
		} else if (ZEPHIR_IS_STRING_IDENTICAL(&key, "*")) {
			ZEPHIR_INIT_NVAR(&values$$13);
			array_init(&values$$13);
			zephir_is_iterable(&data, 0, "ice/arr.zep", 311);
			if (Z_TYPE_P(&data) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _11$$13)
				{
					ZEPHIR_INIT_NVAR(&arr$$13);
					ZVAL_COPY(&arr$$13, _11$$13);
					if (Z_TYPE_P(&arr$$13) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_13$$15);
						object_init_ex(&_13$$15, ice_arr_ce);
						ZEPHIR_CALL_METHOD(NULL, &_13$$15, "__construct", &_14, 4, &arr$$13);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value$$13, &_13$$15, "getpath", &_15, 5, &keys);
						zephir_check_call_status();
						if (zephir_is_true(&value$$13)) {
							zephir_array_append(&values$$13, &value$$13, PH_SEPARATE, "ice/arr.zep", 307);
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_12$$13, &data, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_12$$13)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&arr$$13, &data, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&arr$$13) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_16$$18);
							object_init_ex(&_16$$18, ice_arr_ce);
							ZEPHIR_CALL_METHOD(NULL, &_16$$18, "__construct", &_14, 4, &arr$$13);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&value$$13, &_16$$18, "getpath", &_15, 5, &keys);
							zephir_check_call_status();
							if (zephir_is_true(&value$$13)) {
								zephir_array_append(&values$$13, &value$$13, PH_SEPARATE, "ice/arr.zep", 307);
							}
						}
					ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&arr$$13);
			if (zephir_is_true(&values$$13)) {
				RETURN_CCTOR(&values$$13);
			} else {
				break;
			}
		} else {
			break;
		}
	} while (zephir_is_true(&keys));
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();
}

/**
 * Converts recursively the object to an array.
 *
 * @return array
 */
PHP_METHOD(Ice_Arr, toArray)
{
	zend_string *_4;
	zend_ulong _3;
	zval key, value, tmp, _0, *_1, _2, _5$$5, _6$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$10);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tmp);
	array_init(&tmp);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "ice/arr.zep", 349);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (Z_TYPE_P(&value) == IS_OBJECT) {
				if ((zephir_method_exists_ex(&value, ZEND_STRL("toarray")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&_5$$5, &value, "toarray", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&tmp, &key, &_5$$5, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&tmp, &key, &value, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_array_update_zval(&tmp, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) == IS_OBJECT) {
					if ((zephir_method_exists_ex(&value, ZEND_STRL("toarray")) == SUCCESS)) {
						ZEPHIR_CALL_METHOD(&_6$$10, &value, "toarray", NULL, 0);
						zephir_check_call_status();
						zephir_array_update_zval(&tmp, &key, &_6$$10, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&tmp, &key, &value, PH_COPY | PH_SEPARATE);
					}
				} else {
					zephir_array_update_zval(&tmp, &key, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&tmp);
}

/**
 * Whether or not an offset exists.
 *
 * @param string An offset to check for
 * @return boolean
 * @abstracting ArrayAccess
 */
PHP_METHOD(Ice_Arr, offsetExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Ice_Arr, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Ice_Arr, offsetSet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Ice_Arr, offsetUnset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, offset);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic isset, whether or not a key exists.
 */
PHP_METHOD(Ice_Arr, __isset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Magic get, returns the value at specified key.
 * First check if property exist.
 */
PHP_METHOD(Ice_Arr, __get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);


	if (zephir_isset_property_zval(this_ptr, key)) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property_zval(&_0$$3, this_ptr, key, PH_NOISY_CC);
		RETURN_CCTOR(&_0$$3);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Magic set, assigns a value to the specified key.
 * First check if property exist.
 */
PHP_METHOD(Ice_Arr, __set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);
	zephir_get_strval(&key, key_param);


	if (zephir_isset_property_zval(this_ptr, &key)) {
		zephir_update_property_zval_zval(this_ptr, &key, value);
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic unset, unsets a key.
 */
PHP_METHOD(Ice_Arr, __unset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Ice_Arr(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("data"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

