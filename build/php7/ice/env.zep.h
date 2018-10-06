
extern zend_class_entry *ice_env_ce;

ZEPHIR_INIT_CLASS(Ice_Env);

PHP_METHOD(Ice_Env, __construct);
PHP_METHOD(Ice_Env, has);
PHP_METHOD(Ice_Env, get);
PHP_METHOD(Ice_Env, set);
PHP_METHOD(Ice_Env, remove);
PHP_METHOD(Ice_Env, getData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_env___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_env_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_env_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_env_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, required, _IS_BOOL, 1)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_env_set, 0, 2, Ice\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_env_set, 0, 2, NULL, "Ice\\self", 0)
#endif
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_env_remove, 0, 1, Ice\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_env_remove, 0, 1, NULL, "Ice\\self", 0)
#endif
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_env_getdata, 0, 0, IS_NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_env_getdata, 0, 0, IS_NULL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_env_method_entry) {
	PHP_ME(Ice_Env, __construct, arginfo_ice_env___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Env, has, arginfo_ice_env_has, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Env, get, arginfo_ice_env_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Env, set, arginfo_ice_env_set, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Env, remove, arginfo_ice_env_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Env, getData, arginfo_ice_env_getdata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
