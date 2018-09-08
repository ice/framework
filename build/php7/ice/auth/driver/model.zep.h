
extern zend_class_entry *ice_auth_driver_model_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model);

PHP_METHOD(Ice_Auth_Driver_Model, autoLogin);
PHP_METHOD(Ice_Auth_Driver_Model, completeLogin);
PHP_METHOD(Ice_Auth_Driver_Model, getUser);
PHP_METHOD(Ice_Auth_Driver_Model, hasRole);
PHP_METHOD(Ice_Auth_Driver_Model, login);
PHP_METHOD(Ice_Auth_Driver_Model, loginBy);
PHP_METHOD(Ice_Auth_Driver_Model, logout);
PHP_METHOD(Ice_Auth_Driver_Model, refreshUser);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_completelogin, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_ARRAY_INFO(0, roles, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_getuser, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_model_hasrole, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_model_hasrole, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_TYPE_INFO(0, role, IS_STRING, 1)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_model_login, 0, 2, _IS_BOOL, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_model_login, 0, 2, _IS_BOOL, NULL, 1)
#endif
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_TYPE_INFO(0, password, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 1)
	ZEND_ARG_TYPE_INFO(0, force, _IS_BOOL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_loginby, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, social, Ice\\Auth\\Social, 0)
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 1)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_model_logout, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_model_logout, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, destroy, _IS_BOOL, 1)
	ZEND_ARG_TYPE_INFO(0, logoutAll, _IS_BOOL, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_model_method_entry) {
	PHP_ME(Ice_Auth_Driver_Model, autoLogin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model, completeLogin, arginfo_ice_auth_driver_model_completelogin, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Auth_Driver_Model, getUser, arginfo_ice_auth_driver_model_getuser, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model, hasRole, arginfo_ice_auth_driver_model_hasrole, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model, login, arginfo_ice_auth_driver_model_login, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model, loginBy, arginfo_ice_auth_driver_model_loginby, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model, logout, arginfo_ice_auth_driver_model_logout, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model, refreshUser, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
