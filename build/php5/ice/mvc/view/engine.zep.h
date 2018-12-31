
extern zend_class_entry *ice_mvc_view_engine_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine);

PHP_METHOD(Ice_Mvc_View_Engine, setOptions);
PHP_METHOD(Ice_Mvc_View_Engine, __construct);
PHP_METHOD(Ice_Mvc_View_Engine, getContent);
PHP_METHOD(Ice_Mvc_View_Engine, load);
PHP_METHOD(Ice_Mvc_View_Engine, partial);
PHP_METHOD(Ice_Mvc_View_Engine, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Ice\\Mvc\\View\\ViewInterface, 0)
	ZEND_ARG_OBJ_INFO(0, di, Ice\\Di, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_load, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_render, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_view_engine_method_entry) {
	PHP_ME(Ice_Mvc_View_Engine, setOptions, arginfo_ice_mvc_view_engine_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_View_Engine, __construct, arginfo_ice_mvc_view_engine___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Mvc_View_Engine, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_View_Engine, load, arginfo_ice_mvc_view_engine_load, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_View_Engine, partial, arginfo_ice_mvc_view_engine_partial, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_View_Engine, render, arginfo_ice_mvc_view_engine_render, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_FE_END
};
