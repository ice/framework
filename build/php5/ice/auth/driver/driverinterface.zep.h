
extern zend_class_entry *ice_auth_driver_driverinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_DriverInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_driverinterface_getuser, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_driverinterface_hasrole, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_driverinterface_login, 0, 0, 2)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, remember)
	ZEND_ARG_INFO(0, force)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_driverinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Auth_Driver_DriverInterface, getUser, arginfo_ice_auth_driver_driverinterface_getuser)
	PHP_ABSTRACT_ME(Ice_Auth_Driver_DriverInterface, hasRole, arginfo_ice_auth_driver_driverinterface_hasrole)
	PHP_ABSTRACT_ME(Ice_Auth_Driver_DriverInterface, login, arginfo_ice_auth_driver_driverinterface_login)
	PHP_FE_END
};
