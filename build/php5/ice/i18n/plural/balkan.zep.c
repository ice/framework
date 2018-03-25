
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * Plural rules for the following locales and languages:
 * 
 * Locales: be bs hr ru sh sr uk
 *
 * Rules:
 *  one → n mod 10 is 1 and n mod 100 is not 11;
 *  few → n mod 10 in 2..4 and n mod 100 not in 12..14;
 *  many → n mod 10 is 0 or n mod 10 in 5..9 or n mod 100 in 11..14;
 *  other → everything else (fractions)
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
ZEPHIR_INIT_CLASS(Ice_I18n_Plural_Balkan) {

	ZEPHIR_REGISTER_CLASS(Ice\\I18n\\Plural, Balkan, ice, i18n_plural_balkan, ice_i18n_plural_balkan_method_entry, 0);

	zend_class_implements(ice_i18n_plural_balkan_ce TSRMLS_CC, 1, ice_i18n_plural_pluralinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_I18n_Plural_Balkan, getCategory) {

	zend_bool _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11;
	zval *count_param = NULL, *isInt = NULL, *_0;
	zend_long count, ZEPHIR_LAST_CALL_STATUS, i10 = 0, i100 = 0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &count_param);

	count = zephir_get_intval(count_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, count);
	ZEPHIR_CALL_METHOD(&isInt, this_ptr, "isint", NULL, 0, _0);
	zephir_check_call_status();
	i10 = (long) (zephir_safe_mod_long_long(count, 10 TSRMLS_CC));
	i100 = (long) (zephir_safe_mod_long_long(count, 100 TSRMLS_CC));
	_1 = zephir_is_true(isInt);
	if (_1) {
		_1 = zephir_safe_mod_long_long(count, 10 TSRMLS_CC) == 1;
	}
	_2 = _1;
	if (_2) {
		_2 = zephir_safe_mod_long_long(count, 100 TSRMLS_CC) != 11;
	}
	_3 = zephir_is_true(isInt);
	if (_3) {
		_3 = i10 >= 2;
	}
	_4 = _3;
	if (_4) {
		_4 = i10 <= 4;
	}
	_5 = _4;
	if (_5) {
		_6 = i100 >= 12;
		if (_6) {
			_6 = i100 <= 14;
		}
		_5 = !(_6);
	}
	_7 = zephir_is_true(isInt);
	if (_7) {
		_8 = i10 == 0;
		if (!(_8)) {
			_9 = i10 >= 5;
			if (_9) {
				_9 = i10 <= 9;
			}
			_8 = _9;
		}
		_10 = _8;
		if (!(_10)) {
			_11 = i100 >= 11;
			if (_11) {
				_11 = i100 <= 14;
			}
			_10 = _11;
		}
		_7 = _10;
	}
	if (_2) {
		RETURN_MM_STRING("one", 1);
	} else if (_5) {
		RETURN_MM_STRING("few", 1);
	} else if (_7) {
		RETURN_MM_STRING("many", 1);
	} else {
		RETURN_MM_STRING("other", 1);
	}

}

PHP_METHOD(Ice_I18n_Plural_Balkan, isInt) {

	zend_bool _0;
	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	_0 = zephir_is_numeric(value);
	if (_0) {
		_0 = (zephir_get_numberval(value) - zephir_get_intval(value)) == 0;
	}
	RETURN_BOOL(_0);

}

