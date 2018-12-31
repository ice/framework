
extern zend_class_entry *ice_cookies_ce;

ZEPHIR_INIT_CLASS(Ice_Cookies);

PHP_METHOD(Ice_Cookies, getSalt);
PHP_METHOD(Ice_Cookies, setSalt);
PHP_METHOD(Ice_Cookies, getExpiration);
PHP_METHOD(Ice_Cookies, setExpiration);
PHP_METHOD(Ice_Cookies, getPath);
PHP_METHOD(Ice_Cookies, setPath);
PHP_METHOD(Ice_Cookies, getDomain);
PHP_METHOD(Ice_Cookies, setDomain);
PHP_METHOD(Ice_Cookies, getSecure);
PHP_METHOD(Ice_Cookies, setSecure);
PHP_METHOD(Ice_Cookies, getHttpOnly);
PHP_METHOD(Ice_Cookies, setHttpOnly);
PHP_METHOD(Ice_Cookies, getEncrypt);
PHP_METHOD(Ice_Cookies, setEncrypt);
PHP_METHOD(Ice_Cookies, __construct);
PHP_METHOD(Ice_Cookies, has);
PHP_METHOD(Ice_Cookies, get);
PHP_METHOD(Ice_Cookies, set);
PHP_METHOD(Ice_Cookies, remove);
PHP_METHOD(Ice_Cookies, salt);
PHP_METHOD(Ice_Cookies, setcookie);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cookies_setsalt, 0, 0, 1)
	ZEND_ARG_INFO(0, salt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cookies_setexpiration, 0, 0, 1)
	ZEND_ARG_INFO(0, expiration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cookies_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cookies_setdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cookies_setsecure, 0, 0, 1)
	ZEND_ARG_INFO(0, secure)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cookies_sethttponly, 0, 0, 1)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cookies_setencrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, encrypt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cookies___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, salt, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, salt)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cookies_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cookies_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cookies_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cookies_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cookies_remove, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cookies_remove, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cookies_salt, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_cookies_salt, 0, 2, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cookies_setcookie, 0, 0, 7)
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
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expire, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, expire)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, domain, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, domain)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, secure, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, secure)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, httpOnly, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, httpOnly)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_cookies_method_entry) {
	PHP_ME(Ice_Cookies, getSalt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, setSalt, arginfo_ice_cookies_setsalt, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, getExpiration, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, setExpiration, arginfo_ice_cookies_setexpiration, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, setPath, arginfo_ice_cookies_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, getDomain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, setDomain, arginfo_ice_cookies_setdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, getSecure, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, setSecure, arginfo_ice_cookies_setsecure, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, getHttpOnly, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, setHttpOnly, arginfo_ice_cookies_sethttponly, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, getEncrypt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, setEncrypt, arginfo_ice_cookies_setencrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, __construct, arginfo_ice_cookies___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Cookies, has, arginfo_ice_cookies_has, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, get, arginfo_ice_cookies_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, set, arginfo_ice_cookies_set, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, remove, arginfo_ice_cookies_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, salt, arginfo_ice_cookies_salt, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cookies, setcookie, arginfo_ice_cookies_setcookie, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
