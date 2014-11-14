
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Ice_Http_Response_ResponseInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Http\\Response, ResponseInterface, ice, http_response_responseinterface, NULL);

	return SUCCESS;

}

