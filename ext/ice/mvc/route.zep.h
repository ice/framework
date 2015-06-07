
extern zend_class_entry *ice_mvc_route_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Route);

PHP_METHOD(Ice_Mvc_Route, __construct);
PHP_METHOD(Ice_Mvc_Route, matches);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, regex)
	ZEND_ARG_ARRAY_INFO(0, variables, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_matches, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_route_method_entry) {
	PHP_ME(Ice_Mvc_Route, __construct, arginfo_ice_mvc_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Mvc_Route, matches, arginfo_ice_mvc_route_matches, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
