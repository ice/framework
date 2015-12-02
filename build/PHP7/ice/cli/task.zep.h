
extern zend_class_entry *ice_cli_task_ce;

ZEPHIR_INIT_CLASS(Ice_Cli_Task);

PHP_METHOD(Ice_Cli_Task, __construct);

ZEPHIR_INIT_FUNCS(ice_cli_task_method_entry) {
	PHP_ME(Ice_Cli_Task, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_FE_END
};
