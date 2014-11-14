
extern zend_class_entry *ice_mvc_controller_ce;

ZEPHIR_INIT_CLASS(Ice_Mvc_Controller);

PHP_METHOD(Ice_Mvc_Controller, __construct);

ZEPHIR_INIT_FUNCS(ice_mvc_controller_method_entry) {
	PHP_ME(Ice_Mvc_Controller, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
  PHP_FE_END
};
