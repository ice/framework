
extern zend_class_entry *ice_http_response_headers_ce;

ZEPHIR_INIT_CLASS(Ice_Http_Response_Headers);

PHP_METHOD(Ice_Http_Response_Headers, send);

ZEPHIR_INIT_FUNCS(ice_http_response_headers_method_entry) {
	PHP_ME(Ice_Http_Response_Headers, send, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
