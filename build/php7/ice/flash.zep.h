
extern zend_class_entry *ice_flash_ce;

ZEPHIR_INIT_CLASS(Ice_Flash);

PHP_METHOD(Ice_Flash, setOptions);
PHP_METHOD(Ice_Flash, __construct);
PHP_METHOD(Ice_Flash, getOption);
PHP_METHOD(Ice_Flash, getMessages);
PHP_METHOD(Ice_Flash, getMessage);
PHP_METHOD(Ice_Flash, message);
PHP_METHOD(Ice_Flash, success);
PHP_METHOD(Ice_Flash, ok);
PHP_METHOD(Ice_Flash, info);
PHP_METHOD(Ice_Flash, notice);
PHP_METHOD(Ice_Flash, warning);
PHP_METHOD(Ice_Flash, alert);
PHP_METHOD(Ice_Flash, danger);
PHP_METHOD(Ice_Flash, error);
zend_object *zephir_init_properties_Ice_Flash(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash_getoption, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_flash_getmessages, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_flash_getmessages, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, remove, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, remove)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_flash_getmessage, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_flash_getmessage, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash_message, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash_success, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash_ok, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash_info, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash_notice, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash_warning, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash_alert, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash_danger, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_flash_error, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_flash_method_entry) {
	PHP_ME(Ice_Flash, setOptions, arginfo_ice_flash_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, __construct, arginfo_ice_flash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Flash, getOption, arginfo_ice_flash_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, getMessages, arginfo_ice_flash_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, getMessage, arginfo_ice_flash_getmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, message, arginfo_ice_flash_message, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, success, arginfo_ice_flash_success, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, ok, arginfo_ice_flash_ok, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, info, arginfo_ice_flash_info, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, notice, arginfo_ice_flash_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, warning, arginfo_ice_flash_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, alert, arginfo_ice_flash_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, danger, arginfo_ice_flash_danger, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Flash, error, arginfo_ice_flash_error, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
