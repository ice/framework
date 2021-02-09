
extern zend_class_entry *ice_mvc_view_engine_sleet_compiler_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_Sleet_Compiler);

PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Compiler, getParser);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Compiler, __construct);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Compiler, compile);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Compiler, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_sleet_compiler_getparser, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_sleet_compiler___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_sleet_compiler_compile, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_sleet_compiler___tostring, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_view_engine_sleet_compiler_method_entry) {
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Compiler, getParser, arginfo_ice_mvc_view_engine_sleet_compiler_getparser, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Compiler, __construct, arginfo_ice_mvc_view_engine_sleet_compiler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Compiler, compile, arginfo_ice_mvc_view_engine_sleet_compiler_compile, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Compiler, __toString, arginfo_ice_mvc_view_engine_sleet_compiler___tostring, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
