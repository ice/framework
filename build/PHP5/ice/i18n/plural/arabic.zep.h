
extern zend_class_entry *ice_i18n_plural_arabic_ce;

ZEPHIR_INIT_CLASS(Ice_I18n_Plural_Arabic);

PHP_METHOD(Ice_I18n_Plural_Arabic, getCategory);
PHP_METHOD(Ice_I18n_Plural_Arabic, isInt);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_plural_arabic_getcategory, 0, 0, 1)
	ZEND_ARG_INFO(0, count)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_plural_arabic_isint, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_i18n_plural_arabic_method_entry) {
	PHP_ME(Ice_I18n_Plural_Arabic, getCategory, arginfo_ice_i18n_plural_arabic_getcategory, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_I18n_Plural_Arabic, isInt, arginfo_ice_i18n_plural_arabic_isint, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
