
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
zend_object_value zephir_init_properties_Ice_Cli_Router(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_setdefaulthandler, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultHandler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_cli_router_method_entry) {
	PHP_ME(Ice_Cli_Router, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, setDefaultModule, arginfo_ice_cli_router_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, getDefaultHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, setDefaultHandler, arginfo_ice_cli_router_setdefaulthandler, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, getDefaultAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, setDefaultAction, arginfo_ice_cli_router_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, getModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, getHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, setDefaults, arginfo_ice_cli_router_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Router, handle, arginfo_ice_cli_router_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
