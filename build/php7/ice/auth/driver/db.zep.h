
extern zend_class_entry *ice_auth_driver_db_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Db);

PHP_METHOD(Ice_Auth_Driver_Db, autoLogin);
PHP_METHOD(Ice_Auth_Driver_Db, completeLogin);
PHP_METHOD(Ice_Auth_Driver_Db, getUser);
PHP_METHOD(Ice_Auth_Driver_Db, hasRole);
PHP_METHOD(Ice_Auth_Driver_Db, login);
PHP_METHOD(Ice_Auth_Driver_Db, loginBy);
PHP_METHOD(Ice_Auth_Driver_Db, logout);
PHP_METHOD(Ice_Auth_Driver_Db, refreshUser);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_db_completelogin, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_ARRAY_INFO(0, roles, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_db_getuser, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_db_hasrole, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_db_hasrole, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, user)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, role, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, role)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_db_login, 0, 2, _IS_BOOL, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_db_login, 0, 2, _IS_BOOL, NULL, 1)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_db_loginby, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, social, Ice\\Auth\\Social, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, remember)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_db_logout, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_db_logout, 0, 0, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, destroy, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, destroy)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, logoutAll, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, logoutAll)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_db_method_entry) {
	PHP_ME(Ice_Auth_Driver_Db, autoLogin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Db, completeLogin, arginfo_ice_auth_driver_db_completelogin, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Auth_Driver_Db, getUser, arginfo_ice_auth_driver_db_getuser, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Db, hasRole, arginfo_ice_auth_driver_db_hasrole, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Db, login, arginfo_ice_auth_driver_db_login, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Db, loginBy, arginfo_ice_auth_driver_db_loginby, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Db, logout, arginfo_ice_auth_driver_db_logout, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Db, refreshUser, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
