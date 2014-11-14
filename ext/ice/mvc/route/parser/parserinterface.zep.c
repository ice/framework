
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Ice_Mvc_Route_Parser_ParserInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Mvc\\Route\\Parser, ParserInterface, ice, mvc_route_parser_parserinterface, ice_mvc_route_parser_parserinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns an array of the following form:
 *
 *[
 *  "/fixedRoutePart/",
 *  ["varName", "[^/]+"],
 *  "/moreFixed/",
 *  ["varName2", [0-9]+"],
 *]
 *
 * @param string $route Route to parse
 * 
 * @return array Parsed route data
 */
ZEPHIR_DOC_METHOD(Ice_Mvc_Route_Parser_ParserInterface, parse);

