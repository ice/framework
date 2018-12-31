
extern zend_class_entry *ice_mvc_view_engine_engineinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_EngineInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_engineinterface___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Ice\\Mvc\\View\\ViewInterface, 0)
	ZEND_ARG_OBJ_INFO(0, di, Ice\\Di, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_engineinterface_render, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_view_engine_engineinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Mvc_View_Engine_EngineInterface, __construct, arginfo_ice_mvc_view_engine_engineinterface___construct)
	PHP_ABSTRACT_ME(Ice_Mvc_View_Engine_EngineInterface, render, arginfo_ice_mvc_view_engine_engineinterface_render)
	PHP_FE_END
};
