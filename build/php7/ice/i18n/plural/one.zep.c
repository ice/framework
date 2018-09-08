
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
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * Plural rules for the following locales and languages:
 * 
 * Locales: asa ast af bem bez bg bn brx ca cgg chr ckb da de dv ee el en eo es et eu fi fo fur fy gl gsw gu
 *          ha haw is it jmc kaj kcg kk kl ks ksb ku ky lb lg mas ml mn mr nah nb nd ne nl nn no nr ny nyn om
 *          or os pa pap ps pt rof rm rwk saq seh sn so sq ss ssy st sv sw syr ta te teo tig tk tn ts ur vo
 *          wae ve vun xh xog zu
 * 
 * Rules:
 *  one → n is 1;
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
ZEPHIR_INIT_CLASS(Ice_I18n_Plural_One) {

	ZEPHIR_REGISTER_CLASS(Ice\\I18n\\Plural, One, ice, i18n_plural_one, ice_i18n_plural_one_method_entry, 0);

	zend_class_implements(ice_i18n_plural_one_ce TSRMLS_CC, 1, ice_i18n_plural_pluralinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_I18n_Plural_One, getCategory) {

	zval *count_param = NULL, _0;
	zend_long count;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &count_param);

	count = zephir_get_intval(count_param);


	ZEPHIR_INIT_VAR(&_0);
	if (count == 1) {
		ZVAL_STRING(&_0, "one");
	} else {
		ZVAL_STRING(&_0, "other");
	}
	RETURN_CCTOR(&_0);

}

