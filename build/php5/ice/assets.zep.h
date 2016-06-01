
extern zend_class_entry *ice_assets_ce;

ZEPHIR_INIT_CLASS(Ice_Assets);

PHP_METHOD(Ice_Assets, setCollections);
PHP_METHOD(Ice_Assets, getCollections);
PHP_METHOD(Ice_Assets, setOptions);
PHP_METHOD(Ice_Assets, __construct);
PHP_METHOD(Ice_Assets, getOption);
PHP_METHOD(Ice_Assets, add);
PHP_METHOD(Ice_Assets, addCss);
PHP_METHOD(Ice_Assets, addJs);
PHP_METHOD(Ice_Assets, addToCollection);
PHP_METHOD(Ice_Assets, getCss);
PHP_METHOD(Ice_Assets, getJs);
PHP_METHOD(Ice_Assets, get);
PHP_METHOD(Ice_Assets, minify);
PHP_METHOD(Ice_Assets, prepare);
zend_object_value zephir_init_properties_Ice_Assets(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_assets_setcollections, 0, 0, 1)
	ZEND_ARG_INFO(0, collections)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_assets_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_assets_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_assets_add, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, version)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, minify)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_assets_addcss, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
	ZEND_ARG_INFO(0, version)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, minify)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_assets_addjs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
	ZEND_ARG_INFO(0, version)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, minify)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_assets_addtocollection, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_assets_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_assets_minify, 0, 0, 2)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_assets_prepare, 0, 0, 3)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, minify)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_assets_method_entry) {
	PHP_ME(Ice_Assets, setCollections, arginfo_ice_assets_setcollections, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Assets, getCollections, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Assets, setOptions, arginfo_ice_assets_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Assets, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Assets, getOption, arginfo_ice_assets_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Assets, add, arginfo_ice_assets_add, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Assets, addCss, arginfo_ice_assets_addcss, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Assets, addJs, arginfo_ice_assets_addjs, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Assets, addToCollection, arginfo_ice_assets_addtocollection, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Assets, getCss, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Assets, getJs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Assets, get, arginfo_ice_assets_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Assets, minify, arginfo_ice_assets_minify, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Assets, prepare, arginfo_ice_assets_prepare, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
