
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * Plural rules for the following locales and languages:
 *
 * Locales: cs sk
 *
 * Rules:
 *  one → n is 1;
 *  few → n in 2..4;
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
ZEPHIR_INIT_CLASS(Ice_I18n_Plural_Czech) {

	ZEPHIR_REGISTER_CLASS(Ice\\I18n\\Plural, Czech, ice, i18n_plural_czech, ice_i18n_plural_czech_method_entry, 0);

	zend_class_implements(ice_i18n_plural_czech_ce, 1, ice_i18n_plural_pluralinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_I18n_Plural_Czech, getCategory) {

	zend_bool _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *count_param = NULL, _0, _1;
	zend_long count, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &count_param);

	count = zephir_get_intval(count_param);


	ZVAL_LONG(&_1, count);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isint", NULL, 0, &_1);
	zephir_check_call_status();
	_2 = zephir_is_true(&_0);
	if (_2) {
		_2 = count >= 2;
	}
	_3 = _2;
	if (_3) {
		_3 = count <= 4;
	}
	if (count == 1) {
		RETURN_MM_STRING("one");
	} else if (_3) {
		RETURN_MM_STRING("few");
	} else {
		RETURN_MM_STRING("other");
	}

}

PHP_METHOD(Ice_I18n_Plural_Czech, isInt) {

	zend_bool _0;
	zval *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &value);



	_0 = zephir_is_numeric(value);
	if (_0) {
		_0 = (zephir_get_numberval(value) - zephir_get_intval(value)) == 0;
	}
	RETURN_BOOL(_0);

}

