
extern zend_class_entry *ice_auth_driver_file_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_File);

PHP_METHOD(Ice_Auth_Driver_File, setUsers);
PHP_METHOD(Ice_Auth_Driver_File, getUser);
PHP_METHOD(Ice_Auth_Driver_File, hasRole);
PHP_METHOD(Ice_Auth_Driver_File, login);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_file_setusers, 0, 0, 1)
	ZEND_ARG_INFO(0, users)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_file_getuser, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_file_hasrole, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_file_hasrole, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, user)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, role, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, role)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_file_login, 0, 2, _IS_BOOL, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_file_login, 0, 2, _IS_BOOL, NULL, 1)
#endif
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

ZEPHIR_INIT_FUNCS(ice_auth_driver_file_method_entry) {
	PHP_ME(Ice_Auth_Driver_File, setUsers, arginfo_ice_auth_driver_file_setusers, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_File, getUser, arginfo_ice_auth_driver_file_getuser, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_File, hasRole, arginfo_ice_auth_driver_file_hasrole, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_File, login, arginfo_ice_auth_driver_file_login, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
