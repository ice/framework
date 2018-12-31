
extern zend_class_entry *ice_arr_ce;

ZEPHIR_INIT_CLASS(Ice_Arr);

PHP_METHOD(Ice_Arr, getData);
PHP_METHOD(Ice_Arr, __construct);
PHP_METHOD(Ice_Arr, has);
PHP_METHOD(Ice_Arr, get);
PHP_METHOD(Ice_Arr, set);
PHP_METHOD(Ice_Arr, replace);
PHP_METHOD(Ice_Arr, all);
PHP_METHOD(Ice_Arr, only);
PHP_METHOD(Ice_Arr, getValue);
PHP_METHOD(Ice_Arr, setData);
PHP_METHOD(Ice_Arr, keys);
PHP_METHOD(Ice_Arr, remove);
PHP_METHOD(Ice_Arr, clear);
PHP_METHOD(Ice_Arr, count);
PHP_METHOD(Ice_Arr, getIterator);
PHP_METHOD(Ice_Arr, getPath);
PHP_METHOD(Ice_Arr, toArray);
PHP_METHOD(Ice_Arr, offsetExists);
PHP_METHOD(Ice_Arr, offsetGet);
PHP_METHOD(Ice_Arr, offsetSet);
PHP_METHOD(Ice_Arr, offsetUnset);
PHP_METHOD(Ice_Arr, __isset);
PHP_METHOD(Ice_Arr, __get);
PHP_METHOD(Ice_Arr, __set);
PHP_METHOD(Ice_Arr, __unset);
zend_object_value zephir_init_properties_Ice_Arr(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_only, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
	ZEND_ARG_INFO(0, strict)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, allowEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_setdata, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_getpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_arr___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_arr_method_entry) {
	PHP_ME(Ice_Arr, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, __construct, arginfo_ice_arr___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Arr, has, arginfo_ice_arr_has, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, get, arginfo_ice_arr_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, set, arginfo_ice_arr_set, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, replace, arginfo_ice_arr_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, only, arginfo_ice_arr_only, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, getValue, arginfo_ice_arr_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, setData, arginfo_ice_arr_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, keys, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, remove, arginfo_ice_arr_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, getPath, arginfo_ice_arr_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, offsetExists, arginfo_ice_arr_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, offsetGet, arginfo_ice_arr_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, offsetSet, arginfo_ice_arr_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, offsetUnset, arginfo_ice_arr_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, __isset, arginfo_ice_arr___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, __get, arginfo_ice_arr___get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, __set, arginfo_ice_arr___set, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Arr, __unset, arginfo_ice_arr___unset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
