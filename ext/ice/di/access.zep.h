
extern zend_class_entry *ice_di_access_ce;

ZEPHIR_INIT_CLASS(Ice_Di_Access);

PHP_METHOD(Ice_Di_Access, __construct);
PHP_METHOD(Ice_Di_Access, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_access___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, di, Ice\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_di_access___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_di_access_method_entry) {
	PHP_ME(Ice_Di_Access, __construct, arginfo_ice_di_access___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Di_Access, __get, arginfo_ice_di_access___get, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
