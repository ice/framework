
extern zend_class_entry *ice_mvc_route_datagenerator_regex_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Route_DataGenerator_Regex);

PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, getApproxChunkSize);
PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, processChunk);
PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addRoute);
PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, getData);
PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, generateVariableRouteData);
PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, computeChunkSize);
PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, isStaticRoute);
PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addStaticRoute);
PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, addVariableRoute);
PHP_METHOD(Ice_Mvc_Route_DataGenerator_Regex, buildRegexForRoute);
zend_object_value zephir_init_properties_Ice_Mvc_Route_DataGenerator_Regex(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_datagenerator_regex_processchunk, 0, 0, 1)
	ZEND_ARG_INFO(0, regexToRoutesMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_datagenerator_regex_addroute, 0, 0, 3)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, routeData)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_datagenerator_regex_computechunksize, 0, 0, 1)
	ZEND_ARG_INFO(0, count)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_datagenerator_regex_isstaticroute, 0, 0, 1)
	ZEND_ARG_INFO(0, routeData)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_datagenerator_regex_addstaticroute, 0, 0, 3)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, routeData)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_datagenerator_regex_addvariableroute, 0, 0, 3)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, routeData)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_datagenerator_regex_buildregexforroute, 0, 0, 1)
	ZEND_ARG_INFO(0, routeData)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_route_datagenerator_regex_method_entry) {
	PHP_ME(Ice_Mvc_Route_DataGenerator_Regex, getApproxChunkSize, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_ABSTRACT)
	PHP_ME(Ice_Mvc_Route_DataGenerator_Regex, processChunk, arginfo_ice_mvc_route_datagenerator_regex_processchunk, ZEND_ACC_PROTECTED|ZEND_ACC_ABSTRACT)
	PHP_ME(Ice_Mvc_Route_DataGenerator_Regex, addRoute, arginfo_ice_mvc_route_datagenerator_regex_addroute, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_DataGenerator_Regex, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_DataGenerator_Regex, generateVariableRouteData, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Mvc_Route_DataGenerator_Regex, computeChunkSize, arginfo_ice_mvc_route_datagenerator_regex_computechunksize, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Mvc_Route_DataGenerator_Regex, isStaticRoute, arginfo_ice_mvc_route_datagenerator_regex_isstaticroute, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Mvc_Route_DataGenerator_Regex, addStaticRoute, arginfo_ice_mvc_route_datagenerator_regex_addstaticroute, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Mvc_Route_DataGenerator_Regex, addVariableRoute, arginfo_ice_mvc_route_datagenerator_regex_addvariableroute, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Mvc_Route_DataGenerator_Regex, buildRegexForRoute, arginfo_ice_mvc_route_datagenerator_regex_buildregexforroute, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
