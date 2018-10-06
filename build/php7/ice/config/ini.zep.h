
extern zend_class_entry *ice_config_ini_ce;

ZEPHIR_INIT_CLASS(Ice_Config_Ini);

PHP_METHOD(Ice_Config_Ini, __construct);
PHP_METHOD(Ice_Config_Ini, cast);
PHP_METHOD(Ice_Config_Ini, map);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_ini___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_ini_cast, 0, 0, 2)
	ZEND_ARG_INFO(0, ini)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_ini_map, 0, 0, 2)
	ZEND_ARG_INFO(0, ini)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_config_ini_method_entry) {
	PHP_ME(Ice_Config_Ini, __construct, arginfo_ice_config_ini___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Config_Ini, cast, arginfo_ice_config_ini_cast, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Config_Ini, map, arginfo_ice_config_ini_map, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
