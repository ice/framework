
extern zend_class_entry *ice_auth_social_google_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Social_Google);

PHP_METHOD(Ice_Auth_Social_Google, __construct);
PHP_METHOD(Ice_Auth_Social_Google, getBirthday);
PHP_METHOD(Ice_Auth_Social_Google, authenticate);
PHP_METHOD(Ice_Auth_Social_Google, prepareAuthParams);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_google___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_social_google_method_entry) {
	PHP_ME(Ice_Auth_Social_Google, __construct, arginfo_ice_auth_social_google___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Auth_Social_Google, getBirthday, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social_Google, authenticate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social_Google, prepareAuthParams, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
