
extern zend_class_entry *ice_version_ce;

ZEPHIR_INIT_CLASS(Ice_Version);

PHP_METHOD(Ice_Version, current);
PHP_METHOD(Ice_Version, get);
PHP_METHOD(Ice_Version, id);

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_version_current, 0, 0, IS_NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_version_current, 0, 0, IS_NULL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_version_get, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_version_get, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_version_id, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_version_id, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_version_method_entry) {
	PHP_ME(Ice_Version, current, arginfo_ice_version_current, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Version, get, arginfo_ice_version_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Ice_Version, id, arginfo_ice_version_id, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
