
extern zend_class_entry *ice_mvc_route_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Route);

PHP_METHOD(Ice_Mvc_Route, getDefaults);
PHP_METHOD(Ice_Mvc_Route, setDefaults);
PHP_METHOD(Ice_Mvc_Route, getMethod);
PHP_METHOD(Ice_Mvc_Route, getError);
PHP_METHOD(Ice_Mvc_Route, __construct);
PHP_METHOD(Ice_Mvc_Route, matches);
PHP_METHOD(Ice_Mvc_Route, checkMethod);
PHP_METHOD(Ice_Mvc_Route, uri);
zend_object *zephir_init_properties_Ice_Mvc_Route(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_setdefaults, 0, 0, 1)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_ARRAY_INFO(0, regexMap, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_matches, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_checkmethod, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_uri, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_route_method_entry) {
	PHP_ME(Ice_Mvc_Route, getDefaults, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route, setDefaults, arginfo_ice_mvc_route_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route, __construct, arginfo_ice_mvc_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Mvc_Route, matches, arginfo_ice_mvc_route_matches, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route, checkMethod, arginfo_ice_mvc_route_checkmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route, uri, arginfo_ice_mvc_route_uri, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
