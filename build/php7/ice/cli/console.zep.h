
extern zend_class_entry *ice_cli_console_ce;

ZEPHIR_INIT_CLASS(Ice_Cli_Console);

PHP_METHOD(Ice_Cli_Console, getModules);
PHP_METHOD(Ice_Cli_Console, setModules);
PHP_METHOD(Ice_Cli_Console, __construct);
PHP_METHOD(Ice_Cli_Console, addModule);
PHP_METHOD(Ice_Cli_Console, handle);
PHP_METHOD(Ice_Cli_Console, color);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_console_setmodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_console___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, di, Ice\\Di, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_console_addmodule, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_console_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_console_color, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, color, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, color)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, decoration, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, decoration)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, bgColor, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, bgColor)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_cli_console_method_entry) {
	PHP_ME(Ice_Cli_Console, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Console, setModules, arginfo_ice_cli_console_setmodules, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Console, __construct, arginfo_ice_cli_console___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Cli_Console, addModule, arginfo_ice_cli_console_addmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Console, handle, arginfo_ice_cli_console_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Console, color, arginfo_ice_cli_console_color, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
