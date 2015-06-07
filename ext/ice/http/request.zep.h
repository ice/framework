
extern zend_class_entry *ice_http_request_ce;

ZEPHIR_INIT_CLASS(Ice_Http_Request);

PHP_METHOD(Ice_Http_Request, __construct);
PHP_METHOD(Ice_Http_Request, hasRequest);
PHP_METHOD(Ice_Http_Request, hasPost);
PHP_METHOD(Ice_Http_Request, hasGet);
PHP_METHOD(Ice_Http_Request, hasServer);
PHP_METHOD(Ice_Http_Request, hasFile);
PHP_METHOD(Ice_Http_Request, isPost);
PHP_METHOD(Ice_Http_Request, isGet);
PHP_METHOD(Ice_Http_Request, isPut);
PHP_METHOD(Ice_Http_Request, isPatch);
PHP_METHOD(Ice_Http_Request, isHead);
PHP_METHOD(Ice_Http_Request, isDelete);
PHP_METHOD(Ice_Http_Request, isOptions);
PHP_METHOD(Ice_Http_Request, isAjax);
PHP_METHOD(Ice_Http_Request, getMethod);
PHP_METHOD(Ice_Http_Request, getUserAgent);
PHP_METHOD(Ice_Http_Request, getHTTPReferer);
PHP_METHOD(Ice_Http_Request, getClientAddress);
PHP_METHOD(Ice_Http_Request, getQuery);
PHP_METHOD(Ice_Http_Request, getPost);
PHP_METHOD(Ice_Http_Request, getServer);
PHP_METHOD(Ice_Http_Request, getFiles);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_hasrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_haspost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_hasget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_hasserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_hasfile, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_getquery, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, allowEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_getpost, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, allowEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_getserver, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_getfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_http_request_method_entry) {
	PHP_ME(Ice_Http_Request, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Http_Request, hasRequest, arginfo_ice_http_request_hasrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, hasPost, arginfo_ice_http_request_haspost, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, hasGet, arginfo_ice_http_request_hasget, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, hasServer, arginfo_ice_http_request_hasserver, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, hasFile, arginfo_ice_http_request_hasfile, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isPost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isGet, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isPut, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isPatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isHead, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isDelete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isAjax, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getUserAgent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getHTTPReferer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getClientAddress, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getQuery, arginfo_ice_http_request_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getPost, arginfo_ice_http_request_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getServer, arginfo_ice_http_request_getserver, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getFiles, arginfo_ice_http_request_getfiles, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
