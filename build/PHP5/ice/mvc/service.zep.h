
extern zend_class_entry *ice_mvc_service_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Service);

PHP_METHOD(Ice_Mvc_Service, setModel);
PHP_METHOD(Ice_Mvc_Service, getModel);
PHP_METHOD(Ice_Mvc_Service, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_service_setmodel, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_service___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_service_method_entry) {
	PHP_ME(Ice_Mvc_Service, setModel, arginfo_ice_mvc_service_setmodel, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Service, getModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Service, __call, arginfo_ice_mvc_service___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
