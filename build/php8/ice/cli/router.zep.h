
extern zend_class_entry *ice_cli_router_ce;

ZEPHIR_INIT_CLASS(Ice_Cli_Router);

PHP_METHOD(Ice_Cli_Router, getDefaultModule);
PHP_METHOD(Ice_Cli_Router, setDefaultModule);
PHP_METHOD(Ice_Cli_Router, getDefaultHandler);
PHP_METHOD(Ice_Cli_Router, setDefaultHandler);
PHP_METHOD(Ice_Cli_Router, getDefaultAction);
PHP_METHOD(Ice_Cli_Router, setDefaultAction);
PHP_METHOD(Ice_Cli_Router, getModule);
PHP_METHOD(Ice_Cli_Router, getHandler);
PHP_METHOD(Ice_Cli_Router, getAction);
PHP_METHOD(Ice_Cli_Router, getParams);
PHP_METHOD(Ice_Cli_Router, setDefaults);
PHP_METHOD(Ice_Cli_Router, handle);
zend_object *zephir_init_properties_Ice_Cli_Router(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_getdefaultmodule, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_getdefaulthandler, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_setdefaulthandler, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultHandler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_getdefaultaction, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_getmodule, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_gethandler, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_getaction, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_getparams, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cli_router_handle, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_zephir_init_properties_ice_cli_router, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_cli_router_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Cli_Router, getDefaultModule, arginfo_ice_cli_router_getdefaultmodule, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Cli_Router, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Cli_Router, setDefaultModule, arginfo_ice_cli_router_setdefaultmodule, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Cli_Router, getDefaultHandler, arginfo_ice_cli_router_getdefaulthandler, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Cli_Router, getDefaultHandler, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Cli_Router, setDefaultHandler, arginfo_ice_cli_router_setdefaulthandler, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Cli_Router, getDefaultAction, arginfo_ice_cli_router_getdefaultaction, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Cli_Router, getDefaultAction, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Cli_Router, setDefaultAction, arginfo_ice_cli_router_setdefaultaction, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Cli_Router, getModule, arginfo_ice_cli_router_getmodule, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Cli_Router, getModule, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Cli_Router, getHandler, arginfo_ice_cli_router_gethandler, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Cli_Router, getHandler, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Cli_Router, getAction, arginfo_ice_cli_router_getaction, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Cli_Router, getAction, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Cli_Router, getParams, arginfo_ice_cli_router_getparams, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Cli_Router, getParams, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Cli_Router, setDefaults, arginfo_ice_cli_router_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, handle, arginfo_ice_cli_router_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
