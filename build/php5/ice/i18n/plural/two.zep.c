
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
 * Locales: iu kw naq se sma smi smj smn sms
 * 
 * Rules:
 *  one → n is 1;
 *  two → n is 2;
 *  other → everything else
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
ZEPHIR_INIT_CLASS(Ice_I18n_Plural_Two) {

	ZEPHIR_REGISTER_CLASS(Ice\\I18n\\Plural, Two, ice, i18n_plural_two, ice_i18n_plural_two_method_entry, 0);

	zend_class_implements(ice_i18n_plural_two_ce TSRMLS_CC, 1, ice_i18n_plural_pluralinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_I18n_Plural_Two, getCategory) {

	zval *count_param = NULL;
	zend_long count;

	zephir_fetch_params(0, 1, 0, &count_param);

	count = zephir_get_intval(count_param);


	if (count == 1) {
		RETURN_STRING("one", 1);
	} else if (count == 2) {
		RETURN_STRING("two", 1);
	} else {
		RETURN_STRING("other", 1);
	}

}

