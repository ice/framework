
extern zend_class_entry *ice_mvc_route_dispatcher_groupcount_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_GroupCount);

PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setStaticRouteMap);
PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setVariableRouteData);
PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, __construct);
PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, setData);
PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, dispatch);
PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, dispatchStaticRoute);
PHP_METHOD(Ice_Mvc_Route_Dispatcher_GroupCount, dispatchVariableRoute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_groupcount_setstaticroutemap, 0, 0, 1)
	ZEND_ARG_INFO(0, staticRouteMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_groupcount_setvariableroutedata, 0, 0, 1)
	ZEND_ARG_INFO(0, variableRouteData)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_groupcount___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_groupcount_setdata, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_groupcount_dispatch, 0, 0, 2)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_groupcount_dispatchstaticroute, 0, 0, 2)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_groupcount_dispatchvariableroute, 0, 0, 2)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_route_dispatcher_groupcount_method_entry) {
	PHP_ME(Ice_Mvc_Route_Dispatcher_GroupCount, setStaticRouteMap, arginfo_ice_mvc_route_dispatcher_groupcount_setstaticroutemap, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_Dispatcher_GroupCount, setVariableRouteData, arginfo_ice_mvc_route_dispatcher_groupcount_setvariableroutedata, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_Dispatcher_GroupCount, __construct, arginfo_ice_mvc_route_dispatcher_groupcount___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Mvc_Route_Dispatcher_GroupCount, setData, arginfo_ice_mvc_route_dispatcher_groupcount_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_Dispatcher_GroupCount, dispatch, arginfo_ice_mvc_route_dispatcher_groupcount_dispatch, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_Dispatcher_GroupCount, dispatchStaticRoute, arginfo_ice_mvc_route_dispatcher_groupcount_dispatchstaticroute, ZEND_ACC_PRIVATE)
	PHP_ME(Ice_Mvc_Route_Dispatcher_GroupCount, dispatchVariableRoute, arginfo_ice_mvc_route_dispatcher_groupcount_dispatchvariableroute, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
