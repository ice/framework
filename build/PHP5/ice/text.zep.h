
extern zend_class_entry *ice_text_ce;

ZEPHIR_INIT_CLASS(Ice_Text);

PHP_METHOD(Ice_Text, random);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_text_random, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_text_method_entry) {
	PHP_ME(Ice_Text, random, arginfo_ice_text_random, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
