
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Global alias of translate method.
 */
/**
 * Internationalization (i18n) class.
 *
 * @package     Ice/I18n
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_I18n) {

	ZEPHIR_REGISTER_CLASS(Ice, I18n, ice, i18n, ice_i18n_method_entry, 0);

	zend_declare_property_null(ice_i18n_ce, SL("i18n"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(ice_i18n_ce, SL("cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_i18n_ce, SL("rules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_i18n_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_i18n_ce->create_object = zephir_init_properties_Ice_I18n;
	return SUCCESS;

}

/**
 * I18n constructor.
 *
 * @param array options
 */
PHP_METHOD(Ice_I18n, __construct) {

	zval *options_param = NULL, _0, _1;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &options TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("options"), &_0);
	zend_update_static_property(ice_i18n_ce, ZEND_STRL("i18n"), this_ptr);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the last I18n created.
 *
 * @return I18n
 */
PHP_METHOD(Ice_I18n, fetch) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, ice_i18n_ce, SL("i18n"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

/**
 * Get and set the target language.
 *
 * @param string lang New language setting
 * @return string
 */
PHP_METHOD(Ice_I18n, lang) {

	zval *lang_param = NULL, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5, _6;
	zval lang;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&lang);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &lang_param);

	if (!lang_param) {
		ZEPHIR_INIT_VAR(&lang);
		ZVAL_STRING(&lang, "");
	} else {
		zephir_get_strval(&lang, lang_param);
	}


	if (!(Z_TYPE_P(&lang) == IS_UNDEF) && Z_STRLEN_P(&lang)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "_");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "-");
		zephir_fast_str_replace(&_1$$3, &_2$$3, &_3$$3, &lang TSRMLS_CC);
		zephir_fast_strtolower(&_0$$3, &_1$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "lang");
		zephir_update_property_array(this_ptr, SL("options"), &_4$$3, &_0$$3 TSRMLS_CC);
	}
	zephir_read_property(&_5, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_6, &_5, SL("lang"), PH_NOISY | PH_READONLY, "ice/i18n.zep", 74 TSRMLS_CC);
	RETURN_CTOR(&_6);

}

/**
 * Get ISO language code.
 *
 * @param string lang Language
 * @param boolean country Get country code, by default gets language code
 * @return string
 */
PHP_METHOD(Ice_I18n, iso) {

	zend_bool country, _6;
	zval *lang = NULL, lang_sub, *country_param = NULL, __$null, parts, _1, _2, _3, _4, _5, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&lang_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &lang, &country_param);

	if (!lang) {
		lang = &lang_sub;
		ZEPHIR_CPY_WRT(lang, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(lang);
	}
	if (!country_param) {
		country = 0;
	} else {
		country = zephir_get_boolval(country_param);
	}


	if (!(zephir_is_true(lang))) {
		zephir_read_property(&_0$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(lang);
		zephir_array_fetch_string(lang, &_0$$3, SL("lang"), PH_NOISY, "ice/i18n.zep", 89 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "_");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "-");
	zephir_fast_str_replace(&_2, &_3, &_4, lang TSRMLS_CC);
	zephir_fast_strtolower(&_1, &_2);
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("-"), &_1, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	_6 = country;
	if (_6) {
		_6 = zephir_array_isset_long(&parts, 1);
	}
	if (_6) {
		zephir_array_fetch_long(&_5, &parts, 1, PH_NOISY, "ice/i18n.zep", 94 TSRMLS_CC);
	} else {
		zephir_array_fetch_long(&_5, &parts, 0, PH_NOISY, "ice/i18n.zep", 94 TSRMLS_CC);
	}
	RETURN_CCTOR(&_5);

}

/**
 * Returns specified form of a string translation. No parameters are replaced.
 * If no translation exists, the original string will be returned. 
 *
 * @param string str Text to translate
 * @param mixed form If NULL, looking for `other` form, else the very first form
 * @param string lang Target language
 * @return string
 */
PHP_METHOD(Ice_I18n, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *form = NULL, form_sub, *lang_param = NULL, __$null, messages, translation, _0$$3, _1$$3, _3$$5, _4$$6, _5$$7;
	zval str, lang, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&lang);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&form_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &str_param, &form, &lang_param);

	zephir_get_strval(&str, str_param);
	if (!form) {
		form = &form_sub;
		form = &__$null;
	}
	if (!lang_param) {
		ZEPHIR_INIT_VAR(&lang);
		ZVAL_STRING(&lang, "");
	} else {
		zephir_get_strval(&lang, lang_param);
	}


	ZEPHIR_INIT_VAR(&messages);
	array_init(&messages);
	if (!(!(Z_TYPE_P(&lang) == IS_UNDEF) && Z_STRLEN_P(&lang))) {
		zephir_read_property(&_0$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_array_fetch_string(&_1$$3, &_0$$3, SL("lang"), PH_NOISY, "ice/i18n.zep", 116 TSRMLS_CC);
		zephir_get_strval(&_2$$3, &_1$$3);
		ZEPHIR_CPY_WRT(&lang, &_2$$3);
	}
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "load", NULL, 140, &lang);
	zephir_check_call_status();
	if (zephir_array_isset(&messages, &str)) {
		ZEPHIR_OBS_VAR(&translation);
		zephir_array_fetch(&translation, &messages, &str, PH_NOISY, "ice/i18n.zep", 123 TSRMLS_CC);
		if (Z_TYPE_P(&translation) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "other");
			if (zephir_array_key_exists(&translation, form TSRMLS_CC)) {
				zephir_array_fetch(&_4$$6, &translation, form, PH_NOISY | PH_READONLY, "ice/i18n.zep", 129 TSRMLS_CC);
				RETURN_CTOR(&_4$$6);
			} else if (zephir_array_key_exists(&translation, &_3$$5 TSRMLS_CC)) {
				zephir_array_fetch_string(&_5$$7, &translation, SL("other"), PH_NOISY | PH_READONLY, "ice/i18n.zep", 131 TSRMLS_CC);
				RETURN_CTOR(&_5$$7);
			}
			ZEPHIR_MAKE_REF(&translation);
			ZEPHIR_RETURN_CALL_FUNCTION("reset", NULL, 141, &translation);
			ZEPHIR_UNREF(&translation);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(&translation);
	}
	RETURN_CTOR(&str);

}

/**
 * Load language from the file.
 *
 * @param string lang Language code
 * @return array
 */
PHP_METHOD(Ice_I18n, load) {

	zval _2;
	zval *lang_param = NULL, cache, parts, subdir, tail, tmp, found, path, messages, _0, _1, *_3, _9, _10, *_4$$4, _5$$6, _6$$6, _8$$7;
	zval lang, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&lang);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&subdir);
	ZVAL_UNDEF(&tail);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&found);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &lang_param);

	zephir_get_strval(&lang, lang_param);


	ZEPHIR_OBS_VAR(&cache);
	zephir_read_property(&_0, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&cache, &_0, &lang, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&cache);
	}
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("-"), &lang, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_INIT_VAR(&subdir);
	zephir_fast_join(&subdir, &_1, &parts TSRMLS_CC);
	ZEPHIR_INIT_VAR(&messages);
	array_init(&messages);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, &subdir);
	zephir_array_fast_append(&_2, &lang);
	zephir_array_fast_append(&_2, &parts);
	zephir_is_iterable(&_2, 0, "ice/i18n.zep", 182);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _3)
	{
		ZEPHIR_INIT_NVAR(&tail);
		ZVAL_COPY(&tail, _3);
		if (Z_TYPE_P(&tail) != IS_ARRAY) {
			ZEPHIR_CPY_WRT(&tmp, &tail);
			ZEPHIR_INIT_NVAR(&tail);
			zephir_create_array(&tail, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&tail, &tmp);
		}
		zephir_is_iterable(&tail, 0, "ice/i18n.zep", 180);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tail), _4$$4)
		{
			ZEPHIR_INIT_NVAR(&found);
			ZVAL_COPY(&found, _4$$4);
			zephir_read_property(&_5$$6, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&_6$$6);
			zephir_array_fetch_string(&_6$$6, &_5$$6, SL("dir"), PH_NOISY, "ice/i18n.zep", 172 TSRMLS_CC);
			zephir_get_strval(&_7$$6, &_6$$6);
			ZEPHIR_INIT_NVAR(&path);
			ZEPHIR_CONCAT_VVS(&path, &_7$$6, &found, ".php");
			if ((zephir_file_exists(&path TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_8$$7);
				if (zephir_require_zval_ret(&_8$$7, &path TSRMLS_CC) == FAILURE) {
					RETURN_MM_NULL();
				}
				ZEPHIR_CPY_WRT(&messages, &_8$$7);
				break;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&found);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&tail);
	zephir_update_property_array(this_ptr, SL("cache"), &lang, &messages TSRMLS_CC);
	zephir_read_property(&_9, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_10, &_9, &lang, PH_NOISY | PH_READONLY, "ice/i18n.zep", 184 TSRMLS_CC);
	RETURN_CTOR(&_10);

}

/**
 * Returns translation of a string with right plural form.
 * If no translation exists, the original string will be returned.
 * 
 * @param string string
 * @param int count
 * @param string lang
 * @return string
 */
PHP_METHOD(Ice_I18n, plural) {

	zend_long count, ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *count_param = NULL, *lang_param = NULL, rules, form, code, _0, _4, _1$$3, _2$$3, _3$$3;
	zval str, lang;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&lang);
	ZVAL_UNDEF(&rules);
	ZVAL_UNDEF(&form);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &str_param, &count_param, &lang_param);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(&str, str_param);
	} else {
		ZEPHIR_INIT_VAR(&str);
		ZVAL_EMPTY_STRING(&str);
	}
	if (!count_param) {
		count = 0;
	} else {
		count = zephir_get_intval(count_param);
	}
	if (!lang_param) {
		ZEPHIR_INIT_VAR(&lang);
		ZVAL_STRING(&lang, "");
	} else {
		zephir_get_strval(&lang, lang_param);
	}


	ZEPHIR_CALL_METHOD(&code, this_ptr, "iso", NULL, 0, &lang);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&rules);
	zephir_read_property(&_0, this_ptr, SL("rules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&rules, &_0, &code, 0 TSRMLS_CC))) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "pluralrules", NULL, 0, &code);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("rules"), &code, &_1$$3 TSRMLS_CC);
		zephir_read_property(&_2$$3, this_ptr, SL("rules"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &code, PH_NOISY | PH_READONLY, "ice/i18n.zep", 205 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&rules, &_3$$3);
	}
	ZVAL_LONG(&_4, count);
	ZEPHIR_CALL_METHOD(&form, &rules, "getcategory", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &str, &form, &lang);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Plural rules lazy initialization.
 * 
 * @param string code Language code
 * @return object
 */
PHP_METHOD(Ice_I18n, pluralRules) {

	zval _0, _3, _5, _7, _9, _11, _13, _15;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code_param = NULL, __$true, _1, _2, _4, _6, _8, _10, _12, _14, _16, _17$$13;
	zval code, _18$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code_param);

	zephir_get_strval(&code, code_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cs");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sk");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(&_2, "in_array", NULL, 142, &code, &_0, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 7, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ru");
	zephir_array_fast_append(&_3, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sr");
	zephir_array_fast_append(&_3, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "uk");
	zephir_array_fast_append(&_3, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sh");
	zephir_array_fast_append(&_3, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "be");
	zephir_array_fast_append(&_3, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "hr");
	zephir_array_fast_append(&_3, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "bs");
	zephir_array_fast_append(&_3, &_1);
	ZEPHIR_CALL_FUNCTION(&_4, "in_array", NULL, 142, &code, &_3, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fr");
	zephir_array_fast_append(&_5, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ff");
	zephir_array_fast_append(&_5, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "kab");
	zephir_array_fast_append(&_5, &_1);
	ZEPHIR_CALL_FUNCTION(&_6, "in_array", NULL, 142, &code, &_5, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "mo");
	zephir_array_fast_append(&_7, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ro");
	zephir_array_fast_append(&_7, &_1);
	ZEPHIR_CALL_FUNCTION(&_8, "in_array", NULL, 142, &code, &_7, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 12, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "hi");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ln");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "mg");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ak");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tl");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "am");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "bh");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "wa");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ti");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "guw");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fil");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "nso");
	zephir_array_fast_append(&_9, &_1);
	ZEPHIR_CALL_FUNCTION(&_10, "in_array", NULL, 142, &code, &_9, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 97, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "en");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ny");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "nr");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "no");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "om");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "os");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ps");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "pa");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "nn");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "or");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "nl");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "lg");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "lb");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ky");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ml");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "mr");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ne");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "nd");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "nb");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "pt");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "rm");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ts");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tn");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tk");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ur");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "vo");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "zu");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "xh");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ve");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "te");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ta");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sq");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "so");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sn");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ss");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "st");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sw");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sv");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ku");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "mn");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "et");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "eo");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "el");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "eu");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fi");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fy");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fo");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ee");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "dv");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "bg");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "af");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "bn");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ca");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "de");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "da");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "gl");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "es");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "it");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "is");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ks");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ha");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "kk");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "kl");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "gu");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "brx");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "mas");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "teo");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "chr");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "cgg");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tig");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "wae");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "xog");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ast");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "vun");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "bem");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "syr");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "bez");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "asa");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "rof");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ksb");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "rwk");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "haw");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "pap");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "gsw");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fur");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "saq");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "seh");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "nyn");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "kcg");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ssy");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "kaj");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "jmc");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "nah");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ckb");
	zephir_array_fast_append(&_11, &_1);
	ZEPHIR_CALL_FUNCTION(&_12, "in_array", NULL, 142, &code, &_11, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 9, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "se");
	zephir_array_fast_append(&_13, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "kw");
	zephir_array_fast_append(&_13, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "iu");
	zephir_array_fast_append(&_13, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "smn");
	zephir_array_fast_append(&_13, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sms");
	zephir_array_fast_append(&_13, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "smj");
	zephir_array_fast_append(&_13, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sma");
	zephir_array_fast_append(&_13, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "naq");
	zephir_array_fast_append(&_13, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "smi");
	zephir_array_fast_append(&_13, &_1);
	ZEPHIR_CALL_FUNCTION(&_14, "in_array", NULL, 142, &code, &_13, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_15);
	zephir_create_array(&_15, 30, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "my");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sg");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ms");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "lo");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "kn");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ko");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "th");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "to");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "yo");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "zh");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "wo");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "vi");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tr");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "az");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "km");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "id");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ig");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "fa");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "dz");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "bm");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "bo");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ii");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "hu");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ka");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "jv");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ja");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "kde");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ses");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "sah");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "kea");
	zephir_array_fast_append(&_15, &_1);
	ZEPHIR_CALL_FUNCTION(&_16, "in_array", NULL, 142, &code, &_15, &__$true);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(&code, "pl")) {
		object_init_ex(return_value, ice_i18n_plural_polish_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (ZEPHIR_IS_STRING_IDENTICAL(&code, "ar")) {
		object_init_ex(return_value, ice_i18n_plural_arabic_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(&_2)) {
		object_init_ex(return_value, ice_i18n_plural_czech_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(&_4)) {
		object_init_ex(return_value, ice_i18n_plural_balkan_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(&_6)) {
		object_init_ex(return_value, ice_i18n_plural_french_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(&_8)) {
		object_init_ex(return_value, ice_i18n_plural_romanian_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(&_10)) {
		object_init_ex(return_value, ice_i18n_plural_zero_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(&_12)) {
		object_init_ex(return_value, ice_i18n_plural_one_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(&_14)) {
		object_init_ex(return_value, ice_i18n_plural_two_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(&_16)) {
		object_init_ex(return_value, ice_i18n_plural_none_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else {
		ZEPHIR_INIT_VAR(&_17$$13);
		object_init_ex(&_17$$13, ice_exception_ce);
		ZEPHIR_INIT_VAR(&_18$$13);
		ZEPHIR_CONCAT_SV(&_18$$13, "Unknown language code: ", &code);
		ZEPHIR_CALL_METHOD(NULL, &_17$$13, "__construct", NULL, 12, &_18$$13);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_17$$13, "ice/i18n.zep", 253 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

/**
 * Alias of translate.
 */
PHP_METHOD(Ice_I18n, _) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *str_param = NULL, *values_param = NULL, *context = NULL, context_sub, *lang_param = NULL, __$null;
	zval str, lang;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&lang);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &str_param, &values_param, &context, &lang_param);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(&str, str_param);
	} else {
		ZEPHIR_INIT_VAR(&str);
		ZVAL_EMPTY_STRING(&str);
	}
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!lang_param) {
		ZEPHIR_INIT_VAR(&lang);
		ZVAL_STRING(&lang, "");
	} else {
		zephir_get_strval(&lang, lang_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "translate", NULL, 0, &str, &values, &lang);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Translation/internationalization function. strtr() or sprintf is used for replacing parameters.
 *
 * @param string string Text to translate
 * @param array values Values to replace in the translated text
 * @param mixed context String form or numeric count
 * @param string lang Source language
 * @return string
 */
PHP_METHOD(Ice_I18n, translate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values, _9$$9;
	zval *str_param = NULL, *values_param = NULL, *context = NULL, context_sub, *lang_param = NULL, __$null, _0$$3, _1$$3, _3$$4, _4$$5, _5$$7, _6$$7, _7$$7, _8$$9, _10$$9;
	zval str, lang, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&lang);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_9$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &str_param, &values_param, &context, &lang_param);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(&str, str_param);
	} else {
		ZEPHIR_INIT_VAR(&str);
		ZVAL_EMPTY_STRING(&str);
	}
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!lang_param) {
		ZEPHIR_INIT_VAR(&lang);
		ZVAL_STRING(&lang, "");
	} else {
		zephir_get_strval(&lang, lang_param);
	}


	if (!(!(Z_TYPE_P(&lang) == IS_UNDEF) && Z_STRLEN_P(&lang))) {
		zephir_read_property(&_0$$3, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_array_fetch_string(&_1$$3, &_0$$3, SL("lang"), PH_NOISY, "ice/i18n.zep", 277 TSRMLS_CC);
		zephir_get_strval(&_2$$3, &_1$$3);
		ZEPHIR_CPY_WRT(&lang, &_2$$3);
	}
	if (zephir_is_numeric(context)) {
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "plural", NULL, 0, &str, context, &lang);
		zephir_check_call_status();
		zephir_get_strval(&str, &_3$$4);
	} else {
		ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "get", NULL, 0, &str, context, &lang);
		zephir_check_call_status();
		zephir_get_strval(&str, &_4$$5);
	}
	if (!(zephir_fast_count_int(&values TSRMLS_CC))) {
		RETURN_CTOR(&str);
	} else {
		ZEPHIR_INIT_VAR(&_5$$7);
		zephir_array_keys(&_5$$7, &values TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$7);
		ZVAL_STRING(&_6$$7, "is_string");
		ZEPHIR_CALL_FUNCTION(&_7$$7, "array_filter", NULL, 7, &_5$$7, &_6$$7);
		zephir_check_call_status();
		if (zephir_fast_count_int(&_7$$7 TSRMLS_CC)) {
			ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 103, &str, &values);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(&_8$$9);
			ZEPHIR_INIT_VAR(&_9$$9);
			zephir_create_array(&_9$$9, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_9$$9, &str);
			zephir_fast_array_merge(&_8$$9, &_9$$9, &values TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_10$$9);
			ZVAL_STRING(&_10$$9, "sprintf");
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_10$$9, &_8$$9);
			zephir_check_call_status();
			RETURN_MM();
		}
	}

}

zend_object *zephir_init_properties_Ice_I18n(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2, _4, _3$$4, _5$$5;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("source"), SL("en-gb"));
			add_assoc_stringl_ex(&_1$$3, SL("lang"), SL("en-gb"));
			add_assoc_stringl_ex(&_1$$3, SL("dir"), SL(""));
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("rules"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("rules"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("cache"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

PHP_FUNCTION(g_ice__t) {
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval values;
	zval *str_param = NULL, *values_param = NULL, *context = NULL, context_sub, *lang_param = NULL, __$null, i18n;
	zval str, lang;
		ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&lang);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &str_param, &values_param, &context, &lang_param);

	if (UNEXPECTED(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(&str, str_param);
	} else {
		ZEPHIR_INIT_VAR(&str);
		ZVAL_EMPTY_STRING(&str);
	}
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!lang_param) {
		ZEPHIR_INIT_VAR(&lang);
		ZVAL_STRING(&lang, "");
	} else {
		zephir_get_strval(&lang, lang_param);
	}


	ZEPHIR_CALL_CE_STATIC(&i18n, ice_i18n_ce, "fetch", &_0, 0);
	zephir_check_call_status();
	if (zephir_is_true(&i18n)) {
		ZEPHIR_RETURN_CALL_METHOD(&i18n, "translate", NULL, 0, &str, &values, context, &lang);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

