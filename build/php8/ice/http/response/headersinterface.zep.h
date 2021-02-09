
extern zend_class_entry *ice_http_response_headersinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Http_Response_HeadersInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_headersinterface_send, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_http_response_headersinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Http_Response_HeadersInterface, send, arginfo_ice_http_response_headersinterface_send)
	PHP_FE_END
};
