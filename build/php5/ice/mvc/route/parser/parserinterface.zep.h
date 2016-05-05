
extern zend_class_entry *ice_mvc_route_parser_parserinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Parser_ParserInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_route_parser_parserinterface_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, route)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_route_parser_parserinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Mvc_Route_Parser_ParserInterface, parse, arginfo_ice_mvc_route_parser_parserinterface_parse)
	PHP_FE_END
};
