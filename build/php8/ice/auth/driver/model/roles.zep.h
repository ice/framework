
extern zend_class_entry *ice_auth_driver_model_roles_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Roles);

PHP_METHOD(Ice_Auth_Driver_Model_Roles, initialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_roles_initialize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_model_roles_method_entry) {
	PHP_ME(Ice_Auth_Driver_Model_Roles, initialize, arginfo_ice_auth_driver_model_roles_initialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
