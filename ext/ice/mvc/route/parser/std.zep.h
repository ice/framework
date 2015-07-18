
extern zend_class_entry *ice_mvc_route_parser_std_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Parser_Std);

PHP_METHOD(Ice_Mvc_Route_Parser_Std, parse);
PHP_METHOD(Ice_Mvc_Route_Parser_Std, parsePlaceholders);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_parser_std_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, route)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_parser_std_parseplaceholders, 0, 0, 1)
	ZEND_ARG_INFO(0, route)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_route_parser_std_method_entry) {
	PHP_ME(Ice_Mvc_Route_Parser_Std, parse, arginfo_ice_mvc_route_parser_std_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Route_Parser_Std, parsePlaceholders, arginfo_ice_mvc_route_parser_std_parseplaceholders, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
