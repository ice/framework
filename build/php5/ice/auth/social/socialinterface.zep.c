
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Auth social interface.
 *
 * @package     Ice/Auth
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Social_SocialInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\Auth\\Social, SocialInterface, ice, auth_social_socialinterface, ice_auth_social_socialinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Ice_Auth_Social_SocialInterface, authenticate);

