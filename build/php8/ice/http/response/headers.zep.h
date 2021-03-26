
extern zend_class_entry *ice_http_response_headers_ce;

ZEPHIR_INIT_CLASS(Ice_Http_Response_Headers);

PHP_METHOD(Ice_Http_Response_Headers, send);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_headers_send, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_http_response_headers_method_entry) {
	PHP_ME(Ice_Http_Response_Headers, send, arginfo_ice_http_response_headers_send, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
