
extern zend_class_entry *ice_loader_ce;

ZEPHIR_INIT_CLASS(Ice_Loader);

PHP_METHOD(Ice_Loader, register);
PHP_METHOD(Ice_Loader, addNamespace);
PHP_METHOD(Ice_Loader, loadClass);
PHP_METHOD(Ice_Loader, loadMappedFile);
PHP_METHOD(Ice_Loader, requireFile);
zend_object *zephir_init_properties_Ice_Loader(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_loader_addnamespace, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, baseDir, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, baseDir)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prepend, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, prepend)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_loader_loadclass, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_loader_loadmappedfile, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, relativeClass, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, relativeClass)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_loader_requirefile, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, file)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_loader_method_entry) {
	PHP_ME(Ice_Loader, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Loader, addNamespace, arginfo_ice_loader_addnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Loader, loadClass, arginfo_ice_loader_loadclass, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Loader, loadMappedFile, arginfo_ice_loader_loadmappedfile, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Loader, requireFile, arginfo_ice_loader_requirefile, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
