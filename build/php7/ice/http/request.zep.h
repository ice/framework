
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

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_hasrequest, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_hasrequest, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_haspost, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_haspost, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_hasget, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_hasget, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_hasserver, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_hasserver, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_hasfile, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_hasfile, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_ispost, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_ispost, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_isget, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_isget, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_isput, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_isput, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_ispatch, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_ispatch, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_ishead, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_ishead, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_isdelete, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_isdelete, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_isoptions, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_isoptions, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_isajax, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_isajax, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_getmethod, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_getmethod, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_getuseragent, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_getuseragent, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_gethttpreferer, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_gethttpreferer, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_getclientaddress, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_http_request_getclientaddress, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_getquery, 0, 0, 0)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_getpost, 0, 0, 0)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_getserver, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_http_request_getfiles, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_http_request_method_entry) {
	PHP_ME(Ice_Http_Request, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Http_Request, hasRequest, arginfo_ice_http_request_hasrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, hasPost, arginfo_ice_http_request_haspost, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, hasGet, arginfo_ice_http_request_hasget, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, hasServer, arginfo_ice_http_request_hasserver, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, hasFile, arginfo_ice_http_request_hasfile, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isPost, arginfo_ice_http_request_ispost, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isGet, arginfo_ice_http_request_isget, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isPut, arginfo_ice_http_request_isput, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isPatch, arginfo_ice_http_request_ispatch, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isHead, arginfo_ice_http_request_ishead, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isDelete, arginfo_ice_http_request_isdelete, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isOptions, arginfo_ice_http_request_isoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, isAjax, arginfo_ice_http_request_isajax, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getMethod, arginfo_ice_http_request_getmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getUserAgent, arginfo_ice_http_request_getuseragent, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getHTTPReferer, arginfo_ice_http_request_gethttpreferer, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getClientAddress, arginfo_ice_http_request_getclientaddress, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getQuery, arginfo_ice_http_request_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getPost, arginfo_ice_http_request_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getServer, arginfo_ice_http_request_getserver, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Http_Request, getFiles, arginfo_ice_http_request_getfiles, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
