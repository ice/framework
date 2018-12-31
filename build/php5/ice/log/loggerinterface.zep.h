
extern zend_class_entry *ice_log_loggerinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Log_LoggerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_loggerinterface_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_loggerinterface_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_loggerinterface_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_loggerinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_loggerinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_loggerinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_loggerinterface_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_loggerinterface_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_loggerinterface_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_log_loggerinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Log_LoggerInterface, emergency, arginfo_ice_log_loggerinterface_emergency)
	PHP_ABSTRACT_ME(Ice_Log_LoggerInterface, alert, arginfo_ice_log_loggerinterface_alert)
	PHP_ABSTRACT_ME(Ice_Log_LoggerInterface, critical, arginfo_ice_log_loggerinterface_critical)
	PHP_ABSTRACT_ME(Ice_Log_LoggerInterface, error, arginfo_ice_log_loggerinterface_error)
	PHP_ABSTRACT_ME(Ice_Log_LoggerInterface, warning, arginfo_ice_log_loggerinterface_warning)
	PHP_ABSTRACT_ME(Ice_Log_LoggerInterface, notice, arginfo_ice_log_loggerinterface_notice)
	PHP_ABSTRACT_ME(Ice_Log_LoggerInterface, info, arginfo_ice_log_loggerinterface_info)
	PHP_ABSTRACT_ME(Ice_Log_LoggerInterface, debug, arginfo_ice_log_loggerinterface_debug)
	PHP_ABSTRACT_ME(Ice_Log_LoggerInterface, log, arginfo_ice_log_loggerinterface_log)
	PHP_FE_END
};
