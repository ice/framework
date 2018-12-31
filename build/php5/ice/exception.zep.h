
extern zend_class_entry *ice_exception_ce;

ZEPHIR_INIT_CLASS(Ice_Exception);

PHP_METHOD(Ice_Exception, __construct);
PHP_METHOD(Ice_Exception, getFullTraceAsString);
PHP_METHOD(Ice_Exception, errorHandler);
PHP_METHOD(Ice_Exception, handler);
PHP_METHOD(Ice_Exception, shutdownHandler);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_exception___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, previous)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_exception_getfulltraceasstring, 0, 0, 1)
	ZEND_ARG_INFO(0, e)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_exception_errorhandler, 0, 0, 2)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_exception_handler, 0, 0, 1)
	ZEND_ARG_INFO(0, e)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_exception_method_entry) {
	PHP_ME(Ice_Exception, __construct, arginfo_ice_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Exception, getFullTraceAsString, arginfo_ice_exception_getfulltraceasstring, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Exception, errorHandler, arginfo_ice_exception_errorhandler, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Exception, handler, arginfo_ice_exception_handler, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Exception, shutdownHandler, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
