
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
zend_object_value zephir_init_properties_Ice_Auth_Driver(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_checkhash, 0, 0, 2)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, hash)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_completelogin, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_ARRAY_INFO(0, roles, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_getuser, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_hash, 0, 0, 1)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_loggedin, 0, 0, 0)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_logout, 0, 0, 0)
	ZEND_ARG_INFO(0, destroy)
	ZEND_ARG_INFO(0, logoutAll)
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
