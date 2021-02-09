
extern zend_class_entry *ice_filter_js_ce;

ZEPHIR_INIT_CLASS(Ice_Filter_Js);

PHP_METHOD(Ice_Filter_Js, getOutput);
PHP_METHOD(Ice_Filter_Js, sanitize);
PHP_METHOD(Ice_Filter_Js, action);
PHP_METHOD(Ice_Filter_Js, get);
PHP_METHOD(Ice_Filter_Js, isAlphaNum);
PHP_METHOD(Ice_Filter_Js, min);
PHP_METHOD(Ice_Filter_Js, next);
PHP_METHOD(Ice_Filter_Js, peek);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_filter_js_getoutput, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_filter_js_sanitize, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, js, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, js)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_filter_js_action, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, command, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, command)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_filter_js_get, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_filter_js_isalphanum, 0, 0, 1)
	ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_filter_js_min, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_filter_js_next, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_filter_js_peek, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_filter_js_method_entry) {
	PHP_ME(Ice_Filter_Js, getOutput, arginfo_ice_filter_js_getoutput, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Filter_Js, sanitize, arginfo_ice_filter_js_sanitize, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Filter_Js, action, arginfo_ice_filter_js_action, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Filter_Js, get, arginfo_ice_filter_js_get, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Filter_Js, isAlphaNum, arginfo_ice_filter_js_isalphanum, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Filter_Js, min, arginfo_ice_filter_js_min, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Filter_Js, next, arginfo_ice_filter_js_next, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Filter_Js, peek, arginfo_ice_filter_js_peek, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
