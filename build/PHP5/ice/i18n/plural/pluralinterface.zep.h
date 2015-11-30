
extern zend_class_entry *ice_i18n_plural_pluralinterface_ce;

ZEPHIR_INIT_CLASS(Ice_I18n_Plural_PluralInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_plural_pluralinterface_getcategory, 0, 0, 1)
	ZEND_ARG_INFO(0, count)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_i18n_plural_pluralinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_I18n_Plural_PluralInterface, getCategory, arginfo_ice_i18n_plural_pluralinterface_getcategory)
	PHP_FE_END
};
