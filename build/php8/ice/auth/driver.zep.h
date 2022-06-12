
extern zend_class_entry *ice_auth_driver_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver);

PHP_METHOD(Ice_Auth_Driver, __construct);
PHP_METHOD(Ice_Auth_Driver, checkHash);
PHP_METHOD(Ice_Auth_Driver, completeLogin);
PHP_METHOD(Ice_Auth_Driver, getOption);
PHP_METHOD(Ice_Auth_Driver, setOption);
PHP_METHOD(Ice_Auth_Driver, getUser);
PHP_METHOD(Ice_Auth_Driver, hash);
PHP_METHOD(Ice_Auth_Driver, loggedIn);
PHP_METHOD(Ice_Auth_Driver, logout);
zend_object *zephir_init_properties_Ice_Auth_Driver(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_checkhash, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, password, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, hash, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_completelogin, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, roles, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, roles, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_getoption, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_setoption, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_getuser, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_hash, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, password, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_loggedin, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, role, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_logout, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, destroy, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, logoutAll, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_zephir_init_properties_ice_auth_driver, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_method_entry) {
	PHP_ME(Ice_Auth_Driver, __construct, arginfo_ice_auth_driver___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Auth_Driver, checkHash, arginfo_ice_auth_driver_checkhash, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver, completeLogin, arginfo_ice_auth_driver_completelogin, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Auth_Driver, getOption, arginfo_ice_auth_driver_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver, setOption, arginfo_ice_auth_driver_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver, getUser, arginfo_ice_auth_driver_getuser, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver, hash, arginfo_ice_auth_driver_hash, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver, loggedIn, arginfo_ice_auth_driver_loggedin, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver, logout, arginfo_ice_auth_driver_logout, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
