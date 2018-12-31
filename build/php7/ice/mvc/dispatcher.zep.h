
extern zend_class_entry *ice_mvc_dispatcher_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Dispatcher);

PHP_METHOD(Ice_Mvc_Dispatcher, getMethod);
PHP_METHOD(Ice_Mvc_Dispatcher, setMethod);
PHP_METHOD(Ice_Mvc_Dispatcher, getActiveMethod);
PHP_METHOD(Ice_Mvc_Dispatcher, dispatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_dispatcher_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_dispatcher_getactivemethod, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_dispatcher_getactivemethod, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_dispatcher_method_entry) {
	PHP_ME(Ice_Mvc_Dispatcher, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Dispatcher, setMethod, arginfo_ice_mvc_dispatcher_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Dispatcher, getActiveMethod, arginfo_ice_mvc_dispatcher_getactivemethod, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Dispatcher, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
