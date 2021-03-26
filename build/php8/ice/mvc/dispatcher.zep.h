
extern zend_class_entry *ice_mvc_dispatcher_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Dispatcher);

PHP_METHOD(Ice_Mvc_Dispatcher, getMethod);
PHP_METHOD(Ice_Mvc_Dispatcher, setMethod);
PHP_METHOD(Ice_Mvc_Dispatcher, getActiveMethod);
PHP_METHOD(Ice_Mvc_Dispatcher, dispatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_dispatcher_getmethod, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_dispatcher_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_dispatcher_getactivemethod, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_dispatcher_dispatch, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_dispatcher_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Dispatcher, getMethod, arginfo_ice_mvc_dispatcher_getmethod, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Dispatcher, getMethod, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Mvc_Dispatcher, setMethod, arginfo_ice_mvc_dispatcher_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Dispatcher, getActiveMethod, arginfo_ice_mvc_dispatcher_getactivemethod, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Dispatcher, dispatch, arginfo_ice_mvc_dispatcher_dispatch, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Dispatcher, dispatch, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
