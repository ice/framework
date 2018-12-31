
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

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_config_env_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_config_env_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_config_env_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, required, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, required)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_config_env_set, 0, 2, Ice\\Config\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_config_env_set, 0, 2, IS_OBJECT, "Ice\\Config\\self", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_config_env_remove, 0, 1, Ice\\Config\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_config_env_remove, 0, 1, IS_OBJECT, "Ice\\Config\\self", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_config_env_getdata, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_config_env_getdata, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_config_env_method_entry) {
	PHP_ME(Ice_Config_Env, __construct, arginfo_ice_config_env___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Config_Env, has, arginfo_ice_config_env_has, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Config_Env, get, arginfo_ice_config_env_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Config_Env, set, arginfo_ice_config_env_set, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Config_Env, remove, arginfo_ice_config_env_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Config_Env, getData, arginfo_ice_config_env_getdata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
