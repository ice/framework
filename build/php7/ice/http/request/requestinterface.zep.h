
extern zend_class_entry *ice_http_request_requestinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Http_Request_RequestInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_hasrequest, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_hasrequest, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_haspost, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_haspost, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_hasget, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_hasget, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_hasserver, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_hasserver, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_ispost, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_ispost, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_isget, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_isget, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_isput, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_isput, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_ispatch, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_ispatch, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_ishead, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_ishead, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_isdelete, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_isdelete, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_isoptions, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_isoptions, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_getmethod, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_getmethod, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_getuseragent, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_getuseragent, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_gethttpreferer, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_requestinterface_gethttpreferer, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_getquery, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, allowEmpty, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, allowEmpty)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_getfiles, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_getpost, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, allowEmpty, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, allowEmpty)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_getserver, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_http_request_requestinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, hasRequest, arginfo_ice_http_request_requestinterface_hasrequest)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, hasPost, arginfo_ice_http_request_requestinterface_haspost)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, hasGet, arginfo_ice_http_request_requestinterface_hasget)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, hasServer, arginfo_ice_http_request_requestinterface_hasserver)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isPost, arginfo_ice_http_request_requestinterface_ispost)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isGet, arginfo_ice_http_request_requestinterface_isget)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isPut, arginfo_ice_http_request_requestinterface_isput)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isPatch, arginfo_ice_http_request_requestinterface_ispatch)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isHead, arginfo_ice_http_request_requestinterface_ishead)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isDelete, arginfo_ice_http_request_requestinterface_isdelete)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isOptions, arginfo_ice_http_request_requestinterface_isoptions)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getMethod, arginfo_ice_http_request_requestinterface_getmethod)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getUserAgent, arginfo_ice_http_request_requestinterface_getuseragent)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getHTTPReferer, arginfo_ice_http_request_requestinterface_gethttpreferer)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getQuery, arginfo_ice_http_request_requestinterface_getquery)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getFiles, arginfo_ice_http_request_requestinterface_getfiles)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getPost, arginfo_ice_http_request_requestinterface_getpost)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getServer, arginfo_ice_http_request_requestinterface_getserver)
	PHP_FE_END
};
