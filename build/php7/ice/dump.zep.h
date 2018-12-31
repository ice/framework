
extern zend_class_entry *ice_dump_ce;

ZEPHIR_INIT_CLASS(Ice_Dump);

PHP_METHOD(Ice_Dump, getDetailed);
PHP_METHOD(Ice_Dump, setDetailed);
PHP_METHOD(Ice_Dump, getPlain);
PHP_METHOD(Ice_Dump, setPlain);
PHP_METHOD(Ice_Dump, getSkip);
PHP_METHOD(Ice_Dump, setSkip);
PHP_METHOD(Ice_Dump, __construct);
PHP_METHOD(Ice_Dump, all);
PHP_METHOD(Ice_Dump, getStyle);
PHP_METHOD(Ice_Dump, setStyles);
PHP_METHOD(Ice_Dump, one);
PHP_METHOD(Ice_Dump, output);
PHP_METHOD(Ice_Dump, variable);
PHP_METHOD(Ice_Dump, vars);
PHP_METHOD(Ice_Dump, source);
zend_object *zephir_init_properties_Ice_Dump(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dump_setdetailed, 0, 0, 1)
	ZEND_ARG_INFO(0, detailed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dump_setplain, 0, 0, 1)
	ZEND_ARG_INFO(0, plain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dump_setskip, 0, 0, 1)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dump___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, detailed, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, detailed)
#endif
	ZEND_ARG_INFO(0, styles)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_all, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_all, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_getstyle, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_getstyle, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_setstyles, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_setstyles, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, styles, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_one, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_one, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, variable)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_output, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_output, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, tab)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_variable, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_variable, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, variable)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_vars, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_dump_vars, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_dump_source, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filename)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, line, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, line)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, padding, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, padding)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_dump_method_entry) {
	PHP_ME(Ice_Dump, getDetailed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dump, setDetailed, arginfo_ice_dump_setdetailed, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dump, getPlain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dump, setPlain, arginfo_ice_dump_setplain, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dump, getSkip, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dump, setSkip, arginfo_ice_dump_setskip, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dump, __construct, arginfo_ice_dump___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Dump, all, arginfo_ice_dump_all, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dump, getStyle, arginfo_ice_dump_getstyle, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Dump, setStyles, arginfo_ice_dump_setstyles, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dump, one, arginfo_ice_dump_one, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dump, output, arginfo_ice_dump_output, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Dump, variable, arginfo_ice_dump_variable, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dump, vars, arginfo_ice_dump_vars, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Dump, source, arginfo_ice_dump_source, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
