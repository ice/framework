
extern zend_class_entry *ice_http_request_requestinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Http_Request_RequestInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_hasrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_haspost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_hasget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_hasserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_getquery, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, allowEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_getfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_getpost, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, allowEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_requestinterface_getserver, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_http_request_requestinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, hasRequest, arginfo_ice_http_request_requestinterface_hasrequest)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, hasPost, arginfo_ice_http_request_requestinterface_haspost)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, hasGet, arginfo_ice_http_request_requestinterface_hasget)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, hasServer, arginfo_ice_http_request_requestinterface_hasserver)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isPost, NULL)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isGet, NULL)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isPut, NULL)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isPatch, NULL)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isHead, NULL)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isDelete, NULL)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, isOptions, NULL)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getMethod, NULL)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getUserAgent, NULL)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getHTTPReferer, NULL)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getQuery, arginfo_ice_http_request_requestinterface_getquery)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getFiles, arginfo_ice_http_request_requestinterface_getfiles)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getPost, arginfo_ice_http_request_requestinterface_getpost)
	PHP_ABSTRACT_ME(Ice_Http_Request_RequestInterface, getServer, arginfo_ice_http_request_requestinterface_getserver)
	PHP_FE_END
};
