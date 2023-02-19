
extern zend_class_entry *ice_loader_ce;

ZEPHIR_INIT_CLASS(Ice_Loader);

PHP_METHOD(Ice_Loader, __construct);
PHP_METHOD(Ice_Loader, register);
PHP_METHOD(Ice_Loader, addNamespace);
PHP_METHOD(Ice_Loader, loadClass);
PHP_METHOD(Ice_Loader, loadMappedFile);
PHP_METHOD(Ice_Loader, requireFile);
zend_object *zephir_init_properties_Ice_Loader(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_loader___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefixes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, prefixes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_loader_register, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_loader_addnamespace, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, baseDir, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, prepend, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_loader_loadclass, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_loader_loadmappedfile, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, relativeClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_loader_requirefile, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_loader_zephir_init_properties_ice_loader, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_loader_method_entry) {
	PHP_ME(Ice_Loader, __construct, arginfo_ice_loader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Loader, register, arginfo_ice_loader_register, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Loader, register, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Loader, addNamespace, arginfo_ice_loader_addnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Loader, loadClass, arginfo_ice_loader_loadclass, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Loader, loadMappedFile, arginfo_ice_loader_loadmappedfile, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Loader, requireFile, arginfo_ice_loader_requirefile, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
