
extern zend_class_entry *ice_pagination_ce;

ZEPHIR_INIT_CLASS(Ice_Pagination);

PHP_METHOD(Ice_Pagination, getDi);
PHP_METHOD(Ice_Pagination, getTag);
PHP_METHOD(Ice_Pagination, __construct);
PHP_METHOD(Ice_Pagination, calculate);
PHP_METHOD(Ice_Pagination, prepareButton);
PHP_METHOD(Ice_Pagination, minimal);
PHP_METHOD(Ice_Pagination, basic);
PHP_METHOD(Ice_Pagination, floating);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_pagination___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_pagination_preparebutton, 0, 0, 1)
	ZEND_ARG_INFO(0, page)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, active)
	ZEND_ARG_INFO(0, symbol)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_pagination_minimal, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_pagination_basic, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_pagination_floating, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
	ZEND_ARG_INFO(0, countOut)
	ZEND_ARG_INFO(0, countIn)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_pagination_method_entry) {
	PHP_ME(Ice_Pagination, getDi, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Pagination, getTag, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Pagination, __construct, arginfo_ice_pagination___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Pagination, calculate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Pagination, prepareButton, arginfo_ice_pagination_preparebutton, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Pagination, minimal, arginfo_ice_pagination_minimal, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Pagination, basic, arginfo_ice_pagination_basic, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Pagination, floating, arginfo_ice_pagination_floating, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
