
extern zend_class_entry *ice_http_response_ce;

ZEPHIR_INIT_CLASS(Ice_Http_Response);

PHP_METHOD(Ice_Http_Response, getProtocolVersion);
PHP_METHOD(Ice_Http_Response, setProtocolVersion);
PHP_METHOD(Ice_Http_Response, getStatus);
PHP_METHOD(Ice_Http_Response, setStatus);
PHP_METHOD(Ice_Http_Response, getBody);
PHP_METHOD(Ice_Http_Response, setBody);
PHP_METHOD(Ice_Http_Response, getMessages);
PHP_METHOD(Ice_Http_Response, __construct);
PHP_METHOD(Ice_Http_Response, getHeaders);
PHP_METHOD(Ice_Http_Response, hasHeader);
PHP_METHOD(Ice_Http_Response, getHeader);
PHP_METHOD(Ice_Http_Response, setHeader);
PHP_METHOD(Ice_Http_Response, setHeaders);
PHP_METHOD(Ice_Http_Response, removeHeader);
PHP_METHOD(Ice_Http_Response, setContent);
PHP_METHOD(Ice_Http_Response, finalize);
PHP_METHOD(Ice_Http_Response, send);
PHP_METHOD(Ice_Http_Response, redirect);
PHP_METHOD(Ice_Http_Response, isEmpty);
PHP_METHOD(Ice_Http_Response, isInformational);
PHP_METHOD(Ice_Http_Response, isOk);
PHP_METHOD(Ice_Http_Response, isSuccessful);
PHP_METHOD(Ice_Http_Response, isRedirect);
PHP_METHOD(Ice_Http_Response, isRedirection);
PHP_METHOD(Ice_Http_Response, isForbidden);
PHP_METHOD(Ice_Http_Response, isNotFound);
PHP_METHOD(Ice_Http_Response, isClientError);
PHP_METHOD(Ice_Http_Response, isServerError);
PHP_METHOD(Ice_Http_Response, getMessage);
PHP_METHOD(Ice_Http_Response, __toString);
static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setprotocolversion, 0, 0, 1)
	ZEND_ARG_INFO(0, protocolVersion)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setstatus, 0, 0, 1)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setbody, 0, 0, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_hasheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_removeheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, contet)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_finalize, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Ice\\Http\\Request\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_redirect, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_INFO(0, external)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_getmessage, 0, 0, 0)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_http_response_method_entry) {
	PHP_ME(Ice_Http_Response, getProtocolVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setProtocolVersion, arginfo_ice_http_response_setprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getStatus, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setStatus, arginfo_ice_http_response_setstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setBody, arginfo_ice_http_response_setbody, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, __construct, arginfo_ice_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Http_Response, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, hasHeader, arginfo_ice_http_response_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getHeader, arginfo_ice_http_response_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setHeader, arginfo_ice_http_response_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setHeaders, arginfo_ice_http_response_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, removeHeader, arginfo_ice_http_response_removeheader, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setContent, arginfo_ice_http_response_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, finalize, arginfo_ice_http_response_finalize, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, redirect, arginfo_ice_http_response_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isInformational, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isOk, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isSuccessful, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isRedirect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isRedirection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isForbidden, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isNotFound, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isClientError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isServerError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getMessage, arginfo_ice_http_response_getmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
