
extern zend_class_entry *ice_mvc_url_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Url);

PHP_METHOD(Ice_Mvc_Url, getBaseUri);
PHP_METHOD(Ice_Mvc_Url, setBaseUri);
PHP_METHOD(Ice_Mvc_Url, getStaticUri);
PHP_METHOD(Ice_Mvc_Url, setStaticUri);
PHP_METHOD(Ice_Mvc_Url, href);
PHP_METHOD(Ice_Mvc_Url, getStatic);
PHP_METHOD(Ice_Mvc_Url, rel);
PHP_METHOD(Ice_Mvc_Url, get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_url_getbaseuri, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_url_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_url_getstaticuri, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_mvc_url_setstaticuri, 0, 0, 1)
	ZEND_ARG_INFO(0, staticUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_url_href, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_url_getstatic, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_url_rel, 0, 0, IS_STRING, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, args)
	ZEND_ARG_TYPE_INFO(0, local, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_mvc_url_get, 0, 0, IS_STRING, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, args)
	ZEND_ARG_TYPE_INFO(0, local, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_mvc_url_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Url, getBaseUri, arginfo_ice_mvc_url_getbaseuri, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Url, getBaseUri, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Mvc_Url, setBaseUri, arginfo_ice_mvc_url_setbaseuri, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Mvc_Url, getStaticUri, arginfo_ice_mvc_url_getstaticuri, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Mvc_Url, getStaticUri, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Mvc_Url, setStaticUri, arginfo_ice_mvc_url_setstaticuri, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Url, href, arginfo_ice_mvc_url_href, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Url, getStatic, arginfo_ice_mvc_url_getstatic, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Url, rel, arginfo_ice_mvc_url_rel, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Mvc_Url, get, arginfo_ice_mvc_url_get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
