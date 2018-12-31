
extern zend_class_entry *ice_mvc_view_engine_sleet_parser_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_View_Engine_Sleet_Parser);

PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, __construct);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, text);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parse);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseControl);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseEcho);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseSet);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, parseUse);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, doParse);
PHP_METHOD(Ice_Mvc_View_Engine_Sleet_Parser, token);
zend_object *zephir_init_properties_Ice_Mvc_View_Engine_Sleet_Parser(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_text, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_text, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_parse, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_parse, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expression, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, expression)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_parsecontrol, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_parsecontrol, 0, 2, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, control)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_parseecho, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_parseecho, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_parseset, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_parseset, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_parseuse, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_parseuse, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_doparse, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_doparse, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, tokens)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_view_engine_sleet_parser_token, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, prev)
	ZEND_ARG_INFO(0, next)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_view_engine_sleet_parser_method_entry) {
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Parser, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Parser, text, arginfo_ice_mvc_view_engine_sleet_parser_text, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Parser, parse, arginfo_ice_mvc_view_engine_sleet_parser_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Parser, parseControl, arginfo_ice_mvc_view_engine_sleet_parser_parsecontrol, ZEND_ACC_PRIVATE)
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Parser, parseEcho, arginfo_ice_mvc_view_engine_sleet_parser_parseecho, ZEND_ACC_PRIVATE)
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Parser, parseSet, arginfo_ice_mvc_view_engine_sleet_parser_parseset, ZEND_ACC_PRIVATE)
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Parser, parseUse, arginfo_ice_mvc_view_engine_sleet_parser_parseuse, ZEND_ACC_PRIVATE)
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Parser, doParse, arginfo_ice_mvc_view_engine_sleet_parser_doparse, ZEND_ACC_PRIVATE)
	PHP_ME(Ice_Mvc_View_Engine_Sleet_Parser, token, arginfo_ice_mvc_view_engine_sleet_parser_token, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
