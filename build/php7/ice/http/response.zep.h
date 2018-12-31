
extern zend_class_entry *ice_http_response_ce;

ZEPHIR_INIT_CLASS(Ice_Http_Response);

PHP_METHOD(Ice_Http_Response, getProtocolVersion);
PHP_METHOD(Ice_Http_Response, setProtocolVersion);
PHP_METHOD(Ice_Http_Response, getStatus);
PHP_METHOD(Ice_Http_Response, setStatus);
PHP_METHOD(Ice_Http_Response, getLoops);
PHP_METHOD(Ice_Http_Response, setLoops);
PHP_METHOD(Ice_Http_Response, getRedirects);
PHP_METHOD(Ice_Http_Response, getBody);
PHP_METHOD(Ice_Http_Response, setBody);
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
PHP_METHOD(Ice_Http_Response, sendFile);
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
PHP_METHOD(Ice_Http_Response, getMessages);
PHP_METHOD(Ice_Http_Response, toJson);
PHP_METHOD(Ice_Http_Response, toXml);
PHP_METHOD(Ice_Http_Response, xmlEncode);
PHP_METHOD(Ice_Http_Response, __toString);
PHP_METHOD(Ice_Http_Response, getByteRange);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setprotocolversion, 0, 0, 1)
	ZEND_ARG_INFO(0, protocolVersion)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setstatus, 0, 0, 1)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setloops, 0, 0, 1)
	ZEND_ARG_INFO(0, loops)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setbody, 0, 0, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, body)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, status, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, status)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_getheaders, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_getheaders, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_hasheader, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_hasheader, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_getheader, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_getheader, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setheader, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_setheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_removeheader, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_http_response_setcontent, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_setcontent, 0, 1, IS_OBJECT, "NULL", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, contet, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, contet)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_finalize, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Ice\\Http\\Request\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_sendfile, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filename)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mime, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, mime)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_redirect, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, location, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, location)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, status, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, status)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, external, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, external)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isempty, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isempty, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isinformational, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isinformational, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isok, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isok, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_issuccessful, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_issuccessful, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isredirect, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isredirect, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isredirection, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isredirection, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isforbidden, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isforbidden, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isnotfound, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isnotfound, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isclienterror, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isclienterror, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isservererror, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_isservererror, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_getmessage, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_getmessage, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_getmessages, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_getmessages, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_tojson, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_toxml, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_response_xmlencode, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, root, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, root)
#endif
	ZEND_ARG_OBJ_INFO(0, domNode, DOMElement, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_getbyterange, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_response_getbyterange, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, size)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_http_response_method_entry) {
	PHP_ME(Ice_Http_Response, getProtocolVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setProtocolVersion, arginfo_ice_http_response_setprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getStatus, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setStatus, arginfo_ice_http_response_setstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getLoops, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setLoops, arginfo_ice_http_response_setloops, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getRedirects, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setBody, arginfo_ice_http_response_setbody, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, __construct, arginfo_ice_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Http_Response, getHeaders, arginfo_ice_http_response_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, hasHeader, arginfo_ice_http_response_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getHeader, arginfo_ice_http_response_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setHeader, arginfo_ice_http_response_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setHeaders, arginfo_ice_http_response_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, removeHeader, arginfo_ice_http_response_removeheader, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, setContent, arginfo_ice_http_response_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, finalize, arginfo_ice_http_response_finalize, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, sendFile, arginfo_ice_http_response_sendfile, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, redirect, arginfo_ice_http_response_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isEmpty, arginfo_ice_http_response_isempty, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isInformational, arginfo_ice_http_response_isinformational, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isOk, arginfo_ice_http_response_isok, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isSuccessful, arginfo_ice_http_response_issuccessful, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isRedirect, arginfo_ice_http_response_isredirect, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isRedirection, arginfo_ice_http_response_isredirection, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isForbidden, arginfo_ice_http_response_isforbidden, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isNotFound, arginfo_ice_http_response_isnotfound, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isClientError, arginfo_ice_http_response_isclienterror, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, isServerError, arginfo_ice_http_response_isservererror, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getMessage, arginfo_ice_http_response_getmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getMessages, arginfo_ice_http_response_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, toJson, arginfo_ice_http_response_tojson, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, toXml, arginfo_ice_http_response_toxml, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, xmlEncode, arginfo_ice_http_response_xmlencode, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, __toString, arginfo_ice_http_response___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Response, getByteRange, arginfo_ice_http_response_getbyterange, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
