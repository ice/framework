
extern zend_class_entry *ice_mvc_fastrouter_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_FastRouter);

PHP_METHOD(Ice_Mvc_FastRouter, getDefaultModule);
PHP_METHOD(Ice_Mvc_FastRouter, setDefaultModule);
PHP_METHOD(Ice_Mvc_FastRouter, getDefaultHandler);
PHP_METHOD(Ice_Mvc_FastRouter, setDefaultHandler);
PHP_METHOD(Ice_Mvc_FastRouter, getDefaultAction);
PHP_METHOD(Ice_Mvc_FastRouter, setDefaultAction);
PHP_METHOD(Ice_Mvc_FastRouter, getMethod);
PHP_METHOD(Ice_Mvc_FastRouter, getModule);
PHP_METHOD(Ice_Mvc_FastRouter, getHandler);
PHP_METHOD(Ice_Mvc_FastRouter, getAction);
PHP_METHOD(Ice_Mvc_FastRouter, getParams);
PHP_METHOD(Ice_Mvc_FastRouter, setSilent);
PHP_METHOD(Ice_Mvc_FastRouter, getOptions);
PHP_METHOD(Ice_Mvc_FastRouter, getRoutes);
PHP_METHOD(Ice_Mvc_FastRouter, setRoutes);
PHP_METHOD(Ice_Mvc_FastRouter, getCollector);
PHP_METHOD(Ice_Mvc_FastRouter, setCollector);
PHP_METHOD(Ice_Mvc_FastRouter, getDispatcher);
PHP_METHOD(Ice_Mvc_FastRouter, setDispatcher);
PHP_METHOD(Ice_Mvc_FastRouter, setDefaults);
PHP_METHOD(Ice_Mvc_FastRouter, setOptions);
PHP_METHOD(Ice_Mvc_FastRouter, fastRoute);
PHP_METHOD(Ice_Mvc_FastRouter, handle);
zend_object_value zephir_init_properties_Ice_Mvc_FastRouter(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastrouter_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastrouter_setdefaulthandler, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultHandler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastrouter_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastrouter_setsilent, 0, 0, 1)
	ZEND_ARG_INFO(0, silent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastrouter_setroutes, 0, 0, 1)
	ZEND_ARG_INFO(0, routes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastrouter_setcollector, 0, 0, 1)
	ZEND_ARG_INFO(0, collector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastrouter_setdispatcher, 0, 0, 1)
	ZEND_ARG_INFO(0, dispatcher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastrouter_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastrouter_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_fastrouter_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_fastrouter_method_entry) {
	PHP_ME(Ice_Mvc_FastRouter, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, setDefaultModule, arginfo_ice_mvc_fastrouter_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, getDefaultHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, setDefaultHandler, arginfo_ice_mvc_fastrouter_setdefaulthandler, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, getDefaultAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, setDefaultAction, arginfo_ice_mvc_fastrouter_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, getModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, getHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, setSilent, arginfo_ice_mvc_fastrouter_setsilent, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, setRoutes, arginfo_ice_mvc_fastrouter_setroutes, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, getCollector, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, setCollector, arginfo_ice_mvc_fastrouter_setcollector, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, getDispatcher, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, setDispatcher, arginfo_ice_mvc_fastrouter_setdispatcher, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, setDefaults, arginfo_ice_mvc_fastrouter_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, setOptions, arginfo_ice_mvc_fastrouter_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, fastRoute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_FastRouter, handle, arginfo_ice_mvc_fastrouter_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
