
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Plural rules for the following locales and languages:
 * 
 * Locales: az bm bo dz fa id ig ii hu ja jv ka kde kea km kn ko lo ms my sah ses sg th to tr vi wo yo zh
 * 
 * These are known to have no plurals, there are no rules:
 *  other → everything
 * 
 * Reference CLDR Version 21 (2012-03-01 03:27:30 GMT)
 * @see  http://unicode.org/repos/cldr-tmp/trunk/diff/supplemental/language_plural_rules.html
 * @see  http://unicode.org/repos/cldr/trunk/common/supplemental/plurals.xml
 * 
 * @package     Ice/I18n
 * @category    Plural rules
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_I18n_Plural_None) {

	ZEPHIR_REGISTER_CLASS(Ice\\I18n\\Plural, None, ice, i18n_plural_none, ice_i18n_plural_none_method_entry, 0);

	zend_class_implements(ice_i18n_plural_none_ce TSRMLS_CC, 1, ice_i18n_plural_pluralinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_I18n_Plural_None, getCategory) {

	zval *count_param = NULL;
	zend_long count;
	zval *this_ptr = getThis();


	zephir_fetch_params(0, 1, 0, &count_param);

	count = zephir_get_intval(count_param);


	RETURN_STRING("other");

}

