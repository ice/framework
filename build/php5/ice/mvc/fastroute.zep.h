
extern zend_class_entry *ice_mvc_fastroute_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_FastRoute);

PHP_METHOD(Ice_Mvc_FastRoute, __construct);
PHP_METHOD(Ice_Mvc_FastRoute, matches);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastroute___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, regex)
	ZEND_ARG_ARRAY_INFO(0, variables, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastroute_matches, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_fastroute_method_entry) {
	PHP_ME(Ice_Mvc_FastRoute, __construct, arginfo_ice_mvc_fastroute___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Mvc_FastRoute, matches, arginfo_ice_mvc_fastroute_matches, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
