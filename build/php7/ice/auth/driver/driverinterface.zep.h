
extern zend_class_entry *ice_auth_driver_driverinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_DriverInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_driverinterface_getuser, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_driverinterface_hasrole, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, role, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, role)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_driverinterface_login, 0, 0, 2)
	ZEND_ARG_INFO(0, username)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, password, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, password)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, remember)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, force, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, force)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_driverinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Auth_Driver_DriverInterface, getUser, arginfo_ice_auth_driver_driverinterface_getuser)
	PHP_ABSTRACT_ME(Ice_Auth_Driver_DriverInterface, hasRole, arginfo_ice_auth_driver_driverinterface_hasrole)
	PHP_ABSTRACT_ME(Ice_Auth_Driver_DriverInterface, login, arginfo_ice_auth_driver_driverinterface_login)
	PHP_FE_END
};
