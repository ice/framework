
extern zend_class_entry *ice_di_access_ce;

ZEPHIR_INIT_CLASS(Ice_Di_Access);

PHP_METHOD(Ice_Di_Access, __get);
PHP_METHOD(Ice_Di_Access, __set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_access___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_access___set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_di_access_method_entry) {
	PHP_ME(Ice_Di_Access, __get, arginfo_ice_di_access___get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Di_Access, __set, arginfo_ice_di_access___set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
