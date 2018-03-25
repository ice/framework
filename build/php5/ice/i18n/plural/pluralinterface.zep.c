
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Interface for Plural rules
 *
 * @package     Ice/I18n
 * @category    Interface
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_I18n_Plural_PluralInterface) {

	ZEPHIR_REGISTER_INTERFACE(Ice\\I18n\\Plural, PluralInterface, ice, i18n_plural_pluralinterface, ice_i18n_plural_pluralinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Ice_I18n_Plural_PluralInterface, getCategory);

