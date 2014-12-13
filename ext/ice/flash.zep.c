
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(Ice_Flash) {

	ZEPHIR_REGISTER_CLASS(Ice, Flash, ice, flash, ice_flash_method_entry, 0);

	zend_declare_property_null(ice_flash_ce, SL("_session"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_flash_ce, SL("_tag"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_flash_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Ice_Flash, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *options_param = NULL, *di = NULL, *_3 = NULL, *_4 = NULL;
	zval *options = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 8);
	add_assoc_stringl_ex(_0, SS("session_key"), SL("_flash"), 1);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 2);
	add_assoc_stringl_ex(_1, SS("class"), SL("alert alert-success"), 1);
	zephir_array_update_string(&_0, SL("success"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	array_init_size(_1, 2);
	add_assoc_stringl_ex(_1, SS("class"), SL("alert alert-info"), 1);
	zephir_array_update_string(&_0, SL("info"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	array_init_size(_1, 2);
	add_assoc_stringl_ex(_1, SS("class"), SL("alert alert-warning"), 1);
	zephir_array_update_string(&_0, SL("warning"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	array_init_size(_1, 2);
	add_assoc_stringl_ex(_1, SS("class"), SL("alert alert-danger"), 1);
	zephir_array_update_string(&_0, SL("danger"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("html"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_options"), _0 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, di, "getsession", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_session"), _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, di, "gettag", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_tag"), _4 TSRMLS_CC);
	if (zephir_fast_count_int(options TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get option value with key.
 *
 * @param string key The option key
 * @param mixed defaultValue The value to return if option key does not exist
 * @return mixed
 */
PHP_METHOD(Ice_Flash, getOption) {

	zval *key_param = NULL, *defaultValue = NULL, *value, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Display the messages
 *
 * @param boolean remove
 * @return string
 */
PHP_METHOD(Ice_Flash, getMessages) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, *key = NULL, *type = NULL, *message = NULL, *messages = NULL, *body, *_0, *_1, **_4, *_5 = NULL, *_7;
	zend_bool remove;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &remove_param);

	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "session_key", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&key, this_ptr, "getoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&messages, _1, "get", NULL, key);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(body);
	ZVAL_STRING(body, "", 1);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		zephir_is_iterable(messages, &_3, &_2, 0, 0, "ice/flash.zep", 66);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(type, _3, _2);
			ZEPHIR_GET_HVALUE(message, _4);
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "getmessage", &_6, type, message);
			zephir_check_call_status();
			zephir_concat_self(&body, _5 TSRMLS_CC);
		}
	}
	if (remove) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _7, "remove", NULL, key);
		zephir_check_call_status();
	}
	RETURN_CCTOR(body);

}

/**
 * Get a message formatting it with HTML
 *
 * @param string type
 * @param mixed message
 */
PHP_METHOD(Ice_Flash, getMessage) {

	zephir_fcall_cache_entry *_8 = NULL;
	HashTable *_5;
	HashPosition _4;
	zval *_2, *_11 = NULL, *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *messages = NULL, *params = NULL, *body, *close = NULL, *message = NULL, *_0, *_1, *_3 = NULL, **_6, *_7 = NULL, *_9, *_10 = NULL, *_12 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &messages);

	zephir_get_strval(type, type_param);
	ZEPHIR_SEPARATE_PARAM(messages);


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_CALL_METHOD(&params, this_ptr, "getoption", NULL, type, _0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 4);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "#", 1);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "×", 1);
	zephir_array_fast_append(_2, _3);
	add_assoc_stringl_ex(_2, SS("class"), SL("close"), 1);
	ZEPHIR_CALL_METHOD(&close, _1, "a", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(body);
	ZVAL_STRING(body, "", 1);
	if (Z_TYPE_P(messages) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(messages);
		array_init_size(messages, 2);
		zephir_array_fast_append(messages, messages);
	}
	zephir_is_iterable(messages, &_5, &_4, 0, 0, "ice/flash.zep", 101);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(message, _6);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "html", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "getoption", &_8, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (zephir_is_true(_7)) {
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_tag"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_11);
			array_init_size(_11, 2);
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_VV(_12, close, message);
			zephir_array_update_string(&_11, SL("content"), &_12, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_13);
			array_init_size(_13, 2);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "content", 1);
			zephir_array_fast_append(_13, _3);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "div", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_14);
			ZVAL_STRING(_14, "content", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_15);
			ZVAL_BOOL(_15, 1);
			ZEPHIR_INIT_NVAR(_16);
			ZVAL_BOOL(_16, 1);
			ZEPHIR_CALL_METHOD(&_10, _9, "taghtml", NULL, _3, params, _11, _13, _14, _15, _16);
			zephir_check_temp_parameter(_3);
			zephir_check_temp_parameter(_14);
			zephir_check_call_status();
			zephir_concat_self(&body, _10 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_GET_CONSTANT(_3, "PHP_EOL");
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_VV(_12, message, _3);
			zephir_concat_self(&body, _12 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(body);

}

/**
 * Adds a message to the flash
 *
 * @param string type
 * @param string message
 */
PHP_METHOD(Ice_Flash, message) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message_param = NULL, *key = NULL, *messages = NULL, *_0 = NULL, *_1, *_2, *_3;
	zval *type = NULL, *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message_param);

	zephir_get_strval(type, type_param);
	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "session_key", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&key, this_ptr, "getoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_0);
	array_init(_0);
	ZEPHIR_CALL_METHOD(&messages, _1, "get", NULL, key, _0);
	zephir_check_call_status();
	if (!(zephir_array_isset(messages, type))) {
		ZEPHIR_INIT_VAR(_2);
		array_init(_2);
		zephir_array_update_zval(&messages, type, &_2, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_multi(&messages, &message TSRMLS_CC, SL("za"), 2, type);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "set", NULL, key, messages);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Add success message
 *
 * @param string message
 * @return void
 */
PHP_METHOD(Ice_Flash, success) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "success", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of success message
 */
PHP_METHOD(Ice_Flash, ok) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "success", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Add info message
 *
 * @param string message
 * @return void
 */
PHP_METHOD(Ice_Flash, info) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "info", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of info message
 */
PHP_METHOD(Ice_Flash, notice) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "info", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Add warning message
 *
 * @param string message
 * @return void
 */
PHP_METHOD(Ice_Flash, warning) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "warning", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of warning message
 */
PHP_METHOD(Ice_Flash, alert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "warning", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Add danger message
 *
 * @param string message
 * @return void
 */
PHP_METHOD(Ice_Flash, danger) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "danger", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of danger message
 */
PHP_METHOD(Ice_Flash, error) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "danger", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

