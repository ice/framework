
extern zend_class_entry *ice_mvc_app_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_App);

PHP_METHOD(Ice_Mvc_App, getAutoRender);
PHP_METHOD(Ice_Mvc_App, setAutoRender);
PHP_METHOD(Ice_Mvc_App, getDefaultModule);
PHP_METHOD(Ice_Mvc_App, setDefaultModule);
PHP_METHOD(Ice_Mvc_App, getModules);
PHP_METHOD(Ice_Mvc_App, setModules);
PHP_METHOD(Ice_Mvc_App, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_app_setautorender, 0, 0, 1)
	ZEND_ARG_INFO(0, autoRender)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_app_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_app_setmodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_app_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_app_method_entry) {
	PHP_ME(Ice_Mvc_App, getAutoRender, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_App, setAutoRender, arginfo_ice_mvc_app_setautorender, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_App, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_App, setDefaultModule, arginfo_ice_mvc_app_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_App, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_App, setModules, arginfo_ice_mvc_app_setmodules, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_App, handle, arginfo_ice_mvc_app_handle, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
