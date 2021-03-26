
extern zend_class_entry *ice_auth_social_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Social);

PHP_METHOD(Ice_Auth_Social, getAdapter);
PHP_METHOD(Ice_Auth_Social, __construct);
PHP_METHOD(Ice_Auth_Social, authenticate);
PHP_METHOD(Ice_Auth_Social, get);
PHP_METHOD(Ice_Auth_Social, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_getadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, adapter, Ice\\Auth\\Social\\SocialInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_authenticate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social___call, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_social_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Social, getAdapter, arginfo_ice_auth_social_getadapter, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Social, getAdapter, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Auth_Social, __construct, arginfo_ice_auth_social___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Social, authenticate, arginfo_ice_auth_social_authenticate, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Social, authenticate, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Auth_Social, get, arginfo_ice_auth_social_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social, __call, arginfo_ice_auth_social___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
