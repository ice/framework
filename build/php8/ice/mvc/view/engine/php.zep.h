
extern zend_class_entry *ice_mvc_view_engine_php_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_Php);

PHP_METHOD(Ice_Mvc_View_Engine_Php, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_php_render, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_view_engine_php_method_entry) {
	PHP_ME(Ice_Mvc_View_Engine_Php, render, arginfo_ice_mvc_view_engine_php_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
