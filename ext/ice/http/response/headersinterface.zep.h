
extern zend_class_entry *ice_http_response_headersinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Http_Response_HeadersInterface);

ZEPHIR_INIT_FUNCS(ice_http_response_headersinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Http_Response_HeadersInterface, send, NULL)
	PHP_FE_END
};
