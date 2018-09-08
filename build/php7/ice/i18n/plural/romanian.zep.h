
extern zend_class_entry *ice_i18n_plural_romanian_ce;

ZEPHIR_INIT_CLASS(Ice_I18n_Plural_Romanian);

PHP_METHOD(Ice_I18n_Plural_Romanian, getCategory);
PHP_METHOD(Ice_I18n_Plural_Romanian, isInt);

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_i18n_plural_romanian_getcategory, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_i18n_plural_romanian_getcategory, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_plural_romanian_isint, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_i18n_plural_romanian_method_entry) {
	PHP_ME(Ice_I18n_Plural_Romanian, getCategory, arginfo_ice_i18n_plural_romanian_getcategory, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_I18n_Plural_Romanian, isInt, arginfo_ice_i18n_plural_romanian_isint, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
