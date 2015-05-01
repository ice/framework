
extern zend_class_entry *ice_mvc_router_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Router);

PHP_METHOD(Ice_Mvc_Router, getDefaultModule);
PHP_METHOD(Ice_Mvc_Router, setDefaultModule);
PHP_METHOD(Ice_Mvc_Router, getDefaultHandler);
PHP_METHOD(Ice_Mvc_Router, setDefaultHandler);
PHP_METHOD(Ice_Mvc_Router, getDefaultAction);
PHP_METHOD(Ice_Mvc_Router, setDefaultAction);
PHP_METHOD(Ice_Mvc_Router, getMethod);
PHP_METHOD(Ice_Mvc_Router, getModule);
PHP_METHOD(Ice_Mvc_Router, getHandler);
PHP_METHOD(Ice_Mvc_Router, getAction);
PHP_METHOD(Ice_Mvc_Router, getParams);
PHP_METHOD(Ice_Mvc_Router, setSilent);
PHP_METHOD(Ice_Mvc_Router, getOptions);
PHP_METHOD(Ice_Mvc_Router, setOptions);
PHP_METHOD(Ice_Mvc_Router, getRoutes);
PHP_METHOD(Ice_Mvc_Router, setRoutes);
PHP_METHOD(Ice_Mvc_Router, getCollector);
PHP_METHOD(Ice_Mvc_Router, setCollector);
PHP_METHOD(Ice_Mvc_Router, getDispatcher);
PHP_METHOD(Ice_Mvc_Router, setDispatcher);
PHP_METHOD(Ice_Mvc_Router, __construct);
PHP_METHOD(Ice_Mvc_Router, setDefaults);
PHP_METHOD(Ice_Mvc_Router, fastRoute);
PHP_METHOD(Ice_Mvc_Router, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setdefaulthandler, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultHandler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setsilent, 0, 0, 1)
	ZEND_ARG_INFO(0, silent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setroutes, 0, 0, 1)
	ZEND_ARG_INFO(0, routes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setcollector, 0, 0, 1)
	ZEND_ARG_INFO(0, collector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setdispatcher, 0, 0, 1)
	ZEND_ARG_INFO(0, dispatcher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_router_method_entry) {
	PHP_ME(Ice_Mvc_Router, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setDefaultModule, arginfo_ice_mvc_router_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getDefaultHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setDefaultHandler, arginfo_ice_mvc_router_setdefaulthandler, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getDefaultAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setDefaultAction, arginfo_ice_mvc_router_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setSilent, arginfo_ice_mvc_router_setsilent, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setOptions, arginfo_ice_mvc_router_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setRoutes, arginfo_ice_mvc_router_setroutes, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getCollector, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setCollector, arginfo_ice_mvc_router_setcollector, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getDispatcher, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setDispatcher, arginfo_ice_mvc_router_setdispatcher, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Mvc_Router, setDefaults, arginfo_ice_mvc_router_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, fastRoute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, handle, arginfo_ice_mvc_router_handle, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
