
extern zend_class_entry *ice_auth_driver_model_roles_users_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Roles_Users);

PHP_METHOD(Ice_Auth_Driver_Model_Roles_Users, initialize);

ZEPHIR_INIT_FUNCS(ice_auth_driver_model_roles_users_method_entry) {
	PHP_ME(Ice_Auth_Driver_Model_Roles_Users, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
