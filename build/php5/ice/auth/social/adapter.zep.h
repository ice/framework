
extern zend_class_entry *ice_auth_social_adapter_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Social_Adapter);

PHP_METHOD(Ice_Auth_Social_Adapter, setAccessToken);
PHP_METHOD(Ice_Auth_Social_Adapter, getAccessToken);
PHP_METHOD(Ice_Auth_Social_Adapter, getProvider);
PHP_METHOD(Ice_Auth_Social_Adapter, getResponseType);
PHP_METHOD(Ice_Auth_Social_Adapter, __construct);
PHP_METHOD(Ice_Auth_Social_Adapter, __call);
PHP_METHOD(Ice_Auth_Social_Adapter, has);
PHP_METHOD(Ice_Auth_Social_Adapter, get);
PHP_METHOD(Ice_Auth_Social_Adapter, getAuthUrl);
PHP_METHOD(Ice_Auth_Social_Adapter, getOption);
PHP_METHOD(Ice_Auth_Social_Adapter, call);
zend_object_value zephir_init_properties_Ice_Auth_Social_Adapter(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_adapter_setaccesstoken, 0, 0, 1)
	ZEND_ARG_INFO(0, accessToken)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_adapter___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_adapter___call, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_adapter_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_adapter_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_adapter_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_adapter_call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_INFO(0, parse)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_social_adapter_method_entry) {
	PHP_ME(Ice_Auth_Social_Adapter, setAccessToken, arginfo_ice_auth_social_adapter_setaccesstoken, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social_Adapter, getAccessToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social_Adapter, getProvider, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social_Adapter, getResponseType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social_Adapter, __construct, arginfo_ice_auth_social_adapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Auth_Social_Adapter, __call, arginfo_ice_auth_social_adapter___call, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social_Adapter, has, arginfo_ice_auth_social_adapter_has, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social_Adapter, get, arginfo_ice_auth_social_adapter_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social_Adapter, getAuthUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social_Adapter, getOption, arginfo_ice_auth_social_adapter_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Social_Adapter, call, arginfo_ice_auth_social_adapter_call, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
