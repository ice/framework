
extern zend_class_entry *ice_config_env_ce;

ZEPHIR_INIT_CLASS(Ice_Config_Env);

PHP_METHOD(Ice_Config_Env, __construct);
PHP_METHOD(Ice_Config_Env, has);
PHP_METHOD(Ice_Config_Env, get);
PHP_METHOD(Ice_Config_Env, set);
PHP_METHOD(Ice_Config_Env, remove);
PHP_METHOD(Ice_Config_Env, getData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_env___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_env_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_env_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, required)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_env_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_env_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_config_env_method_entry) {
	PHP_ME(Ice_Config_Env, __construct, arginfo_ice_config_env___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Config_Env, has, arginfo_ice_config_env_has, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Config_Env, get, arginfo_ice_config_env_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Config_Env, set, arginfo_ice_config_env_set, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Config_Env, remove, arginfo_ice_config_env_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Config_Env, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
