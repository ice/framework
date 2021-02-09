
extern zend_class_entry *ice_mvc_view_engine_sleet_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_Sleet);

PHP_METHOD(Ice_Mvc_View_Engine_Sleet, getCompiler);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet, compile);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_sleet_getcompiler, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_sleet_compile, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_sleet_render, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_view_engine_sleet_method_entry) {
	PHP_ME(Ice_Mvc_View_Engine_Sleet, getCompiler, arginfo_ice_mvc_view_engine_sleet_getcompiler, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_View_Engine_Sleet, compile, arginfo_ice_mvc_view_engine_sleet_compile, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_View_Engine_Sleet, render, arginfo_ice_mvc_view_engine_sleet_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
