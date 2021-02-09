
extern zend_class_entry *ice_auth_driver_model_users_social_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users_Social);

PHP_METHOD(Ice_Auth_Driver_Model_Users_Social, initialize);
PHP_METHOD(Ice_Auth_Driver_Model_Users_Social, onConstruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_users_social_initialize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_users_social_onconstruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_model_users_social_method_entry) {
	PHP_ME(Ice_Auth_Driver_Model_Users_Social, initialize, arginfo_ice_auth_driver_model_users_social_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model_Users_Social, onConstruct, arginfo_ice_auth_driver_model_users_social_onconstruct, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
