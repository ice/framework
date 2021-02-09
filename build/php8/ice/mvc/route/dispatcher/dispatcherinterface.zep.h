
extern zend_class_entry *ice_mvc_route_dispatcher_dispatcherinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_dispatcherinterface_dispatch, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, httpMethod, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, httpMethod)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_route_dispatcher_dispatcherinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Mvc_Route_Dispatcher_DispatcherInterface, dispatch, arginfo_ice_mvc_route_dispatcher_dispatcherinterface_dispatch)
	PHP_FE_END
};
