
extern zend_class_entry *ice_log_driver_file_ce;

ZEPHIR_INIT_CLASS(Ice_Log_Driver_File);

PHP_METHOD(Ice_Log_Driver_File, __construct);
PHP_METHOD(Ice_Log_Driver_File, log);
PHP_METHOD(Ice_Log_Driver_File, interpolate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_file_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_log_driver_file_interpolate, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_log_driver_file_method_entry) {
	PHP_ME(Ice_Log_Driver_File, __construct, arginfo_ice_log_driver_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Log_Driver_File, log, arginfo_ice_log_driver_file_log, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Log_Driver_File, interpolate, arginfo_ice_log_driver_file_interpolate, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
