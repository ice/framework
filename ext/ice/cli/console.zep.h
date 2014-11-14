
extern zend_class_entry *ice_cli_console_ce;

ZEPHIR_INIT_CLASS(Ice_Cli_Console);

PHP_METHOD(Ice_Cli_Console, getModules);
PHP_METHOD(Ice_Cli_Console, setModules);
PHP_METHOD(Ice_Cli_Console, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_console_setmodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_cli_console_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_cli_console_method_entry) {
	PHP_ME(Ice_Cli_Console, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Console, setModules, arginfo_ice_cli_console_setmodules, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Cli_Console, handle, arginfo_ice_cli_console_handle, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
