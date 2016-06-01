
extern zend_class_entry *ice_mvc_dispatcher_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Dispatcher);

PHP_METHOD(Ice_Mvc_Dispatcher, getMethod);
PHP_METHOD(Ice_Mvc_Dispatcher, setMethod);
PHP_METHOD(Ice_Mvc_Dispatcher, getActiveMethod);
PHP_METHOD(Ice_Mvc_Dispatcher, dispatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_dispatcher_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_dispatcher_method_entry) {
	PHP_ME(Ice_Mvc_Dispatcher, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Dispatcher, setMethod, arginfo_ice_mvc_dispatcher_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Dispatcher, getActiveMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Dispatcher, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
