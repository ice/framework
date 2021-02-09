
extern zend_class_entry *ice_auth_social_socialinterface_ce;

ZEPHIR_INIT_CLASS(Ice_Auth_Social_SocialInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_ice_auth_social_socialinterface_authenticate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_auth_social_socialinterface_method_entry) {
	PHP_ABSTRACT_ME(Ice_Auth_Social_SocialInterface, authenticate, arginfo_ice_auth_social_socialinterface_authenticate)
	PHP_FE_END
};
