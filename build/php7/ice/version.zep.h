
extern zend_class_entry *ice_version_ce;

ZEPHIR_INIT_CLASS(Ice_Version);

PHP_METHOD(Ice_Version, current);
PHP_METHOD(Ice_Version, get);
PHP_METHOD(Ice_Version, id);

ZEPHIR_INIT_FUNCS(ice_version_method_entry) {
	PHP_ME(Ice_Version, current, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Version, get, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Version, id, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
