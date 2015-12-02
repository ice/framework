
extern zend_class_entry *ice_i18n_plural_one_ce;

ZEPHIR_INIT_CLASS(Ice_I18n_Plural_One);

PHP_METHOD(Ice_I18n_Plural_One, getCategory);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_plural_one_getcategory, 0, 0, 1)
	ZEND_ARG_INFO(0, count)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_i18n_plural_one_method_entry) {
	PHP_ME(Ice_I18n_Plural_One, getCategory, arginfo_ice_i18n_plural_one_getcategory, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
