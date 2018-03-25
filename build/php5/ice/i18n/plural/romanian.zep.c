
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
#include "kernel/fcall.h"


/**
 * Plural rules for the following locales and languages:
 * 
 * Locales: ro mo
 * 
 * Rules:
 *  one → n is 1;
 *  few → n is 0 OR n is not 1 AND n mod 100 in 1..19;
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
ZEPHIR_INIT_CLASS(Ice_I18n_Plural_Romanian) {

	ZEPHIR_REGISTER_CLASS(Ice\\I18n\\Plural, Romanian, ice, i18n_plural_romanian, ice_i18n_plural_romanian_method_entry, 0);

	zend_class_implements(ice_i18n_plural_romanian_ce TSRMLS_CC, 1, ice_i18n_plural_pluralinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_I18n_Plural_Romanian, getCategory) {

	zend_bool _2, _3, _4;
	zval *count_param = NULL, *_0 = NULL, *_1;
	zend_long count, ZEPHIR_LAST_CALL_STATUS, i100 = 0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &count_param);

	count = zephir_get_intval(count_param);


	i100 = (long) (zephir_safe_mod_long_long(count, 100 TSRMLS_CC));
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, count);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isint", NULL, 0, _1);
	zephir_check_call_status();
	_2 = zephir_is_true(_0);
	if (_2) {
		_3 = count == 0;
		if (!(_3)) {
			_4 = i100 >= 1;
			if (_4) {
				_4 = i100 <= 19;
			}
			_3 = _4;
		}
		_2 = _3;
	}
	if (count == 1) {
		RETURN_MM_STRING("one", 1);
	} else if (_2) {
		RETURN_MM_STRING("few", 1);
	} else {
		RETURN_MM_STRING("other", 1);
	}

}

PHP_METHOD(Ice_I18n_Plural_Romanian, isInt) {

	zend_bool _0;
	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	_0 = zephir_is_numeric(value);
	if (_0) {
		_0 = (zephir_get_numberval(value) - zephir_get_intval(value)) == 0;
	}
	RETURN_BOOL(_0);

}

