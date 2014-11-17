
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

	zend_declare_property_null(ice_i18n_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_I18n, __construct) {

	zval *options_param = NULL, *_1, *_2, *_3;
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
	zephir_update_property_this(this_ptr, SL("_cache"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	zephir_fast_array_merge(_2, &(_3), &(options) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_options"), _2 TSRMLS_CC);
	zephir_update_static_property_ce(ice_i18n_ce, SL("_i18n"), &this_ptr TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Ice_I18n, fetch) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(ice_i18n_ce, SL("_i18n") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Get and set the target language
 *
 * @param string $lang new language setting
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
	zephir_array_fetch_string(&_6, _5, SL("lang"), PH_NOISY | PH_READONLY, "ice/i18n.zep", 39 TSRMLS_CC);
	RETURN_CTOR(_6);

}

/**
 * Returns translation of a string. No parameters are replaced.
 * If no translation exists, the original string will be returned. 
 *
 * @param string $str text to translate
 * @param string $lang target language
 * @return string
 */
PHP_METHOD(Ice_I18n, get) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *lang_param = NULL, *messages = NULL, *_0, *_1, *_4 = NULL;
	zval *str = NULL, *lang = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &lang_param);

	zephir_get_strval(str, str_param);
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
		zephir_array_fetch_string(&_1, _0, SL("lang"), PH_NOISY, "ice/i18n.zep", 58 TSRMLS_CC);
		zephir_get_strval(_2, _1);
		ZEPHIR_CPY_WRT(lang, _2);
	}
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "load", &_3, lang);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	if (zephir_array_isset(messages, str)) {
		zephir_array_fetch(&_4, messages, str, PH_NOISY, "ice/i18n.zep", 65 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(_4, str);
	}
	RETURN_CCTOR(_4);

}

/**
 * Load language from the file
 *
 * @param string $lang language code
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
	zephir_is_iterable(_2, &_4, &_3, 0, 0, "ice/i18n.zep", 105);
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
		zephir_is_iterable(tail, &_7, &_6, 0, 0, "ice/i18n.zep", 103);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HVALUE(found, _8);
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(_10);
			zephir_array_fetch_string(&_10, _9, SL("dir"), PH_NOISY, "ice/i18n.zep", 95 TSRMLS_CC);
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
	zephir_array_fetch(&_13, _9, lang, PH_NOISY | PH_READONLY, "ice/i18n.zep", 107 TSRMLS_CC);
	RETURN_CTOR(_13);

}

/**
 * Alias of translate
 */
PHP_METHOD(Ice_I18n, _) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *str_param = NULL, *values_param = NULL, *lang_param = NULL;
	zval *str = NULL, *lang = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &str_param, &values_param, &lang_param);

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
 * @param string $string text to translate
 * @param array $values values to replace in the translated text
 * @param string $lang source language
 * @return  string
 */
PHP_METHOD(Ice_I18n, translate) {

	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL, *_10;
	zval *str_param = NULL, *values_param = NULL, *lang_param = NULL, *_0, *_1, *_3 = NULL, *_4, _5 = zval_used_for_init, *_6 = NULL, *_9;
	zval *str = NULL, *lang = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &str_param, &values_param, &lang_param);

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
	if (!lang_param) {
		ZEPHIR_INIT_VAR(lang);
		ZVAL_EMPTY_STRING(lang);
	} else {
		zephir_get_strval(lang, lang_param);
	}


	if (!(lang && Z_STRLEN_P(lang))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_1);
		zephir_array_fetch_string(&_1, _0, SL("lang"), PH_NOISY, "ice/i18n.zep", 129 TSRMLS_CC);
		zephir_get_strval(_2, _1);
		ZEPHIR_CPY_WRT(lang, _2);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", NULL, str, lang);
	zephir_check_call_status();
	zephir_get_strval(str, _3);
	if (!(zephir_fast_count_int(values TSRMLS_CC))) {
		RETURN_CTOR(str);
	} else {
		ZEPHIR_INIT_VAR(_4);
		zephir_array_keys(_4, values TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "is_string", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "array_filter", &_7, _4, &_5);
		zephir_check_call_status();
		if (zephir_fast_count_int(_6 TSRMLS_CC)) {
			ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_8, str, values);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(_9);
			ZEPHIR_INIT_VAR(_10);
			array_init_size(_10, 2);
			zephir_array_fast_append(_10, str);
			zephir_fast_array_merge(_9, &(_10), &(values) TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_STRING(&_5, "sprintf", 0);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_5, _9);
			zephir_check_call_status();
			RETURN_MM();
		}
	}

}

