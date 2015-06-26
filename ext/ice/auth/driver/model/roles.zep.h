
extern zend_class_entry *ice_auth_driver_model_roles_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Roles);

PHP_METHOD(Ice_Auth_Driver_Model_Roles, initialize);
static zend_object_value zephir_init_properties(zend_class_entry *class_type TSRMLS_DC);

ZEPHIR_INIT_FUNCS(ice_auth_driver_model_roles_method_entry) {
	PHP_ME(Ice_Auth_Driver_Model_Roles, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
