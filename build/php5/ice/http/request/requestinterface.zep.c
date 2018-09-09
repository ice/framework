
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Request interface.
 *
 * @package     Ice/Http
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Http_Request_RequestInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Http\\Request, RequestInterface, ice, http_request_requestinterface, ice_http_request_requestinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, hasRequest);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, hasPost);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, hasGet);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, hasServer);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, isPost);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, isGet);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, isPut);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, isPatch);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, isHead);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, isDelete);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, isOptions);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, getMethod);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, getUserAgent);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, getHTTPReferer);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, getQuery);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, getFiles);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, getPost);

ZEPHIR_DOC_METHOD(Ice_Http_Request_RequestInterface, getServer);

