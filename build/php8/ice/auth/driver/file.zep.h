
extern zend_class_entry *ice_auth_driver_file_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_File);

PHP_METHOD(Ice_Auth_Driver_File, setUsers);
PHP_METHOD(Ice_Auth_Driver_File, __construct);
PHP_METHOD(Ice_Auth_Driver_File, getUser);
PHP_METHOD(Ice_Auth_Driver_File, hasRole);
PHP_METHOD(Ice_Auth_Driver_File, login);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_file_setusers, 0, 0, 1)
	ZEND_ARG_INFO(0, users)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_file___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_file_getuser, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_file_hasrole, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_TYPE_INFO(0, role, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_file_login, 0, 2, _IS_BOOL, 1)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_TYPE_INFO(0, password, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, force, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_file_method_entry) {
	PHP_ME(Ice_Auth_Driver_File, setUsers, arginfo_ice_auth_driver_file_setusers, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_File, __construct, arginfo_ice_auth_driver_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Ice_Auth_Driver_File, getUser, arginfo_ice_auth_driver_file_getuser, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_File, hasRole, arginfo_ice_auth_driver_file_hasrole, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_File, login, arginfo_ice_auth_driver_file_login, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
