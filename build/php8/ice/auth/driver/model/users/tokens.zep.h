
extern zend_class_entry *ice_auth_driver_model_users_tokens_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users_Tokens);

PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, initialize);
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, create);
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, deleteExpired);
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, update);
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, generate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_users_tokens_initialize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_users_tokens_create, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_OBJ_INFO(0, extra, Ice\\Validation, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_users_tokens_deleteexpired, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_driver_model_users_tokens_update, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_OBJ_INFO(0, extra, Ice\\Validation, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_auth_driver_model_users_tokens_generate, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_driver_model_users_tokens_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Driver_Model_Users_Tokens, initialize, arginfo_ice_auth_driver_model_users_tokens_initialize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Driver_Model_Users_Tokens, initialize, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Auth_Driver_Model_Users_Tokens, create, arginfo_ice_auth_driver_model_users_tokens_create, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Ice_Auth_Driver_Model_Users_Tokens, deleteExpired, arginfo_ice_auth_driver_model_users_tokens_deleteexpired, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Ice_Auth_Driver_Model_Users_Tokens, deleteExpired, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Ice_Auth_Driver_Model_Users_Tokens, update, arginfo_ice_auth_driver_model_users_tokens_update, ZEND_ACC_PUBLIC)
	PHP_ME(Ice_Auth_Driver_Model_Users_Tokens, generate, arginfo_ice_auth_driver_model_users_tokens_generate, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
