
extern zend_class_entry *ice_auth_driver_model_users_social_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users_Social);

PHP_METHOD(Ice_Auth_Driver_Model_Users_Social, initialize);
PHP_METHOD(Ice_Auth_Driver_Model_Users_Social, onConstruct);

ZEPHIR_INIT_FUNCS(ice_auth_driver_model_users_social_method_entry) {
	PHP_ME(Ice_Auth_Driver_Model_Users_Social, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model_Users_Social, onConstruct, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
