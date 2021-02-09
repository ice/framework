
extern zend_class_entry *ice_mvc_route_dispatcher_regex_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Dispatcher_Regex);

PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setStaticRouteMap);
PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setVariableRouteData);
PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, setData);
PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, dispatchVariableRoute);
PHP_METHOD(Ice_Mvc_Route_Dispatcher_Regex, dispatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_regex_setstaticroutemap, 0, 0, 1)
	ZEND_ARG_INFO(0, staticRouteMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_regex_setvariableroutedata, 0, 0, 1)
	ZEND_ARG_INFO(0, variableRouteData)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_regex_setdata, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_regex_dispatchvariableroute, 0, 0, 2)
	ZEND_ARG_INFO(0, routeData)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_dispatcher_regex_dispatch, 0, 0, 2)
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

ZEPHIR_INIT_FUNCS(ice_mvc_route_dispatcher_regex_method_entry) {
	PHP_ME(Ice_Mvc_Route_Dispatcher_Regex, setStaticRouteMap, arginfo_ice_mvc_route_dispatcher_regex_setstaticroutemap, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_Dispatcher_Regex, setVariableRouteData, arginfo_ice_mvc_route_dispatcher_regex_setvariableroutedata, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_Dispatcher_Regex, setData, arginfo_ice_mvc_route_dispatcher_regex_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_Dispatcher_Regex, dispatchVariableRoute, arginfo_ice_mvc_route_dispatcher_regex_dispatchvariableroute, ZEND_ACC_PROTECTED|ZEND_ACC_ABSTRACT)
	PHP_ME(Ice_Mvc_Route_Dispatcher_Regex, dispatch, arginfo_ice_mvc_route_dispatcher_regex_dispatch, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
