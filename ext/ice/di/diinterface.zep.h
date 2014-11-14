
extern zend_class_entry *ice_di_diinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Di_DiInterface);

ZEPHIR_INIT_FUNCS(ice_di_diinterface_method_entry) {
	ZEND_FENTRY(fetch, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
