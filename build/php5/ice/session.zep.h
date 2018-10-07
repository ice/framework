
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_session_isstarted, 0, 0, 0)
	ZEND_ARG_INFO(0, autoStart)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_session_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_session_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, required)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_session_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_session_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_session_method_entry) {
	PHP_ME(Ice_Session, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Session, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, isStarted, arginfo_ice_session_isstarted, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, regenerate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, destroy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, has, arginfo_ice_session_has, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, get, arginfo_ice_session_get, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, set, arginfo_ice_session_set, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, remove, arginfo_ice_session_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Session, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
