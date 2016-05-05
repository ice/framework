
extern zend_class_entry *ice_filter_ce;

ZEPHIR_INIT_CLASS(Ice_Filter);

PHP_METHOD(Ice_Filter, add);
PHP_METHOD(Ice_Filter, sanitize);
PHP_METHOD(Ice_Filter, doSanitize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_filter_add, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_filter_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_filter_dosanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_filter_method_entry) {
	PHP_ME(Ice_Filter, add, arginfo_ice_filter_add, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Filter, sanitize, arginfo_ice_filter_sanitize, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Filter, doSanitize, arginfo_ice_filter_dosanitize, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
