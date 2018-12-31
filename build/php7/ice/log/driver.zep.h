
extern zend_class_entry *ice_log_driver_ce;

ZEPHIR_INIT_CLASS(Ice_Log_Driver);

PHP_METHOD(Ice_Log_Driver, emergency);
PHP_METHOD(Ice_Log_Driver, alert);
PHP_METHOD(Ice_Log_Driver, critical);
PHP_METHOD(Ice_Log_Driver, error);
PHP_METHOD(Ice_Log_Driver, warning);
PHP_METHOD(Ice_Log_Driver, notice);
PHP_METHOD(Ice_Log_Driver, info);
PHP_METHOD(Ice_Log_Driver, debug);
PHP_METHOD(Ice_Log_Driver, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_emergency, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_alert, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_critical, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_error, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_warning, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_notice, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_info, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_debug, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_log_driver_method_entry) {
	PHP_ME(Ice_Log_Driver, emergency, arginfo_ice_log_driver_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Log_Driver, alert, arginfo_ice_log_driver_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Log_Driver, critical, arginfo_ice_log_driver_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Log_Driver, error, arginfo_ice_log_driver_error, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Log_Driver, warning, arginfo_ice_log_driver_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Log_Driver, notice, arginfo_ice_log_driver_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Log_Driver, info, arginfo_ice_log_driver_info, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Log_Driver, debug, arginfo_ice_log_driver_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Log_Driver, log, arginfo_ice_log_driver_log, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_FE_END
};
