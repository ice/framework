
extern zend_class_entry *ice_session_ce;

ZEPHIR_INIT_CLASS(Ice_Session);

PHP_METHOD(Ice_Session, __construct);
PHP_METHOD(Ice_Session, start);
PHP_METHOD(Ice_Session, isStarted);
PHP_METHOD(Ice_Session, getId);
PHP_METHOD(Ice_Session, regenerate);
PHP_METHOD(Ice_Session, destroy);
PHP_METHOD(Ice_Session, has);
PHP_METHOD(Ice_Session, get);
PHP_METHOD(Ice_Session, set);
PHP_METHOD(Ice_Session, remove);
PHP_METHOD(Ice_Session, getData);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_start, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_start, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_isstarted, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_isstarted, 0, 0, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, autoStart, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, autoStart)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_getid, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_getid, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_regenerate, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_regenerate, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_destroy, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_destroy, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_session_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, required, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, required)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_session_set, 0, 2, Ice\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_set, 0, 2, IS_OBJECT, "Ice\\self", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_ice_session_remove, 0, 1, Ice\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_remove, 0, 1, IS_OBJECT, "Ice\\self", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_getdata, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_session_getdata, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_session_method_entry) {
	PHP_ME(Ice_Session, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Session, start, arginfo_ice_session_start, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, isStarted, arginfo_ice_session_isstarted, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, getId, arginfo_ice_session_getid, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, regenerate, arginfo_ice_session_regenerate, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, destroy, arginfo_ice_session_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, has, arginfo_ice_session_has, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, get, arginfo_ice_session_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, set, arginfo_ice_session_set, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, remove, arginfo_ice_session_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, getData, arginfo_ice_session_getdata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
