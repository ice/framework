
extern zend_class_entry *ice_i18n_plural_balkan_ce;

ZEPHIR_INIT_CLASS(Ice_I18n_Plural_Balkan);

PHP_METHOD(Ice_I18n_Plural_Balkan, getCategory);
PHP_METHOD(Ice_I18n_Plural_Balkan, isInt);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_i18n_plural_balkan_getcategory, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_i18n_plural_balkan_getcategory, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, count)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_plural_balkan_isint, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_i18n_plural_balkan_method_entry) {
	PHP_ME(Ice_I18n_Plural_Balkan, getCategory, arginfo_ice_i18n_plural_balkan_getcategory, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_I18n_Plural_Balkan, isInt, arginfo_ice_i18n_plural_balkan_isint, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
