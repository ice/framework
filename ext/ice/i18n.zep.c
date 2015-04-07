
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"

ZEPHIR_INIT_CLASS(Ice_I18n) {

	ZEPHIR_REGISTER_CLASS(Ice, I18n, ice, i18n, ice_i18n_method_entry, 0);

	zend_declare_property_null(ice_i18n_ce, SL("_i18n"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(ice_i18n_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_i18n_ce, SL("_rules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_i18n_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * I18n constructor.
 *
 * @param array options
 */
PHP_METHOD(Ice_I18n, __construct) {

	zval *options_param = NULL, *_1, *_2, *_3, *_4;
	zval *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 4);
	add_assoc_stringl_ex(_0, SS("source"), SL("en-gb"), 1);
	add_assoc_stringl_ex(_0, SS("lang"), SL("en-gb"), 1);
	add_assoc_stringl_ex(_0, SS("dir"), SL(""), 1);
	zephir_update_property_this(this_ptr, SL("_options"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_rules"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_cache"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_fast_array_merge(_3, &(_4), &(options) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_options"), _3 TSRMLS_CC);
	zephir_update_static_property_ce(ice_i18n_ce, SL("_i18n"), &this_ptr TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the last I18n created.
 *
 * @return I18n
 */
PHP_METHOD(Ice_I18n, fetch) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(ice_i18n_ce, SL("_i18n") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Get and set the target language.
 *
 * @param string lang New language setting
 * @return string
 */
PHP_METHOD(Ice_I18n, lang) {

	zval *lang_param = NULL, *_0, *_1, _2, _3, *_4, *_5, *_6;
	zval *lang = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &lang_param);

	if (!lang_param) {
		ZEPHIR_INIT_VAR(lang);
		ZVAL_EMPTY_STRING(lang);
	} else {
		zephir_get_strval(lang, lang_param);
	}


	if (lang && Z_STRLEN_P(lang)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "_", 0);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "-", 0);
		zephir_fast_str_replace(_1, &_2, &_3, lang TSRMLS_CC);
		zephir_fast_strtolower(_0, _1);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "lang", 1);
		zephir_update_property_array(this_ptr, SL("_options"), _4, _0 TSRMLS_CC);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_array_fetch_string(&_6, _5, SL("lang"), PH_NOISY | PH_READONLY, "ice/i18n.zep", 68 TSRMLS_CC);
	RETURN_CTOR(_6);

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
	zval *lang = NULL, *country_param = NULL, *parts, *_0, *_1, *_2, _3, _4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &lang, &country_param);

	if (!lang) {
		ZEPHIR_CPY_WRT(lang, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(lang);
	}
	if (!country_param) {
		country = 0;
	} else {
		country = zephir_get_boolval(country_param);
	}


	if (!(zephir_is_true(lang))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(lang);
		zephir_array_fetch_string(&lang, _0, SL("lang"), PH_NOISY, "ice/i18n.zep", 83 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(parts);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "_", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "-", 0);
	zephir_fast_str_replace(_2, &_3, &_4, lang TSRMLS_CC);
	zephir_fast_strtolower(_1, _2);
	zephir_fast_explode_str(parts, SL("-"), _1, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	_6 = country;
	if (_6) {
		_6 = zephir_array_isset_long(parts, 1);
	}
	if (_6) {
		zephir_array_fetch_long(&_5, parts, 1, PH_NOISY, "ice/i18n.zep", 88 TSRMLS_CC);
	} else {
		zephir_array_fetch_long(&_5, parts, 0, PH_NOISY, "ice/i18n.zep", 88 TSRMLS_CC);
	}
	RETURN_CCTOR(_5);

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

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *form = NULL, *lang_param = NULL, *messages = NULL, *translation, *_0, *_1, _4, *_5;
	zval *str = NULL, *lang = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &str_param, &form, &lang_param);

	zephir_get_strval(str, str_param);
	if (!form) {
		form = ZEPHIR_GLOBAL(global_null);
	}
	if (!lang_param) {
		ZEPHIR_INIT_VAR(lang);
		ZVAL_EMPTY_STRING(lang);
	} else {
		zephir_get_strval(lang, lang_param);
	}


	ZEPHIR_INIT_VAR(messages);
	array_init(messages);
	if (!(lang && Z_STRLEN_P(lang))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_1);
		zephir_array_fetch_string(&_1, _0, SL("lang"), PH_NOISY, "ice/i18n.zep", 110 TSRMLS_CC);
		zephir_get_strval(_2, _1);
		ZEPHIR_CPY_WRT(lang, _2);
	}
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "load", &_3, lang);
	zephir_check_call_status();
	if (zephir_array_isset(messages, str)) {
		ZEPHIR_OBS_VAR(translation);
		zephir_array_fetch(&translation, messages, str, PH_NOISY, "ice/i18n.zep", 117 TSRMLS_CC);
		if (Z_TYPE_P(translation) == IS_ARRAY) {
			ZEPHIR_SINIT_VAR(_4);
			ZVAL_STRING(&_4, "other", 0);
			if (zephir_array_key_exists(translation, form TSRMLS_CC)) {
				zephir_array_fetch(&_5, translation, form, PH_NOISY | PH_READONLY, "ice/i18n.zep", 123 TSRMLS_CC);
				RETURN_CTOR(_5);
			} else if (zephir_array_key_exists(translation, &_4 TSRMLS_CC)) {
				zephir_array_fetch_string(&_5, translation, SL("other"), PH_NOISY | PH_READONLY, "ice/i18n.zep", 125 TSRMLS_CC);
				RETURN_CTOR(_5);
			}
			Z_SET_ISREF_P(translation);
			ZEPHIR_RETURN_CALL_FUNCTION("reset", &_6, translation);
			Z_UNSET_ISREF_P(translation);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(translation);
	}
	RETURN_CTOR(str);

}

/**
 * Load language from the file.
 *
 * @param string lang Language code
 * @return array
 */
PHP_METHOD(Ice_I18n, load) {

	HashTable *_4, *_7;
	HashPosition _3, _6;
	zval *_2;
	zval *lang_param = NULL, *cache, *parts, *subdir, *tail = NULL, *tmp = NULL, *found = NULL, *path = NULL, *messages = NULL, *_0, _1, **_5, **_8, *_9, *_10 = NULL, *_12 = NULL, *_13;
	zval *lang = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &lang_param);

	zephir_get_strval(lang, lang_param);


	ZEPHIR_OBS_VAR(cache);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&cache, _0, lang, 0 TSRMLS_CC)) {
		RETURN_CCTOR(cache);
	}
	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode_str(parts, SL("-"), lang, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_VAR(subdir);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/", 0);
	zephir_fast_join(subdir, &_1, parts TSRMLS_CC);
	ZEPHIR_INIT_VAR(messages);
	array_init(messages);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 4);
	zephir_array_fast_append(_2, subdir);
	zephir_array_fast_append(_2, lang);
	zephir_array_fast_append(_2, parts);
	zephir_is_iterable(_2, &_4, &_3, 0, 0, "ice/i18n.zep", 176);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(tail, _5);
		if (Z_TYPE_P(tail) != IS_ARRAY) {
			ZEPHIR_CPY_WRT(tmp, tail);
			ZEPHIR_INIT_NVAR(tail);
			array_init_size(tail, 2);
			zephir_array_fast_append(tail, tmp);
		}
		zephir_is_iterable(tail, &_7, &_6, 0, 0, "ice/i18n.zep", 174);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HVALUE(found, _8);
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(_10);
			zephir_array_fetch_string(&_10, _9, SL("dir"), PH_NOISY, "ice/i18n.zep", 166 TSRMLS_CC);
			zephir_get_strval(_11, _10);
			ZEPHIR_INIT_NVAR(path);
			ZEPHIR_CONCAT_VVS(path, _11, found, ".php");
			if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_12);
				if (zephir_require_zval_ret(&_12, path TSRMLS_CC) == FAILURE) {
					RETURN_MM_NULL();
				}
				ZEPHIR_CPY_WRT(messages, _12);
				break;
			}
		}
	}
	zephir_update_property_array(this_ptr, SL("_cache"), lang, messages TSRMLS_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
	zephir_array_fetch(&_13, _9, lang, PH_NOISY | PH_READONLY, "ice/i18n.zep", 178 TSRMLS_CC);
	RETURN_CTOR(_13);

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

	int count, ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *count_param = NULL, *lang_param = NULL, *rules = NULL, *form = NULL, *code = NULL, *_0, *_1 = NULL, *_2, *_3;
	zval *str = NULL, *lang = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &str_param, &count_param, &lang_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	if (!count_param) {
		count = 0;
	} else {
		count = zephir_get_intval(count_param);
	}
	if (!lang_param) {
		ZEPHIR_INIT_VAR(lang);
		ZVAL_EMPTY_STRING(lang);
	} else {
		zephir_get_strval(lang, lang_param);
	}


	ZEPHIR_CALL_METHOD(&code, this_ptr, "iso", NULL, lang);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(rules);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_rules"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&rules, _0, code, 0 TSRMLS_CC))) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "pluralrules", NULL, code);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("_rules"), code, _1 TSRMLS_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_rules"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(rules);
		zephir_array_fetch(&rules, _2, code, PH_NOISY, "ice/i18n.zep", 199 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, count);
	ZEPHIR_CALL_METHOD(&form, rules, "getcategory", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, str, form, lang);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *_0, *_4, *_6, *_8, *_10, *_12, *_14, *_16;
	zval *code_param = NULL, *_1 = NULL, *_2 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL, *_13 = NULL, *_15 = NULL, *_17 = NULL;
	zval *code = NULL, *_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code_param);

	zephir_get_strval(code, code_param);


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "cs", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sk", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(&_2, "in_array", &_3, code, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	array_init_size(_4, 9);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ru", 1);
	zephir_array_fast_append(_4, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sr", 1);
	zephir_array_fast_append(_4, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "uk", 1);
	zephir_array_fast_append(_4, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sh", 1);
	zephir_array_fast_append(_4, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "be", 1);
	zephir_array_fast_append(_4, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "hr", 1);
	zephir_array_fast_append(_4, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "bs", 1);
	zephir_array_fast_append(_4, _1);
	ZEPHIR_CALL_FUNCTION(&_5, "in_array", &_3, code, _4, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	array_init_size(_6, 4);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "fr", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ff", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "kab", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_CALL_FUNCTION(&_7, "in_array", &_3, code, _6, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	array_init_size(_8, 3);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "mo", 1);
	zephir_array_fast_append(_8, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ro", 1);
	zephir_array_fast_append(_8, _1);
	ZEPHIR_CALL_FUNCTION(&_9, "in_array", &_3, code, _8, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_10);
	array_init_size(_10, 16);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "hi", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ln", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "mg", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ak", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "tl", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "am", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "bh", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "wa", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ti", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "guw", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "fil", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "nso", 1);
	zephir_array_fast_append(_10, _1);
	ZEPHIR_CALL_FUNCTION(&_11, "in_array", &_3, code, _10, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_12);
	array_init_size(_12, 118);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "en", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ny", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "nr", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "no", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "om", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "os", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ps", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pa", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "nn", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "or", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "nl", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "lg", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "lb", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ky", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ml", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "mr", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ne", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "nd", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "nb", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pt", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "rm", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ts", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "tn", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "tk", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ur", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "vo", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "zu", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "xh", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ve", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "te", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ta", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sq", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "so", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sn", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ss", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "st", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sw", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sv", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ku", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "mn", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "et", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "eo", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "el", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "eu", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "fi", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "fy", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "fo", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ee", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "dv", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "bg", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "af", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "bn", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ca", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "de", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "da", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "gl", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "es", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "it", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "is", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ks", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ha", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "kk", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "kl", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "gu", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "brx", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "mas", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "teo", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "chr", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "cgg", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "tig", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "wae", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "xog", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ast", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "vun", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "bem", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "syr", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "bez", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "asa", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "rof", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ksb", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "rwk", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "haw", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "pap", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "gsw", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "fur", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "saq", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "seh", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "nyn", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "kcg", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ssy", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "kaj", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "jmc", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "nah", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ckb", 1);
	zephir_array_fast_append(_12, _1);
	ZEPHIR_CALL_FUNCTION(&_13, "in_array", &_3, code, _12, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_14);
	array_init_size(_14, 12);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "se", 1);
	zephir_array_fast_append(_14, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "kw", 1);
	zephir_array_fast_append(_14, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "iu", 1);
	zephir_array_fast_append(_14, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "smn", 1);
	zephir_array_fast_append(_14, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sms", 1);
	zephir_array_fast_append(_14, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "smj", 1);
	zephir_array_fast_append(_14, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sma", 1);
	zephir_array_fast_append(_14, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "naq", 1);
	zephir_array_fast_append(_14, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "smi", 1);
	zephir_array_fast_append(_14, _1);
	ZEPHIR_CALL_FUNCTION(&_15, "in_array", &_3, code, _14, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_16);
	array_init_size(_16, 38);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "my", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sg", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ms", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "lo", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "kn", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ko", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "th", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "to", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "yo", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "zh", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "wo", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "vi", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "tr", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "az", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "km", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "id", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ig", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "fa", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "dz", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "bm", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "bo", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ii", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "hu", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ka", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "jv", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ja", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "kde", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "ses", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "sah", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "kea", 1);
	zephir_array_fast_append(_16, _1);
	ZEPHIR_CALL_FUNCTION(&_17, "in_array", &_3, code, _16, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(code, "pl")) {
		object_init_ex(return_value, ice_i18n_plural_polish_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (ZEPHIR_IS_STRING_IDENTICAL(code, "ar")) {
		object_init_ex(return_value, ice_i18n_plural_arabic_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(_2)) {
		object_init_ex(return_value, ice_i18n_plural_czech_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(_5)) {
		object_init_ex(return_value, ice_i18n_plural_balkan_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(_7)) {
		object_init_ex(return_value, ice_i18n_plural_french_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(_9)) {
		object_init_ex(return_value, ice_i18n_plural_romanian_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(_11)) {
		object_init_ex(return_value, ice_i18n_plural_zero_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(_13)) {
		object_init_ex(return_value, ice_i18n_plural_one_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(_15)) {
		object_init_ex(return_value, ice_i18n_plural_two_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else if (zephir_is_true(_17)) {
		object_init_ex(return_value, ice_i18n_plural_none_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, ice_exception_ce);
		ZEPHIR_INIT_VAR(_18);
		ZEPHIR_CONCAT_SV(_18, "Unknown language code: ", code);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _18);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "ice/i18n.zep", 247 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

/**
 * Alias of translate.
 */
PHP_METHOD(Ice_I18n, _) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *str_param = NULL, *values_param = NULL, *context = NULL, *lang_param = NULL;
	zval *str = NULL, *lang = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &str_param, &values_param, &context, &lang_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	if (!values_param) {
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	} else {
		zephir_get_arrval(values, values_param);
	}
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}
	if (!lang_param) {
		ZEPHIR_INIT_VAR(lang);
		ZVAL_EMPTY_STRING(lang);
	} else {
		zephir_get_strval(lang, lang_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "translate", NULL, str, values, lang);
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

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL, *_9;
	zval *str_param = NULL, *values_param = NULL, *context = NULL, *lang_param = NULL, *_0, *_1, *_3 = NULL, *_4, _5 = zval_used_for_init, *_8;
	zval *str = NULL, *lang = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &str_param, &values_param, &context, &lang_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	if (!values_param) {
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	} else {
		zephir_get_arrval(values, values_param);
	}
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}
	if (!lang_param) {
		ZEPHIR_INIT_VAR(lang);
		ZVAL_EMPTY_STRING(lang);
	} else {
		zephir_get_strval(lang, lang_param);
	}


	if (!(lang && Z_STRLEN_P(lang))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_1);
		zephir_array_fetch_string(&_1, _0, SL("lang"), PH_NOISY, "ice/i18n.zep", 271 TSRMLS_CC);
		zephir_get_strval(_2, _1);
		ZEPHIR_CPY_WRT(lang, _2);
	}
	if (zephir_is_numeric(context)) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "plural", NULL, str, context, lang);
		zephir_check_call_status();
		zephir_get_strval(str, _3);
	} else {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", NULL, str, context, lang);
		zephir_check_call_status();
		zephir_get_strval(str, _3);
	}
	if (!(zephir_fast_count_int(values TSRMLS_CC))) {
		RETURN_CTOR(str);
	} else {
		ZEPHIR_INIT_VAR(_4);
		zephir_array_keys(_4, values TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "is_string", 0);
		ZEPHIR_CALL_FUNCTION(&_3, "array_filter", &_6, _4, &_5);
		zephir_check_call_status();
		if (zephir_fast_count_int(_3 TSRMLS_CC)) {
			ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_7, str, values);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(_8);
			ZEPHIR_INIT_VAR(_9);
			array_init_size(_9, 2);
			zephir_array_fast_append(_9, str);
			zephir_fast_array_merge(_8, &(_9), &(values) TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_STRING(&_5, "sprintf", 0);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_5, _8);
			zephir_check_call_status();
			RETURN_MM();
		}
	}

}

