
extern zend_class_entry *ice_auth_driver_model_users_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users);

PHP_METHOD(Ice_Auth_Driver_Model_Users, initialize);
PHP_METHOD(Ice_Auth_Driver_Model_Users, completeLogin);
PHP_METHOD(Ice_Auth_Driver_Model_Users, getRole);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_users_getrole, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_model_users_method_entry) {
	PHP_ME(Ice_Auth_Driver_Model_Users, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model_Users, completeLogin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model_Users, getRole, arginfo_ice_auth_driver_model_users_getrole, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
