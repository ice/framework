
extern zend_class_entry *ice_config_ce;

ZEPHIR_INIT_CLASS(Ice_Config);

PHP_METHOD(Ice_Config, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_config_method_entry) {
	PHP_ME(Ice_Config, __construct, arginfo_ice_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
