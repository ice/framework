
extern zend_class_entry *ice_mvc_route_collector_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Collector);

PHP_METHOD(Ice_Mvc_Route_Collector, setRouteParser);
PHP_METHOD(Ice_Mvc_Route_Collector, setDataGenerator);
PHP_METHOD(Ice_Mvc_Route_Collector, __construct);
PHP_METHOD(Ice_Mvc_Route_Collector, addRoute);
PHP_METHOD(Ice_Mvc_Route_Collector, getData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_collector_setrouteparser, 0, 0, 1)
	ZEND_ARG_INFO(0, routeParser)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_collector_setdatagenerator, 0, 0, 1)
	ZEND_ARG_INFO(0, dataGenerator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_collector___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, routeParser, Ice\\Mvc\\Route\\Parser\\ParserInterface, 1)
	ZEND_ARG_OBJ_INFO(0, dataGenerator, Ice\\Mvc\\Route\\DataGenerator\\DataGeneratorInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_collector_addroute, 0, 0, 2)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, route)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_route_collector_method_entry) {
	PHP_ME(Ice_Mvc_Route_Collector, setRouteParser, arginfo_ice_mvc_route_collector_setrouteparser, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_Collector, setDataGenerator, arginfo_ice_mvc_route_collector_setdatagenerator, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_Collector, __construct, arginfo_ice_mvc_route_collector___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Mvc_Route_Collector, addRoute, arginfo_ice_mvc_route_collector_addroute, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_Collector, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
