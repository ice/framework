
extern zend_class_entry *ice_auth_social_twitter_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Social_Twitter);

PHP_METHOD(Ice_Auth_Social_Twitter, __construct);
PHP_METHOD(Ice_Auth_Social_Twitter, getSocialPage);
PHP_METHOD(Ice_Auth_Social_Twitter, getImage);
PHP_METHOD(Ice_Auth_Social_Twitter, authenticate);
PHP_METHOD(Ice_Auth_Social_Twitter, prepareAuthParams);
PHP_METHOD(Ice_Auth_Social_Twitter, prepareUrlParams);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_twitter___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_twitter_getsocialpage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_twitter_getimage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_twitter_authenticate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_twitter_prepareauthparams, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_twitter_prepareurlparams, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_TYPE_INFO(0, oauthToken, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_social_twitter_method_entry) {
	PHP_ME(Ice_Auth_Social_Twitter, __construct, arginfo_ice_auth_social_twitter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Social_Twitter, getSocialPage, arginfo_ice_auth_social_twitter_getsocialpage, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Social_Twitter, getSocialPage, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Social_Twitter, getImage, arginfo_ice_auth_social_twitter_getimage, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Social_Twitter, getImage, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Social_Twitter, authenticate, arginfo_ice_auth_social_twitter_authenticate, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Social_Twitter, authenticate, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Social_Twitter, prepareAuthParams, arginfo_ice_auth_social_twitter_prepareauthparams, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Social_Twitter, prepareAuthParams, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Auth_Social_Twitter, prepareUrlParams, arginfo_ice_auth_social_twitter_prepareurlparams, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
