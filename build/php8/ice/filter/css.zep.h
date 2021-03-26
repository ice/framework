
extern zend_class_entry *ice_filter_css_ce;

ZEPHIR_INIT_CLASS(Ice_Filter_Css);

PHP_METHOD(Ice_Filter_Css, sanitize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_filter_css_sanitize, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, css, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_filter_css_method_entry) {
	PHP_ME(Ice_Filter_Css, sanitize, arginfo_ice_filter_css_sanitize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
