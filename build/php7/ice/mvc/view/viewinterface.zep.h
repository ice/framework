
extern zend_class_entry *ice_mvc_view_viewinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_View_ViewInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_viewinterface_render, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_view_viewinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Mvc_View_ViewInterface, getEngines, NULL)
	PHP_ABSTRACT_ME(Ice_Mvc_View_ViewInterface, render, arginfo_ice_mvc_view_viewinterface_render)
	PHP_FE_END
};
