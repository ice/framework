
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
#include "kernel/object.h"


/**
 * Plural rules for the following locales and languages:
 *
 * Locales: ak am bh fil tl guw hi ln mg nso ti wa
 *
 * Rules:
 *  one → n in 0..1;
 *  other → everything else
 *
 * Reference CLDR Version 21 (2012-03-01 03:27:30 GMT)
 * @see  http://unicode.org/repos/cldr-tmp/trunk/diff/supplemental/language_plural_rules.html
 * @see  http://unicode.org/repos/cldr/trunk/common/supplemental/plurals.xml
 *
 * @package     Ice/I18n
 * @category    Plural rules
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_I18n_Plural_Zero)
{
	ZEPHIR_REGISTER_CLASS(Ice\\I18n\\Plural, Zero, ice, i18n_plural_zero, ice_i18n_plural_zero_method_entry, 0);

	zend_class_implements(ice_i18n_plural_zero_ce, 1, ice_i18n_plural_pluralinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Ice_I18n_Plural_Zero, getCategory)
{
	zend_bool _0;
	zval *count_param = NULL;
	zend_long count;
	zval *this_ptr = getThis();

#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &count_param);
	count = zephir_get_intval(count_param);


	_0 = count == 0;
	if (!(_0)) {
		_0 = count == 1;
	}
	if (_0) {
		RETURN_STRING("one");
	} else {
		RETURN_STRING("other");
	}
}

