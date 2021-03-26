
extern zend_class_entry *ice_mvc_route_datagenerator_groupcount_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Route_DataGenerator_GroupCount);

PHP_METHOD(Ice_Mvc_Route_DataGenerator_GroupCount, getApproxChunkSize);
PHP_METHOD(Ice_Mvc_Route_DataGenerator_GroupCount, processChunk);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_datagenerator_groupcount_getapproxchunksize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_datagenerator_groupcount_processchunk, 0, 0, 1)
	ZEND_ARG_INFO(0, regexToRoutesMap)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_route_datagenerator_groupcount_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Route_DataGenerator_GroupCount, getApproxChunkSize, arginfo_ice_mvc_route_datagenerator_groupcount_getapproxchunksize, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Ice_Mvc_Route_DataGenerator_GroupCount, getApproxChunkSize, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_ME(Ice_Mvc_Route_DataGenerator_GroupCount, processChunk, arginfo_ice_mvc_route_datagenerator_groupcount_processchunk, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
