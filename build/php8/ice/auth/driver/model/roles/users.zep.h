
extern zend_class_entry *ice_auth_driver_model_roles_users_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Roles_Users);

PHP_METHOD(Ice_Auth_Driver_Model_Roles_Users, initialize);
zend_object *zephir_init_properties_Ice_Auth_Driver_Model_Roles_Users(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_roles_users_initialize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_roles_users_zephir_init_properties_ice_auth_driver_model_roles_users, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_model_roles_users_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Driver_Model_Roles_Users, initialize, arginfo_ice_auth_driver_model_roles_users_initialize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Driver_Model_Roles_Users, initialize, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
