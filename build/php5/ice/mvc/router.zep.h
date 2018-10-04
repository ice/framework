
extern zend_class_entry *ice_mvc_router_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Router);

PHP_METHOD(Ice_Mvc_Router, getRoutes);
PHP_METHOD(Ice_Mvc_Router, getMethod);
PHP_METHOD(Ice_Mvc_Router, getModule);
PHP_METHOD(Ice_Mvc_Router, getHandler);
PHP_METHOD(Ice_Mvc_Router, getAction);
PHP_METHOD(Ice_Mvc_Router, getParams);
PHP_METHOD(Ice_Mvc_Router, getSilent);
PHP_METHOD(Ice_Mvc_Router, setSilent);
PHP_METHOD(Ice_Mvc_Router, getDefaultModule);
PHP_METHOD(Ice_Mvc_Router, setDefaultModule);
PHP_METHOD(Ice_Mvc_Router, getDefaultHandler);
PHP_METHOD(Ice_Mvc_Router, setDefaultHandler);
PHP_METHOD(Ice_Mvc_Router, getDefaultAction);
PHP_METHOD(Ice_Mvc_Router, setDefaultAction);
PHP_METHOD(Ice_Mvc_Router, addRoute);
PHP_METHOD(Ice_Mvc_Router, getRoute);
PHP_METHOD(Ice_Mvc_Router, getRouteName);
PHP_METHOD(Ice_Mvc_Router, cache);
PHP_METHOD(Ice_Mvc_Router, defaults);
PHP_METHOD(Ice_Mvc_Router, setRoutes);
PHP_METHOD(Ice_Mvc_Router, handle);
PHP_METHOD(Ice_Mvc_Router, match);
PHP_METHOD(Ice_Mvc_Router, uri);
zend_object_value zephir_init_properties_Ice_Mvc_Router(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setsilent, 0, 0, 1)
	ZEND_ARG_INFO(0, silent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setdefaulthandler, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultHandler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_addroute, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_ARRAY_INFO(0, regex, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_getroute, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_getroutename, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route, Ice\\Mvc\\Route, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_defaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_setroutes, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, routes, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_match, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_router_uri, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_router_method_entry) {
	PHP_ME(Ice_Mvc_Router, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getSilent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setSilent, arginfo_ice_mvc_router_setsilent, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setDefaultModule, arginfo_ice_mvc_router_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getDefaultHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setDefaultHandler, arginfo_ice_mvc_router_setdefaulthandler, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getDefaultAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setDefaultAction, arginfo_ice_mvc_router_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, addRoute, arginfo_ice_mvc_router_addroute, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getRoute, arginfo_ice_mvc_router_getroute, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, getRouteName, arginfo_ice_mvc_router_getroutename, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, cache, arginfo_ice_mvc_router_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, defaults, arginfo_ice_mvc_router_defaults, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, setRoutes, arginfo_ice_mvc_router_setroutes, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, handle, arginfo_ice_mvc_router_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, match, arginfo_ice_mvc_router_match, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Router, uri, arginfo_ice_mvc_router_uri, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
