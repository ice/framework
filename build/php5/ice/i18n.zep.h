
extern zend_class_entry *ice_i18n_ce;

ZEPHIR_INIT_CLASS(Ice_I18n);

PHP_METHOD(Ice_I18n, __construct);
PHP_METHOD(Ice_I18n, fetch);
PHP_METHOD(Ice_I18n, lang);
PHP_METHOD(Ice_I18n, iso);
PHP_METHOD(Ice_I18n, get);
PHP_METHOD(Ice_I18n, load);
PHP_METHOD(Ice_I18n, plural);
PHP_METHOD(Ice_I18n, pluralRules);
PHP_METHOD(Ice_I18n, _);
PHP_METHOD(Ice_I18n, translate);
zend_object_value zephir_init_properties_Ice_I18n(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_lang, 0, 0, 0)
	ZEND_ARG_INFO(0, lang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_iso, 0, 0, 0)
	ZEND_ARG_INFO(0, lang)
	ZEND_ARG_INFO(0, country)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_get, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, form)
	ZEND_ARG_INFO(0, lang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_load, 0, 0, 1)
	ZEND_ARG_INFO(0, lang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_plural, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, count)
	ZEND_ARG_INFO(0, lang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_pluralrules, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n__, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_ARRAY_INFO(0, values, 1)
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_INFO(0, lang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_i18n_translate, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_ARRAY_INFO(0, values, 1)
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_INFO(0, lang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_i18n_method_entry) {
	PHP_ME(Ice_I18n, __construct, arginfo_ice_i18n___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_I18n, fetch, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_I18n, lang, arginfo_ice_i18n_lang, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_I18n, iso, arginfo_ice_i18n_iso, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_I18n, get, arginfo_ice_i18n_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_I18n, load, arginfo_ice_i18n_load, ZEND_ACC_PRIVATE)
	PHP_ME(Ice_I18n, plural, arginfo_ice_i18n_plural, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_I18n, pluralRules, arginfo_ice_i18n_pluralrules, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_I18n, _, arginfo_ice_i18n__, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_I18n, translate, arginfo_ice_i18n_translate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
