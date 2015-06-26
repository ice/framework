
extern zend_class_entry *ice_cli_dispatcher_ce;

ZEPHIR_INIT_CLASS(Ice_Cli_Dispatcher);

static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC);

ZEPHIR_INIT_FUNCS(ice_cli_dispatcher_method_entry) {
	PHP_FE_END
};
