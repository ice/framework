
extern zend_class_entry *ice_config_ini_ce;

ZEPHIR_INIT_CLASS(Ice_Config_Ini);

PHP_METHOD(Ice_Config_Ini, __construct);
PHP_METHOD(Ice_Config_Ini, cast);
PHP_METHOD(Ice_Config_Ini, arrayMapRecursive);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_ini___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_ini_cast, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_ini_arraymaprecursive, 0, 0, 2)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_config_ini_method_entry) {
	PHP_ME(Ice_Config_Ini, __construct, arginfo_ice_config_ini___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Config_Ini, cast, arginfo_ice_config_ini_cast, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Config_Ini, arrayMapRecursive, arginfo_ice_config_ini_arraymaprecursive, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
