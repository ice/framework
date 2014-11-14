
extern zend_class_entry *ice_auth_driver_model_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model);

PHP_METHOD(Ice_Auth_Driver_Model, autoLogin);
PHP_METHOD(Ice_Auth_Driver_Model, completeLogin);
PHP_METHOD(Ice_Auth_Driver_Model, getUser);
PHP_METHOD(Ice_Auth_Driver_Model, hasRole);
PHP_METHOD(Ice_Auth_Driver_Model, login);
PHP_METHOD(Ice_Auth_Driver_Model, logout);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_completelogin, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_ARRAY_INFO(0, roles, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_getuser, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_hasrole, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Ice\\Auth\\Driver\\Model\\Users, 0)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_login, 0, 0, 2)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, remember)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_logout, 0, 0, 0)
	ZEND_ARG_INFO(0, destroy)
	ZEND_ARG_INFO(0, logoutAll)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_model_method_entry) {
	PHP_ME(Ice_Auth_Driver_Model, autoLogin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model, completeLogin, arginfo_ice_auth_driver_model_completelogin, ZEND_ACC_PROTECTED)
	PHP_ME(Ice_Auth_Driver_Model, getUser, arginfo_ice_auth_driver_model_getuser, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model, hasRole, arginfo_ice_auth_driver_model_hasrole, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model, login, arginfo_ice_auth_driver_model_login, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model, logout, arginfo_ice_auth_driver_model_logout, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
