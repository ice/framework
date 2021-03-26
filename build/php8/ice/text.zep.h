
extern zend_class_entry *ice_text_ce;

ZEPHIR_INIT_CLASS(Ice_Text);

PHP_METHOD(Ice_Text, random);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_text_random, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_text_method_entry) {
	PHP_ME(Ice_Text, random, arginfo_ice_text_random, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
