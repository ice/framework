
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * Shows HTML notifications related to different circumstances.
 *
 * @package     Ice/Flash
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2021 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Flash) {

	ZEPHIR_REGISTER_CLASS(Ice, Flash, ice, flash, ice_flash_method_entry, 0);

	zend_declare_property_null(ice_flash_ce, SL("session"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_flash_ce, SL("tag"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(ice_flash_ce, SL("options"), ZEND_ACC_PROTECTED);

	ice_flash_ce->create_object = zephir_init_properties_Ice_Flash;
	return SUCCESS;

}

PHP_METHOD(Ice_Flash, setOptions) {

	zval *options, options_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &options);



	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), options);
	RETURN_THISW();

}

/**
 * Flash constructor. Fetch session and tag service from the di.
 *
 * @param array options
 */
PHP_METHOD(Ice_Flash, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL, di, _1, _2, _3;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_CE_STATIC(&di, ice_di_ce, "fetch", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "session");
	ZEPHIR_CALL_METHOD(&_1, &di, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("session"), &_1);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "tag");
	ZEPHIR_CALL_METHOD(&_3, &di, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("tag"), &_3);
	if (zephir_fast_count_int(&options)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &key, 1)) {
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Display the messages.
 *
 * @param boolean remove
 * @return string
 */
PHP_METHOD(Ice_Flash, getMessages) {

	zend_string *_5$$3;
	zend_ulong _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, key, type, message, messages, body, _0, _1, *_2$$3, _3$$3, _6$$4, _8$$5, _9$$6;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &remove_param);

	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session_key");
	ZEPHIR_CALL_METHOD(&key, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&messages, &_1, "get", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&body);
	ZVAL_STRING(&body, "");
	if (Z_TYPE_P(&messages) == IS_ARRAY) {
		zephir_is_iterable(&messages, 0, "ice/flash.zep", 80);
		if (Z_TYPE_P(&messages) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&messages), _4$$3, _5$$3, _2$$3)
			{
				ZEPHIR_INIT_NVAR(&type);
				if (_5$$3 != NULL) { 
					ZVAL_STR_COPY(&type, _5$$3);
				} else {
					ZVAL_LONG(&type, _4$$3);
				}
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _2$$3);
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "getmessage", &_7, 0, &type, &message);
				zephir_check_call_status();
				zephir_concat_self(&body, &_6$$4);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &messages, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&type, &messages, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&message, &messages, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "getmessage", &_7, 0, &type, &message);
					zephir_check_call_status();
					zephir_concat_self(&body, &_8$$5);
				ZEPHIR_CALL_METHOD(NULL, &messages, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_INIT_NVAR(&type);
	}
	if (remove) {
		zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_9$$6, "remove", NULL, 0, &key);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&body);

}

/**
 * Get a message formatting it with HTML.
 *
 * @param string type
 * @param mixed message
 * @return string
 */
PHP_METHOD(Ice_Flash, getMessage) {

	zval _13$$5, _15$$5, _26$$8, _28$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *messages = NULL, messages_sub, params, body, close, message, _0, _2, _3, _4, _5, *_7, _8, _6$$3, _9$$4, _10$$4, _11$$5, _12$$5, _14$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$6, _21$$6, _22$$7, _23$$7, _24$$8, _25$$8, _27$$8, _29$$8, _30$$8, _31$$8, _32$$8, _33$$9, _34$$9;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&messages_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&close);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_28$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &messages);

	zephir_get_strval(&type, type_param);
	ZEPHIR_SEPARATE_PARAM(messages);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&params, this_ptr, "getoption", &_1, 0, &type, &_0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("tag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "close");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoption", &_1, 0, &_5, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&close, &_2, "button", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&body);
	ZVAL_STRING(&body, "");
	if (Z_TYPE_P(messages) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_create_array(&_6$$3, 1, 0);
		zephir_array_fast_append(&_6$$3, messages);
		ZEPHIR_CPY_WRT(messages, &_6$$3);
	}
	zephir_is_iterable(messages, 0, "ice/flash.zep", 116);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(messages), _7)
		{
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_COPY(&message, _7);
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "html");
			ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "getoption", &_1, 0, &_10$$4);
			zephir_check_call_status();
			if (zephir_is_true(&_9$$4)) {
				zephir_read_property(&_11$$5, this_ptr, ZEND_STRL("tag"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_create_array(&_13$$5, 1, 0);
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZEPHIR_CONCAT_VV(&_14$$5, &close, &message);
				zephir_array_update_string(&_13$$5, SL("content"), &_14$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_15$$5);
				zephir_create_array(&_15$$5, 1, 0);
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZVAL_STRING(&_16$$5, "content");
				zephir_array_fast_append(&_15$$5, &_16$$5);
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZVAL_STRING(&_16$$5, "div");
				ZEPHIR_INIT_NVAR(&_17$$5);
				ZVAL_STRING(&_17$$5, "content");
				ZVAL_BOOL(&_18$$5, 1);
				ZVAL_BOOL(&_19$$5, 1);
				ZEPHIR_CALL_METHOD(&_12$$5, &_11$$5, "taghtml", NULL, 0, &_16$$5, &params, &_13$$5, &_15$$5, &_17$$5, &_18$$5, &_19$$5);
				zephir_check_call_status();
				zephir_concat_self(&body, &_12$$5);
			} else {
				ZEPHIR_INIT_NVAR(&_20$$6);
				ZEPHIR_GET_CONSTANT(&_20$$6, "PHP_EOL");
				ZEPHIR_INIT_NVAR(&_21$$6);
				ZEPHIR_CONCAT_VV(&_21$$6, &message, &_20$$6);
				zephir_concat_self(&body, &_21$$6);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, messages, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, messages, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&message, messages, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_23$$7);
				ZVAL_STRING(&_23$$7, "html");
				ZEPHIR_CALL_METHOD(&_22$$7, this_ptr, "getoption", &_1, 0, &_23$$7);
				zephir_check_call_status();
				if (zephir_is_true(&_22$$7)) {
					zephir_read_property(&_24$$8, this_ptr, ZEND_STRL("tag"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_26$$8);
					zephir_create_array(&_26$$8, 1, 0);
					ZEPHIR_INIT_NVAR(&_27$$8);
					ZEPHIR_CONCAT_VV(&_27$$8, &close, &message);
					zephir_array_update_string(&_26$$8, SL("content"), &_27$$8, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_28$$8);
					zephir_create_array(&_28$$8, 1, 0);
					ZEPHIR_INIT_NVAR(&_29$$8);
					ZVAL_STRING(&_29$$8, "content");
					zephir_array_fast_append(&_28$$8, &_29$$8);
					ZEPHIR_INIT_NVAR(&_29$$8);
					ZVAL_STRING(&_29$$8, "div");
					ZEPHIR_INIT_NVAR(&_30$$8);
					ZVAL_STRING(&_30$$8, "content");
					ZVAL_BOOL(&_31$$8, 1);
					ZVAL_BOOL(&_32$$8, 1);
					ZEPHIR_CALL_METHOD(&_25$$8, &_24$$8, "taghtml", NULL, 0, &_29$$8, &params, &_26$$8, &_28$$8, &_30$$8, &_31$$8, &_32$$8);
					zephir_check_call_status();
					zephir_concat_self(&body, &_25$$8);
				} else {
					ZEPHIR_INIT_NVAR(&_33$$9);
					ZEPHIR_GET_CONSTANT(&_33$$9, "PHP_EOL");
					ZEPHIR_INIT_NVAR(&_34$$9);
					ZEPHIR_CONCAT_VV(&_34$$9, &message, &_33$$9);
					zephir_concat_self(&body, &_34$$9);
				}
			ZEPHIR_CALL_METHOD(NULL, messages, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&message);
	RETURN_CCTOR(&body);

}

/**
 * Adds a message to the flash.
 *
 * @param string type
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, message) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message_param = NULL, key, messages, _0, _1, _3, _2$$3;
	zval type, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message_param);

	zephir_get_strval(&type, type_param);
	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session_key");
	ZEPHIR_CALL_METHOD(&key, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&messages, &_1, "get", NULL, 0, &key, &_0);
	zephir_check_call_status();
	if (!(zephir_array_isset(&messages, &type))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		array_init(&_2$$3);
		zephir_array_update_zval(&messages, &type, &_2$$3, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_multi(&messages, &message, SL("za"), 2, &type);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "set", NULL, 0, &key, &messages);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Add success message.
 *
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, success) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "success");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Alias of success message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, ok) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "success");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add info message.
 *
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, info) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "info");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of info message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, notice) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "info");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add warning message.
 *
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, warning) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of warning message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, alert) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Add danger message.
 *
 * @param string message
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, danger) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "danger");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of danger message.
 * @return object Flash
 */
PHP_METHOD(Ice_Flash, error) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "danger");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Ice_Flash(zend_class_entry *class_type) {

		zval _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, _0, _3$$3;
		ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 7, 0);
			add_assoc_stringl_ex(&_1$$3, SL("session_key"), SL("_flash"));
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-success alert-dismissible fade show"));
			zephir_array_update_string(&_1$$3, SL("success"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-info alert-dismissible fade show"));
			zephir_array_update_string(&_1$$3, SL("info"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-warning alert-dismissible fade show"));
			zephir_array_update_string(&_1$$3, SL("warning"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 1, 0);
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("alert alert-danger alert-dismissible fade show"));
			zephir_array_update_string(&_1$$3, SL("danger"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 5, 0);
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "close");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "×");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			add_assoc_stringl_ex(&_2$$3, SL("type"), SL("button"));
			add_assoc_stringl_ex(&_2$$3, SL("class"), SL("close"));
			add_assoc_stringl_ex(&_2$$3, SL("data-dismiss"), SL("alert"));
			zephir_array_update_string(&_1$$3, SL("close"), &_2$$3, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("html"), &__$true, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

