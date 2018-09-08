
extern zend_class_entry *ice_mvc_moduleinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_ModuleInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_moduleinterface_registerautoloaders, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, loader, Ice\\Loader, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_moduleinterface_registerservices, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Ice\\Di, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_moduleinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Mvc_ModuleInterface, registerAutoloaders, arginfo_ice_mvc_moduleinterface_registerautoloaders)
	PHP_ABSTRACT_ME(Ice_Mvc_ModuleInterface, registerServices, arginfo_ice_mvc_moduleinterface_registerservices)
	PHP_FE_END
};
