
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Headers interface.
 *
 * @package     Ice/Http
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Http_Response_HeadersInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Http\\Response, HeadersInterface, ice, http_response_headersinterface, ice_http_response_headersinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Ice_Http_Response_HeadersInterface, send);

