
extern zend_class_entry *ice_auth_social_facebook_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Social_Facebook);

PHP_METHOD(Ice_Auth_Social_Facebook, __construct);
PHP_METHOD(Ice_Auth_Social_Facebook, getImage);
PHP_METHOD(Ice_Auth_Social_Facebook, authenticate);
PHP_METHOD(Ice_Auth_Social_Facebook, prepareAuthParams);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_facebook___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_facebook_getimage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_facebook_authenticate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_facebook_prepareauthparams, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_social_facebook_method_entry) {
	PHP_ME(Ice_Auth_Social_Facebook, __construct, arginfo_ice_auth_social_facebook___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Social_Facebook, getImage, arginfo_ice_auth_social_facebook_getimage, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Social_Facebook, getImage, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Social_Facebook, authenticate, arginfo_ice_auth_social_facebook_authenticate, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Social_Facebook, authenticate, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Social_Facebook, prepareAuthParams, arginfo_ice_auth_social_facebook_prepareauthparams, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Social_Facebook, prepareAuthParams, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
