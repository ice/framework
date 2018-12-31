
extern zend_class_entry *ice_mvc_app_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_App);

PHP_METHOD(Ice_Mvc_App, getAutoRender);
PHP_METHOD(Ice_Mvc_App, setAutoRender);
PHP_METHOD(Ice_Mvc_App, getModules);
PHP_METHOD(Ice_Mvc_App, setModules);
PHP_METHOD(Ice_Mvc_App, __construct);
PHP_METHOD(Ice_Mvc_App, handle);
PHP_METHOD(Ice_Mvc_App, addModule);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_app_setautorender, 0, 0, 1)
	ZEND_ARG_INFO(0, autoRender)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_app_setmodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_app___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, di, Ice\\Di, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_app_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_app_addmodule, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_app_method_entry) {
	PHP_ME(Ice_Mvc_App, getAutoRender, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_App, setAutoRender, arginfo_ice_mvc_app_setautorender, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_App, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_App, setModules, arginfo_ice_mvc_app_setmodules, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_App, __construct, arginfo_ice_mvc_app___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Mvc_App, handle, arginfo_ice_mvc_app_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_App, addModule, arginfo_ice_mvc_app_addmodule, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
