
extern zend_class_entry *ice_auth_social_socialinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Social_SocialInterface);

ZEPHIR_INIT_FUNCS(ice_auth_social_socialinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Auth_Social_SocialInterface, authenticate, NULL)
	PHP_FE_END
};
